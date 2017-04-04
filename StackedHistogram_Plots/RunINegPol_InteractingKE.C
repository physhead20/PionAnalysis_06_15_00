{

// ######################################################################################################
// ######################################################################################################
// ### To obtain these numbers first set them equal to 1.0 and then use the printed output in the file
// ###   as input into "PlotBreakDown.ods" spreadsheet found in this repository....the output of the 
// ###       spreadsheet goes into these catagories to scale the particle species appropriately
// ######################################################################################################
// ######################################################################################################
double PionPercentage     = 0.54377;
double MuonPercentage     = 1.2323;
double ElectronPercentage = 1.1005;
double PhotonPercentage   = 1.51485;
double KaonPercentage     = 1.01446;

/*double PionPercentage     = 1.0;
double MuonPercentage     = 1.0;
double ElectronPercentage = 1.0;
double PhotonPercentage   = 1.0;
double KaonPercentage     = 1.0;*/


// #######################
// ### Load Data Plots ###
// #######################
TFile *f1 = new TFile("../histoROOTfiles_forPlots/RunINegPolData_histos_noCorrections_PionXSectionSample.root");


// ###################################
// ### Load Pion Monte Carlo Plots ###
// ###################################
TFile *f2 = new TFile("../histoROOTfiles_forPlots/PionMC_RunI_OutOfTheBox.root");

// ###################################
// ### Load Muon Monte Carlo Plots ###
// ###################################
TFile *f3 = new TFile("../histoROOTfiles_forPlots/MuonMC_RunI_OutOfTheBox.root");

// #######################################
// ### Load Electron Monte Carlo Plots ###
// #######################################
TFile *f4 = new TFile("../histoROOTfiles_forPlots/ElectronMC_RunI_OutOfTheBox.root");

// ###################################
// ### Load Kaon Monte Carlo Plots ###
// ###################################
TFile *f5 = new TFile("../histoROOTfiles_forPlots/KaonMC_RunI_OutOfTheBox.root");

// #####################################
// ### Load Photon Monte Carlo Plots ###
// #####################################
TFile *f6 = new TFile("../histoROOTfiles_forPlots/PhotonMC_RunI_OutOfTheBox.root");


//--------------------------------------------------------------------------------------------------------------
//					Incident Kinetic Energy Plot
//--------------------------------------------------------------------------------------------------------------

// #########################################
// ### Getting the data Incident KE plot ###
// #########################################
TH1F *hDataInKE = (TH1F*)f1->Get("hdataInteractingKE");

// ### Labeling the axis ###
hDataInKE->GetXaxis()->SetTitle("Kinetic Energy (MeV)");
hDataInKE->GetXaxis()->CenterTitle();

hDataInKE->GetYaxis()->SetTitle("Events / 50 MeV");
hDataInKE->GetYaxis()->CenterTitle(); 

// ########################################################
// ###      Scaling factor for through going muon       ###
// ### Note: If you have a 10% contamination than your  ###
// ###            scale factor should be 0.90           ###
// ########################################################
double MuonContaminationScaleFactor = 0.90;
    
// ===============================================================================================================
// 					SCALING FOR THE MUON CONTAMINATION
// ==========================================================================================================
    
hDataInKE->Scale(MuonContaminationScaleFactor);

// ############################################
// ### Getting the Pion MC Incident KE plot ###
// ############################################
TH1F *hPionIncKE = (TH1F*)f2->Get("hRecoMCInteractingKE");

// ### Labeling the axis ###
hPionIncKE->GetXaxis()->SetTitle("Kinetic Energy (MeV)");
hPionIncKE->GetXaxis()->CenterTitle();

hPionIncKE->GetYaxis()->SetTitle("Events / 50 MeV");
hPionIncKE->GetYaxis()->CenterTitle(); 

// ############################################
// ### Getting the Muon MC Incident KE plot ###
// ############################################
TH1F *hMuonMCIncKE = (TH1F*)f3->Get("hRecoMCInteractingKE");

// ### Labeling the axis ###
hMuonMCIncKE->GetXaxis()->SetTitle("Kinetic Energy (MeV)");
hMuonMCIncKE->GetXaxis()->CenterTitle();

hMuonMCIncKE->GetYaxis()->SetTitle("Events / 50 MeV");
hMuonMCIncKE->GetYaxis()->CenterTitle(); 


// ################################################
// ### Getting the Electron MC Incident KE plot ###
// ################################################
TH1F *hElectronMCIncKE = (TH1F*)f4->Get("hRecoMCInteractingKE");

// ### Labeling the axis ###
hElectronMCIncKE->GetXaxis()->SetTitle("Kinetic Energy (MeV)");
hElectronMCIncKE->GetXaxis()->CenterTitle();

hElectronMCIncKE->GetYaxis()->SetTitle("Events / 50 MeV");
hElectronMCIncKE->GetYaxis()->CenterTitle(); 


// ############################################
// ### Getting the Kaon MC Incident KE plot ###
// ############################################
TH1F *hKaonMCIncKE = (TH1F*)f5->Get("hRecoMCInteractingKE");

// ### Labeling the axis ###
hKaonMCIncKE->GetXaxis()->SetTitle("Kinetic Energy (MeV)");
hKaonMCIncKE->GetXaxis()->CenterTitle();

hKaonMCIncKE->GetYaxis()->SetTitle("Events / 50 MeV");
hKaonMCIncKE->GetYaxis()->CenterTitle(); 


// ##############################################
// ### Getting the Photon MC Incident KE plot ###
// ##############################################
TH1F *hPhotonMCIncKE = (TH1F*)f6->Get("hRecoMCInteractingKE");

// ### Labeling the axis ###
hPhotonMCIncKE->GetXaxis()->SetTitle("Kinetic Energy (MeV)");
hPhotonMCIncKE->GetXaxis()->CenterTitle();

hPhotonMCIncKE->GetYaxis()->SetTitle("Events / 50 MeV");
hPhotonMCIncKE->GetYaxis()->CenterTitle();  

// ============================================================================
// ======================= Normalizing MC to Data =============================
// ============================================================================

double PionMCIntegralIncKE     = hPionIncKE->Integral() ;
double MuonMCIntegralIncKE     = hMuonMCIncKE->Integral() ;
double ElectronMCIntegralIncKE = hElectronMCIncKE->Integral() ;
double KaonMCIntegralTrkIncKE  = hKaonMCIncKE->Integral();
double PhotonMCIntegralTrkIncKE= hPhotonMCIncKE->Integral();


// ### Overall MC scale factor ###
double MCIntegralTrkLength = PionMCIntegralIncKE + MuonMCIntegralIncKE + ElectronMCIntegralIncKE + KaonMCIntegralTrkIncKE + PhotonMCIntegralTrkIncKE;
double DataIntegralTrkLength = hDataInKE->Integral();

double scaleMCIncKE = DataIntegralTrkLength/MCIntegralTrkLength * 0.75;




// == Scale Pions ===
hPionIncKE->Sumw2();
hPionIncKE->Scale(scaleMCIncKE*(1/PionPercentage));
std::cout<<"# of Pion = "<<hPionIncKE->Integral()<<std::endl;

// == Scale Muons ===
hMuonMCIncKE->Sumw2();
hMuonMCIncKE->Scale(scaleMCIncKE*(1/MuonPercentage));
std::cout<<"# of Muon = "<<hMuonMCIncKE->Integral()<<std::endl;

// == Scale Electron ===
hElectronMCIncKE->Sumw2();
hElectronMCIncKE->Scale(scaleMCIncKE*(1/ElectronPercentage));
std::cout<<"# of Electron = "<<hElectronMCIncKE->Integral()<<std::endl;

// == Scale Kaon ===
hKaonMCIncKE->Sumw2();
hKaonMCIncKE->Scale(scaleMCIncKE*(1/KaonPercentage));
std::cout<<"# of Kaon = "<<hKaonMCIncKE->Integral()<<std::endl;
std::cout<<std::endl;

// == Scale Photon ===
hPhotonMCIncKE->Sumw2();
hPhotonMCIncKE->Scale(scaleMCIncKE*(1/PhotonPercentage));
std::cout<<"# of Photon = "<<hPhotonMCIncKE->Integral()<<std::endl;
std::cout<<std::endl;

std::cout<<std::endl;

std::cout<<"# of data events = "<<hDataInKE->Integral()<<std::endl;


// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c09 = new TCanvas("c09", "Track Length");
c09->SetTicks();
c09->SetFillColor(kWhite);


hPionIncKE->SetLineColor(kBlue);
hPionIncKE->SetLineStyle(0);
hPionIncKE->SetLineWidth(3);
hPionIncKE->SetFillColor(kBlue);
hPionIncKE->SetFillStyle(3006);

hElectronMCIncKE->SetLineColor(kRed);
hElectronMCIncKE->SetLineStyle(0);
hElectronMCIncKE->SetLineWidth(3);
hElectronMCIncKE->SetFillColor(kRed);
hElectronMCIncKE->SetFillStyle(3006);

hMuonMCIncKE->SetLineColor(kGreen+3);
hMuonMCIncKE->SetLineStyle(0);
hMuonMCIncKE->SetLineWidth(3);
hMuonMCIncKE->SetFillColor(kGreen+3);
hMuonMCIncKE->SetFillStyle(3006);

hKaonMCIncKE->SetLineColor(kPink+3);
hKaonMCIncKE->SetLineStyle(0);
hKaonMCIncKE->SetLineWidth(3);
hKaonMCIncKE->SetFillColor(kPink+3);
hKaonMCIncKE->SetFillStyle(3006);

hPhotonMCIncKE->SetLineColor(kAzure-9);
hPhotonMCIncKE->SetLineStyle(0);
hPhotonMCIncKE->SetLineWidth(3);
hPhotonMCIncKE->SetFillColor(kAzure-9);
hPhotonMCIncKE->SetFillStyle(3007);

hDataInKE->SetLineColor(kBlack);
hDataInKE->SetLineStyle(0);
hDataInKE->SetLineWidth(3);
hDataInKE->SetMarkerStyle(8);
hDataInKE->SetMarkerSize(0.9);


// ### Making a stacked histogram ###
THStack *hstacked = new THStack("hstacked","Stacked 1D histograms");

// ### Labeling the axis ###
//hstacked->GetXaxis()->SetTitle("Track Length (cm)");
//hstacked->GetXaxis()->CenterTitle();

//hstacked->GetYaxis()->SetTitle("Events / 0.5 cm");
//hstacked->GetYaxis()->CenterTitle(); 

hstacked->Add(hKaonMCIncKE);
hstacked->Add(hPhotonMCIncKE);
hstacked->Add(hMuonMCIncKE);
hstacked->Add(hElectronMCIncKE);
hstacked->Add(hPionIncKE);

// ### Drawing the histograms ###
hstacked->Draw("histo");
hDataInKE->Draw("E1same");


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
leg->AddEntry(hDataInKE,"Data");
leg->AddEntry(hPionIncKE,"Pion MC"); 
leg->AddEntry(hMuonMCIncKE,"Muon MC");
leg->AddEntry(hElectronMCIncKE,"Electron MC");
leg->AddEntry(hPhotonMCIncKE, "Photon MC");
leg->AddEntry(hKaonMCIncKE,"Kaon MC");
leg->Draw();




}//<---End File
