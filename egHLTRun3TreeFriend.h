//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Nov 25 13:05:22 2021 by ROOT version 6.24/06
// from TTree egHLTRun3TreeFriend/
// found on file: /eos/home-a/arun/EGMRegression_rootFiles/inputrootfiles/results/resultsEle/regEleEcal2021Run3_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root
//////////////////////////////////////////////////////////

#ifndef egHLTRun3TreeFriend_h
#define egHLTRun3TreeFriend_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class egHLTRun3TreeFriend {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           eventnr;
   Int_t           runnr;
   Int_t           lumiSec;
   Float_t         mean;
   Float_t         sigma;
   Float_t         invTar;

   // List of branches
   TBranch        *b_eventnr;   //!
   TBranch        *b_runnr;   //!
   TBranch        *b_lumiSec;   //!
   TBranch        *b_mean;   //!
   TBranch        *b_sigma;   //!
   TBranch        *b_invTar;   //!

   egHLTRun3TreeFriend(TTree *tree=0);
   virtual ~egHLTRun3TreeFriend();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef egHLTRun3TreeFriend_cxx
egHLTRun3TreeFriend::egHLTRun3TreeFriend(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/eos/home-a/arun/EGMRegression_rootFiles/inputrootfiles/results/resultsEle/regEleEcal2021Run3_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/eos/home-a/arun/EGMRegression_rootFiles/inputrootfiles/results/resultsEle/regEleEcal2021Run3_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root");
      }
      f->GetObject("egHLTRun3TreeFriend",tree);

   }
   Init(tree);
}

egHLTRun3TreeFriend::~egHLTRun3TreeFriend()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t egHLTRun3TreeFriend::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t egHLTRun3TreeFriend::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void egHLTRun3TreeFriend::Init(TTree *tree)
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

   fChain->SetBranchAddress("eventnr", &eventnr, &b_eventnr);
   fChain->SetBranchAddress("runnr", &runnr, &b_runnr);
   fChain->SetBranchAddress("lumiSec", &lumiSec, &b_lumiSec);
   fChain->SetBranchAddress("mean", &mean, &b_mean);
   fChain->SetBranchAddress("sigma", &sigma, &b_sigma);
   fChain->SetBranchAddress("invTar", &invTar, &b_invTar);
   Notify();
}

Bool_t egHLTRun3TreeFriend::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void egHLTRun3TreeFriend::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t egHLTRun3TreeFriend::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef egHLTRun3TreeFriend_cxx
