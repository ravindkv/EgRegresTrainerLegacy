{

 gROOT->ProcessLine(".L makeResPlots.C+");
 TTree* regTestTree = HistFuncs::makeChain("egHLTRun3Tree","/afs/cern.ch/user/a/arun/public/results_regression/Run3HLT_RealIC_IdealTraining_stdVar_stdCuts_ntrees1500_applied.root");
 regTestTree->AddFriend("regCorr = egHLTRun3TreeFriend","/afs/cern.ch/user/a/arun/public/results_regression/Run3HLT_RealIC_IdealTraining_stdVar_stdCuts_ntrees1500_applied.root");
}
