import ROOT
ROOT.gROOT.SetBatch(True)
ROOT.gStyle.SetOptStat(1111)

var1 = "eg_energy/eg_gen_energy"
var2 = "mean*invTar"

pt_low = 60; pt_high = 200;

# Cut = "eg_gen_pt>20 && eg_gen_pt<200"
Cut = "eg_gen_pt>"+str(pt_low)+" && eg_gen_pt<" + str(pt_high)

# InputFile = "results/resultsSC_CMSSW12X_15Feb/Run3HLT_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root"
# InputFile = "results/resultsSC_CMSSW12X_15Feb/Run3HLT_RealIC_IdealTraining_stdVar_stdCuts_ntrees1500_applied.root"
InputFile = "/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_Arun/HLTAnalyzerTree_REAL.root"
FriendInputFile = "/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_Arun/results/resultsSC_MainNtuples_Arun_FullSelection/Run3HLT_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root"
Tree1 = "egHLTRun3Tree"
Tree2 = "egHLTRun3TreeFriend"

# inFile = ROOT.TFile(InputFile)
inFile = ROOT.TFile(FriendInputFile)
inTree = inFile.Get(Tree1)
inTree.AddFriend(Tree2, FriendInputFile)
# inTree.AddFriend(Tree2, InputFile)

c1 = ROOT.TCanvas()
# c1.SetLogy(1)

l1 = ROOT.TLegend(0.1,0.70, 0.46,0.90)
h1 = ROOT.TH1F("h1",";;Entries",144, 0.6, 1.2)
h2 = ROOT.TH1F("h2",";;Entries",144, 0.6, 1.2)

h1.SetLineWidth(2)
h2.SetLineWidth(2)
h1.SetLineColor(1)
h2.SetLineColor(2)

inTree.Draw(var1+">>h1", Cut)
inTree.Draw(var2+">>h2", Cut)

h1.SetMaximum(ROOT.TMath.Max(h1.GetMaximum()*1.1,h2.GetMaximum()*1.1))
h1.Draw()
c1.GetPad(0).Update()
stats1 = h1.GetListOfFunctions().FindObject("stats").Clone("stats1")
stats1.SetY1NDC(0.95)
stats1.SetY2NDC(0.75)
stats1.SetX1NDC(0.98)
stats1.SetX2NDC(0.75)
stats1.SetTextColor(1)

h2.Draw("sames")
c1.GetPad(0).Update()
stats2 = h2.GetListOfFunctions().FindObject("stats").Clone("stats2")
stats2.SetY1NDC(.75)
stats2.SetY2NDC(.55)
stats2.SetX1NDC(.98)
stats2.SetX2NDC(.75)
stats2.SetTextColor(2)

# h1.Draw("same")
stats1.Draw()
stats2.Draw()

l1.AddEntry(h1,var1)
l1.AddEntry(h2,var2)
l1.Draw()

l = ROOT.TLatex()
l.SetTextSize(0.050)
# l.DrawLatex(0.25, 2500, Cut.replace("eg_gen_pt","p_{T}^{gen}"))
# l.DrawLatexNDC(0.15, 0.5, Cut.replace("eg_gen_pt","p_{T}^{gen}"))
l.DrawLatexNDC(0.15, 0.5, str(pt_low) +" < p_{T}^{gen} < " + str(pt_high))

c1.SaveAs("mean_invTar_"+str(pt_low)+"_"+str(pt_high)+".png")

ROOT.gStyle.SetOptStat(0)

h3 = ROOT.TH2F("h3",";p_{T}^{gen};#frac{Raw Energy}{True Energy}",100, pt_low,  pt_high,144, 0.6, 1.2)
inTree.Draw(var1+":eg_gen_pt>>h3", Cut)
h3.Draw("colz")
c1.SaveAs("twoD_var1BeforeCorr_"+str(pt_low)+"_"+str(pt_high)+".png")



h4 = ROOT.TH2F("h4",";p_{T}^{gen};#frac{Raw Energy}{True Energy}",100, pt_low, pt_high, 144, 0.6, 1.2)
inTree.Draw(var2+":eg_gen_pt>>h4", Cut)
h4.Draw("colz")
c1.SaveAs("twoD_var2AfterCorr_"+str(pt_low)+"_"+str(pt_high)+".png")
