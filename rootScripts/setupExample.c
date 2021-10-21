{

 gROOT->ProcessLine(".L makeResPlots.C+");
 // TTree* regTestTree = HistFuncs::makeChain("een_analyzer/ClusterTree","/eos/cms/store/group/phys_egamma/EgRegression/SCReg/allBar1.root");
 TTree* regTestTree = HistFuncs::makeChain("egHLTRun3Tree","/afs/cern.ch/user/a/arun/public/results_regression/Run3HLT_RealIC_IdealTraining_stdVar_stdCuts_ntrees1500_applied.root");
 // regTestTree->AddFriend("regCorr = een_analyzer/ClusterTree","results/reg_sc_stdVarsNoWidthNoSigma_stdCutsAllEvts_ntrees1500_applied.root");
 regTestTree->AddFriend("regCorr = egHLTRun3TreeFriend","/afs/cern.ch/user/a/arun/public/results_regression/Run3HLT_RealIC_IdealTraining_stdVar_stdCuts_ntrees1500_applied.root");

 // hists = makeHists(regTestTree,{-3.0,-2.5,-2.,-1.6,-1.566,-1.4442,-1.1,-0.7,0.,0.7,1.1,1.4442,1.566,1.6,2.,2.5},150,0,1.5,{"invTar*mean:eg_gen_eta","eg_energy/eg_gen_energy:eg_gen_eta"},"eg_energy>0 && eg_sigmaIEtaIEta>0 && eg_gen_pt>20 && eg_gen_pt<60");
 // compareRes({hists[0],"ECAL Energy"},{hists[1],"existing energy"},6);

}
