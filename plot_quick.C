/*
 * =====================================================================================
 *
 *       Filename:  plot_quick.C
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  02/23/22 21:58:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Ramkrishna Sharma (Ram), ramkrishna.sharma71@gmail.com
 *   Organization:  Institute of High Energy Physics, Beijing, China
 *
 * =====================================================================================
 */

void plot_quick(){
	// gSystem->Exec("gmake RegressionTrainerExe -j 8");
	// gSystem->Exec("gmake RegressionApplierExe -j 8");

    gROOT->ProcessLine("gROOT->SetBatch(true)");
	gROOT->ProcessLine(".x rootScripts/setupExample.c");
	gROOT->ProcessLine("ResPlotter res");

	TString treeName = "regTestTree";

    TString etaBins2p5 = "etaBins2p5";
    TString etaBins3p0 = "etaBins3p0";
    TString etaBins3 = "etaBins3";
    TString etaBins = "etaBins";
    TString plotVars = "plotVars";

    TString baseCuts = "eg_energy>0 && eg_gen_energy> 0 && eg_sigmaIEtaIEta>0 && eg_gen_pt>20 && eg_gen_pt<200";

// hists = makeHists(regTestTree,{-3.0,-2.5,-2.,-1.6,-1.566,-1.4442,-1.1,-0.7,0.,0.7,1.1,1.4442,1.566,1.6,2.,2.5,3.0},150,0,1.5,{"regInvTar*regMean:eg_eta","eg_rawEnergy/eg_gen_energy:eg_eta","eg_energy/eg_gen_energy:eg_eta"},"eg_energy>0 && eg_sigmaIEtaIEta>0 && eg_sigmaIPhiIPhi>0 && eg_gen_pt>20 && eg_gen_pt<60")


    TString makeHists = "makeHists("+treeName+", "+etaBins3p0+", 150, 0, 1.5, "+plotVars+", \""+baseCuts+"\")";
// compareRes({hists[0],"ECAL Energy"},{hists[1],"existing energy"}, 6, "20" , "200");
    // TString compareRes = "compareRes({makeHists[0],\"ECAL Energy\"},{makeHists[1],\"existing energy\"}, 6, \"20\" , \"200\");"
    std::cout << "MakeHists: \n\t" << makeHists << std::endl;
	gROOT->ProcessLine(makeHists);

}
