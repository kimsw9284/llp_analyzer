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

  // first attempt at preselection cut flow diagram
  TH1F *h_preselection_cutflow_candidates = new TH1F("h_preselection_cutflow_candidates","Preselection Cut Flow (# of candidates)",20,0,20);
  TH1F *h_preselection_cutflow_events_1cand = new TH1F("h_preselection_cutflow_events_1cand","Preselection Cut Flow (# of events with at least 1 candidate)",20,0,20);
  TH1F *h_preselection_cutflow_events_2cand = new TH1F("h_preselection_cutflow_events_2cand","Preselection Cut Flow (# of events with at least 2 candidates)",20,0,20);

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

  TH1F* h_twoCand_dPhi_HSCP_RecoCaloMET_HSCPPFMETdPhiPi = new TH1F("h_twoCand_dPhi_HSCP_RecoCaloMET_HSCPPFMETdPhiPi","2 HSCP Cand: dPhi HSCP & RecoCaloMET for dPhi > 2.8 HSCP & PFMET;delta phi;",50,0,3.5);
  TH1F* h_twoCand_dPhi_HSCP_RecoCaloMET_HSCPPFMETdPhiZero = new TH1F("h_twoCand_dPhi_HSCP_RecoCaloMET_HSCPPFMETdPhiZero","2 HSCP Cand: dPhi HSCP & RecoCaloMET for dPhi < 0.34 HSCP & PFMET;delta phi;",50,0,3.5);
  TH1F* h_twoCand_dPhi_RecoPFMET_RecoCaloMET_HSCPPFMETdPhiPi = new TH1F("h_twoCand_dPhi_RecoPFMET_RecoCaloMET_HSCPPFMETdPhiPi","2 HSCP Cand: dPhi RecoPFMET & RecoCaloMET for dPhi > 2.8 HSCP & PFMET;delta phi;",50,0,3.5);
  TH1F* h_twoCand_dPhi_RecoPFMET_RecoCaloMET_HSCPPFMETdPhiZero = new TH1F("h_twoCand_dPhi_RecoPFMET_RecoCaloMET_HSCPPFMETdPhiZero","2 HSCP Cand: dPhi RecoPFMET & RecoCaloMET for dPhi < 0.34 HSCP & PFMET;delta phi;",50,0,3.5);
  TH2F* h_twoCand_dPhi_HSCP_RecoPFMET_vs_RecoPFMET = new TH2F("h_twoCand_dPhi_HSCP_RecoPFMET_vs_RecoPFMET","2 HSCP Cand: RecoPFMET vs dPhi(HSCP, RecoPFMET);delta phi;RecoPFMET [GeV]",50,0,3.5,50,0,2000);
  TH2F* h_twoCand_dPhi_HSCP_RecoPFMET_vs_RecoCaloMET = new TH2F("h_twoCand_dPhi_HSCP_RecoPFMET_vs_RecoCaloMET","2 HSCP Cand: dPhi HSCP & RecoPFMET vs RecoCaloMET;delta phi;",50,0,3.5,50,0,2000);
  TH2F* h_twoCand_dPhi_HSCP_RecoCaloMET_vs_RecoPFMET = new TH2F("h_twoCand_dPhi_HSCP_RecoCaloMET_vs_RecoPFMET","2 HSCP Cand: dPhi HSCP & RecoCaloMET vs RecoPFMET;delta phi;",50,0,3.5,50,0,2000);
  TH2F* h_twoCand_dPhi_HSCP_RecoCaloMET_vs_RecoCaloMET = new TH2F("h_twoCand_dPhi_HSCP_RecoCaloMET_vs_RecoCaloMET","2 HSCP Cand: dPhi HSCP & RecoCaloMET vs RecoCaloMET;delta phi;",50,0,3.5,50,0,2000);


  TH2F* h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET = new TH2F("h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET","2 HSCP Cand: dPhi(HSCP,RecoCaloMET) vs dPhi(HSCP,RecoPFMET);delta phi(HSCP,RecoPFMET);dPhi(HSCP,RecoCaloMET)",50,0,3.5,50,0,3.5);
  TH2F* h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pt0to500 = new TH2F("h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pt0to500","2 HSCP Cand: dPhi(HSCP,RecoCaloMET) vs dPhi(HSCP,RecoPFMET) for HSCP pT < 500;delta phi(HSCP,RecoPFMET);dPhi(HSCP,RecoCaloMET)",50,0,3.5,50,0,3.5);
  TH2F* h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pt500to1000 = new TH2F("h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pt500to1000","2 HSCP Cand: dPhi(HSCP,RecoCaloMET) vs dPhi(HSCP,RecoPFMET) for 500 < HSCP pT < 1000;delta phi(HSCP,RecoPFMET);dPhi(HSCP,RecoCaloMET)",50,0,3.5,50,0,3.5);
  TH2F* h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pt1000to = new TH2F("h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pt1000to","2 HSCP Cand: dPhi(HSCP,RecoCaloMET) vs dPhi(HSCP,RecoPFMET) for HSCP pT > 1000;delta phi(HSCP,RecoPFMET);dPhi(HSCP,RecoCaloMET)",50,0,3.5,50,0,3.5);
  TH2F* h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet0to100 = new TH2F("h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet0to100","2 HSCP Cand: dPhi(HSCP,RecoCaloMET) vs dPhi(HSCP,RecoPFMET) for RecoCaloMET < 100;delta phi(HSCP,RecoPFMET);dPhi(HSCP,RecoCaloMET)",50,0,3.5,50,0,3.5);
  TH2F* h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet100to500 = new TH2F("h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet100to500","2 HSCP Cand: dPhi(HSCP,RecoCaloMET) vs dPhi(HSCP,RecoPFMET) for 100 < RecoCaloMET < 500;delta phi(HSCP,RecoPFMET);dPhi(HSCP,RecoCaloMET)",50,0,3.5,50,0,3.5);
  TH2F* h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet500to = new TH2F("h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet500to","2 HSCP Cand: dPhi(HSCP,RecoCaloMET) vs dPhi(HSCP,RecoPFMET) for RecoCaloMET > 500;delta phi(HSCP,RecoPFMET);dPhi(HSCP,RecoCaloMET)",50,0,3.5,50,0,3.5);
  TH2F* h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet0to100 = new TH2F("h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet0to100","2 HSCP Cand: dPhi(HSCP,RecoCaloMET) vs dPhi(HSCP,RecoPFMET) for RecoPFMET < 100;delta phi(HSCP,RecoPFMET);dPhi(HSCP,RecoCaloMET)",50,0,3.5,50,0,3.5);
  TH2F* h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet100to500 = new TH2F("h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet100to500","2 HSCP Cand: dPhi(HSCP,RecoCaloMET) vs dPhi(HSCP,RecoPFMET) for 100 < RecoPFMET < 500;delta phi(HSCP,RecoPFMET);dPhi(HSCP,RecoCaloMET)",50,0,3.5,50,0,3.5);
  TH2F* h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet500to = new TH2F("h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet500to","2 HSCP Cand: dPhi(HSCP,RecoCaloMET) vs dPhi(HSCP,RecoPFMET) for RecoPFMET > 500;delta phi(HSCP,RecoPFMET);dPhi(HSCP,RecoCaloMET)",50,0,3.5,50,0,3.5);
  TH1F* h_deltaR_HSCP_Jet = new TH1F("h_deltaR_HSCP_Jet","all delta R between Gen HSCP & Jet",100,0,7);
  TH1F* h_deltaR_HSCP_Jet_best = new TH1F("h_deltaR_HSCP_Jet_best","best delta R between Gen HSCP & Jet",100,0,7); 
  TH1F* h_genHSCPPt = new TH1F("h_genHSCPPt","Gen HSCP Pt;Pt [GeV];",100,0,4000);
  TH1F* h_genHSCPEta = new TH1F("h_genHSCPEta","Gen HSCP Eta;Eta;",100,-6,6);
  TH1F* h_genHSCPPhi = new TH1F("h_genHSCPPhi","Gen HSCP Phi;Phi;",100,-3.5,3.5);
  TH1F* h_genHSCPBeta = new TH1F("h_genHSCPBeta","Gen HSCP Beta;Beta;",100,0,1);
  TH1I* h_genHSCPCharge = new TH1I("h_genHSCPCharge","Gen HSCP Charge;Charge [e];",7,-3.5,3.5);
  TH1I* h_genHSCPChargeConfig = new TH1I("h_genHSCPChargeConfig","Gen HSCP Charge Configuation",3,0,3);
  TH1I* h_total_NGenHSCP = new TH1I("h_total_NGenHSCP","total number of GenHSCP",3,0,3);
  TH1I* h_total_NGenHSCPMatched = new TH1I("h_total_NGenHSCPMatched","total number of GenHSCP matched to a jet (dR<0.1)",3,0,3);
  TH1I* h_total_NNonHSCPGen1GeV = new TH1I("h_total_NNonHSCPGen1GeV","Number of non HSCP GEN particles above 1 GeV",50,0,50);
  TH1I* h_total_NNonHSCPGen10GeV = new TH1I("h_total_NNonHSCPGen10GeV","Number of non HSCP GEN particles above 10 GeV",50,0,50);
  TH1I* h_total_NNonHSCPGen50GeV = new TH1I("h_total_NNonHSCPGen50GeV","Number of non HSCP GEN particles above 50 GeV",50,0,50);
  TH1I* h_total_NNonHSCPGen100GeV = new TH1I("h_total_NNonHSCPGen100GeV","Number of non HSCP GEN particles above 100 GeV",50,0,50);
  TH1F* h_Eta_HSCP1 = new TH1F("h_Eta_HSCP1","Eta of HSCP1",100,-20,20);
  TH1F* h_Eta_HSCP2 = new TH1F("h_Eta_HSCP2","Eta of HSCP2",100,-20,20);
  TH1F* h_Eta_Gen = new TH1F("h_Eta_Gen","Eta of non-HSCP GEN particles",100,-20,20);
  TH1F* h_Eta_Gen_pT5 = new TH1F("h_Eta_Gen_pT5","Eta of non-HSCP GEN particles with pT > 5 GeV",100,-20,20);
  TH1F* h_Eta_Gen_pT50 = new TH1F("h_Eta_Gen_pT50","Eta of non-HSCP GEN particles with pT > 50 GeV",100,-20,20);
  TH1F* h_Eta_Gen_pT100 = new TH1F("h_Eta_Gen_pT100","Eta of non-HSCP GEN particles with pT > 100 GeV",100,-20,20);
  TH1F* h_Phi_HSCP1 = new TH1F("h_Phi_HSCP1","Phi of HSCP1",100,-3.5,3.5);
  TH1F* h_Phi_HSCP2 = new TH1F("h_Phi_HSCP2","Phi of HSCP2",100,-3.5,3.5);
  TH1F* h_Phi_Gen = new TH1F("h_Phi_Gen","Phi of non-HSCP GEN particles",100,-3.5,3.5);
  TH1F* h_deltaEta_HSCP1_HSCP2 = new TH1F("h_deltaEta_HSCP1_HSCP2","Delta Eta between HSCP1 and HSCP2",100,-20,20);
  TH1F* h_deltaPhi_HSCP1_HSCP2 = new TH1F("h_deltaPhi_HSCP1_HSCP2","Delta Phi between HSCP1 and HSCP2",100,0,3.5);
  TH1F* h_deltaR_HSCP1_HSCP2 = new TH1F("h_deltaR_HSCP1_HSCP2","Delta R between HSCP1 and HSCP2",100,0,20);
  TH1F* h_deltaPhi_HSCP1_HSCP2_numEvents = new TH1F("h_deltaPhi_HSCP1_HSCP2_numEvents","how many events in each dPhi bin",4,0,4);
  TH1F* h_deltaEta_HSCP1_Gen = new TH1F("h_deltaEta_HSCP1_Gen","Delta Eta between HSCP1 and other GEN particles",100,-20,20);
  TH1F* h_deltaPhi_HSCP1_Gen = new TH1F("h_deltaPhi_HSCP1_Gen","Delta Phi between HSCP1 and other GEN particles",100,0,3.5);
  TH1F* h_deltaR_HSCP1_Gen = new TH1F("h_deltaR_HSCP1_Gen","Delta R between HSCP1 and other GEN particles",100,0,20);
  TH1F* h_deltaEta_HSCP1_Gen_pT5 = new TH1F("h_deltaEta_HSCP1_Gen_pT5","Delta Eta between HSCP1 and other GEN particles with pT > 5 GeV",100,-20,20);
  TH1F* h_deltaPhi_HSCP1_Gen_pT5 = new TH1F("h_deltaPhi_HSCP1_Gen_pT5","Delta Phi between HSCP1 and other GEN particles with pT > 5 GeV",100,0,3.5);
  TH1F* h_deltaR_HSCP1_Gen_pT5 = new TH1F("h_deltaR_HSCP1_Gen_pT5","Delta R between HSCP1 and other GEN particles with pT > 5 GV",100,0,20);
  TH1F* h_deltaEta_HSCP1_Gen_pT50 = new TH1F("h_deltaEta_HSCP1_Gen_pT50","Delta Eta between HSCP1 and other GEN particles with pT > 50 GeV",100,-20,20);
  TH1F* h_deltaPhi_HSCP1_Gen_pT50 = new TH1F("h_deltaPhi_HSCP1_Gen_pT50","Delta Phi between HSCP1 and other GEN particles with pT > 50 GeV",100,0,3.5);
  TH1F* h_deltaR_HSCP1_Gen_pT50 = new TH1F("h_deltaR_HSCP1_Gen_pT50","Delta R between HSCP1 and other GEN particles with pT > 50 GV",100,0,20);
  TH1F* h_deltaEta_HSCP1_Gen_pT100 = new TH1F("h_deltaEta_HSCP1_Gen_pT100","Delta Eta between HSCP1 and other GEN particles with pT > 100 GeV",100,-20,20);
  TH1F* h_deltaPhi_HSCP1_Gen_pT100 = new TH1F("h_deltaPhi_HSCP1_Gen_pT100","Delta Phi between HSCP1 and other GEN particles with pT > 100 GeV",100,0,3.5);
  TH1F* h_deltaR_HSCP1_Gen_pT100 = new TH1F("h_deltaR_HSCP1_Gen_pT100","Delta R between HSCP1 and other GEN particles with pT > 100 GV",100,0,20);
  TH1F* h_deltaEta_HSCP1_Gen_bin1 = new TH1F("h_deltaEta_HSCP1_Gen_bin1","Delta Eta between HSCP1 and other GEN particles for HSCP dPhi >= 3.1",100,-20,20);
  TH1F* h_deltaPhi_HSCP1_Gen_bin1 = new TH1F("h_deltaPhi_HSCP1_Gen_bin1","Delta Phi between HSCP1 and other GEN particles for HSCP dPhi >= 3.1",100,0,3.5);
  TH1F* h_deltaR_HSCP1_Gen_bin1 = new TH1F("h_deltaR_HSCP1_Gen_bin1","Delta R between HSCP1 and other GEN particles for HSCP dPhi >= 3.1",100,0,20);
  TH1F* h_deltaEta_HSCP1_Gen_pT5_bin1 = new TH1F("h_deltaEta_HSCP1_Gen_pT5_bin1","Delta Eta between HSCP1 and other GEN particles with pT > 5 GeV and HSCP dPhi >= 3.1",100,-20,20);
  TH1F* h_deltaPhi_HSCP1_Gen_pT5_bin1 = new TH1F("h_deltaPhi_HSCP1_Gen_pT5_bin1","Delta Phi between HSCP1 and other GEN particles with pT > 5 GeV and HSCP dPhi >= 3.1",100,0,3.5);
  TH1F* h_deltaR_HSCP1_Gen_pT5_bin1 = new TH1F("h_deltaR_HSCP1_Gen_pT5_bin1","Delta R between HSCP1 and other GEN particles with pT > 5 GeV and HSCP dPhi >= 3.1",100,0,20);
  TH1F* h_deltaEta_HSCP1_Gen_pT50_bin1 = new TH1F("h_deltaEta_HSCP1_Gen_pT50_bin1","Delta Eta between HSCP1 and other GEN particles with pT > 50 GeV and HSCP dPhi >= 3.1",100,-20,20);
  TH1F* h_deltaPhi_HSCP1_Gen_pT50_bin1 = new TH1F("h_deltaPhi_HSCP1_Gen_pT50_bin1","Delta Phi between HSCP1 and other GEN particles with pT > 50 GeV and HSCP dPhi >= 3.1",100,0,3.5);
  TH1F* h_deltaR_HSCP1_Gen_pT50_bin1 = new TH1F("h_deltaR_HSCP1_Gen_pT50_bin1","Delta R between HSCP1 and other GEN particles with pT > 50 GV and HSCP dPhi >= 3.1",100,0,20);
  TH1F* h_deltaEta_HSCP1_Gen_pT100_bin1 = new TH1F("h_deltaEta_HSCP1_Gen_pT100_bin1","Delta Eta between HSCP1 and other GEN particles with pT > 100 GeV and HSCP dPhi >= 3.1",100,-20,20);
  TH1F* h_deltaPhi_HSCP1_Gen_pT100_bin1 = new TH1F("h_deltaPhi_HSCP1_Gen_pT100_bin1","Delta Phi between HSCP1 and other GEN particles with pT > 100 GeV and HSCP dPhi >= 3.1",100,0,3.5);
  TH1F* h_deltaR_HSCP1_Gen_pT100_bin1 = new TH1F("h_deltaR_HSCP1_Gen_pT100_bin1","Delta R between HSCP1 and other GEN particles with pT > 100 GV and HSCP dPhi >= 3.1",100,0,20);
  TH1F* h_deltaEta_HSCP2_Gen = new TH1F("h_deltaEta_HSCP2_Gen","Delta Eta between HSCP2 and other GEN particles",100,-20,20);
  TH1F* h_deltaPhi_HSCP2_Gen = new TH1F("h_deltaPhi_HSCP2_Gen","Delta Phi between HSCP2 and other GEN particles",100,0,3.5);
  TH1F* h_deltaR_HSCP2_Gen = new TH1F("h_deltaR_HSCP2_Gen","Delta R between HSCP2 and other GEN particles",100,0,20);
  TH1F* h_deltaEta_HSCP2_Gen_pT5 = new TH1F("h_deltaEta_HSCP2_Gen_pT5","Delta Eta between HSCP2 and other GEN particles with pT > 5 GeV",100,-20,20);
  TH1F* h_deltaPhi_HSCP2_Gen_pT5 = new TH1F("h_deltaPhi_HSCP2_Gen_pT5","Delta Phi between HSCP2 and other GEN particles with pT > 5 GeV",100,0,3.5);
  TH1F* h_deltaR_HSCP2_Gen_pT5 = new TH1F("h_deltaR_HSCP2_Gen_pT5","Delta R between HSCP2 and other GEN particles with pT > 5 GV",100,0,20);
  TH1F* h_deltaEta_HSCP2_Gen_pT50 = new TH1F("h_deltaEta_HSCP2_Gen_pT50","Delta Eta between HSCP2 and other GEN particles with pT > 50 GeV",100,-20,20);
  TH1F* h_deltaPhi_HSCP2_Gen_pT50 = new TH1F("h_deltaPhi_HSCP2_Gen_pT50","Delta Phi between HSCP2 and other GEN particles with pT > 50 GeV",100,0,3.5);
  TH1F* h_deltaR_HSCP2_Gen_pT50 = new TH1F("h_deltaR_HSCP2_Gen_pT50","Delta R between HSCP2 and other GEN particles with pT > 50 GV",100,0,20);
  TH1F* h_deltaEta_HSCP2_Gen_pT100 = new TH1F("h_deltaEta_HSCP2_Gen_pT100","Delta Eta between HSCP2 and other GEN particles with pT > 100 GeV",100,-20,20);
  TH1F* h_deltaPhi_HSCP2_Gen_pT100 = new TH1F("h_deltaPhi_HSCP2_Gen_pT100","Delta Phi between HSCP2 and other GEN particles with pT > 100 GeV",100,0,3.5);
  TH1F* h_deltaR_HSCP2_Gen_pT100 = new TH1F("h_deltaR_HSCP2_Gen_pT100","Delta R between HSCP2 and other GEN particles with pT > 100 GV",100,0,20);
  TH1F* h_deltaEta_HSCP2_Gen_bin1 = new TH1F("h_deltaEta_HSCP2_Gen_bin1","Delta Eta between HSCP2 and other GEN particles for HSCP dPhi >= 3.1",100,-20,20);
  TH1F* h_deltaPhi_HSCP2_Gen_bin1 = new TH1F("h_deltaPhi_HSCP2_Gen_bin1","Delta Phi between HSCP2 and other GEN particles for HSCP dPhi >= 3.1",100,0,3.5);
  TH1F* h_deltaR_HSCP2_Gen_bin1 = new TH1F("h_deltaR_HSCP2_Gen_bin1","Delta R between HSCP2 and other GEN particles for HSCP dPhi >= 3.1",100,0,20);
  TH1F* h_deltaEta_HSCP2_Gen_pT5_bin1 = new TH1F("h_deltaEta_HSCP2_Gen_pT5_bin1","Delta Eta between HSCP2 and other GEN particles with pT > 5 GeV and HSCP dPhi >= 3.1",100,-20,20);
  TH1F* h_deltaPhi_HSCP2_Gen_pT5_bin1 = new TH1F("h_deltaPhi_HSCP2_Gen_pT5_bin1","Delta Phi between HSCP2 and other GEN particles with pT > 5 GeV and HSCP dPhi >= 3.1",100,0,3.5);
  TH1F* h_deltaR_HSCP2_Gen_pT5_bin1 = new TH1F("h_deltaR_HSCP2_Gen_pT5_bin1","Delta R between HSCP2 and other GEN particles with pT > 5 GeV and HSCP dPhi >= 3.1",100,0,20);
  TH1F* h_deltaEta_HSCP2_Gen_pT50_bin1 = new TH1F("h_deltaEta_HSCP2_Gen_pT50_bin1","Delta Eta between HSCP2 and other GEN particles with pT > 50 GeV and HSCP dPhi >= 3.1",100,-20,20);
  TH1F* h_deltaPhi_HSCP2_Gen_pT50_bin1 = new TH1F("h_deltaPhi_HSCP2_Gen_pT50_bin1","Delta Phi between HSCP2 and other GEN particles with pT > 50 GeV and HSCP dPhi >= 3.1",100,0,3.5);
  TH1F* h_deltaR_HSCP2_Gen_pT50_bin1 = new TH1F("h_deltaR_HSCP2_Gen_pT50_bin1","Delta R between HSCP2 and other GEN particles with pT > 50 GV and HSCP dPhi >= 3.1",100,0,20);
  TH1F* h_deltaEta_HSCP2_Gen_pT100_bin1 = new TH1F("h_deltaEta_HSCP2_Gen_pT100_bin1","Delta Eta between HSCP2 and other GEN particles with pT > 100 GeV and HSCP dPhi >= 3.1",100,-20,20);
  TH1F* h_deltaPhi_HSCP2_Gen_pT100_bin1 = new TH1F("h_deltaPhi_HSCP2_Gen_pT100_bin1","Delta Phi between HSCP2 and other GEN particles with pT > 100 GeV and HSCP dPhi >= 3.1",100,0,3.5);
  TH1F* h_deltaR_HSCP2_Gen_pT100_bin1 = new TH1F("h_deltaR_HSCP2_Gen_pT100_bin1","Delta R between HSCP2 and other GEN particles with pT > 100 GV and HSCP dPhi >= 3.1",100,0,20);
  TH1F* h_deltaEta_HSCP2_Gen_bin2 = new TH1F("h_deltaEta_HSCP2_Gen_bin2","Delta Eta between HSCP2 and other GEN particles for 3.1 > HSCP dPhi >= 2.35",100,-20,20);
  TH1F* h_deltaPhi_HSCP2_Gen_bin2 = new TH1F("h_deltaPhi_HSCP2_Gen_bin2","Delta Phi between HSCP2 and other GEN particles for 3.1 > HSCP dPhi >= 2.35",100,0,3.5);
  TH1F* h_deltaR_HSCP2_Gen_bin2 = new TH1F("h_deltaR_HSCP2_Gen_bin2","Delta R between HSCP2 and other GEN particles for 3.1 > HSCP dPhi >= 2.35",100,0,20);
  TH1F* h_deltaEta_HSCP2_Gen_pT5_bin2 = new TH1F("h_deltaEta_HSCP2_Gen_pT5_bin2","Delta Eta between HSCP2 and other GEN particles with pT > 5 GeV and 3.1 > HSCP dPhi >= 2.35",100,-20,20);
  TH1F* h_deltaPhi_HSCP2_Gen_pT5_bin2 = new TH1F("h_deltaPhi_HSCP2_Gen_pT5_bin2","Delta Phi between HSCP2 and other GEN particles with pT > 5 GeV and 3.1 > HSCP dPhi >= 2.35",100,0,3.5);
  TH1F* h_deltaR_HSCP2_Gen_pT5_bin2 = new TH1F("h_deltaR_HSCP2_Gen_pT5_bin2","Delta R between HSCP2 and other GEN particles with pT > 5 GeV and 3.1 > HSCP dPhi >= 2.35",100,0,20);
  TH1F* h_deltaEta_HSCP2_Gen_pT50_bin2 = new TH1F("h_deltaEta_HSCP2_Gen_pT50_bin2","Delta Eta between HSCP2 and other GEN particles with pT > 50 GeV and 3.1 > HSCP dPhi >= 2.35",100,-20,20);
  TH1F* h_deltaPhi_HSCP2_Gen_pT50_bin2 = new TH1F("h_deltaPhi_HSCP2_Gen_pT50_bin2","Delta Phi between HSCP2 and other GEN particles with pT > 50 GeV and 3.1 > HSCP dPhi >= 2.35",100,0,3.5);
  TH1F* h_deltaR_HSCP2_Gen_pT50_bin2 = new TH1F("h_deltaR_HSCP2_Gen_pT50_bin2","Delta R between HSCP2 and other GEN particles with pT > 50 GV and 3.1 > HSCP dPhi >= 2.35",100,0,20);
  TH1F* h_deltaEta_HSCP2_Gen_pT100_bin2 = new TH1F("h_deltaEta_HSCP2_Gen_pT100_bin2","Delta Eta between HSCP2 and other GEN particles with pT > 100 GeV and 3.1 > HSCP dPhi >= 2.35",100,-20,20);
  TH1F* h_deltaPhi_HSCP2_Gen_pT100_bin2 = new TH1F("h_deltaPhi_HSCP2_Gen_pT100_bin2","Delta Phi between HSCP2 and other GEN particles with pT > 100 GeV and 3.1 > HSCP dPhi >= 2.35",100,0,3.5);
  TH1F* h_deltaR_HSCP2_Gen_pT100_bin2 = new TH1F("h_deltaR_HSCP2_Gen_pT100_bin2","Delta R between HSCP2 and other GEN particles with pT > 100 GV and 3.1 > HSCP dPhi >= 2.35",100,0,20);
  TH1F* h_deltaEta_HSCP2_Gen_bin3 = new TH1F("h_deltaEta_HSCP2_Gen_bin3","Delta Eta between HSCP2 and other GEN particles for 2.35 > HSCP dPhi >= 1.6",100,-20,20);
  TH1F* h_deltaPhi_HSCP2_Gen_bin3 = new TH1F("h_deltaPhi_HSCP2_Gen_bin3","Delta Phi between HSCP2 and other GEN particles for 2.35 > HSCP dPhi >= 1.6",100,0,3.5);
  TH1F* h_deltaR_HSCP2_Gen_bin3 = new TH1F("h_deltaR_HSCP2_Gen_bin3","Delta R between HSCP2 and other GEN particles for 2.35 > HSCP dPhi >= 1.6",100,0,20);
  TH1F* h_deltaEta_HSCP2_Gen_pT5_bin3 = new TH1F("h_deltaEta_HSCP2_Gen_pT5_bin3","Delta Eta between HSCP2 and other GEN particles with pT > 5 GeV and 2.35 > HSCP dPhi >= 1.6",100,-20,20);
  TH1F* h_deltaPhi_HSCP2_Gen_pT5_bin3 = new TH1F("h_deltaPhi_HSCP2_Gen_pT5_bin3","Delta Phi between HSCP2 and other GEN particles with pT > 5 GeV and 2.35 > HSCP dPhi >= 1.6",100,0,3.5);
  TH1F* h_deltaR_HSCP2_Gen_pT5_bin3 = new TH1F("h_deltaR_HSCP2_Gen_pT5_bin3","Delta R between HSCP2 and other GEN particles with pT > 5 GeV and 2.35 > HSCP dPhi >= 1.6",100,0,20);
  TH1F* h_deltaEta_HSCP2_Gen_pT50_bin3 = new TH1F("h_deltaEta_HSCP2_Gen_pT50_bin3","Delta Eta between HSCP2 and other GEN particles with pT > 50 GeV and 2.35 > HSCP dPhi >= 1.6",100,-20,20);
  TH1F* h_deltaPhi_HSCP2_Gen_pT50_bin3 = new TH1F("h_deltaPhi_HSCP2_Gen_pT50_bin3","Delta Phi between HSCP2 and other GEN particles with pT > 50 GeV and 2.35 > HSCP dPhi >= 1.6",100,0,3.5);
  TH1F* h_deltaR_HSCP2_Gen_pT50_bin3 = new TH1F("h_deltaR_HSCP2_Gen_pT50_bin3","Delta R between HSCP2 and other GEN particles with pT > 50 GV and 2.35 > HSCP dPhi >= 1.6",100,0,20);
  TH1F* h_deltaEta_HSCP2_Gen_pT100_bin3 = new TH1F("h_deltaEta_HSCP2_Gen_pT100_bin3","Delta Eta between HSCP2 and other GEN particles with pT > 100 GeV and 2.35 > HSCP dPhi >= 1.6",100,-20,20);
  TH1F* h_deltaPhi_HSCP2_Gen_pT100_bin3 = new TH1F("h_deltaPhi_HSCP2_Gen_pT100_bin3","Delta Phi between HSCP2 and other GEN particles with pT > 100 GeV and 2.35 > HSCP dPhi >= 1.6",100,0,3.5);
  TH1F* h_deltaR_HSCP2_Gen_pT100_bin3 = new TH1F("h_deltaR_HSCP2_Gen_pT100_bin3","Delta R between HSCP2 and other GEN particles with pT > 100 GV and 2.35 > HSCP dPhi >= 1.6",100,0,20);
  TH1F* h_deltaEta_HSCP2_Gen_bin4 = new TH1F("h_deltaEta_HSCP2_Gen_bin4","Delta Eta between HSCP2 and other GEN particles for HSCP dPhi < 1.6",100,-20,20);
  TH1F* h_deltaPhi_HSCP2_Gen_bin4 = new TH1F("h_deltaPhi_HSCP2_Gen_bin4","Delta Phi between HSCP2 and other GEN particles for HSCP dPhi < 1.6",100,0,3.5);
  TH1F* h_deltaR_HSCP2_Gen_bin4 = new TH1F("h_deltaR_HSCP2_Gen_bin4","Delta R between HSCP2 and other GEN particles for HSCP dPhi < 1.6",100,0,20);
  TH1F* h_deltaEta_HSCP2_Gen_pT5_bin4 = new TH1F("h_deltaEta_HSCP2_Gen_pT5_bin4","Delta Eta between HSCP2 and other GEN particles with pT > 5 GeV and HSCP dPhi < 1.6",100,-20,20);
  TH1F* h_deltaPhi_HSCP2_Gen_pT5_bin4 = new TH1F("h_deltaPhi_HSCP2_Gen_pT5_bin4","Delta Phi between HSCP2 and other GEN particles with pT > 5 GeV and HSCP dPhi < 1.6",100,0,3.5);
  TH1F* h_deltaR_HSCP2_Gen_pT5_bin4 = new TH1F("h_deltaR_HSCP2_Gen_pT5_bin4","Delta R between HSCP2 and other GEN particles with pT > 5 GeV and HSCP dPhi < 1.6",100,0,20);
  TH1F* h_deltaEta_HSCP2_Gen_pT50_bin4 = new TH1F("h_deltaEta_HSCP2_Gen_pT50_bin4","Delta Eta between HSCP2 and other GEN particles with pT > 50 GeV and HSCP dPhi < 1.6",100,-20,20);
  TH1F* h_deltaPhi_HSCP2_Gen_pT50_bin4 = new TH1F("h_deltaPhi_HSCP2_Gen_pT50_bin4","Delta Phi between HSCP2 and other GEN particles with pT > 50 GeV and HSCP dPhi < 1.6",100,0,3.5);
  TH1F* h_deltaR_HSCP2_Gen_pT50_bin4 = new TH1F("h_deltaR_HSCP2_Gen_pT50_bin4","Delta R between HSCP2 and other GEN particles with pT > 50 GV and HSCP dPhi < 1.6",100,0,20);
  TH1F* h_deltaEta_HSCP2_Gen_pT100_bin4 = new TH1F("h_deltaEta_HSCP2_Gen_pT100_bin4","Delta Eta between HSCP2 and other GEN particles with pT > 100 GeV and HSCP dPhi < 1.6",100,-20,20);
  TH1F* h_deltaPhi_HSCP2_Gen_pT100_bin4 = new TH1F("h_deltaPhi_HSCP2_Gen_pT100_bin4","Delta Phi between HSCP2 and other GEN particles with pT > 100 GeV and HSCP dPhi < 1.6",100,0,3.5);
  TH1F* h_deltaR_HSCP2_Gen_pT100_bin4 = new TH1F("h_deltaR_HSCP2_Gen_pT100_bin4","Delta R between HSCP2 and other GEN particles with pT > 100 GV and HSCP dPhi < 1.6",100,0,20);
  TH1F* h_Phi_diHSCP = new TH1F("h_Phi_diHSCP","Phi of diHSCP system",100,-3.5,3.5);
  TH1F* h_mag_diHSCP = new TH1F("h_mag_diHSCP","magnitude of diHSCP system",100,0,3000);
  TH2F* h_Phi_diHSCP_mag = new TH2F("h_Phi_diHSCP_mag","|pT| vs Phi of diHSCP system;phi;|pT|",100,-3.5,3.5,100,0,3000);  
  TH2F* h_Phi_diHSCP_mag_bin1 = new TH2F("h_Phi_diHSCP_mag_bin1","|pT| vs Phi of diHSCP system with HSCP dPhi >= 3.1;phi;|pT|",100,-3.5,3.5,100,0,3000);
  TH2F* h_Phi_diHSCP_mag_bin2 = new TH2F("h_Phi_diHSCP_mag_bin2","|pT| vs Phi of diHSCP system with 3.1 > HSCP dPhi >= 2.35;phi;|pT|",100,-3.5,3.5,100,0,3000);
  TH2F* h_Phi_diHSCP_mag_bin3 = new TH2F("h_Phi_diHSCP_mag_bin3","|pT| vs Phi of diHSCP system with 2.35 > HSCP dPhi >= 1.6;phi;|pT|",100,-3.5,3.5,100,0,3000);
  TH2F* h_Phi_diHSCP_mag_bin4 = new TH2F("h_Phi_diHSCP_mag_bin4","|pT| vs Phi of diHSCP system with HSCP dPhi < 1.6;phi;|pT|",100,-3.5,3.5,100,0,3000);  
  TH1F* h_deltaPhi_diHSCP_Gen = new TH1F("h_deltaPhi_diHSCP_Gen","Delta Phi between diHSCP and other GEN particles",100,0,3.5);
  TH1F* h_deltaPhi_diHSCP_Gen_pT5 = new TH1F("h_deltaPhi_diHSCP_Gen_pT5","Delta Phi between diHSCP and other GEN particles with pT > 5 GeV",100,0,3.5);
  TH1F* h_deltaPhi_diHSCP_Gen_pT50 = new TH1F("h_deltaPhi_diHSCP_Gen_pT50","Delta Phi between diHSCP and other GEN particles with pT > 50 GeV",100,0,3.5);
  TH1F* h_deltaPhi_diHSCP_Gen_pT100 = new TH1F("h_deltaPhi_diHSCP_Gen_pT100","Delta Phi between diHSCP and other GEN particles with pT > 100 GeV",100,0,3.5);
  TH2F* h_deltaPhi_diHSCP_Gen_GenpT = new TH2F("h_deltaPhi_diHSCP_Gen_GenpT","GEN pT vs dPhi(diHSCP, other GEN particles);dPhi;pT [GeV]",100,0,3.5,100,0,1500); 
  TH2F* h_deltaPhi_diHSCP_Gen_pT5_GenpT = new TH2F("h_deltaPhi_diHSCP_Gen_pT5_GenpT","GEN pT vs dPhi(diHSCP, other GEN particles) with GEN pT > 5 GeV;dPhi;pT [GeV]",100,0,3.5,100,0,1500); 
  TH2F* h_deltaPhi_diHSCP_Gen_pT50_GenpT = new TH2F("h_deltaPhi_diHSCP_Gen_pT50_GenpT","GEN pT vs dPhi(diHSCP, other GEN particles) with GEN pT > 50 GeV;dPhi;pT [GeV]",100,0,3.5,100,0,1500); 
  TH2F* h_deltaPhi_diHSCP_Gen_pT100_GenpT = new TH2F("h_deltaPhi_diHSCP_Gen_pT100_GenpT","GEN pT vs dPhi(diHSCP, other GEN particles) with GEN pT > 100 GeV;dPhi;pT [GeV]",100,0,3.5,100,0,1500); 
  TH2F* h_deltaPhi_diHSCP_Gen_GenpT_bin1 = new TH2F("h_deltaPhi_diHSCP_Gen_GenpT_bin1","GEN pT vs dPhi(diHSCP, other GEN particles) with dPhi HSCP >= 3.1;dPhi;pT [GeV]",100,0,3.5,100,0,1500); 
  TH2F* h_deltaPhi_diHSCP_Gen_pT5_GenpT_bin1 = new TH2F("h_deltaPhi_diHSCP_Gen_pT5_GenpT_bin1","GEN pT vs dPhi(diHSCP, other GEN particles) with GEN pT > 5 GeV and HSCP dPhi >= 3.1;dPhi;pT [GeV]",100,0,3.5,100,0,1500); 
  TH2F* h_deltaPhi_diHSCP_Gen_pT50_GenpT_bin1 = new TH2F("h_deltaPhi_diHSCP_Gen_pT50_GenpT_bin1","GEN pT vs dPhi(diHSCP, other GEN particles) with GEN pT > 50 GeV and HSCP dPhi >= 3.1;dPhi;pT [GeV]",100,0,3.5,100,0,1500); 
  TH2F* h_deltaPhi_diHSCP_Gen_pT100_GenpT_bin1 = new TH2F("h_deltaPhi_diHSCP_Gen_pT100_GenpT_bin1","GEN pT vs dPhi(diHSCP, other GEN particles) with GEN pT > 100 GeV and HSCP dPhi >= 3.1;dPhi;pT [GeV]",100,0,3.5,100,0,1500); 
  TH2F* h_deltaPhi_diHSCP_Gen_GenpT_bin2 = new TH2F("h_deltaPhi_diHSCP_Gen_GenpT_bin2","GEN pT vs dPhi(diHSCP, other GEN particles) with 3.1 > dPhi HSCP >= 2.35;dPhi;pT [GeV]",100,0,3.5,100,0,1500); 
  TH2F* h_deltaPhi_diHSCP_Gen_pT5_GenpT_bin2 = new TH2F("h_deltaPhi_diHSCP_Gen_pT5_GenpT_bin2","GEN pT vs dPhi(diHSCP, other GEN particles) with GEN pT > 5 GeV and 3.1 > dPhi HSCP >= 2.35;dPhi;pT [GeV]",100,0,3.5,100,0,1500); 
  TH2F* h_deltaPhi_diHSCP_Gen_pT50_GenpT_bin2 = new TH2F("h_deltaPhi_diHSCP_Gen_pT50_GenpT_bin2","GEN pT vs dPhi(diHSCP, other GEN particles) with GEN pT > 50 GeV and 3.1 > dPhi HSCP >= 2.35;dPhi;pT [GeV]",100,0,3.5,100,0,1500); 
  TH2F* h_deltaPhi_diHSCP_Gen_pT100_GenpT_bin2 = new TH2F("h_deltaPhi_diHSCP_Gen_pT100_GenpT_bin2","GEN pT vs dPhi(diHSCP, other GEN particles) with GEN pT > 100 GeV and 3.1 > dPhi HSCP >= 2.35;dPhi;pT [GeV]",100,0,3.5,100,0,1500); 
  TH2F* h_deltaPhi_diHSCP_Gen_GenpT_bin3 = new TH2F("h_deltaPhi_diHSCP_Gen_GenpT_bin3","GEN pT vs dPhi(diHSCP, other GEN particles) with 2.35 > dPhi HSCP >= 1.6;dPhi;pT [GeV]",100,0,3.5,100,0,1500); 
  TH2F* h_deltaPhi_diHSCP_Gen_pT5_GenpT_bin3 = new TH2F("h_deltaPhi_diHSCP_Gen_pT5_GenpT_bin3","GEN pT vs dPhi(diHSCP, other GEN particles) with GEN pT > 5 GeV and 2.35 > dPhi HSCP >= 1.6;dPhi;pT [GeV]",100,0,3.5,100,0,1500); 
  TH2F* h_deltaPhi_diHSCP_Gen_pT50_GenpT_bin3 = new TH2F("h_deltaPhi_diHSCP_Gen_pT50_GenpT_bin3","GEN pT vs dPhi(diHSCP, other GEN particles) with GEN pT > 50 GeV and 2.35 > dPhi HSCP >= 1.6;dPhi;pT [GeV]",100,0,3.5,100,0,1500); 
  TH2F* h_deltaPhi_diHSCP_Gen_pT100_GenpT_bin3 = new TH2F("h_deltaPhi_diHSCP_Gen_pT100_GenpT_bin3","GEN pT vs dPhi(diHSCP, other GEN particles) with GEN pT > 100 GeV and 2.35 > dPhi HSCP >= 1.6;dPhi;pT [GeV]",100,0,3.5,100,0,1500); 
  TH2F* h_deltaPhi_diHSCP_Gen_GenpT_bin4 = new TH2F("h_deltaPhi_diHSCP_Gen_GenpT_bin4","GEN pT vs dPhi(diHSCP, other GEN particles) with dPhi HSCP < 1.6;dPhi;pT [GeV]",100,0,3.5,100,0,1500); 
  TH2F* h_deltaPhi_diHSCP_Gen_pT5_GenpT_bin4 = new TH2F("h_deltaPhi_diHSCP_Gen_pT5_GenpT_bin4","GEN pT vs dPhi(diHSCP, other GEN particles) with GEN pT > 5 GeV and dPhi HSCP < 1.6;dPhi;pT [GeV]",100,0,3.5,100,0,1500); 
  TH2F* h_deltaPhi_diHSCP_Gen_pT50_GenpT_bin4 = new TH2F("h_deltaPhi_diHSCP_Gen_pT50_GenpT_bin4","GEN pT vs dPhi(diHSCP, other GEN particles) with GEN pT > 50 GeV and dPhi HSCP < 1.6;dPhi;pT [GeV]",100,0,3.5,100,0,1500); 
  TH2F* h_deltaPhi_diHSCP_Gen_pT100_GenpT_bin4 = new TH2F("h_deltaPhi_diHSCP_Gen_pT100_GenpT_bin4","GEN pT vs dPhi(diHSCP, other GEN particles) with GEN pT > 100 GeV and dPhi HSCP < 1.6;dPhi;pT [GeV]",100,0,3.5,100,0,1500); 
  TH1F* h_deltaPhi_neg_diHSCP_Gen = new TH1F("h_deltaPhi_neg_diHSCP_Gen","dPhi(-diHSCP pT, other GEN particles)",100,0,3.5);
  TH1F* h_deltaPhi_neg_diHSCP_Gen_pT5 = new TH1F("h_deltaPhi_neg_diHSCP_Gen_pT5","dPhi(-diHSCP pT, other GEN particles with pT > 5 GeV);dPhi;",100,0,3.5);
  TH1F* h_deltaPhi_neg_diHSCP_Gen_pT50 = new TH1F("h_deltaPhi_neg_diHSCP_Gen_pT50","dPhi(-diHSCP pT, other GEN particles with pT > 50 GeV);dphi;",100,0,3.5);
  TH1F* h_deltaPhi_neg_diHSCP_Gen_pT100 = new TH1F("h_deltaPhi_neg_diHSCP_Gen_pT100","dPhi(-diHSCP pT, other GEN particles with pT > 100 GeV);dPhi;",100,0,3.5);
  TH1F* h_deltaPhi_neg_diHSCP_pT100_Gen = new TH1F("h_deltaPhi_neg_diHSCP_pT100_Gen","dPhi(-diHSCP with pT > 100 GeV, other GEN particles);dPhi;",100,0,3.5);
  TH1F* h_deltaPhi_neg_diHSCP_pT100_Gen_pT5 = new TH1F("h_deltaPhi_neg_diHSCP_pT100_Gen_pT5","dPhi(-diHSCP with pT > 100 GeV, other GEN particles with pT > 5 GeV);dPhi;",100,0,3.5);
  TH1F* h_deltaPhi_neg_diHSCP_pT100_Gen_pT50 = new TH1F("h_deltaPhi_neg_diHSCP_pT100_Gen_pT50","dPhi(-diHSCP with pT > 100 GeV, other GEN particles with pT > 50 GeV);dPhi;",100,0,3.5);
  TH1F* h_deltaPhi_neg_diHSCP_pT100_Gen_pT100 = new TH1F("h_deltaPhi_neg_diHSCP_pT100_Gen_pT100","dPhi(-diHSCP with pT > 100 GeV, other GEN particles with pT > 100 GeV);dPhi;",100,0,3.5);
  TH1F* h_neg_diHSCP_cone0p4_GenPtMag = new TH1F("h_neg_diHSCP_cone0p4_GenPtMag","total Gen Pt in dPhi<0.4 of neg of diHSCP",100,0,3000);
  TH1F* h_diHSCP_L1METHF = new TH1F("h_diHSCP_L1METHF","dPhi(diHSCP,L1METHF);dPhi",100,0,3.5);
  TH1F* h_diHSCP_pT100_L1METHF_pT100_noSat = new TH1F("h_diHSCP_pT100_L1METHF_pT100_noSat","dPhi(diHSCP,L1METHF) for |pT|>100 GeV for both, and no L1 calo tower saturation",100,0,3.5);
  TH1F* h_deltaPhi_diHSCP_HSCP = new TH1F("h_deltaPhi_diHSCP_HSCP","dPhi(diHSCP,HSCPs)",100,0,3.5);
  TH1F* h_deltaPhi_diHSCP_pT100_HSCP_pT100 = new TH1F("h_deltaPhi_diHSCP_pT100_HSCP_pT100","dPhi(diHSCP,HSCPs) with |pT|>100 GeV for both",100,0,3.5);
  TH1I* h_total_NJets = new TH1I("h_total_NJets","total number of jets",50,0,50);
  TH1I* h_total_NJetsMinusMatched = new TH1I("h_total_NJetsMinusMatched","total number of jets minus number of jets matched to HSCPs",50,0,50);
  TH1I* h_total_NGenHSCPMatched_2HSCP_2jet = new TH1I("h_total_NGenHSCPMatched_2HSCP_2jet","total number of GenHSCP matched to a jet (dR<0.1) with 2 GenHSCP & 2 jets",3,0,3);
  TH1I* h_total_NGenHSCPMatched_2HSCP_1jet = new TH1I("h_total_NGenHSCPMatched_2HSCP_1jet","total number of GenHSCP matched to a jet (dR<0.1) with 2 GenHSCP & 1 jet",3,0,3);
  TH1I* h_total_NGenHSCPMatched_1HSCP = new TH1I("h_totalNGenHSCPMatched_1HSCP","total number of GenHSCP matched to a jet (dR<0.1) with 1 GenHSCP",3,0,3);

  TH2F* h_jetPt_muonPt_allmatched = new TH2F("h_jetPt_muonPt_allmatched","Muon Pt vs Jet Pt when a jet and a muon are both matched to a GenHSCP with dR<0.1;Jet Pt [GeV];Muon Pt [GeV]",100,0,5000,100,0,5000);
  TH2F* h_jetPt_genhscpPt_allmatched = new TH2F("h_jetPt_genhscpPt_allmatched","GenHSCP Pt vs Jet Pt when a jet and a muon are both matched to a GenHSCP with dR<0.1;Jet Pt [GeV];GenHSCP Pt [GeV]",100,0,5000,100,0,5000);
  TH2F* h_muonPt_genhscpPt_allmatched = new TH2F("h_muonPt_genhscpPt_allmatched","GenHSCP Pt vs Muon Pt when a jet & a muon are both matched to a GenHSCP with dR<0.1;Muon Pt [GeV];GenHSCP Pt [GeV]",100,0,5000,100,0,5000);
  TH1F* h_jetPt_allmatched = new TH1F("h_jetPt_allmatched","Jet Pt when a jet and a muon are both matched to a GenHSCP with dR<0.1;Jet Pt [GeV];",100,0,5000);
  TH1F* h_muonPt_allmatched = new TH1F("h_muonPt_allmatched","Muon Pt when a jet and a muon are both matched to a GenHSCP with dR<0.1;Jet Pt [GeV];",100,0,5000);
  TH1F* h_genhscpPt_allmatched = new TH1F("h_genhscpPt_allmatched","GenHSCP Pt when a jet and a muon are both matched to a GenHSCP with dR<0.1;Jet Pt [GeV];",100,0,5000);


  TH1F* h_muonPt_matched = new TH1F("h_muonPt_matched","Pt for muons matched to HSCPs (dR<0.1)",100,0,5000);
  TH1F* h_muonEta_matched = new TH1F("h_muonEta_matched","Eta for muons matched to HSCPs (dR<0.1)",100,-5,5);
  TH1F* h_muonPhi_matched = new TH1F("h_muonPhi_matched","Phi for muons matched to HSCPs (dR<0.1)",100,-3.5,3.5);
  TH1I* h_muonType_matched = new TH1I("h_muonType_matched","Pt for muons matched to HSCPs (dR<0.1)",128,0,128);

  TH1F* h_jetPt_matched = new TH1F("h_jetPt_matched","Pt for jets matched to HSCPs (dR<0.1)",100,0,5000);
  TH1F* h_jetEta_matched = new TH1F("h_jetEta_matched","Eta for jets matched to HSCPs (dR<0.1)",100,-5,5);
  TH1F* h_jetPhi_matched = new TH1F("h_jetPhi_matched","Phi for jets matched to HSCPs (dR<0.1)",100,-3.5,3.5);
  TH1F* h_jetMass_matched = new TH1F("h_jetMass_matched","Mass for jets matched to HSCPs (dR<0.1)",100,-20,1000);
  TH1F* h_jetEnergy_matched = new TH1F("h_jetEnergy_matched","Energy for jets matched to HSCPs (dR<0.1)",100,0,100000);
  TH1F* h_jetChargedEmEnergyFraction_matched = new TH1F("h_jetChargedEmEnergyFraction_matched","ChargedEmEnergyFraction for jets matched to HSCPs (dR<0.1)",100,0,1);
  TH1F* h_jetNeutralEmEnergyFraction_matched = new TH1F("h_jetNeutralEmEnergyFraction_matched","NeutralEmEnergyFraction for jets matched to HSCPs (dR<0.1)",100,0,1);
  TH1F* h_jetChargedHadronEnergyFraction_matched = new TH1F("h_jetChargedHadronEnergyFraction_matched","ChargedHadronEnergyFraction for jets matched to HSCPs (dR<0.1)",100,0,1);
  TH1F* h_jetNeutralHadronEnergyFraction_matched = new TH1F("h_jetNeutralHadronEnergyFraction_matched","NeutralHadronEnergyFraction for jets matched to HSCPs (dR<0.1)",100,0,1);
  TH1F* h_jetNeutralHadronEnergyFraction_matched_GenHSCPCharge0 = new TH1F("h_jetNeutralHadronEnergyFraction_matched_GenHSCPCharge0","NeutralHadronEnergyFraction for jets matched to HSCPs with charge 0 (dR<0.1)",100,0,1);
  TH1F* h_jetNeutralHadronEnergyFraction_matched_GenHSCPChargeNon0 = new TH1F("h_jetNeutralHadronEnergyFraction_matched_GenHSCPChargeNon0","NeutralHadronEnergyFraction for jets matched to HSCPs with charge > 0 (dR<0.1)",100,0,1);
  TH1F* h_jetChargedEnergyFraction_matched = new TH1F("h_jetChargedEnergyFraction_matched","ChargedEnergyFraction for jets matched to HSCPs (dR<0.1)",100,0,1);
  TH1F* h_jetNeutralEnergyFraction_matched = new TH1F("h_jetNeutralEnergyFraction_matched","NeutralEnergyFraction for jets matched to HSCPs (dR<0.1)",100,0,1); 
  TH1F* h_jetMuonEnergyFraction_matched = new TH1F("h_jetMuonEnergyFraction_matched","MuonEnergyFraction for jets matched to HSCPs (dR<0.1)",100,0,1);
  TH1F* h_jetMuonEnergyFraction_matched_GenHSCPCharge0 = new TH1F("h_jetMuonEnergyFraction_matched_GenHSCPCharge0","MuonEnergyFraction for jets matched to HSCPs with charge 0 (dR<0.1)",100,0,1);
  TH1F* h_jetMuonEnergyFraction_matched_GenHSCPCharge1 = new TH1F("h_jetMuonEnergyFraction_matched_GenHSCPCharge1","MuonEnergyFraction for jets matched to HSCPs with charge 1 (dR<0.1)",100,0,1);
  TH1F* h_jetMuonEnergyFraction_matched_GenHSCPCharge2 = new TH1F("h_jetMuonEnergyFraction_matched_GenHSCPCharge2","MuonEnergyFraction for jets matched to HSCPs with charge 2 (dR<0.1)",100,0,1);
 
  TH1I* h_jetChargedMultiplicity_matched = new TH1I("h_jetChargedMultiplicity_matched","ChargedMultiplicityfor jets matched to HSCPs (dR<0.1)",100,0,100);
  TH1I* h_jetNeutralMultiplicity_matched = new TH1I("h_jetNeutralMultiplicity_matched","NeutralMultiplicity for jets matched to HSCPs (dR<0.1)",100,0,100);
  TH1F* h_jetJetArea_matched = new TH1F("h_jetJetArea_matched","JetArea for jets matched to HSCPs (dR<0.1)",100,0,1);
  TH1F* h_jetPileupE_matched = new TH1F("h_jetPileupE_matched","PileupE for jets matched to HSCPs (dR<0.1)",100,0,1);

  //======================================
  // histograms needed for trig eff plots
  //======================================

  // no preselection criteria
  
  //"RPFM" short for Reco PF MET
  TH1F* h_RPFM_all = new TH1F("h_RPFM_all","RecoPFMET all;Reco PF MET [GeV];",150,0,3000);
  //"RCAM" short for Reco Calo MET
  TH1F* h_RCAM_all = new TH1F("h_RCAM_all","RecoCaloMET all;Reco Calo MET [GeV];",150,0,3000);
  TH1F* h_RPFM_passMuORMET1234 = new TH1F("h_RPFM_passMuORMET1234","RecoPFMET passing Muon or MET1234 triggers;Reco PF MET [GeV];",150,0,3000);
  TH1F* h_RCAM_passMuORMET1234 = new TH1F("h_RCAM_passMuORMET1234","RecoCaloMET passing Muon or MET1234 triggers;Reco Calo MET [GeV];",150,0,3000);
  TH1F* h_RPFM_passMET1234 = new TH1F("h_RPFM_passMET1234","RecoPFMET passing MET1234 triggers;Reco PF MET [GeV];",150,0,3000);
  TH1F* h_RCAM_passMET1234 = new TH1F("h_RCAM_passMET1234","RecoCaloMET passing MET1234 triggers;Reco Calo MET [GeV];",150,0,3000);
  TH1F* h_RPFM_passMu = new TH1F("h_RPFM_passMu","RecoPFMET passing Mu trigger;Reco PF MET [GeV];",150,0,3000);
  TH1F* h_RCAM_passMu = new TH1F("h_RCAM_passMu","RecoCaloMET passing Mu trigger;Reco Calo MET [GeV];",150,0,3000);

  //MET Trigger 1
  TH1F* h_RPFM_passMET1 = new TH1F("h_RPFM_passMET1","RecoPFMET passing MET1 trigger;Reco PF MET [GeV];",150,0,3000);
  TH1F* h_RCAM_passMET1 = new TH1F("h_RCAM_passMET1","RecoCaloMET passing MET1 trigger;Reco Calo MET [GeV];",150,0,3000);
  TH1F* h_RPFM_passMET1Cut1 = new TH1F("h_RPFM_passMET1Cut1","RecoPFMET passing Cut1 of MET1 trigger;Reco PF MET [GeV];",150,0,3000);
  TH1F* h_RCAM_passMET1Cut1 = new TH1F("h_RCAM_passMET1Cut1","RecoCaloMET passing Cut1 of MET1 trigger;Reco Calo MET [GeV];",150,0,3000);
  TH1F* h_RPFM_passMET1Cut2 = new TH1F("h_RPFM_passMET1Cut2","RecoPFMET passing Cut2 of MET1 trigger;Reco PF MET [GeV];",150,0,3000);
  TH1F* h_RCAM_passMET1Cut2 = new TH1F("h_RCAM_passMET1Cut2","RecoCaloMET passing Cut2 of MET1 trigger;Reco Calo MET [GeV];",150,0,3000);
  TH1F* h_RPFM_passMET1Cut3 = new TH1F("h_RPFM_passMET1Cut3","RecoPFMET passing Cut3 of MET1 trigger;Reco PF MET [GeV];",150,0,3000);
  TH1F* h_RCAM_passMET1Cut3 = new TH1F("h_RCAM_passMET1Cut3","RecoCaloMET passing Cut3 of MET1 trigger;Reco Calo MET [GeV];",150,0,3000);
  TH1F* h_RPFM_passMET1Cut4 = new TH1F("h_RPFM_passMET1Cut4","RecoPFMET passing Cut4 of MET1 trigger;Reco PF MET [GeV];",150,0,3000);
  TH1F* h_RCAM_passMET1Cut4 = new TH1F("h_RCAM_passMET1Cut4","RecoCaloMET passing Cut4 of MET1 trigger;Reco Calo MET [GeV];",150,0,3000);
  TH1F* h_RPFM_passMET1Cut5 = new TH1F("h_RPFM_passMET1Cut5","RecoPFMET passing Cut5 of MET1 trigger;Reco PF MET [GeV];",150,0,3000);
  TH1F* h_RCAM_passMET1Cut5 = new TH1F("h_RCAM_passMET1Cut5","RecoCaloMET passing Cut5 of MET1 trigger;Reco Calo MET [GeV];",150,0,3000);
  TH1F* h_RPFM_passMET1Cut6 = new TH1F("h_RPFM_passMET1Cut6","RecoPFMET passing Cut6 of MET1 trigger;Reco PF MET [GeV];",150,0,3000);
  TH1F* h_RCAM_passMET1Cut6 = new TH1F("h_RCAM_passMET1Cut6","RecoCaloMET passing Cut6 of MET1 trigger;Reco Calo MET [GeV];",150,0,3000);

  // passing preselection criteria

  //"LHFM" short for L1 MET HF
  TH1F* h_LHFM_passPres_all = new TH1F("h_LHFM_passPres_all","L1 MET HF passing preselection all;L1 MET HF [GeV];",150,0,3000);
  //"RPFM" short for Reco PF MET
  TH1F* h_RPFM_passPres_all = new TH1F("h_RPFM_passPres_all","RecoPFMET passing preselection all;Reco PF MET [GeV];",150,0,50000);
  TH1F* h_RPFM_passPres_zoomed = new TH1F("h_RPFM_passPres_zoomed","RecoPFMET passing preselection <3000 GeV;Reco PF MET [GeV];",150,0,3000);
  //"RCAM" short for Reco Calo MET
  TH1F* h_RCAM_passPres_all = new TH1F("h_RCAM_passPres_all","RecoCaloMET passing preselection all;Reco Calo MET [GeV];",150,0,50000);
  TH1F* h_RCAM_passPres_zoomed = new TH1F("h_RCAM_passPres_zoomed","RecoCaloMET passing preselection zoomed;Reco Calo MET [GeV];",150,0,3000);
  //2D plots comparing distributions
  TH2F* h_RPFM_LHFM_passPres = new TH2F("h_RPFM_LHFM_passPres","L1 MET HF vs RecoPFMET passing preselection;RecoPFMET [GeV];L1 MET HF [GeV]",150,0,3000,150,0,3000);
  TH2F* h_RCAM_LHFM_passPres = new TH2F("h_RCAM_LHFM_passPres","L1 MET HF vs RecoCaloMET passing preselection;RecoCaloMET [GeV];L1 MET HF [GeV]",150,0,3000,150,0,3000);
  TH2F* h_RPFM_RCAM_passPres = new TH2F("h_RPFM_RCAM_passPres","RecoCaloMET vs RecoPFMET passing preselection;RecoPFMET [GeV];RecoCaloMET [GeV]",150,0,3000,150,0,3000);

  //histograms needed for trig eff plots

  const Int_t NBINS = 20;
  Double_t edges[NBINS + 1] = {0.0,50.0,100.0,150.0,200.0,250.0,300.0,350.0,400.0,500.0,600.0,700.0,800.0,1000.0,1200.0,1400.0,1600.0,1800.0,2000.0,2500.0,3000.0};

  TH1F* h_RPFM_passPres_noMU = new TH1F("h_RPFM_passPres_noMU","RecoPFMET passing preselection, !MuTrig;Reco PF MET [GeV];RecoPFMET [GeV]",NBINS,edges);
  TH1F* h_RCAM_passPres_noMU = new TH1F("h_RCAM_passPres_noMU","RecoCaloMET passing preselection, !MuTrig;Reco Calo MET [GeV];RecoCaloMET [GeV]",NBINS,edges);
  TH1F* h_RPFM_passPres_noMU_passMET1234 = new TH1F("h_RPFM_passPres_noMU_passMET1234","RecoPFMET passing preselection, !MuTrig, MET1234 trigs;Reco PF MET [GeV]",NBINS,edges);
  TH1F* h_RCAM_passPres_noMU_passMET1234 = new TH1F("h_RCAM_passPres_noMU_passMET1234","RecoCaloMET passing preselection, !MuTrig, MET1234 trigs;Reco Calo MET [GeV]",NBINS,edges);
  TH1F* h_RPFM_passPres_noMU_passMET1 = new TH1F("h_RPFM_passPres_noMU_passMET1","RecoPFMET passing preselection, !MuTrig, MET1 trig;Reco PF MET [GeV]",NBINS,edges);
  TH1F* h_RCAM_passPres_noMU_passMET1 = new TH1F("h_RCAM_passPres_noMU_passMET1","RecoCaloMET passing preselection, !MuTrig, MET1 trig;Reco Calo MET [GeV]",NBINS,edges);
  TH1F* h_RPFM_passPres_noMU_passMET1Cut1 = new TH1F("h_RPFM_passPres_noMU_passMET1Cut1","RecoPFMET passing preselection, !MuTrig, Cut1 of MET1 trig;Reco PF MET [GeV]",NBINS,edges);
  TH1F* h_RCAM_passPres_noMU_passMET1Cut1 = new TH1F("h_RCAM_passPres_noMU_passMET1Cut1","RecoCaloMET passing preselection, !MuTrig, Cut1 of MET1 trig;Reco Calo MET [GeV]",NBINS,edges);
  TH1F* h_RPFM_passPres_noMU_passMET1Cut2 = new TH1F("h_RPFM_passPres_noMU_passMET1Cut2","RecoPFMET passing preselection, !MuTrig, Cut2 of MET1 trig;Reco PF MET [GeV]",NBINS,edges);
  TH1F* h_RCAM_passPres_noMU_passMET1Cut2 = new TH1F("h_RCAM_passPres_noMU_passMET1Cut2","RecoCaloMET passing preselection, !MuTrig, Cut2 of MET1 trig;Reco Calo MET [GeV]",NBINS,edges);
  TH1F* h_RPFM_passPres_noMU_passMET1Cut3 = new TH1F("h_RPFM_passPres_noMU_passMET1Cut3","RecoPFMET passing preselection, !MuTrig, Cut3 of MET1 trig;Reco PF MET [GeV]",NBINS,edges);
  TH1F* h_RCAM_passPres_noMU_passMET1Cut3 = new TH1F("h_RCAM_passPres_noMU_passMET1Cut3","RecoCaloMET passing preselection, !MuTrig, Cut3 of MET1 trig;Reco Calo MET [GeV]",NBINS,edges);
  TH1F* h_RPFM_passPres_noMU_passMET1Cut4 = new TH1F("h_RPFM_passPres_noMU_passMET1Cut4","RecoPFMET passing preselection, !MuTrig, Cut4 of MET1 trig;Reco PF MET [GeV]",NBINS,edges);
  TH1F* h_RCAM_passPres_noMU_passMET1Cut4 = new TH1F("h_RCAM_passPres_noMU_passMET1Cut4","RecoCaloMET passing preselection, !MuTrig, Cut4 of MET1 trig;Reco Calo MET [GeV]",NBINS,edges);
  TH1F* h_RPFM_passPres_noMU_passMET1Cut5 = new TH1F("h_RPFM_passPres_noMU_passMET1Cut5","RecoPFMET passing preselection, !MuTrig, Cut5 of MET1 trig;Reco PF MET [GeV]",NBINS,edges);
  TH1F* h_RCAM_passPres_noMU_passMET1Cut5 = new TH1F("h_RCAM_passPres_noMU_passMET1Cut5","RecoCaloMET passing preselection, !MuTrig, Cut5 of MET1 trig;Reco Calo MET [GeV]",NBINS,edges);
  TH1F* h_RPFM_passPres_noMU_passMET1Cut6 = new TH1F("h_RPFM_passPres_noMU_passMET1Cut6","RecoPFMET passing preselection, !MuTrig, Cut6 of MET1 trig;Reco PF MET [GeV]",NBINS,edges);
  TH1F* h_RCAM_passPres_noMU_passMET1Cut6 = new TH1F("h_RCAM_passPres_noMU_passMET1Cut6","RecoCaloMET passing preselection, !MuTrig, Cut6 of MET1 trig;Reco Calo MET [GeV]",NBINS,edges);

  TH1F* h_RCAM_passPres_noMU_cat1_beforeMETFilters = new TH1F("h_RCAM_passPres_noMU_cat1_beforeMETFilters","RecoCaloMET passing preselection, !MuTrig, cat 1, before MET filters",NBINS,edges);
  TH1F* h_RCAM_passPres_noMU_cat1_beforeMETFilters_passMET1 = new TH1F("h_RCAM_passPres_noMU_cat1_beforeMETFilters_passMET1","RecoCaloMET passing preselection, !MuTrig, cat 1, before MET filters, passing MET trigger 1",NBINS,edges);
  TH1F* h_RCAM_passPres_noMU_cat1_beforeMETFilters_passMET1234 = new TH1F("h_RCAM_passPres_noMU_cat1_beforeMETFilters_passMET1234","RecoCaloMET passing preselection, !MuTrig, cat 1, before MET filters, passing MET trigger 1234",NBINS,edges);
  TH1F* h_RCAM_passPres_noMU_cat2_beforeMETFilters = new TH1F("h_RCAM_passPres_noMU_cat2_beforeMETFilters","RecoCaloMET passing preselection, !MuTrig, cat 2, before MET filters",NBINS,edges);
  TH1F* h_RCAM_passPres_noMU_cat2_beforeMETFilters_passMET1  = new TH1F("h_RCAM_passPres_noMU_cat2_beforeMETFilters_passMET1","RecoCaloMET passing preselection, !MuTrig, cat 2, before MET filters, passing MET trigger 1",NBINS,edges);
  TH1F* h_RCAM_passPres_noMU_cat2_beforeMETFilters_passMET1234  = new TH1F("h_RCAM_passPres_noMU_cat2_beforeMETFilters_passMET1234","RecoCaloMET passing preselection, !MuTrig, cat 2, before MET filters, passing MET trigger 1234",NBINS,edges);
  TH1F* h_RCAM_passPres_noMU_cat1_afterMETFilters  = new TH1F("h_RCAM_passPres_noMU_cat1_afterMETFilters","RecoCaloMET passing preselection, !MuTrig, cat 1, after MET filters",NBINS,edges);
  TH1F* h_RCAM_passPres_noMU_cat1_afterMETFilters_passMET1 = new TH1F("h_RCAM_passPres_noMU_cat1_afterMETFilters_passMET1","RecoCaloMET passing preselection, !MuTrig, cat 1, after MET filters, passing MET trigger 1",NBINS,edges);
  TH1F* h_RCAM_passPres_noMU_cat1_afterMETFilters_passMET1234 = new TH1F("h_RCAM_passPres_noMU_cat1_afterMETFilters_passMET1234","RecoCaloMET passing preselection, !MuTrig, cat 1, after MET filters, passing MET trigger 1234",NBINS,edges);
  TH1F* h_RCAM_passPres_noMU_cat2_afterMETFilters = new TH1F("h_RCAM_passPres_noMU_cat2_afterMETFilters","RecoCaloMET passing preselection, !MuTrig, cat 2, after MET filters",NBINS,edges);
  TH1F* h_RCAM_passPres_noMU_cat2_afterMETFilters_passMET1 = new TH1F("h_RCAM_passPres_noMU_cat2_afterMETFilters_passMET1","RecoCaloMET passing preselection, !MuTrig, cat 2, after MET filters, passing MET trigger 1",NBINS,edges);
  TH1F* h_RCAM_passPres_noMU_cat2_afterMETFilters_passMET1234 = new TH1F("h_RCAM_passPres_noMU_cat2_afterMETFilters_passMET1234","RecoCaloMET passing preselection, !MuTrig, cat 2, after MET filters, passing MET trigger 1234",NBINS,edges);
  TH1F* h_RCAM_passPres_noMU_beforeMETFilters = new TH1F("h_RCAM_passPres_noMU_beforeMETFilters","RecoCaloMET passing preselection, !MuTrig, before MET filters",NBINS,edges);
  TH1F* h_RCAM_passPres_noMU_beforeMETFilters_passMET1234 = new TH1F("h_RCAM_passPres_noMU_beforeMETFilters_passMET1234","RecoCaloMET passing preselection, !MuTrig, before MET filters, passing MET trigers 1234",NBINS,edges);
  TH1F* h_RCAM_passPres_noMU_afterMETFilters = new TH1F("h_RCAM_passPres_noMU_afterMETFilters","RecoCaloMET passing preselection, !MuTrig, after MET filters",NBINS,edges);
  TH1F* h_RCAM_passPres_noMU_afterMETFilters_passMET1234 = new TH1F("h_RCAM_passPres_noMU_afterMETFilters_passMET1234","RecoCaloMET passing preselection, !MuTrig, after MET filters, passing MET trigers 1234",NBINS,edges);
  TH1F* h_RCAM_passPres_noMU_afterMETFilters_quality = new TH1F("h_RCAM_passPres_noMU_afterMETFilters_quality","RecoCaloMET passing preselection, !MuTrig, after MET filters, quality cut",NBINS,edges);
  TH1F* h_RCAM_passPres_noMU_afterMETFilters_quality_passMET1234 = new TH1F("h_RCAM_passPres_noMU_afterMETFilters_quality_passMET1234","RecoCaloMET passing preselection, !MuTrig, after MET filters, quality cut, passing MET trigers 1234",NBINS,edges);

  const Int_t NBINS2 = 22;
  Double_t edges2[NBINS2 + 1] = {0.0,50.0,100.0,150.0,200.0,250.0,300.0,350.0,400.0,500.0,600.0,700.0,800.0,1000.0,1200.0,1400.0,1600.0,1800.0,2000.0,2500.0,3000.0,15000.0,30000.0};

  TH1F* h_RCAM_passPres_noMU_cat1_beforeMETFilters_full = new TH1F("h_RCAM_passPres_noMU_cat1_beforeMETFilters_full","RecoCaloMET passing preselection, !MuTrig, cat 1, before MET filters",NBINS2,edges2);
  TH1F* h_RCAM_passPres_noMU_cat1_beforeMETFilters_passMET1_full = new TH1F("h_RCAM_passPres_noMU_cat1_beforeMETFilters_passMET1_full","RecoCaloMET passing preselection, !MuTrig, cat 1, before MET filters, passing MET trigger 1",NBINS2,edges2);
  TH1F* h_RCAM_passPres_noMU_cat1_beforeMETFilters_passMET1234_full = new TH1F("h_RCAM_passPres_noMU_cat1_beforeMETFilters_passMET1234_full","RecoCaloMET passing preselection, !MuTrig, cat 1, before MET filters, passing MET trigger 1234",NBINS2,edges2);
  TH1F* h_RCAM_passPres_noMU_cat1_afterMETFilters_full  = new TH1F("h_RCAM_passPres_noMU_cat1_afterMETFilters_full","RecoCaloMET passing preselection, !MuTrig, cat 1, after MET filters",NBINS2,edges2);
  TH1F* h_RCAM_passPres_noMU_cat1_afterMETFilters_passMET1_full = new TH1F("h_RCAM_passPres_noMU_cat1_afterMETFilters_passMET1_full","RecoCaloMET passing preselection, !MuTrig, cat 1, after MET filters, passing MET trigger 1",NBINS2,edges2);
  TH1F* h_RCAM_passPres_noMU_cat1_afterMETFilters_passMET1234_full = new TH1F("h_RCAM_passPres_noMU_cat1_afterMETFilters_passMET1234_full","RecoCaloMET passing preselection, !MuTrig, cat 1, after MET filters, passing MET trigger 1234",NBINS2,edges2);
  TH1F* h_RCAM_passPres_noMU_beforeMETFilters_full = new TH1F("h_RCAM_passPres_noMU_beforeMETFilters_full","RecoCaloMET passing preselection, !MuTrig, before MET filters",NBINS2,edges2);
  TH1F* h_RCAM_passPres_noMU_beforeMETFilters_passMET1234_full = new TH1F("h_RCAM_passPres_noMU_beforeMETFilters_passMET1234_full","RecoCaloMET passing preselection, !MuTrig, before MET filters, passing MET trigers 1234",NBINS2,edges2);
  TH1F* h_RCAM_passPres_noMU_afterMETFilters_full = new TH1F("h_RCAM_passPres_noMU_afterMETFilters_full","RecoCaloMET passing preselection, !MuTrig, after MET filters",NBINS2,edges2);
  TH1F* h_RCAM_passPres_noMU_afterMETFilters_passMET1234_full = new TH1F("h_RCAM_passPres_noMU_afterMETFilters_passMET1234_full","RecoCaloMET passing preselection, !MuTrig, after MET filters, passing MET trigers 1234",NBINS2,edges2);
  TH1F* h_RCAM_passPres_noMU_afterMETFilters_quality_full = new TH1F("h_RCAM_passPres_noMU_afterMETFilters_quality_full","RecoCaloMET passing preselection, !MuTrig, after MET filters, quality cut",NBINS2,edges2);
  TH1F* h_RCAM_passPres_noMU_afterMETFilters_quality_passMET1234_full = new TH1F("h_RCAM_passPres_noMU_afterMETFilters_quality_passMET1234_full","RecoCaloMET passing preselection, !MuTrig, after MET filters, quality cut, passing MET trigers 1234",NBINS2,edges2);

  const Int_t NBINS3 = 15;
  Double_t edges3[NBINS3 + 1] = {0.0,50.0,100.0,150.0,200.0,250.0,300.0,350.0,400.0,500.0,600.0,700.0,800.0,1000.0,2500.0,5000.0};

  TH1F* h_RCAM_passPres_noMU_afterMETFilters_quality_noSat = new TH1F("h_RCAM_passPres_noMU_afterMETFilters_quality_noSat","RecoCaloMET passing preselection, !MuTrig, after MET filters, quality cut, no saturation",NBINS3,edges3);
  TH1F* h_RCAM_passPres_noMU_afterMETFilters_quality_noSat_passMET1234 = new TH1F("h_RCAM_passPres_noMU_afterMETFilters_quality_noSat_passMET1234","RecoCaloMET passing preselection, !MuTrig, after MET filters, quality cut, no saturation, passing MET trigers 1234",NBINS3,edges3);

  //====================================================
  // histograms needed for numb of events in categories
  //====================================================

  TH1F* h_numEventsCategories_noPres = new TH1F("h_numEventsCategories_noPres","",25,0,25);
  TH1F* h_numEventsCategories_passPres = new TH1F("h_numEventsCategories_passPres","",25,0,25);

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
    tree->n_pv = npv;

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
      tree->L1MET = L1MET;
      tree->L1MET_phi = L1MET_phi;
      tree->L1METHF = L1METHF;
      tree->L1METHF_phi = L1METHF_phi;
      tree->L1MHT = L1MHT;
      tree->L1MHT_phi = L1MHT_phi;
      tree->L1ETSum = L1ETSum;
      tree->L1HTSum = L1HTSum;
      tree->Flag_globalSuperTightHalo2016Filter = Flag_globalSuperTightHalo2016Filter;
      tree->Flag_HBHENoiseFilter = Flag_HBHENoiseFilter;
      tree->Flag_HBHENoiseIsoFilter = Flag_HBHENoiseIsoFilter;
      tree->Flag_EcalDeadCellTriggerPrimitiveFilter = Flag_EcalDeadCellTriggerPrimitiveFilter;
      tree->Flag_BadPFMuonFilter = Flag_BadPFMuonFilter;
      tree->Flag_BadPFMuonDzFilter = Flag_BadPFMuonDzFilter;
      tree->Flag_hfNoisyHitsFilter = Flag_hfNoisyHitsFilter;
      tree->Flag_eeBadScFilter = Flag_eeBadScFilter;
      tree->Flag_ecalBadCalibFilter = Flag_ecalBadCalibFilter;
      tree->Flag_allMETFilters = Flag_allMETFilters;


      tree->passPreselection = passPreselection;



    //***************************************************************
    //Start Object Selection
    //***************************************************************

    //HSCP stuff -- preselections

      tree->nHSCP = 0;
      bool bool_CandPassPres = false;
      int total_NCandPassPres_0 = 0;
      int total_NCandPassPres_1 = 0;
      int total_NCandPassPres_2 = 0;
      int total_NCandPassPres_3 = 0;
      int total_NCandPassPres_4 = 0;
      int total_NCandPassPres_5 = 0;
      int total_NCandPassPres_6 = 0;
      int total_NCandPassPres_7 = 0;
      int total_NCandPassPres_8 = 0;
      int total_NCandPassPres_9 = 0;
      int total_NCandPassPres_10 = 0;
      int total_NCandPassPres_11 = 0;
      int total_NCandPassPres_12 = 0;
      int total_NCandPassPres_13 = 0;
      int total_NCandPassPres_14 = 0;
      int total_NCandPassPres_all = 0;
      int index_PassPres[3] = {-1,-1,-1};

      for(unsigned int i = 0; i < Pt->size(); i++) {
	
	tree->HSCP_charge[tree->nHSCP] = Charge->at(i);
	tree->HSCP_pt[tree->nHSCP] = Pt->at(i);
	tree->HSCP_eta[tree->nHSCP] = eta->at(i);
	tree->HSCP_phi[tree->nHSCP] = phi->at(i);
	tree->HSCP_nPixelHit[tree->nHSCP] = NOPH->at(i);
	tree->HSCP_nHits[tree->nHSCP] = NOM->at(i);
	tree->HSCP_isHighPurity[tree->nHSCP] = isHighPurity->at(i);
	//	if(tree->HSCP_isHighPurity[tree->nHSCP] > 1) {
	//  std::cout << "=====" << std::endl;
	//  std::cout << "left side: " << tree->HSCP_isHighPurity[tree->nHSCP] << std::endl;
	//  std::cout << "right side: " << isHighPurity->at(i) << std::endl;
	//} if(isHighPurity->at(i) > 1) {
	//  std::cout << "=====" << std::endl;
	//  std::cout << "left side: " << tree->HSCP_isHighPurity[tree->nHSCP] << std::endl;
	//  std::cout << "right side: " << isHighPurity->at(i) << std::endl;
	//}
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

	/* //causing a crash for some reason, are these not in the files? check later
	tree->HSCP_isPFMuon[tree->nHSCP] = isPFMuon->at(i);
	tree->HSCP_isMuon[tree->nHSCP] = isMuon->at(i);
	tree->HSCP_isPhoton[tree->nHSCP] = isPhoton->at(i);
	tree->HSCP_isElectron[tree->nHSCP] = isElectron->at(i);
	tree->HSCP_isChHadron[tree->nHSCP] = isChHadron->at(i);
	tree->HSCP_isNeutHadron[tree->nHSCP] = isNeutHadron->at(i);
	tree->HSCP_isPfTrack[tree->nHSCP] = isPfTrack->at(i);
	tree->HSCP_isUndefined[tree->nHSCP] = isUndefined->at(i);
	*/
	tree->HSCP_ECAL_energy[tree->nHSCP] = ECAL_energy->at(i);
	tree->HSCP_HCAL_energy[tree->nHSCP] = HCAL_energy->at(i);
	tree->HSCP_TOF[tree->nHSCP] = TOF->at(i);
 

	// explicitly defining preselections
	h_preselection_cutflow_candidates->Fill(0.5);
	total_NCandPassPres_0++;
	if (Pt->at(i) > 55) {
	  h_preselection_cutflow_candidates->Fill(1.5);
	  total_NCandPassPres_1++;
	  if(eta->at(i) < 2.1 && eta->at(i) > -2.1) {
	    h_preselection_cutflow_candidates->Fill(2.5);
	    total_NCandPassPres_2++;
	    if(NOPH->at(i) >= 2) {
	      h_preselection_cutflow_candidates->Fill(3.5);
	      total_NCandPassPres_3++;
	      if(FOVH->at(i) > 0.8) {
		h_preselection_cutflow_candidates->Fill(4.5);
		total_NCandPassPres_4++;
		if(NOM->at(i) >= 10) {
		  h_preselection_cutflow_candidates->Fill(5.5);
		  total_NCandPassPres_5++;
		  if(isHighPurity->at(i) == true) {
		    h_preselection_cutflow_candidates->Fill(6.5);
		    total_NCandPassPres_6++;
		    if(Chi2->at(i)/Ndof->at(i) < 5) {
		      h_preselection_cutflow_candidates->Fill(7.5);
		      total_NCandPassPres_7++;
		      if(dZ->at(i) < 0.1) {
			h_preselection_cutflow_candidates->Fill(8.5);
			total_NCandPassPres_8++;
			if(dXY->at(i) < 0.02) {
			  h_preselection_cutflow_candidates->Fill(9.5);
			  total_NCandPassPres_9++;
			  if(PFMiniIso_relative->at(i) < 0.02) {
			    h_preselection_cutflow_candidates->Fill(10.5);
			    total_NCandPassPres_10++;
			    if(EoverP->at(i) < 0.3) {
			      h_preselection_cutflow_candidates->Fill(11.5);
			      total_NCandPassPres_11++;
			      if(track_genTrackMiniIsoSumPt->at(i) < 15) {
				h_preselection_cutflow_candidates->Fill(12.5);
				total_NCandPassPres_12++;
				if(PtErr->at(i)/(Pt->at(i)*Pt->at(i)) < 0.0008) {
				  h_preselection_cutflow_candidates->Fill(13.5);
				  total_NCandPassPres_13++;
				  if((1 - ProbQ_noL1->at(i)) > 0.3) {
				    h_preselection_cutflow_candidates->Fill(14.5);
				    bool_CandPassPres = true;
				    tree->HSCP_passPres[tree->nHSCP] = bool_CandPassPres;
				    total_NCandPassPres_14++;
				    total_NCandPassPres_all++;
				    //this saves which index candidate passes preselection
				    index_PassPres[total_NCandPassPres_all-1] = i;
				    //std::cout << "i: " << i << " ";

				  }
				}
			      }
			    }
			  }
			}
		      }
		    }
		  }
		}
	      }
	    } 
	  }
	}

	if ( !(Pt->at(i) > 55 && eta->at(i) < 2.1 && eta->at(i) > -2.1 && NOPH->at(i) >= 2 && FOVH->at(i) > 0.8 && NOM->at(i) >= 10 && isHighPurity->at(i) == true && Chi2->at(i)/Ndof->at(i) < 5 && dZ->at(i) < 0.1 && dXY->at(i) < 0.02 && PFMiniIso_relative->at(i) < 0.02 && EoverP->at(i) < 0.3 && track_genTrackMiniIsoSumPt->at(i) < 15 && PtErr->at(i)/(Pt->at(i)*Pt->at(i)) < 0.0008 && (1 - ProbQ_noL1->at(i)) > 0.3) ) {

	  bool_CandPassPres = false;
	  tree->HSCP_passPres[tree->nHSCP] = bool_CandPassPres; 

	}

	//std::cout << tree->nHSCP << std::endl; 
	//this line used to cause a crash
	tree->nHSCP++;

      }

      //std::cout << " " << std::endl;

      tree->NCandPassPres_0 = total_NCandPassPres_0;
      tree->NCandPassPres_1 = total_NCandPassPres_1;
      tree->NCandPassPres_2 = total_NCandPassPres_2;
      tree->NCandPassPres_3 = total_NCandPassPres_3;
      tree->NCandPassPres_4 = total_NCandPassPres_4;
      tree->NCandPassPres_5 = total_NCandPassPres_5;
      tree->NCandPassPres_6 = total_NCandPassPres_6;
      tree->NCandPassPres_7 = total_NCandPassPres_7;
      tree->NCandPassPres_8 = total_NCandPassPres_8;
      tree->NCandPassPres_9 = total_NCandPassPres_9;
      tree->NCandPassPres_10 = total_NCandPassPres_10;
      tree->NCandPassPres_11 = total_NCandPassPres_11;
      tree->NCandPassPres_12 = total_NCandPassPres_12;
      tree->NCandPassPres_13 = total_NCandPassPres_13;
      tree->NCandPassPres_14 = total_NCandPassPres_14;
      tree->NCandPassPres_all = total_NCandPassPres_all;

      if(total_NCandPassPres_0 > 0) h_preselection_cutflow_events_1cand->Fill(0.5);
      if(total_NCandPassPres_1 > 0) h_preselection_cutflow_events_1cand->Fill(1.5);
      if(total_NCandPassPres_2 > 0) h_preselection_cutflow_events_1cand->Fill(2.5);
      if(total_NCandPassPres_3 > 0) h_preselection_cutflow_events_1cand->Fill(3.5);
      if(total_NCandPassPres_4 > 0) h_preselection_cutflow_events_1cand->Fill(4.5);
      if(total_NCandPassPres_5 > 0) h_preselection_cutflow_events_1cand->Fill(5.5);
      if(total_NCandPassPres_6 > 0) h_preselection_cutflow_events_1cand->Fill(6.5);
      if(total_NCandPassPres_7 > 0) h_preselection_cutflow_events_1cand->Fill(7.5);
      if(total_NCandPassPres_8 > 0) h_preselection_cutflow_events_1cand->Fill(8.5);
      if(total_NCandPassPres_9 > 0) h_preselection_cutflow_events_1cand->Fill(9.5);
      if(total_NCandPassPres_10 > 0) h_preselection_cutflow_events_1cand->Fill(10.5);
      if(total_NCandPassPres_11 > 0) h_preselection_cutflow_events_1cand->Fill(11.5);
      if(total_NCandPassPres_12 > 0) h_preselection_cutflow_events_1cand->Fill(12.5);
      if(total_NCandPassPres_13 > 0) h_preselection_cutflow_events_1cand->Fill(13.5);
      if(total_NCandPassPres_14 > 0) h_preselection_cutflow_events_1cand->Fill(14.5);

      if(total_NCandPassPres_0 > 1) h_preselection_cutflow_events_2cand->Fill(0.5);
      if(total_NCandPassPres_1 > 1) h_preselection_cutflow_events_2cand->Fill(1.5);
      if(total_NCandPassPres_2 > 1) h_preselection_cutflow_events_2cand->Fill(2.5);
      if(total_NCandPassPres_3 > 1) h_preselection_cutflow_events_2cand->Fill(3.5);
      if(total_NCandPassPres_4 > 1) h_preselection_cutflow_events_2cand->Fill(4.5);
      if(total_NCandPassPres_5 > 1) h_preselection_cutflow_events_2cand->Fill(5.5);
      if(total_NCandPassPres_6 > 1) h_preselection_cutflow_events_2cand->Fill(6.5);
      if(total_NCandPassPres_7 > 1) h_preselection_cutflow_events_2cand->Fill(7.5);
      if(total_NCandPassPres_8 > 1) h_preselection_cutflow_events_2cand->Fill(8.5);
      if(total_NCandPassPres_9 > 1) h_preselection_cutflow_events_2cand->Fill(9.5);
      if(total_NCandPassPres_10 > 1) h_preselection_cutflow_events_2cand->Fill(10.5);
      if(total_NCandPassPres_11 > 1) h_preselection_cutflow_events_2cand->Fill(11.5);
      if(total_NCandPassPres_12 > 1) h_preselection_cutflow_events_2cand->Fill(12.5);
      if(total_NCandPassPres_13 > 1) h_preselection_cutflow_events_2cand->Fill(13.5);
      if(total_NCandPassPres_14 > 1) h_preselection_cutflow_events_2cand->Fill(14.5);

      // jets
      tree->nJets = 0;
      float total_HT_value = 0;
      float total_HT_value_passJetID = 0;
      bool bool_passJetID = false;

      for(unsigned int i = 0; i < Jet_pt->size(); i++) {	
	tree->Jets_pt[tree->nJets]  = Jet_pt->at(i);
	total_HT_value = total_HT_value + Jet_pt->at(i);
	tree->Jets_eta[tree->nJets] = Jet_eta->at(i);
	tree->Jets_phi[tree->nJets] = Jet_phi->at(i);
	tree->Jets_mass[tree->nJets] = Jet_mass->at(i);
	tree->Jets_energy[tree->nJets] = Jet_energy->at(i);
	tree->Jets_chargedEmEnergyFraction[tree->nJets] = Jet_chargedEmEnergyFraction->at(i);
	tree->Jets_neutralEmEnergyFraction[tree->nJets] = Jet_neutralEmEnergyFraction->at(i);
	tree->Jets_chargedHadronEnergyFraction[tree->nJets] = Jet_chargedHadronEnergyFraction->at(i);
	tree->Jets_neutralHadronEnergyFraction[tree->nJets] = Jet_neutralHadronEnergyFraction->at(i);
	tree->Jets_muonEnergyFraction[tree->nJets] = Jet_muonEnergyFraction->at(i);
	tree->Jets_chargedMultiplicity[tree->nJets] = Jet_chargedMultiplicity->at(i);
	tree->Jets_neutralMultiplicity[tree->nJets] = Jet_neutralMultiplicity->at(i);
	tree->Jets_jetArea[tree->nJets] = Jet_jetArea->at(i);
	tree->Jets_pileupE[tree->nJets] = Jet_pileupE->at(i);

	if(
	   fabs(Jet_eta->at(i)) < 2.4 &&
	   Jet_neutralHadronEnergyFraction->at(i) < 0.9 &&
	   Jet_neutralEmEnergyFraction->at(i) < 0.9 &&
	   Jet_chargedHadronEnergyFraction->at(i) > 0 &&
	   Jet_chargedEmEnergyFraction->at(i) < 0.8 &&
	   Jet_muonEnergyFraction->at(i) < 0.8 &&
	   Jet_chargedMultiplicity->at(i) > 0 &&
	   (Jet_chargedMultiplicity->at(i) + Jet_neutralMultiplicity->at(i)) > 1 
	   ){
	  bool_passJetID = true;
	  total_HT_value_passJetID = total_HT_value_passJetID + Jet_pt->at(i);
	} if(
	     fabs(Jet_eta->at(i)) > 2.4 &&
	     fabs(Jet_eta->at(i)) <= 2.7 &&
	     Jet_neutralHadronEnergyFraction->at(i) < 0.9 &&
	     Jet_neutralEmEnergyFraction->at(i) < 0.99
	     ){
	  bool_passJetID = true;
	  total_HT_value_passJetID = total_HT_value_passJetID + Jet_pt->at(i);
	} if(
	     fabs(Jet_eta->at(i)) > 2.7 &&
	     fabs(Jet_eta->at(i)) <= 3.0 &&
	     Jet_neutralHadronEnergyFraction->at(i) < 0.9 &&
	     Jet_neutralEmEnergyFraction->at(i) > 0 &&
	     Jet_neutralEmEnergyFraction->at(i) < 0.99 &&
	     Jet_neutralMultiplicity->at(i) > 1
	     ){
	  bool_passJetID = true;
	  total_HT_value_passJetID = total_HT_value_passJetID + Jet_pt->at(i);
	} if(
	     fabs(Jet_eta->at(i)) > 3.0 &&
	     fabs(Jet_eta->at(i)) <= 5.0 &&
	     Jet_neutralHadronEnergyFraction->at(i) > 0.2 &&
	     Jet_neutralEmEnergyFraction->at(i) < 0.9 &&
	     Jet_neutralMultiplicity->at(i) > 10
	     ){
	  bool_passJetID = true;
	  total_HT_value_passJetID = total_HT_value_passJetID + Jet_pt->at(i);
	}

	tree->Jets_passJetID[tree->nJets] = bool_passJetID;
	tree->nJets++;
      }

      tree->total_HT = total_HT_value;
      tree->total_HT_passJetID = total_HT_value_passJetID;

      // gParticles
      tree->ngParticles = 0;
      int total_NFinalState1 = 0;
      int index_FinalState1[10000] = {-1}; //next time vector of ints
      for(unsigned int i = 0; i < gParticlePt->size(); i++) {
	tree->gParticles_Id[tree->ngParticles] = gParticleId->at(i);
	tree->gParticles_Status[tree->ngParticles] = gParticleStatus->at(i);
	tree->gParticles_E[tree->ngParticles] = gParticleE->at(i);
	tree->gParticles_Pt[tree->ngParticles] = gParticlePt->at(i);
	tree->gParticles_Pz[tree->ngParticles] = gParticlePz->at(i);
	tree->gParticles_Eta[tree->ngParticles] = gParticleEta->at(i);
	tree->gParticles_Phi[tree->ngParticles] = gParticlePhi->at(i);
	tree->gParticles_Beta[tree->ngParticles] = gParticleBeta->at(i);
	tree->gParticles_MotherId[tree->ngParticles] = gParticleMotherId->at(i);
	//tree->gParticles_Charge[tree->ngParticles] = gParticleCharge->at(i);

	float HSCP_charge_ = -10;

	if(gParticleId->at(i) == -1092224) {
	  HSCP_charge_ = -2;
	} else if(
	     gParticleId->at(i) == 1093334 ||
	     gParticleId->at(i) == 1093314 ||
	     gParticleId->at(i) == 1093114 ||
	     gParticleId->at(i) == 1091114 ||
	     gParticleId->at(i) == -1009213 ||
	     gParticleId->at(i) == -1009323 ||
	     gParticleId->at(i) == -1092214 ||
	     gParticleId->at(i) == -1093224
		  ) {
	  HSCP_charge_ = -1;
	} else if(
	     gParticleId->at(i) == 1093324 ||
	     gParticleId->at(i) == 1093214 ||
	     gParticleId->at(i) == 1092114 ||
	     gParticleId->at(i) == 1009333 ||
	     gParticleId->at(i) == 1009313 ||
	     gParticleId->at(i) == 1009223 ||
	     gParticleId->at(i) == 1009113 ||
	     gParticleId->at(i) == 1000993 ||
	     gParticleId->at(i) == -1009313 ||
	     gParticleId->at(i) == -1092114 ||
	     gParticleId->at(i) == -1093214 ||
	     gParticleId->at(i) == -1093324
		  ) {
	  HSCP_charge_ = 0;
	} else if(
	     gParticleId->at(i) == 1093224 ||
	     gParticleId->at(i) == 1092214 ||
	     gParticleId->at(i) == 1009323 ||
	     gParticleId->at(i) == 1009213 ||
	     gParticleId->at(i) == -1091114 ||
	     gParticleId->at(i) == -1093114 ||
	     gParticleId->at(i) == -1093314
		  ){
	  HSCP_charge_ = 1;
	} else if(
	     gParticleId->at(i) == 1092224
		  ){
	  HSCP_charge_ = 2;
	} else {
	  HSCP_charge_ = gParticleCharge->at(i);
	}
	tree->gParticles_Charge[tree->ngParticles] = HSCP_charge_;
	
	if(gParticleStatus->at(i) == 1) {
	  if(total_NFinalState1 >= 10000) {
	    std::cout<<"more than 10000 particles with status 1!"<<std::endl;
	  } else {
	    index_FinalState1[total_NFinalState1] = i;
	    total_NFinalState1++;
	  }
	}
	
	tree->ngParticles++;
      }

      //std::cout << "NFinalState1: " << total_NFinalState1 << std::endl;

      // Muons
      tree->nMuons = 0;
      for(unsigned int i = 0; i < muonPt->size(); i++) {
	tree->Muons_Pt[tree->nMuons] = muonPt->at(i);
	tree->Muons_Eta[tree->nMuons] = muonEta->at(i);
	tree->Muons_Phi[tree->nMuons] = muonPhi->at(i);
	tree->Muons_Type[tree->nMuons] = muonType->at(i);
	tree->Muons_IsLoose[tree->nMuons] = muonIsLoose->at(i);
	tree->Muons_IsMedium[tree->nMuons] = muonIsMedium->at(i);
	tree->Muons_IsTight[tree->nMuons] = muonIsTight->at(i);

	tree->nMuons++;
      }

      //this is where we used to fill trees but i'm going to try moving it later
      //tree->tree_->Fill();

 //============================
 //============================
 //   fill histograms here
 //============================
 //============================

    // no trigger requirments

      //everything not passing muon trigger & L1 not saturated  for histograms
      //if(!HLT_Mu50 && L1METHF>2000) {
  
      // no preselection requirement
      h_RecoCaloMET_noPres->Fill(RecoCaloMET);
      h_RecoPFMET_noPres->Fill(RecoPFMET);
      h_HLTCaloMET_noPres->Fill(HLTCaloMET);
      h_HLTPFMET_noPres->Fill(HLTPFMET);

      h_RPFM_all->Fill(RecoPFMET);
      h_RCAM_all->Fill(RecoCaloMET);

      h_numEventsCategories_noPres->Fill(0.5);
      h_numEventsCategories_passPres->Fill(0.5);

      // cut sequence for MET1 trigger
      if(L1METHF>100) {
	h_RPFM_passMET1Cut1->Fill(RecoPFMET);
	h_RCAM_passMET1Cut1->Fill(RecoCaloMET);
	if(HLTCaloMET>90) {
	  h_RPFM_passMET1Cut2->Fill(RecoPFMET);
	  h_RCAM_passMET1Cut2->Fill(RecoCaloMET);
	  if(HLTCaloMETClean>80) {
	    h_RPFM_passMET1Cut3->Fill(RecoPFMET);
	    h_RCAM_passMET1Cut3->Fill(RecoCaloMET);
	    if(HLTCaloMHT>90) {
	      h_RPFM_passMET1Cut4->Fill(RecoPFMET);
	      h_RCAM_passMET1Cut4->Fill(RecoCaloMET);
	      if(HLTPFMHT>120) {
		h_RPFM_passMET1Cut5->Fill(RecoPFMET);
		h_RCAM_passMET1Cut5->Fill(RecoCaloMET);
		if(HLTPFMET>120) {
		  h_RPFM_passMET1Cut6->Fill(RecoPFMET);
		  h_RCAM_passMET1Cut6->Fill(RecoCaloMET);
		}
	      }
	    }
	  }
	}
      }


      // events with at least one HSCP candidate passing preselection
      if(total_NCandPassPres_all == 0) {
	h_numEventsCategories_passPres->Fill(1.5);
      }

      if(total_NCandPassPres_all > 0) {
	h_RecoCaloMET_passPres->Fill(RecoCaloMET);
	h_RecoPFMET_passPres->Fill(RecoPFMET);
	h_HLTCaloMET_passPres->Fill(HLTCaloMET);
	h_HLTPFMET_passPres->Fill(HLTPFMET);
	h_numEventsCategories_passPres->Fill(2.5);

	h_LHFM_passPres_all->Fill(L1METHF);
	h_RPFM_passPres_all->Fill(RecoPFMET);
	h_RPFM_passPres_zoomed->Fill(RecoPFMET);
	h_RCAM_passPres_all->Fill(RecoCaloMET);
	h_RCAM_passPres_zoomed->Fill(RecoCaloMET);
	h_RPFM_LHFM_passPres->Fill(RecoPFMET,L1METHF);
	h_RCAM_LHFM_passPres->Fill(RecoCaloMET,L1METHF);
	h_RPFM_RCAM_passPres->Fill(RecoPFMET,RecoCaloMET);

	if(total_NCandPassPres_all == 1) {
	  h_RecoCaloMET_oneCand->Fill(RecoCaloMET);
	  h_RecoPFMET_oneCand->Fill(RecoPFMET);
	  h_HLTCaloMET_oneCand->Fill(HLTCaloMET);
	  h_HLTPFMET_oneCand->Fill(HLTPFMET);
	} if(total_NCandPassPres_all == 2) {
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

	h_RPFM_passMET1234->Fill(RecoPFMET);
	h_RCAM_passMET1234->Fill(RecoCaloMET);
	
	// events with at least one HSCP candidate passing preselection
	if(total_NCandPassPres_all > 0) {
	  h_RecoCaloMET_passPres_passMET->Fill(RecoCaloMET);
	  h_RecoPFMET_passPres_passMET->Fill(RecoPFMET);
	  h_HLTCaloMET_passPres_passMET->Fill(HLTCaloMET);
	  h_HLTPFMET_passPres_passMET->Fill(HLTPFMET);

	  if(total_NCandPassPres_all == 1) {
	    h_RecoCaloMET_oneCand_passMET->Fill(RecoCaloMET);
	    h_RecoPFMET_oneCand_passMET->Fill(RecoPFMET);
	    h_HLTCaloMET_oneCand_passMET->Fill(HLTCaloMET);
	    h_HLTPFMET_oneCand_passMET->Fill(HLTPFMET);
	  } if(total_NCandPassPres_all == 2) {
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

	h_RPFM_passMu->Fill(RecoPFMET);
	h_RCAM_passMu->Fill(RecoCaloMET);

	h_numEventsCategories_noPres->Fill(1.5);

	if(HLT_PFMET120_PFMHT120_IDTight || HLT_PFHT500_PFMET100_PFMHT100_IDTight || HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 || HLT_MET105_IsoTrk50) {
	  h_numEventsCategories_noPres->Fill(2.5);
	  if(L1METHF<2000) h_numEventsCategories_noPres->Fill(3.5);
	  if(L1METHF>2000) h_numEventsCategories_noPres->Fill(4.5);
	}

	if(!(HLT_PFMET120_PFMHT120_IDTight || HLT_PFHT500_PFMET100_PFMHT100_IDTight || HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 || HLT_MET105_IsoTrk50)) {
	  h_numEventsCategories_noPres->Fill(5.5);
	  if(L1METHF<2000) h_numEventsCategories_noPres->Fill(6.5);
	  if(L1METHF>2000) h_numEventsCategories_noPres->Fill(7.5);
	}
	

	// events with at least one HSCP candidate passing preselection
	if(total_NCandPassPres_all > 0) {
	  h_RecoCaloMET_passPres_passMuon->Fill(RecoCaloMET);
	  h_RecoPFMET_passPres_passMuon->Fill(RecoPFMET);
	  h_HLTCaloMET_passPres_passMuon->Fill(HLTCaloMET);
	  h_HLTPFMET_passPres_passMuon->Fill(HLTPFMET);
	  h_numEventsCategories_passPres->Fill(3.5);

	  if(HLT_PFMET120_PFMHT120_IDTight || HLT_PFHT500_PFMET100_PFMHT100_IDTight || HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 || HLT_MET105_IsoTrk50) {
	    h_numEventsCategories_passPres->Fill(4.5);
	    if(L1METHF<2000) h_numEventsCategories_passPres->Fill(5.5);
	    if(L1METHF>2000) h_numEventsCategories_passPres->Fill(6.5);
	  }

	  if(!(HLT_PFMET120_PFMHT120_IDTight || HLT_PFHT500_PFMET100_PFMHT100_IDTight || HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 || HLT_MET105_IsoTrk50)) {
	    h_numEventsCategories_passPres->Fill(7.5);
	    if(L1METHF<2000) h_numEventsCategories_passPres->Fill(8.5);
	    if(L1METHF>2000) h_numEventsCategories_passPres->Fill(9.5);
	  }
	}

      } 

      //FAIL muon trigger
      if(!HLT_Mu50) {
	// no preselection requirement
	h_numEventsCategories_noPres->Fill(8.5);

	if(HLT_PFMET120_PFMHT120_IDTight || HLT_PFHT500_PFMET100_PFMHT100_IDTight || HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 || HLT_MET105_IsoTrk50) {
	  h_numEventsCategories_noPres->Fill(9.5);
	  if(L1METHF<2000) {
	    h_numEventsCategories_noPres->Fill(10.5);
	    if(RecoCaloMET<170) h_numEventsCategories_noPres->Fill(11.5);
	    if(RecoCaloMET>170 && RecoCaloMET<600) h_numEventsCategories_noPres->Fill(12.5);
	    if(RecoCaloMET>600) h_numEventsCategories_noPres->Fill(13.5);
	  }
	  if(L1METHF>2000) {
	    h_numEventsCategories_noPres->Fill(14.5);
	    if(RecoCaloMET<170) h_numEventsCategories_noPres->Fill(15.5);
	    if(RecoCaloMET>170 && RecoCaloMET<600) h_numEventsCategories_noPres->Fill(16.5);
	    if(RecoCaloMET>600) h_numEventsCategories_noPres->Fill(17.5);
	  }
	}

	if(!(HLT_PFMET120_PFMHT120_IDTight || HLT_PFHT500_PFMET100_PFMHT100_IDTight || HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 || HLT_MET105_IsoTrk50)) {
	  h_numEventsCategories_noPres->Fill(18.5);
	  if(L1METHF<2000) h_numEventsCategories_noPres->Fill(19.5);
	  if(L1METHF>2000) h_numEventsCategories_noPres->Fill(20.5);
	}

	// events with at least one HSCP candidate passing preselection
	if(total_NCandPassPres_all > 0) {

	  h_numEventsCategories_passPres->Fill(10.5);
	  h_RPFM_passPres_noMU->Fill(RecoPFMET);
	  h_RCAM_passPres_noMU->Fill(RecoCaloMET);

	  if(L1METHF>100) {
	    h_RPFM_passPres_noMU_passMET1Cut1->Fill(RecoPFMET);
	    h_RCAM_passPres_noMU_passMET1Cut1->Fill(RecoCaloMET);
	    if(HLTCaloMET>90) {
	      h_RPFM_passPres_noMU_passMET1Cut2->Fill(RecoPFMET);
	      h_RCAM_passPres_noMU_passMET1Cut2->Fill(RecoCaloMET);
	      if(HLTCaloMETClean>80) {
		h_RPFM_passPres_noMU_passMET1Cut3->Fill(RecoPFMET);
		h_RCAM_passPres_noMU_passMET1Cut3->Fill(RecoCaloMET);
		if(HLTCaloMHT>90) {
		  h_RPFM_passPres_noMU_passMET1Cut4->Fill(RecoPFMET);
		  h_RCAM_passPres_noMU_passMET1Cut4->Fill(RecoCaloMET);
		  if(HLTPFMHT>120) {
		    h_RPFM_passPres_noMU_passMET1Cut5->Fill(RecoPFMET);
		    h_RCAM_passPres_noMU_passMET1Cut5->Fill(RecoCaloMET);
		    if(HLTPFMET>120) {
		      h_RPFM_passPres_noMU_passMET1Cut6->Fill(RecoPFMET);
		      h_RCAM_passPres_noMU_passMET1Cut6->Fill(RecoCaloMET);
		    }
		  }
		}
	      }
	    }
	  }

	  if(HLT_PFMET120_PFMHT120_IDTight || HLT_PFHT500_PFMET100_PFMHT100_IDTight || HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 || HLT_MET105_IsoTrk50) {

	    h_numEventsCategories_passPres->Fill(11.5);
	    h_RPFM_passPres_noMU_passMET1234->Fill(RecoPFMET);
	    h_RCAM_passPres_noMU_passMET1234->Fill(RecoCaloMET);

	    if(L1METHF<2000) {
	      h_numEventsCategories_passPres->Fill(12.5);
	      if(RecoCaloMET<170) h_numEventsCategories_passPres->Fill(13.5);
	      if(RecoCaloMET>170 && RecoCaloMET<600) h_numEventsCategories_passPres->Fill(14.5);
	      if(RecoCaloMET>600) h_numEventsCategories_passPres->Fill(15.5);
	    }
	    if(L1METHF>2000) {
	      h_numEventsCategories_passPres->Fill(16.5);
	      if(RecoCaloMET<170) h_numEventsCategories_passPres->Fill(17.5);
	      if(RecoCaloMET>170 && RecoCaloMET<600) h_numEventsCategories_passPres->Fill(18.5);
	      if(RecoCaloMET>600) h_numEventsCategories_passPres->Fill(19.5);
	    }

	  }

	  if(HLT_PFMET120_PFMHT120_IDTight) {
	    h_RPFM_passPres_noMU_passMET1->Fill(RecoPFMET);
	    h_RCAM_passPres_noMU_passMET1->Fill(RecoCaloMET);
	  }
	  
	  if(!(HLT_PFMET120_PFMHT120_IDTight || HLT_PFHT500_PFMET100_PFMHT100_IDTight || HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 || HLT_MET105_IsoTrk50)) {
	    h_numEventsCategories_passPres->Fill(20.5);
	    if(L1METHF<2000) h_numEventsCategories_passPres->Fill(21.5);
	    if(L1METHF>2000) h_numEventsCategories_passPres->Fill(22.5);
	  }

	}

      }



      // passing MET OR Muon triggers
      if (HLT_PFMET120_PFMHT120_IDTight || HLT_PFHT500_PFMET100_PFMHT100_IDTight || HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 || HLT_MET105_IsoTrk50 || HLT_Mu50) {

	// no preselection requirement
	h_RecoCaloMET_noPres_passMETOrMuon->Fill(RecoCaloMET);
	h_RecoPFMET_noPres_passMETOrMuon->Fill(RecoPFMET);
	h_HLTCaloMET_noPres_passMETOrMuon->Fill(HLTCaloMET);
	h_HLTPFMET_noPres_passMETOrMuon->Fill(HLTPFMET);

	h_RPFM_passMuORMET1234->Fill(RecoPFMET);
	h_RCAM_passMuORMET1234->Fill(RecoCaloMET);

	// events with at least one HSCP candidate passing preselection
	if(total_NCandPassPres_all > 0) {
	  h_RecoCaloMET_passPres_passMETOrMuon->Fill(RecoCaloMET);
	  h_RecoPFMET_passPres_passMETOrMuon->Fill(RecoPFMET);
	  h_HLTCaloMET_passPres_passMETOrMuon->Fill(HLTCaloMET);
	  h_HLTPFMET_passPres_passMETOrMuon->Fill(HLTPFMET);
	}

      } if (HLT_PFMET120_PFMHT120_IDTight) {

	// no preselection requirement
	h_RPFM_passMET1->Fill(RecoPFMET);
	h_RCAM_passMET1->Fill(RecoCaloMET);
      }


      // start filling other histograms
      if(total_NCandPassPres_all == 1) {

	int HSCP_index = index_PassPres[0];

	float HSCP_pt_value = Pt->at(HSCP_index);
	h_HSCP_pt_passPres->Fill(HSCP_pt_value);

	float dPhi_HSCP_RecoPFMET_value = fabs(RazorAnalyzer::deltaPhi(phi->at(HSCP_index),RecoPFMET_phi));
	float dPhi_HSCP_RecoCaloMET_value = fabs(RazorAnalyzer::deltaPhi(phi->at(HSCP_index),RecoCaloMET_phi));
	float dPhi_HSCP_HLTPFMET_value = fabs(RazorAnalyzer::deltaPhi(phi->at(HSCP_index),HLTPFMET_phi));
	float dPhi_HSCP_HLTCaloMET_value = fabs(RazorAnalyzer::deltaPhi(phi->at(HSCP_index),HLTCaloMET_phi));
	float dPhi_RecoPFMET_RecoCaloMET_value = fabs(RazorAnalyzer::deltaPhi(RecoPFMET_phi, RecoCaloMET_phi));
	float dPhi_HLTPFMET_HLTCaloMET_value = fabs(RazorAnalyzer::deltaPhi(HLTPFMET_phi, HLTCaloMET_phi));
	float dPhi_RecoPFMET_HLTPFMET_value = fabs(RazorAnalyzer::deltaPhi(RecoPFMET_phi, HLTPFMET_phi));
	float dPhi_RecoCaloMET_HLTCaloMET_value = fabs(RazorAnalyzer::deltaPhi(RecoCaloMET_phi, HLTCaloMET_phi));

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
	
      }

      if(total_NCandPassPres_all == 2) {

	int HSCP_index1 = index_PassPres[0];
	int HSCP_index2 = index_PassPres[1];

	float HSCP_pt_value1 = Pt->at(HSCP_index1);
	float HSCP_pt_value2 = Pt->at(HSCP_index2);
	h_HSCP_pt_passPres->Fill(HSCP_pt_value1);
	h_HSCP_pt_passPres->Fill(HSCP_pt_value2);

	float dPhi_HSCP_RecoPFMET_value = fabs(RazorAnalyzer::deltaPhi(phi->at(HSCP_index1),RecoPFMET_phi));
	float dPhi_HSCP_RecoCaloMET_value = fabs(RazorAnalyzer::deltaPhi(phi->at(HSCP_index1),RecoCaloMET_phi));
	float dPhi_HSCP_HLTPFMET_value = fabs(RazorAnalyzer::deltaPhi(phi->at(HSCP_index1),HLTPFMET_phi));
	float dPhi_HSCP_HLTCaloMET_value = fabs(RazorAnalyzer::deltaPhi(phi->at(HSCP_index1),HLTCaloMET_phi));
	float dPhi_RecoPFMET_RecoCaloMET_value = fabs(RazorAnalyzer::deltaPhi(RecoPFMET_phi, RecoCaloMET_phi));
	float dPhi_HLTPFMET_HLTCaloMET_value = fabs(RazorAnalyzer::deltaPhi(HLTPFMET_phi, HLTCaloMET_phi));
	float dPhi_RecoPFMET_HLTPFMET_value = fabs(RazorAnalyzer::deltaPhi(RecoPFMET_phi, HLTPFMET_phi));
	float dPhi_RecoCaloMET_HLTCaloMET_value = fabs(RazorAnalyzer::deltaPhi(RecoCaloMET_phi, HLTCaloMET_phi));


	h_twoCand_dPhi_HSCP1_HSCP2->Fill(fabs(RazorAnalyzer::deltaPhi(phi->at(HSCP_index1), phi->at(HSCP_index2))));
	h_twoCand_dPhi_HSCP1_RecoPFMET->Fill(fabs(RazorAnalyzer::deltaPhi(phi->at(HSCP_index1), RecoPFMET_phi)));
	h_twoCand_dPhi_HSCP2_RecoPFMET->Fill(fabs(RazorAnalyzer::deltaPhi(phi->at(HSCP_index2), RecoPFMET_phi)));
	h_twoCand_dPhi_HSCP1_RecoCaloMET->Fill(fabs(RazorAnalyzer::deltaPhi(phi->at(HSCP_index1), RecoCaloMET_phi)));
	h_twoCand_dPhi_HSCP1_HLTPFMET->Fill(fabs(RazorAnalyzer::deltaPhi(phi->at(HSCP_index1), HLTPFMET_phi)));
	h_twoCand_dPhi_HSCP1_HLTCaloMET->Fill(fabs(RazorAnalyzer::deltaPhi(phi->at(HSCP_index1), HLTCaloMET_phi)));
	h_twoCand_dPhi_RecoPFMET_RecoCaloMET->Fill(fabs(RazorAnalyzer::deltaPhi(RecoPFMET_phi, RecoCaloMET_phi)));
	h_twoCand_dPhi_HLTPFMET_HLTCaloMET->Fill(fabs(RazorAnalyzer::deltaPhi(HLTPFMET_phi, HLTCaloMET_phi)));
	h_twoCand_dPhi_RecoPFMET_HLTPFMET->Fill(fabs(RazorAnalyzer::deltaPhi(RecoPFMET_phi, HLTPFMET_phi)));
	h_twoCand_dPhi_RecoCaloMET_HLTCaloMET->Fill(fabs(RazorAnalyzer::deltaPhi(RecoCaloMET_phi, HLTCaloMET_phi)));

	h_twoCand_dPhi_HSCP_RecoPFMET_vs_RecoPFMET->Fill(dPhi_HSCP_RecoPFMET_value, RecoPFMET);
	h_twoCand_dPhi_HSCP_RecoPFMET_vs_RecoCaloMET->Fill(dPhi_HSCP_RecoPFMET_value, RecoCaloMET);
	h_twoCand_dPhi_HSCP_RecoCaloMET_vs_RecoPFMET->Fill(dPhi_HSCP_RecoCaloMET_value, RecoPFMET);
	h_twoCand_dPhi_HSCP_RecoCaloMET_vs_RecoCaloMET->Fill(dPhi_HSCP_RecoCaloMET_value, RecoCaloMET);

	h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET->Fill(dPhi_HSCP_RecoPFMET_value, dPhi_HSCP_RecoCaloMET_value);
	if(RecoCaloMET < 100) {
	  h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet0to100->Fill(dPhi_HSCP_RecoPFMET_value, dPhi_HSCP_RecoCaloMET_value);
	} if(RecoCaloMET > 100 && RecoCaloMET < 500) {
	  h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet100to500->Fill(dPhi_HSCP_RecoPFMET_value, dPhi_HSCP_RecoCaloMET_value);
	} if(RecoCaloMET > 500) {
	  h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet500to->Fill(dPhi_HSCP_RecoPFMET_value, dPhi_HSCP_RecoCaloMET_value);
	} if(RecoPFMET < 100) {
	  h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet0to100->Fill(dPhi_HSCP_RecoPFMET_value, dPhi_HSCP_RecoCaloMET_value);
	} if(RecoPFMET > 100 && RecoPFMET < 500) {
	  h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet100to500->Fill(dPhi_HSCP_RecoPFMET_value, dPhi_HSCP_RecoCaloMET_value);
	} if(RecoPFMET > 500) {
	  h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet500to->Fill(dPhi_HSCP_RecoPFMET_value, dPhi_HSCP_RecoCaloMET_value);
	}

      }

      int total_NGenHSCP = 0;
      int total_NNonHSCPGen1GeV = 0;
      int total_NNonHSCPGen10GeV = 0;
      int total_NNonHSCPGen50GeV = 0;
      int total_NNonHSCPGen100GeV = 0;
      int total_NGenHSCPCharge0 = 0;
      int total_NGenHSCPChargeNon0 = 0;
      int total_NGenHSCPMatched = 0;
      int total_NGenHSCPCharge0Matched =  0;
      int total_NGenHSCPChargeNon0Matched = 0;
      int total_NJets = Jet_pt->size();
      int total_GenHSCP_charge_configuration = 0;

      int   quick_HSCP_counter = 0;
      float HSCP1_eta = -10;
      float HSCP1_phi = -10;
      int   HSCP1_charge = -10;
      float HSCP1_beta = -10;
      float HSCP1_p = -10;
      float HSCP1_pt = -10;
      float HSCP1_px = -10;
      float HSCP1_py = -10;
      float HSCP2_eta = -10;
      float HSCP2_phi = -10;
      int   HSCP2_charge = -10;
      float HSCP2_beta = -10;
      float HSCP2_p = -10;
      float HSCP2_pt = -10;
      float HSCP2_px = -10;
      float HSCP2_py = -10;

      float deltaEta_HSCP1_Gen = -10;
      float deltaPhi_HSCP1_Gen = -10;
      float deltaR_HSCP1_Gen = -10;
      float deltaEta_HSCP2_Gen = -10;
      float deltaPhi_HSCP2_Gen = -10;
      float deltaR_HSCP2_Gen = -10;
      
      float deltaPt_HSCP1_HSCP2 = -10;
      float deltaP_HSCP1_HSCP2 = -10;
      float deltaEta_HSCP1_HSCP2 = -10;
      float deltaPhi_HSCP1_HSCP2 = -10;
      float deltaR_HSCP1_HSCP2 = -10;

      float diHSCP_mag = -10;
      float diHSCP_phi = -10;
      float neg_diHSCP_phi = -10;
      float deltaPhi_diHSCP_Gen = -10;
      float deltaPhi_neg_diHSCP_Gen = -10;
      float deltaPhi_diHSCP_HSCP1 = -10;
      float deltaPhi_diHSCP_HSCP2 = -10;
      float deltaPhi_RecoCaloMET_diHSCP = -10;
      float deltaPhi_RecoCaloMET_HSCP1 = -10;
      float deltaPhi_RecoCaloMET_HSCP2 = -10;
      float deltaPhi_HLTCaloMET_diHSCP = -10;
      float deltaPhi_HLTCaloMET_HSCP1 = -10;
      float deltaPhi_HLTCaloMET_HSCP2 = -10;
      float neg_diHSCP_cone0p4_GenPx = -10;
      float neg_diHSCP_cone0p4_GenPy = -10;
      float neg_diHSCP_cone0p4_GenPtMag = -10;

      bool CaloMETClean_same = false;

      //beginning of loop on final state particles
      //if(total_NFinalState1 > 0){ //technically not necessary
      for(unsigned int i = 0; i < total_NFinalState1; i++){

	if(fabs(gParticleId->at(index_FinalState1[i])) < 1000000) {
	  if(gParticlePt->at(index_FinalState1[i]) > 1) total_NNonHSCPGen1GeV++;
	  if(gParticlePt->at(index_FinalState1[i]) > 10) total_NNonHSCPGen10GeV++;
	  if(gParticlePt->at(index_FinalState1[i]) > 50) total_NNonHSCPGen50GeV++;
	  if(gParticlePt->at(index_FinalState1[i]) > 100) total_NNonHSCPGen100GeV++;
	}
	
	//require the final state particle to have ID in the millions, i.e. require the particle to be the R-hadron
	if(fabs(gParticleId->at(index_FinalState1[i])) > 999999){

	  quick_HSCP_counter++;
	  
	  float best_matched_deltaR_value = 999;
	  int   total_NMatches_lessthan01 = 0;
	
	  float HSCP_pt_ = gParticlePt->at(index_FinalState1[i]);
	  float HSCP_pz_ = gParticlePz->at(index_FinalState1[i]);
	  float HSCP_eta_ = gParticleEta->at(index_FinalState1[i]);
	  float HSCP_phi_ = gParticlePhi->at(index_FinalState1[i]);
	  float HSCP_beta_ = gParticleBeta->at(index_FinalState1[i]);
	  float HSCP_px_ = cos(HSCP_phi_)*(HSCP_pt_);
	  float HSCP_py_ = sin(HSCP_phi_)*(HSCP_pt_);
	  float HSCP_p_ = sqrt(pow(HSCP_pt_,2) + pow(HSCP_pz_,2));

	  //float HSCP_charge_ defined way up above
	  //float HSCP_charge_ = gParticleCharge->at(index_FinalState1[i]);

	  int   HSCP_charge_ = -10;

	  if(gParticleId->at(index_FinalState1[i]) == -1092224) {
	    HSCP_charge_ = -2;
	  } else if(
	        gParticleId->at(index_FinalState1[i]) == 1093334 ||
		gParticleId->at(index_FinalState1[i]) == 1093314 ||
		gParticleId->at(index_FinalState1[i]) == 1093114 ||
		gParticleId->at(index_FinalState1[i]) == 1091114 ||
		gParticleId->at(index_FinalState1[i]) == -1009213 ||
		gParticleId->at(index_FinalState1[i]) == -1009323 ||
		gParticleId->at(index_FinalState1[i]) == -1092214 ||
		gParticleId->at(index_FinalState1[i]) == -1093224
		    ) {
	    HSCP_charge_ = -1;
	  } else if(
	        gParticleId->at(index_FinalState1[i]) == 1093324 ||
		gParticleId->at(index_FinalState1[i]) == 1093214 ||
		gParticleId->at(index_FinalState1[i]) == 1092114 ||
		gParticleId->at(index_FinalState1[i]) == 1009333 ||
		gParticleId->at(index_FinalState1[i]) == 1009313 ||
		gParticleId->at(index_FinalState1[i]) == 1009223 ||
		gParticleId->at(index_FinalState1[i]) == 1009113 ||
		gParticleId->at(index_FinalState1[i]) == 1000993 ||
		gParticleId->at(index_FinalState1[i]) == -1009313 ||
		gParticleId->at(index_FinalState1[i]) == -1092114 ||
		gParticleId->at(index_FinalState1[i]) == -1093214 ||
		gParticleId->at(index_FinalState1[i]) == -1093324
		    ) {
	    HSCP_charge_ = 0;
	  } else if(
	        gParticleId->at(index_FinalState1[i]) == 1093224 ||
		gParticleId->at(index_FinalState1[i]) == 1092214 ||
		gParticleId->at(index_FinalState1[i]) == 1009323 ||
		gParticleId->at(index_FinalState1[i]) == 1009213 ||
		gParticleId->at(index_FinalState1[i]) == -1091114 ||
		gParticleId->at(index_FinalState1[i]) == -1093114 ||
		gParticleId->at(index_FinalState1[i]) == -1093314
		    ){
	    HSCP_charge_ = 1;
	  } else if(
	        gParticleId->at(index_FinalState1[i]) == 1092224
		    ){
	    HSCP_charge_ = 2;
	  } else {
	    HSCP_charge_ = -10;
	  }


	  if(quick_HSCP_counter == 1) {

	    HSCP1_eta = HSCP_eta_;
	    HSCP1_phi = HSCP_phi_;
	    HSCP1_charge = HSCP_charge_;
	    HSCP1_beta = HSCP_beta_;
	    HSCP1_p = HSCP_p_;
	    HSCP1_pt = HSCP_pt_;
	    HSCP1_px = HSCP_px_;
	    HSCP1_py = HSCP_py_;

	    h_Eta_HSCP1->Fill(HSCP1_eta);
	    h_Phi_HSCP1->Fill(HSCP1_phi);

	  } if(quick_HSCP_counter == 2) {

	    HSCP2_eta = HSCP_eta_;
	    HSCP2_phi = HSCP_phi_;
	    HSCP2_charge = HSCP_charge_;
	    HSCP2_beta = HSCP_beta_;
	    HSCP2_p = HSCP_p_;
	    HSCP2_pt = HSCP_pt_;
	    HSCP2_px = HSCP_px_;
	    HSCP2_py = HSCP_py_;

	    h_Eta_HSCP2->Fill(HSCP2_eta);
	    h_Phi_HSCP2->Fill(HSCP2_phi);

	  }

	  
	  total_NGenHSCP++;
	  //if(HSCP_charge_ == 0) total_NGenHSCPCharge0++;
	  //if(HSCP_charge_ != 0) total_NGenHSCPChargeNon0++;

	  //adding value to genHSCP charge config only if gen HSCP has charge not equal to 0, so charge config 0 = n-n, 1 = n-c, 2 = c-c

	  if(HSCP_charge_ != 0) total_GenHSCP_charge_configuration++;

	  //beginning of loop for nonHSCP gen particles within gen HSCP loop
	  for(unsigned int j = 0; j < total_NFinalState1; j++){	    
	    
	    // all non-HSCP GEN particles
	    if(fabs(gParticleId->at(index_FinalState1[j])) < 1000000){
	    
	    // only photons & pions
	    //if( (fabs(gParticleId->at(index_FinalState1[j])) == 211) || (gParticleId->at(index_FinalState1[j]) == 22) ){

	    // only photons
	    //if(gParticleId->at(index_FinalState1[j]) == 22){

	      //first HSCP
	      if(quick_HSCP_counter == 1) {

		deltaEta_HSCP1_Gen = HSCP1_eta - gParticleEta->at(index_FinalState1[j]);
		deltaPhi_HSCP1_Gen = fabs(RazorAnalyzer::deltaPhi(HSCP1_phi, gParticlePhi->at(index_FinalState1[j])));
		deltaR_HSCP1_Gen = sqrt(pow(deltaEta_HSCP1_Gen,2) + pow(deltaPhi_HSCP1_Gen, 2));

		h_Eta_Gen->Fill(gParticleEta->at(index_FinalState1[j]));
		h_Phi_Gen->Fill(gParticlePhi->at(index_FinalState1[j]));

		h_deltaEta_HSCP1_Gen->Fill(deltaEta_HSCP1_Gen);
		h_deltaPhi_HSCP1_Gen->Fill(deltaPhi_HSCP1_Gen);
		h_deltaR_HSCP1_Gen->Fill(deltaR_HSCP1_Gen);

		if(gParticlePt->at(index_FinalState1[j]) > 5){
		
		  h_Eta_Gen_pT5->Fill(gParticleEta->at(index_FinalState1[j]));
			
		  h_deltaEta_HSCP1_Gen_pT5->Fill(deltaEta_HSCP1_Gen);
		  h_deltaPhi_HSCP1_Gen_pT5->Fill(deltaPhi_HSCP1_Gen);
		  h_deltaR_HSCP1_Gen_pT5->Fill(deltaR_HSCP1_Gen);
		}

		if(gParticlePt->at(index_FinalState1[j]) > 50){
		
		  h_Eta_Gen_pT50->Fill(gParticleEta->at(index_FinalState1[j]));
		
		  h_deltaEta_HSCP1_Gen_pT50->Fill(deltaEta_HSCP1_Gen);
		  h_deltaPhi_HSCP1_Gen_pT50->Fill(deltaPhi_HSCP1_Gen);
		  h_deltaR_HSCP1_Gen_pT50->Fill(deltaR_HSCP1_Gen);
		}

		if(gParticlePt->at(index_FinalState1[j]) > 100){
		
		  h_Eta_Gen_pT100->Fill(gParticleEta->at(index_FinalState1[j]));
		
		  h_deltaEta_HSCP1_Gen_pT100->Fill(deltaEta_HSCP1_Gen);
		  h_deltaPhi_HSCP1_Gen_pT100->Fill(deltaPhi_HSCP1_Gen);
		  h_deltaR_HSCP1_Gen_pT100->Fill(deltaR_HSCP1_Gen);
		}
	      }

	      //second HSCP
	      if(quick_HSCP_counter == 2) {
		
		deltaEta_HSCP1_Gen = HSCP1_eta - gParticleEta->at(index_FinalState1[j]);
		deltaPhi_HSCP1_Gen = fabs(RazorAnalyzer::deltaPhi(HSCP1_phi, gParticlePhi->at(index_FinalState1[j])));
		deltaR_HSCP1_Gen = sqrt(pow(deltaEta_HSCP1_Gen, 2) + pow(deltaPhi_HSCP1_Gen, 2));

		deltaEta_HSCP2_Gen = HSCP2_eta - gParticleEta->at(index_FinalState1[j]);
		deltaPhi_HSCP2_Gen = fabs(RazorAnalyzer::deltaPhi(HSCP2_phi, gParticlePhi->at(index_FinalState1[j])));
		deltaR_HSCP2_Gen = sqrt(pow(deltaEta_HSCP2_Gen, 2) + pow(deltaPhi_HSCP2_Gen, 2));

		h_deltaEta_HSCP2_Gen->Fill(deltaEta_HSCP2_Gen);
		h_deltaPhi_HSCP2_Gen->Fill(deltaPhi_HSCP2_Gen);
		h_deltaR_HSCP2_Gen->Fill(deltaR_HSCP2_Gen);

		deltaPhi_HSCP1_HSCP2 = fabs(RazorAnalyzer::deltaPhi(HSCP1_phi, HSCP2_phi));

		diHSCP_phi = atan2((HSCP1_py + HSCP2_py),(HSCP1_px + HSCP2_px));
		diHSCP_mag = sqrt(pow((HSCP1_px + HSCP2_px),2) + pow((HSCP1_py + HSCP2_py),2));
		deltaPhi_diHSCP_Gen = fabs(RazorAnalyzer::deltaPhi(diHSCP_phi,gParticlePhi->at(index_FinalState1[j])));

		h_deltaPhi_diHSCP_Gen->Fill(deltaPhi_diHSCP_Gen);
		h_deltaPhi_diHSCP_Gen_GenpT->Fill(deltaPhi_diHSCP_Gen,gParticlePt->at(index_FinalState1[j]));

		//atan(1)*4 is pi
		if(diHSCP_phi<0) neg_diHSCP_phi = diHSCP_phi + (atan(1)*4);
		if(diHSCP_phi>0) neg_diHSCP_phi = diHSCP_phi - (atan(1)*4);
		deltaPhi_neg_diHSCP_Gen = fabs(RazorAnalyzer::deltaPhi(neg_diHSCP_phi, gParticlePhi->at(index_FinalState1[j])));
		h_deltaPhi_neg_diHSCP_Gen->Fill(deltaPhi_neg_diHSCP_Gen);
		if(diHSCP_mag>100) h_deltaPhi_neg_diHSCP_pT100_Gen->Fill(deltaPhi_neg_diHSCP_Gen);
		if(deltaPhi_neg_diHSCP_Gen<0.4) {
		  float gen_px_ = cos(gParticlePhi->at(index_FinalState1[j]))*(gParticlePt->at(index_FinalState1[j]));
		  float gen_py_ = sin(gParticlePhi->at(index_FinalState1[j]))*(gParticlePt->at(index_FinalState1[j]));

		  neg_diHSCP_cone0p4_GenPx += gen_px_;
		  neg_diHSCP_cone0p4_GenPy += gen_py_;
		}
	      
		if(gParticlePt->at(index_FinalState1[j]) > 5){
		  h_deltaEta_HSCP2_Gen_pT5->Fill(deltaEta_HSCP2_Gen);
		  h_deltaPhi_HSCP2_Gen_pT5->Fill(deltaPhi_HSCP2_Gen);
		  h_deltaR_HSCP2_Gen_pT5->Fill(deltaR_HSCP2_Gen);
		  h_deltaPhi_diHSCP_Gen_pT5->Fill(deltaPhi_diHSCP_Gen);
		  h_deltaPhi_diHSCP_Gen_pT5_GenpT->Fill(deltaPhi_diHSCP_Gen,gParticlePt->at(index_FinalState1[j]));
		  h_deltaPhi_neg_diHSCP_Gen_pT5->Fill(deltaPhi_neg_diHSCP_Gen);
		  if(diHSCP_mag>100) h_deltaPhi_neg_diHSCP_pT100_Gen_pT5->Fill(deltaPhi_neg_diHSCP_Gen);
		  
		}
		if(gParticlePt->at(index_FinalState1[j]) > 50){
		  h_deltaEta_HSCP2_Gen_pT50->Fill(deltaEta_HSCP2_Gen);
		  h_deltaPhi_HSCP2_Gen_pT50->Fill(deltaPhi_HSCP2_Gen);
		  h_deltaR_HSCP2_Gen_pT50->Fill(deltaR_HSCP2_Gen);
		  h_deltaPhi_diHSCP_Gen_pT50->Fill(deltaPhi_diHSCP_Gen);
		  h_deltaPhi_diHSCP_Gen_pT50_GenpT->Fill(deltaPhi_diHSCP_Gen,gParticlePt->at(index_FinalState1[j]));
		  h_deltaPhi_neg_diHSCP_Gen_pT50->Fill(deltaPhi_neg_diHSCP_Gen);
		  if(diHSCP_mag>100) h_deltaPhi_neg_diHSCP_pT100_Gen_pT50->Fill(deltaPhi_neg_diHSCP_Gen);
		}
		if(gParticlePt->at(index_FinalState1[j]) > 100){
		  h_deltaEta_HSCP2_Gen_pT100->Fill(deltaEta_HSCP2_Gen);
		  h_deltaPhi_HSCP2_Gen_pT100->Fill(deltaPhi_HSCP2_Gen);
		  h_deltaR_HSCP2_Gen_pT100->Fill(deltaR_HSCP2_Gen);
		  h_deltaPhi_diHSCP_Gen_pT100->Fill(deltaPhi_diHSCP_Gen);
		  h_deltaPhi_diHSCP_Gen_pT100_GenpT->Fill(deltaPhi_diHSCP_Gen,gParticlePt->at(index_FinalState1[j]));
		  h_deltaPhi_neg_diHSCP_Gen_pT100->Fill(deltaPhi_neg_diHSCP_Gen);
		  if(diHSCP_mag>100) h_deltaPhi_neg_diHSCP_pT100_Gen_pT100->Fill(deltaPhi_neg_diHSCP_Gen);
		}

		//check now in bins of delta Phi of HSCPs
		if(deltaPhi_HSCP1_HSCP2 >= 3.1) {
		 
		  h_deltaEta_HSCP1_Gen_bin1->Fill(deltaEta_HSCP1_Gen);
		  h_deltaPhi_HSCP1_Gen_bin1->Fill(deltaPhi_HSCP1_Gen);
		  h_deltaR_HSCP1_Gen_bin1->Fill(deltaR_HSCP1_Gen);
		  h_deltaEta_HSCP2_Gen_bin1->Fill(deltaEta_HSCP2_Gen);
		  h_deltaPhi_HSCP2_Gen_bin1->Fill(deltaPhi_HSCP2_Gen);
		  h_deltaR_HSCP2_Gen_bin1->Fill(deltaR_HSCP2_Gen);
		  h_deltaPhi_diHSCP_Gen_GenpT_bin1->Fill(deltaPhi_diHSCP_Gen,gParticlePt->at(index_FinalState1[j]));

		  if(gParticlePt->at(index_FinalState1[j]) > 5){
		    h_deltaEta_HSCP1_Gen_pT5_bin1->Fill(deltaEta_HSCP1_Gen);
		    h_deltaPhi_HSCP1_Gen_pT5_bin1->Fill(deltaPhi_HSCP1_Gen);
		    h_deltaR_HSCP1_Gen_pT5_bin1->Fill(deltaR_HSCP1_Gen);
		    h_deltaEta_HSCP2_Gen_pT5_bin1->Fill(deltaEta_HSCP2_Gen);
		    h_deltaPhi_HSCP2_Gen_pT5_bin1->Fill(deltaPhi_HSCP2_Gen);
		    h_deltaR_HSCP2_Gen_pT5_bin1->Fill(deltaR_HSCP2_Gen);
		    h_deltaPhi_diHSCP_Gen_pT5_GenpT_bin1->Fill(deltaPhi_diHSCP_Gen,gParticlePt->at(index_FinalState1[j]));
		  }
		  if(gParticlePt->at(index_FinalState1[j]) > 50){
		    h_deltaEta_HSCP1_Gen_pT50_bin1->Fill(deltaEta_HSCP1_Gen);
		    h_deltaPhi_HSCP1_Gen_pT50_bin1->Fill(deltaPhi_HSCP1_Gen);
		    h_deltaR_HSCP1_Gen_pT50_bin1->Fill(deltaR_HSCP1_Gen);
		    h_deltaEta_HSCP2_Gen_pT50_bin1->Fill(deltaEta_HSCP2_Gen);
		    h_deltaPhi_HSCP2_Gen_pT50_bin1->Fill(deltaPhi_HSCP2_Gen);
		    h_deltaR_HSCP2_Gen_pT50_bin1->Fill(deltaR_HSCP2_Gen);
		    h_deltaPhi_diHSCP_Gen_pT50_GenpT_bin1->Fill(deltaPhi_diHSCP_Gen,gParticlePt->at(index_FinalState1[j]));
		  }
		  if(gParticlePt->at(index_FinalState1[j]) > 100){
		    h_deltaEta_HSCP1_Gen_pT100_bin1->Fill(deltaEta_HSCP1_Gen);
		    h_deltaPhi_HSCP1_Gen_pT100_bin1->Fill(deltaPhi_HSCP1_Gen);
		    h_deltaR_HSCP1_Gen_pT100_bin1->Fill(deltaR_HSCP1_Gen);
		    h_deltaEta_HSCP2_Gen_pT100_bin1->Fill(deltaEta_HSCP2_Gen);
		    h_deltaPhi_HSCP2_Gen_pT100_bin1->Fill(deltaPhi_HSCP2_Gen);
		    h_deltaR_HSCP2_Gen_pT100_bin1->Fill(deltaR_HSCP2_Gen);
		    h_deltaPhi_diHSCP_Gen_pT100_GenpT_bin1->Fill(deltaPhi_diHSCP_Gen,gParticlePt->at(index_FinalState1[j]));
		  }

		} if(deltaPhi_HSCP1_HSCP2 >= 2.35 && deltaPhi_HSCP1_HSCP2 < 3.1) {

		  h_deltaEta_HSCP2_Gen_bin2->Fill(deltaEta_HSCP2_Gen);
		  h_deltaPhi_HSCP2_Gen_bin2->Fill(deltaPhi_HSCP2_Gen);
		  h_deltaR_HSCP2_Gen_bin2->Fill(deltaR_HSCP2_Gen);
		  h_deltaPhi_diHSCP_Gen_GenpT_bin2->Fill(deltaPhi_diHSCP_Gen,gParticlePt->at(index_FinalState1[j]));

		  if(gParticlePt->at(index_FinalState1[j]) > 5){
		    h_deltaEta_HSCP2_Gen_pT5_bin2->Fill(deltaEta_HSCP2_Gen);
		    h_deltaPhi_HSCP2_Gen_pT5_bin2->Fill(deltaPhi_HSCP2_Gen);
		    h_deltaR_HSCP2_Gen_pT5_bin2->Fill(deltaR_HSCP2_Gen);
		    h_deltaPhi_diHSCP_Gen_pT5_GenpT_bin2->Fill(deltaPhi_diHSCP_Gen,gParticlePt->at(index_FinalState1[j]));
		  }
		  if(gParticlePt->at(index_FinalState1[j]) > 50){
		    h_deltaEta_HSCP2_Gen_pT50_bin2->Fill(deltaEta_HSCP2_Gen);
		    h_deltaPhi_HSCP2_Gen_pT50_bin2->Fill(deltaPhi_HSCP2_Gen);
		    h_deltaR_HSCP2_Gen_pT50_bin2->Fill(deltaR_HSCP2_Gen);
		    h_deltaPhi_diHSCP_Gen_pT50_GenpT_bin2->Fill(deltaPhi_diHSCP_Gen,gParticlePt->at(index_FinalState1[j]));
		  }
		  if(gParticlePt->at(index_FinalState1[j]) > 100){
		    h_deltaEta_HSCP2_Gen_pT100_bin2->Fill(deltaEta_HSCP2_Gen);
		    h_deltaPhi_HSCP2_Gen_pT100_bin2->Fill(deltaPhi_HSCP2_Gen);
		    h_deltaR_HSCP2_Gen_pT100_bin2->Fill(deltaR_HSCP2_Gen);
		    h_deltaPhi_diHSCP_Gen_pT100_GenpT_bin2->Fill(deltaPhi_diHSCP_Gen,gParticlePt->at(index_FinalState1[j]));
		  }

		} if(deltaPhi_HSCP1_HSCP2 >= 1.6 && deltaPhi_HSCP1_HSCP2 < 2.35) {

		  h_deltaEta_HSCP2_Gen_bin3->Fill(deltaEta_HSCP2_Gen);
		  h_deltaPhi_HSCP2_Gen_bin3->Fill(deltaPhi_HSCP2_Gen);
		  h_deltaR_HSCP2_Gen_bin3->Fill(deltaR_HSCP2_Gen);
		  h_deltaPhi_diHSCP_Gen_GenpT_bin3->Fill(deltaPhi_diHSCP_Gen,gParticlePt->at(index_FinalState1[j]));

		  if(gParticlePt->at(index_FinalState1[j]) > 5){
		    h_deltaEta_HSCP2_Gen_pT5_bin3->Fill(deltaEta_HSCP2_Gen);
		    h_deltaPhi_HSCP2_Gen_pT5_bin3->Fill(deltaPhi_HSCP2_Gen);
		    h_deltaR_HSCP2_Gen_pT5_bin3->Fill(deltaR_HSCP2_Gen);
		    h_deltaPhi_diHSCP_Gen_pT5_GenpT_bin3->Fill(deltaPhi_diHSCP_Gen,gParticlePt->at(index_FinalState1[j]));
		  }
		  if(gParticlePt->at(index_FinalState1[j]) > 50){
		    h_deltaEta_HSCP2_Gen_pT50_bin3->Fill(deltaEta_HSCP2_Gen);
		    h_deltaPhi_HSCP2_Gen_pT50_bin3->Fill(deltaPhi_HSCP2_Gen);
		    h_deltaR_HSCP2_Gen_pT50_bin3->Fill(deltaR_HSCP2_Gen);
		    h_deltaPhi_diHSCP_Gen_pT50_GenpT_bin3->Fill(deltaPhi_diHSCP_Gen,gParticlePt->at(index_FinalState1[j]));
		  }
		  if(gParticlePt->at(index_FinalState1[j]) > 100){
		    h_deltaEta_HSCP2_Gen_pT100_bin3->Fill(deltaEta_HSCP2_Gen);
		    h_deltaPhi_HSCP2_Gen_pT100_bin3->Fill(deltaPhi_HSCP2_Gen);
		    h_deltaR_HSCP2_Gen_pT100_bin3->Fill(deltaR_HSCP2_Gen);
		    h_deltaPhi_diHSCP_Gen_pT100_GenpT_bin3->Fill(deltaPhi_diHSCP_Gen,gParticlePt->at(index_FinalState1[j]));
		  }

		} if(deltaPhi_HSCP1_HSCP2 < 1.6) {

		  h_deltaEta_HSCP2_Gen_bin4->Fill(deltaEta_HSCP2_Gen);
		  h_deltaPhi_HSCP2_Gen_bin4->Fill(deltaPhi_HSCP2_Gen);
		  h_deltaR_HSCP2_Gen_bin4->Fill(deltaR_HSCP2_Gen);
		  h_deltaPhi_diHSCP_Gen_GenpT_bin4->Fill(deltaPhi_diHSCP_Gen,gParticlePt->at(index_FinalState1[j]));

		  if(gParticlePt->at(index_FinalState1[j]) > 5){
		    h_deltaEta_HSCP2_Gen_pT5_bin4->Fill(deltaEta_HSCP2_Gen);
		    h_deltaPhi_HSCP2_Gen_pT5_bin4->Fill(deltaPhi_HSCP2_Gen);
		    h_deltaR_HSCP2_Gen_pT5_bin4->Fill(deltaR_HSCP2_Gen);
		    h_deltaPhi_diHSCP_Gen_pT5_GenpT_bin4->Fill(deltaPhi_diHSCP_Gen,gParticlePt->at(index_FinalState1[j]));
		  }
		  if(gParticlePt->at(index_FinalState1[j]) > 50){
		    h_deltaEta_HSCP2_Gen_pT50_bin4->Fill(deltaEta_HSCP2_Gen);
		    h_deltaPhi_HSCP2_Gen_pT50_bin4->Fill(deltaPhi_HSCP2_Gen);
		    h_deltaR_HSCP2_Gen_pT50_bin4->Fill(deltaR_HSCP2_Gen);
		    h_deltaPhi_diHSCP_Gen_pT50_GenpT_bin4->Fill(deltaPhi_diHSCP_Gen,gParticlePt->at(index_FinalState1[j]));
		  }
		  if(gParticlePt->at(index_FinalState1[j]) > 100){
		    h_deltaEta_HSCP2_Gen_pT100_bin4->Fill(deltaEta_HSCP2_Gen);
		    h_deltaPhi_HSCP2_Gen_pT100_bin4->Fill(deltaPhi_HSCP2_Gen);
		    h_deltaR_HSCP2_Gen_pT100_bin4->Fill(deltaR_HSCP2_Gen);
		    h_deltaPhi_diHSCP_Gen_pT100_GenpT_bin4->Fill(deltaPhi_diHSCP_Gen,gParticlePt->at(index_FinalState1[j]));
		  }
		}

	      } // end of loop for non-HSCP gen particles

	     
	    } //end of if statement on checking ID<1000000
	  } //end of loop on non-HSCP gen particles

	  //beginning of loop for jets within gen HSCP loop
	  for(unsigned int j = 0; j < total_NJets; j++){

	  float Jet_pt_  = Jet_pt->at(j);
	  float Jet_eta_ = Jet_eta->at(j);
	  float Jet_phi_ = Jet_phi->at(j);
	  float Jet_mass_ = Jet_mass->at(j);
	  float Jet_energy_ = Jet_energy->at(j);
	  float Jet_chargedEmEnergyFraction_ = Jet_chargedEmEnergyFraction->at(j);
	  float Jet_neutralEmEnergyFraction_ = Jet_neutralEmEnergyFraction->at(j);
	  float Jet_chargedHadronEnergyFraction_ = Jet_chargedHadronEnergyFraction->at(j);
	  float Jet_neutralHadronEnergyFraction_ = Jet_neutralHadronEnergyFraction->at(j);
	  float Jet_muonEnergyFraction_ = Jet_muonEnergyFraction->at(j);
	  float Jet_chargedMultiplicity_ = Jet_chargedMultiplicity->at(j);
	  float Jet_neutralMultiplicity_ = Jet_neutralMultiplicity->at(j);
	  float Jet_jetArea_ = Jet_jetArea->at(j);
	  float Jet_pileupE_ = Jet_pileupE->at(j);

	  bool Jet_passesJetID_ = false;

	  //JetID criteria
	  if(fabs(Jet_eta_)<=2.4) {
	    if(
	       Jet_neutralHadronEnergyFraction_ < 0.9 &&
	       Jet_neutralEmEnergyFraction_ < 0.9 &&
	       Jet_chargedHadronEnergyFraction_ > 0 &&
	       Jet_chargedEmEnergyFraction_ < 0.8 &&
	       Jet_muonEnergyFraction_ < 0.8 &&
	       Jet_chargedMultiplicity_ > 0 &&
	       Jet_chargedMultiplicity_ + Jet_neutralMultiplicity_ > 1
	       ){
	      Jet_passesJetID_ = true;
	    }
	  } if(fabs(Jet_eta_)>2.4 && fabs(Jet_eta_)<=2.7) {
	    if(
	       Jet_neutralHadronEnergyFraction_ < 0.9 &&
	       Jet_neutralEmEnergyFraction_ < 0.99
	       ){
	      Jet_passesJetID_ = true;
	    }
	  } if(fabs(Jet_eta_)>2.7 && fabs(Jet_eta_)<=3.0) {
	    if(
	       Jet_neutralHadronEnergyFraction_ < 0.9 &&
	       Jet_neutralEmEnergyFraction_ > 0. &&
	       Jet_neutralEmEnergyFraction_ < 0.99 &&
	       Jet_neutralMultiplicity_ > 1
	       ){
	      Jet_passesJetID_ = true;
	    }
	  } if(fabs(Jet_eta_)>3.0 && fabs(Jet_eta_)<=5.0) {
	    if(
	       Jet_neutralHadronEnergyFraction_ > 0.2 &&
	       Jet_neutralEmEnergyFraction_ < 0.9 &&
	       Jet_neutralMultiplicity_ > 10
	       ){
	      Jet_passesJetID_ = true;
	    }
	  }


	  ////jetspassingjetID
	  if(Jet_passesJetID_) {

	  
	  float deltaEta_HSCP_Jet = HSCP_eta_ - Jet_eta_;
	  float deltaPhi_HSCP_Jet = fabs(RazorAnalyzer::deltaPhi(HSCP_phi_, Jet_phi_));
	  float deltaR_HSCP_Jet = sqrt(pow(deltaEta_HSCP_Jet, 2) + pow(deltaPhi_HSCP_Jet, 2));


	  ////loop on muons
	  for(unsigned int m = 0; m < muonPt->size(); m++){

	    ////condition on muon ID

	    //if(muonIsLoose->at(m)==true) {
	    //if(muonIsMedium->at(m)==true) {
	    if(muonIsTight->at(m)==true) {
	      float Muon_pt_ = muonPt->at(m);
	      float Muon_eta_ = muonEta->at(m);
	      float Muon_phi_ = muonPhi->at(m);
	      int Muon_type_ = muonType->at(m);

	      float deltaEta_HSCP_Muon = HSCP_eta_ - Muon_eta_;
	      float deltaPhi_HSCP_Muon = fabs(RazorAnalyzer::deltaPhi(HSCP_phi_, Muon_phi_));
	      float deltaR_HSCP_Muon = sqrt(pow(deltaEta_HSCP_Muon,2) + pow(deltaPhi_HSCP_Muon,2));

	      float deltaEta_Jet_Muon = Jet_eta_ - Muon_eta_;
	      float deltaPhi_Jet_Muon = fabs(RazorAnalyzer::deltaPhi(Jet_phi_, Muon_phi_));
	      float deltaR_Jet_Muon = sqrt(pow(deltaEta_Jet_Muon,2) + pow(deltaPhi_Jet_Muon,2));

	    //all match
	      if((deltaR_HSCP_Jet < 0.1) && (deltaR_HSCP_Muon < 0.1) && (deltaR_Jet_Muon < 0.1) ){
		h_jetPt_muonPt_allmatched->Fill(Jet_pt_,Muon_pt_);
		h_jetPt_genhscpPt_allmatched->Fill(Jet_pt_,HSCP_pt_);
		h_muonPt_genhscpPt_allmatched->Fill(Muon_pt_,HSCP_pt_);
		h_jetPt_allmatched->Fill(Jet_pt_);
		h_muonPt_allmatched->Fill(Muon_pt_);
		h_genhscpPt_allmatched->Fill(HSCP_pt_);
	      } 

	      //muon match genHSCP
	      if(deltaR_HSCP_Muon < 0.1) {
		h_muonPt_matched->Fill(Muon_pt_);
		h_muonEta_matched->Fill(Muon_eta_);
		h_muonPhi_matched->Fill(Muon_phi_);
		h_muonType_matched->Fill(Muon_type_);
	      }
	    }

	  }
	  
	  //jet match genHSCP
	  if(deltaR_HSCP_Jet < 0.1) {
	    total_NMatches_lessthan01++;
	    //Pt,eta,phi,mass,energy fractions,multiplicities,jetarea,pileupE
	    h_jetPt_matched->Fill(Jet_pt_);
	    h_jetEta_matched->Fill(Jet_eta_);
	    h_jetPhi_matched->Fill(Jet_phi_);
	    h_jetMass_matched->Fill(Jet_mass_);
	    h_jetEnergy_matched->Fill(Jet_energy_);
	    h_jetChargedEmEnergyFraction_matched->Fill(Jet_chargedEmEnergyFraction_);
	    h_jetNeutralEmEnergyFraction_matched->Fill(Jet_neutralEmEnergyFraction_);
	    h_jetChargedHadronEnergyFraction_matched->Fill(Jet_chargedHadronEnergyFraction_);
	    h_jetNeutralHadronEnergyFraction_matched->Fill(Jet_neutralHadronEnergyFraction_);
	    if(HSCP_charge_ == 0) h_jetNeutralHadronEnergyFraction_matched_GenHSCPCharge0->Fill(Jet_neutralHadronEnergyFraction_);
	    if(HSCP_charge_ != 0) h_jetNeutralHadronEnergyFraction_matched_GenHSCPChargeNon0->Fill(Jet_neutralHadronEnergyFraction_);
	    h_jetChargedEnergyFraction_matched->Fill(Jet_chargedEmEnergyFraction_ + Jet_chargedHadronEnergyFraction_);
	    h_jetNeutralEnergyFraction_matched->Fill(Jet_neutralEmEnergyFraction_ + Jet_neutralHadronEnergyFraction_);
	    h_jetMuonEnergyFraction_matched->Fill(Jet_muonEnergyFraction_);
	    if(HSCP_charge_ == 0) h_jetMuonEnergyFraction_matched_GenHSCPCharge0->Fill(Jet_muonEnergyFraction_);
	    if(HSCP_charge_ == 1 || HSCP_charge_ == -1) h_jetMuonEnergyFraction_matched_GenHSCPCharge1->Fill(Jet_muonEnergyFraction_);
	    if(HSCP_charge_ == 2 || HSCP_charge_ == -2) h_jetMuonEnergyFraction_matched_GenHSCPCharge2->Fill(Jet_muonEnergyFraction_);

	    h_jetChargedMultiplicity_matched->Fill(Jet_chargedMultiplicity_);
	    h_jetNeutralMultiplicity_matched->Fill(Jet_neutralMultiplicity_);
	    h_jetJetArea_matched->Fill(Jet_jetArea_);
	    h_jetPileupE_matched->Fill(Jet_pileupE_);
	    
	  } /*if(deltaR_HSCP_Jet > 0.1) {
	    //for now don't fill this
	    h_jetPt_unmatched->Fill(Jet_pt_);
	    h_jetEta_unmatched->Fill(Jet_eta_);
	    h_jetPhi_unmatched->Fill(Jet_phi_);
	    h_jetMass_unmatched->Fill(Jet_mass_);
	    h_jetEnergy_unmatched->Fill(Jet_energy_);
	    h_jetChargedEmEnergyFraction_unmatched->Fill(Jet_chargedEmEnergyFraction_);
	    h_jetNeutralEmEnergyFraction_unmatched->Fill(Jet_neutralEmEnergyFraction_);
	    h_jetChargedHadronEnergyFraction_unmatched->Fill(Jet_chargedHadronEnergyFraction_);
	    h_jetNeutralHadronEnergyFraction_unmatched->Fill(Jet_neutralHadronEnergyFraction_);
	    h_jetMuonEnergyFraction_unmatched->Fill(Jet_muonEnergyFraction_);
	    h_jetChargedMultiplicity_unmatched->Fill(Jet_chargedMultiplicity_);
	    h_jetNeutralMultiplicity_unmatched->Fill(Jet_neutralMultiplicity_);
	    h_jetJetArea->Fill(Jet_jetArea_);
	    h_jetPileupE_unmatched->Fill(Jet_pileupE_);
	  }*/


	  h_deltaR_HSCP_Jet->Fill(deltaR_HSCP_Jet); //to fill all deltaR
	  
	  if(deltaR_HSCP_Jet < best_matched_deltaR_value) {
	    best_matched_deltaR_value = deltaR_HSCP_Jet; //save best deltaR
	  }
	  

	  ////jetspassingjetID
	  }

	} //end of loop for jets
	
	if(total_NMatches_lessthan01 > 1) {
	  std::cout << "More than 1 jet matched to HSCP with delta R less than 0.1!" << std::endl;
	} 
	
	// if the jet is matched to HSCP, fill jet information
	if(best_matched_deltaR_value < 0.1) {
	  total_NGenHSCPMatched++;
	  //if(HSCP_charge_ == 0) total_NGenHSCPCharge0Matched++;
	  //if(HSCP_charge_ != 0) total_NGenHSCPChargeNon0Matched++;
	  //THIS IS WHERE I WAS    lol looks like I never finished...
	}
	
	h_deltaR_HSCP_Jet_best->Fill(best_matched_deltaR_value); //fill best deltaR
	
	h_genHSCPPt->Fill(HSCP_pt_);
	h_genHSCPEta->Fill(HSCP_eta_);
	h_genHSCPPhi->Fill(HSCP_phi_);
	h_genHSCPBeta->Fill(HSCP_beta_);
	h_genHSCPCharge->Fill(HSCP_charge_);
	
	}	//end of if statement to check for HSCP gParticle_ID greater than a million

      } // end of loop for all final state particles

      h_total_NGenHSCP->Fill(total_NGenHSCP);
      h_total_NGenHSCPMatched->Fill(total_NGenHSCPMatched);
      h_total_NNonHSCPGen1GeV->Fill(total_NNonHSCPGen1GeV);
      h_total_NNonHSCPGen10GeV->Fill(total_NNonHSCPGen10GeV);
      h_total_NNonHSCPGen50GeV->Fill(total_NNonHSCPGen50GeV);
      h_total_NNonHSCPGen100GeV->Fill(total_NNonHSCPGen100GeV);
      h_total_NJets->Fill(total_NJets);
      h_total_NJetsMinusMatched->Fill(total_NJets - total_NGenHSCPMatched);
      if(total_NGenHSCP==2 && total_NJets==2) h_total_NGenHSCPMatched_2HSCP_2jet->Fill(total_NGenHSCPMatched);
      if(total_NGenHSCP==2 && total_NJets==1) h_total_NGenHSCPMatched_2HSCP_1jet->Fill(total_NGenHSCPMatched);
      if(total_NGenHSCP==1) h_total_NGenHSCPMatched_1HSCP->Fill(total_NGenHSCPMatched);
      h_genHSCPChargeConfig->Fill(total_GenHSCP_charge_configuration);

      deltaPt_HSCP1_HSCP2 = fabs(HSCP1_pt - HSCP2_pt);
      deltaP_HSCP1_HSCP2 = fabs(HSCP1_p - HSCP2_p);
      deltaEta_HSCP1_HSCP2 = HSCP1_eta - HSCP2_eta;
      deltaPhi_HSCP1_HSCP2 = fabs(RazorAnalyzer::deltaPhi(HSCP1_phi, HSCP2_phi));
      deltaR_HSCP1_HSCP2 = sqrt(pow(deltaEta_HSCP1_HSCP2,2) + pow(deltaPhi_HSCP1_HSCP2,2));

      h_deltaEta_HSCP1_HSCP2->Fill(deltaEta_HSCP1_HSCP2);
      h_deltaPhi_HSCP1_HSCP2->Fill(deltaPhi_HSCP1_HSCP2);
      h_deltaR_HSCP1_HSCP2->Fill(deltaR_HSCP1_HSCP2);

      h_Phi_diHSCP->Fill(diHSCP_phi);
      h_mag_diHSCP->Fill(diHSCP_mag);
      h_Phi_diHSCP_mag->Fill(diHSCP_phi,diHSCP_mag);

      neg_diHSCP_cone0p4_GenPtMag = sqrt(pow((neg_diHSCP_cone0p4_GenPx),2) + pow((neg_diHSCP_cone0p4_GenPy),2));
      h_neg_diHSCP_cone0p4_GenPtMag->Fill(neg_diHSCP_cone0p4_GenPtMag);

      h_diHSCP_L1METHF->Fill(fabs(RazorAnalyzer::deltaPhi(diHSCP_phi,L1METHF_phi)));
      if(diHSCP_mag>100 && L1METHF>100 && L1METHF<2000) h_diHSCP_pT100_L1METHF_pT100_noSat->Fill(fabs(RazorAnalyzer::deltaPhi(diHSCP_phi,L1METHF_phi)));

      if(deltaPhi_HSCP1_HSCP2 >= 3.1) { //bin1
	h_deltaPhi_HSCP1_HSCP2_numEvents->Fill(0.5);
	h_Phi_diHSCP_mag_bin1->Fill(diHSCP_phi,diHSCP_mag);
      }
      if(deltaPhi_HSCP1_HSCP2 >= 2.35 && deltaPhi_HSCP1_HSCP2 < 3.1) { //bin2
	h_deltaPhi_HSCP1_HSCP2_numEvents->Fill(1.5);
	h_Phi_diHSCP_mag_bin2->Fill(diHSCP_phi,diHSCP_mag);
      }
      if(deltaPhi_HSCP1_HSCP2 >= 1.6 && deltaPhi_HSCP1_HSCP2 < 2.35) {//bin3
	h_deltaPhi_HSCP1_HSCP2_numEvents->Fill(2.5);
	h_Phi_diHSCP_mag_bin3->Fill(diHSCP_phi,diHSCP_mag);
      }
      if(deltaPhi_HSCP1_HSCP2 < 1.6) {//bin4
	h_deltaPhi_HSCP1_HSCP2_numEvents->Fill(3.5);
	h_Phi_diHSCP_mag_bin4->Fill(diHSCP_phi,diHSCP_mag);
      }

      deltaPhi_diHSCP_HSCP1 = fabs(RazorAnalyzer::deltaPhi(diHSCP_phi,HSCP1_phi));
      deltaPhi_diHSCP_HSCP2 = fabs(RazorAnalyzer::deltaPhi(diHSCP_phi,HSCP2_phi));
      h_deltaPhi_diHSCP_HSCP->Fill(deltaPhi_diHSCP_HSCP1);
      h_deltaPhi_diHSCP_HSCP->Fill(deltaPhi_diHSCP_HSCP2);

      deltaPhi_RecoCaloMET_diHSCP = fabs(RazorAnalyzer::deltaPhi(RecoCaloMET_phi,diHSCP_phi));
      deltaPhi_RecoCaloMET_HSCP1 = fabs(RazorAnalyzer::deltaPhi(RecoCaloMET_phi,HSCP1_phi));
      deltaPhi_RecoCaloMET_HSCP2 = fabs(RazorAnalyzer::deltaPhi(RecoCaloMET_phi,HSCP2_phi));
      deltaPhi_HLTCaloMET_diHSCP = fabs(RazorAnalyzer::deltaPhi(HLTCaloMET_phi,diHSCP_phi));
      deltaPhi_HLTCaloMET_HSCP1 = fabs(RazorAnalyzer::deltaPhi(HLTCaloMET_phi,HSCP1_phi));
      deltaPhi_HLTCaloMET_HSCP2 = fabs(RazorAnalyzer::deltaPhi(HLTCaloMET_phi,HSCP2_phi));
		
      if(diHSCP_mag>100 && HSCP1_pt>100) h_deltaPhi_diHSCP_pT100_HSCP_pT100->Fill(deltaPhi_diHSCP_HSCP1);
      if(diHSCP_mag>100 && HSCP2_pt>100) h_deltaPhi_diHSCP_pT100_HSCP_pT100->Fill(deltaPhi_diHSCP_HSCP2);


      if(total_NCandPassPres_all > 0 && !HLT_Mu50) {
	
	//no MET trigger requirement

	//before MET filters

	h_RCAM_passPres_noMU_beforeMETFilters->Fill(RecoCaloMET);
	h_RCAM_passPres_noMU_beforeMETFilters_full->Fill(RecoCaloMET);
	
	//cat 1
	if(diHSCP_mag>100 && HLTCaloMET>100 && (deltaPhi_diHSCP_HSCP1>0.3 && deltaPhi_diHSCP_HSCP2>0.3 && deltaPhi_HSCP1_HSCP2>0.3) && (deltaPhi_RecoCaloMET_HSCP1>2.9 || deltaPhi_RecoCaloMET_HSCP2>2.9 || deltaPhi_HLTCaloMET_HSCP1>2.9 || deltaPhi_HLTCaloMET_HSCP2>2.9)) {
	  h_RCAM_passPres_noMU_cat1_beforeMETFilters->Fill(RecoCaloMET);
	  h_RCAM_passPres_noMU_cat1_beforeMETFilters_full->Fill(RecoCaloMET);
	}
	//cat 2
	if(diHSCP_mag>100 && HLTCaloMET>100 && (deltaPhi_diHSCP_HSCP1>0.3 && deltaPhi_diHSCP_HSCP2>0.3 && deltaPhi_HSCP1_HSCP2>0.3) && (deltaPhi_RecoCaloMET_HSCP1<2.9 && deltaPhi_RecoCaloMET_HSCP2<2.9 && deltaPhi_HLTCaloMET_HSCP1<2.9 && deltaPhi_HLTCaloMET_HSCP2<2.9)) {
	  h_RCAM_passPres_noMU_cat2_beforeMETFilters->Fill(RecoCaloMET);
	}

	//after MET filters
	if(Flag_allMETFilters==true) {
	    
	  h_RCAM_passPres_noMU_afterMETFilters->Fill(RecoCaloMET);
	  h_RCAM_passPres_noMU_afterMETFilters_full->Fill(RecoCaloMET);
	  
	  //and including final quality cut
	  if(fabs(HLTCaloMET - RecoCaloMET)<300) {
	    
	    h_RCAM_passPres_noMU_afterMETFilters_quality->Fill(RecoCaloMET);
	    h_RCAM_passPres_noMU_afterMETFilters_quality_full->Fill(RecoCaloMET);	      
	    if(L1METHF<2000) {
	      h_RCAM_passPres_noMU_afterMETFilters_quality_noSat->Fill(RecoCaloMET);
	    }

	  }

	  //cat 1
	  if(diHSCP_mag>100 && HLTCaloMET>100 && (deltaPhi_diHSCP_HSCP1>0.3 && deltaPhi_diHSCP_HSCP2>0.3 && deltaPhi_HSCP1_HSCP2>0.3) && (deltaPhi_RecoCaloMET_HSCP1>2.9 || deltaPhi_RecoCaloMET_HSCP2>2.9 || deltaPhi_HLTCaloMET_HSCP1>2.9 || deltaPhi_HLTCaloMET_HSCP2>2.9)) {
	    h_RCAM_passPres_noMU_cat1_afterMETFilters->Fill(RecoCaloMET);
	    h_RCAM_passPres_noMU_cat1_afterMETFilters_full->Fill(RecoCaloMET);
	  }
	  //cat 2
	  if(diHSCP_mag>100 && HLTCaloMET>100 && (deltaPhi_diHSCP_HSCP1>0.3 && deltaPhi_diHSCP_HSCP2>0.3 && deltaPhi_HSCP1_HSCP2>0.3) && (deltaPhi_RecoCaloMET_HSCP1<2.9 && deltaPhi_RecoCaloMET_HSCP2<2.9 && deltaPhi_HLTCaloMET_HSCP1<2.9 && deltaPhi_HLTCaloMET_HSCP2<2.9)) {
	    h_RCAM_passPres_noMU_cat2_afterMETFilters->Fill(RecoCaloMET);
	  }	  
	}

	//passing MET trigger 1
	if(HLT_PFMET120_PFMHT120_IDTight) {

	  //before MET filters

	  //cat 1
	  if(diHSCP_mag>100 && HLTCaloMET>100 && (deltaPhi_diHSCP_HSCP1>0.3 && deltaPhi_diHSCP_HSCP2>0.3 && deltaPhi_HSCP1_HSCP2>0.3) && (deltaPhi_RecoCaloMET_HSCP1>2.9 || deltaPhi_RecoCaloMET_HSCP2>2.9 || deltaPhi_HLTCaloMET_HSCP1>2.9 || deltaPhi_HLTCaloMET_HSCP2>2.9)) {
	    h_RCAM_passPres_noMU_cat1_beforeMETFilters_passMET1->Fill(RecoCaloMET);
	    h_RCAM_passPres_noMU_cat1_beforeMETFilters_passMET1_full->Fill(RecoCaloMET);
	  }

	  //cat 2
	  if(diHSCP_mag>100 && HLTCaloMET>100 && (deltaPhi_diHSCP_HSCP1>0.3 && deltaPhi_diHSCP_HSCP2>0.3 && deltaPhi_HSCP1_HSCP2>0.3) && (deltaPhi_RecoCaloMET_HSCP1<2.9 && deltaPhi_RecoCaloMET_HSCP2<2.9 && deltaPhi_HLTCaloMET_HSCP1<2.9 && deltaPhi_HLTCaloMET_HSCP2<2.9)) {
	    h_RCAM_passPres_noMU_cat2_beforeMETFilters_passMET1->Fill(RecoCaloMET);
	  }

	  //after MET filters
	  if(Flag_allMETFilters==true) {
	
	    //cat 1
	    if(diHSCP_mag>100 && HLTCaloMET>100 && (deltaPhi_diHSCP_HSCP1>0.3 && deltaPhi_diHSCP_HSCP2>0.3 && deltaPhi_HSCP1_HSCP2>0.3) && (deltaPhi_RecoCaloMET_HSCP1>2.9 || deltaPhi_RecoCaloMET_HSCP2>2.9 || deltaPhi_HLTCaloMET_HSCP1>2.9 || deltaPhi_HLTCaloMET_HSCP2>2.9)) {
	      h_RCAM_passPres_noMU_cat1_afterMETFilters_passMET1->Fill(RecoCaloMET);
	      h_RCAM_passPres_noMU_cat1_afterMETFilters_passMET1_full->Fill(RecoCaloMET);
	    }
	    //cat 2
	    if(diHSCP_mag>100 && HLTCaloMET>100 && (deltaPhi_diHSCP_HSCP1>0.3 && deltaPhi_diHSCP_HSCP2>0.3 && deltaPhi_HSCP1_HSCP2>0.3) && (deltaPhi_RecoCaloMET_HSCP1<2.9 && deltaPhi_RecoCaloMET_HSCP2<2.9 && deltaPhi_HLTCaloMET_HSCP1<2.9 && deltaPhi_HLTCaloMET_HSCP2<2.9)) {
	      h_RCAM_passPres_noMU_cat2_afterMETFilters_passMET1->Fill(RecoCaloMET);
	    }	  
	  }
	}

	//passing OR of 4 MET triggers
	if(HLT_PFMET120_PFMHT120_IDTight || HLT_PFHT500_PFMET100_PFMHT100_IDTight || HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 || HLT_MET105_IsoTrk50) {

	  //before MET filters
	  h_RCAM_passPres_noMU_beforeMETFilters_passMET1234->Fill(RecoCaloMET);
	  h_RCAM_passPres_noMU_beforeMETFilters_passMET1234_full->Fill(RecoCaloMET);

	  //cat 1
	  if(diHSCP_mag>100 && HLTCaloMET>100 && (deltaPhi_diHSCP_HSCP1>0.3 && deltaPhi_diHSCP_HSCP2>0.3 && deltaPhi_HSCP1_HSCP2>0.3) && (deltaPhi_RecoCaloMET_HSCP1>2.9 || deltaPhi_RecoCaloMET_HSCP2>2.9 || deltaPhi_HLTCaloMET_HSCP1>2.9 || deltaPhi_HLTCaloMET_HSCP2>2.9)) {
	    h_RCAM_passPres_noMU_cat1_beforeMETFilters_passMET1234->Fill(RecoCaloMET);
	    h_RCAM_passPres_noMU_cat1_beforeMETFilters_passMET1234_full->Fill(RecoCaloMET);
	  }
	  //cat 2
	  if(diHSCP_mag>100 && HLTCaloMET>100 && (deltaPhi_diHSCP_HSCP1>0.3 && deltaPhi_diHSCP_HSCP2>0.3 && deltaPhi_HSCP1_HSCP2>0.3) && (deltaPhi_RecoCaloMET_HSCP1<2.9 && deltaPhi_RecoCaloMET_HSCP2<2.9 && deltaPhi_HLTCaloMET_HSCP1<2.9 && deltaPhi_HLTCaloMET_HSCP2<2.9)) {
	    h_RCAM_passPres_noMU_cat2_beforeMETFilters_passMET1234->Fill(RecoCaloMET);
	  }


	  //after MET filters
	  if(Flag_allMETFilters==true) {
	    
	    h_RCAM_passPres_noMU_afterMETFilters_passMET1234->Fill(RecoCaloMET);
	    h_RCAM_passPres_noMU_afterMETFilters_passMET1234_full->Fill(RecoCaloMET);

	    //and including final quality cut
	    if(fabs(HLTCaloMET - RecoCaloMET)<300) {

	    h_RCAM_passPres_noMU_afterMETFilters_quality_passMET1234->Fill(RecoCaloMET);
	    h_RCAM_passPres_noMU_afterMETFilters_quality_passMET1234_full->Fill(RecoCaloMET);	      
	    if(L1METHF<2000) {
	      h_RCAM_passPres_noMU_afterMETFilters_quality_noSat_passMET1234->Fill(RecoCaloMET);
	    }

	    }
	
	    //cat 1
	    if(diHSCP_mag>100 && HLTCaloMET>100 && (deltaPhi_diHSCP_HSCP1>0.3 && deltaPhi_diHSCP_HSCP2>0.3 && deltaPhi_HSCP1_HSCP2>0.3) && (deltaPhi_RecoCaloMET_HSCP1>2.9 || deltaPhi_RecoCaloMET_HSCP2>2.9 || deltaPhi_HLTCaloMET_HSCP1>2.9 || deltaPhi_HLTCaloMET_HSCP2>2.9)) {
	      h_RCAM_passPres_noMU_cat1_afterMETFilters_passMET1234->Fill(RecoCaloMET);
	      h_RCAM_passPres_noMU_cat1_afterMETFilters_passMET1234_full->Fill(RecoCaloMET);
	    }

	    //cat 2
	    if(diHSCP_mag>100 && HLTCaloMET>100 && (deltaPhi_diHSCP_HSCP1>0.3 && deltaPhi_diHSCP_HSCP2>0.3 && deltaPhi_HSCP1_HSCP2>0.3) && (deltaPhi_RecoCaloMET_HSCP1<2.9 && deltaPhi_RecoCaloMET_HSCP2<2.9 && deltaPhi_HLTCaloMET_HSCP1<2.9 && deltaPhi_HLTCaloMET_HSCP2<2.9)) {
	      h_RCAM_passPres_noMU_cat2_afterMETFilters_passMET1234->Fill(RecoCaloMET);
	    }	  
	  }
	}
      }
      
      tree->genHSCPChargeConfig = total_GenHSCP_charge_configuration;
      tree->HSCP1_Eta = HSCP1_eta;
      tree->HSCP1_Phi = HSCP1_phi;
      tree->HSCP1_Charge = HSCP1_charge;
      tree->HSCP1_Beta = HSCP1_beta;
      tree->HSCP1_Pt = HSCP1_pt;
      tree->HSCP2_Eta = HSCP2_eta;
      tree->HSCP2_Phi = HSCP2_phi;
      tree->HSCP2_Charge = HSCP2_charge;
      tree->HSCP2_Beta = HSCP2_beta;
      tree->HSCP2_Pt = HSCP2_pt;

      tree->NNonHSCPGen1GeV = total_NNonHSCPGen1GeV;
      tree->NNonHSCPGen10GeV = total_NNonHSCPGen10GeV;
      tree->NNonHSCPGen50GeV = total_NNonHSCPGen50GeV;
      tree->NNonHSCPGen100GeV = total_NNonHSCPGen100GeV;
      tree->GenPtMag_dPhi0p4_neg_diHSCP = neg_diHSCP_cone0p4_GenPtMag;
      tree->diHSCP_pT_mag = diHSCP_mag;
      tree->diHSCP_pT_phi = diHSCP_phi;
      tree->dPhi_HSCP1_HSCP2 = deltaPhi_HSCP1_HSCP2;
      tree->dPt_HSCP1_HSCP2 = deltaPt_HSCP1_HSCP2;
      tree->dP_HSCP1_HSCP2 = deltaP_HSCP1_HSCP2;
      tree->dPhi_diHSCP_HSCP1 = deltaPhi_diHSCP_HSCP1;
      tree->dPhi_diHSCP_HSCP2 = deltaPhi_diHSCP_HSCP2;
      tree->dPhi_RecoCaloMET_diHSCP = deltaPhi_RecoCaloMET_diHSCP;
      tree->dPhi_RecoCaloMET_HSCP1 = deltaPhi_RecoCaloMET_HSCP1;
      tree->dPhi_RecoCaloMET_HSCP2 = deltaPhi_RecoCaloMET_HSCP2;
      tree->dPhi_HLTCaloMET_diHSCP = deltaPhi_HLTCaloMET_diHSCP;
      tree->dPhi_HLTCaloMET_HSCP1 = deltaPhi_HLTCaloMET_HSCP1;
      tree->dPhi_HLTCaloMET_HSCP2 = deltaPhi_HLTCaloMET_HSCP2;

      
      if(HLTCaloMET<HLTCaloMETClean+1300) {
	CaloMETClean_same = true;
      }
      tree->bool_CaloMETClean_same = CaloMETClean_same;

      //}//this should be for the everything not passing muon trigger && L1 MET not saturated
      
      //fill nTuples tree here
      tree->tree_->Fill();
           
  }// end of jentry loop

  
  if (!isData) {
    cout << "Filled Total of " << NEvents->GetBinContent(1) << " Events\n";
    cout << "Writing output trees..." << endl;
    outFile->cd();
    tree->tree_->Write();

    NEvents->Write();
    h_preselection_cutflow_candidates->Write();
    h_preselection_cutflow_events_1cand->Write();
    h_preselection_cutflow_events_2cand->Write();
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
    h_twoCand_dPhi_HSCP_RecoCaloMET_HSCPPFMETdPhiPi->Write();
    h_twoCand_dPhi_HSCP_RecoCaloMET_HSCPPFMETdPhiZero->Write();
    h_twoCand_dPhi_RecoPFMET_RecoCaloMET_HSCPPFMETdPhiPi->Write();
    h_twoCand_dPhi_RecoPFMET_RecoCaloMET_HSCPPFMETdPhiZero->Write();
    h_twoCand_dPhi_HSCP_RecoPFMET_vs_RecoPFMET->Write();
    h_twoCand_dPhi_HSCP_RecoPFMET_vs_RecoCaloMET->Write();
    h_twoCand_dPhi_HSCP_RecoCaloMET_vs_RecoPFMET->Write();
    h_twoCand_dPhi_HSCP_RecoCaloMET_vs_RecoCaloMET->Write();
    h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET->Write();
    h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pt0to500->Write();
    h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pt500to1000->Write();
    h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pt1000to->Write();
    h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet0to100->Write();
    h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet100to500->Write();
    h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet500to->Write();
    h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet0to100->Write();
    h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet100to500->Write();
    h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet500to->Write();  
    h_deltaR_HSCP_Jet->Write();
    h_deltaR_HSCP_Jet_best->Write();
    h_genHSCPPt->Write();
    h_genHSCPEta->Write();
    h_genHSCPPhi->Write();
    h_genHSCPBeta->Write();
    h_genHSCPCharge->Write();
    h_genHSCPChargeConfig->Write();
    h_total_NGenHSCP->Write();
    h_total_NGenHSCPMatched->Write();
    h_total_NNonHSCPGen1GeV->Write();
    h_total_NNonHSCPGen10GeV->Write();
    h_total_NNonHSCPGen50GeV->Write(); 
    h_total_NNonHSCPGen100GeV->Write();
    h_Eta_HSCP1->Write();
    h_Eta_HSCP2->Write();
    h_Eta_Gen->Write();
    h_Eta_Gen_pT5->Write();
    h_Eta_Gen_pT50->Write();
    h_Eta_Gen_pT100->Write();
    h_Phi_HSCP1->Write();
    h_Phi_HSCP2->Write();
    h_Phi_diHSCP->Write();
    h_mag_diHSCP->Write();
    h_Phi_diHSCP_mag->Write();
    h_Phi_diHSCP_mag_bin1->Write();
    h_Phi_diHSCP_mag_bin2->Write();
    h_Phi_diHSCP_mag_bin3->Write();
    h_Phi_diHSCP_mag_bin4->Write();
    h_Phi_Gen->Write();
    h_deltaEta_HSCP1_HSCP2->Write();
    h_deltaPhi_HSCP1_HSCP2->Write();
    h_deltaR_HSCP1_HSCP2->Write();
    h_deltaPhi_HSCP1_HSCP2_numEvents->Write();
    h_deltaEta_HSCP1_Gen->Write();
    h_deltaPhi_HSCP1_Gen->Write();
    h_deltaR_HSCP1_Gen->Write();
    h_deltaEta_HSCP1_Gen_pT5->Write();
    h_deltaPhi_HSCP1_Gen_pT5->Write();
    h_deltaR_HSCP1_Gen_pT5->Write();
    h_deltaEta_HSCP1_Gen_pT50->Write();
    h_deltaPhi_HSCP1_Gen_pT50->Write();
    h_deltaR_HSCP1_Gen_pT50->Write();
    h_deltaEta_HSCP1_Gen_pT100->Write();
    h_deltaPhi_HSCP1_Gen_pT100->Write();
    h_deltaR_HSCP1_Gen_pT100->Write();
    h_deltaEta_HSCP1_Gen_bin1->Write();
    h_deltaPhi_HSCP1_Gen_bin1->Write();
    h_deltaR_HSCP1_Gen_bin1->Write();
    h_deltaEta_HSCP1_Gen_pT5_bin1->Write();
    h_deltaPhi_HSCP1_Gen_pT5_bin1->Write();
    h_deltaR_HSCP1_Gen_pT5_bin1->Write();
    h_deltaEta_HSCP1_Gen_pT50_bin1->Write();
    h_deltaPhi_HSCP1_Gen_pT50_bin1->Write();
    h_deltaR_HSCP1_Gen_pT50_bin1->Write();
    h_deltaEta_HSCP1_Gen_pT100_bin1->Write();
    h_deltaPhi_HSCP1_Gen_pT100_bin1->Write();
    h_deltaR_HSCP1_Gen_pT100_bin1->Write();
    h_deltaEta_HSCP2_Gen->Write();
    h_deltaPhi_HSCP2_Gen->Write();
    h_deltaR_HSCP2_Gen->Write();
    h_deltaEta_HSCP2_Gen_pT5->Write();
    h_deltaPhi_HSCP2_Gen_pT5->Write();
    h_deltaR_HSCP2_Gen_pT5->Write();
    h_deltaEta_HSCP2_Gen_pT50->Write();
    h_deltaPhi_HSCP2_Gen_pT50->Write();
    h_deltaR_HSCP2_Gen_pT50->Write();
    h_deltaEta_HSCP2_Gen_pT100->Write();
    h_deltaPhi_HSCP2_Gen_pT100->Write();
    h_deltaR_HSCP2_Gen_pT100->Write();
    h_deltaEta_HSCP2_Gen_bin1->Write();
    h_deltaPhi_HSCP2_Gen_bin1->Write();
    h_deltaR_HSCP2_Gen_bin1->Write();
    h_deltaEta_HSCP2_Gen_pT5_bin1->Write();
    h_deltaPhi_HSCP2_Gen_pT5_bin1->Write();
    h_deltaR_HSCP2_Gen_pT5_bin1->Write();
    h_deltaEta_HSCP2_Gen_pT50_bin1->Write();
    h_deltaPhi_HSCP2_Gen_pT50_bin1->Write();
    h_deltaR_HSCP2_Gen_pT50_bin1->Write();
    h_deltaEta_HSCP2_Gen_pT100_bin1->Write();
    h_deltaPhi_HSCP2_Gen_pT100_bin1->Write();
    h_deltaR_HSCP2_Gen_pT100_bin1->Write();
    h_deltaEta_HSCP2_Gen_bin2->Write();
    h_deltaPhi_HSCP2_Gen_bin2->Write();
    h_deltaR_HSCP2_Gen_bin2->Write();
    h_deltaEta_HSCP2_Gen_pT5_bin2->Write();
    h_deltaPhi_HSCP2_Gen_pT5_bin2->Write();
    h_deltaR_HSCP2_Gen_pT5_bin2->Write();
    h_deltaEta_HSCP2_Gen_pT50_bin2->Write();
    h_deltaPhi_HSCP2_Gen_pT50_bin2->Write();
    h_deltaR_HSCP2_Gen_pT50_bin2->Write();
    h_deltaEta_HSCP2_Gen_pT100_bin2->Write();
    h_deltaPhi_HSCP2_Gen_pT100_bin2->Write();
    h_deltaR_HSCP2_Gen_pT100_bin2->Write();
    h_deltaEta_HSCP2_Gen_bin3->Write();
    h_deltaPhi_HSCP2_Gen_bin3->Write();
    h_deltaR_HSCP2_Gen_bin3->Write();
    h_deltaEta_HSCP2_Gen_pT5_bin3->Write();
    h_deltaPhi_HSCP2_Gen_pT5_bin3->Write();
    h_deltaR_HSCP2_Gen_pT5_bin3->Write();
    h_deltaEta_HSCP2_Gen_pT50_bin3->Write();
    h_deltaPhi_HSCP2_Gen_pT50_bin3->Write();
    h_deltaR_HSCP2_Gen_pT50_bin3->Write();
    h_deltaEta_HSCP2_Gen_pT100_bin3->Write();
    h_deltaPhi_HSCP2_Gen_pT100_bin3->Write();
    h_deltaR_HSCP2_Gen_pT100_bin3->Write();
    h_deltaEta_HSCP2_Gen_bin4->Write();
    h_deltaPhi_HSCP2_Gen_bin4->Write();
    h_deltaR_HSCP2_Gen_bin4->Write();
    h_deltaEta_HSCP2_Gen_pT5_bin4->Write();
    h_deltaPhi_HSCP2_Gen_pT5_bin4->Write();
    h_deltaR_HSCP2_Gen_pT5_bin4->Write();
    h_deltaEta_HSCP2_Gen_pT50_bin4->Write();
    h_deltaPhi_HSCP2_Gen_pT50_bin4->Write();
    h_deltaR_HSCP2_Gen_pT50_bin4->Write();
    h_deltaEta_HSCP2_Gen_pT100_bin4->Write();
    h_deltaPhi_HSCP2_Gen_pT100_bin4->Write();
    h_deltaR_HSCP2_Gen_pT100_bin4->Write();
    h_deltaPhi_diHSCP_Gen->Write();
    h_deltaPhi_diHSCP_Gen_pT5->Write();
    h_deltaPhi_diHSCP_Gen_pT50->Write();
    h_deltaPhi_diHSCP_Gen_pT100->Write();
    h_deltaPhi_diHSCP_Gen_GenpT->Write();
    h_deltaPhi_diHSCP_Gen_pT5_GenpT->Write();
    h_deltaPhi_diHSCP_Gen_pT50_GenpT->Write();
    h_deltaPhi_diHSCP_Gen_pT100_GenpT->Write();
    h_deltaPhi_diHSCP_Gen_GenpT_bin1->Write();
    h_deltaPhi_diHSCP_Gen_pT5_GenpT_bin1->Write();
    h_deltaPhi_diHSCP_Gen_pT50_GenpT_bin1->Write();
    h_deltaPhi_diHSCP_Gen_pT100_GenpT_bin1->Write();
    h_deltaPhi_diHSCP_Gen_GenpT_bin2->Write();
    h_deltaPhi_diHSCP_Gen_pT5_GenpT_bin2->Write();
    h_deltaPhi_diHSCP_Gen_pT50_GenpT_bin2->Write();
    h_deltaPhi_diHSCP_Gen_pT100_GenpT_bin2->Write();
    h_deltaPhi_diHSCP_Gen_GenpT_bin3->Write();
    h_deltaPhi_diHSCP_Gen_pT5_GenpT_bin3->Write();
    h_deltaPhi_diHSCP_Gen_pT50_GenpT_bin3->Write();
    h_deltaPhi_diHSCP_Gen_pT100_GenpT_bin3->Write();
    h_deltaPhi_diHSCP_Gen_GenpT_bin4->Write();
    h_deltaPhi_diHSCP_Gen_pT5_GenpT_bin4->Write();
    h_deltaPhi_diHSCP_Gen_pT50_GenpT_bin4->Write();
    h_deltaPhi_diHSCP_Gen_pT100_GenpT_bin4->Write();
    h_deltaPhi_neg_diHSCP_Gen->Write();
    h_deltaPhi_neg_diHSCP_Gen_pT5->Write();
    h_deltaPhi_neg_diHSCP_Gen_pT50->Write();
    h_deltaPhi_neg_diHSCP_Gen_pT100->Write();
    h_deltaPhi_neg_diHSCP_pT100_Gen->Write();
    h_deltaPhi_neg_diHSCP_pT100_Gen_pT5->Write();
    h_deltaPhi_neg_diHSCP_pT100_Gen_pT50->Write();
    h_deltaPhi_neg_diHSCP_pT100_Gen_pT100->Write();
    h_neg_diHSCP_cone0p4_GenPtMag->Write();
    h_diHSCP_L1METHF->Write();
    h_diHSCP_pT100_L1METHF_pT100_noSat->Write();
    h_deltaPhi_diHSCP_HSCP->Write();
    h_deltaPhi_diHSCP_pT100_HSCP_pT100->Write();
    h_total_NJets->Write();
    h_total_NJetsMinusMatched->Write();
    h_total_NGenHSCPMatched_2HSCP_2jet->Write();
    h_total_NGenHSCPMatched_2HSCP_1jet->Write();
    h_total_NGenHSCPMatched_1HSCP->Write();

    h_jetPt_muonPt_allmatched->Write();
    h_jetPt_genhscpPt_allmatched->Write();
    h_muonPt_genhscpPt_allmatched->Write();
    h_jetPt_allmatched->Write();
    h_muonPt_allmatched->Write();
    h_genhscpPt_allmatched->Write();
    h_muonPt_matched->Write();
    h_muonEta_matched->Write();
    h_muonPhi_matched->Write();
    h_muonType_matched->Write();
    h_jetPt_matched->Write();
    h_jetEta_matched->Write();
    h_jetPhi_matched->Write();
    h_jetMass_matched->Write();
    h_jetEnergy_matched->Write();
    h_jetChargedEmEnergyFraction_matched->Write();
    h_jetNeutralEmEnergyFraction_matched->Write();
    h_jetChargedHadronEnergyFraction_matched->Write();
    h_jetNeutralHadronEnergyFraction_matched->Write();
    h_jetNeutralHadronEnergyFraction_matched_GenHSCPCharge0->Write();
    h_jetNeutralHadronEnergyFraction_matched_GenHSCPChargeNon0->Write();
    h_jetChargedEnergyFraction_matched->Write();
    h_jetNeutralEnergyFraction_matched->Write();
    h_jetMuonEnergyFraction_matched->Write();
    h_jetMuonEnergyFraction_matched_GenHSCPCharge0->Write();
    h_jetMuonEnergyFraction_matched_GenHSCPCharge1->Write();
    h_jetMuonEnergyFraction_matched_GenHSCPCharge2->Write();
    h_jetChargedMultiplicity_matched->Write();
    h_jetNeutralMultiplicity_matched->Write();
    h_jetJetArea_matched->Write();
    h_jetPileupE_matched->Write();

    h_RPFM_all->Write();
    h_RCAM_all->Write();
    h_RPFM_passMuORMET1234->Write();
    h_RCAM_passMuORMET1234->Write();
    h_RPFM_passMET1234->Write();
    h_RCAM_passMET1234->Write();
    h_RPFM_passMu->Write();
    h_RCAM_passMu->Write();
    h_RPFM_passMET1->Write();
    h_RCAM_passMET1->Write();
    h_RPFM_passMET1Cut1->Write();
    h_RCAM_passMET1Cut1->Write();
    h_RPFM_passMET1Cut2->Write();
    h_RCAM_passMET1Cut2->Write();
    h_RPFM_passMET1Cut3->Write();
    h_RCAM_passMET1Cut3->Write();
    h_RPFM_passMET1Cut4->Write();
    h_RCAM_passMET1Cut4->Write();
    h_RPFM_passMET1Cut5->Write();
    h_RCAM_passMET1Cut5->Write();
    h_RPFM_passMET1Cut6->Write();
    h_RCAM_passMET1Cut6->Write();
    
    h_LHFM_passPres_all->Write();
    h_RPFM_passPres_all->Write();
    h_RPFM_passPres_zoomed->Write();
    h_RCAM_passPres_all->Write();
    h_RCAM_passPres_zoomed->Write();
    h_RPFM_LHFM_passPres->Write();
    h_RCAM_LHFM_passPres->Write();
    h_RPFM_RCAM_passPres->Write();
    
    h_RPFM_passPres_noMU->Write();
    h_RCAM_passPres_noMU->Write();
    h_RPFM_passPres_noMU_passMET1234->Write();
    h_RCAM_passPres_noMU_passMET1234->Write();
    h_RPFM_passPres_noMU_passMET1->Write();
    h_RCAM_passPres_noMU_passMET1->Write();
    h_RPFM_passPres_noMU_passMET1Cut1->Write();
    h_RCAM_passPres_noMU_passMET1Cut1->Write();
    h_RPFM_passPres_noMU_passMET1Cut2->Write();
    h_RCAM_passPres_noMU_passMET1Cut2->Write();
    h_RPFM_passPres_noMU_passMET1Cut3->Write();
    h_RCAM_passPres_noMU_passMET1Cut3->Write();
    h_RPFM_passPres_noMU_passMET1Cut4->Write();
    h_RCAM_passPres_noMU_passMET1Cut4->Write();
    h_RPFM_passPres_noMU_passMET1Cut5->Write();
    h_RCAM_passPres_noMU_passMET1Cut5->Write();
    h_RPFM_passPres_noMU_passMET1Cut6->Write();
    h_RCAM_passPres_noMU_passMET1Cut6->Write();

    h_RCAM_passPres_noMU_cat1_beforeMETFilters->Write();
    h_RCAM_passPres_noMU_cat1_beforeMETFilters_passMET1->Write();
    h_RCAM_passPres_noMU_cat1_beforeMETFilters_passMET1234->Write();
    h_RCAM_passPres_noMU_cat1_beforeMETFilters_full->Write();
    h_RCAM_passPres_noMU_cat1_beforeMETFilters_passMET1_full->Write();
    h_RCAM_passPres_noMU_cat1_beforeMETFilters_passMET1234_full->Write();
    h_RCAM_passPres_noMU_cat2_beforeMETFilters->Write();
    h_RCAM_passPres_noMU_cat2_beforeMETFilters_passMET1->Write();
    h_RCAM_passPres_noMU_cat2_beforeMETFilters_passMET1234->Write();
    h_RCAM_passPres_noMU_cat1_afterMETFilters->Write();
    h_RCAM_passPres_noMU_cat1_afterMETFilters_passMET1->Write();
    h_RCAM_passPres_noMU_cat1_afterMETFilters_passMET1234->Write();
    h_RCAM_passPres_noMU_cat1_afterMETFilters_full->Write();
    h_RCAM_passPres_noMU_cat1_afterMETFilters_passMET1_full->Write();
    h_RCAM_passPres_noMU_cat1_afterMETFilters_passMET1234_full->Write();
    h_RCAM_passPres_noMU_cat2_afterMETFilters->Write();
    h_RCAM_passPres_noMU_cat2_afterMETFilters_passMET1->Write();
    h_RCAM_passPres_noMU_cat2_afterMETFilters_passMET1234->Write();
    h_RCAM_passPres_noMU_beforeMETFilters->Write();
    h_RCAM_passPres_noMU_beforeMETFilters_passMET1234->Write();
    h_RCAM_passPres_noMU_beforeMETFilters_full->Write();
    h_RCAM_passPres_noMU_beforeMETFilters_passMET1234_full->Write();
    h_RCAM_passPres_noMU_afterMETFilters->Write();
    h_RCAM_passPres_noMU_afterMETFilters_passMET1234->Write();
    h_RCAM_passPres_noMU_afterMETFilters_full->Write();
    h_RCAM_passPres_noMU_afterMETFilters_passMET1234_full->Write();
    h_RCAM_passPres_noMU_afterMETFilters_quality->Write();
    h_RCAM_passPres_noMU_afterMETFilters_quality_passMET1234->Write();
    h_RCAM_passPres_noMU_afterMETFilters_quality_full->Write();
    h_RCAM_passPres_noMU_afterMETFilters_quality_passMET1234_full->Write();
    h_RCAM_passPres_noMU_afterMETFilters_quality_noSat->Write();
    h_RCAM_passPres_noMU_afterMETFilters_quality_noSat_passMET1234->Write();
    
    h_numEventsCategories_noPres->Write();
    h_numEventsCategories_passPres->Write();
    
    outFile->Close();
    
  } else {
    
    cout << "Filled Total of " << NEvents->GetBinContent(1) << " Events\n";
    cout << "Writing output trees..." << endl;
    outFile->cd();
    tree->tree_->Write();
    
    NEvents->Write();
    h_preselection_cutflow_candidates->Write();
    h_preselection_cutflow_events_1cand->Write();
    h_preselection_cutflow_events_2cand->Write();
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
    h_twoCand_dPhi_HSCP_RecoCaloMET_HSCPPFMETdPhiPi->Write();
    h_twoCand_dPhi_HSCP_RecoCaloMET_HSCPPFMETdPhiZero->Write();
    h_twoCand_dPhi_RecoPFMET_RecoCaloMET_HSCPPFMETdPhiPi->Write();
    h_twoCand_dPhi_RecoPFMET_RecoCaloMET_HSCPPFMETdPhiZero->Write();
    h_twoCand_dPhi_HSCP_RecoPFMET_vs_RecoPFMET->Write();
    h_twoCand_dPhi_HSCP_RecoPFMET_vs_RecoCaloMET->Write();
    h_twoCand_dPhi_HSCP_RecoCaloMET_vs_RecoPFMET->Write();
    h_twoCand_dPhi_HSCP_RecoCaloMET_vs_RecoCaloMET->Write();
    h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET->Write();
    h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pt0to500->Write();
    h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pt500to1000->Write();
    h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pt1000to->Write();
    h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet0to100->Write();
    h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet100to500->Write();
    h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_calomet500to->Write();
    h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet0to100->Write();
    h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet100to500->Write();
    h_twoCand_dPhi_HSCP_RecoCaloMET_vs_dPhi_HSCP_RecoPFMET_pfmet500to->Write();  
    h_deltaR_HSCP_Jet->Write();
    h_deltaR_HSCP_Jet_best->Write();
    h_genHSCPPt->Write();
    h_genHSCPEta->Write();
    h_genHSCPPhi->Write();
    h_genHSCPBeta->Write();
    h_genHSCPCharge->Write();
    h_genHSCPChargeConfig->Write();
    h_total_NGenHSCP->Write();
    h_total_NGenHSCPMatched->Write();
    h_total_NNonHSCPGen1GeV->Write();
    h_total_NNonHSCPGen10GeV->Write();
    h_total_NNonHSCPGen50GeV->Write();
    h_total_NNonHSCPGen100GeV->Write();
    h_Eta_HSCP1->Write();
    h_Eta_HSCP2->Write();
    h_Eta_Gen->Write();
    h_Eta_Gen_pT5->Write();
    h_Eta_Gen_pT50->Write();
    h_Eta_Gen_pT100->Write();
    h_Phi_HSCP1->Write();
    h_Phi_HSCP2->Write();
    h_Phi_diHSCP->Write();
    h_mag_diHSCP->Write();
    h_Phi_diHSCP_mag->Write();
    h_Phi_diHSCP_mag_bin1->Write();
    h_Phi_diHSCP_mag_bin2->Write();
    h_Phi_diHSCP_mag_bin3->Write();
    h_Phi_diHSCP_mag_bin4->Write();
    h_Phi_Gen->Write();
    h_deltaEta_HSCP1_HSCP2->Write();
    h_deltaPhi_HSCP1_HSCP2->Write();
    h_deltaR_HSCP1_HSCP2->Write();
    h_deltaPhi_HSCP1_HSCP2_numEvents->Write();
    h_deltaEta_HSCP1_Gen->Write();
    h_deltaPhi_HSCP1_Gen->Write();
    h_deltaR_HSCP1_Gen->Write();
    h_deltaEta_HSCP1_Gen_pT5->Write();
    h_deltaPhi_HSCP1_Gen_pT5->Write();
    h_deltaR_HSCP1_Gen_pT5->Write();
    h_deltaEta_HSCP1_Gen_pT50->Write();
    h_deltaPhi_HSCP1_Gen_pT50->Write();
    h_deltaR_HSCP1_Gen_pT50->Write();
    h_deltaEta_HSCP1_Gen_pT100->Write();
    h_deltaPhi_HSCP1_Gen_pT100->Write();
    h_deltaR_HSCP1_Gen_pT100->Write();
    h_deltaEta_HSCP1_Gen_bin1->Write();
    h_deltaPhi_HSCP1_Gen_bin1->Write();
    h_deltaR_HSCP1_Gen_bin1->Write();
    h_deltaEta_HSCP1_Gen_pT5_bin1->Write();
    h_deltaPhi_HSCP1_Gen_pT5_bin1->Write();
    h_deltaR_HSCP1_Gen_pT5_bin1->Write();
    h_deltaEta_HSCP1_Gen_pT50_bin1->Write();
    h_deltaPhi_HSCP1_Gen_pT50_bin1->Write();
    h_deltaR_HSCP1_Gen_pT50_bin1->Write();
    h_deltaEta_HSCP1_Gen_pT100_bin1->Write();
    h_deltaPhi_HSCP1_Gen_pT100_bin1->Write();
    h_deltaR_HSCP1_Gen_pT100_bin1->Write();
    h_deltaEta_HSCP2_Gen->Write();
    h_deltaPhi_HSCP2_Gen->Write();
    h_deltaR_HSCP2_Gen->Write();
    h_deltaEta_HSCP2_Gen_pT5->Write();
    h_deltaPhi_HSCP2_Gen_pT5->Write();
    h_deltaR_HSCP2_Gen_pT5->Write();
    h_deltaEta_HSCP2_Gen_pT50->Write();
    h_deltaPhi_HSCP2_Gen_pT50->Write();
    h_deltaR_HSCP2_Gen_pT50->Write();
    h_deltaEta_HSCP2_Gen_pT100->Write();
    h_deltaPhi_HSCP2_Gen_pT100->Write();
    h_deltaR_HSCP2_Gen_pT100->Write();
    h_deltaEta_HSCP2_Gen_bin1->Write();
    h_deltaPhi_HSCP2_Gen_bin1->Write();
    h_deltaR_HSCP2_Gen_bin1->Write();
    h_deltaEta_HSCP2_Gen_pT5_bin1->Write();
    h_deltaPhi_HSCP2_Gen_pT5_bin1->Write();
    h_deltaR_HSCP2_Gen_pT5_bin1->Write();
    h_deltaEta_HSCP2_Gen_pT50_bin1->Write();
    h_deltaPhi_HSCP2_Gen_pT50_bin1->Write();
    h_deltaR_HSCP2_Gen_pT50_bin1->Write();
    h_deltaEta_HSCP2_Gen_pT100_bin1->Write();
    h_deltaPhi_HSCP2_Gen_pT100_bin1->Write();
    h_deltaR_HSCP2_Gen_pT100_bin1->Write();
    h_deltaEta_HSCP2_Gen_bin2->Write();
    h_deltaPhi_HSCP2_Gen_bin2->Write();
    h_deltaR_HSCP2_Gen_bin2->Write();
    h_deltaEta_HSCP2_Gen_pT5_bin2->Write();
    h_deltaPhi_HSCP2_Gen_pT5_bin2->Write();
    h_deltaR_HSCP2_Gen_pT5_bin2->Write();
    h_deltaEta_HSCP2_Gen_pT50_bin2->Write();
    h_deltaPhi_HSCP2_Gen_pT50_bin2->Write();
    h_deltaR_HSCP2_Gen_pT50_bin2->Write();
    h_deltaEta_HSCP2_Gen_pT100_bin2->Write();
    h_deltaPhi_HSCP2_Gen_pT100_bin2->Write();
    h_deltaR_HSCP2_Gen_pT100_bin2->Write();
    h_deltaEta_HSCP2_Gen_bin3->Write();
    h_deltaPhi_HSCP2_Gen_bin3->Write();
    h_deltaR_HSCP2_Gen_bin3->Write();
    h_deltaEta_HSCP2_Gen_pT5_bin3->Write();
    h_deltaPhi_HSCP2_Gen_pT5_bin3->Write();
    h_deltaR_HSCP2_Gen_pT5_bin3->Write();
    h_deltaEta_HSCP2_Gen_pT50_bin3->Write();
    h_deltaPhi_HSCP2_Gen_pT50_bin3->Write();
    h_deltaR_HSCP2_Gen_pT50_bin3->Write();
    h_deltaEta_HSCP2_Gen_pT100_bin3->Write();
    h_deltaPhi_HSCP2_Gen_pT100_bin3->Write();
    h_deltaR_HSCP2_Gen_pT100_bin3->Write();
    h_deltaEta_HSCP2_Gen_bin4->Write();
    h_deltaPhi_HSCP2_Gen_bin4->Write();
    h_deltaR_HSCP2_Gen_bin4->Write();
    h_deltaEta_HSCP2_Gen_pT5_bin4->Write();
    h_deltaPhi_HSCP2_Gen_pT5_bin4->Write();
    h_deltaR_HSCP2_Gen_pT5_bin4->Write();
    h_deltaEta_HSCP2_Gen_pT50_bin4->Write();
    h_deltaPhi_HSCP2_Gen_pT50_bin4->Write();
    h_deltaR_HSCP2_Gen_pT50_bin4->Write();
    h_deltaEta_HSCP2_Gen_pT100_bin4->Write();
    h_deltaPhi_HSCP2_Gen_pT100_bin4->Write();
    h_deltaR_HSCP2_Gen_pT100_bin4->Write();
    h_deltaPhi_diHSCP_Gen->Write();
    h_deltaPhi_diHSCP_Gen_pT5->Write();
    h_deltaPhi_diHSCP_Gen_pT50->Write();
    h_deltaPhi_diHSCP_Gen_pT100->Write();
    h_deltaPhi_diHSCP_Gen_GenpT->Write();
    h_deltaPhi_diHSCP_Gen_pT5_GenpT->Write();
    h_deltaPhi_diHSCP_Gen_pT50_GenpT->Write();
    h_deltaPhi_diHSCP_Gen_pT100_GenpT->Write();
    h_deltaPhi_diHSCP_Gen_GenpT_bin1->Write();
    h_deltaPhi_diHSCP_Gen_pT5_GenpT_bin1->Write();
    h_deltaPhi_diHSCP_Gen_pT50_GenpT_bin1->Write();
    h_deltaPhi_diHSCP_Gen_pT100_GenpT_bin1->Write();
    h_deltaPhi_diHSCP_Gen_GenpT_bin2->Write();
    h_deltaPhi_diHSCP_Gen_pT5_GenpT_bin2->Write();
    h_deltaPhi_diHSCP_Gen_pT50_GenpT_bin2->Write();
    h_deltaPhi_diHSCP_Gen_pT100_GenpT_bin2->Write();
    h_deltaPhi_diHSCP_Gen_GenpT_bin3->Write();
    h_deltaPhi_diHSCP_Gen_pT5_GenpT_bin3->Write();
    h_deltaPhi_diHSCP_Gen_pT50_GenpT_bin3->Write();
    h_deltaPhi_diHSCP_Gen_pT100_GenpT_bin3->Write();
    h_deltaPhi_diHSCP_Gen_GenpT_bin4->Write();
    h_deltaPhi_diHSCP_Gen_pT5_GenpT_bin4->Write();
    h_deltaPhi_diHSCP_Gen_pT50_GenpT_bin4->Write();
    h_deltaPhi_diHSCP_Gen_pT100_GenpT_bin4->Write();
    h_deltaPhi_neg_diHSCP_Gen->Write();
    h_deltaPhi_neg_diHSCP_Gen_pT5->Write();
    h_deltaPhi_neg_diHSCP_Gen_pT50->Write();
    h_deltaPhi_neg_diHSCP_Gen_pT100->Write();
    h_deltaPhi_neg_diHSCP_pT100_Gen->Write();
    h_deltaPhi_neg_diHSCP_pT100_Gen_pT5->Write();
    h_deltaPhi_neg_diHSCP_pT100_Gen_pT50->Write();
    h_deltaPhi_neg_diHSCP_pT100_Gen_pT100->Write();
    h_neg_diHSCP_cone0p4_GenPtMag->Write();
    h_diHSCP_L1METHF->Write();
    h_diHSCP_pT100_L1METHF_pT100_noSat->Write();
    h_deltaPhi_diHSCP_HSCP->Write();
    h_deltaPhi_diHSCP_pT100_HSCP_pT100->Write();
    h_total_NJets->Write();
    h_total_NJetsMinusMatched->Write();
    h_total_NGenHSCPMatched_2HSCP_2jet->Write();
    h_total_NGenHSCPMatched_2HSCP_1jet->Write();
    h_total_NGenHSCPMatched_1HSCP->Write();
    
    h_jetPt_muonPt_allmatched->Write();
    h_jetPt_genhscpPt_allmatched->Write();
    h_muonPt_genhscpPt_allmatched->Write();
    h_jetPt_allmatched->Write();
    h_muonPt_allmatched->Write();
    h_genhscpPt_allmatched->Write();
    h_muonPt_matched->Write();
    h_muonEta_matched->Write();
    h_muonPhi_matched->Write();
    h_muonType_matched->Write();
    h_jetPt_matched->Write();
    h_jetEta_matched->Write();
    h_jetPhi_matched->Write();
    h_jetMass_matched->Write();
    h_jetEnergy_matched->Write();
    h_jetChargedEmEnergyFraction_matched->Write();
    h_jetNeutralEmEnergyFraction_matched->Write();
    h_jetChargedHadronEnergyFraction_matched->Write();
    h_jetNeutralHadronEnergyFraction_matched->Write();
    h_jetNeutralHadronEnergyFraction_matched_GenHSCPCharge0->Write();
    h_jetNeutralHadronEnergyFraction_matched_GenHSCPChargeNon0->Write();
    h_jetChargedEnergyFraction_matched->Write();
    h_jetNeutralEnergyFraction_matched->Write();
    h_jetMuonEnergyFraction_matched->Write();
    h_jetMuonEnergyFraction_matched_GenHSCPCharge0->Write();
    h_jetMuonEnergyFraction_matched_GenHSCPCharge1->Write();
    h_jetMuonEnergyFraction_matched_GenHSCPCharge2->Write();
    h_jetChargedMultiplicity_matched->Write();
    h_jetNeutralMultiplicity_matched->Write();
    h_jetJetArea_matched->Write();
    h_jetPileupE_matched->Write();
    
    h_RPFM_all->Write();
    h_RCAM_all->Write();
    h_RPFM_passMuORMET1234->Write();
    h_RCAM_passMuORMET1234->Write();
    h_RPFM_passMET1234->Write();
    h_RCAM_passMET1234->Write();
    h_RPFM_passMu->Write();
    h_RCAM_passMu->Write();
    h_RPFM_passMET1->Write();
    h_RCAM_passMET1->Write();
    h_RPFM_passMET1Cut1->Write();
    h_RCAM_passMET1Cut1->Write();
    h_RPFM_passMET1Cut2->Write();
    h_RCAM_passMET1Cut2->Write();
    h_RPFM_passMET1Cut3->Write();
    h_RCAM_passMET1Cut3->Write();
    h_RPFM_passMET1Cut4->Write();
    h_RCAM_passMET1Cut4->Write();
    h_RPFM_passMET1Cut5->Write();
    h_RCAM_passMET1Cut5->Write();
    h_RPFM_passMET1Cut6->Write();
    h_RCAM_passMET1Cut6->Write();
    
    h_LHFM_passPres_all->Write();
    h_RPFM_passPres_all->Write();
    h_RPFM_passPres_zoomed->Write();
    h_RCAM_passPres_all->Write();
    h_RCAM_passPres_zoomed->Write();
    h_RPFM_LHFM_passPres->Write();
    h_RCAM_LHFM_passPres->Write();
    h_RPFM_RCAM_passPres->Write();
    
    h_RPFM_passPres_noMU->Write();
    h_RCAM_passPres_noMU->Write();
    h_RPFM_passPres_noMU_passMET1234->Write();
    h_RCAM_passPres_noMU_passMET1234->Write();
    h_RPFM_passPres_noMU_passMET1->Write();
    h_RCAM_passPres_noMU_passMET1->Write();
    h_RPFM_passPres_noMU_passMET1Cut1->Write();
    h_RCAM_passPres_noMU_passMET1Cut1->Write();
    h_RPFM_passPres_noMU_passMET1Cut2->Write();
    h_RCAM_passPres_noMU_passMET1Cut2->Write();
    h_RPFM_passPres_noMU_passMET1Cut3->Write();
    h_RCAM_passPres_noMU_passMET1Cut3->Write();
    h_RPFM_passPres_noMU_passMET1Cut4->Write();
    h_RCAM_passPres_noMU_passMET1Cut4->Write();
    h_RPFM_passPres_noMU_passMET1Cut5->Write();
    h_RCAM_passPres_noMU_passMET1Cut5->Write();
    h_RPFM_passPres_noMU_passMET1Cut6->Write();
    h_RCAM_passPres_noMU_passMET1Cut6->Write();

    h_RCAM_passPres_noMU_cat1_beforeMETFilters->Write();
    h_RCAM_passPres_noMU_cat1_beforeMETFilters_passMET1->Write();
    h_RCAM_passPres_noMU_cat1_beforeMETFilters_passMET1234->Write();
    h_RCAM_passPres_noMU_cat1_beforeMETFilters_full->Write();
    h_RCAM_passPres_noMU_cat1_beforeMETFilters_passMET1_full->Write();
    h_RCAM_passPres_noMU_cat1_beforeMETFilters_passMET1234_full->Write();
    h_RCAM_passPres_noMU_cat2_beforeMETFilters->Write();
    h_RCAM_passPres_noMU_cat2_beforeMETFilters_passMET1->Write();
    h_RCAM_passPres_noMU_cat2_beforeMETFilters_passMET1234->Write();
    h_RCAM_passPres_noMU_cat1_afterMETFilters->Write();
    h_RCAM_passPres_noMU_cat1_afterMETFilters_passMET1->Write();
    h_RCAM_passPres_noMU_cat1_afterMETFilters_passMET1234->Write();
    h_RCAM_passPres_noMU_cat1_afterMETFilters_full->Write();
    h_RCAM_passPres_noMU_cat1_afterMETFilters_passMET1_full->Write();
    h_RCAM_passPres_noMU_cat1_afterMETFilters_passMET1234_full->Write();
    h_RCAM_passPres_noMU_cat2_afterMETFilters->Write();
    h_RCAM_passPres_noMU_cat2_afterMETFilters_passMET1->Write();
    h_RCAM_passPres_noMU_cat2_afterMETFilters_passMET1234->Write();
    h_RCAM_passPres_noMU_beforeMETFilters->Write();
    h_RCAM_passPres_noMU_beforeMETFilters_passMET1234->Write();
    h_RCAM_passPres_noMU_beforeMETFilters_full->Write();
    h_RCAM_passPres_noMU_beforeMETFilters_passMET1234_full->Write();
    h_RCAM_passPres_noMU_afterMETFilters->Write();
    h_RCAM_passPres_noMU_afterMETFilters_passMET1234->Write();
    h_RCAM_passPres_noMU_afterMETFilters_full->Write();
    h_RCAM_passPres_noMU_afterMETFilters_passMET1234_full->Write();
    h_RCAM_passPres_noMU_afterMETFilters_quality->Write();
    h_RCAM_passPres_noMU_afterMETFilters_quality_passMET1234->Write();
    h_RCAM_passPres_noMU_afterMETFilters_quality_full->Write();
    h_RCAM_passPres_noMU_afterMETFilters_quality_passMET1234_full->Write();
    h_RCAM_passPres_noMU_afterMETFilters_quality_noSat->Write();
    h_RCAM_passPres_noMU_afterMETFilters_quality_noSat_passMET1234->Write();

    h_numEventsCategories_noPres->Write();
    h_numEventsCategories_passPres->Write();
    
    outFile->Close();
    
  }
}
