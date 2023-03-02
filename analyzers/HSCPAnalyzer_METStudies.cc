#include "HSCPAnalyzer_METStudies.h"
#include "RazorHelper.h"
#include "HSCPTree_METStudies.h"
#include "TVector3.h"
#include "TLorentzVector.h"
#include "TMath.h"
#include "Math/Vector3D.h"
#include <iostream>
#include <random>
//C++ includes
#include "assert.h"

//ROOT includes
#include "TH1F.h"


using namespace std::chrono;
using namespace std;
using namespace ROOT::Math;


void HSCPAnalyzer_METStudies::Analyze(bool isData, int options, string outputfilename, string analysisTag)
{
  //initialization: create one TTree for each analysis box
  cout << "Initializing..." << endl;
  cout << "IsData = " << isData << "\n";
  cout << "options = " << options << "\n";

  //---------------------------
  //options format: MH/MX/ctau/condor: 1000/300/0/1


  int option = options%10;

  if( isData )
  {
    std::cout << "[INFO]: running on data with option: " << option << std::endl;
  }
  else
  {
    std::cout << "[INFO]: running on MC with option: " << option << std::endl;
  }



  const float ELE_MASS = 0.000511;
  const float MU_MASS  = 0.105658;
  const float Z_MASS   = 91.2;

  if (analysisTag == ""){
    analysisTag = "test";

  }


  //-----------------------------------------------
  //Set up Output File
  //-----------------------------------------------
  string outfilename = outputfilename;
  if (outfilename == "") outfilename = "HSCP_tree.root";
  TFile *outFile;
  outFile = new TFile(outfilename.c_str(), "RECREATE");


  HSCPTree_METStudies *tree = new HSCPTree_METStudies;
  tree->CreateTree();
  tree->tree_->SetAutoFlush(0);
  tree->InitTree();

  // for signals, need one output file for each signal point



  //======================
  //  define histograms
  //=====================

  //histogram containing total number of processed events (for normalization)
  TH1F *NEvents = new TH1F("NEvents", "NEvents", 1, 1, 2);

  // no preselection & no triggers
  TH1F* h_RecoCaloMET_noPres = new TH1F("h_RecoCaloMET_noPres","no preselection & no triggers;RECO Calo MET [GeV]", 50,0,3000);
  TH1F* h_RecoPFMET_noPres = new TH1F("h_RecoPFMET_noPres","no preselection & no triggers;RECO PF MET [GeV]",50,0,3000);
  TH1F* h_HLTCaloMET_noPres = new TH1F("h_HLTCaloMET_noPres","no preselection & no triggers;HLT Calo MET [GeV]", 50,0,3000);
  TH1F* h_HLTPFMET_noPres = new TH1F("h_HLTPFMET_noPres","no preselection & no triggers;HLT PF MET [GeV]",50,0,3000);

  // no preselection & pass MET triggers
  TH1F* h_RecoCaloMET_noPres_passMET = new TH1F("h_RecoCaloMET_noPres_passMET","no preselection & pass MET triggers;RECO Calo MET [GeV]",50,0,3000);
  TH1F* h_RecoPFMET_noPres_passMET = new TH1F("h_RecoPFMET_noPres_passMET","no preselection & pass MET triggers;RECO PF MET [GeV]",50,0,3000);
  TH1F* h_HLTCaloMET_noPres_passMET = new TH1F("h_HLTCaloMET_noPres_passMET","no preselection & pass MET triggers;HLT Calo MET [GeV]", 50,0,3000);
  TH1F* h_HLTPFMET_noPres_passMET = new TH1F("h_HLTPFMET_noPres_passMET","no preselection & pass MET triggers;HLT PF MET [GeV]",50,0,3000);

  // no preselection & pass muon trigger
  TH1F* h_RecoCaloMET_noPres_passMuon = new TH1F("h_RecoCaloMET_noPres_passMuon","no preselection & pass Muon trigger;RECO Calo MET [GeV]",50,0,3000);
  TH1F* h_RecoPFMET_noPres_passMuon = new TH1F("h_RecoPFMET_noPres_passMuon","no preselection & pass Muon trigger;RECO PF MET [GeV]",50,0,3000);
  TH1F* h_HLTCaloMET_noPres_passMuon = new TH1F("h_HLTCaloMET_noPres_passMuon","no preselection & pass Muon trigger;HLT Calo MET [GeV]", 50,0,3000);
  TH1F* h_HLTPFMET_noPres_passMuon = new TH1F("h_HLTPFMET_noPres_passMuon","no preselection & pass Muon trigger;HLT PF MET [GeV]",50,0,3000);

  // no preselection & pass MET OR muon triggers
  TH1F* h_RecoCaloMET_noPres_passMETOrMuon = new TH1F("h_RecoCaloMET_noPres_passMETOrMuon","no preselection & pass MET or Muon triggers;RECO Calo MET [GeV]",50,0,3000);
  TH1F* h_RecoPFMET_noPres_passMETOrMuon = new TH1F("h_RecoPFMET_noPres_passMETOrMuon","no preselection & pass MET or Muon triggers;RECO PF MET [GeV]",50,0,3000);
  TH1F* h_HLTCaloMET_noPres_passMETOrMuon = new TH1F("h_HLTCaloMET_noPres_passMETOrMuon","no preselection & pass MET or Muon triggers;HLT Calo MET [GeV]", 50,0,3000);
  TH1F* h_HLTPFMET_noPres_passMETOrMuon = new TH1F("h_HLTPFMET_noPres_passMETOrMuon","no preselection & pass MET or Muon triggers;HLT PF MET [GeV]",50,0,3000);


  //=============================================
  // at least one candidate passing preselection
  //=============================================

  // pass preselection & no triggers
  TH1F* h_HSCP_pt_passPres = new TH1F("h_HSCP_pt_passPres","pass preselection & no triggers;pT [GeV]",50,0,10000);
  TH1F* h_RecoCaloMET_passPres = new TH1F("h_RecoCaloMET_passPres","pass preselection & no triggers;RECO Calo MET [GeV]", 50,0,3000);
  TH1F* h_RecoPFMET_passPres = new TH1F("h_RecoPFMET_passPres","pass preselection & no triggers;RECO PF MET [GeV]",50,0,3000);
  TH1F* h_HLTCaloMET_passPres = new TH1F("h_HLTCaloMET_passPres","pass preselection & no triggers;HLT Calo MET [GeV]", 50,0,3000);
  TH1F* h_HLTPFMET_passPres = new TH1F("h_HLTPFMET_passPres","pass preselection & no triggers;HLT PF MET [GeV]",50,0,3000);

  TH1F* h_RecoCaloMET_oneCand = new TH1F("h_RecoCaloMET_oneCand","one cand pass preselection & no triggers;RECO Calo MET [GeV]", 50,0,3000);
  TH1F* h_RecoPFMET_oneCand = new TH1F("h_RecoPFMET_oneCand","one cand pass preselection & no triggers;RECO PF MET [GeV]",50,0,3000);
  TH1F* h_HLTCaloMET_oneCand = new TH1F("h_HLTCaloMET_oneCand","one cand pass preselection & no triggers;HLT Calo MET [GeV]", 50,0,3000);
  TH1F* h_HLTPFMET_oneCand = new TH1F("h_HLTPFMET_oneCand","one cand pass preselection & no triggers;HLT PF MET [GeV]",50,0,3000);
  TH1F* h_RecoCaloMET_twoCand = new TH1F("h_RecoCaloMET_twoCand","two cand pass preselection & no triggers;RECO Calo MET [GeV]", 50,0,3000);
  TH1F* h_RecoPFMET_twoCand = new TH1F("h_RecoPFMET_twoCand","two cand pass preselection & no triggers;RECO PF MET [GeV]",50,0,3000);
  TH1F* h_HLTCaloMET_twoCand = new TH1F("h_HLTCaloMET_twoCand","two cand pass preselection & no triggers;HLT Calo MET [GeV]", 50,0,3000);
  TH1F* h_HLTPFMET_twoCand = new TH1F("h_HLTPFMET_twoCand","two cand pass preselection & no triggers;HLT PF MET [GeV]",50,0,3000);

  // pass preselection & pass MET triggers
  TH1F* h_RecoCaloMET_passPres_passMET = new TH1F("h_RecoCaloMET_passPres_passMET","pass preselection & pass MET triggers;RECO Calo MET [GeV]",50,0,3000);
  TH1F* h_RecoPFMET_passPres_passMET = new TH1F("h_RecoPFMET_passPres_passMET","pass preselection & pass MET triggers;RECO PF MET [GeV]",50,0,3000);
  TH1F* h_HLTCaloMET_passPres_passMET = new TH1F("h_HLTCaloMET_passPres_passMET","pass preselection & pass MET triggers;HLT Calo MET [GeV]", 50,0,3000);
  TH1F* h_HLTPFMET_passPres_passMET = new TH1F("h_HLTPFMET_passPres_passMET","pass preselection & pass MET triggers;HLT PF MET [GeV]",50,0,3000);

  TH1F* h_RecoCaloMET_oneCand_passMET = new TH1F("h_RecoCaloMET_oneCand_passMET","one cand pass preselection & pass MET triggers;RECO Calo MET [GeV]",50,0,3000);
  TH1F* h_RecoPFMET_oneCand_passMET = new TH1F("h_RecoPFMET_oneCand_passMET","one cand pass preselection & pass MET triggers;RECO PF MET [GeV]",50,0,3000);
  TH1F* h_HLTCaloMET_oneCand_passMET = new TH1F("h_HLTCaloMET_oneCand_passMET","one cand pass preselection & pass MET triggers;HLT Calo MET [GeV]", 50,0,3000);
  TH1F* h_HLTPFMET_oneCand_passMET = new TH1F("h_HLTPFMET_oneCand_passMET","one cand pass preselection & pass MET triggers;HLT PF MET [GeV]",50,0,3000);
  TH1F* h_RecoCaloMET_twoCand_passMET = new TH1F("h_RecoCaloMET_twoCand_passMET","two cand pass preselection & pass MET triggers;RECO Calo MET [GeV]",50,0,3000);
  TH1F* h_RecoPFMET_twoCand_passMET = new TH1F("h_RecoPFMET_twoCand_passMET","two cand pass preselection & pass MET triggers;RECO PF MET [GeV]",50,0,3000);
  TH1F* h_HLTCaloMET_twoCand_passMET = new TH1F("h_HLTCaloMET_twoCand_passMET","two cand pass preselection & pass MET triggers;HLT Calo MET [GeV]", 50,0,3000);
  TH1F* h_HLTPFMET_twoCand_passMET = new TH1F("h_HLTPFMET_twoCand_passMET","two cand pass preselection & pass MET triggers;HLT PF MET [GeV]",50,0,3000);

  // pass preselection & pass muon trigger
  TH1F* h_RecoCaloMET_passPres_passMuon = new TH1F("h_RecoCaloMET_passPres_passMuon","pass preselection & pass Muon trigger;RECO Calo MET [GeV]",50,0,3000);
  TH1F* h_RecoPFMET_passPres_passMuon = new TH1F("h_RecoPFMET_passPres_passMuon","pass preselection & pass Muon trigger;RECO PF MET [GeV]",50,0,3000);
  TH1F* h_HLTCaloMET_passPres_passMuon = new TH1F("h_HLTCaloMET_passPres_passMuon","pass preselection & pass Muon trigger;HLT Calo MET [GeV]", 50,0,3000);
  TH1F* h_HLTPFMET_passPres_passMuon = new TH1F("h_HLTPFMET_passPres_passMuon","pass preselection & pass Muon trigger;HLT PF MET [GeV]",50,0,3000);

  // pass preselection & pass MET OR muon triggers
  TH1F* h_RecoCaloMET_passPres_passMETOrMuon = new TH1F("h_RecoCaloMET_passPres_passMETOrMuon","pass preselection & pass MET or Muon triggers;RECO Calo MET [GeV]",50,0,3000);
  TH1F* h_RecoPFMET_passPres_passMETOrMuon = new TH1F("h_RecoPFMET_passPres_passMETOrMuon","pass preselection & pass MET or Muon triggers;RECO PF MET [GeV]",50,0,3000);
  TH1F* h_HLTCaloMET_passPres_passMETOrMuon = new TH1F("h_HLTCaloMET_passPres_passMETOrMuon","pass preselection & pass MET or Muon triggers;HLT Calo MET [GeV]", 50,0,3000);
  TH1F* h_HLTPFMET_passPres_passMETOrMuon = new TH1F("h_HLTPFMET_passPres_passMETOrMuon","pass preselection & pass MET or Muon triggers;HLT PF MET [GeV]",50,0,3000);


  //===================================
  // various other histograms desired
  //===================================

  TH1F* h_oneCand_dPhi_HSCP_RecoPFMET = new TH1F("h_oneCand_dPhi_HSCP_RecoPFMET","1 HSCP Cand: dPhi HSCP & RecoPFMET;delta phi;",50,0,3.5);
  TH1F* h_oneCand_dPhi_HSCP_RecoCaloMET = new TH1F("h_oneCand_dPhi_HSCP_RecoCaloMET","1 HSCP Cand: dPhi HSCP & RecoCaloMET;delta phi;",50,0,3.5);
  TH1F* h_oneCand_dPhi_HSCP_HLTPFMET = new TH1F("h_oneCand_dPhi_HSCP_HLTPFMET","1 HSCP Cand: dPhi HSCP & HLTPFMET;delta phi;",50,0,3.5);
  TH1F* h_oneCand_dPhi_HSCP_HLTCaloMET = new TH1F("h_oneCand_dPhi_HSCP_HLTCaloMET","1 HSCP Cand: dPhi HSCP & HLTCaloMET;delta phi;",50,0,3.5);
  TH1F* h_oneCand_dPhi_RecoPFMET_RecoCaloMET = new TH1F("h_oneCand_dPhi_RecoPFMET_RecoCaloMET","1 HSCP Cand: dPhi RecoPFMET & RecoCaloMET;delta phi;",50,0,3.5);
  TH1F* h_oneCand_dPhi_HLTPFMET_HLTCaloMET = new TH1F("h_oneCand_dPhi_HLTPFMET_HLTCaloMET","1 HSCP Cand: dPhi HLTPFMET & HLTCaloMET;delta phi;",50,0,3.5);
  TH1F* h_oneCand_dPhi_RecoPFMET_HLTPFMET = new TH1F("h_oneCand_dPhi_RecoPFMET_HLTPFMET","1 HSCP Cand: dPhi RecoPFMET & HLTPFMET;delta phi;",50,0,3.5);
  TH1F* h_oneCand_dPhi_RecoCaloMET_HLTCaloMET = new TH1F("h_oneCand_dPhi_RecoCaloMET_HLTCaloMET","1 HSCP Cand: dPhi RecoCaloMET & HLTCaloMET;delta phi;",50,0,3.5);

  TH1F* h_oneCand_dPhi_HSCP_RecoCaloMET_HSCPPFMETdPhiPi = new TH1F("h_oneCand_dPhi_HSCP_RecoCaloMET_HSCPPFMETdPhiPi","1 HSCP Cand: dPhi HSCP & RecoCaloMET for dPhi > 2.8 HSCP & PFMET;delta phi;",50,0,3.5);
  TH1F* h_oneCand_dPhi_HSCP_RecoCaloMET_HSCPPFMETdPhiZero = new TH1F("h_oneCand_dPhi_HSCP_RecoCaloMET_HSCPPFMETdPhiZero","1 HSCP Cand: dPhi HSCP & RecoCaloMET for dPhi < 0.34 HSCP & PFMET;delta phi;",50,0,3.5);
  TH1F* h_oneCand_dPhi_RecoPFMET_RecoCaloMET_HSCPPFMETdPhiPi = new TH1F("h_oneCand_dPhi_RecoPFMET_RecoCaloMET_HSCPPFMETdPhiPi","1 HSCP Cand: dPhi RecoPFMET & RecoCaloMET for dPhi > 2.8 HSCP & PFMET;delta phi;",50,0,3.5);
  TH1F* h_oneCand_dPhi_RecoPFMET_RecoCaloMET_HSCPPFMETdPhiZero = new TH1F("h_oneCand_dPhi_RecoPFMET_RecoCaloMET_HSCPPFMETdPhiZero","1 HSCP Cand: dPhi RecoPFMET & RecoCaloMET for dPhi < 0.34 HSCP & PFMET;delta phi;",50,0,3.5);
  TH2F* h_oneCand_dPhi_HSCP_RecoPFMET_vs_RecoPFMET = new TH2F("h_oneCand_dPhi_HSCP_RecoPFMET_vs_RecoPFMET","1 HSCP Cand: RecoPFMET vs dPhi(HSCP, RecoPFMET);delta phi;RecoPFMET [GeV]",50,0,3.5,50,0,2000);
  TH2F* h_oneCand_dPhi_HSCP_RecoPFMET_vs_RecoCaloMET = new TH2F("h_oneCand_dPhi_HSCP_RecoPFMET_vs_RecoCaloMET","1 HSCP Cand: dPhi HSCP & RecoPFMET vs RecoCaloMET;delta phi;",50,0,3.5,50,0,2000);
  TH2F* h_oneCand_dPhi_HSCP_RecoCaloMET_vs_RecoPFMET = new TH2F("h_oneCand_dPhi_HSCP_RecoCaloMET_vs_RecoPFMET","1 HSCP Cand: dPhi HSCP & RecoCaloMET vs RecoPFMET;delta phi;",50,0,3.5,50,0,2000);
  TH2F* h_oneCand_dPhi_HSCP_RecoCaloMET_vs_RecoCaloMET = new TH2F("h_oneCand_dPhi_HSCP_RecoCaloMET_vs_RecoCaloMET","1 HSCP Cand: dPhi HSCP & RecoCaloMET vs RecoCaloMET;delta phi;",50,0,3.5,50,0,2000);

  TH2F* h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET = new TH2F("h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET","1 HSCP Cand: dPhi(HSCP,RecoCaloMET) vs dPhi(HSCP,RecoPFMET);delta phi(HSCP,RecoPFMET);dPhi(HSCP,RecoCaloMET)",50,0,3.5,50,0,3.5);
  TH2F* h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pt0to500 = new TH2F("h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pt0to500","1 HSCP Cand: dPhi(HSCP,RecoCaloMET) vs dPhi(HSCP,RecoPFMET) for HSCP pT < 500;delta phi(HSCP,RecoPFMET);dPhi(HSCP,RecoCaloMET)",50,0,3.5,50,0,3.5);
  TH2F* h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pt500to1000 = new TH2F("h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pt500to1000","1 HSCP Cand: dPhi(HSCP,RecoCaloMET) vs dPhi(HSCP,RecoPFMET) for 500 < HSCP pT < 1000;delta phi(HSCP,RecoPFMET);dPhi(HSCP,RecoCaloMET)",50,0,3.5,50,0,3.5);
  TH2F* h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pt1000to = new TH2F("h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pt1000to","1 HSCP Cand: dPhi(HSCP,RecoCaloMET) vs dPhi(HSCP,RecoPFMET) for HSCP pT > 1000;delta phi(HSCP,RecoPFMET);dPhi(HSCP,RecoCaloMET)",50,0,3.5,50,0,3.5);
  TH2F* h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet0to100 = new TH2F("h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet0to100","1 HSCP Cand: dPhi(HSCP,RecoCaloMET) vs dPhi(HSCP,RecoPFMET) for RecoCaloMET < 100;delta phi(HSCP,RecoPFMET);dPhi(HSCP,RecoCaloMET)",50,0,3.5,50,0,3.5);
  TH2F* h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet100to500 = new TH2F("h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet100to500","1 HSCP Cand: dPhi(HSCP,RecoCaloMET) vs dPhi(HSCP,RecoPFMET) for 100 < RecoCaloMET < 500;delta phi(HSCP,RecoPFMET);dPhi(HSCP,RecoCaloMET)",50,0,3.5,50,0,3.5);
  TH2F* h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet500to = new TH2F("h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet500to","1 HSCP Cand: dPhi(HSCP,RecoCaloMET) vs dPhi(HSCP,RecoPFMET) for RecoCaloMET > 500;delta phi(HSCP,RecoPFMET);dPhi(HSCP,RecoCaloMET)",50,0,3.5,50,0,3.5);
  TH2F* h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet0to100 = new TH2F("h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet0to100","1 HSCP Cand: dPhi(HSCP,RecoCaloMET) vs dPhi(HSCP,RecoPFMET) for RecoPFMET < 100;delta phi(HSCP,RecoPFMET);dPhi(HSCP,RecoCaloMET)",50,0,3.5,50,0,3.5);
  TH2F* h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet100to500 = new TH2F("h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet100to500","1 HSCP Cand: dPhi(HSCP,RecoCaloMET) vs dPhi(HSCP,RecoPFMET) for 100 < RecoPFMET < 500;delta phi(HSCP,RecoPFMET);dPhi(HSCP,RecoCaloMET)",50,0,3.5,50,0,3.5);
  TH2F* h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet500to = new TH2F("h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet500to","1 HSCP Cand: dPhi(HSCP,RecoCaloMET) vs dPhi(HSCP,RecoPFMET) for RecoPFMET > 500;delta phi(HSCP,RecoPFMET);dPhi(HSCP,RecoCaloMET)",50,0,3.5,50,0,3.5);

  TH1F* h_twoCand_dPhi_HSCP1_HSCP2 = new TH1F("h_twoCand_dPhi_HSCP1_HSCP2","2 HSCP Cand: dPhi HSCP1 & HSCP2;delta phi;",50,0,3.5);
  TH1F* h_twoCand_dPhi_HSCP1_RecoPFMET = new TH1F("h_twoCand_dPhi_HSCP1_RecoPFMET","2 HSCP Cand: dPhi HSCP1 & RecoPFMET;delta phi;",50,0,3.5);
  TH1F* h_twoCand_dPhi_HSCP2_RecoPFMET = new TH1F("h_twoCand_dPhi_HSCP2_RecoPFMET","2 HSCP Cand: dPhi HSCP2 & RecoPFMET;delta phi;",50,0,3.5);
  TH1F* h_twoCand_dPhi_HSCP1_RecoCaloMET = new TH1F("h_twoCand_dPhi_HSCP1_RecoCaloMET","2 HSCP Cand: dPhi HSCP1 & RecoCaloMET;delta phi;",50,0,3.5);
  TH1F* h_twoCand_dPhi_HSCP1_HLTPFMET = new TH1F("h_twoCand_dPhi_HSCP1_HLTPFMET","2 HSCP Cand: dPhi HSCP1 & HLTPFMET;delta phi;",50,0,3.5);
  TH1F* h_twoCand_dPhi_HSCP1_HLTCaloMET = new TH1F("h_twoCand_dPhi_HSCP1_HLTCaloMET","2 HSCP Cand: dPhi HSCP1 & HLTCaloMET;delta phi;",50,0,3.5);
  TH1F* h_twoCand_dPhi_RecoPFMET_RecoCaloMET = new TH1F("h_twoCand_dPhi_RecoPFMET_RecoCaloMET","2 HSCP Cand: dPhi RecoPFMET & RecoCaloMET;delta phi;",50,0,3.5);
  TH1F* h_twoCand_dPhi_HLTPFMET_HLTCaloMET = new TH1F("h_twoCand_dPhi_HLTPFMET_HLTCaloMET","2 HSCP Cand: dPhi HLTPFMET & HLTCaloMET;delta phi;",50,0,3.5);
  TH1F* h_twoCand_dPhi_RecoPFMET_HLTPFMET = new TH1F("h_twoCand_dPhi_RecoPFMET_HLTPFMET","2 HSCP Cand: dPhi RecoPFMET & HLTPFMET;delta phi;",50,0,3.5);
  TH1F* h_twoCand_dPhi_RecoCaloMET_HLTCaloMET = new TH1F("h_twoCand_dPhi_RecoCaloMET_HLTCaloMET","2 HSCP Cand: dPhi RecoCaloMET & HLTCaloMET;delta phi;",50,0,3.5);



  char* cmsswPath;
  cmsswPath = getenv("CMSSW_BASE");
  string pathname;
  if(cmsswPath != NULL) pathname = string(cmsswPath) + "/src/llp_analyzer/data/JEC/";
  if(cmsswPath != NULL and option == 1) pathname = "JEC/"; //run on condor if option == 1



  //--------------------------------
  //Initialize helper
  //--------------------------------
  RazorHelper *helper = 0;
  helper = new RazorHelper(analysisTag, isData);


  //*************************************************************************
  //Look over Input File Events
  //*************************************************************************
  if (fChain == 0) return;
  cout << "Total Events: " << fChain->GetEntries() << "\n";
  Long64_t nbytes = 0, nb = 0;
  clock_t start, end;
  start = clock();
  for (Long64_t jentry=0; jentry<fChain->GetEntries();jentry++) {

    //begin event
    if(jentry % 10000 == 0)
    {
      end = clock();
      double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
      cout << "Processing entry " << jentry << endl;
      cout << "Time taken by program is : " << time_taken << endl;
      start = clock();
    }
    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    //GetEntry(ientry);
    nb = fChain->GetEntry(jentry); nbytes += nb;

    tree->InitVariables();



    //
    // //event info
    if (isData)
    {
      NEvents->Fill(1);
      tree->weight = 1;
    }
    else
    {
      tree->weight = GeneratorWeight;
      NEvents->Fill(1, GeneratorWeight);
    }
    tree->runNum = Run;
    tree->lumiSec = Lumi;
    tree->evtNum = Event;
    tree->pileupWeight = Weight;

    //edit here to add branches 
    //tree->branch name from output file = branch name from input file

    //
    //
    //   for (int i=0; i < nBunchXing; i++)
    //   {
    //     if (BunchXing[i] == 0)
    //     {
    //       tree->npu = nPUmean[i];
    //     }
    //   }
    //   tree->pileupWeight = helper->getPileupWeight(tree->npu);
    //   tree->pileupWeightUp = helper->getPileupWeightUp(tree->npu) / tree->pileupWeight;
    //   tree->pileupWeightDown = helper->getPileupWeightDown(tree->npu) / tree->pileupWeight;
    //
    // }//end of isData
    //
    //   //get NPU
    //   tree->npv = nPV;
    //   tree->rho = fixedGridRhoFastjetAll;





      //Triggers
      //if (!HLT_Mu50) continue; //if only muon trigger passing desired
      tree->HLT_Mu50 = HLT_Mu50;
      tree->HLT_PFMET120_PFMHT120_IDTight = HLT_PFMET120_PFMHT120_IDTight;
      tree->HLT_PFHT500_PFMET100_PFMHT100_IDTight = HLT_PFHT500_PFMET100_PFMHT100_IDTight;
      tree->HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 = HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60;
      tree->HLT_MET105_IsoTrk50 = HLT_MET105_IsoTrk50;



      //*************************************************************************
      // MET-related variables
      //*************************************************************************

      tree->RecoCaloMET = RecoCaloMET;
      tree->RecoCaloMET_phi = RecoCaloMET_phi;
      tree->RecoPFMET = RecoPFMET;
      tree->RecoPFMET_phi = RecoPFMET_phi;
      tree->RecoPFMHT = RecoPFMHT;
      tree->HLTCaloMET = HLTCaloMET;
      tree->HLTCaloMET_phi = HLTCaloMET_phi;
      tree->HLTCaloMET_sigf = HLTCaloMET_sigf;
      tree->HLTCaloMETClean = HLTCaloMETClean;
      tree->HLTCaloMETClean_phi = HLTCaloMETClean_phi;
      tree->HLTCaloMETClean_sigf = HLTCaloMETClean_sigf;
      tree->HLTCaloMHT = HLTCaloMHT;
      tree->HLTCaloMHT_phi = HLTCaloMHT_phi;
      tree->HLTCaloMHT_sigf = HLTCaloMHT_sigf;
      tree->HLTPFMET = HLTPFMET;
      tree->HLTPFMET_phi = HLTPFMET_phi;
      tree->HLTPFMET_sigf = HLTPFMET_sigf;
      tree->HLTPFMHT = HLTPFMHT;
      tree->HLTPFMHT_phi = HLTPFMHT_phi;
      tree->HLTPFMHT_sigf = HLTPFMHT_sigf;

      tree->passPreselection = passPreselection;


    //***************************************************************
    //Start Object Selection
    //***************************************************************

    //HSCP stuff -- preselections

      tree->nHSCP = 0;
      bool bool_CandPassPres = false;
      int total_NCandPassPres = 0;
      int index_PassPres[3] = {-1,-1,-1};
      for(unsigned int i = 0; i < Pt->size(); i++) {
	
	tree->HSCP_pt[tree->nHSCP] = Pt->at(i);
	tree->HSCP_eta[tree->nHSCP] = eta->at(i);
	tree->HSCP_phi[tree->nHSCP] = phi->at(i);
	tree->HSCP_nPixelHit[tree->nHSCP] = NOPH->at(i);
	tree->HSCP_nHits[tree->nHSCP] = NOM->at(i);
	tree->HSCP_isHighPurity[tree->nHSCP] = isHighPurity->at(i);
	if(tree->HSCP_isHighPurity[tree->nHSCP] > 1) {
	  std::cout << "=====" << std::endl;
	  std::cout << "left side: " << tree->HSCP_isHighPurity[tree->nHSCP] << std::endl;
	  std::cout << "right side: " << isHighPurity->at(i) << std::endl;
	} if(isHighPurity->at(i) > 1) {
	  std::cout << "=====" << std::endl;
	  std::cout << "left side: " << tree->HSCP_isHighPurity[tree->nHSCP] << std::endl;
	  std::cout << "right side: " << isHighPurity->at(i) << std::endl;
	}
	tree->HSCP_fracValidHits[tree->nHSCP] = FOVH->at(i);
	tree->HSCP_EOverP[tree->nHSCP] = EoverP->at(i);
	tree->HSCP_chi2[tree->nHSCP] = Chi2->at(i);
	tree->HSCP_nDof[tree->nHSCP] = Ndof->at(i);
	tree->HSCP_track_genTrackMiniIsoSumPt[tree->nHSCP] = track_genTrackMiniIsoSumPt->at(i);
	tree->HSCP_pfMiniIso_relative[tree->nHSCP] = PFMiniIso_relative->at(i);
	tree->HSCP_probQ[tree->nHSCP] = ProbQ_noL1->at(i);
	tree->HSCP_ptErr[tree->nHSCP] = PtErr->at(i);
	tree->HSCP_ias_StripOnly[tree->nHSCP] = Ias_StripOnly->at(i);
	tree->HSCP_mass[tree->nHSCP] = Mass->at(i);
	tree->HSCP_dZ[tree->nHSCP] = dZ->at(i);
	tree->HSCP_dXY[tree->nHSCP] = dXY->at(i);

	// explicitly defining preselections
	if (
	    Pt->at(i) > 55 &&
	    eta->at(i) < 2.1 && eta->at(i) > -2.1 &&
	    isHighPurity->at(i) == true &&
	    NOPH->at(i) >= 2 &&
	    Chi2->at(i)/Ndof->at(i) < 5 &&
	    dZ->at(i) < 0.1 &&
	    dXY->at(i) < 0.02 &&
	    NOM->at(i) >= 10 &&
	    FOVH->at(i) > 0.8 &&
	    PFMiniIso_relative->at(i) < 0.02 &&
	    track_genTrackMiniIsoSumPt->at(i) < 15 &&
	    PtErr->at(i)/(Pt->at(i)*Pt->at(i)) < 0.0008 &&
	    EoverP->at(i) < 0.3
	    ) {
	  bool_CandPassPres = true;
	  tree->HSCP_passPres[tree->nHSCP] = bool_CandPassPres;
	  total_NCandPassPres++;
	  //this saves which index candidate passes preselection
	  index_PassPres[total_NCandPassPres-1] = i;
	  //std::cout << "i: " << i << " ";
	} else {
	  bool_CandPassPres = false;
	  tree->HSCP_passPres[tree->nHSCP] = bool_CandPassPres;
	}
	
	tree->nHSCP++;
      }

      /* block to check the index array
      std::cout << "Array: " << std::endl;
      for (size_t i_t = 0; i_t < 3; i_t++) {
      	std::cout << index_PassPres[i_t] << " ";
      } 
      std::cout << " " << std::endl;
      */

      tree->NCandPassPres = total_NCandPassPres;

      // muons
      // jets
      
      tree->tree_->Fill();



 //============================
 //============================
 //   fill histograms here
 //============================
 //============================

    // no trigger requirments
  
      // no preselection requirement
      h_RecoCaloMET_noPres->Fill(RecoCaloMET);
      h_RecoPFMET_noPres->Fill(RecoPFMET);
      h_HLTCaloMET_noPres->Fill(HLTCaloMET);
      h_HLTPFMET_noPres->Fill(HLTPFMET);

      // events with at least one HSCP candidate passing preselection
      if(total_NCandPassPres > 0) {
	h_RecoCaloMET_passPres->Fill(RecoCaloMET);
	h_RecoPFMET_passPres->Fill(RecoPFMET);
	h_HLTCaloMET_passPres->Fill(HLTCaloMET);
	h_HLTPFMET_passPres->Fill(HLTPFMET);

	if(total_NCandPassPres == 1) {
	  h_RecoCaloMET_oneCand->Fill(RecoCaloMET);
	  h_RecoPFMET_oneCand->Fill(RecoPFMET);
	  h_HLTCaloMET_oneCand->Fill(HLTCaloMET);
	  h_HLTPFMET_oneCand->Fill(HLTPFMET);
	} if(total_NCandPassPres == 2) {
	  h_RecoCaloMET_twoCand->Fill(RecoCaloMET);
	  h_RecoPFMET_twoCand->Fill(RecoPFMET);
	  h_HLTCaloMET_twoCand->Fill(HLTCaloMET);
	  h_HLTPFMET_twoCand->Fill(HLTPFMET);
	}

      }

      // passing MET triggers (OR of all four MET triggers)
      if(HLT_PFMET120_PFMHT120_IDTight || HLT_PFHT500_PFMET100_PFMHT100_IDTight || HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 || HLT_MET105_IsoTrk50) {

	// no preselection requirement
	h_RecoCaloMET_noPres_passMET->Fill(RecoCaloMET);
	h_RecoPFMET_noPres_passMET->Fill(RecoPFMET);
	h_HLTCaloMET_noPres_passMET->Fill(HLTCaloMET);
	h_HLTPFMET_noPres_passMET->Fill(HLTPFMET);
	
	// events with at least one HSCP candidate passing preselection
	if(total_NCandPassPres > 0) {
	  h_RecoCaloMET_passPres_passMET->Fill(RecoCaloMET);
	  h_RecoPFMET_passPres_passMET->Fill(RecoPFMET);
	  h_HLTCaloMET_passPres_passMET->Fill(HLTCaloMET);
	  h_HLTPFMET_passPres_passMET->Fill(HLTPFMET);

	  if(total_NCandPassPres == 1) {
	    h_RecoCaloMET_oneCand_passMET->Fill(RecoCaloMET);
	    h_RecoPFMET_oneCand_passMET->Fill(RecoPFMET);
	    h_HLTCaloMET_oneCand_passMET->Fill(HLTCaloMET);
	    h_HLTPFMET_oneCand_passMET->Fill(HLTPFMET);
	  } if(total_NCandPassPres == 2) {
	    h_RecoCaloMET_twoCand_passMET->Fill(RecoCaloMET);
	    h_RecoPFMET_twoCand_passMET->Fill(RecoPFMET);
	    h_HLTCaloMET_twoCand_passMET->Fill(HLTCaloMET);
	    h_HLTPFMET_twoCand_passMET->Fill(HLTPFMET);
	  }
	} 

      // passing Muon trigger
      } if(HLT_Mu50) {

	// no preselection requirement
	h_RecoCaloMET_noPres_passMuon->Fill(RecoCaloMET);
	h_RecoPFMET_noPres_passMuon->Fill(RecoPFMET);
	h_HLTCaloMET_noPres_passMuon->Fill(HLTCaloMET);
	h_HLTPFMET_noPres_passMuon->Fill(HLTPFMET);

	// events with at least one HSCP candidate passing preselection
	if(total_NCandPassPres > 0) {
	  h_RecoCaloMET_passPres_passMuon->Fill(RecoCaloMET);
	  h_RecoPFMET_passPres_passMuon->Fill(RecoPFMET);
	  h_HLTCaloMET_passPres_passMuon->Fill(HLTCaloMET);
	  h_HLTPFMET_passPres_passMuon->Fill(HLTPFMET);
	}

      // passing MET OR Muon triggers
      } if (HLT_PFMET120_PFMHT120_IDTight || HLT_PFHT500_PFMET100_PFMHT100_IDTight || HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 || HLT_MET105_IsoTrk50 || HLT_Mu50) {

	// no preselection requirement
	h_RecoCaloMET_noPres_passMETOrMuon->Fill(RecoCaloMET);
	h_RecoPFMET_noPres_passMETOrMuon->Fill(RecoPFMET);
	h_HLTCaloMET_noPres_passMETOrMuon->Fill(HLTCaloMET);
	h_HLTPFMET_noPres_passMETOrMuon->Fill(HLTPFMET);

	// events with at least one HSCP candidate passing preselection
	if(total_NCandPassPres > 0) {
	  h_RecoCaloMET_passPres_passMETOrMuon->Fill(RecoCaloMET);
	  h_RecoPFMET_passPres_passMETOrMuon->Fill(RecoPFMET);
	  h_HLTCaloMET_passPres_passMETOrMuon->Fill(HLTCaloMET);
	  h_HLTPFMET_passPres_passMETOrMuon->Fill(HLTPFMET);
	}

      }


      // start filling other histograms
      if(total_NCandPassPres == 1) {

	int HSCP_index = index_PassPres[0];

	float HSCP_pt_value = Pt->at(HSCP_index);
	h_HSCP_pt_passPres->Fill(HSCP_pt_value);

	float dPhi_HSCP_RecoPFMET_value = abs(RazorAnalyzer::deltaPhi(phi->at(HSCP_index),RecoPFMET_phi));
	float dPhi_HSCP_RecoCaloMET_value = abs(RazorAnalyzer::deltaPhi(phi->at(HSCP_index),RecoCaloMET_phi));
	float dPhi_HSCP_HLTPFMET_value = abs(RazorAnalyzer::deltaPhi(phi->at(HSCP_index),HLTPFMET_phi));
	float dPhi_HSCP_HLTCaloMET_value = abs(RazorAnalyzer::deltaPhi(phi->at(HSCP_index),HLTCaloMET_phi));
	float dPhi_RecoPFMET_RecoCaloMET_value = abs(RazorAnalyzer::deltaPhi(RecoPFMET_phi, RecoCaloMET_phi));
	float dPhi_HLTPFMET_HLTCaloMET_value = abs(RazorAnalyzer::deltaPhi(HLTPFMET_phi, HLTCaloMET_phi));
	float dPhi_RecoPFMET_HLTPFMET_value = abs(RazorAnalyzer::deltaPhi(RecoPFMET_phi, HLTPFMET_phi));
	float dPhi_RecoCaloMET_HLTCaloMET_value = abs(RazorAnalyzer::deltaPhi(RecoCaloMET_phi, HLTCaloMET_phi));

	h_oneCand_dPhi_HSCP_RecoPFMET->Fill(dPhi_HSCP_RecoPFMET_value);
	h_oneCand_dPhi_HSCP_RecoCaloMET->Fill(dPhi_HSCP_RecoCaloMET_value);
	h_oneCand_dPhi_HSCP_HLTPFMET->Fill(dPhi_HSCP_HLTPFMET_value);
	h_oneCand_dPhi_HSCP_HLTCaloMET->Fill(dPhi_HSCP_HLTCaloMET_value);
	h_oneCand_dPhi_RecoPFMET_RecoCaloMET->Fill(dPhi_RecoPFMET_RecoCaloMET_value);
	h_oneCand_dPhi_HLTPFMET_HLTCaloMET->Fill(dPhi_HLTPFMET_HLTCaloMET_value);
	h_oneCand_dPhi_RecoPFMET_HLTPFMET->Fill(dPhi_RecoPFMET_HLTPFMET_value);
	h_oneCand_dPhi_RecoCaloMET_HLTCaloMET->Fill(dPhi_RecoCaloMET_HLTCaloMET_value);

	if(dPhi_HSCP_RecoPFMET_value > 2.8) {
	  h_oneCand_dPhi_HSCP_RecoCaloMET_HSCPPFMETdPhiPi->Fill(dPhi_HSCP_RecoCaloMET_value);
	  h_oneCand_dPhi_RecoPFMET_RecoCaloMET_HSCPPFMETdPhiPi->Fill(dPhi_RecoPFMET_RecoCaloMET_value);
	} if(dPhi_HSCP_RecoPFMET_value < 0.34) {
	  h_oneCand_dPhi_HSCP_RecoCaloMET_HSCPPFMETdPhiZero->Fill(dPhi_HSCP_RecoCaloMET_value);
	  h_oneCand_dPhi_RecoPFMET_RecoCaloMET_HSCPPFMETdPhiZero->Fill(dPhi_RecoPFMET_RecoCaloMET_value);
	}

	h_oneCand_dPhi_HSCP_RecoPFMET_vs_RecoPFMET->Fill(dPhi_HSCP_RecoPFMET_value, RecoPFMET);
	h_oneCand_dPhi_HSCP_RecoPFMET_vs_RecoCaloMET->Fill(dPhi_HSCP_RecoPFMET_value, RecoCaloMET);
	h_oneCand_dPhi_HSCP_RecoCaloMET_vs_RecoPFMET->Fill(dPhi_HSCP_RecoCaloMET_value, RecoPFMET);
	h_oneCand_dPhi_HSCP_RecoCaloMET_vs_RecoCaloMET->Fill(dPhi_HSCP_RecoCaloMET_value, RecoCaloMET);

	h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET->Fill(dPhi_HSCP_RecoPFMET_value, dPhi_HSCP_RecoCaloMET_value);
	if(HSCP_pt_value < 500) {
	  h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pt0to500->Fill(dPhi_HSCP_RecoPFMET_value, dPhi_HSCP_RecoCaloMET_value);
	} if(HSCP_pt_value > 500 && HSCP_pt_value < 1000) {
	  h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pt500to1000->Fill(dPhi_HSCP_RecoPFMET_value, dPhi_HSCP_RecoCaloMET_value);
	} if(HSCP_pt_value > 1000) {
	  h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pt1000to->Fill(dPhi_HSCP_RecoPFMET_value, dPhi_HSCP_RecoCaloMET_value);
	} if(RecoCaloMET < 100) {
	  h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet0to100->Fill(dPhi_HSCP_RecoPFMET_value, dPhi_HSCP_RecoCaloMET_value);
	} if(RecoCaloMET > 100 && RecoCaloMET < 500) {
	  h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet100to500->Fill(dPhi_HSCP_RecoPFMET_value, dPhi_HSCP_RecoCaloMET_value);
	} if(RecoCaloMET > 500) {
	  h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet500to->Fill(dPhi_HSCP_RecoPFMET_value, dPhi_HSCP_RecoCaloMET_value);
	} if(RecoPFMET < 100) {
	  h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet0to100->Fill(dPhi_HSCP_RecoPFMET_value, dPhi_HSCP_RecoCaloMET_value);
	} if(RecoPFMET > 100 && RecoPFMET < 500) {
	  h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet100to500->Fill(dPhi_HSCP_RecoPFMET_value, dPhi_HSCP_RecoCaloMET_value);
	} if(RecoPFMET > 500) {
	  h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet500to->Fill(dPhi_HSCP_RecoPFMET_value, dPhi_HSCP_RecoCaloMET_value);
	}


	
	/*
	float dPhi_HSCP_RecoPFMET = phi->at(HSCP_index) - RecoPFMET_phi;
	float dPhi_HSCP_RecoCaloMET = phi->at(HSCP_index) - RecoCaloMET_phi;
	float dPhi_HSCP_HLTPFMET = phi->at(HSCP_index) - HLTPFMET_phi;
	float dPhi_HSCP_HLTCaloMET = phi->at(HSCP_index) - HLTCaloMET_phi;
	float dPhi_RecoPFMET_RecoCaloMET = RecoPFMET_phi - RecoCaloMET_phi;
	float dPhi_HLTPFMET_HLTCaloMET = HLTPFMET_phi - HLTCaloMET_phi;
	float dPhi_RecoPFMET_HLTPFMET = RecoPFMET_phi - HLTPFMET_phi;
	float dPhi_RecoCaloMET_HLTCaloMET = RecoCaloMET_phi - HLTCaloMET_phi;

	if(dPhi_HSCP_RecoPFMET > TMath::Pi()) {
	  h_oneCand_dPhi_HSCP_RecoPFMET->Fill(dPhi_HSCP_RecoPFMET - TMath::TwoPi());
	} else if (dPhi_HSCP_RecoPFMET < -TMath::Pi()) {
	  h_oneCand_dPhi_HSCP_RecoPFMET->Fill(dPhi_HSCP_RecoPFMET + TMath::TwoPi());
	} else {
	  h_oneCand_dPhi_HSCP_RecoPFMET->Fill(dPhi_HSCP_RecoPFMET);
	}

	if(dPhi_HSCP_RecoCaloMET > TMath::Pi()) {
	  h_oneCand_dPhi_HSCP_RecoCaloMET->Fill(dPhi_HSCP_RecoCaloMET - TMath::TwoPi());
	} else if (dPhi_HSCP_RecoCaloMET < -TMath::Pi()) {
	  h_oneCand_dPhi_HSCP_RecoCaloMET->Fill(dPhi_HSCP_RecoCaloMET + TMath::TwoPi());
	} else {
	  h_oneCand_dPhi_HSCP_RecoCaloMET->Fill(dPhi_HSCP_RecoCaloMET);
	}

	if(dPhi_HSCP_HLTPFMET > TMath::Pi()) {
	  h_oneCand_dPhi_HSCP_HLTPFMET->Fill(dPhi_HSCP_HLTPFMET - TMath::TwoPi());
	} else if (dPhi_HSCP_HLTPFMET < -TMath::Pi()) {
	  h_oneCand_dPhi_HSCP_HLTPFMET->Fill(dPhi_HSCP_HLTPFMET + TMath::TwoPi());
	} else {
	  h_oneCand_dPhi_HSCP_HLTPFMET->Fill(dPhi_HSCP_HLTPFMET);
	}

	if(dPhi_HSCP_HLTCaloMET > TMath::Pi()) {
	  h_oneCand_dPhi_HSCP_HLTCaloMET->Fill(dPhi_HSCP_HLTCaloMET - TMath::TwoPi());
	} else if (dPhi_HSCP_HLTCaloMET < -TMath::Pi()) {
	  h_oneCand_dPhi_HSCP_HLTCaloMET->Fill(dPhi_HSCP_HLTCaloMET + TMath::TwoPi());
	} else {
	  h_oneCand_dPhi_HSCP_HLTCaloMET->Fill(dPhi_HSCP_HLTCaloMET);
	}

	if(dPhi_RecoPFMET_RecoCaloMET > TMath::Pi()) {
	  h_oneCand_dPhi_RecoPFMET_RecoCaloMET->Fill(dPhi_RecoPFMET_RecoCaloMET - TMath::TwoPi());
	} else if (dPhi_RecoPFMET_RecoCaloMET < -TMath::Pi()) {
	  h_oneCand_dPhi_RecoPFMET_RecoCaloMET->Fill(dPhi_RecoPFMET_RecoCaloMET + TMath::TwoPi());
	} else {
	  h_oneCand_dPhi_RecoPFMET_RecoCaloMET->Fill(dPhi_RecoPFMET_RecoCaloMET);
	}

	if(dPhi_HLTPFMET_HLTCaloMET > TMath::Pi()) {
	  h_oneCand_dPhi_HLTPFMET_HLTCaloMET->Fill(dPhi_HLTPFMET_HLTCaloMET - TMath::TwoPi());
	} else if (dPhi_HLTPFMET_HLTCaloMET < -TMath::Pi()) {
	  h_oneCand_dPhi_HLTPFMET_HLTCaloMET->Fill(dPhi_HLTPFMET_HLTCaloMET + TMath::TwoPi());
	} else {
	  h_oneCand_dPhi_HLTPFMET_HLTCaloMET->Fill(dPhi_HLTPFMET_HLTCaloMET);
	}

	if(dPhi_RecoPFMET_HLTPFMET > TMath::Pi()) {
	  h_oneCand_dPhi_RecoPFMET_HLTPFMET->Fill(dPhi_RecoPFMET_HLTPFMET - TMath::TwoPi());
	} else if (dPhi_RecoPFMET_HLTPFMET < -TMath::Pi()) {
	  h_oneCand_dPhi_RecoPFMET_HLTPFMET->Fill(dPhi_RecoPFMET_HLTPFMET + TMath::TwoPi());
	} else {
	  h_oneCand_dPhi_RecoPFMET_HLTPFMET->Fill(dPhi_RecoPFMET_HLTPFMET);
	}

	if(dPhi_RecoCaloMET_HLTCaloMET > TMath::Pi()) {
	  h_oneCand_dPhi_RecoCaloMET_HLTCaloMET->Fill(dPhi_RecoCaloMET_HLTCaloMET - TMath::TwoPi());
	} else if (dPhi_RecoCaloMET_HLTCaloMET < -TMath::Pi()) {
	  h_oneCand_dPhi_RecoCaloMET_HLTCaloMET->Fill(dPhi_RecoCaloMET_HLTCaloMET + TMath::TwoPi());
	} else {
	  h_oneCand_dPhi_RecoCaloMET_HLTCaloMET->Fill(dPhi_RecoCaloMET_HLTCaloMET);
	}
	*/
	
      }

      if(total_NCandPassPres == 2) {

	int HSCP_index1 = index_PassPres[0];
	int HSCP_index2 = index_PassPres[1];

	float HSCP_pt_value1 = Pt->at(HSCP_index1);
	float HSCP_pt_value2 = Pt->at(HSCP_index2);
	h_HSCP_pt_passPres->Fill(HSCP_pt_value1);
	h_HSCP_pt_passPres->Fill(HSCP_pt_value2);

	h_twoCand_dPhi_HSCP1_HSCP2->Fill(abs(RazorAnalyzer::deltaPhi(phi->at(HSCP_index1), phi->at(HSCP_index2))));
	h_twoCand_dPhi_HSCP1_RecoPFMET->Fill(abs(RazorAnalyzer::deltaPhi(phi->at(HSCP_index1), RecoPFMET_phi)));
	h_twoCand_dPhi_HSCP2_RecoPFMET->Fill(abs(RazorAnalyzer::deltaPhi(phi->at(HSCP_index2), RecoPFMET_phi)));
	h_twoCand_dPhi_HSCP1_RecoCaloMET->Fill(abs(RazorAnalyzer::deltaPhi(phi->at(HSCP_index1), RecoCaloMET_phi)));
	h_twoCand_dPhi_HSCP1_HLTPFMET->Fill(abs(RazorAnalyzer::deltaPhi(phi->at(HSCP_index1), HLTPFMET_phi)));
	h_twoCand_dPhi_HSCP1_HLTCaloMET->Fill(abs(RazorAnalyzer::deltaPhi(phi->at(HSCP_index1), HLTCaloMET_phi)));
	h_twoCand_dPhi_RecoPFMET_RecoCaloMET->Fill(abs(RazorAnalyzer::deltaPhi(RecoPFMET_phi, RecoCaloMET_phi)));
	h_twoCand_dPhi_HLTPFMET_HLTCaloMET->Fill(abs(RazorAnalyzer::deltaPhi(HLTPFMET_phi, HLTCaloMET_phi)));
	h_twoCand_dPhi_RecoPFMET_HLTPFMET->Fill(abs(RazorAnalyzer::deltaPhi(RecoPFMET_phi, HLTPFMET_phi)));
	h_twoCand_dPhi_RecoCaloMET_HLTCaloMET->Fill(abs(RazorAnalyzer::deltaPhi(RecoCaloMET_phi, HLTCaloMET_phi)));




	/*
	float dPhi_HSCP1_HSCP2 = phi->at(HSCP_index1) - phi->at(HSCP_index2);
	float dPhi_HSCP1_RecoPFMET = phi->at(HSCP_index1) - RecoPFMET_phi;
	float dPhi_HSCP2_RecoPFMET = phi->at(HSCP_index2) - RecoPFMET_phi;
	float dPhi_HSCP1_RecoCaloMET = phi->at(HSCP_index1) - RecoCaloMET_phi;
	float dPhi_HSCP1_HLTPFMET = phi->at(HSCP_index1) - HLTPFMET_phi;
	float dPhi_HSCP1_HLTCaloMET = phi->at(HSCP_index1) - HLTCaloMET_phi;
	float dPhi_RecoPFMET_RecoCaloMET = RecoPFMET_phi - RecoCaloMET_phi;
	float dPhi_HLTPFMET_HLTCaloMET = HLTPFMET_phi - HLTCaloMET_phi;
	float dPhi_RecoPFMET_HLTPFMET = RecoPFMET_phi - HLTPFMET_phi;
	float dPhi_RecoCaloMET_HLTCaloMET = RecoCaloMET_phi - HLTCaloMET_phi;

	if(dPhi_HSCP1_HSCP2 > TMath::Pi()) {
	  h_twoCand_dPhi_HSCP1_HSCP2->Fill(dPhi_HSCP1_HSCP2 - TMath::TwoPi());
	} else if (dPhi_HSCP1_HSCP2 < -TMath::Pi()) {
	  h_twoCand_dPhi_HSCP1_HSCP2->Fill(dPhi_HSCP1_HSCP2 + TMath::TwoPi());
	} else {
	  h_twoCand_dPhi_HSCP1_HSCP2->Fill(dPhi_HSCP1_HSCP2);
	}

	if(dPhi_HSCP1_RecoPFMET > TMath::Pi()) {
	  h_twoCand_dPhi_HSCP1_RecoPFMET->Fill(dPhi_HSCP1_RecoPFMET - TMath::TwoPi());
	} else if (dPhi_HSCP1_RecoPFMET < -TMath::Pi()) {
	  h_twoCand_dPhi_HSCP1_RecoPFMET->Fill(dPhi_HSCP1_RecoPFMET + TMath::TwoPi());
	} else {
	  h_twoCand_dPhi_HSCP1_RecoPFMET->Fill(dPhi_HSCP1_RecoPFMET);
	}

	if(dPhi_HSCP2_RecoPFMET > TMath::Pi()) {
	  h_twoCand_dPhi_HSCP2_RecoPFMET->Fill(dPhi_HSCP2_RecoPFMET - TMath::TwoPi());
	} else if (dPhi_HSCP2_RecoPFMET < -TMath::Pi()) {
	  h_twoCand_dPhi_HSCP2_RecoPFMET->Fill(dPhi_HSCP2_RecoPFMET + TMath::TwoPi());
	} else {
	  h_twoCand_dPhi_HSCP2_RecoPFMET->Fill(dPhi_HSCP2_RecoPFMET);
	}

	if(dPhi_HSCP1_RecoCaloMET > TMath::Pi()) {
	  h_twoCand_dPhi_HSCP1_RecoCaloMET->Fill(dPhi_HSCP1_RecoCaloMET - TMath::TwoPi());
	} else if (dPhi_HSCP1_RecoCaloMET < -TMath::Pi()) {
	  h_twoCand_dPhi_HSCP1_RecoCaloMET->Fill(dPhi_HSCP1_RecoCaloMET + TMath::TwoPi());
	} else {
	  h_twoCand_dPhi_HSCP1_RecoCaloMET->Fill(dPhi_HSCP1_RecoCaloMET);
	}

	if(dPhi_HSCP1_HLTPFMET > TMath::Pi()) {
	  h_twoCand_dPhi_HSCP1_HLTPFMET->Fill(dPhi_HSCP1_HLTPFMET - TMath::TwoPi());
	} else if (dPhi_HSCP1_HLTPFMET < -TMath::Pi()) {
	  h_twoCand_dPhi_HSCP1_HLTPFMET->Fill(dPhi_HSCP1_HLTPFMET + TMath::TwoPi());
	} else {
	  h_twoCand_dPhi_HSCP1_HLTPFMET->Fill(dPhi_HSCP1_HLTPFMET);
	}

	if(dPhi_HSCP1_HLTCaloMET > TMath::Pi()) {
	  h_twoCand_dPhi_HSCP1_HLTCaloMET->Fill(dPhi_HSCP1_HLTCaloMET - TMath::TwoPi());
	} else if (dPhi_HSCP1_HLTCaloMET < -TMath::Pi()) {
	  h_twoCand_dPhi_HSCP1_HLTCaloMET->Fill(dPhi_HSCP1_HLTCaloMET + TMath::TwoPi());
	} else {
	  h_twoCand_dPhi_HSCP1_HLTCaloMET->Fill(dPhi_HSCP1_HLTCaloMET);
	}

	if(dPhi_RecoPFMET_RecoCaloMET > TMath::Pi()) {
	  h_twoCand_dPhi_RecoPFMET_RecoCaloMET->Fill(dPhi_RecoPFMET_RecoCaloMET - TMath::TwoPi());
	} else if (dPhi_RecoPFMET_RecoCaloMET < -TMath::Pi()) {
	  h_twoCand_dPhi_RecoPFMET_RecoCaloMET->Fill(dPhi_RecoPFMET_RecoCaloMET + TMath::TwoPi());
	} else {
	  h_twoCand_dPhi_RecoPFMET_RecoCaloMET->Fill(dPhi_RecoPFMET_RecoCaloMET);
	}

	if(dPhi_HLTPFMET_HLTCaloMET > TMath::Pi()) {
	  h_twoCand_dPhi_HLTPFMET_HLTCaloMET->Fill(dPhi_HLTPFMET_HLTCaloMET - TMath::TwoPi());
	} else if (dPhi_HLTPFMET_HLTCaloMET < -TMath::Pi()) {
	  h_twoCand_dPhi_HLTPFMET_HLTCaloMET->Fill(dPhi_HLTPFMET_HLTCaloMET + TMath::TwoPi());
	} else {
	  h_twoCand_dPhi_HLTPFMET_HLTCaloMET->Fill(dPhi_HLTPFMET_HLTCaloMET);
	}

	if(dPhi_RecoPFMET_HLTPFMET > TMath::Pi()) {
	  h_twoCand_dPhi_RecoPFMET_HLTPFMET->Fill(dPhi_RecoPFMET_HLTPFMET - TMath::TwoPi());
	} else if (dPhi_RecoPFMET_HLTPFMET < -TMath::Pi()) {
	  h_twoCand_dPhi_RecoPFMET_HLTPFMET->Fill(dPhi_RecoPFMET_HLTPFMET + TMath::TwoPi());
	} else {
	  h_twoCand_dPhi_RecoPFMET_HLTPFMET->Fill(dPhi_RecoPFMET_HLTPFMET);
	}

	if(dPhi_RecoCaloMET_HLTCaloMET > TMath::Pi()) {
	  h_twoCand_dPhi_RecoCaloMET_HLTCaloMET->Fill(dPhi_RecoCaloMET_HLTCaloMET - TMath::TwoPi());
	} else if (dPhi_RecoCaloMET_HLTCaloMET < -TMath::Pi()) {
	  h_twoCand_dPhi_RecoCaloMET_HLTCaloMET->Fill(dPhi_RecoCaloMET_HLTCaloMET + TMath::TwoPi());
	} else {
	  h_twoCand_dPhi_RecoCaloMET_HLTCaloMET->Fill(dPhi_RecoCaloMET_HLTCaloMET);
	}
	*/

      }

            
    }// end of jentry loop


    if (!isData) {
      cout << "Filled Total of " << NEvents->GetBinContent(1) << " Events\n";
      cout << "Writing output trees..." << endl;
      outFile->cd();
      tree->tree_->Write();
      
      NEvents->Write();
      h_RecoCaloMET_noPres->Write();
      h_RecoPFMET_noPres->Write();
      h_HLTCaloMET_noPres->Write();
      h_HLTPFMET_noPres->Write();
      h_RecoCaloMET_noPres_passMET->Write();
      h_RecoPFMET_noPres_passMET->Write();
      h_HLTCaloMET_noPres_passMET->Write();
      h_HLTPFMET_noPres_passMET->Write();
      h_RecoCaloMET_noPres_passMuon->Write();
      h_RecoPFMET_noPres_passMuon->Write();
      h_HLTCaloMET_noPres_passMuon->Write();
      h_HLTPFMET_noPres_passMuon->Write();
      h_RecoCaloMET_noPres_passMETOrMuon->Write();
      h_RecoPFMET_noPres_passMETOrMuon->Write();
      h_HLTCaloMET_noPres_passMETOrMuon->Write();
      h_HLTPFMET_noPres_passMETOrMuon->Write();
      h_HSCP_pt_passPres->Write();
      h_RecoCaloMET_passPres->Write();
      h_RecoPFMET_passPres->Write();
      h_HLTCaloMET_passPres->Write();
      h_HLTPFMET_passPres->Write();
      h_RecoCaloMET_oneCand->Write();
      h_RecoPFMET_oneCand->Write();
      h_HLTCaloMET_oneCand->Write();
      h_HLTPFMET_oneCand->Write();
      h_RecoCaloMET_twoCand->Write();
      h_RecoPFMET_twoCand->Write();
      h_HLTCaloMET_twoCand->Write();
      h_HLTPFMET_twoCand->Write();
      h_RecoCaloMET_passPres_passMET->Write();
      h_RecoPFMET_passPres_passMET->Write();
      h_HLTCaloMET_passPres_passMET->Write();
      h_HLTPFMET_passPres_passMET->Write();
      h_RecoCaloMET_oneCand_passMET->Write();
      h_RecoPFMET_oneCand_passMET->Write();
      h_HLTCaloMET_oneCand_passMET->Write();
      h_HLTPFMET_oneCand_passMET->Write();
      h_RecoCaloMET_twoCand_passMET->Write();
      h_RecoPFMET_twoCand_passMET->Write();
      h_HLTCaloMET_twoCand_passMET->Write();
      h_HLTPFMET_twoCand_passMET->Write();
      h_RecoCaloMET_passPres_passMuon->Write();
      h_RecoPFMET_passPres_passMuon->Write();
      h_HLTCaloMET_passPres_passMuon->Write();
      h_HLTPFMET_passPres_passMuon->Write();
      h_RecoCaloMET_passPres_passMETOrMuon->Write();
      h_RecoPFMET_passPres_passMETOrMuon->Write();
      h_HLTCaloMET_passPres_passMETOrMuon->Write();
      h_HLTPFMET_passPres_passMETOrMuon->Write();

      h_oneCand_dPhi_HSCP_RecoPFMET->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET->Write();
      h_oneCand_dPhi_HSCP_HLTPFMET->Write();
      h_oneCand_dPhi_HSCP_HLTCaloMET->Write();
      h_oneCand_dPhi_RecoPFMET_RecoCaloMET->Write();
      h_oneCand_dPhi_HLTPFMET_HLTCaloMET->Write();
      h_oneCand_dPhi_RecoPFMET_HLTPFMET->Write();
      h_oneCand_dPhi_RecoCaloMET_HLTCaloMET->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET_HSCPPFMETdPhiPi->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET_HSCPPFMETdPhiZero->Write();
      h_oneCand_dPhi_RecoPFMET_RecoCaloMET_HSCPPFMETdPhiPi->Write();
      h_oneCand_dPhi_RecoPFMET_RecoCaloMET_HSCPPFMETdPhiZero->Write();
      h_oneCand_dPhi_HSCP_RecoPFMET_vs_RecoPFMET->Write();
      h_oneCand_dPhi_HSCP_RecoPFMET_vs_RecoCaloMET->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET_vs_RecoPFMET->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET_vs_RecoCaloMET->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pt0to500->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pt500to1000->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pt1000to->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet0to100->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet100to500->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet500to->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet0to100->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet100to500->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet500to->Write();
      h_twoCand_dPhi_HSCP1_HSCP2->Write();
      h_twoCand_dPhi_HSCP1_RecoPFMET->Write();
      h_twoCand_dPhi_HSCP2_RecoPFMET->Write();
      h_twoCand_dPhi_HSCP1_RecoCaloMET->Write();
      h_twoCand_dPhi_HSCP1_HLTPFMET->Write();
      h_twoCand_dPhi_HSCP1_HLTCaloMET->Write();
      h_twoCand_dPhi_RecoPFMET_RecoCaloMET->Write();
      h_twoCand_dPhi_HLTPFMET_HLTCaloMET->Write();
      h_twoCand_dPhi_RecoPFMET_HLTPFMET->Write();
      h_twoCand_dPhi_RecoCaloMET_HLTCaloMET->Write();
     
      outFile->Close();

    } else {
    
      cout << "Filled Total of " << NEvents->GetBinContent(1) << " Events\n";
      cout << "Writing output trees..." << endl;
      outFile->cd();
      tree->tree_->Write();
      
      NEvents->Write();
      h_RecoCaloMET_noPres->Write();
      h_RecoPFMET_noPres->Write();
      h_HLTCaloMET_noPres->Write();
      h_HLTPFMET_noPres->Write();
      h_RecoCaloMET_noPres_passMET->Write();
      h_RecoPFMET_noPres_passMET->Write();
      h_HLTCaloMET_noPres_passMET->Write();
      h_HLTPFMET_noPres_passMET->Write();
      h_RecoCaloMET_noPres_passMuon->Write();
      h_RecoPFMET_noPres_passMuon->Write();
      h_HLTCaloMET_noPres_passMuon->Write();
      h_HLTPFMET_noPres_passMuon->Write();
      h_RecoCaloMET_noPres_passMETOrMuon->Write();
      h_RecoPFMET_noPres_passMETOrMuon->Write();
      h_HLTCaloMET_noPres_passMETOrMuon->Write();
      h_HLTPFMET_noPres_passMETOrMuon->Write();
      h_HSCP_pt_passPres->Write();
      h_RecoCaloMET_passPres->Write();
      h_RecoPFMET_passPres->Write();
      h_HLTCaloMET_passPres->Write();
      h_HLTPFMET_passPres->Write();
      h_RecoCaloMET_oneCand->Write();
      h_RecoPFMET_oneCand->Write();
      h_HLTCaloMET_oneCand->Write();
      h_HLTPFMET_oneCand->Write();
      h_RecoCaloMET_twoCand->Write();
      h_RecoPFMET_twoCand->Write();
      h_HLTCaloMET_twoCand->Write();
      h_HLTPFMET_twoCand->Write();
      h_RecoCaloMET_passPres_passMET->Write();
      h_RecoPFMET_passPres_passMET->Write();
      h_HLTCaloMET_passPres_passMET->Write();
      h_HLTPFMET_passPres_passMET->Write();
      h_RecoCaloMET_oneCand_passMET->Write();
      h_RecoPFMET_oneCand_passMET->Write();
      h_HLTCaloMET_oneCand_passMET->Write();
      h_HLTPFMET_oneCand_passMET->Write();
      h_RecoCaloMET_twoCand_passMET->Write();
      h_RecoPFMET_twoCand_passMET->Write();
      h_HLTCaloMET_twoCand_passMET->Write();
      h_HLTPFMET_twoCand_passMET->Write();
      h_RecoCaloMET_passPres_passMuon->Write();
      h_RecoPFMET_passPres_passMuon->Write();
      h_HLTCaloMET_passPres_passMuon->Write();
      h_HLTPFMET_passPres_passMuon->Write();
      h_RecoCaloMET_passPres_passMETOrMuon->Write();
      h_RecoPFMET_passPres_passMETOrMuon->Write();
      h_HLTCaloMET_passPres_passMETOrMuon->Write();
      h_HLTPFMET_passPres_passMETOrMuon->Write();

      h_oneCand_dPhi_HSCP_RecoPFMET->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET->Write();
      h_oneCand_dPhi_HSCP_HLTPFMET->Write();
      h_oneCand_dPhi_HSCP_HLTCaloMET->Write();
      h_oneCand_dPhi_RecoPFMET_RecoCaloMET->Write();
      h_oneCand_dPhi_HLTPFMET_HLTCaloMET->Write();
      h_oneCand_dPhi_RecoPFMET_HLTPFMET->Write();
      h_oneCand_dPhi_RecoCaloMET_HLTCaloMET->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET_HSCPPFMETdPhiPi->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET_HSCPPFMETdPhiZero->Write();
      h_oneCand_dPhi_RecoPFMET_RecoCaloMET_HSCPPFMETdPhiPi->Write();
      h_oneCand_dPhi_RecoPFMET_RecoCaloMET_HSCPPFMETdPhiZero->Write();
      h_oneCand_dPhi_HSCP_RecoPFMET_vs_RecoPFMET->Write();
      h_oneCand_dPhi_HSCP_RecoPFMET_vs_RecoCaloMET->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET_vs_RecoPFMET->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET_vs_RecoCaloMET->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pt0to500->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pt500to1000->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pt1000to->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet0to100->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet100to500->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet500to->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet0to100->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet100to500->Write();
      h_oneCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet500to->Write();
      h_twoCand_dPhi_HSCP1_HSCP2->Write();
      h_twoCand_dPhi_HSCP1_RecoPFMET->Write();
      h_twoCand_dPhi_HSCP2_RecoPFMET->Write();
      h_twoCand_dPhi_HSCP1_RecoCaloMET->Write();
      h_twoCand_dPhi_HSCP1_HLTPFMET->Write();
      h_twoCand_dPhi_HSCP1_HLTCaloMET->Write();
      h_twoCand_dPhi_RecoPFMET_RecoCaloMET->Write();
      h_twoCand_dPhi_HLTPFMET_HLTCaloMET->Write();
      h_twoCand_dPhi_RecoPFMET_HLTPFMET->Write();
      h_twoCand_dPhi_RecoCaloMET_HLTCaloMET->Write();

      outFile->Close();
 
    }
}
