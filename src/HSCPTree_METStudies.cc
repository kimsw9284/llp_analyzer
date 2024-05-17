#include "RazorHelper.h"
#include "HSCPTree_METStudies.h"
#include "assert.h"
#include "TTree.h"

// Constructor
HSCPTree_METStudies::HSCPTree_METStudies()
{
  InitVariables();
};
HSCPTree_METStudies::~HSCPTree_METStudies()
{
  if (f_) f_->Close();
};
void HSCPTree_METStudies::InitVariables()
{

  //edit here to add branches
  runNum=0; lumiSec=0; evtNum=0; weight=0; n_pv=0;
  HLT_Mu50 = false; HLT_PFMET120_PFMHT120_IDTight = false; HLT_PFHT500_PFMET100_PFMHT100_IDTight = false;
  HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 = false; HLT_MET105_IsoTrk50 = false;
  RecoCaloMET = -999; RecoCaloMET_phi = -999; RecoPFMET = -999; RecoPFMET_phi = -999; RecoPFMHT = -999; HLTCaloMET = -999; HLTCaloMET_phi = -999; HLTCaloMET_sigf = -999; HLTCaloMETClean = -999; HLTCaloMETClean_phi = -999; HLTCaloMETClean_sigf = -999; HLTCaloMHT = -999; HLTCaloMHT_phi = -999; HLTCaloMHT_sigf = -999; HLTPFMET = -999; HLTPFMET_phi = -999; HLTPFMET_sigf = -999; HLTPFMHT = -999; HLTPFMHT_phi = -999; HLTPFMHT_sigf = -999; L1MET = -999; L1MET_phi = -999; L1METHF = -999; L1METHF_phi = -999; L1MHT = -999; L1MHT_phi = -999; L1ETSum = -999; L1HTSum = -999;
  Flag_globalSuperTightHalo2016Filter = false; Flag_HBHENoiseFilter = false; Flag_HBHENoiseIsoFilter = false; Flag_EcalDeadCellTriggerPrimitiveFilter = false; Flag_BadPFMuonFilter = false; Flag_BadPFMuonDzFilter = false; Flag_hfNoisyHitsFilter = false; Flag_eeBadScFilter = false; Flag_ecalBadCalibFilter = false; Flag_allMETFilters = false;
  bool_CaloMETClean_same = false;
  passPreselection = false;
  NCandPassPres_0 = -999;
  NCandPassPres_1 = -999;
  NCandPassPres_2 = -999;
  NCandPassPres_3 = -999;
  NCandPassPres_4 = -999;
  NCandPassPres_5 = -999;
  NCandPassPres_6 = -999;
  NCandPassPres_7 = -999;
  NCandPassPres_8 = -999;
  NCandPassPres_9 = -999;
  NCandPassPres_10 = -999;
  NCandPassPres_11 = -999;
  NCandPassPres_12 = -999;
  NCandPassPres_13 = -999;
  NCandPassPres_14 = -999;
  NCandPassPres_all = -999;
  genHSCPChargeConfig = -999;
  HSCP1_Eta = -999;
  HSCP1_Phi = -999;
  HSCP1_Charge = -999;
  HSCP1_Beta = -999;
  HSCP1_Pt = -999;
  HSCP2_Eta = -999;
  HSCP2_Phi = -999;
  HSCP2_Charge = -999;
  HSCP2_Beta = -999;
  HSCP2_Pt = -999;
  NNonHSCPGen1GeV = -999;
  NNonHSCPGen10GeV = -999;
  NNonHSCPGen50GeV = -999; 
  NNonHSCPGen100GeV = -999;
  GenPtMag_dPhi0p4_neg_diHSCP = -999;
  diHSCP_pT_mag = -999;
  diHSCP_pT_phi = -999;
  dPhi_HSCP1_HSCP2 = -999;
  dPt_HSCP1_HSCP2 = -999;
  dP_HSCP1_HSCP2 = -999;
  dPhi_diHSCP_HSCP1 = -999;
  dPhi_diHSCP_HSCP2 = -999;
  dPhi_RecoCaloMET_diHSCP = -999;
  dPhi_RecoCaloMET_HSCP1 = -999;
  dPhi_RecoCaloMET_HSCP2 = -999;
  dPhi_HLTCaloMET_diHSCP = -999;
  dPhi_HLTCaloMET_HSCP1 = -999;
  dPhi_HLTCaloMET_HSCP2 = -999;

  nHSCP = 0;
  pileupWeight = 0;
  for( int i = 0; i < N_MAX_HSCP; i++ ) {
    HSCP_charge[i] = -999.;
    HSCP_pt[i] = -999.;
    HSCP_eta[i] = -999.;
    HSCP_phi[i] = -999.;
    HSCP_nPixelHit[i] = -999;
    HSCP_nHits[i] = -999;
    HSCP_isHighPurity[i] = false;
    HSCP_fracValidHits[i] = -999.;
    HSCP_EOverP[i] = -999.;
    HSCP_chi2[i] = -999.;
    HSCP_nDof[i] = -999;
    HSCP_track_genTrackMiniIsoSumPt[i] = -999.;
    HSCP_pfMiniIso_relative[i] = -999.;
    HSCP_probQ[i] = -999.;
    HSCP_ptErr[i] = -999.;
    HSCP_ias_StripOnly[i] = -999.;
    HSCP_mass[i] = -999.;
    HSCP_dZ[i] = -999.;
    HSCP_dXY[i] = -999.;
    HSCP_passPres[i] = false;
    HSCP_isPFMuon[i] = false;
    HSCP_isMuon[i] = false;
    HSCP_isPhoton[i] = false;
    HSCP_isElectron[i] = false;
    HSCP_isChHadron[i] = false;
    HSCP_isNeutHadron[i] = false;
    HSCP_isPfTrack[i] = false;
    HSCP_isUndefined[i] = false;
    HSCP_ECAL_energy[i] = -999.;
    HSCP_HCAL_energy[i] = -999.;
    HSCP_TOF[i] = -999.;
  }

  nJets = 0;
  total_HT = 0;
  total_HT_passJetID = 0;
  for(int i = 0; i < N_MAX_JETS; i++) {
    Jets_pt[i] = -999.;
    Jets_eta[i] = -999.;
    Jets_phi[i] = -999.;
    Jets_mass[i] = -999.;
    Jets_energy[i] = -999.;
    Jets_chargedEmEnergyFraction[i] = -999.;
    Jets_neutralEmEnergyFraction[i] = -999.;
    Jets_chargedHadronEnergyFraction[i] = -999.;
    Jets_neutralHadronEnergyFraction[i] = -999.;
    Jets_muonEnergyFraction[i] = -999.;
    Jets_chargedMultiplicity[i] = -999.;
    Jets_neutralMultiplicity[i] = -999.;
    Jets_jetArea[i] = -999.;
    Jets_pileupE[i] = -999.;
    Jets_passJetID[i] = false;
  }  

  ngParticles = 0;
  for(int i = 0; i < N_MAX_GPARTICLES; i++) {
    gParticles_Id[i] = -999;
    gParticles_Status[i] = -999;
    gParticles_E[i] = -999.;
    gParticles_Pt[i] = -999.;
    gParticles_Pz[i] = -999.;
    gParticles_P[i] = -999.;
    gParticles_Eta[i] = -999.;
    gParticles_Phi[i] = -999.;
    gParticles_Beta[i] = -999.;
    gParticles_Charge[i] = -999;
    gParticles_MotherId[i] = -999;
    
  }

  nMuons = 0;
  for(int i = 0; i < N_MAX_MUONS; i++) {
    Muons_Pt[i] = -999.;
    Muons_Eta[i] = -999.;
    Muons_Phi[i] = -999.;
    Muons_Type[i] = -999;
    Muons_IsLoose[i] = false;
    Muons_IsMedium[i] = false;
    Muons_IsTight[i] = false;
  }

};

void HSCPTree_METStudies::InitTree()
{
  assert(tree_);
  InitVariables();

  //edit here to add branches

  tree_->SetBranchAddress("runNum",      &runNum);
  tree_->SetBranchAddress("lumiSec",     &lumiSec);
  tree_->SetBranchAddress("evtNum",      &evtNum);
  tree_->SetBranchAddress("weight",      &weight);
  tree_->SetBranchAddress("pileupWeight",      &pileupWeight);
  tree_->SetBranchAddress("n_pv",        &n_pv);
  tree_->SetBranchAddress("HLT_Mu50",      &HLT_Mu50);
  tree_->SetBranchAddress("HLT_PFMET120_PFMHT120_IDTight",      &HLT_PFMET120_PFMHT120_IDTight);
  tree_->SetBranchAddress("HLT_PFHT500_PFMET100_PFMHT100_IDTight",      &HLT_PFHT500_PFMET100_PFMHT100_IDTight);
  tree_->SetBranchAddress("HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60",      &HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60);
  tree_->SetBranchAddress("HLT_MET105_IsoTrk50",      &HLT_MET105_IsoTrk50);
  tree_->SetBranchAddress("RecoCaloMET",           &RecoCaloMET);
  tree_->SetBranchAddress("RecoCaloMET_phi",       &RecoCaloMET_phi);
  tree_->SetBranchAddress("RecoPFMET",             &RecoPFMET);
  tree_->SetBranchAddress("RecoPFMET_phi",         &RecoPFMET_phi);
  tree_->SetBranchAddress("RecoPFMHT",             &RecoPFMHT);
  tree_->SetBranchAddress("HLTCaloMET",            &HLTCaloMET);
  tree_->SetBranchAddress("HLTCaloMET_phi",        &HLTCaloMET_phi);
  tree_->SetBranchAddress("HLTCaloMET_sigf",       &HLTCaloMET_sigf);
  tree_->SetBranchAddress("HLTCaloMETClean",       &HLTCaloMETClean);
  tree_->SetBranchAddress("HLTCaloMETClean_phi",   &HLTCaloMETClean_phi);
  tree_->SetBranchAddress("HLTCaloMETClean_sigf",  &HLTCaloMETClean_sigf);
  tree_->SetBranchAddress("HLTCaloMHT",            &HLTCaloMHT);
  tree_->SetBranchAddress("HLTCaloMHT_phi",        &HLTCaloMHT_phi);
  tree_->SetBranchAddress("HLTCaloMHT_sigf",       &HLTCaloMHT_sigf);
  tree_->SetBranchAddress("HLTPFMET",              &HLTPFMET);
  tree_->SetBranchAddress("HLTPFMET_phi",          &HLTPFMET_phi);
  tree_->SetBranchAddress("HLTPFMET_sigf",         &HLTPFMET_sigf);
  tree_->SetBranchAddress("HLTPFMHT",              &HLTPFMHT);
  tree_->SetBranchAddress("HLTPFMHT_phi",          &HLTPFMHT_phi);
  tree_->SetBranchAddress("HLTPFMHT_sigf",         &HLTPFMHT_sigf);
  tree_->SetBranchAddress("L1MET",                 &L1MET);
  tree_->SetBranchAddress("L1MET_phi",             &L1MET_phi);
  tree_->SetBranchAddress("L1METHF",               &L1METHF);
  tree_->SetBranchAddress("L1METHF_phi",           &L1METHF_phi);
  tree_->SetBranchAddress("L1MHT",                 &L1MHT);
  tree_->SetBranchAddress("L1MHT_phi",             &L1MHT_phi);
  tree_->SetBranchAddress("L1ETSum",               &L1ETSum);
  tree_->SetBranchAddress("L1HTSum",               &L1HTSum);
  tree_->SetBranchAddress("Flag_globalSuperTightHalo2016Filter", &Flag_globalSuperTightHalo2016Filter);
  tree_->SetBranchAddress("Flag_HBHENoiseFilter", &Flag_HBHENoiseFilter);
  tree_->SetBranchAddress("Flag_HBHENoiseIsoFilter", &Flag_HBHENoiseIsoFilter);
  tree_->SetBranchAddress("Flag_EcalDeadCellTriggerPrimitiveFilter", &Flag_EcalDeadCellTriggerPrimitiveFilter);
  tree_->SetBranchAddress("Flag_BadPFMuonFilter", &Flag_BadPFMuonFilter);
  tree_->SetBranchAddress("Flag_BadPFMuonDzFilter", &Flag_BadPFMuonDzFilter);
  tree_->SetBranchAddress("Flag_hfNoisyHitsFilter", &Flag_hfNoisyHitsFilter);
  tree_->SetBranchAddress("Flag_eeBadScFilter", &Flag_eeBadScFilter);
  tree_->SetBranchAddress("Flag_ecalBadCalibFilter", &Flag_ecalBadCalibFilter);
  tree_->SetBranchAddress("Flag_allMETFilters", &Flag_allMETFilters);
  tree_->SetBranchAddress("bool_CaloMETClean_same", &bool_CaloMETClean_same);
  tree_->SetBranchAddress("passPreselection",      &passPreselection);
  tree_->SetBranchAddress("NCandPassPres_0",    &NCandPassPres_0);
  tree_->SetBranchAddress("NCandPassPres_1",    &NCandPassPres_1);
  tree_->SetBranchAddress("NCandPassPres_2",    &NCandPassPres_2);
  tree_->SetBranchAddress("NCandPassPres_3",    &NCandPassPres_3);
  tree_->SetBranchAddress("NCandPassPres_4",    &NCandPassPres_4);
  tree_->SetBranchAddress("NCandPassPres_5",    &NCandPassPres_5);
  tree_->SetBranchAddress("NCandPassPres_6",    &NCandPassPres_6);
  tree_->SetBranchAddress("NCandPassPres_7",    &NCandPassPres_7);
  tree_->SetBranchAddress("NCandPassPres_8",    &NCandPassPres_8);
  tree_->SetBranchAddress("NCandPassPres_9",    &NCandPassPres_9);
  tree_->SetBranchAddress("NCandPassPres_10",    &NCandPassPres_10);
  tree_->SetBranchAddress("NCandPassPres_11",    &NCandPassPres_11);
  tree_->SetBranchAddress("NCandPassPres_12",    &NCandPassPres_12);
  tree_->SetBranchAddress("NCandPassPres_13",    &NCandPassPres_13);
  tree_->SetBranchAddress("NCandPassPres_14",    &NCandPassPres_14);
  tree_->SetBranchAddress("NCandPassPres_all",    &NCandPassPres_all);
  tree_->SetBranchAddress("genHSCPChargeConfig",    &genHSCPChargeConfig);
  tree_->SetBranchAddress("HSCP1_Eta",    &HSCP1_Eta);
  tree_->SetBranchAddress("HSCP1_Phi",    &HSCP1_Phi);
  tree_->SetBranchAddress("HSCP1_Charge",    &HSCP1_Charge);
  tree_->SetBranchAddress("HSCP1_Beta",    &HSCP1_Beta);
  tree_->SetBranchAddress("HSCP1_Pt",    &HSCP1_Pt);
  tree_->SetBranchAddress("HSCP2_Eta",    &HSCP2_Eta);
  tree_->SetBranchAddress("HSCP2_Phi",    &HSCP2_Phi);
  tree_->SetBranchAddress("HSCP2_Charge",    &HSCP2_Charge);
  tree_->SetBranchAddress("HSCP2_Beta",    &HSCP2_Beta);
  tree_->SetBranchAddress("HSCP2_Pt",    &HSCP2_Pt);
  tree_->SetBranchAddress("NNonHSCPGen1GeV",    &NNonHSCPGen1GeV);
  tree_->SetBranchAddress("NNonHSCPGen10GeV",    &NNonHSCPGen10GeV);
  tree_->SetBranchAddress("NNonHSCPGen50GeV",    &NNonHSCPGen50GeV);
  tree_->SetBranchAddress("NNonHSCPGen100GeV",    &NNonHSCPGen100GeV);
  tree_->SetBranchAddress("GenPtMag_dPhi0p4_neg_diHSCP",    &GenPtMag_dPhi0p4_neg_diHSCP);
  tree_->SetBranchAddress("diHSCP_pT_mag",    &diHSCP_pT_mag);
  tree_->SetBranchAddress("diHSCP_pT_phi",    &diHSCP_pT_phi);
  tree_->SetBranchAddress("dPhi_HSCP1_HSCP2", &dPhi_HSCP1_HSCP2);
  tree_->SetBranchAddress("dPt_HSCP1_HSCP2", &dPt_HSCP1_HSCP2);
  tree_->SetBranchAddress("dP_HSCP1_HSCP2", &dP_HSCP1_HSCP2);
  tree_->SetBranchAddress("dPhi_diHSCP_HSCP1", &dPhi_diHSCP_HSCP1);
  tree_->SetBranchAddress("dPhi_diHSCP_HSCP2", &dPhi_diHSCP_HSCP2);
  tree_->SetBranchAddress("dPhi_RecoCaloMET_diHSCP", &dPhi_RecoCaloMET_diHSCP);
  tree_->SetBranchAddress("dPhi_RecoCaloMET_HSCP1", &dPhi_RecoCaloMET_HSCP1);
  tree_->SetBranchAddress("dPhi_RecoCaloMET_HSCP2", &dPhi_RecoCaloMET_HSCP2);
  tree_->SetBranchAddress("dPhi_HLTCaloMET_diHSCP", &dPhi_HLTCaloMET_diHSCP);
  tree_->SetBranchAddress("dPhi_HLTCaloMET_HSCP1", &dPhi_HLTCaloMET_HSCP1);
  tree_->SetBranchAddress("dPhi_HLTCaloMET_HSCP2", &dPhi_HLTCaloMET_HSCP2);
  tree_->SetBranchAddress("nHSCP",      &nHSCP);
  tree_->SetBranchAddress("HSCP_charge",          HSCP_charge);
  tree_->SetBranchAddress("HSCP_pt",              HSCP_pt);
  tree_->SetBranchAddress("HSCP_eta",             HSCP_eta);
  tree_->SetBranchAddress("HSCP_phi",             HSCP_phi);
  tree_->SetBranchAddress("HSCP_nPixelHit",       HSCP_nPixelHit);
  tree_->SetBranchAddress("HSCP_nHits",           HSCP_nHits);
  tree_->SetBranchAddress("HSCP_isHighPurity",    HSCP_isHighPurity);
  tree_->SetBranchAddress("HSCP_fracValidHits",   HSCP_fracValidHits);
  tree_->SetBranchAddress("HSCP_EOverP",          HSCP_EOverP);
  tree_->SetBranchAddress("HSCP_chi2",            HSCP_chi2);
  tree_->SetBranchAddress("HSCP_nDof",            HSCP_nDof);
  tree_->SetBranchAddress("HSCP_track_genTrackMiniIsoSumPt",      HSCP_track_genTrackMiniIsoSumPt);
  tree_->SetBranchAddress("HSCP_pfMiniIso_relative",      HSCP_pfMiniIso_relative);
  tree_->SetBranchAddress("HSCP_probQ",           HSCP_probQ);
  tree_->SetBranchAddress("HSCP_ptErr",           HSCP_ptErr);
  tree_->SetBranchAddress("HSCP_ias_StripOnly",   HSCP_ias_StripOnly);
  tree_->SetBranchAddress("HSCP_mass",            HSCP_mass);
  tree_->SetBranchAddress("HSCP_dZ",              HSCP_dZ);
  tree_->SetBranchAddress("HSCP_dXY",             HSCP_dXY);
  tree_->SetBranchAddress("HSCP_passPres",        HSCP_passPres);
  tree_->SetBranchAddress("HSCP_isPFMuon",        HSCP_isPFMuon);
  tree_->SetBranchAddress("HSCP_isMuon",          HSCP_isMuon);
  tree_->SetBranchAddress("HSCP_isPhoton",        HSCP_isPhoton);
  tree_->SetBranchAddress("HSCP_isElectron",      HSCP_isElectron);
  tree_->SetBranchAddress("HSCP_isChHadron",      HSCP_isChHadron);
  tree_->SetBranchAddress("HSCP_isNeutHadron",    HSCP_isNeutHadron);
  tree_->SetBranchAddress("HSCP_isPfTrack",       HSCP_isPfTrack);
  tree_->SetBranchAddress("HSCP_isUndefined",     HSCP_isUndefined);
  tree_->SetBranchAddress("HSCP_ECAL_energy",     HSCP_ECAL_energy);
  tree_->SetBranchAddress("HSCP_HCAL_energy",     HSCP_HCAL_energy);
  tree_->SetBranchAddress("HSCP_TOF",             HSCP_TOF);

  tree_->SetBranchAddress("nJets",      &nJets);
  tree_->SetBranchAddress("total_HT",   &total_HT);
  tree_->SetBranchAddress("total_HT_passJetID", &total_HT_passJetID);
  tree_->SetBranchAddress("Jets_pt",    Jets_pt);
  tree_->SetBranchAddress("Jets_eta",   Jets_eta);
  tree_->SetBranchAddress("Jets_phi",   Jets_phi);
  tree_->SetBranchAddress("Jets_mass",  Jets_mass);
  tree_->SetBranchAddress("Jets_energy",  Jets_energy);
  tree_->SetBranchAddress("Jets_chargedEmEnergyFraction", Jets_chargedEmEnergyFraction);
  tree_->SetBranchAddress("Jets_neutralEmEnergyFraction", Jets_neutralEmEnergyFraction);
  tree_->SetBranchAddress("Jets_chargedHadronEnergyFraction", Jets_chargedHadronEnergyFraction);
  tree_->SetBranchAddress("Jets_neutralHadronEnergyFraction", Jets_neutralHadronEnergyFraction);
  tree_->SetBranchAddress("Jets_muonEnergyFraction", Jets_muonEnergyFraction);
  tree_->SetBranchAddress("Jets_chargedMultiplicity", Jets_chargedMultiplicity);
  tree_->SetBranchAddress("Jets_neutralMultiplicity", Jets_neutralMultiplicity);
  tree_->SetBranchAddress("Jets_jetArea", Jets_jetArea);
  tree_->SetBranchAddress("Jets_pileupE", Jets_pileupE);
  tree_->SetBranchAddress("Jets_passJetID", Jets_passJetID);

  tree_->SetBranchAddress("ngParticles",         &ngParticles);
  tree_->SetBranchAddress("gParticles_Id",       gParticles_Id);
  tree_->SetBranchAddress("gParticles_Status",   gParticles_Status);
  tree_->SetBranchAddress("gParticles_E",        gParticles_E);
  tree_->SetBranchAddress("gParticles_Pt",       gParticles_Pt);
  tree_->SetBranchAddress("gParticles_Pz",       gParticles_Pz);
  tree_->SetBranchAddress("gParticles_P",        gParticles_P);
  tree_->SetBranchAddress("gParticles_Eta",      gParticles_Eta);
  tree_->SetBranchAddress("gParticles_Phi",      gParticles_Phi);
  tree_->SetBranchAddress("gParticles_Beta",     gParticles_Beta);
  tree_->SetBranchAddress("gParticles_Charge",   gParticles_Charge);
  tree_->SetBranchAddress("gParticles_MotherId", gParticles_MotherId);

  tree_->SetBranchAddress("nMuons",               &nMuons);
  tree_->SetBranchAddress("Muons_Pt",             Muons_Pt);
  tree_->SetBranchAddress("Muons_Eta",            Muons_Eta);
  tree_->SetBranchAddress("Muons_Phi",            Muons_Phi);
  tree_->SetBranchAddress("Muons_Type",           Muons_Type);
  tree_->SetBranchAddress("Muons_IsLoose",        Muons_IsLoose);
  tree_->SetBranchAddress("Muons_IsMedium",       Muons_IsMedium);
  tree_->SetBranchAddress("Muons_IsTight",        Muons_IsTight);

};

void HSCPTree_METStudies::LoadTree(const char* file)
{
  f_ = TFile::Open(file);
  assert(f_);
  tree_ = dynamic_cast<TTree*>(f_->Get("tree"));
  InitTree();
  assert(tree_);
};

void HSCPTree_METStudies::CreateTree()
{
  tree_ = new TTree("tree","tree");
  f_ = 0;

  //edit here to add branches

  tree_->Branch("runNum",      &runNum,     "runNum/i");
  tree_->Branch("lumiSec",     &lumiSec,    "lumiSec/i");
  tree_->Branch("evtNum",      &evtNum,     "evtNum/i");
  tree_->Branch("weight",      &weight,     "weight/F");
  tree_->Branch("pileupWeight",      &pileupWeight,     "pileupWeight/F");
  tree_->Branch("n_pv",        &n_pv,       "n_pv/I");

  tree_->Branch("HLT_Mu50",      &HLT_Mu50,     "HLT_Mu50/O");
  tree_->Branch("HLT_PFMET120_PFMHT120_IDTight",      &HLT_PFMET120_PFMHT120_IDTight,     "HLT_PFMET120_PFMHT120_IDTight/O");      // event number
  tree_->Branch("HLT_PFHT500_PFMET100_PFMHT100_IDTight",      &HLT_PFHT500_PFMET100_PFMHT100_IDTight,     "HLT_PFHT500_PFMET100_PFMHT100_IDTight/O");      // event number
  tree_->Branch("HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60",      &HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60,     "HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60/O");      // event number
  tree_->Branch("HLT_MET105_IsoTrk50",      &HLT_MET105_IsoTrk50,     "HLT_MET105_IsoTrk50/O");      // event number
  tree_->Branch("RecoCaloMET",  &RecoCaloMET, "RecoCaloMET/F");
  tree_->Branch("RecoCaloMET_phi",  &RecoCaloMET_phi, "RecoCaloMET_phi/F");
  tree_->Branch("RecoPFMET",  &RecoPFMET, "RecoPFMET/F");
  tree_->Branch("RecoPFMET_phi",  &RecoPFMET_phi, "RecoPFMET_phi/F");
  tree_->Branch("RecoPFMHT",  &RecoPFMHT, "RecoPFMHT/F");
  tree_->Branch("HLTCaloMET",  &HLTCaloMET, "HLTCaloMET/F");
  tree_->Branch("HLTCaloMET_phi",  &HLTCaloMET_phi, "HLTCaloMET_phi/F");
  tree_->Branch("HLTCaloMET_sigf",  &HLTCaloMET_sigf, "HLTCaloMET_sigf/F");
  tree_->Branch("HLTCaloMETClean",  &HLTCaloMETClean, "HLTCaloMETClean/F");
  tree_->Branch("HLTCaloMETClean_phi",  &HLTCaloMETClean_phi, "HLTCaloMETClean_phi/F");
  tree_->Branch("HLTCaloMETClean_sigf",  &HLTCaloMETClean_sigf, "HLTCaloMETClean_sigf/F");
  tree_->Branch("HLTCaloMHT",  &HLTCaloMHT, "HLTCaloMHT/F");
  tree_->Branch("HLTCaloMHT_phi",  &HLTCaloMHT_phi, "HLTCaloMHT_phi/F");
  tree_->Branch("HLTCaloMHT_sigf",  &HLTCaloMHT_sigf, "HLTCaloMHT_sigf/F");
  tree_->Branch("HLTPFMET",  &HLTPFMET, "HLTPFMET/F");
  tree_->Branch("HLTPFMET_phi",  &HLTPFMET_phi, "HLTPFMET_phi/F");
  tree_->Branch("HLTPFMET_sigf",  &HLTPFMET_sigf, "HLTPFMET_sigf/F");
  tree_->Branch("HLTPFMHT",  &HLTPFMHT, "HLTPFMHT/F");
  tree_->Branch("HLTPFMHT_phi",  &HLTPFMHT_phi, "HLTPFMHT_phi/F");
  tree_->Branch("HLTPFMHT_sigf",  &HLTPFMHT_sigf, "HLTPFMHT_sigf/F");
  tree_->Branch("L1MET",   &L1MET,  "L1MET/F");
  tree_->Branch("L1MET_phi",   &L1MET_phi,  "L1MET_phi/F");
  tree_->Branch("L1METHF",   &L1METHF,  "L1METHF/F");
  tree_->Branch("L1METHF_phi",   &L1METHF_phi,  "L1METHF_phi/F");
  tree_->Branch("L1MHT",   &L1MHT,  "L1MHT/F");
  tree_->Branch("L1MHT_phi",   &L1MHT_phi,  "L1MHT_phi/F");
  tree_->Branch("L1ETSum",   &L1ETSum,  "L1ETSum/F");
  tree_->Branch("L1HTSum",   &L1HTSum,  "L1HTSum/F");
  tree_->Branch("Flag_globalSuperTightHalo2016Filter", &Flag_globalSuperTightHalo2016Filter, "Flag_globalSuperTightHalo2016Filter/O");
  tree_->Branch("Flag_HBHENoiseFilter", &Flag_HBHENoiseFilter, "Flag_HBHENoiseFilter/O");
  tree_->Branch("Flag_HBHENoiseIsoFilter", &Flag_HBHENoiseIsoFilter, "Flag_HBHENoiseIsoFilter/O");
  tree_->Branch("Flag_EcalDeadCellTriggerPrimitiveFilter", &Flag_EcalDeadCellTriggerPrimitiveFilter, "Flag_EcalDeadCellTriggerPrimitiveFilter/O");
  tree_->Branch("Flag_BadPFMuonFilter", &Flag_BadPFMuonFilter, "Flag_BadPFMuonFilter/O");
  tree_->Branch("Flag_BadPFMuonDzFilter", &Flag_BadPFMuonDzFilter, "Flag_BadPFMuonDzFilter/O");
  tree_->Branch("Flag_hfNoisyHitsFilter", &Flag_hfNoisyHitsFilter, "Flag_hfNoisyHitsFilter/O");
  tree_->Branch("Flag_eeBadScFilter", &Flag_eeBadScFilter, "Flag_eeBadScFilter/O");
  tree_->Branch("Flag_ecalBadCalibFilter", &Flag_ecalBadCalibFilter, "Flag_ecalBadCalibFilter/O");
  tree_->Branch("Flag_allMETFilters", &Flag_allMETFilters, "Flag_allMETFilters/O");
  tree_->Branch("bool_CaloMETClean_same", &bool_CaloMETClean_same, "bool_CaloMETClean_same/O");
  tree_->Branch("passPreselection", &passPreselection, "passPreselection/O");
  tree_->Branch("NCandPassPres_0", &NCandPassPres_0, "NCandPassPres_0/I");
  tree_->Branch("NCandPassPres_1", &NCandPassPres_1, "NCandPassPres_1/I");
  tree_->Branch("NCandPassPres_2", &NCandPassPres_2, "NCandPassPres_2/I");
  tree_->Branch("NCandPassPres_3", &NCandPassPres_3, "NCandPassPres_3/I");
  tree_->Branch("NCandPassPres_4", &NCandPassPres_4, "NCandPassPres_4/I");
  tree_->Branch("NCandPassPres_5", &NCandPassPres_5, "NCandPassPres_5/I");
  tree_->Branch("NCandPassPres_6", &NCandPassPres_6, "NCandPassPres_6/I");
  tree_->Branch("NCandPassPres_7", &NCandPassPres_7, "NCandPassPres_7/I");
  tree_->Branch("NCandPassPres_8", &NCandPassPres_8, "NCandPassPres_8/I");
  tree_->Branch("NCandPassPres_9", &NCandPassPres_9, "NCandPassPres_9/I");
  tree_->Branch("NCandPassPres_10", &NCandPassPres_10, "NCandPassPres_10/I");
  tree_->Branch("NCandPassPres_11", &NCandPassPres_11, "NCandPassPres_11/I");
  tree_->Branch("NCandPassPres_12", &NCandPassPres_12, "NCandPassPres_12/I");
  tree_->Branch("NCandPassPres_13", &NCandPassPres_13, "NCandPassPres_13/I");
  tree_->Branch("NCandPassPres_14", &NCandPassPres_14, "NCandPassPres_14/I");
  tree_->Branch("NCandPassPres_all", &NCandPassPres_all, "NCandPassPres_all/I");
  tree_->Branch("genHSCPChargeConfig", &genHSCPChargeConfig, "genHSCPChargeConfig/I");
  tree_->Branch("HSCP1_Eta", &HSCP1_Eta, "HSCP1_Eta/F");
  tree_->Branch("HSCP1_Phi", &HSCP1_Phi, "HSCP1_Phi/F");
  tree_->Branch("HSCP1_Charge", &HSCP1_Charge, "HSCP1_Charge/I");
  tree_->Branch("HSCP1_Beta", &HSCP1_Beta, "HSCP1_Beta/F");
  tree_->Branch("HSCP1_Pt", &HSCP1_Pt, "HSCP1_Pt/F");
  tree_->Branch("HSCP2_Eta", &HSCP2_Eta, "HSCP2_Eta/F");
  tree_->Branch("HSCP2_Phi", &HSCP2_Phi, "HSCP2_Phi/F");
  tree_->Branch("HSCP2_Charge", &HSCP2_Charge, "HSCP2_Charge/I");
  tree_->Branch("HSCP2_Beta", &HSCP2_Beta, "HSCP2_Beta/F");
  tree_->Branch("HSCP2_Pt", &HSCP2_Pt, "HSCP2_Pt/F");
  tree_->Branch("NNonHSCPGen1GeV", &NNonHSCPGen1GeV, "NNonHSCPGen1GeV/I");
  tree_->Branch("NNonHSCPGen10GeV", &NNonHSCPGen10GeV, "NNonHSCPGen10GeV/I");
  tree_->Branch("NNonHSCPGen50GeV", &NNonHSCPGen50GeV, "NNonHSCPGen50GeV/I");
  tree_->Branch("NNonHSCPGen100GeV", &NNonHSCPGen100GeV, "NNonHSCPGen100GeV/I");
  tree_->Branch("GenPtMag_dPhi0p4_neg_diHSCP", &GenPtMag_dPhi0p4_neg_diHSCP, "GenPtMag_dPhi0p4_neg_diHSCP/F");
  tree_->Branch("diHSCP_pT_mag", &diHSCP_pT_mag, "diHSCP_pT_mag/F");
  tree_->Branch("diHSCP_pT_phi", &diHSCP_pT_phi, "diHSCP_pT_phi/F");
  tree_->Branch("dPhi_HSCP1_HSCP2", &dPhi_HSCP1_HSCP2, "dPhi_HSCP1_HSCP2/F");
  tree_->Branch("dPt_HSCP1_HSCP2", &dPt_HSCP1_HSCP2, "dPt_HSCP1_HSCP2/F");
  tree_->Branch("dP_HSCP1_HSCP2", &dP_HSCP1_HSCP2, "dP_HSCP1_HSCP2/F");
  tree_->Branch("dPhi_diHSCP_HSCP1", &dPhi_diHSCP_HSCP1, "dPhi_diHSCP_HSCP1/F");
  tree_->Branch("dPhi_diHSCP_HSCP2", &dPhi_diHSCP_HSCP2, "dPhi_diHSCP_HSCP2/F");
  tree_->Branch("dPhi_RecoCaloMET_diHSCP", &dPhi_RecoCaloMET_diHSCP, "dPhi_RecoCaloMET_diHSCP/F");
  tree_->Branch("dPhi_RecoCaloMET_HSCP1", &dPhi_RecoCaloMET_HSCP1, "dPhi_RecoCaloMET_HSCP1/F");
  tree_->Branch("dPhi_RecoCaloMET_HSCP2", &dPhi_RecoCaloMET_HSCP2, "dPhi_RecoCaloMET_HSCP2/F");
  tree_->Branch("dPhi_HLTCaloMET_diHSCP", &dPhi_HLTCaloMET_diHSCP, "dPhi_HLTCaloMET_diHSCP/F");
  tree_->Branch("dPhi_HLTCaloMET_HSCP1", &dPhi_HLTCaloMET_HSCP1, "dPhi_HLTCaloMET_HSCP1/F");
  tree_->Branch("dPhi_HLTCaloMET_HSCP2", &dPhi_HLTCaloMET_HSCP2, "dPhi_HLTCaloMET_HSCP2/F");
  tree_->Branch("nHSCP",      &nHSCP, "nHSCP/I");
  tree_->Branch("HSCP_charge",  HSCP_charge, "HSCP_charge[nHSCP]/F");
  tree_->Branch("HSCP_pt",      HSCP_pt, "HSCP_pt[nHSCP]/F");
  tree_->Branch("HSCP_eta",      HSCP_eta, "HSCP_eta[nHSCP]/F");
  tree_->Branch("HSCP_phi",      HSCP_phi, "HSCP_phi[nHSCP]/F");
  tree_->Branch("HSCP_nPixelHit",      HSCP_nPixelHit, "HSCP_nPixelHit[nHSCP]/i");
  tree_->Branch("HSCP_nHits",      HSCP_nHits, "HSCP_nHits[nHSCP]/i");
  tree_->Branch("HSCP_isHighPurity",      HSCP_isHighPurity, "HSCP_isHighPurity[nHSCP]/O");
  tree_->Branch("HSCP_fracValidHits",      HSCP_fracValidHits, "HSCP_fracValidHits[nHSCP]/F");
  tree_->Branch("HSCP_EOverP",      HSCP_EOverP, "HSCP_EOverP[nHSCP]/F");
  tree_->Branch("HSCP_chi2",      HSCP_chi2, "HSCP_chi2[nHSCP]/F");
  tree_->Branch("HSCP_nDof",      HSCP_nDof, "HSCP_nDof[nHSCP]/i");
  tree_->Branch("HSCP_track_genTrackMiniIsoSumPt",      HSCP_track_genTrackMiniIsoSumPt, "HSCP_track_genTrackMiniIsoSumPt[nHSCP]/F");
  tree_->Branch("HSCP_pfMiniIso_relative",      HSCP_pfMiniIso_relative, "HSCP_pfMiniIso_relative[nHSCP]/F");
  tree_->Branch("HSCP_probQ",      HSCP_probQ, "HSCP_probQ[nHSCP]/F");
  tree_->Branch("HSCP_ptErr",      HSCP_ptErr, "HSCP_ptErr[nHSCP]/F");
  tree_->Branch("HSCP_ias_StripOnly",      HSCP_ias_StripOnly, "HSCP_ias_StripOnly[nHSCP]/F");
  tree_->Branch("HSCP_mass",      HSCP_mass, "HSCP_mass[nHSCP]/F");
  tree_->Branch("HSCP_dZ",      HSCP_dZ, "HSCP_dZ[nHSCP]/F");
  tree_->Branch("HSCP_dXY",      HSCP_dXY, "HSCP_dXY[nHSCP]/F");
  tree_->Branch("HSCP_passPres", HSCP_passPres, "HSCP_passPres[nHSCP]/O");
  tree_->Branch("HSCP_isPFMuon", HSCP_isPFMuon, "HSCP_isPFMuon[nHSCP]/O");
  tree_->Branch("HSCP_isMuon", HSCP_isMuon, "HSCP_isMuon[nHSCP]/O");
  tree_->Branch("HSCP_isPhoton", HSCP_isPhoton, "HSCP_isPhoton[nHSCP]/O");
  tree_->Branch("HSCP_isElectron", HSCP_isElectron, "HSCP_isElctron[nHSCP]/O");
  tree_->Branch("HSCP_isChHadron", HSCP_isChHadron, "HSCP_isChHadron[nHSCP]/O");
  tree_->Branch("HSCP_isNeutHadron", HSCP_isNeutHadron, "HSCP_isNeutHadron[nHSCP]/O");
  tree_->Branch("HSCP_isPfTrack", HSCP_isPfTrack, "HSCP_isPfTrack[nHSCP]/O");
  tree_->Branch("HSCP_isUndefined", HSCP_isUndefined, "HSCP_isUndefined[nHSCP]/O");
  tree_->Branch("HSCP_ECAL_energy", HSCP_ECAL_energy, "HSCP_ECAL_energy[nHSCP]/F");
  tree_->Branch("HSCP_HCAL_energy", HSCP_HCAL_energy, "HSCP_HCAL_energy[nHSCP]/F");
  tree_->Branch("HSCP_TOF", HSCP_TOF, "HSCP_TOF[nHSCP]/F");


  tree_->Branch("nJets",         &nJets,    "nJets/I");
  tree_->Branch("total_HT",      &total_HT, "total_HT/F");
  tree_->Branch("total_HT_passJetID", &total_HT_passJetID, "total_HT_passJetID/F");
  tree_->Branch("Jets_pt",       Jets_pt,   "Jets_pt[nJets]/F");
  tree_->Branch("Jets_eta",      Jets_eta,  "Jets_eta[nJets]/F");
  tree_->Branch("Jets_phi",      Jets_phi,  "Jets_phi[nJets]/F");
  tree_->Branch("Jets_mass",     Jets_mass,  "Jets_mass[nJets]/F");
  tree_->Branch("Jets_energy",   Jets_energy,  "Jets_energy[nJets]/F");
  tree_->Branch("Jets_chargedEmEnergyFraction",      Jets_chargedEmEnergyFraction,  "Jets_chargedEmEnergyFraction[nJets]/F");
  tree_->Branch("Jets_neutralEmEnergyFraction",      Jets_neutralEmEnergyFraction,  "Jets_neutralEmEnergyFraction[nJets]/F");
  tree_->Branch("Jets_chargedHadronEnergyFraction",      Jets_chargedHadronEnergyFraction,  "Jets_chargedHadronEnergyFraction[nJets]/F");
  tree_->Branch("Jets_neutralHadronEnergyFraction",      Jets_neutralHadronEnergyFraction,  "Jets_neutralHadronEnergyFraction[nJets]/F");
  tree_->Branch("Jets_muonEnergyFraction",      Jets_muonEnergyFraction,  "Jets_muonEnergyFraction[nJets]/F");
  tree_->Branch("Jets_chargedMultiplicity",      Jets_chargedMultiplicity,  "Jets_chargedMultiplicity[nJets]/I");
  tree_->Branch("Jets_neutralMultiplicity",      Jets_neutralMultiplicity,  "Jets_neutralMultiplicity[nJets]/I");
  tree_->Branch("Jets_jetArea",  Jets_jetArea,  "Jets_jetArea[nJets]/F");
  tree_->Branch("Jets_pileupE",  Jets_pileupE,  "Jets_pileupE[nJets]/F");
  tree_->Branch("Jets_passJetID", Jets_passJetID, "Jets_passJetID[nJets]/O");


  tree_->Branch("ngParticles",   &ngParticles,   "ngParticles/I");
  tree_->Branch("gParticles_Id", gParticles_Id, "gParticles_Id[ngParticles]/I");
  tree_->Branch("gParticles_Status", gParticles_Status, "gParticles_Status[ngParticles]/I");
  tree_->Branch("gParticles_E", gParticles_E, "gParticles_E[ngParticles]/F");
  tree_->Branch("gParticles_Pt", gParticles_Pt, "gParticles_Pt[ngParticles]/F");
  tree_->Branch("gParticles_Pz", gParticles_Pz, "gParticles_Pz[ngParticles]/F");
  tree_->Branch("gParticles_P", gParticles_P, "gParticles_P[ngParticles]/F");
  tree_->Branch("gParticles_Eta", gParticles_Eta, "gParticles_Eta[ngParticles]/F");
  tree_->Branch("gParticles_Phi", gParticles_Phi, "gParticles_Phi[ngParticles]/F");
  tree_->Branch("gParticles_Beta", gParticles_Beta, "gParticles_Beta[ngParticles]/F");
  tree_->Branch("gParticles_Charge", gParticles_Charge, "gParticles_Charge[ngParticles]/I");
  tree_->Branch("gParticles_MotherId", gParticles_MotherId, "gParticles_MotherId[ngParticles]/I");


  tree_->Branch("nMuons",    &nMuons,   "nMuons/I");
  tree_->Branch("Muons_Pt",   Muons_Pt,   "Muons_Pt[nMuons]/F");
  tree_->Branch("Muons_Eta",  Muons_Eta,  "Muons_Eta[nMuons]/F");
  tree_->Branch("Muons_Phi",  Muons_Phi,  "Muons_Phi[nMuons]/F");
  tree_->Branch("Muons_Type", Muons_Type, "Muons_Type[nMuons]/I");
  tree_->Branch("Muons_IsLoose", Muons_IsLoose, "Muons_IsLoose[nMuons]/O");
  tree_->Branch("Muons_IsMedium", Muons_IsMedium, "Muons_IsMedium[nMuons]/O");
  tree_->Branch("Muons_IsTight", Muons_IsTight, "Muons_IsTight[nMuons]/O");
};
