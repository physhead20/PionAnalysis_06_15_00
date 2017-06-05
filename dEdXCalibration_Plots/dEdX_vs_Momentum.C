{
#include <TFile.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <TMath.h>


double dEdX[21] = {0.};
double dEdXError[21] = {0.};

double binX[21] = {175, 225, 275, 325, 375, 425, 475, 525, 575, 625, 675, 725, 775, 825, 875, 925, 975, 1025, 1075, 1125, 1175};
double binXError[21] = {0.};

double MuonMomentum[28] = {100.3, 107.4, 114.3, 121, 127.6, 140.3, 152.7, 164.7, 176.4, 199.4, 221.8, 254.6, 286.8, 339.6, 356.7, 
                       391.7, 443.2, 494.5, 545.5, 596.4, 647.1, 697.7, 798.7, 899.5, 1000, 1101, 1301, 1502};
		       
double MuonMomentumError[28] = {0.};

double MuonTheorydEdX[28] = {2.34, 2.21, 2.107, 2.023, 1.954, 1.848, 1.771, 1.713, 1.67, 1.609, 1.57, 1.536, 1.519, 1.508,
			 1.51, 1.51, 1.517, 1.526, 1.537, 1.548, 1.559, 1.57, 1.591, 1.61, 1.628, 1.645, 1.675, 1.7};
			 
double MuonTheorydEdXError[28] = {0.};	

double PionMomentum[28] = {130.39, 139.62, 148.59, 157.3, 165.88, 182.39, 198.51, 214.11, 229.32, 259.22, 288.34, 330.98, 372.84,
			   441.48, 463.71, 509.21, 576.16, 642.85, 709.15, 775.32, 841.23, 907.01, 1038.31, 1169.35, 1300, 1431.3,
			   1691.3, 1952.6};
		       
double PionMomentumError[28] = {0.};

double PionTheorydEdX[28] = {2.34, 2.21, 2.107, 2.023, 1.954, 1.848, 1.771, 1.713, 1.67, 1.609, 1.57, 1.536, 1.519, 1.508,
			 1.51, 1.51, 1.517, 1.526, 1.537, 1.548, 1.559, 1.57, 1.591, 1.61, 1.628, 1.645, 1.675, 1.7};
			 
double PionTheorydEdXError[28] = {0.};
	       

for(int a = 0; a < 21; a++){binXError[a] = 25.;}

TFile *f1 = new TFile("./CalibrationMethod.root");

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h150_200 = (TH1F*)f1->Get("hdatadEdX_150_200");
TF1 *data_gaus = new TF1("data_gaus","gaus",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h150_200->Fit(data_gaus,"R+0LLi","0",1, 2.25);

dEdX[0]       = data_gaus->GetParameter(1);
dEdXError[0]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h200_250 = (TH1F*)f1->Get("hdatadEdX_200_250");
TF1 *data_gaus = new TF1("data_gaus","gaus",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h200_250->Fit(data_gaus,"R+0LLi","0",1, 2.25);

dEdX[1]       = data_gaus->GetParameter(1);
dEdXError[1]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h250_300 = (TH1F*)f1->Get("hdatadEdX_250_300");
TF1 *data_gaus = new TF1("data_gaus","gaus",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h250_300->Fit(data_gaus,"R+0LLi","0",1, 2.25);

dEdX[2]       = data_gaus->GetParameter(1);
dEdXError[2]  = data_gaus->GetParError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h300_350 = (TH1F*)f1->Get("hdatadEdX_300_350");
TF1 *data_gaus = new TF1("data_gaus","gaus",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h300_350->Fit(data_gaus,"R+0LLi","0",1, 2.25);

dEdX[3]       = data_gaus->GetParameter(1);
dEdXError[3]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h350_400 = (TH1F*)f1->Get("hdatadEdX_350_400");
TF1 *data_gaus = new TF1("data_gaus","gaus",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h350_400->Fit(data_gaus,"R+0LLi","0",1, 2.25);

dEdX[4]       = data_gaus->GetParameter(1);
dEdXError[4]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h400_450 = (TH1F*)f1->Get("hdatadEdX_400_450");
TF1 *data_gaus = new TF1("data_gaus","gaus",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h400_450->Fit(data_gaus,"R+0LLi","0",1, 2.25);

dEdX[5]       = data_gaus->GetParameter(1);
dEdXError[5]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h450_500 = (TH1F*)f1->Get("hdatadEdX_450_500");
TF1 *data_gaus = new TF1("data_gaus","gaus",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h450_500->Fit(data_gaus,"R+0LLi","0",1, 2.25);

dEdX[6]       = data_gaus->GetParameter(1);
dEdXError[6]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h500_550 = (TH1F*)f1->Get("hdatadEdX_500_550");
TF1 *data_gaus = new TF1("data_gaus","gaus",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h500_550->Fit(data_gaus,"R+0LLi","0",1, 2.25);

dEdX[7]       = data_gaus->GetParameter(1);
dEdXError[7]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h550_600 = (TH1F*)f1->Get("hdatadEdX_550_600");
TF1 *data_gaus = new TF1("data_gaus","gaus",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h550_600->Fit(data_gaus,"R+0LLi","0",1, 2.25);

dEdX[8]       = data_gaus->GetParameter(1);
dEdXError[8]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h600_650 = (TH1F*)f1->Get("hdatadEdX_600_650");
TF1 *data_gaus = new TF1("data_gaus","gaus",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h600_650->Fit(data_gaus,"R+0LLi","0",1, 2.25);

dEdX[9]       = data_gaus->GetParameter(1);
dEdXError[9]  = data_gaus->GetParError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h650_700 = (TH1F*)f1->Get("hdatadEdX_650_700");
TF1 *data_gaus = new TF1("data_gaus","gaus",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h650_700->Fit(data_gaus,"R+0LLi","0",1, 2.25);

dEdX[10]       = data_gaus->GetParameter(1);
dEdXError[10]  = data_gaus->GetParError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h700_750 = (TH1F*)f1->Get("hdatadEdX_700_750");
TF1 *data_gaus = new TF1("data_gaus","gaus",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h700_750->Fit(data_gaus,"R+0LLi","0",1, 2.25);

dEdX[11]       = data_gaus->GetParameter(1);
dEdXError[11]  = data_gaus->GetParError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h750_800 = (TH1F*)f1->Get("hdatadEdX_750_800");
TF1 *data_gaus = new TF1("data_gaus","gaus",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h750_800->Fit(data_gaus,"R+0LLi","0",1, 2.25);

dEdX[12]       = data_gaus->GetParameter(1);
dEdXError[12]  = data_gaus->GetParError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h800_850 = (TH1F*)f1->Get("hdatadEdX_800_850");
TF1 *data_gaus = new TF1("data_gaus","gaus",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h800_850->Fit(data_gaus,"R+0LLi","0",1, 2.25);

dEdX[13]       = data_gaus->GetParameter(1);
dEdXError[13]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h850_900 = (TH1F*)f1->Get("hdatadEdX_850_900");
TF1 *data_gaus = new TF1("data_gaus","gaus",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h850_900->Fit(data_gaus,"R+0LLi","0",1, 2.25);

dEdX[14]       = data_gaus->GetParameter(1);
dEdXError[14]  = data_gaus->GetParError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h900_950 = (TH1F*)f1->Get("hdatadEdX_900_950");
TF1 *data_gaus = new TF1("data_gaus","gaus",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h900_950->Fit(data_gaus,"R+0LLi","0",1, 2.25);

dEdX[15]       = data_gaus->GetParameter(1);
dEdXError[15]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h950_1000 = (TH1F*)f1->Get("hdatadEdX_950_1000");
TF1 *data_gaus = new TF1("data_gaus","gaus",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h950_1000->Fit(data_gaus,"R+0LLi","0",1, 2.25);

dEdX[16]       = data_gaus->GetParameter(1);
dEdXError[16]  = data_gaus->GetParError(1);


//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h1000_1050 = (TH1F*)f1->Get("hdatadEdX_1000_1050");
TF1 *data_gaus = new TF1("data_gaus","gaus",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h1000_1050->Fit(data_gaus,"R+0LLi","0",1, 2.25);

dEdX[17]       = data_gaus->GetParameter(1);
dEdXError[17]  = data_gaus->GetParError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h1050_1100 = (TH1F*)f1->Get("hdatadEdX_1050_1100");
TF1 *data_gaus = new TF1("data_gaus","gaus",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h1050_1100->Fit(data_gaus,"R+0LLi","0",1, 2.25);

dEdX[18]       = data_gaus->GetParameter(1);
dEdXError[18]  = data_gaus->GetParError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h1100_1150 = (TH1F*)f1->Get("hdatadEdX_1100_1150");
TF1 *data_gaus = new TF1("data_gaus","gaus",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h1100_1150->Fit(data_gaus,"R+0LLi","0",1, 2.25);

dEdX[19]       = data_gaus->GetParameter(1);
dEdXError[19]  = data_gaus->GetParError(1);

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h1150_1200 = (TH1F*)f1->Get("hdatadEdX_1150_1200");
TF1 *data_gaus = new TF1("data_gaus","gaus",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h1150_1200->Fit(data_gaus,"R+0LLi","0",1, 2.25);

dEdX[20]       = data_gaus->GetParameter(1);
dEdXError[20]  = data_gaus->GetParError(1);

const Int_t n = 20;
const Int_t m = 28;
const Int_t o = 28;

gr  = new TGraphErrors(n,binX,dEdX,binXError,dEdXError);
gr1 = new TGraphErrors(m,MuonMomentum,MuonTheorydEdX,MuonMomentumError,MuonTheorydEdXError);
gr2 = new TGraphErrors(m,PionMomentum,PionTheorydEdX,PionMomentumError,PionTheorydEdXError);

gr->Draw("AP");
gr1->Draw("Csame");
gr2->Draw("Csame");
}//<---End File
