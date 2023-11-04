#include "TFile.h"
#include "TH1.h"
#include "TH2F.h"
#include "TLegend.h"
#include "TString.h"
#include "TCanvas.h"
#include "TEfficiency.h"
#include "TStyle.h"

void make_trig_plots_test () {

  gStyle->SetPadTopMargin(0.08);
  gStyle->SetPadBottomMargin(0.12);
  gStyle->SetPadLeftMargin(0.15);
  gStyle->SetPadRightMargin(0.05);
  gStyle->SetOptStat(0);

  TH1::SetDefaultSumw2();

  //TFile* f_in03 = new TFile("../histos_Gluino1800.root");
  //TFile* f_in03 = new TFile("../histos_GluinoN1800.root");
  //TFile* f_in03 = new TFile("../histos_GMSBStau557.root");
  //TFile* f_in03 = new TFile("../histos_PairStau557.root");
  //TFile* f_in03 = new TFile("../output_files/V1p4/Gluino_M1800_histos.root");
  //TFile* f_in03 = new TFile("../output_files/V1p4/noMuTrig/noL1Sat/Gluino_M1800_histos_noMuTrig_noL1Sat.root");
  //TFile* f_in03 = new TFile("../output_files/V1p4/noMuTrig/noL1Sat/GluinoN_M1800_histos_noMuTrig_noL1Sat.root");
  //TFile* f_in03 = new TFile("../output_files/V1p4/noMuTrig/noL1Sat/PairStau_M557_histos_noMuTrig_noL1Sat.root");
  TFile* f_in03 = new TFile("../20230921_Gluino_M1800_histos_onlyL1Sat.root");

  //get histograms
  //TH1F* Gluino1800_RPFM_all = (TH1F*) f_in03->Get("h_RPFM_all");
  //TH1F* Gluino1800_RCAM_all = (TH1F*) f_in03->Get("h_RCAM_all");
  TH1F* Gluino1800_RPFM_passMuORMET1234 = (TH1F*) f_in03->Get("h_RPFM_passMuORMET1234");
  TH1F* Gluino1800_RCAM_passMuORMET1234 = (TH1F*) f_in03->Get("h_RCAM_passMuORMET1234");
  //TH1F* Gluino1800_RPFM_passMET1234 = (TH1F*) f_in03->Get("h_RPFM_passMET1234");
  //TH1F* Gluino1800_RCAM_passMET1234 = (TH1F*) f_in03->Get("h_RCAM_passMET1234");
  TH1F* Gluino1800_RPFM_passMu = (TH1F*) f_in03->Get("h_RPFM_passMu");
  TH1F* Gluino1800_RCAM_passMu = (TH1F*) f_in03->Get("h_RCAM_passMu");
  //TH1F* Gluino1800_RPFM_passMET1 = (TH1F*) f_in03->Get("h_RPFM_passMET1");
  //TH1F* Gluino1800_RCAM_passMET1 = (TH1F*) f_in03->Get("h_RCAM_passMET1");
  //TH1F* Gluino1800_RPFM_passMET1Cut1 = (TH1F*) f_in03->Get("h_RPFM_passMET1Cut1");
  //TH1F* Gluino1800_RCAM_passMET1Cut1 = (TH1F*) f_in03->Get("h_RCAM_passMET1Cut1");
  //TH1F* Gluino1800_RPFM_passMET1Cut2 = (TH1F*) f_in03->Get("h_RPFM_passMET1Cut2");
  //TH1F* Gluino1800_RCAM_passMET1Cut2 = (TH1F*) f_in03->Get("h_RCAM_passMET1Cut2");
  //TH1F* Gluino1800_RPFM_passMET1Cut3 = (TH1F*) f_in03->Get("h_RPFM_passMET1Cut3");
  //TH1F* Gluino1800_RCAM_passMET1Cut3 = (TH1F*) f_in03->Get("h_RCAM_passMET1Cut3");
  //TH1F* Gluino1800_RPFM_passMET1Cut4 = (TH1F*) f_in03->Get("h_RPFM_passMET1Cut4");
  //TH1F* Gluino1800_RCAM_passMET1Cut4 = (TH1F*) f_in03->Get("h_RCAM_passMET1Cut4");
  //TH1F* Gluino1800_RPFM_passMET1Cut5 = (TH1F*) f_in03->Get("h_RPFM_passMET1Cut5");
  //TH1F* Gluino1800_RCAM_passMET1Cut5 = (TH1F*) f_in03->Get("h_RCAM_passMET1Cut5");
  //TH1F* Gluino1800_RPFM_passMET1Cut6 = (TH1F*) f_in03->Get("h_RPFM_passMET1Cut6");
  //TH1F* Gluino1800_RCAM_passMET1Cut6 = (TH1F*) f_in03->Get("h_RCAM_passMET1Cut6");

  //passPres & noMu
  TH1F* Gluino1800_RPFM_all = (TH1F*) f_in03->Get("h_RPFM_passPres_noMU");
  TH1F* Gluino1800_RCAM_all = (TH1F*) f_in03->Get("h_RCAM_passPres_noMU");
  TH1F* Gluino1800_RPFM_passMET1234 = (TH1F*) f_in03->Get("h_RPFM_passPres_noMU_passMET1234");
  TH1F* Gluino1800_RCAM_passMET1234 = (TH1F*) f_in03->Get("h_RCAM_passPres_noMU_passMET1234");
  TH1F* Gluino1800_RPFM_passMET1 = (TH1F*) f_in03->Get("h_RPFM_passPres_noMU_passMET1");
  TH1F* Gluino1800_RCAM_passMET1 = (TH1F*) f_in03->Get("h_RCAM_passPres_noMU_passMET1");
  TH1F* Gluino1800_RPFM_passMET1Cut1 = (TH1F*) f_in03->Get("h_RPFM_passPres_noMU_passMET1Cut1");
  TH1F* Gluino1800_RCAM_passMET1Cut1 = (TH1F*) f_in03->Get("h_RCAM_passPres_noMU_passMET1Cut1");
  TH1F* Gluino1800_RPFM_passMET1Cut2 = (TH1F*) f_in03->Get("h_RPFM_passPres_noMU_passMET1Cut2");
  TH1F* Gluino1800_RCAM_passMET1Cut2 = (TH1F*) f_in03->Get("h_RCAM_passPres_noMU_passMET1Cut2");
  TH1F* Gluino1800_RPFM_passMET1Cut3 = (TH1F*) f_in03->Get("h_RPFM_passPres_noMU_passMET1Cut3");
  TH1F* Gluino1800_RCAM_passMET1Cut3 = (TH1F*) f_in03->Get("h_RCAM_passPres_noMU_passMET1Cut3");
  TH1F* Gluino1800_RPFM_passMET1Cut4 = (TH1F*) f_in03->Get("h_RPFM_passPres_noMU_passMET1Cut4");
  TH1F* Gluino1800_RCAM_passMET1Cut4 = (TH1F*) f_in03->Get("h_RCAM_passPres_noMU_passMET1Cut4");
  TH1F* Gluino1800_RPFM_passMET1Cut5 = (TH1F*) f_in03->Get("h_RPFM_passPres_noMU_passMET1Cut5");
  TH1F* Gluino1800_RCAM_passMET1Cut5 = (TH1F*) f_in03->Get("h_RCAM_passPres_noMU_passMET1Cut5");
  TH1F* Gluino1800_RPFM_passMET1Cut6 = (TH1F*) f_in03->Get("h_RPFM_passPres_noMU_passMET1Cut6");
  TH1F* Gluino1800_RCAM_passMET1Cut6 = (TH1F*) f_in03->Get("h_RCAM_passPres_noMU_passMET1Cut6");


  //create canvas
  TCanvas* c_met = new TCanvas("c_met","c_met");
  c_met->SetGrid(1,1);
  c_met->cd();

  // 01) Muon OR MET1234 trigger efficiency vs RecoPFMET
  // 02) Muon OR MET1234 trigger efficiency vs RecoCaloMET
  // 03) MET1234 trigger efficiency vs RecoPFMET
  // 04) MET1234 trigger efficiency vs RecoCaloMET
  // 05) Muon trigger efficiency vs RecoPFMET
  // 06) Muon trigger efficiency vs RecoCaloMET
  // 07) MET1 trigger efficiency vs RecoPFMET
  // 08) MET1 trigger efficiency vs RecoCaloMET
  // 09) MET1 trigger cuts efficiency vs RecoPFMET
  // 010) MET1 trigger cuts efficiency vs RecoCaloMET


  // 01) Muon OR MET1234 trigger efficiency vs RecoPFMET
  TH2F* Gluino1800_MuORMET1234_RPFM = new TH2F("Gluino1800_MuORMET1234_RPFM",";Reco PF MET [GeV];Mu OR MET1234 trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_MuORMET1234_RPFM->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_MuORMET1234_RPFM->Draw();  
  TEfficiency* TEff_Gluino1800_MuORMET1234_RPFM = new TEfficiency(*Gluino1800_RPFM_passMuORMET1234,*Gluino1800_RPFM_all);
  TEff_Gluino1800_MuORMET1234_RPFM->SetLineColor(kRed);
  TEff_Gluino1800_MuORMET1234_RPFM->SetMarkerColor(kRed);
  TEff_Gluino1800_MuORMET1234_RPFM->Draw("pesame");
  c_met->SaveAs("./png/test/Gluino1800_MuORMET1234_RPFM.png");

  // 02) Muon OR MET1234 trigger efficiency vs RecoCaloMET
  TH2F* Gluino1800_MuORMET1234_RCAM = new TH2F("Gluino1800_MuORMET1234_RCAM",";Reco Calo MET [GeV];Mu OR MET1234 trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_MuORMET1234_RCAM->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_MuORMET1234_RCAM->Draw();  
  TEfficiency* TEff_Gluino1800_MuORMET1234_RCAM = new TEfficiency(*Gluino1800_RCAM_passMuORMET1234,*Gluino1800_RCAM_all);
  TEff_Gluino1800_MuORMET1234_RCAM->SetLineColor(kRed);
  TEff_Gluino1800_MuORMET1234_RCAM->SetMarkerColor(kRed);
  TEff_Gluino1800_MuORMET1234_RCAM->Draw("pesame");
  c_met->SaveAs("./png/test/Gluino1800_MuORMET1234_RCAM.png");

  // 03) MET1234 trigger efficiency vs RecoPFMET
  TH2F* Gluino1800_MET1234_RPFM = new TH2F("Gluino1800_MET1234_RPFM",";Reco PF MET [GeV];MET1234 trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_MET1234_RPFM->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_MET1234_RPFM->Draw();  
  TEfficiency* TEff_Gluino1800_MET1234_RPFM = new TEfficiency(*Gluino1800_RPFM_passMET1234,*Gluino1800_RPFM_all);
  TEff_Gluino1800_MET1234_RPFM->SetLineColor(kRed);
  TEff_Gluino1800_MET1234_RPFM->SetMarkerColor(kRed);
  TEff_Gluino1800_MET1234_RPFM->Draw("pesame");
  c_met->SaveAs("./png/test/Gluino1800_MET1234_RPFM.png");

  // 04) MET1234 trigger efficiency vs RecoCaloMET
  TH2F* Gluino1800_MET1234_RCAM = new TH2F("Gluino1800_MET1234_RCAM",";Reco Calo MET [GeV];MET1234 trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_MET1234_RCAM->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_MET1234_RCAM->Draw();  
  TEfficiency* TEff_Gluino1800_MET1234_RCAM = new TEfficiency(*Gluino1800_RCAM_passMET1234,*Gluino1800_RCAM_all);
  TEff_Gluino1800_MET1234_RCAM->SetLineColor(kRed);
  TEff_Gluino1800_MET1234_RCAM->SetMarkerColor(kRed);
  TEff_Gluino1800_MET1234_RCAM->Draw("pesame");
  c_met->SaveAs("./png/test/Gluino1800_MET1234_RCAM.png");

  // 05) Muon trigger efficiency vs RecoPFMET
  TH2F* Gluino1800_Mu_RPFM = new TH2F("Gluino1800_Mu_RPFM",";Reco PF MET [GeV];Mu trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_Mu_RPFM->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_Mu_RPFM->Draw();  
  TEfficiency* TEff_Gluino1800_Mu_RPFM = new TEfficiency(*Gluino1800_RPFM_passMu,*Gluino1800_RPFM_all);
  TEff_Gluino1800_Mu_RPFM->SetLineColor(kRed);
  TEff_Gluino1800_Mu_RPFM->SetMarkerColor(kRed);
  TEff_Gluino1800_Mu_RPFM->Draw("pesame");
  c_met->SaveAs("./png/test/Gluino1800_Mu_RPFM.png");

  // 06) Muon trigger efficiency vs RecoCaloMET
  TH2F* Gluino1800_Mu_RCAM = new TH2F("Gluino1800_Mu_RCAM",";Reco Calo MET [GeV];Mu trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_Mu_RCAM->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_Mu_RCAM->Draw();  
  TEfficiency* TEff_Gluino1800_Mu_RCAM = new TEfficiency(*Gluino1800_RCAM_passMu,*Gluino1800_RCAM_all);
  TEff_Gluino1800_Mu_RCAM->SetLineColor(kRed);
  TEff_Gluino1800_Mu_RCAM->SetMarkerColor(kRed);
  TEff_Gluino1800_Mu_RCAM->Draw("pesame");
  c_met->SaveAs("./png/test/Gluino1800_Mu_RCAM.png");

  // 07) MET1 trigger efficiency vs RecoPFMET
  TH2F* Gluino1800_MET1_RPFM = new TH2F("Gluino1800_MET1_RPFM",";Reco PF MET [GeV];MET1 trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_MET1_RPFM->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_MET1_RPFM->Draw();  
  TEfficiency* TEff_Gluino1800_MET1_RPFM = new TEfficiency(*Gluino1800_RPFM_passMET1,*Gluino1800_RPFM_all);
  TEff_Gluino1800_MET1_RPFM->SetLineColor(kRed);
  TEff_Gluino1800_MET1_RPFM->SetMarkerColor(kRed);
  TEff_Gluino1800_MET1_RPFM->Draw("pesame");
  c_met->SaveAs("./png/test/Gluino1800_MET1_RPFM.png");

  // 08) MET1 trigger efficiency vs RecoCaloMET
  TH2F* Gluino1800_MET1_RCAM = new TH2F("Gluino1800_MET1_RCAM",";Reco Calo MET [GeV];MET1 trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_MET1_RCAM->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_MET1_RCAM->Draw();  
  TEfficiency* TEff_Gluino1800_MET1_RCAM = new TEfficiency(*Gluino1800_RCAM_passMET1,*Gluino1800_RCAM_all);
  TEff_Gluino1800_MET1_RCAM->SetLineColor(kRed);
  TEff_Gluino1800_MET1_RCAM->SetMarkerColor(kRed);
  TEff_Gluino1800_MET1_RCAM->Draw("pesame");
  c_met->SaveAs("./png/test/Gluino1800_MET1_RCAM.png");

  // 09) MET1 trigger cuts efficiency vs RecoPFMET
  TH2F* Gluino1800_MET1Cuts_RPFM = new TH2F("Gluino1800_MET1Cuts_RPFM",";Reco PF MET [GeV];MET1 trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_MET1Cuts_RPFM->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_MET1Cuts_RPFM->Draw();  
  TEfficiency* TEff_Gluino1800_MET1Cut1_RPFM = new TEfficiency(*Gluino1800_RPFM_passMET1Cut1,*Gluino1800_RPFM_all);
  TEfficiency* TEff_Gluino1800_MET1Cut2_RPFM = new TEfficiency(*Gluino1800_RPFM_passMET1Cut2,*Gluino1800_RPFM_all);
  TEfficiency* TEff_Gluino1800_MET1Cut3_RPFM = new TEfficiency(*Gluino1800_RPFM_passMET1Cut3,*Gluino1800_RPFM_all);
  TEfficiency* TEff_Gluino1800_MET1Cut4_RPFM = new TEfficiency(*Gluino1800_RPFM_passMET1Cut4,*Gluino1800_RPFM_all);
  TEfficiency* TEff_Gluino1800_MET1Cut5_RPFM = new TEfficiency(*Gluino1800_RPFM_passMET1Cut5,*Gluino1800_RPFM_all);
  TEfficiency* TEff_Gluino1800_MET1Cut6_RPFM = new TEfficiency(*Gluino1800_RPFM_passMET1Cut6,*Gluino1800_RPFM_all);
  TEff_Gluino1800_MET1Cut1_RPFM->SetLineColor(kGray+3);
  TEff_Gluino1800_MET1Cut1_RPFM->SetMarkerColor(kGray+3);
  TEff_Gluino1800_MET1Cut2_RPFM->SetLineColor(kViolet);
  TEff_Gluino1800_MET1Cut2_RPFM->SetMarkerColor(kViolet);
  TEff_Gluino1800_MET1Cut3_RPFM->SetLineColor(kAzure);
  TEff_Gluino1800_MET1Cut3_RPFM->SetMarkerColor(kAzure);
  TEff_Gluino1800_MET1Cut4_RPFM->SetLineColor(kSpring);
  TEff_Gluino1800_MET1Cut4_RPFM->SetMarkerColor(kSpring);
  TEff_Gluino1800_MET1Cut5_RPFM->SetLineColor(kOrange);
  TEff_Gluino1800_MET1Cut5_RPFM->SetMarkerColor(kOrange);
  TEff_Gluino1800_MET1Cut6_RPFM->SetLineColor(kRed);
  TEff_Gluino1800_MET1Cut6_RPFM->SetMarkerColor(kRed);
  TEff_Gluino1800_MET1Cut1_RPFM->Draw("pesame");
  TEff_Gluino1800_MET1Cut2_RPFM->Draw("pesame");
  TEff_Gluino1800_MET1Cut3_RPFM->Draw("pesame");
  TEff_Gluino1800_MET1Cut4_RPFM->Draw("pesame");
  TEff_Gluino1800_MET1Cut5_RPFM->Draw("pesame");
  TEff_Gluino1800_MET1Cut6_RPFM->Draw("pesame");
  c_met->SaveAs("./png/test/Gluino1800_MET1Cuts_RPFM.png");

  // 10) MET1 trigger cuts efficiency vs RecoCaloMET
  TH2F* Gluino1800_MET1Cuts_RCAM = new TH2F("Gluino1800_MET1Cuts_RCAM",";Reco Calo MET [GeV];MET1 trigger efficiency",100,0,1500,100,0,1);
  Gluino1800_MET1Cuts_RCAM->GetYaxis()->SetTitleOffset(0.98);
  Gluino1800_MET1Cuts_RCAM->Draw();  
  TEfficiency* TEff_Gluino1800_MET1Cut1_RCAM = new TEfficiency(*Gluino1800_RCAM_passMET1Cut1,*Gluino1800_RCAM_all);
  TEfficiency* TEff_Gluino1800_MET1Cut2_RCAM = new TEfficiency(*Gluino1800_RCAM_passMET1Cut2,*Gluino1800_RCAM_all);
  TEfficiency* TEff_Gluino1800_MET1Cut3_RCAM = new TEfficiency(*Gluino1800_RCAM_passMET1Cut3,*Gluino1800_RCAM_all);
  TEfficiency* TEff_Gluino1800_MET1Cut4_RCAM = new TEfficiency(*Gluino1800_RCAM_passMET1Cut4,*Gluino1800_RCAM_all);
  TEfficiency* TEff_Gluino1800_MET1Cut5_RCAM = new TEfficiency(*Gluino1800_RCAM_passMET1Cut5,*Gluino1800_RCAM_all);
  TEfficiency* TEff_Gluino1800_MET1Cut6_RCAM = new TEfficiency(*Gluino1800_RCAM_passMET1Cut6,*Gluino1800_RCAM_all);
  TEff_Gluino1800_MET1Cut1_RCAM->SetLineColor(kGray+3);
  TEff_Gluino1800_MET1Cut1_RCAM->SetMarkerColor(kGray+3);
  TEff_Gluino1800_MET1Cut2_RCAM->SetLineColor(kViolet);
  TEff_Gluino1800_MET1Cut2_RCAM->SetMarkerColor(kViolet);
  TEff_Gluino1800_MET1Cut3_RCAM->SetLineColor(kAzure);
  TEff_Gluino1800_MET1Cut3_RCAM->SetMarkerColor(kAzure);
  TEff_Gluino1800_MET1Cut4_RCAM->SetLineColor(kSpring);
  TEff_Gluino1800_MET1Cut4_RCAM->SetMarkerColor(kSpring);
  TEff_Gluino1800_MET1Cut5_RCAM->SetLineColor(kOrange);
  TEff_Gluino1800_MET1Cut5_RCAM->SetMarkerColor(kOrange);
  TEff_Gluino1800_MET1Cut6_RCAM->SetLineColor(kRed);
  TEff_Gluino1800_MET1Cut6_RCAM->SetMarkerColor(kRed);
  TEff_Gluino1800_MET1Cut1_RCAM->Draw("pesame");
  TEff_Gluino1800_MET1Cut2_RCAM->Draw("pesame");
  TEff_Gluino1800_MET1Cut3_RCAM->Draw("pesame");
  TEff_Gluino1800_MET1Cut4_RCAM->Draw("pesame");
  TEff_Gluino1800_MET1Cut5_RCAM->Draw("pesame");
  TEff_Gluino1800_MET1Cut6_RCAM->Draw("pesame");
  c_met->SaveAs("./png/test/Gluino1800_MET1Cuts_RCAM.png");

  return;
}
