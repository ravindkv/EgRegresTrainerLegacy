# Steps

1. Get hlt configuration file
    1. Get two set of ntuples. One for "ideal" IC and another for "real" IC.
2. Obtain the reduced set of ntuples
3. Run regression
    1. Train
    2. evaluation
4. Check new regression by re-run the hlt step
5. Upload the new regression to GT

# Step - 1: Get HLT configuration

```bash
cmsrel CMSSW_12_0_1
cd CMSSW_12_0_1/src
cmsenv
git cms-addpkg HLTrigger
git cms-merge-topic Sam-Harper:EGHLTCustomisation_1130pre4
# apply path available here: https://github.com/cms-sw/cmssw/pull/35368/files
# Get the hlt config using the following two global tag
#       REAL:  120X_mcRun3_2021_realistic_v6
#       IDEAL: 120X_mcRun3_2021_realistic_v6_ECALIdealIC

# hltGetConfiguration command for real
hltGetConfiguration /users/swmukher/egm_ele5_open/V16 --setup /dev/CMSSW_12_0_0/GRun/V6 --globaltag 120X_mcRun3_2021_realistic_v6 --input root://cms-xrd-global.cern.ch///store/mc/Run3Winter21DRMiniAOD/DoubleElectron_Pt-1To300-gun/GEN-SIM-DIGI-RAW/FlatPU0to80FEVT_112X_mcRun3_2021_realistic_v16-v3/120000/0019ce34-a026-4ec0-83a5-3094586bce59.root --mc --process MYHLT --prescale none --max-events 50 --eras Run3 --output none --customise HLTrigger/Configuration/customizeHLTforEGamma.customiseEGammaMenuDev > hlt_real.py

# hltGetConfiguration command for ideal
hltGetConfiguration /users/swmukher/egm_ele5_open/V16 --setup /dev/CMSSW_12_0_0/GRun/V6 --globaltag auto:120X_mcRun3_2021_realistic_v6_ECALIdealIC --input root://cms-xrd-global.cern.ch///store/mc/Run3Winter21DRMiniAOD/DoubleElectron_Pt-1To300-gun/GEN-SIM-DIGI-RAW/FlatPU0to80FEVT_112X_mcRun3_2021_realistic_v16-v3/120000/0019ce34-a026-4ec0-83a5-3094586bce59.root --mc --process MYHLT --prescale none --max-events 50 --eras Run3 --output none --customise HLTrigger/Configuration/customizeHLTforEGamma.customiseEGammaMenuDev  > hlt_ideal.py

# proxy
voms-proxy-init --voms cms --valid 168:00
```

# Get reduced ntuples

```
cd /afs/cern.ch/user/r/rasharma/work/EGamma-POG/HLT_tasks/CPUtoGPUTransition/analyzer/CMSSW_12_0_1/src
cmsrel CMSSW_12_0_1
cd CMSSW_12_0_1/src
cmsenv
git cms-merge-topic Sam-Harper:L1NtupleFWLiteFixes_1130pre4
# git clone ssh://git@gitlab.cern.ch:7999/sharper/HLTAnalyserPy.git Analysis/HLTAnalyserPy
git clone -b RegNtupleRun3 ssh://git@gitlab.cern.ch:7999/rasharma/HLTAnalyserPy.git Analysis/HLTAnalyserPy
scramv1 b -j 8
python3 Analysis/HLTAnalyserPy/test/makeRun3Ntup.py <input>*.root  -o test.root -r 1000
# Using multithread
python3 Analysis/HLTAnalyserPy/test/runMultiThreaded.py  -o ZPrime_petaTrk.root  <input>*.root --cmd "python3 Analysis/HLTAnalyserPy/test/makeRun3Ntup.py -r 1000" --hadd
```

# Run regression

- Input root file: Input root file should be flat tree. All the branches should be int, float, double, etc. Branches should not be saved as vector.
    - This means that if in an event we have two electrons then the same event number will appear twice, if we `Scan` the root file.
- Input target variable: `(True Energy) / (Raw Energy)`
- List of input variables for the training:
      1. SC energy
      2. eta
- Output
    1. invTar: Invarse target, i.e. `(Raw Energy) / (True Energy)`
    2. To get the corrected response: `invTar * mean`


# Verify new regression by re-running hlt

# Upload new regression to GT

- Setup
    ```bash
    cmsrel CMSSW_10_2_13
    cd CMSSW_10_2_13/src
    cmsenv
    git cms-init
    git clone git@github.com:cms-egamma/EgammaDBTools.git RecoEgamma/EgammaDBTools
    scram b -j 16
    ```

- Command to run
    ```bash
    cd $CMSSW_10_2_13/src
    cmsRun RecoEgamma/EgammaDBTools/test/gbrForestDBWriter.py gbrFilename=/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/results/resultsSC_MainNtuples_FullSelection_FlatNtuple/Run3HLT_RealIC_RealTraining_stdVar_stdCuts_EB_ntrees1500_results.root fileLabel=EBCorrection dbTag=pfscecal_EBCorrection_online_Run3_120X_v1 dbLabel=pfscecal_EBCorrection_online dbFilename=/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/dbFiles/pfscecal_EBCorrection_online_Run3_120X_v1
    ```
- Re-run HLT step: In the first hlt\*.py configuration file append the following lines (with proper naming conventions) and run:

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

-----



# Ntuple Production

- Used Sam's analyzer: https://gitlab.cern.ch/sharper/HLTAnalyserPy

```bash
python3 Analysis/HLTAnalyserPy/test/runMultiThreaded.py  -o HLTAnalyzerTree_REAL.root /eos/cms/store/group/phys_egamma/arun/run3_egamma_hlt/DoubleElectron_Pt-1To300-gun/winter21/211008_134201_REAL/0000/output_1*.root --cmd "python3 Analysis/HLTAnalyserPy/test/makeRun3Ntup.py -r 1000" --hadd

python3 Analysis/HLTAnalyserPy/test/runMultiThreaded.py  -o HLTAnalyzerTree_IDEAL.root /eos/cms/store/group/phys_egamma/arun/run3_egamma_hlt/DoubleElectron_Pt-1To300-gun/winter21/211008_134201_IDEAL/0000/output_1*.root --cmd "python3 Analysis/HLTAnalyserPy/test/makeRun3Ntup.py -r 1000" --hadd

```
