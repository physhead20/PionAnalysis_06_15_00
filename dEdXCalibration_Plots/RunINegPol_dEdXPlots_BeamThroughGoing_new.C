{

#include <TFile.h>
#include <TH1F.h>
#include <TCanvas.h>

// #######################
// ### Load Data Plots ###
// #######################
TFile *f1 = new TFile("../histoROOTfiles_forPlots/RunINegPolData_histos_noCorrections_ThroughGoingNotMatched.root");

// #################################################
// ### Load Beam Through-Going Monte Carlo Plots ###
// #################################################
TFile *f2 = new TFile("../histoROOTfiles_forPlots/PionMC_RunI_OutOfTheBox_ThroughGoing.root");



// ########################################################################
// ### Fix the Monte Carlo Low Energy parameters based on the data fits ###
// ### True  = Fix the parameters                                       ###
// ### False = Don't fix the parameters                                 ### 
// ########################################################################

bool FixTheParameter = true;


//--------------------------------------------------------------------------------------------------------------
//						dE/dX Plot Data Only
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


// ==================================================
// == Initializing the parameters which record the ==
// == fit parameters (3 for gaussian 3 for landau) ==
// ==================================================
Double_t landauData_parameters[6];
Double_t fullFitData_parameters[9];
TF1 *data_dedx_landau     = new TF1("data_dedx_landau","landau",0, 50);
TF1 *data_dedx_landaugaus = new TF1("data_dedx_landaugaus","landau+gaus",0, 50);
TF1 *data_dedx_gausLOW    = new TF1("data_dedx_gausLOW","gaus",0, 50);
TF1 *data_dqdx_gausdelta  = new TF1("data_dqdx_gausdelta","gaus",0, 50);
TF1 *combined_data_dedx   = new TF1("combined_data_dedx","landau+gaus(0)+gaus(3)+gaus(6)",0,50);


// 									LANDAU FIT
// !!!!! This is just used to seed the landau + gaussian fit so that we don't get crazy values !!!!!!!
//---------------------------------------------------------------------------------------------------------------------------------------------------
// ======================================
// === Getting a seed for the Landau ====
// ======================================
hDatadEdX->Fit(data_dedx_landau,"R+0i","0", 0.0, 20.0);
data_dedx_landau->GetParameters(&landauData_parameters[0]); //<---Getting parameters from fit 0,1,2
//----------------------------------------------------------------------------------------------------------------------------------------------------




//									LANDAU+GAUS (CONVOLVED)
//----------------------------------------------------------------------------------------------------------------------------------------------------
// ===========================================================
// === Using the seed to set for the convolved Landau+Gaus ===
// ===========================================================
data_dedx_landaugaus->SetParameters(landauData_parameters);
// ### Fitting the data dE/dX with Landau+Gaus ###
data_dedx_landaugaus->SetParLimits(0,0,900000);
data_dedx_landaugaus->SetParLimits(1,0,900000);

// !!! To fit the actual Landau portion of the function !!!
// !!!            I start the fit at 1 MeV/cm           !!!
hDatadEdX->Fit(data_dedx_landaugaus,"R+0i","0", 1.0, 50.0);

// ### Get the seed parameters for the Landau+Gaus fit ###
data_dedx_landau->GetParameters(&fullFitData_parameters[0]); //<---Getting parameters from fit 0,1,2
//----------------------------------------------------------------------------------------------------------------------------------------------------




//									LOW TAIL GAUSSIAN
//-----------------------------------------------------------------------------------------------------------------------------------------------------
data_dedx_gausLOW->SetParLimits(0,0,900000);
data_dedx_gausLOW->SetParLimits(1,0,2);

// !!! To only sample the "low tail" I fit in the region !!!
// !!!         of unphysical dE/dX below 1 MeV/cm        !!!

// ### Fitting the data dE/dX with Gaussian as a seed ###
hDatadEdX->Fit(data_dedx_gausLOW,"R+0iLL","0", 0, 1);


// ### Get the seed parameters for the Landau+Gaus fit ###
data_dedx_gausLOW->GetParameters(&fullFitData_parameters[3]); //<---Getting parameters from fit 0,1,2
//-----------------------------------------------------------------------------------------------------------------------------------------------------



data_dqdx_gausdelta->SetParLimits(0,0,900000);
data_dqdx_gausdelta->SetParLimits(1,2,6);
// ### Fitting the data dE/dX with Gaussian as a seed ###
hDatadEdX->Fit(data_dqdx_gausdelta,"R+0iLL","0", 2, 6);


// ### Get the seed parameters for the Landau+Gaus fit ###
data_dqdx_gausdelta->GetParameters(&fullFitData_parameters[6]); //<---Getting parameters from fit 0,1,2


// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_data_dedx->SetParameters(fullFitData_parameters);
// === Setting the Landau+Gaus Portion ===
combined_data_dedx->SetParLimits(0,0,900000);
combined_data_dedx->SetParLimits(1,0,900000);
combined_data_dedx->SetParLimits(2,0,900000);
// === Setting the low Gaus portion ===
combined_data_dedx->SetParLimits(3,0,900000);
//combined_data_dedx->SetParLimits(4,0,2.0);
combined_data_dedx->SetParLimits(5,0,900000);

// === Setting the delta-ray portion ===
combined_data_dedx->SetParLimits(6,0,900000);
//combined_data_dedx->SetParLimits(7,2,6);
combined_data_dedx->SetParLimits(8,0,900000);

combined_data_dedx->SetParName(0,"Landau+Gauss: Norm");
combined_data_dedx->SetParName(1,"Landau+Gauss: MPV");
combined_data_dedx->SetParName(2,"Landau+Gauss: Sigma");
combined_data_dedx->SetParName(3,"Gauss-low: Norm");
combined_data_dedx->SetParName(4,"Gauss-low: Mean");
combined_data_dedx->SetParName(5,"Gauss-low: RMS");
combined_data_dedx->SetParName(6,"Gauss-#delta: Norm");
combined_data_dedx->SetParName(7,"Gauss-#delta: Mean");
combined_data_dedx->SetParName(8,"Gauss-#delta: RMS");

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c01 = new TCanvas("c01", "dEdX");
c01->SetTicks();
c01->SetFillColor(kWhite);
c01->SetLogy();

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
combined_data_dedx->GetParameters(fullFitData_parameters);
data_dedx_landaugaus->SetParameters(&fullFitData_parameters[0]);
data_dedx_gausLOW->SetParameters(&fullFitData_parameters[3]);
data_dqdx_gausdelta->SetParameters(&fullFitData_parameters[6]);


// #######################################
// ### Making a histogram from the fit ###
// #######################################



TH1D *landau_histo1 = new TH1D("landau_histo1","landau_histo1",1000,0,50);
data_dedx_landaugaus->SetRange(0,50);
landau_histo1 = (TH1D*)data_dedx_landaugaus->GetHistogram();
landau_histo1->SetFillColor(kRed);
landau_histo1->SetFillStyle(3001);
landau_histo1->SetLineWidth(2);
landau_histo1->SetLineColor(kRed);
landau_histo1->SetMarkerColor(kRed);
landau_histo1->Draw("Csame");

TH1D *gaus_histo1 = new TH1D("gaus_histo1","gaus_histo1",1000,0,50);
data_dedx_gausLOW->SetRange(0,50);
gaus_histo1 = (TH1D*)data_dedx_gausLOW->GetHistogram();
gaus_histo1->SetFillColor(kAzure+2);
gaus_histo1->SetFillStyle(3002);
gaus_histo1->SetLineWidth(2);
gaus_histo1->SetLineColor(kAzure+2);
gaus_histo1->SetMarkerColor(kAzure+2);
gaus_histo1->Draw("Csame");

TH1D *delta_histo1 = new TH1D("delta_histo1","delta_histo1",1000,0,50);
data_dqdx_gausdelta->SetRange(0,50);
delta_histo1 = (TH1D*)data_dqdx_gausdelta->GetHistogram();
delta_histo1->SetFillColor(kBlue);
delta_histo1->SetFillStyle(3002);
delta_histo1->SetLineWidth(2);
delta_histo1->SetLineColor(kBlue);
delta_histo1->SetMarkerColor(kBlue);
delta_histo1->Draw("Csame");

// #######################################
// ### Making a histogram from the fit ###
// #######################################
TH1D *combined_histo1 = new TH1D("combined_histo1","combined_histo1",1000,0,50);
combined_data_dedx->SetRange(0,50);
combined_histo1 = (TH1D*)combined_data_dedx->GetHistogram();
combined_histo1->SetFillColor(kBlack);
combined_histo1->SetFillStyle(3007);
combined_histo1->SetLineColor(kBlack);
combined_histo1->SetLineWidth(2);
combined_histo1->Draw("Csames");


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
leg->AddEntry(combined_histo1,"Full Fit"); 
leg->AddEntry(gaus_histo1,"Gaussian_Low");
leg->AddEntry(delta_histo1,"Gaussian_#delta");
leg->AddEntry(landau_histo1,"Landau+Gauss");
leg->Draw();






//--------------------------------------------------------------------------------------------------------------
//						dE/dX Plot MC Only
//--------------------------------------------------------------------------------------------------------------


// ### Getting the data dE/dX plot ###
TH1F *hMCdEdX = (TH1F*)f2->Get("hRecoMCdEdX");

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
hMCdEdX->SetMarkerColor(kBlue);
hMCdEdX->SetLineStyle(0);
hMCdEdX->SetLineWidth(2);
hMCdEdX->SetMarkerStyle(8);
hMCdEdX->SetMarkerSize(0.8);


// ==================================================
// == Initializing the parameters which record the ==
// == fit parameters (3 for gaussian 3 for landau) ==
// ==================================================
Double_t landauMC_parameters[6];
Double_t fullFitMC_parameters[9];
TF1 *mc_dedx_landau     = new TF1("mc_dedx_landau","landau",0, 50);
TF1 *mc_dedx_landaugaus = new TF1("mc_dedx_landaugaus","landau+gaus",0, 50);
TF1 *mc_dedx_gausLOW    = new TF1("mc_dedx_gausLOW","gaus",0, 50);
TF1 *mc_dqdx_gausdelta  = new TF1("mc_dqdx_gausdelta","gaus",0, 50);
TF1 *combined_mc_dedx   = new TF1("combined_mc_dedx","landau+gaus(0)+gaus(3)+gaus(6)",0,50);


// 									LANDAU FIT
//---------------------------------------------------------------------------------------------------------------------------------------------------
// ======================================
// === Getting a seed for the Landau ====
// ======================================
hMCdEdX->Fit(mc_dedx_landau,"R+0i","0", 0.0, 20.0);
mc_dedx_landau->GetParameters(&landauMC_parameters[0]); //<---Getting parameters from fit 0,1,2
//----------------------------------------------------------------------------------------------------------------------------------------------------




//									LANDAU+GAUS (CONVOLVED)
//----------------------------------------------------------------------------------------------------------------------------------------------------
// ===========================================================
// === Using the seed to set for the convolved Landau+Gaus ===
// ===========================================================
mc_dedx_landaugaus->SetParameters(landauData_parameters);
// ### Fitting the data dE/dX with Landau+Gaus ###
mc_dedx_landaugaus->SetParLimits(0,0,900000);
mc_dedx_landaugaus->SetParLimits(1,0,900000);
hMCdEdX->Fit(mc_dedx_landaugaus,"R+0i","0", 0.0, 50.0);

// ### Get the seed parameters for the Landau+Gaus fit ###
mc_dedx_landau->GetParameters(&fullFitMC_parameters[0]); //<---Getting parameters from fit 0,1,2
//----------------------------------------------------------------------------------------------------------------------------------------------------




//									LOW TAIL GAUSSIAN
//-----------------------------------------------------------------------------------------------------------------------------------------------------
mc_dedx_gausLOW->SetParLimits(0,0,900000);
mc_dedx_gausLOW->SetParLimits(1,0,2);
// ### Fitting the data dE/dX with Gaussian as a seed ###
hMCdEdX->Fit(mc_dedx_gausLOW,"R+0iLL","0", 0, 1);


// ### Get the seed parameters for the Landau+Gaus fit ###
mc_dedx_gausLOW->GetParameters(&fullFitMC_parameters[3]); //<---Getting parameters from fit 0,1,2
//-----------------------------------------------------------------------------------------------------------------------------------------------------



mc_dqdx_gausdelta->SetParLimits(0,0,900000);
mc_dqdx_gausdelta->SetParLimits(1,2,6);
// ### Fitting the data dE/dX with Gaussian as a seed ###
hMCdEdX->Fit(mc_dqdx_gausdelta,"R+0iLL","0", 2, 6);


// ### Get the seed parameters for the Landau+Gaus fit ###
mc_dqdx_gausdelta->GetParameters(&fullFitMC_parameters[6]); //<---Getting parameters from fit 0,1,2


// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_mc_dedx->SetParameters(fullFitMC_parameters);
// === Setting the Landau+Gaus Portion ===
combined_mc_dedx->SetParLimits(0,0,900000);
combined_mc_dedx->SetParLimits(1,0,900000);
combined_mc_dedx->SetParLimits(2,0,900000);

// ====================================
// === Setting the low Gaus portion ===
// ====================================
if(FixTheParameter)
   {
   combined_mc_dedx->SetParLimits(3,0,fullFitData_parameters[3]);
   combined_mc_dedx->FixParameter(4,fullFitData_parameters[4]);
   combined_mc_dedx->FixParameter(5,fullFitData_parameters[5]);
   
   // === Setting the delta-ray portion ===
   combined_mc_dedx->SetParLimits(6,0,fullFitData_parameters[6]);
   combined_mc_dedx->FixParameter(7,fullFitData_parameters[7]);
   combined_mc_dedx->SetParLimits(8,0,fullFitData_parameters[8]);
   
   }//<---End Fixing Paramters

else
   {
   combined_mc_dedx->SetParLimits(3,0,900000);
   combined_mc_dedx->SetParLimits(4,0,900000);
   combined_mc_dedx->SetParLimits(5,0,900000);
   // === Setting the delta-ray portion ===
   combined_mc_dedx->SetParLimits(6,0,900000);
   //combined_data_dedx->SetParLimits(7,2,6);
   combined_mc_dedx->SetParLimits(8,0,900000);
   
   }//<---Not fixing parameters

// =====================================
// === Setting the delta-ray portion ===
// =====================================
combined_mc_dedx->SetParLimits(6,0,900000);
//combined_mc_dedx->SetParLimits(7,2,6);
combined_mc_dedx->SetParLimits(8,0,900000);

combined_mc_dedx->SetParName(0,"Landau+Gauss: Norm");
combined_mc_dedx->SetParName(1,"Landau+Gauss: MPV");
combined_mc_dedx->SetParName(2,"Landau+Gauss: Sigma");
combined_mc_dedx->SetParName(3,"Gauss-low: Norm");
combined_mc_dedx->SetParName(4,"Gauss-low: Mean");
combined_mc_dedx->SetParName(5,"Gauss-low: RMS");
combined_mc_dedx->SetParName(6,"Gauss-#delta: Norm");
combined_mc_dedx->SetParName(7,"Gauss-#delta: Mean");
combined_mc_dedx->SetParName(8,"Gauss-#delta: RMS");

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c02 = new TCanvas("c02", "dEdX");
c02->SetTicks();
c02->SetFillColor(kWhite);
c02->SetLogy();

hMCdEdX->Draw("E1");

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
combined_mc_dedx->GetParameters(fullFitMC_parameters);
mc_dedx_landaugaus->SetParameters(&fullFitMC_parameters[0]);
mc_dedx_gausLOW->SetParameters(&fullFitMC_parameters[3]);
mc_dqdx_gausdelta->SetParameters(&fullFitMC_parameters[6]);


// #######################################
// ### Making a histogram from the fit ###
// #######################################



TH1D *landau_histo1 = new TH1D("landau_histo1","landau_histo1",1000,0,50);
mc_dedx_landaugaus->SetRange(0,50);
landau_histo1 = (TH1D*)mc_dedx_landaugaus->GetHistogram();
landau_histo1->SetFillColor(kRed);
landau_histo1->SetFillStyle(3001);
landau_histo1->SetLineWidth(2);
landau_histo1->SetLineColor(kRed);
landau_histo1->SetMarkerColor(kRed);
landau_histo1->Draw("Csame");

TH1D *gaus_histo1 = new TH1D("gaus_histo1","gaus_histo1",1000,0,50);
mc_dedx_gausLOW->SetRange(0,50);
gaus_histo1 = (TH1D*)mc_dedx_gausLOW->GetHistogram();
gaus_histo1->SetFillColor(kAzure+2);
gaus_histo1->SetFillStyle(3002);
gaus_histo1->SetLineWidth(2);
gaus_histo1->SetLineColor(kAzure+2);
gaus_histo1->SetMarkerColor(kAzure+2);
gaus_histo1->Draw("Csame");

TH1D *delta_histo1 = new TH1D("delta_histo1","delta_histo1",1000,0,50);
mc_dqdx_gausdelta->SetRange(0,50);
delta_histo1 = (TH1D*)mc_dqdx_gausdelta->GetHistogram();
delta_histo1->SetFillColor(kBlue);
delta_histo1->SetFillStyle(3002);
delta_histo1->SetLineWidth(2);
delta_histo1->SetLineColor(kBlue);
delta_histo1->SetMarkerColor(kBlue);
delta_histo1->Draw("Csame");

// #######################################
// ### Making a histogram from the fit ###
// #######################################
TH1D *combined_histo1 = new TH1D("combined_histo1","combined_histo1",1000,0,50);
combined_mc_dedx->SetRange(0,50);
combined_histo1 = (TH1D*)combined_mc_dedx->GetHistogram();
combined_histo1->SetFillColor(kBlack);
combined_histo1->SetFillStyle(3007);
combined_histo1->SetLineColor(kBlack);
combined_histo1->SetLineWidth(2);
combined_histo1->Draw("Csames");


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
leg->AddEntry(hMCdEdX,"Cosmic MC");
leg->AddEntry(combined_histo1,"Full Fit"); 
leg->AddEntry(gaus_histo1,"Gaussian_Low");
leg->AddEntry(delta_histo1,"Gaussian_#delta");
leg->AddEntry(landau_histo1,"Landau+Gauss");
leg->Draw();





//--------------------------------------------------------------------------------------------------------------
//						Overlay Data and MC Plots
//--------------------------------------------------------------------------------------------------------------

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c03 = new TCanvas("c03", "dEdX overlay");
c03->SetTicks();
c03->SetFillColor(kWhite);
c03->SetLogy();


// ### Draw the data ###
hDatadEdX->Draw("E1");

// ### Draw the MC ###
hMCdEdX->Draw("histosame");































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
hMCdEdX->Scale(scaleMC);


// ==================================================
// == Initializing the parameters which record the ==
// == fit parameters (3 for gaussian 3 for landau) ==
// ==================================================
Double_t par_02[6];
TF1 *mc_dqdx_landau = new TF1("mc_dqdx_landau","landau",0, 50);
TF1 *mc_dqdx_gaus = new TF1("mc_dqdx_gaus","gaus",0, 50);
TF1 *combined_mc_dedx   = new TF1("combined_mc_dedx","landau(0)+gaus(3)",0,50);


// ### Fitting the data dE/dX with Landau as a seed ###
hMCdEdX->Fit(mc_dqdx_landau,"R+0i","0", 0.0, 10.0);

// ### Get the seed parameters for the Landau+Gaus fit ###
mc_dqdx_landau->GetParameters(&par_02[0]); //<---Getting parameters from fit 0,1,2


// ### Fitting the data dE/dX with Gaussian as a seed ###
hMCdEdX->Fit(mc_dqdx_gaus,"R+0i","0", 10.0, 25.0);


// ### Get the seed parameters for the Landau+Gaus fit ###
mc_dqdx_gaus->GetParameters(&par_02[3]); //<---Getting parameters from fit 3,4,5

// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_mc_dedx->SetParameters(par_02);
//combined_data_dedx->SetParLimits(1,1.8,1.94);
//combined_mc_dedx->SetParLimits(0,0,900000);
//combined_mc_dedx->SetParLimits(2,0,900000);
combined_mc_dedx->SetParLimits(3,par_03[3] - 50, par_03[3] + 50);
//combined_mc_dedx->SetParLimits(4,par_03[4] - 0.5 , par_03[4] + 0.5);
combined_mc_dedx->SetParLimits(5, par_03[5] - 0.2 , par_03[5] + 0.2);
//combined_mc_dedx->FixParameter(3,par_03[3]);
combined_mc_dedx->FixParameter(4,par_03[4]);
//combined_mc_dedx->FixParameter(5,par_03[5]);

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

hMCdEdX->Draw("C");

// ============================================
// ==== Doing the Landau + Gaussian Fit =======
// ============================================

std::cout<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<"MC dE/dX All"<<std::endl;
std::cout<<"======================================="<<std::endl;
std::cout<<std::endl;


// ### Fit the combined function ###
hMCdEdX->Fit(combined_mc_dedx,"R0i","0",0,50);


// === Inputting Parameters for Drawing Fits ====
combined_mc_dedx->GetParameters(par_02);
mc_dqdx_landau->SetParameters(&par_02[0]);
mc_dqdx_gaus->SetParameters(&par_02[3]);


// #######################################
// ### Making a histogram from the fit ###
// #######################################



TH1D *landau_histo2 = new TH1D("landau_histo2","landau_histo2",1000,0,50);
mc_dqdx_landau->SetRange(0,50);
landau_histo2 = (TH1D*)mc_dqdx_landau->GetHistogram();
landau_histo2->SetFillColor(kRed);
landau_histo2->SetFillStyle(3001);
landau_histo2->SetLineWidth(2);
landau_histo2->SetLineColor(kRed);
landau_histo2->SetMarkerColor(kRed);
landau_histo2->Draw("Csame");

TH1D *gaus_histo2 = new TH1D("gaus_histo2","gaus_histo2",1000,0,50);
mc_dqdx_gaus->SetRange(0,50);
gaus_histo2 = (TH1D*)mc_dqdx_gaus->GetHistogram();
gaus_histo2->SetFillColor(kBlue);
gaus_histo2->SetFillStyle(3002);
gaus_histo2->SetLineWidth(2);
gaus_histo2->SetLineColor(kBlue);
gaus_histo2->SetMarkerColor(kBlue);
gaus_histo2->Draw("Csame");

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


hMCdEdX->Draw("Csame");

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
leg->AddEntry(hMCdEdX,"Cosmic MC");
leg->AddEntry(combined_data_dedx,"Landau + Gaussian"); 
leg->AddEntry(gaus_histo1,"Gaussian");
leg->AddEntry(landau_histo1,"Landau");
leg->Draw();
*/

}
