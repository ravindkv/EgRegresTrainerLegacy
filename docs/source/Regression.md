# Regression

The main readme link, with the details of the regression framework,  can be seen here: {doc}`link <Default_RegressionREADME>`.

## Some general information

- `Input root file`: Input root file should be flat tree. All the branches should be `int`, `float`, `double`, etc. Branches should not be saved as `vector`.
    - This means that if in an event we have two electrons then the same event number will appear twice, if we `Scan` the root file.
- Input target variable: `(True Energy) / (Raw Energy)`
- List of input variables for the training:

    1. `nrHitsEB1GeV+nrHitsEE1GeV`: Total number of ECAL rechits in EB and EE above 1 GeV threshold
    1. `eg_eta`: rapidity
    1. `eg_phiWidth`: phi-width of supercluster
    1. `eg_r9Frac`: Fractional R9
    1. `eg_nrClus`: Total number of clusters in supercluster
    1. `eg_clusterMaxDR`: Maximum distance between the seed and clusters inside the SC
    1. `eg_rawEnergy`: Raw energy

- Output
    1. invTar: Invarse target, i.e. `(Raw Energy) / (True Energy)`
    2. To get the corrected response: `invTar * mean`

## Regression setup

```bash
cmsrel CMSSW_12_0_1
cd CMSSW_12_0_1/src
git clone -b Run3_2021_Robert_CMSSW12_0_1_FullSelection https://github.com/ram1123/EgRegresTrainerLegacy.git
cd EgRegresTrainerLegacy
gmake RegressionTrainerExe -j 8
gmake RegressionApplierExe -j 8
export PATH=$PATH:./bin/$SCRAM_ARCH #add the binary location to path
python3 scripts/runSCRegTrainings.py --era "Run3"
```

### Regression performance test

For this compare the distribution of `E_reco/E_gen` and `regInvTar*regMean`.

Here, `regInvTar*regMean` should be equivalent to `E_reco/E_gen` after the regression correction. So, the distribution of `regInvTar*regMean` should be closer to 1 with narrow width.

An example script exists here: [Plot_mean.py](https://github.com/ram1123/EgRegresTrainerLegacy/blob/Run3_2021_Robert_CMSSW12_0_1_FullSelection/Plot_mean.py)

Or this can be also checked like:

```bash
export ROOT_INCLUDE_PATH=$ROOT_INCLUDE_PATH:$PWD/include #otherwise will get header not found errors
#root -l -b rootScripts/setupExample.c
root -l rootScripts/setupExample.c
hists = makeHists(regTestTree,{-3.0,-2.5,-2.,-1.6,-1.566,-1.4442,-1.1,-0.7,0.,0.7,1.1,1.4442,1.566,1.6,2.,2.5,3.0},150,0,1.5,{"regInvTar*regMean:eg_eta","eg_rawEnergy/eg_gen_energy:eg_eta","eg_energy/eg_gen_energy:eg_eta"},"eg_energy>0 && eg_sigmaIEtaIEta>0 && eg_sigmaIPhiIPhi>0 && eg_gen_pt>20 && eg_gen_pt<60")
compareRes({hists[0],"Corr Energy"},{hists[1],"raw energy"},{hists[2],"corr energy (old)"}, 6)
```

## Verify new regression by re-running hlt

### Upload new regression to GT

Need to create 4 `.db` files. Two files for the correction and another two files for the uncertainty, for EB and EE respectively. We should compute correction from ideal training and uncertainty from real training.

They are:

1. Correction for EB: We should get this from `Run3HLT_IdealIC_IdealTraining_stdVar_stdCuts_EB_ntrees1500_results.root`
    - Label: `pfscecal_EBCorrection_online`
    - Tag: `pfscecal_EBCorrection_online_Run3_120X_v1`
2. Uncertainty for EB: We should get this from `Run3HLT_RealIC_RealTraining_stdVar_stdCuts_EB_ntrees1500_results.root`
    - Label: `pfscecal_EBUncertainty_online`
    - Tag: `pfscecal_EBUncertainty_online_Run3_120X_v1`
3. Correction for EE: We should get this from `Run3HLT_IdealIC_IdealTraining_stdVar_stdCuts_EE_ntrees1500_results.root`
    - Label: `pfscecal_EECorrection_online`
    - Tag: `pfscecal_EECorrection_online_Run3_120X_v1`
4. Uncertainty for EE: We should get this from `Run3HLT_RealIC_RealTraining_stdVar_stdCuts_EE_ntrees1500_results.root`
    - Label: `pfscecal_EEUncertainty_online`
    - Tag: `pfscecal_EEUncertainty_online_Run3_120X_v1`

### Get DBTool Setup

```bash
cmsrel CMSSW_10_2_13
cd CMSSW_10_2_13/src
cmsenv
git cms-init
git clone git@github.com:cms-egamma/EgammaDBTools.git RecoEgamma/EgammaDBTools
scram b -j 16
```

Command to run

```bash
# EB Correction
cmsRun RecoEgamma/EgammaDBTools/test/gbrForestDBWriter.py gbrFilename=/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/results/resultSC_UpdatedEtaDef_16March/Run3HLT_IdealIC_IdealTraining_stdVar_stdCuts_EB_ntrees1500_results.root fileLabel=EBCorrection dbTag=pfscecal_EBCorrection_online_Run3_120X_v1 dbLabel=pfscecal_EBCorrection_online dbFilename=/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/dbFiles_BugFixed_ReOrderVars_16March/pfscecal_EBCorrection_online_Run3_120X_v1

# EE Correction
cmsRun RecoEgamma/EgammaDBTools/test/gbrForestDBWriter.py gbrFilename=/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/results/resultSC_UpdatedEtaDef_16March/Run3HLT_IdealIC_IdealTraining_stdVar_stdCuts_EE_ntrees1500_results.root fileLabel=EECorrection dbTag=pfscecal_EECorrection_online_Run3_120X_v1 dbLabel=pfscecal_EECorrection_online dbFilename=/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/dbFiles_BugFixed_ReOrderVars_16March/pfscecal_EECorrection_online_Run3_120X_v1

# EB Uncertainty
cmsRun RecoEgamma/EgammaDBTools/test/gbrForestDBWriter.py gbrFilename=/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/results/resultSC_UpdatedEtaDef_16March/Run3HLT_RealIC_RealTraining_stdVar_stdCuts_EB_ntrees1500_results.root fileLabel=EBUncertainty dbTag=pfscecal_EBUncertainty_online_Run3_120X_v1 dbLabel=pfscecal_EBUncertainty_online dbFilename=/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/dbFiles_BugFixed_ReOrderVars_16March/pfscecal_EBUncertainty_online_Run3_120X_v1

# EE Uncertainty
cmsRun RecoEgamma/EgammaDBTools/test/gbrForestDBWriter.py gbrFilename=/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/results/resultSC_UpdatedEtaDef_16March/Run3HLT_RealIC_RealTraining_stdVar_stdCuts_EE_ntrees1500_results.root fileLabel=EEUncertainty dbTag=pfscecal_EEUncertainty_online_Run3_120X_v1 dbLabel=pfscecal_EEUncertainty_online dbFilename=/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/dbFiles_BugFixed_ReOrderVars_16March/pfscecal_EEUncertainty_online_Run3_120X_v1
```

Latest version of .db files are present [here](https://github.com/ram1123/EGamma_hltConfig_Regression/tree/10f59cc6fb6b2e7b274274fbc9beae10c5dd6078)

## Re-Run HLT with updated training information

Re-run HLT step with the realIC configuration file append the following lines (with proper naming conventions and 4 times corresponding to above 4 .db files) and run:

```python
process.GlobalTag.toGet.extend( cms.VPSet(
cms.PSet(
    record = cms.string('GBRDWrapperRcd'),
    tag = cms.string('pfscecal_EBCorrection_online_Run3_120X_v1'),
    label = cms.untracked.string('pfscecal_EBCorrection_online'),
    connect = cms.string('sqlite_file:pfscecal_EBCorrection_online_Run3_120X_v1.db')
    )
)
)
```

Link of updated real hlt config file: [hlt_real_WithDBFile.py#L3456-L3491](https://github.com/ram1123/EGamma_hltConfig_Regression/blob/10f59cc6fb6b2e7b274274fbc9beae10c5dd6078/hlt_real_WithDBFile.py#L3456-L3491)
