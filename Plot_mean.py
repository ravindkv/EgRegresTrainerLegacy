from numbers import Integral
import ROOT
import argparse
ROOT.gROOT.SetBatch(True)
ROOT.gStyle.SetOptStat(1111)

var1 = "eg_rawEnergy/eg_gen_energy"
var2 = "eg_energy/eg_gen_energy"
var3 = "eg_energy/eg_gen_energy" # should be read using old corr root file

parser = argparse.ArgumentParser(description='plot the output of SC regression trainings')
parser.add_argument('--input_dir','-i',default='/eos/cms/store/group/phys_egamma/ec/rverma/egammaRegChain/s5Reg/DoublePhoton_Pt-5To300_gun',help='input directory with the ntuples')
args = parser.parse_args()


InputFile = "%s/Run3HLT_IdealIC_IdealTraining_stdVar_stdCuts_ntrees1500_applied.root"%args.input_dir
InputFile_UnCorr = "%s/Run3HLT_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root"%args.input_dir
Tree1 = "egHLTRun3Tree"
Tree_Uncorr = "egHLTRun3Tree"

inFile = ROOT.TFile(InputFile)
inFile_UnCorr = ROOT.TFile(InputFile_UnCorr)

inTree = inFile.Get(Tree1)
inTree_UnCorr = inFile_UnCorr.Get(Tree_Uncorr)

c1 = ROOT.TCanvas()
# c1.SetLogy(1)

# suffix = "EndCap"; suffix_symbol = ">"
#suffix = "Barrel_Ext"; suffix_symbol = "<"
suffix = "Applied_Ext"; suffix_symbol = "<"

# nBins = 51; minX = 0.5; maxX = 1.5;       pt_low = 3;  pt_high = 10; etaCutVal = 3.0; etaCut = "abs(eg_gen_eta)  "+suffix_symbol+" "+str(etaCutVal);
# nBins = 51; minX = 0.1; maxX = 1.7;       pt_low = 3;  pt_high = 10; etaCutVal = 3.0; etaCut = "abs(eg_gen_eta)  "+suffix_symbol+" "+str(etaCutVal);

# nBins = 108; minX = 0.6; maxX = 1.2;     pt_low = 10; pt_high = 20; etaCutVal = 3.0; etaCut = "abs(eg_gen_eta)  "+suffix_symbol+" "+str(etaCutVal);
# nBins = 108; minX = 0.1; maxX = 1.6;     pt_low = 10; pt_high = 20; etaCutVal = 3.0; etaCut = "abs(eg_gen_eta)  "+suffix_symbol+" "+str(etaCutVal);

# nBins = 108; minX = 0.7; maxX = 1.15;     pt_low = 20; pt_high = 60; etaCutVal = 3.0; etaCut = "abs(eg_gen_eta)  "+suffix_symbol+" "+str(etaCutVal);
# nBins = 108; minX = 0.5; maxX = 1.30;     pt_low = 20; pt_high = 60; etaCutVal = 3.0; etaCut = "abs(eg_gen_eta)  "+suffix_symbol+" "+str(etaCutVal);

nBins = 108; minX = 0.73; maxX = 1.2;   pt_low = 60; pt_high = 200; etaCutVal = 3.0; etaCut = "abs(eg_gen_eta)  "+suffix_symbol+" "+str(etaCutVal);
# nBins = 108; minX = 0.88; maxX = 1.07; pt_low = 60; pt_high = 200; etaCutVal = 3.0; etaCut = "abs(eg_gen_eta)  "+suffix_symbol+" "+str(etaCutVal);

# Cut = "eg_gen_pt>20 && eg_gen_pt<200"
Cut = "eg_gen_pt>"+str(pt_low)+" && eg_gen_pt<" + str(pt_high) + " && " + etaCut

h1 = ROOT.TH1F("h1",";E^{reco}/E^{gen};Entries", nBins, minX, maxX)
h2 = ROOT.TH1F("h2",";E^{reco}/E^{gen};Entries", nBins, minX, maxX)
h3 = ROOT.TH1F("h3",";E^{reco}/E^{gen};Entries", nBins, minX, maxX)

h1.SetLineWidth(2)
h2.SetLineWidth(2)
h3.SetLineWidth(2)

h1.SetLineColor(1)
h2.SetLineColor(2)
h3.SetLineColor(3)

inTree.Draw(var1+">>h1", Cut)
inTree.Draw(var2+">>h2", Cut)
inTree_UnCorr.Draw(var3+">>h3", Cut)

h1.Scale(1./h1.Integral())
h2.Scale(1./h2.Integral())
h3.Scale(1./h3.Integral())

h1.SetMaximum(ROOT.TMath.Max(h1.GetMaximum()*1.1,h2.GetMaximum()*1.1))
h1.SetMaximum(ROOT.TMath.Max(h1.GetMaximum()*1.1,h3.GetMaximum()*1.1))
h1.Draw()
c1.GetPad(0).Update()
stats1 = h1.GetListOfFunctions().FindObject("stats").Clone("stats1")
stats1.SetY1NDC(0.95)
stats1.SetY2NDC(0.75)
stats1.SetX1NDC(0.98)
stats1.SetX2NDC(0.75)
stats1.SetTextColor(1)


h3.Draw("sames")
c1.GetPad(0).Update()
stats3 = h3.GetListOfFunctions().FindObject("stats").Clone("stats3")
stats3.SetY1NDC(.75)
stats3.SetY2NDC(.55)
stats3.SetX1NDC(.98)
stats3.SetX2NDC(.75)
stats3.SetTextColor(3)

h2.Draw("sames")
c1.GetPad(0).Update()
stats2 = h2.GetListOfFunctions().FindObject("stats").Clone("stats2")
stats2.SetY1NDC(.55)
stats2.SetY2NDC(.35)
stats2.SetX1NDC(.98)
stats2.SetX2NDC(.75)
stats2.SetTextColor(2)

# h1.Draw("same")
stats1.Draw()
stats3.Draw()
stats2.Draw()

l1 = ROOT.TLegend(0.1,0.70, 0.46,0.90)
l1.AddEntry(h1,"Raw")
l1.AddEntry(h3,"Corr Old")
l1.AddEntry(h2,"Corr New")
l1.Draw()

l = ROOT.TLatex()
l.SetTextSize(0.050)
l.DrawLatexNDC(0.15, 0.5, str(pt_low) +" < p_{T}^{gen} < " + str(pt_high))
l.DrawLatexNDC(0.15, 0.4,"| #eta^{gen} | " + suffix_symbol + str(etaCutVal))

out = "mean_invTar_"+str(pt_low)+"_"+str(pt_high)+"_"+str(etaCutVal).replace(".","p")+"_"+suffix+".png"
c1.SaveAs("%s/%s"%(args.input_dir, out))
