/*
 * =====================================================================================
 *
 *       Filename:  Plot_UsingEvtNum.C
 *
 *    Description:  Reference: https://root.cern/doc/master/treefriend_8C_source.html
 *
 *        Version:  1.0
 *        Created:  25/11/21 11:32:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ramkrishna Sharma (Ram), ramkrishna.sharma71@gmail.com
 *   Organization:  Institute of High Energy Physics, Beijing, China
 *
 * =====================================================================================
 */

void Plot_UsingEvtNum()
{
    // TFile *f = new TFile("/eos/home-a/arun/EGMRegression_rootFiles/inputrootfiles/results/resultsEle/regEleEcal2021Run3_RealIC_RealTraining_stdVar_stdCuts_ntrees1500_applied.root");
    // TFile *f = new TFile("/afs/cern.ch/user/a/arun/public/results_regression/Run3HLT_RealIC_IdealTraining_stdVar_stdCuts_ntrees1500_applied.root");
    TFile *f = new TFile("/eos/home-a/arun/EGMRegression_rootFiles/inputrootfiles/results/Run3HLT_IdealIC_IdealTraining_stdVar_stdCuts_ntrees1500_applied.root");
    TTree *T = (TTree*)f->Get("egHLTRun3Tree");
    TTree *TF = (TTree*)f->Get("egHLTRun3TreeFriend");

    UInt_t Run, Event, lumi;
    T->SetBranchAddress("runnr",&Run);
    T->SetBranchAddress("lumiSec",&lumi);
    T->SetBranchAddress("eventnr",&Event);

    Float_t mean, sigma, invTar;
    TF->SetBranchAddress("mean", &mean);
    TF->SetBranchAddress("sigma", &sigma);
    TF->SetBranchAddress("invTar", &invTar);


    // T->AddFriend(TF);

    // int nentries = T->GetEntriesFast();
    int nentries = T->GetEntries();
    std::cout << "Total entries: " << nentries << std::endl;

    int RunEntries = (nentries > 5) ? 5 : nentries;
    // int RunEntries = nentries;
    std::cout << "Number of events to run: " << RunEntries << std::endl;

    for (int j = 0; j < 5; j++)
    {
        TF->GetEntry(j);
        std::cout << "j : " << j << std::endl;

        TLeaf* evt_runnr = TF->GetLeaf("evt.runnr");
        TLeaf* evt_lumiSec = TF->GetLeaf("evt.lumiSec");
        TLeaf* evt_eventnr = TF->GetLeaf("evt.eventnr");
        for (int i = 0; i < T->GetEntries(); i++)
        // for (int i = 0; i < 5; i++)
        {
            T->GetEntry(i);

                // std::cout << i <<  std::fixed << std::setprecision(2) <<"\t" << int(Event) << "\t" << int(evt_eventnr->GetValue()) << std::endl;
            if ( int(Event) == int(evt_eventnr->GetValue()))
            {
                std::cout << i <<  std::fixed << std::setprecision(2) <<"\t" << int(Event) << "\t" << int(evt_eventnr->GetValue()) << std::endl;
                continue;
            }

            // if (TF->GetEntryWithIndex(Run,Event) > 0) {
                // std::cout << i <<  std::fixed << std::setprecision(2) <<"\t" << int(Event) << "\t" << int(evt_eventnr->GetValue()) << std::endl;
            // }
        }
    }
}
