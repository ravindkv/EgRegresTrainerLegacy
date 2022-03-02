#ifndef OUTPUT_HH
#define OUTPUT_HH

#include "TTree.h"

class output{

public:

  output(TTree *t) {
    fTree = t;
    init(fTree);
  };

  ~output() {
    delete fTree;
  };

  void clearVars();
  virtual void init(TTree *tree);

  TTree *fTree;

  //------------------------------------//
  //       METADATA AND EVENT WEIGHTS   //
  //------------------------------------//

  UInt_t   runnr   = 0;
  UInt_t   lumiSec = 0;
  UInt_t   eventnr = 0;

  Float_t   nrHitsEB1GeV = -999.0;
  Float_t   nrHitsEE1GeV = -999.0;

  Float_t   eg_et   = -999.0;
  Float_t   eg_energy   = -999.0;
  Float_t   eg_rawEnergy   = -999.0;
  Float_t   eg_eta   = -999.0;
  Float_t   eg_phi   = -999.0;
  Float_t   eg_phiWidth   = -999.0;
  Float_t   eg_nrClus   = -999.0;
  Float_t   eg_seedId   = -999.0;
  Float_t   eg_seedDet   = -999.0;
  Float_t   eg_sigmaIEtaIEta   = -999.0;
  Float_t   eg_sigmaIPhiIPhi   = -999.0;
  Float_t   eg_sigmaIEtaIEtaNoise   = -999.0;
  Float_t   eg_sigmaIPhiIPhiNoise   = -999.0;
  Float_t   eg_clusterMaxDR   = -999.0;
  Float_t   eg_r9Frac   = -999.0;
  Float_t   eg_r9Full   = -999.0;
  Float_t   eg_isEB   = -999.0;
  Float_t   eg_isEE   = -999.0;
  Float_t   eg_gen_energy   = -999.0;
  Float_t   eg_gen_pt   = -999.0;
  Float_t   eg_gen_et   = -999.0;
  Float_t   eg_gen_eta   = -999.0;
  Float_t   eg_gen_phi   = -999.0;
  Float_t   eg_gen_vz   = -999.0;
  };


#endif

void output::init(TTree* tree) {

  fTree = tree;

  fTree->Branch("runnr", &runnr,  "runnr/I");
  fTree->Branch("lumiSec", &lumiSec,  "lumiSec/I");
  fTree->Branch("eventnr", &eventnr,  "eventnr/I");

  fTree->Branch("nrHitsEB1GeV", &nrHitsEB1GeV,  "nrHitsEB1GeV/F");
  fTree->Branch("nrHitsEE1GeV", &nrHitsEE1GeV,  "nrHitsEE1GeV/F");

  fTree->Branch("eg_et", &eg_et,  "eg_et/F");
  fTree->Branch("eg_energy", &eg_energy,  "eg_energy/F");
  fTree->Branch("eg_rawEnergy", &eg_rawEnergy,  "eg_rawEnergy/F");
  fTree->Branch("eg_eta", &eg_eta,  "eg_eta/F");
  fTree->Branch("eg_phi", &eg_phi,  "eg_phi/F");
  fTree->Branch("eg_phiWidth", &eg_phiWidth,  "eg_phiWidth/F");
  fTree->Branch("eg_nrClus", &eg_nrClus,  "eg_nrClus/F");
  fTree->Branch("eg_seedId", &eg_seedId,  "eg_seedId/F");
  fTree->Branch("eg_seedDet", &eg_seedDet,  "eg_seedDet/F");
  fTree->Branch("eg_sigmaIEtaIEta", &eg_sigmaIEtaIEta,  "eg_sigmaIEtaIEta/F");
  fTree->Branch("eg_sigmaIPhiIPhi", &eg_sigmaIPhiIPhi,  "eg_sigmaIPhiIPhi/F");
  fTree->Branch("eg_sigmaIEtaIEtaNoise", &eg_sigmaIEtaIEtaNoise,  "eg_sigmaIEtaIEtaNoise/F");
  fTree->Branch("eg_sigmaIPhiIPhiNoise", &eg_sigmaIPhiIPhiNoise,  "eg_sigmaIPhiIPhiNoise/F");
  fTree->Branch("eg_clusterMaxDR", &eg_clusterMaxDR,  "eg_clusterMaxDR/F");
  fTree->Branch("eg_r9Frac", &eg_r9Frac,  "eg_r9Frac/F");
  fTree->Branch("eg_r9Full", &eg_r9Full,  "eg_r9Full/F");
  fTree->Branch("eg_isEB", &eg_isEB,  "eg_isEB/F");
  fTree->Branch("eg_isEE", &eg_isEE,  "eg_isEE/F");
  fTree->Branch("eg_gen_energy", &eg_gen_energy,  "eg_gen_energy/F");
  fTree->Branch("eg_gen_pt", &eg_gen_pt,  "eg_gen_pt/F");
  fTree->Branch("eg_gen_et", &eg_gen_et,  "eg_gen_et/F");
  fTree->Branch("eg_gen_eta", &eg_gen_eta,  "eg_gen_eta/F");
  fTree->Branch("eg_gen_phi", &eg_gen_phi,  "eg_gen_phi/F");
  fTree->Branch("eg_gen_vz", &eg_gen_vz,  "eg_gen_vz/F");
}
