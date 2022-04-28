# Reduced Ntuples

Currently, it has two steps.

1. **Step -1** : Converts the edm to simple ROOT file.
1. **Step -2** : Converts the ROOT file to flat ROOT file. Here, flat means that all the vectors are splitted into separate entries.

## Step -1: Setup

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
```

Command to run over large statistics (Using 8 cores):

```bash
# Using multithread
python3 Analysis/HLTAnalyserPy/test/runMultiThreaded.py  -o output.root  <input>*.root --cmd "python3 Analysis/HLTAnalyserPy/test/makeRun3Ntup.py -r 50000" --hadd
```

## Step - 2: Get Flat ROOT File

Simple script is placed inside the [EgRegresTrainerLegacy](https://github.com/ram1123/EgRegresTrainerLegacy),  [here](https://github.com/ram1123/EgRegresTrainerLegacy/tree/Run3_2021_Robert_CMSSW12_0_1_FullSelection/GetFlatNtuple). One can use it as

```bash
root -l -b -q GetFlatNtuple.C\(\"Input.root\",\"Input_Flat.root\"\)
```

```{note}
Before moving to the next step, which is the regression training, we should have two flat root files. They are

1. ideal flat root file
1. read flat root file
```
