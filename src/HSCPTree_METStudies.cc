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
  runNum=0; lumiSec=0; evtNum=0; weight = 0;
  HLT_Mu50 = false; HLT_PFMET120_PFMHT120_IDTight = false; HLT_PFHT500_PFMET100_PFMHT100_IDTight = false;
  HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 = false; HLT_MET105_IsoTrk50 = false;
  RecoCaloMET = -999; RecoCaloMET_phi = -999; RecoPFMET = -999; RecoPFMET_phi = -999; RecoPFMHT = -999; HLTCaloMET = -999; HLTCaloMET_phi = -999; HLTCaloMET_sigf = -999; HLTCaloMETClean = -999; HLTCaloMETClean_phi = -999; HLTCaloMETClean_sigf = -999; HLTCaloMHT = -999; HLTCaloMHT_phi = -999; HLTCaloMHT_sigf = -999; HLTPFMET = -999; HLTPFMET_phi = -999; HLTPFMET_sigf = -999; HLTPFMHT = -999; HLTPFMHT_phi = -999; HLTPFMHT_sigf = -999;
  passPreselection = false;
  NCandPassPres = -999;

  nHSCP = 0;
  pileupWeight = 0;
  for( int i = 0; i < N_MAX_HSCP; i++ )
  {
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
  tree_->SetBranchAddress("passPreselection",      &passPreselection);
  tree_->SetBranchAddress("NCandPassPres",    &NCandPassPres);
  tree_->SetBranchAddress("nHSCP",      &nHSCP);
  tree_->SetBranchAddress("HSCP_pt",      HSCP_pt);
  tree_->SetBranchAddress("HSCP_eta",      HSCP_eta);
  tree_->SetBranchAddress("HSCP_phi",      HSCP_phi);
  tree_->SetBranchAddress("HSCP_nPixelHit",      HSCP_nPixelHit);
  tree_->SetBranchAddress("HSCP_nHits",      HSCP_nHits);
  tree_->SetBranchAddress("HSCP_isHighPurity",      HSCP_isHighPurity);
  tree_->SetBranchAddress("HSCP_fracValidHits",      HSCP_fracValidHits);
  tree_->SetBranchAddress("HSCP_EOverP",      HSCP_EOverP);
  tree_->SetBranchAddress("HSCP_chi2",      HSCP_chi2);
  tree_->SetBranchAddress("HSCP_nDof",      HSCP_nDof);
  tree_->SetBranchAddress("HSCP_track_genTrackMiniIsoSumPt",      HSCP_track_genTrackMiniIsoSumPt);
  tree_->SetBranchAddress("HSCP_pfMiniIso_relative",      HSCP_pfMiniIso_relative);
  tree_->SetBranchAddress("HSCP_probQ",      HSCP_probQ);
  tree_->SetBranchAddress("HSCP_ptErr",      HSCP_ptErr);
  tree_->SetBranchAddress("HSCP_ias_StripOnly",      HSCP_ias_StripOnly);
  tree_->SetBranchAddress("HSCP_mass",      HSCP_mass);
  tree_->SetBranchAddress("HSCP_dZ",      HSCP_dZ);
  tree_->SetBranchAddress("HSCP_dXY",      HSCP_dXY);
  tree_->SetBranchAddress("HSCP_passPres", HSCP_passPres);

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
  tree_->Branch("passPreselection", &passPreselection, "passPreselection/O");
  tree_->Branch("NCandPassPres", &NCandPassPres, "NCandPassPres/I");
  tree_->Branch("nHSCP",      &nHSCP, "nHSCP/I");
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

};
