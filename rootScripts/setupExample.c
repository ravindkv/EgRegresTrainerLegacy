{

 gROOT->ProcessLine(".L makeResPlots.C+");
//  TTree* regTestTree = HistFuncs::makeChain("egHLTRun3Tree","/afs/cern.ch/user/r/rasharma/work/EGamma-POG/HLT_tasks/CPUtoGPUTransition/analyzer/CMSSW_12_0_1/src/HLTAnalyzerTree_REAL.root");
 TTree* regTestTree = HistFuncs::makeChain("egHLTRun3Tree","/afs/cern.ch/user/r/rasharma/work/EGamma-POG/HLT_tasks/CPUtoGPUTransition/analyzer/CMSSW_12_0_1/src/HLTAnalyzerTree_REAL.root");
//  regTestTree->AddFriend("regCorr = egHLTRun3TreeFriend","results/resultsSC/Run3HLT_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root");
 regTestTree->AddFriend("regCorr = egHLTRun3TreeFriend","results/resultsSC_CMSSW12X_15Feb/Run3HLT_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied_hadd.root");
}
