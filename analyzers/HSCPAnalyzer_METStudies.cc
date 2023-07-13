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
  TH1I* h_total_NGenHSCP = new TH1I("h_total_NGenHSCP","total number of GenHSCP",3,0,3);
  TH1I* h_total_NGenHSCPMatched = new TH1I("h_total_NGenHSCPMatched","total number of GenHSCP matched to a jet (dR<0.1)",3,0,3);
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
  TH1I* h_muonType_matched = new TH1I("h_muonType_matched","Pt for muons matched to HSCPs (dR<0.1)",100,0,100);

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

	/* //these lines are causing a crash, but I don't actually need this at the moment so just leave it blank
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
	
	//std::cout << tree->nHSCP << std::endl; 
	//this line causes the crash  // not any more after adding jets?? why lol
	tree->nHSCP++;

      }

      //std::cout << " " << std::endl;

      tree->NCandPassPres = total_NCandPassPres;

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
	tree->gParticles_Eta[tree->ngParticles] = gParticleEta->at(i);
	tree->gParticles_Phi[tree->ngParticles] = gParticlePhi->at(i);
	tree->gParticles_Beta[tree->ngParticles] = gParticleBeta->at(i);
	tree->gParticles_Charge[tree->ngParticles] = gParticleCharge->at(i);
	tree->gParticles_MotherId[tree->ngParticles] = gParticleMotherId->at(i);

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

	//tree->nMuons++;
      }


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

      if(total_NCandPassPres == 2) {

	int HSCP_index1 = index_PassPres[0];
	int HSCP_index2 = index_PassPres[1];

	float HSCP_pt_value1 = Pt->at(HSCP_index1);
	float HSCP_pt_value2 = Pt->at(HSCP_index2);
	h_HSCP_pt_passPres->Fill(HSCP_pt_value1);
	h_HSCP_pt_passPres->Fill(HSCP_pt_value2);

	float dPhi_HSCP_RecoPFMET_value = abs(RazorAnalyzer::deltaPhi(phi->at(HSCP_index1),RecoPFMET_phi));
	float dPhi_HSCP_RecoCaloMET_value = abs(RazorAnalyzer::deltaPhi(phi->at(HSCP_index1),RecoCaloMET_phi));
	float dPhi_HSCP_HLTPFMET_value = abs(RazorAnalyzer::deltaPhi(phi->at(HSCP_index1),HLTPFMET_phi));
	float dPhi_HSCP_HLTCaloMET_value = abs(RazorAnalyzer::deltaPhi(phi->at(HSCP_index1),HLTCaloMET_phi));
	float dPhi_RecoPFMET_RecoCaloMET_value = abs(RazorAnalyzer::deltaPhi(RecoPFMET_phi, RecoCaloMET_phi));
	float dPhi_HLTPFMET_HLTCaloMET_value = abs(RazorAnalyzer::deltaPhi(HLTPFMET_phi, HLTCaloMET_phi));
	float dPhi_RecoPFMET_HLTPFMET_value = abs(RazorAnalyzer::deltaPhi(RecoPFMET_phi, HLTPFMET_phi));
	float dPhi_RecoCaloMET_HLTCaloMET_value = abs(RazorAnalyzer::deltaPhi(RecoCaloMET_phi, HLTCaloMET_phi));


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
      int total_NGenHSCPCharge0 = 0;
      int total_NGenHSCPChargeNon0 = 0;
      int total_NGenHSCPMatched = 0;
      int total_NGenHSCPCharge0Matched =  0;
      int total_NGenHSCPChargeNon0Matched = 0;
      int total_NJets = Jet_pt->size();

      //if(total_NFinalState1 > 0){ //technically not necessary
    for(unsigned int i = 0; i < total_NFinalState1; i++){
      if(fabs(gParticleId->at(index_FinalState1[i])) > 999999){

	float best_matched_deltaR_value = 999;
	int total_NMatches_lessthan01 = 0;
	
	float HSCP_pt_ = gParticlePt->at(index_FinalState1[i]);
	float HSCP_eta_ = gParticleEta->at(index_FinalState1[i]);
	float HSCP_phi_ = gParticlePhi->at(index_FinalState1[i]);
	float HSCP_beta_ = gParticleBeta->at(index_FinalState1[i]);
	float HSCP_charge_ = gParticleCharge->at(index_FinalState1[i]);

	total_NGenHSCP++;
	if(HSCP_charge_ == 0) total_NGenHSCPCharge0++;
	if(HSCP_charge_ != 0) total_NGenHSCPChargeNon0++;
	
	//beginning of loop for jets
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
	  float deltaPhi_HSCP_Jet = RazorAnalyzer::deltaPhi(HSCP_phi_, Jet_phi_);
	  float deltaR_HSCP_Jet = sqrt(pow(deltaEta_HSCP_Jet, 2) + pow(deltaPhi_HSCP_Jet, 2));


	  ////loop on muons
	  for(unsigned int m = 0; m < muonPt->size(); m++){

	    float Muon_pt_ = muonPt->at(m);
	    float Muon_eta_ = muonEta->at(m);
	    float Muon_phi_ = muonPhi->at(m);
	    int Muon_type_ = muonType->at(m);

	    float deltaEta_HSCP_Muon = HSCP_eta_ - Muon_eta_;
	    float deltaPhi_HSCP_Muon = RazorAnalyzer::deltaPhi(HSCP_phi_, Muon_phi_);
	    float deltaR_HSCP_Muon = sqrt(pow(deltaEta_HSCP_Muon,2) + pow(deltaPhi_HSCP_Muon,2));

	    float deltaEta_Jet_Muon = Jet_eta_ - Muon_eta_;
	    float deltaPhi_Jet_Muon = RazorAnalyzer::deltaPhi(Jet_phi_, Muon_phi_);
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
	  if(HSCP_charge_ == 0) total_NGenHSCPCharge0Matched++;
	  if(HSCP_charge_ != 0) total_NGenHSCPChargeNon0Matched++;
	  //THIS IS WHERE I WAS
	}
	
	h_deltaR_HSCP_Jet_best->Fill(best_matched_deltaR_value); //fill best deltaR

	h_genHSCPPt->Fill(HSCP_pt_);
	h_genHSCPEta->Fill(HSCP_eta_);
	h_genHSCPPhi->Fill(HSCP_phi_);
	h_genHSCPBeta->Fill(HSCP_beta_);
	h_genHSCPCharge->Fill(HSCP_charge_);
	
      }	//end of if statement to check for HSCP gParticle_ID
    } // end of loop for all final state particles

      h_total_NGenHSCP->Fill(total_NGenHSCP);
      h_total_NGenHSCPMatched->Fill(total_NGenHSCPMatched);
      h_total_NJets->Fill(total_NJets);
      h_total_NJetsMinusMatched->Fill(total_NJets - total_NGenHSCPMatched);
      if(total_NGenHSCP==2 && total_NJets==2) h_total_NGenHSCPMatched_2HSCP_2jet->Fill(total_NGenHSCPMatched);
      if(total_NGenHSCP==2 && total_NJets==1) h_total_NGenHSCPMatched_2HSCP_1jet->Fill(total_NGenHSCPMatched);
      if(total_NGenHSCP==1) h_total_NGenHSCPMatched_1HSCP->Fill(total_NGenHSCPMatched);
           
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
      h_total_NGenHSCP->Write();
      h_total_NGenHSCPMatched->Write();
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
      h_total_NGenHSCP->Write();
      h_total_NGenHSCPMatched->Write();
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
         
      outFile->Close();
 
    }
}
