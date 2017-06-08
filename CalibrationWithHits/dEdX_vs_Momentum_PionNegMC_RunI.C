{
#include <TFile.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <TMath.h>


double dEdX[21] = {0.};
double dEdXError[21] = {0.};

double binX[21] = {175, 225, 275, 325, 375, 425, 475, 525, 575, 625, 675, 725, 775, 825, 875, 925, 975, 1025, 1075, 1125, 1175};
//double binX[21] = {125, 175, 225, 275, 325, 375, 425, 475, 525, 575, 625, 675, 725, 775, 825, 875, 925, 975, 1025, 1075, 1125};
double binXError[21] = {0.};


double dEdXLessbin[11] = {0.};
double dEdXErrorLessbin[11] = {0.};

double binXLessbin[11] = {200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100};
double binXErrorLessbin[11] = {0.};

double MuonMomentum[49] = {27.42, 29.35, 31.16, 32.89, 34.53, 36.11, 39.09, 41.89, 44.53, 47.04, 51.77, 56.16, 62.3, 68.02, 76.86,
                           85.09, 92.85, 100.3, 107.4, 114.3, 121, 127.6, 140.3, 152.7, 164.7, 176.4, 199.4, 221.8, 254.6, 286.8,
                           339.6, 356.7, 391.7, 443.2, 494.5, 545.5, 596.4, 647.1, 697.7, 798.7, 899.5, 1000, 1101, 1301, 1502, 1803, 2103,
			   2604};
		       
double MuonMomentumError[49] = {0.};

double PionMomentum[49] = {35.646, 38.155, 40.508, 42.757, 44.889, 46.943, 50.817, 54.457, 57.889, 61.152, 67.301, 73.008, 80.99, 88.426,
                           99.918, 110.617, 120.705, 130.39, 139.62, 148.59, 157.3, 165.88, 182.39, 198.51, 214.11, 229.32, 259.22, 288.34,
                           330.98, 372.84, 441.48, 463.71, 509.21, 576.16, 642.85, 709.15, 775.32, 841.23, 907.01, 1038.31, 1169.35, 1300,
                           1431.3, 1691.3, 1952.6, 2343.9, 2733.9, 3385.2};
		       
double PionMomentumError[49] = {0.};

double TheorydEdXError[49] = {0.};
double TheorydEdX[49] = {12.72, 11.46, 10.46, 9.635, 8.949, 8.368, 7.435, 6.719, 6.15, 5.687, 4.979, 4.461, 3.902, 3.502, 3.042, 2.731,
                         2.508, 2.34, 2.21, 2.107, 2.023, 1.954, 1.848, 1.771, 1.713, 1.67, 1.609, 1.57, 1.536, 1.519, 1.508, 1.51, 1.51,
                         1.517, 1.526, 1.537, 1.548, 1.559, 1.57, 1.591, 1.61, 1.628, 1.645, 1.675, 1.7, 1.733, 1.761, 1.799};

			 

for(int a = 0; a < 11; a++){binXErrorLessbin[a] = 50.;}

for(int a = 0; a < 21; a++){binXError[a] = 25.;}


// ########################
// ### Collection Plane ###
// ########################
//TFile *f1 = new TFile("./TJCalibrationMethod_RunIPionMC_DefaultCollection_ThroughGoing.root");
//TFile *f1 = new TFile("./TJCalibrationMethod_RunIPionMC_0.098Collection_ThroughGoing.root");
//TFile *f1 = new TFile("./TJCalibrationMethod_RunIPionMC_0.101Collection_ThroughGoing.root");

//TFile *f1 = new TFile("./TJCalibrationMethod_RunIPionMC_DefaultCollection_notThroughGoing.root");
//TFile *f1 = new TFile("./TJCalibrationMethod_RunIPionMC_0.101Collection_notThroughGoing.root");
//TFile *f1 = new TFile("./TJCalibrationMethod_RunIPionMC_0.098Collection_notThroughGoing.root");

// #######################
// ### Induction Plane ###
// #######################
//TFile *f1 = new TFile("./TJCalibrationMethod_RunIPionMC_DefaultInduction_ThroughGoing.root");
//TFile *f1 = new TFile("./TJCalibrationMethod_RunIPionMC_0.077Induction_ThroughGoing.root");
//TFile *f1 = new TFile("./TJCalibrationMethod_RunIPionMC_0.087Induction_ThroughGoing.root");
//TFile *f1 = new TFile("./TJCalibrationMethod_RunIPionMC_0.105Induction_ThroughGoing.root");
//TFile *f1 = new TFile("./TJCalibrationMethod_RunIPionMC_0.097Induction_ThroughGoing.root");
TFile *f1 = new TFile("./TJCalibrationMethod_RunIPionMC_0.094Induction_ThroughGoing.root");

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h150_200 = (TH1F*)f1->Get("hdatadEdX_150_200");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h150_200->Fit(data_gaus,"R+0LLi","0",1.25, 3.00);

dEdX[0]       = data_gaus->GetParameter(1);
dEdXError[0]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h200_250 = (TH1F*)f1->Get("hdatadEdX_200_250");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h200_250->Fit(data_gaus,"R+0LLi","0",1.25, 3.00);

dEdX[1]       = data_gaus->GetParameter(1);
dEdXError[1]  = data_gaus->GetParError(1);


//==============================================================================
//==============================================================================
dEdXLessbin[0] = (dEdX[0] + dEdX[1]) / 2;
dEdXErrorLessbin[0] = sqrt( (dEdXError[0]*dEdXError[0])+(dEdXError[1]*dEdXError[1]));


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h250_300 = (TH1F*)f1->Get("hdatadEdX_250_300");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h250_300->Fit(data_gaus,"R+0LLi","0",1.25, 3.00);

dEdX[2]       = data_gaus->GetParameter(1);
dEdXError[2]  = data_gaus->GetParError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h300_350 = (TH1F*)f1->Get("hdatadEdX_300_350");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h300_350->Fit(data_gaus,"R+0LLi","0",1.25, 3.00);

dEdX[3]       = data_gaus->GetParameter(1);
dEdXError[3]  = data_gaus->GetParError(1);


//==============================================================================
//==============================================================================
dEdXLessbin[1] = (dEdX[2] + dEdX[3]) / 2;
dEdXErrorLessbin[1] = sqrt( (dEdXError[2]*dEdXError[2])+(dEdXError[3]*dEdXError[3]));


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h350_400 = (TH1F*)f1->Get("hdatadEdX_350_400");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h350_400->Fit(data_gaus,"R+0LLi","0",1.25, 5.25);

dEdX[4]       = data_gaus->GetParameter(1);
dEdXError[4]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h400_450 = (TH1F*)f1->Get("hdatadEdX_400_450");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h400_450->Fit(data_gaus,"R+0LLi","0",1.25, 3.0);

dEdX[5]       = data_gaus->GetParameter(1);
dEdXError[5]  = data_gaus->GetParError(1);


//==============================================================================
//==============================================================================
dEdXLessbin[2] = (dEdX[4] + dEdX[5]) / 2;
dEdXErrorLessbin[2] = sqrt( (dEdXError[4]*dEdXError[4])+(dEdXError[5]*dEdXError[5]));


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h450_500 = (TH1F*)f1->Get("hdatadEdX_450_500");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h450_500->Fit(data_gaus,"R+0LLi","0",1.25, 3.00);

dEdX[6]       = data_gaus->GetParameter(1);
dEdXError[6]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h500_550 = (TH1F*)f1->Get("hdatadEdX_500_550");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h500_550->Fit(data_gaus,"R+0LLi","0",1.25, 3.00);

dEdX[7]       = data_gaus->GetParameter(1);
dEdXError[7]  = data_gaus->GetParError(1);


//==============================================================================
//==============================================================================
dEdXLessbin[3] = (dEdX[6] + dEdX[7]) / 2;
dEdXErrorLessbin[3] = sqrt( (dEdXError[6]*dEdXError[6])+(dEdXError[7]*dEdXError[7]));


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h550_600 = (TH1F*)f1->Get("hdatadEdX_550_600");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h550_600->Fit(data_gaus,"R+0LLi","0",1.25, 3.00);

dEdX[8]       = data_gaus->GetParameter(1);
dEdXError[8]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h600_650 = (TH1F*)f1->Get("hdatadEdX_600_650");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h600_650->Fit(data_gaus,"R+0LLi","0",1.25, 3.00);

dEdX[9]       = data_gaus->GetParameter(1);
dEdXError[9]  = data_gaus->GetParError(1);


//==============================================================================
//==============================================================================
dEdXLessbin[4] = (dEdX[8] + dEdX[9]) / 2;
dEdXErrorLessbin[4] = sqrt( (dEdXError[8]*dEdXError[8])+(dEdXError[9]*dEdXError[9]) );

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h650_700 = (TH1F*)f1->Get("hdatadEdX_650_700");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h650_700->Fit(data_gaus,"R+0LLi","0",1.25, 3.00);

dEdX[10]       = data_gaus->GetParameter(1);
dEdXError[10]  = data_gaus->GetParError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h700_750 = (TH1F*)f1->Get("hdatadEdX_700_750");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h700_750->Fit(data_gaus,"R+0LLi","0",1.25, 3.00);

dEdX[11]       = data_gaus->GetParameter(1);
dEdXError[11]  = data_gaus->GetParError(1);


//==============================================================================
//==============================================================================
dEdXLessbin[5] = (dEdX[10] + dEdX[11]) / 2;
dEdXErrorLessbin[5] = sqrt( (dEdXError[10]*dEdXError[10])+(dEdXError[11]*dEdXError[11]));

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h750_800 = (TH1F*)f1->Get("hdatadEdX_750_800");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h750_800->Fit(data_gaus,"R+0LLi","0",1.25, 3.00);

dEdX[12]       = data_gaus->GetParameter(1);
dEdXError[12]  = data_gaus->GetParError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h800_850 = (TH1F*)f1->Get("hdatadEdX_800_850");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h800_850->Fit(data_gaus,"R+0LLi","0",1.25, 3.00);

dEdX[13]       = data_gaus->GetParameter(1);
dEdXError[13]  = data_gaus->GetParError(1);

//==============================================================================
//==============================================================================
dEdXLessbin[6] = (dEdX[12] + dEdX[13]) / 2;
dEdXErrorLessbin[6] = sqrt( (dEdXError[12]*dEdXError[12])+(dEdXError[13]*dEdXError[13]));


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h850_900 = (TH1F*)f1->Get("hdatadEdX_850_900");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h850_900->Fit(data_gaus,"R+0LLi","0",1.25, 3.00);

dEdX[14]       = data_gaus->GetParameter(1);
dEdXError[14]  = data_gaus->GetParError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h900_950 = (TH1F*)f1->Get("hdatadEdX_900_950");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h900_950->Fit(data_gaus,"R+0LLi","0",1.25, 3.00);

dEdX[15]       = data_gaus->GetParameter(1);
dEdXError[15]  = data_gaus->GetParError(1);

//==============================================================================
//==============================================================================
dEdXLessbin[7] = (dEdX[14] + dEdX[15]) / 2;
dEdXErrorLessbin[7] = sqrt( (dEdXError[14]*dEdXError[14])+(dEdXError[15]*dEdXError[15]));


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h950_1000 = (TH1F*)f1->Get("hdatadEdX_950_1000");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h950_1000->Fit(data_gaus,"R+0LLi","0",1.25, 3.00);

dEdX[16]       = data_gaus->GetParameter(1);
dEdXError[16]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h1000_1050 = (TH1F*)f1->Get("hdatadEdX_1000_1050");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h1000_1050->Fit(data_gaus,"R+0LLi","0",1.25, 3.00);

dEdX[17]       = data_gaus->GetParameter(1);
dEdXError[17]  = data_gaus->GetParError(1);

//==============================================================================
//==============================================================================
dEdXLessbin[8] = (dEdX[16] + dEdX[17]) / 2;
dEdXErrorLessbin[8] = sqrt( (dEdXError[16]*dEdXError[16])+(dEdXError[17]*dEdXError[17]));

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h1050_1100 = (TH1F*)f1->Get("hdatadEdX_1050_1100");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h1050_1100->Fit(data_gaus,"R+0LLi","0",1.25, 3.00);

dEdX[18]       = data_gaus->GetParameter(1);
dEdXError[18]  = data_gaus->GetParError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h1100_1150 = (TH1F*)f1->Get("hdatadEdX_1100_1150");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h1100_1150->Fit(data_gaus,"R+0LLi","0",1.25, 3.00);

dEdX[19]       = data_gaus->GetParameter(1);
dEdXError[19]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h1150_1200 = (TH1F*)f1->Get("hdatadEdX_1150_1200");
TF1 *data_gaus = new TF1("data_gaus","landau",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h1150_1200->Fit(data_gaus,"R+0LLi","0",1.25, 3.00);

dEdX[20]       = data_gaus->GetParameter(1);
dEdXError[20]  = data_gaus->GetParError(1);

//==============================================================================
//==============================================================================
dEdXLessbin[9] = (dEdX[18] + dEdX[19] + dEdX[20]) / 3;
dEdXErrorLessbin[9] = sqrt( (dEdXError[18]*dEdXError[18])+(dEdXError[19]*dEdXError[19]) + (dEdXError[20]*dEdXError[20]));


const Int_t n = 10;
const Int_t nn = 20;
const Int_t m = 49;
const Int_t o = 35;

// ### Finely binned Data ###
gr  = new TGraphErrors(n,binXLessbin,dEdXLessbin,binXErrorLessbin,dEdXErrorLessbin);
gr->SetFillColor(kWhite);
gr->SetFillStyle(3005);
gr->SetLineColor(kAzure+2);
gr->SetLineWidth(2);


// ### Less finely binned data ###
grFullBin  = new TGraphErrors(nn,binX,dEdX,binXError,dEdXError);
grFullBin->SetFillColor(kWhite);
grFullBin->SetFillStyle(3005);
grFullBin->SetLineColor(kAzure+2);
grFullBin->SetLineWidth(2);

// ### Muon Lines ###
grMuon = new TGraphErrors(m,MuonMomentum,TheorydEdX,MuonMomentumError,TheorydEdXError);
grMuon->SetFillColor(kWhite);
grMuon->SetFillStyle(3005);
grMuon->SetLineColor(kBlue);
grMuon->SetLineWidth(2);

grPion = new TGraphErrors(m,PionMomentum,TheorydEdX,PionMomentumError,TheorydEdXError);
grPion->SetFillColor(kWhite);
grPion->SetFillStyle(3005);
grPion->SetLineColor(kRed);
grPion->SetLineWidth(2);

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c01 = new TCanvas("c01", "Low bin data");
c01->SetTicks();
c01->SetFillColor(kWhite);

gr->Draw("AP");
grMuon->Draw("Csame");
grPion->Draw("Csame");

// ### Labeling the axis ###
gr->GetXaxis()->SetTitle("Momentum (MeV)");
gr->GetXaxis()->CenterTitle();

gr->GetYaxis()->SetTitle("dE/dX (MeV/cm)");
gr->GetYaxis()->CenterTitle();


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
leg->SetHeader("LArIAT Run-I Negative Polarity");
leg->AddEntry(gr,"Reconstructed #pi MC");
leg->AddEntry(grMuon,"Muon"); 
leg->AddEntry(grPion,"Pion");
leg->Draw();



// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c02 = new TCanvas("c02", "High bin data");
c02->SetTicks();
c02->SetFillColor(kWhite);

grFullBin->Draw("AP");
grMuon->Draw("Csame");
grPion->Draw("Csame");

// ### Labeling the axis ###
grFullBin->GetXaxis()->SetTitle("Momentum (MeV)");
grFullBin->GetXaxis()->CenterTitle();

grFullBin->GetYaxis()->SetTitle("dE/dX (MeV/cm)");
grFullBin->GetYaxis()->CenterTitle();

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
leg->SetHeader("LArIAT Run-I Negative Polarity");
leg->AddEntry(gr,"Reconstructed #pi MC");
leg->AddEntry(grMuon,"Muon"); 
leg->AddEntry(grPion,"Pion");
leg->Draw();

}//<---End File
