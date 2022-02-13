{

 gROOT->ProcessLine(".L makeResPlots.C+");
 TTree* regTestTree = HistFuncs::makeChain("egHLTRun3Tree","/eos/home-a/arun/EGMRegression_rootFiles/inputrootfiles/results/Run3HLT_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root");
 regTestTree->AddFriend("regCorr = egHLTRun3TreeFriend","/eos/home-a/arun/EGMRegression_rootFiles/inputrootfiles/results/Run3HLT_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root");
}
