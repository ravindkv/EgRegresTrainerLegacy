/*
 * =====================================================================================
 *
 *       Filename:  GetFlatNtuple.C
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  02/28/22 21:27:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ramkrishna Sharma (Ram), ramkrishna.sharma71@gmail.com
 *   Organization:  Institute of High Energy Physics, Beijing, China
 *
 * =====================================================================================
 */

#include <time.h>
#include <chrono>
#include "interface/progressbar.hpp"

#include "interface/egHLTRun3Tree.h"
#include "interface/output.h"

void GetFlatNtuple(
    TString inputFile1 = "/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/HLTAnalyzerTree_REAL.root",
    TString OutPutFile = "/eos/user/r/rasharma/post_doc_ihep/EGamma/HLT/regression/MainNtuples_v2/HLTAnalyzerTree_REAL_Flat.root", // Signal, Backgrounds, Data
    TString inputTree1 = "egHLTRun3Tree", // Signal, Backgrounds, Data
    TString PrefixOutPutRootFileName = ""
    )
{
    clock_t tStart = clock();
    TFile *OldRootFile = new TFile(inputFile1,"READ");

    if (OldRootFile->IsZombie()) {

        std::cout << "File " << inputFile1 << " does not exists" << std::endl;
        return;
    }
    std::cout << "Input  file ==> " << inputFile1 << std::endl;
    std::cout << "Output file ==> " << OutPutFile << std::endl;

    TFile *newfile = new TFile(OutPutFile, "RECREATE","",207);

    TTree *OldTree = NULL;
    OldTree = (TTree*)OldRootFile->Get(inputTree1);

    egHLTRun3Tree egHLTRun3Tree_ = egHLTRun3Tree(OldTree);

    TTree *newtree = new TTree("egHLTRun3Tree","egHLTRun3Tree");
    output outputVars = output(newtree);

    Long64_t nentries = OldTree->GetEntries();

    std::cout << "Total entries: " << nentries << std::endl;

    int temp_percentage_done = 0;
    progressbar bar(20);

    // nentries = 20000;
    for (Long64_t jentry=0; jentry<nentries;jentry++) {
        egHLTRun3Tree_.GetEntry(jentry);

        int percentage_done = (int)(((float)jentry/(float)nentries)*100);
        if (percentage_done % 5 == 0) {
            if (percentage_done != temp_percentage_done) {
                bar.update();
                temp_percentage_done = percentage_done;
            }
        }

        if (egHLTRun3Tree_.nrEgs != 2) continue;
        // std::cout << "runnr: " << egHLTRun3Tree_.runnr << "\tlumiSec: " << egHLTRun3Tree_.lumiSec << "\teventnr: " << egHLTRun3Tree_.eventnr << "\tnEg: " << egHLTRun3Tree_.nrEgs<< std::endl;
        for (int nele = 0; nele<egHLTRun3Tree_.nrEgs; nele++)
        {
            outputVars.runnr = egHLTRun3Tree_.runnr;
            outputVars.lumiSec = egHLTRun3Tree_.lumiSec;
            outputVars.eventnr = egHLTRun3Tree_.eventnr;

            outputVars.nrHitsEB1GeV = egHLTRun3Tree_.nrHitsEB1GeV;
            outputVars.nrHitsEE1GeV = egHLTRun3Tree_.nrHitsEE1GeV;

            outputVars.eg_et = egHLTRun3Tree_.eg_et[nele];

            outputVars.eg_energy = egHLTRun3Tree_.eg_energy[nele];
            outputVars.eg_rawEnergy = egHLTRun3Tree_.eg_rawEnergy[nele];
            outputVars.eg_eta = egHLTRun3Tree_.eg_eta[nele];
            outputVars.eg_phi = egHLTRun3Tree_.eg_phi[nele];
            outputVars.eg_phiWidth = egHLTRun3Tree_.eg_phiWidth[nele];
            outputVars.eg_nrClus = egHLTRun3Tree_.eg_nrClus[nele];
            outputVars.eg_seedId = egHLTRun3Tree_.eg_seedId[nele];
            outputVars.eg_seedDet = egHLTRun3Tree_.eg_seedDet[nele];
            outputVars.eg_sigmaIEtaIEta = egHLTRun3Tree_.eg_sigmaIEtaIEta[nele];
            outputVars.eg_sigmaIPhiIPhi = egHLTRun3Tree_.eg_sigmaIPhiIPhi[nele];
            outputVars.eg_sigmaIEtaIEtaNoise = egHLTRun3Tree_.eg_sigmaIEtaIEtaNoise[nele];
            outputVars.eg_sigmaIPhiIPhiNoise = egHLTRun3Tree_.eg_sigmaIPhiIPhiNoise[nele];
            outputVars.eg_clusterMaxDR = egHLTRun3Tree_.eg_clusterMaxDR[nele];
            outputVars.eg_r9Frac = egHLTRun3Tree_.eg_r9Frac[nele];
            outputVars.eg_r9Full = egHLTRun3Tree_.eg_r9Full[nele];
            outputVars.eg_isEB = egHLTRun3Tree_.eg_isEB[nele];
            outputVars.eg_isEE = egHLTRun3Tree_.eg_isEE[nele];
            outputVars.eg_gen_energy = egHLTRun3Tree_.eg_gen_energy[nele];
            outputVars.eg_gen_pt = egHLTRun3Tree_.eg_gen_pt[nele];
            outputVars.eg_gen_et = egHLTRun3Tree_.eg_gen_et[nele];
            outputVars.eg_gen_eta = egHLTRun3Tree_.eg_gen_eta[nele];
            outputVars.eg_gen_phi = egHLTRun3Tree_.eg_gen_phi[nele];
            outputVars.eg_gen_vz = egHLTRun3Tree_.eg_gen_vz[nele];

            newtree->Fill();
        }
    }
    newtree->Write("",TObject::kOverwrite);
    printf("\nTime taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    printf("\nTime taken to run full code: %.2fs  (%.2fm)\n\n", (double)(clock() - tStart)/CLOCKS_PER_SEC, (double)(clock() - tStart)/(CLOCKS_PER_SEC*60));
}
