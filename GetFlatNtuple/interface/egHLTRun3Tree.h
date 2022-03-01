//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Feb 28 21:35:35 2022 by ROOT version 6.22/09
// from TTree egHLTRun3Tree/
// found on file: /eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/HLTAnalyzerTree_REAL.root
//////////////////////////////////////////////////////////

#ifndef egHLTRun3Tree_h
#define egHLTRun3Tree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
// #include "L1AnalysisL1UpgradeDataFormat.h"

class egHLTRun3Tree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          runnr;
   UInt_t          lumiSec;
   UInt_t          eventnr;
   Int_t           bx;
   Float_t         nrHitsEB1GeV;
   Float_t         nrHitsEE1GeV;
 //L1Analysis::L1AnalysisL1UpgradeDataFormat *L1Upgrade;
   UShort_t        nEGs;
   vector<float>   egEt;
   vector<float>   egEta;
   vector<float>   egPhi;
   vector<short>   egIEt;
   vector<short>   egIEta;
   vector<short>   egIPhi;
   vector<short>   egIso;
   vector<short>   egBx;
   vector<short>   egTowerIPhi;
   vector<short>   egTowerIEta;
   vector<short>   egRawEt;
   vector<short>   egIsoEt;
   vector<short>   egFootprintEt;
   vector<short>   egNTT;
   vector<short>   egShape;
   vector<short>   egTowerHoE;
   vector<short>   egHwQual;
   UShort_t        nTaus;
   vector<float>   tauEt;
   vector<float>   tauEta;
   vector<float>   tauPhi;
   vector<short>   tauIEt;
   vector<short>   tauIEta;
   vector<short>   tauIPhi;
   vector<short>   tauIso;
   vector<short>   tauBx;
   vector<short>   tauTowerIPhi;
   vector<short>   tauTowerIEta;
   vector<short>   tauRawEt;
   vector<short>   tauIsoEt;
   vector<short>   tauNTT;
   vector<short>   tauHasEM;
   vector<short>   tauIsMerged;
   vector<short>   tauHwQual;
   UShort_t        nJets;
   vector<float>   jetEt;
   vector<float>   jetEta;
   vector<float>   jetPhi;
   vector<short>   jetIEt;
   vector<short>   jetIEta;
   vector<short>   jetIPhi;
   vector<short>   jetBx;
   vector<short>   jetTowerIPhi;
   vector<short>   jetTowerIEta;
   vector<short>   jetRawEt;
   vector<short>   jetSeedEt;
   vector<short>   jetPUEt;
   vector<short>   jetPUDonutEt0;
   vector<short>   jetPUDonutEt1;
   vector<short>   jetPUDonutEt2;
   vector<short>   jetPUDonutEt3;
   UShort_t        nMuons;
   vector<float>   muonEt;
   vector<float>   muonEtUnconstrained;
   vector<float>   muonEta;
   vector<float>   muonPhi;
   vector<float>   muonEtaAtVtx;
   vector<float>   muonPhiAtVtx;
   vector<short>   muonIEt;
   vector<short>   muonIEtUnconstrained;
   vector<short>   muonIEta;
   vector<short>   muonIPhi;
   vector<short>   muonIEtaAtVtx;
   vector<short>   muonIPhiAtVtx;
   vector<short>   muonIDEta;
   vector<short>   muonIDPhi;
   vector<short>   muonChg;
   vector<unsigned short> muonIso;
   vector<unsigned short> muonQual;
   vector<unsigned short> muonDxy;
   vector<unsigned short> muonTfMuonIdx;
   vector<short>   muonBx;
   UShort_t        nSums;
   vector<short>   sumType;
   vector<float>   sumEt;
   vector<float>   sumPhi;
   vector<short>   sumIEt;
   vector<short>   sumIPhi;
   vector<float>   sumBx;
   UInt_t          nrEgs;
   Float_t         eg_et[11];   //[nrEgs]
   Float_t         eg_energy[11];   //[nrEgs]
   Float_t         eg_rawEnergy[11];   //[nrEgs]
   Float_t         eg_eta[11];   //[nrEgs]
   Float_t         eg_phi[11];   //[nrEgs]
   Float_t         eg_phiWidth[11];   //[nrEgs]
   Int_t           eg_nrClus[11];   //[nrEgs]
   UInt_t          eg_seedId[11];   //[nrEgs]
   Int_t           eg_seedDet[11];   //[nrEgs]
   Float_t         eg_sigmaIEtaIEta[11];   //[nrEgs]
   Float_t         eg_sigmaIPhiIPhi[11];   //[nrEgs]
   Float_t         eg_sigmaIEtaIEtaNoise[11];   //[nrEgs]
   Float_t         eg_sigmaIPhiIPhiNoise[11];   //[nrEgs]
   Float_t         eg_ecalPFIsol[11];   //[nrEgs]
   Float_t         eg_hcalPFIsol[11];   //[nrEgs]
   Float_t         eg_trkIsol[11];   //[nrEgs]
   Float_t         eg_trkChi2[11];   //[nrEgs]
   Float_t         eg_trkMissHits[11];   //[nrEgs]
   Float_t         eg_trkValidHits[11];   //[nrEgs]
   Float_t         eg_invESeedInvP[11];   //[nrEgs]
   Float_t         eg_invEInvP[11];   //[nrEgs]
   Float_t         eg_trkDEta[11];   //[nrEgs]
   Float_t         eg_trkDEtaSeed[11];   //[nrEgs]
   Float_t         eg_trkDPhi[11];   //[nrEgs]
   Float_t         eg_trkNrLayerIT[11];   //[nrEgs]
   Float_t         eg_pms2[11];   //[nrEgs]
   Float_t         eg_hcalHForHoverE[11];   //[nrEgs]
   Float_t         eg_bestTrkChi2[11];   //[nrEgs]
   Float_t         eg_bestTrkDEta[11];   //[nrEgs]
   Float_t         eg_bestTrkDEtaSeed[11];   //[nrEgs]
   Float_t         eg_bestTrkDPhi[11];   //[nrEgs]
   Float_t         eg_bestTrkMissHits[11];   //[nrEgs]
   Float_t         eg_bestTrkNrLayerIT[11];   //[nrEgs]
   Float_t         eg_bestTrkESeedInvP[11];   //[nrEgs]
   Float_t         eg_bestTrkInvEInvP[11];   //[nrEgs]
   Float_t         eg_bestTrkValitHits[11];   //[nrEgs]
   Float_t         eg_clusterMaxDR[11];   //[nrEgs]
   Float_t         eg_r9Frac[11];   //[nrEgs]
   Float_t         eg_r9Full[11];   //[nrEgs]
   UChar_t         eg_isEB[11];   //[nrEgs]
   UChar_t         eg_isEE[11];   //[nrEgs]
   Float_t         eg_gen_energy[11];   //[nrEgs]
   Float_t         eg_gen_pt[11];   //[nrEgs]
   Float_t         eg_gen_et[11];   //[nrEgs]
   Float_t         eg_gen_eta[11];   //[nrEgs]
   Float_t         eg_gen_phi[11];   //[nrEgs]
   Float_t         eg_gen_vz[11];   //[nrEgs]
   Float_t         eg_l1eg_et[11];   //[nrEgs]
   Float_t         eg_l1eg_eta[11];   //[nrEgs]
   Float_t         eg_l1eg_phi[11];   //[nrEgs]
   Float_t         eg_l1eg_hwEt[11];   //[nrEgs]
   Float_t         eg_l1eg_hwEta[11];   //[nrEgs]
   Float_t         eg_l1eg_hwPhi[11];   //[nrEgs]
   Float_t         eg_l1eg_hwQual[11];   //[nrEgs]
   Float_t         eg_l1eg_iso[11];   //[nrEgs]
   Float_t         eg_l1eg_isoEt[11];   //[nrEgs]
   Float_t         eg_l1eg_nTT[11];   //[nrEgs]
   Float_t         eg_l1eg_footprintEt[11];   //[nrEgs]
   Float_t         eg_l1eg_shape[11];   //[nrEgs]
   Float_t         eg_l1eg_towerHoE[11];   //[nrEgs]
   UChar_t         path_Gen_QCDMuGenFilter;
   UChar_t         path_Gen_QCDBCToEFilter;
   UChar_t         path_Gen_QCDEmEnrichingFilter;
   UChar_t         path_Gen_QCDEmEnrichingNoBCToEFilter;

   // List of branches
   TBranch        *b_runnr;   //!
   TBranch        *b_lumiSec;   //!
   TBranch        *b_eventnr;   //!
   TBranch        *b_bx;   //!
   TBranch        *b_nrHitsEB1GeV;   //!
   TBranch        *b_nrHitsEE1GeV;   //!
   TBranch        *b_L1Upgrade_nEGs;   //!
   TBranch        *b_L1Upgrade_egEt;   //!
   TBranch        *b_L1Upgrade_egEta;   //!
   TBranch        *b_L1Upgrade_egPhi;   //!
   TBranch        *b_L1Upgrade_egIEt;   //!
   TBranch        *b_L1Upgrade_egIEta;   //!
   TBranch        *b_L1Upgrade_egIPhi;   //!
   TBranch        *b_L1Upgrade_egIso;   //!
   TBranch        *b_L1Upgrade_egBx;   //!
   TBranch        *b_L1Upgrade_egTowerIPhi;   //!
   TBranch        *b_L1Upgrade_egTowerIEta;   //!
   TBranch        *b_L1Upgrade_egRawEt;   //!
   TBranch        *b_L1Upgrade_egIsoEt;   //!
   TBranch        *b_L1Upgrade_egFootprintEt;   //!
   TBranch        *b_L1Upgrade_egNTT;   //!
   TBranch        *b_L1Upgrade_egShape;   //!
   TBranch        *b_L1Upgrade_egTowerHoE;   //!
   TBranch        *b_L1Upgrade_egHwQual;   //!
   TBranch        *b_L1Upgrade_nTaus;   //!
   TBranch        *b_L1Upgrade_tauEt;   //!
   TBranch        *b_L1Upgrade_tauEta;   //!
   TBranch        *b_L1Upgrade_tauPhi;   //!
   TBranch        *b_L1Upgrade_tauIEt;   //!
   TBranch        *b_L1Upgrade_tauIEta;   //!
   TBranch        *b_L1Upgrade_tauIPhi;   //!
   TBranch        *b_L1Upgrade_tauIso;   //!
   TBranch        *b_L1Upgrade_tauBx;   //!
   TBranch        *b_L1Upgrade_tauTowerIPhi;   //!
   TBranch        *b_L1Upgrade_tauTowerIEta;   //!
   TBranch        *b_L1Upgrade_tauRawEt;   //!
   TBranch        *b_L1Upgrade_tauIsoEt;   //!
   TBranch        *b_L1Upgrade_tauNTT;   //!
   TBranch        *b_L1Upgrade_tauHasEM;   //!
   TBranch        *b_L1Upgrade_tauIsMerged;   //!
   TBranch        *b_L1Upgrade_tauHwQual;   //!
   TBranch        *b_L1Upgrade_nJets;   //!
   TBranch        *b_L1Upgrade_jetEt;   //!
   TBranch        *b_L1Upgrade_jetEta;   //!
   TBranch        *b_L1Upgrade_jetPhi;   //!
   TBranch        *b_L1Upgrade_jetIEt;   //!
   TBranch        *b_L1Upgrade_jetIEta;   //!
   TBranch        *b_L1Upgrade_jetIPhi;   //!
   TBranch        *b_L1Upgrade_jetBx;   //!
   TBranch        *b_L1Upgrade_jetTowerIPhi;   //!
   TBranch        *b_L1Upgrade_jetTowerIEta;   //!
   TBranch        *b_L1Upgrade_jetRawEt;   //!
   TBranch        *b_L1Upgrade_jetSeedEt;   //!
   TBranch        *b_L1Upgrade_jetPUEt;   //!
   TBranch        *b_L1Upgrade_jetPUDonutEt0;   //!
   TBranch        *b_L1Upgrade_jetPUDonutEt1;   //!
   TBranch        *b_L1Upgrade_jetPUDonutEt2;   //!
   TBranch        *b_L1Upgrade_jetPUDonutEt3;   //!
   TBranch        *b_L1Upgrade_nMuons;   //!
   TBranch        *b_L1Upgrade_muonEt;   //!
   TBranch        *b_L1Upgrade_muonEtUnconstrained;   //!
   TBranch        *b_L1Upgrade_muonEta;   //!
   TBranch        *b_L1Upgrade_muonPhi;   //!
   TBranch        *b_L1Upgrade_muonEtaAtVtx;   //!
   TBranch        *b_L1Upgrade_muonPhiAtVtx;   //!
   TBranch        *b_L1Upgrade_muonIEt;   //!
   TBranch        *b_L1Upgrade_muonIEtUnconstrained;   //!
   TBranch        *b_L1Upgrade_muonIEta;   //!
   TBranch        *b_L1Upgrade_muonIPhi;   //!
   TBranch        *b_L1Upgrade_muonIEtaAtVtx;   //!
   TBranch        *b_L1Upgrade_muonIPhiAtVtx;   //!
   TBranch        *b_L1Upgrade_muonIDEta;   //!
   TBranch        *b_L1Upgrade_muonIDPhi;   //!
   TBranch        *b_L1Upgrade_muonChg;   //!
   TBranch        *b_L1Upgrade_muonIso;   //!
   TBranch        *b_L1Upgrade_muonQual;   //!
   TBranch        *b_L1Upgrade_muonDxy;   //!
   TBranch        *b_L1Upgrade_muonTfMuonIdx;   //!
   TBranch        *b_L1Upgrade_muonBx;   //!
   TBranch        *b_L1Upgrade_nSums;   //!
   TBranch        *b_L1Upgrade_sumType;   //!
   TBranch        *b_L1Upgrade_sumEt;   //!
   TBranch        *b_L1Upgrade_sumPhi;   //!
   TBranch        *b_L1Upgrade_sumIEt;   //!
   TBranch        *b_L1Upgrade_sumIPhi;   //!
   TBranch        *b_L1Upgrade_sumBx;   //!
   TBranch        *b_nrEgs;   //!
   TBranch        *b_eg_et;   //!
   TBranch        *b_eg_energy;   //!
   TBranch        *b_eg_rawEnergy;   //!
   TBranch        *b_eg_eta;   //!
   TBranch        *b_eg_phi;   //!
   TBranch        *b_eg_phiWidth;   //!
   TBranch        *b_eg_nrClus;   //!
   TBranch        *b_eg_seedId;   //!
   TBranch        *b_eg_seedDet;   //!
   TBranch        *b_eg_sigmaIEtaIEta;   //!
   TBranch        *b_eg_sigmaIPhiIPhi;   //!
   TBranch        *b_eg_sigmaIEtaIEtaNoise;   //!
   TBranch        *b_eg_sigmaIPhiIPhiNoise;   //!
   TBranch        *b_eg_ecalPFIsol;   //!
   TBranch        *b_eg_hcalPFIsol;   //!
   TBranch        *b_eg_trkIsol;   //!
   TBranch        *b_eg_trkChi2;   //!
   TBranch        *b_eg_trkMissHits;   //!
   TBranch        *b_eg_trkValidHits;   //!
   TBranch        *b_eg_invESeedInvP;   //!
   TBranch        *b_eg_invEInvP;   //!
   TBranch        *b_eg_trkDEta;   //!
   TBranch        *b_eg_trkDEtaSeed;   //!
   TBranch        *b_eg_trkDPhi;   //!
   TBranch        *b_eg_trkNrLayerIT;   //!
   TBranch        *b_eg_pms2;   //!
   TBranch        *b_eg_hcalHForHoverE;   //!
   TBranch        *b_eg_bestTrkChi2;   //!
   TBranch        *b_eg_bestTrkDEta;   //!
   TBranch        *b_eg_bestTrkDEtaSeed;   //!
   TBranch        *b_eg_bestTrkDPhi;   //!
   TBranch        *b_eg_bestTrkMissHits;   //!
   TBranch        *b_eg_bestTrkNrLayerIT;   //!
   TBranch        *b_eg_bestTrkESeedInvP;   //!
   TBranch        *b_eg_bestTrkInvEInvP;   //!
   TBranch        *b_eg_bestTrkValitHits;   //!
   TBranch        *b_eg_clusterMaxDR;   //!
   TBranch        *b_eg_r9Frac;   //!
   TBranch        *b_eg_r9Full;   //!
   TBranch        *b_eg_isEB;   //!
   TBranch        *b_eg_isEE;   //!
   TBranch        *b_eg_gen_energy;   //!
   TBranch        *b_eg_gen_pt;   //!
   TBranch        *b_eg_gen_et;   //!
   TBranch        *b_eg_gen_eta;   //!
   TBranch        *b_eg_gen_phi;   //!
   TBranch        *b_eg_gen_vz;   //!
   TBranch        *b_eg_l1eg_et;   //!
   TBranch        *b_eg_l1eg_eta;   //!
   TBranch        *b_eg_l1eg_phi;   //!
   TBranch        *b_eg_l1eg_hwEt;   //!
   TBranch        *b_eg_l1eg_hwEta;   //!
   TBranch        *b_eg_l1eg_hwPhi;   //!
   TBranch        *b_eg_l1eg_hwQual;   //!
   TBranch        *b_eg_l1eg_iso;   //!
   TBranch        *b_eg_l1eg_isoEt;   //!
   TBranch        *b_eg_l1eg_nTT;   //!
   TBranch        *b_eg_l1eg_footprintEt;   //!
   TBranch        *b_eg_l1eg_shape;   //!
   TBranch        *b_eg_l1eg_towerHoE;   //!
   TBranch        *b_path_Gen_QCDMuGenFilter;   //!
   TBranch        *b_path_Gen_QCDBCToEFilter;   //!
   TBranch        *b_path_Gen_QCDEmEnrichingFilter;   //!
   TBranch        *b_path_Gen_QCDEmEnrichingNoBCToEFilter;   //!

   egHLTRun3Tree(TTree *tree)
   {
   // if parameter tree is not specified (or zero), connect the file
   // used to generate this class and read the Tree.
      if (tree == 0) {
         TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/HLTAnalyzerTree_REAL.root");
         if (!f || !f->IsOpen()) {
            f = new TFile("/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/HLTAnalyzerTree_REAL.root");
         }
         f->GetObject("egHLTRun3Tree",tree);

      }
      Init(tree);
   }
   virtual ~egHLTRun3Tree()
   {
      if (!fChain) return;
      delete fChain->GetCurrentFile();
   }

   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
};

#endif

Int_t egHLTRun3Tree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}

Long64_t egHLTRun3Tree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
   }
   return centry;
}

void egHLTRun3Tree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("runnr", &runnr, &b_runnr);
   fChain->SetBranchAddress("lumiSec", &lumiSec, &b_lumiSec);
   fChain->SetBranchAddress("eventnr", &eventnr, &b_eventnr);
   fChain->SetBranchAddress("bx", &bx, &b_bx);
   fChain->SetBranchAddress("nrHitsEB1GeV", &nrHitsEB1GeV, &b_nrHitsEB1GeV);
   fChain->SetBranchAddress("nrHitsEE1GeV", &nrHitsEE1GeV, &b_nrHitsEE1GeV);
   fChain->SetBranchAddress("nEGs", &nEGs, &b_L1Upgrade_nEGs);
   fChain->SetBranchAddress("egEt", &egEt, &b_L1Upgrade_egEt);
   fChain->SetBranchAddress("egEta", &egEta, &b_L1Upgrade_egEta);
   fChain->SetBranchAddress("egPhi", &egPhi, &b_L1Upgrade_egPhi);
   fChain->SetBranchAddress("egIEt", &egIEt, &b_L1Upgrade_egIEt);
   fChain->SetBranchAddress("egIEta", &egIEta, &b_L1Upgrade_egIEta);
   fChain->SetBranchAddress("egIPhi", &egIPhi, &b_L1Upgrade_egIPhi);
   fChain->SetBranchAddress("egIso", &egIso, &b_L1Upgrade_egIso);
   fChain->SetBranchAddress("egBx", &egBx, &b_L1Upgrade_egBx);
   fChain->SetBranchAddress("egTowerIPhi", &egTowerIPhi, &b_L1Upgrade_egTowerIPhi);
   fChain->SetBranchAddress("egTowerIEta", &egTowerIEta, &b_L1Upgrade_egTowerIEta);
   fChain->SetBranchAddress("egRawEt", &egRawEt, &b_L1Upgrade_egRawEt);
   fChain->SetBranchAddress("egIsoEt", &egIsoEt, &b_L1Upgrade_egIsoEt);
   fChain->SetBranchAddress("egFootprintEt", &egFootprintEt, &b_L1Upgrade_egFootprintEt);
   fChain->SetBranchAddress("egNTT", &egNTT, &b_L1Upgrade_egNTT);
   fChain->SetBranchAddress("egShape", &egShape, &b_L1Upgrade_egShape);
   fChain->SetBranchAddress("egTowerHoE", &egTowerHoE, &b_L1Upgrade_egTowerHoE);
   fChain->SetBranchAddress("egHwQual", &egHwQual, &b_L1Upgrade_egHwQual);
   fChain->SetBranchAddress("nTaus", &nTaus, &b_L1Upgrade_nTaus);
   fChain->SetBranchAddress("tauEt", &tauEt, &b_L1Upgrade_tauEt);
   fChain->SetBranchAddress("tauEta", &tauEta, &b_L1Upgrade_tauEta);
   fChain->SetBranchAddress("tauPhi", &tauPhi, &b_L1Upgrade_tauPhi);
   fChain->SetBranchAddress("tauIEt", &tauIEt, &b_L1Upgrade_tauIEt);
   fChain->SetBranchAddress("tauIEta", &tauIEta, &b_L1Upgrade_tauIEta);
   fChain->SetBranchAddress("tauIPhi", &tauIPhi, &b_L1Upgrade_tauIPhi);
   fChain->SetBranchAddress("tauIso", &tauIso, &b_L1Upgrade_tauIso);
   fChain->SetBranchAddress("tauBx", &tauBx, &b_L1Upgrade_tauBx);
   fChain->SetBranchAddress("tauTowerIPhi", &tauTowerIPhi, &b_L1Upgrade_tauTowerIPhi);
   fChain->SetBranchAddress("tauTowerIEta", &tauTowerIEta, &b_L1Upgrade_tauTowerIEta);
   fChain->SetBranchAddress("tauRawEt", &tauRawEt, &b_L1Upgrade_tauRawEt);
   fChain->SetBranchAddress("tauIsoEt", &tauIsoEt, &b_L1Upgrade_tauIsoEt);
   fChain->SetBranchAddress("tauNTT", &tauNTT, &b_L1Upgrade_tauNTT);
   fChain->SetBranchAddress("tauHasEM", &tauHasEM, &b_L1Upgrade_tauHasEM);
   fChain->SetBranchAddress("tauIsMerged", &tauIsMerged, &b_L1Upgrade_tauIsMerged);
   fChain->SetBranchAddress("tauHwQual", &tauHwQual, &b_L1Upgrade_tauHwQual);
   fChain->SetBranchAddress("nJets", &nJets, &b_L1Upgrade_nJets);
   fChain->SetBranchAddress("jetEt", &jetEt, &b_L1Upgrade_jetEt);
   fChain->SetBranchAddress("jetEta", &jetEta, &b_L1Upgrade_jetEta);
   fChain->SetBranchAddress("jetPhi", &jetPhi, &b_L1Upgrade_jetPhi);
   fChain->SetBranchAddress("jetIEt", &jetIEt, &b_L1Upgrade_jetIEt);
   fChain->SetBranchAddress("jetIEta", &jetIEta, &b_L1Upgrade_jetIEta);
   fChain->SetBranchAddress("jetIPhi", &jetIPhi, &b_L1Upgrade_jetIPhi);
   fChain->SetBranchAddress("jetBx", &jetBx, &b_L1Upgrade_jetBx);
   fChain->SetBranchAddress("jetTowerIPhi", &jetTowerIPhi, &b_L1Upgrade_jetTowerIPhi);
   fChain->SetBranchAddress("jetTowerIEta", &jetTowerIEta, &b_L1Upgrade_jetTowerIEta);
   fChain->SetBranchAddress("jetRawEt", &jetRawEt, &b_L1Upgrade_jetRawEt);
   fChain->SetBranchAddress("jetSeedEt", &jetSeedEt, &b_L1Upgrade_jetSeedEt);
   fChain->SetBranchAddress("jetPUEt", &jetPUEt, &b_L1Upgrade_jetPUEt);
   fChain->SetBranchAddress("jetPUDonutEt0", &jetPUDonutEt0, &b_L1Upgrade_jetPUDonutEt0);
   fChain->SetBranchAddress("jetPUDonutEt1", &jetPUDonutEt1, &b_L1Upgrade_jetPUDonutEt1);
   fChain->SetBranchAddress("jetPUDonutEt2", &jetPUDonutEt2, &b_L1Upgrade_jetPUDonutEt2);
   fChain->SetBranchAddress("jetPUDonutEt3", &jetPUDonutEt3, &b_L1Upgrade_jetPUDonutEt3);
   fChain->SetBranchAddress("nMuons", &nMuons, &b_L1Upgrade_nMuons);
   fChain->SetBranchAddress("muonEt", &muonEt, &b_L1Upgrade_muonEt);
   fChain->SetBranchAddress("muonEtUnconstrained", &muonEtUnconstrained, &b_L1Upgrade_muonEtUnconstrained);
   fChain->SetBranchAddress("muonEta", &muonEta, &b_L1Upgrade_muonEta);
   fChain->SetBranchAddress("muonPhi", &muonPhi, &b_L1Upgrade_muonPhi);
   fChain->SetBranchAddress("muonEtaAtVtx", &muonEtaAtVtx, &b_L1Upgrade_muonEtaAtVtx);
   fChain->SetBranchAddress("muonPhiAtVtx", &muonPhiAtVtx, &b_L1Upgrade_muonPhiAtVtx);
   fChain->SetBranchAddress("muonIEt", &muonIEt, &b_L1Upgrade_muonIEt);
   fChain->SetBranchAddress("muonIEtUnconstrained", &muonIEtUnconstrained, &b_L1Upgrade_muonIEtUnconstrained);
   fChain->SetBranchAddress("muonIEta", &muonIEta, &b_L1Upgrade_muonIEta);
   fChain->SetBranchAddress("muonIPhi", &muonIPhi, &b_L1Upgrade_muonIPhi);
   fChain->SetBranchAddress("muonIEtaAtVtx", &muonIEtaAtVtx, &b_L1Upgrade_muonIEtaAtVtx);
   fChain->SetBranchAddress("muonIPhiAtVtx", &muonIPhiAtVtx, &b_L1Upgrade_muonIPhiAtVtx);
   fChain->SetBranchAddress("muonIDEta", &muonIDEta, &b_L1Upgrade_muonIDEta);
   fChain->SetBranchAddress("muonIDPhi", &muonIDPhi, &b_L1Upgrade_muonIDPhi);
   fChain->SetBranchAddress("muonChg", &muonChg, &b_L1Upgrade_muonChg);
   fChain->SetBranchAddress("muonIso", &muonIso, &b_L1Upgrade_muonIso);
   fChain->SetBranchAddress("muonQual", &muonQual, &b_L1Upgrade_muonQual);
   fChain->SetBranchAddress("muonDxy", &muonDxy, &b_L1Upgrade_muonDxy);
   fChain->SetBranchAddress("muonTfMuonIdx", &muonTfMuonIdx, &b_L1Upgrade_muonTfMuonIdx);
   fChain->SetBranchAddress("muonBx", &muonBx, &b_L1Upgrade_muonBx);
   fChain->SetBranchAddress("nSums", &nSums, &b_L1Upgrade_nSums);
   fChain->SetBranchAddress("sumType", &sumType, &b_L1Upgrade_sumType);
   fChain->SetBranchAddress("sumEt", &sumEt, &b_L1Upgrade_sumEt);
   fChain->SetBranchAddress("sumPhi", &sumPhi, &b_L1Upgrade_sumPhi);
   fChain->SetBranchAddress("sumIEt", &sumIEt, &b_L1Upgrade_sumIEt);
   fChain->SetBranchAddress("sumIPhi", &sumIPhi, &b_L1Upgrade_sumIPhi);
   fChain->SetBranchAddress("sumBx", &sumBx, &b_L1Upgrade_sumBx);
   fChain->SetBranchAddress("nrEgs", &nrEgs, &b_nrEgs);
   fChain->SetBranchAddress("eg_et", eg_et, &b_eg_et);
   fChain->SetBranchAddress("eg_energy", eg_energy, &b_eg_energy);
   fChain->SetBranchAddress("eg_rawEnergy", eg_rawEnergy, &b_eg_rawEnergy);
   fChain->SetBranchAddress("eg_eta", eg_eta, &b_eg_eta);
   fChain->SetBranchAddress("eg_phi", eg_phi, &b_eg_phi);
   fChain->SetBranchAddress("eg_phiWidth", eg_phiWidth, &b_eg_phiWidth);
   fChain->SetBranchAddress("eg_nrClus", eg_nrClus, &b_eg_nrClus);
   fChain->SetBranchAddress("eg_seedId", eg_seedId, &b_eg_seedId);
   fChain->SetBranchAddress("eg_seedDet", eg_seedDet, &b_eg_seedDet);
   fChain->SetBranchAddress("eg_sigmaIEtaIEta", eg_sigmaIEtaIEta, &b_eg_sigmaIEtaIEta);
   fChain->SetBranchAddress("eg_sigmaIPhiIPhi", eg_sigmaIPhiIPhi, &b_eg_sigmaIPhiIPhi);
   fChain->SetBranchAddress("eg_sigmaIEtaIEtaNoise", eg_sigmaIEtaIEtaNoise, &b_eg_sigmaIEtaIEtaNoise);
   fChain->SetBranchAddress("eg_sigmaIPhiIPhiNoise", eg_sigmaIPhiIPhiNoise, &b_eg_sigmaIPhiIPhiNoise);
   fChain->SetBranchAddress("eg_ecalPFIsol", eg_ecalPFIsol, &b_eg_ecalPFIsol);
   fChain->SetBranchAddress("eg_hcalPFIsol", eg_hcalPFIsol, &b_eg_hcalPFIsol);
   fChain->SetBranchAddress("eg_trkIsol", eg_trkIsol, &b_eg_trkIsol);
   fChain->SetBranchAddress("eg_trkChi2", eg_trkChi2, &b_eg_trkChi2);
   fChain->SetBranchAddress("eg_trkMissHits", eg_trkMissHits, &b_eg_trkMissHits);
   fChain->SetBranchAddress("eg_trkValidHits", eg_trkValidHits, &b_eg_trkValidHits);
   fChain->SetBranchAddress("eg_invESeedInvP", eg_invESeedInvP, &b_eg_invESeedInvP);
   fChain->SetBranchAddress("eg_invEInvP", eg_invEInvP, &b_eg_invEInvP);
   fChain->SetBranchAddress("eg_trkDEta", eg_trkDEta, &b_eg_trkDEta);
   fChain->SetBranchAddress("eg_trkDEtaSeed", eg_trkDEtaSeed, &b_eg_trkDEtaSeed);
   fChain->SetBranchAddress("eg_trkDPhi", eg_trkDPhi, &b_eg_trkDPhi);
   fChain->SetBranchAddress("eg_trkNrLayerIT", eg_trkNrLayerIT, &b_eg_trkNrLayerIT);
   fChain->SetBranchAddress("eg_pms2", eg_pms2, &b_eg_pms2);
   fChain->SetBranchAddress("eg_hcalHForHoverE", eg_hcalHForHoverE, &b_eg_hcalHForHoverE);
   fChain->SetBranchAddress("eg_bestTrkChi2", eg_bestTrkChi2, &b_eg_bestTrkChi2);
   fChain->SetBranchAddress("eg_bestTrkDEta", eg_bestTrkDEta, &b_eg_bestTrkDEta);
   fChain->SetBranchAddress("eg_bestTrkDEtaSeed", eg_bestTrkDEtaSeed, &b_eg_bestTrkDEtaSeed);
   fChain->SetBranchAddress("eg_bestTrkDPhi", eg_bestTrkDPhi, &b_eg_bestTrkDPhi);
   fChain->SetBranchAddress("eg_bestTrkMissHits", eg_bestTrkMissHits, &b_eg_bestTrkMissHits);
   fChain->SetBranchAddress("eg_bestTrkNrLayerIT", eg_bestTrkNrLayerIT, &b_eg_bestTrkNrLayerIT);
   fChain->SetBranchAddress("eg_bestTrkESeedInvP", eg_bestTrkESeedInvP, &b_eg_bestTrkESeedInvP);
   fChain->SetBranchAddress("eg_bestTrkInvEInvP", eg_bestTrkInvEInvP, &b_eg_bestTrkInvEInvP);
   fChain->SetBranchAddress("eg_bestTrkValitHits", eg_bestTrkValitHits, &b_eg_bestTrkValitHits);
   fChain->SetBranchAddress("eg_clusterMaxDR", eg_clusterMaxDR, &b_eg_clusterMaxDR);
   fChain->SetBranchAddress("eg_r9Frac", eg_r9Frac, &b_eg_r9Frac);
   fChain->SetBranchAddress("eg_r9Full", eg_r9Full, &b_eg_r9Full);
   fChain->SetBranchAddress("eg_isEB", eg_isEB, &b_eg_isEB);
   fChain->SetBranchAddress("eg_isEE", eg_isEE, &b_eg_isEE);
   fChain->SetBranchAddress("eg_gen_energy", eg_gen_energy, &b_eg_gen_energy);
   fChain->SetBranchAddress("eg_gen_pt", eg_gen_pt, &b_eg_gen_pt);
   fChain->SetBranchAddress("eg_gen_et", eg_gen_et, &b_eg_gen_et);
   fChain->SetBranchAddress("eg_gen_eta", eg_gen_eta, &b_eg_gen_eta);
   fChain->SetBranchAddress("eg_gen_phi", eg_gen_phi, &b_eg_gen_phi);
   fChain->SetBranchAddress("eg_gen_vz", eg_gen_vz, &b_eg_gen_vz);
   fChain->SetBranchAddress("eg_l1eg_et", eg_l1eg_et, &b_eg_l1eg_et);
   fChain->SetBranchAddress("eg_l1eg_eta", eg_l1eg_eta, &b_eg_l1eg_eta);
   fChain->SetBranchAddress("eg_l1eg_phi", eg_l1eg_phi, &b_eg_l1eg_phi);
   fChain->SetBranchAddress("eg_l1eg_hwEt", eg_l1eg_hwEt, &b_eg_l1eg_hwEt);
   fChain->SetBranchAddress("eg_l1eg_hwEta", eg_l1eg_hwEta, &b_eg_l1eg_hwEta);
   fChain->SetBranchAddress("eg_l1eg_hwPhi", eg_l1eg_hwPhi, &b_eg_l1eg_hwPhi);
   fChain->SetBranchAddress("eg_l1eg_hwQual", eg_l1eg_hwQual, &b_eg_l1eg_hwQual);
   fChain->SetBranchAddress("eg_l1eg_iso", eg_l1eg_iso, &b_eg_l1eg_iso);
   fChain->SetBranchAddress("eg_l1eg_isoEt", eg_l1eg_isoEt, &b_eg_l1eg_isoEt);
   fChain->SetBranchAddress("eg_l1eg_nTT", eg_l1eg_nTT, &b_eg_l1eg_nTT);
   fChain->SetBranchAddress("eg_l1eg_footprintEt", eg_l1eg_footprintEt, &b_eg_l1eg_footprintEt);
   fChain->SetBranchAddress("eg_l1eg_shape", eg_l1eg_shape, &b_eg_l1eg_shape);
   fChain->SetBranchAddress("eg_l1eg_towerHoE", eg_l1eg_towerHoE, &b_eg_l1eg_towerHoE);
   fChain->SetBranchAddress("path_Gen_QCDMuGenFilter", &path_Gen_QCDMuGenFilter, &b_path_Gen_QCDMuGenFilter);
   fChain->SetBranchAddress("path_Gen_QCDBCToEFilter", &path_Gen_QCDBCToEFilter, &b_path_Gen_QCDBCToEFilter);
   fChain->SetBranchAddress("path_Gen_QCDEmEnrichingFilter", &path_Gen_QCDEmEnrichingFilter, &b_path_Gen_QCDEmEnrichingFilter);
   fChain->SetBranchAddress("path_Gen_QCDEmEnrichingNoBCToEFilter", &path_Gen_QCDEmEnrichingNoBCToEFilter, &b_path_Gen_QCDEmEnrichingNoBCToEFilter);
}
