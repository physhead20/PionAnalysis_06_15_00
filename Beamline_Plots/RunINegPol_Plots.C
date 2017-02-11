{

// #######################
// ### Load Data Plots ###
// #######################
TFile *f1 = new TFile("../histoROOTfiles_forPlots/RunINegPolData_histos_noCorrections_PionXSectionSample.root");

//--------------------------------------------------------------------------------------------------------------
//						Delta X WC-TPC Track
//--------------------------------------------------------------------------------------------------------------

// ### Getting the data Delta X plot ###
TH1F *hDataDeltaXMatch = (TH1F*)f1->Get("hdataDeltaWCTrkX");

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c01 = new TCanvas("c01", "Delta X");
c01->SetTicks();
c01->SetFillColor(kWhite);


// ################################
// ### Formatting the histogram ###
// ################################
hDataDeltaXMatch->SetLineColor(kBlack);
hDataDeltaXMatch->SetLineStyle(0);
hDataDeltaXMatch->SetLineWidth(3);
hDataDeltaXMatch->SetMarkerStyle(8);
hDataDeltaXMatch->SetMarkerSize(0.9);

// ### Labeling the axis ###
hDataDeltaXMatch->GetXaxis()->SetTitle("#DeltaX between WC/TPC Track (cm)");
hDataDeltaXMatch->GetXaxis()->CenterTitle();

hDataDeltaXMatch->GetYaxis()->SetTitle("Events / 0.5 cm");
hDataDeltaXMatch->GetYaxis()->CenterTitle();

// ######################################################################
// ### Calling the two gaussians I use to fit the different regions ###
// ######################################################################

// ==================================================
// == Initializing the parameters which record the ==
// ==     fit parameters (3 for each gaussian)     ==
// ==================================================
Double_t par_01[6];
TF1 *rightMatch_01 = new TF1("rightMatch_01","gaus",-6,6);
TF1 *wrongMatch_01 = new TF1("wrongMatch_01","gaus",-30,10);
TF1 *combined_01   = new TF1("combined_01","gaus(0)+gaus(3)",-30,30);

// ### Fitting the Right Match Data ###
hDataDeltaXMatch->Fit(rightMatch_01,"R+0LLi","0",-1.0, 4.5);
rightMatch_01->GetParameters(&par_01[0]); //<---Getting parameters from fit 0,1,2

hDataDeltaXMatch->Fit(wrongMatch_01,"R+0LLi","0",-30, 10);
wrongMatch_01->GetParameters(&par_01[3]); //<---Getting parameters from fit 0,1,2



// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_01->SetParameters(par_01);
combined_01->SetParLimits(4,-6,6);

combined_01->SetParName(0,"RM: Norm");
combined_01->SetParName(1,"RM: Mean");
combined_01->SetParName(2,"RM: RMS");
combined_01->SetParName(3,"WM: Norm");
combined_01->SetParName(4,"WM: Mean");
combined_01->SetParName(5,"WM: RMS");

// ### Drawing the histogram ###
hDataDeltaXMatch->Draw("E1");

hDataDeltaXMatch->Fit(combined_01,"R0LLi","0",-30,30);

// === Inputting Parameters for Drawing Fits ====
combined_01->GetParameters(par_01);
rightMatch_01->SetParameters(&par_01[0]);
wrongMatch_01->SetParameters(&par_01[3]);

combined_01->SetRange(-30,30);
TH1D* combined_histo = (TH1D*)combined_01->GetHistogram();
combined_histo->SetFillColor(kBlue);
combined_histo->SetFillStyle(3005);
combined_histo->SetLineColor(kBlue);
combined_histo->SetLineWidth(2);
combined_histo->Draw("Csames");

TH1D *wrong_histo1 = new TH1D("wrong_histo1","wrong_histo1",1000,-10,10);
wrongMatch_01->SetRange(-30,30);
wrong_histo1 = (TH1D*)wrongMatch_01->GetHistogram();
wrong_histo1->SetFillColor(kRed);
wrong_histo1->SetFillStyle(3005);
wrong_histo1->SetLineWidth(2);
wrong_histo1->SetLineColor(kRed);
wrong_histo1->SetMarkerColor(kRed);
wrong_histo1->Draw("Csame");

// ### Drawing the histogram ###
hDataDeltaXMatch->Draw("E1same");

c01->Update();
gPad->RedrawAxis();

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
leg->AddEntry(hDataDeltaXMatch,"Data");
leg->AddEntry(combined_histo,"Right Match"); 
leg->AddEntry(wrong_histo1,"Wrong Match");
leg->Draw();


//--------------------------------------------------------------------------------------------------------------
//						Delta Y WC-TPC Track
//--------------------------------------------------------------------------------------------------------------

// ### Getting the data Delta X plot ###
TH1F *hDataDeltaYMatch = (TH1F*)f1->Get("hdataDeltaWCTrkY");

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c02 = new TCanvas("c02", "Delta Y");
c02->SetTicks();
c02->SetFillColor(kWhite);


// ################################
// ### Formatting the histogram ###
// ################################
hDataDeltaYMatch->SetLineColor(kBlack);
hDataDeltaYMatch->SetLineStyle(0);
hDataDeltaYMatch->SetLineWidth(3);
hDataDeltaYMatch->SetMarkerStyle(8);
hDataDeltaYMatch->SetMarkerSize(0.9);

// ### Labeling the axis ###
hDataDeltaYMatch->GetXaxis()->SetTitle("#DeltaY between WC/TPC Track (cm)");
hDataDeltaYMatch->GetXaxis()->CenterTitle();

hDataDeltaYMatch->GetYaxis()->SetTitle("Events / 0.5 cm");
hDataDeltaYMatch->GetYaxis()->CenterTitle();

// ######################################################################
// ### Calling the two gaussians I use to fit the different regions ###
// ######################################################################

// ==================================================
// == Initializing the parameters which record the ==
// ==     fit parameters (3 for each gaussian)     ==
// ==================================================
Double_t par_02[6];
TF1 *rightMatch_02 = new TF1("rightMatch_02","gaus",-6,6);
TF1 *wrongMatch_02 = new TF1("wrongMatch_02","gaus",-30,10);
TF1 *combined_02   = new TF1("combined_02","gaus(0)+gaus(3)",-30,30);

// ### Fitting the Right Match Data ###
hDataDeltaYMatch->Fit(rightMatch_02,"R+0LLi","0",-1.0, 4.5);
rightMatch_02->GetParameters(&par_02[0]); //<---Getting parameters from fit 0,1,2

hDataDeltaYMatch->Fit(wrongMatch_02,"R+0LLi","0",-30, 10);
wrongMatch_02->GetParameters(&par_02[3]); //<---Getting parameters from fit 0,1,2



// ===============================================
// == Putting in parameters into combined plots ==
// ===============================================
combined_02->SetParameters(par_01);
combined_02->SetParLimits(4,-6,6);

combined_02->SetParName(0,"RM: Norm");
combined_02->SetParName(1,"RM: Mean");
combined_02->SetParName(2,"RM: RMS");
combined_02->SetParName(3,"WM: Norm");
combined_02->SetParName(4,"WM: Mean");
combined_02->SetParName(5,"WM: RMS");

// ### Drawing the histogram ###
hDataDeltaYMatch->Draw("E1");

hDataDeltaYMatch->Fit(combined_02,"R0LLi","0",-30,30);

// === Inputting Parameters for Drawing Fits ====
combined_02->GetParameters(par_02);
rightMatch_02->SetParameters(&par_02[0]);
wrongMatch_02->SetParameters(&par_02[3]);

combined_02->SetRange(-30,30);
TH1D* combined_histo2 = (TH1D*)combined_02->GetHistogram();
combined_histo2->SetFillColor(kBlue);
combined_histo2->SetFillStyle(3005);
combined_histo2->SetLineColor(kBlue);
combined_histo2->SetLineWidth(2);
combined_histo2->Draw("Csames");

TH1D *wrong_histo2 = new TH1D("wrong_histo2","wrong_histo1",1000,-10,10);
wrongMatch_02->SetRange(-30,30);
wrong_histo2 = (TH1D*)wrongMatch_02->GetHistogram();
wrong_histo2->SetFillColor(kRed);
wrong_histo2->SetFillStyle(3005);
wrong_histo2->SetLineWidth(2);
wrong_histo2->SetLineColor(kRed);
wrong_histo2->SetMarkerColor(kRed);
wrong_histo2->Draw("Csame");

// ### Drawing the histogram ###
hDataDeltaYMatch->Draw("E1same");

c02->Update();
gPad->RedrawAxis();

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
leg->SetHeader("LArIAT Run-I Negative Polarity");
leg->AddEntry(hDataDeltaYMatch,"Data");
leg->AddEntry(combined_histo2,"Right Match"); 
leg->AddEntry(wrong_histo2,"Wrong Match");
leg->Draw();

//--------------------------------------------------------------------------------------------------------------
//						Alpha
//--------------------------------------------------------------------------------------------------------------

// ### Getting the data Delta X plot ###
TH1F *hAlpha = (TH1F*)f1->Get("hdataAlpha");

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c03 = new TCanvas("c03", "Alpha");
c03->SetTicks();
c03->SetFillColor(kWhite);


// ################################
// ### Formatting the histogram ###
// ################################
hAlpha->SetLineColor(kBlack);
hAlpha->SetLineStyle(0);
hAlpha->SetLineWidth(3);
hAlpha->SetMarkerStyle(8);
hAlpha->SetMarkerSize(0.9);

// ### Labeling the axis ###
hAlpha->GetXaxis()->SetTitle("#alpha (Degrees)");
hAlpha->GetXaxis()->CenterTitle();

hAlpha->GetYaxis()->SetTitle("Events / Degree");
hAlpha->GetYaxis()->CenterTitle();

// ### Drawing the histogram ###
hAlpha->Draw("E1");


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

//--------------------------------------------------------------------------------------------------------------
//					TOF vs Pz
//--------------------------------------------------------------------------------------------------------------

// ### Getting the data Incident Kinetic Energy plot ###
TH2F *hTOFvsWCTrk = (TH2F*)f1->Get("hdataWCTrackMomentumVSTOF");

// ### Labeling the axis ###
hTOFvsWCTrk->GetXaxis()->SetTitle("WC Track Momentum (MeV)");
hTOFvsWCTrk->GetXaxis()->CenterTitle();

hTOFvsWCTrk->GetYaxis()->SetTitle("TOF (ns)");
hTOFvsWCTrk->GetYaxis()->CenterTitle();

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c08 = new TCanvas("c08", "TOF vs WC Track");
c08->SetTicks();
c08->SetFillColor(kWhite);

// ### Drawing the histograms ###
hTOFvsWCTrk->Draw("colz");

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


}//<---End File
