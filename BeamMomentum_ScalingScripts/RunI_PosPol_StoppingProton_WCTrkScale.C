{

// #######################
// ### Load Data Plots ###
// #######################
TFile *f1 = new TFile("../histoROOTfiles_forPlots/RunIPosPolData_histos_noCorrections_ProtonXSectionSample.root");


// #####################################
// ### Load Proton Monte Carlo Plots ###
// #####################################
TFile *f2 = new TFile("../histoROOTfiles_forPlots/StoppingProtonMC_RunI_OutOfTheBox.root");


// ### Scaling the highest count bin in data (740-750) ###


//--------------------------------------------------------------------------------------------------------------
//						UnWeighted Beam Profile Plots
//--------------------------------------------------------------------------------------------------------------

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c01 = new TCanvas("c01", "Unweighted Beam Profile");
c01->SetTicks();
c01->SetFillColor(kWhite);


// ### Get the Beam Profile Plot ###
TH1F *hdataWCTrackMomentum = (TH1F*)f1->Get("hdataWCTRKMomentum");

// ################################
// ### Formatting the histogram ###
// ################################
hdataWCTrackMomentum->SetLineColor(kBlack);
hdataWCTrackMomentum->SetLineStyle(0);
hdataWCTrackMomentum->SetLineWidth(3);
hdataWCTrackMomentum->SetMarkerStyle(8);
hdataWCTrackMomentum->SetMarkerSize(0.9);

// ### Labeling the axis ###
hdataWCTrackMomentum->GetXaxis()->SetTitle("WC Track Momentum (MeV)");
hdataWCTrackMomentum->GetXaxis()->CenterTitle();

hdataWCTrackMomentum->GetYaxis()->SetTitle("Events / 10 MeV");
hdataWCTrackMomentum->GetYaxis()->CenterTitle();



// ### Get the Monte Carlo Unweigthed Beam Profile Plot ###
TH1F *hMCWCTrackMomentumUnweighted = (TH1F*)f2->Get("hMCPrimaryPzUnWeighted");

// ################################
// ### Formatting the histogram ###
// ################################
hMCWCTrackMomentumUnweighted->SetLineColor(kBlue);
hMCWCTrackMomentumUnweighted->SetLineStyle(0);
hMCWCTrackMomentumUnweighted->SetLineWidth(3);

// ### Labeling the axis ###
hMCWCTrackMomentumUnweighted->GetXaxis()->SetTitle("WC Track Momentum (MeV)");
hMCWCTrackMomentumUnweighted->GetXaxis()->CenterTitle();

hMCWCTrackMomentumUnweighted->GetYaxis()->SetTitle("Events / 10 MeV");
hMCWCTrackMomentumUnweighted->GetYaxis()->CenterTitle();


// ### Normalizing MC to Data ###
double MCIntegral = hMCWCTrackMomentumUnweighted->Integral();
double DataIntegral = hdataWCTrackMomentum->Integral();

double scaleMC = DataIntegral/MCIntegral;

hMCWCTrackMomentumUnweighted->Sumw2();
hMCWCTrackMomentumUnweighted->Scale(scaleMC * 6.72097);

hMCWCTrackMomentumUnweighted->Draw("histo");
hdataWCTrackMomentum->Draw("E1same");


// ### Find the ratio bin by bin ###
TH1D *Ratio = new TH1D("Ratio", "P_{z}", 250, 0 , 2500);

// ### Data / MC
Ratio->Divide(hdataWCTrackMomentum,hMCWCTrackMomentumUnweighted);

// ### Read out each bins scale factor ###
for(int nbins = 1; nbins < Ratio.GetNbinsX(); nbins++)
   {
   //std::cout<<"nbins = "<<Ratio.GetBinContent(nbins)<<std::endl;
   
   std::cout<<"		if(g4Primary_Pz[nG4Primary] > "<<(nbins - 1)*10<<" && g4Primary_Pz[nG4Primary] < "<<nbins*10<<") {EventWeight = "<<Ratio.GetBinContent(nbins)<<";}"<<std::endl;
   
   }//<---End Nbins





//--------------------------------------------------------------------------------------------------------------
//						Weighted Beam Profile Plots
//--------------------------------------------------------------------------------------------------------------

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c02 = new TCanvas("c02", "Weighted Beam Profile");
c02->SetTicks();
c02->SetFillColor(kWhite);


// ### Get the Monte Carlo Weigthed Beam Profile Plot ###
TH1F *hMCWCTrackMomentumWeighted = (TH1F*)f2->Get("hMCPrimaryPz");

// ################################
// ### Formatting the histogram ###
// ################################
hMCWCTrackMomentumWeighted->SetLineColor(kBlue);
hMCWCTrackMomentumWeighted->SetLineStyle(0);
hMCWCTrackMomentumWeighted->SetLineWidth(3);

// ### Labeling the axis ###
hMCWCTrackMomentumWeighted->GetXaxis()->SetTitle("WC Track Momentum (MeV)");
hMCWCTrackMomentumWeighted->GetXaxis()->CenterTitle();

hMCWCTrackMomentumWeighted->GetYaxis()->SetTitle("Events / 10 MeV");
hMCWCTrackMomentumWeighted->GetYaxis()->CenterTitle();


// ### Normalizing MC to Data ###
double MCIntegral = hMCWCTrackMomentumWeighted->Integral();
double DataIntegral = hdataWCTrackMomentum->Integral();

double scaleMC = DataIntegral/MCIntegral;

hMCWCTrackMomentumWeighted->Sumw2();
hMCWCTrackMomentumWeighted->Scale(scaleMC);

hMCWCTrackMomentumWeighted->Draw("histo");
hdataWCTrackMomentum->Draw("E1same");



//--------------------------------------------------------------------------------------------------------------
//						Beam Profile Plots (New) Data - MC / Data
//--------------------------------------------------------------------------------------------------------------

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c03 = new TCanvas("c03", "Beam Profile Delta");
c03->SetTicks();
c03->SetFillColor(kWhite);

TH1F* Sub1 = new TH1F(*hMCWCTrackMomentumWeighted);

// ### Scaling the MC histogram
Sub1->Sumw2();
Sub1->Scale(-1);

/////////////////////////////////// Primary Particle Pz //////////////////////////////////////////
TH1D *Ratio = new TH1D("Ratio", "P_{z}", 250, 0 , 2500);

TH1D *Difference = new TH1D("Difference", "P_{z}", 250, 0 , 2500);

Difference->Add(hdataWCTrackMomentum, Sub1);
Difference->Sumw2();

Ratio->Divide(Difference,hdataWCTrackMomentum);

// ### Labeling the axis ###
Ratio->GetXaxis()->SetTitle("WCTrack Momentum (MeV)");
Ratio->GetXaxis()->CenterTitle();

Ratio->GetYaxis()->SetTitle("(Data - MC) / Data ");
Ratio->GetYaxis()->CenterTitle();

Ratio->SetLineColor(kRed);
Ratio->SetLineStyle(0);
Ratio->SetLineWidth(3);


//AddedHisto->Draw();
Ratio->Draw("histo");


//--------------------------------------------------------------------------------------------------------------
//						Kinetic Energy (New Profile)
//--------------------------------------------------------------------------------------------------------------

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c04 = new TCanvas("c04", "Kineitic Energy");
c04->SetTicks();
c04->SetFillColor(kWhite);

// ### Get the Beam Profile Plot ###
TH1F *hdataInitialKinEng = (TH1F*)f1->Get("hdataInitialKEMomentum");

// ################################
// ### Formatting the histogram ###
// ################################
hdataInitialKinEng->SetLineColor(kBlack);
hdataInitialKinEng->SetLineStyle(0);
hdataInitialKinEng->SetLineWidth(3);
hdataInitialKinEng->SetMarkerStyle(8);
hdataInitialKinEng->SetMarkerSize(0.9);

// ### Labeling the axis ###
hdataInitialKinEng->GetXaxis()->SetTitle("Initial Kinetic Energy (MeV)");
hdataInitialKinEng->GetXaxis()->CenterTitle();

hdataInitialKinEng->GetYaxis()->SetTitle("Events / 5 MeV");
hdataInitialKinEng->GetYaxis()->CenterTitle();


// ### Get the Monte Carlo Beam Profile Plot ###
TH1F *hMCInitialKinEng = (TH1F*)f2->Get("hRecoMCInitialKEMomentum");

// ################################
// ### Formatting the histogram ###
// ################################
hMCInitialKinEng->SetLineColor(kBlue);
hMCInitialKinEng->SetLineStyle(0);
hMCInitialKinEng->SetLineWidth(3);

// ### Labeling the axis ###
hMCInitialKinEng->GetXaxis()->SetTitle("Initial Kinetic Energy (MeV)");
hMCInitialKinEng->GetXaxis()->CenterTitle();

hMCInitialKinEng->GetYaxis()->SetTitle("Events / 5 MeV");
hMCInitialKinEng->GetYaxis()->CenterTitle();


// ### Normalizing MC to Data ###
double MCIntegralKE = hMCInitialKinEng->Integral();
double DataIntegralKE = hdataInitialKinEng->Integral();

double scaleMCKE = DataIntegralKE/MCIntegralKE;

hMCInitialKinEng->Sumw2();
hMCInitialKinEng->Scale(scaleMCKE);

hdataInitialKinEng->Draw("E1");
hMCInitialKinEng->Draw("histosame");


//--------------------------------------------------------------------------------------------------------------
//						Beam Profile Plots (New) Data - MC / Data
//--------------------------------------------------------------------------------------------------------------

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c05 = new TCanvas("c05", "KE Delta");
c05->SetTicks();
c05->SetFillColor(kWhite);

TH1F* Sub2 = new TH1F(*hMCInitialKinEng);

// ### Scaling the MC histogram
Sub2->Sumw2();
Sub2->Scale(-1);

/////////////////////////////////// Primary Particle Pz //////////////////////////////////////////
TH1D *Ratio2 = new TH1D("Ratio2", "KE", 500, 0 , 2500);

TH1D *Difference2 = new TH1D("Difference2", "KE", 500, 0 , 2500);

Difference2->Add(hdataInitialKinEng, Sub2);
Difference2->Sumw2();

Ratio2->Divide(Difference2,hdataInitialKinEng);

// ### Labeling the axis ###
Ratio2->GetXaxis()->SetTitle("Kinetic Energy (MeV)");
Ratio2->GetXaxis()->CenterTitle();

Ratio2->GetYaxis()->SetTitle("(Data - MC) / Data ");
Ratio2->GetYaxis()->CenterTitle();


//AddedHisto->Draw();
Ratio2->Draw("E1");




}//<---End File


