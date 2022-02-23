# Ntuple Production

- Used Sam's analyzer: https://gitlab.cern.ch/sharper/HLTAnalyserPy

```bash
python3 Analysis/HLTAnalyserPy/test/runMultiThreaded.py  -o HLTAnalyzerTree_REAL.root /eos/cms/store/group/phys_egamma/arun/run3_egamma_hlt/DoubleElectron_Pt-1To300-gun/winter21/211008_134201_REAL/0000/output_1*.root --cmd "python3 Analysis/HLTAnalyserPy/test/makeRun3Ntup.py -r 1000" --hadd

python3 Analysis/HLTAnalyserPy/test/runMultiThreaded.py  -o HLTAnalyzerTree_IDEAL.root /eos/cms/store/group/phys_egamma/arun/run3_egamma_hlt/DoubleElectron_Pt-1To300-gun/winter21/211008_134201_IDEAL/0000/output_1*.root --cmd "python3 Analysis/HLTAnalyserPy/test/makeRun3Ntup.py -r 1000" --hadd

```
