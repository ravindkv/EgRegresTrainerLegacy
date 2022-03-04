import ROOT
ROOT.gROOT.SetBatch(True)
ROOT.gStyle.SetOptStat(1111)

ThreeVar = False

var1 = "eg_rawEnergy/eg_gen_energy"
var2 = "eg_energy/eg_gen_energy"
var3 = "eg_rawEnergy/eg_gen_energy"
# var2 = "eg_energy/eg_gen_energy"
# var3 = "mean*invTar"
# var1 = "invTar"
# var2 = "regInvTar"
# var3 = "regMean*regInvTar"

pt_low = 20; pt_high = 60;
# pt_low = 60; pt_high = 200;

# Cut = "eg_gen_pt>20 && eg_gen_pt<200"
Cut = "eg_gen_pt>"+str(pt_low)+" && eg_gen_pt<" + str(pt_high)

# File output from training
# InputFile = "/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/results/resultsSC_MainNtuples_FullSelection_FlatNtuple/Run3HLT_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root";

# File from new crab output (having new reg. info loaded)
InputFile = "/tmp/rasharma/output_flat.root"

# // using latest v1 GT db file
# InputFile = "/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/ReRunHLT_WithDB/pfscecal_EBCorrection_online_Run3_120X_v1_Flat.root";
# // InputFile = "/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/ReRunHLT_WithDB/pfscecal_EBCorrection_online_Run3_120X_v1.root";

# InputFile = "results/resultsSC_CMSSW12X_15Feb/Run3HLT_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root"
# InputFile = "results/resultsSC_CMSSW12X_15Feb/Run3HLT_RealIC_IdealTraining_stdVar_stdCuts_ntrees1500_applied.root"
# InputFile = "/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_Arun/HLTAnalyzerTree_REAL.root"
# FriendInputFile = "/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_Arun/results/resultsSC_MainNtuples_FullSelection/Run3HLT_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root"
Tree1 = "egHLTRun3Tree"
# Tree2 = "egHLTRun3TreeFriend"

inFile = ROOT.TFile(InputFile)
# inFile = ROOT.TFile(FriendInputFile)
inTree = inFile.Get(Tree1)
# inTree.AddFriend(Tree2, FriendInputFile)
# inTree.AddFriend(Tree2, InputFile)

c1 = ROOT.TCanvas()
# c1.SetLogy(1)

l1 = ROOT.TLegend(0.1,0.70, 0.46,0.90)
h1 = ROOT.TH1F("h1",";;Entries",144, 0.0, 1.7)
h2 = ROOT.TH1F("h2",";;Entries",144, 0.0, 1.7)
if ThreeVar: h22 = ROOT.TH1F("h22",";;Entries",144, 0.0, 1.7)

h1.SetLineWidth(2)
h2.SetLineWidth(2)
if ThreeVar: h22.SetLineWidth(2)
h1.SetLineColor(1)
h2.SetLineColor(2)
if ThreeVar: h22.SetLineColor(3)

inTree.Draw(var1+">>h1", Cut)
inTree.Draw(var2+">>h2", Cut)
if ThreeVar: inTree.Draw(var3+">>h22", Cut)

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

if ThreeVar: h22.Draw("sames")
if ThreeVar: c1.GetPad(0).Update()
if ThreeVar: stats3 = h22.GetListOfFunctions().FindObject("stats").Clone("stats3")
if ThreeVar: stats3.SetY1NDC(.55)
if ThreeVar: stats3.SetY2NDC(.35)
if ThreeVar: stats3.SetX1NDC(.98)
if ThreeVar: stats3.SetX2NDC(.75)
if ThreeVar: stats3.SetTextColor(3)
# h1.Draw("same")
stats1.Draw()
stats2.Draw()
if ThreeVar: stats3.Draw()

l1.AddEntry(h1,var1)
l1.AddEntry(h2,var2)
if ThreeVar: l1.AddEntry(h22,var3)
l1.Draw()

l = ROOT.TLatex()
l.SetTextSize(0.050)
# l.DrawLatex(0.25, 2500, Cut.replace("eg_gen_pt","p_{T}^{gen}"))
# l.DrawLatexNDC(0.15, 0.5, Cut.replace("eg_gen_pt","p_{T}^{gen}"))
l.DrawLatexNDC(0.15, 0.5, str(pt_low) +" < p_{T}^{gen} < " + str(pt_high))

c1.SaveAs("mean_invTar_"+str(pt_low)+"_"+str(pt_high)+".png")
# c1.SaveAs("mean_invTar_"+str(pt_low)+"_"+str(pt_high)+"_v2.png")

ROOT.gStyle.SetOptStat(0)

h3 = ROOT.TH2F("h3",";p_{T}^{gen};#frac{Raw Energy}{True Energy}",100, pt_low,  pt_high,144, 0.0, 1.7)
inTree.Draw(var1+":eg_gen_pt>>h3", Cut)
h3.Draw("colz")
c1.SaveAs("twoD_var1BeforeCorr_"+str(pt_low)+"_"+str(pt_high)+".png")



h4 = ROOT.TH2F("h4",";p_{T}^{gen};#frac{Raw Energy}{True Energy}",100, pt_low, pt_high, 144, 0.0, 1.7)
inTree.Draw(var2+":eg_gen_pt>>h4", Cut)
h4.Draw("colz")
c1.SaveAs("twoD_var2AfterCorr_"+str(pt_low)+"_"+str(pt_high)+".png")

# inTree.Scan("eventnr:regInvTar:invTar:regMean:mean")
