# Reduced Ntuples

## Setup

```bash
cmsrel CMSSW_12_0_1
cd CMSSW_12_0_1/src
cmsenv
git cms-merge-topic Sam-Harper:L1NtupleFWLiteFixes_1130pre4
# git clone ssh://git@gitlab.cern.ch:7999/sharper/HLTAnalyserPy.git Analysis/HLTAnalyserPy
git clone -b RegNtupleRun3 ssh://git@gitlab.cern.ch:7999/rasharma/HLTAnalyserPy.git Analysis/HLTAnalyserPy
scramv1 b -j 8
```


Command to run for small statistics:

```bash
python3 Analysis/HLTAnalyserPy/test/makeRun3Ntup.py <input>*.root  -o test.root -r 1000
# python3 Analysis/HLTAnalyserPy/test/makeRun3Ntup.py /afs/cern.ch/user/r/rasharma/work/EGamma-POG/HLT_tasks/regression/GetRawFiles/CMSSW_12_0_1/src/output.root  -o /eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/ReRunHLT_WithDB/pfscecal_EBCorrection_online_Run3_120X_v1.root -r 1000
```


Command to run over large statistics:

```bash
# Using multithread
python3 Analysis/HLTAnalyserPy/test/runMultiThreaded.py  -o ZPrime_petaTrk.root  <input>*.root --cmd "python3 Analysis/HLTAnalyserPy/test/makeRun3Ntup.py -r 1000" --hadd
python3 Analysis/HLTAnalyserPy/test/runMultiThreaded.py  -o /eos/cms/store/group/phys_egamma/Run3Studies/SCRegression/IDEAL_UpdatedisEB.root  /eos/cms/store/group/phys_egamma/Run3Studies/SCRegression/IDEAL_IC/DoubleElectron_Pt-1To300-gun/crab_crab_DoubleElectron_Pt1To300_IDEAL/220303_003943/0000/*.root --cmd "python3 Analysis/HLTAnalyserPy/test/makeRun3Ntup.py -r 50000" --hadd
python3 Analysis/HLTAnalyserPy/test/runMultiThreaded.py  -o /eos/cms/store/group/phys_egamma/Run3Studies/SCRegression/REAL_UpdatedisEB.root  /eos/cms/store/group/phys_egamma/Run3Studies/SCRegression/WithOldCorrection_v2/DoubleElectron_Pt-1To300-gun/crab_crab_DoubleElectron_Pt1To300_WithOldCorr_v2/220303_004828/0000/*.root --cmd "python3 Analysis/HLTAnalyserPy/test/makeRun3Ntup.py -r 50000" --hadd
```
