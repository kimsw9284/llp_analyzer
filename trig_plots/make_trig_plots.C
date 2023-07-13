#include "TFile.h"
#include "TH1.h"
#include "TH2F.h"
#include "TLegend.h"
#include "TString.h"
#include "TCanvas.h"
#include "TEfficiency.h"
#include "TStyle.h"

void make_trig_plots () {

  gStyle->SetPadTopMargin(0.08);
  gStyle->SetPadBottomMargin(0.12);
  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetPadRightMargin(0.05);
  gStyle->SetOptStat(0);

  TH1::SetDefaultSumw2();

  TFile* f_in01 = new TFile("../Gluino_M800_histos.root");
  TFile* f_in02 = new TFile("../Gluino_M1400_histos.root");
  TFile* f_in03 = new TFile("../Gluino_M1800_histos.root");
  TFile* f_in04 = new TFile("../Gluino_M2400_histos.root");
  TFile* f_in05 = new TFile("../GluinoN_M800_histos.root");
  TFile* f_in06 = new TFile("../GluinoN_M1400_histos.root");
  TFile* f_in07 = new TFile("../GluinoN_M1800_histos.root");
  TFile* f_in08 = new TFile("../GluinoN_M2400_histos.root");
  TFile* f_in09 = new TFile("../GMSBStau_M200_histos.root");
  TFile* f_in10 = new TFile("../GMSBStau_M432_histos.root");
  TFile* f_in11 = new TFile("../GMSBStau_M651_histos.root");
  TFile* f_in12 = new TFile("../GMSBStau_M871_histos.root");
  TFile* f_in13 = new TFile("../PairStau_M200_histos.root");
  TFile* f_in14 = new TFile("../PairStau_M432_histos.root");
  TFile* f_in15 = new TFile("../PairStau_M651_histos.root");

  //get histograms
  TH1F* Gluino800_RecoCaloMET_noPres_ = (TH1F*) f_in01->Get("h_RecoCaloMET_noPres");
  TH1F* Gluino800_RecoPFMET_noPres_ = (TH1F*) f_in01->Get("h_RecoPFMET_noPres");
  TH1F* Gluino800_HLTCaloMET_noPres_ = (TH1F*) f_in01->Get("h_HLTCaloMET_noPres");
  TH1F* Gluino800_HLTPFMET_noPres_ = (TH1F*) f_in01->Get("h_HLTPFMET_noPres");
  TH1F* Gluino800_RecoCaloMET_noPres_passMET_ = (TH1F*) f_in01->Get("h_RecoCaloMET_noPres_passMET");
  TH1F* Gluino800_RecoPFMET_noPres_passMET_ = (TH1F*) f_in01->Get("h_RecoPFMET_noPres_passMET");
  TH1F* Gluino800_HLTCaloMET_noPres_passMET_ = (TH1F*) f_in01->Get("h_HLTCaloMET_noPres_passMET");
  TH1F* Gluino800_HLTPFMET_noPres_passMET_ = (TH1F*) f_in01->Get("h_HLTPFMET_noPres_passMET");
  TH1F* Gluino800_RecoCaloMET_noPres_passMuon_ = (TH1F*) f_in01->Get("h_RecoCaloMET_noPres_passMuon");
  TH1F* Gluino800_RecoPFMET_noPres_passMuon_ = (TH1F*) f_in01->Get("h_RecoPFMET_noPres_passMuon");
  TH1F* Gluino800_HLTCaloMET_noPres_passMuon_ = (TH1F*) f_in01->Get("h_HLTCaloMET_noPres_passMuon");
  TH1F* Gluino800_HLTPFMET_noPres_passMuon_ = (TH1F*) f_in01->Get("h_HLTPFMET_noPres_passMuon");
  TH1F* Gluino800_RecoCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in01->Get("h_RecoCaloMET_noPres_passMETOrMuon");
  TH1F* Gluino800_RecoPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in01->Get("h_RecoPFMET_noPres_passMETOrMuon");
  TH1F* Gluino800_HLTCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in01->Get("h_HLTCaloMET_noPres_passMETOrMuon");
  TH1F* Gluino800_HLTPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in01->Get("h_HLTPFMET_noPres_passMETOrMuon");
  TH1F* Gluino800_RecoCaloMET_passPres_ = (TH1F*) f_in01->Get("h_RecoCaloMET_passPres");
  TH1F* Gluino800_RecoPFMET_passPres_ = (TH1F*) f_in01->Get("h_RecoPFMET_passPres");
  TH1F* Gluino800_HLTCaloMET_passPres_ = (TH1F*) f_in01->Get("h_HLTCaloMET_passPres");
  TH1F* Gluino800_HLTPFMET_passPres_ = (TH1F*) f_in01->Get("h_HLTPFMET_passPres");
  TH1F* Gluino800_RecoCaloMET_passPres_passMET_ = (TH1F*) f_in01->Get("h_RecoCaloMET_passPres_passMET");
  TH1F* Gluino800_RecoPFMET_passPres_passMET_ = (TH1F*) f_in01->Get("h_RecoPFMET_passPres_passMET");
  TH1F* Gluino800_HLTCaloMET_passPres_passMET_ = (TH1F*) f_in01->Get("h_HLTCaloMET_passPres_passMET");
  TH1F* Gluino800_HLTPFMET_passPres_passMET_ = (TH1F*) f_in01->Get("h_HLTPFMET_passPres_passMET");
  TH1F* Gluino800_RecoCaloMET_passPres_passMuon_ = (TH1F*) f_in01->Get("h_RecoCaloMET_passPres_passMuon");
  TH1F* Gluino800_RecoPFMET_passPres_passMuon_ = (TH1F*) f_in01->Get("h_RecoPFMET_passPres_passMuon");
  TH1F* Gluino800_HLTCaloMET_passPres_passMuon_ = (TH1F*) f_in01->Get("h_HLTCaloMET_passPres_passMuon");
  TH1F* Gluino800_HLTPFMET_passPres_passMuon_ = (TH1F*) f_in01->Get("h_HLTPFMET_passPres_passMuon");
  TH1F* Gluino800_RecoCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in01->Get("h_RecoCaloMET_passPres_passMETOrMuon");
  TH1F* Gluino800_RecoPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in01->Get("h_RecoPFMET_passPres_passMETOrMuon");
  TH1F* Gluino800_HLTCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in01->Get("h_HLTCaloMET_passPres_passMETOrMuon");
  TH1F* Gluino800_HLTPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in01->Get("h_HLTPFMET_passPres_passMETOrMuon");

  TH1F* Gluino1400_RecoCaloMET_noPres_ = (TH1F*) f_in02->Get("h_RecoCaloMET_noPres");
  TH1F* Gluino1400_RecoPFMET_noPres_ = (TH1F*) f_in02->Get("h_RecoPFMET_noPres");
  TH1F* Gluino1400_HLTCaloMET_noPres_ = (TH1F*) f_in02->Get("h_HLTCaloMET_noPres");
  TH1F* Gluino1400_HLTPFMET_noPres_ = (TH1F*) f_in02->Get("h_HLTPFMET_noPres");
  TH1F* Gluino1400_RecoCaloMET_noPres_passMET_ = (TH1F*) f_in02->Get("h_RecoCaloMET_noPres_passMET");
  TH1F* Gluino1400_RecoPFMET_noPres_passMET_ = (TH1F*) f_in02->Get("h_RecoPFMET_noPres_passMET");
  TH1F* Gluino1400_HLTCaloMET_noPres_passMET_ = (TH1F*) f_in02->Get("h_HLTCaloMET_noPres_passMET");
  TH1F* Gluino1400_HLTPFMET_noPres_passMET_ = (TH1F*) f_in02->Get("h_HLTPFMET_noPres_passMET");
  TH1F* Gluino1400_RecoCaloMET_noPres_passMuon_ = (TH1F*) f_in02->Get("h_RecoCaloMET_noPres_passMuon");
  TH1F* Gluino1400_RecoPFMET_noPres_passMuon_ = (TH1F*) f_in02->Get("h_RecoPFMET_noPres_passMuon");
  TH1F* Gluino1400_HLTCaloMET_noPres_passMuon_ = (TH1F*) f_in02->Get("h_HLTCaloMET_noPres_passMuon");
  TH1F* Gluino1400_HLTPFMET_noPres_passMuon_ = (TH1F*) f_in02->Get("h_HLTPFMET_noPres_passMuon");
  TH1F* Gluino1400_RecoCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in02->Get("h_RecoCaloMET_noPres_passMETOrMuon");
  TH1F* Gluino1400_RecoPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in02->Get("h_RecoPFMET_noPres_passMETOrMuon");
  TH1F* Gluino1400_HLTCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in02->Get("h_HLTCaloMET_noPres_passMETOrMuon");
  TH1F* Gluino1400_HLTPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in02->Get("h_HLTPFMET_noPres_passMETOrMuon");
  TH1F* Gluino1400_RecoCaloMET_passPres_ = (TH1F*) f_in02->Get("h_RecoCaloMET_passPres");
  TH1F* Gluino1400_RecoPFMET_passPres_ = (TH1F*) f_in02->Get("h_RecoPFMET_passPres");
  TH1F* Gluino1400_HLTCaloMET_passPres_ = (TH1F*) f_in02->Get("h_HLTCaloMET_passPres");
  TH1F* Gluino1400_HLTPFMET_passPres_ = (TH1F*) f_in02->Get("h_HLTPFMET_passPres");
  TH1F* Gluino1400_RecoCaloMET_passPres_passMET_ = (TH1F*) f_in02->Get("h_RecoCaloMET_passPres_passMET");
  TH1F* Gluino1400_RecoPFMET_passPres_passMET_ = (TH1F*) f_in02->Get("h_RecoPFMET_passPres_passMET");
  TH1F* Gluino1400_HLTCaloMET_passPres_passMET_ = (TH1F*) f_in02->Get("h_HLTCaloMET_passPres_passMET");
  TH1F* Gluino1400_HLTPFMET_passPres_passMET_ = (TH1F*) f_in02->Get("h_HLTPFMET_passPres_passMET");
  TH1F* Gluino1400_RecoCaloMET_passPres_passMuon_ = (TH1F*) f_in02->Get("h_RecoCaloMET_passPres_passMuon");
  TH1F* Gluino1400_RecoPFMET_passPres_passMuon_ = (TH1F*) f_in02->Get("h_RecoPFMET_passPres_passMuon");
  TH1F* Gluino1400_HLTCaloMET_passPres_passMuon_ = (TH1F*) f_in02->Get("h_HLTCaloMET_passPres_passMuon");
  TH1F* Gluino1400_HLTPFMET_passPres_passMuon_ = (TH1F*) f_in02->Get("h_HLTPFMET_passPres_passMuon");
  TH1F* Gluino1400_RecoCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in02->Get("h_RecoCaloMET_passPres_passMETOrMuon");
  TH1F* Gluino1400_RecoPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in02->Get("h_RecoPFMET_passPres_passMETOrMuon");
  TH1F* Gluino1400_HLTCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in02->Get("h_HLTCaloMET_passPres_passMETOrMuon");
  TH1F* Gluino1400_HLTPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in02->Get("h_HLTPFMET_passPres_passMETOrMuon");

  TH1F* Gluino1800_RecoCaloMET_noPres_ = (TH1F*) f_in03->Get("h_RecoCaloMET_noPres");
  TH1F* Gluino1800_RecoPFMET_noPres_ = (TH1F*) f_in03->Get("h_RecoPFMET_noPres");
  TH1F* Gluino1800_HLTCaloMET_noPres_ = (TH1F*) f_in03->Get("h_HLTCaloMET_noPres");
  TH1F* Gluino1800_HLTPFMET_noPres_ = (TH1F*) f_in03->Get("h_HLTPFMET_noPres");
  TH1F* Gluino1800_RecoCaloMET_noPres_passMET_ = (TH1F*) f_in03->Get("h_RecoCaloMET_noPres_passMET");
  TH1F* Gluino1800_RecoPFMET_noPres_passMET_ = (TH1F*) f_in03->Get("h_RecoPFMET_noPres_passMET");
  TH1F* Gluino1800_HLTCaloMET_noPres_passMET_ = (TH1F*) f_in03->Get("h_HLTCaloMET_noPres_passMET");
  TH1F* Gluino1800_HLTPFMET_noPres_passMET_ = (TH1F*) f_in03->Get("h_HLTPFMET_noPres_passMET");
  TH1F* Gluino1800_RecoCaloMET_noPres_passMuon_ = (TH1F*) f_in03->Get("h_RecoCaloMET_noPres_passMuon");
  TH1F* Gluino1800_RecoPFMET_noPres_passMuon_ = (TH1F*) f_in03->Get("h_RecoPFMET_noPres_passMuon");
  TH1F* Gluino1800_HLTCaloMET_noPres_passMuon_ = (TH1F*) f_in03->Get("h_HLTCaloMET_noPres_passMuon");
  TH1F* Gluino1800_HLTPFMET_noPres_passMuon_ = (TH1F*) f_in03->Get("h_HLTPFMET_noPres_passMuon");
  TH1F* Gluino1800_RecoCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in03->Get("h_RecoCaloMET_noPres_passMETOrMuon");
  TH1F* Gluino1800_RecoPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in03->Get("h_RecoPFMET_noPres_passMETOrMuon");
  TH1F* Gluino1800_HLTCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in03->Get("h_HLTCaloMET_noPres_passMETOrMuon");
  TH1F* Gluino1800_HLTPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in03->Get("h_HLTPFMET_noPres_passMETOrMuon");
  TH1F* Gluino1800_RecoCaloMET_passPres_ = (TH1F*) f_in03->Get("h_RecoCaloMET_passPres");
  TH1F* Gluino1800_RecoPFMET_passPres_ = (TH1F*) f_in03->Get("h_RecoPFMET_passPres");
  TH1F* Gluino1800_HLTCaloMET_passPres_ = (TH1F*) f_in03->Get("h_HLTCaloMET_passPres");
  TH1F* Gluino1800_HLTPFMET_passPres_ = (TH1F*) f_in03->Get("h_HLTPFMET_passPres");
  TH1F* Gluino1800_RecoCaloMET_passPres_passMET_ = (TH1F*) f_in03->Get("h_RecoCaloMET_passPres_passMET");
  TH1F* Gluino1800_RecoPFMET_passPres_passMET_ = (TH1F*) f_in03->Get("h_RecoPFMET_passPres_passMET");
  TH1F* Gluino1800_HLTCaloMET_passPres_passMET_ = (TH1F*) f_in03->Get("h_HLTCaloMET_passPres_passMET");
  TH1F* Gluino1800_HLTPFMET_passPres_passMET_ = (TH1F*) f_in03->Get("h_HLTPFMET_passPres_passMET");
  TH1F* Gluino1800_RecoCaloMET_passPres_passMuon_ = (TH1F*) f_in03->Get("h_RecoCaloMET_passPres_passMuon");
  TH1F* Gluino1800_RecoPFMET_passPres_passMuon_ = (TH1F*) f_in03->Get("h_RecoPFMET_passPres_passMuon");
  TH1F* Gluino1800_HLTCaloMET_passPres_passMuon_ = (TH1F*) f_in03->Get("h_HLTCaloMET_passPres_passMuon");
  TH1F* Gluino1800_HLTPFMET_passPres_passMuon_ = (TH1F*) f_in03->Get("h_HLTPFMET_passPres_passMuon");
  TH1F* Gluino1800_RecoCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in03->Get("h_RecoCaloMET_passPres_passMETOrMuon");
  TH1F* Gluino1800_RecoPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in03->Get("h_RecoPFMET_passPres_passMETOrMuon");
  TH1F* Gluino1800_HLTCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in03->Get("h_HLTCaloMET_passPres_passMETOrMuon");
  TH1F* Gluino1800_HLTPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in03->Get("h_HLTPFMET_passPres_passMETOrMuon");

  TH1F* Gluino2400_RecoCaloMET_noPres_ = (TH1F*) f_in04->Get("h_RecoCaloMET_noPres");
  TH1F* Gluino2400_RecoPFMET_noPres_ = (TH1F*) f_in04->Get("h_RecoPFMET_noPres");
  TH1F* Gluino2400_HLTCaloMET_noPres_ = (TH1F*) f_in04->Get("h_HLTCaloMET_noPres");
  TH1F* Gluino2400_HLTPFMET_noPres_ = (TH1F*) f_in04->Get("h_HLTPFMET_noPres");
  TH1F* Gluino2400_RecoCaloMET_noPres_passMET_ = (TH1F*) f_in04->Get("h_RecoCaloMET_noPres_passMET");
  TH1F* Gluino2400_RecoPFMET_noPres_passMET_ = (TH1F*) f_in04->Get("h_RecoPFMET_noPres_passMET");
  TH1F* Gluino2400_HLTCaloMET_noPres_passMET_ = (TH1F*) f_in04->Get("h_HLTCaloMET_noPres_passMET");
  TH1F* Gluino2400_HLTPFMET_noPres_passMET_ = (TH1F*) f_in04->Get("h_HLTPFMET_noPres_passMET");
  TH1F* Gluino2400_RecoCaloMET_noPres_passMuon_ = (TH1F*) f_in04->Get("h_RecoCaloMET_noPres_passMuon");
  TH1F* Gluino2400_RecoPFMET_noPres_passMuon_ = (TH1F*) f_in04->Get("h_RecoPFMET_noPres_passMuon");
  TH1F* Gluino2400_HLTCaloMET_noPres_passMuon_ = (TH1F*) f_in04->Get("h_HLTCaloMET_noPres_passMuon");
  TH1F* Gluino2400_HLTPFMET_noPres_passMuon_ = (TH1F*) f_in04->Get("h_HLTPFMET_noPres_passMuon");
  TH1F* Gluino2400_RecoCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in04->Get("h_RecoCaloMET_noPres_passMETOrMuon");
  TH1F* Gluino2400_RecoPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in04->Get("h_RecoPFMET_noPres_passMETOrMuon");
  TH1F* Gluino2400_HLTCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in04->Get("h_HLTCaloMET_noPres_passMETOrMuon");
  TH1F* Gluino2400_HLTPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in04->Get("h_HLTPFMET_noPres_passMETOrMuon");
  TH1F* Gluino2400_RecoCaloMET_passPres_ = (TH1F*) f_in04->Get("h_RecoCaloMET_passPres");
  TH1F* Gluino2400_RecoPFMET_passPres_ = (TH1F*) f_in04->Get("h_RecoPFMET_passPres");
  TH1F* Gluino2400_HLTCaloMET_passPres_ = (TH1F*) f_in04->Get("h_HLTCaloMET_passPres");
  TH1F* Gluino2400_HLTPFMET_passPres_ = (TH1F*) f_in04->Get("h_HLTPFMET_passPres");
  TH1F* Gluino2400_RecoCaloMET_passPres_passMET_ = (TH1F*) f_in04->Get("h_RecoCaloMET_passPres_passMET");
  TH1F* Gluino2400_RecoPFMET_passPres_passMET_ = (TH1F*) f_in04->Get("h_RecoPFMET_passPres_passMET");
  TH1F* Gluino2400_HLTCaloMET_passPres_passMET_ = (TH1F*) f_in04->Get("h_HLTCaloMET_passPres_passMET");
  TH1F* Gluino2400_HLTPFMET_passPres_passMET_ = (TH1F*) f_in04->Get("h_HLTPFMET_passPres_passMET");
  TH1F* Gluino2400_RecoCaloMET_passPres_passMuon_ = (TH1F*) f_in04->Get("h_RecoCaloMET_passPres_passMuon");
  TH1F* Gluino2400_RecoPFMET_passPres_passMuon_ = (TH1F*) f_in04->Get("h_RecoPFMET_passPres_passMuon");
  TH1F* Gluino2400_HLTCaloMET_passPres_passMuon_ = (TH1F*) f_in04->Get("h_HLTCaloMET_passPres_passMuon");
  TH1F* Gluino2400_HLTPFMET_passPres_passMuon_ = (TH1F*) f_in04->Get("h_HLTPFMET_passPres_passMuon");
  TH1F* Gluino2400_RecoCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in04->Get("h_RecoCaloMET_passPres_passMETOrMuon");
  TH1F* Gluino2400_RecoPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in04->Get("h_RecoPFMET_passPres_passMETOrMuon");
  TH1F* Gluino2400_HLTCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in04->Get("h_HLTCaloMET_passPres_passMETOrMuon");
  TH1F* Gluino2400_HLTPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in04->Get("h_HLTPFMET_passPres_passMETOrMuon");

  TH1F* GluinoN800_RecoCaloMET_noPres_ = (TH1F*) f_in05->Get("h_RecoCaloMET_noPres");
  TH1F* GluinoN800_RecoPFMET_noPres_ = (TH1F*) f_in05->Get("h_RecoPFMET_noPres");
  TH1F* GluinoN800_HLTCaloMET_noPres_ = (TH1F*) f_in05->Get("h_HLTCaloMET_noPres");
  TH1F* GluinoN800_HLTPFMET_noPres_ = (TH1F*) f_in05->Get("h_HLTPFMET_noPres");
  TH1F* GluinoN800_RecoCaloMET_noPres_passMET_ = (TH1F*) f_in05->Get("h_RecoCaloMET_noPres_passMET");
  TH1F* GluinoN800_RecoPFMET_noPres_passMET_ = (TH1F*) f_in05->Get("h_RecoPFMET_noPres_passMET");
  TH1F* GluinoN800_HLTCaloMET_noPres_passMET_ = (TH1F*) f_in05->Get("h_HLTCaloMET_noPres_passMET");
  TH1F* GluinoN800_HLTPFMET_noPres_passMET_ = (TH1F*) f_in05->Get("h_HLTPFMET_noPres_passMET");
  TH1F* GluinoN800_RecoCaloMET_noPres_passMuon_ = (TH1F*) f_in05->Get("h_RecoCaloMET_noPres_passMuon");
  TH1F* GluinoN800_RecoPFMET_noPres_passMuon_ = (TH1F*) f_in05->Get("h_RecoPFMET_noPres_passMuon");
  TH1F* GluinoN800_HLTCaloMET_noPres_passMuon_ = (TH1F*) f_in05->Get("h_HLTCaloMET_noPres_passMuon");
  TH1F* GluinoN800_HLTPFMET_noPres_passMuon_ = (TH1F*) f_in05->Get("h_HLTPFMET_noPres_passMuon");
  TH1F* GluinoN800_RecoCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in05->Get("h_RecoCaloMET_noPres_passMETOrMuon");
  TH1F* GluinoN800_RecoPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in05->Get("h_RecoPFMET_noPres_passMETOrMuon");
  TH1F* GluinoN800_HLTCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in05->Get("h_HLTCaloMET_noPres_passMETOrMuon");
  TH1F* GluinoN800_HLTPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in05->Get("h_HLTPFMET_noPres_passMETOrMuon");
  TH1F* GluinoN800_RecoCaloMET_passPres_ = (TH1F*) f_in05->Get("h_RecoCaloMET_passPres");
  TH1F* GluinoN800_RecoPFMET_passPres_ = (TH1F*) f_in05->Get("h_RecoPFMET_passPres");
  TH1F* GluinoN800_HLTCaloMET_passPres_ = (TH1F*) f_in05->Get("h_HLTCaloMET_passPres");
  TH1F* GluinoN800_HLTPFMET_passPres_ = (TH1F*) f_in05->Get("h_HLTPFMET_passPres");
  TH1F* GluinoN800_RecoCaloMET_passPres_passMET_ = (TH1F*) f_in05->Get("h_RecoCaloMET_passPres_passMET");
  TH1F* GluinoN800_RecoPFMET_passPres_passMET_ = (TH1F*) f_in05->Get("h_RecoPFMET_passPres_passMET");
  TH1F* GluinoN800_HLTCaloMET_passPres_passMET_ = (TH1F*) f_in05->Get("h_HLTCaloMET_passPres_passMET");
  TH1F* GluinoN800_HLTPFMET_passPres_passMET_ = (TH1F*) f_in05->Get("h_HLTPFMET_passPres_passMET");
  TH1F* GluinoN800_RecoCaloMET_passPres_passMuon_ = (TH1F*) f_in05->Get("h_RecoCaloMET_passPres_passMuon");
  TH1F* GluinoN800_RecoPFMET_passPres_passMuon_ = (TH1F*) f_in05->Get("h_RecoPFMET_passPres_passMuon");
  TH1F* GluinoN800_HLTCaloMET_passPres_passMuon_ = (TH1F*) f_in05->Get("h_HLTCaloMET_passPres_passMuon");
  TH1F* GluinoN800_HLTPFMET_passPres_passMuon_ = (TH1F*) f_in05->Get("h_HLTPFMET_passPres_passMuon");
  TH1F* GluinoN800_RecoCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in05->Get("h_RecoCaloMET_passPres_passMETOrMuon");
  TH1F* GluinoN800_RecoPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in05->Get("h_RecoPFMET_passPres_passMETOrMuon");
  TH1F* GluinoN800_HLTCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in05->Get("h_HLTCaloMET_passPres_passMETOrMuon");
  TH1F* GluinoN800_HLTPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in05->Get("h_HLTPFMET_passPres_passMETOrMuon");

  TH1F* GluinoN1400_RecoCaloMET_noPres_ = (TH1F*) f_in06->Get("h_RecoCaloMET_noPres");
  TH1F* GluinoN1400_RecoPFMET_noPres_ = (TH1F*) f_in06->Get("h_RecoPFMET_noPres");
  TH1F* GluinoN1400_HLTCaloMET_noPres_ = (TH1F*) f_in06->Get("h_HLTCaloMET_noPres");
  TH1F* GluinoN1400_HLTPFMET_noPres_ = (TH1F*) f_in06->Get("h_HLTPFMET_noPres");
  TH1F* GluinoN1400_RecoCaloMET_noPres_passMET_ = (TH1F*) f_in06->Get("h_RecoCaloMET_noPres_passMET");
  TH1F* GluinoN1400_RecoPFMET_noPres_passMET_ = (TH1F*) f_in06->Get("h_RecoPFMET_noPres_passMET");
  TH1F* GluinoN1400_HLTCaloMET_noPres_passMET_ = (TH1F*) f_in06->Get("h_HLTCaloMET_noPres_passMET");
  TH1F* GluinoN1400_HLTPFMET_noPres_passMET_ = (TH1F*) f_in06->Get("h_HLTPFMET_noPres_passMET");
  TH1F* GluinoN1400_RecoCaloMET_noPres_passMuon_ = (TH1F*) f_in06->Get("h_RecoCaloMET_noPres_passMuon");
  TH1F* GluinoN1400_RecoPFMET_noPres_passMuon_ = (TH1F*) f_in06->Get("h_RecoPFMET_noPres_passMuon");
  TH1F* GluinoN1400_HLTCaloMET_noPres_passMuon_ = (TH1F*) f_in06->Get("h_HLTCaloMET_noPres_passMuon");
  TH1F* GluinoN1400_HLTPFMET_noPres_passMuon_ = (TH1F*) f_in06->Get("h_HLTPFMET_noPres_passMuon");
  TH1F* GluinoN1400_RecoCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in06->Get("h_RecoCaloMET_noPres_passMETOrMuon");
  TH1F* GluinoN1400_RecoPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in06->Get("h_RecoPFMET_noPres_passMETOrMuon");
  TH1F* GluinoN1400_HLTCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in06->Get("h_HLTCaloMET_noPres_passMETOrMuon");
  TH1F* GluinoN1400_HLTPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in06->Get("h_HLTPFMET_noPres_passMETOrMuon");
  TH1F* GluinoN1400_RecoCaloMET_passPres_ = (TH1F*) f_in06->Get("h_RecoCaloMET_passPres");
  TH1F* GluinoN1400_RecoPFMET_passPres_ = (TH1F*) f_in06->Get("h_RecoPFMET_passPres");
  TH1F* GluinoN1400_HLTCaloMET_passPres_ = (TH1F*) f_in06->Get("h_HLTCaloMET_passPres");
  TH1F* GluinoN1400_HLTPFMET_passPres_ = (TH1F*) f_in06->Get("h_HLTPFMET_passPres");
  TH1F* GluinoN1400_RecoCaloMET_passPres_passMET_ = (TH1F*) f_in06->Get("h_RecoCaloMET_passPres_passMET");
  TH1F* GluinoN1400_RecoPFMET_passPres_passMET_ = (TH1F*) f_in06->Get("h_RecoPFMET_passPres_passMET");
  TH1F* GluinoN1400_HLTCaloMET_passPres_passMET_ = (TH1F*) f_in06->Get("h_HLTCaloMET_passPres_passMET");
  TH1F* GluinoN1400_HLTPFMET_passPres_passMET_ = (TH1F*) f_in06->Get("h_HLTPFMET_passPres_passMET");
  TH1F* GluinoN1400_RecoCaloMET_passPres_passMuon_ = (TH1F*) f_in06->Get("h_RecoCaloMET_passPres_passMuon");
  TH1F* GluinoN1400_RecoPFMET_passPres_passMuon_ = (TH1F*) f_in06->Get("h_RecoPFMET_passPres_passMuon");
  TH1F* GluinoN1400_HLTCaloMET_passPres_passMuon_ = (TH1F*) f_in06->Get("h_HLTCaloMET_passPres_passMuon");
  TH1F* GluinoN1400_HLTPFMET_passPres_passMuon_ = (TH1F*) f_in06->Get("h_HLTPFMET_passPres_passMuon");
  TH1F* GluinoN1400_RecoCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in06->Get("h_RecoCaloMET_passPres_passMETOrMuon");
  TH1F* GluinoN1400_RecoPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in06->Get("h_RecoPFMET_passPres_passMETOrMuon");
  TH1F* GluinoN1400_HLTCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in06->Get("h_HLTCaloMET_passPres_passMETOrMuon");
  TH1F* GluinoN1400_HLTPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in06->Get("h_HLTPFMET_passPres_passMETOrMuon");

  TH1F* GluinoN1800_RecoCaloMET_noPres_ = (TH1F*) f_in07->Get("h_RecoCaloMET_noPres");
  TH1F* GluinoN1800_RecoPFMET_noPres_ = (TH1F*) f_in07->Get("h_RecoPFMET_noPres");
  TH1F* GluinoN1800_HLTCaloMET_noPres_ = (TH1F*) f_in07->Get("h_HLTCaloMET_noPres");
  TH1F* GluinoN1800_HLTPFMET_noPres_ = (TH1F*) f_in07->Get("h_HLTPFMET_noPres");
  TH1F* GluinoN1800_RecoCaloMET_noPres_passMET_ = (TH1F*) f_in07->Get("h_RecoCaloMET_noPres_passMET");
  TH1F* GluinoN1800_RecoPFMET_noPres_passMET_ = (TH1F*) f_in07->Get("h_RecoPFMET_noPres_passMET");
  TH1F* GluinoN1800_HLTCaloMET_noPres_passMET_ = (TH1F*) f_in07->Get("h_HLTCaloMET_noPres_passMET");
  TH1F* GluinoN1800_HLTPFMET_noPres_passMET_ = (TH1F*) f_in07->Get("h_HLTPFMET_noPres_passMET");
  TH1F* GluinoN1800_RecoCaloMET_noPres_passMuon_ = (TH1F*) f_in07->Get("h_RecoCaloMET_noPres_passMuon");
  TH1F* GluinoN1800_RecoPFMET_noPres_passMuon_ = (TH1F*) f_in07->Get("h_RecoPFMET_noPres_passMuon");
  TH1F* GluinoN1800_HLTCaloMET_noPres_passMuon_ = (TH1F*) f_in07->Get("h_HLTCaloMET_noPres_passMuon");
  TH1F* GluinoN1800_HLTPFMET_noPres_passMuon_ = (TH1F*) f_in07->Get("h_HLTPFMET_noPres_passMuon");
  TH1F* GluinoN1800_RecoCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in07->Get("h_RecoCaloMET_noPres_passMETOrMuon");
  TH1F* GluinoN1800_RecoPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in07->Get("h_RecoPFMET_noPres_passMETOrMuon");
  TH1F* GluinoN1800_HLTCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in07->Get("h_HLTCaloMET_noPres_passMETOrMuon");
  TH1F* GluinoN1800_HLTPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in07->Get("h_HLTPFMET_noPres_passMETOrMuon");
  TH1F* GluinoN1800_RecoCaloMET_passPres_ = (TH1F*) f_in07->Get("h_RecoCaloMET_passPres");
  TH1F* GluinoN1800_RecoPFMET_passPres_ = (TH1F*) f_in07->Get("h_RecoPFMET_passPres");
  TH1F* GluinoN1800_HLTCaloMET_passPres_ = (TH1F*) f_in07->Get("h_HLTCaloMET_passPres");
  TH1F* GluinoN1800_HLTPFMET_passPres_ = (TH1F*) f_in07->Get("h_HLTPFMET_passPres");
  TH1F* GluinoN1800_RecoCaloMET_passPres_passMET_ = (TH1F*) f_in07->Get("h_RecoCaloMET_passPres_passMET");
  TH1F* GluinoN1800_RecoPFMET_passPres_passMET_ = (TH1F*) f_in07->Get("h_RecoPFMET_passPres_passMET");
  TH1F* GluinoN1800_HLTCaloMET_passPres_passMET_ = (TH1F*) f_in07->Get("h_HLTCaloMET_passPres_passMET");
  TH1F* GluinoN1800_HLTPFMET_passPres_passMET_ = (TH1F*) f_in07->Get("h_HLTPFMET_passPres_passMET");
  TH1F* GluinoN1800_RecoCaloMET_passPres_passMuon_ = (TH1F*) f_in07->Get("h_RecoCaloMET_passPres_passMuon");
  TH1F* GluinoN1800_RecoPFMET_passPres_passMuon_ = (TH1F*) f_in07->Get("h_RecoPFMET_passPres_passMuon");
  TH1F* GluinoN1800_HLTCaloMET_passPres_passMuon_ = (TH1F*) f_in07->Get("h_HLTCaloMET_passPres_passMuon");
  TH1F* GluinoN1800_HLTPFMET_passPres_passMuon_ = (TH1F*) f_in07->Get("h_HLTPFMET_passPres_passMuon");
  TH1F* GluinoN1800_RecoCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in07->Get("h_RecoCaloMET_passPres_passMETOrMuon");
  TH1F* GluinoN1800_RecoPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in07->Get("h_RecoPFMET_passPres_passMETOrMuon");
  TH1F* GluinoN1800_HLTCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in07->Get("h_HLTCaloMET_passPres_passMETOrMuon");
  TH1F* GluinoN1800_HLTPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in07->Get("h_HLTPFMET_passPres_passMETOrMuon");

  TH1F* GluinoN2400_RecoCaloMET_noPres_ = (TH1F*) f_in08->Get("h_RecoCaloMET_noPres");
  TH1F* GluinoN2400_RecoPFMET_noPres_ = (TH1F*) f_in08->Get("h_RecoPFMET_noPres");
  TH1F* GluinoN2400_HLTCaloMET_noPres_ = (TH1F*) f_in08->Get("h_HLTCaloMET_noPres");
  TH1F* GluinoN2400_HLTPFMET_noPres_ = (TH1F*) f_in08->Get("h_HLTPFMET_noPres");
  TH1F* GluinoN2400_RecoCaloMET_noPres_passMET_ = (TH1F*) f_in08->Get("h_RecoCaloMET_noPres_passMET");
  TH1F* GluinoN2400_RecoPFMET_noPres_passMET_ = (TH1F*) f_in08->Get("h_RecoPFMET_noPres_passMET");
  TH1F* GluinoN2400_HLTCaloMET_noPres_passMET_ = (TH1F*) f_in08->Get("h_HLTCaloMET_noPres_passMET");
  TH1F* GluinoN2400_HLTPFMET_noPres_passMET_ = (TH1F*) f_in08->Get("h_HLTPFMET_noPres_passMET");
  TH1F* GluinoN2400_RecoCaloMET_noPres_passMuon_ = (TH1F*) f_in08->Get("h_RecoCaloMET_noPres_passMuon");
  TH1F* GluinoN2400_RecoPFMET_noPres_passMuon_ = (TH1F*) f_in08->Get("h_RecoPFMET_noPres_passMuon");
  TH1F* GluinoN2400_HLTCaloMET_noPres_passMuon_ = (TH1F*) f_in08->Get("h_HLTCaloMET_noPres_passMuon");
  TH1F* GluinoN2400_HLTPFMET_noPres_passMuon_ = (TH1F*) f_in08->Get("h_HLTPFMET_noPres_passMuon");
  TH1F* GluinoN2400_RecoCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in08->Get("h_RecoCaloMET_noPres_passMETOrMuon");
  TH1F* GluinoN2400_RecoPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in08->Get("h_RecoPFMET_noPres_passMETOrMuon");
  TH1F* GluinoN2400_HLTCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in08->Get("h_HLTCaloMET_noPres_passMETOrMuon");
  TH1F* GluinoN2400_HLTPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in08->Get("h_HLTPFMET_noPres_passMETOrMuon");
  TH1F* GluinoN2400_RecoCaloMET_passPres_ = (TH1F*) f_in08->Get("h_RecoCaloMET_passPres");
  TH1F* GluinoN2400_RecoPFMET_passPres_ = (TH1F*) f_in08->Get("h_RecoPFMET_passPres");
  TH1F* GluinoN2400_HLTCaloMET_passPres_ = (TH1F*) f_in08->Get("h_HLTCaloMET_passPres");
  TH1F* GluinoN2400_HLTPFMET_passPres_ = (TH1F*) f_in08->Get("h_HLTPFMET_passPres");
  TH1F* GluinoN2400_RecoCaloMET_passPres_passMET_ = (TH1F*) f_in08->Get("h_RecoCaloMET_passPres_passMET");
  TH1F* GluinoN2400_RecoPFMET_passPres_passMET_ = (TH1F*) f_in08->Get("h_RecoPFMET_passPres_passMET");
  TH1F* GluinoN2400_HLTCaloMET_passPres_passMET_ = (TH1F*) f_in08->Get("h_HLTCaloMET_passPres_passMET");
  TH1F* GluinoN2400_HLTPFMET_passPres_passMET_ = (TH1F*) f_in08->Get("h_HLTPFMET_passPres_passMET");
  TH1F* GluinoN2400_RecoCaloMET_passPres_passMuon_ = (TH1F*) f_in08->Get("h_RecoCaloMET_passPres_passMuon");
  TH1F* GluinoN2400_RecoPFMET_passPres_passMuon_ = (TH1F*) f_in08->Get("h_RecoPFMET_passPres_passMuon");
  TH1F* GluinoN2400_HLTCaloMET_passPres_passMuon_ = (TH1F*) f_in08->Get("h_HLTCaloMET_passPres_passMuon");
  TH1F* GluinoN2400_HLTPFMET_passPres_passMuon_ = (TH1F*) f_in08->Get("h_HLTPFMET_passPres_passMuon");
  TH1F* GluinoN2400_RecoCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in08->Get("h_RecoCaloMET_passPres_passMETOrMuon");
  TH1F* GluinoN2400_RecoPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in08->Get("h_RecoPFMET_passPres_passMETOrMuon");
  TH1F* GluinoN2400_HLTCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in08->Get("h_HLTCaloMET_passPres_passMETOrMuon");
  TH1F* GluinoN2400_HLTPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in08->Get("h_HLTPFMET_passPres_passMETOrMuon");

  TH1F* GMSBStau200_RecoCaloMET_noPres_ = (TH1F*) f_in09->Get("h_RecoCaloMET_noPres");
  TH1F* GMSBStau200_RecoPFMET_noPres_ = (TH1F*) f_in09->Get("h_RecoPFMET_noPres");
  TH1F* GMSBStau200_HLTCaloMET_noPres_ = (TH1F*) f_in09->Get("h_HLTCaloMET_noPres");
  TH1F* GMSBStau200_HLTPFMET_noPres_ = (TH1F*) f_in09->Get("h_HLTPFMET_noPres");
  TH1F* GMSBStau200_RecoCaloMET_noPres_passMET_ = (TH1F*) f_in09->Get("h_RecoCaloMET_noPres_passMET");
  TH1F* GMSBStau200_RecoPFMET_noPres_passMET_ = (TH1F*) f_in09->Get("h_RecoPFMET_noPres_passMET");
  TH1F* GMSBStau200_HLTCaloMET_noPres_passMET_ = (TH1F*) f_in09->Get("h_HLTCaloMET_noPres_passMET");
  TH1F* GMSBStau200_HLTPFMET_noPres_passMET_ = (TH1F*) f_in09->Get("h_HLTPFMET_noPres_passMET");
  TH1F* GMSBStau200_RecoCaloMET_noPres_passMuon_ = (TH1F*) f_in09->Get("h_RecoCaloMET_noPres_passMuon");
  TH1F* GMSBStau200_RecoPFMET_noPres_passMuon_ = (TH1F*) f_in09->Get("h_RecoPFMET_noPres_passMuon");
  TH1F* GMSBStau200_HLTCaloMET_noPres_passMuon_ = (TH1F*) f_in09->Get("h_HLTCaloMET_noPres_passMuon");
  TH1F* GMSBStau200_HLTPFMET_noPres_passMuon_ = (TH1F*) f_in09->Get("h_HLTPFMET_noPres_passMuon");
  TH1F* GMSBStau200_RecoCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in09->Get("h_RecoCaloMET_noPres_passMETOrMuon");
  TH1F* GMSBStau200_RecoPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in09->Get("h_RecoPFMET_noPres_passMETOrMuon");
  TH1F* GMSBStau200_HLTCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in09->Get("h_HLTCaloMET_noPres_passMETOrMuon");
  TH1F* GMSBStau200_HLTPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in09->Get("h_HLTPFMET_noPres_passMETOrMuon");
  TH1F* GMSBStau200_RecoCaloMET_passPres_ = (TH1F*) f_in09->Get("h_RecoCaloMET_passPres");
  TH1F* GMSBStau200_RecoPFMET_passPres_ = (TH1F*) f_in09->Get("h_RecoPFMET_passPres");
  TH1F* GMSBStau200_HLTCaloMET_passPres_ = (TH1F*) f_in09->Get("h_HLTCaloMET_passPres");
  TH1F* GMSBStau200_HLTPFMET_passPres_ = (TH1F*) f_in09->Get("h_HLTPFMET_passPres");
  TH1F* GMSBStau200_RecoCaloMET_passPres_passMET_ = (TH1F*) f_in09->Get("h_RecoCaloMET_passPres_passMET");
  TH1F* GMSBStau200_RecoPFMET_passPres_passMET_ = (TH1F*) f_in09->Get("h_RecoPFMET_passPres_passMET");
  TH1F* GMSBStau200_HLTCaloMET_passPres_passMET_ = (TH1F*) f_in09->Get("h_HLTCaloMET_passPres_passMET");
  TH1F* GMSBStau200_HLTPFMET_passPres_passMET_ = (TH1F*) f_in09->Get("h_HLTPFMET_passPres_passMET");
  TH1F* GMSBStau200_RecoCaloMET_passPres_passMuon_ = (TH1F*) f_in09->Get("h_RecoCaloMET_passPres_passMuon");
  TH1F* GMSBStau200_RecoPFMET_passPres_passMuon_ = (TH1F*) f_in09->Get("h_RecoPFMET_passPres_passMuon");
  TH1F* GMSBStau200_HLTCaloMET_passPres_passMuon_ = (TH1F*) f_in09->Get("h_HLTCaloMET_passPres_passMuon");
  TH1F* GMSBStau200_HLTPFMET_passPres_passMuon_ = (TH1F*) f_in09->Get("h_HLTPFMET_passPres_passMuon");
  TH1F* GMSBStau200_RecoCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in09->Get("h_RecoCaloMET_passPres_passMETOrMuon");
  TH1F* GMSBStau200_RecoPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in09->Get("h_RecoPFMET_passPres_passMETOrMuon");
  TH1F* GMSBStau200_HLTCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in09->Get("h_HLTCaloMET_passPres_passMETOrMuon");
  TH1F* GMSBStau200_HLTPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in09->Get("h_HLTPFMET_passPres_passMETOrMuon");

  TH1F* GMSBStau432_RecoCaloMET_noPres_ = (TH1F*) f_in10->Get("h_RecoCaloMET_noPres");
  TH1F* GMSBStau432_RecoPFMET_noPres_ = (TH1F*) f_in10->Get("h_RecoPFMET_noPres");
  TH1F* GMSBStau432_HLTCaloMET_noPres_ = (TH1F*) f_in10->Get("h_HLTCaloMET_noPres");
  TH1F* GMSBStau432_HLTPFMET_noPres_ = (TH1F*) f_in10->Get("h_HLTPFMET_noPres");
  TH1F* GMSBStau432_RecoCaloMET_noPres_passMET_ = (TH1F*) f_in10->Get("h_RecoCaloMET_noPres_passMET");
  TH1F* GMSBStau432_RecoPFMET_noPres_passMET_ = (TH1F*) f_in10->Get("h_RecoPFMET_noPres_passMET");
  TH1F* GMSBStau432_HLTCaloMET_noPres_passMET_ = (TH1F*) f_in10->Get("h_HLTCaloMET_noPres_passMET");
  TH1F* GMSBStau432_HLTPFMET_noPres_passMET_ = (TH1F*) f_in10->Get("h_HLTPFMET_noPres_passMET");
  TH1F* GMSBStau432_RecoCaloMET_noPres_passMuon_ = (TH1F*) f_in10->Get("h_RecoCaloMET_noPres_passMuon");
  TH1F* GMSBStau432_RecoPFMET_noPres_passMuon_ = (TH1F*) f_in10->Get("h_RecoPFMET_noPres_passMuon");
  TH1F* GMSBStau432_HLTCaloMET_noPres_passMuon_ = (TH1F*) f_in10->Get("h_HLTCaloMET_noPres_passMuon");
  TH1F* GMSBStau432_HLTPFMET_noPres_passMuon_ = (TH1F*) f_in10->Get("h_HLTPFMET_noPres_passMuon");
  TH1F* GMSBStau432_RecoCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in10->Get("h_RecoCaloMET_noPres_passMETOrMuon");
  TH1F* GMSBStau432_RecoPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in10->Get("h_RecoPFMET_noPres_passMETOrMuon");
  TH1F* GMSBStau432_HLTCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in10->Get("h_HLTCaloMET_noPres_passMETOrMuon");
  TH1F* GMSBStau432_HLTPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in10->Get("h_HLTPFMET_noPres_passMETOrMuon");
  TH1F* GMSBStau432_RecoCaloMET_passPres_ = (TH1F*) f_in10->Get("h_RecoCaloMET_passPres");
  TH1F* GMSBStau432_RecoPFMET_passPres_ = (TH1F*) f_in10->Get("h_RecoPFMET_passPres");
  TH1F* GMSBStau432_HLTCaloMET_passPres_ = (TH1F*) f_in10->Get("h_HLTCaloMET_passPres");
  TH1F* GMSBStau432_HLTPFMET_passPres_ = (TH1F*) f_in10->Get("h_HLTPFMET_passPres");
  TH1F* GMSBStau432_RecoCaloMET_passPres_passMET_ = (TH1F*) f_in10->Get("h_RecoCaloMET_passPres_passMET");
  TH1F* GMSBStau432_RecoPFMET_passPres_passMET_ = (TH1F*) f_in10->Get("h_RecoPFMET_passPres_passMET");
  TH1F* GMSBStau432_HLTCaloMET_passPres_passMET_ = (TH1F*) f_in10->Get("h_HLTCaloMET_passPres_passMET");
  TH1F* GMSBStau432_HLTPFMET_passPres_passMET_ = (TH1F*) f_in10->Get("h_HLTPFMET_passPres_passMET");
  TH1F* GMSBStau432_RecoCaloMET_passPres_passMuon_ = (TH1F*) f_in10->Get("h_RecoCaloMET_passPres_passMuon");
  TH1F* GMSBStau432_RecoPFMET_passPres_passMuon_ = (TH1F*) f_in10->Get("h_RecoPFMET_passPres_passMuon");
  TH1F* GMSBStau432_HLTCaloMET_passPres_passMuon_ = (TH1F*) f_in10->Get("h_HLTCaloMET_passPres_passMuon");
  TH1F* GMSBStau432_HLTPFMET_passPres_passMuon_ = (TH1F*) f_in10->Get("h_HLTPFMET_passPres_passMuon");
  TH1F* GMSBStau432_RecoCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in10->Get("h_RecoCaloMET_passPres_passMETOrMuon");
  TH1F* GMSBStau432_RecoPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in10->Get("h_RecoPFMET_passPres_passMETOrMuon");
  TH1F* GMSBStau432_HLTCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in10->Get("h_HLTCaloMET_passPres_passMETOrMuon");
  TH1F* GMSBStau432_HLTPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in10->Get("h_HLTPFMET_passPres_passMETOrMuon");

  TH1F* GMSBStau651_RecoCaloMET_noPres_ = (TH1F*) f_in11->Get("h_RecoCaloMET_noPres");
  TH1F* GMSBStau651_RecoPFMET_noPres_ = (TH1F*) f_in11->Get("h_RecoPFMET_noPres");
  TH1F* GMSBStau651_HLTCaloMET_noPres_ = (TH1F*) f_in11->Get("h_HLTCaloMET_noPres");
  TH1F* GMSBStau651_HLTPFMET_noPres_ = (TH1F*) f_in11->Get("h_HLTPFMET_noPres");
  TH1F* GMSBStau651_RecoCaloMET_noPres_passMET_ = (TH1F*) f_in11->Get("h_RecoCaloMET_noPres_passMET");
  TH1F* GMSBStau651_RecoPFMET_noPres_passMET_ = (TH1F*) f_in11->Get("h_RecoPFMET_noPres_passMET");
  TH1F* GMSBStau651_HLTCaloMET_noPres_passMET_ = (TH1F*) f_in11->Get("h_HLTCaloMET_noPres_passMET");
  TH1F* GMSBStau651_HLTPFMET_noPres_passMET_ = (TH1F*) f_in11->Get("h_HLTPFMET_noPres_passMET");
  TH1F* GMSBStau651_RecoCaloMET_noPres_passMuon_ = (TH1F*) f_in11->Get("h_RecoCaloMET_noPres_passMuon");
  TH1F* GMSBStau651_RecoPFMET_noPres_passMuon_ = (TH1F*) f_in11->Get("h_RecoPFMET_noPres_passMuon");
  TH1F* GMSBStau651_HLTCaloMET_noPres_passMuon_ = (TH1F*) f_in11->Get("h_HLTCaloMET_noPres_passMuon");
  TH1F* GMSBStau651_HLTPFMET_noPres_passMuon_ = (TH1F*) f_in11->Get("h_HLTPFMET_noPres_passMuon");
  TH1F* GMSBStau651_RecoCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in11->Get("h_RecoCaloMET_noPres_passMETOrMuon");
  TH1F* GMSBStau651_RecoPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in11->Get("h_RecoPFMET_noPres_passMETOrMuon");
  TH1F* GMSBStau651_HLTCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in11->Get("h_HLTCaloMET_noPres_passMETOrMuon");
  TH1F* GMSBStau651_HLTPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in11->Get("h_HLTPFMET_noPres_passMETOrMuon");
  TH1F* GMSBStau651_RecoCaloMET_passPres_ = (TH1F*) f_in11->Get("h_RecoCaloMET_passPres");
  TH1F* GMSBStau651_RecoPFMET_passPres_ = (TH1F*) f_in11->Get("h_RecoPFMET_passPres");
  TH1F* GMSBStau651_HLTCaloMET_passPres_ = (TH1F*) f_in11->Get("h_HLTCaloMET_passPres");
  TH1F* GMSBStau651_HLTPFMET_passPres_ = (TH1F*) f_in11->Get("h_HLTPFMET_passPres");
  TH1F* GMSBStau651_RecoCaloMET_passPres_passMET_ = (TH1F*) f_in11->Get("h_RecoCaloMET_passPres_passMET");
  TH1F* GMSBStau651_RecoPFMET_passPres_passMET_ = (TH1F*) f_in11->Get("h_RecoPFMET_passPres_passMET");
  TH1F* GMSBStau651_HLTCaloMET_passPres_passMET_ = (TH1F*) f_in11->Get("h_HLTCaloMET_passPres_passMET");
  TH1F* GMSBStau651_HLTPFMET_passPres_passMET_ = (TH1F*) f_in11->Get("h_HLTPFMET_passPres_passMET");
  TH1F* GMSBStau651_RecoCaloMET_passPres_passMuon_ = (TH1F*) f_in11->Get("h_RecoCaloMET_passPres_passMuon");
  TH1F* GMSBStau651_RecoPFMET_passPres_passMuon_ = (TH1F*) f_in11->Get("h_RecoPFMET_passPres_passMuon");
  TH1F* GMSBStau651_HLTCaloMET_passPres_passMuon_ = (TH1F*) f_in11->Get("h_HLTCaloMET_passPres_passMuon");
  TH1F* GMSBStau651_HLTPFMET_passPres_passMuon_ = (TH1F*) f_in11->Get("h_HLTPFMET_passPres_passMuon");
  TH1F* GMSBStau651_RecoCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in11->Get("h_RecoCaloMET_passPres_passMETOrMuon");
  TH1F* GMSBStau651_RecoPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in11->Get("h_RecoPFMET_passPres_passMETOrMuon");
  TH1F* GMSBStau651_HLTCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in11->Get("h_HLTCaloMET_passPres_passMETOrMuon");
  TH1F* GMSBStau651_HLTPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in11->Get("h_HLTPFMET_passPres_passMETOrMuon");

  TH1F* GMSBStau871_RecoCaloMET_noPres_ = (TH1F*) f_in12->Get("h_RecoCaloMET_noPres");
  TH1F* GMSBStau871_RecoPFMET_noPres_ = (TH1F*) f_in12->Get("h_RecoPFMET_noPres");
  TH1F* GMSBStau871_HLTCaloMET_noPres_ = (TH1F*) f_in12->Get("h_HLTCaloMET_noPres");
  TH1F* GMSBStau871_HLTPFMET_noPres_ = (TH1F*) f_in12->Get("h_HLTPFMET_noPres");
  TH1F* GMSBStau871_RecoCaloMET_noPres_passMET_ = (TH1F*) f_in12->Get("h_RecoCaloMET_noPres_passMET");
  TH1F* GMSBStau871_RecoPFMET_noPres_passMET_ = (TH1F*) f_in12->Get("h_RecoPFMET_noPres_passMET");
  TH1F* GMSBStau871_HLTCaloMET_noPres_passMET_ = (TH1F*) f_in12->Get("h_HLTCaloMET_noPres_passMET");
  TH1F* GMSBStau871_HLTPFMET_noPres_passMET_ = (TH1F*) f_in12->Get("h_HLTPFMET_noPres_passMET");
  TH1F* GMSBStau871_RecoCaloMET_noPres_passMuon_ = (TH1F*) f_in12->Get("h_RecoCaloMET_noPres_passMuon");
  TH1F* GMSBStau871_RecoPFMET_noPres_passMuon_ = (TH1F*) f_in12->Get("h_RecoPFMET_noPres_passMuon");
  TH1F* GMSBStau871_HLTCaloMET_noPres_passMuon_ = (TH1F*) f_in12->Get("h_HLTCaloMET_noPres_passMuon");
  TH1F* GMSBStau871_HLTPFMET_noPres_passMuon_ = (TH1F*) f_in12->Get("h_HLTPFMET_noPres_passMuon");
  TH1F* GMSBStau871_RecoCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in12->Get("h_RecoCaloMET_noPres_passMETOrMuon");
  TH1F* GMSBStau871_RecoPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in12->Get("h_RecoPFMET_noPres_passMETOrMuon");
  TH1F* GMSBStau871_HLTCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in12->Get("h_HLTCaloMET_noPres_passMETOrMuon");
  TH1F* GMSBStau871_HLTPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in12->Get("h_HLTPFMET_noPres_passMETOrMuon");
  TH1F* GMSBStau871_RecoCaloMET_passPres_ = (TH1F*) f_in12->Get("h_RecoCaloMET_passPres");
  TH1F* GMSBStau871_RecoPFMET_passPres_ = (TH1F*) f_in12->Get("h_RecoPFMET_passPres");
  TH1F* GMSBStau871_HLTCaloMET_passPres_ = (TH1F*) f_in12->Get("h_HLTCaloMET_passPres");
  TH1F* GMSBStau871_HLTPFMET_passPres_ = (TH1F*) f_in12->Get("h_HLTPFMET_passPres");
  TH1F* GMSBStau871_RecoCaloMET_passPres_passMET_ = (TH1F*) f_in12->Get("h_RecoCaloMET_passPres_passMET");
  TH1F* GMSBStau871_RecoPFMET_passPres_passMET_ = (TH1F*) f_in12->Get("h_RecoPFMET_passPres_passMET");
  TH1F* GMSBStau871_HLTCaloMET_passPres_passMET_ = (TH1F*) f_in12->Get("h_HLTCaloMET_passPres_passMET");
  TH1F* GMSBStau871_HLTPFMET_passPres_passMET_ = (TH1F*) f_in12->Get("h_HLTPFMET_passPres_passMET");
  TH1F* GMSBStau871_RecoCaloMET_passPres_passMuon_ = (TH1F*) f_in12->Get("h_RecoCaloMET_passPres_passMuon");
  TH1F* GMSBStau871_RecoPFMET_passPres_passMuon_ = (TH1F*) f_in12->Get("h_RecoPFMET_passPres_passMuon");
  TH1F* GMSBStau871_HLTCaloMET_passPres_passMuon_ = (TH1F*) f_in12->Get("h_HLTCaloMET_passPres_passMuon");
  TH1F* GMSBStau871_HLTPFMET_passPres_passMuon_ = (TH1F*) f_in12->Get("h_HLTPFMET_passPres_passMuon");
  TH1F* GMSBStau871_RecoCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in12->Get("h_RecoCaloMET_passPres_passMETOrMuon");
  TH1F* GMSBStau871_RecoPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in12->Get("h_RecoPFMET_passPres_passMETOrMuon");
  TH1F* GMSBStau871_HLTCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in12->Get("h_HLTCaloMET_passPres_passMETOrMuon");
  TH1F* GMSBStau871_HLTPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in12->Get("h_HLTPFMET_passPres_passMETOrMuon");

  TH1F* PairStau200_RecoCaloMET_noPres_ = (TH1F*) f_in13->Get("h_RecoCaloMET_noPres");
  TH1F* PairStau200_RecoPFMET_noPres_ = (TH1F*) f_in13->Get("h_RecoPFMET_noPres");
  TH1F* PairStau200_HLTCaloMET_noPres_ = (TH1F*) f_in13->Get("h_HLTCaloMET_noPres");
  TH1F* PairStau200_HLTPFMET_noPres_ = (TH1F*) f_in13->Get("h_HLTPFMET_noPres");
  TH1F* PairStau200_RecoCaloMET_noPres_passMET_ = (TH1F*) f_in13->Get("h_RecoCaloMET_noPres_passMET");
  TH1F* PairStau200_RecoPFMET_noPres_passMET_ = (TH1F*) f_in13->Get("h_RecoPFMET_noPres_passMET");
  TH1F* PairStau200_HLTCaloMET_noPres_passMET_ = (TH1F*) f_in13->Get("h_HLTCaloMET_noPres_passMET");
  TH1F* PairStau200_HLTPFMET_noPres_passMET_ = (TH1F*) f_in13->Get("h_HLTPFMET_noPres_passMET");
  TH1F* PairStau200_RecoCaloMET_noPres_passMuon_ = (TH1F*) f_in13->Get("h_RecoCaloMET_noPres_passMuon");
  TH1F* PairStau200_RecoPFMET_noPres_passMuon_ = (TH1F*) f_in13->Get("h_RecoPFMET_noPres_passMuon");
  TH1F* PairStau200_HLTCaloMET_noPres_passMuon_ = (TH1F*) f_in13->Get("h_HLTCaloMET_noPres_passMuon");
  TH1F* PairStau200_HLTPFMET_noPres_passMuon_ = (TH1F*) f_in13->Get("h_HLTPFMET_noPres_passMuon");
  TH1F* PairStau200_RecoCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in13->Get("h_RecoCaloMET_noPres_passMETOrMuon");
  TH1F* PairStau200_RecoPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in13->Get("h_RecoPFMET_noPres_passMETOrMuon");
  TH1F* PairStau200_HLTCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in13->Get("h_HLTCaloMET_noPres_passMETOrMuon");
  TH1F* PairStau200_HLTPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in13->Get("h_HLTPFMET_noPres_passMETOrMuon");
  TH1F* PairStau200_RecoCaloMET_passPres_ = (TH1F*) f_in13->Get("h_RecoCaloMET_passPres");
  TH1F* PairStau200_RecoPFMET_passPres_ = (TH1F*) f_in13->Get("h_RecoPFMET_passPres");
  TH1F* PairStau200_HLTCaloMET_passPres_ = (TH1F*) f_in13->Get("h_HLTCaloMET_passPres");
  TH1F* PairStau200_HLTPFMET_passPres_ = (TH1F*) f_in13->Get("h_HLTPFMET_passPres");
  TH1F* PairStau200_RecoCaloMET_passPres_passMET_ = (TH1F*) f_in13->Get("h_RecoCaloMET_passPres_passMET");
  TH1F* PairStau200_RecoPFMET_passPres_passMET_ = (TH1F*) f_in13->Get("h_RecoPFMET_passPres_passMET");
  TH1F* PairStau200_HLTCaloMET_passPres_passMET_ = (TH1F*) f_in13->Get("h_HLTCaloMET_passPres_passMET");
  TH1F* PairStau200_HLTPFMET_passPres_passMET_ = (TH1F*) f_in13->Get("h_HLTPFMET_passPres_passMET");
  TH1F* PairStau200_RecoCaloMET_passPres_passMuon_ = (TH1F*) f_in13->Get("h_RecoCaloMET_passPres_passMuon");
  TH1F* PairStau200_RecoPFMET_passPres_passMuon_ = (TH1F*) f_in13->Get("h_RecoPFMET_passPres_passMuon");
  TH1F* PairStau200_HLTCaloMET_passPres_passMuon_ = (TH1F*) f_in13->Get("h_HLTCaloMET_passPres_passMuon");
  TH1F* PairStau200_HLTPFMET_passPres_passMuon_ = (TH1F*) f_in13->Get("h_HLTPFMET_passPres_passMuon");
  TH1F* PairStau200_RecoCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in13->Get("h_RecoCaloMET_passPres_passMETOrMuon");
  TH1F* PairStau200_RecoPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in13->Get("h_RecoPFMET_passPres_passMETOrMuon");
  TH1F* PairStau200_HLTCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in13->Get("h_HLTCaloMET_passPres_passMETOrMuon");
  TH1F* PairStau200_HLTPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in13->Get("h_HLTPFMET_passPres_passMETOrMuon");

  TH1F* PairStau432_RecoCaloMET_noPres_ = (TH1F*) f_in14->Get("h_RecoCaloMET_noPres");
  TH1F* PairStau432_RecoPFMET_noPres_ = (TH1F*) f_in14->Get("h_RecoPFMET_noPres");
  TH1F* PairStau432_HLTCaloMET_noPres_ = (TH1F*) f_in14->Get("h_HLTCaloMET_noPres");
  TH1F* PairStau432_HLTPFMET_noPres_ = (TH1F*) f_in14->Get("h_HLTPFMET_noPres");
  TH1F* PairStau432_RecoCaloMET_noPres_passMET_ = (TH1F*) f_in14->Get("h_RecoCaloMET_noPres_passMET");
  TH1F* PairStau432_RecoPFMET_noPres_passMET_ = (TH1F*) f_in14->Get("h_RecoPFMET_noPres_passMET");
  TH1F* PairStau432_HLTCaloMET_noPres_passMET_ = (TH1F*) f_in14->Get("h_HLTCaloMET_noPres_passMET");
  TH1F* PairStau432_HLTPFMET_noPres_passMET_ = (TH1F*) f_in14->Get("h_HLTPFMET_noPres_passMET");
  TH1F* PairStau432_RecoCaloMET_noPres_passMuon_ = (TH1F*) f_in14->Get("h_RecoCaloMET_noPres_passMuon");
  TH1F* PairStau432_RecoPFMET_noPres_passMuon_ = (TH1F*) f_in14->Get("h_RecoPFMET_noPres_passMuon");
  TH1F* PairStau432_HLTCaloMET_noPres_passMuon_ = (TH1F*) f_in14->Get("h_HLTCaloMET_noPres_passMuon");
  TH1F* PairStau432_HLTPFMET_noPres_passMuon_ = (TH1F*) f_in14->Get("h_HLTPFMET_noPres_passMuon");
  TH1F* PairStau432_RecoCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in14->Get("h_RecoCaloMET_noPres_passMETOrMuon");
  TH1F* PairStau432_RecoPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in14->Get("h_RecoPFMET_noPres_passMETOrMuon");
  TH1F* PairStau432_HLTCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in14->Get("h_HLTCaloMET_noPres_passMETOrMuon");
  TH1F* PairStau432_HLTPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in14->Get("h_HLTPFMET_noPres_passMETOrMuon");
  TH1F* PairStau432_RecoCaloMET_passPres_ = (TH1F*) f_in14->Get("h_RecoCaloMET_passPres");
  TH1F* PairStau432_RecoPFMET_passPres_ = (TH1F*) f_in14->Get("h_RecoPFMET_passPres");
  TH1F* PairStau432_HLTCaloMET_passPres_ = (TH1F*) f_in14->Get("h_HLTCaloMET_passPres");
  TH1F* PairStau432_HLTPFMET_passPres_ = (TH1F*) f_in14->Get("h_HLTPFMET_passPres");
  TH1F* PairStau432_RecoCaloMET_passPres_passMET_ = (TH1F*) f_in14->Get("h_RecoCaloMET_passPres_passMET");
  TH1F* PairStau432_RecoPFMET_passPres_passMET_ = (TH1F*) f_in14->Get("h_RecoPFMET_passPres_passMET");
  TH1F* PairStau432_HLTCaloMET_passPres_passMET_ = (TH1F*) f_in14->Get("h_HLTCaloMET_passPres_passMET");
  TH1F* PairStau432_HLTPFMET_passPres_passMET_ = (TH1F*) f_in14->Get("h_HLTPFMET_passPres_passMET");
  TH1F* PairStau432_RecoCaloMET_passPres_passMuon_ = (TH1F*) f_in14->Get("h_RecoCaloMET_passPres_passMuon");
  TH1F* PairStau432_RecoPFMET_passPres_passMuon_ = (TH1F*) f_in14->Get("h_RecoPFMET_passPres_passMuon");
  TH1F* PairStau432_HLTCaloMET_passPres_passMuon_ = (TH1F*) f_in14->Get("h_HLTCaloMET_passPres_passMuon");
  TH1F* PairStau432_HLTPFMET_passPres_passMuon_ = (TH1F*) f_in14->Get("h_HLTPFMET_passPres_passMuon");
  TH1F* PairStau432_RecoCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in14->Get("h_RecoCaloMET_passPres_passMETOrMuon");
  TH1F* PairStau432_RecoPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in14->Get("h_RecoPFMET_passPres_passMETOrMuon");
  TH1F* PairStau432_HLTCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in14->Get("h_HLTCaloMET_passPres_passMETOrMuon");
  TH1F* PairStau432_HLTPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in14->Get("h_HLTPFMET_passPres_passMETOrMuon");

  TH1F* PairStau651_RecoCaloMET_noPres_ = (TH1F*) f_in15->Get("h_RecoCaloMET_noPres");
  TH1F* PairStau651_RecoPFMET_noPres_ = (TH1F*) f_in15->Get("h_RecoPFMET_noPres");
  TH1F* PairStau651_HLTCaloMET_noPres_ = (TH1F*) f_in15->Get("h_HLTCaloMET_noPres");
  TH1F* PairStau651_HLTPFMET_noPres_ = (TH1F*) f_in15->Get("h_HLTPFMET_noPres");
  TH1F* PairStau651_RecoCaloMET_noPres_passMET_ = (TH1F*) f_in15->Get("h_RecoCaloMET_noPres_passMET");
  TH1F* PairStau651_RecoPFMET_noPres_passMET_ = (TH1F*) f_in15->Get("h_RecoPFMET_noPres_passMET");
  TH1F* PairStau651_HLTCaloMET_noPres_passMET_ = (TH1F*) f_in15->Get("h_HLTCaloMET_noPres_passMET");
  TH1F* PairStau651_HLTPFMET_noPres_passMET_ = (TH1F*) f_in15->Get("h_HLTPFMET_noPres_passMET");
  TH1F* PairStau651_RecoCaloMET_noPres_passMuon_ = (TH1F*) f_in15->Get("h_RecoCaloMET_noPres_passMuon");
  TH1F* PairStau651_RecoPFMET_noPres_passMuon_ = (TH1F*) f_in15->Get("h_RecoPFMET_noPres_passMuon");
  TH1F* PairStau651_HLTCaloMET_noPres_passMuon_ = (TH1F*) f_in15->Get("h_HLTCaloMET_noPres_passMuon");
  TH1F* PairStau651_HLTPFMET_noPres_passMuon_ = (TH1F*) f_in15->Get("h_HLTPFMET_noPres_passMuon");
  TH1F* PairStau651_RecoCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in15->Get("h_RecoCaloMET_noPres_passMETOrMuon");
  TH1F* PairStau651_RecoPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in15->Get("h_RecoPFMET_noPres_passMETOrMuon");
  TH1F* PairStau651_HLTCaloMET_noPres_passMETOrMuon_ = (TH1F*) f_in15->Get("h_HLTCaloMET_noPres_passMETOrMuon");
  TH1F* PairStau651_HLTPFMET_noPres_passMETOrMuon_ = (TH1F*) f_in15->Get("h_HLTPFMET_noPres_passMETOrMuon");
  TH1F* PairStau651_RecoCaloMET_passPres_ = (TH1F*) f_in15->Get("h_RecoCaloMET_passPres");
  TH1F* PairStau651_RecoPFMET_passPres_ = (TH1F*) f_in15->Get("h_RecoPFMET_passPres");
  TH1F* PairStau651_HLTCaloMET_passPres_ = (TH1F*) f_in15->Get("h_HLTCaloMET_passPres");
  TH1F* PairStau651_HLTPFMET_passPres_ = (TH1F*) f_in15->Get("h_HLTPFMET_passPres");
  TH1F* PairStau651_RecoCaloMET_passPres_passMET_ = (TH1F*) f_in15->Get("h_RecoCaloMET_passPres_passMET");
  TH1F* PairStau651_RecoPFMET_passPres_passMET_ = (TH1F*) f_in15->Get("h_RecoPFMET_passPres_passMET");
  TH1F* PairStau651_HLTCaloMET_passPres_passMET_ = (TH1F*) f_in15->Get("h_HLTCaloMET_passPres_passMET");
  TH1F* PairStau651_HLTPFMET_passPres_passMET_ = (TH1F*) f_in15->Get("h_HLTPFMET_passPres_passMET");
  TH1F* PairStau651_RecoCaloMET_passPres_passMuon_ = (TH1F*) f_in15->Get("h_RecoCaloMET_passPres_passMuon");
  TH1F* PairStau651_RecoPFMET_passPres_passMuon_ = (TH1F*) f_in15->Get("h_RecoPFMET_passPres_passMuon");
  TH1F* PairStau651_HLTCaloMET_passPres_passMuon_ = (TH1F*) f_in15->Get("h_HLTCaloMET_passPres_passMuon");
  TH1F* PairStau651_HLTPFMET_passPres_passMuon_ = (TH1F*) f_in15->Get("h_HLTPFMET_passPres_passMuon");
  TH1F* PairStau651_RecoCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in15->Get("h_RecoCaloMET_passPres_passMETOrMuon");
  TH1F* PairStau651_RecoPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in15->Get("h_RecoPFMET_passPres_passMETOrMuon");
  TH1F* PairStau651_HLTCaloMET_passPres_passMETOrMuon_ = (TH1F*) f_in15->Get("h_HLTCaloMET_passPres_passMETOrMuon");
  TH1F* PairStau651_HLTPFMET_passPres_passMETOrMuon_ = (TH1F*) f_in15->Get("h_HLTPFMET_passPres_passMETOrMuon");




  //create canvas
  TCanvas* c_met = new TCanvas("c_met","c_met");
  c_met->SetGrid(1,1);
  c_met->cd();



  // (trigger x3) X (MET x4) X (noPres,passPres) = 24 plots per sample
  // -----------------------------------------------------------------
  // 01) MET trigger efficiency vs RECO Calo MET, no preselection
  // 02) MET trigger efficiency vs RECO Calo MET, pass preselection
  // 03) Muon trigger efficiency vs RECO Calo MET, no preselection
  // 04) Muon trigger efficiency vs RECO Calo MET, pass preselection
  // 05) MET or Muon trigger efficiency vs RECO Calo MET, no preselection
  // 06) MET or Muon trigger efficiency vs RECO Calo MET, pass preselection
  // 07) MET trigger efficiency vs RECO PF MET, no preselection
  // 08) MET trigger efficiency vs RECO PF MET, pass preselection
  // 09) Muon trigger efficiency vs RECO PF MET, no preselection
  // 10) Muon trigger efficiency vs RECO PF MET, pass preselection
  // 11) MET or Muon trigger efficiency vs RECO PF MET, no preselection
  // 12) MET or Muon trigger efficiency vs RECO PF MET, pass preselection
  // 13) MET trigger efficiency vs HLT Calo MET, no preselection
  // 14) MET trigger efficiency vs HLT Calo MET, pass preselection
  // 15) Muon trigger efficiency vs HLT Calo MET, no preselection
  // 16) Muon trigger efficiency vs HLT Calo MET, pass preselection
  // 17) MET or Muon trigger efficiency vs HLT Calo MET, no preselection
  // 18) MET or Muon trigger efficiency vs HLT Calo MET, pass preselection
  // 19) MET trigger efficiency vs HLT PF MET, no preselection
  // 20) MET trigger efficiency vs HLT PF MET, pass preselection
  // 21) Muon trigger efficiency vs HLT PF MET, no preselection
  // 22) Muon trigger efficiency vs HLT PF MET, pass preselection
  // 23) MET or Muon trigger efficiency vs HLT PF MET, no preselection
  // 24) MET or Muon trigger efficiency vs HLT PF MET, pass preselection


  //=====================
  //   GLUINO 800 GeV  
  //=====================

  /*
  // 01.1) MET trigger efficiency vs RECO Calo MET, no preselection
  TH2F* Gluino800_METEff_RecoCaloMET_noPres = new TH2F("Gluino800_METEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino800_METEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino800_METEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* Gluino800_METEff_RecoCaloMET_noPres_TEff = new TEfficiency(*Gluino800_RecoCaloMET_noPres_passMET_,*Gluino800_RecoCaloMET_noPres_);
  Gluino800_METEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  Gluino800_METEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino800_METEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino800_METEff_RecoCaloMET_noPres.png");
  */

  // 01.2) MET trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* Gluino800_METEff_RecoCaloMET_passPres = new TH2F("Gluino800_METEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino800_METEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino800_METEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* Gluino800_METEff_RecoCaloMET_passPres_TEff = new TEfficiency(*Gluino800_RecoCaloMET_passPres_passMET_,*Gluino800_RecoCaloMET_passPres_);
  Gluino800_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino800_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino800_METEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino800_METEff_RecoCaloMET_passPres.png");

  /*
  // 01.3) Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* Gluino800_MuonEff_RecoCaloMET_noPres = new TH2F("Gluino800_MuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino800_MuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino800_MuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* Gluino800_MuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*Gluino800_RecoCaloMET_noPres_passMuon_,*Gluino800_RecoCaloMET_noPres_);
  Gluino800_MuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  Gluino800_MuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino800_MuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino800_MuonEff_RecoCaloMET_noPres.png");
  */

  // 01.4) Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* Gluino800_MuonEff_RecoCaloMET_passPres = new TH2F("Gluino800_MuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino800_MuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino800_MuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* Gluino800_MuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*Gluino800_RecoCaloMET_passPres_passMuon_,*Gluino800_RecoCaloMET_passPres_);
  Gluino800_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino800_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino800_MuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino800_MuonEff_RecoCaloMET_passPres.png");

  /*
  // 01.5) MET or Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* Gluino800_METOrMuonEff_RecoCaloMET_noPres = new TH2F("Gluino800_METOrMuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino800_METOrMuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino800_METOrMuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* Gluino800_METOrMuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*Gluino800_RecoCaloMET_noPres_passMETOrMuon_,*Gluino800_RecoCaloMET_noPres_);
  Gluino800_METOrMuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  Gluino800_METOrMuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino800_METOrMuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino800_METOrMuonEff_RecoCaloMET_noPres.png");
  */

  // 01.6) MET or Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* Gluino800_METOrMuonEff_RecoCaloMET_passPres = new TH2F("Gluino800_METOrMuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino800_METOrMuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino800_METOrMuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* Gluino800_METOrMuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*Gluino800_RecoCaloMET_passPres_passMETOrMuon_,*Gluino800_RecoCaloMET_passPres_);
  Gluino800_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino800_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino800_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino800_METOrMuonEff_RecoCaloMET_passPres.png");

  /*
  // 01.7) MET trigger efficiency vs RECO PF MET, no preselection
  TH2F* Gluino800_METEff_RecoPFMET_noPres = new TH2F("Gluino800_METEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino800_METEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino800_METEff_RecoPFMET_noPres->Draw();  
  TEfficiency* Gluino800_METEff_RecoPFMET_noPres_TEff = new TEfficiency(*Gluino800_RecoPFMET_noPres_passMET_,*Gluino800_RecoPFMET_noPres_);
  Gluino800_METEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  Gluino800_METEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino800_METEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino800_METEff_RecoPFMET_noPres.png");
  */

  // 01.8) MET trigger efficiency vs RECO PF MET, pass preselection
  TH2F* Gluino800_METEff_RecoPFMET_passPres = new TH2F("Gluino800_METEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino800_METEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino800_METEff_RecoPFMET_passPres->Draw();  
  TEfficiency* Gluino800_METEff_RecoPFMET_passPres_TEff = new TEfficiency(*Gluino800_RecoPFMET_passPres_passMET_,*Gluino800_RecoPFMET_passPres_);
  Gluino800_METEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino800_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino800_METEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino800_METEff_RecoPFMET_passPres.png");

  /*
  // 01.9) Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* Gluino800_MuonEff_RecoPFMET_noPres = new TH2F("Gluino800_MuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino800_MuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino800_MuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* Gluino800_MuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*Gluino800_RecoPFMET_noPres_passMuon_,*Gluino800_RecoPFMET_noPres_);
  Gluino800_MuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  Gluino800_MuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino800_MuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino800_MuonEff_RecoPFMET_noPres.png");
  */

  // 01.10) Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* Gluino800_MuonEff_RecoPFMET_passPres = new TH2F("Gluino800_MuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino800_MuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino800_MuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* Gluino800_MuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*Gluino800_RecoPFMET_passPres_passMuon_,*Gluino800_RecoPFMET_passPres_);
  Gluino800_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino800_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino800_MuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino800_MuonEff_RecoPFMET_passPres.png");

  /*
  // 01.11) MET or Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* Gluino800_METOrMuonEff_RecoPFMET_noPres = new TH2F("Gluino800_METOrMuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino800_METOrMuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino800_METOrMuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* Gluino800_METOrMuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*Gluino800_RecoPFMET_noPres_passMETOrMuon_,*Gluino800_RecoPFMET_noPres_);
  Gluino800_METOrMuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  Gluino800_METOrMuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino800_METOrMuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino800_METOrMuonEff_RecoPFMET_noPres.png");
  */

  // 01.12) MET or Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* Gluino800_METOrMuonEff_RecoPFMET_passPres = new TH2F("Gluino800_METOrMuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino800_METOrMuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino800_METOrMuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* Gluino800_METOrMuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*Gluino800_RecoPFMET_passPres_passMETOrMuon_,*Gluino800_RecoPFMET_passPres_);
  Gluino800_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino800_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino800_METOrMuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino800_METOrMuonEff_RecoPFMET_passPres.png");

  /*
  // 01.13) MET trigger efficiency vs HLT Calo MET, no preselection
  TH2F* Gluino800_METEff_HLTCaloMET_noPres = new TH2F("Gluino800_METEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino800_METEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino800_METEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* Gluino800_METEff_HLTCaloMET_noPres_TEff = new TEfficiency(*Gluino800_HLTCaloMET_noPres_passMET_,*Gluino800_HLTCaloMET_noPres_);
  Gluino800_METEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  Gluino800_METEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino800_METEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino800_METEff_HLTCaloMET_noPres.png");
  */

  // 01.14) MET trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* Gluino800_METEff_HLTCaloMET_passPres = new TH2F("Gluino800_METEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino800_METEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino800_METEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* Gluino800_METEff_HLTCaloMET_passPres_TEff = new TEfficiency(*Gluino800_HLTCaloMET_passPres_passMET_,*Gluino800_HLTCaloMET_passPres_);
  Gluino800_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino800_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino800_METEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino800_METEff_HLTCaloMET_passPres.png");

  /*
  // 01.15) Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* Gluino800_MuonEff_HLTCaloMET_noPres = new TH2F("Gluino800_MuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino800_MuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino800_MuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* Gluino800_MuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*Gluino800_HLTCaloMET_noPres_passMuon_,*Gluino800_HLTCaloMET_noPres_);
  Gluino800_MuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  Gluino800_MuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino800_MuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino800_MuonEff_HLTCaloMET_noPres.png");
  */

  // 01.16) Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* Gluino800_MuonEff_HLTCaloMET_passPres = new TH2F("Gluino800_MuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino800_MuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino800_MuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* Gluino800_MuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*Gluino800_HLTCaloMET_passPres_passMuon_,*Gluino800_HLTCaloMET_passPres_);
  Gluino800_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino800_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino800_MuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino800_MuonEff_HLTCaloMET_passPres.png");

  /*
  // 01.17) MET or Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* Gluino800_METOrMuonEff_HLTCaloMET_noPres = new TH2F("Gluino800_METOrMuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino800_METOrMuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino800_METOrMuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* Gluino800_METOrMuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*Gluino800_HLTCaloMET_noPres_passMETOrMuon_,*Gluino800_HLTCaloMET_noPres_);
  Gluino800_METOrMuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  Gluino800_METOrMuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino800_METOrMuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino800_METOrMuonEff_HLTCaloMET_noPres.png");
  */

  // 01.18) MET or Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* Gluino800_METOrMuonEff_HLTCaloMET_passPres = new TH2F("Gluino800_METOrMuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino800_METOrMuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino800_METOrMuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* Gluino800_METOrMuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*Gluino800_HLTCaloMET_passPres_passMETOrMuon_,*Gluino800_HLTCaloMET_passPres_);
  Gluino800_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino800_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino800_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino800_METOrMuonEff_HLTCaloMET_passPres.png");

  /*
  // 01.19) MET trigger efficiency vs HLT PF MET, no preselection
  TH2F* Gluino800_METEff_HLTPFMET_noPres = new TH2F("Gluino800_METEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino800_METEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino800_METEff_HLTPFMET_noPres->Draw();  
  TEfficiency* Gluino800_METEff_HLTPFMET_noPres_TEff = new TEfficiency(*Gluino800_HLTPFMET_noPres_passMET_,*Gluino800_HLTPFMET_noPres_);
  Gluino800_METEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  Gluino800_METEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino800_METEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino800_METEff_HLTPFMET_noPres.png");
  */

  // 01.20) MET trigger efficiency vs HLT PF MET, pass preselection
  TH2F* Gluino800_METEff_HLTPFMET_passPres = new TH2F("Gluino800_METEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino800_METEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino800_METEff_HLTPFMET_passPres->Draw();  
  TEfficiency* Gluino800_METEff_HLTPFMET_passPres_TEff = new TEfficiency(*Gluino800_HLTPFMET_passPres_passMET_,*Gluino800_HLTPFMET_passPres_);
  Gluino800_METEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino800_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino800_METEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino800_METEff_HLTPFMET_passPres.png");

  /*
  // 01.21) Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* Gluino800_MuonEff_HLTPFMET_noPres = new TH2F("Gluino800_MuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino800_MuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino800_MuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* Gluino800_MuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*Gluino800_HLTPFMET_noPres_passMuon_,*Gluino800_HLTPFMET_noPres_);
  Gluino800_MuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  Gluino800_MuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino800_MuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino800_MuonEff_HLTPFMET_noPres.png");
  */

  // 01.22) Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* Gluino800_MuonEff_HLTPFMET_passPres = new TH2F("Gluino800_MuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino800_MuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino800_MuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* Gluino800_MuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*Gluino800_HLTPFMET_passPres_passMuon_,*Gluino800_HLTPFMET_passPres_);
  Gluino800_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino800_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino800_MuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino800_MuonEff_HLTPFMET_passPres.png");

  /* // 01.23) MET or Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* Gluino800_METOrMuonEff_HLTPFMET_noPres = new TH2F("Gluino800_METOrMuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino800_METOrMuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino800_METOrMuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* Gluino800_METOrMuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*Gluino800_HLTPFMET_noPres_passMETOrMuon_,*Gluino800_HLTPFMET_noPres_);
  Gluino800_METOrMuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  Gluino800_METOrMuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino800_METOrMuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino800_METOrMuonEff_HLTPFMET_noPres.png"); */

  // 01.24) MET or Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* Gluino800_METOrMuonEff_HLTPFMET_passPres = new TH2F("Gluino800_METOrMuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino800_METOrMuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino800_METOrMuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* Gluino800_METOrMuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*Gluino800_HLTPFMET_passPres_passMETOrMuon_,*Gluino800_HLTPFMET_passPres_);
  Gluino800_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino800_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino800_METOrMuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino800_METOrMuonEff_HLTPFMET_passPres.png");

  //=====================
  //   GLUINO 1400 GeV  
  //=====================

  /* // 02.1) MET trigger efficiency vs RECO Calo MET, no preselection
  TH2F* Gluino1400_METEff_RecoCaloMET_noPres = new TH2F("Gluino1400_METEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino1400_METEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1400_METEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* Gluino1400_METEff_RecoCaloMET_noPres_TEff = new TEfficiency(*Gluino1400_RecoCaloMET_noPres_passMET_,*Gluino1400_RecoCaloMET_noPres_);
  Gluino1400_METEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  Gluino1400_METEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino1400_METEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1400_METEff_RecoCaloMET_noPres.png"); */

  // 02.2) MET trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* Gluino1400_METEff_RecoCaloMET_passPres = new TH2F("Gluino1400_METEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino1400_METEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1400_METEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* Gluino1400_METEff_RecoCaloMET_passPres_TEff = new TEfficiency(*Gluino1400_RecoCaloMET_passPres_passMET_,*Gluino1400_RecoCaloMET_passPres_);
  Gluino1400_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino1400_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1400_METEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1400_METEff_RecoCaloMET_passPres.png");

  /* // 02.3) Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* Gluino1400_MuonEff_RecoCaloMET_noPres = new TH2F("Gluino1400_MuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1400_MuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1400_MuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* Gluino1400_MuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*Gluino1400_RecoCaloMET_noPres_passMuon_,*Gluino1400_RecoCaloMET_noPres_);
  Gluino1400_MuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  Gluino1400_MuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino1400_MuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1400_MuonEff_RecoCaloMET_noPres.png"); */

  // 02.4) Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* Gluino1400_MuonEff_RecoCaloMET_passPres = new TH2F("Gluino1400_MuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1400_MuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1400_MuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* Gluino1400_MuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*Gluino1400_RecoCaloMET_passPres_passMuon_,*Gluino1400_RecoCaloMET_passPres_);
  Gluino1400_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino1400_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1400_MuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1400_MuonEff_RecoCaloMET_passPres.png");

  /* // 02.5) MET or Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* Gluino1400_METOrMuonEff_RecoCaloMET_noPres = new TH2F("Gluino1400_METOrMuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1400_METOrMuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1400_METOrMuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* Gluino1400_METOrMuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*Gluino1400_RecoCaloMET_noPres_passMETOrMuon_,*Gluino1400_RecoCaloMET_noPres_);
  Gluino1400_METOrMuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  Gluino1400_METOrMuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino1400_METOrMuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1400_METOrMuonEff_RecoCaloMET_noPres.png"); */

  // 02.6) MET or Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* Gluino1400_METOrMuonEff_RecoCaloMET_passPres = new TH2F("Gluino1400_METOrMuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1400_METOrMuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1400_METOrMuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* Gluino1400_METOrMuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*Gluino1400_RecoCaloMET_passPres_passMETOrMuon_,*Gluino1400_RecoCaloMET_passPres_);
  Gluino1400_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino1400_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1400_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1400_METOrMuonEff_RecoCaloMET_passPres.png");

  /* // 02.7) MET trigger efficiency vs RECO PF MET, no preselection
  TH2F* Gluino1400_METEff_RecoPFMET_noPres = new TH2F("Gluino1400_METEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino1400_METEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1400_METEff_RecoPFMET_noPres->Draw();  
  TEfficiency* Gluino1400_METEff_RecoPFMET_noPres_TEff = new TEfficiency(*Gluino1400_RecoPFMET_noPres_passMET_,*Gluino1400_RecoPFMET_noPres_);
  Gluino1400_METEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  Gluino1400_METEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino1400_METEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1400_METEff_RecoPFMET_noPres.png"); */

  // 02.8) MET trigger efficiency vs RECO PF MET, pass preselection
  TH2F* Gluino1400_METEff_RecoPFMET_passPres = new TH2F("Gluino1400_METEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino1400_METEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1400_METEff_RecoPFMET_passPres->Draw();  
  TEfficiency* Gluino1400_METEff_RecoPFMET_passPres_TEff = new TEfficiency(*Gluino1400_RecoPFMET_passPres_passMET_,*Gluino1400_RecoPFMET_passPres_);
  Gluino1400_METEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino1400_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1400_METEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1400_METEff_RecoPFMET_passPres.png");

  /* // 02.9) Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* Gluino1400_MuonEff_RecoPFMET_noPres = new TH2F("Gluino1400_MuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1400_MuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1400_MuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* Gluino1400_MuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*Gluino1400_RecoPFMET_noPres_passMuon_,*Gluino1400_RecoPFMET_noPres_);
  Gluino1400_MuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  Gluino1400_MuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino1400_MuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1400_MuonEff_RecoPFMET_noPres.png"); */

  // 02.10) Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* Gluino1400_MuonEff_RecoPFMET_passPres = new TH2F("Gluino1400_MuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1400_MuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1400_MuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* Gluino1400_MuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*Gluino1400_RecoPFMET_passPres_passMuon_,*Gluino1400_RecoPFMET_passPres_);
  Gluino1400_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino1400_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1400_MuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1400_MuonEff_RecoPFMET_passPres.png");

  /* // 02.11) MET or Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* Gluino1400_METOrMuonEff_RecoPFMET_noPres = new TH2F("Gluino1400_METOrMuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1400_METOrMuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1400_METOrMuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* Gluino1400_METOrMuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*Gluino1400_RecoPFMET_noPres_passMETOrMuon_,*Gluino1400_RecoPFMET_noPres_);
  Gluino1400_METOrMuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  Gluino1400_METOrMuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino1400_METOrMuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1400_METOrMuonEff_RecoPFMET_noPres.png"); */

  // 02.12) MET or Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* Gluino1400_METOrMuonEff_RecoPFMET_passPres = new TH2F("Gluino1400_METOrMuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1400_METOrMuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1400_METOrMuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* Gluino1400_METOrMuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*Gluino1400_RecoPFMET_passPres_passMETOrMuon_,*Gluino1400_RecoPFMET_passPres_);
  Gluino1400_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino1400_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1400_METOrMuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1400_METOrMuonEff_RecoPFMET_passPres.png");

  /* // 02.13) MET trigger efficiency vs HLT Calo MET, no preselection
  TH2F* Gluino1400_METEff_HLTCaloMET_noPres = new TH2F("Gluino1400_METEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino1400_METEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1400_METEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* Gluino1400_METEff_HLTCaloMET_noPres_TEff = new TEfficiency(*Gluino1400_HLTCaloMET_noPres_passMET_,*Gluino1400_HLTCaloMET_noPres_);
  Gluino1400_METEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  Gluino1400_METEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino1400_METEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1400_METEff_HLTCaloMET_noPres.png"); */

  // 02.14) MET trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* Gluino1400_METEff_HLTCaloMET_passPres = new TH2F("Gluino1400_METEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino1400_METEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1400_METEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* Gluino1400_METEff_HLTCaloMET_passPres_TEff = new TEfficiency(*Gluino1400_HLTCaloMET_passPres_passMET_,*Gluino1400_HLTCaloMET_passPres_);
  Gluino1400_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino1400_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1400_METEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1400_METEff_HLTCaloMET_passPres.png");

  /* // 02.15) Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* Gluino1400_MuonEff_HLTCaloMET_noPres = new TH2F("Gluino1400_MuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1400_MuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1400_MuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* Gluino1400_MuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*Gluino1400_HLTCaloMET_noPres_passMuon_,*Gluino1400_HLTCaloMET_noPres_);
  Gluino1400_MuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  Gluino1400_MuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino1400_MuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1400_MuonEff_HLTCaloMET_noPres.png"); */

  // 02.16) Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* Gluino1400_MuonEff_HLTCaloMET_passPres = new TH2F("Gluino1400_MuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1400_MuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1400_MuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* Gluino1400_MuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*Gluino1400_HLTCaloMET_passPres_passMuon_,*Gluino1400_HLTCaloMET_passPres_);
  Gluino1400_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino1400_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1400_MuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1400_MuonEff_HLTCaloMET_passPres.png");

  /* // 02.17) MET or Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* Gluino1400_METOrMuonEff_HLTCaloMET_noPres = new TH2F("Gluino1400_METOrMuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1400_METOrMuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1400_METOrMuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* Gluino1400_METOrMuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*Gluino1400_HLTCaloMET_noPres_passMETOrMuon_,*Gluino1400_HLTCaloMET_noPres_);
  Gluino1400_METOrMuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  Gluino1400_METOrMuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino1400_METOrMuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1400_METOrMuonEff_HLTCaloMET_noPres.png"); */

  // 02.18) MET or Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* Gluino1400_METOrMuonEff_HLTCaloMET_passPres = new TH2F("Gluino1400_METOrMuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1400_METOrMuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1400_METOrMuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* Gluino1400_METOrMuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*Gluino1400_HLTCaloMET_passPres_passMETOrMuon_,*Gluino1400_HLTCaloMET_passPres_);
  Gluino1400_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino1400_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1400_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1400_METOrMuonEff_HLTCaloMET_passPres.png");

  /* // 02.19) MET trigger efficiency vs HLT PF MET, no preselection
  TH2F* Gluino1400_METEff_HLTPFMET_noPres = new TH2F("Gluino1400_METEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino1400_METEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1400_METEff_HLTPFMET_noPres->Draw();  
  TEfficiency* Gluino1400_METEff_HLTPFMET_noPres_TEff = new TEfficiency(*Gluino1400_HLTPFMET_noPres_passMET_,*Gluino1400_HLTPFMET_noPres_);
  Gluino1400_METEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  Gluino1400_METEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino1400_METEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1400_METEff_HLTPFMET_noPres.png"); */

  // 02.20) MET trigger efficiency vs HLT PF MET, pass preselection
  TH2F* Gluino1400_METEff_HLTPFMET_passPres = new TH2F("Gluino1400_METEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino1400_METEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1400_METEff_HLTPFMET_passPres->Draw();  
  TEfficiency* Gluino1400_METEff_HLTPFMET_passPres_TEff = new TEfficiency(*Gluino1400_HLTPFMET_passPres_passMET_,*Gluino1400_HLTPFMET_passPres_);
  Gluino1400_METEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino1400_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1400_METEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1400_METEff_HLTPFMET_passPres.png");

  /* // 02.21) Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* Gluino1400_MuonEff_HLTPFMET_noPres = new TH2F("Gluino1400_MuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1400_MuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1400_MuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* Gluino1400_MuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*Gluino1400_HLTPFMET_noPres_passMuon_,*Gluino1400_HLTPFMET_noPres_);
  Gluino1400_MuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  Gluino1400_MuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino1400_MuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1400_MuonEff_HLTPFMET_noPres.png"); */

  // 02.22) Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* Gluino1400_MuonEff_HLTPFMET_passPres = new TH2F("Gluino1400_MuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1400_MuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1400_MuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* Gluino1400_MuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*Gluino1400_HLTPFMET_passPres_passMuon_,*Gluino1400_HLTPFMET_passPres_);
  Gluino1400_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino1400_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1400_MuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1400_MuonEff_HLTPFMET_passPres.png");

  /* // 02.23) MET or Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* Gluino1400_METOrMuonEff_HLTPFMET_noPres = new TH2F("Gluino1400_METOrMuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1400_METOrMuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1400_METOrMuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* Gluino1400_METOrMuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*Gluino1400_HLTPFMET_noPres_passMETOrMuon_,*Gluino1400_HLTPFMET_noPres_);
  Gluino1400_METOrMuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  Gluino1400_METOrMuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino1400_METOrMuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1400_METOrMuonEff_HLTPFMET_noPres.png"); */

  // 02.24) MET or Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* Gluino1400_METOrMuonEff_HLTPFMET_passPres = new TH2F("Gluino1400_METOrMuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1400_METOrMuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1400_METOrMuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* Gluino1400_METOrMuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*Gluino1400_HLTPFMET_passPres_passMETOrMuon_,*Gluino1400_HLTPFMET_passPres_);
  Gluino1400_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino1400_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1400_METOrMuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1400_METOrMuonEff_HLTPFMET_passPres.png");

  //=====================
  //   GLUINO 1800 GeV  
  //=====================

  /* // 03.1) MET trigger efficiency vs RECO Calo MET, no preselection
  TH2F* Gluino1800_METEff_RecoCaloMET_noPres = new TH2F("Gluino1800_METEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_METEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_METEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* Gluino1800_METEff_RecoCaloMET_noPres_TEff = new TEfficiency(*Gluino1800_RecoCaloMET_noPres_passMET_,*Gluino1800_RecoCaloMET_noPres_);
  Gluino1800_METEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  Gluino1800_METEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino1800_METEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1800_METEff_RecoCaloMET_noPres.png"); */

  // 03.2) MET trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* Gluino1800_METEff_RecoCaloMET_passPres = new TH2F("Gluino1800_METEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_METEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_METEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* Gluino1800_METEff_RecoCaloMET_passPres_TEff = new TEfficiency(*Gluino1800_RecoCaloMET_passPres_passMET_,*Gluino1800_RecoCaloMET_passPres_);
  Gluino1800_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino1800_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1800_METEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1800_METEff_RecoCaloMET_passPres.png");

  /* // 03.3) Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* Gluino1800_MuonEff_RecoCaloMET_noPres = new TH2F("Gluino1800_MuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_MuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_MuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* Gluino1800_MuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*Gluino1800_RecoCaloMET_noPres_passMuon_,*Gluino1800_RecoCaloMET_noPres_);
  Gluino1800_MuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  Gluino1800_MuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino1800_MuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1800_MuonEff_RecoCaloMET_noPres.png"); */

  // 03.4) Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* Gluino1800_MuonEff_RecoCaloMET_passPres = new TH2F("Gluino1800_MuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_MuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_MuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* Gluino1800_MuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*Gluino1800_RecoCaloMET_passPres_passMuon_,*Gluino1800_RecoCaloMET_passPres_);
  Gluino1800_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino1800_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1800_MuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1800_MuonEff_RecoCaloMET_passPres.png");

  /* // 03.5) MET or Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* Gluino1800_METOrMuonEff_RecoCaloMET_noPres = new TH2F("Gluino1800_METOrMuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_METOrMuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_METOrMuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* Gluino1800_METOrMuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*Gluino1800_RecoCaloMET_noPres_passMETOrMuon_,*Gluino1800_RecoCaloMET_noPres_);
  Gluino1800_METOrMuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  Gluino1800_METOrMuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino1800_METOrMuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1800_METOrMuonEff_RecoCaloMET_noPres.png"); */

  // 03.6) MET or Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* Gluino1800_METOrMuonEff_RecoCaloMET_passPres = new TH2F("Gluino1800_METOrMuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_METOrMuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_METOrMuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* Gluino1800_METOrMuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*Gluino1800_RecoCaloMET_passPres_passMETOrMuon_,*Gluino1800_RecoCaloMET_passPres_);
  Gluino1800_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino1800_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1800_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1800_METOrMuonEff_RecoCaloMET_passPres.png");

  /* // 03.7) MET trigger efficiency vs RECO PF MET, no preselection
  TH2F* Gluino1800_METEff_RecoPFMET_noPres = new TH2F("Gluino1800_METEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_METEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_METEff_RecoPFMET_noPres->Draw();  
  TEfficiency* Gluino1800_METEff_RecoPFMET_noPres_TEff = new TEfficiency(*Gluino1800_RecoPFMET_noPres_passMET_,*Gluino1800_RecoPFMET_noPres_);
  Gluino1800_METEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  Gluino1800_METEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino1800_METEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1800_METEff_RecoPFMET_noPres.png"); */

  // 03.8) MET trigger efficiency vs RECO PF MET, pass preselection
  TH2F* Gluino1800_METEff_RecoPFMET_passPres = new TH2F("Gluino1800_METEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_METEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_METEff_RecoPFMET_passPres->Draw();  
  TEfficiency* Gluino1800_METEff_RecoPFMET_passPres_TEff = new TEfficiency(*Gluino1800_RecoPFMET_passPres_passMET_,*Gluino1800_RecoPFMET_passPres_);
  Gluino1800_METEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino1800_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1800_METEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1800_METEff_RecoPFMET_passPres.png");

  /* // 03.9) Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* Gluino1800_MuonEff_RecoPFMET_noPres = new TH2F("Gluino1800_MuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_MuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_MuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* Gluino1800_MuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*Gluino1800_RecoPFMET_noPres_passMuon_,*Gluino1800_RecoPFMET_noPres_);
  Gluino1800_MuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  Gluino1800_MuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino1800_MuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1800_MuonEff_RecoPFMET_noPres.png"); */

  // 03.10) Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* Gluino1800_MuonEff_RecoPFMET_passPres = new TH2F("Gluino1800_MuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_MuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_MuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* Gluino1800_MuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*Gluino1800_RecoPFMET_passPres_passMuon_,*Gluino1800_RecoPFMET_passPres_);
  Gluino1800_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino1800_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1800_MuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1800_MuonEff_RecoPFMET_passPres.png");

  /* // 03.11) MET or Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* Gluino1800_METOrMuonEff_RecoPFMET_noPres = new TH2F("Gluino1800_METOrMuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_METOrMuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_METOrMuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* Gluino1800_METOrMuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*Gluino1800_RecoPFMET_noPres_passMETOrMuon_,*Gluino1800_RecoPFMET_noPres_);
  Gluino1800_METOrMuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  Gluino1800_METOrMuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino1800_METOrMuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1800_METOrMuonEff_RecoPFMET_noPres.png"); */

  // 03.12) MET or Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* Gluino1800_METOrMuonEff_RecoPFMET_passPres = new TH2F("Gluino1800_METOrMuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_METOrMuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_METOrMuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* Gluino1800_METOrMuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*Gluino1800_RecoPFMET_passPres_passMETOrMuon_,*Gluino1800_RecoPFMET_passPres_);
  Gluino1800_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino1800_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1800_METOrMuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1800_METOrMuonEff_RecoPFMET_passPres.png");

  /* // 03.13) MET trigger efficiency vs HLT Calo MET, no preselection
  TH2F* Gluino1800_METEff_HLTCaloMET_noPres = new TH2F("Gluino1800_METEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_METEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_METEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* Gluino1800_METEff_HLTCaloMET_noPres_TEff = new TEfficiency(*Gluino1800_HLTCaloMET_noPres_passMET_,*Gluino1800_HLTCaloMET_noPres_);
  Gluino1800_METEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  Gluino1800_METEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino1800_METEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1800_METEff_HLTCaloMET_noPres.png"); */

  // 03.14) MET trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* Gluino1800_METEff_HLTCaloMET_passPres = new TH2F("Gluino1800_METEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_METEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_METEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* Gluino1800_METEff_HLTCaloMET_passPres_TEff = new TEfficiency(*Gluino1800_HLTCaloMET_passPres_passMET_,*Gluino1800_HLTCaloMET_passPres_);
  Gluino1800_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino1800_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1800_METEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1800_METEff_HLTCaloMET_passPres.png");

  /* // 03.15) Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* Gluino1800_MuonEff_HLTCaloMET_noPres = new TH2F("Gluino1800_MuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_MuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_MuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* Gluino1800_MuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*Gluino1800_HLTCaloMET_noPres_passMuon_,*Gluino1800_HLTCaloMET_noPres_);
  Gluino1800_MuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  Gluino1800_MuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino1800_MuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1800_MuonEff_HLTCaloMET_noPres.png"); */

  // 03.16) Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* Gluino1800_MuonEff_HLTCaloMET_passPres = new TH2F("Gluino1800_MuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_MuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_MuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* Gluino1800_MuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*Gluino1800_HLTCaloMET_passPres_passMuon_,*Gluino1800_HLTCaloMET_passPres_);
  Gluino1800_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino1800_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1800_MuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1800_MuonEff_HLTCaloMET_passPres.png");

  /* // 03.17) MET or Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* Gluino1800_METOrMuonEff_HLTCaloMET_noPres = new TH2F("Gluino1800_METOrMuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_METOrMuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_METOrMuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* Gluino1800_METOrMuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*Gluino1800_HLTCaloMET_noPres_passMETOrMuon_,*Gluino1800_HLTCaloMET_noPres_);
  Gluino1800_METOrMuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  Gluino1800_METOrMuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino1800_METOrMuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1800_METOrMuonEff_HLTCaloMET_noPres.png"); */

  // 03.18) MET or Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* Gluino1800_METOrMuonEff_HLTCaloMET_passPres = new TH2F("Gluino1800_METOrMuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_METOrMuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_METOrMuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* Gluino1800_METOrMuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*Gluino1800_HLTCaloMET_passPres_passMETOrMuon_,*Gluino1800_HLTCaloMET_passPres_);
  Gluino1800_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino1800_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1800_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1800_METOrMuonEff_HLTCaloMET_passPres.png");

  /* // 03.19) MET trigger efficiency vs HLT PF MET, no preselection
  TH2F* Gluino1800_METEff_HLTPFMET_noPres = new TH2F("Gluino1800_METEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_METEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_METEff_HLTPFMET_noPres->Draw();  
  TEfficiency* Gluino1800_METEff_HLTPFMET_noPres_TEff = new TEfficiency(*Gluino1800_HLTPFMET_noPres_passMET_,*Gluino1800_HLTPFMET_noPres_);
  Gluino1800_METEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  Gluino1800_METEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino1800_METEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1800_METEff_HLTPFMET_noPres.png"); */

  // 03.20) MET trigger efficiency vs HLT PF MET, pass preselection
  TH2F* Gluino1800_METEff_HLTPFMET_passPres = new TH2F("Gluino1800_METEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_METEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_METEff_HLTPFMET_passPres->Draw();  
  TEfficiency* Gluino1800_METEff_HLTPFMET_passPres_TEff = new TEfficiency(*Gluino1800_HLTPFMET_passPres_passMET_,*Gluino1800_HLTPFMET_passPres_);
  Gluino1800_METEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino1800_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1800_METEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1800_METEff_HLTPFMET_passPres.png");

  /* // 03.21) Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* Gluino1800_MuonEff_HLTPFMET_noPres = new TH2F("Gluino1800_MuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_MuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_MuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* Gluino1800_MuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*Gluino1800_HLTPFMET_noPres_passMuon_,*Gluino1800_HLTPFMET_noPres_);
  Gluino1800_MuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  Gluino1800_MuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino1800_MuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1800_MuonEff_HLTPFMET_noPres.png"); */

  // 03.22) Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* Gluino1800_MuonEff_HLTPFMET_passPres = new TH2F("Gluino1800_MuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_MuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_MuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* Gluino1800_MuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*Gluino1800_HLTPFMET_passPres_passMuon_,*Gluino1800_HLTPFMET_passPres_);
  Gluino1800_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino1800_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1800_MuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1800_MuonEff_HLTPFMET_passPres.png");

  /* // 03.23) MET or Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* Gluino1800_METOrMuonEff_HLTPFMET_noPres = new TH2F("Gluino1800_METOrMuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_METOrMuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_METOrMuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* Gluino1800_METOrMuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*Gluino1800_HLTPFMET_noPres_passMETOrMuon_,*Gluino1800_HLTPFMET_noPres_);
  Gluino1800_METOrMuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  Gluino1800_METOrMuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino1800_METOrMuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1800_METOrMuonEff_HLTPFMET_noPres.png"); */

  // 03.24) MET or Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* Gluino1800_METOrMuonEff_HLTPFMET_passPres = new TH2F("Gluino1800_METOrMuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_METOrMuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_METOrMuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* Gluino1800_METOrMuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*Gluino1800_HLTPFMET_passPres_passMETOrMuon_,*Gluino1800_HLTPFMET_passPres_);
  Gluino1800_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino1800_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1800_METOrMuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino1800_METOrMuonEff_HLTPFMET_passPres.png");

  //=====================
  //   GLUINO 2400 GeV  
  //=====================

  /* // 04.1) MET trigger efficiency vs RECO Calo MET, no preselection
  TH2F* Gluino2400_METEff_RecoCaloMET_noPres = new TH2F("Gluino2400_METEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino2400_METEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino2400_METEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* Gluino2400_METEff_RecoCaloMET_noPres_TEff = new TEfficiency(*Gluino2400_RecoCaloMET_noPres_passMET_,*Gluino2400_RecoCaloMET_noPres_);
  Gluino2400_METEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  Gluino2400_METEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino2400_METEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino2400_METEff_RecoCaloMET_noPres.png"); */

  // 04.2) MET trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* Gluino2400_METEff_RecoCaloMET_passPres = new TH2F("Gluino2400_METEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino2400_METEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino2400_METEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* Gluino2400_METEff_RecoCaloMET_passPres_TEff = new TEfficiency(*Gluino2400_RecoCaloMET_passPres_passMET_,*Gluino2400_RecoCaloMET_passPres_);
  Gluino2400_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino2400_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino2400_METEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino2400_METEff_RecoCaloMET_passPres.png");

  /* // 04.3) Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* Gluino2400_MuonEff_RecoCaloMET_noPres = new TH2F("Gluino2400_MuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino2400_MuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino2400_MuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* Gluino2400_MuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*Gluino2400_RecoCaloMET_noPres_passMuon_,*Gluino2400_RecoCaloMET_noPres_);
  Gluino2400_MuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  Gluino2400_MuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino2400_MuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino2400_MuonEff_RecoCaloMET_noPres.png"); */

  // 04.4) Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* Gluino2400_MuonEff_RecoCaloMET_passPres = new TH2F("Gluino2400_MuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino2400_MuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino2400_MuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* Gluino2400_MuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*Gluino2400_RecoCaloMET_passPres_passMuon_,*Gluino2400_RecoCaloMET_passPres_);
  Gluino2400_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino2400_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino2400_MuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino2400_MuonEff_RecoCaloMET_passPres.png");

  /* // 04.5) MET or Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* Gluino2400_METOrMuonEff_RecoCaloMET_noPres = new TH2F("Gluino2400_METOrMuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino2400_METOrMuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino2400_METOrMuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* Gluino2400_METOrMuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*Gluino2400_RecoCaloMET_noPres_passMETOrMuon_,*Gluino2400_RecoCaloMET_noPres_);
  Gluino2400_METOrMuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  Gluino2400_METOrMuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino2400_METOrMuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino2400_METOrMuonEff_RecoCaloMET_noPres.png"); */

  // 04.6) MET or Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* Gluino2400_METOrMuonEff_RecoCaloMET_passPres = new TH2F("Gluino2400_METOrMuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino2400_METOrMuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino2400_METOrMuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* Gluino2400_METOrMuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*Gluino2400_RecoCaloMET_passPres_passMETOrMuon_,*Gluino2400_RecoCaloMET_passPres_);
  Gluino2400_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino2400_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino2400_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino2400_METOrMuonEff_RecoCaloMET_passPres.png");

  /* // 04.7) MET trigger efficiency vs RECO PF MET, no preselection
  TH2F* Gluino2400_METEff_RecoPFMET_noPres = new TH2F("Gluino2400_METEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino2400_METEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino2400_METEff_RecoPFMET_noPres->Draw();  
  TEfficiency* Gluino2400_METEff_RecoPFMET_noPres_TEff = new TEfficiency(*Gluino2400_RecoPFMET_noPres_passMET_,*Gluino2400_RecoPFMET_noPres_);
  Gluino2400_METEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  Gluino2400_METEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino2400_METEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino2400_METEff_RecoPFMET_noPres.png"); */

  // 04.8) MET trigger efficiency vs RECO PF MET, pass preselection
  TH2F* Gluino2400_METEff_RecoPFMET_passPres = new TH2F("Gluino2400_METEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino2400_METEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino2400_METEff_RecoPFMET_passPres->Draw();  
  TEfficiency* Gluino2400_METEff_RecoPFMET_passPres_TEff = new TEfficiency(*Gluino2400_RecoPFMET_passPres_passMET_,*Gluino2400_RecoPFMET_passPres_);
  Gluino2400_METEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino2400_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino2400_METEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino2400_METEff_RecoPFMET_passPres.png");

  /* // 04.9) Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* Gluino2400_MuonEff_RecoPFMET_noPres = new TH2F("Gluino2400_MuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino2400_MuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino2400_MuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* Gluino2400_MuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*Gluino2400_RecoPFMET_noPres_passMuon_,*Gluino2400_RecoPFMET_noPres_);
  Gluino2400_MuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  Gluino2400_MuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino2400_MuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino2400_MuonEff_RecoPFMET_noPres.png"); */

  // 04.10) Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* Gluino2400_MuonEff_RecoPFMET_passPres = new TH2F("Gluino2400_MuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino2400_MuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino2400_MuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* Gluino2400_MuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*Gluino2400_RecoPFMET_passPres_passMuon_,*Gluino2400_RecoPFMET_passPres_);
  Gluino2400_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino2400_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino2400_MuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino2400_MuonEff_RecoPFMET_passPres.png");

  /* // 04.11) MET or Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* Gluino2400_METOrMuonEff_RecoPFMET_noPres = new TH2F("Gluino2400_METOrMuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino2400_METOrMuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino2400_METOrMuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* Gluino2400_METOrMuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*Gluino2400_RecoPFMET_noPres_passMETOrMuon_,*Gluino2400_RecoPFMET_noPres_);
  Gluino2400_METOrMuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  Gluino2400_METOrMuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino2400_METOrMuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino2400_METOrMuonEff_RecoPFMET_noPres.png"); */

  // 04.12) MET or Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* Gluino2400_METOrMuonEff_RecoPFMET_passPres = new TH2F("Gluino2400_METOrMuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino2400_METOrMuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino2400_METOrMuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* Gluino2400_METOrMuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*Gluino2400_RecoPFMET_passPres_passMETOrMuon_,*Gluino2400_RecoPFMET_passPres_);
  Gluino2400_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino2400_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino2400_METOrMuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino2400_METOrMuonEff_RecoPFMET_passPres.png");

  /* // 04.13) MET trigger efficiency vs HLT Calo MET, no preselection
  TH2F* Gluino2400_METEff_HLTCaloMET_noPres = new TH2F("Gluino2400_METEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino2400_METEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino2400_METEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* Gluino2400_METEff_HLTCaloMET_noPres_TEff = new TEfficiency(*Gluino2400_HLTCaloMET_noPres_passMET_,*Gluino2400_HLTCaloMET_noPres_);
  Gluino2400_METEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  Gluino2400_METEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino2400_METEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino2400_METEff_HLTCaloMET_noPres.png"); */

  // 04.14) MET trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* Gluino2400_METEff_HLTCaloMET_passPres = new TH2F("Gluino2400_METEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino2400_METEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino2400_METEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* Gluino2400_METEff_HLTCaloMET_passPres_TEff = new TEfficiency(*Gluino2400_HLTCaloMET_passPres_passMET_,*Gluino2400_HLTCaloMET_passPres_);
  Gluino2400_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino2400_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino2400_METEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino2400_METEff_HLTCaloMET_passPres.png");

  /* // 04.15) Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* Gluino2400_MuonEff_HLTCaloMET_noPres = new TH2F("Gluino2400_MuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino2400_MuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino2400_MuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* Gluino2400_MuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*Gluino2400_HLTCaloMET_noPres_passMuon_,*Gluino2400_HLTCaloMET_noPres_);
  Gluino2400_MuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  Gluino2400_MuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino2400_MuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino2400_MuonEff_HLTCaloMET_noPres.png"); */

  // 04.16) Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* Gluino2400_MuonEff_HLTCaloMET_passPres = new TH2F("Gluino2400_MuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino2400_MuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino2400_MuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* Gluino2400_MuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*Gluino2400_HLTCaloMET_passPres_passMuon_,*Gluino2400_HLTCaloMET_passPres_);
  Gluino2400_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino2400_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino2400_MuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino2400_MuonEff_HLTCaloMET_passPres.png");

  /* // 04.17) MET or Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* Gluino2400_METOrMuonEff_HLTCaloMET_noPres = new TH2F("Gluino2400_METOrMuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino2400_METOrMuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino2400_METOrMuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* Gluino2400_METOrMuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*Gluino2400_HLTCaloMET_noPres_passMETOrMuon_,*Gluino2400_HLTCaloMET_noPres_);
  Gluino2400_METOrMuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  Gluino2400_METOrMuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino2400_METOrMuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino2400_METOrMuonEff_HLTCaloMET_noPres.png"); */

  // 04.18) MET or Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* Gluino2400_METOrMuonEff_HLTCaloMET_passPres = new TH2F("Gluino2400_METOrMuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino2400_METOrMuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino2400_METOrMuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* Gluino2400_METOrMuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*Gluino2400_HLTCaloMET_passPres_passMETOrMuon_,*Gluino2400_HLTCaloMET_passPres_);
  Gluino2400_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino2400_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino2400_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino2400_METOrMuonEff_HLTCaloMET_passPres.png");

  /* // 04.19) MET trigger efficiency vs HLT PF MET, no preselection
  TH2F* Gluino2400_METEff_HLTPFMET_noPres = new TH2F("Gluino2400_METEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino2400_METEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino2400_METEff_HLTPFMET_noPres->Draw();  
  TEfficiency* Gluino2400_METEff_HLTPFMET_noPres_TEff = new TEfficiency(*Gluino2400_HLTPFMET_noPres_passMET_,*Gluino2400_HLTPFMET_noPres_);
  Gluino2400_METEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  Gluino2400_METEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino2400_METEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino2400_METEff_HLTPFMET_noPres.png"); */

  // 04.20) MET trigger efficiency vs HLT PF MET, pass preselection
  TH2F* Gluino2400_METEff_HLTPFMET_passPres = new TH2F("Gluino2400_METEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  Gluino2400_METEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino2400_METEff_HLTPFMET_passPres->Draw();  
  TEfficiency* Gluino2400_METEff_HLTPFMET_passPres_TEff = new TEfficiency(*Gluino2400_HLTPFMET_passPres_passMET_,*Gluino2400_HLTPFMET_passPres_);
  Gluino2400_METEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino2400_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino2400_METEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino2400_METEff_HLTPFMET_passPres.png");

  /* // 04.21) Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* Gluino2400_MuonEff_HLTPFMET_noPres = new TH2F("Gluino2400_MuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino2400_MuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino2400_MuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* Gluino2400_MuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*Gluino2400_HLTPFMET_noPres_passMuon_,*Gluino2400_HLTPFMET_noPres_);
  Gluino2400_MuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  Gluino2400_MuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino2400_MuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino2400_MuonEff_HLTPFMET_noPres.png"); */

  // 04.22) Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* Gluino2400_MuonEff_HLTPFMET_passPres = new TH2F("Gluino2400_MuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino2400_MuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino2400_MuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* Gluino2400_MuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*Gluino2400_HLTPFMET_passPres_passMuon_,*Gluino2400_HLTPFMET_passPres_);
  Gluino2400_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino2400_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino2400_MuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino2400_MuonEff_HLTPFMET_passPres.png");

  /* // 04.23) MET or Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* Gluino2400_METOrMuonEff_HLTPFMET_noPres = new TH2F("Gluino2400_METOrMuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino2400_METOrMuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino2400_METOrMuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* Gluino2400_METOrMuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*Gluino2400_HLTPFMET_noPres_passMETOrMuon_,*Gluino2400_HLTPFMET_noPres_);
  Gluino2400_METOrMuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  Gluino2400_METOrMuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  Gluino2400_METOrMuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino2400_METOrMuonEff_HLTPFMET_noPres.png"); */

  // 04.24) MET or Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* Gluino2400_METOrMuonEff_HLTPFMET_passPres = new TH2F("Gluino2400_METOrMuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  Gluino2400_METOrMuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  Gluino2400_METOrMuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* Gluino2400_METOrMuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*Gluino2400_HLTPFMET_passPres_passMETOrMuon_,*Gluino2400_HLTPFMET_passPres_);
  Gluino2400_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino2400_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino2400_METOrMuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/Gluino2400_METOrMuonEff_HLTPFMET_passPres.png");
  
  //=====================
  //  GLUINO N 800 GeV  
  //=====================

  /* // 05.1) MET trigger efficiency vs RECO Calo MET, no preselection
  TH2F* GluinoN800_METEff_RecoCaloMET_noPres = new TH2F("GluinoN800_METEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN800_METEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN800_METEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* GluinoN800_METEff_RecoCaloMET_noPres_TEff = new TEfficiency(*GluinoN800_RecoCaloMET_noPres_passMET_,*GluinoN800_RecoCaloMET_noPres_);
  GluinoN800_METEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  GluinoN800_METEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN800_METEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN800_METEff_RecoCaloMET_noPres.png"); */

  // 05.2) MET trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* GluinoN800_METEff_RecoCaloMET_passPres = new TH2F("GluinoN800_METEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN800_METEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN800_METEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* GluinoN800_METEff_RecoCaloMET_passPres_TEff = new TEfficiency(*GluinoN800_RecoCaloMET_passPres_passMET_,*GluinoN800_RecoCaloMET_passPres_);
  GluinoN800_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN800_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN800_METEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN800_METEff_RecoCaloMET_passPres.png");

  /* // 05.3) Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* GluinoN800_MuonEff_RecoCaloMET_noPres = new TH2F("GluinoN800_MuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN800_MuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN800_MuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* GluinoN800_MuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*GluinoN800_RecoCaloMET_noPres_passMuon_,*GluinoN800_RecoCaloMET_noPres_);
  GluinoN800_MuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  GluinoN800_MuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN800_MuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN800_MuonEff_RecoCaloMET_noPres.png"); */

  // 05.4) Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* GluinoN800_MuonEff_RecoCaloMET_passPres = new TH2F("GluinoN800_MuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN800_MuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN800_MuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* GluinoN800_MuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*GluinoN800_RecoCaloMET_passPres_passMuon_,*GluinoN800_RecoCaloMET_passPres_);
  GluinoN800_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN800_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN800_MuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN800_MuonEff_RecoCaloMET_passPres.png");

  /* // 05.5) MET or Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* GluinoN800_METOrMuonEff_RecoCaloMET_noPres = new TH2F("GluinoN800_METOrMuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN800_METOrMuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN800_METOrMuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* GluinoN800_METOrMuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*GluinoN800_RecoCaloMET_noPres_passMETOrMuon_,*GluinoN800_RecoCaloMET_noPres_);
  GluinoN800_METOrMuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  GluinoN800_METOrMuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN800_METOrMuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN800_METOrMuonEff_RecoCaloMET_noPres.png"); */

  // 05.6) MET or Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* GluinoN800_METOrMuonEff_RecoCaloMET_passPres = new TH2F("GluinoN800_METOrMuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN800_METOrMuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN800_METOrMuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* GluinoN800_METOrMuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*GluinoN800_RecoCaloMET_passPres_passMETOrMuon_,*GluinoN800_RecoCaloMET_passPres_);
  GluinoN800_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN800_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN800_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN800_METOrMuonEff_RecoCaloMET_passPres.png");

  /* // 05.7) MET trigger efficiency vs RECO PF MET, no preselection
  TH2F* GluinoN800_METEff_RecoPFMET_noPres = new TH2F("GluinoN800_METEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN800_METEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN800_METEff_RecoPFMET_noPres->Draw();  
  TEfficiency* GluinoN800_METEff_RecoPFMET_noPres_TEff = new TEfficiency(*GluinoN800_RecoPFMET_noPres_passMET_,*GluinoN800_RecoPFMET_noPres_);
  GluinoN800_METEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  GluinoN800_METEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN800_METEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN800_METEff_RecoPFMET_noPres.png"); */

  // 05.8) MET trigger efficiency vs RECO PF MET, pass preselection
  TH2F* GluinoN800_METEff_RecoPFMET_passPres = new TH2F("GluinoN800_METEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN800_METEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN800_METEff_RecoPFMET_passPres->Draw();  
  TEfficiency* GluinoN800_METEff_RecoPFMET_passPres_TEff = new TEfficiency(*GluinoN800_RecoPFMET_passPres_passMET_,*GluinoN800_RecoPFMET_passPres_);
  GluinoN800_METEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN800_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN800_METEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN800_METEff_RecoPFMET_passPres.png");

  /* // 05.9) Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* GluinoN800_MuonEff_RecoPFMET_noPres = new TH2F("GluinoN800_MuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN800_MuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN800_MuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* GluinoN800_MuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*GluinoN800_RecoPFMET_noPres_passMuon_,*GluinoN800_RecoPFMET_noPres_);
  GluinoN800_MuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  GluinoN800_MuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN800_MuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN800_MuonEff_RecoPFMET_noPres.png"); */

  // 05.10) Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* GluinoN800_MuonEff_RecoPFMET_passPres = new TH2F("GluinoN800_MuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN800_MuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN800_MuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* GluinoN800_MuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*GluinoN800_RecoPFMET_passPres_passMuon_,*GluinoN800_RecoPFMET_passPres_);
  GluinoN800_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN800_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN800_MuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN800_MuonEff_RecoPFMET_passPres.png");

  /* // 05.11) MET or Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* GluinoN800_METOrMuonEff_RecoPFMET_noPres = new TH2F("GluinoN800_METOrMuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN800_METOrMuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN800_METOrMuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* GluinoN800_METOrMuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*GluinoN800_RecoPFMET_noPres_passMETOrMuon_,*GluinoN800_RecoPFMET_noPres_);
  GluinoN800_METOrMuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  GluinoN800_METOrMuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN800_METOrMuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN800_METOrMuonEff_RecoPFMET_noPres.png"); */

  // 05.12) MET or Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* GluinoN800_METOrMuonEff_RecoPFMET_passPres = new TH2F("GluinoN800_METOrMuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN800_METOrMuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN800_METOrMuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* GluinoN800_METOrMuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*GluinoN800_RecoPFMET_passPres_passMETOrMuon_,*GluinoN800_RecoPFMET_passPres_);
  GluinoN800_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN800_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN800_METOrMuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN800_METOrMuonEff_RecoPFMET_passPres.png");

  /* // 05.13) MET trigger efficiency vs HLT Calo MET, no preselection
  TH2F* GluinoN800_METEff_HLTCaloMET_noPres = new TH2F("GluinoN800_METEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN800_METEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN800_METEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* GluinoN800_METEff_HLTCaloMET_noPres_TEff = new TEfficiency(*GluinoN800_HLTCaloMET_noPres_passMET_,*GluinoN800_HLTCaloMET_noPres_);
  GluinoN800_METEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  GluinoN800_METEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN800_METEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN800_METEff_HLTCaloMET_noPres.png"); */

  // 05.14) MET trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* GluinoN800_METEff_HLTCaloMET_passPres = new TH2F("GluinoN800_METEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN800_METEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN800_METEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* GluinoN800_METEff_HLTCaloMET_passPres_TEff = new TEfficiency(*GluinoN800_HLTCaloMET_passPres_passMET_,*GluinoN800_HLTCaloMET_passPres_);
  GluinoN800_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN800_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN800_METEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN800_METEff_HLTCaloMET_passPres.png");

  /* // 05.15) Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* GluinoN800_MuonEff_HLTCaloMET_noPres = new TH2F("GluinoN800_MuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN800_MuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN800_MuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* GluinoN800_MuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*GluinoN800_HLTCaloMET_noPres_passMuon_,*GluinoN800_HLTCaloMET_noPres_);
  GluinoN800_MuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  GluinoN800_MuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN800_MuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN800_MuonEff_HLTCaloMET_noPres.png"); */

  // 05.16) Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* GluinoN800_MuonEff_HLTCaloMET_passPres = new TH2F("GluinoN800_MuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN800_MuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN800_MuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* GluinoN800_MuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*GluinoN800_HLTCaloMET_passPres_passMuon_,*GluinoN800_HLTCaloMET_passPres_);
  GluinoN800_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN800_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN800_MuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN800_MuonEff_HLTCaloMET_passPres.png");

  /* // 05.17) MET or Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* GluinoN800_METOrMuonEff_HLTCaloMET_noPres = new TH2F("GluinoN800_METOrMuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN800_METOrMuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN800_METOrMuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* GluinoN800_METOrMuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*GluinoN800_HLTCaloMET_noPres_passMETOrMuon_,*GluinoN800_HLTCaloMET_noPres_);
  GluinoN800_METOrMuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  GluinoN800_METOrMuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN800_METOrMuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN800_METOrMuonEff_HLTCaloMET_noPres.png"); */

  // 05.18) MET or Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* GluinoN800_METOrMuonEff_HLTCaloMET_passPres = new TH2F("GluinoN800_METOrMuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN800_METOrMuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN800_METOrMuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* GluinoN800_METOrMuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*GluinoN800_HLTCaloMET_passPres_passMETOrMuon_,*GluinoN800_HLTCaloMET_passPres_);
  GluinoN800_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN800_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN800_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN800_METOrMuonEff_HLTCaloMET_passPres.png");

  /* // 05.19) MET trigger efficiency vs HLT PF MET, no preselection
  TH2F* GluinoN800_METEff_HLTPFMET_noPres = new TH2F("GluinoN800_METEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN800_METEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN800_METEff_HLTPFMET_noPres->Draw();  
  TEfficiency* GluinoN800_METEff_HLTPFMET_noPres_TEff = new TEfficiency(*GluinoN800_HLTPFMET_noPres_passMET_,*GluinoN800_HLTPFMET_noPres_);
  GluinoN800_METEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  GluinoN800_METEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN800_METEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN800_METEff_HLTPFMET_noPres.png"); */

  // 05.20) MET trigger efficiency vs HLT PF MET, pass preselection
  TH2F* GluinoN800_METEff_HLTPFMET_passPres = new TH2F("GluinoN800_METEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN800_METEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN800_METEff_HLTPFMET_passPres->Draw();  
  TEfficiency* GluinoN800_METEff_HLTPFMET_passPres_TEff = new TEfficiency(*GluinoN800_HLTPFMET_passPres_passMET_,*GluinoN800_HLTPFMET_passPres_);
  GluinoN800_METEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN800_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN800_METEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN800_METEff_HLTPFMET_passPres.png");

  /* // 05.21) Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* GluinoN800_MuonEff_HLTPFMET_noPres = new TH2F("GluinoN800_MuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN800_MuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN800_MuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* GluinoN800_MuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*GluinoN800_HLTPFMET_noPres_passMuon_,*GluinoN800_HLTPFMET_noPres_);
  GluinoN800_MuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  GluinoN800_MuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN800_MuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN800_MuonEff_HLTPFMET_noPres.png"); */

  // 05.22) Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* GluinoN800_MuonEff_HLTPFMET_passPres = new TH2F("GluinoN800_MuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN800_MuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN800_MuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* GluinoN800_MuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*GluinoN800_HLTPFMET_passPres_passMuon_,*GluinoN800_HLTPFMET_passPres_);
  GluinoN800_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN800_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN800_MuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN800_MuonEff_HLTPFMET_passPres.png");

  /* // 05.23) MET or Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* GluinoN800_METOrMuonEff_HLTPFMET_noPres = new TH2F("GluinoN800_METOrMuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN800_METOrMuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN800_METOrMuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* GluinoN800_METOrMuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*GluinoN800_HLTPFMET_noPres_passMETOrMuon_,*GluinoN800_HLTPFMET_noPres_);
  GluinoN800_METOrMuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  GluinoN800_METOrMuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN800_METOrMuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN800_METOrMuonEff_HLTPFMET_noPres.png"); */

  // 05.24) MET or Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* GluinoN800_METOrMuonEff_HLTPFMET_passPres = new TH2F("GluinoN800_METOrMuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN800_METOrMuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN800_METOrMuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* GluinoN800_METOrMuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*GluinoN800_HLTPFMET_passPres_passMETOrMuon_,*GluinoN800_HLTPFMET_passPres_);
  GluinoN800_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN800_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN800_METOrMuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN800_METOrMuonEff_HLTPFMET_passPres.png");

  //=====================
  //  GLUINO N 1400 GeV  
  //=====================

  /* // 06.1) MET trigger efficiency vs RECO Calo MET, no preselection
  TH2F* GluinoN1400_METEff_RecoCaloMET_noPres = new TH2F("GluinoN1400_METEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN1400_METEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1400_METEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* GluinoN1400_METEff_RecoCaloMET_noPres_TEff = new TEfficiency(*GluinoN1400_RecoCaloMET_noPres_passMET_,*GluinoN1400_RecoCaloMET_noPres_);
  GluinoN1400_METEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  GluinoN1400_METEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_METEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1400_METEff_RecoCaloMET_noPres.png"); */

  // 06.2) MET trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* GluinoN1400_METEff_RecoCaloMET_passPres = new TH2F("GluinoN1400_METEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN1400_METEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1400_METEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* GluinoN1400_METEff_RecoCaloMET_passPres_TEff = new TEfficiency(*GluinoN1400_RecoCaloMET_passPres_passMET_,*GluinoN1400_RecoCaloMET_passPres_);
  GluinoN1400_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN1400_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_METEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1400_METEff_RecoCaloMET_passPres.png");

  /* // 06.3) Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* GluinoN1400_MuonEff_RecoCaloMET_noPres = new TH2F("GluinoN1400_MuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1400_MuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1400_MuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* GluinoN1400_MuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*GluinoN1400_RecoCaloMET_noPres_passMuon_,*GluinoN1400_RecoCaloMET_noPres_);
  GluinoN1400_MuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  GluinoN1400_MuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_MuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1400_MuonEff_RecoCaloMET_noPres.png"); */

  // 06.4) Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* GluinoN1400_MuonEff_RecoCaloMET_passPres = new TH2F("GluinoN1400_MuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1400_MuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1400_MuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* GluinoN1400_MuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*GluinoN1400_RecoCaloMET_passPres_passMuon_,*GluinoN1400_RecoCaloMET_passPres_);
  GluinoN1400_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN1400_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_MuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1400_MuonEff_RecoCaloMET_passPres.png");

  /* // 06.5) MET or Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* GluinoN1400_METOrMuonEff_RecoCaloMET_noPres = new TH2F("GluinoN1400_METOrMuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1400_METOrMuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1400_METOrMuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* GluinoN1400_METOrMuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*GluinoN1400_RecoCaloMET_noPres_passMETOrMuon_,*GluinoN1400_RecoCaloMET_noPres_);
  GluinoN1400_METOrMuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  GluinoN1400_METOrMuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_METOrMuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1400_METOrMuonEff_RecoCaloMET_noPres.png"); */

  // 06.6) MET or Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* GluinoN1400_METOrMuonEff_RecoCaloMET_passPres = new TH2F("GluinoN1400_METOrMuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1400_METOrMuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1400_METOrMuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* GluinoN1400_METOrMuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*GluinoN1400_RecoCaloMET_passPres_passMETOrMuon_,*GluinoN1400_RecoCaloMET_passPres_);
  GluinoN1400_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN1400_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1400_METOrMuonEff_RecoCaloMET_passPres.png");

  /* // 06.7) MET trigger efficiency vs RECO PF MET, no preselection
  TH2F* GluinoN1400_METEff_RecoPFMET_noPres = new TH2F("GluinoN1400_METEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN1400_METEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1400_METEff_RecoPFMET_noPres->Draw();  
  TEfficiency* GluinoN1400_METEff_RecoPFMET_noPres_TEff = new TEfficiency(*GluinoN1400_RecoPFMET_noPres_passMET_,*GluinoN1400_RecoPFMET_noPres_);
  GluinoN1400_METEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  GluinoN1400_METEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_METEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1400_METEff_RecoPFMET_noPres.png"); */

  // 06.8) MET trigger efficiency vs RECO PF MET, pass preselection
  TH2F* GluinoN1400_METEff_RecoPFMET_passPres = new TH2F("GluinoN1400_METEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN1400_METEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1400_METEff_RecoPFMET_passPres->Draw();  
  TEfficiency* GluinoN1400_METEff_RecoPFMET_passPres_TEff = new TEfficiency(*GluinoN1400_RecoPFMET_passPres_passMET_,*GluinoN1400_RecoPFMET_passPres_);
  GluinoN1400_METEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN1400_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_METEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1400_METEff_RecoPFMET_passPres.png");

  /* // 06.9) Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* GluinoN1400_MuonEff_RecoPFMET_noPres = new TH2F("GluinoN1400_MuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1400_MuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1400_MuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* GluinoN1400_MuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*GluinoN1400_RecoPFMET_noPres_passMuon_,*GluinoN1400_RecoPFMET_noPres_);
  GluinoN1400_MuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  GluinoN1400_MuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_MuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1400_MuonEff_RecoPFMET_noPres.png"); */

  // 06.10) Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* GluinoN1400_MuonEff_RecoPFMET_passPres = new TH2F("GluinoN1400_MuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1400_MuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1400_MuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* GluinoN1400_MuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*GluinoN1400_RecoPFMET_passPres_passMuon_,*GluinoN1400_RecoPFMET_passPres_);
  GluinoN1400_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN1400_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_MuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1400_MuonEff_RecoPFMET_passPres.png");

  /* // 06.11) MET or Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* GluinoN1400_METOrMuonEff_RecoPFMET_noPres = new TH2F("GluinoN1400_METOrMuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1400_METOrMuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1400_METOrMuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* GluinoN1400_METOrMuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*GluinoN1400_RecoPFMET_noPres_passMETOrMuon_,*GluinoN1400_RecoPFMET_noPres_);
  GluinoN1400_METOrMuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  GluinoN1400_METOrMuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_METOrMuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1400_METOrMuonEff_RecoPFMET_noPres.png"); */

  // 06.12) MET or Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* GluinoN1400_METOrMuonEff_RecoPFMET_passPres = new TH2F("GluinoN1400_METOrMuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1400_METOrMuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1400_METOrMuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* GluinoN1400_METOrMuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*GluinoN1400_RecoPFMET_passPres_passMETOrMuon_,*GluinoN1400_RecoPFMET_passPres_);
  GluinoN1400_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN1400_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_METOrMuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1400_METOrMuonEff_RecoPFMET_passPres.png");

  /* // 06.13) MET trigger efficiency vs HLT Calo MET, no preselection
  TH2F* GluinoN1400_METEff_HLTCaloMET_noPres = new TH2F("GluinoN1400_METEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN1400_METEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1400_METEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* GluinoN1400_METEff_HLTCaloMET_noPres_TEff = new TEfficiency(*GluinoN1400_HLTCaloMET_noPres_passMET_,*GluinoN1400_HLTCaloMET_noPres_);
  GluinoN1400_METEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  GluinoN1400_METEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_METEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1400_METEff_HLTCaloMET_noPres.png"); */

  // 06.14) MET trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* GluinoN1400_METEff_HLTCaloMET_passPres = new TH2F("GluinoN1400_METEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN1400_METEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1400_METEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* GluinoN1400_METEff_HLTCaloMET_passPres_TEff = new TEfficiency(*GluinoN1400_HLTCaloMET_passPres_passMET_,*GluinoN1400_HLTCaloMET_passPres_);
  GluinoN1400_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN1400_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_METEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1400_METEff_HLTCaloMET_passPres.png");

  /* // 06.15) Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* GluinoN1400_MuonEff_HLTCaloMET_noPres = new TH2F("GluinoN1400_MuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1400_MuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1400_MuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* GluinoN1400_MuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*GluinoN1400_HLTCaloMET_noPres_passMuon_,*GluinoN1400_HLTCaloMET_noPres_);
  GluinoN1400_MuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  GluinoN1400_MuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_MuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1400_MuonEff_HLTCaloMET_noPres.png"); */

  // 06.16) Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* GluinoN1400_MuonEff_HLTCaloMET_passPres = new TH2F("GluinoN1400_MuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1400_MuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1400_MuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* GluinoN1400_MuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*GluinoN1400_HLTCaloMET_passPres_passMuon_,*GluinoN1400_HLTCaloMET_passPres_);
  GluinoN1400_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN1400_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_MuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1400_MuonEff_HLTCaloMET_passPres.png");

  /* // 06.17) MET or Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* GluinoN1400_METOrMuonEff_HLTCaloMET_noPres = new TH2F("GluinoN1400_METOrMuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1400_METOrMuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1400_METOrMuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* GluinoN1400_METOrMuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*GluinoN1400_HLTCaloMET_noPres_passMETOrMuon_,*GluinoN1400_HLTCaloMET_noPres_);
  GluinoN1400_METOrMuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  GluinoN1400_METOrMuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_METOrMuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1400_METOrMuonEff_HLTCaloMET_noPres.png"); */

  // 06.18) MET or Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* GluinoN1400_METOrMuonEff_HLTCaloMET_passPres = new TH2F("GluinoN1400_METOrMuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1400_METOrMuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1400_METOrMuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* GluinoN1400_METOrMuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*GluinoN1400_HLTCaloMET_passPres_passMETOrMuon_,*GluinoN1400_HLTCaloMET_passPres_);
  GluinoN1400_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN1400_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1400_METOrMuonEff_HLTCaloMET_passPres.png");

  /* // 06.19) MET trigger efficiency vs HLT PF MET, no preselection
  TH2F* GluinoN1400_METEff_HLTPFMET_noPres = new TH2F("GluinoN1400_METEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN1400_METEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1400_METEff_HLTPFMET_noPres->Draw();  
  TEfficiency* GluinoN1400_METEff_HLTPFMET_noPres_TEff = new TEfficiency(*GluinoN1400_HLTPFMET_noPres_passMET_,*GluinoN1400_HLTPFMET_noPres_);
  GluinoN1400_METEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  GluinoN1400_METEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_METEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1400_METEff_HLTPFMET_noPres.png"); */

  // 06.20) MET trigger efficiency vs HLT PF MET, pass preselection
  TH2F* GluinoN1400_METEff_HLTPFMET_passPres = new TH2F("GluinoN1400_METEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN1400_METEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1400_METEff_HLTPFMET_passPres->Draw();  
  TEfficiency* GluinoN1400_METEff_HLTPFMET_passPres_TEff = new TEfficiency(*GluinoN1400_HLTPFMET_passPres_passMET_,*GluinoN1400_HLTPFMET_passPres_);
  GluinoN1400_METEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN1400_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_METEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1400_METEff_HLTPFMET_passPres.png");

  /* // 06.21) Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* GluinoN1400_MuonEff_HLTPFMET_noPres = new TH2F("GluinoN1400_MuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1400_MuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1400_MuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* GluinoN1400_MuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*GluinoN1400_HLTPFMET_noPres_passMuon_,*GluinoN1400_HLTPFMET_noPres_);
  GluinoN1400_MuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  GluinoN1400_MuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_MuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1400_MuonEff_HLTPFMET_noPres.png"); */

  // 06.22) Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* GluinoN1400_MuonEff_HLTPFMET_passPres = new TH2F("GluinoN1400_MuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1400_MuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1400_MuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* GluinoN1400_MuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*GluinoN1400_HLTPFMET_passPres_passMuon_,*GluinoN1400_HLTPFMET_passPres_);
  GluinoN1400_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN1400_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_MuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1400_MuonEff_HLTPFMET_passPres.png");

  /* // 06.23) MET or Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* GluinoN1400_METOrMuonEff_HLTPFMET_noPres = new TH2F("GluinoN1400_METOrMuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1400_METOrMuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1400_METOrMuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* GluinoN1400_METOrMuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*GluinoN1400_HLTPFMET_noPres_passMETOrMuon_,*GluinoN1400_HLTPFMET_noPres_);
  GluinoN1400_METOrMuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  GluinoN1400_METOrMuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_METOrMuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1400_METOrMuonEff_HLTPFMET_noPres.png"); */

  // 06.24) MET or Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* GluinoN1400_METOrMuonEff_HLTPFMET_passPres = new TH2F("GluinoN1400_METOrMuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1400_METOrMuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1400_METOrMuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* GluinoN1400_METOrMuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*GluinoN1400_HLTPFMET_passPres_passMETOrMuon_,*GluinoN1400_HLTPFMET_passPres_);
  GluinoN1400_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN1400_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_METOrMuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1400_METOrMuonEff_HLTPFMET_passPres.png");

  //=====================
  //  GLUINO N 1800 GeV  
  //=====================

  /* // 07.1) MET trigger efficiency vs RECO Calo MET, no preselection
  TH2F* GluinoN1800_METEff_RecoCaloMET_noPres = new TH2F("GluinoN1800_METEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN1800_METEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1800_METEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* GluinoN1800_METEff_RecoCaloMET_noPres_TEff = new TEfficiency(*GluinoN1800_RecoCaloMET_noPres_passMET_,*GluinoN1800_RecoCaloMET_noPres_);
  GluinoN1800_METEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  GluinoN1800_METEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN1800_METEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1800_METEff_RecoCaloMET_noPres.png"); */

  // 07.2) MET trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* GluinoN1800_METEff_RecoCaloMET_passPres = new TH2F("GluinoN1800_METEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN1800_METEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1800_METEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* GluinoN1800_METEff_RecoCaloMET_passPres_TEff = new TEfficiency(*GluinoN1800_RecoCaloMET_passPres_passMET_,*GluinoN1800_RecoCaloMET_passPres_);
  GluinoN1800_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN1800_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1800_METEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1800_METEff_RecoCaloMET_passPres.png");

  /* // 07.3) Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* GluinoN1800_MuonEff_RecoCaloMET_noPres = new TH2F("GluinoN1800_MuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1800_MuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1800_MuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* GluinoN1800_MuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*GluinoN1800_RecoCaloMET_noPres_passMuon_,*GluinoN1800_RecoCaloMET_noPres_);
  GluinoN1800_MuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  GluinoN1800_MuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN1800_MuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1800_MuonEff_RecoCaloMET_noPres.png"); */

  // 07.4) Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* GluinoN1800_MuonEff_RecoCaloMET_passPres = new TH2F("GluinoN1800_MuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1800_MuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1800_MuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* GluinoN1800_MuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*GluinoN1800_RecoCaloMET_passPres_passMuon_,*GluinoN1800_RecoCaloMET_passPres_);
  GluinoN1800_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN1800_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1800_MuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1800_MuonEff_RecoCaloMET_passPres.png");

  /* // 07.5) MET or Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* GluinoN1800_METOrMuonEff_RecoCaloMET_noPres = new TH2F("GluinoN1800_METOrMuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1800_METOrMuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1800_METOrMuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* GluinoN1800_METOrMuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*GluinoN1800_RecoCaloMET_noPres_passMETOrMuon_,*GluinoN1800_RecoCaloMET_noPres_);
  GluinoN1800_METOrMuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  GluinoN1800_METOrMuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN1800_METOrMuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1800_METOrMuonEff_RecoCaloMET_noPres.png"); */

  // 07.6) MET or Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* GluinoN1800_METOrMuonEff_RecoCaloMET_passPres = new TH2F("GluinoN1800_METOrMuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1800_METOrMuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1800_METOrMuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* GluinoN1800_METOrMuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*GluinoN1800_RecoCaloMET_passPres_passMETOrMuon_,*GluinoN1800_RecoCaloMET_passPres_);
  GluinoN1800_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN1800_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1800_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1800_METOrMuonEff_RecoCaloMET_passPres.png");

  /* // 07.7) MET trigger efficiency vs RECO PF MET, no preselection
  TH2F* GluinoN1800_METEff_RecoPFMET_noPres = new TH2F("GluinoN1800_METEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN1800_METEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1800_METEff_RecoPFMET_noPres->Draw();  
  TEfficiency* GluinoN1800_METEff_RecoPFMET_noPres_TEff = new TEfficiency(*GluinoN1800_RecoPFMET_noPres_passMET_,*GluinoN1800_RecoPFMET_noPres_);
  GluinoN1800_METEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  GluinoN1800_METEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN1800_METEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1800_METEff_RecoPFMET_noPres.png"); */

  // 07.8) MET trigger efficiency vs RECO PF MET, pass preselection
  TH2F* GluinoN1800_METEff_RecoPFMET_passPres = new TH2F("GluinoN1800_METEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN1800_METEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1800_METEff_RecoPFMET_passPres->Draw();  
  TEfficiency* GluinoN1800_METEff_RecoPFMET_passPres_TEff = new TEfficiency(*GluinoN1800_RecoPFMET_passPres_passMET_,*GluinoN1800_RecoPFMET_passPres_);
  GluinoN1800_METEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN1800_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1800_METEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1800_METEff_RecoPFMET_passPres.png");

  /* // 07.9) Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* GluinoN1800_MuonEff_RecoPFMET_noPres = new TH2F("GluinoN1800_MuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1800_MuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1800_MuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* GluinoN1800_MuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*GluinoN1800_RecoPFMET_noPres_passMuon_,*GluinoN1800_RecoPFMET_noPres_);
  GluinoN1800_MuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  GluinoN1800_MuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN1800_MuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1800_MuonEff_RecoPFMET_noPres.png"); */

  // 07.10) Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* GluinoN1800_MuonEff_RecoPFMET_passPres = new TH2F("GluinoN1800_MuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1800_MuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1800_MuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* GluinoN1800_MuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*GluinoN1800_RecoPFMET_passPres_passMuon_,*GluinoN1800_RecoPFMET_passPres_);
  GluinoN1800_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN1800_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1800_MuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1800_MuonEff_RecoPFMET_passPres.png");

  /* // 07.11) MET or Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* GluinoN1800_METOrMuonEff_RecoPFMET_noPres = new TH2F("GluinoN1800_METOrMuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1800_METOrMuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1800_METOrMuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* GluinoN1800_METOrMuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*GluinoN1800_RecoPFMET_noPres_passMETOrMuon_,*GluinoN1800_RecoPFMET_noPres_);
  GluinoN1800_METOrMuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  GluinoN1800_METOrMuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN1800_METOrMuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1800_METOrMuonEff_RecoPFMET_noPres.png"); */

  // 07.12) MET or Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* GluinoN1800_METOrMuonEff_RecoPFMET_passPres = new TH2F("GluinoN1800_METOrMuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1800_METOrMuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1800_METOrMuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* GluinoN1800_METOrMuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*GluinoN1800_RecoPFMET_passPres_passMETOrMuon_,*GluinoN1800_RecoPFMET_passPres_);
  GluinoN1800_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN1800_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1800_METOrMuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1800_METOrMuonEff_RecoPFMET_passPres.png");

  /* // 07.13) MET trigger efficiency vs HLT Calo MET, no preselection
  TH2F* GluinoN1800_METEff_HLTCaloMET_noPres = new TH2F("GluinoN1800_METEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN1800_METEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1800_METEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* GluinoN1800_METEff_HLTCaloMET_noPres_TEff = new TEfficiency(*GluinoN1800_HLTCaloMET_noPres_passMET_,*GluinoN1800_HLTCaloMET_noPres_);
  GluinoN1800_METEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  GluinoN1800_METEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN1800_METEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1800_METEff_HLTCaloMET_noPres.png"); */

  // 07.14) MET trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* GluinoN1800_METEff_HLTCaloMET_passPres = new TH2F("GluinoN1800_METEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN1800_METEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1800_METEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* GluinoN1800_METEff_HLTCaloMET_passPres_TEff = new TEfficiency(*GluinoN1800_HLTCaloMET_passPres_passMET_,*GluinoN1800_HLTCaloMET_passPres_);
  GluinoN1800_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN1800_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1800_METEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1800_METEff_HLTCaloMET_passPres.png");

  /* // 07.15) Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* GluinoN1800_MuonEff_HLTCaloMET_noPres = new TH2F("GluinoN1800_MuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1800_MuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1800_MuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* GluinoN1800_MuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*GluinoN1800_HLTCaloMET_noPres_passMuon_,*GluinoN1800_HLTCaloMET_noPres_);
  GluinoN1800_MuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  GluinoN1800_MuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN1800_MuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1800_MuonEff_HLTCaloMET_noPres.png"); */

  // 07.16) Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* GluinoN1800_MuonEff_HLTCaloMET_passPres = new TH2F("GluinoN1800_MuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1800_MuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1800_MuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* GluinoN1800_MuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*GluinoN1800_HLTCaloMET_passPres_passMuon_,*GluinoN1800_HLTCaloMET_passPres_);
  GluinoN1800_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN1800_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1800_MuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1800_MuonEff_HLTCaloMET_passPres.png");

  /* // 07.17) MET or Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* GluinoN1800_METOrMuonEff_HLTCaloMET_noPres = new TH2F("GluinoN1800_METOrMuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1800_METOrMuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1800_METOrMuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* GluinoN1800_METOrMuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*GluinoN1800_HLTCaloMET_noPres_passMETOrMuon_,*GluinoN1800_HLTCaloMET_noPres_);
  GluinoN1800_METOrMuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  GluinoN1800_METOrMuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN1800_METOrMuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1800_METOrMuonEff_HLTCaloMET_noPres.png"); */

  // 07.18) MET or Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* GluinoN1800_METOrMuonEff_HLTCaloMET_passPres = new TH2F("GluinoN1800_METOrMuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1800_METOrMuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1800_METOrMuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* GluinoN1800_METOrMuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*GluinoN1800_HLTCaloMET_passPres_passMETOrMuon_,*GluinoN1800_HLTCaloMET_passPres_);
  GluinoN1800_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN1800_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1800_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1800_METOrMuonEff_HLTCaloMET_passPres.png");

  /* // 07.19) MET trigger efficiency vs HLT PF MET, no preselection
  TH2F* GluinoN1800_METEff_HLTPFMET_noPres = new TH2F("GluinoN1800_METEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN1800_METEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1800_METEff_HLTPFMET_noPres->Draw();  
  TEfficiency* GluinoN1800_METEff_HLTPFMET_noPres_TEff = new TEfficiency(*GluinoN1800_HLTPFMET_noPres_passMET_,*GluinoN1800_HLTPFMET_noPres_);
  GluinoN1800_METEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  GluinoN1800_METEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN1800_METEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1800_METEff_HLTPFMET_noPres.png"); */

  // 07.20) MET trigger efficiency vs HLT PF MET, pass preselection
  TH2F* GluinoN1800_METEff_HLTPFMET_passPres = new TH2F("GluinoN1800_METEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN1800_METEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1800_METEff_HLTPFMET_passPres->Draw();  
  TEfficiency* GluinoN1800_METEff_HLTPFMET_passPres_TEff = new TEfficiency(*GluinoN1800_HLTPFMET_passPres_passMET_,*GluinoN1800_HLTPFMET_passPres_);
  GluinoN1800_METEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN1800_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1800_METEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1800_METEff_HLTPFMET_passPres.png");

  /* // 07.21) Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* GluinoN1800_MuonEff_HLTPFMET_noPres = new TH2F("GluinoN1800_MuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1800_MuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1800_MuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* GluinoN1800_MuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*GluinoN1800_HLTPFMET_noPres_passMuon_,*GluinoN1800_HLTPFMET_noPres_);
  GluinoN1800_MuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  GluinoN1800_MuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN1800_MuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1800_MuonEff_HLTPFMET_noPres.png"); */

  // 07.22) Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* GluinoN1800_MuonEff_HLTPFMET_passPres = new TH2F("GluinoN1800_MuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1800_MuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1800_MuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* GluinoN1800_MuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*GluinoN1800_HLTPFMET_passPres_passMuon_,*GluinoN1800_HLTPFMET_passPres_);
  GluinoN1800_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN1800_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1800_MuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1800_MuonEff_HLTPFMET_passPres.png");

  /* // 07.23) MET or Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* GluinoN1800_METOrMuonEff_HLTPFMET_noPres = new TH2F("GluinoN1800_METOrMuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1800_METOrMuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1800_METOrMuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* GluinoN1800_METOrMuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*GluinoN1800_HLTPFMET_noPres_passMETOrMuon_,*GluinoN1800_HLTPFMET_noPres_);
  GluinoN1800_METOrMuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  GluinoN1800_METOrMuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN1800_METOrMuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1800_METOrMuonEff_HLTPFMET_noPres.png"); */

  // 07.24) MET or Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* GluinoN1800_METOrMuonEff_HLTPFMET_passPres = new TH2F("GluinoN1800_METOrMuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN1800_METOrMuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN1800_METOrMuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* GluinoN1800_METOrMuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*GluinoN1800_HLTPFMET_passPres_passMETOrMuon_,*GluinoN1800_HLTPFMET_passPres_);
  GluinoN1800_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN1800_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1800_METOrMuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN1800_METOrMuonEff_HLTPFMET_passPres.png");

  //=====================
  //  GLUINO N 2400 GeV  
  //=====================

  /* // 08.1) MET trigger efficiency vs RECO Calo MET, no preselection
  TH2F* GluinoN2400_METEff_RecoCaloMET_noPres = new TH2F("GluinoN2400_METEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN2400_METEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN2400_METEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* GluinoN2400_METEff_RecoCaloMET_noPres_TEff = new TEfficiency(*GluinoN2400_RecoCaloMET_noPres_passMET_,*GluinoN2400_RecoCaloMET_noPres_);
  GluinoN2400_METEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  GluinoN2400_METEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN2400_METEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN2400_METEff_RecoCaloMET_noPres.png"); */

  // 08.2) MET trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* GluinoN2400_METEff_RecoCaloMET_passPres = new TH2F("GluinoN2400_METEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN2400_METEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN2400_METEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* GluinoN2400_METEff_RecoCaloMET_passPres_TEff = new TEfficiency(*GluinoN2400_RecoCaloMET_passPres_passMET_,*GluinoN2400_RecoCaloMET_passPres_);
  GluinoN2400_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN2400_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN2400_METEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN2400_METEff_RecoCaloMET_passPres.png");

  /* // 08.3) Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* GluinoN2400_MuonEff_RecoCaloMET_noPres = new TH2F("GluinoN2400_MuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN2400_MuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN2400_MuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* GluinoN2400_MuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*GluinoN2400_RecoCaloMET_noPres_passMuon_,*GluinoN2400_RecoCaloMET_noPres_);
  GluinoN2400_MuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  GluinoN2400_MuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN2400_MuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN2400_MuonEff_RecoCaloMET_noPres.png"); */

  // 08.4) Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* GluinoN2400_MuonEff_RecoCaloMET_passPres = new TH2F("GluinoN2400_MuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN2400_MuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN2400_MuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* GluinoN2400_MuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*GluinoN2400_RecoCaloMET_passPres_passMuon_,*GluinoN2400_RecoCaloMET_passPres_);
  GluinoN2400_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN2400_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN2400_MuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN2400_MuonEff_RecoCaloMET_passPres.png");

  /* // 08.5) MET or Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* GluinoN2400_METOrMuonEff_RecoCaloMET_noPres = new TH2F("GluinoN2400_METOrMuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN2400_METOrMuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN2400_METOrMuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* GluinoN2400_METOrMuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*GluinoN2400_RecoCaloMET_noPres_passMETOrMuon_,*GluinoN2400_RecoCaloMET_noPres_);
  GluinoN2400_METOrMuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  GluinoN2400_METOrMuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN2400_METOrMuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN2400_METOrMuonEff_RecoCaloMET_noPres.png"); */

  // 08.6) MET or Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* GluinoN2400_METOrMuonEff_RecoCaloMET_passPres = new TH2F("GluinoN2400_METOrMuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN2400_METOrMuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN2400_METOrMuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* GluinoN2400_METOrMuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*GluinoN2400_RecoCaloMET_passPres_passMETOrMuon_,*GluinoN2400_RecoCaloMET_passPres_);
  GluinoN2400_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN2400_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN2400_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN2400_METOrMuonEff_RecoCaloMET_passPres.png");

  /* // 08.7) MET trigger efficiency vs RECO PF MET, no preselection
  TH2F* GluinoN2400_METEff_RecoPFMET_noPres = new TH2F("GluinoN2400_METEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN2400_METEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN2400_METEff_RecoPFMET_noPres->Draw();  
  TEfficiency* GluinoN2400_METEff_RecoPFMET_noPres_TEff = new TEfficiency(*GluinoN2400_RecoPFMET_noPres_passMET_,*GluinoN2400_RecoPFMET_noPres_);
  GluinoN2400_METEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  GluinoN2400_METEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN2400_METEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN2400_METEff_RecoPFMET_noPres.png"); */

  // 08.8) MET trigger efficiency vs RECO PF MET, pass preselection
  TH2F* GluinoN2400_METEff_RecoPFMET_passPres = new TH2F("GluinoN2400_METEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN2400_METEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN2400_METEff_RecoPFMET_passPres->Draw();  
  TEfficiency* GluinoN2400_METEff_RecoPFMET_passPres_TEff = new TEfficiency(*GluinoN2400_RecoPFMET_passPres_passMET_,*GluinoN2400_RecoPFMET_passPres_);
  GluinoN2400_METEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN2400_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN2400_METEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN2400_METEff_RecoPFMET_passPres.png");

  /* // 08.9) Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* GluinoN2400_MuonEff_RecoPFMET_noPres = new TH2F("GluinoN2400_MuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN2400_MuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN2400_MuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* GluinoN2400_MuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*GluinoN2400_RecoPFMET_noPres_passMuon_,*GluinoN2400_RecoPFMET_noPres_);
  GluinoN2400_MuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  GluinoN2400_MuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN2400_MuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN2400_MuonEff_RecoPFMET_noPres.png"); */

  // 08.10) Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* GluinoN2400_MuonEff_RecoPFMET_passPres = new TH2F("GluinoN2400_MuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN2400_MuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN2400_MuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* GluinoN2400_MuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*GluinoN2400_RecoPFMET_passPres_passMuon_,*GluinoN2400_RecoPFMET_passPres_);
  GluinoN2400_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN2400_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN2400_MuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN2400_MuonEff_RecoPFMET_passPres.png");

  /* // 08.11) MET or Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* GluinoN2400_METOrMuonEff_RecoPFMET_noPres = new TH2F("GluinoN2400_METOrMuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN2400_METOrMuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN2400_METOrMuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* GluinoN2400_METOrMuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*GluinoN2400_RecoPFMET_noPres_passMETOrMuon_,*GluinoN2400_RecoPFMET_noPres_);
  GluinoN2400_METOrMuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  GluinoN2400_METOrMuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN2400_METOrMuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN2400_METOrMuonEff_RecoPFMET_noPres.png"); */

  // 08.12) MET or Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* GluinoN2400_METOrMuonEff_RecoPFMET_passPres = new TH2F("GluinoN2400_METOrMuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN2400_METOrMuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN2400_METOrMuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* GluinoN2400_METOrMuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*GluinoN2400_RecoPFMET_passPres_passMETOrMuon_,*GluinoN2400_RecoPFMET_passPres_);
  GluinoN2400_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN2400_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN2400_METOrMuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN2400_METOrMuonEff_RecoPFMET_passPres.png");

  /* // 08.13) MET trigger efficiency vs HLT Calo MET, no preselection
  TH2F* GluinoN2400_METEff_HLTCaloMET_noPres = new TH2F("GluinoN2400_METEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN2400_METEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN2400_METEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* GluinoN2400_METEff_HLTCaloMET_noPres_TEff = new TEfficiency(*GluinoN2400_HLTCaloMET_noPres_passMET_,*GluinoN2400_HLTCaloMET_noPres_);
  GluinoN2400_METEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  GluinoN2400_METEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN2400_METEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN2400_METEff_HLTCaloMET_noPres.png"); */

  // 08.14) MET trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* GluinoN2400_METEff_HLTCaloMET_passPres = new TH2F("GluinoN2400_METEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN2400_METEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN2400_METEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* GluinoN2400_METEff_HLTCaloMET_passPres_TEff = new TEfficiency(*GluinoN2400_HLTCaloMET_passPres_passMET_,*GluinoN2400_HLTCaloMET_passPres_);
  GluinoN2400_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN2400_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN2400_METEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN2400_METEff_HLTCaloMET_passPres.png");

  /* // 08.15) Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* GluinoN2400_MuonEff_HLTCaloMET_noPres = new TH2F("GluinoN2400_MuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN2400_MuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN2400_MuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* GluinoN2400_MuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*GluinoN2400_HLTCaloMET_noPres_passMuon_,*GluinoN2400_HLTCaloMET_noPres_);
  GluinoN2400_MuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  GluinoN2400_MuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN2400_MuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN2400_MuonEff_HLTCaloMET_noPres.png"); */

  // 08.16) Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* GluinoN2400_MuonEff_HLTCaloMET_passPres = new TH2F("GluinoN2400_MuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN2400_MuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN2400_MuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* GluinoN2400_MuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*GluinoN2400_HLTCaloMET_passPres_passMuon_,*GluinoN2400_HLTCaloMET_passPres_);
  GluinoN2400_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN2400_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN2400_MuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN2400_MuonEff_HLTCaloMET_passPres.png");

  /* // 08.17) MET or Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* GluinoN2400_METOrMuonEff_HLTCaloMET_noPres = new TH2F("GluinoN2400_METOrMuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN2400_METOrMuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN2400_METOrMuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* GluinoN2400_METOrMuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*GluinoN2400_HLTCaloMET_noPres_passMETOrMuon_,*GluinoN2400_HLTCaloMET_noPres_);
  GluinoN2400_METOrMuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  GluinoN2400_METOrMuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN2400_METOrMuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN2400_METOrMuonEff_HLTCaloMET_noPres.png"); */

  // 08.18) MET or Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* GluinoN2400_METOrMuonEff_HLTCaloMET_passPres = new TH2F("GluinoN2400_METOrMuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN2400_METOrMuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN2400_METOrMuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* GluinoN2400_METOrMuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*GluinoN2400_HLTCaloMET_passPres_passMETOrMuon_,*GluinoN2400_HLTCaloMET_passPres_);
  GluinoN2400_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN2400_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN2400_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN2400_METOrMuonEff_HLTCaloMET_passPres.png");

  /* // 08.19) MET trigger efficiency vs HLT PF MET, no preselection
  TH2F* GluinoN2400_METEff_HLTPFMET_noPres = new TH2F("GluinoN2400_METEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN2400_METEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN2400_METEff_HLTPFMET_noPres->Draw();  
  TEfficiency* GluinoN2400_METEff_HLTPFMET_noPres_TEff = new TEfficiency(*GluinoN2400_HLTPFMET_noPres_passMET_,*GluinoN2400_HLTPFMET_noPres_);
  GluinoN2400_METEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  GluinoN2400_METEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN2400_METEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN2400_METEff_HLTPFMET_noPres.png"); */

  // 08.20) MET trigger efficiency vs HLT PF MET, pass preselection
  TH2F* GluinoN2400_METEff_HLTPFMET_passPres = new TH2F("GluinoN2400_METEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GluinoN2400_METEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN2400_METEff_HLTPFMET_passPres->Draw();  
  TEfficiency* GluinoN2400_METEff_HLTPFMET_passPres_TEff = new TEfficiency(*GluinoN2400_HLTPFMET_passPres_passMET_,*GluinoN2400_HLTPFMET_passPres_);
  GluinoN2400_METEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN2400_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN2400_METEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN2400_METEff_HLTPFMET_passPres.png");

  /* // 08.21) Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* GluinoN2400_MuonEff_HLTPFMET_noPres = new TH2F("GluinoN2400_MuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN2400_MuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN2400_MuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* GluinoN2400_MuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*GluinoN2400_HLTPFMET_noPres_passMuon_,*GluinoN2400_HLTPFMET_noPres_);
  GluinoN2400_MuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  GluinoN2400_MuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN2400_MuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN2400_MuonEff_HLTPFMET_noPres.png"); */

  // 08.22) Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* GluinoN2400_MuonEff_HLTPFMET_passPres = new TH2F("GluinoN2400_MuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN2400_MuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN2400_MuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* GluinoN2400_MuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*GluinoN2400_HLTPFMET_passPres_passMuon_,*GluinoN2400_HLTPFMET_passPres_);
  GluinoN2400_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN2400_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN2400_MuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN2400_MuonEff_HLTPFMET_passPres.png");

  /* // 08.23) MET or Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* GluinoN2400_METOrMuonEff_HLTPFMET_noPres = new TH2F("GluinoN2400_METOrMuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN2400_METOrMuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN2400_METOrMuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* GluinoN2400_METOrMuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*GluinoN2400_HLTPFMET_noPres_passMETOrMuon_,*GluinoN2400_HLTPFMET_noPres_);
  GluinoN2400_METOrMuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  GluinoN2400_METOrMuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  GluinoN2400_METOrMuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN2400_METOrMuonEff_HLTPFMET_noPres.png"); */

  // 08.24) MET or Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* GluinoN2400_METOrMuonEff_HLTPFMET_passPres = new TH2F("GluinoN2400_METOrMuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GluinoN2400_METOrMuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GluinoN2400_METOrMuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* GluinoN2400_METOrMuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*GluinoN2400_HLTPFMET_passPres_passMETOrMuon_,*GluinoN2400_HLTPFMET_passPres_);
  GluinoN2400_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN2400_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN2400_METOrMuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GluinoN2400_METOrMuonEff_HLTPFMET_passPres.png");

  //=====================
  //  GMSBStau 200 GeV  
  //=====================

  /* // 09.1) MET trigger efficiency vs RECO Calo MET, no preselection
  TH2F* GMSBStau200_METEff_RecoCaloMET_noPres = new TH2F("GMSBStau200_METEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau200_METEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau200_METEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* GMSBStau200_METEff_RecoCaloMET_noPres_TEff = new TEfficiency(*GMSBStau200_RecoCaloMET_noPres_passMET_,*GMSBStau200_RecoCaloMET_noPres_);
  GMSBStau200_METEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau200_METEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau200_METEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau200_METEff_RecoCaloMET_noPres.png"); */

  // 09.2) MET trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* GMSBStau200_METEff_RecoCaloMET_passPres = new TH2F("GMSBStau200_METEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau200_METEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau200_METEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* GMSBStau200_METEff_RecoCaloMET_passPres_TEff = new TEfficiency(*GMSBStau200_RecoCaloMET_passPres_passMET_,*GMSBStau200_RecoCaloMET_passPres_);
  GMSBStau200_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau200_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau200_METEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau200_METEff_RecoCaloMET_passPres.png");

  /* // 09.3) Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* GMSBStau200_MuonEff_RecoCaloMET_noPres = new TH2F("GMSBStau200_MuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau200_MuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau200_MuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* GMSBStau200_MuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*GMSBStau200_RecoCaloMET_noPres_passMuon_,*GMSBStau200_RecoCaloMET_noPres_);
  GMSBStau200_MuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau200_MuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau200_MuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau200_MuonEff_RecoCaloMET_noPres.png"); */

  // 09.4) Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* GMSBStau200_MuonEff_RecoCaloMET_passPres = new TH2F("GMSBStau200_MuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau200_MuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau200_MuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* GMSBStau200_MuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*GMSBStau200_RecoCaloMET_passPres_passMuon_,*GMSBStau200_RecoCaloMET_passPres_);
  GMSBStau200_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau200_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau200_MuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau200_MuonEff_RecoCaloMET_passPres.png");

  /* // 09.5) MET or Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* GMSBStau200_METOrMuonEff_RecoCaloMET_noPres = new TH2F("GMSBStau200_METOrMuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau200_METOrMuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau200_METOrMuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* GMSBStau200_METOrMuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*GMSBStau200_RecoCaloMET_noPres_passMETOrMuon_,*GMSBStau200_RecoCaloMET_noPres_);
  GMSBStau200_METOrMuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau200_METOrMuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau200_METOrMuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau200_METOrMuonEff_RecoCaloMET_noPres.png"); */

  // 09.6) MET or Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* GMSBStau200_METOrMuonEff_RecoCaloMET_passPres = new TH2F("GMSBStau200_METOrMuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau200_METOrMuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau200_METOrMuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* GMSBStau200_METOrMuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*GMSBStau200_RecoCaloMET_passPres_passMETOrMuon_,*GMSBStau200_RecoCaloMET_passPres_);
  GMSBStau200_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau200_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau200_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau200_METOrMuonEff_RecoCaloMET_passPres.png");

  /* // 09.7) MET trigger efficiency vs RECO PF MET, no preselection
  TH2F* GMSBStau200_METEff_RecoPFMET_noPres = new TH2F("GMSBStau200_METEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau200_METEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau200_METEff_RecoPFMET_noPres->Draw();  
  TEfficiency* GMSBStau200_METEff_RecoPFMET_noPres_TEff = new TEfficiency(*GMSBStau200_RecoPFMET_noPres_passMET_,*GMSBStau200_RecoPFMET_noPres_);
  GMSBStau200_METEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau200_METEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau200_METEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau200_METEff_RecoPFMET_noPres.png"); */

  // 09.8) MET trigger efficiency vs RECO PF MET, pass preselection
  TH2F* GMSBStau200_METEff_RecoPFMET_passPres = new TH2F("GMSBStau200_METEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau200_METEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau200_METEff_RecoPFMET_passPres->Draw();  
  TEfficiency* GMSBStau200_METEff_RecoPFMET_passPres_TEff = new TEfficiency(*GMSBStau200_RecoPFMET_passPres_passMET_,*GMSBStau200_RecoPFMET_passPres_);
  GMSBStau200_METEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau200_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau200_METEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau200_METEff_RecoPFMET_passPres.png");

  /* // 09.9) Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* GMSBStau200_MuonEff_RecoPFMET_noPres = new TH2F("GMSBStau200_MuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau200_MuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau200_MuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* GMSBStau200_MuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*GMSBStau200_RecoPFMET_noPres_passMuon_,*GMSBStau200_RecoPFMET_noPres_);
  GMSBStau200_MuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau200_MuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau200_MuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau200_MuonEff_RecoPFMET_noPres.png"); */

  // 09.10) Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* GMSBStau200_MuonEff_RecoPFMET_passPres = new TH2F("GMSBStau200_MuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau200_MuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau200_MuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* GMSBStau200_MuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*GMSBStau200_RecoPFMET_passPres_passMuon_,*GMSBStau200_RecoPFMET_passPres_);
  GMSBStau200_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau200_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau200_MuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau200_MuonEff_RecoPFMET_passPres.png");

  /* // 09.11) MET or Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* GMSBStau200_METOrMuonEff_RecoPFMET_noPres = new TH2F("GMSBStau200_METOrMuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau200_METOrMuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau200_METOrMuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* GMSBStau200_METOrMuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*GMSBStau200_RecoPFMET_noPres_passMETOrMuon_,*GMSBStau200_RecoPFMET_noPres_);
  GMSBStau200_METOrMuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau200_METOrMuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau200_METOrMuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau200_METOrMuonEff_RecoPFMET_noPres.png"); */

  // 09.12) MET or Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* GMSBStau200_METOrMuonEff_RecoPFMET_passPres = new TH2F("GMSBStau200_METOrMuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau200_METOrMuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau200_METOrMuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* GMSBStau200_METOrMuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*GMSBStau200_RecoPFMET_passPres_passMETOrMuon_,*GMSBStau200_RecoPFMET_passPres_);
  GMSBStau200_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau200_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau200_METOrMuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau200_METOrMuonEff_RecoPFMET_passPres.png");

  /* // 09.13) MET trigger efficiency vs HLT Calo MET, no preselection
  TH2F* GMSBStau200_METEff_HLTCaloMET_noPres = new TH2F("GMSBStau200_METEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau200_METEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau200_METEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* GMSBStau200_METEff_HLTCaloMET_noPres_TEff = new TEfficiency(*GMSBStau200_HLTCaloMET_noPres_passMET_,*GMSBStau200_HLTCaloMET_noPres_);
  GMSBStau200_METEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau200_METEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau200_METEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau200_METEff_HLTCaloMET_noPres.png"); */

  // 09.14) MET trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* GMSBStau200_METEff_HLTCaloMET_passPres = new TH2F("GMSBStau200_METEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau200_METEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau200_METEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* GMSBStau200_METEff_HLTCaloMET_passPres_TEff = new TEfficiency(*GMSBStau200_HLTCaloMET_passPres_passMET_,*GMSBStau200_HLTCaloMET_passPres_);
  GMSBStau200_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau200_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau200_METEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau200_METEff_HLTCaloMET_passPres.png");

  /* // 09.15) Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* GMSBStau200_MuonEff_HLTCaloMET_noPres = new TH2F("GMSBStau200_MuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau200_MuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau200_MuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* GMSBStau200_MuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*GMSBStau200_HLTCaloMET_noPres_passMuon_,*GMSBStau200_HLTCaloMET_noPres_);
  GMSBStau200_MuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau200_MuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau200_MuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau200_MuonEff_HLTCaloMET_noPres.png"); */

  // 09.16) Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* GMSBStau200_MuonEff_HLTCaloMET_passPres = new TH2F("GMSBStau200_MuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau200_MuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau200_MuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* GMSBStau200_MuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*GMSBStau200_HLTCaloMET_passPres_passMuon_,*GMSBStau200_HLTCaloMET_passPres_);
  GMSBStau200_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau200_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau200_MuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau200_MuonEff_HLTCaloMET_passPres.png");

  /* // 09.17) MET or Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* GMSBStau200_METOrMuonEff_HLTCaloMET_noPres = new TH2F("GMSBStau200_METOrMuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau200_METOrMuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau200_METOrMuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* GMSBStau200_METOrMuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*GMSBStau200_HLTCaloMET_noPres_passMETOrMuon_,*GMSBStau200_HLTCaloMET_noPres_);
  GMSBStau200_METOrMuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau200_METOrMuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau200_METOrMuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau200_METOrMuonEff_HLTCaloMET_noPres.png"); */

  // 09.18) MET or Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* GMSBStau200_METOrMuonEff_HLTCaloMET_passPres = new TH2F("GMSBStau200_METOrMuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau200_METOrMuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau200_METOrMuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* GMSBStau200_METOrMuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*GMSBStau200_HLTCaloMET_passPres_passMETOrMuon_,*GMSBStau200_HLTCaloMET_passPres_);
  GMSBStau200_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau200_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau200_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau200_METOrMuonEff_HLTCaloMET_passPres.png");

  /* // 09.19) MET trigger efficiency vs HLT PF MET, no preselection
  TH2F* GMSBStau200_METEff_HLTPFMET_noPres = new TH2F("GMSBStau200_METEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau200_METEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau200_METEff_HLTPFMET_noPres->Draw();  
  TEfficiency* GMSBStau200_METEff_HLTPFMET_noPres_TEff = new TEfficiency(*GMSBStau200_HLTPFMET_noPres_passMET_,*GMSBStau200_HLTPFMET_noPres_);
  GMSBStau200_METEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau200_METEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau200_METEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau200_METEff_HLTPFMET_noPres.png"); */

  // 09.20) MET trigger efficiency vs HLT PF MET, pass preselection
  TH2F* GMSBStau200_METEff_HLTPFMET_passPres = new TH2F("GMSBStau200_METEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau200_METEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau200_METEff_HLTPFMET_passPres->Draw();  
  TEfficiency* GMSBStau200_METEff_HLTPFMET_passPres_TEff = new TEfficiency(*GMSBStau200_HLTPFMET_passPres_passMET_,*GMSBStau200_HLTPFMET_passPres_);
  GMSBStau200_METEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau200_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau200_METEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau200_METEff_HLTPFMET_passPres.png");

  /* // 09.21) Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* GMSBStau200_MuonEff_HLTPFMET_noPres = new TH2F("GMSBStau200_MuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau200_MuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau200_MuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* GMSBStau200_MuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*GMSBStau200_HLTPFMET_noPres_passMuon_,*GMSBStau200_HLTPFMET_noPres_);
  GMSBStau200_MuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau200_MuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau200_MuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau200_MuonEff_HLTPFMET_noPres.png"); */

  // 09.22) Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* GMSBStau200_MuonEff_HLTPFMET_passPres = new TH2F("GMSBStau200_MuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau200_MuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau200_MuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* GMSBStau200_MuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*GMSBStau200_HLTPFMET_passPres_passMuon_,*GMSBStau200_HLTPFMET_passPres_);
  GMSBStau200_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau200_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau200_MuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau200_MuonEff_HLTPFMET_passPres.png");

  /* // 09.23) MET or Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* GMSBStau200_METOrMuonEff_HLTPFMET_noPres = new TH2F("GMSBStau200_METOrMuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau200_METOrMuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau200_METOrMuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* GMSBStau200_METOrMuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*GMSBStau200_HLTPFMET_noPres_passMETOrMuon_,*GMSBStau200_HLTPFMET_noPres_);
  GMSBStau200_METOrMuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau200_METOrMuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau200_METOrMuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau200_METOrMuonEff_HLTPFMET_noPres.png"); */

  // 09.24) MET or Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* GMSBStau200_METOrMuonEff_HLTPFMET_passPres = new TH2F("GMSBStau200_METOrMuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau200_METOrMuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau200_METOrMuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* GMSBStau200_METOrMuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*GMSBStau200_HLTPFMET_passPres_passMETOrMuon_,*GMSBStau200_HLTPFMET_passPres_);
  GMSBStau200_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau200_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau200_METOrMuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau200_METOrMuonEff_HLTPFMET_passPres.png");

  //=====================
  //  GMSBStau 432 GeV  
  //=====================

  /* // 10.1) MET trigger efficiency vs RECO Calo MET, no preselection
  TH2F* GMSBStau432_METEff_RecoCaloMET_noPres = new TH2F("GMSBStau432_METEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau432_METEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau432_METEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* GMSBStau432_METEff_RecoCaloMET_noPres_TEff = new TEfficiency(*GMSBStau432_RecoCaloMET_noPres_passMET_,*GMSBStau432_RecoCaloMET_noPres_);
  GMSBStau432_METEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau432_METEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_METEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau432_METEff_RecoCaloMET_noPres.png"); */

  // 10.2) MET trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* GMSBStau432_METEff_RecoCaloMET_passPres = new TH2F("GMSBStau432_METEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau432_METEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau432_METEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* GMSBStau432_METEff_RecoCaloMET_passPres_TEff = new TEfficiency(*GMSBStau432_RecoCaloMET_passPres_passMET_,*GMSBStau432_RecoCaloMET_passPres_);
  GMSBStau432_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau432_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_METEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau432_METEff_RecoCaloMET_passPres.png");

  /* // 10.3) Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* GMSBStau432_MuonEff_RecoCaloMET_noPres = new TH2F("GMSBStau432_MuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau432_MuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau432_MuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* GMSBStau432_MuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*GMSBStau432_RecoCaloMET_noPres_passMuon_,*GMSBStau432_RecoCaloMET_noPres_);
  GMSBStau432_MuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau432_MuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_MuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau432_MuonEff_RecoCaloMET_noPres.png"); */

  // 10.4) Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* GMSBStau432_MuonEff_RecoCaloMET_passPres = new TH2F("GMSBStau432_MuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau432_MuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau432_MuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* GMSBStau432_MuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*GMSBStau432_RecoCaloMET_passPres_passMuon_,*GMSBStau432_RecoCaloMET_passPres_);
  GMSBStau432_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau432_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_MuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau432_MuonEff_RecoCaloMET_passPres.png");

  /* // 10.5) MET or Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* GMSBStau432_METOrMuonEff_RecoCaloMET_noPres = new TH2F("GMSBStau432_METOrMuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau432_METOrMuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau432_METOrMuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* GMSBStau432_METOrMuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*GMSBStau432_RecoCaloMET_noPres_passMETOrMuon_,*GMSBStau432_RecoCaloMET_noPres_);
  GMSBStau432_METOrMuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau432_METOrMuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_METOrMuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau432_METOrMuonEff_RecoCaloMET_noPres.png"); */

  // 10.6) MET or Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* GMSBStau432_METOrMuonEff_RecoCaloMET_passPres = new TH2F("GMSBStau432_METOrMuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau432_METOrMuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau432_METOrMuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* GMSBStau432_METOrMuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*GMSBStau432_RecoCaloMET_passPres_passMETOrMuon_,*GMSBStau432_RecoCaloMET_passPres_);
  GMSBStau432_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau432_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau432_METOrMuonEff_RecoCaloMET_passPres.png");

  /* // 10.7) MET trigger efficiency vs RECO PF MET, no preselection
  TH2F* GMSBStau432_METEff_RecoPFMET_noPres = new TH2F("GMSBStau432_METEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau432_METEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau432_METEff_RecoPFMET_noPres->Draw();  
  TEfficiency* GMSBStau432_METEff_RecoPFMET_noPres_TEff = new TEfficiency(*GMSBStau432_RecoPFMET_noPres_passMET_,*GMSBStau432_RecoPFMET_noPres_);
  GMSBStau432_METEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau432_METEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_METEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau432_METEff_RecoPFMET_noPres.png"); */

  // 10.8) MET trigger efficiency vs RECO PF MET, pass preselection
  TH2F* GMSBStau432_METEff_RecoPFMET_passPres = new TH2F("GMSBStau432_METEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau432_METEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau432_METEff_RecoPFMET_passPres->Draw();  
  TEfficiency* GMSBStau432_METEff_RecoPFMET_passPres_TEff = new TEfficiency(*GMSBStau432_RecoPFMET_passPres_passMET_,*GMSBStau432_RecoPFMET_passPres_);
  GMSBStau432_METEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau432_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_METEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau432_METEff_RecoPFMET_passPres.png");

  /* // 10.9) Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* GMSBStau432_MuonEff_RecoPFMET_noPres = new TH2F("GMSBStau432_MuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau432_MuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau432_MuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* GMSBStau432_MuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*GMSBStau432_RecoPFMET_noPres_passMuon_,*GMSBStau432_RecoPFMET_noPres_);
  GMSBStau432_MuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau432_MuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_MuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau432_MuonEff_RecoPFMET_noPres.png"); */

  // 10.10) Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* GMSBStau432_MuonEff_RecoPFMET_passPres = new TH2F("GMSBStau432_MuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau432_MuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau432_MuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* GMSBStau432_MuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*GMSBStau432_RecoPFMET_passPres_passMuon_,*GMSBStau432_RecoPFMET_passPres_);
  GMSBStau432_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau432_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_MuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau432_MuonEff_RecoPFMET_passPres.png");

  /* // 10.11) MET or Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* GMSBStau432_METOrMuonEff_RecoPFMET_noPres = new TH2F("GMSBStau432_METOrMuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau432_METOrMuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau432_METOrMuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* GMSBStau432_METOrMuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*GMSBStau432_RecoPFMET_noPres_passMETOrMuon_,*GMSBStau432_RecoPFMET_noPres_);
  GMSBStau432_METOrMuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau432_METOrMuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_METOrMuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau432_METOrMuonEff_RecoPFMET_noPres.png"); */

  // 10.12) MET or Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* GMSBStau432_METOrMuonEff_RecoPFMET_passPres = new TH2F("GMSBStau432_METOrMuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau432_METOrMuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau432_METOrMuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* GMSBStau432_METOrMuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*GMSBStau432_RecoPFMET_passPres_passMETOrMuon_,*GMSBStau432_RecoPFMET_passPres_);
  GMSBStau432_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau432_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_METOrMuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau432_METOrMuonEff_RecoPFMET_passPres.png");

  /* // 10.13) MET trigger efficiency vs HLT Calo MET, no preselection
  TH2F* GMSBStau432_METEff_HLTCaloMET_noPres = new TH2F("GMSBStau432_METEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau432_METEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau432_METEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* GMSBStau432_METEff_HLTCaloMET_noPres_TEff = new TEfficiency(*GMSBStau432_HLTCaloMET_noPres_passMET_,*GMSBStau432_HLTCaloMET_noPres_);
  GMSBStau432_METEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau432_METEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_METEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau432_METEff_HLTCaloMET_noPres.png"); */

  // 10.14) MET trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* GMSBStau432_METEff_HLTCaloMET_passPres = new TH2F("GMSBStau432_METEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau432_METEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau432_METEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* GMSBStau432_METEff_HLTCaloMET_passPres_TEff = new TEfficiency(*GMSBStau432_HLTCaloMET_passPres_passMET_,*GMSBStau432_HLTCaloMET_passPres_);
  GMSBStau432_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau432_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_METEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau432_METEff_HLTCaloMET_passPres.png");

  /* // 10.15) Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* GMSBStau432_MuonEff_HLTCaloMET_noPres = new TH2F("GMSBStau432_MuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau432_MuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau432_MuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* GMSBStau432_MuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*GMSBStau432_HLTCaloMET_noPres_passMuon_,*GMSBStau432_HLTCaloMET_noPres_);
  GMSBStau432_MuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau432_MuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_MuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau432_MuonEff_HLTCaloMET_noPres.png"); */

  // 10.16) Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* GMSBStau432_MuonEff_HLTCaloMET_passPres = new TH2F("GMSBStau432_MuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau432_MuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau432_MuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* GMSBStau432_MuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*GMSBStau432_HLTCaloMET_passPres_passMuon_,*GMSBStau432_HLTCaloMET_passPres_);
  GMSBStau432_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau432_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_MuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau432_MuonEff_HLTCaloMET_passPres.png");

  /* // 10.17) MET or Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* GMSBStau432_METOrMuonEff_HLTCaloMET_noPres = new TH2F("GMSBStau432_METOrMuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau432_METOrMuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau432_METOrMuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* GMSBStau432_METOrMuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*GMSBStau432_HLTCaloMET_noPres_passMETOrMuon_,*GMSBStau432_HLTCaloMET_noPres_);
  GMSBStau432_METOrMuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau432_METOrMuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_METOrMuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau432_METOrMuonEff_HLTCaloMET_noPres.png"); */

  // 10.18) MET or Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* GMSBStau432_METOrMuonEff_HLTCaloMET_passPres = new TH2F("GMSBStau432_METOrMuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau432_METOrMuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau432_METOrMuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* GMSBStau432_METOrMuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*GMSBStau432_HLTCaloMET_passPres_passMETOrMuon_,*GMSBStau432_HLTCaloMET_passPres_);
  GMSBStau432_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau432_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau432_METOrMuonEff_HLTCaloMET_passPres.png");

  /* // 10.19) MET trigger efficiency vs HLT PF MET, no preselection
  TH2F* GMSBStau432_METEff_HLTPFMET_noPres = new TH2F("GMSBStau432_METEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau432_METEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau432_METEff_HLTPFMET_noPres->Draw();  
  TEfficiency* GMSBStau432_METEff_HLTPFMET_noPres_TEff = new TEfficiency(*GMSBStau432_HLTPFMET_noPres_passMET_,*GMSBStau432_HLTPFMET_noPres_);
  GMSBStau432_METEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau432_METEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_METEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau432_METEff_HLTPFMET_noPres.png"); */

  // 10.20) MET trigger efficiency vs HLT PF MET, pass preselection
  TH2F* GMSBStau432_METEff_HLTPFMET_passPres = new TH2F("GMSBStau432_METEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau432_METEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau432_METEff_HLTPFMET_passPres->Draw();  
  TEfficiency* GMSBStau432_METEff_HLTPFMET_passPres_TEff = new TEfficiency(*GMSBStau432_HLTPFMET_passPres_passMET_,*GMSBStau432_HLTPFMET_passPres_);
  GMSBStau432_METEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau432_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_METEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau432_METEff_HLTPFMET_passPres.png");

  /* // 10.21) Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* GMSBStau432_MuonEff_HLTPFMET_noPres = new TH2F("GMSBStau432_MuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau432_MuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau432_MuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* GMSBStau432_MuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*GMSBStau432_HLTPFMET_noPres_passMuon_,*GMSBStau432_HLTPFMET_noPres_);
  GMSBStau432_MuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau432_MuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_MuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau432_MuonEff_HLTPFMET_noPres.png"); */

  // 10.22) Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* GMSBStau432_MuonEff_HLTPFMET_passPres = new TH2F("GMSBStau432_MuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau432_MuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau432_MuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* GMSBStau432_MuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*GMSBStau432_HLTPFMET_passPres_passMuon_,*GMSBStau432_HLTPFMET_passPres_);
  GMSBStau432_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau432_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_MuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau432_MuonEff_HLTPFMET_passPres.png");

  /* // 10.23) MET or Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* GMSBStau432_METOrMuonEff_HLTPFMET_noPres = new TH2F("GMSBStau432_METOrMuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau432_METOrMuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau432_METOrMuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* GMSBStau432_METOrMuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*GMSBStau432_HLTPFMET_noPres_passMETOrMuon_,*GMSBStau432_HLTPFMET_noPres_);
  GMSBStau432_METOrMuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau432_METOrMuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_METOrMuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau432_METOrMuonEff_HLTPFMET_noPres.png"); */

  // 10.24) MET or Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* GMSBStau432_METOrMuonEff_HLTPFMET_passPres = new TH2F("GMSBStau432_METOrMuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau432_METOrMuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau432_METOrMuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* GMSBStau432_METOrMuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*GMSBStau432_HLTPFMET_passPres_passMETOrMuon_,*GMSBStau432_HLTPFMET_passPres_);
  GMSBStau432_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau432_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_METOrMuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau432_METOrMuonEff_HLTPFMET_passPres.png");

  //=====================
  //  GMSBStau 651 GeV  
  //=====================

  /* // 11.1) MET trigger efficiency vs RECO Calo MET, no preselection
  TH2F* GMSBStau651_METEff_RecoCaloMET_noPres = new TH2F("GMSBStau651_METEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau651_METEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau651_METEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* GMSBStau651_METEff_RecoCaloMET_noPres_TEff = new TEfficiency(*GMSBStau651_RecoCaloMET_noPres_passMET_,*GMSBStau651_RecoCaloMET_noPres_);
  GMSBStau651_METEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau651_METEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau651_METEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau651_METEff_RecoCaloMET_noPres.png"); */

  // 11.2) MET trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* GMSBStau651_METEff_RecoCaloMET_passPres = new TH2F("GMSBStau651_METEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau651_METEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau651_METEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* GMSBStau651_METEff_RecoCaloMET_passPres_TEff = new TEfficiency(*GMSBStau651_RecoCaloMET_passPres_passMET_,*GMSBStau651_RecoCaloMET_passPres_);
  GMSBStau651_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau651_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau651_METEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau651_METEff_RecoCaloMET_passPres.png");

  /* // 11.3) Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* GMSBStau651_MuonEff_RecoCaloMET_noPres = new TH2F("GMSBStau651_MuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau651_MuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau651_MuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* GMSBStau651_MuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*GMSBStau651_RecoCaloMET_noPres_passMuon_,*GMSBStau651_RecoCaloMET_noPres_);
  GMSBStau651_MuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau651_MuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau651_MuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau651_MuonEff_RecoCaloMET_noPres.png"); */

  // 11.4) Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* GMSBStau651_MuonEff_RecoCaloMET_passPres = new TH2F("GMSBStau651_MuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau651_MuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau651_MuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* GMSBStau651_MuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*GMSBStau651_RecoCaloMET_passPres_passMuon_,*GMSBStau651_RecoCaloMET_passPres_);
  GMSBStau651_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau651_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau651_MuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau651_MuonEff_RecoCaloMET_passPres.png");

  /* // 11.5) MET or Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* GMSBStau651_METOrMuonEff_RecoCaloMET_noPres = new TH2F("GMSBStau651_METOrMuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau651_METOrMuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau651_METOrMuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* GMSBStau651_METOrMuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*GMSBStau651_RecoCaloMET_noPres_passMETOrMuon_,*GMSBStau651_RecoCaloMET_noPres_);
  GMSBStau651_METOrMuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau651_METOrMuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau651_METOrMuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau651_METOrMuonEff_RecoCaloMET_noPres.png"); */

  // 11.6) MET or Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* GMSBStau651_METOrMuonEff_RecoCaloMET_passPres = new TH2F("GMSBStau651_METOrMuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau651_METOrMuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau651_METOrMuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* GMSBStau651_METOrMuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*GMSBStau651_RecoCaloMET_passPres_passMETOrMuon_,*GMSBStau651_RecoCaloMET_passPres_);
  GMSBStau651_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau651_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau651_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau651_METOrMuonEff_RecoCaloMET_passPres.png");

  /* // 11.7) MET trigger efficiency vs RECO PF MET, no preselection
  TH2F* GMSBStau651_METEff_RecoPFMET_noPres = new TH2F("GMSBStau651_METEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau651_METEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau651_METEff_RecoPFMET_noPres->Draw();  
  TEfficiency* GMSBStau651_METEff_RecoPFMET_noPres_TEff = new TEfficiency(*GMSBStau651_RecoPFMET_noPres_passMET_,*GMSBStau651_RecoPFMET_noPres_);
  GMSBStau651_METEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau651_METEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau651_METEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau651_METEff_RecoPFMET_noPres.png"); */

  // 11.8) MET trigger efficiency vs RECO PF MET, pass preselection
  TH2F* GMSBStau651_METEff_RecoPFMET_passPres = new TH2F("GMSBStau651_METEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau651_METEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau651_METEff_RecoPFMET_passPres->Draw();  
  TEfficiency* GMSBStau651_METEff_RecoPFMET_passPres_TEff = new TEfficiency(*GMSBStau651_RecoPFMET_passPres_passMET_,*GMSBStau651_RecoPFMET_passPres_);
  GMSBStau651_METEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau651_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau651_METEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau651_METEff_RecoPFMET_passPres.png");

  /* // 11.9) Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* GMSBStau651_MuonEff_RecoPFMET_noPres = new TH2F("GMSBStau651_MuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau651_MuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau651_MuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* GMSBStau651_MuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*GMSBStau651_RecoPFMET_noPres_passMuon_,*GMSBStau651_RecoPFMET_noPres_);
  GMSBStau651_MuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau651_MuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau651_MuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau651_MuonEff_RecoPFMET_noPres.png"); */

  // 11.10) Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* GMSBStau651_MuonEff_RecoPFMET_passPres = new TH2F("GMSBStau651_MuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau651_MuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau651_MuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* GMSBStau651_MuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*GMSBStau651_RecoPFMET_passPres_passMuon_,*GMSBStau651_RecoPFMET_passPres_);
  GMSBStau651_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau651_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau651_MuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau651_MuonEff_RecoPFMET_passPres.png");

  /* // 11.11) MET or Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* GMSBStau651_METOrMuonEff_RecoPFMET_noPres = new TH2F("GMSBStau651_METOrMuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau651_METOrMuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau651_METOrMuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* GMSBStau651_METOrMuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*GMSBStau651_RecoPFMET_noPres_passMETOrMuon_,*GMSBStau651_RecoPFMET_noPres_);
  GMSBStau651_METOrMuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau651_METOrMuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau651_METOrMuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau651_METOrMuonEff_RecoPFMET_noPres.png"); */

  // 11.12) MET or Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* GMSBStau651_METOrMuonEff_RecoPFMET_passPres = new TH2F("GMSBStau651_METOrMuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau651_METOrMuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau651_METOrMuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* GMSBStau651_METOrMuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*GMSBStau651_RecoPFMET_passPres_passMETOrMuon_,*GMSBStau651_RecoPFMET_passPres_);
  GMSBStau651_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau651_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau651_METOrMuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau651_METOrMuonEff_RecoPFMET_passPres.png");

  /* // 11.13) MET trigger efficiency vs HLT Calo MET, no preselection
  TH2F* GMSBStau651_METEff_HLTCaloMET_noPres = new TH2F("GMSBStau651_METEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau651_METEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau651_METEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* GMSBStau651_METEff_HLTCaloMET_noPres_TEff = new TEfficiency(*GMSBStau651_HLTCaloMET_noPres_passMET_,*GMSBStau651_HLTCaloMET_noPres_);
  GMSBStau651_METEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau651_METEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau651_METEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau651_METEff_HLTCaloMET_noPres.png"); */

  // 11.14) MET trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* GMSBStau651_METEff_HLTCaloMET_passPres = new TH2F("GMSBStau651_METEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau651_METEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau651_METEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* GMSBStau651_METEff_HLTCaloMET_passPres_TEff = new TEfficiency(*GMSBStau651_HLTCaloMET_passPres_passMET_,*GMSBStau651_HLTCaloMET_passPres_);
  GMSBStau651_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau651_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau651_METEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau651_METEff_HLTCaloMET_passPres.png");

  /* // 11.15) Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* GMSBStau651_MuonEff_HLTCaloMET_noPres = new TH2F("GMSBStau651_MuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau651_MuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau651_MuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* GMSBStau651_MuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*GMSBStau651_HLTCaloMET_noPres_passMuon_,*GMSBStau651_HLTCaloMET_noPres_);
  GMSBStau651_MuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau651_MuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau651_MuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau651_MuonEff_HLTCaloMET_noPres.png"); */

  // 11.16) Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* GMSBStau651_MuonEff_HLTCaloMET_passPres = new TH2F("GMSBStau651_MuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau651_MuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau651_MuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* GMSBStau651_MuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*GMSBStau651_HLTCaloMET_passPres_passMuon_,*GMSBStau651_HLTCaloMET_passPres_);
  GMSBStau651_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau651_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau651_MuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau651_MuonEff_HLTCaloMET_passPres.png");

  /* // 11.17) MET or Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* GMSBStau651_METOrMuonEff_HLTCaloMET_noPres = new TH2F("GMSBStau651_METOrMuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau651_METOrMuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau651_METOrMuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* GMSBStau651_METOrMuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*GMSBStau651_HLTCaloMET_noPres_passMETOrMuon_,*GMSBStau651_HLTCaloMET_noPres_);
  GMSBStau651_METOrMuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau651_METOrMuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau651_METOrMuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau651_METOrMuonEff_HLTCaloMET_noPres.png"); */

  // 11.18) MET or Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* GMSBStau651_METOrMuonEff_HLTCaloMET_passPres = new TH2F("GMSBStau651_METOrMuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau651_METOrMuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau651_METOrMuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* GMSBStau651_METOrMuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*GMSBStau651_HLTCaloMET_passPres_passMETOrMuon_,*GMSBStau651_HLTCaloMET_passPres_);
  GMSBStau651_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau651_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau651_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau651_METOrMuonEff_HLTCaloMET_passPres.png");

  /* // 11.19) MET trigger efficiency vs HLT PF MET, no preselection
  TH2F* GMSBStau651_METEff_HLTPFMET_noPres = new TH2F("GMSBStau651_METEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau651_METEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau651_METEff_HLTPFMET_noPres->Draw();  
  TEfficiency* GMSBStau651_METEff_HLTPFMET_noPres_TEff = new TEfficiency(*GMSBStau651_HLTPFMET_noPres_passMET_,*GMSBStau651_HLTPFMET_noPres_);
  GMSBStau651_METEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau651_METEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau651_METEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau651_METEff_HLTPFMET_noPres.png"); */

  // 11.20) MET trigger efficiency vs HLT PF MET, pass preselection
  TH2F* GMSBStau651_METEff_HLTPFMET_passPres = new TH2F("GMSBStau651_METEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau651_METEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau651_METEff_HLTPFMET_passPres->Draw();  
  TEfficiency* GMSBStau651_METEff_HLTPFMET_passPres_TEff = new TEfficiency(*GMSBStau651_HLTPFMET_passPres_passMET_,*GMSBStau651_HLTPFMET_passPres_);
  GMSBStau651_METEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau651_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau651_METEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau651_METEff_HLTPFMET_passPres.png");

  /* // 11.21) Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* GMSBStau651_MuonEff_HLTPFMET_noPres = new TH2F("GMSBStau651_MuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau651_MuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau651_MuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* GMSBStau651_MuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*GMSBStau651_HLTPFMET_noPres_passMuon_,*GMSBStau651_HLTPFMET_noPres_);
  GMSBStau651_MuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau651_MuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau651_MuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau651_MuonEff_HLTPFMET_noPres.png"); */

  // 11.22) Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* GMSBStau651_MuonEff_HLTPFMET_passPres = new TH2F("GMSBStau651_MuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau651_MuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau651_MuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* GMSBStau651_MuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*GMSBStau651_HLTPFMET_passPres_passMuon_,*GMSBStau651_HLTPFMET_passPres_);
  GMSBStau651_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau651_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau651_MuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau651_MuonEff_HLTPFMET_passPres.png");

  /* // 11.23) MET or Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* GMSBStau651_METOrMuonEff_HLTPFMET_noPres = new TH2F("GMSBStau651_METOrMuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau651_METOrMuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau651_METOrMuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* GMSBStau651_METOrMuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*GMSBStau651_HLTPFMET_noPres_passMETOrMuon_,*GMSBStau651_HLTPFMET_noPres_);
  GMSBStau651_METOrMuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau651_METOrMuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau651_METOrMuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau651_METOrMuonEff_HLTPFMET_noPres.png"); */

  // 11.24) MET or Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* GMSBStau651_METOrMuonEff_HLTPFMET_passPres = new TH2F("GMSBStau651_METOrMuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau651_METOrMuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau651_METOrMuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* GMSBStau651_METOrMuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*GMSBStau651_HLTPFMET_passPres_passMETOrMuon_,*GMSBStau651_HLTPFMET_passPres_);
  GMSBStau651_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau651_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau651_METOrMuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau651_METOrMuonEff_HLTPFMET_passPres.png");

  //=====================
  //  GMSBStau 871 GeV  
  //=====================

  /* // 12.1) MET trigger efficiency vs RECO Calo MET, no preselection
  TH2F* GMSBStau871_METEff_RecoCaloMET_noPres = new TH2F("GMSBStau871_METEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau871_METEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau871_METEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* GMSBStau871_METEff_RecoCaloMET_noPres_TEff = new TEfficiency(*GMSBStau871_RecoCaloMET_noPres_passMET_,*GMSBStau871_RecoCaloMET_noPres_);
  GMSBStau871_METEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau871_METEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau871_METEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau871_METEff_RecoCaloMET_noPres.png"); */

  // 12.2) MET trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* GMSBStau871_METEff_RecoCaloMET_passPres = new TH2F("GMSBStau871_METEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau871_METEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau871_METEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* GMSBStau871_METEff_RecoCaloMET_passPres_TEff = new TEfficiency(*GMSBStau871_RecoCaloMET_passPres_passMET_,*GMSBStau871_RecoCaloMET_passPres_);
  GMSBStau871_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau871_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau871_METEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau871_METEff_RecoCaloMET_passPres.png");

  /* // 12.3) Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* GMSBStau871_MuonEff_RecoCaloMET_noPres = new TH2F("GMSBStau871_MuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau871_MuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau871_MuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* GMSBStau871_MuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*GMSBStau871_RecoCaloMET_noPres_passMuon_,*GMSBStau871_RecoCaloMET_noPres_);
  GMSBStau871_MuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau871_MuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau871_MuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau871_MuonEff_RecoCaloMET_noPres.png"); */

  // 12.4) Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* GMSBStau871_MuonEff_RecoCaloMET_passPres = new TH2F("GMSBStau871_MuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau871_MuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau871_MuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* GMSBStau871_MuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*GMSBStau871_RecoCaloMET_passPres_passMuon_,*GMSBStau871_RecoCaloMET_passPres_);
  GMSBStau871_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau871_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau871_MuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau871_MuonEff_RecoCaloMET_passPres.png");

  /* // 12.5) MET or Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* GMSBStau871_METOrMuonEff_RecoCaloMET_noPres = new TH2F("GMSBStau871_METOrMuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau871_METOrMuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau871_METOrMuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* GMSBStau871_METOrMuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*GMSBStau871_RecoCaloMET_noPres_passMETOrMuon_,*GMSBStau871_RecoCaloMET_noPres_);
  GMSBStau871_METOrMuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau871_METOrMuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau871_METOrMuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau871_METOrMuonEff_RecoCaloMET_noPres.png"); */

  // 12.6) MET or Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* GMSBStau871_METOrMuonEff_RecoCaloMET_passPres = new TH2F("GMSBStau871_METOrMuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau871_METOrMuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau871_METOrMuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* GMSBStau871_METOrMuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*GMSBStau871_RecoCaloMET_passPres_passMETOrMuon_,*GMSBStau871_RecoCaloMET_passPres_);
  GMSBStau871_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau871_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau871_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau871_METOrMuonEff_RecoCaloMET_passPres.png");

  /* // 12.7) MET trigger efficiency vs RECO PF MET, no preselection
  TH2F* GMSBStau871_METEff_RecoPFMET_noPres = new TH2F("GMSBStau871_METEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau871_METEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau871_METEff_RecoPFMET_noPres->Draw();  
  TEfficiency* GMSBStau871_METEff_RecoPFMET_noPres_TEff = new TEfficiency(*GMSBStau871_RecoPFMET_noPres_passMET_,*GMSBStau871_RecoPFMET_noPres_);
  GMSBStau871_METEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau871_METEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau871_METEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau871_METEff_RecoPFMET_noPres.png"); */

  // 12.8) MET trigger efficiency vs RECO PF MET, pass preselection
  TH2F* GMSBStau871_METEff_RecoPFMET_passPres = new TH2F("GMSBStau871_METEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau871_METEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau871_METEff_RecoPFMET_passPres->Draw();  
  TEfficiency* GMSBStau871_METEff_RecoPFMET_passPres_TEff = new TEfficiency(*GMSBStau871_RecoPFMET_passPres_passMET_,*GMSBStau871_RecoPFMET_passPres_);
  GMSBStau871_METEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau871_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau871_METEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau871_METEff_RecoPFMET_passPres.png");

  /* // 12.9) Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* GMSBStau871_MuonEff_RecoPFMET_noPres = new TH2F("GMSBStau871_MuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau871_MuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau871_MuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* GMSBStau871_MuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*GMSBStau871_RecoPFMET_noPres_passMuon_,*GMSBStau871_RecoPFMET_noPres_);
  GMSBStau871_MuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau871_MuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau871_MuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau871_MuonEff_RecoPFMET_noPres.png"); */

  // 12.10) Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* GMSBStau871_MuonEff_RecoPFMET_passPres = new TH2F("GMSBStau871_MuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau871_MuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau871_MuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* GMSBStau871_MuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*GMSBStau871_RecoPFMET_passPres_passMuon_,*GMSBStau871_RecoPFMET_passPres_);
  GMSBStau871_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau871_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau871_MuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau871_MuonEff_RecoPFMET_passPres.png");

  /* // 12.11) MET or Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* GMSBStau871_METOrMuonEff_RecoPFMET_noPres = new TH2F("GMSBStau871_METOrMuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau871_METOrMuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau871_METOrMuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* GMSBStau871_METOrMuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*GMSBStau871_RecoPFMET_noPres_passMETOrMuon_,*GMSBStau871_RecoPFMET_noPres_);
  GMSBStau871_METOrMuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau871_METOrMuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau871_METOrMuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau871_METOrMuonEff_RecoPFMET_noPres.png"); */

  // 12.12) MET or Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* GMSBStau871_METOrMuonEff_RecoPFMET_passPres = new TH2F("GMSBStau871_METOrMuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau871_METOrMuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau871_METOrMuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* GMSBStau871_METOrMuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*GMSBStau871_RecoPFMET_passPres_passMETOrMuon_,*GMSBStau871_RecoPFMET_passPres_);
  GMSBStau871_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau871_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau871_METOrMuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau871_METOrMuonEff_RecoPFMET_passPres.png");

  /* // 12.13) MET trigger efficiency vs HLT Calo MET, no preselection
  TH2F* GMSBStau871_METEff_HLTCaloMET_noPres = new TH2F("GMSBStau871_METEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau871_METEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau871_METEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* GMSBStau871_METEff_HLTCaloMET_noPres_TEff = new TEfficiency(*GMSBStau871_HLTCaloMET_noPres_passMET_,*GMSBStau871_HLTCaloMET_noPres_);
  GMSBStau871_METEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau871_METEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau871_METEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau871_METEff_HLTCaloMET_noPres.png"); */

  // 12.14) MET trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* GMSBStau871_METEff_HLTCaloMET_passPres = new TH2F("GMSBStau871_METEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau871_METEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau871_METEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* GMSBStau871_METEff_HLTCaloMET_passPres_TEff = new TEfficiency(*GMSBStau871_HLTCaloMET_passPres_passMET_,*GMSBStau871_HLTCaloMET_passPres_);
  GMSBStau871_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau871_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau871_METEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau871_METEff_HLTCaloMET_passPres.png");

  /* // 12.15) Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* GMSBStau871_MuonEff_HLTCaloMET_noPres = new TH2F("GMSBStau871_MuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau871_MuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau871_MuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* GMSBStau871_MuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*GMSBStau871_HLTCaloMET_noPres_passMuon_,*GMSBStau871_HLTCaloMET_noPres_);
  GMSBStau871_MuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau871_MuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau871_MuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau871_MuonEff_HLTCaloMET_noPres.png"); */

  // 12.16) Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* GMSBStau871_MuonEff_HLTCaloMET_passPres = new TH2F("GMSBStau871_MuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau871_MuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau871_MuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* GMSBStau871_MuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*GMSBStau871_HLTCaloMET_passPres_passMuon_,*GMSBStau871_HLTCaloMET_passPres_);
  GMSBStau871_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau871_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau871_MuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau871_MuonEff_HLTCaloMET_passPres.png");

  /* // 12.17) MET or Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* GMSBStau871_METOrMuonEff_HLTCaloMET_noPres = new TH2F("GMSBStau871_METOrMuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau871_METOrMuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau871_METOrMuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* GMSBStau871_METOrMuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*GMSBStau871_HLTCaloMET_noPres_passMETOrMuon_,*GMSBStau871_HLTCaloMET_noPres_);
  GMSBStau871_METOrMuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau871_METOrMuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau871_METOrMuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau871_METOrMuonEff_HLTCaloMET_noPres.png"); */

  // 12.18) MET or Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* GMSBStau871_METOrMuonEff_HLTCaloMET_passPres = new TH2F("GMSBStau871_METOrMuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau871_METOrMuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau871_METOrMuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* GMSBStau871_METOrMuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*GMSBStau871_HLTCaloMET_passPres_passMETOrMuon_,*GMSBStau871_HLTCaloMET_passPres_);
  GMSBStau871_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau871_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau871_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau871_METOrMuonEff_HLTCaloMET_passPres.png");

  /* // 12.19) MET trigger efficiency vs HLT PF MET, no preselection
  TH2F* GMSBStau871_METEff_HLTPFMET_noPres = new TH2F("GMSBStau871_METEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau871_METEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau871_METEff_HLTPFMET_noPres->Draw();  
  TEfficiency* GMSBStau871_METEff_HLTPFMET_noPres_TEff = new TEfficiency(*GMSBStau871_HLTPFMET_noPres_passMET_,*GMSBStau871_HLTPFMET_noPres_);
  GMSBStau871_METEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau871_METEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau871_METEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau871_METEff_HLTPFMET_noPres.png"); */

  // 12.20) MET trigger efficiency vs HLT PF MET, pass preselection
  TH2F* GMSBStau871_METEff_HLTPFMET_passPres = new TH2F("GMSBStau871_METEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  GMSBStau871_METEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau871_METEff_HLTPFMET_passPres->Draw();  
  TEfficiency* GMSBStau871_METEff_HLTPFMET_passPres_TEff = new TEfficiency(*GMSBStau871_HLTPFMET_passPres_passMET_,*GMSBStau871_HLTPFMET_passPres_);
  GMSBStau871_METEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau871_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau871_METEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau871_METEff_HLTPFMET_passPres.png");

  /* // 12.21) Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* GMSBStau871_MuonEff_HLTPFMET_noPres = new TH2F("GMSBStau871_MuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau871_MuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau871_MuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* GMSBStau871_MuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*GMSBStau871_HLTPFMET_noPres_passMuon_,*GMSBStau871_HLTPFMET_noPres_);
  GMSBStau871_MuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau871_MuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau871_MuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau871_MuonEff_HLTPFMET_noPres.png"); */

  // 12.22) Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* GMSBStau871_MuonEff_HLTPFMET_passPres = new TH2F("GMSBStau871_MuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau871_MuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau871_MuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* GMSBStau871_MuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*GMSBStau871_HLTPFMET_passPres_passMuon_,*GMSBStau871_HLTPFMET_passPres_);
  GMSBStau871_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau871_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau871_MuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau871_MuonEff_HLTPFMET_passPres.png");

  /* // 12.23) MET or Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* GMSBStau871_METOrMuonEff_HLTPFMET_noPres = new TH2F("GMSBStau871_METOrMuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau871_METOrMuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau871_METOrMuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* GMSBStau871_METOrMuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*GMSBStau871_HLTPFMET_noPres_passMETOrMuon_,*GMSBStau871_HLTPFMET_noPres_);
  GMSBStau871_METOrMuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  GMSBStau871_METOrMuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  GMSBStau871_METOrMuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau871_METOrMuonEff_HLTPFMET_noPres.png"); */

  // 12.24) MET or Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* GMSBStau871_METOrMuonEff_HLTPFMET_passPres = new TH2F("GMSBStau871_METOrMuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  GMSBStau871_METOrMuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  GMSBStau871_METOrMuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* GMSBStau871_METOrMuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*GMSBStau871_HLTPFMET_passPres_passMETOrMuon_,*GMSBStau871_HLTPFMET_passPres_);
  GMSBStau871_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau871_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau871_METOrMuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/GMSBStau871_METOrMuonEff_HLTPFMET_passPres.png");

  //=====================
  //  PairStau 200 GeV  
  //=====================

  /* // 13.1) MET trigger efficiency vs RECO Calo MET, no preselection
  TH2F* PairStau200_METEff_RecoCaloMET_noPres = new TH2F("PairStau200_METEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  PairStau200_METEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau200_METEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* PairStau200_METEff_RecoCaloMET_noPres_TEff = new TEfficiency(*PairStau200_RecoCaloMET_noPres_passMET_,*PairStau200_RecoCaloMET_noPres_);
  PairStau200_METEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  PairStau200_METEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau200_METEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau200_METEff_RecoCaloMET_noPres.png"); */

  // 13.2) MET trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* PairStau200_METEff_RecoCaloMET_passPres = new TH2F("PairStau200_METEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  PairStau200_METEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau200_METEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* PairStau200_METEff_RecoCaloMET_passPres_TEff = new TEfficiency(*PairStau200_RecoCaloMET_passPres_passMET_,*PairStau200_RecoCaloMET_passPres_);
  PairStau200_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  PairStau200_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau200_METEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau200_METEff_RecoCaloMET_passPres.png");

  /* // 13.3) Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* PairStau200_MuonEff_RecoCaloMET_noPres = new TH2F("PairStau200_MuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau200_MuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau200_MuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* PairStau200_MuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*PairStau200_RecoCaloMET_noPres_passMuon_,*PairStau200_RecoCaloMET_noPres_);
  PairStau200_MuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  PairStau200_MuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau200_MuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau200_MuonEff_RecoCaloMET_noPres.png"); */

  // 13.4) Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* PairStau200_MuonEff_RecoCaloMET_passPres = new TH2F("PairStau200_MuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau200_MuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau200_MuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* PairStau200_MuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*PairStau200_RecoCaloMET_passPres_passMuon_,*PairStau200_RecoCaloMET_passPres_);
  PairStau200_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  PairStau200_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau200_MuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau200_MuonEff_RecoCaloMET_passPres.png");

  /* // 13.5) MET or Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* PairStau200_METOrMuonEff_RecoCaloMET_noPres = new TH2F("PairStau200_METOrMuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau200_METOrMuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau200_METOrMuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* PairStau200_METOrMuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*PairStau200_RecoCaloMET_noPres_passMETOrMuon_,*PairStau200_RecoCaloMET_noPres_);
  PairStau200_METOrMuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  PairStau200_METOrMuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau200_METOrMuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau200_METOrMuonEff_RecoCaloMET_noPres.png"); */

  // 13.6) MET or Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* PairStau200_METOrMuonEff_RecoCaloMET_passPres = new TH2F("PairStau200_METOrMuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau200_METOrMuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau200_METOrMuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* PairStau200_METOrMuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*PairStau200_RecoCaloMET_passPres_passMETOrMuon_,*PairStau200_RecoCaloMET_passPres_);
  PairStau200_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  PairStau200_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau200_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau200_METOrMuonEff_RecoCaloMET_passPres.png");

  /* // 13.7) MET trigger efficiency vs RECO PF MET, no preselection
  TH2F* PairStau200_METEff_RecoPFMET_noPres = new TH2F("PairStau200_METEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  PairStau200_METEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau200_METEff_RecoPFMET_noPres->Draw();  
  TEfficiency* PairStau200_METEff_RecoPFMET_noPres_TEff = new TEfficiency(*PairStau200_RecoPFMET_noPres_passMET_,*PairStau200_RecoPFMET_noPres_);
  PairStau200_METEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  PairStau200_METEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau200_METEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau200_METEff_RecoPFMET_noPres.png"); */

  // 13.8) MET trigger efficiency vs RECO PF MET, pass preselection
  TH2F* PairStau200_METEff_RecoPFMET_passPres = new TH2F("PairStau200_METEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  PairStau200_METEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau200_METEff_RecoPFMET_passPres->Draw();  
  TEfficiency* PairStau200_METEff_RecoPFMET_passPres_TEff = new TEfficiency(*PairStau200_RecoPFMET_passPres_passMET_,*PairStau200_RecoPFMET_passPres_);
  PairStau200_METEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  PairStau200_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau200_METEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau200_METEff_RecoPFMET_passPres.png");

  /* // 13.9) Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* PairStau200_MuonEff_RecoPFMET_noPres = new TH2F("PairStau200_MuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau200_MuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau200_MuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* PairStau200_MuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*PairStau200_RecoPFMET_noPres_passMuon_,*PairStau200_RecoPFMET_noPres_);
  PairStau200_MuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  PairStau200_MuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau200_MuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau200_MuonEff_RecoPFMET_noPres.png"); */

  // 13.10) Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* PairStau200_MuonEff_RecoPFMET_passPres = new TH2F("PairStau200_MuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau200_MuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau200_MuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* PairStau200_MuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*PairStau200_RecoPFMET_passPres_passMuon_,*PairStau200_RecoPFMET_passPres_);
  PairStau200_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  PairStau200_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau200_MuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau200_MuonEff_RecoPFMET_passPres.png");

  /* // 13.11) MET or Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* PairStau200_METOrMuonEff_RecoPFMET_noPres = new TH2F("PairStau200_METOrMuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau200_METOrMuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau200_METOrMuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* PairStau200_METOrMuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*PairStau200_RecoPFMET_noPres_passMETOrMuon_,*PairStau200_RecoPFMET_noPres_);
  PairStau200_METOrMuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  PairStau200_METOrMuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau200_METOrMuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau200_METOrMuonEff_RecoPFMET_noPres.png"); */

  // 13.12) MET or Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* PairStau200_METOrMuonEff_RecoPFMET_passPres = new TH2F("PairStau200_METOrMuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau200_METOrMuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau200_METOrMuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* PairStau200_METOrMuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*PairStau200_RecoPFMET_passPres_passMETOrMuon_,*PairStau200_RecoPFMET_passPres_);
  PairStau200_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  PairStau200_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau200_METOrMuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau200_METOrMuonEff_RecoPFMET_passPres.png");

  /* // 13.13) MET trigger efficiency vs HLT Calo MET, no preselection
  TH2F* PairStau200_METEff_HLTCaloMET_noPres = new TH2F("PairStau200_METEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  PairStau200_METEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau200_METEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* PairStau200_METEff_HLTCaloMET_noPres_TEff = new TEfficiency(*PairStau200_HLTCaloMET_noPres_passMET_,*PairStau200_HLTCaloMET_noPres_);
  PairStau200_METEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  PairStau200_METEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau200_METEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau200_METEff_HLTCaloMET_noPres.png"); */

  // 13.14) MET trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* PairStau200_METEff_HLTCaloMET_passPres = new TH2F("PairStau200_METEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  PairStau200_METEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau200_METEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* PairStau200_METEff_HLTCaloMET_passPres_TEff = new TEfficiency(*PairStau200_HLTCaloMET_passPres_passMET_,*PairStau200_HLTCaloMET_passPres_);
  PairStau200_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  PairStau200_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau200_METEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau200_METEff_HLTCaloMET_passPres.png");

  /* // 13.15) Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* PairStau200_MuonEff_HLTCaloMET_noPres = new TH2F("PairStau200_MuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau200_MuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau200_MuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* PairStau200_MuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*PairStau200_HLTCaloMET_noPres_passMuon_,*PairStau200_HLTCaloMET_noPres_);
  PairStau200_MuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  PairStau200_MuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau200_MuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau200_MuonEff_HLTCaloMET_noPres.png"); */

  // 13.16) Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* PairStau200_MuonEff_HLTCaloMET_passPres = new TH2F("PairStau200_MuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau200_MuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau200_MuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* PairStau200_MuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*PairStau200_HLTCaloMET_passPres_passMuon_,*PairStau200_HLTCaloMET_passPres_);
  PairStau200_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  PairStau200_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau200_MuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau200_MuonEff_HLTCaloMET_passPres.png");

  /* // 13.17) MET or Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* PairStau200_METOrMuonEff_HLTCaloMET_noPres = new TH2F("PairStau200_METOrMuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau200_METOrMuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau200_METOrMuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* PairStau200_METOrMuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*PairStau200_HLTCaloMET_noPres_passMETOrMuon_,*PairStau200_HLTCaloMET_noPres_);
  PairStau200_METOrMuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  PairStau200_METOrMuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau200_METOrMuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau200_METOrMuonEff_HLTCaloMET_noPres.png"); */

  // 13.18) MET or Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* PairStau200_METOrMuonEff_HLTCaloMET_passPres = new TH2F("PairStau200_METOrMuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau200_METOrMuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau200_METOrMuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* PairStau200_METOrMuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*PairStau200_HLTCaloMET_passPres_passMETOrMuon_,*PairStau200_HLTCaloMET_passPres_);
  PairStau200_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  PairStau200_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau200_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau200_METOrMuonEff_HLTCaloMET_passPres.png");

  /* // 13.19) MET trigger efficiency vs HLT PF MET, no preselection
  TH2F* PairStau200_METEff_HLTPFMET_noPres = new TH2F("PairStau200_METEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  PairStau200_METEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau200_METEff_HLTPFMET_noPres->Draw();  
  TEfficiency* PairStau200_METEff_HLTPFMET_noPres_TEff = new TEfficiency(*PairStau200_HLTPFMET_noPres_passMET_,*PairStau200_HLTPFMET_noPres_);
  PairStau200_METEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  PairStau200_METEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau200_METEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau200_METEff_HLTPFMET_noPres.png"); */

  // 13.20) MET trigger efficiency vs HLT PF MET, pass preselection
  TH2F* PairStau200_METEff_HLTPFMET_passPres = new TH2F("PairStau200_METEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  PairStau200_METEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau200_METEff_HLTPFMET_passPres->Draw();  
  TEfficiency* PairStau200_METEff_HLTPFMET_passPres_TEff = new TEfficiency(*PairStau200_HLTPFMET_passPres_passMET_,*PairStau200_HLTPFMET_passPres_);
  PairStau200_METEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  PairStau200_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau200_METEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau200_METEff_HLTPFMET_passPres.png");

  /* // 13.21) Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* PairStau200_MuonEff_HLTPFMET_noPres = new TH2F("PairStau200_MuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau200_MuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau200_MuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* PairStau200_MuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*PairStau200_HLTPFMET_noPres_passMuon_,*PairStau200_HLTPFMET_noPres_);
  PairStau200_MuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  PairStau200_MuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau200_MuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau200_MuonEff_HLTPFMET_noPres.png"); */

  // 13.22) Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* PairStau200_MuonEff_HLTPFMET_passPres = new TH2F("PairStau200_MuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau200_MuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau200_MuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* PairStau200_MuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*PairStau200_HLTPFMET_passPres_passMuon_,*PairStau200_HLTPFMET_passPres_);
  PairStau200_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  PairStau200_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau200_MuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau200_MuonEff_HLTPFMET_passPres.png");

  /* // 13.23) MET or Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* PairStau200_METOrMuonEff_HLTPFMET_noPres = new TH2F("PairStau200_METOrMuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau200_METOrMuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau200_METOrMuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* PairStau200_METOrMuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*PairStau200_HLTPFMET_noPres_passMETOrMuon_,*PairStau200_HLTPFMET_noPres_);
  PairStau200_METOrMuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  PairStau200_METOrMuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau200_METOrMuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau200_METOrMuonEff_HLTPFMET_noPres.png"); */

  // 13.24) MET or Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* PairStau200_METOrMuonEff_HLTPFMET_passPres = new TH2F("PairStau200_METOrMuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau200_METOrMuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau200_METOrMuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* PairStau200_METOrMuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*PairStau200_HLTPFMET_passPres_passMETOrMuon_,*PairStau200_HLTPFMET_passPres_);
  PairStau200_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  PairStau200_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau200_METOrMuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau200_METOrMuonEff_HLTPFMET_passPres.png");

  //=====================
  //  PairStau 432 GeV  
  //=====================

  /* // 14.1) MET trigger efficiency vs RECO Calo MET, no preselection
  TH2F* PairStau432_METEff_RecoCaloMET_noPres = new TH2F("PairStau432_METEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  PairStau432_METEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau432_METEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* PairStau432_METEff_RecoCaloMET_noPres_TEff = new TEfficiency(*PairStau432_RecoCaloMET_noPres_passMET_,*PairStau432_RecoCaloMET_noPres_);
  PairStau432_METEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  PairStau432_METEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau432_METEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau432_METEff_RecoCaloMET_noPres.png"); */

  // 14.2) MET trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* PairStau432_METEff_RecoCaloMET_passPres = new TH2F("PairStau432_METEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  PairStau432_METEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau432_METEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* PairStau432_METEff_RecoCaloMET_passPres_TEff = new TEfficiency(*PairStau432_RecoCaloMET_passPres_passMET_,*PairStau432_RecoCaloMET_passPres_);
  PairStau432_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  PairStau432_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau432_METEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau432_METEff_RecoCaloMET_passPres.png");

  /* // 14.3) Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* PairStau432_MuonEff_RecoCaloMET_noPres = new TH2F("PairStau432_MuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau432_MuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau432_MuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* PairStau432_MuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*PairStau432_RecoCaloMET_noPres_passMuon_,*PairStau432_RecoCaloMET_noPres_);
  PairStau432_MuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  PairStau432_MuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau432_MuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau432_MuonEff_RecoCaloMET_noPres.png"); */

  // 14.4) Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* PairStau432_MuonEff_RecoCaloMET_passPres = new TH2F("PairStau432_MuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau432_MuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau432_MuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* PairStau432_MuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*PairStau432_RecoCaloMET_passPres_passMuon_,*PairStau432_RecoCaloMET_passPres_);
  PairStau432_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  PairStau432_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau432_MuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau432_MuonEff_RecoCaloMET_passPres.png");

  /* // 14.5) MET or Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* PairStau432_METOrMuonEff_RecoCaloMET_noPres = new TH2F("PairStau432_METOrMuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau432_METOrMuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau432_METOrMuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* PairStau432_METOrMuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*PairStau432_RecoCaloMET_noPres_passMETOrMuon_,*PairStau432_RecoCaloMET_noPres_);
  PairStau432_METOrMuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  PairStau432_METOrMuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau432_METOrMuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau432_METOrMuonEff_RecoCaloMET_noPres.png"); */

  // 14.6) MET or Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* PairStau432_METOrMuonEff_RecoCaloMET_passPres = new TH2F("PairStau432_METOrMuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau432_METOrMuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau432_METOrMuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* PairStau432_METOrMuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*PairStau432_RecoCaloMET_passPres_passMETOrMuon_,*PairStau432_RecoCaloMET_passPres_);
  PairStau432_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  PairStau432_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau432_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau432_METOrMuonEff_RecoCaloMET_passPres.png");

  /* // 14.7) MET trigger efficiency vs RECO PF MET, no preselection
  TH2F* PairStau432_METEff_RecoPFMET_noPres = new TH2F("PairStau432_METEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  PairStau432_METEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau432_METEff_RecoPFMET_noPres->Draw();  
  TEfficiency* PairStau432_METEff_RecoPFMET_noPres_TEff = new TEfficiency(*PairStau432_RecoPFMET_noPres_passMET_,*PairStau432_RecoPFMET_noPres_);
  PairStau432_METEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  PairStau432_METEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau432_METEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau432_METEff_RecoPFMET_noPres.png"); */

  // 14.8) MET trigger efficiency vs RECO PF MET, pass preselection
  TH2F* PairStau432_METEff_RecoPFMET_passPres = new TH2F("PairStau432_METEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  PairStau432_METEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau432_METEff_RecoPFMET_passPres->Draw();  
  TEfficiency* PairStau432_METEff_RecoPFMET_passPres_TEff = new TEfficiency(*PairStau432_RecoPFMET_passPres_passMET_,*PairStau432_RecoPFMET_passPres_);
  PairStau432_METEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  PairStau432_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau432_METEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau432_METEff_RecoPFMET_passPres.png");

  /* // 14.9) Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* PairStau432_MuonEff_RecoPFMET_noPres = new TH2F("PairStau432_MuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau432_MuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau432_MuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* PairStau432_MuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*PairStau432_RecoPFMET_noPres_passMuon_,*PairStau432_RecoPFMET_noPres_);
  PairStau432_MuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  PairStau432_MuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau432_MuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau432_MuonEff_RecoPFMET_noPres.png"); */

  // 14.10) Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* PairStau432_MuonEff_RecoPFMET_passPres = new TH2F("PairStau432_MuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau432_MuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau432_MuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* PairStau432_MuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*PairStau432_RecoPFMET_passPres_passMuon_,*PairStau432_RecoPFMET_passPres_);
  PairStau432_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  PairStau432_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau432_MuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau432_MuonEff_RecoPFMET_passPres.png");

  /* // 14.11) MET or Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* PairStau432_METOrMuonEff_RecoPFMET_noPres = new TH2F("PairStau432_METOrMuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau432_METOrMuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau432_METOrMuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* PairStau432_METOrMuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*PairStau432_RecoPFMET_noPres_passMETOrMuon_,*PairStau432_RecoPFMET_noPres_);
  PairStau432_METOrMuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  PairStau432_METOrMuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau432_METOrMuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau432_METOrMuonEff_RecoPFMET_noPres.png"); */

  // 14.12) MET or Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* PairStau432_METOrMuonEff_RecoPFMET_passPres = new TH2F("PairStau432_METOrMuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau432_METOrMuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau432_METOrMuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* PairStau432_METOrMuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*PairStau432_RecoPFMET_passPres_passMETOrMuon_,*PairStau432_RecoPFMET_passPres_);
  PairStau432_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  PairStau432_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau432_METOrMuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau432_METOrMuonEff_RecoPFMET_passPres.png");

  /* // 14.13) MET trigger efficiency vs HLT Calo MET, no preselection
  TH2F* PairStau432_METEff_HLTCaloMET_noPres = new TH2F("PairStau432_METEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  PairStau432_METEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau432_METEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* PairStau432_METEff_HLTCaloMET_noPres_TEff = new TEfficiency(*PairStau432_HLTCaloMET_noPres_passMET_,*PairStau432_HLTCaloMET_noPres_);
  PairStau432_METEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  PairStau432_METEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau432_METEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau432_METEff_HLTCaloMET_noPres.png"); */

  // 14.14) MET trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* PairStau432_METEff_HLTCaloMET_passPres = new TH2F("PairStau432_METEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  PairStau432_METEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau432_METEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* PairStau432_METEff_HLTCaloMET_passPres_TEff = new TEfficiency(*PairStau432_HLTCaloMET_passPres_passMET_,*PairStau432_HLTCaloMET_passPres_);
  PairStau432_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  PairStau432_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau432_METEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau432_METEff_HLTCaloMET_passPres.png");

  /* // 14.15) Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* PairStau432_MuonEff_HLTCaloMET_noPres = new TH2F("PairStau432_MuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau432_MuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau432_MuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* PairStau432_MuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*PairStau432_HLTCaloMET_noPres_passMuon_,*PairStau432_HLTCaloMET_noPres_);
  PairStau432_MuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  PairStau432_MuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau432_MuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau432_MuonEff_HLTCaloMET_noPres.png"); */

  // 14.16) Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* PairStau432_MuonEff_HLTCaloMET_passPres = new TH2F("PairStau432_MuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau432_MuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau432_MuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* PairStau432_MuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*PairStau432_HLTCaloMET_passPres_passMuon_,*PairStau432_HLTCaloMET_passPres_);
  PairStau432_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  PairStau432_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau432_MuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau432_MuonEff_HLTCaloMET_passPres.png");

  /* // 14.17) MET or Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* PairStau432_METOrMuonEff_HLTCaloMET_noPres = new TH2F("PairStau432_METOrMuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau432_METOrMuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau432_METOrMuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* PairStau432_METOrMuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*PairStau432_HLTCaloMET_noPres_passMETOrMuon_,*PairStau432_HLTCaloMET_noPres_);
  PairStau432_METOrMuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  PairStau432_METOrMuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau432_METOrMuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau432_METOrMuonEff_HLTCaloMET_noPres.png"); */

  // 14.18) MET or Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* PairStau432_METOrMuonEff_HLTCaloMET_passPres = new TH2F("PairStau432_METOrMuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau432_METOrMuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau432_METOrMuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* PairStau432_METOrMuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*PairStau432_HLTCaloMET_passPres_passMETOrMuon_,*PairStau432_HLTCaloMET_passPres_);
  PairStau432_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  PairStau432_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau432_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau432_METOrMuonEff_HLTCaloMET_passPres.png");

  /* // 14.19) MET trigger efficiency vs HLT PF MET, no preselection
  TH2F* PairStau432_METEff_HLTPFMET_noPres = new TH2F("PairStau432_METEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  PairStau432_METEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau432_METEff_HLTPFMET_noPres->Draw();  
  TEfficiency* PairStau432_METEff_HLTPFMET_noPres_TEff = new TEfficiency(*PairStau432_HLTPFMET_noPres_passMET_,*PairStau432_HLTPFMET_noPres_);
  PairStau432_METEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  PairStau432_METEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau432_METEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau432_METEff_HLTPFMET_noPres.png"); */

  // 14.20) MET trigger efficiency vs HLT PF MET, pass preselection
  TH2F* PairStau432_METEff_HLTPFMET_passPres = new TH2F("PairStau432_METEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  PairStau432_METEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau432_METEff_HLTPFMET_passPres->Draw();  
  TEfficiency* PairStau432_METEff_HLTPFMET_passPres_TEff = new TEfficiency(*PairStau432_HLTPFMET_passPres_passMET_,*PairStau432_HLTPFMET_passPres_);
  PairStau432_METEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  PairStau432_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau432_METEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau432_METEff_HLTPFMET_passPres.png");

  /* // 14.21) Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* PairStau432_MuonEff_HLTPFMET_noPres = new TH2F("PairStau432_MuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau432_MuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau432_MuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* PairStau432_MuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*PairStau432_HLTPFMET_noPres_passMuon_,*PairStau432_HLTPFMET_noPres_);
  PairStau432_MuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  PairStau432_MuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau432_MuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau432_MuonEff_HLTPFMET_noPres.png"); */

  // 14.22) Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* PairStau432_MuonEff_HLTPFMET_passPres = new TH2F("PairStau432_MuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau432_MuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau432_MuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* PairStau432_MuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*PairStau432_HLTPFMET_passPres_passMuon_,*PairStau432_HLTPFMET_passPres_);
  PairStau432_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  PairStau432_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau432_MuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau432_MuonEff_HLTPFMET_passPres.png");

  /* // 14.23) MET or Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* PairStau432_METOrMuonEff_HLTPFMET_noPres = new TH2F("PairStau432_METOrMuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau432_METOrMuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau432_METOrMuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* PairStau432_METOrMuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*PairStau432_HLTPFMET_noPres_passMETOrMuon_,*PairStau432_HLTPFMET_noPres_);
  PairStau432_METOrMuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  PairStau432_METOrMuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau432_METOrMuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau432_METOrMuonEff_HLTPFMET_noPres.png"); */

  // 14.24) MET or Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* PairStau432_METOrMuonEff_HLTPFMET_passPres = new TH2F("PairStau432_METOrMuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau432_METOrMuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau432_METOrMuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* PairStau432_METOrMuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*PairStau432_HLTPFMET_passPres_passMETOrMuon_,*PairStau432_HLTPFMET_passPres_);
  PairStau432_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  PairStau432_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau432_METOrMuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau432_METOrMuonEff_HLTPFMET_passPres.png");

  //=====================
  //  PairStau 651 GeV  
  //=====================

  /* // 15.1) MET trigger efficiency vs RECO Calo MET, no preselection
  TH2F* PairStau651_METEff_RecoCaloMET_noPres = new TH2F("PairStau651_METEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  PairStau651_METEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau651_METEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* PairStau651_METEff_RecoCaloMET_noPres_TEff = new TEfficiency(*PairStau651_RecoCaloMET_noPres_passMET_,*PairStau651_RecoCaloMET_noPres_);
  PairStau651_METEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  PairStau651_METEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau651_METEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau651_METEff_RecoCaloMET_noPres.png"); */

  // 15.2) MET trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* PairStau651_METEff_RecoCaloMET_passPres = new TH2F("PairStau651_METEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  PairStau651_METEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau651_METEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* PairStau651_METEff_RecoCaloMET_passPres_TEff = new TEfficiency(*PairStau651_RecoCaloMET_passPres_passMET_,*PairStau651_RecoCaloMET_passPres_);
  PairStau651_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  PairStau651_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau651_METEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau651_METEff_RecoCaloMET_passPres.png");

  /* // 15.3) Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* PairStau651_MuonEff_RecoCaloMET_noPres = new TH2F("PairStau651_MuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau651_MuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau651_MuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* PairStau651_MuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*PairStau651_RecoCaloMET_noPres_passMuon_,*PairStau651_RecoCaloMET_noPres_);
  PairStau651_MuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  PairStau651_MuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau651_MuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau651_MuonEff_RecoCaloMET_noPres.png"); */

  // 15.4) Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* PairStau651_MuonEff_RecoCaloMET_passPres = new TH2F("PairStau651_MuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau651_MuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau651_MuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* PairStau651_MuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*PairStau651_RecoCaloMET_passPres_passMuon_,*PairStau651_RecoCaloMET_passPres_);
  PairStau651_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  PairStau651_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau651_MuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau651_MuonEff_RecoCaloMET_passPres.png");

  /* // 15.5) MET or Muon trigger efficiency vs RECO Calo MET, no preselection
  TH2F* PairStau651_METOrMuonEff_RecoCaloMET_noPres = new TH2F("PairStau651_METOrMuonEff_RecoCaloMET_noPres","no preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau651_METOrMuonEff_RecoCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau651_METOrMuonEff_RecoCaloMET_noPres->Draw();  
  TEfficiency* PairStau651_METOrMuonEff_RecoCaloMET_noPres_TEff = new TEfficiency(*PairStau651_RecoCaloMET_noPres_passMETOrMuon_,*PairStau651_RecoCaloMET_noPres_);
  PairStau651_METOrMuonEff_RecoCaloMET_noPres_TEff->SetLineColor(kRed);
  PairStau651_METOrMuonEff_RecoCaloMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau651_METOrMuonEff_RecoCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau651_METOrMuonEff_RecoCaloMET_noPres.png"); */

  // 15.6) MET or Muon trigger efficiency vs RECO Calo MET, pass preselection
  TH2F* PairStau651_METOrMuonEff_RecoCaloMET_passPres = new TH2F("PairStau651_METOrMuonEff_RecoCaloMET_passPres","pass preselection;RECO Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau651_METOrMuonEff_RecoCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau651_METOrMuonEff_RecoCaloMET_passPres->Draw();  
  TEfficiency* PairStau651_METOrMuonEff_RecoCaloMET_passPres_TEff = new TEfficiency(*PairStau651_RecoCaloMET_passPres_passMETOrMuon_,*PairStau651_RecoCaloMET_passPres_);
  PairStau651_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  PairStau651_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau651_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau651_METOrMuonEff_RecoCaloMET_passPres.png");

  /* // 15.7) MET trigger efficiency vs RECO PF MET, no preselection
  TH2F* PairStau651_METEff_RecoPFMET_noPres = new TH2F("PairStau651_METEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  PairStau651_METEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau651_METEff_RecoPFMET_noPres->Draw();  
  TEfficiency* PairStau651_METEff_RecoPFMET_noPres_TEff = new TEfficiency(*PairStau651_RecoPFMET_noPres_passMET_,*PairStau651_RecoPFMET_noPres_);
  PairStau651_METEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  PairStau651_METEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau651_METEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau651_METEff_RecoPFMET_noPres.png"); */

  // 15.8) MET trigger efficiency vs RECO PF MET, pass preselection
  TH2F* PairStau651_METEff_RecoPFMET_passPres = new TH2F("PairStau651_METEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  PairStau651_METEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau651_METEff_RecoPFMET_passPres->Draw();  
  TEfficiency* PairStau651_METEff_RecoPFMET_passPres_TEff = new TEfficiency(*PairStau651_RecoPFMET_passPres_passMET_,*PairStau651_RecoPFMET_passPres_);
  PairStau651_METEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  PairStau651_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau651_METEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau651_METEff_RecoPFMET_passPres.png");

  /* // 15.9) Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* PairStau651_MuonEff_RecoPFMET_noPres = new TH2F("PairStau651_MuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau651_MuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau651_MuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* PairStau651_MuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*PairStau651_RecoPFMET_noPres_passMuon_,*PairStau651_RecoPFMET_noPres_);
  PairStau651_MuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  PairStau651_MuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau651_MuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau651_MuonEff_RecoPFMET_noPres.png"); */

  // 15.10) Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* PairStau651_MuonEff_RecoPFMET_passPres = new TH2F("PairStau651_MuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau651_MuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau651_MuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* PairStau651_MuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*PairStau651_RecoPFMET_passPres_passMuon_,*PairStau651_RecoPFMET_passPres_);
  PairStau651_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  PairStau651_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau651_MuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau651_MuonEff_RecoPFMET_passPres.png");

  /* // 15.11) MET or Muon trigger efficiency vs RECO PF MET, no preselection
  TH2F* PairStau651_METOrMuonEff_RecoPFMET_noPres = new TH2F("PairStau651_METOrMuonEff_RecoPFMET_noPres","no preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau651_METOrMuonEff_RecoPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau651_METOrMuonEff_RecoPFMET_noPres->Draw();  
  TEfficiency* PairStau651_METOrMuonEff_RecoPFMET_noPres_TEff = new TEfficiency(*PairStau651_RecoPFMET_noPres_passMETOrMuon_,*PairStau651_RecoPFMET_noPres_);
  PairStau651_METOrMuonEff_RecoPFMET_noPres_TEff->SetLineColor(kRed);
  PairStau651_METOrMuonEff_RecoPFMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau651_METOrMuonEff_RecoPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau651_METOrMuonEff_RecoPFMET_noPres.png"); */

  // 15.12) MET or Muon trigger efficiency vs RECO PF MET, pass preselection
  TH2F* PairStau651_METOrMuonEff_RecoPFMET_passPres = new TH2F("PairStau651_METOrMuonEff_RecoPFMET_passPres","pass preselection;RECO PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau651_METOrMuonEff_RecoPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau651_METOrMuonEff_RecoPFMET_passPres->Draw();  
  TEfficiency* PairStau651_METOrMuonEff_RecoPFMET_passPres_TEff = new TEfficiency(*PairStau651_RecoPFMET_passPres_passMETOrMuon_,*PairStau651_RecoPFMET_passPres_);
  PairStau651_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  PairStau651_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau651_METOrMuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau651_METOrMuonEff_RecoPFMET_passPres.png");

  /* // 15.13) MET trigger efficiency vs HLT Calo MET, no preselection
  TH2F* PairStau651_METEff_HLTCaloMET_noPres = new TH2F("PairStau651_METEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  PairStau651_METEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau651_METEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* PairStau651_METEff_HLTCaloMET_noPres_TEff = new TEfficiency(*PairStau651_HLTCaloMET_noPres_passMET_,*PairStau651_HLTCaloMET_noPres_);
  PairStau651_METEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  PairStau651_METEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau651_METEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau651_METEff_HLTCaloMET_noPres.png"); */

  // 15.14) MET trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* PairStau651_METEff_HLTCaloMET_passPres = new TH2F("PairStau651_METEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  PairStau651_METEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau651_METEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* PairStau651_METEff_HLTCaloMET_passPres_TEff = new TEfficiency(*PairStau651_HLTCaloMET_passPres_passMET_,*PairStau651_HLTCaloMET_passPres_);
  PairStau651_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  PairStau651_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau651_METEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau651_METEff_HLTCaloMET_passPres.png");

  /* // 15.15) Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* PairStau651_MuonEff_HLTCaloMET_noPres = new TH2F("PairStau651_MuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau651_MuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau651_MuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* PairStau651_MuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*PairStau651_HLTCaloMET_noPres_passMuon_,*PairStau651_HLTCaloMET_noPres_);
  PairStau651_MuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  PairStau651_MuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau651_MuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau651_MuonEff_HLTCaloMET_noPres.png"); */

  // 15.16) Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* PairStau651_MuonEff_HLTCaloMET_passPres = new TH2F("PairStau651_MuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau651_MuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau651_MuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* PairStau651_MuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*PairStau651_HLTCaloMET_passPres_passMuon_,*PairStau651_HLTCaloMET_passPres_);
  PairStau651_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  PairStau651_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau651_MuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau651_MuonEff_HLTCaloMET_passPres.png");

  /* // 15.17) MET or Muon trigger efficiency vs HLT Calo MET, no preselection
  TH2F* PairStau651_METOrMuonEff_HLTCaloMET_noPres = new TH2F("PairStau651_METOrMuonEff_HLTCaloMET_noPres","no preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau651_METOrMuonEff_HLTCaloMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau651_METOrMuonEff_HLTCaloMET_noPres->Draw();  
  TEfficiency* PairStau651_METOrMuonEff_HLTCaloMET_noPres_TEff = new TEfficiency(*PairStau651_HLTCaloMET_noPres_passMETOrMuon_,*PairStau651_HLTCaloMET_noPres_);
  PairStau651_METOrMuonEff_HLTCaloMET_noPres_TEff->SetLineColor(kRed);
  PairStau651_METOrMuonEff_HLTCaloMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau651_METOrMuonEff_HLTCaloMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau651_METOrMuonEff_HLTCaloMET_noPres.png"); */

  // 15.18) MET or Muon trigger efficiency vs HLT Calo MET, pass preselection
  TH2F* PairStau651_METOrMuonEff_HLTCaloMET_passPres = new TH2F("PairStau651_METOrMuonEff_HLTCaloMET_passPres","pass preselection;HLT Calo MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau651_METOrMuonEff_HLTCaloMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau651_METOrMuonEff_HLTCaloMET_passPres->Draw();  
  TEfficiency* PairStau651_METOrMuonEff_HLTCaloMET_passPres_TEff = new TEfficiency(*PairStau651_HLTCaloMET_passPres_passMETOrMuon_,*PairStau651_HLTCaloMET_passPres_);
  PairStau651_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  PairStau651_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau651_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau651_METOrMuonEff_HLTCaloMET_passPres.png");

  /* // 15.19) MET trigger efficiency vs HLT PF MET, no preselection
  TH2F* PairStau651_METEff_HLTPFMET_noPres = new TH2F("PairStau651_METEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  PairStau651_METEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau651_METEff_HLTPFMET_noPres->Draw();  
  TEfficiency* PairStau651_METEff_HLTPFMET_noPres_TEff = new TEfficiency(*PairStau651_HLTPFMET_noPres_passMET_,*PairStau651_HLTPFMET_noPres_);
  PairStau651_METEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  PairStau651_METEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau651_METEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau651_METEff_HLTPFMET_noPres.png"); */

  // 15.20) MET trigger efficiency vs HLT PF MET, pass preselection
  TH2F* PairStau651_METEff_HLTPFMET_passPres = new TH2F("PairStau651_METEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET trigger efficiency",100,0,1500,100,0,1);
  PairStau651_METEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau651_METEff_HLTPFMET_passPres->Draw();  
  TEfficiency* PairStau651_METEff_HLTPFMET_passPres_TEff = new TEfficiency(*PairStau651_HLTPFMET_passPres_passMET_,*PairStau651_HLTPFMET_passPres_);
  PairStau651_METEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  PairStau651_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau651_METEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau651_METEff_HLTPFMET_passPres.png");

  /* // 15.21) Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* PairStau651_MuonEff_HLTPFMET_noPres = new TH2F("PairStau651_MuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau651_MuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau651_MuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* PairStau651_MuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*PairStau651_HLTPFMET_noPres_passMuon_,*PairStau651_HLTPFMET_noPres_);
  PairStau651_MuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  PairStau651_MuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau651_MuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau651_MuonEff_HLTPFMET_noPres.png"); */

  // 15.22) Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* PairStau651_MuonEff_HLTPFMET_passPres = new TH2F("PairStau651_MuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau651_MuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau651_MuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* PairStau651_MuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*PairStau651_HLTPFMET_passPres_passMuon_,*PairStau651_HLTPFMET_passPres_);
  PairStau651_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  PairStau651_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau651_MuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau651_MuonEff_HLTPFMET_passPres.png");

  /* // 15.23) MET or Muon trigger efficiency vs HLT PF MET, no preselection
  TH2F* PairStau651_METOrMuonEff_HLTPFMET_noPres = new TH2F("PairStau651_METOrMuonEff_HLTPFMET_noPres","no preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau651_METOrMuonEff_HLTPFMET_noPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau651_METOrMuonEff_HLTPFMET_noPres->Draw();  
  TEfficiency* PairStau651_METOrMuonEff_HLTPFMET_noPres_TEff = new TEfficiency(*PairStau651_HLTPFMET_noPres_passMETOrMuon_,*PairStau651_HLTPFMET_noPres_);
  PairStau651_METOrMuonEff_HLTPFMET_noPres_TEff->SetLineColor(kRed);
  PairStau651_METOrMuonEff_HLTPFMET_noPres_TEff->SetMarkerColor(kRed);
  PairStau651_METOrMuonEff_HLTPFMET_noPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau651_METOrMuonEff_HLTPFMET_noPres.png"); */

  // 15.24) MET or Muon trigger efficiency vs HLT PF MET, pass preselection
  TH2F* PairStau651_METOrMuonEff_HLTPFMET_passPres = new TH2F("PairStau651_METOrMuonEff_HLTPFMET_passPres","pass preselection;HLT PF MET [GeV];MET or Muon trigger efficiency",100,0,1500,100,0,1);
  PairStau651_METOrMuonEff_HLTPFMET_passPres->GetYaxis()->SetTitleOffset(0.98);
  PairStau651_METOrMuonEff_HLTPFMET_passPres->Draw();  
  TEfficiency* PairStau651_METOrMuonEff_HLTPFMET_passPres_TEff = new TEfficiency(*PairStau651_HLTPFMET_passPres_passMETOrMuon_,*PairStau651_HLTPFMET_passPres_);
  PairStau651_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  PairStau651_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau651_METOrMuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  c_met->SaveAs("./png/PairStau651_METOrMuonEff_HLTPFMET_passPres.png");


  //==================
  //  SUMMARY PLOTS
  //==================

  // 1234.02) MET trigger efficiency vs RECO Calo MET, pass preselection
  Gluino800_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino800_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1400_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kOrange);
  Gluino1400_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kOrange);
  Gluino1800_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kAzure);
  Gluino1800_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kAzure);
  Gluino2400_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kBlack);
  Gluino2400_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kBlack);
  Gluino800_METEff_RecoCaloMET_passPres_TEff->Draw();
  Gluino1400_METEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  Gluino1800_METEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  Gluino2400_METEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  /*TEMP
  auto Gluino_METEff_RecoCaloMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  Gluino_METEff_RecoCaloMET_legend->AddEntry(Gluino800_METEff_RecoCaloMET_passPres_TEff,"Gluino 800 GeV");
  Gluino_METEff_RecoCaloMET_legend->AddEntry(Gluino1400_METEff_RecoCaloMET_passPres_TEff,"Gluino 1400 GeV");
  Gluino_METEff_RecoCaloMET_legend->AddEntry(Gluino1800_METEff_RecoCaloMET_passPres_TEff,"Gluino 1800 GeV");
  Gluino_METEff_RecoCaloMET_legend->AddEntry(Gluino2400_METEff_RecoCaloMET_passPres_TEff,"Gluino 2400 GeV");
  Gluino_METEff_RecoCaloMET_legend->Draw();
  *///TEMP
  c_met->SaveAs("./png/Gluino_METEff_RecoCaloMET_passPres.png");

  // 1234.04) Muon trigger efficiency vs RECO Calo MET, pass preselection
  Gluino800_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino800_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1400_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kOrange);
  Gluino1400_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kOrange);
  Gluino1800_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kAzure);
  Gluino1800_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kAzure);
  Gluino2400_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kBlack);
  Gluino2400_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kBlack);
  Gluino800_MuonEff_RecoCaloMET_passPres_TEff->Draw();
  Gluino1400_MuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  Gluino1800_MuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  Gluino2400_MuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  auto Gluino_MuonEff_RecoCaloMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  Gluino_MuonEff_RecoCaloMET_legend->AddEntry(Gluino800_MuonEff_RecoCaloMET_passPres_TEff,"Gluino 800 GeV");
  Gluino_MuonEff_RecoCaloMET_legend->AddEntry(Gluino1400_MuonEff_RecoCaloMET_passPres_TEff,"Gluino 1400 GeV");
  Gluino_MuonEff_RecoCaloMET_legend->AddEntry(Gluino1800_MuonEff_RecoCaloMET_passPres_TEff,"Gluino 1800 GeV");
  Gluino_MuonEff_RecoCaloMET_legend->AddEntry(Gluino2400_MuonEff_RecoCaloMET_passPres_TEff,"Gluino 2400 GeV");
  Gluino_MuonEff_RecoCaloMET_legend->Draw();
  c_met->SaveAs("./png/Gluino_MuonEff_RecoCaloMET_passPres.png");

  // 1234.06) MET or Muon trigger efficiency vs RECO Calo MET, pass preselection
  Gluino800_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino800_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1400_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kOrange);
  Gluino1400_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kOrange);
  Gluino1800_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kAzure);
  Gluino1800_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kAzure);
  Gluino2400_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kBlack);
  Gluino2400_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kBlack);
  Gluino800_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw();
  Gluino1400_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  Gluino1800_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  Gluino2400_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  auto Gluino_METOrMuonEff_RecoCaloMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  Gluino_METOrMuonEff_RecoCaloMET_legend->AddEntry(Gluino800_METOrMuonEff_RecoCaloMET_passPres_TEff,"Gluino 800 GeV");
  Gluino_METOrMuonEff_RecoCaloMET_legend->AddEntry(Gluino1400_METOrMuonEff_RecoCaloMET_passPres_TEff,"Gluino 1400 GeV");
  Gluino_METOrMuonEff_RecoCaloMET_legend->AddEntry(Gluino1800_METOrMuonEff_RecoCaloMET_passPres_TEff,"Gluino 1800 GeV");
  Gluino_METOrMuonEff_RecoCaloMET_legend->AddEntry(Gluino2400_METOrMuonEff_RecoCaloMET_passPres_TEff,"Gluino 2400 GeV");
  Gluino_METOrMuonEff_RecoCaloMET_legend->Draw();
  c_met->SaveAs("./png/Gluino_METOrMuonEff_RecoCaloMET_passPres.png");

  // 1234.08) MET trigger efficiency vs RECO PF MET, pass preselection
  Gluino800_METEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino800_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1400_METEff_RecoPFMET_passPres_TEff->SetLineColor(kOrange);
  Gluino1400_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kOrange);
  Gluino1800_METEff_RecoPFMET_passPres_TEff->SetLineColor(kAzure);
  Gluino1800_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kAzure);
  Gluino2400_METEff_RecoPFMET_passPres_TEff->SetLineColor(kBlack);
  Gluino2400_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kBlack);
  Gluino800_METEff_RecoPFMET_passPres_TEff->Draw();
  Gluino1400_METEff_RecoPFMET_passPres_TEff->Draw("pe same");
  Gluino1800_METEff_RecoPFMET_passPres_TEff->Draw("pe same");
  Gluino2400_METEff_RecoPFMET_passPres_TEff->Draw("pe same");
  /*TEMP
  auto Gluino_METEff_RecoPFMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  Gluino_METEff_RecoPFMET_legend->AddEntry(Gluino800_METEff_RecoPFMET_passPres_TEff,"Gluino 800 GeV");
  Gluino_METEff_RecoPFMET_legend->AddEntry(Gluino1400_METEff_RecoPFMET_passPres_TEff,"Gluino 1400 GeV");
  Gluino_METEff_RecoPFMET_legend->AddEntry(Gluino1800_METEff_RecoPFMET_passPres_TEff,"Gluino 1800 GeV");
  Gluino_METEff_RecoPFMET_legend->AddEntry(Gluino2400_METEff_RecoPFMET_passPres_TEff,"Gluino 2400 GeV");
  Gluino_METEff_RecoPFMET_legend->Draw();
  *///TEMP
  c_met->SaveAs("./png/Gluino_METEff_RecoPFMET_passPres.png");

  // 1234.10) Muon trigger efficiency vs RECO PF MET, pass preselection
  Gluino800_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino800_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1400_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kOrange);
  Gluino1400_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kOrange);
  Gluino1800_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kAzure);
  Gluino1800_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kAzure);
  Gluino2400_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kBlack);
  Gluino2400_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kBlack);
  Gluino800_MuonEff_RecoPFMET_passPres_TEff->Draw();
  Gluino1400_MuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  Gluino1800_MuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  Gluino2400_MuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  auto Gluino_MuonEff_RecoPFMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  Gluino_MuonEff_RecoPFMET_legend->AddEntry(Gluino800_MuonEff_RecoPFMET_passPres_TEff,"Gluino 800 GeV");
  Gluino_MuonEff_RecoPFMET_legend->AddEntry(Gluino1400_MuonEff_RecoPFMET_passPres_TEff,"Gluino 1400 GeV");
  Gluino_MuonEff_RecoPFMET_legend->AddEntry(Gluino1800_MuonEff_RecoPFMET_passPres_TEff,"Gluino 1800 GeV");
  Gluino_MuonEff_RecoPFMET_legend->AddEntry(Gluino2400_MuonEff_RecoPFMET_passPres_TEff,"Gluino 2400 GeV");
  Gluino_MuonEff_RecoPFMET_legend->Draw();
  c_met->SaveAs("./png/Gluino_MuonEff_RecoPFMET_passPres.png");

  // 1234.12) MET or Muon trigger efficiency vs RECO PF MET, pass preselection
  Gluino800_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino800_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1400_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kOrange);
  Gluino1400_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kOrange);
  Gluino1800_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kAzure);
  Gluino1800_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kAzure);
  Gluino2400_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kBlack);
  Gluino2400_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kBlack);
  Gluino800_METOrMuonEff_RecoPFMET_passPres_TEff->Draw();
  Gluino1400_METOrMuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  Gluino1800_METOrMuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  Gluino2400_METOrMuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  auto Gluino_METOrMuonEff_RecoPFMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  Gluino_METOrMuonEff_RecoPFMET_legend->AddEntry(Gluino800_METOrMuonEff_RecoPFMET_passPres_TEff,"Gluino 800 GeV");
  Gluino_METOrMuonEff_RecoPFMET_legend->AddEntry(Gluino1400_METOrMuonEff_RecoPFMET_passPres_TEff,"Gluino 1400 GeV");
  Gluino_METOrMuonEff_RecoPFMET_legend->AddEntry(Gluino1800_METOrMuonEff_RecoPFMET_passPres_TEff,"Gluino 1800 GeV");
  Gluino_METOrMuonEff_RecoPFMET_legend->AddEntry(Gluino2400_METOrMuonEff_RecoPFMET_passPres_TEff,"Gluino 2400 GeV");
  Gluino_METOrMuonEff_RecoPFMET_legend->Draw();
  c_met->SaveAs("./png/Gluino_METOrMuonEff_RecoPFMET_passPres.png");

  // 1234.14) MET trigger efficiency vs HLT Calo MET, pass preselection
  Gluino800_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino800_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1400_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kOrange);
  Gluino1400_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kOrange);
  Gluino1800_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kAzure);
  Gluino1800_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kAzure);
  Gluino2400_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kBlack);
  Gluino2400_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kBlack);
  Gluino800_METEff_HLTCaloMET_passPres_TEff->Draw();
  Gluino1400_METEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  Gluino1800_METEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  Gluino2400_METEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  auto Gluino_METEff_HLTCaloMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  Gluino_METEff_HLTCaloMET_legend->AddEntry(Gluino800_METEff_HLTCaloMET_passPres_TEff,"Gluino 800 GeV");
  Gluino_METEff_HLTCaloMET_legend->AddEntry(Gluino1400_METEff_HLTCaloMET_passPres_TEff,"Gluino 1400 GeV");
  Gluino_METEff_HLTCaloMET_legend->AddEntry(Gluino1800_METEff_HLTCaloMET_passPres_TEff,"Gluino 1800 GeV");
  Gluino_METEff_HLTCaloMET_legend->AddEntry(Gluino2400_METEff_HLTCaloMET_passPres_TEff,"Gluino 2400 GeV");
  Gluino_METEff_HLTCaloMET_legend->Draw();
  c_met->SaveAs("./png/Gluino_METEff_HLTCaloMET_passPres.png");

  // 1234.16) Muon trigger efficiency vs HLT Calo MET, pass preselection
  Gluino800_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino800_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1400_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kOrange);
  Gluino1400_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kOrange);
  Gluino1800_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kAzure);
  Gluino1800_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kAzure);
  Gluino2400_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kBlack);
  Gluino2400_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kBlack);
  Gluino800_MuonEff_HLTCaloMET_passPres_TEff->Draw();
  Gluino1400_MuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  Gluino1800_MuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  Gluino2400_MuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  auto Gluino_MuonEff_HLTCaloMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  Gluino_MuonEff_HLTCaloMET_legend->AddEntry(Gluino800_MuonEff_HLTCaloMET_passPres_TEff,"Gluino 800 GeV");
  Gluino_MuonEff_HLTCaloMET_legend->AddEntry(Gluino1400_MuonEff_HLTCaloMET_passPres_TEff,"Gluino 1400 GeV");
  Gluino_MuonEff_HLTCaloMET_legend->AddEntry(Gluino1800_MuonEff_HLTCaloMET_passPres_TEff,"Gluino 1800 GeV");
  Gluino_MuonEff_HLTCaloMET_legend->AddEntry(Gluino2400_MuonEff_HLTCaloMET_passPres_TEff,"Gluino 2400 GeV");
  Gluino_MuonEff_HLTCaloMET_legend->Draw();
  c_met->SaveAs("./png/Gluino_MuonEff_HLTCaloMET_passPres.png");

  // 1234.18) MET or Muon trigger efficiency vs HLT Calo MET, pass preselection
  Gluino800_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  Gluino800_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1400_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kOrange);
  Gluino1400_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kOrange);
  Gluino1800_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kAzure);
  Gluino1800_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kAzure);
  Gluino2400_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kBlack);
  Gluino2400_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kBlack);
  Gluino800_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw();
  Gluino1400_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  Gluino1800_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  Gluino2400_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  auto Gluino_METOrMuonEff_HLTCaloMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  Gluino_METOrMuonEff_HLTCaloMET_legend->AddEntry(Gluino800_METOrMuonEff_HLTCaloMET_passPres_TEff,"Gluino 800 GeV");
  Gluino_METOrMuonEff_HLTCaloMET_legend->AddEntry(Gluino1400_METOrMuonEff_HLTCaloMET_passPres_TEff,"Gluino 1400 GeV");
  Gluino_METOrMuonEff_HLTCaloMET_legend->AddEntry(Gluino1800_METOrMuonEff_HLTCaloMET_passPres_TEff,"Gluino 1800 GeV");
  Gluino_METOrMuonEff_HLTCaloMET_legend->AddEntry(Gluino2400_METOrMuonEff_HLTCaloMET_passPres_TEff,"Gluino 2400 GeV");
  Gluino_METOrMuonEff_HLTCaloMET_legend->Draw();
  c_met->SaveAs("./png/Gluino_METOrMuonEff_HLTCaloMET_passPres.png");

  // 1234.20) MET trigger efficiency vs HLT PF MET, pass preselection
  Gluino800_METEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino800_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1400_METEff_HLTPFMET_passPres_TEff->SetLineColor(kOrange);
  Gluino1400_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kOrange);
  Gluino1800_METEff_HLTPFMET_passPres_TEff->SetLineColor(kAzure);
  Gluino1800_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kAzure);
  Gluino2400_METEff_HLTPFMET_passPres_TEff->SetLineColor(kBlack);
  Gluino2400_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kBlack);
  Gluino800_METEff_HLTPFMET_passPres_TEff->Draw();
  Gluino1400_METEff_HLTPFMET_passPres_TEff->Draw("pe same");
  Gluino1800_METEff_HLTPFMET_passPres_TEff->Draw("pe same");
  Gluino2400_METEff_HLTPFMET_passPres_TEff->Draw("pe same");
  auto Gluino_METEff_HLTPFMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  Gluino_METEff_HLTPFMET_legend->AddEntry(Gluino800_METEff_HLTPFMET_passPres_TEff,"Gluino 800 GeV");
  Gluino_METEff_HLTPFMET_legend->AddEntry(Gluino1400_METEff_HLTPFMET_passPres_TEff,"Gluino 1400 GeV");
  Gluino_METEff_HLTPFMET_legend->AddEntry(Gluino1800_METEff_HLTPFMET_passPres_TEff,"Gluino 1800 GeV");
  Gluino_METEff_HLTPFMET_legend->AddEntry(Gluino2400_METEff_HLTPFMET_passPres_TEff,"Gluino 2400 GeV");
  Gluino_METEff_HLTPFMET_legend->Draw();
  c_met->SaveAs("./png/Gluino_METEff_HLTPFMET_passPres.png");

  // 1234.22) Muon trigger efficiency vs HLT PF MET, pass preselection
  Gluino800_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino800_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1400_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kOrange);
  Gluino1400_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kOrange);
  Gluino1800_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kAzure);
  Gluino1800_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kAzure);
  Gluino2400_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kBlack);
  Gluino2400_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kBlack);
  Gluino800_MuonEff_HLTPFMET_passPres_TEff->Draw();
  Gluino1400_MuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  Gluino1800_MuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  Gluino2400_MuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  auto Gluino_MuonEff_HLTPFMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  Gluino_MuonEff_HLTPFMET_legend->AddEntry(Gluino800_MuonEff_HLTPFMET_passPres_TEff,"Gluino 800 GeV");
  Gluino_MuonEff_HLTPFMET_legend->AddEntry(Gluino1400_MuonEff_HLTPFMET_passPres_TEff,"Gluino 1400 GeV");
  Gluino_MuonEff_HLTPFMET_legend->AddEntry(Gluino1800_MuonEff_HLTPFMET_passPres_TEff,"Gluino 1800 GeV");
  Gluino_MuonEff_HLTPFMET_legend->AddEntry(Gluino2400_MuonEff_HLTPFMET_passPres_TEff,"Gluino 2400 GeV");
  Gluino_MuonEff_HLTPFMET_legend->Draw();
  c_met->SaveAs("./png/Gluino_MuonEff_HLTPFMET_passPres.png");

  // 1234.24) MET or Muon trigger efficiency vs HLT PF MET, pass preselection
  Gluino800_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  Gluino800_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  Gluino1400_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kOrange);
  Gluino1400_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kOrange);
  Gluino1800_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kAzure);
  Gluino1800_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kAzure);
  Gluino2400_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kBlack);
  Gluino2400_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kBlack);
  Gluino800_METOrMuonEff_HLTPFMET_passPres_TEff->Draw();
  Gluino1400_METOrMuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  Gluino1800_METOrMuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  Gluino2400_METOrMuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  auto Gluino_METOrMuonEff_HLTPFMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  Gluino_METOrMuonEff_HLTPFMET_legend->AddEntry(Gluino800_METOrMuonEff_HLTPFMET_passPres_TEff,"Gluino 800 GeV");
  Gluino_METOrMuonEff_HLTPFMET_legend->AddEntry(Gluino1400_METOrMuonEff_HLTPFMET_passPres_TEff,"Gluino 1400 GeV");
  Gluino_METOrMuonEff_HLTPFMET_legend->AddEntry(Gluino1800_METOrMuonEff_HLTPFMET_passPres_TEff,"Gluino 1800 GeV");
  Gluino_METOrMuonEff_HLTPFMET_legend->AddEntry(Gluino2400_METOrMuonEff_HLTPFMET_passPres_TEff,"Gluino 2400 GeV");
  Gluino_METOrMuonEff_HLTPFMET_legend->Draw();
  c_met->SaveAs("./png/Gluino_METOrMuonEff_HLTPFMET_passPres.png");

  // 5678.02) MET trigger efficiency vs RECO Calo MET, pass preselection
  GluinoN800_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN800_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kOrange);
  GluinoN1400_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kOrange);
  GluinoN1800_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kAzure);
  GluinoN1800_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kAzure);
  GluinoN2400_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kBlack);
  GluinoN2400_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kBlack);
  GluinoN800_METEff_RecoCaloMET_passPres_TEff->Draw();
  GluinoN1400_METEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  GluinoN1800_METEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  GluinoN2400_METEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  auto GluinoN_METEff_RecoCaloMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  GluinoN_METEff_RecoCaloMET_legend->AddEntry(GluinoN800_METEff_RecoCaloMET_passPres_TEff,"GluinoN 800 GeV");
  GluinoN_METEff_RecoCaloMET_legend->AddEntry(GluinoN1400_METEff_RecoCaloMET_passPres_TEff,"GluinoN 1400 GeV");
  GluinoN_METEff_RecoCaloMET_legend->AddEntry(GluinoN1800_METEff_RecoCaloMET_passPres_TEff,"GluinoN 1800 GeV");
  GluinoN_METEff_RecoCaloMET_legend->AddEntry(GluinoN2400_METEff_RecoCaloMET_passPres_TEff,"GluinoN 2400 GeV");
  GluinoN_METEff_RecoCaloMET_legend->Draw();
  c_met->SaveAs("./png/GluinoN_METEff_RecoCaloMET_passPres.png");

  // 5678.04) Muon trigger efficiency vs RECO Calo MET, pass preselection
  GluinoN800_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN800_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kOrange);
  GluinoN1400_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kOrange);
  GluinoN1800_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kAzure);
  GluinoN1800_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kAzure);
  GluinoN2400_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kBlack);
  GluinoN2400_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kBlack);
  GluinoN800_MuonEff_RecoCaloMET_passPres_TEff->Draw();
  GluinoN1400_MuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  GluinoN1800_MuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  GluinoN2400_MuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  auto GluinoN_MuonEff_RecoCaloMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  GluinoN_MuonEff_RecoCaloMET_legend->AddEntry(GluinoN800_MuonEff_RecoCaloMET_passPres_TEff,"GluinoN 800 GeV");
  GluinoN_MuonEff_RecoCaloMET_legend->AddEntry(GluinoN1400_MuonEff_RecoCaloMET_passPres_TEff,"GluinoN 1400 GeV");
  GluinoN_MuonEff_RecoCaloMET_legend->AddEntry(GluinoN1800_MuonEff_RecoCaloMET_passPres_TEff,"GluinoN 1800 GeV");
  GluinoN_MuonEff_RecoCaloMET_legend->AddEntry(GluinoN2400_MuonEff_RecoCaloMET_passPres_TEff,"GluinoN 2400 GeV");
  GluinoN_MuonEff_RecoCaloMET_legend->Draw();
  c_met->SaveAs("./png/GluinoN_MuonEff_RecoCaloMET_passPres.png");

  // 5678.06) MET or Muon trigger efficiency vs RECO Calo MET, pass preselection
  GluinoN800_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN800_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kOrange);
  GluinoN1400_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kOrange);
  GluinoN1800_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kAzure);
  GluinoN1800_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kAzure);
  GluinoN2400_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kBlack);
  GluinoN2400_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kBlack);
  GluinoN800_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw();
  GluinoN1400_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  GluinoN1800_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  GluinoN2400_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  auto GluinoN_METOrMuonEff_RecoCaloMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  GluinoN_METOrMuonEff_RecoCaloMET_legend->AddEntry(GluinoN800_METOrMuonEff_RecoCaloMET_passPres_TEff,"GluinoN 800 GeV");
  GluinoN_METOrMuonEff_RecoCaloMET_legend->AddEntry(GluinoN1400_METOrMuonEff_RecoCaloMET_passPres_TEff,"GluinoN 1400 GeV");
  GluinoN_METOrMuonEff_RecoCaloMET_legend->AddEntry(GluinoN1800_METOrMuonEff_RecoCaloMET_passPres_TEff,"GluinoN 1800 GeV");
  GluinoN_METOrMuonEff_RecoCaloMET_legend->AddEntry(GluinoN2400_METOrMuonEff_RecoCaloMET_passPres_TEff,"GluinoN 2400 GeV");
  GluinoN_METOrMuonEff_RecoCaloMET_legend->Draw();
  c_met->SaveAs("./png/GluinoN_METOrMuonEff_RecoCaloMET_passPres.png");

  // 5678.08) MET trigger efficiency vs RECO PF MET, pass preselection
  GluinoN800_METEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN800_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_METEff_RecoPFMET_passPres_TEff->SetLineColor(kOrange);
  GluinoN1400_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kOrange);
  GluinoN1800_METEff_RecoPFMET_passPres_TEff->SetLineColor(kAzure);
  GluinoN1800_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kAzure);
  GluinoN2400_METEff_RecoPFMET_passPres_TEff->SetLineColor(kBlack);
  GluinoN2400_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kBlack);
  GluinoN800_METEff_RecoPFMET_passPres_TEff->Draw();
  GluinoN1400_METEff_RecoPFMET_passPres_TEff->Draw("pe same");
  GluinoN1800_METEff_RecoPFMET_passPres_TEff->Draw("pe same");
  GluinoN2400_METEff_RecoPFMET_passPres_TEff->Draw("pe same");
  auto GluinoN_METEff_RecoPFMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  GluinoN_METEff_RecoPFMET_legend->AddEntry(GluinoN800_METEff_RecoPFMET_passPres_TEff,"GluinoN 800 GeV");
  GluinoN_METEff_RecoPFMET_legend->AddEntry(GluinoN1400_METEff_RecoPFMET_passPres_TEff,"GluinoN 1400 GeV");
  GluinoN_METEff_RecoPFMET_legend->AddEntry(GluinoN1800_METEff_RecoPFMET_passPres_TEff,"GluinoN 1800 GeV");
  GluinoN_METEff_RecoPFMET_legend->AddEntry(GluinoN2400_METEff_RecoPFMET_passPres_TEff,"GluinoN 2400 GeV");
  GluinoN_METEff_RecoPFMET_legend->Draw();
  c_met->SaveAs("./png/GluinoN_METEff_RecoPFMET_passPres.png");

  // 5678.10) Muon trigger efficiency vs RECO PF MET, pass preselection
  GluinoN800_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN800_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kOrange);
  GluinoN1400_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kOrange);
  GluinoN1800_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kAzure);
  GluinoN1800_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kAzure);
  GluinoN2400_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kBlack);
  GluinoN2400_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kBlack);
  GluinoN800_MuonEff_RecoPFMET_passPres_TEff->Draw();
  GluinoN1400_MuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  GluinoN1800_MuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  GluinoN2400_MuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  auto GluinoN_MuonEff_RecoPFMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  GluinoN_MuonEff_RecoPFMET_legend->AddEntry(GluinoN800_MuonEff_RecoPFMET_passPres_TEff,"GluinoN 800 GeV");
  GluinoN_MuonEff_RecoPFMET_legend->AddEntry(GluinoN1400_MuonEff_RecoPFMET_passPres_TEff,"GluinoN 1400 GeV");
  GluinoN_MuonEff_RecoPFMET_legend->AddEntry(GluinoN1800_MuonEff_RecoPFMET_passPres_TEff,"GluinoN 1800 GeV");
  GluinoN_MuonEff_RecoPFMET_legend->AddEntry(GluinoN2400_MuonEff_RecoPFMET_passPres_TEff,"GluinoN 2400 GeV");
  GluinoN_MuonEff_RecoPFMET_legend->Draw();
  c_met->SaveAs("./png/GluinoN_MuonEff_RecoPFMET_passPres.png");

  // 5678.12) MET or Muon trigger efficiency vs RECO PF MET, pass preselection
  GluinoN800_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN800_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kOrange);
  GluinoN1400_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kOrange);
  GluinoN1800_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kAzure);
  GluinoN1800_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kAzure);
  GluinoN2400_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kBlack);
  GluinoN2400_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kBlack);
  GluinoN800_METOrMuonEff_RecoPFMET_passPres_TEff->Draw();
  GluinoN1400_METOrMuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  GluinoN1800_METOrMuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  GluinoN2400_METOrMuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  auto GluinoN_METOrMuonEff_RecoPFMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  GluinoN_METOrMuonEff_RecoPFMET_legend->AddEntry(GluinoN800_METOrMuonEff_RecoPFMET_passPres_TEff,"GluinoN 800 GeV");
  GluinoN_METOrMuonEff_RecoPFMET_legend->AddEntry(GluinoN1400_METOrMuonEff_RecoPFMET_passPres_TEff,"GluinoN 1400 GeV");
  GluinoN_METOrMuonEff_RecoPFMET_legend->AddEntry(GluinoN1800_METOrMuonEff_RecoPFMET_passPres_TEff,"GluinoN 1800 GeV");
  GluinoN_METOrMuonEff_RecoPFMET_legend->AddEntry(GluinoN2400_METOrMuonEff_RecoPFMET_passPres_TEff,"GluinoN 2400 GeV");
  GluinoN_METOrMuonEff_RecoPFMET_legend->Draw();
  c_met->SaveAs("./png/GluinoN_METOrMuonEff_RecoPFMET_passPres.png");

  // 5678.14) MET trigger efficiency vs HLT Calo MET, pass preselection
  GluinoN800_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN800_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kOrange);
  GluinoN1400_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kOrange);
  GluinoN1800_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kAzure);
  GluinoN1800_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kAzure);
  GluinoN2400_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kBlack);
  GluinoN2400_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kBlack);
  GluinoN800_METEff_HLTCaloMET_passPres_TEff->Draw();
  GluinoN1400_METEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  GluinoN1800_METEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  GluinoN2400_METEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  auto GluinoN_METEff_HLTCaloMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  GluinoN_METEff_HLTCaloMET_legend->AddEntry(GluinoN800_METEff_HLTCaloMET_passPres_TEff,"GluinoN 800 GeV");
  GluinoN_METEff_HLTCaloMET_legend->AddEntry(GluinoN1400_METEff_HLTCaloMET_passPres_TEff,"GluinoN 1400 GeV");
  GluinoN_METEff_HLTCaloMET_legend->AddEntry(GluinoN1800_METEff_HLTCaloMET_passPres_TEff,"GluinoN 1800 GeV");
  GluinoN_METEff_HLTCaloMET_legend->AddEntry(GluinoN2400_METEff_HLTCaloMET_passPres_TEff,"GluinoN 2400 GeV");
  GluinoN_METEff_HLTCaloMET_legend->Draw();
  c_met->SaveAs("./png/GluinoN_METEff_HLTCaloMET_passPres.png");

  // 5678.16) Muon trigger efficiency vs HLT Calo MET, pass preselection
  GluinoN800_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN800_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kOrange);
  GluinoN1400_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kOrange);
  GluinoN1800_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kAzure);
  GluinoN1800_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kAzure);
  GluinoN2400_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kBlack);
  GluinoN2400_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kBlack);
  GluinoN800_MuonEff_HLTCaloMET_passPres_TEff->Draw();
  GluinoN1400_MuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  GluinoN1800_MuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  GluinoN2400_MuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  auto GluinoN_MuonEff_HLTCaloMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  GluinoN_MuonEff_HLTCaloMET_legend->AddEntry(GluinoN800_MuonEff_HLTCaloMET_passPres_TEff,"GluinoN 800 GeV");
  GluinoN_MuonEff_HLTCaloMET_legend->AddEntry(GluinoN1400_MuonEff_HLTCaloMET_passPres_TEff,"GluinoN 1400 GeV");
  GluinoN_MuonEff_HLTCaloMET_legend->AddEntry(GluinoN1800_MuonEff_HLTCaloMET_passPres_TEff,"GluinoN 1800 GeV");
  GluinoN_MuonEff_HLTCaloMET_legend->AddEntry(GluinoN2400_MuonEff_HLTCaloMET_passPres_TEff,"GluinoN 2400 GeV");
  GluinoN_MuonEff_HLTCaloMET_legend->Draw();
  c_met->SaveAs("./png/GluinoN_MuonEff_HLTCaloMET_passPres.png");

  // 5678.18) MET or Muon trigger efficiency vs HLT Calo MET, pass preselection
  GluinoN800_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GluinoN800_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kOrange);
  GluinoN1400_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kOrange);
  GluinoN1800_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kAzure);
  GluinoN1800_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kAzure);
  GluinoN2400_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kBlack);
  GluinoN2400_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kBlack);
  GluinoN800_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw();
  GluinoN1400_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  GluinoN1800_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  GluinoN2400_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  auto GluinoN_METOrMuonEff_HLTCaloMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  GluinoN_METOrMuonEff_HLTCaloMET_legend->AddEntry(GluinoN800_METOrMuonEff_HLTCaloMET_passPres_TEff,"GluinoN 800 GeV");
  GluinoN_METOrMuonEff_HLTCaloMET_legend->AddEntry(GluinoN1400_METOrMuonEff_HLTCaloMET_passPres_TEff,"GluinoN 1400 GeV");
  GluinoN_METOrMuonEff_HLTCaloMET_legend->AddEntry(GluinoN1800_METOrMuonEff_HLTCaloMET_passPres_TEff,"GluinoN 1800 GeV");
  GluinoN_METOrMuonEff_HLTCaloMET_legend->AddEntry(GluinoN2400_METOrMuonEff_HLTCaloMET_passPres_TEff,"GluinoN 2400 GeV");
  GluinoN_METOrMuonEff_HLTCaloMET_legend->Draw();
  c_met->SaveAs("./png/GluinoN_METOrMuonEff_HLTCaloMET_passPres.png");

  // 5678.20) MET trigger efficiency vs HLT PF MET, pass preselection
  GluinoN800_METEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN800_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_METEff_HLTPFMET_passPres_TEff->SetLineColor(kOrange);
  GluinoN1400_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kOrange);
  GluinoN1800_METEff_HLTPFMET_passPres_TEff->SetLineColor(kAzure);
  GluinoN1800_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kAzure);
  GluinoN2400_METEff_HLTPFMET_passPres_TEff->SetLineColor(kBlack);
  GluinoN2400_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kBlack);
  GluinoN800_METEff_HLTPFMET_passPres_TEff->Draw();
  GluinoN1400_METEff_HLTPFMET_passPres_TEff->Draw("pe same");
  GluinoN1800_METEff_HLTPFMET_passPres_TEff->Draw("pe same");
  GluinoN2400_METEff_HLTPFMET_passPres_TEff->Draw("pe same");
  auto GluinoN_METEff_HLTPFMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  GluinoN_METEff_HLTPFMET_legend->AddEntry(GluinoN800_METEff_HLTPFMET_passPres_TEff,"GluinoN 800 GeV");
  GluinoN_METEff_HLTPFMET_legend->AddEntry(GluinoN1400_METEff_HLTPFMET_passPres_TEff,"GluinoN 1400 GeV");
  GluinoN_METEff_HLTPFMET_legend->AddEntry(GluinoN1800_METEff_HLTPFMET_passPres_TEff,"GluinoN 1800 GeV");
  GluinoN_METEff_HLTPFMET_legend->AddEntry(GluinoN2400_METEff_HLTPFMET_passPres_TEff,"GluinoN 2400 GeV");
  GluinoN_METEff_HLTPFMET_legend->Draw();
  c_met->SaveAs("./png/GluinoN_METEff_HLTPFMET_passPres.png");

  // 5678.22) Muon trigger efficiency vs HLT PF MET, pass preselection
  GluinoN800_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN800_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kOrange);
  GluinoN1400_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kOrange);
  GluinoN1800_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kAzure);
  GluinoN1800_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kAzure);
  GluinoN2400_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kBlack);
  GluinoN2400_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kBlack);
  GluinoN800_MuonEff_HLTPFMET_passPres_TEff->Draw();
  GluinoN1400_MuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  GluinoN1800_MuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  GluinoN2400_MuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  auto GluinoN_MuonEff_HLTPFMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  GluinoN_MuonEff_HLTPFMET_legend->AddEntry(GluinoN800_MuonEff_HLTPFMET_passPres_TEff,"GluinoN 800 GeV");
  GluinoN_MuonEff_HLTPFMET_legend->AddEntry(GluinoN1400_MuonEff_HLTPFMET_passPres_TEff,"GluinoN 1400 GeV");
  GluinoN_MuonEff_HLTPFMET_legend->AddEntry(GluinoN1800_MuonEff_HLTPFMET_passPres_TEff,"GluinoN 1800 GeV");
  GluinoN_MuonEff_HLTPFMET_legend->AddEntry(GluinoN2400_MuonEff_HLTPFMET_passPres_TEff,"GluinoN 2400 GeV");
  GluinoN_MuonEff_HLTPFMET_legend->Draw();
  c_met->SaveAs("./png/GluinoN_MuonEff_HLTPFMET_passPres.png");

  // 5678.24) MET or Muon trigger efficiency vs HLT PF MET, pass preselection
  GluinoN800_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GluinoN800_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GluinoN1400_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kOrange);
  GluinoN1400_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kOrange);
  GluinoN1800_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kAzure);
  GluinoN1800_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kAzure);
  GluinoN2400_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kBlack);
  GluinoN2400_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kBlack);
  GluinoN800_METOrMuonEff_HLTPFMET_passPres_TEff->Draw();
  GluinoN1400_METOrMuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  GluinoN1800_METOrMuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  GluinoN2400_METOrMuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  auto GluinoN_METOrMuonEff_HLTPFMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  GluinoN_METOrMuonEff_HLTPFMET_legend->AddEntry(GluinoN800_METOrMuonEff_HLTPFMET_passPres_TEff,"GluinoN 800 GeV");
  GluinoN_METOrMuonEff_HLTPFMET_legend->AddEntry(GluinoN1400_METOrMuonEff_HLTPFMET_passPres_TEff,"GluinoN 1400 GeV");
  GluinoN_METOrMuonEff_HLTPFMET_legend->AddEntry(GluinoN1800_METOrMuonEff_HLTPFMET_passPres_TEff,"GluinoN 1800 GeV");
  GluinoN_METOrMuonEff_HLTPFMET_legend->AddEntry(GluinoN2400_METOrMuonEff_HLTPFMET_passPres_TEff,"GluinoN 2400 GeV");
  GluinoN_METOrMuonEff_HLTPFMET_legend->Draw();
  c_met->SaveAs("./png/GluinoN_METOrMuonEff_HLTPFMET_passPres.png");

  // 9101112.02) MET trigger efficiency vs RECO Calo MET, pass preselection
  GMSBStau200_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau200_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kOrange);
  GMSBStau432_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kOrange);
  GMSBStau651_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kAzure);
  GMSBStau651_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kAzure);
  GMSBStau871_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kBlack);
  GMSBStau871_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kBlack);
  GMSBStau200_METEff_RecoCaloMET_passPres_TEff->Draw();
  GMSBStau432_METEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  GMSBStau651_METEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  GMSBStau871_METEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  auto GMSBStau_METEff_RecoCaloMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  GMSBStau_METEff_RecoCaloMET_legend->AddEntry(GMSBStau200_METEff_RecoCaloMET_passPres_TEff,"GMSBStau 200 GeV");
  GMSBStau_METEff_RecoCaloMET_legend->AddEntry(GMSBStau432_METEff_RecoCaloMET_passPres_TEff,"GMSBStau 432 GeV");
  GMSBStau_METEff_RecoCaloMET_legend->AddEntry(GMSBStau651_METEff_RecoCaloMET_passPres_TEff,"GMSBStau 651 GeV");
  GMSBStau_METEff_RecoCaloMET_legend->AddEntry(GMSBStau871_METEff_RecoCaloMET_passPres_TEff,"GMSBStau 871 GeV");
  GMSBStau_METEff_RecoCaloMET_legend->Draw();
  c_met->SaveAs("./png/GMSBStau_METEff_RecoCaloMET_passPres.png");

  // 9101112.04) Muon trigger efficiency vs RECO Calo MET, pass preselection
  GMSBStau200_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau200_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kOrange);
  GMSBStau432_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kOrange);
  GMSBStau651_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kAzure);
  GMSBStau651_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kAzure);
  GMSBStau871_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kBlack);
  GMSBStau871_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kBlack);
  GMSBStau200_MuonEff_RecoCaloMET_passPres_TEff->Draw();
  GMSBStau432_MuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  GMSBStau651_MuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  GMSBStau871_MuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  auto GMSBStau_MuonEff_RecoCaloMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  GMSBStau_MuonEff_RecoCaloMET_legend->AddEntry(GMSBStau200_MuonEff_RecoCaloMET_passPres_TEff,"GMSBStau 200 GeV");
  GMSBStau_MuonEff_RecoCaloMET_legend->AddEntry(GMSBStau432_MuonEff_RecoCaloMET_passPres_TEff,"GMSBStau 432 GeV");
  GMSBStau_MuonEff_RecoCaloMET_legend->AddEntry(GMSBStau651_MuonEff_RecoCaloMET_passPres_TEff,"GMSBStau 651 GeV");
  GMSBStau_MuonEff_RecoCaloMET_legend->AddEntry(GMSBStau871_MuonEff_RecoCaloMET_passPres_TEff,"GMSBStau 871 GeV");
  GMSBStau_MuonEff_RecoCaloMET_legend->Draw();
  c_met->SaveAs("./png/GMSBStau_MuonEff_RecoCaloMET_passPres.png");

  // 9101112.06) MET or Muon trigger efficiency vs RECO Calo MET, pass preselection
  GMSBStau200_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau200_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kOrange);
  GMSBStau432_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kOrange);
  GMSBStau651_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kAzure);
  GMSBStau651_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kAzure);
  GMSBStau871_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kBlack);
  GMSBStau871_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kBlack);
  GMSBStau200_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw();
  GMSBStau432_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  GMSBStau651_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  GMSBStau871_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  auto GMSBStau_METOrMuonEff_RecoCaloMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  GMSBStau_METOrMuonEff_RecoCaloMET_legend->AddEntry(GMSBStau200_METOrMuonEff_RecoCaloMET_passPres_TEff,"GMSBStau 200 GeV");
  GMSBStau_METOrMuonEff_RecoCaloMET_legend->AddEntry(GMSBStau432_METOrMuonEff_RecoCaloMET_passPres_TEff,"GMSBStau 432 GeV");
  GMSBStau_METOrMuonEff_RecoCaloMET_legend->AddEntry(GMSBStau651_METOrMuonEff_RecoCaloMET_passPres_TEff,"GMSBStau 651 GeV");
  GMSBStau_METOrMuonEff_RecoCaloMET_legend->AddEntry(GMSBStau871_METOrMuonEff_RecoCaloMET_passPres_TEff,"GMSBStau 871 GeV");
  GMSBStau_METOrMuonEff_RecoCaloMET_legend->Draw();
  c_met->SaveAs("./png/GMSBStau_METOrMuonEff_RecoCaloMET_passPres.png");

  // 9101112.08) MET trigger efficiency vs RECO PF MET, pass preselection
  GMSBStau200_METEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau200_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_METEff_RecoPFMET_passPres_TEff->SetLineColor(kOrange);
  GMSBStau432_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kOrange);
  GMSBStau651_METEff_RecoPFMET_passPres_TEff->SetLineColor(kAzure);
  GMSBStau651_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kAzure);
  GMSBStau871_METEff_RecoPFMET_passPres_TEff->SetLineColor(kBlack);
  GMSBStau871_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kBlack);
  GMSBStau200_METEff_RecoPFMET_passPres_TEff->Draw();
  GMSBStau432_METEff_RecoPFMET_passPres_TEff->Draw("pe same");
  GMSBStau651_METEff_RecoPFMET_passPres_TEff->Draw("pe same");
  GMSBStau871_METEff_RecoPFMET_passPres_TEff->Draw("pe same");
  auto GMSBStau_METEff_RecoPFMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  GMSBStau_METEff_RecoPFMET_legend->AddEntry(GMSBStau200_METEff_RecoPFMET_passPres_TEff,"GMSBStau 200 GeV");
  GMSBStau_METEff_RecoPFMET_legend->AddEntry(GMSBStau432_METEff_RecoPFMET_passPres_TEff,"GMSBStau 432 GeV");
  GMSBStau_METEff_RecoPFMET_legend->AddEntry(GMSBStau651_METEff_RecoPFMET_passPres_TEff,"GMSBStau 651 GeV");
  GMSBStau_METEff_RecoPFMET_legend->AddEntry(GMSBStau871_METEff_RecoPFMET_passPres_TEff,"GMSBStau 871 GeV");
  GMSBStau_METEff_RecoPFMET_legend->Draw();
  c_met->SaveAs("./png/GMSBStau_METEff_RecoPFMET_passPres.png");

  // 9101112.10) Muon trigger efficiency vs RECO PF MET, pass preselection
  GMSBStau200_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau200_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kOrange);
  GMSBStau432_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kOrange);
  GMSBStau651_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kAzure);
  GMSBStau651_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kAzure);
  GMSBStau871_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kBlack);
  GMSBStau871_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kBlack);
  GMSBStau200_MuonEff_RecoPFMET_passPres_TEff->Draw();
  GMSBStau432_MuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  GMSBStau651_MuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  GMSBStau871_MuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  auto GMSBStau_MuonEff_RecoPFMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  GMSBStau_MuonEff_RecoPFMET_legend->AddEntry(GMSBStau200_MuonEff_RecoPFMET_passPres_TEff,"GMSBStau 200 GeV");
  GMSBStau_MuonEff_RecoPFMET_legend->AddEntry(GMSBStau432_MuonEff_RecoPFMET_passPres_TEff,"GMSBStau 432 GeV");
  GMSBStau_MuonEff_RecoPFMET_legend->AddEntry(GMSBStau651_MuonEff_RecoPFMET_passPres_TEff,"GMSBStau 651 GeV");
  GMSBStau_MuonEff_RecoPFMET_legend->AddEntry(GMSBStau871_MuonEff_RecoPFMET_passPres_TEff,"GMSBStau 871 GeV");
  GMSBStau_MuonEff_RecoPFMET_legend->Draw();
  c_met->SaveAs("./png/GMSBStau_MuonEff_RecoPFMET_passPres.png");

  // 9101112.12) MET or Muon trigger efficiency vs RECO PF MET, pass preselection
  GMSBStau200_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau200_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kOrange);
  GMSBStau432_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kOrange);
  GMSBStau651_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kAzure);
  GMSBStau651_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kAzure);
  GMSBStau871_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kBlack);
  GMSBStau871_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kBlack);
  GMSBStau200_METOrMuonEff_RecoPFMET_passPres_TEff->Draw();
  GMSBStau432_METOrMuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  GMSBStau651_METOrMuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  GMSBStau871_METOrMuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  auto GMSBStau_METOrMuonEff_RecoPFMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  GMSBStau_METOrMuonEff_RecoPFMET_legend->AddEntry(GMSBStau200_METOrMuonEff_RecoPFMET_passPres_TEff,"GMSBStau 200 GeV");
  GMSBStau_METOrMuonEff_RecoPFMET_legend->AddEntry(GMSBStau432_METOrMuonEff_RecoPFMET_passPres_TEff,"GMSBStau 432 GeV");
  GMSBStau_METOrMuonEff_RecoPFMET_legend->AddEntry(GMSBStau651_METOrMuonEff_RecoPFMET_passPres_TEff,"GMSBStau 651 GeV");
  GMSBStau_METOrMuonEff_RecoPFMET_legend->AddEntry(GMSBStau871_METOrMuonEff_RecoPFMET_passPres_TEff,"GMSBStau 871 GeV");
  GMSBStau_METOrMuonEff_RecoPFMET_legend->Draw();
  c_met->SaveAs("./png/GMSBStau_METOrMuonEff_RecoPFMET_passPres.png");

  // 9101112.14) MET trigger efficiency vs HLT Calo MET, pass preselection
  GMSBStau200_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau200_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kOrange);
  GMSBStau432_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kOrange);
  GMSBStau651_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kAzure);
  GMSBStau651_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kAzure);
  GMSBStau871_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kBlack);
  GMSBStau871_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kBlack);
  GMSBStau200_METEff_HLTCaloMET_passPres_TEff->Draw();
  GMSBStau432_METEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  GMSBStau651_METEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  GMSBStau871_METEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  auto GMSBStau_METEff_HLTCaloMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  GMSBStau_METEff_HLTCaloMET_legend->AddEntry(GMSBStau200_METEff_HLTCaloMET_passPres_TEff,"GMSBStau 200 GeV");
  GMSBStau_METEff_HLTCaloMET_legend->AddEntry(GMSBStau432_METEff_HLTCaloMET_passPres_TEff,"GMSBStau 432 GeV");
  GMSBStau_METEff_HLTCaloMET_legend->AddEntry(GMSBStau651_METEff_HLTCaloMET_passPres_TEff,"GMSBStau 651 GeV");
  GMSBStau_METEff_HLTCaloMET_legend->AddEntry(GMSBStau871_METEff_HLTCaloMET_passPres_TEff,"GMSBStau 871 GeV");
  GMSBStau_METEff_HLTCaloMET_legend->Draw();
  c_met->SaveAs("./png/GMSBStau_METEff_HLTCaloMET_passPres.png");

  // 9101112.16) Muon trigger efficiency vs HLT Calo MET, pass preselection
  GMSBStau200_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau200_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kOrange);
  GMSBStau432_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kOrange);
  GMSBStau651_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kAzure);
  GMSBStau651_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kAzure);
  GMSBStau871_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kBlack);
  GMSBStau871_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kBlack);
  GMSBStau200_MuonEff_HLTCaloMET_passPres_TEff->Draw();
  GMSBStau432_MuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  GMSBStau651_MuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  GMSBStau871_MuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  auto GMSBStau_MuonEff_HLTCaloMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  GMSBStau_MuonEff_HLTCaloMET_legend->AddEntry(GMSBStau200_MuonEff_HLTCaloMET_passPres_TEff,"GMSBStau 200 GeV");
  GMSBStau_MuonEff_HLTCaloMET_legend->AddEntry(GMSBStau432_MuonEff_HLTCaloMET_passPres_TEff,"GMSBStau 432 GeV");
  GMSBStau_MuonEff_HLTCaloMET_legend->AddEntry(GMSBStau651_MuonEff_HLTCaloMET_passPres_TEff,"GMSBStau 651 GeV");
  GMSBStau_MuonEff_HLTCaloMET_legend->AddEntry(GMSBStau871_MuonEff_HLTCaloMET_passPres_TEff,"GMSBStau 871 GeV");
  GMSBStau_MuonEff_HLTCaloMET_legend->Draw();
  c_met->SaveAs("./png/GMSBStau_MuonEff_HLTCaloMET_passPres.png");

  // 9101112.18) MET or Muon trigger efficiency vs HLT Calo MET, pass preselection
  GMSBStau200_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau200_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kOrange);
  GMSBStau432_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kOrange);
  GMSBStau651_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kAzure);
  GMSBStau651_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kAzure);
  GMSBStau871_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kBlack);
  GMSBStau871_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kBlack);
  GMSBStau200_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw();
  GMSBStau432_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  GMSBStau651_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  GMSBStau871_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  auto GMSBStau_METOrMuonEff_HLTCaloMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  GMSBStau_METOrMuonEff_HLTCaloMET_legend->AddEntry(GMSBStau200_METOrMuonEff_HLTCaloMET_passPres_TEff,"GMSBStau 200 GeV");
  GMSBStau_METOrMuonEff_HLTCaloMET_legend->AddEntry(GMSBStau432_METOrMuonEff_HLTCaloMET_passPres_TEff,"GMSBStau 432 GeV");
  GMSBStau_METOrMuonEff_HLTCaloMET_legend->AddEntry(GMSBStau651_METOrMuonEff_HLTCaloMET_passPres_TEff,"GMSBStau 651 GeV");
  GMSBStau_METOrMuonEff_HLTCaloMET_legend->AddEntry(GMSBStau871_METOrMuonEff_HLTCaloMET_passPres_TEff,"GMSBStau 871 GeV");
  GMSBStau_METOrMuonEff_HLTCaloMET_legend->Draw();
  c_met->SaveAs("./png/GMSBStau_METOrMuonEff_HLTCaloMET_passPres.png");

  // 9101112.20) MET trigger efficiency vs HLT PF MET, pass preselection
  GMSBStau200_METEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau200_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_METEff_HLTPFMET_passPres_TEff->SetLineColor(kOrange);
  GMSBStau432_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kOrange);
  GMSBStau651_METEff_HLTPFMET_passPres_TEff->SetLineColor(kAzure);
  GMSBStau651_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kAzure);
  GMSBStau871_METEff_HLTPFMET_passPres_TEff->SetLineColor(kBlack);
  GMSBStau871_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kBlack);
  GMSBStau200_METEff_HLTPFMET_passPres_TEff->Draw();
  GMSBStau432_METEff_HLTPFMET_passPres_TEff->Draw("pe same");
  GMSBStau651_METEff_HLTPFMET_passPres_TEff->Draw("pe same");
  GMSBStau871_METEff_HLTPFMET_passPres_TEff->Draw("pe same");
  auto GMSBStau_METEff_HLTPFMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  GMSBStau_METEff_HLTPFMET_legend->AddEntry(GMSBStau200_METEff_HLTPFMET_passPres_TEff,"GMSBStau 200 GeV");
  GMSBStau_METEff_HLTPFMET_legend->AddEntry(GMSBStau432_METEff_HLTPFMET_passPres_TEff,"GMSBStau 432 GeV");
  GMSBStau_METEff_HLTPFMET_legend->AddEntry(GMSBStau651_METEff_HLTPFMET_passPres_TEff,"GMSBStau 651 GeV");
  GMSBStau_METEff_HLTPFMET_legend->AddEntry(GMSBStau871_METEff_HLTPFMET_passPres_TEff,"GMSBStau 871 GeV");
  GMSBStau_METEff_HLTPFMET_legend->Draw();
  c_met->SaveAs("./png/GMSBStau_METEff_HLTPFMET_passPres.png");

  // 9101112.22) Muon trigger efficiency vs HLT PF MET, pass preselection
  GMSBStau200_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau200_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kOrange);
  GMSBStau432_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kOrange);
  GMSBStau651_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kAzure);
  GMSBStau651_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kAzure);
  GMSBStau871_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kBlack);
  GMSBStau871_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kBlack);
  GMSBStau200_MuonEff_HLTPFMET_passPres_TEff->Draw();
  GMSBStau432_MuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  GMSBStau651_MuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  GMSBStau871_MuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  auto GMSBStau_MuonEff_HLTPFMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  GMSBStau_MuonEff_HLTPFMET_legend->AddEntry(GMSBStau200_MuonEff_HLTPFMET_passPres_TEff,"GMSBStau 200 GeV");
  GMSBStau_MuonEff_HLTPFMET_legend->AddEntry(GMSBStau432_MuonEff_HLTPFMET_passPres_TEff,"GMSBStau 432 GeV");
  GMSBStau_MuonEff_HLTPFMET_legend->AddEntry(GMSBStau651_MuonEff_HLTPFMET_passPres_TEff,"GMSBStau 651 GeV");
  GMSBStau_MuonEff_HLTPFMET_legend->AddEntry(GMSBStau871_MuonEff_HLTPFMET_passPres_TEff,"GMSBStau 871 GeV");
  GMSBStau_MuonEff_HLTPFMET_legend->Draw();
  c_met->SaveAs("./png/GMSBStau_MuonEff_HLTPFMET_passPres.png");

  // 9101112.24) MET or Muon trigger efficiency vs HLT PF MET, pass preselection
  GMSBStau200_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  GMSBStau200_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  GMSBStau432_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kOrange);
  GMSBStau432_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kOrange);
  GMSBStau651_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kAzure);
  GMSBStau651_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kAzure);
  GMSBStau871_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kBlack);
  GMSBStau871_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kBlack);
  GMSBStau200_METOrMuonEff_HLTPFMET_passPres_TEff->Draw();
  GMSBStau432_METOrMuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  GMSBStau651_METOrMuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  GMSBStau871_METOrMuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  auto GMSBStau_METOrMuonEff_HLTPFMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  GMSBStau_METOrMuonEff_HLTPFMET_legend->AddEntry(GMSBStau200_METOrMuonEff_HLTPFMET_passPres_TEff,"GMSBStau 200 GeV");
  GMSBStau_METOrMuonEff_HLTPFMET_legend->AddEntry(GMSBStau432_METOrMuonEff_HLTPFMET_passPres_TEff,"GMSBStau 432 GeV");
  GMSBStau_METOrMuonEff_HLTPFMET_legend->AddEntry(GMSBStau651_METOrMuonEff_HLTPFMET_passPres_TEff,"GMSBStau 651 GeV");
  GMSBStau_METOrMuonEff_HLTPFMET_legend->AddEntry(GMSBStau871_METOrMuonEff_HLTPFMET_passPres_TEff,"GMSBStau 871 GeV");
  GMSBStau_METOrMuonEff_HLTPFMET_legend->Draw();
  c_met->SaveAs("./png/GMSBStau_METOrMuonEff_HLTPFMET_passPres.png");

  // 131415.02) MET trigger efficiency vs RECO Calo MET, pass preselection
  PairStau200_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  PairStau200_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau432_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kOrange);
  PairStau432_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kOrange);
  PairStau651_METEff_RecoCaloMET_passPres_TEff->SetLineColor(kAzure);
  PairStau651_METEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kAzure);
  PairStau200_METEff_RecoCaloMET_passPres_TEff->Draw();
  PairStau432_METEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  PairStau651_METEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  auto PairStau_METEff_RecoCaloMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  PairStau_METEff_RecoCaloMET_legend->AddEntry(PairStau200_METEff_RecoCaloMET_passPres_TEff,"PairStau 200 GeV");
  PairStau_METEff_RecoCaloMET_legend->AddEntry(PairStau432_METEff_RecoCaloMET_passPres_TEff,"PairStau 432 GeV");
  PairStau_METEff_RecoCaloMET_legend->AddEntry(PairStau651_METEff_RecoCaloMET_passPres_TEff,"PairStau 651 GeV");
  PairStau_METEff_RecoCaloMET_legend->Draw();
  c_met->SaveAs("./png/PairStau_METEff_RecoCaloMET_passPres.png");

  // 131415.04) Muon trigger efficiency vs RECO Calo MET, pass preselection
  PairStau200_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  PairStau200_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau432_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kOrange);
  PairStau432_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kOrange);
  PairStau651_MuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kAzure);
  PairStau651_MuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kAzure);
  PairStau200_MuonEff_RecoCaloMET_passPres_TEff->Draw();
  PairStau432_MuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  PairStau651_MuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  auto PairStau_MuonEff_RecoCaloMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  PairStau_MuonEff_RecoCaloMET_legend->AddEntry(PairStau200_MuonEff_RecoCaloMET_passPres_TEff,"PairStau 200 GeV");
  PairStau_MuonEff_RecoCaloMET_legend->AddEntry(PairStau432_MuonEff_RecoCaloMET_passPres_TEff,"PairStau 432 GeV");
  PairStau_MuonEff_RecoCaloMET_legend->AddEntry(PairStau651_MuonEff_RecoCaloMET_passPres_TEff,"PairStau 651 GeV");
  PairStau_MuonEff_RecoCaloMET_legend->Draw();
  c_met->SaveAs("./png/PairStau_MuonEff_RecoCaloMET_passPres.png");

  // 131415.06) MET or Muon trigger efficiency vs RECO Calo MET, pass preselection
  PairStau200_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kRed);
  PairStau200_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau432_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kOrange);
  PairStau432_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kOrange);
  PairStau651_METOrMuonEff_RecoCaloMET_passPres_TEff->SetLineColor(kAzure);
  PairStau651_METOrMuonEff_RecoCaloMET_passPres_TEff->SetMarkerColor(kAzure);
  PairStau200_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw();
  PairStau432_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  PairStau651_METOrMuonEff_RecoCaloMET_passPres_TEff->Draw("pe same");
  auto PairStau_METOrMuonEff_RecoCaloMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  PairStau_METOrMuonEff_RecoCaloMET_legend->AddEntry(PairStau200_METOrMuonEff_RecoCaloMET_passPres_TEff,"PairStau 200 GeV");
  PairStau_METOrMuonEff_RecoCaloMET_legend->AddEntry(PairStau432_METOrMuonEff_RecoCaloMET_passPres_TEff,"PairStau 432 GeV");
  PairStau_METOrMuonEff_RecoCaloMET_legend->AddEntry(PairStau651_METOrMuonEff_RecoCaloMET_passPres_TEff,"PairStau 651 GeV");
  PairStau_METOrMuonEff_RecoCaloMET_legend->Draw();
  c_met->SaveAs("./png/PairStau_METOrMuonEff_RecoCaloMET_passPres.png");

  // 131415.08) MET trigger efficiency vs RECO PF MET, pass preselection
  PairStau200_METEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  PairStau200_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau432_METEff_RecoPFMET_passPres_TEff->SetLineColor(kOrange);
  PairStau432_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kOrange);
  PairStau651_METEff_RecoPFMET_passPres_TEff->SetLineColor(kAzure);
  PairStau651_METEff_RecoPFMET_passPres_TEff->SetMarkerColor(kAzure);
  PairStau200_METEff_RecoPFMET_passPres_TEff->Draw();
  PairStau432_METEff_RecoPFMET_passPres_TEff->Draw("pe same");
  PairStau651_METEff_RecoPFMET_passPres_TEff->Draw("pe same");
  auto PairStau_METEff_RecoPFMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  PairStau_METEff_RecoPFMET_legend->AddEntry(PairStau200_METEff_RecoPFMET_passPres_TEff,"PairStau 200 GeV");
  PairStau_METEff_RecoPFMET_legend->AddEntry(PairStau432_METEff_RecoPFMET_passPres_TEff,"PairStau 432 GeV");
  PairStau_METEff_RecoPFMET_legend->AddEntry(PairStau651_METEff_RecoPFMET_passPres_TEff,"PairStau 651 GeV");
  PairStau_METEff_RecoPFMET_legend->Draw();
  c_met->SaveAs("./png/PairStau_METEff_RecoPFMET_passPres.png");

  // 131415.10) Muon trigger efficiency vs RECO PF MET, pass preselection
  PairStau200_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  PairStau200_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau432_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kOrange);
  PairStau432_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kOrange);
  PairStau651_MuonEff_RecoPFMET_passPres_TEff->SetLineColor(kAzure);
  PairStau651_MuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kAzure);
  PairStau200_MuonEff_RecoPFMET_passPres_TEff->Draw();
  PairStau432_MuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  PairStau651_MuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  auto PairStau_MuonEff_RecoPFMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  PairStau_MuonEff_RecoPFMET_legend->AddEntry(PairStau200_MuonEff_RecoPFMET_passPres_TEff,"PairStau 200 GeV");
  PairStau_MuonEff_RecoPFMET_legend->AddEntry(PairStau432_MuonEff_RecoPFMET_passPres_TEff,"PairStau 432 GeV");
  PairStau_MuonEff_RecoPFMET_legend->AddEntry(PairStau651_MuonEff_RecoPFMET_passPres_TEff,"PairStau 651 GeV");
  PairStau_MuonEff_RecoPFMET_legend->Draw();
  c_met->SaveAs("./png/PairStau_MuonEff_RecoPFMET_passPres.png");

  // 131415.12) MET or Muon trigger efficiency vs RECO PF MET, pass preselection
  PairStau200_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kRed);
  PairStau200_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau432_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kOrange);
  PairStau432_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kOrange);
  PairStau651_METOrMuonEff_RecoPFMET_passPres_TEff->SetLineColor(kAzure);
  PairStau651_METOrMuonEff_RecoPFMET_passPres_TEff->SetMarkerColor(kAzure);
  PairStau200_METOrMuonEff_RecoPFMET_passPres_TEff->Draw();
  PairStau432_METOrMuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  PairStau651_METOrMuonEff_RecoPFMET_passPres_TEff->Draw("pe same");
  auto PairStau_METOrMuonEff_RecoPFMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  PairStau_METOrMuonEff_RecoPFMET_legend->AddEntry(PairStau200_METOrMuonEff_RecoPFMET_passPres_TEff,"PairStau 200 GeV");
  PairStau_METOrMuonEff_RecoPFMET_legend->AddEntry(PairStau432_METOrMuonEff_RecoPFMET_passPres_TEff,"PairStau 432 GeV");
  PairStau_METOrMuonEff_RecoPFMET_legend->AddEntry(PairStau651_METOrMuonEff_RecoPFMET_passPres_TEff,"PairStau 651 GeV");
  PairStau_METOrMuonEff_RecoPFMET_legend->Draw();
  c_met->SaveAs("./png/PairStau_METOrMuonEff_RecoPFMET_passPres.png");

  // 131415.14) MET trigger efficiency vs HLT Calo MET, pass preselection
  PairStau200_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  PairStau200_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau432_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kOrange);
  PairStau432_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kOrange);
  PairStau651_METEff_HLTCaloMET_passPres_TEff->SetLineColor(kAzure);
  PairStau651_METEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kAzure);
  PairStau200_METEff_HLTCaloMET_passPres_TEff->Draw();
  PairStau432_METEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  PairStau651_METEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  auto PairStau_METEff_HLTCaloMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  PairStau_METEff_HLTCaloMET_legend->AddEntry(PairStau200_METEff_HLTCaloMET_passPres_TEff,"PairStau 200 GeV");
  PairStau_METEff_HLTCaloMET_legend->AddEntry(PairStau432_METEff_HLTCaloMET_passPres_TEff,"PairStau 432 GeV");
  PairStau_METEff_HLTCaloMET_legend->AddEntry(PairStau651_METEff_HLTCaloMET_passPres_TEff,"PairStau 651 GeV");
  PairStau_METEff_HLTCaloMET_legend->Draw();
  c_met->SaveAs("./png/PairStau_METEff_HLTCaloMET_passPres.png");

  // 131415.16) Muon trigger efficiency vs HLT Calo MET, pass preselection
  PairStau200_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  PairStau200_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau432_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kOrange);
  PairStau432_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kOrange);
  PairStau651_MuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kAzure);
  PairStau651_MuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kAzure);
  PairStau200_MuonEff_HLTCaloMET_passPres_TEff->Draw();
  PairStau432_MuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  PairStau651_MuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  auto PairStau_MuonEff_HLTCaloMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  PairStau_MuonEff_HLTCaloMET_legend->AddEntry(PairStau200_MuonEff_HLTCaloMET_passPres_TEff,"PairStau 200 GeV");
  PairStau_MuonEff_HLTCaloMET_legend->AddEntry(PairStau432_MuonEff_HLTCaloMET_passPres_TEff,"PairStau 432 GeV");
  PairStau_MuonEff_HLTCaloMET_legend->AddEntry(PairStau651_MuonEff_HLTCaloMET_passPres_TEff,"PairStau 651 GeV");
  PairStau_MuonEff_HLTCaloMET_legend->Draw();
  c_met->SaveAs("./png/PairStau_MuonEff_HLTCaloMET_passPres.png");

  // 131415.18) MET or Muon trigger efficiency vs HLT Calo MET, pass preselection
  PairStau200_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kRed);
  PairStau200_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau432_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kOrange);
  PairStau432_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kOrange);
  PairStau651_METOrMuonEff_HLTCaloMET_passPres_TEff->SetLineColor(kAzure);
  PairStau651_METOrMuonEff_HLTCaloMET_passPres_TEff->SetMarkerColor(kAzure);
  PairStau200_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw();
  PairStau432_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  PairStau651_METOrMuonEff_HLTCaloMET_passPres_TEff->Draw("pe same");
  auto PairStau_METOrMuonEff_HLTCaloMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  PairStau_METOrMuonEff_HLTCaloMET_legend->AddEntry(PairStau200_METOrMuonEff_HLTCaloMET_passPres_TEff,"PairStau 200 GeV");
  PairStau_METOrMuonEff_HLTCaloMET_legend->AddEntry(PairStau432_METOrMuonEff_HLTCaloMET_passPres_TEff,"PairStau 432 GeV");
  PairStau_METOrMuonEff_HLTCaloMET_legend->AddEntry(PairStau651_METOrMuonEff_HLTCaloMET_passPres_TEff,"PairStau 651 GeV");
  PairStau_METOrMuonEff_HLTCaloMET_legend->Draw();
  c_met->SaveAs("./png/PairStau_METOrMuonEff_HLTCaloMET_passPres.png");

  // 131415.20) MET trigger efficiency vs HLT PF MET, pass preselection
  PairStau200_METEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  PairStau200_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau432_METEff_HLTPFMET_passPres_TEff->SetLineColor(kOrange);
  PairStau432_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kOrange);
  PairStau651_METEff_HLTPFMET_passPres_TEff->SetLineColor(kAzure);
  PairStau651_METEff_HLTPFMET_passPres_TEff->SetMarkerColor(kAzure);
  PairStau200_METEff_HLTPFMET_passPres_TEff->Draw();
  PairStau432_METEff_HLTPFMET_passPres_TEff->Draw("pe same");
  PairStau651_METEff_HLTPFMET_passPres_TEff->Draw("pe same");
  auto PairStau_METEff_HLTPFMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  PairStau_METEff_HLTPFMET_legend->AddEntry(PairStau200_METEff_HLTPFMET_passPres_TEff,"PairStau 200 GeV");
  PairStau_METEff_HLTPFMET_legend->AddEntry(PairStau432_METEff_HLTPFMET_passPres_TEff,"PairStau 432 GeV");
  PairStau_METEff_HLTPFMET_legend->AddEntry(PairStau651_METEff_HLTPFMET_passPres_TEff,"PairStau 651 GeV");
  PairStau_METEff_HLTPFMET_legend->Draw();
  c_met->SaveAs("./png/PairStau_METEff_HLTPFMET_passPres.png");

  // 131415.22) Muon trigger efficiency vs HLT PF MET, pass preselection
  PairStau200_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  PairStau200_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau432_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kOrange);
  PairStau432_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kOrange);
  PairStau651_MuonEff_HLTPFMET_passPres_TEff->SetLineColor(kAzure);
  PairStau651_MuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kAzure);
  PairStau200_MuonEff_HLTPFMET_passPres_TEff->Draw();
  PairStau432_MuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  PairStau651_MuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  auto PairStau_MuonEff_HLTPFMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  PairStau_MuonEff_HLTPFMET_legend->AddEntry(PairStau200_MuonEff_HLTPFMET_passPres_TEff,"PairStau 200 GeV");
  PairStau_MuonEff_HLTPFMET_legend->AddEntry(PairStau432_MuonEff_HLTPFMET_passPres_TEff,"PairStau 432 GeV");
  PairStau_MuonEff_HLTPFMET_legend->AddEntry(PairStau651_MuonEff_HLTPFMET_passPres_TEff,"PairStau 651 GeV");
  PairStau_MuonEff_HLTPFMET_legend->Draw();
  c_met->SaveAs("./png/PairStau_MuonEff_HLTPFMET_passPres.png");

  // 131415.24) MET or Muon trigger efficiency vs HLT PF MET, pass preselection
  PairStau200_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kRed);
  PairStau200_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kRed);
  PairStau432_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kOrange);
  PairStau432_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kOrange);
  PairStau651_METOrMuonEff_HLTPFMET_passPres_TEff->SetLineColor(kAzure);
  PairStau651_METOrMuonEff_HLTPFMET_passPres_TEff->SetMarkerColor(kAzure);
  PairStau200_METOrMuonEff_HLTPFMET_passPres_TEff->Draw();
  PairStau432_METOrMuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  PairStau651_METOrMuonEff_HLTPFMET_passPres_TEff->Draw("pe same");
  auto PairStau_METOrMuonEff_HLTPFMET_legend = new TLegend(0.37,0.13,0.75,0.36);
  PairStau_METOrMuonEff_HLTPFMET_legend->AddEntry(PairStau200_METOrMuonEff_HLTPFMET_passPres_TEff,"PairStau 200 GeV");
  PairStau_METOrMuonEff_HLTPFMET_legend->AddEntry(PairStau432_METOrMuonEff_HLTPFMET_passPres_TEff,"PairStau 432 GeV");
  PairStau_METOrMuonEff_HLTPFMET_legend->AddEntry(PairStau651_METOrMuonEff_HLTPFMET_passPres_TEff,"PairStau 651 GeV");
  PairStau_METOrMuonEff_HLTPFMET_legend->Draw();
  c_met->SaveAs("./png/PairStau_METOrMuonEff_HLTPFMET_passPres.png");

  return;
}
