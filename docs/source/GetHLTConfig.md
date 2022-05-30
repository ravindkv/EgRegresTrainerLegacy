# Get HLT Configuration file

The detailed instructions about the HLT configuration files can be find in the twiki page "E/gamma HLT: Recommendations for PAG" ([link](https://twiki.cern.ch/twiki/bin/viewauth/CMS/EGMHLTRun3RecommendationForPAG)) and the links/references therein.

```{note}
The following commands are used for the training of the Run - 3 HLT regression.
```

## Setup

```bash
cmsrel CMSSW_12_0_1
cd CMSSW_12_0_1/src
cmsenv
git cms-addpkg HLTrigger
git cms-merge-topic Sam-Harper:EGHLTCustomisation_1130pre4
# apply patch available here: https://github.com/cms-sw/cmssw/pull/35368/files
scramv1 b -j 8
voms-proxy-init --voms cms --valid 168:00
```

## Get hltConfig file

* Get the hlt config using the following two **global tags**:
   * REAL:  `120X_mcRun3_2021_realistic_v6`
   * IDEAL: `120X_mcRun3_2021_realistic_v6_ECALIdealIC`

Command to get the hltConfig:

1. For real IC

```bash
hltGetConfiguration /users/swmukher/egm_ele5_open/V16 --setup /dev/CMSSW_12_0_0/GRun/V6 --globaltag 120X_mcRun3_2021_realistic_v6 --input root://cms-xrd-global.cern.ch//store/mc/Run3Winter21DRMiniAOD/DoubleElectron_Pt-1To300-gun/GEN-SIM-DIGI-RAW/FlatPU0to80FEVT_112X_mcRun3_2021_realistic_v16-v3/120002/5db8ce5f-a1e0-4604-b947-1a1da5bbf5e7.root --mc --process MYHLT --prescale none --max-events 50 --eras Run3 --output none --customise HLTrigger/Configuration/customizeHLTforEGamma.customiseEGammaMenuDev > hlt_real.py
```

2. For ideal IC

```bash
hltGetConfiguration /users/swmukher/egm_ele5_open/V16 --setup /dev/CMSSW_12_0_0/GRun/V6 --globaltag 120X_mcRun3_2021_realistic_v6_ECALIdealIC --input root://cms-xrd-global.cern.ch//store/mc/Run3Winter21DRMiniAOD/DoubleElectron_Pt-1To300-gun/GEN-SIM-DIGI-RAW/FlatPU0to80FEVT_112X_mcRun3_2021_realistic_v16-v3/120002/5db8ce5f-a1e0-4604-b947-1a1da5bbf5e7.root --mc --process MYHLT --prescale none --max-events 50 --eras Run3 --output none --customise HLTrigger/Configuration/customizeHLTforEGamma.customiseEGammaMenuDev  > hlt_ideal.py
```

- With the previous two commands, we will get the two configuration files. Check them first by running locally using `cmsRun`. If it works fine submit the crab job over full statistics.

## Crab Submit

```bash
cd $CMSSW_BASE/src
cmsenv
voms-proxy-init --voms cms --valid 168:00
source /cvmfs/cms.cern.ch/crab3/crab.sh
```

Example crab config file (one should modify at least the highlighted lines based on their use)

```{code-block} python
---
linenos:
emphasize-lines: 5-6,12,20,25,27
caption: |
    FileName: `crab_config_ideal.py`
---
from CRABClient.UserUtilities import config
config = config()

# config.section_('General')
config.General.requestName = 'crab_DoubleElectron_Pt1To300_IDEAL'
config.General.workArea = 'crab_DoubleElectron_Pt1To300_IDEAL'
config.General.transferOutputs = True
config.General.transferLogs = True

# config.section_('JobType')
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'hlt_ideal.py'
config.JobType.numCores = 4

# config.Data.inputDBS = 'phys03'
config.JobType.allowUndistributedCMSSW = True
config.JobType.maxMemoryMB = 4000

# config.JobType.numCores = 8
config.Data.inputDataset ='/DoubleElectron_Pt-1To300-gun/Run3Winter21DRMiniAOD-FlatPU0to80FEVT_112X_mcRun3_2021_realistic_v16-v3/GEN-SIM-DIGI-RAW'
# config.Data.splitting = 'Automatic'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 10

config.Data.outLFNDirBase = '/store/group/phys_egamma/Run3Studies/SCRegression/IDEAL_IC'
config.Data.publication = False
config.Site.storageSite = 'T2_CH_CERN'
```

- To run the above crab script:

    ```bash
    crab submit crab_config_ideal.py
    ```

- To get the last hltconfig file used and the crab scripts you can check the github repository: [EGamma_hltConfig_Regression](https://github.com/ram1123/EGamma_hltConfig_Regression>)
