{

#include <math.h>
// ############################
// #######   Constants  #######
// ############################
float rho = 1400; //Argon density in kg/m^3
float molar_mass = 39.9; //g/mol
float g_per_kg = 1000; 
float avogadro = 6.02e+23; //number/mol
float number_density = rho*g_per_kg/molar_mass*avogadro;
float slab_width = 0.0045;//in m (from mean of track pitch)

// ############################
// ###   Load Data Plots    ###
// ############################
TFile *f1 = new TFile("../histoROOTfiles_forPlots/CombinedNegPolData_histos_noCorrections_PionXSectionSample.root");

// ####################################
// ### Grab the relevant histograms ###
// ####################################

// --- Incident Kinetic Energy Histo ---
TH1F* hDataInc = (TH1F*)f1->Get("hdataIncidentKE");
// --- Interacting Kinetic Energy Histo ---
TH1F* hDataInt = (TH1F*)f1->Get("hdataInteractingKE");
// --- Cross-Section Plot from file ---
TH1F* DataCrossSection = (TH1F*)f1->Get("fCrossSection");

// ########################################################
// ###      Scaling factor for through going muon       ###
// ### Note: If you have a 10% contamination than your  ###
// ###            scale factor should be 0.90           ###
// ########################################################
double MuonContaminationScaleFactor = 0.90;
    
// ==========================================================================================================
// 			SCALING THE INCIDENT HISTOGRAM FOR THE MUON CONTAMINATION
// ==========================================================================================================
hDataInc->Scale(MuonContaminationScaleFactor);


const Int_t nBins = 19;
Double_t edges[nBins+1] = {0, 50, 100, 150, 200, 250, 300, 350, 400, 450, 500, 550, 600, 650, 700, 750, 800, 900, 1200, 1600};

TH1* hVariableBinCrossSection = new TH1D("hVariableBinCrossSection", "Cross-Section", nBins, edges);


// ##########################
// ### Variables for Data ###
// ##########################
float data_numerator;
float data_denomenator;
float datasigbinom;

float VariableCrossSection[40] = {0.};
float VariableCrossSectionError[40] = {0.};

int counter = 0;

// ################################################################
// ### Loop over the data histograms to get all the information ###
// ################################################################
for(int i = 1; i <= hDataInc->GetNbinsX(); i++)
   {
   
   // ####################################################
   // ### Getting the numerator and denomenator values ###
   // ####################################################
   data_numerator   = hDataInt->GetBinContent(i);
   data_denomenator = hDataInc->GetBinContent(i);
   
   // ### Cross-section = (Interacting Bins / Incident Bins) / (Density) / (slab width) ###
   TempCrossSection = ((data_numerator/data_denomenator)/(number_density)/(slab_width)) * (1e28);
   
   // ### Calculating the binomial error on this bin ###
   datasigbinom = sqrt(data_numerator/(data_denomenator*data_denomenator)*(1-data_numerator/data_denomenator));
   datasigbinom = datasigbinom/number_density/slab_width*1e28; //data binomial stat error in barns
   
   // ### Putting in protection for dividing by zero ###
   if(data_denomenator == 0){TempCrossSection = 0; datasigbinom = 0;}
   
   VariableCrossSection[counter]      = TempCrossSection;
   VariableCrossSectionError[counter] = datasigbinom;
   counter++;
   
   std::cout<<"i = "<<(i-1)*50<<" cross-section = "<<TempCrossSection<<" +/-"<<datasigbinom<<std::endl;
   
   }//End getting data from bins



// --------------------------------------------------------------------------------------------------------------------------
// ########################################################
// ### Putting the variable binning into the histograms ###
// ########################################################
hVariableBinCrossSection->SetBinContent(1,VariableCrossSection[0]);
hVariableBinCrossSection->SetBinError(1,VariableCrossSectionError[0]);

hVariableBinCrossSection->SetBinContent(2,VariableCrossSection[1]);
hVariableBinCrossSection->SetBinError(2,VariableCrossSectionError[1]);

hVariableBinCrossSection->SetBinContent(3,VariableCrossSection[2]);
hVariableBinCrossSection->SetBinError(3,VariableCrossSectionError[2]);

hVariableBinCrossSection->SetBinContent(4,VariableCrossSection[3]);
hVariableBinCrossSection->SetBinError(4,VariableCrossSectionError[3]);

hVariableBinCrossSection->SetBinContent(5,VariableCrossSection[4]);
hVariableBinCrossSection->SetBinError(5,VariableCrossSectionError[4]);

hVariableBinCrossSection->SetBinContent(6,VariableCrossSection[5]);
hVariableBinCrossSection->SetBinError(6,VariableCrossSectionError[5]);

hVariableBinCrossSection->SetBinContent(7,VariableCrossSection[6]);
hVariableBinCrossSection->SetBinError(7,VariableCrossSectionError[6]);

hVariableBinCrossSection->SetBinContent(8,VariableCrossSection[7]);
hVariableBinCrossSection->SetBinError(8,VariableCrossSectionError[7]);

hVariableBinCrossSection->SetBinContent(9,VariableCrossSection[8]);
hVariableBinCrossSection->SetBinError(9,VariableCrossSectionError[8]);

hVariableBinCrossSection->SetBinContent(10,VariableCrossSection[9]);
hVariableBinCrossSection->SetBinError(10,VariableCrossSectionError[9]);

hVariableBinCrossSection->SetBinContent(11,VariableCrossSection[10]);
hVariableBinCrossSection->SetBinError(11,VariableCrossSectionError[10]);

hVariableBinCrossSection->SetBinContent(12,VariableCrossSection[11]);
hVariableBinCrossSection->SetBinError(12,VariableCrossSectionError[11]);

hVariableBinCrossSection->SetBinContent(13,VariableCrossSection[12]);
hVariableBinCrossSection->SetBinError(13,VariableCrossSectionError[12]);

hVariableBinCrossSection->SetBinContent(14,VariableCrossSection[13]);
hVariableBinCrossSection->SetBinError(14,VariableCrossSectionError[13]);

hVariableBinCrossSection->SetBinContent(15,VariableCrossSection[14]);
hVariableBinCrossSection->SetBinError(15,VariableCrossSectionError[14]);

hVariableBinCrossSection->SetBinContent(16,VariableCrossSection[15]);
hVariableBinCrossSection->SetBinError(16,VariableCrossSectionError[15]);


float bin17 = (VariableCrossSection[16] + VariableCrossSection[17]) / 2;
hVariableBinCrossSection->SetBinContent(17,bin17);
float bin17error = sqrt( (VariableCrossSectionError[16]*VariableCrossSectionError[16]) + (VariableCrossSectionError[17]*VariableCrossSectionError[17]) );
hVariableBinCrossSection->SetBinError(17,bin17error);

float bin18 = (VariableCrossSection[18] + VariableCrossSection[19] + VariableCrossSection[20] + VariableCrossSection[21] + VariableCrossSection[22] + VariableCrossSection[23]) / 6;
hVariableBinCrossSection->SetBinContent(18,bin18);
float bin18error = (sqrt( pow(VariableCrossSectionError[18],2) + pow(VariableCrossSectionError[19],2) + pow(VariableCrossSectionError[20],2)+
                         pow(VariableCrossSectionError[21],2) + pow(VariableCrossSectionError[22],2) + pow(VariableCrossSectionError[23],2) ) )/ 6;
hVariableBinCrossSection->SetBinError(18,bin18error);

float bin19 = (VariableCrossSection[24] + VariableCrossSection[25] + VariableCrossSection[26] + VariableCrossSection[27] + VariableCrossSection[28] + VariableCrossSection[29] + 
               VariableCrossSection[30] + VariableCrossSection[31]) / 8;
hVariableBinCrossSection->SetBinContent(19,bin19);
float bin19error = (sqrt( pow(VariableCrossSectionError[24],2) + pow(VariableCrossSectionError[25],2) + pow(VariableCrossSectionError[26],2)+
                          pow(VariableCrossSectionError[27],2) + pow(VariableCrossSectionError[28],2) + pow(VariableCrossSectionError[29],2) + 
                          pow(VariableCrossSectionError[30],2) + pow(VariableCrossSectionError[31],2)) )/ 8;
hVariableBinCrossSection->SetBinError(19,bin19error);
// --------------------------------------------------------------------------------------------------------------------------


// ############################
// ### Load MC Plots        ###
// ############################
TFile *f2 = new TFile("../histoROOTfiles_forPlots/PionMC_Combined_OutOfTheBox.root");
 
 TH1F* hMCInc = (TH1F*)f2->Get("hRecoMCIncidentKEunweighted");
 TH1F* hMCInt = (TH1F*)f2->Get("hRecoMCInteractingKEunweighted");
 TH1F* MCCrossSection = (TH1F*)f2->Get("fCrossSection");
 TH1F* MCCrossSys = (TH1F*)fCrossSection->Clone();
 MCCrossSys->SetName("MCCrossSys");


// ####################################################
// ### Monte Carlo Central Value (stat. error only) ###
// ####################################################
const Int_t MCnBins = 19;
Double_t MCedges[MCnBins+1] = {0, 50, 100, 150, 200, 250, 300, 350, 400, 450, 500, 550, 600, 650, 700, 750, 800, 900, 1200, 1600};

TH1* hVariableBinCrossSectionMC = new TH1D("hVariableBinCrossSectionMC", "Cross-Section", MCnBins, MCedges);

float VariableCrossSectionMC[40] = {0.};
float VariableCrossSectionErrorMC[40] = {0.};


// #############################################################
// ### Monte Carlo Central Value (stat. + Systematic errors) ###
// #############################################################
TH1* hVariableBinCrossSectionMCSys = new TH1D("hVariableBinCrossSectionMCSys", "Cross-Section", MCnBins, MCedges);

float VariableCrossSectionMCSys[40] = {0.};
float VariableCrossSectionErrorMCSys[40] = {0.};

int counterMC = 0;
 
// ######################### 
// ### General Variables ###
// ######################### 
 int nbinsMC = fCrossSection->GetNbinsX();
 float MCsigbinom;
 float MCsysstat;
 float MCn;
 float MCN;
 float MCp;
 
 //Systematic errors taken from Jonathan's slide
 float dEdxuncert = 0.05;
 float dEdxuncertsq = dEdxuncert*dEdxuncert;
 float mucontam = 0.03;
 float mucontamsq = mucontam*mucontam;
 float WCmomuncert = 0.03;
 float WCmomuncertsq = WCmomuncert*WCmomuncert;
 float Eflatuncert = 0.035;
 float Eflatuncertsq = Eflatuncert*Eflatuncert;

 //MC statistical error should be flat (before momentum reweighting)
 //Take peak value of hMCInc histo as proxy for real MC stats
 //In truth, should use the unweighted MC histo to get stat err instead
 double MCstat = hMCInt->GetBinContent(8);
 std::cout << MCstat << std::endl;
 MCstat = (sqrt(MCstat))/MCstat;
 std::cout << MCstat << std::endl;

 std::cout << "MC cross section" << std::endl;

 for (int i = 1; i <= nbinsMC; i++ ) {
   MCn = hMCInt->GetBinContent(i); 
   MCN = hMCInc->GetBinContent(i);
   MCsigbinom = sqrt((MCn/(MCN*MCN))*(1-(MCn/MCN)));

   if( MCN == 0 )continue; //Temporary fix to ensure no divide by zero 
   // ### Cross-section = (Interacting Bins / Incident Bins) / (Density) / (slab width) ###
   TempCrossSection = (MCn/MCN)/(number_density)/(slab_width);
   
   crossSection = TempCrossSection * (1e28); //To put this into barns
   MCCrossSection->SetBinContent(i,crossSection);
   
   VariableCrossSectionMC[counterMC] = crossSection;

   MCsigbinom = sqrt(MCn/(MCN*MCN)*(1-MCn/MCN));
   MCsigbinom = MCsigbinom/number_density/slab_width*1e28; //MC binomial stat error in barns
//
//   MCCrossSection->SetBinError(i,MCsigbinom);
   MCCrossSection->SetBinError(i, MCstat*crossSection); // use flat stat uncertainty
   
   VariableCrossSectionErrorMC[counterMC] = MCstat*crossSection;

   MCsysstat = dEdxuncertsq + mucontamsq + WCmomuncertsq + Eflatuncertsq; //sum of squares of syserrs
   //   MCsysstat = MCsysstat + MCsigbinom*MCsigbinom; // Add in MC stat err squared
   MCsysstat = MCsysstat*crossSection;
   MCsysstat = MCsysstat + MCstat*MCstat;
   MCsysstat = sqrt(MCsysstat); // sqrt of sum of squares = total err

   std::cout << crossSection << " +/- " << MCstat*crossSection << "(stat) +/- " << MCsysstat << std::endl;


   MCCrossSys->SetBinContent(i,crossSection);
   VariableCrossSectionMCSys[counterMC] = crossSection;
   
   MCCrossSys->SetBinError(i,MCsysstat); 
   VariableCrossSectionErrorMCSys[counterMC] = MCsysstat;
   counterMC++; 
 }// end loop over MC bins




// --------------------------------------------------------------------------------------------------------------------------
// ########################################################
// ### Putting the variable binning into the histograms ###
// ########################################################
hVariableBinCrossSectionMCSys->SetBinContent(1,VariableCrossSectionMCSys[0]);
hVariableBinCrossSectionMCSys->SetBinError(1,VariableCrossSectionErrorMCSys[0]);

hVariableBinCrossSectionMCSys->SetBinContent(2,VariableCrossSectionMCSys[1]);
hVariableBinCrossSectionMCSys->SetBinError(2,VariableCrossSectionErrorMCSys[1]);

hVariableBinCrossSectionMCSys->SetBinContent(3,VariableCrossSectionMCSys[2]);
hVariableBinCrossSectionMCSys->SetBinError(3,VariableCrossSectionErrorMCSys[2]);

hVariableBinCrossSectionMCSys->SetBinContent(4,VariableCrossSectionMCSys[3]);
hVariableBinCrossSectionMCSys->SetBinError(4,VariableCrossSectionErrorMCSys[3]);

hVariableBinCrossSectionMCSys->SetBinContent(5,VariableCrossSectionMCSys[4]);
hVariableBinCrossSectionMCSys->SetBinError(5,VariableCrossSectionErrorMCSys[4]);

hVariableBinCrossSectionMCSys->SetBinContent(6,VariableCrossSectionMCSys[5]);
hVariableBinCrossSectionMCSys->SetBinError(6,VariableCrossSectionErrorMCSys[5]);

hVariableBinCrossSectionMCSys->SetBinContent(7,VariableCrossSectionMCSys[6]);
hVariableBinCrossSectionMCSys->SetBinError(7,VariableCrossSectionErrorMCSys[6]);

hVariableBinCrossSectionMCSys->SetBinContent(8,VariableCrossSectionMCSys[7]);
hVariableBinCrossSectionMCSys->SetBinError(8,VariableCrossSectionErrorMCSys[7]);

hVariableBinCrossSectionMCSys->SetBinContent(9,VariableCrossSectionMCSys[8]);
hVariableBinCrossSectionMCSys->SetBinError(9,VariableCrossSectionErrorMCSys[8]);

hVariableBinCrossSectionMCSys->SetBinContent(10,VariableCrossSectionMCSys[9]);
hVariableBinCrossSectionMCSys->SetBinError(10,VariableCrossSectionErrorMCSys[9]);

hVariableBinCrossSectionMCSys->SetBinContent(11,VariableCrossSectionMCSys[10]);
hVariableBinCrossSectionMCSys->SetBinError(11,VariableCrossSectionErrorMCSys[10]);

hVariableBinCrossSectionMCSys->SetBinContent(12,VariableCrossSectionMCSys[11]);
hVariableBinCrossSectionMCSys->SetBinError(12,VariableCrossSectionErrorMCSys[11]);

hVariableBinCrossSectionMCSys->SetBinContent(13,VariableCrossSectionMCSys[12]);
hVariableBinCrossSectionMCSys->SetBinError(13,VariableCrossSectionErrorMCSys[12]);

hVariableBinCrossSectionMCSys->SetBinContent(14,VariableCrossSectionMCSys[13]);
hVariableBinCrossSectionMCSys->SetBinError(14,VariableCrossSectionErrorMCSys[13]);

hVariableBinCrossSectionMCSys->SetBinContent(15,VariableCrossSectionMCSys[14]);
hVariableBinCrossSectionMCSys->SetBinError(15,VariableCrossSectionErrorMCSys[14]);

hVariableBinCrossSectionMCSys->SetBinContent(16,VariableCrossSectionMCSys[15]);
hVariableBinCrossSectionMCSys->SetBinError(16,VariableCrossSectionErrorMCSys[15]);


float bin17 = (VariableCrossSectionMCSys[16] + VariableCrossSectionMCSys[17]) / 2;
hVariableBinCrossSectionMCSys->SetBinContent(17,bin17);
float bin17error = sqrt( (VariableCrossSectionErrorMCSys[16]*VariableCrossSectionErrorMCSys[16]) + (VariableCrossSectionErrorMCSys[17]*VariableCrossSectionErrorMCSys[17]) );
hVariableBinCrossSectionMCSys->SetBinError(17,bin17error);

float bin18 = (VariableCrossSectionMCSys[18] + VariableCrossSectionMCSys[19] + VariableCrossSectionMCSys[20] + VariableCrossSectionMCSys[21] + VariableCrossSectionMCSys[22] + VariableCrossSectionMCSys[23]) / 6;
hVariableBinCrossSectionMCSys->SetBinContent(18,bin18);
float bin18error = (sqrt( pow(VariableCrossSectionErrorMCSys[18],2) + pow(VariableCrossSectionErrorMCSys[19],2) + pow(VariableCrossSectionErrorMCSys[20],2)+
                         pow(VariableCrossSectionErrorMCSys[21],2) + pow(VariableCrossSectionErrorMCSys[22],2) + pow(VariableCrossSectionErrorMCSys[23],2) ) );
hVariableBinCrossSectionMCSys->SetBinError(18,bin18error);

float bin19 = (VariableCrossSectionMCSys[24] + VariableCrossSectionMCSys[25] + VariableCrossSectionMCSys[26] + VariableCrossSectionMCSys[27] + VariableCrossSectionMCSys[28] + VariableCrossSectionMCSys[29] + 
               VariableCrossSectionMCSys[30] + VariableCrossSectionMCSys[31]) / 8;
hVariableBinCrossSectionMCSys->SetBinContent(19,bin19);
float bin19error = (sqrt( pow(VariableCrossSectionErrorMCSys[24],2) + pow(VariableCrossSectionErrorMCSys[25],2) + pow(VariableCrossSectionErrorMCSys[26],2)+
                          pow(VariableCrossSectionErrorMCSys[27],2) + pow(VariableCrossSectionErrorMCSys[28],2) + pow(VariableCrossSectionErrorMCSys[29],2) + 
                          pow(VariableCrossSectionErrorMCSys[30],2) + pow(VariableCrossSectionErrorMCSys[31],2)) );
hVariableBinCrossSectionMCSys->SetBinError(19,bin19error);
// --------------------------------------------------------------------------------------------------------------------------



// --------------------------------------------------------------------------------------------------------------------------
// ########################################################
// ### Putting the variable binning into the histograms ###
// ########################################################
hVariableBinCrossSectionMC->SetBinContent(1,VariableCrossSectionMC[0]);
hVariableBinCrossSectionMC->SetBinError(1,VariableCrossSectionErrorMC[0]);

hVariableBinCrossSectionMC->SetBinContent(2,VariableCrossSectionMC[1]);
hVariableBinCrossSectionMC->SetBinError(2,VariableCrossSectionErrorMC[1]);

hVariableBinCrossSectionMC->SetBinContent(3,VariableCrossSectionMC[2]);
hVariableBinCrossSectionMC->SetBinError(3,VariableCrossSectionErrorMC[2]);

hVariableBinCrossSectionMC->SetBinContent(4,VariableCrossSectionMC[3]);
hVariableBinCrossSectionMC->SetBinError(4,VariableCrossSectionErrorMC[3]);

hVariableBinCrossSectionMC->SetBinContent(5,VariableCrossSectionMC[4]);
hVariableBinCrossSectionMC->SetBinError(5,VariableCrossSectionErrorMC[4]);

hVariableBinCrossSectionMC->SetBinContent(6,VariableCrossSectionMC[5]);
hVariableBinCrossSectionMC->SetBinError(6,VariableCrossSectionErrorMC[5]);

hVariableBinCrossSectionMC->SetBinContent(7,VariableCrossSectionMC[6]);
hVariableBinCrossSectionMC->SetBinError(7,VariableCrossSectionErrorMC[6]);

hVariableBinCrossSectionMC->SetBinContent(8,VariableCrossSectionMC[7]);
hVariableBinCrossSectionMC->SetBinError(8,VariableCrossSectionErrorMC[7]);

hVariableBinCrossSectionMC->SetBinContent(9,VariableCrossSectionMC[8]);
hVariableBinCrossSectionMC->SetBinError(9,VariableCrossSectionErrorMC[8]);

hVariableBinCrossSectionMC->SetBinContent(10,VariableCrossSectionMC[9]);
hVariableBinCrossSectionMC->SetBinError(10,VariableCrossSectionErrorMC[9]);

hVariableBinCrossSectionMC->SetBinContent(11,VariableCrossSectionMC[10]);
hVariableBinCrossSectionMC->SetBinError(11,VariableCrossSectionErrorMC[10]);

hVariableBinCrossSectionMC->SetBinContent(12,VariableCrossSectionMC[11]);
hVariableBinCrossSectionMC->SetBinError(12,VariableCrossSectionErrorMC[11]);

hVariableBinCrossSectionMC->SetBinContent(13,VariableCrossSectionMC[12]);
hVariableBinCrossSectionMC->SetBinError(13,VariableCrossSectionErrorMC[12]);

hVariableBinCrossSectionMC->SetBinContent(14,VariableCrossSectionMC[13]);
hVariableBinCrossSectionMC->SetBinError(14,VariableCrossSectionErrorMC[13]);

hVariableBinCrossSectionMC->SetBinContent(15,VariableCrossSectionMC[14]);
hVariableBinCrossSectionMC->SetBinError(15,VariableCrossSectionErrorMC[14]);

hVariableBinCrossSectionMC->SetBinContent(16,VariableCrossSectionMC[15]);
hVariableBinCrossSectionMC->SetBinError(16,VariableCrossSectionErrorMC[15]);


float bin17 = (VariableCrossSectionMC[16] + VariableCrossSectionMC[17]) / 2;
hVariableBinCrossSectionMC->SetBinContent(17,bin17);
float bin17error = sqrt( (VariableCrossSectionErrorMC[16]*VariableCrossSectionErrorMC[16]) + (VariableCrossSectionErrorMC[17]*VariableCrossSectionErrorMC[17]) );
hVariableBinCrossSectionMC->SetBinError(17,bin17error);

float bin18 = (VariableCrossSectionMC[18] + VariableCrossSectionMC[19] + VariableCrossSectionMC[20] + VariableCrossSectionMC[21] + VariableCrossSectionMC[22] + VariableCrossSectionMC[23]) / 6;
hVariableBinCrossSectionMC->SetBinContent(18,bin18);
float bin18error = (sqrt( pow(VariableCrossSectionErrorMC[18],2) + pow(VariableCrossSectionErrorMC[19],2) + pow(VariableCrossSectionErrorMC[20],2)+
                         pow(VariableCrossSectionErrorMC[21],2) + pow(VariableCrossSectionErrorMC[22],2) + pow(VariableCrossSectionErrorMC[23],2) ) );
hVariableBinCrossSectionMC->SetBinError(18,bin18error);

float bin19 = (VariableCrossSectionMC[24] + VariableCrossSectionMC[25] + VariableCrossSectionMC[26] + VariableCrossSectionMC[27] + VariableCrossSectionMC[28] + VariableCrossSectionMC[29] + 
               VariableCrossSectionMC[30] + VariableCrossSectionMC[31]) / 8;
hVariableBinCrossSectionMC->SetBinContent(19,bin19);
float bin19error = (sqrt( pow(VariableCrossSectionErrorMC[24],2) + pow(VariableCrossSectionErrorMC[25],2) + pow(VariableCrossSectionErrorMC[26],2)+
                          pow(VariableCrossSectionErrorMC[27],2) + pow(VariableCrossSectionErrorMC[28],2) + pow(VariableCrossSectionErrorMC[29],2) + 
                          pow(VariableCrossSectionErrorMC[30],2) + pow(VariableCrossSectionErrorMC[31],2)) );
hVariableBinCrossSectionMC->SetBinError(19,bin19error);
// --------------------------------------------------------------------------------------------------------------------------






// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c01 = new TCanvas("c01", "Track Length");
c01->SetTicks();
c01->SetFillColor(kWhite);
c01->cd();
gStyle->SetOptStat(0);

 hVariableBinCrossSectionMCSys->SetFillColor(kAzure-5);
 hVariableBinCrossSectionMCSys->SetLineColor(kAzure-5);
 hVariableBinCrossSectionMCSys->SetMarkerStyle(1);
 hVariableBinCrossSectionMCSys->SetMarkerColor(kAzure-5);
 hVariableBinCrossSectionMCSys->SetTitle("");
 hVariableBinCrossSectionMCSys->GetXaxis()->SetTitle("Reconstructed Kinetic Energy (MeV)");
 hVariableBinCrossSectionMCSys->GetXaxis()->SetTitleFont(42);
 hVariableBinCrossSectionMCSys->GetXaxis()->SetTitleSize(0.04);
 hVariableBinCrossSectionMCSys->GetXaxis()->CenterTitle();
 hVariableBinCrossSectionMCSys->GetYaxis()->SetTitle("Total #pi^{#minus} cross section, #sigma_{TOT} (barns)");
 hVariableBinCrossSectionMCSys->GetYaxis()->CenterTitle();
 hVariableBinCrossSectionMCSys->GetYaxis()->SetTitleFont(42);
 hVariableBinCrossSectionMCSys->GetYaxis()->SetTitleSize(0.04);

 hVariableBinCrossSectionMC->SetTitle("");
 hVariableBinCrossSectionMC->SetFillColor(kAzure-9);
 hVariableBinCrossSectionMC->SetLineColor(kAzure-9);
 hVariableBinCrossSectionMC->SetMarkerStyle(1);
 hVariableBinCrossSectionMC->SetMarkerColor(kAzure-9);
 hVariableBinCrossSectionMC->GetXaxis()->SetTitle("");
 hVariableBinCrossSectionMC->GetYaxis()->SetTitle("");

 hVariableBinCrossSection->SetMarkerStyle(8);
 hVariableBinCrossSection->SetMarkerSize(0.85);
 hVariableBinCrossSection->SetMarkerColor(kBlack);
 hVariableBinCrossSection->SetLineColor(kBlack);
 hVariableBinCrossSection->SetLineWidth(2);
 hVariableBinCrossSection->SetTitle("");
 hVariableBinCrossSection->GetXaxis()->SetTitle("");
 hVariableBinCrossSection->GetYaxis()->SetTitle("");

 hVariableBinCrossSectionMCSys->SetAxisRange(0,1600.);
 hVariableBinCrossSectionMCSys->SetMaximum(3.5);
 hVariableBinCrossSectionMCSys->SetMinimum(0);
 
 
 hVariableBinCrossSectionMCSys->Draw("e2");
 hVariableBinCrossSectionMC->Draw("e2same");
 hVariableBinCrossSection->Draw("e1same");
 
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
leg->SetHeader("LArIAT Combined");
leg->AddEntry(hVariableBinCrossSection,"Data, stat");
leg->AddEntry(hVariableBinCrossSectionMCSys,"MC syst + stat"); 
leg->AddEntry(hVariableBinCrossSectionMC,"MC central value");
leg->Draw();

//hVariableBinCrossSection->Draw();
}//<---End File
