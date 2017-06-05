{

#include <TFile.h>
#include <TH1F.h>
#include <TCanvas.h>

// #######################
// ### Load Data Plots ###
// #######################
//TFile *f1 = new TFile("../histoROOTfiles_forPlots/RunINegPolData_histos_noCorrections_PionXSectionSample.root");
TFile *f1 = new TFile("../histoROOTfiles_forPlots/RunIINegPolData_histos_noCorrections_PionXSectionSample.root");

// #####################################
// ### Load Cosmic Monte Carlo Plots ###
// #####################################
TFile *f2 = new TFile("../histoROOTfiles_forPlots/PionMCDD_RunI_OutOfTheBox.root");


//--------------------------------------------------------------------------------------------------------------
//						dE/dX Plot
//--------------------------------------------------------------------------------------------------------------


// ### Getting the data dE/dX plot ###
TH1F *hDatadEdX = (TH1F*)f1->Get("hdatadEdX");

// ### Labeling the axis ###
hDatadEdX->GetXaxis()->SetTitle("dE/dX (MeV / cm)");
hDatadEdX->GetXaxis()->CenterTitle();

hDatadEdX->GetYaxis()->SetTitle("Events / 0.25 MeV/cm");
hDatadEdX->GetYaxis()->CenterTitle(); 


// ################################
// ### Formatting the histogram ###
// ################################
hDatadEdX->SetLineColor(kBlack);
hDatadEdX->SetLineStyle(0);
hDatadEdX->SetLineWidth(2);
hDatadEdX->SetMarkerStyle(8);
hDatadEdX->SetMarkerSize(0.8);


// ### Scaling Data ###
hDatadEdX->Sumw2();
//hDatadEdX->Scale(1/hDatadEdX->Integral());


// ### Getting the MC dE/dX plot ###
TH1F *hMCdEdX = (TH1F*)f2->Get("hRecoMCdEdX");

// ### Labeling the axis ###
hMCdEdX->GetXaxis()->SetTitle("dE/dX (MeV / cm)");
hMCdEdX->GetXaxis()->CenterTitle();

hMCdEdX->GetYaxis()->SetTitle("Events / 0.25 MeV/cm");
hMCdEdX->GetYaxis()->CenterTitle(); 

// ################################
// ### Formatting the histogram ###
// ################################
hMCdEdX->SetLineColor(kBlue);
hMCdEdX->SetLineStyle(0);
hMCdEdX->SetLineWidth(3);


// ### Normalizing MC to Data ###
double MCIntegral = hMCdEdX->Integral();
double DataIntegral = hDatadEdX->Integral();

double scaleMC = DataIntegral/MCIntegral;

// ### Scaling MC ###
hMCdEdX->Sumw2();
//hMCdEdX->Scale(scaleMC*2.1);
hMCdEdX->Scale(scaleMC*2.5);
//hMCdEdX->Scale( (1/hMCdEdX->Integral())*1.80);


// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c01 = new TCanvas("c01", "dEdX");
c01->SetTicks();
c01->SetFillColor(kWhite);

hMCdEdX->Draw();
hDatadEdX->Draw("E1same");

hMCdEdX->Draw("histosame");


c01->Update();
gPad->RedrawAxis();


TLegend *leg = new TLegend();
leg = new TLegend(0.58,0.65,0.88,0.88);
leg->SetTextSize(0.04);
leg->SetTextAlign(12);
leg->SetFillColor(kWhite);
leg->SetLineColor(kWhite);
leg->SetShadowColor(kWhite);
leg->SetHeader("LArIAT Run-II");
leg->AddEntry(hDatadEdX,"Run-II Pion Data");
leg->AddEntry(hMCdEdX,"Pion MC"); 
leg->Draw();





}
