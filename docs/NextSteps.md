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

## Upload new regression to GT

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

### Setup

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
