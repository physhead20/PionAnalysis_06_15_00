{
#include <TFile.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <TMath.h>


double dEdX[21] = {0.};
double dEdXError[21] = {0.};

double binX[21] = {175, 225, 275, 325, 375, 425, 475, 525, 575, 625, 675, 725, 775, 825, 875, 925, 975, 1025, 1075, 1125, 1175};
double binXError[21] = {0.};


double dEdXLessbin[11] = {0.};
double dEdXErrorLessbin[11] = {0.};

double binXLessbin[11] = {200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100};
double binXErrorLessbin[11] = {0.};

for(int a = 0; a < 11; a++){binXErrorLessbin[a] = 50.;}

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


//==============================================================================
//==============================================================================
dEdXLessbin[0] = (dEdX[0] + dEdX[1]) / 2;
dEdXErrorLessbin[0] = sqrt( (dEdXError[0]*dEdXError[0])+(dEdXError[1]*dEdXError[1]));


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


//==============================================================================
//==============================================================================
dEdXLessbin[1] = (dEdX[2] + dEdX[3]) / 2;
dEdXErrorLessbin[1] = sqrt( (dEdXError[2]*dEdXError[2])+(dEdXError[3]*dEdXError[3]));


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


//==============================================================================
//==============================================================================
dEdXLessbin[2] = (dEdX[4] + dEdX[5]) / 2;
dEdXErrorLessbin[2] = sqrt( (dEdXError[4]*dEdXError[4])+(dEdXError[5]*dEdXError[5]));


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


//==============================================================================
//==============================================================================
dEdXLessbin[3] = (dEdX[6] + dEdX[7]) / 2;
dEdXErrorLessbin[3] = sqrt( (dEdXError[6]*dEdXError[6])+(dEdXError[7]*dEdXError[7]));


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


//==============================================================================
//==============================================================================
dEdXLessbin[4] = (dEdX[8] + dEdX[9]) / 2;
dEdXErrorLessbin[4] = sqrt( (dEdXError[8]*dEdXError[8])+(dEdXError[9]*dEdXError[9]) );

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


//==============================================================================
//==============================================================================
dEdXLessbin[5] = (dEdX[10] + dEdX[11]) / 2;
dEdXErrorLessbin[5] = sqrt( (dEdXError[10]*dEdXError[10])+(dEdXError[11]*dEdXError[11]));

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

//==============================================================================
//==============================================================================
dEdXLessbin[6] = (dEdX[12] + dEdX[13]) / 2;
dEdXErrorLessbin[6] = sqrt( (dEdXError[12]*dEdXError[12])+(dEdXError[13]*dEdXError[13]));


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

//==============================================================================
//==============================================================================
dEdXLessbin[7] = (dEdX[14] + dEdX[15]) / 2;
dEdXErrorLessbin[7] = sqrt( (dEdXError[14]*dEdXError[14])+(dEdXError[15]*dEdXError[15]));


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

//==============================================================================
//==============================================================================
dEdXLessbin[8] = (dEdX[16] + dEdX[17]) / 2;
dEdXErrorLessbin[8] = sqrt( (dEdXError[16]*dEdXError[16])+(dEdXError[17]*dEdXError[17]));

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

//==============================================================================
//==============================================================================
dEdXLessbin[9] = (dEdX[18] + dEdX[19] + dEdX[20]) / 3;
dEdXErrorLessbin[9] = sqrt( (dEdXError[18]*dEdXError[18])+(dEdXError[19]*dEdXError[19]) + (dEdXError[20]*dEdXError[20]));

//------------------------------------------------------------------------------
// ### Getting the data dE/dX plot ###
TH1F *h1150_1200 = (TH1F*)f1->Get("hdatadEdX_1150_1200");
TF1 *data_gaus = new TF1("data_gaus","gaus",0, 50);
// ### Fitting the data dE/dX peak with Gaussian ###
h1150_1200->Fit(data_gaus,"R+0LLi","0",1, 2.25);

dEdX[20]       = data_gaus->GetParameter(1);
dEdXError[20]  = data_gaus->GetParError(1);

const Int_t n = 10;

gr = new TGraphErrors(n,binXLessbin,dEdXLessbin,binXErrorLessbin,dEdXErrorLessbin);
gr->Draw("AP");

}//<---End File
