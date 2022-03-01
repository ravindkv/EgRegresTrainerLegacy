 {
	//binning
	std::vector<double> puBins = {0,5,10,15,20,25,30,35,40,45,50,55,60,65,70};
	std::vector<double> resBins = {0.005, 0.0075, 0.01, 0.0125, 0.015, 0.0175, 0.02, 0.0225, 0.025, 0.0275, 0.03, 0.0325, 0.035, 0.0375, 0.04, 0.0425, 0.045, 0.0475, 0.05, 0.055, 0.06, 0.065, 0.07, 0.075, 0.08, 0.09, 0.1,0.12,0.2,0.4,0.5};
	std::vector<double> etaBins3p0 = {-3.0, -2.75, -2.5,-2.0,-1.5666,-1.4442,-1.0,-0.5,0.0,0.5,1.0,1.4442,1.566,2.0,2.5, 2.75, 3.0};
	std::vector<double> etaBins = {0.,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.4442,1.566,1.7,1.8,1.9,2.,2.25,2.5};//,2.75,3.0}
	std::vector<double> etaBinsPho = {0.,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.4442,1.566,1.7,1.8,1.9,2.,2.25,2.5,2.75,3.0};
	std::vector<double> etBins = {5,15,30,50,100,150,300};
	std::vector<double> etBinsPho = {10,20,30,50,100,150,300};
	std::vector<double> etBinsSC = {25,40,50,60};

	//std::vector<double> etBins = {10,20,30,50,75,100,125,150,200,250,300};
	std::vector<double> etBinsVs = {5,10,15,20,25,30,35,40,45,50,60,65,70,75,80,85,90,95,100,120,140,160,180,200,220,240,260,280,300};
	std::vector<double> etBinsVsPho = {20,25,30,35,40,45,50,60,65,70,75,80,85,90,95,100,120,140,160,180,200,220,240,260,280,300};

	std::vector<double> etBinsMedium = {300,400,500,600,700,800,900,1000};
	std::vector<double> etBinsEleHigh = {1000,1100,1200,1300,1400,1500};
	std::vector<double> etBinsPhoHigh = {1500,1600,1700,1800,1900,2000,2100,2200,2300,2400,2500,2600,2700,2800,2900,3000};
	std::vector<double> etaBinsSimple = {0.,0.7,1.1,1.4442,1.566,2.,2.25,2.5};



	// suppressing noisy fits
	RooMsgService::instance().setGlobalKillBelow(RooFit::FATAL);
	RooMsgService::instance().setSilentMode(true);
	gErrorIgnoreLevel = kError;

	// inFile = "/afs/cern.ch/user/r/rasharma/work/EGamma-POG/HLT_tasks/CPUtoGPUTransition/analyzer/CMSSW_12_0_1/src/HLTAnalyzerTree_REAL.root";
	// inFileFriend = "results/resultsSC_CMSSW12X_15Feb/Run3HLT_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied_hadd.root";

	inFile = "/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/results/resultsSC_MainNtuples_FullSelection_FlatNtuple/Run3HLT_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root";

	gROOT->ProcessLine(".L makeResPlots.C+");
	TTree* regTestTree = HistFuncs::makeChain("egHLTRun3Tree",inFile);
	// regTestTree->AddFriend("regCorr = egHLTRun3TreeFriend",inFileFriend);

    // std::vector<std::string> plotVars = {"invTar*mean:eg_gen_eta","eg_energy/eg_gen_energy:eg_gen_eta"};
    std::vector<std::string> plotVars = {"regInvTar*regMean:eg_gen_eta","eg_energy/eg_gen_energy:eg_gen_eta"};

	// TString pTCutLow = "3";
	// TString pTCutUp  = "500";

	TString pTCutLow = "3";
	// TString pTCutUp  = "10";

	// TString pTCutLow = "10";
	// TString pTCutUp  = "20";

	// TString pTCutLow = "20";
	// TString pTCutUp  = "60";

	// TString pTCutLow = "60";
	// TString pTCutUp  = "200";

	// TString pTCutLow = "200";
	TString pTCutUp  = "500";

	TString baseCuts = "eg_energy>0 && eg_gen_energy> 0 && eg_sigmaIEtaIEta>0 && eg_gen_pt>"+pTCutLow+" && eg_gen_pt<"+pTCutUp;

	std::vector<TH2*> hists3 = makeHists(regTestTree,etaBins3p0,150,0.0,1.5,plotVars,(const std::string)baseCuts);
	// std::vector<TH2*> hists3 = makeHists(regTestTree,etaBins,51,0.6,1.2,plotVars,(const std::string)baseCuts);
	compareRes({hists3[0],"Raw Energy"},{hists3[1],"Corr energy"}, 6, pTCutLow , pTCutUp);

}
