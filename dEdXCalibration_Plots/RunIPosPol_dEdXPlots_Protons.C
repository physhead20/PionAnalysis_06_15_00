{

#include <TFile.h>
#include <TH1F.h>
#include <TCanvas.h>

// #######################
// ### Load Data Plots ###
// #######################
TFile *f1 = new TFile("../histoROOTfiles_forPlots/RunIPosPolData_histos_noCorrections_ProtonXSectionSample.root");

// #####################################
// ### Load Cosmic Monte Carlo Plots ###
// #####################################
//TFile *f2 = new TFile("../histoROOTfiles_forPlots/CosmicMC_histos_noCorrections.root");


//--------------------------------------------------------------------------------------------------------------
//						dE/dX Plot Data Only
//--------------------------------------------------------------------------------------------------------------


// ### Getting the data dE/dX plot ###
TH1F *hDatadEdX = (TH1F*)f1->Get("hStoppedProtondEdX");

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


// ==================================================
// == Initializing the parameters which record the ==
// == fit parameters (3 for gaussian 3 for landau) ==
// ==================================================
Double_t par_03[6];
TF1 *data_dqdx_landau = new TF1("data_dedx_landau","landau",0, 50);
TF1 *data_dqdx_gaus = new TF1("data_dedx_gaus","gaus",0, 50);
TF1 *combined_data_dedx   = new TF1("combined_data_dedx","landau(0)+gaus(3)",0,50);


// ### Fitting the data dE/dX with Landau as a seed ###
hDatadEdX->Fit(data_dedx_landau,"R+0i","0", 1.0, 10.0);

// ### Get the seed parameters for the Landau+Gaus fit ###
data_dedx_landau->GetParameters(&par_03[0]); //<---Getting parameters from fit 0,1,2


// ### Fitting the data dE/dX with Gaussian as a seed ###
hDatadEdX->Fit(data_dedx_gaus,"R+0iLL","0", 0.0, 25.0);


// ### Get the seed parameters for the Landau+Gaus fit ###
data_dedx_gaus->GetParameters(&par_03[3]); //<---Getting parameters from fit 0,1,2

// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_data_dedx->SetParameters(par_03);
//combined_data_dedx->SetParLimits(1,1.8,1.94);
combined_data_dedx->SetParLimits(3,0,900000);
//combined_data_dedx->SetParameter(4,1.8);
combined_data_dedx->SetParLimits(5,0,900000);

combined_data_dedx->SetParName(0,"Landau: Norm");
combined_data_dedx->SetParName(1,"Landau: MPV");
combined_data_dedx->SetParName(2,"Landau: Sigma");
combined_data_dedx->SetParName(3,"Gauss: Norm");
combined_data_dedx->SetParName(4,"Gauss: Mean");
combined_data_dedx->SetParName(5,"Gauss: RMS");


// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c01 = new TCanvas("c01", "dEdX");
c01->SetTicks();
c01->SetFillColor(kWhite);

hDatadEdX->Draw("E1");

// ============================================
// ==== Doing the Landau + Gaussian Fit =======
// ============================================

std::cout<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<"Data dE/dX All"<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<std::endl;

hDatadEdX->Fit(combined_data_dedx,"R0i","0",0,50);


// === Inputting Parameters for Drawing Fits ====
combined_data_dedx->GetParameters(par_03);
data_dqdx_landau->SetParameters(&par_03[0]);
data_dqdx_gaus->SetParameters(&par_03[3]);


// #######################################
// ### Making a histogram from the fit ###
// #######################################



TH1D *landau_histo1 = new TH1D("landau_histo1","landau_histo1",1000,0,50);
data_dqdx_gaus->SetRange(0,50);
landau_histo1 = (TH1D*)data_dqdx_gaus->GetHistogram();
landau_histo1->SetFillColor(kRed);
landau_histo1->SetFillStyle(3001);
landau_histo1->SetLineWidth(2);
landau_histo1->SetLineColor(kRed);
landau_histo1->SetMarkerColor(kRed);
landau_histo1->Draw("Csame");

TH1D *gaus_histo1 = new TH1D("gaus_histo1","gaus_histo1",1000,0,50);
data_dqdx_landau->SetRange(0,50);
gaus_histo1 = (TH1D*)data_dqdx_landau->GetHistogram();
gaus_histo1->SetFillColor(kBlue);
gaus_histo1->SetFillStyle(3002);
gaus_histo1->SetLineWidth(2);
gaus_histo1->SetLineColor(kBlue);
gaus_histo1->SetMarkerColor(kBlue);
gaus_histo1->Draw("Csame");

// #######################################
// ### Making a histogram from the fit ###
// #######################################
combined_data_dedx->GetParameters(par_03);
combined_data_dedx->SetRange(0,50);
TH1D* dataFit_histo = (TH1D*)combined_data_dedx->GetHistogram();
combined_data_dedx->SetFillColor(kBlack);
combined_data_dedx->SetFillStyle(3007);
combined_data_dedx->SetLineColor(kBlack);
combined_data_dedx->SetLineWidth(2);
combined_data_dedx->Draw("Csames");


hDatadEdX->Draw("E1same");

c01->Update();
gPad->RedrawAxis();


TLegend *leg = new TLegend();
leg = new TLegend(0.58,0.65,0.88,0.88);
leg->SetTextSize(0.04);
leg->SetTextAlign(12);
leg->SetFillColor(kWhite);
leg->SetLineColor(kWhite);
leg->SetShadowColor(kWhite);
leg->SetHeader("LArIAT Run-I");
leg->AddEntry(hDatadEdX,"Cosmic Data");
leg->AddEntry(combined_data_dedx,"Landau + Gaussian"); 
leg->AddEntry(gaus_histo1,"Gaussian");
leg->AddEntry(landau_histo1,"Landau");
leg->Draw();

/*




//--------------------------------------------------------------------------------------------------------------
//						dE/dX Plot MC Only
//--------------------------------------------------------------------------------------------------------------


// ### Getting the data dE/dX plot ###
TH1F *hMCdEdX = (TH1F*)f2->Get("hMCRecodEdX");

// ### Labeling the axis ###
hMCdEdX->GetXaxis()->SetTitle("dE/dX (MeV / cm)");
hMCdEdX->GetXaxis()->CenterTitle();

hMCdEdX->GetYaxis()->SetTitle("Events / 0.25 MeV/cm");
hMCdEdX->GetYaxis()->CenterTitle(); 


// ### Normalizing MC to Data ###
double MCIntegral = hMCdEdX->Integral();
double DataIntegral = hDatadEdX->Integral();

double scaleMC = DataIntegral/MCIntegral;

// ### Scaling MC ###
hMCdEdX->Sumw2();
hMCdEdX->Scale(scaleMC);

// ################################
// ### Formatting the histogram ###
// ################################
hMCdEdX->SetLineColor(kBlue);
hMCdEdX->SetLineStyle(0);
hMCdEdX->SetLineWidth(3);



// ==================================================
// == Initializing the parameters which record the ==
// == fit parameters (3 for gaussian 3 for landau) ==
// ==================================================
Double_t par_02[6];
TF1 *mc_dqdx_landau = new TF1("mc_dqdx_landau","landau",0, 50);
TF1 *mc_dqdx_gaus = new TF1("mc_dqdx_gaus","gaus",0, 50);
TF1 *combined_mc_dedx   = new TF1("combined_mc_dedx","landau(0)+gaus(3)",0,50);


// ### Fitting the data dE/dX with Landau as a seed ###
hMCdEdX->Fit(mc_dqdx_landau,"R+0i","0", 1.0, 10.0);

// ### Get the seed parameters for the Landau+Gaus fit ###
mc_dqdx_landau->GetParameters(&par_02[0]); //<---Getting parameters from fit 0,1,2


// ### Fitting the data dE/dX with Gaussian as a seed ###
hMCdEdX->Fit(mc_dqdx_gaus,"R+0iLL","0", 10.0, 25.0);


// ### Get the seed parameters for the Landau+Gaus fit ###
mc_dqdx_gaus->GetParameters(&par_02[3]); //<---Getting parameters from fit 0,1,2

// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_mc_dedx->SetParameters(par_02);
//combined_data_dedx->SetParLimits(1,1.8,1.94);
combined_mc_dedx->SetParLimits(3,par_03[3],900000);
combined_mc_dedx->SetParameter(4,par_03[4]);
combined_mc_dedx->SetParLimits(5,0,900000);

combined_mc_dedx->SetParName(0,"Landau: Norm");
combined_mc_dedx->SetParName(1,"Landau: MPV");
combined_mc_dedx->SetParName(2,"Landau: Sigma");
combined_mc_dedx->SetParName(3,"Gauss: Norm");
combined_mc_dedx->SetParName(4,"Gauss: Mean");
combined_mc_dedx->SetParName(5,"Gauss: RMS");


// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c02 = new TCanvas("c02", "dEdX");
c02->SetTicks();
c02->SetFillColor(kWhite);

hMCdEdX->Draw("");

// ============================================
// ==== Doing the Landau + Gaussian Fit =======
// ============================================

std::cout<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<"MC dE/dX All"<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<std::endl;

hMCdEdX->Fit(combined_mc_dedx,"R0i","0",0,50);


// === Inputting Parameters for Drawing Fits ====
combined_mc_dedx->GetParameters(par_02);
mc_dqdx_landau->SetParameters(&par_02[0]);
mc_dqdx_gaus->SetParameters(&par_02[3]);


// #######################################
// ### Making a histogram from the fit ###
// #######################################



TH1D *landau_histo2 = new TH1D("landau_histo2","landau_histo2",1000,0,50);
mc_dqdx_gaus->SetRange(0,50);
landau_histo2 = (TH1D*)mc_dqdx_gaus->GetHistogram();
landau_histo2->SetFillColor(kRed);
landau_histo2->SetFillStyle(3001);
landau_histo2->SetLineWidth(2);
landau_histo2->SetLineColor(kRed);
landau_histo2->SetMarkerColor(kRed);
landau_histo2->Draw("Csame");

TH1D *gaus_histo2 = new TH1D("gaus_histo2","gaus_histo2",1000,0,50);
mc_dqdx_landau->SetRange(0,50);
gaus_histo2 = (TH1D*)mc_dqdx_landau->GetHistogram();
gaus_histo2->SetFillColor(kBlue);
gaus_histo2->SetFillStyle(3002);
gaus_histo2->SetLineWidth(2);
gaus_histo2->SetLineColor(kBlue);
gaus_histo2->SetMarkerColor(kBlue);
gaus_histo1->Draw("Csame");

// #######################################
// ### Making a histogram from the fit ###
// #######################################
combined_mc_dedx->GetParameters(par_02);
combined_mc_dedx->SetRange(0,50);
TH1D* dataFit_histo = (TH1D*)combined_mc_dedx->GetHistogram();
combined_mc_dedx->SetFillColor(kBlack);
combined_mc_dedx->SetFillStyle(3007);
combined_mc_dedx->SetLineColor(kBlack);
combined_mc_dedx->SetLineWidth(2);
combined_mc_dedx->Draw("Csames");


hMCdEdX->Draw("E1same");

c02->Update();
gPad->RedrawAxis();


TLegend *leg = new TLegend();
leg = new TLegend(0.58,0.65,0.88,0.88);
leg->SetTextSize(0.04);
leg->SetTextAlign(12);
leg->SetFillColor(kWhite);
leg->SetLineColor(kWhite);
leg->SetShadowColor(kWhite);
leg->SetHeader("LArIAT Run-I");
leg->AddEntry(hDatadEdX,"Cosmic Data");
leg->AddEntry(combined_data_dedx,"Landau + Gaussian"); 
leg->AddEntry(gaus_histo1,"Gaussian");
leg->AddEntry(landau_histo1,"Landau");
leg->Draw();

*/
}
