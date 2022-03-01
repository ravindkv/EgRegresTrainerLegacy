{

 gROOT->ProcessLine(".L makeResPlots.C+");
//  TTree* regTestTree = HistFuncs::makeChain("egHLTRun3Tree","/afs/cern.ch/user/r/rasharma/work/EGamma-POG/HLT_tasks/CPUtoGPUTransition/analyzer/CMSSW_12_0_1/src/HLTAnalyzerTree_REAL.root");
//  TTree* regTestTree = HistFuncs::makeChain("egHLTRun3Tree","/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/results/resultsSC_MainNtuples_FullSelection/Run3HLT_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root");
//  regTestTree->AddFriend("regCorr = egHLTRun3TreeFriend","results/resultsSC/Run3HLT_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root");
//  regTestTree->AddFriend("regCorr = egHLTRun3TreeFriend",   "/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/results/resultsSC_MainNtuples_FullSelection/Run3HLT_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root");
//  regTestTree->AddFriend("regCorr = egHLTRun3Tree",   "/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_V2/results/resultsSC_MainNtuples_FullSelection/Run3HLT_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root");

// Soham
// TTree* regTestTree = HistFuncs::makeChain("egHLTRun3TreeFlat","/afs/cern.ch/work/s/sobhatta/public/test_EgRegresTrainerLegacy_Run3HLT/Run3HLT_IdealIC_IdealTraining_stdVar_stdCuts_ntrees1500_applied.root")
// TTree* regTestTree = HistFuncs::makeChain("egHLTRun3Tree","/afs/cern.ch/work/s/sobhatta/public/test_EgRegresTrainerLegacy_Run3HLT/v2/Run3HLT_IdealIC_IdealTraining_stdVar_stdCuts_ntrees1500_applied.root")


//  My New
TTree* regTestTree = HistFuncs::makeChain("egHLTRun3Tree","/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/results/resultsSC_MainNtuples_FullSelection_FlatNtuple/Run3HLT_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root")

}
