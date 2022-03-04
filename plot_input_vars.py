import ROOT
ROOT.gROOT.SetBatch(True)

InputFile = ROOT.TFile("/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/results/resultsSC_MainNtuples_FullSelection_FlatNtuple/Run3HLT_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root")
Tree1 = "egHLTRun3Tree"

inTree = InputFile.Get(Tree1)

InputVarList = {
    "eg_rawEnergy": [100, 0, 1500],
    "eg_gen_energy": [100, 0, 1500],
    "eg_phiWidth": [100, 0, 0.2],
    "eg_eta": [100, -3, 3],
    "eg_clusterMaxDR": [100, 0, 1],
    "eg_r9Full": [200, 0, 1.5],
    "eg_nrClus": [10, 0, 10],
    "nrHitsEB1GeV": [100, 0, 100],
    "nrHitsEE1GeV": [100, 0, 500],
    "eg_isEB": [4, -1, 3],
    "eg_isEE": [4, -1, 3],
}

base_ele_cuts = "(eg_gen_energy>0 && eg_sigmaIEtaIEta>0 && eg_sigmaIPhiIPhi>0)" # Full selection for Run-3

c1 = ROOT.TCanvas()
for variable, range_ in InputVarList.items():
    print("{:15}: {}".format(variable, range_))
    h1 = ROOT.TH1F("h1", ";"+variable+";Entries", range_[0], range_[1], range_[2])
    inTree.Draw(variable+">>h1",base_ele_cuts)
    c1.SaveAs("plots/"+variable+".png")
    c1.Clear()



