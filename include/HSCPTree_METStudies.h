// Class to manage files for b-tag scale factors, lepton scale factors, pileup weights, and other information

#ifndef HSCPTree_METStudies_H
#define HSCPTree_METStudies_H

#define N_MAX_LEPTONS 100
#define N_MAX_JETS 100
#define N_MAX_CSC 200
#define N_MAX_CSCRECHITS 5000
#define N_MAX_DTRECHITS 20000
#define NTriggersMAX 1201 // Number of trigger in the .dat file
#define N_CSC_CUT 20
#define JET_PT_CUT 10
#define MUON_PT_CUT 20
#define N_MAX_GPARTICLES 5000
#define N_MAX_HSCP 10
#define N_MAX_MUONS 100

#include <iostream>
#include <string>
#include <sys/stat.h>
#include "assert.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH2D.h"
#include "TRandom.h"
#include "TTree.h"
#include "RazorAnalyzer.h"
#include "RazorHelper.h"

class HSCPTree_METStudies
{

public:
  HSCPTree_METStudies();
  ~HSCPTree_METStudies();
  // HSCPTree_METStudies::HSCPTree_METStudies()
  // {
  //   InitVariables();
  // };
  // HSCPTree_METStudies::~HSCPTree_METStudies()
  // {
  //   if (f_) f_->Close();
  // };
  TTree *tree_;
  TFile *f_;

  UInt_t  runNum, lumiSec, evtNum;

  float weight, pileupWeight;
  int n_pv;

  bool HLT_Mu50, HLT_PFMET120_PFMHT120_IDTight, HLT_PFHT500_PFMET100_PFMHT100_IDTight, HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60, HLT_MET105_IsoTrk50;
  float RecoCaloMET, RecoCaloMET_phi, RecoPFMET, RecoPFMET_phi, RecoPFMHT, HLTCaloMET, HLTCaloMET_phi, HLTCaloMET_sigf, HLTCaloMETClean, HLTCaloMETClean_phi, HLTCaloMETClean_sigf, HLTCaloMHT, HLTCaloMHT_phi, HLTCaloMHT_sigf, HLTPFMET, HLTPFMET_phi, HLTPFMET_sigf, HLTPFMHT, HLTPFMHT_phi, HLTPFMHT_sigf, L1MET, L1MET_phi, L1METHF, L1METHF_phi, L1MHT, L1MHT_phi, L1ETSum, L1HTSum;
  //bool Flag_primaryVertexFilter;
  bool Flag_globalSuperTightHalo2016Filter, Flag_HBHENoiseFilter, Flag_HBHENoiseIsoFilter, Flag_EcalDeadCellTriggerPrimitiveFilter, Flag_BadPFMuonFilter, Flag_BadPFMuonDzFilter, Flag_hfNoisyHitsFilter, Flag_eeBadScFilter, Flag_ecalBadCalibFilter, Flag_allMETFilters;
  bool bool_CaloMETClean_same;
  bool passPreselection;
  int NCandPassPres_0, NCandPassPres_1, NCandPassPres_2, NCandPassPres_3, NCandPassPres_4, NCandPassPres_5, NCandPassPres_6, NCandPassPres_7, NCandPassPres_8, NCandPassPres_9, NCandPassPres_10, NCandPassPres_11, NCandPassPres_12, NCandPassPres_13, NCandPassPres_14, NCandPassPres_all, genHSCPChargeConfig;
  float HSCP1_Eta, HSCP1_Phi;
  int HSCP1_Charge;
  float HSCP1_Beta, HSCP1_Pt, HSCP2_Eta, HSCP2_Phi;
  int HSCP2_Charge;
  float HSCP2_Beta, HSCP2_Pt;
  int NNonHSCPGen1GeV, NNonHSCPGen10GeV, NNonHSCPGen50GeV, NNonHSCPGen100GeV;
  float GenPtMag_dPhi0p4_neg_diHSCP, diHSCP_pT_mag, diHSCP_pT_phi, dPhi_HSCP1_HSCP2, dPt_HSCP1_HSCP2, dP_HSCP1_HSCP2, dPhi_diHSCP_HSCP1, dPhi_diHSCP_HSCP2, dPhi_RecoCaloMET_diHSCP, dPhi_RecoCaloMET_HSCP1, dPhi_RecoCaloMET_HSCP2, dPhi_HLTCaloMET_diHSCP, dPhi_HLTCaloMET_HSCP1, dPhi_HLTCaloMET_HSCP2;

  //edit here to add branches

  // HSCP
  int nHSCP;
  float HSCP_charge[N_MAX_HSCP];
  float HSCP_pt[N_MAX_HSCP];
  float HSCP_eta[N_MAX_HSCP];
  float HSCP_phi[N_MAX_HSCP];
  UInt_t HSCP_nPixelHit[N_MAX_HSCP];
  UInt_t HSCP_nHits[N_MAX_HSCP];
  bool HSCP_isHighPurity[N_MAX_HSCP];
  float HSCP_fracValidHits[N_MAX_HSCP];
  float HSCP_EOverP[N_MAX_HSCP];
  float HSCP_chi2[N_MAX_HSCP];
  UInt_t HSCP_nDof[N_MAX_HSCP];
  float HSCP_track_genTrackMiniIsoSumPt[N_MAX_HSCP];
  float HSCP_pfMiniIso_relative[N_MAX_HSCP];
  float HSCP_probQ[N_MAX_HSCP];
  float HSCP_ptErr[N_MAX_HSCP];
  float HSCP_ias_StripOnly[N_MAX_HSCP];
  float HSCP_mass[N_MAX_HSCP];
  float HSCP_dZ[N_MAX_HSCP];
  float HSCP_dXY[N_MAX_HSCP];
  bool HSCP_passPres[N_MAX_HSCP];
  bool HSCP_isPFMuon[N_MAX_HSCP];
  bool HSCP_isMuon[N_MAX_HSCP];
  bool HSCP_isPhoton[N_MAX_HSCP];
  bool HSCP_isElectron[N_MAX_HSCP];
  bool HSCP_isChHadron[N_MAX_HSCP];
  bool HSCP_isNeutHadron[N_MAX_HSCP];
  bool HSCP_isPfTrack[N_MAX_HSCP];
  bool HSCP_isUndefined[N_MAX_HSCP];
  float HSCP_ECAL_energy[N_MAX_HSCP];
  float HSCP_HCAL_energy[N_MAX_HSCP];
  float HSCP_TOF[N_MAX_HSCP];


  //Jets
  int nJets;
  float total_HT;
  float total_HT_passJetID;
  float Jets_pt[N_MAX_JETS];
  float Jets_eta[N_MAX_JETS];
  float Jets_phi[N_MAX_JETS];
  float Jets_mass[N_MAX_JETS];
  float Jets_energy[N_MAX_JETS];
  float Jets_chargedEmEnergyFraction[N_MAX_JETS];
  float Jets_neutralEmEnergyFraction[N_MAX_JETS];
  float Jets_chargedHadronEnergyFraction[N_MAX_JETS];
  float Jets_neutralHadronEnergyFraction[N_MAX_JETS];
  float Jets_muonEnergyFraction[N_MAX_JETS];
  int Jets_chargedMultiplicity[N_MAX_JETS];
  int Jets_neutralMultiplicity[N_MAX_JETS];
  float Jets_jetArea[N_MAX_JETS];
  float Jets_pileupE[N_MAX_JETS];
  bool Jets_passJetID[N_MAX_JETS];

  //gParticles
  int ngParticles;
  int gParticles_Id[N_MAX_GPARTICLES];
  int gParticles_Status[N_MAX_GPARTICLES];
  float gParticles_E[N_MAX_GPARTICLES];
  float gParticles_Pt[N_MAX_GPARTICLES];
  float gParticles_Pz[N_MAX_GPARTICLES];
  float gParticles_P[N_MAX_GPARTICLES];
  float gParticles_Eta[N_MAX_GPARTICLES];
  float gParticles_Phi[N_MAX_GPARTICLES];
  float gParticles_Beta[N_MAX_GPARTICLES];
  int gParticles_Charge[N_MAX_GPARTICLES];
  int gParticles_MotherId[N_MAX_GPARTICLES];

  //muons
  int nMuons;
  float Muons_Pt[N_MAX_MUONS];
  float Muons_Eta[N_MAX_MUONS];
  float Muons_Phi[N_MAX_MUONS];
  int Muons_Type[N_MAX_MUONS];
  bool Muons_IsLoose[N_MAX_MUONS];
  bool Muons_IsMedium[N_MAX_MUONS];
  bool Muons_IsTight[N_MAX_MUONS];

  void InitVariables();
  void InitTree();
  void LoadTree(const char* file);
  void CreateTree();

};
#endif
