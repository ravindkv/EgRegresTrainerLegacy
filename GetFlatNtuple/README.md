# Get flat ntuple

The root file that we get from

```bash
root -l -b -q GetFlatNtuple.C\(\"/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/HLTAnalyzerTree_REAL.root\",\"/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/HLTAnalyzerTree_REAL_Flat.root\"\)
root -l -b -q GetFlatNtuple.C\(\"/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/HLTAnalyzerTree_IDEAL.root\",\"/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/HLTAnalyzerTree_IDEAL_Flat.root\"\)
```

```bash
nohup root -l -b -q GetFlatNtuple.C\(\"/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/HLTAnalyzerTree_REAL.root\",\"/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/HLTAnalyzerTree_REAL_Flat_Small.root\"\) >& REAL.log &
nohup root -l -b -q GetFlatNtuple.C\(\"/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/HLTAnalyzerTree_IDEAL.root\",\"/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/HLTAnalyzerTree_IDEAL_Flat_Small.root\"\) >& IDEAL.log &
```
