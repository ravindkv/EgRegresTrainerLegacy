# E/gamma Energy Regression Trainer


This is the E/gamma Energy Regression Trainer used for RunII

It is https://github.com/cms-egamma/RegressionTrainer & https://github.com/cms-egamma/HiggsAnalysis ported to a common build system. It links against CMSSW but is otherwise standalone and is not built as part of CMSSW.

It is very much a legacy tool and E/gamma wishes to move away from it as quickly as possible. So you have been warned.


## setup instructions

First setup a CMSSW environment. We only link against this so we only need the CMSSW environment variables setup. Any version >=CMSSW_9_4_1 should work.

Then clone this repo into a location of your chosing. It does not have to be under $(CMSSW_BASE)/src, in fact it is better that it is not. 

```bash
git clone git@github.com:cms-egamma/EgRegresTrainerLegacy.git
cd EgRegresTrainerLegacy 
gmake RegressionTrainerExe -j 8
gmake RegressionApplierExe -j 8
export PATH=$PATH:./bin/$SCRAM_ARCH #add the binary location to path
export PYTHON27PATH=$PYTHON27PATH:python #adds the python sub dir to python path, this may be PYTHONPATH in some systems
```

## running the regression training
The training of the regression is done via RegressionTrainerExe. 
The trainer is ntuple agnoistic and can run on any resonable input.  
It is completely configured by a single config file which is now generated by a python script. 
The config file specifies:
- regression target : mc.energy / energy to apply correction to
- regression input variables (EB) : a list of variables seperated by ":" to take as input for the barrel
- regression input variables (EE) : a list of variables seperated by ":" to take as input for the endcap
- cuts to be applied to events to enter the training
- cut to determine if barrel
- cut to determine if endcap
- whether to run the barrel or endcap
- input tree name
- input files
- name of the regression which determines the output
- output directory
- options : various hyperparameters 
- trainer: we always use GBRLikelihoodTrain now

Currently our workflow is run the regression seperately in barrel and endcap in two different jobs. We use a script to make this easier. 

The RegressionTrainerExe outputs a root file with the GBRForestD objects. It has them for both the mean and the sigma, called EBCorrection and EBUncertainty (EECorrection and EEUncertainty for the endcap). It additionally stores the RooWorkspace, the target variable and the input variables names. 

RegressionApplierExe can read the barrel and endcap root files and apply those corrections to a given tree. By default it makes a "friend" tree which just has the mean, inverse of the target and the sigma. It is called <treeName>Friend. Optionally it can copy the input tree and add the mean, inv target and sigma directly to it. The later functionality is useful for training regressions that take the input of previous regressions (such as the ECAL-Trk combination).

## example workflow

An example is running the regression training for electrons. 
```
./scripts/runEleRegTrainings.py
```

This runs over an input for the ECAL training, does it for both barrel and endcap, makes a new tree with this applied and then uses this tree as input for the ECAL-Trk regression training. 

It then makes a new copy of the tree with the regressed mean and sigma included. The ecal only mean and sigma is regEcalMean and regEcalSigma while the combined is simply regMean, regSigma. The targets are regEcalInvTar and regInvTar. Note saving the target variable is just for convenience, it can of course be recalculated from the variables in the trees but it ends up being complicated for the ecal-trk combination. 

The training step will take all availible CPUs, ie if you have 24 cores, it'll automatically run 24 processes. At least this is the case on the RAL interactive nodes, on lxplus it seems just to take the one CPU. The testing step runs over 4 threads which was emperically derived (this can be adjusted).

On a 24 core machine (using all 24 cores of course), this takes under 5mins. The training can get stuck so if it doesnt finish in 10-15mins, just stop it and try again. 


Then to make an example resolution plot:
```bash
export ROOT_INCLUDE_PATH=$ROOT_INCLUDE_PATH:$PWD/include #otherwise will get header not found errors
root rootScripts/setupExample.c
hists = makeHists(egRegTree,{-3.0,-2.5,-2.,-1.6,-1.566,-1.4442,-1.1,-0.7,0.,0.7,1.1,1.4442,1.566,1.6,2.,2.5},150,0,1.5,{"regInvTar*regMean","regEcalInvTar*regEcalMean:sc.seedEta","ele.energy/mc.energy:sc.seedEta"},"mc.energy>0 && sc.sigmaIEtaIEta>0 && mc.dR<0.1 && mc.pt>20 && mc.pt<60");
compareRes({hists[0],"ECAL-Trk Energy"},{hists[1],"ECAL Only Energy"},{hists[2],"existing energy"},6); //6 is the bin number, adjust as you like
```

Common issues:
1) the environment variable needs to have the include subdirectory in it (export ROOT_INCLUDE_PATH=$ROOT_INCLUDE_PATH:$PWD/include  when you are in the main working directory) otherwise you will get header not found errors
2) CMSSW not setup will cause this to crash. Again you dont need to be a sub directoy, just cmsenv in an appropriate area and then change to your working directory.


## build system 

This build system is a lightweight custom system Sam uses for his analysis code. Its ~11 years old and could have been better so has some quirks. 

### conventions
A libary is built for each subdirectoy of the "packages" directory. All c++ files must have the suffix ".cc". All header files must have the suffix of ".hh" although an individual package may allow them to be all ".h" instead. ROOT dictionaries are generated by a name_LinkDef.h in the dict dir

Files defining a main() function are located in the top level main directory. 

Include locations are #include "packagename/filename.hh"

### layout

main: location of all files which define a main() function. The filename is Name.cc. To build do "gmake NameExe -j 16" (where the -j 16 is just to build in parallel.

packages: location of the libary files. Each libary has a specific subdirectory here. 

packages/LibName\/include: location of header files

packages/LibName/src : location of src files

packages/LibName/dict : localtion of the LinkDef files

packages/LibName/package.mk: build fragment for the package, controlling what files are build as part of it

package.mk defines the LIBNAME_LIBFILES varible which controls the building of the libary. To add a file to the libary it should be added here as follows
LIBNAME_LIBFILES = $(PKG_OBJ_DIR)/FILENAME1.o $(PKG_OBJ_DIR)/FILENAME2.o 
where FILENAME1.cc and FILENAME2.cc exist in the src direction.

ROOT dictionaries are done by rootcint and are triggered by adding FILENAME1Dict.o to LIBNAME_LIBFILES. It requires that there is FILENAME1_LinkDef.h in the dict subdir.  Note here it matters on the header suffix, by default it assumes that it has FILENAME1.hh but it can be modified to FILENAME1.h on a per package basis by changing the rule 

LIBNAME/src/%_LinkDef.h: packages/LIBNAME/dict/%_LinkDef.h packages/LIBNAME/include/%.hh   to 

LIBNAME/src/%_LinkDef.h: packages/LIBNAME/dict/%_LinkDef.h packages/LIBNAME/include/%.h 

(ie deleting the last h)

Finally to make a new package just do coreScripts/mkPkg.py --pkgName NAME which will make the initial empty dirs and package.mk







