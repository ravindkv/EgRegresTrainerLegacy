from numbers import Integral
import ROOT
import argparse
ROOT.gROOT.SetBatch(True)
ROOT.gStyle.SetOptStat(0)

parser = argparse.ArgumentParser(description='plot the output of SC regression trainings')
parser.add_argument('--input_dir','-i',default='/eos/cms/store/group/phys_egamma/ec/rverma/egammaRegChain/s5Reg/DoublePhoton_Pt-5To300_gun',help='input directory with the ntuples')
args = parser.parse_args()

#Ratio of energies
r = "eg_energy/eg_gen_energy"
rRaw = "eg_rawEnergy/eg_gen_energy"
rReg = "regInvTar*regMean"# this equivalent to rRaw

fIdeal = ROOT.TFile("%s/Run3HLT_IdealIC_IdealTraining_stdVar_stdCuts_ntrees1500_applied.root"%args.input_dir)
fReal  = ROOT.TFile("%s/Run3HLT_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root"%args.input_dir)
print("%s\n%s"%(fIdeal, fReal))

tName   = "egHLTRun3Tree"
tIdeal  = fIdeal.Get(tName)
tReal   = fReal.Get(tName)

hInfo = {}
hInfo["hIdeal"] = [tIdeal, r, "IdealIC"] 
hInfo["hReal"]  = [tReal,  r, "RealIC"] 
hInfo["hRawIdeal"] = [tIdeal, rRaw, "IdealIC"] 
hInfo["hRawReal"]  = [tReal,  rRaw, "RealIC"] 
hInfo["hRegIdeal"] = [tIdeal, rReg, "IdealIC"] 
hInfo["hRegReal"]  = [tReal,  rReg, "RealIC"] 


suffix = "Applied_Ext"; suffix_symbol = "<"
nBins = 108; minX = 0.73; maxX = 1.2;   pt_low = 60; pt_high = 200; etaCutVal = 3.0; etaCut = "abs(eg_gen_eta)  "+suffix_symbol+" "+str(etaCutVal);
Cut = "eg_gen_pt>"+str(pt_low)+" && eg_gen_pt<" + str(pt_high) + " && " + etaCut
print(Cut)

hists = []
yMax  = []
for h in hInfo.keys():
    hist = ROOT.TH1F(h,";E^{reco}/E^{gen};Entries", nBins, minX, maxX)
    hists.append(hist)
    hInfo[h][0].Draw(hInfo[h][1]+">>%s"%h, Cut)
    print(hist.Integral())
    yMax.append(hist.GetMaximum())

leg = ROOT.TLegend(0.1,0.60, 0.56,0.90)
leg.SetFillStyle(0);
leg.SetBorderSize(0);
leg.SetTextFont(42);
leg.SetTextAngle(0);
leg.SetTextSize(0.035);
leg.SetTextAlign(12);
c1 = ROOT.TCanvas()
c1.cd()
for index, hist in enumerate(hists):
    hist.SetLineWidth(2)
    hist.SetLineColor(index+1)
    #hist.SetMaximum(ROOT.TMath.Max(1.1*hist.GetMaximum()))
    if index==0:
        hist.Draw("HIST")
        hist.SetMaximum(1.2*max(yMax))
    else:
        hist.Draw("Histsame")
    var = hInfo[hist.GetName()][1]
    ic  = hInfo[hist.GetName()][2]
    int_   = round(hist.Integral(), 2)
    mean   = round(hist.GetMean(), 2)
    rms    = round(hist.GetRMS(), 2)
    legLabel = "%s, %s: %s, %s, %s"%(ic, var, int_, mean, rms)
    leg.AddEntry(hist, legLabel)
    c1.Update()
leg.Draw()

l = ROOT.TLatex()
l.SetTextSize(0.050)
l.DrawLatexNDC(0.15, 0.5, str(pt_low) +" < p_{T}^{gen} < " + str(pt_high))
l.DrawLatexNDC(0.15, 0.4,"| #eta^{gen} | " + suffix_symbol + str(etaCutVal))

out = "mean_invTar_"+str(pt_low)+"_"+str(pt_high)+"_"+str(etaCutVal).replace(".","p")+"_"+suffix+".pdf"
c1.SaveAs("%s/%s"%(args.input_dir, out))
