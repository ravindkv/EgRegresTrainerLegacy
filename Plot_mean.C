void Plot_mean(){
    gStyle->SetOptStat(1111);

    // TFile *f = new TFile("Run3HLT_RealIC_IdealTraining_stdVar_stdCuts_ntrees1500_applied.root");
    // TFile *f = new TFile("/eos/home-a/arun/EGMRegression_rootFiles/inputrootfiles/results/Run3HLT_IdealIC_IdealTraining_stdVar_stdCuts_ntrees1500_applied.root");
    // TFile *f = new TFile("/eos/home-a/arun/EGMRegression_rootFiles/inputrootfiles/results/fromRobert/regEleEcal2021Run3_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root");
    // TFile *f = new TFile("/eos/home-a/arun/EGMRegression_rootFiles/inputrootfiles/results/Run3HLT_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root");
    // TFile *f = new TFile("results/resultsSC_CMSSW12X_15Feb/Run3HLT_IdealIC_IdealTraining_stdVar_stdCuts_ntrees1500_applied.root");
    TFile *f = new TFile("results/resultsSC_CMSSW12X_15Feb/Run3HLT_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root");
    // TTree *T  = (TTree*)f->Get("egRegTreeFriend");
    TTree *T  = (TTree*)f->Get("egHLTRun3Tree");
    // TTree *T  = (TTree*)f->Get("egHLTRun3TreeFriend");
    T->AddFriend("egHLTRun3TreeFriend","results/resultsSC_CMSSW12X_15Feb/Run3HLT_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root");

    TCanvas* c1 = new TCanvas();
    c1->SetLogy(1);
    // TLegend* l1 = new TLegend(0.60,0.70, 0.96,0.90);
    TLegend* l1 = new TLegend(0.15,0.70, 0.46,0.90);
    TH1F* h1 = new TH1F("h1","",144, 0.2, 1.6);
    TH1F* h2 = new TH1F("h2","",144, 0.2, 1.6);
    h1->SetLineWidth(2);
    h2->SetLineWidth(2);
    h1->SetLineColor(1);
    h2->SetLineColor(2);
    // T->Draw("eg_energy/eg_gen_energy>>h1","eg_gen_pt<100 && (regMean < 1.176055 || regMean > 1.17607)");
    // T->Draw("eg_energy/eg_gen_energy>>h1","eg_gen_pt<100");
    T->Draw("eg_energy/eg_gen_energy>>h1","eg_gen_pt<3 && eg_gen_pt<12");
    // T->Draw("invTar>>h1");
    T->Draw("mean*invTar>>h2","eg_gen_pt<3 && eg_gen_pt<12");
    // T->Draw("regMean*regInvTar>>h2");
    // T->Draw("regInvTar>>h2");
    // T->Draw("regMean>>h2","regMean>1.02 && regMean<1.04");
    // T->Draw("regMean*regInvTar>>h2","regMean != 1.0316001","eg_gen_pt<100");
    // T->Draw("regMean*regInvTar>>h2","eg_gen_pt<100 && (regMean < 1.176055 || regMean > 1.17607)");
    // T->Draw("regMean*regInvTar>>h2","eg_gen_pt<100");
    // T->Draw("regMean*regInvTar>>h2","(regMean > 1.03161 || regMean<1.03162) && eg_gen_pt<100");
    // T->Draw("regMean*regInvTar>>h2","eg_gen_pt<100");
    // h2->Fit("gaus");
    // T->Draw("mean*invTar>>h2","eg_gen_energy>0 && eg_sigmaIEtaIEta>0 && eg_sigmaIPhiIPhi>0 && eg_isEB==1");

    // T->Draw("invTar>>h1");
    // T->Draw("invTar>>h2","eg_gen_energy>0 && eg_sigmaIEtaIEta>0 && eg_sigmaIPhiIPhi>0 && eg_isEB==1 && nrEgs>0");

    // T->Draw("1>>h1");
    // T->Draw("2>>h2","eventnr == evt.eventnr");
    // T->Draw("eg_rawEnergy>>h2","eg_gen_energy>0 && eg_sigmaIEtaIEta>0 && eg_sigmaIPhiIPhi>0 && eg_isEB==1 && nrEgs>0");
    // T->Draw("invTar>>h2","mean>1.047828 && mean<1.047829");
    // T->Draw("invTar>>h2","eventnr==evt.eventnr && lumiSec==evt.lumiSec");
    // T->Draw("mean>>h2","eventnr>0");
    // T->Draw("mean>>h2","eventnr == egHLTRun3TreeFriend.eventnr");
    // T->Draw("mean>>h2","evt.eventnr>0");


    // T->Draw("eg_rawEnergy>>h1");
    // // T->Draw("eg_rawEnergy>>h2","eg_gen_energy>0 && eg_sigmaIEtaIEta>0 && eg_sigmaIPhiIPhi>0 && eg_isEB==1 && nrEgs>0");
    // T->Draw("eg_rawEnergy>>h2","mean>1.047828 && mean<1.047829");

    h1->SetMaximum(TMath::Max(h1->GetMaximum()*1.1,h2->GetMaximum()*1.1));
    // h1->Scale(1./h1->Integral());
    // h2->Scale(1./h2->Integral());

        // c1->GetPad(index+1).Update()
        // stats1 = h1->GetListOfFunctions()->FindObject("stats")->Clone("stats1")
        // stats1->SetY1NDC(.5)
        // stats1->SetY2NDC(.7)
        // histo2.Draw()
        // c1->GetPad(index+1).Update()
        // stats2 = histo2.GetListOfFunctions().FindObject("stats").Clone("stats2")
        // # move stats2 where you want it to be
        // histo1.Draw("same")
        // stats1.Draw()
        // stats2.Draw()

    h1->Draw();
    c1->Update();
    TPaveStats *stats =(TPaveStats*)c1->GetPrimitive("stats");
    stats->SetName("h1stats");
    stats->SetY1NDC(.9);
    stats->SetY2NDC(.7);
    stats->SetX1NDC(.9);
    stats->SetX2NDC(.7);
    stats->SetTextColor(1);

    h2->Draw("sames");
    c1->Update();
    TPaveStats *stats2 =(TPaveStats*)c1->GetPrimitive("stats");
    stats2->SetName("h2stats");
    stats2->SetY1NDC(.7);
    stats2->SetY2NDC(.5);
    stats2->SetX1NDC(.9);
    stats2->SetX2NDC(.7);
    stats2->SetTextColor(2);
    l1->AddEntry(h1,"invTar");
    // l1->AddEntry(h1,"eg_energy/eg_gen_energy");
    // l1->AddEntry(h2,"mean<1.047828 || mean>1.047829");
    l1->AddEntry(h2,"mean*invTar");
    l1->Draw();
    c1->SaveAs("mean_invTar.png");
}
