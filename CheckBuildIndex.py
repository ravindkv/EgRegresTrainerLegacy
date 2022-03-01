import ROOT
ROOT.gROOT.SetBatch(True)

fileGPU = ROOT.TFile.Open("/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_Arun/results/resultsSC_MainNtuples_FullSelection/Run3HLT_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root")

tree1 = fileGPU.Get("egHLTRun3Tree")
tree2 = fileGPU.Get("egHLTRun3TreeFriend")

tree1.BuildIndex("eventnr")
tree2.BuildIndex("eventnr")

tree1.AddFriend(tree2,"gpu")
tree1.Scan("eventnr:gpu.eventnr")

# fileGPU = ROOT.TFile.Open("output_GPU_badEvent.root")
# fileCPU = ROOT.TFile.Open("output_CPU_badEvent.root")
# treeGPU = fileGPU.Get("Events")
# treeCPU = fileCPU.Get("Events")
# treeGPU.BuildIndex("EventAuxiliary.event()")
# treeCPU.BuildIndex("EventAuxiliary.event()")
# treeCPU.AddFriend(treeGPU,"gpu")
# treeCPU.Scan("EventAuxiliary.event():yourvariable:gpu.yourvariable","gpu.yourvariable>10")
