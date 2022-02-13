void Plot_mean(){
    // TFile *f = new TFile("Run3HLT_RealIC_IdealTraining_stdVar_stdCuts_ntrees1500_applied.root");
    TFile *f = new TFile("/eos/home-a/arun/EGMRegression_rootFiles/inputrootfiles/results/Run3HLT_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root");
    // TFile *f = new TFile("/eos/home-a/arun/EGMRegression_rootFiles/inputrootfiles/results/fromRobert/regEleEcal2021Run3_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root");
    TTree *T  = (TTree*)f->Get("egHLTRun3Tree");
    // TTree *T  = (TTree*)f->Get("egHLTRun3TreeFriend");
    T->AddFriend("egHLTRun3TreeFriend","/eos/home-a/arun/EGMRegression_rootFiles/inputrootfiles/results/Run3HLT_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root");

    TCanvas* c1 = new TCanvas();
    // c1->SetLogy(1);
    // TLegend* l1 = new TLegend(0.60,0.70, 0.96,0.90);
    TLegend* l1 = new TLegend(0.15,0.70, 0.36,0.90);
    TH1F* h1 = new TH1F("h1","",144, 0.7, 1.3);
    TH1F* h2 = new TH1F("h2","",144, 0.7, 1.3);
    h1->SetLineWidth(2);
    h2->SetLineWidth(2);
    h1->SetLineColor(1);
    h2->SetLineColor(2);
    T->Draw("eg_energy/eg_gen_energy>>h1","eg_gen_energy>0 && eg_gen_energy<100");
    T->Draw("mean*invTar>>h2","eg_gen_energy>0 && eg_gen_energy<100");
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
    h1->Draw();
    h2->Draw("sames");
    l1->AddEntry(h1,"eg_energy/eg_gen_energy");
    // l1->AddEntry(h2,"mean<1.047828 || mean>1.047829");
    l1->AddEntry(h2,"mean*invTar");
    l1->Draw();
    c1->SaveAs("mean.png");
}
