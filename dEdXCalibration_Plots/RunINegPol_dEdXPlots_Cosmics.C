{

#include <TFile.h>
#include <TH1F.h>
#include <TCanvas.h>

// #######################
// ### Load Data Plots ###
// #######################
TFile *f1 = new TFile("../histoROOTfiles_forPlots/RunINegPolData_histos_noCorrections_CosmicTrackSample.root");

// #####################################
// ### Load Cosmic Monte Carlo Plots ###
// #####################################
TFile *f2 = new TFile("../histoROOTfiles_forPlots/CosmicMC_histos_noCorrections.root");


//--------------------------------------------------------------------------------------------------------------
//						dE/dX Plots
//--------------------------------------------------------------------------------------------------------------

// ### Getting the data dE/dX plot ###
TH1F *hDatadEdX = (TH1F*)f1->Get("hdatadEdX");

// ### Labeling the axis ###
hDatadEdX->GetXaxis()->SetTitle("dE/dX (MeV / cm)");
hDatadEdX->GetXaxis()->CenterTitle();

hDatadEdX->GetYaxis()->SetTitle("Events / 0.25 MeV/cm");
hDatadEdX->GetYaxis()->CenterTitle(); 

// ### Getting the MC dE/dX plot ###
TH1F *hMCdEdX = (TH1F*)f2->Get("hMCRecodEdX");

// ### Labeling the axis ###
hMCdEdX->GetXaxis()->SetTitle("dE/dX (MeV / cm)");
hMCdEdX->GetXaxis()->CenterTitle();

hDatadEdX->GetYaxis()->SetTitle("Events / 0.25 MeV/cm");
hDatadEdX->GetYaxis()->CenterTitle(); 

// ### Normalizing MC to Data ###
double MCIntegral = hMCdEdX->Integral();
double DataIntegral = hDatadEdX->Integral();

double scaleMC = DataIntegral/MCIntegral;


// ==================================================
// == Initializing the parameters which record the ==
// == fit parameters (3 for gaussian 3 for landau) ==
// ==================================================
Double_t par_03[6];
TF1 *data_dqdx_landau = new TF1("data_dedx_landau","landau",0, 50);
TF1 *combined_data_dedx   = new TF1("combined_data_dedx","landau+gaus",0,50);
//TF1 *combined_data_dedx   = new TF1("combined_data_dedx","landau",0,50);


TF1 *mc_dedx_landau   = new TF1("mc_dedx_landau","landau",0, 50);
TF1 *combined_mc_dedx   = new TF1("combined_mc_dedx","landau+gaus",0,50);
//TF1 *combined_mc_dedx   = new TF1("combined_mc_dedx","landau",0,50);


// ### Scaling MC ###
hMCdEdX->Sumw2();
hMCdEdX->Scale(scaleMC);

// ### Fitting the data dE/dX with Landau as a seed ###
hDatadEdX->Fit(data_dedx_landau,"R+0LLi","0",0, 50);

// ### Get the seed parameters for the Landau+Gaus fit ###
data_dedx_landau->GetParameters(&par_03[0]); //<---Getting parameters from fit 0,1,2


// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_data_dedx->SetParameters(par_03);
//combined_data_dedx->SetParLimits(0,0,900000);


// ============================================
// ==== Doing the Landau + Gaussian Fit =======
// ============================================

std::cout<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<"Data dE/dX All"<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<std::endl;

hDatadEdX->Fit(combined_data_dedx,"R0LLi","0",0,50);

// #######################################
// ### Making a histogram from the fit ###
// #######################################
combined_data_dedx->GetParameters(par_03);
combined_data_dedx->SetRange(0,50);
TH1D* dataFit_histo = (TH1D*)combined_data_dedx->GetHistogram();
dataFit_histo->SetFillColor(kBlack);
dataFit_histo->SetFillStyle(3005);
dataFit_histo->SetLineColor(kBlack);
dataFit_histo->SetLineWidth(2);


// ### Fitting the MC dE/dX with Landau as a seed ###
hMCdEdX->Fit(mc_dedx_landau,"R+0LLi","0",0 , 50);

// ### Get the seed parameters for the Landau+Gaus fit ###
mc_dedx_landau->GetParameters(&par_03[0]); //<---Getting parameters from fit 0,1,2

// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_mc_dedx->SetParameters(par_03);
//combined_mc_dedx->SetParLimits(0,0,900000);


std::cout<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<"MC dE/dX Total"<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<std::endl;

// ============================================
// ==== Doing the Landau + Gaussian Fit =======
// ============================================
hMCdEdX->Fit(combined_mc_dedx,"R0LLi","0",0,50);

// #######################################
// ### Making a histogram from the fit ###
// #######################################
combined_mc_dedx->GetParameters(par_03);
combined_mc_dedx->SetRange(0,50);
TH1D* MCFit_histo = (TH1D*)combined_mc_dedx->GetHistogram();
MCFit_histo->SetFillColor(kCyan-9);
MCFit_histo->SetFillStyle(3002);
MCFit_histo->SetLineColor(kCyan-9);
MCFit_histo->SetLineWidth(2);


// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c01 = new TCanvas("c01", "dEdX");
c01->SetTicks();
c01->SetFillColor(kWhite);


hMCdEdX->SetLineColor(kBlue);
hMCdEdX->SetLineStyle(0);
hMCdEdX->SetLineWidth(3);

hDatadEdX->SetLineColor(kBlack);
hDatadEdX->SetLineStyle(0);
hDatadEdX->SetLineWidth(1);
hDatadEdX->SetMarkerStyle(8);
hDatadEdX->SetMarkerSize(0.7);

// ### Drawing the histograms ###
hMCdEdX->Draw("histo");
dataFit_histo->Draw("Csames");
MCFit_histo->Draw("Csames");
hDatadEdX->Draw("E1same");


// ############################
// # Setting the Latex Header #
// ############################
TLatex *t = new TLatex();
t->SetNDC();
t->SetTextFont(62);
t->SetTextSize(0.04);
t->SetTextAlign(40);
t->DrawLatex(0.1,0.90,"LArIAT Preliminary");
t->DrawLatex(0.13,0.84,""); 


TLegend *leg = new TLegend();
leg = new TLegend(0.58,0.65,0.88,0.88);
leg->SetTextSize(0.04);
leg->SetTextAlign(12);
leg->SetFillColor(kWhite);
leg->SetLineColor(kWhite);
leg->SetShadowColor(kWhite);
leg->SetHeader("LArIAT Run-I");
leg->AddEntry(hDatadEdX,"Data");
leg->AddEntry(hMCdEdX,"#pi^{-} MC"); 
leg->AddEntry(dataFit_histo,"Data Fit: MPV = 1.95 #sigma 0.44");
leg->AddEntry(MCFit_histo," MC  Fit: MPV = 1.70 #sigma 0.24");
leg->Draw();



//--------------------------------------------------------------------------------------------------------------
//						dE/dX Plots Quadrant 1
//--------------------------------------------------------------------------------------------------------------

// ### Getting the data dE/dX plot ###
TH1F *hDatadEdX = (TH1F*)f1->Get("hdatadEdXQ1");

// ### Labeling the axis ###
hDatadEdX->GetXaxis()->SetTitle("dE/dX (MeV / cm)");
hDatadEdX->GetXaxis()->CenterTitle();

hDatadEdX->GetYaxis()->SetTitle("Events / 0.25 MeV/cm");
hDatadEdX->GetYaxis()->CenterTitle(); 

// ### Getting the MC dE/dX plot ###
TH1F *hMCdEdX = (TH1F*)f2->Get("hMCRecodEdXQ1");

// ### Labeling the axis ###
hMCdEdX->GetXaxis()->SetTitle("dE/dX (MeV / cm)");
hMCdEdX->GetXaxis()->CenterTitle();

hDatadEdX->GetYaxis()->SetTitle("Events / 0.25 MeV/cm");
hDatadEdX->GetYaxis()->CenterTitle(); 

// ### Normalizing MC to Data ###
double MCIntegral = hMCdEdX->Integral();
double DataIntegral = hDatadEdX->Integral();

double scaleMC = DataIntegral/MCIntegral;


// ==================================================
// == Initializing the parameters which record the ==
// == fit parameters (3 for gaussian 3 for landau) ==
// ==================================================
Double_t par_03[6];
TF1 *data_dedx_landau = new TF1("data_dedx_landau","landau",0, 50);
TF1 *combined_data_dedx   = new TF1("combined_data_dedx","landau+gaus",0,50);


TF1 *mc_dedx_landau   = new TF1("mc_dedx_landau","landau",0, 50);
TF1 *combined_mc_dedx   = new TF1("combined_mc_dedx","landau+gaus",0,50);

// ### Scaling MC ###
hMCdEdX->Sumw2();
hMCdEdX->Scale(scaleMC);

// ### Fitting the data dE/dX with Landau as a seed ###
hDatadEdX->Fit(data_dedx_landau,"R+0LLi","0",0, 50);

// ### Get the seed parameters for the Landau+Gaus fit ###
data_dedx_landau->GetParameters(&par_03[0]); //<---Getting parameters from fit 0,1,2


// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_data_dedx->SetParameters(par_03);
combined_data_dedx->SetParLimits(0,0,900000);


// ============================================
// ==== Doing the Landau + Gaussian Fit =======
// ============================================

std::cout<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<"Data dE/dX Quadrant 1"<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<std::endl;

hDatadEdX->Fit(combined_data_dedx,"R0LLi","0",0,50);

// #######################################
// ### Making a histogram from the fit ###
// #######################################
combined_data_dedx->GetParameters(par_03);
combined_data_dedx->SetRange(0,50);
TH1D* dataFit_histo = (TH1D*)combined_data_dedx->GetHistogram();
dataFit_histo->SetFillColor(kBlack);
dataFit_histo->SetFillStyle(3005);
dataFit_histo->SetLineColor(kBlack);
dataFit_histo->SetLineWidth(2);


// ### Fitting the MC dE/dX with Landau as a seed ###
hMCdEdX->Fit(mc_dedx_landau,"R+0LLi","0",0 , 50);

// ### Get the seed parameters for the Landau+Gaus fit ###
mc_dedx_landau->GetParameters(&par_03[0]); //<---Getting parameters from fit 0,1,2

// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_mc_dedx->SetParameters(par_03);
combined_mc_dedx->SetParLimits(0,0,900000);


std::cout<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<"MC dE/dX  Quadrant 1"<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<std::endl;

// ============================================
// ==== Doing the Landau + Gaussian Fit =======
// ============================================
hMCdEdX->Fit(combined_mc_dedx,"R0LLi","0",0,50);

// #######################################
// ### Making a histogram from the fit ###
// #######################################
combined_mc_dedx->GetParameters(par_03);
combined_mc_dedx->SetRange(0,50);
TH1D* MCFit_histo = (TH1D*)combined_mc_dedx->GetHistogram();
MCFit_histo->SetFillColor(kCyan-9);
MCFit_histo->SetFillStyle(3002);
MCFit_histo->SetLineColor(kCyan-9);
MCFit_histo->SetLineWidth(2);


// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c02 = new TCanvas("c02", "dEdX Q1");
c02->SetTicks();
c02->SetFillColor(kWhite);


hMCdEdX->SetLineColor(kBlue);
hMCdEdX->SetLineStyle(0);
hMCdEdX->SetLineWidth(3);

hDatadEdX->SetLineColor(kBlack);
hDatadEdX->SetLineStyle(0);
hDatadEdX->SetLineWidth(1);
hDatadEdX->SetMarkerStyle(8);
hDatadEdX->SetMarkerSize(0.7);


// ### Drawing the histograms ###
hMCdEdX->Draw("histo");
dataFit_histo->Draw("Csames");
MCFit_histo->Draw("Csames");
hDatadEdX->Draw("E1same");


// ############################
// # Setting the Latex Header #
// ############################
//TLatex *t = new TLatex();
t->SetNDC();
t->SetTextFont(62);
t->SetTextSize(0.04);
t->SetTextAlign(40);
t->DrawLatex(0.1,0.90,"LArIAT Preliminary");
t->DrawLatex(0.13,0.84,""); 


//TLegend *leg = new TLegend();
leg = new TLegend(0.58,0.65,0.88,0.88);
leg->SetTextSize(0.04);
leg->SetTextAlign(12);
leg->SetFillColor(kWhite);
leg->SetLineColor(kWhite);
leg->SetShadowColor(kWhite);
leg->SetHeader("LArIAT Run-I");
leg->AddEntry(hDatadEdX,"Data");
leg->AddEntry(hMCdEdX,"#pi^{-} MC"); 
leg->AddEntry(dataFit_histo,"Data Fit: MPV = 1.91 #sigma 0.31");
leg->AddEntry(MCFit_histo," MC  Fit: MPV = 1.77 #sigma 0.21");
leg->Draw();



//--------------------------------------------------------------------------------------------------------------
//						dE/dX Plots Quadrant 2
//--------------------------------------------------------------------------------------------------------------

// ### Getting the data dE/dX plot ###
TH1F *hDatadEdX = (TH1F*)f1->Get("hdatadEdXQ2");

// ### Labeling the axis ###
hDatadEdX->GetXaxis()->SetTitle("dE/dX (MeV / cm)");
hDatadEdX->GetXaxis()->CenterTitle();

hDatadEdX->GetYaxis()->SetTitle("Events / 0.25 MeV/cm");
hDatadEdX->GetYaxis()->CenterTitle(); 

// ### Getting the MC dE/dX plot ###
TH1F *hMCdEdX = (TH1F*)f2->Get("hMCRecodEdXQ2");

// ### Labeling the axis ###
hMCdEdX->GetXaxis()->SetTitle("dE/dX (MeV / cm)");
hMCdEdX->GetXaxis()->CenterTitle();

hDatadEdX->GetYaxis()->SetTitle("Events / 0.25 MeV/cm");
hDatadEdX->GetYaxis()->CenterTitle(); 

// ### Normalizing MC to Data ###
double MCIntegral = hMCdEdX->Integral();
double DataIntegral = hDatadEdX->Integral();

double scaleMC = DataIntegral/MCIntegral;


// ==================================================
// == Initializing the parameters which record the ==
// == fit parameters (3 for gaussian 3 for landau) ==
// ==================================================
Double_t par_03[6];
TF1 *data_dedx_landau = new TF1("data_dedx_landau","landau",0, 50);
TF1 *combined_data_dedx   = new TF1("combined_data_dedx","landau+gaus",0,50);


TF1 *mc_dedx_landau   = new TF1("mc_dedx_landau","landau",0, 50);
TF1 *combined_mc_dedx   = new TF1("combined_mc_dedx","landau+gaus",0,50);

// ### Scaling MC ###
hMCdEdX->Sumw2();
hMCdEdX->Scale(scaleMC);

// ### Fitting the data dE/dX with Landau as a seed ###
hDatadEdX->Fit(data_dedx_landau,"R+0LLi","0",0, 50);

// ### Get the seed parameters for the Landau+Gaus fit ###
data_dedx_landau->GetParameters(&par_03[0]); //<---Getting parameters from fit 0,1,2


// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_data_dedx->SetParameters(par_03);
combined_data_dedx->SetParLimits(0,0,900000);


// ============================================
// ==== Doing the Landau + Gaussian Fit =======
// ============================================

std::cout<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<"Data dE/dX  Quadrant 2"<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<std::endl;

hDatadEdX->Fit(combined_data_dedx,"R0LLi","0",0,50);

// #######################################
// ### Making a histogram from the fit ###
// #######################################
combined_data_dedx->GetParameters(par_03);
combined_data_dedx->SetRange(0,50);
TH1D* dataFit_histo = (TH1D*)combined_data_dedx->GetHistogram();
dataFit_histo->SetFillColor(kGray+2);
dataFit_histo->SetFillStyle(3003);
dataFit_histo->SetLineColor(kGray+2);
dataFit_histo->SetLineWidth(2);


// ### Fitting the MC dE/dX with Landau as a seed ###
hMCdEdX->Fit(mc_dedx_landau,"R+0LLi","0",0 , 50);

// ### Get the seed parameters for the Landau+Gaus fit ###
mc_dedx_landau->GetParameters(&par_03[0]); //<---Getting parameters from fit 0,1,2

// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_mc_dedx->SetParameters(par_03);
combined_mc_dedx->SetParLimits(0,0,900000);


std::cout<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<"MC dE/dX Quadrant 2"<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<std::endl;

// ============================================
// ==== Doing the Landau + Gaussian Fit =======
// ============================================
hMCdEdX->Fit(combined_mc_dedx,"R0LLi","0",0,50);

// #######################################
// ### Making a histogram from the fit ###
// #######################################
combined_mc_dedx->GetParameters(par_03);
combined_mc_dedx->SetRange(0,50);
TH1D* MCFit_histo = (TH1D*)combined_mc_dedx->GetHistogram();
MCFit_histo->SetFillColor(kCyan-9);
MCFit_histo->SetFillStyle(3002);
MCFit_histo->SetLineColor(kCyan-9);
MCFit_histo->SetLineWidth(2);


// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c03 = new TCanvas("c03", "dEdX Q2");
c03->SetTicks();
c03->SetFillColor(kWhite);


hMCdEdX->SetLineColor(kAzure+1);
hMCdEdX->SetLineStyle(0);
hMCdEdX->SetLineWidth(3);


hDatadEdX->SetLineColor(kGray+2);
hDatadEdX->SetLineStyle(0);
hDatadEdX->SetLineWidth(1);
hDatadEdX->SetMarkerStyle(8);
hDatadEdX->SetMarkerSize(0.7);
hDatadEdX->SetMarkerColor(kGray+2);


// ### Drawing the histograms ###
hMCdEdX->Draw("histo");
dataFit_histo->Draw("Csames");
MCFit_histo->Draw("Csames");
hDatadEdX->Draw("E1same");


// ############################
// # Setting the Latex Header #
// ############################
//TLatex *t = new TLatex();
t->SetNDC();
t->SetTextFont(62);
t->SetTextSize(0.04);
t->SetTextAlign(40);
t->DrawLatex(0.1,0.90,"LArIAT Preliminary");
t->DrawLatex(0.13,0.84,""); 


//TLegend *leg = new TLegend();
leg = new TLegend(0.58,0.65,0.88,0.88);
leg->SetTextSize(0.04);
leg->SetTextAlign(12);
leg->SetFillColor(kWhite);
leg->SetLineColor(kWhite);
leg->SetShadowColor(kWhite);
leg->SetHeader("LArIAT Run-I");
leg->AddEntry(hDatadEdX,"Data");
leg->AddEntry(hMCdEdX,"#pi^{-} MC"); 
leg->AddEntry(dataFit_histo,"Data Fit: MPV = 1.88 #sigma 0.50");
leg->AddEntry(MCFit_histo," MC  Fit: MPV = 1.78 #sigma 0.22");
leg->Draw();




//--------------------------------------------------------------------------------------------------------------
//						dE/dX Plots Quadrant 3
//--------------------------------------------------------------------------------------------------------------

// ### Getting the data dE/dX plot ###
TH1F *hDatadEdX = (TH1F*)f1->Get("hdatadEdXQ3");

// ### Labeling the axis ###
hDatadEdX->GetXaxis()->SetTitle("dE/dX (MeV / cm)");
hDatadEdX->GetXaxis()->CenterTitle();

hDatadEdX->GetYaxis()->SetTitle("Events / 0.25 MeV/cm");
hDatadEdX->GetYaxis()->CenterTitle(); 

// ### Getting the MC dE/dX plot ###
TH1F *hMCdEdX = (TH1F*)f2->Get("hMCRecodEdXQ3");

// ### Labeling the axis ###
hMCdEdX->GetXaxis()->SetTitle("dE/dX (MeV / cm)");
hMCdEdX->GetXaxis()->CenterTitle();

hDatadEdX->GetYaxis()->SetTitle("Events / 0.25 MeV/cm");
hDatadEdX->GetYaxis()->CenterTitle(); 

// ### Normalizing MC to Data ###
double MCIntegral = hMCdEdX->Integral();
double DataIntegral = hDatadEdX->Integral();

double scaleMC = DataIntegral/MCIntegral;


// ==================================================
// == Initializing the parameters which record the ==
// == fit parameters (3 for gaussian 3 for landau) ==
// ==================================================
Double_t par_03[6];
TF1 *data_dedx_landau = new TF1("data_dedx_landau","landau",0, 50);
TF1 *combined_data_dedx   = new TF1("combined_data_dedx","landau+gaus",0,50);


TF1 *mc_dedx_landau   = new TF1("mc_dedx_landau","landau",0, 50);
TF1 *combined_mc_dedx   = new TF1("combined_mc_dedx","landau+gaus",0,50);

// ### Scaling MC ###
hMCdEdX->Sumw2();
hMCdEdX->Scale(scaleMC);

// ### Fitting the data dE/dX with Landau as a seed ###
hDatadEdX->Fit(data_dedx_landau,"R+0LLi","0",0, 50);

// ### Get the seed parameters for the Landau+Gaus fit ###
data_dedx_landau->GetParameters(&par_03[0]); //<---Getting parameters from fit 0,1,2


// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_data_dedx->SetParameters(par_03);
combined_data_dedx->SetParLimits(0,0,900000);


// ============================================
// ==== Doing the Landau + Gaussian Fit =======
// ============================================

std::cout<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<"Data dE/dX  Quadrant 3"<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<std::endl;

hDatadEdX->Fit(combined_data_dedx,"R0LLi","0",0,50);

// #######################################
// ### Making a histogram from the fit ###
// #######################################
combined_data_dedx->GetParameters(par_03);
combined_data_dedx->SetRange(0,50);
TH1D* dataFit_histo = (TH1D*)combined_data_dedx->GetHistogram();
dataFit_histo->SetFillColor(kGray+2);
dataFit_histo->SetFillStyle(3003);
dataFit_histo->SetLineColor(kGray+2);
dataFit_histo->SetLineWidth(2);


// ### Fitting the MC dE/dX with Landau as a seed ###
hMCdEdX->Fit(mc_dedx_landau,"R+0LLi","0",0 , 50);

// ### Get the seed parameters for the Landau+Gaus fit ###
mc_dedx_landau->GetParameters(&par_03[0]); //<---Getting parameters from fit 0,1,2

// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_mc_dedx->SetParameters(par_03);
combined_mc_dedx->SetParLimits(0,0,900000);


std::cout<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<"MC dE/dX Quadrant 3"<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<std::endl;

// ============================================
// ==== Doing the Landau + Gaussian Fit =======
// ============================================
hMCdEdX->Fit(combined_mc_dedx,"R0LLi","0",0,50);

// #######################################
// ### Making a histogram from the fit ###
// #######################################
combined_mc_dedx->GetParameters(par_03);
combined_mc_dedx->SetRange(0,50);
TH1D* MCFit_histo = (TH1D*)combined_mc_dedx->GetHistogram();
MCFit_histo->SetFillColor(kCyan-9);
MCFit_histo->SetFillStyle(3002);
MCFit_histo->SetLineColor(kCyan-9);
MCFit_histo->SetLineWidth(2);


// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c04 = new TCanvas("c04", "dEdX Q3");
c04->SetTicks();
c04->SetFillColor(kWhite);


hMCdEdX->SetLineColor(kAzure+1);
hMCdEdX->SetLineStyle(0);
hMCdEdX->SetLineWidth(3);


hDatadEdX->SetLineColor(kGray+2);
hDatadEdX->SetLineStyle(0);
hDatadEdX->SetLineWidth(1);
hDatadEdX->SetMarkerStyle(8);
hDatadEdX->SetMarkerSize(0.7);
hDatadEdX->SetMarkerColor(kGray+2);


// ### Drawing the histograms ###
hMCdEdX->Draw("histo");
dataFit_histo->Draw("Csames");
MCFit_histo->Draw("Csames");
hDatadEdX->Draw("E1same");


// ############################
// # Setting the Latex Header #
// ############################
//TLatex *t = new TLatex();
t->SetNDC();
t->SetTextFont(62);
t->SetTextSize(0.04);
t->SetTextAlign(40);
t->DrawLatex(0.1,0.90,"LArIAT Preliminary");
t->DrawLatex(0.13,0.84,""); 


//TLegend *leg = new TLegend();
leg = new TLegend(0.58,0.65,0.88,0.88);
leg->SetTextSize(0.04);
leg->SetTextAlign(12);
leg->SetFillColor(kWhite);
leg->SetLineColor(kWhite);
leg->SetShadowColor(kWhite);
leg->SetHeader("LArIAT Run-I");
leg->AddEntry(hDatadEdX,"Data");
leg->AddEntry(hMCdEdX,"#pi^{-} MC"); 
leg->AddEntry(dataFit_histo,"Data Fit: MPV = 1.92 #sigma 0.49");
leg->AddEntry(MCFit_histo," MC  Fit: MPV = 1.80 #sigma 0.23");
leg->Draw();



//--------------------------------------------------------------------------------------------------------------
//						dE/dX Plots Quadrant 4
//--------------------------------------------------------------------------------------------------------------

// ### Getting the data dE/dX plot ###
TH1F *hDatadEdX = (TH1F*)f1->Get("hdatadEdXQ4");

// ### Labeling the axis ###
hDatadEdX->GetXaxis()->SetTitle("dE/dX (MeV / cm)");
hDatadEdX->GetXaxis()->CenterTitle();

hDatadEdX->GetYaxis()->SetTitle("Events / 0.25 MeV/cm");
hDatadEdX->GetYaxis()->CenterTitle(); 

// ### Getting the MC dE/dX plot ###
TH1F *hMCdEdX = (TH1F*)f2->Get("hMCRecodEdXQ4");

// ### Labeling the axis ###
hMCdEdX->GetXaxis()->SetTitle("dE/dX (MeV / cm)");
hMCdEdX->GetXaxis()->CenterTitle();

hDatadEdX->GetYaxis()->SetTitle("Events / 0.25 MeV/cm");
hDatadEdX->GetYaxis()->CenterTitle(); 

// ### Normalizing MC to Data ###
double MCIntegral = hMCdEdX->Integral();
double DataIntegral = hDatadEdX->Integral();

double scaleMC = DataIntegral/MCIntegral;


// ==================================================
// == Initializing the parameters which record the ==
// == fit parameters (3 for gaussian 3 for landau) ==
// ==================================================
Double_t par_03[6];
TF1 *data_dedx_landau = new TF1("data_dedx_landau","landau",0, 50);
TF1 *combined_data_dedx   = new TF1("combined_data_dedx","landau+gaus",0,50);


TF1 *mc_dedx_landau   = new TF1("mc_dedx_landau","landau",0, 50);
TF1 *combined_mc_dedx   = new TF1("combined_mc_dedx","landau+gaus",0,50);

// ### Scaling MC ###
hMCdEdX->Sumw2();
hMCdEdX->Scale(scaleMC);

// ### Fitting the data dE/dX with Landau as a seed ###
hDatadEdX->Fit(data_dedx_landau,"R+0LLi","0",0, 50);

// ### Get the seed parameters for the Landau+Gaus fit ###
data_dedx_landau->GetParameters(&par_03[0]); //<---Getting parameters from fit 0,1,2


// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_data_dedx->SetParameters(par_03);
combined_data_dedx->SetParLimits(0,0,900000);


// ============================================
// ==== Doing the Landau + Gaussian Fit =======
// ============================================

std::cout<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<"Data dE/dX  Quadrant 4"<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<std::endl;

hDatadEdX->Fit(combined_data_dedx,"R0LLi","0",0,50);

// #######################################
// ### Making a histogram from the fit ###
// #######################################
combined_data_dedx->GetParameters(par_03);
combined_data_dedx->SetRange(0,50);
TH1D* dataFit_histo = (TH1D*)combined_data_dedx->GetHistogram();
dataFit_histo->SetFillColor(kGray+2);
dataFit_histo->SetFillStyle(3003);
dataFit_histo->SetLineColor(kGray+2);
dataFit_histo->SetLineWidth(2);


// ### Fitting the MC dE/dX with Landau as a seed ###
hMCdEdX->Fit(mc_dedx_landau,"R+0LLi","0",0 , 50);

// ### Get the seed parameters for the Landau+Gaus fit ###
mc_dedx_landau->GetParameters(&par_03[0]); //<---Getting parameters from fit 0,1,2

// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_mc_dedx->SetParameters(par_03);
combined_mc_dedx->SetParLimits(0,0,900000);


std::cout<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<"MC dE/dX Quadrant 4"<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<std::endl;

// ============================================
// ==== Doing the Landau + Gaussian Fit =======
// ============================================
hMCdEdX->Fit(combined_mc_dedx,"R0LLi","0",0,50);

// #######################################
// ### Making a histogram from the fit ###
// #######################################
combined_mc_dedx->GetParameters(par_03);
combined_mc_dedx->SetRange(0,50);
TH1D* MCFit_histo = (TH1D*)combined_mc_dedx->GetHistogram();
MCFit_histo->SetFillColor(kCyan-9);
MCFit_histo->SetFillStyle(3002);
MCFit_histo->SetLineColor(kCyan-9);
MCFit_histo->SetLineWidth(2);


// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c05 = new TCanvas("c05", "dEdX Q4");
c05->SetTicks();
c05->SetFillColor(kWhite);


hMCdEdX->SetLineColor(kAzure+1);
hMCdEdX->SetLineStyle(0);
hMCdEdX->SetLineWidth(3);


hDatadEdX->SetLineColor(kGray+2);
hDatadEdX->SetLineStyle(0);
hDatadEdX->SetLineWidth(1);
hDatadEdX->SetMarkerStyle(8);
hDatadEdX->SetMarkerSize(0.7);
hDatadEdX->SetMarkerColor(kGray+2);


// ### Drawing the histograms ###
hMCdEdX->Draw("histo");
dataFit_histo->Draw("Csames");
MCFit_histo->Draw("Csames");
hDatadEdX->Draw("E1same");


// ############################
// # Setting the Latex Header #
// ############################
//TLatex *t = new TLatex();
t->SetNDC();
t->SetTextFont(62);
t->SetTextSize(0.04);
t->SetTextAlign(40);
t->DrawLatex(0.1,0.90,"LArIAT Preliminary");
t->DrawLatex(0.13,0.84,""); 


//TLegend *leg = new TLegend();
leg = new TLegend(0.58,0.65,0.88,0.88);
leg->SetTextSize(0.04);
leg->SetTextAlign(12);
leg->SetFillColor(kWhite);
leg->SetLineColor(kWhite);
leg->SetShadowColor(kWhite);
leg->SetHeader("LArIAT Run-I");
leg->AddEntry(hDatadEdX,"Data");
leg->AddEntry(hMCdEdX,"#pi^{-} MC"); 
leg->AddEntry(dataFit_histo,"Data Fit: MPV = 2.08 #sigma 0.38");
leg->AddEntry(MCFit_histo," MC  Fit: MPV = 1.82 #sigma 0.26");
leg->Draw();































//--------------------------------------------------------------------------------------------------------------
//						dQ/dX Plots
//--------------------------------------------------------------------------------------------------------------

// ### Getting the data dQ/dX plot ###
TH1F *hDatadQdX = (TH1F*)f1->Get("hdatadQdX");

// ### Labeling the axis ###
hDatadQdX->GetXaxis()->SetTitle("dQ/dX (ADC / cm)");
hDatadQdX->GetXaxis()->CenterTitle();

hDatadQdX->GetYaxis()->SetTitle("Events / 0.25 ADC/cm");
hDatadQdX->GetYaxis()->CenterTitle(); 

// ### Getting the MC dQ/dX plot ###
TH1F *hMCdQdX = (TH1F*)f2->Get("hMCRecodQdX");

// ### Labeling the axis ###
hMCdQdX->GetXaxis()->SetTitle("dQ/dX (ADC / cm)");
hMCdQdX->GetXaxis()->CenterTitle();

hDatadQdX->GetYaxis()->SetTitle("Events / 0.25 ADC/cm");
hDatadQdX->GetYaxis()->CenterTitle(); 

// ### Normalizing MC to Data ###
double MCIntegral = hMCdQdX->Integral();
double DataIntegral = hDatadQdX->Integral();

double scaleMC = DataIntegral/MCIntegral;


// ==================================================
// == Initializing the parameters which record the ==
// == fit parameters (3 for gaussian 3 for landau) ==
// ==================================================
Double_t par_03[6];
TF1 *data_dqdx_landau = new TF1("data_dqdx_landau","gaus",0, 14000);
TF1 *combined_data_dqdx   = new TF1("combined_data_dqdx","landau+gaus",0,14000);
//TF1 *combined_data_dqdx   = new TF1("combined_data_dqdx","gaus",0,14000);


TF1 *mc_dqdx_landau   = new TF1("mc_dqdx_landau","landau",0, 14000);
TF1 *combined_mc_dqdx   = new TF1("combined_mc_dqdx","landau+gaus",0,14000);
//TF1 *combined_mc_dqdx   = new TF1("combined_mc_dqdx","gaus",0,14000);


// ### Scaling MC ###
hMCdQdX->Sumw2();
hMCdQdX->Scale(scaleMC);

// ### Fitting the data dQ/dX with Landau as a seed ###
hDatadQdX->Fit(data_dqdx_landau,"R+0LLi","0",2000, 3000);

// ### Get the seed parameters for the Landau+Gaus fit ###
data_dqdx_landau->GetParameters(&par_03[0]); //<---Getting parameters from fit 0,1,2


// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_data_dqdx->SetParameters(par_03);
//combined_data_dqdx->FixParameter(1,par_03[1]);


// ============================================
// ==== Doing the Landau + Gaussian Fit =======
// ============================================

std::cout<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<"Data dQ/dX All"<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<std::endl;

hDatadQdX->Fit(combined_data_dqdx,"R0LLi","0",0,14000);

// #######################################
// ### Making a histogram from the fit ###
// #######################################
combined_data_dqdx->GetParameters(par_03);
combined_data_dqdx->SetRange(0,14000);
TH1D* dataFit_histo = (TH1D*)combined_data_dqdx->GetHistogram();
dataFit_histo->SetFillColor(kBlack);
dataFit_histo->SetFillStyle(3013);
dataFit_histo->SetLineColor(kBlack);
dataFit_histo->SetLineWidth(2);


// ### Fitting the MC dQ/dX with Landau as a seed ###
hMCdQdX->Fit(mc_dqdx_landau,"R+0LLi","0",0 , 14000);

// ### Get the seed parameters for the Landau+Gaus fit ###
mc_dqdx_landau->GetParameters(&par_03[0]); //<---Getting parameters from fit 0,1,2

// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_mc_dqdx->SetParameters(par_03);
//combined_mc_dqdx->SetParLimits(0,0,900000);


std::cout<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<"MC dQ/dX Total"<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<std::endl;

// ============================================
// ==== Doing the Landau + Gaussian Fit =======
// ============================================
hMCdQdX->Fit(combined_mc_dqdx,"R0LLi","0",0,14000);

// #######################################
// ### Making a histogram from the fit ###
// #######################################
combined_mc_dqdx->GetParameters(par_03);
combined_mc_dqdx->SetRange(0,14000);
TH1D* MCFit_histo = (TH1D*)combined_mc_dqdx->GetHistogram();
MCFit_histo->SetFillColor(kPink+8);
MCFit_histo->SetFillStyle(3002);
MCFit_histo->SetLineColor(kPink+8);
MCFit_histo->SetLineWidth(2);


// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c06 = new TCanvas("c06", "dQdX Total");
c06->SetTicks();
c06->SetFillColor(kWhite);


hMCdQdX->SetLineColor(kRed);
hMCdQdX->SetLineStyle(0);
hMCdQdX->SetLineWidth(3);

hDatadQdX->SetLineColor(kBlack);
hDatadQdX->SetLineStyle(0);
hDatadQdX->SetLineWidth(1);
hDatadQdX->SetMarkerStyle(8);
hDatadQdX->SetMarkerSize(0.7);

// ### Drawing the histograms ###
hDatadQdX->Draw("E1");
hMCdQdX->Draw("histosames");
dataFit_histo->Draw("Csames");
MCFit_histo->Draw("Csames");



// ############################
// # Setting the Latex Header #
// ############################
TLatex *t = new TLatex();
t->SetNDC();
t->SetTextFont(62);
t->SetTextSize(0.04);
t->SetTextAlign(40);
t->DrawLatex(0.1,0.90,"LArIAT Preliminary");
t->DrawLatex(0.13,0.84,""); 


TLegend *leg = new TLegend();
leg = new TLegend(0.58,0.65,0.88,0.88);
leg->SetTextSize(0.04);
leg->SetTextAlign(12);
leg->SetFillColor(kWhite);
leg->SetLineColor(kWhite);
leg->SetShadowColor(kWhite);
leg->SetHeader("LArIAT Run-I");
leg->AddEntry(hDatadQdX,"Data");
leg->AddEntry(hMCdQdX,"#pi^{-} MC"); 
leg->AddEntry(dataFit_histo,"Data Fit: MPV = 2571 #sigma 566");
leg->AddEntry(MCFit_histo," MC  Fit: MPV = 4472 #sigma 592");
leg->Draw();







//--------------------------------------------------------------------------------------------------------------
//						dQ/dX Plot Quadrant 1
//--------------------------------------------------------------------------------------------------------------

// ### Getting the data dQ/dX plot ###
TH1F *hDatadQdX = (TH1F*)f1->Get("hdatadQdXQ1");

// ### Labeling the axis ###
hDatadQdX->GetXaxis()->SetTitle("dQ/dX (ADC / cm)");
hDatadQdX->GetXaxis()->CenterTitle();

hDatadQdX->GetYaxis()->SetTitle("Events / 0.25 ADC/cm");
hDatadQdX->GetYaxis()->CenterTitle(); 

// ### Getting the MC dQ/dX plot ###
TH1F *hMCdQdX = (TH1F*)f2->Get("hMCRecodQdXQ1");

// ### Labeling the axis ###
hMCdQdX->GetXaxis()->SetTitle("dQ/dX (ADC / cm)");
hMCdQdX->GetXaxis()->CenterTitle();

hDatadQdX->GetYaxis()->SetTitle("Events / 0.25 ADC/cm");
hDatadQdX->GetYaxis()->CenterTitle(); 

// ### Normalizing MC to Data ###
double MCIntegral = hMCdQdX->Integral();
double DataIntegral = hDatadQdX->Integral();

double scaleMC = DataIntegral/MCIntegral;


// ==================================================
// == Initializing the parameters which record the ==
// == fit parameters (3 for gaussian 3 for landau) ==
// ==================================================
Double_t par_03[6];
TF1 *data_dqdx_landau = new TF1("data_dqdx_landau","gaus",0, 14000);
TF1 *combined_data_dqdx   = new TF1("combined_data_dqdx","landau+gaus",0,14000);
//TF1 *combined_data_dqdx   = new TF1("combined_data_dqdx","gaus",0,14000);


TF1 *mc_dqdx_landau   = new TF1("mc_dqdx_landau","landau",0, 14000);
TF1 *combined_mc_dqdx   = new TF1("combined_mc_dqdx","landau+gaus",0,14000);
//TF1 *combined_mc_dqdx   = new TF1("combined_mc_dqdx","gaus",0,14000);


// ### Scaling MC ###
hMCdQdX->Sumw2();
hMCdQdX->Scale(scaleMC);

// ### Fitting the data dQ/dX with Landau as a seed ###
hDatadQdX->Fit(data_dqdx_landau,"R+0LLi","0",2000, 3000);

// ### Get the seed parameters for the Landau+Gaus fit ###
data_dqdx_landau->GetParameters(&par_03[0]); //<---Getting parameters from fit 0,1,2


// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_data_dqdx->SetParameters(par_03);
//combined_data_dqdx->FixParameter(1,par_03[1]);


// ============================================
// ==== Doing the Landau + Gaussian Fit =======
// ============================================

std::cout<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<"Data dQ/dX Q1"<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<std::endl;

hDatadQdX->Fit(combined_data_dqdx,"R0LLi","0",0,14000);

// #######################################
// ### Making a histogram from the fit ###
// #######################################
combined_data_dqdx->GetParameters(par_03);
combined_data_dqdx->SetRange(0,14000);
TH1D* dataFit_histo = (TH1D*)combined_data_dqdx->GetHistogram();
dataFit_histo->SetFillColor(kBlack);
dataFit_histo->SetFillStyle(3013);
dataFit_histo->SetLineColor(kBlack);
dataFit_histo->SetLineWidth(2);


// ### Fitting the MC dQ/dX with Landau as a seed ###
hMCdQdX->Fit(mc_dqdx_landau,"R+0LLi","0",0 , 14000);

// ### Get the seed parameters for the Landau+Gaus fit ###
mc_dqdx_landau->GetParameters(&par_03[0]); //<---Getting parameters from fit 0,1,2

// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_mc_dqdx->SetParameters(par_03);
//combined_mc_dqdx->SetParLimits(0,0,900000);


std::cout<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<"MC dQ/dX Q1"<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<std::endl;

// ============================================
// ==== Doing the Landau + Gaussian Fit =======
// ============================================
hMCdQdX->Fit(combined_mc_dqdx,"R0LLi","0",0,14000);

// #######################################
// ### Making a histogram from the fit ###
// #######################################
combined_mc_dqdx->GetParameters(par_03);
combined_mc_dqdx->SetRange(0,14000);
TH1D* MCFit_histo = (TH1D*)combined_mc_dqdx->GetHistogram();
MCFit_histo->SetFillColor(kPink+8);
MCFit_histo->SetFillStyle(3002);
MCFit_histo->SetLineColor(kPink+8);
MCFit_histo->SetLineWidth(2);


// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c07 = new TCanvas("c07", "dQdX Q1");
c07->SetTicks();
c07->SetFillColor(kWhite);


hMCdQdX->SetLineColor(kRed);
hMCdQdX->SetLineStyle(0);
hMCdQdX->SetLineWidth(3);

hDatadQdX->SetLineColor(kBlack);
hDatadQdX->SetLineStyle(0);
hDatadQdX->SetLineWidth(1);
hDatadQdX->SetMarkerStyle(8);
hDatadQdX->SetMarkerSize(0.7);

// ### Drawing the histograms ###
hDatadQdX->Draw("E1");
hMCdQdX->Draw("histosames");
dataFit_histo->Draw("Csames");
MCFit_histo->Draw("Csames");



// ############################
// # Setting the Latex Header #
// ############################
TLatex *t = new TLatex();
t->SetNDC();
t->SetTextFont(62);
t->SetTextSize(0.04);
t->SetTextAlign(40);
t->DrawLatex(0.1,0.90,"LArIAT Preliminary");
t->DrawLatex(0.13,0.84,""); 


TLegend *leg = new TLegend();
leg = new TLegend(0.58,0.65,0.88,0.88);
leg->SetTextSize(0.04);
leg->SetTextAlign(12);
leg->SetFillColor(kWhite);
leg->SetLineColor(kWhite);
leg->SetShadowColor(kWhite);
leg->SetHeader("LArIAT Run-I");
leg->AddEntry(hDatadQdX,"Data");
leg->AddEntry(hMCdQdX,"#pi^{-} MC"); 
leg->AddEntry(dataFit_histo,"Data Fit: MPV = 2486 #sigma 382");
leg->AddEntry(MCFit_histo," MC  Fit: MPV = 4420 #sigma 529");
leg->Draw();





//--------------------------------------------------------------------------------------------------------------
//						dQ/dX Plot Quadrant 2
//--------------------------------------------------------------------------------------------------------------

// ### Getting the data dQ/dX plot ###
TH1F *hDatadQdX = (TH1F*)f1->Get("hdatadQdXQ2");

// ### Labeling the axis ###
hDatadQdX->GetXaxis()->SetTitle("dQ/dX (ADC / cm)");
hDatadQdX->GetXaxis()->CenterTitle();

hDatadQdX->GetYaxis()->SetTitle("Events / 0.25 ADC/cm");
hDatadQdX->GetYaxis()->CenterTitle(); 

// ### Getting the MC dQ/dX plot ###
TH1F *hMCdQdX = (TH1F*)f2->Get("hMCRecodQdXQ2");

// ### Labeling the axis ###
hMCdQdX->GetXaxis()->SetTitle("dQ/dX (ADC / cm)");
hMCdQdX->GetXaxis()->CenterTitle();

hDatadQdX->GetYaxis()->SetTitle("Events / 0.25 ADC/cm");
hDatadQdX->GetYaxis()->CenterTitle(); 

// ### Normalizing MC to Data ###
double MCIntegral = hMCdQdX->Integral();
double DataIntegral = hDatadQdX->Integral();

double scaleMC = DataIntegral/MCIntegral;


// ==================================================
// == Initializing the parameters which record the ==
// == fit parameters (3 for gaussian 3 for landau) ==
// ==================================================
Double_t par_03[6];
TF1 *data_dqdx_landau = new TF1("data_dqdx_landau","gaus",0, 14000);
TF1 *combined_data_dqdx   = new TF1("combined_data_dqdx","landau+gaus",0,14000);
//TF1 *combined_data_dqdx   = new TF1("combined_data_dqdx","gaus",0,14000);


TF1 *mc_dqdx_landau   = new TF1("mc_dqdx_landau","landau",0, 14000);
TF1 *combined_mc_dqdx   = new TF1("combined_mc_dqdx","landau+gaus",0,14000);
//TF1 *combined_mc_dqdx   = new TF1("combined_mc_dqdx","gaus",0,14000);


// ### Scaling MC ###
hMCdQdX->Sumw2();
hMCdQdX->Scale(scaleMC);

// ### Fitting the data dQ/dX with Landau as a seed ###
hDatadQdX->Fit(data_dqdx_landau,"R+0LLi","0",2000, 3000);

// ### Get the seed parameters for the Landau+Gaus fit ###
data_dqdx_landau->GetParameters(&par_03[0]); //<---Getting parameters from fit 0,1,2


// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_data_dqdx->SetParameters(par_03);
//combined_data_dqdx->FixParameter(1,par_03[1]);


// ============================================
// ==== Doing the Landau + Gaussian Fit =======
// ============================================

std::cout<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<"Data dQ/dX Q2"<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<std::endl;

hDatadQdX->Fit(combined_data_dqdx,"R0LLi","0",0,14000);

// #######################################
// ### Making a histogram from the fit ###
// #######################################
combined_data_dqdx->GetParameters(par_03);
combined_data_dqdx->SetRange(0,14000);
TH1D* dataFit_histo = (TH1D*)combined_data_dqdx->GetHistogram();
dataFit_histo->SetFillColor(kBlack);
dataFit_histo->SetFillStyle(3013);
dataFit_histo->SetLineColor(kBlack);
dataFit_histo->SetLineWidth(2);


// ### Fitting the MC dQ/dX with Landau as a seed ###
hMCdQdX->Fit(mc_dqdx_landau,"R+0LLi","0",0 , 14000);

// ### Get the seed parameters for the Landau+Gaus fit ###
mc_dqdx_landau->GetParameters(&par_03[0]); //<---Getting parameters from fit 0,1,2

// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_mc_dqdx->SetParameters(par_03);
//combined_mc_dqdx->SetParLimits(0,0,900000);


std::cout<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<"MC dQ/dX Q2"<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<std::endl;

// ============================================
// ==== Doing the Landau + Gaussian Fit =======
// ============================================
hMCdQdX->Fit(combined_mc_dqdx,"R0LLi","0",0,14000);

// #######################################
// ### Making a histogram from the fit ###
// #######################################
combined_mc_dqdx->GetParameters(par_03);
combined_mc_dqdx->SetRange(0,14000);
TH1D* MCFit_histo = (TH1D*)combined_mc_dqdx->GetHistogram();
MCFit_histo->SetFillColor(kPink+8);
MCFit_histo->SetFillStyle(3002);
MCFit_histo->SetLineColor(kPink+8);
MCFit_histo->SetLineWidth(2);


// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c08 = new TCanvas("c08", "dQdX Q2");
c08->SetTicks();
c08->SetFillColor(kWhite);


hMCdQdX->SetLineColor(kRed);
hMCdQdX->SetLineStyle(0);
hMCdQdX->SetLineWidth(3);

hDatadQdX->SetLineColor(kBlack);
hDatadQdX->SetLineStyle(0);
hDatadQdX->SetLineWidth(1);
hDatadQdX->SetMarkerStyle(8);
hDatadQdX->SetMarkerSize(0.7);

// ### Drawing the histograms ###
hDatadQdX->Draw("E1");
hMCdQdX->Draw("histosames");
dataFit_histo->Draw("Csames");
MCFit_histo->Draw("Csames");



// ############################
// # Setting the Latex Header #
// ############################
TLatex *t = new TLatex();
t->SetNDC();
t->SetTextFont(62);
t->SetTextSize(0.04);
t->SetTextAlign(40);
t->DrawLatex(0.1,0.90,"LArIAT Preliminary");
t->DrawLatex(0.13,0.84,""); 


TLegend *leg = new TLegend();
leg = new TLegend(0.58,0.65,0.88,0.88);
leg->SetTextSize(0.04);
leg->SetTextAlign(12);
leg->SetFillColor(kWhite);
leg->SetLineColor(kWhite);
leg->SetShadowColor(kWhite);
leg->SetHeader("LArIAT Run-I");
leg->AddEntry(hDatadQdX,"Data");
leg->AddEntry(hMCdQdX,"#pi^{-} MC"); 
leg->AddEntry(dataFit_histo,"Data Fit: MPV = 2473 #sigma 647");
leg->AddEntry(MCFit_histo," MC  Fit: MPV = 4443 #sigma 543");
leg->Draw();





//--------------------------------------------------------------------------------------------------------------
//						dQ/dX Plot Quadrant 3
//--------------------------------------------------------------------------------------------------------------

// ### Getting the data dQ/dX plot ###
TH1F *hDatadQdX = (TH1F*)f1->Get("hdatadQdXQ3");

// ### Labeling the axis ###
hDatadQdX->GetXaxis()->SetTitle("dQ/dX (ADC / cm)");
hDatadQdX->GetXaxis()->CenterTitle();

hDatadQdX->GetYaxis()->SetTitle("Events / 0.25 ADC/cm");
hDatadQdX->GetYaxis()->CenterTitle(); 

// ### Getting the MC dQ/dX plot ###
TH1F *hMCdQdX = (TH1F*)f2->Get("hMCRecodQdXQ3");

// ### Labeling the axis ###
hMCdQdX->GetXaxis()->SetTitle("dQ/dX (ADC / cm)");
hMCdQdX->GetXaxis()->CenterTitle();

hDatadQdX->GetYaxis()->SetTitle("Events / 0.25 ADC/cm");
hDatadQdX->GetYaxis()->CenterTitle(); 

// ### Normalizing MC to Data ###
double MCIntegral = hMCdQdX->Integral();
double DataIntegral = hDatadQdX->Integral();

double scaleMC = DataIntegral/MCIntegral;


// ==================================================
// == Initializing the parameters which record the ==
// == fit parameters (3 for gaussian 3 for landau) ==
// ==================================================
Double_t par_03[6];
TF1 *data_dqdx_landau = new TF1("data_dqdx_landau","gaus",0, 14000);
TF1 *combined_data_dqdx   = new TF1("combined_data_dqdx","landau+gaus",0,14000);
//TF1 *combined_data_dqdx   = new TF1("combined_data_dqdx","gaus",0,14000);


TF1 *mc_dqdx_landau   = new TF1("mc_dqdx_landau","landau",0, 14000);
TF1 *combined_mc_dqdx   = new TF1("combined_mc_dqdx","landau+gaus",0,14000);
//TF1 *combined_mc_dqdx   = new TF1("combined_mc_dqdx","gaus",0,14000);


// ### Scaling MC ###
hMCdQdX->Sumw2();
hMCdQdX->Scale(scaleMC);

// ### Fitting the data dQ/dX with Landau as a seed ###
hDatadQdX->Fit(data_dqdx_landau,"R+0LLi","0",2000, 3000);

// ### Get the seed parameters for the Landau+Gaus fit ###
data_dqdx_landau->GetParameters(&par_03[0]); //<---Getting parameters from fit 0,1,2


// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_data_dqdx->SetParameters(par_03);
//combined_data_dqdx->FixParameter(1,par_03[1]);


// ============================================
// ==== Doing the Landau + Gaussian Fit =======
// ============================================

std::cout<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<"Data dQ/dX Q3"<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<std::endl;

hDatadQdX->Fit(combined_data_dqdx,"R0LLi","0",0,14000);

// #######################################
// ### Making a histogram from the fit ###
// #######################################
combined_data_dqdx->GetParameters(par_03);
combined_data_dqdx->SetRange(0,14000);
TH1D* dataFit_histo = (TH1D*)combined_data_dqdx->GetHistogram();
dataFit_histo->SetFillColor(kBlack);
dataFit_histo->SetFillStyle(3013);
dataFit_histo->SetLineColor(kBlack);
dataFit_histo->SetLineWidth(2);


// ### Fitting the MC dQ/dX with Landau as a seed ###
hMCdQdX->Fit(mc_dqdx_landau,"R+0LLi","0",0 , 14000);

// ### Get the seed parameters for the Landau+Gaus fit ###
mc_dqdx_landau->GetParameters(&par_03[0]); //<---Getting parameters from fit 0,1,2

// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_mc_dqdx->SetParameters(par_03);
//combined_mc_dqdx->SetParLimits(0,0,900000);


std::cout<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<"MC dQ/dX Q3"<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<std::endl;

// ============================================
// ==== Doing the Landau + Gaussian Fit =======
// ============================================
hMCdQdX->Fit(combined_mc_dqdx,"R0LLi","0",0,14000);

// #######################################
// ### Making a histogram from the fit ###
// #######################################
combined_mc_dqdx->GetParameters(par_03);
combined_mc_dqdx->SetRange(0,14000);
TH1D* MCFit_histo = (TH1D*)combined_mc_dqdx->GetHistogram();
MCFit_histo->SetFillColor(kPink+8);
MCFit_histo->SetFillStyle(3002);
MCFit_histo->SetLineColor(kPink+8);
MCFit_histo->SetLineWidth(2);


// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c09 = new TCanvas("c09", "dQdX Q3");
c09->SetTicks();
c09->SetFillColor(kWhite);


hMCdQdX->SetLineColor(kRed);
hMCdQdX->SetLineStyle(0);
hMCdQdX->SetLineWidth(3);

hDatadQdX->SetLineColor(kBlack);
hDatadQdX->SetLineStyle(0);
hDatadQdX->SetLineWidth(1);
hDatadQdX->SetMarkerStyle(8);
hDatadQdX->SetMarkerSize(0.7);

// ### Drawing the histograms ###
hDatadQdX->Draw("E1");
hMCdQdX->Draw("histosames");
dataFit_histo->Draw("Csames");
MCFit_histo->Draw("Csames");



// ############################
// # Setting the Latex Header #
// ############################
TLatex *t = new TLatex();
t->SetNDC();
t->SetTextFont(62);
t->SetTextSize(0.04);
t->SetTextAlign(40);
t->DrawLatex(0.1,0.90,"LArIAT Preliminary");
t->DrawLatex(0.13,0.84,""); 


TLegend *leg = new TLegend();
leg = new TLegend(0.58,0.65,0.88,0.88);
leg->SetTextSize(0.04);
leg->SetTextAlign(12);
leg->SetFillColor(kWhite);
leg->SetLineColor(kWhite);
leg->SetShadowColor(kWhite);
leg->SetHeader("LArIAT Run-I");
leg->AddEntry(hDatadQdX,"Data");
leg->AddEntry(hMCdQdX,"#pi^{-} MC"); 
leg->AddEntry(dataFit_histo,"Data Fit: MPV = 2545 #sigma 635");
leg->AddEntry(MCFit_histo," MC  Fit: MPV = 4482 #sigma 568");
leg->Draw();




//--------------------------------------------------------------------------------------------------------------
//						dQ/dX Plot Quadrant 4
//--------------------------------------------------------------------------------------------------------------

// ### Getting the data dQ/dX plot ###
TH1F *hDatadQdX = (TH1F*)f1->Get("hdatadQdXQ4");

// ### Labeling the axis ###
hDatadQdX->GetXaxis()->SetTitle("dQ/dX (ADC / cm)");
hDatadQdX->GetXaxis()->CenterTitle();

hDatadQdX->GetYaxis()->SetTitle("Events / 0.25 ADC/cm");
hDatadQdX->GetYaxis()->CenterTitle(); 

// ### Getting the MC dQ/dX plot ###
TH1F *hMCdQdX = (TH1F*)f2->Get("hMCRecodQdXQ4");

// ### Labeling the axis ###
hMCdQdX->GetXaxis()->SetTitle("dQ/dX (ADC / cm)");
hMCdQdX->GetXaxis()->CenterTitle();

hDatadQdX->GetYaxis()->SetTitle("Events / 0.25 ADC/cm");
hDatadQdX->GetYaxis()->CenterTitle(); 

// ### Normalizing MC to Data ###
double MCIntegral = hMCdQdX->Integral();
double DataIntegral = hDatadQdX->Integral();

double scaleMC = DataIntegral/MCIntegral;


// ==================================================
// == Initializing the parameters which record the ==
// == fit parameters (3 for gaussian 3 for landau) ==
// ==================================================
Double_t par_03[6];
TF1 *data_dqdx_landau = new TF1("data_dqdx_landau","gaus",0, 14000);
TF1 *combined_data_dqdx   = new TF1("combined_data_dqdx","landau+gaus",0,14000);
//TF1 *combined_data_dqdx   = new TF1("combined_data_dqdx","gaus",0,14000);


TF1 *mc_dqdx_landau   = new TF1("mc_dqdx_landau","landau",0, 14000);
TF1 *combined_mc_dqdx   = new TF1("combined_mc_dqdx","landau+gaus",0,14000);
//TF1 *combined_mc_dqdx   = new TF1("combined_mc_dqdx","gaus",0,14000);


// ### Scaling MC ###
hMCdQdX->Sumw2();
hMCdQdX->Scale(scaleMC);

// ### Fitting the data dQ/dX with Landau as a seed ###
hDatadQdX->Fit(data_dqdx_landau,"R+0LLi","0",2000, 3000);

// ### Get the seed parameters for the Landau+Gaus fit ###
data_dqdx_landau->GetParameters(&par_03[0]); //<---Getting parameters from fit 0,1,2


// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_data_dqdx->SetParameters(par_03);
//combined_data_dqdx->FixParameter(1,par_03[1]);


// ============================================
// ==== Doing the Landau + Gaussian Fit =======
// ============================================

std::cout<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<"Data dQ/dX Q4"<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<std::endl;

hDatadQdX->Fit(combined_data_dqdx,"R0LLi","0",0,14000);

// #######################################
// ### Making a histogram from the fit ###
// #######################################
combined_data_dqdx->GetParameters(par_03);
combined_data_dqdx->SetRange(0,14000);
TH1D* dataFit_histo = (TH1D*)combined_data_dqdx->GetHistogram();
dataFit_histo->SetFillColor(kBlack);
dataFit_histo->SetFillStyle(3013);
dataFit_histo->SetLineColor(kBlack);
dataFit_histo->SetLineWidth(2);


// ### Fitting the MC dQ/dX with Landau as a seed ###
hMCdQdX->Fit(mc_dqdx_landau,"R+0LLi","0",0 , 14000);

// ### Get the seed parameters for the Landau+Gaus fit ###
mc_dqdx_landau->GetParameters(&par_03[0]); //<---Getting parameters from fit 0,1,2

// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_mc_dqdx->SetParameters(par_03);
//combined_mc_dqdx->SetParLimits(0,0,900000);


std::cout<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<"MC dQ/dX Q4"<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<std::endl;

// ============================================
// ==== Doing the Landau + Gaussian Fit =======
// ============================================
hMCdQdX->Fit(combined_mc_dqdx,"R0LLi","0",0,14000);

// #######################################
// ### Making a histogram from the fit ###
// #######################################
combined_mc_dqdx->GetParameters(par_03);
combined_mc_dqdx->SetRange(0,14000);
TH1D* MCFit_histo = (TH1D*)combined_mc_dqdx->GetHistogram();
MCFit_histo->SetFillColor(kPink+8);
MCFit_histo->SetFillStyle(3002);
MCFit_histo->SetLineColor(kPink+8);
MCFit_histo->SetLineWidth(2);


// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c10 = new TCanvas("c10", "dQdX Q4");
c10->SetTicks();
c10->SetFillColor(kWhite);


hMCdQdX->SetLineColor(kRed);
hMCdQdX->SetLineStyle(0);
hMCdQdX->SetLineWidth(3);

hDatadQdX->SetLineColor(kBlack);
hDatadQdX->SetLineStyle(0);
hDatadQdX->SetLineWidth(1);
hDatadQdX->SetMarkerStyle(8);
hDatadQdX->SetMarkerSize(0.7);

// ### Drawing the histograms ###
hDatadQdX->Draw("E1");
hMCdQdX->Draw("histosames");
dataFit_histo->Draw("Csames");
MCFit_histo->Draw("Csames");



// ############################
// # Setting the Latex Header #
// ############################
TLatex *t = new TLatex();
t->SetNDC();
t->SetTextFont(62);
t->SetTextSize(0.04);
t->SetTextAlign(40);
t->DrawLatex(0.1,0.90,"LArIAT Preliminary");
t->DrawLatex(0.13,0.84,""); 


TLegend *leg = new TLegend();
leg = new TLegend(0.58,0.65,0.88,0.88);
leg->SetTextSize(0.04);
leg->SetTextAlign(12);
leg->SetFillColor(kWhite);
leg->SetLineColor(kWhite);
leg->SetShadowColor(kWhite);
leg->SetHeader("LArIAT Run-I");
leg->AddEntry(hDatadQdX,"Data");
leg->AddEntry(hMCdQdX,"#pi^{-} MC"); 
leg->AddEntry(dataFit_histo,"Data Fit: MPV = 2756 #sigma 478");
leg->AddEntry(MCFit_histo," MC  Fit: MPV = 4543 #sigma 653");
leg->Draw();


}
