#define PionMCDD_cxx
#include "PionMCDD.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <TVector3.h>

// ===================================================================================================================
// ====================================       PUT HISTOGRAMS HERE           ==========================================
// ===================================================================================================================

// *********************************** GEANT INFORMATION ****************************************************************


/////////////////////////////////// Primary Particle Start X Position //////////////////////////////////////////
TH1D *hMCPrimaryStartX = new TH1D("hMCPrimaryStartX", "Primary Particle X_{0}", 200, -50 , 50);
/////////////////////////////////// Primary Particle Start Y Position //////////////////////////////////////////
TH1D *hMCPrimaryStartY = new TH1D("hMCPrimaryStartY", "Primary Particle Y_{0}", 200, -50 , 50);
/////////////////////////////////// Primary Particle Start Z Position //////////////////////////////////////////
TH1D *hMCPrimaryStartZ = new TH1D("hMCPrimaryStartZ", "Primary Particle Z_{0}", 600, -120 , 180);

/////////////////////////////////// Primary Projected Particle Start X Position //////////////////////////////////////////
TH1D *hMCPrimaryProjectedStartX = new TH1D("hMCPrimaryProjectedStartX", "Primary Particle X_{0}", 200, -50 , 50);
/////////////////////////////////// Primary Projected Particle Start Y Position //////////////////////////////////////////
TH1D *hMCPrimaryProjectedStartY = new TH1D("hMCPrimaryProjectedStartY", "Primary Particle Y_{0}", 200, -50 , 50);
/////////////////////////////////// Primary Projected Particle Start Z Position //////////////////////////////////////////
TH1D *hMCPrimaryProjectedStartZ = new TH1D("hMCPrimaryProjectedStartZ", "Primary Particle Z_{0}", 400, -50 , 150);

/////////////////////////////////// Primary Particle End X Position //////////////////////////////////////////
TH1D *hMCPrimaryEndX = new TH1D("hMCPrimaryEndX", "Primary Particle X_{f}", 400, -200 , 200);
/////////////////////////////////// Primary Particle End Y Position //////////////////////////////////////////
TH1D *hMCPrimaryEndY = new TH1D("hMCPrimaryEndY", "Primary Particle Y_{f}", 400, -200 , 200);
/////////////////////////////////// Primary Particle End Z Position //////////////////////////////////////////
TH1D *hMCPrimaryEndZ = new TH1D("hMCPrimaryEndZ", "Primary Particle Z_{f}", 600, -120 , 480);

/////////////////////////////////// Primary Particle Px  //////////////////////////////////////////
TH1D *hMCPrimaryPx = new TH1D("hMCPrimaryPx", "Primary Particle P_{x}", 300, -150 , 150);
/////////////////////////////////// Primary Particle Py  //////////////////////////////////////////
TH1D *hMCPrimaryPy = new TH1D("hMCPrimaryPy", "Primary Particle P_{y}", 300, -159 , 150);
/////////////////////////////////// Primary Particle Pz //////////////////////////////////////////
TH1D *hMCPrimaryPz = new TH1D("hMCPrimaryPz", "Primary Particle P_{z}", 250, 0 , 2500);


/////////////////////////////////// Primary Particle Px (unweighted)  //////////////////////////////////////////
TH1D *hMCPrimaryPxUnWeighted = new TH1D("hMCPrimaryPxUnWeighted", "Primary Particle P_{x} UnWeighted", 300, -150 , 150);
/////////////////////////////////// Primary Particle Py  //////////////////////////////////////////
TH1D *hMCPrimaryPyUnWeighted = new TH1D("hMCPrimaryPyUnWeighted", "Primary Particle P_{y} UnWeighted", 300, -159 , 150);
/////////////////////////////////// Primary Particle Pz //////////////////////////////////////////
TH1D *hMCPrimaryPzUnWeighted = new TH1D("hMCPrimaryPzUnWeighted", "Primary Particle P_{z} UnWeighted", 250, 0 , 2500);

/////////////////////////////////// Primary Particle Process //////////////////////////////////////////
TH1D *hMCPrimaryProcess = new TH1D("hMCPrimaryProcess", "Primary Particle Process", 100, 0 , 10);

/////////////////////////////////// Primary End X vs Z Position //////////////////////////////////////////////
TH2D *hMCPrimaryEndXvsZ = new TH2D("hMCPrimaryEndXvsZ", "X_{f} vs Z_{f}", 600, -150, 450, 400, -200, 200);
/////////////////////////////////// Primary End Y vs Z Position //////////////////////////////////////////////
TH2D *hMCPrimaryEndYvsZ = new TH2D("hMCPrimaryEndYvsZ", "Y_{f} vs Z_{f}", 600, -150, 450, 200, -200, 200);

/////////////////////////////////// Energy Loss in the upstream region of the beamline ///////////////////////
TH1D *hMCELossUpstream = new TH1D("hMCELossUpstream", "Energy loss prior to entering the TPC", 1000, 0, 1000);

/////////////////////////////////// True Length //////////////////////////////////////////
TH1D *hMCTrueLength = new TH1D("hMCTrueLength", "#True Length of the Primary Particle inside the TPC", 200, 0 , 100);


// **********************************************************************************************************************



// ********************************************** RECONSTRUCTED INFORMATION **********************************************


/////////////////////////////////// Most Upstream Z point of tracks //////////////////////////////////////////
TH1D *hRecoMCUpstreamZPos = new TH1D("hRecoMCUpstreamZPos", "Most upstream spacepoint of all TPC Tracks", 20, 0, 10);

/////////////////////////////////// TPC Track Theta at the upstream point //////////////////////////////////////
TH1D *hRecoMCTPCTheta = new TH1D("hRecoMCTPCTheta", "TPC Track Theta", 180, 0, 90);

/////////////////////////////////// TPC Track Theta at the upstream point unweighted //////////////////////////////////////
TH1D *hRecoMCTPCThetaUnWeighted = new TH1D("hRecoMCTPCThetaUnWeighted", "TPC Track Theta", 180, 0, 90);

/////////////////////////////////// TPC Track Phi at the upstream point ///////////////////////////////////////
TH1D *hRecoMCTPCPhi = new TH1D("hRecoMCTPCPhi", "TPC Track Phi", 360, 0, 360);

/////////////////////////////////// TPC Track Phi at the upstream point unweighted ///////////////////////////////////////
TH1D *hRecoMCTPCPhiUnWeighted = new TH1D("hRecoMCTPCPhiUnWeighted", "TPC Track Phi", 360, 0, 360);

/////////////////////////////////// Wire Chamber Theta ////////////////////////////////////////////////////////
TH1D *hRecoMCWCTheta = new TH1D("hRecoMCWCTheta", "WCTrack Theta", 180, 0, 90);

/////////////////////////////////// Wire Chamber Theta unweighted ////////////////////////////////////////////////////////
TH1D *hRecoMCWCThetaUnWeighted = new TH1D("hRecoMCWCThetaUnWeighted", "WCTrack Theta", 180, 0, 90);

/////////////////////////////////// Wire Chamber Phi //////////////////////////////////////////////////////////
TH1D *hRecoMChWCPhi = new TH1D("hRecoMChWCPhi", "WCTrack Phi", 360, 0, 360);

/////////////////////////////////// Wire Chamber Phi unweighted //////////////////////////////////////////////////////////
TH1D *hRecoMChWCPhiUnWeighted = new TH1D("hRecoMChWCPhiUnWeighted", "WCTrack Phi", 360, 0, 360);

/////////////////////////////////// Delta WCTrack X ///////////////////////////////////////////////////////////
TH1D *hRecoMCDeltaWCTrkX = new TH1D("hRecoMCDeltaWCTrkX", "#Delta X TPC/WC Track", 160, -40, 40);

/////////////////////////////////// Delta WCTrack Y ///////////////////////////////////////////////////////////
TH1D *hRecoMCDeltaWCTrkY = new TH1D("hRecoMCDeltaWCTrkY", "#Delta Y TPC/WC Track", 160, -40, 40);

/////////////////////////////////// Alpha Between WC and TPC Tracks //////////////////////////////////////////
TH1D *hRecoMCAlpha = new TH1D("hRecoMCAlpha", "#alpha between WC and TPC Track", 90, 0, 90);

/////////////////////////////////// Number of Matched Tracks ////////////////////////////////////////////////
TH1D *hRecoMCNMatchTPCWCTrk = new TH1D("hRecoMCNMatchTPCWCTrk", "Number of matched TPC/WC Tracks", 20, 0, 10);

/////////////////////////////////// WCTRK Momentum Histogram (MeV) //////////////////////////////////////////
TH1D *hRecoMCWCTRKMomentum = new TH1D("hRecoMCWCTRKMomentum", "WCtrk Momentum (MeV)", 250, 0, 2500);

/////////////////////////////////// Initial Kinetic Energy (MeV) /////////////////////////////////////////////
TH1D *hRecoMCInitialKEMomentum = new TH1D("hRecoMCInitialKEMomentum", "Pion Initial Momentum (MeV)", 500, 0, 2500); 

/////////////////////////////////// Initial Kinetic Energy (MeV) Unweighted /////////////////////////////////////////////
TH1D *hRecoMCInitialKEMomentumUnWeighted = new TH1D("hRecoMCInitialKEMomentumUnWeighted", "Pion Initial Momentum (MeV)", 500, 0, 2500);

/////////////////////////////////// "Matched Track" dE/dX /////////////////////////////////////////////////////
TH1D *hRecoMCdEdX = new TH1D("hRecoMCdEdX", "Matched Track dE/dX", 500, 0, 50);

/////////////////////////////////// "Matched Track" dQ/dX /////////////////////////////////////////////////////
TH1D *hRecoMCdQdX = new TH1D("hRecoMCdQdX", "Matched Track dQ/dX", 2000, 0, 20000);

// -------------------------------------------------------------------------------------------------------------------------

/////////////////////////////////// "Matched Track" dE/dX in Q1 /////////////////////////////////////////////////////
TH1D *hMCRecodEdXQ1 = new TH1D("hMCRecodEdXQ1", "Matched Track dE/dX Q1", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX in Q2 /////////////////////////////////////////////////////
TH1D *hMCRecodEdXQ2 = new TH1D("hMCRecodEdXQ2", "Matched Track dE/dX Q2", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX in Q3 /////////////////////////////////////////////////////
TH1D *hMCRecodEdXQ3 = new TH1D("hMCRecodEdXQ3", "Matched Track dE/dX Q3", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX in Q4 /////////////////////////////////////////////////////
TH1D *hMCRecodEdXQ4 = new TH1D("hMCRecodEdXQ4", "Matched Track dE/dX Q4", 200, 0, 50);

/////////////////////////////////// "Matched Track" dQ/dX in Q1 /////////////////////////////////////////////////////
TH1D *hMCRecodQdXQ1 = new TH1D("hMCRecodQdXQ1", "Matched Track dQ/dX Q1", 2000, 0, 20000);

/////////////////////////////////// "Matched Track" dQ/dX in Q2 /////////////////////////////////////////////////////
TH1D *hMCRecodQdXQ2 = new TH1D("hMCRecodQdXQ2", "Matched Track dQ/dX Q2", 2000, 0, 20000);

/////////////////////////////////// "Matched Track" dQ/dX in Q3 /////////////////////////////////////////////////////
TH1D *hMCRecodQdXQ3 = new TH1D("hMCRecodQdXQ3", "Matched Track dQ/dX Q3", 2000, 0, 20000);

/////////////////////////////////// "Matched Track" dQ/dX in Q4 /////////////////////////////////////////////////////
TH1D *hMCRecodQdXQ4 = new TH1D("hMCRecodQdXQ4", "Matched Track dQ/dX Q4", 2000, 0, 20000);


// --------------------------------------------------------------------------------------------------------------------------


/////////////////////////////////// "Matched Track" dE/dX (Fixed) /////////////////////////////////////////////////////
TH1D *hRecoMCdEdXFixed = new TH1D("hRecoMCdEdXFixed", "Matched Track dE/dX", 200, 0, 50);

/////////////////////////////////// "Matched Track" Residual Range //////////////////////////////////////////
TH1D *hRecoMCPionRR = new TH1D("hRecoMCPionRR", "Matched Track Residual Range", 400, -100, 100);

/////////////////////////////////// "Matched Track" Track Pitch //////////////////////////////////////////
TH1D *hRecoMCPionTrkPitch = new TH1D("hRecoMCPionTrkPitch", "Matched Track Pitch", 1000, 0, 5);

///////////////////////////////// "Matched Track" dE/dX vs RR ///////////////////////////////////////////////
TH2D *hRecoMCdEdXvsRR = new TH2D("hRecoMCdEdXvsRR", "dE/dX vs Residual Range",200, 0, 100, 200, 0, 50);

///////////////////////////////// "Matched Track" dE/dX vs RR (Fixed) ///////////////////////////////////////////////
TH2D *hRecoMCdEdXvsRRFix = new TH2D("hRecoMCdEdXvsRRFix", "dE/dX vs Residual Range",200, 0, 100, 200, 0, 50);

///////////////////////////////// "Matched Track" dE/dX vs RR (Fixed) ///////////////////////////////////////////////
TH2D *hRecoMCdEdXvsRRFixedDecCap = new TH2D("hRecoMCdEdXvsRRFixedDecCap", "dE/dX vs Residual Range for Capture/Decay",200, 0, 100, 200, 0, 50);

//////////////////////////////// "Low Momentum Track" PIDA (no cuts) ///////////////////////////////////////
TH1D *hRecoMCLowMomentumTrkPIDA = new TH1D("hRecoMCLowMomentumTrkPIDA", "Low Momentum PIDA", 30, 0, 30);

//////////////////////////////// "Low Momentum Track" PIDA (for stopping) ///////////////////////////////////////
TH1D *hRecoMCLowMomentumTrkPIDACapDec = new TH1D("hRecoMCLowMomentumTrkPIDACapDec", "Low Momentum PIDA", 30, 0, 30);


/////////////////////////////////// Reconstructed Length //////////////////////////////////////////
TH1D *hRecoLength = new TH1D("hRecoLength", "Reconstructed Length of the Primary Particle inside the TPC", 200, 0 , 100);


/////////////////////////////////// Initial Track X Position ////////////////////////////////////////////////////////
TH1D *hRecoMCTrkInitialX = new TH1D("hRecoMCTrkInitialX", "Initial X Position of the TPC Track", 100, 0, 50);

/////////////////////////////////// Initial Track X Position  Unweighted ////////////////////////////////////////////////////////
TH1D *hRecoMCTrkInitialXUnweighted = new TH1D("hRecoMCTrkInitialXUnweighted", "Initial X Position of the TPC Track", 100, 0, 50);

/////////////////////////////////// Initial Track Y Position ////////////////////////////////////////////////////////
TH1D *hRecoMCTrkInitialY = new TH1D("hRecoMCTrkInitialY", "Initial Y Position of the TPC Track", 100, -25, 25);

/////////////////////////////////// Initial Track Y Position Unweighted ////////////////////////////////////////////////////////
TH1D *hRecoMCTrkInitialYUnweighted = new TH1D("hRecoMCTrkInitialYUnweighted", "Initial Y Position of the TPC Track", 100, -25, 25);



TH2D *DeltaEvsPIDAAll = new TH2D("DeltaEvsPIDAAll", " #Delta E vs PIDA All", 30,0, 30, 100, 0, 100);
TH2D *DeltaEvsPIDADecayCap = new TH2D("DeltaEvsPIDADecayCap", " #Delta E vs PIDA All", 30,0, 30, 100, 0, 100);


// ###############################################################################
// ### Note: The binning (number and range) needs to match between these plots ###
// ###############################################################################

/////////////////////////////////// "Pion" Incident to the slab Kinetic Energy (MeV) //////////////////////////////////////////
TH1D *hRecoMCIncidentKE = new TH1D("hRecoMCIncidentKE", "Incident Kinetic Energy (MeV)", 40, 0, 2000);

/////////////////////////////////// "Pion" Incident to the slab Kinetic Energy (MeV) //////////////////////////////////////////
TH1D *hRecoMCIncidentKEunweighted = new TH1D("hRecoMCIncidentKEunweighted", "Incident Kinetic Energy (MeV) (unweighted)", 40, 0, 2000);

/////////////////////////////////// "Pion" Exiting the slab Kinetic Energy (MeV) /////////////////////////////////////////////
TH1D *hRecoMCInteractingKE = new TH1D("hRecoMCInteractingKE", "Interacting Kinetic Energy (MeV)", 40, 0, 2000);

/////////////////////////////////// "Pion" Exiting the slab Kinetic Energy (MeV) (Unweighted) ////////////////////////////////
TH1D *hRecoMCInteractingKEunweighted = new TH1D("hRecoMCInteractingKEunweighted", "Interacting Kinetic Energy (MeV) (unweighted)", 40, 0, 2000);


/////////////////////////////////// Cross-Section ////////////////////////////////////////////////////////////////////////////
TH1F *fCrossSection = new TH1F("fCrossSection", "Cross-Section", 40, 0, 2000);

void PionMCDD::Loop()
{
if (fChain == 0) return;
Long64_t nentries = fChain->GetEntriesFast();
Long64_t nbytes = 0, nb = 0;


// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// 					  Putting Flexible Cuts here
// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// ### Putting in the particle mass that is being simulated here ###
// ###    which is used when calculating the energy loss before  ###
// ###                       entering the TPC                    ###

float particle_mass = 139.57; //<---Mass of Pion in MeV


// ##########################################################
// ### Preliminary TOF Cut (sets the bounds for TOF Reco) ###
// ##########################################################
double LowerTOFGoodReco = 0;
double UpperTOFGoodReco = 30;

// ###################################################
// ### Setting the Wire Chamber momentum range and ###
// ###     the TOF range for good particle ID      ###
// ###################################################
double LowerWCTrkMomentum = 100.0; //<--(MeV)
double HighWCTrkMomentum  = 1500.0;//<--(MeV)

double LowerTOF = 10.0; //<--(ns)
double HighTOF  = 25.0; //<--(ns)

// #####################################################
// ### Number of centimeters in Z we require a track ###
// ### to have a space point within (default = 2 cm) ###
// #####################################################
double FirstSpacePointZPos = 2.0;


// ########################################################
// ### Delta X Between Wire Chamber Track and TPC Track ###
// ########################################################
double DeltaXLowerBound = -4.0;
double DeltaXUpperBound = 6.0;

// ########################################################
// ### Delta Y Between Wire Chamber Track and TPC Track ###
// ########################################################
double DeltaYLowerBound = -5.0;
double DeltaYUpperBound = 5.0;


// ########################################################################
// ### Fiducial Boundry Cuts (used to determine if a track is stopping) ###
// ########################################################################
double XLowerFid = 0;
double XUpperFid = 47;

double YLowerFid = -20;
double YUpperFid = 20;

double ZLowerFid = 0;
double ZUpperFid = 90;


// ########################################################################
// ### Definition of the upstream part of the TPC where we restrict the ###
// ###             number of tracks which can be present                ###
// ########################################################################
int UpperPartOfTPC = 14.0;

// #####################################################
// ### Number of tracks allowed in the upstream part ###
// #####################################################
int nLowZTracksAllowed = 4;


// #################################################################################
// ### Making shower Cut (ShortTkLength) and the number of short tracks we allow ###
// #################################################################################
double ShortTkLength = 5.0;
int nShortTracksAllowed = 2;


// ############################
// ### Alpha Cut in degrees ###
// ############################
double alphaCut = 10;

// ### Setting the global event weight based on ###
// ###   open box WCTrack momentum spectrum     ###  
float EventWeight = 1.0;

// #################################################   
// ### True  = Use the momentum based weighting  ###
// ### False = Don't weight events               ###
// #################################################
bool UseEventWeight = false;

bool ScaleByPz = false;

// === Only one of these should be set to true ===
bool RunIScale = false;
bool RunIIScale = false;
bool CombinedScale = false;



// #####################################
// ### Scale the dE/dX to match data ###
// ### True = apply scale factor     ###
// ### False = don't apply scaling   ###
// #####################################
bool RunIScaledEdX = false;

float RunIScaleFactor     = 1.0909;
float RunIdQdXScaleFactor = 0.579038796;

bool RunIIScaledEdX = false;

float RunIIScaleFactor     = 1.0;
float RunIIdQdXScaleFactor = 1.0;

// ######################################################
// ### Choose whether or not to fix the calo problems ###
// ###  associated with ordering of the calo points   ###
// ###                                                ###
// ### True  = Use the fix                            ###
// ### False = Don't use the fix                      ###
// ######################################################
bool FixCaloIssue_Reordering = false; 


// ######################################################
// ### Choose whether or not to fix the calo problems ###
// ###   associated with large dE/dX fluctuations     ###
// ###                                                ###
// ### True  = Use the fix                            ###
// ### False = Don't use the fix                      ###
// ######################################################
bool FixCaloIssue_ExtremeFluctuation = false;     

// ########################################################
// ###   Choose whether or not to fix the calo problems ###
// ### associated with slightly large dE/dX fluctuations###
// ###                                                  ###
// ### True  = Use the fix                              ###
// ### False = Don't use the fix                        ###
// ########################################################
bool FixCaloIssue_LessExtremeFluctuation = false;  


// ##########################################################
// ### Choose whether to remove identified stopping pions ###
// ###                                                    ###
// ### True  = Remove stoppping tagged tracks             ###
// ### False = Don't remove stopping tagged tracks        ###
// ##########################################################
bool RemoveStopping = false;

// ###############################################
// ###  Only keeping through going reco Tracks ###
// ###  True = Only keep through going tracks  ###
// ###   False = Keep all types of tracks      ###
// ###############################################
bool SelectThroughGoing = false;
   


// ###################################################
// ### Setting a flag to print out bunch of checks ###
// ###################################################
bool VERBOSE = false; 



// ###############################################
// ### Creating a file to output my histograms ###
// ###############################################

TFile myfile("../histoROOTfiles_forPlots/PionMCDD_RunI_OutOfTheBox.root","RECREATE");

    

// ----------------------------------------------------------------
// Create the cross section from the incident and interaction plots
// ----------------------------------------------------------------

// ### The assumed energy loss between the cryostat and the TPC ###
float entryTPCEnergyLoss = 40.; //MeV

// ### The assumed mass of the incident particle (here we assume a pion) ###
float mass = 139.57;

float rho = 1396; //kg/m^3
//  float cm_per_m = 100;
float molar_mass = 39.95; //g/mol
float g_per_kg = 1000; 
float avogadro = 6.022e+23; //number/mol
float number_density = rho*g_per_kg/molar_mass*avogadro;
float slab_width = 0.0045;//in m

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// ##########################################################
// ### Putting in some counters for event reduction table ###
// ##########################################################
int nTotalEvents = 0, nEvtsWCTrack = 0, nEvtsWCTrackMatch = 0, nEvtsTrackZPos = 0, nEvntsTPC = 0;
int nEvtsTOF = 0, nEvtsPID = 0, nLowZTrkEvents = 0;
int nNonShowerEvents = 0, nEvtsGoodMC = 0;



// ###############################
// ### Looping over all events ###
// ###############################
for (Long64_t jentry=0; jentry<nentries;jentry++) 
//for (Long64_t jentry=0; jentry<20000;jentry++)
   {
   
   // #########################
   // ### Loading the event ###
   // #########################
   Long64_t ientry = LoadTree(jentry);
   if (ientry < 0) break;
   nb = fChain->GetEntry(jentry);   nbytes += nb;
   
   // #############################
   // ### Counting Total Events ###
   // #############################
   nTotalEvents++;
   
   // === Outputting every nEvents to the screen ===
   if(nTotalEvents % 500 == 0){std::cout<<"Event = "<<nTotalEvents<<std::endl;}
   
   //=======================================================================================================================
   //					      GEANT 4 Information
   //=======================================================================================================================
   // ##################################################
   // ### Defining some useful variables we will use ###
   // ##################################################
   int nG4Primary = 0;
   int nG4TrajPoints = 0;
   
   float g4Primary_X0[100] = {0.}, g4Primary_Y0[100] = {0.}, g4Primary_Z0[100] = {0.};
   float g4Primary_ProjX0[100] = {0.}, g4Primary_ProjY0[100] = {0.}, g4Primary_ProjZ0[100] = {0.};
   
   float g4Primary_Xf[100] = {0.}, g4Primary_Yf[100] = {0.}, g4Primary_Zf[100] = {0.};
   float g4Primary_Px[100] = {0.}, g4Primary_Py[100] = {0.}, g4Primary_Pz[100] = {0.};
   
   int g4Primary_TrkID[100] = {999}, g4PrimaryProcess[100] = {0};
   
   int nG4PriTrj = 0;
   float g4Primary_TrueTrjX[10][10000] = {0.}, g4Primary_TrueTrjY[10][10000] = {0.}, g4Primary_TrueTrjZ[10][10000] = {0.};
   float g4Primary_TrueTrjPx[10][10000] = {0.}, g4Primary_TrueTrjPy[10][10000] = {0.}, g4Primary_TrueTrjPz[10][10000] = {0.};
   
   
   float TrueLength = 0;
   float RecoLength = 0;
   // ##########################################
   // ### Loop over all the GEANT4 particles ###
   // ##########################################
   for (int iG4 = 0; iG4 < geant_list_size; iG4++)
      {
      // #####################################################
      // ### If this is a primary particle then look at it ###
      // #####################################################
      if(process_primary[iG4] == 1)
         {

	 
	 // ### Recording information for use later ###
	 g4Primary_X0[nG4Primary] = StartPointx[iG4];
	 g4Primary_Y0[nG4Primary] = StartPointy[iG4];
	 g4Primary_Z0[nG4Primary] = StartPointz[iG4];
	 
	 g4Primary_Xf[nG4Primary] = EndPointx[iG4];
	 g4Primary_Yf[nG4Primary] = EndPointy[iG4];
	 g4Primary_Zf[nG4Primary] = EndPointz[iG4];
	 
	 g4Primary_Px[nG4Primary] = Px[iG4] * 1000; //<---Converting to MeV
	 g4Primary_Py[nG4Primary] = Py[iG4] * 1000; //<---Converting to MeV
	 g4Primary_Pz[nG4Primary] = Pz[iG4] * 1000; //<---Converting to MeV
	 
	
	 
	 // #############################################################
         // ### Calculating the momentum from the MC Primary Particle ###
         // #############################################################
         float momentumScale = sqrt( (g4Primary_Px[nG4Primary]*g4Primary_Px[nG4Primary]) + 
	                        (g4Primary_Py[nG4Primary]*g4Primary_Py[nG4Primary]) + 
				(g4Primary_Pz[nG4Primary]*g4Primary_Pz[nG4Primary]) );
				
	 float kineticEnergyScale = pow( (momentumScale*momentumScale) + (mass*mass) ,0.5) - mass;
	 
	 //std::cout<<"kineticEnergyScale = "<<kineticEnergyScale<<std::endl;
	 
	 // ### Choosing to scale by setting Event weight ### 
	 if(UseEventWeight)
	    {
	    
	    // ###########################################################
	    // ### Use the scalings derived from the WC-Track Momentum ###
	    // ############################################################
	    if(ScaleByPz && RunIScale)
	        {
		if(g4Primary_Pz[nG4Primary] > 0 && g4Primary_Pz[nG4Primary] < 10) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 10 && g4Primary_Pz[nG4Primary] < 20) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 20 && g4Primary_Pz[nG4Primary] < 30) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 30 && g4Primary_Pz[nG4Primary] < 40) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 40 && g4Primary_Pz[nG4Primary] < 50) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 50 && g4Primary_Pz[nG4Primary] < 60) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 60 && g4Primary_Pz[nG4Primary] < 70) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 70 && g4Primary_Pz[nG4Primary] < 80) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 80 && g4Primary_Pz[nG4Primary] < 90) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 90 && g4Primary_Pz[nG4Primary] < 100) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 100 && g4Primary_Pz[nG4Primary] < 110) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 110 && g4Primary_Pz[nG4Primary] < 120) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 120 && g4Primary_Pz[nG4Primary] < 130) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 130 && g4Primary_Pz[nG4Primary] < 140) {EventWeight = 0.0228321;}
		if(g4Primary_Pz[nG4Primary] > 140 && g4Primary_Pz[nG4Primary] < 150) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 150 && g4Primary_Pz[nG4Primary] < 160) {EventWeight = 0.0442183;}
		if(g4Primary_Pz[nG4Primary] > 160 && g4Primary_Pz[nG4Primary] < 170) {EventWeight = 0.0899994;}
		if(g4Primary_Pz[nG4Primary] > 170 && g4Primary_Pz[nG4Primary] < 180) {EventWeight = 0.179999;}
		if(g4Primary_Pz[nG4Primary] > 180 && g4Primary_Pz[nG4Primary] < 190) {EventWeight = 0.055386;}
		if(g4Primary_Pz[nG4Primary] > 190 && g4Primary_Pz[nG4Primary] < 200) {EventWeight = 0.0328284;}
		if(g4Primary_Pz[nG4Primary] > 200 && g4Primary_Pz[nG4Primary] < 210) {EventWeight = 0.0831581;}
		if(g4Primary_Pz[nG4Primary] > 210 && g4Primary_Pz[nG4Primary] < 220) {EventWeight = 0.105186;}
		if(g4Primary_Pz[nG4Primary] > 220 && g4Primary_Pz[nG4Primary] < 230) {EventWeight = 0.266505;}
		if(g4Primary_Pz[nG4Primary] > 230 && g4Primary_Pz[nG4Primary] < 240) {EventWeight = 0.311757;}
		if(g4Primary_Pz[nG4Primary] > 240 && g4Primary_Pz[nG4Primary] < 250) {EventWeight = 0.404355;}
		if(g4Primary_Pz[nG4Primary] > 250 && g4Primary_Pz[nG4Primary] < 260) {EventWeight = 0.584698;}
		if(g4Primary_Pz[nG4Primary] > 260 && g4Primary_Pz[nG4Primary] < 270) {EventWeight = 0.566496;}
		if(g4Primary_Pz[nG4Primary] > 270 && g4Primary_Pz[nG4Primary] < 280) {EventWeight = 0.822099;}
		if(g4Primary_Pz[nG4Primary] > 280 && g4Primary_Pz[nG4Primary] < 290) {EventWeight = 0.573374;}
		if(g4Primary_Pz[nG4Primary] > 290 && g4Primary_Pz[nG4Primary] < 300) {EventWeight = 0.781806;}
		if(g4Primary_Pz[nG4Primary] > 300 && g4Primary_Pz[nG4Primary] < 310) {EventWeight = 0.581851;}
		if(g4Primary_Pz[nG4Primary] > 310 && g4Primary_Pz[nG4Primary] < 320) {EventWeight = 0.526497;}
		if(g4Primary_Pz[nG4Primary] > 320 && g4Primary_Pz[nG4Primary] < 330) {EventWeight = 0.562204;}
		if(g4Primary_Pz[nG4Primary] > 330 && g4Primary_Pz[nG4Primary] < 340) {EventWeight = 0.523858;}
		if(g4Primary_Pz[nG4Primary] > 340 && g4Primary_Pz[nG4Primary] < 350) {EventWeight = 0.640511;}
		if(g4Primary_Pz[nG4Primary] > 350 && g4Primary_Pz[nG4Primary] < 360) {EventWeight = 0.598169;}
		if(g4Primary_Pz[nG4Primary] > 360 && g4Primary_Pz[nG4Primary] < 370) {EventWeight = 0.794736;}
		if(g4Primary_Pz[nG4Primary] > 370 && g4Primary_Pz[nG4Primary] < 380) {EventWeight = 0.628037;}
		if(g4Primary_Pz[nG4Primary] > 380 && g4Primary_Pz[nG4Primary] < 390) {EventWeight = 0.857005;}
		if(g4Primary_Pz[nG4Primary] > 390 && g4Primary_Pz[nG4Primary] < 400) {EventWeight = 0.893923;}
		if(g4Primary_Pz[nG4Primary] > 400 && g4Primary_Pz[nG4Primary] < 410) {EventWeight = 0.920314;}
		if(g4Primary_Pz[nG4Primary] > 410 && g4Primary_Pz[nG4Primary] < 420) {EventWeight = 0.815078;}
		if(g4Primary_Pz[nG4Primary] > 420 && g4Primary_Pz[nG4Primary] < 430) {EventWeight = 1.00009;}
		if(g4Primary_Pz[nG4Primary] > 430 && g4Primary_Pz[nG4Primary] < 440) {EventWeight = 0.707796;}
		if(g4Primary_Pz[nG4Primary] > 440 && g4Primary_Pz[nG4Primary] < 450) {EventWeight = 0.782991;}
		if(g4Primary_Pz[nG4Primary] > 450 && g4Primary_Pz[nG4Primary] < 460) {EventWeight = 0.618758;}
		if(g4Primary_Pz[nG4Primary] > 460 && g4Primary_Pz[nG4Primary] < 470) {EventWeight = 0.676402;}
		if(g4Primary_Pz[nG4Primary] > 470 && g4Primary_Pz[nG4Primary] < 480) {EventWeight = 0.78863;}
		if(g4Primary_Pz[nG4Primary] > 480 && g4Primary_Pz[nG4Primary] < 490) {EventWeight = 0.587439;}
		if(g4Primary_Pz[nG4Primary] > 490 && g4Primary_Pz[nG4Primary] < 500) {EventWeight = 0.54913;}
		if(g4Primary_Pz[nG4Primary] > 500 && g4Primary_Pz[nG4Primary] < 510) {EventWeight = 0.591537;}
		if(g4Primary_Pz[nG4Primary] > 510 && g4Primary_Pz[nG4Primary] < 520) {EventWeight = 0.484767;}
		if(g4Primary_Pz[nG4Primary] > 520 && g4Primary_Pz[nG4Primary] < 530) {EventWeight = 0.711151;}
		if(g4Primary_Pz[nG4Primary] > 530 && g4Primary_Pz[nG4Primary] < 540) {EventWeight = 0.688821;}
		if(g4Primary_Pz[nG4Primary] > 540 && g4Primary_Pz[nG4Primary] < 550) {EventWeight = 0.698631;}
		if(g4Primary_Pz[nG4Primary] > 550 && g4Primary_Pz[nG4Primary] < 560) {EventWeight = 0.602613;}
		if(g4Primary_Pz[nG4Primary] > 560 && g4Primary_Pz[nG4Primary] < 570) {EventWeight = 0.717226;}
		if(g4Primary_Pz[nG4Primary] > 570 && g4Primary_Pz[nG4Primary] < 580) {EventWeight = 0.861487;}
		if(g4Primary_Pz[nG4Primary] > 580 && g4Primary_Pz[nG4Primary] < 590) {EventWeight = 0.861546;}
		if(g4Primary_Pz[nG4Primary] > 590 && g4Primary_Pz[nG4Primary] < 600) {EventWeight = 0.828745;}
		if(g4Primary_Pz[nG4Primary] > 600 && g4Primary_Pz[nG4Primary] < 610) {EventWeight = 0.879562;}
		if(g4Primary_Pz[nG4Primary] > 610 && g4Primary_Pz[nG4Primary] < 620) {EventWeight = 0.776497;}
		if(g4Primary_Pz[nG4Primary] > 620 && g4Primary_Pz[nG4Primary] < 630) {EventWeight = 0.723076;}
		if(g4Primary_Pz[nG4Primary] > 630 && g4Primary_Pz[nG4Primary] < 640) {EventWeight = 0.719098;}
		if(g4Primary_Pz[nG4Primary] > 640 && g4Primary_Pz[nG4Primary] < 650) {EventWeight = 0.827812;}
		if(g4Primary_Pz[nG4Primary] > 650 && g4Primary_Pz[nG4Primary] < 660) {EventWeight = 0.651954;}
		if(g4Primary_Pz[nG4Primary] > 660 && g4Primary_Pz[nG4Primary] < 670) {EventWeight = 0.862191;}
		if(g4Primary_Pz[nG4Primary] > 670 && g4Primary_Pz[nG4Primary] < 680) {EventWeight = 0.810761;}
		if(g4Primary_Pz[nG4Primary] > 680 && g4Primary_Pz[nG4Primary] < 690) {EventWeight = 0.736738;}
		if(g4Primary_Pz[nG4Primary] > 690 && g4Primary_Pz[nG4Primary] < 700) {EventWeight = 0.753865;}
		if(g4Primary_Pz[nG4Primary] > 700 && g4Primary_Pz[nG4Primary] < 710) {EventWeight = 0.594639;}
		if(g4Primary_Pz[nG4Primary] > 710 && g4Primary_Pz[nG4Primary] < 720) {EventWeight = 0.587361;}
		if(g4Primary_Pz[nG4Primary] > 720 && g4Primary_Pz[nG4Primary] < 730) {EventWeight = 0.731766;}
		if(g4Primary_Pz[nG4Primary] > 730 && g4Primary_Pz[nG4Primary] < 740) {EventWeight = 0.633571;}
		if(g4Primary_Pz[nG4Primary] > 740 && g4Primary_Pz[nG4Primary] < 750) {EventWeight = 0.588567;}
		if(g4Primary_Pz[nG4Primary] > 750 && g4Primary_Pz[nG4Primary] < 760) {EventWeight = 0.39815;}
		if(g4Primary_Pz[nG4Primary] > 760 && g4Primary_Pz[nG4Primary] < 770) {EventWeight = 0.392117;}
		if(g4Primary_Pz[nG4Primary] > 770 && g4Primary_Pz[nG4Primary] < 780) {EventWeight = 0.581851;}
		if(g4Primary_Pz[nG4Primary] > 780 && g4Primary_Pz[nG4Primary] < 790) {EventWeight = 0.47054;}
		if(g4Primary_Pz[nG4Primary] > 790 && g4Primary_Pz[nG4Primary] < 800) {EventWeight = 0.404462;}
		if(g4Primary_Pz[nG4Primary] > 800 && g4Primary_Pz[nG4Primary] < 810) {EventWeight = 0.44199;}
		if(g4Primary_Pz[nG4Primary] > 810 && g4Primary_Pz[nG4Primary] < 820) {EventWeight = 0.464536;}
		if(g4Primary_Pz[nG4Primary] > 820 && g4Primary_Pz[nG4Primary] < 830) {EventWeight = 0.383423;}
		if(g4Primary_Pz[nG4Primary] > 830 && g4Primary_Pz[nG4Primary] < 840) {EventWeight = 0.396822;}
		if(g4Primary_Pz[nG4Primary] > 840 && g4Primary_Pz[nG4Primary] < 850) {EventWeight = 0.400831;}
		if(g4Primary_Pz[nG4Primary] > 850 && g4Primary_Pz[nG4Primary] < 860) {EventWeight = 0.23581;}
		if(g4Primary_Pz[nG4Primary] > 860 && g4Primary_Pz[nG4Primary] < 870) {EventWeight = 0.332212;}
		if(g4Primary_Pz[nG4Primary] > 870 && g4Primary_Pz[nG4Primary] < 880) {EventWeight = 0.296505;}
		if(g4Primary_Pz[nG4Primary] > 880 && g4Primary_Pz[nG4Primary] < 890) {EventWeight = 0.280943;}
		if(g4Primary_Pz[nG4Primary] > 890 && g4Primary_Pz[nG4Primary] < 900) {EventWeight = 0.304001;}
		if(g4Primary_Pz[nG4Primary] > 900 && g4Primary_Pz[nG4Primary] < 910) {EventWeight = 0.261096;}
		if(g4Primary_Pz[nG4Primary] > 910 && g4Primary_Pz[nG4Primary] < 920) {EventWeight = 0.177625;}
		if(g4Primary_Pz[nG4Primary] > 920 && g4Primary_Pz[nG4Primary] < 930) {EventWeight = 0.194882;}
		if(g4Primary_Pz[nG4Primary] > 930 && g4Primary_Pz[nG4Primary] < 940) {EventWeight = 0.160424;}
		if(g4Primary_Pz[nG4Primary] > 940 && g4Primary_Pz[nG4Primary] < 950) {EventWeight = 0.119059;}
		if(g4Primary_Pz[nG4Primary] > 950 && g4Primary_Pz[nG4Primary] < 960) {EventWeight = 0.0738732;}
		if(g4Primary_Pz[nG4Primary] > 960 && g4Primary_Pz[nG4Primary] < 970) {EventWeight = 0.122843;}
		if(g4Primary_Pz[nG4Primary] > 970 && g4Primary_Pz[nG4Primary] < 980) {EventWeight = 0.0734554;}
		if(g4Primary_Pz[nG4Primary] > 980 && g4Primary_Pz[nG4Primary] < 990) {EventWeight = 0.0963064;}
		if(g4Primary_Pz[nG4Primary] > 990 && g4Primary_Pz[nG4Primary] < 1000) {EventWeight = 0.0747233;}
		if(g4Primary_Pz[nG4Primary] > 1000 && g4Primary_Pz[nG4Primary] < 1010) {EventWeight = 0.0635119;}
		if(g4Primary_Pz[nG4Primary] > 1010 && g4Primary_Pz[nG4Primary] < 1020) {EventWeight = 0.112864;}
		if(g4Primary_Pz[nG4Primary] > 1020 && g4Primary_Pz[nG4Primary] < 1030) {EventWeight = 0.0575049;}
		if(g4Primary_Pz[nG4Primary] > 1030 && g4Primary_Pz[nG4Primary] < 1040) {EventWeight = 0.0363169;}
		if(g4Primary_Pz[nG4Primary] > 1040 && g4Primary_Pz[nG4Primary] < 1050) {EventWeight = 0.0481532;}
		if(g4Primary_Pz[nG4Primary] > 1050 && g4Primary_Pz[nG4Primary] < 1060) {EventWeight = 0.025676;}
		if(g4Primary_Pz[nG4Primary] > 1060 && g4Primary_Pz[nG4Primary] < 1070) {EventWeight = 0.0490813;}
		if(g4Primary_Pz[nG4Primary] > 1070 && g4Primary_Pz[nG4Primary] < 1080) {EventWeight = 0.0256152;}
		if(g4Primary_Pz[nG4Primary] > 1080 && g4Primary_Pz[nG4Primary] < 1090) {EventWeight = 0.0496442;}
		if(g4Primary_Pz[nG4Primary] > 1090 && g4Primary_Pz[nG4Primary] < 1100) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1100 && g4Primary_Pz[nG4Primary] < 1110) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1110 && g4Primary_Pz[nG4Primary] < 1120) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1120 && g4Primary_Pz[nG4Primary] < 1130) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1130 && g4Primary_Pz[nG4Primary] < 1140) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1140 && g4Primary_Pz[nG4Primary] < 1150) {EventWeight = 0.0420017;}
		if(g4Primary_Pz[nG4Primary] > 1150 && g4Primary_Pz[nG4Primary] < 1160) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1160 && g4Primary_Pz[nG4Primary] < 1170) {EventWeight = 0.0124253;}
		if(g4Primary_Pz[nG4Primary] > 1170 && g4Primary_Pz[nG4Primary] < 1180) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1180 && g4Primary_Pz[nG4Primary] < 1190) {EventWeight = 0.012838;}
		if(g4Primary_Pz[nG4Primary] > 1190 && g4Primary_Pz[nG4Primary] < 1200) {EventWeight = 0.0126726;}
		if(g4Primary_Pz[nG4Primary] > 1200 && g4Primary_Pz[nG4Primary] < 1210) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1210 && g4Primary_Pz[nG4Primary] < 1220) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1220 && g4Primary_Pz[nG4Primary] < 1230) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1230 && g4Primary_Pz[nG4Primary] < 1240) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1240 && g4Primary_Pz[nG4Primary] < 1250) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1250 && g4Primary_Pz[nG4Primary] < 1260) {EventWeight = 0.0124396;}
		if(g4Primary_Pz[nG4Primary] > 1260 && g4Primary_Pz[nG4Primary] < 1270) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1270 && g4Primary_Pz[nG4Primary] < 1280) {EventWeight = 0.0237856;}
		if(g4Primary_Pz[nG4Primary] > 1280 && g4Primary_Pz[nG4Primary] < 1290) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1290 && g4Primary_Pz[nG4Primary] < 1300) {EventWeight = 0.0121737;}
		if(g4Primary_Pz[nG4Primary] > 1300 && g4Primary_Pz[nG4Primary] < 1310) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1310 && g4Primary_Pz[nG4Primary] < 1320) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1320 && g4Primary_Pz[nG4Primary] < 1330) {EventWeight = 0.0251392;}
		if(g4Primary_Pz[nG4Primary] > 1330 && g4Primary_Pz[nG4Primary] < 1340) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1340 && g4Primary_Pz[nG4Primary] < 1350) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1350 && g4Primary_Pz[nG4Primary] < 1360) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1360 && g4Primary_Pz[nG4Primary] < 1370) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1370 && g4Primary_Pz[nG4Primary] < 1380) {EventWeight = 0.0254048;}
		if(g4Primary_Pz[nG4Primary] > 1380 && g4Primary_Pz[nG4Primary] < 1390) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1390 && g4Primary_Pz[nG4Primary] < 1400) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1400 && g4Primary_Pz[nG4Primary] < 1410) {EventWeight = 0.013166;}
		if(g4Primary_Pz[nG4Primary] > 1410 && g4Primary_Pz[nG4Primary] < 1420) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1420 && g4Primary_Pz[nG4Primary] < 1430) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1430 && g4Primary_Pz[nG4Primary] < 1440) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1440 && g4Primary_Pz[nG4Primary] < 1450) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1450 && g4Primary_Pz[nG4Primary] < 1460) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1460 && g4Primary_Pz[nG4Primary] < 1470) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1470 && g4Primary_Pz[nG4Primary] < 1480) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1480 && g4Primary_Pz[nG4Primary] < 1490) {EventWeight = 0.0125842;}
		if(g4Primary_Pz[nG4Primary] > 1490 && g4Primary_Pz[nG4Primary] < 1500) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1500 && g4Primary_Pz[nG4Primary] < 1510) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1510 && g4Primary_Pz[nG4Primary] < 1520) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1520 && g4Primary_Pz[nG4Primary] < 1530) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1530 && g4Primary_Pz[nG4Primary] < 1540) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1540 && g4Primary_Pz[nG4Primary] < 1550) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1550 && g4Primary_Pz[nG4Primary] < 1560) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1560 && g4Primary_Pz[nG4Primary] < 1570) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1570 && g4Primary_Pz[nG4Primary] < 1580) {EventWeight = 0.0126726;}
		if(g4Primary_Pz[nG4Primary] > 1580 && g4Primary_Pz[nG4Primary] < 1590) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1590 && g4Primary_Pz[nG4Primary] < 1600) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1600 && g4Primary_Pz[nG4Primary] < 1610) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1610 && g4Primary_Pz[nG4Primary] < 1620) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1620 && g4Primary_Pz[nG4Primary] < 1630) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1630 && g4Primary_Pz[nG4Primary] < 1640) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1640 && g4Primary_Pz[nG4Primary] < 1650) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1650 && g4Primary_Pz[nG4Primary] < 1660) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1660 && g4Primary_Pz[nG4Primary] < 1670) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1670 && g4Primary_Pz[nG4Primary] < 1680) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1680 && g4Primary_Pz[nG4Primary] < 1690) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1690 && g4Primary_Pz[nG4Primary] < 1700) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1700 && g4Primary_Pz[nG4Primary] < 1710) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1710 && g4Primary_Pz[nG4Primary] < 1720) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1720 && g4Primary_Pz[nG4Primary] < 1730) {EventWeight = 0.0127925;}
		if(g4Primary_Pz[nG4Primary] > 1730 && g4Primary_Pz[nG4Primary] < 1740) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1740 && g4Primary_Pz[nG4Primary] < 1750) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1750 && g4Primary_Pz[nG4Primary] < 1760) {EventWeight = 0.0125989;}
		if(g4Primary_Pz[nG4Primary] > 1760 && g4Primary_Pz[nG4Primary] < 1770) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1770 && g4Primary_Pz[nG4Primary] < 1780) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1780 && g4Primary_Pz[nG4Primary] < 1790) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1790 && g4Primary_Pz[nG4Primary] < 1800) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1800 && g4Primary_Pz[nG4Primary] < 1810) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1810 && g4Primary_Pz[nG4Primary] < 1820) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1820 && g4Primary_Pz[nG4Primary] < 1830) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1830 && g4Primary_Pz[nG4Primary] < 1840) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1840 && g4Primary_Pz[nG4Primary] < 1850) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1850 && g4Primary_Pz[nG4Primary] < 1860) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1860 && g4Primary_Pz[nG4Primary] < 1870) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1870 && g4Primary_Pz[nG4Primary] < 1880) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1880 && g4Primary_Pz[nG4Primary] < 1890) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1890 && g4Primary_Pz[nG4Primary] < 1900) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1900 && g4Primary_Pz[nG4Primary] < 1910) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1910 && g4Primary_Pz[nG4Primary] < 1920) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1920 && g4Primary_Pz[nG4Primary] < 1930) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1930 && g4Primary_Pz[nG4Primary] < 1940) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1940 && g4Primary_Pz[nG4Primary] < 1950) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1950 && g4Primary_Pz[nG4Primary] < 1960) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1960 && g4Primary_Pz[nG4Primary] < 1970) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1970 && g4Primary_Pz[nG4Primary] < 1980) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1980 && g4Primary_Pz[nG4Primary] < 1990) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 1990 && g4Primary_Pz[nG4Primary] < 2000) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2000 && g4Primary_Pz[nG4Primary] < 2010) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2010 && g4Primary_Pz[nG4Primary] < 2020) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2020 && g4Primary_Pz[nG4Primary] < 2030) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2030 && g4Primary_Pz[nG4Primary] < 2040) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2040 && g4Primary_Pz[nG4Primary] < 2050) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2050 && g4Primary_Pz[nG4Primary] < 2060) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2060 && g4Primary_Pz[nG4Primary] < 2070) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2070 && g4Primary_Pz[nG4Primary] < 2080) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2080 && g4Primary_Pz[nG4Primary] < 2090) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2090 && g4Primary_Pz[nG4Primary] < 2100) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2100 && g4Primary_Pz[nG4Primary] < 2110) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2110 && g4Primary_Pz[nG4Primary] < 2120) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2120 && g4Primary_Pz[nG4Primary] < 2130) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2130 && g4Primary_Pz[nG4Primary] < 2140) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2140 && g4Primary_Pz[nG4Primary] < 2150) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2150 && g4Primary_Pz[nG4Primary] < 2160) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2160 && g4Primary_Pz[nG4Primary] < 2170) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2170 && g4Primary_Pz[nG4Primary] < 2180) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2180 && g4Primary_Pz[nG4Primary] < 2190) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2190 && g4Primary_Pz[nG4Primary] < 2200) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2200 && g4Primary_Pz[nG4Primary] < 2210) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2210 && g4Primary_Pz[nG4Primary] < 2220) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2220 && g4Primary_Pz[nG4Primary] < 2230) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2230 && g4Primary_Pz[nG4Primary] < 2240) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2240 && g4Primary_Pz[nG4Primary] < 2250) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2250 && g4Primary_Pz[nG4Primary] < 2260) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2260 && g4Primary_Pz[nG4Primary] < 2270) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2270 && g4Primary_Pz[nG4Primary] < 2280) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2280 && g4Primary_Pz[nG4Primary] < 2290) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2290 && g4Primary_Pz[nG4Primary] < 2300) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2300 && g4Primary_Pz[nG4Primary] < 2310) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2310 && g4Primary_Pz[nG4Primary] < 2320) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2320 && g4Primary_Pz[nG4Primary] < 2330) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2330 && g4Primary_Pz[nG4Primary] < 2340) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2340 && g4Primary_Pz[nG4Primary] < 2350) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2350 && g4Primary_Pz[nG4Primary] < 2360) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2360 && g4Primary_Pz[nG4Primary] < 2370) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2370 && g4Primary_Pz[nG4Primary] < 2380) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2380 && g4Primary_Pz[nG4Primary] < 2390) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2390 && g4Primary_Pz[nG4Primary] < 2400) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2400 && g4Primary_Pz[nG4Primary] < 2410) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2410 && g4Primary_Pz[nG4Primary] < 2420) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2420 && g4Primary_Pz[nG4Primary] < 2430) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2430 && g4Primary_Pz[nG4Primary] < 2440) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2440 && g4Primary_Pz[nG4Primary] < 2450) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2450 && g4Primary_Pz[nG4Primary] < 2460) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2460 && g4Primary_Pz[nG4Primary] < 2470) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2470 && g4Primary_Pz[nG4Primary] < 2480) {EventWeight = 0;}
		if(g4Primary_Pz[nG4Primary] > 2480 && g4Primary_Pz[nG4Primary] < 2490) {EventWeight = 0;}


		}//<---End Scaling based on Momentum
	       
	    // ###########################################################
	    // ### Use the scalings derived from the WC-Track Momentum ###
	    // ############################################################
	    if(ScaleByPz && RunIIScale)
	        {
		if(g4Primary_Pz[nG4Primary] > 0 && g4Primary_Pz[nG4Primary] < 10) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 10 && g4Primary_Pz[nG4Primary] < 20) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 20 && g4Primary_Pz[nG4Primary] < 30) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 30 && g4Primary_Pz[nG4Primary] < 40) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 40 && g4Primary_Pz[nG4Primary] < 50) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 50 && g4Primary_Pz[nG4Primary] < 60) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 60 && g4Primary_Pz[nG4Primary] < 70) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 70 && g4Primary_Pz[nG4Primary] < 80) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 80 && g4Primary_Pz[nG4Primary] < 90) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 90 && g4Primary_Pz[nG4Primary] < 100) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 100 && g4Primary_Pz[nG4Primary] < 110) {EventWeight = 0.014985;}
 		if(g4Primary_Pz[nG4Primary] > 110 && g4Primary_Pz[nG4Primary] < 120) {EventWeight = 0.0368903;}
 		if(g4Primary_Pz[nG4Primary] > 120 && g4Primary_Pz[nG4Primary] < 130) {EventWeight = 0.051039;}
 		if(g4Primary_Pz[nG4Primary] > 130 && g4Primary_Pz[nG4Primary] < 140) {EventWeight = 0.0690008;}
 		if(g4Primary_Pz[nG4Primary] > 140 && g4Primary_Pz[nG4Primary] < 150) {EventWeight = 0.0546726;}
 		if(g4Primary_Pz[nG4Primary] > 150 && g4Primary_Pz[nG4Primary] < 160) {EventWeight = 0.0718907;}
 		if(g4Primary_Pz[nG4Primary] > 160 && g4Primary_Pz[nG4Primary] < 170) {EventWeight = 0.0762542;}
 		if(g4Primary_Pz[nG4Primary] > 170 && g4Primary_Pz[nG4Primary] < 180) {EventWeight = 0.0752918;}
 		if(g4Primary_Pz[nG4Primary] > 180 && g4Primary_Pz[nG4Primary] < 190) {EventWeight = 0.0522912;}
 		if(g4Primary_Pz[nG4Primary] > 190 && g4Primary_Pz[nG4Primary] < 200) {EventWeight = 0.0370416;}
 		if(g4Primary_Pz[nG4Primary] > 200 && g4Primary_Pz[nG4Primary] < 210) {EventWeight = 0.02849;}
 		if(g4Primary_Pz[nG4Primary] > 210 && g4Primary_Pz[nG4Primary] < 220) {EventWeight = 0.0319957;}
 		if(g4Primary_Pz[nG4Primary] > 220 && g4Primary_Pz[nG4Primary] < 230) {EventWeight = 0.0342466;}
 		if(g4Primary_Pz[nG4Primary] > 230 && g4Primary_Pz[nG4Primary] < 240) {EventWeight = 0.0812475;}
 		if(g4Primary_Pz[nG4Primary] > 240 && g4Primary_Pz[nG4Primary] < 250) {EventWeight = 0.215328;}
 		if(g4Primary_Pz[nG4Primary] > 250 && g4Primary_Pz[nG4Primary] < 260) {EventWeight = 0.36829;}
 		if(g4Primary_Pz[nG4Primary] > 260 && g4Primary_Pz[nG4Primary] < 270) {EventWeight = 0.423555;}
 		if(g4Primary_Pz[nG4Primary] > 270 && g4Primary_Pz[nG4Primary] < 280) {EventWeight = 0.351362;}
 		if(g4Primary_Pz[nG4Primary] > 280 && g4Primary_Pz[nG4Primary] < 290) {EventWeight = 0.0940171;}
 		if(g4Primary_Pz[nG4Primary] > 290 && g4Primary_Pz[nG4Primary] < 300) {EventWeight = 0.0842314;}
 		if(g4Primary_Pz[nG4Primary] > 300 && g4Primary_Pz[nG4Primary] < 310) {EventWeight = 0.118247;}
 		if(g4Primary_Pz[nG4Primary] > 310 && g4Primary_Pz[nG4Primary] < 320) {EventWeight = 0.146118;}
 		if(g4Primary_Pz[nG4Primary] > 320 && g4Primary_Pz[nG4Primary] < 330) {EventWeight = 0.173978;}
 		if(g4Primary_Pz[nG4Primary] > 330 && g4Primary_Pz[nG4Primary] < 340) {EventWeight = 0.220346;}
 		if(g4Primary_Pz[nG4Primary] > 340 && g4Primary_Pz[nG4Primary] < 350) {EventWeight = 0.314349;}
 		if(g4Primary_Pz[nG4Primary] > 350 && g4Primary_Pz[nG4Primary] < 360) {EventWeight = 0.434615;}
 		if(g4Primary_Pz[nG4Primary] > 360 && g4Primary_Pz[nG4Primary] < 370) {EventWeight = 0.544293;}
 		if(g4Primary_Pz[nG4Primary] > 370 && g4Primary_Pz[nG4Primary] < 380) {EventWeight = 0.620107;}
 		if(g4Primary_Pz[nG4Primary] > 380 && g4Primary_Pz[nG4Primary] < 390) {EventWeight = 0.751634;}
 		if(g4Primary_Pz[nG4Primary] > 390 && g4Primary_Pz[nG4Primary] < 400) {EventWeight = 0.886234;}
 		if(g4Primary_Pz[nG4Primary] > 400 && g4Primary_Pz[nG4Primary] < 410) {EventWeight = 0.99951;}
 		if(g4Primary_Pz[nG4Primary] > 410 && g4Primary_Pz[nG4Primary] < 420) {EventWeight = 0.981781;}
 		if(g4Primary_Pz[nG4Primary] > 420 && g4Primary_Pz[nG4Primary] < 430) {EventWeight = 0.945019;}
 		if(g4Primary_Pz[nG4Primary] > 430 && g4Primary_Pz[nG4Primary] < 440) {EventWeight = 1.00612;}
 		if(g4Primary_Pz[nG4Primary] > 440 && g4Primary_Pz[nG4Primary] < 450) {EventWeight = 0.784903;}
 		if(g4Primary_Pz[nG4Primary] > 450 && g4Primary_Pz[nG4Primary] < 460) {EventWeight = 0.770465;}
 		if(g4Primary_Pz[nG4Primary] > 460 && g4Primary_Pz[nG4Primary] < 470) {EventWeight = 0.72901;}
 		if(g4Primary_Pz[nG4Primary] > 470 && g4Primary_Pz[nG4Primary] < 480) {EventWeight = 0.679703;}
 		if(g4Primary_Pz[nG4Primary] > 480 && g4Primary_Pz[nG4Primary] < 490) {EventWeight = 0.741905;}
 		if(g4Primary_Pz[nG4Primary] > 490 && g4Primary_Pz[nG4Primary] < 500) {EventWeight = 0.728022;}
 		if(g4Primary_Pz[nG4Primary] > 500 && g4Primary_Pz[nG4Primary] < 510) {EventWeight = 0.710791;}
 		if(g4Primary_Pz[nG4Primary] > 510 && g4Primary_Pz[nG4Primary] < 520) {EventWeight = 0.612962;}
 		if(g4Primary_Pz[nG4Primary] > 520 && g4Primary_Pz[nG4Primary] < 530) {EventWeight = 0.625624;}
 		if(g4Primary_Pz[nG4Primary] > 530 && g4Primary_Pz[nG4Primary] < 540) {EventWeight = 0.563682;}
 		if(g4Primary_Pz[nG4Primary] > 540 && g4Primary_Pz[nG4Primary] < 550) {EventWeight = 0.661929;}
 		if(g4Primary_Pz[nG4Primary] > 550 && g4Primary_Pz[nG4Primary] < 560) {EventWeight = 0.61209;}
 		if(g4Primary_Pz[nG4Primary] > 560 && g4Primary_Pz[nG4Primary] < 570) {EventWeight = 0.589583;}
 		if(g4Primary_Pz[nG4Primary] > 570 && g4Primary_Pz[nG4Primary] < 580) {EventWeight = 0.686723;}
 		if(g4Primary_Pz[nG4Primary] > 580 && g4Primary_Pz[nG4Primary] < 590) {EventWeight = 0.668082;}
 		if(g4Primary_Pz[nG4Primary] > 590 && g4Primary_Pz[nG4Primary] < 600) {EventWeight = 0.579186;}
 		if(g4Primary_Pz[nG4Primary] > 600 && g4Primary_Pz[nG4Primary] < 610) {EventWeight = 0.57947;}
 		if(g4Primary_Pz[nG4Primary] > 610 && g4Primary_Pz[nG4Primary] < 620) {EventWeight = 0.56376;}
 		if(g4Primary_Pz[nG4Primary] > 620 && g4Primary_Pz[nG4Primary] < 630) {EventWeight = 0.527543;}
 		if(g4Primary_Pz[nG4Primary] > 630 && g4Primary_Pz[nG4Primary] < 640) {EventWeight = 0.523573;}
 		if(g4Primary_Pz[nG4Primary] > 640 && g4Primary_Pz[nG4Primary] < 650) {EventWeight = 0.48433;}
 		if(g4Primary_Pz[nG4Primary] > 650 && g4Primary_Pz[nG4Primary] < 660) {EventWeight = 0.521353;}
 		if(g4Primary_Pz[nG4Primary] > 660 && g4Primary_Pz[nG4Primary] < 670) {EventWeight = 0.493666;}
 		if(g4Primary_Pz[nG4Primary] > 670 && g4Primary_Pz[nG4Primary] < 680) {EventWeight = 0.465734;}
 		if(g4Primary_Pz[nG4Primary] > 680 && g4Primary_Pz[nG4Primary] < 690) {EventWeight = 0.444499;}
 		if(g4Primary_Pz[nG4Primary] > 690 && g4Primary_Pz[nG4Primary] < 700) {EventWeight = 0.42957;}
 		if(g4Primary_Pz[nG4Primary] > 700 && g4Primary_Pz[nG4Primary] < 710) {EventWeight = 0.43097;}
 		if(g4Primary_Pz[nG4Primary] > 710 && g4Primary_Pz[nG4Primary] < 720) {EventWeight = 0.40293;}
 		if(g4Primary_Pz[nG4Primary] > 720 && g4Primary_Pz[nG4Primary] < 730) {EventWeight = 0.358722;}
 		if(g4Primary_Pz[nG4Primary] > 730 && g4Primary_Pz[nG4Primary] < 740) {EventWeight = 0.387197;}
 		if(g4Primary_Pz[nG4Primary] > 740 && g4Primary_Pz[nG4Primary] < 750) {EventWeight = 0.361991;}
 		if(g4Primary_Pz[nG4Primary] > 750 && g4Primary_Pz[nG4Primary] < 760) {EventWeight = 0.292261;}
 		if(g4Primary_Pz[nG4Primary] > 760 && g4Primary_Pz[nG4Primary] < 770) {EventWeight = 0.34188;}
 		if(g4Primary_Pz[nG4Primary] > 770 && g4Primary_Pz[nG4Primary] < 780) {EventWeight = 0.284763;}
 		if(g4Primary_Pz[nG4Primary] > 780 && g4Primary_Pz[nG4Primary] < 790) {EventWeight = 0.304023;}
 		if(g4Primary_Pz[nG4Primary] > 790 && g4Primary_Pz[nG4Primary] < 800) {EventWeight = 0.324476;}
 		if(g4Primary_Pz[nG4Primary] > 800 && g4Primary_Pz[nG4Primary] < 810) {EventWeight = 0.266221;}
 		if(g4Primary_Pz[nG4Primary] > 810 && g4Primary_Pz[nG4Primary] < 820) {EventWeight = 0.259013;}
 		if(g4Primary_Pz[nG4Primary] > 820 && g4Primary_Pz[nG4Primary] < 830) {EventWeight = 0.232827;}
 		if(g4Primary_Pz[nG4Primary] > 830 && g4Primary_Pz[nG4Primary] < 840) {EventWeight = 0.195587;}
 		if(g4Primary_Pz[nG4Primary] > 840 && g4Primary_Pz[nG4Primary] < 850) {EventWeight = 0.192955;}
 		if(g4Primary_Pz[nG4Primary] > 850 && g4Primary_Pz[nG4Primary] < 860) {EventWeight = 0.175369;}
 		if(g4Primary_Pz[nG4Primary] > 860 && g4Primary_Pz[nG4Primary] < 870) {EventWeight = 0.17843;}
 		if(g4Primary_Pz[nG4Primary] > 870 && g4Primary_Pz[nG4Primary] < 880) {EventWeight = 0.168979;}
 		if(g4Primary_Pz[nG4Primary] > 880 && g4Primary_Pz[nG4Primary] < 890) {EventWeight = 0.147606;}
 		if(g4Primary_Pz[nG4Primary] > 890 && g4Primary_Pz[nG4Primary] < 900) {EventWeight = 0.152395;}
 		if(g4Primary_Pz[nG4Primary] > 900 && g4Primary_Pz[nG4Primary] < 910) {EventWeight = 0.118522;}
 		if(g4Primary_Pz[nG4Primary] > 910 && g4Primary_Pz[nG4Primary] < 920) {EventWeight = 0.143228;}
 		if(g4Primary_Pz[nG4Primary] > 920 && g4Primary_Pz[nG4Primary] < 930) {EventWeight = 0.131976;}
 		if(g4Primary_Pz[nG4Primary] > 930 && g4Primary_Pz[nG4Primary] < 940) {EventWeight = 0.0986842;}
 		if(g4Primary_Pz[nG4Primary] > 940 && g4Primary_Pz[nG4Primary] < 950) {EventWeight = 0.0809041;}
 		if(g4Primary_Pz[nG4Primary] > 950 && g4Primary_Pz[nG4Primary] < 960) {EventWeight = 0.0848806;}
 		if(g4Primary_Pz[nG4Primary] > 960 && g4Primary_Pz[nG4Primary] < 970) {EventWeight = 0.0961538;}
 		if(g4Primary_Pz[nG4Primary] > 970 && g4Primary_Pz[nG4Primary] < 980) {EventWeight = 0.0780945;}
 		if(g4Primary_Pz[nG4Primary] > 980 && g4Primary_Pz[nG4Primary] < 990) {EventWeight = 0.0635035;}
 		if(g4Primary_Pz[nG4Primary] > 990 && g4Primary_Pz[nG4Primary] < 1000) {EventWeight = 0.0580076;}
 		if(g4Primary_Pz[nG4Primary] > 1000 && g4Primary_Pz[nG4Primary] < 1010) {EventWeight = 0.0498339;}
 		if(g4Primary_Pz[nG4Primary] > 1010 && g4Primary_Pz[nG4Primary] < 1020) {EventWeight = 0.0488599;}
 		if(g4Primary_Pz[nG4Primary] > 1020 && g4Primary_Pz[nG4Primary] < 1030) {EventWeight = 0.0423985;}
 		if(g4Primary_Pz[nG4Primary] > 1030 && g4Primary_Pz[nG4Primary] < 1040) {EventWeight = 0.0358709;}
 		if(g4Primary_Pz[nG4Primary] > 1040 && g4Primary_Pz[nG4Primary] < 1050) {EventWeight = 0.0317864;}
 		if(g4Primary_Pz[nG4Primary] > 1050 && g4Primary_Pz[nG4Primary] < 1060) {EventWeight = 0.0274725;}
 		if(g4Primary_Pz[nG4Primary] > 1060 && g4Primary_Pz[nG4Primary] < 1070) {EventWeight = 0.0231154;}
 		if(g4Primary_Pz[nG4Primary] > 1070 && g4Primary_Pz[nG4Primary] < 1080) {EventWeight = 0.0159702;}
 		if(g4Primary_Pz[nG4Primary] > 1080 && g4Primary_Pz[nG4Primary] < 1090) {EventWeight = 0.0115193;}
 		if(g4Primary_Pz[nG4Primary] > 1090 && g4Primary_Pz[nG4Primary] < 1100) {EventWeight = 0.0180854;}
 		if(g4Primary_Pz[nG4Primary] > 1100 && g4Primary_Pz[nG4Primary] < 1110) {EventWeight = 0.0186319;}
 		if(g4Primary_Pz[nG4Primary] > 1110 && g4Primary_Pz[nG4Primary] < 1120) {EventWeight = 0.0156454;}
 		if(g4Primary_Pz[nG4Primary] > 1120 && g4Primary_Pz[nG4Primary] < 1130) {EventWeight = 0.00869889;}
 		if(g4Primary_Pz[nG4Primary] > 1130 && g4Primary_Pz[nG4Primary] < 1140) {EventWeight = 0.0176256;}
 		if(g4Primary_Pz[nG4Primary] > 1140 && g4Primary_Pz[nG4Primary] < 1150) {EventWeight = 0.00926784;}
 		if(g4Primary_Pz[nG4Primary] > 1150 && g4Primary_Pz[nG4Primary] < 1160) {EventWeight = 0.0200778;}
 		if(g4Primary_Pz[nG4Primary] > 1160 && g4Primary_Pz[nG4Primary] < 1170) {EventWeight = 0.0168067;}
 		if(g4Primary_Pz[nG4Primary] > 1170 && g4Primary_Pz[nG4Primary] < 1180) {EventWeight = 0.0130157;}
 		if(g4Primary_Pz[nG4Primary] > 1180 && g4Primary_Pz[nG4Primary] < 1190) {EventWeight = 0.00537924;}
 		if(g4Primary_Pz[nG4Primary] > 1190 && g4Primary_Pz[nG4Primary] < 1200) {EventWeight = 0.00926784;}
 		if(g4Primary_Pz[nG4Primary] > 1200 && g4Primary_Pz[nG4Primary] < 1210) {EventWeight = 0.00374625;}
 		if(g4Primary_Pz[nG4Primary] > 1210 && g4Primary_Pz[nG4Primary] < 1220) {EventWeight = 0.00495479;}
 		if(g4Primary_Pz[nG4Primary] > 1220 && g4Primary_Pz[nG4Primary] < 1230) {EventWeight = 0.00673582;}
 		if(g4Primary_Pz[nG4Primary] > 1230 && g4Primary_Pz[nG4Primary] < 1240) {EventWeight = 0.0065634;}
 		if(g4Primary_Pz[nG4Primary] > 1240 && g4Primary_Pz[nG4Primary] < 1250) {EventWeight = 0.00509424;}
 		if(g4Primary_Pz[nG4Primary] > 1250 && g4Primary_Pz[nG4Primary] < 1260) {EventWeight = 0.0011744;}
 		if(g4Primary_Pz[nG4Primary] > 1260 && g4Primary_Pz[nG4Primary] < 1270) {EventWeight = 0.00507743;}
 		if(g4Primary_Pz[nG4Primary] > 1270 && g4Primary_Pz[nG4Primary] < 1280) {EventWeight = 0.00407719;}
 		if(g4Primary_Pz[nG4Primary] > 1280 && g4Primary_Pz[nG4Primary] < 1290) {EventWeight = 0.00402037;}
 		if(g4Primary_Pz[nG4Primary] > 1290 && g4Primary_Pz[nG4Primary] < 1300) {EventWeight = 0.00475568;}
 		if(g4Primary_Pz[nG4Primary] > 1300 && g4Primary_Pz[nG4Primary] < 1310) {EventWeight = 0.00875547;}
 		if(g4Primary_Pz[nG4Primary] > 1310 && g4Primary_Pz[nG4Primary] < 1320) {EventWeight = 0.00782269;}
 		if(g4Primary_Pz[nG4Primary] > 1320 && g4Primary_Pz[nG4Primary] < 1330) {EventWeight = 0.00668896;}
 		if(g4Primary_Pz[nG4Primary] > 1330 && g4Primary_Pz[nG4Primary] < 1340) {EventWeight = 0.00246154;}
 		if(g4Primary_Pz[nG4Primary] > 1340 && g4Primary_Pz[nG4Primary] < 1350) {EventWeight = 0.00242277;}
 		if(g4Primary_Pz[nG4Primary] > 1350 && g4Primary_Pz[nG4Primary] < 1360) {EventWeight = 0.00131044;}
 		if(g4Primary_Pz[nG4Primary] > 1360 && g4Primary_Pz[nG4Primary] < 1370) {EventWeight = 0.00125691;}
 		if(g4Primary_Pz[nG4Primary] > 1370 && g4Primary_Pz[nG4Primary] < 1380) {EventWeight = 0.0081114;}
 		if(g4Primary_Pz[nG4Primary] > 1380 && g4Primary_Pz[nG4Primary] < 1390) {EventWeight = 0.00403443;}
 		if(g4Primary_Pz[nG4Primary] > 1390 && g4Primary_Pz[nG4Primary] < 1400) {EventWeight = 0.0012288;}
 		if(g4Primary_Pz[nG4Primary] > 1400 && g4Primary_Pz[nG4Primary] < 1410) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1410 && g4Primary_Pz[nG4Primary] < 1420) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1420 && g4Primary_Pz[nG4Primary] < 1430) {EventWeight = 0.00605694;}
 		if(g4Primary_Pz[nG4Primary] > 1430 && g4Primary_Pz[nG4Primary] < 1440) {EventWeight = 0.00136874;}
 		if(g4Primary_Pz[nG4Primary] > 1440 && g4Primary_Pz[nG4Primary] < 1450) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1450 && g4Primary_Pz[nG4Primary] < 1460) {EventWeight = 0.00412088;}
 		if(g4Primary_Pz[nG4Primary] > 1460 && g4Primary_Pz[nG4Primary] < 1470) {EventWeight = 0.0024975;}
 		if(g4Primary_Pz[nG4Primary] > 1470 && g4Primary_Pz[nG4Primary] < 1480) {EventWeight = 0.00484555;}
 		if(g4Primary_Pz[nG4Primary] > 1480 && g4Primary_Pz[nG4Primary] < 1490) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1490 && g4Primary_Pz[nG4Primary] < 1500) {EventWeight = 0.00239263;}
 		if(g4Primary_Pz[nG4Primary] > 1500 && g4Primary_Pz[nG4Primary] < 1510) {EventWeight = 0.00255558;}
 		if(g4Primary_Pz[nG4Primary] > 1510 && g4Primary_Pz[nG4Primary] < 1520) {EventWeight = 0.0013885;}
 		if(g4Primary_Pz[nG4Primary] > 1520 && g4Primary_Pz[nG4Primary] < 1530) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1530 && g4Primary_Pz[nG4Primary] < 1540) {EventWeight = 0.00261643;}
 		if(g4Primary_Pz[nG4Primary] > 1540 && g4Primary_Pz[nG4Primary] < 1550) {EventWeight = 0.00131718;}
 		if(g4Primary_Pz[nG4Primary] > 1550 && g4Primary_Pz[nG4Primary] < 1560) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1560 && g4Primary_Pz[nG4Primary] < 1570) {EventWeight = 0.00260315;}
 		if(g4Primary_Pz[nG4Primary] > 1570 && g4Primary_Pz[nG4Primary] < 1580) {EventWeight = 0.00261643;}
 		if(g4Primary_Pz[nG4Primary] > 1580 && g4Primary_Pz[nG4Primary] < 1590) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1590 && g4Primary_Pz[nG4Primary] < 1600) {EventWeight = 0.00124875;}
 		if(g4Primary_Pz[nG4Primary] > 1600 && g4Primary_Pz[nG4Primary] < 1610) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1610 && g4Primary_Pz[nG4Primary] < 1620) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1620 && g4Primary_Pz[nG4Primary] < 1630) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1630 && g4Primary_Pz[nG4Primary] < 1640) {EventWeight = 0.00119076;}
 		if(g4Primary_Pz[nG4Primary] > 1640 && g4Primary_Pz[nG4Primary] < 1650) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1650 && g4Primary_Pz[nG4Primary] < 1660) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1660 && g4Primary_Pz[nG4Primary] < 1670) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1670 && g4Primary_Pz[nG4Primary] < 1680) {EventWeight = 0.00131492;}
 		if(g4Primary_Pz[nG4Primary] > 1680 && g4Primary_Pz[nG4Primary] < 1690) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1690 && g4Primary_Pz[nG4Primary] < 1700) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1700 && g4Primary_Pz[nG4Primary] < 1710) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1710 && g4Primary_Pz[nG4Primary] < 1720) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1720 && g4Primary_Pz[nG4Primary] < 1730) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1730 && g4Primary_Pz[nG4Primary] < 1740) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1740 && g4Primary_Pz[nG4Primary] < 1750) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1750 && g4Primary_Pz[nG4Primary] < 1760) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1760 && g4Primary_Pz[nG4Primary] < 1770) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1770 && g4Primary_Pz[nG4Primary] < 1780) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1780 && g4Primary_Pz[nG4Primary] < 1790) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1790 && g4Primary_Pz[nG4Primary] < 1800) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1800 && g4Primary_Pz[nG4Primary] < 1810) {EventWeight = 0.00131492;}
 		if(g4Primary_Pz[nG4Primary] > 1810 && g4Primary_Pz[nG4Primary] < 1820) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1820 && g4Primary_Pz[nG4Primary] < 1830) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1830 && g4Primary_Pz[nG4Primary] < 1840) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1840 && g4Primary_Pz[nG4Primary] < 1850) {EventWeight = 0.00133316;}
 		if(g4Primary_Pz[nG4Primary] > 1850 && g4Primary_Pz[nG4Primary] < 1860) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1860 && g4Primary_Pz[nG4Primary] < 1870) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1870 && g4Primary_Pz[nG4Primary] < 1880) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1880 && g4Primary_Pz[nG4Primary] < 1890) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1890 && g4Primary_Pz[nG4Primary] < 1900) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1900 && g4Primary_Pz[nG4Primary] < 1910) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1910 && g4Primary_Pz[nG4Primary] < 1920) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1920 && g4Primary_Pz[nG4Primary] < 1930) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1930 && g4Primary_Pz[nG4Primary] < 1940) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1940 && g4Primary_Pz[nG4Primary] < 1950) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1950 && g4Primary_Pz[nG4Primary] < 1960) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1960 && g4Primary_Pz[nG4Primary] < 1970) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1970 && g4Primary_Pz[nG4Primary] < 1980) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1980 && g4Primary_Pz[nG4Primary] < 1990) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1990 && g4Primary_Pz[nG4Primary] < 2000) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2000 && g4Primary_Pz[nG4Primary] < 2010) {EventWeight = 0;}

		
		}
	    
	    // ###########################################################
	    // ### Use the scalings derived from the WC-Track Momentum ###
	    // ############################################################
	    if(ScaleByPz && CombinedScale)
	        { 
		if(g4Primary_Pz[nG4Primary] > 0 && g4Primary_Pz[nG4Primary] < 10) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 10 && g4Primary_Pz[nG4Primary] < 20) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 20 && g4Primary_Pz[nG4Primary] < 30) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 30 && g4Primary_Pz[nG4Primary] < 40) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 40 && g4Primary_Pz[nG4Primary] < 50) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 50 && g4Primary_Pz[nG4Primary] < 60) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 60 && g4Primary_Pz[nG4Primary] < 70) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 70 && g4Primary_Pz[nG4Primary] < 80) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 80 && g4Primary_Pz[nG4Primary] < 90) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 90 && g4Primary_Pz[nG4Primary] < 100) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 100 && g4Primary_Pz[nG4Primary] < 110) {EventWeight = 0.0136705;}
 		if(g4Primary_Pz[nG4Primary] > 110 && g4Primary_Pz[nG4Primary] < 120) {EventWeight = 0.0336543;}
 		if(g4Primary_Pz[nG4Primary] > 120 && g4Primary_Pz[nG4Primary] < 130) {EventWeight = 0.0465619;}
 		if(g4Primary_Pz[nG4Primary] > 130 && g4Primary_Pz[nG4Primary] < 140) {EventWeight = 0.0652795;}
 		if(g4Primary_Pz[nG4Primary] > 140 && g4Primary_Pz[nG4Primary] < 150) {EventWeight = 0.0498768;}
 		if(g4Primary_Pz[nG4Primary] > 150 && g4Primary_Pz[nG4Primary] < 160) {EventWeight = 0.0699568;}
 		if(g4Primary_Pz[nG4Primary] > 160 && g4Primary_Pz[nG4Primary] < 170) {EventWeight = 0.0793288;}
 		if(g4Primary_Pz[nG4Primary] > 170 && g4Primary_Pz[nG4Primary] < 180) {EventWeight = 0.0870038;}
 		if(g4Primary_Pz[nG4Primary] > 180 && g4Primary_Pz[nG4Primary] < 190) {EventWeight = 0.0539811;}
 		if(g4Primary_Pz[nG4Primary] > 190 && g4Primary_Pz[nG4Primary] < 200) {EventWeight = 0.0371716;}
 		if(g4Primary_Pz[nG4Primary] > 200 && g4Primary_Pz[nG4Primary] < 210) {EventWeight = 0.0335716;}
 		if(g4Primary_Pz[nG4Primary] > 210 && g4Primary_Pz[nG4Primary] < 220) {EventWeight = 0.040135;}
 		if(g4Primary_Pz[nG4Primary] > 220 && g4Primary_Pz[nG4Primary] < 230) {EventWeight = 0.0588801;}
 		if(g4Primary_Pz[nG4Primary] > 230 && g4Primary_Pz[nG4Primary] < 240) {EventWeight = 0.107594;}
 		if(g4Primary_Pz[nG4Primary] > 240 && g4Primary_Pz[nG4Primary] < 250) {EventWeight = 0.24038;}
 		if(g4Primary_Pz[nG4Primary] > 250 && g4Primary_Pz[nG4Primary] < 260) {EventWeight = 0.39913;}
 		if(g4Primary_Pz[nG4Primary] > 260 && g4Primary_Pz[nG4Primary] < 270) {EventWeight = 0.446231;}
 		if(g4Primary_Pz[nG4Primary] > 270 && g4Primary_Pz[nG4Primary] < 280) {EventWeight = 0.40411;}
 		if(g4Primary_Pz[nG4Primary] > 280 && g4Primary_Pz[nG4Primary] < 290) {EventWeight = 0.139237;}
 		if(g4Primary_Pz[nG4Primary] > 290 && g4Primary_Pz[nG4Primary] < 300) {EventWeight = 0.155945;}
 		if(g4Primary_Pz[nG4Primary] > 300 && g4Primary_Pz[nG4Primary] < 310) {EventWeight = 0.164651;}
 		if(g4Primary_Pz[nG4Primary] > 310 && g4Primary_Pz[nG4Primary] < 320) {EventWeight = 0.182875;}
 		if(g4Primary_Pz[nG4Primary] > 320 && g4Primary_Pz[nG4Primary] < 330) {EventWeight = 0.217669;}
 		if(g4Primary_Pz[nG4Primary] > 330 && g4Primary_Pz[nG4Primary] < 340) {EventWeight = 0.25398;}
 		if(g4Primary_Pz[nG4Primary] > 340 && g4Primary_Pz[nG4Primary] < 350) {EventWeight = 0.352002;}
 		if(g4Primary_Pz[nG4Primary] > 350 && g4Primary_Pz[nG4Primary] < 360) {EventWeight = 0.459649;}
 		if(g4Primary_Pz[nG4Primary] > 360 && g4Primary_Pz[nG4Primary] < 370) {EventWeight = 0.582684;}
 		if(g4Primary_Pz[nG4Primary] > 370 && g4Primary_Pz[nG4Primary] < 380) {EventWeight = 0.629198;}
 		if(g4Primary_Pz[nG4Primary] > 380 && g4Primary_Pz[nG4Primary] < 390) {EventWeight = 0.77514;}
 		if(g4Primary_Pz[nG4Primary] > 390 && g4Primary_Pz[nG4Primary] < 400) {EventWeight = 0.893658;}
 		if(g4Primary_Pz[nG4Primary] > 400 && g4Primary_Pz[nG4Primary] < 410) {EventWeight = 1.00011;}
 		if(g4Primary_Pz[nG4Primary] > 410 && g4Primary_Pz[nG4Primary] < 420) {EventWeight = 0.978763;}
 		if(g4Primary_Pz[nG4Primary] > 420 && g4Primary_Pz[nG4Primary] < 430) {EventWeight = 0.957662;}
 		if(g4Primary_Pz[nG4Primary] > 430 && g4Primary_Pz[nG4Primary] < 440) {EventWeight = 0.99148;}
 		if(g4Primary_Pz[nG4Primary] > 440 && g4Primary_Pz[nG4Primary] < 450) {EventWeight = 0.803026;}
 		if(g4Primary_Pz[nG4Primary] > 450 && g4Primary_Pz[nG4Primary] < 460) {EventWeight = 0.762581;}
 		if(g4Primary_Pz[nG4Primary] > 460 && g4Primary_Pz[nG4Primary] < 470) {EventWeight = 0.735007;}
 		if(g4Primary_Pz[nG4Primary] > 470 && g4Primary_Pz[nG4Primary] < 480) {EventWeight = 0.689933;}
 		if(g4Primary_Pz[nG4Primary] > 480 && g4Primary_Pz[nG4Primary] < 490) {EventWeight = 0.741641;}
 		if(g4Primary_Pz[nG4Primary] > 490 && g4Primary_Pz[nG4Primary] < 500) {EventWeight = 0.724311;}
 		if(g4Primary_Pz[nG4Primary] > 500 && g4Primary_Pz[nG4Primary] < 510) {EventWeight = 0.702994;}
 		if(g4Primary_Pz[nG4Primary] > 510 && g4Primary_Pz[nG4Primary] < 520) {EventWeight = 0.603398;}
 		if(g4Primary_Pz[nG4Primary] > 520 && g4Primary_Pz[nG4Primary] < 530) {EventWeight = 0.633402;}
 		if(g4Primary_Pz[nG4Primary] > 530 && g4Primary_Pz[nG4Primary] < 540) {EventWeight = 0.574058;}
 		if(g4Primary_Pz[nG4Primary] > 540 && g4Primary_Pz[nG4Primary] < 550) {EventWeight = 0.673786;}
 		if(g4Primary_Pz[nG4Primary] > 550 && g4Primary_Pz[nG4Primary] < 560) {EventWeight = 0.615047;}
 		if(g4Primary_Pz[nG4Primary] > 560 && g4Primary_Pz[nG4Primary] < 570) {EventWeight = 0.599461;}
 		if(g4Primary_Pz[nG4Primary] > 570 && g4Primary_Pz[nG4Primary] < 580) {EventWeight = 0.700596;}
 		if(g4Primary_Pz[nG4Primary] > 580 && g4Primary_Pz[nG4Primary] < 590) {EventWeight = 0.692641;}
 		if(g4Primary_Pz[nG4Primary] > 590 && g4Primary_Pz[nG4Primary] < 600) {EventWeight = 0.60858;}
 		if(g4Primary_Pz[nG4Primary] > 600 && g4Primary_Pz[nG4Primary] < 610) {EventWeight = 0.608807;}
 		if(g4Primary_Pz[nG4Primary] > 610 && g4Primary_Pz[nG4Primary] < 620) {EventWeight = 0.589286;}
 		if(g4Primary_Pz[nG4Primary] > 620 && g4Primary_Pz[nG4Primary] < 630) {EventWeight = 0.54954;}
 		if(g4Primary_Pz[nG4Primary] > 630 && g4Primary_Pz[nG4Primary] < 640) {EventWeight = 0.545557;}
 		if(g4Primary_Pz[nG4Primary] > 640 && g4Primary_Pz[nG4Primary] < 650) {EventWeight = 0.522181;}
 		if(g4Primary_Pz[nG4Primary] > 650 && g4Primary_Pz[nG4Primary] < 660) {EventWeight = 0.537069;}
 		if(g4Primary_Pz[nG4Primary] > 660 && g4Primary_Pz[nG4Primary] < 670) {EventWeight = 0.530188;}
 		if(g4Primary_Pz[nG4Primary] > 670 && g4Primary_Pz[nG4Primary] < 680) {EventWeight = 0.509091;}
 		if(g4Primary_Pz[nG4Primary] > 680 && g4Primary_Pz[nG4Primary] < 690) {EventWeight = 0.47084;}
 		if(g4Primary_Pz[nG4Primary] > 690 && g4Primary_Pz[nG4Primary] < 700) {EventWeight = 0.459102;}
 		if(g4Primary_Pz[nG4Primary] > 700 && g4Primary_Pz[nG4Primary] < 710) {EventWeight = 0.450311;}
 		if(g4Primary_Pz[nG4Primary] > 710 && g4Primary_Pz[nG4Primary] < 720) {EventWeight = 0.421744;}
 		if(g4Primary_Pz[nG4Primary] > 720 && g4Primary_Pz[nG4Primary] < 730) {EventWeight = 0.392936;}
 		if(g4Primary_Pz[nG4Primary] > 730 && g4Primary_Pz[nG4Primary] < 740) {EventWeight = 0.410927;}
 		if(g4Primary_Pz[nG4Primary] > 740 && g4Primary_Pz[nG4Primary] < 750) {EventWeight = 0.384905;}
 		if(g4Primary_Pz[nG4Primary] > 750 && g4Primary_Pz[nG4Primary] < 760) {EventWeight = 0.301818;}
 		if(g4Primary_Pz[nG4Primary] > 760 && g4Primary_Pz[nG4Primary] < 770) {EventWeight = 0.348441;}
 		if(g4Primary_Pz[nG4Primary] > 770 && g4Primary_Pz[nG4Primary] < 780) {EventWeight = 0.310391;}
 		if(g4Primary_Pz[nG4Primary] > 780 && g4Primary_Pz[nG4Primary] < 790) {EventWeight = 0.322783;}
 		if(g4Primary_Pz[nG4Primary] > 790 && g4Primary_Pz[nG4Primary] < 800) {EventWeight = 0.338118;}
 		if(g4Primary_Pz[nG4Primary] > 800 && g4Primary_Pz[nG4Primary] < 810) {EventWeight = 0.285584;}
 		if(g4Primary_Pz[nG4Primary] > 810 && g4Primary_Pz[nG4Primary] < 820) {EventWeight = 0.280227;}
 		if(g4Primary_Pz[nG4Primary] > 820 && g4Primary_Pz[nG4Primary] < 830) {EventWeight = 0.248782;}
 		if(g4Primary_Pz[nG4Primary] > 830 && g4Primary_Pz[nG4Primary] < 840) {EventWeight = 0.214334;}
 		if(g4Primary_Pz[nG4Primary] > 840 && g4Primary_Pz[nG4Primary] < 850) {EventWeight = 0.212653;}
 		if(g4Primary_Pz[nG4Primary] > 850 && g4Primary_Pz[nG4Primary] < 860) {EventWeight = 0.183014;}
 		if(g4Primary_Pz[nG4Primary] > 860 && g4Primary_Pz[nG4Primary] < 870) {EventWeight = 0.194128;}
 		if(g4Primary_Pz[nG4Primary] > 870 && g4Primary_Pz[nG4Primary] < 880) {EventWeight = 0.181766;}
 		if(g4Primary_Pz[nG4Primary] > 880 && g4Primary_Pz[nG4Primary] < 890) {EventWeight = 0.159838;}
 		if(g4Primary_Pz[nG4Primary] > 890 && g4Primary_Pz[nG4Primary] < 900) {EventWeight = 0.166611;}
 		if(g4Primary_Pz[nG4Primary] > 900 && g4Primary_Pz[nG4Primary] < 910) {EventWeight = 0.129326;}
 		if(g4Primary_Pz[nG4Primary] > 910 && g4Primary_Pz[nG4Primary] < 920) {EventWeight = 0.146433;}
 		if(g4Primary_Pz[nG4Primary] > 920 && g4Primary_Pz[nG4Primary] < 930) {EventWeight = 0.137599;}
 		if(g4Primary_Pz[nG4Primary] > 930 && g4Primary_Pz[nG4Primary] < 940) {EventWeight = 0.105032;}
 		if(g4Primary_Pz[nG4Primary] > 940 && g4Primary_Pz[nG4Primary] < 950) {EventWeight = 0.0855227;}
 		if(g4Primary_Pz[nG4Primary] > 950 && g4Primary_Pz[nG4Primary] < 960) {EventWeight = 0.0846945;}
 		if(g4Primary_Pz[nG4Primary] > 960 && g4Primary_Pz[nG4Primary] < 970) {EventWeight = 0.0995733;}
 		if(g4Primary_Pz[nG4Primary] > 970 && g4Primary_Pz[nG4Primary] < 980) {EventWeight = 0.0783685;}
 		if(g4Primary_Pz[nG4Primary] > 980 && g4Primary_Pz[nG4Primary] < 990) {EventWeight = 0.0666776;}
 		if(g4Primary_Pz[nG4Primary] > 990 && g4Primary_Pz[nG4Primary] < 1000) {EventWeight = 0.0598217;}
 		if(g4Primary_Pz[nG4Primary] > 1000 && g4Primary_Pz[nG4Primary] < 1010) {EventWeight = 0.051291;}
 		if(g4Primary_Pz[nG4Primary] > 1010 && g4Primary_Pz[nG4Primary] < 1020) {EventWeight = 0.0548603;}
 		if(g4Primary_Pz[nG4Primary] > 1020 && g4Primary_Pz[nG4Primary] < 1030) {EventWeight = 0.044205;}
 		if(g4Primary_Pz[nG4Primary] > 1030 && g4Primary_Pz[nG4Primary] < 1040) {EventWeight = 0.0363603;}
 		if(g4Primary_Pz[nG4Primary] > 1040 && g4Primary_Pz[nG4Primary] < 1050) {EventWeight = 0.0336378;}
 		if(g4Primary_Pz[nG4Primary] > 1050 && g4Primary_Pz[nG4Primary] < 1060) {EventWeight = 0.0274496;}
 		if(g4Primary_Pz[nG4Primary] > 1060 && g4Primary_Pz[nG4Primary] < 1070) {EventWeight = 0.025774;}
 		if(g4Primary_Pz[nG4Primary] > 1070 && g4Primary_Pz[nG4Primary] < 1080) {EventWeight = 0.0169975;}
 		if(g4Primary_Pz[nG4Primary] > 1080 && g4Primary_Pz[nG4Primary] < 1090) {EventWeight = 0.0151794;}
 		if(g4Primary_Pz[nG4Primary] > 1090 && g4Primary_Pz[nG4Primary] < 1100) {EventWeight = 0.0164989;}
 		if(g4Primary_Pz[nG4Primary] > 1100 && g4Primary_Pz[nG4Primary] < 1110) {EventWeight = 0.0169975;}
 		if(g4Primary_Pz[nG4Primary] > 1110 && g4Primary_Pz[nG4Primary] < 1120) {EventWeight = 0.014273;}
 		if(g4Primary_Pz[nG4Primary] > 1120 && g4Primary_Pz[nG4Primary] < 1130) {EventWeight = 0.00793583;}
 		if(g4Primary_Pz[nG4Primary] > 1130 && g4Primary_Pz[nG4Primary] < 1140) {EventWeight = 0.0160795;}
 		if(g4Primary_Pz[nG4Primary] > 1140 && g4Primary_Pz[nG4Primary] < 1150) {EventWeight = 0.0120784;}
 		if(g4Primary_Pz[nG4Primary] > 1150 && g4Primary_Pz[nG4Primary] < 1160) {EventWeight = 0.0183166;}
 		if(g4Primary_Pz[nG4Primary] > 1160 && g4Primary_Pz[nG4Primary] < 1170) {EventWeight = 0.0165119;}
 		if(g4Primary_Pz[nG4Primary] > 1170 && g4Primary_Pz[nG4Primary] < 1180) {EventWeight = 0.011874;}
 		if(g4Primary_Pz[nG4Primary] > 1180 && g4Primary_Pz[nG4Primary] < 1190) {EventWeight = 0.00613422;}
 		if(g4Primary_Pz[nG4Primary] > 1190 && g4Primary_Pz[nG4Primary] < 1200) {EventWeight = 0.00951173;}
 		if(g4Primary_Pz[nG4Primary] > 1200 && g4Primary_Pz[nG4Primary] < 1210) {EventWeight = 0.00341763;}
 		if(g4Primary_Pz[nG4Primary] > 1210 && g4Primary_Pz[nG4Primary] < 1220) {EventWeight = 0.00452016;}
 		if(g4Primary_Pz[nG4Primary] > 1220 && g4Primary_Pz[nG4Primary] < 1230) {EventWeight = 0.00614496;}
 		if(g4Primary_Pz[nG4Primary] > 1230 && g4Primary_Pz[nG4Primary] < 1240) {EventWeight = 0.00598767;}
 		if(g4Primary_Pz[nG4Primary] > 1240 && g4Primary_Pz[nG4Primary] < 1250) {EventWeight = 0.00464738;}
 		if(g4Primary_Pz[nG4Primary] > 1250 && g4Primary_Pz[nG4Primary] < 1260) {EventWeight = 0.00214276;}
 		if(g4Primary_Pz[nG4Primary] > 1260 && g4Primary_Pz[nG4Primary] < 1270) {EventWeight = 0.00463204;}
 		if(g4Primary_Pz[nG4Primary] > 1270 && g4Primary_Pz[nG4Primary] < 1280) {EventWeight = 0.00619924;}
 		if(g4Primary_Pz[nG4Primary] > 1280 && g4Primary_Pz[nG4Primary] < 1290) {EventWeight = 0.00366771;}
 		if(g4Primary_Pz[nG4Primary] > 1290 && g4Primary_Pz[nG4Primary] < 1300) {EventWeight = 0.00542314;}
 		if(g4Primary_Pz[nG4Primary] > 1300 && g4Primary_Pz[nG4Primary] < 1310) {EventWeight = 0.00798745;}
 		if(g4Primary_Pz[nG4Primary] > 1310 && g4Primary_Pz[nG4Primary] < 1320) {EventWeight = 0.00713649;}
 		if(g4Primary_Pz[nG4Primary] > 1320 && g4Primary_Pz[nG4Primary] < 1330) {EventWeight = 0.0085431;}
 		if(g4Primary_Pz[nG4Primary] > 1330 && g4Primary_Pz[nG4Primary] < 1340) {EventWeight = 0.00224561;}
 		if(g4Primary_Pz[nG4Primary] > 1340 && g4Primary_Pz[nG4Primary] < 1350) {EventWeight = 0.00221025;}
 		if(g4Primary_Pz[nG4Primary] > 1350 && g4Primary_Pz[nG4Primary] < 1360) {EventWeight = 0.00119549;}
 		if(g4Primary_Pz[nG4Primary] > 1360 && g4Primary_Pz[nG4Primary] < 1370) {EventWeight = 0.00114666;}
 		if(g4Primary_Pz[nG4Primary] > 1370 && g4Primary_Pz[nG4Primary] < 1380) {EventWeight = 0.00986649;}
 		if(g4Primary_Pz[nG4Primary] > 1380 && g4Primary_Pz[nG4Primary] < 1390) {EventWeight = 0.00368053;}
 		if(g4Primary_Pz[nG4Primary] > 1390 && g4Primary_Pz[nG4Primary] < 1400) {EventWeight = 0.00112101;}
 		if(g4Primary_Pz[nG4Primary] > 1400 && g4Primary_Pz[nG4Primary] < 1410) {EventWeight = 0.00109308;}
 		if(g4Primary_Pz[nG4Primary] > 1410 && g4Primary_Pz[nG4Primary] < 1420) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1420 && g4Primary_Pz[nG4Primary] < 1430) {EventWeight = 0.00552563;}
 		if(g4Primary_Pz[nG4Primary] > 1430 && g4Primary_Pz[nG4Primary] < 1440) {EventWeight = 0.00124867;}
 		if(g4Primary_Pz[nG4Primary] > 1440 && g4Primary_Pz[nG4Primary] < 1450) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1450 && g4Primary_Pz[nG4Primary] < 1460) {EventWeight = 0.0037594;}
 		if(g4Primary_Pz[nG4Primary] > 1460 && g4Primary_Pz[nG4Primary] < 1470) {EventWeight = 0.00227842;}
 		if(g4Primary_Pz[nG4Primary] > 1470 && g4Primary_Pz[nG4Primary] < 1480) {EventWeight = 0.0044205;}
 		if(g4Primary_Pz[nG4Primary] > 1480 && g4Primary_Pz[nG4Primary] < 1490) {EventWeight = 0.00112281;}
 		if(g4Primary_Pz[nG4Primary] > 1490 && g4Primary_Pz[nG4Primary] < 1500) {EventWeight = 0.00218275;}
 		if(g4Primary_Pz[nG4Primary] > 1500 && g4Primary_Pz[nG4Primary] < 1510) {EventWeight = 0.00233141;}
 		if(g4Primary_Pz[nG4Primary] > 1510 && g4Primary_Pz[nG4Primary] < 1520) {EventWeight = 0.0012667;}
 		if(g4Primary_Pz[nG4Primary] > 1520 && g4Primary_Pz[nG4Primary] < 1530) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1530 && g4Primary_Pz[nG4Primary] < 1540) {EventWeight = 0.00238692;}
 		if(g4Primary_Pz[nG4Primary] > 1540 && g4Primary_Pz[nG4Primary] < 1550) {EventWeight = 0.00120163;}
 		if(g4Primary_Pz[nG4Primary] > 1550 && g4Primary_Pz[nG4Primary] < 1560) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1560 && g4Primary_Pz[nG4Primary] < 1570) {EventWeight = 0.0023748;}
 		if(g4Primary_Pz[nG4Primary] > 1570 && g4Primary_Pz[nG4Primary] < 1580) {EventWeight = 0.00358038;}
 		if(g4Primary_Pz[nG4Primary] > 1580 && g4Primary_Pz[nG4Primary] < 1590) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1590 && g4Primary_Pz[nG4Primary] < 1600) {EventWeight = 0.00113921;}
 		if(g4Primary_Pz[nG4Primary] > 1600 && g4Primary_Pz[nG4Primary] < 1610) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1610 && g4Primary_Pz[nG4Primary] < 1620) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1620 && g4Primary_Pz[nG4Primary] < 1630) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1630 && g4Primary_Pz[nG4Primary] < 1640) {EventWeight = 0.00108631;}
 		if(g4Primary_Pz[nG4Primary] > 1640 && g4Primary_Pz[nG4Primary] < 1650) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1650 && g4Primary_Pz[nG4Primary] < 1660) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1660 && g4Primary_Pz[nG4Primary] < 1670) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1670 && g4Primary_Pz[nG4Primary] < 1680) {EventWeight = 0.00119958;}
 		if(g4Primary_Pz[nG4Primary] > 1680 && g4Primary_Pz[nG4Primary] < 1690) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1690 && g4Primary_Pz[nG4Primary] < 1700) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1700 && g4Primary_Pz[nG4Primary] < 1710) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1710 && g4Primary_Pz[nG4Primary] < 1720) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1720 && g4Primary_Pz[nG4Primary] < 1730) {EventWeight = 0.00116377;}
 		if(g4Primary_Pz[nG4Primary] > 1730 && g4Primary_Pz[nG4Primary] < 1740) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1740 && g4Primary_Pz[nG4Primary] < 1750) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1750 && g4Primary_Pz[nG4Primary] < 1760) {EventWeight = 0.00116377;}
 		if(g4Primary_Pz[nG4Primary] > 1760 && g4Primary_Pz[nG4Primary] < 1770) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1770 && g4Primary_Pz[nG4Primary] < 1780) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1780 && g4Primary_Pz[nG4Primary] < 1790) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1790 && g4Primary_Pz[nG4Primary] < 1800) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1800 && g4Primary_Pz[nG4Primary] < 1810) {EventWeight = 0.00119958;}
 		if(g4Primary_Pz[nG4Primary] > 1810 && g4Primary_Pz[nG4Primary] < 1820) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1820 && g4Primary_Pz[nG4Primary] < 1830) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1830 && g4Primary_Pz[nG4Primary] < 1840) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1840 && g4Primary_Pz[nG4Primary] < 1850) {EventWeight = 0.00121621;}
 		if(g4Primary_Pz[nG4Primary] > 1850 && g4Primary_Pz[nG4Primary] < 1860) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1860 && g4Primary_Pz[nG4Primary] < 1870) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1870 && g4Primary_Pz[nG4Primary] < 1880) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1880 && g4Primary_Pz[nG4Primary] < 1890) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1890 && g4Primary_Pz[nG4Primary] < 1900) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1900 && g4Primary_Pz[nG4Primary] < 1910) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1910 && g4Primary_Pz[nG4Primary] < 1920) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1920 && g4Primary_Pz[nG4Primary] < 1930) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1930 && g4Primary_Pz[nG4Primary] < 1940) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1940 && g4Primary_Pz[nG4Primary] < 1950) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1950 && g4Primary_Pz[nG4Primary] < 1960) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1960 && g4Primary_Pz[nG4Primary] < 1970) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1970 && g4Primary_Pz[nG4Primary] < 1980) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1980 && g4Primary_Pz[nG4Primary] < 1990) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 1990 && g4Primary_Pz[nG4Primary] < 2000) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2000 && g4Primary_Pz[nG4Primary] < 2010) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2010 && g4Primary_Pz[nG4Primary] < 2020) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2020 && g4Primary_Pz[nG4Primary] < 2030) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2030 && g4Primary_Pz[nG4Primary] < 2040) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2040 && g4Primary_Pz[nG4Primary] < 2050) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2050 && g4Primary_Pz[nG4Primary] < 2060) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2060 && g4Primary_Pz[nG4Primary] < 2070) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2070 && g4Primary_Pz[nG4Primary] < 2080) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2080 && g4Primary_Pz[nG4Primary] < 2090) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2090 && g4Primary_Pz[nG4Primary] < 2100) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2100 && g4Primary_Pz[nG4Primary] < 2110) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2110 && g4Primary_Pz[nG4Primary] < 2120) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2120 && g4Primary_Pz[nG4Primary] < 2130) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2130 && g4Primary_Pz[nG4Primary] < 2140) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2140 && g4Primary_Pz[nG4Primary] < 2150) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2150 && g4Primary_Pz[nG4Primary] < 2160) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2160 && g4Primary_Pz[nG4Primary] < 2170) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2170 && g4Primary_Pz[nG4Primary] < 2180) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2180 && g4Primary_Pz[nG4Primary] < 2190) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2190 && g4Primary_Pz[nG4Primary] < 2200) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2200 && g4Primary_Pz[nG4Primary] < 2210) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2210 && g4Primary_Pz[nG4Primary] < 2220) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2220 && g4Primary_Pz[nG4Primary] < 2230) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2230 && g4Primary_Pz[nG4Primary] < 2240) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2240 && g4Primary_Pz[nG4Primary] < 2250) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2250 && g4Primary_Pz[nG4Primary] < 2260) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2260 && g4Primary_Pz[nG4Primary] < 2270) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2270 && g4Primary_Pz[nG4Primary] < 2280) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2280 && g4Primary_Pz[nG4Primary] < 2290) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2290 && g4Primary_Pz[nG4Primary] < 2300) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2300 && g4Primary_Pz[nG4Primary] < 2310) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2310 && g4Primary_Pz[nG4Primary] < 2320) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2320 && g4Primary_Pz[nG4Primary] < 2330) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2330 && g4Primary_Pz[nG4Primary] < 2340) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2340 && g4Primary_Pz[nG4Primary] < 2350) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2350 && g4Primary_Pz[nG4Primary] < 2360) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2360 && g4Primary_Pz[nG4Primary] < 2370) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2370 && g4Primary_Pz[nG4Primary] < 2380) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2380 && g4Primary_Pz[nG4Primary] < 2390) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2390 && g4Primary_Pz[nG4Primary] < 2400) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2400 && g4Primary_Pz[nG4Primary] < 2410) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2410 && g4Primary_Pz[nG4Primary] < 2420) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2420 && g4Primary_Pz[nG4Primary] < 2430) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2430 && g4Primary_Pz[nG4Primary] < 2440) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2440 && g4Primary_Pz[nG4Primary] < 2450) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2450 && g4Primary_Pz[nG4Primary] < 2460) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2460 && g4Primary_Pz[nG4Primary] < 2470) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2470 && g4Primary_Pz[nG4Primary] < 2480) {EventWeight = 0;}
 		if(g4Primary_Pz[nG4Primary] > 2480 && g4Primary_Pz[nG4Primary] < 2490) {EventWeight = 0;}

		
		}
		
		
	    
	    }//<---End Assigning Event weight
	 
	 TrueLength = sqrt( ((EndPointz[iG4]-StartPointz[iG4])*(EndPointz[iG4]-StartPointz[iG4])) + 
	                    ((EndPointy[iG4]-StartPointy[iG4])*(EndPointy[iG4]-StartPointy[iG4])) + 
	                    ((EndPointx[iG4]-StartPointx[iG4])*(EndPointx[iG4]-StartPointx[iG4])) );
			    
	 hMCTrueLength->Fill(TrueLength);
	 
	 // ------------------------------------------------------------------------------------
	 // ---------------        Extrapolate the X, Y, Z position of the primary         -----
	 // ---------------     if it started upstream of the front face of the TPC        -----
	 // ------------------------------------------------------------------------------------
	 
	 double b1 = StartPointz[iG4] - StartPointx[iG4]*Pz[iG4]/Px[iG4];
	 double b2 = StartPointz[iG4] - StartPointy[iG4]*Pz[iG4]/Py[iG4];
	 
	 g4Primary_ProjX0[nG4Primary] = -b1*Px[iG4]/Pz[iG4];
	 g4Primary_ProjY0[nG4Primary] = -b2*Py[iG4]/Pz[iG4];
	 g4Primary_ProjZ0[nG4Primary] = 0.0;
	 
	 // ### Setting the primary particles Track ID ###
	 g4Primary_TrkID[nG4Primary] = TrackId[iG4];
	 
	 
	 hMCPrimaryEndXvsZ->Fill(EndPointz[iG4], EndPointx[iG4]);
	 hMCPrimaryEndYvsZ->Fill(EndPointz[iG4], EndPointy[iG4]);
	 
	 // ##############################
	 // ### Filling the histograms ###
	 // ##############################
	 hMCPrimaryPx->Fill(g4Primary_Px[nG4Primary], EventWeight);
	 hMCPrimaryPy->Fill(g4Primary_Py[nG4Primary], EventWeight);
	 hMCPrimaryPz->Fill(g4Primary_Pz[nG4Primary], EventWeight);
	 
	 hMCPrimaryPxUnWeighted->Fill(g4Primary_Px[nG4Primary]);
	 hMCPrimaryPyUnWeighted->Fill(g4Primary_Py[nG4Primary]);
	 hMCPrimaryPzUnWeighted->Fill(g4Primary_Pz[nG4Primary]);

	 hMCPrimaryStartX->Fill(StartPointx[iG4]);
	 hMCPrimaryStartY->Fill(StartPointy[iG4]);
	 hMCPrimaryStartZ->Fill(StartPointz[iG4]);
	 
	 hMCPrimaryEndX->Fill(EndPointx[iG4]);
	 hMCPrimaryEndY->Fill(EndPointy[iG4]);
	 hMCPrimaryEndZ->Fill(EndPointz[iG4]);

	 hMCPrimaryProjectedStartX->Fill(g4Primary_ProjX0[nG4Primary]);
	 hMCPrimaryProjectedStartY->Fill(g4Primary_ProjY0[nG4Primary]);
	 hMCPrimaryProjectedStartZ->Fill(g4Primary_ProjZ0[nG4Primary]);
	 
	 nG4TrajPoints = 0;
	 
	 // ### Recording the primary particles trajectory points ###
	 for(int iG4Tr = 0; iG4Tr < NTrTrajPts[iG4]; iG4Tr++)
	    {
	    g4Primary_TrueTrjX[nG4Primary][nG4PriTrj] = MidPosX[iG4][iG4Tr];
	    g4Primary_TrueTrjY[nG4Primary][nG4PriTrj] = MidPosY[iG4][iG4Tr];
	    g4Primary_TrueTrjZ[nG4Primary][nG4PriTrj] = MidPosZ[iG4][iG4Tr];
	    
	    //std::cout<<"g4Primary_TrueTrjZ[nG4Primary][nG4PriTrj] = "<<g4Primary_TrueTrjZ[nG4Primary][nG4PriTrj]<<std::endl;
	    
	    g4Primary_TrueTrjPx[nG4Primary][nG4PriTrj] = MidPx[iG4][iG4Tr]*1000;//<---Converting to MeV
	    g4Primary_TrueTrjPy[nG4Primary][nG4PriTrj] = MidPy[iG4][iG4Tr]*1000;//<---Converting to MeV
	    g4Primary_TrueTrjPz[nG4Primary][nG4PriTrj] = MidPz[iG4][iG4Tr]*1000;//<---Converting to MeV
	    
	    nG4PriTrj++;
	    }//<---end looping over this primary particles true trajectory points
	 
	 
	 // ### Bumping the counters ###
	 nG4Primary++;
	 
	 }//<---End Looking only at primaries

      }// <---End iG4 Loop
   
   // ################################################
   // ### Loop over all the GEANT4 particles again ###
   // ###  to get the process from the daughters   ###
   // ################################################
   for (int iG4 = 0; iG4 < geant_list_size; iG4++)
      {
      
      // ### Looking for the Daughters of the primary ###
      if(Mother[iG4] == g4Primary_TrkID[nG4Primary - 1])
	 {
	 g4PrimaryProcess[nG4Primary - 1] = Process[iG4];
	 
	 
	 
	 
	 }//<---End matching daughters
      
      }//<---end iG4 loop
   hMCPrimaryProcess->Fill(g4PrimaryProcess[nG4Primary - 1]);

   //=======================================================================================================================
   //				Only looking at events where the primary particle enters the TPC
   //=======================================================================================================================
   
   bool GoodMCEventInTPC = true;
   
   // ##############################################
   // ### Looping over all the primary particles ###
   // ##############################################
   for(int npri = 0; npri < nG4Primary; npri++)
      {
      if(g4Primary_Zf[npri] < 0){GoodMCEventInTPC = false;}
      
      // ####################################################################
      // ### Calculating the energy loss for particles that enter the TPC ###
      // ####################################################################
      if(GoodMCEventInTPC)
         {
	 float DifferenceInEnergy = 0;
	 // ### Loop over the true trajectory points ###
	 for(int ntrj = 0; ntrj < nG4PriTrj; ntrj++)
	    {
\
	    // ### Only looking at point which are upstream of the TPC ###
	    if(g4Primary_TrueTrjZ[npri][ntrj] < 0)
	       {
	       
	       float Momentum_Point1 = sqrt((g4Primary_TrueTrjPx[npri][ntrj]*g4Primary_TrueTrjPx[npri][ntrj]) + 
	                               (g4Primary_TrueTrjPy[npri][ntrj]*g4Primary_TrueTrjPy[npri][ntrj]) +
				       (g4Primary_TrueTrjPz[npri][ntrj]*g4Primary_TrueTrjPz[npri][ntrj]));
				       
	       float Momentum_Point2 = sqrt((g4Primary_TrueTrjPx[npri][ntrj+1]*g4Primary_TrueTrjPx[npri][ntrj+1]) + 
	                               (g4Primary_TrueTrjPy[npri][ntrj+1]*g4Primary_TrueTrjPy[npri][ntrj+1]) +
				       (g4Primary_TrueTrjPz[npri][ntrj+1]*g4Primary_TrueTrjPz[npri][ntrj+1]));
				       
	       float Energy_Point1 = sqrt( (Momentum_Point1*Momentum_Point1) + (particle_mass*particle_mass)  );
	       
	       float Energy_Point2 = sqrt( (Momentum_Point2*Momentum_Point2) + (particle_mass*particle_mass)  );
	       
	       DifferenceInEnergy +=  Energy_Point1 - Energy_Point2;
	       
	       //std::cout<<"z = "<<g4Primary_TrueTrjZ[npri][ntrj]<<", DifferenceInEnergy = "<<DifferenceInEnergy<<std::endl;
	       
	       
	       }//<---End only look at points which are upstream of the TPC
	    
	    
	    }//<---End ntrj for loop
	 
	 
	 hMCELossUpstream->Fill(DifferenceInEnergy);
	 }//<---Only looking at events that actually make it into the TPC
      
      
      }//<---End npri loop
   
   if(!GoodMCEventInTPC){continue;}
   nEvtsGoodMC++;



   //=======================================================================================================================
   //						Low Z Spacepoint Track Cut
   //=======================================================================================================================
   
   // ### Boolian for events w/ track which ###
   // ###     starts at the front face      ###
   bool TrackSptsZCut = false;
   
   bool ThisTrackHasLowZPoint = false;
   
   // ### Recording the index of the track which ###
   // ###   starts at the front face of the TPC  ###
   bool PreLimTrackIndex[1000] = {false};
   
   // ###########################
   // ### Looping over tracks ###
   // ###########################
   for(int nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {
      
      float tempZpoint = 100;
      ThisTrackHasLowZPoint = false;
      // ########################################################
      // ### Looping over the trajectory points for the track ###
      // ########################################################
      for(int ntrjpts = 0; ntrjpts < nTrajPoint[nTPCtrk]; ntrjpts++)
         {
	 // ################################################################################ 
         // ### Tracking the lowest Z point that is inside fiducial boundries of the TPC ###
	 // ################################################################################
	 if( trjPt_Z[nTPCtrk][ntrjpts] < tempZpoint  && trjPt_Z[nTPCtrk][ntrjpts] > ZLowerFid && 
	     trjPt_Z[nTPCtrk][ntrjpts] < ZUpperFid && trjPt_X[nTPCtrk][ntrjpts] > XLowerFid && trjPt_X[nTPCtrk][ntrjpts] < XUpperFid &&
	     trjPt_Y[nTPCtrk][ntrjpts] < YUpperFid && trjPt_Y[nTPCtrk][ntrjpts] > YLowerFid )
	     
	    {tempZpoint = trjPt_Z[nTPCtrk][ntrjpts];}//<---End looking for the most upstream point
        
	 // ### Only passing events with a track that has ###
	 // ###  a spacepoint within the first N cm in Z  ### 
	 // ###    And requiring it to be inside the TPC  ###
	 if(tempZpoint < FirstSpacePointZPos)
	    {TrackSptsZCut = true;
	     ThisTrackHasLowZPoint = true;}
	 }//<---End looping over ntrjpts	
	 
      // ### Filling the most upstream spacepoint for this track ###
      hRecoMCUpstreamZPos->Fill(tempZpoint);
      
      // ### Recording that this track is a "good Track if ###
      // ###  it has a space point in the first N cm in Z  ###
      if(ThisTrackHasLowZPoint){ PreLimTrackIndex[nTPCtrk] = true;}
      	 
      }//<---End nTPCtrk loop
      
   // ###############################################
   // ### Skipping events that don't have a track ###
   // ###   in the front of the TPC (Z) Position  ###
   // ###############################################
   if(!TrackSptsZCut){continue;}
   // ### Counting Events w/ front face TPC Track ###
   nEvtsTrackZPos++;
   
   
   //=======================================================================================================================
   //					Cutting on the number of tracks in the upstream TPC
   //=======================================================================================================================
   
   int nLowZTracksInTPC = 0;
   // ################################################################
   // ### Initializing variables for study of low Z track location ###
   // ################################################################
   bool LowZTrackInTPC = false;
   
   
   // #################################################################
   // ### Only keeping events if there is less than N tracks in the ###
   // ###    first ## cm of the TPC (to help cut out EM Showers     ###
   // #################################################################
   for(int nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
     {
     // ### Start by assuming this track is not in the ###
     // ###          low Z part of the TPC             ###
     LowZTrackInTPC = false;
           
     // ########################################################
     // ### Looping over the trajectory points for the track ###
     // ########################################################
     for(int ntrjpts = 0; ntrjpts < nTrajPoint[nTPCtrk]; ntrjpts++)
        {
	 
	// ##################################################
	// ### Count this track if it has a spacepoint in ###
	// ###       the low Z region of the TPC          ###
	// ##################################################
	if(trjPt_Z[nTPCtrk][ntrjpts] < UpperPartOfTPC)
	   {  
	   if(trjPt_Y[nTPCtrk][ntrjpts] > YLowerFid && trjPt_Y[nTPCtrk][ntrjpts] < YUpperFid && 
	      trjPt_X[nTPCtrk][ntrjpts] > XLowerFid && trjPt_X[nTPCtrk][ntrjpts] < XUpperFid)
	       {LowZTrackInTPC = true;}
		
           }//<---End counting if 
	
        }//<---End ntrjpts loop
      
     // ##################################################################
     // ### If the track was in the "UpperPartOfTPC", bump the counter ###
     // ##################################################################
     if(LowZTrackInTPC)
        {
	
	nLowZTracksInTPC++;
	}//<---End counting track in the Upstream part

     }//<---End nTPCtrk
    
    
     
    // ### Skipping the event if there are too many ###
    // ###       low Z tracks in the event          ###
    if(nLowZTracksInTPC > nLowZTracksAllowed || nLowZTracksInTPC == 0){continue;}  
    
    // ### Counting the event if it passes ###
    nLowZTrkEvents++;



   // ===========================================================================================================================================
   // 						Vetoing Shower Like Events 
   // ===========================================================================================================================================   
   
   int nShortTrks = 0;
   // ###############################
   // ### Looping over TPC tracks ###
   // ###############################
   for(int nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {
      
      // ### If the track is shorter than our cut ###
      if(trklength[nTPCtrk] < ShortTkLength)
         {
	 nShortTrks++;
	 
	 }
	 
      }//<---End nTPCtrk
   
   // ### Skipping the event if there are too many short tracks ###
   if(nShortTrks > nShortTracksAllowed){continue;}
   
   // ### Bumping the counter ###
   nNonShowerEvents++;


   //=======================================================================================================================
   //						Uniquely matching one WC Track (For MC) to TPC Track
   //=======================================================================================================================
   
   // ### Keeping track of the number of matched tracks ###
   int nMatchedTracks = 0;
   
   // ### Variables for Delta WC and TPC tracks ###
   float DeltaX_WC_TPC_Track = 999;
   float DeltaY_WC_TPC_Track = 999;
   
   // ### Setting the index for the track which is ###
   // ### uniquely matched to a wire chamber track ###
   bool MatchTPC_WVTrack[500] = {false};
   
   
   // ################################################
   // ### Calculating the angles for the Geant4 MC ###
   // ################################################
   TVector3 z_hat_MC(0,0,1);
   TVector3 p_hat_0_MC;
   
   // ### Setting the vector for the MC using the ###
   // ###  extrapolated Momentum vector   ###
   p_hat_0_MC.SetX(g4Primary_Px[0]);
   p_hat_0_MC.SetY(g4Primary_Py[0]);
   p_hat_0_MC.SetZ(g4Primary_Pz[0]); 
   
   // ### Getting everything in the same convention ###
   float mcPhi = 0;
   float mcTheta = 0;
   
   // === Calculating Theta for MC ===
   mcTheta = acos(z_hat_MC.Dot(p_hat_0_MC)/p_hat_0_MC.Mag());
   
   // === Calculating Phi for MC ===
   //---------------------------------------------------------------------------------------------------------------------
   if( p_hat_0_MC.Y() > 0 && p_hat_0_MC.X() > 0 ){ mcPhi = atan(p_hat_0_MC.Y()/p_hat_0_MC.X()); }
   else if( p_hat_0_MC.Y() > 0 && p_hat_0_MC.X() < 0 ){ mcPhi = atan(p_hat_0_MC.Y()/p_hat_0_MC.X())+3.141592654; }
   else if( p_hat_0_MC.Y() < 0 && p_hat_0_MC.X() < 0 ){ mcPhi = atan(p_hat_0_MC.Y()/p_hat_0_MC.X())+3.141592654; }
   else if( p_hat_0_MC.Y() < 0 && p_hat_0_MC.X() > 0 ){ mcPhi = atan(p_hat_0_MC.Y()/p_hat_0_MC.X())+6.28318; }
   else if( p_hat_0_MC.Y() == 0 && p_hat_0_MC.X() == 0 ){ mcPhi = 0; }//defined by convention
   else if( p_hat_0_MC.Y() == 0 )
      {
      if( p_hat_0_MC.X() > 0 ){ mcPhi = 0; }

      else{ mcPhi = 3.141592654; }

      }
   else if( p_hat_0_MC.X() == 0 )
      {
      if( p_hat_0_MC.Y() > 0 ){ mcPhi = 3.141592654/2; }
      else{ mcPhi = 3.141592654*3/2; }

      }
   //---------------------------------------------------------------------------------------------------------------------
   
   // ### Grab the WCTrack Theta ###;
   hRecoMCWCTheta->Fill(mcTheta* (180.0/3.141592654), EventWeight);
   
   hRecoMCWCThetaUnWeighted->Fill(mcTheta* (180.0/3.141592654));
      
   // ### Grabbing the WCTrack Phi ###
   hRecoMChWCPhi->Fill(mcPhi* (180.0/3.141592654), EventWeight);
   
   hRecoMChWCPhiUnWeighted->Fill(mcPhi* (180.0/3.141592654));
      
   // ####################################
   // ### Loop over all the TPC Tracks ###
   // ####################################
   for(int nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {
      // ############################################
      // ###   Only looking at tracks which have  ###
      // ### a point in the first N cm of the TPC ###
      // ############################################
      if(!PreLimTrackIndex[nTPCtrk]){continue;}
	 
      // === Set a dummy variables for the most upstream point ===
      float FirstSpacePointZ = 999;
      float FirstSpacePointY = 999;
      float FirstSpacePointX = 999;
	 
      float TempTrj_X = 999;
      float TempTrj_Y = 999;
      float TempTrj_Z = 999;
      // ###############################################################
      // ### Looping over the trajectory points for the prelim-track ###
      // ###############################################################
      for(int ntrjpts = 0; ntrjpts < nTrajPoint[nTPCtrk]; ntrjpts++)
         {
	    
	 // ### Recording this tracks upstream most X, Y, Z location, ###
	 // ###       which is inside the fiducial boundary           ###
	 if(trjPt_Z[nTPCtrk][ntrjpts] < FirstSpacePointZ && trjPt_Y[nTPCtrk][ntrjpts] > YLowerFid && 
	    trjPt_Y[nTPCtrk][ntrjpts] < YUpperFid && trjPt_X[nTPCtrk][ntrjpts] > XLowerFid && 
	    trjPt_X[nTPCtrk][ntrjpts] < XUpperFid && trjPt_Z[nTPCtrk][ntrjpts] < UpperPartOfTPC)
	    {
	       
	    // ######################################
	    // ### Record the most upstream point ###
	    // ######################################
	    FirstSpacePointZ = trjPt_Z[nTPCtrk][ntrjpts];
	    FirstSpacePointY = trjPt_Y[nTPCtrk][ntrjpts];
	    FirstSpacePointX = trjPt_X[nTPCtrk][ntrjpts];
	       
	    TempTrj_X = pHat0_X[nTPCtrk][ntrjpts];
	    TempTrj_Y = pHat0_Y[nTPCtrk][ntrjpts];
	    TempTrj_Z = pHat0_Z[nTPCtrk][ntrjpts];
	       
	       
	    }//<---End finding the most upstream point
         }//<---End ntrjpts loop
	 
      // ###################################################
      // ### Vectors for angles between TPC and WC Track ###
      // ###################################################
      TVector3 z_hat(0,0,1);
      TVector3 p_hat_0;
      
      // ### Setting the vector for the matched track ###
      // ###      most upstream trajectory point      ###
      p_hat_0.SetX(TempTrj_X);
      p_hat_0.SetY(TempTrj_Y);
      p_hat_0.SetZ(TempTrj_Z); //<--Note: since at this point we only have one unique match
       		               //         only having one entry should be fine
	 			  
      // ===============================================================================================================
      // 				Calculating Theta and Phi for this TPC Track
      // ===============================================================================================================
      // ### Calculating the Theta for the TPC Track ###
      float tpcTheta = acos(z_hat.Dot(p_hat_0)/p_hat_0.Mag());  
      hRecoMCTPCTheta->Fill(tpcTheta* (180.0/3.141592654), EventWeight);
      
      hRecoMCTPCThetaUnWeighted->Fill(tpcTheta* (180.0/3.141592654));
   
      // ### Using same convention as WCTrack to calculate phi ###
      float phi = 0;
      //Calculating phi (degeneracy elimination for the atan function)
      //----------------------------------------------------------------------------------------------
      if( p_hat_0.Y() > 0 && p_hat_0.X() > 0 ){ phi = atan(p_hat_0.Y()/p_hat_0.X()); }
      else if( p_hat_0.Y() > 0 && p_hat_0.X() < 0 ){ phi = atan(p_hat_0.Y()/p_hat_0.X())+3.141592654; }
      else if( p_hat_0.Y() < 0 && p_hat_0.X() < 0 ){ phi = atan(p_hat_0.Y()/p_hat_0.X())+3.141592654; }
      else if( p_hat_0.Y() < 0 && p_hat_0.X() > 0 ){ phi = atan(p_hat_0.Y()/p_hat_0.X())+6.28318; }
      else if( p_hat_0.Y() == 0 && p_hat_0.X() == 0 ){ phi = 0; }//defined by convention
      else if( p_hat_0.Y() == 0 )
         {
         if( p_hat_0.X() > 0 ){ phi = 0; }

         else{ phi = 3.141592654; }

         }
      else if( p_hat_0.X() == 0 )
         {
         if( p_hat_0.Y() > 0 ){ phi = 3.141592654/2; }
         else{ phi = 3.141592654*3/2; }

         }
      //----------------------------------------------------------------------------------------------
   
      // ### Using TPC Phi ###
      float tpcPhi = phi; 
      hRecoMCTPCPhi->Fill(tpcPhi* (180.0/3.141592654), EventWeight);
      
      hRecoMCTPCPhiUnWeighted->Fill(tpcPhi* (180.0/3.141592654));
      
      // ===============================================================================================================            
      // ===============================================================================================================
	 
      // #######################################################
      // ### Defining unit vectors for the WC and TPC tracks ###
      // #######################################################
      TVector3 theUnitVector_WCTrack;
      TVector3 theUnitVector_TPCTrack;
	 
      // === WCTrack Unit Vector ===
      theUnitVector_WCTrack.SetX(sin(mcTheta)*cos(mcPhi));
      theUnitVector_WCTrack.SetY(sin(mcTheta)*sin(mcPhi));
      theUnitVector_WCTrack.SetZ(cos(mcTheta));
    
      // === TPC Track Unit Vector ===
      theUnitVector_TPCTrack.SetX(sin(tpcTheta)*cos(tpcPhi));
      theUnitVector_TPCTrack.SetY(sin(tpcTheta)*sin(tpcPhi));
      theUnitVector_TPCTrack.SetZ(cos(tpcTheta));
	 
      // ##########################################################################
      // ### Calculating the Delta X and Delta Y between WC track and TPC track ###
      // ##########################################################################
      DeltaX_WC_TPC_Track = FirstSpacePointX - (g4Primary_ProjX0[0]);
      DeltaY_WC_TPC_Track = FirstSpacePointY - (g4Primary_ProjY0[0]);
      
      hRecoMCTrkInitialX->Fill(FirstSpacePointX, EventWeight);
      hRecoMCTrkInitialXUnweighted->Fill(FirstSpacePointX);
      
      hRecoMCTrkInitialY->Fill(FirstSpacePointY, EventWeight);
      hRecoMCTrkInitialYUnweighted->Fill(FirstSpacePointY);
	 
      // ###########################################################
      // ### Calculating the angle between WCTrack and TPC Track ###
      // ###########################################################
      float alpha = ( acos(theUnitVector_WCTrack.Dot(theUnitVector_TPCTrack)) )* (180.0/3.141592654);
   
         
      // ### Filling the Delta X and Delta Y  and alpha between WC tracks and TPC Tracks ###
      hRecoMCDeltaWCTrkY->Fill(DeltaY_WC_TPC_Track);
      hRecoMCDeltaWCTrkX->Fill(DeltaX_WC_TPC_Track);
      hRecoMCAlpha->Fill(alpha);
	 
	 // ###########################################################################
	 // ### If this TPC track matches this Wire Chamber Track, bump the counter ###
	 // ###########################################################################
      if( DeltaX_WC_TPC_Track >  DeltaXLowerBound && DeltaX_WC_TPC_Track < DeltaXUpperBound && 
	  DeltaY_WC_TPC_Track > DeltaYLowerBound && DeltaY_WC_TPC_Track < DeltaYUpperBound &&
	  alpha < alphaCut )
         {
	 // ### Counting the matched tracks ###
	 nMatchedTracks++;
	 
	 // ### Setting the index of this track to true ###
	 MatchTPC_WVTrack[nTPCtrk] = true;

         }  
	 
      }//<---end nTPCtrk loop
      
      
   
   // ### Filling the number of matched WC and TPC Tracks ###
   hRecoMCNMatchTPCWCTrk->Fill(nMatchedTracks);
   
   // #####################################################
   // ### Skipping this event if no WC track is matched ###
   // ###    OR if more than one WC track is matched    ###
   // #####################################################
   if( (nMatchedTracks < 1 || nMatchedTracks > 1)){continue;}
   
   // ### Counting the number of events with ONE WC track matched ###
   nEvtsWCTrackMatch++;




   // =========================================================================================================================================
   //						Recording information about the Wire Chamber Track
   // =========================================================================================================================================
   
   // ---   First grab the tracks "initial" momentum which we take from ---
   // --- the momentum of the primary MC track which has been matched ---
   // ---  and correct for the "typical" energy loss for a track in the ---
   // ---   argon between the cryostat and the front face of the TPC    ---
   
   
   
   // #############################################################
   // ### Calculating the momentum from the MC Primary Particle ###
   // #############################################################
   float momentum = sqrt( (g4Primary_Px[0]*g4Primary_Px[0]) + (g4Primary_Py[0]*g4Primary_Py[0]) + (g4Primary_Pz[0]*g4Primary_Pz[0]) );
         
   
   // ###   Calculating the initial Kinetic Energy    ###
   // ### KE = Energy - mass = (p^2 + m^2)^1/2 - mass ###
   float kineticEnergy = pow( (momentum*momentum) + (mass*mass) ,0.5) - mass;
   
   // ### The kinetic energy is that which we calculated ###
   // ###       minus the calculated energy loss         ###
   kineticEnergy -= entryTPCEnergyLoss;
  
   double InitialKinEnAtTPC = 0.;
   InitialKinEnAtTPC = kineticEnergy;
   
   // ###############################################
   // ### Filling the initial kinetic energy plot ###
   // ###############################################
   hRecoMCInitialKEMomentum->Fill(kineticEnergy, EventWeight);
   hRecoMCInitialKEMomentumUnWeighted->Fill(kineticEnergy);



   // =========================================================================================================================================
   //							 Calorimetry Points
   // =========================================================================================================================================
   
   //Vectors with calo info of the matched tpc track
   double MCRecodEdX[1000]={0.};
   double MCRecodQdX[1000]={0.};
   double MCRecoResRange[1000]={0.};
   double MCRecoPitch[1000]={0.};
   int nMCRecoSpts = 0;
   
   double MCRecoSptsX[1000];
   double MCRecoSptsY[1000];
   double MCRecoSptsZ[1000];
   
   // ################################################
   // ### Creating a flag for through going tracks ###
   // ################################################
   bool ThroughGoingTrack[1000]={false};
   
   
   // ###########################################
   // ### Creating a flag for stopping tracks ###
   // ###########################################
   bool StoppingParticle[1000] = {false};
   
   // ############################
   // ### Loop over all tracks ###
   // ############################
   for(int nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {
      // ### Skipping all the tracks which aren't well matched ###
      if(!MatchTPC_WVTrack[nTPCtrk]){continue;}
      
      // ### Recording the track length ###
      hRecoLength->Fill(trklength[nTPCtrk]);
      
      // ###################################################
      // ### Check to see if this track is through going ###
      // ### by checking to see if it ends on a boundary ###
      // ###################################################
      if(trkendx[nTPCtrk] < 1   || trkendx[nTPCtrk] > 42.0 || trkendy[nTPCtrk] > 19 ||
         trkendy[nTPCtrk] < -19 || trkendz[nTPCtrk] > 89.0)
         {ThroughGoingTrack[nTPCtrk] = true;}
      
      // ####################################################### 
      // ### Adding an option to select through-going tracks ###
      // #######################################################
      if( (trkvtxz[nTPCtrk] > 5.0 || trkendz[nTPCtrk] < 88.0) && SelectThroughGoing){continue;}
      
      // ###############################################################
      // ### Looping over the calorimetry spacepoints for this track ###
      // ###############################################################
      for(int nspts = 0; nspts < ntrkhits[nTPCtrk]; nspts++)
         {
	 
	 // ###                 Note: Format for this variable is:             ###
	 // ### [trk number][plane 0 = induction, 1 = collection][spts number] ###
         MCRecodEdX[nMCRecoSpts]     = trkdedx[nTPCtrk][1][nspts];
	 MCRecodQdX[nMCRecoSpts]     = trkdqdx[nTPCtrk][1][nspts];
	 
	 // ### Putting in a fix in the case that the dE/dX is negative in this step ### 
	 // ###  then take the point before and the point after and average them
	 if(MCRecodEdX[nMCRecoSpts] < 0 && nspts < ntrkhits[nTPCtrk] && nspts > 0)
	    {MCRecodEdX[nMCRecoSpts] = ( (trkdedx[nTPCtrk][1][nspts - 1] + trkdedx[nTPCtrk][1][nspts + 1]) / 2);}
	 
	 // ### If this didn't fix it, then just put in a flat 2.4 MeV / cm fix ###
	 if(MCRecodEdX[nMCRecoSpts] < 0)
	    {continue;}

	 // ##############################################################################
	 // #### Applying scale factor to get agreement between data and MC for Run I ####
	 // ##############################################################################
	 if(RunIScaledEdX)
	    {
	    MCRecodEdX[nMCRecoSpts]     = trkdedx[nTPCtrk][1][nspts]*(RunIScaleFactor);
	    MCRecodQdX[nMCRecoSpts]     = trkdqdx[nTPCtrk][1][nspts]*(RunIdQdXScaleFactor);
	    
	    }
	 // ###############################################################################
	 // #### Applying scale factor to get agreement between data and MC for Run II ####
	 // ###############################################################################
	 if(RunIIScaledEdX)
	    {
	    MCRecodEdX[nMCRecoSpts]     = trkdedx[nTPCtrk][1][nspts]*(RunIIScaleFactor);
	    MCRecodQdX[nMCRecoSpts]     = trkdqdx[nTPCtrk][1][nspts]*(RunIIdQdXScaleFactor);
	    
	    }
	    
	 MCRecoResRange[nMCRecoSpts] = trkrr[nTPCtrk][1][nspts];
         MCRecoPitch[nMCRecoSpts] = trkpitchhit[nTPCtrk][1][nspts];
	 
	 MCRecoSptsX[nMCRecoSpts] = trkxyz[nTPCtrk][1][nspts][0];
	 MCRecoSptsY[nMCRecoSpts] = trkxyz[nTPCtrk][1][nspts][1];
	 MCRecoSptsZ[nMCRecoSpts] = trkxyz[nTPCtrk][1][nspts][2];
	 
	 // ### Histogramming the dE/dX ###
	 hRecoMCdEdX->Fill(MCRecodEdX[nMCRecoSpts]);
	 
	 // ### Histogramming the dQ/dX ###
	 hRecoMCdQdX->Fill(MCRecodQdX[nMCRecoSpts]);
	 
	 // ### Histogramming the residual range ###
	 hRecoMCPionRR->Fill(MCRecoResRange[nMCRecoSpts]);
	 // ### Histogramming the Pitch ###
	 hRecoMCPionTrkPitch->Fill(MCRecoPitch[nMCRecoSpts]);
	 
	 // ### Filling 2d dE/dX vs RR ###
	 hRecoMCdEdXvsRR->Fill(MCRecoResRange[nMCRecoSpts], MCRecodEdX[nMCRecoSpts]);
	 
	 // =====================================================================
	 // === Breaking the TPC into 4 quadrants to analyze the dE/dX and dQ/dX
	 // ===               Q1: 0 cm    < z    < 22.5 cm
	 // ===               Q2: 22.5 cm < z    < 45 cm
	 // ===               Q3: 45 cm   < z    < 67.5 cm
	 // ===               Q4: 67.5 cm < z    < 90 cm
	 // =====================================================================
	 if(MCRecoSptsZ[nMCRecoSpts] > 0    && MCRecoSptsZ[nMCRecoSpts] < 22.5)
	    {
	    hMCRecodEdXQ1->Fill(MCRecodEdX[nMCRecoSpts]);
	    hMCRecodQdXQ1->Fill(MCRecodQdX[nMCRecoSpts]);
	    }
	 if(MCRecoSptsZ[nMCRecoSpts] > 22.5 && MCRecoSptsZ[nMCRecoSpts] < 45)
	    {
	    hMCRecodEdXQ2->Fill(MCRecodEdX[nMCRecoSpts]);
	    hMCRecodQdXQ2->Fill(MCRecodQdX[nMCRecoSpts]);
	    }
	 if(MCRecoSptsZ[nMCRecoSpts] > 45   && MCRecoSptsZ[nMCRecoSpts] < 67.5)
	    {
	    hMCRecodEdXQ3->Fill(MCRecodEdX[nMCRecoSpts]);
	    hMCRecodQdXQ3->Fill(MCRecodQdX[nMCRecoSpts]);
	    }
	 if(MCRecoSptsZ[nMCRecoSpts] > 67.5 && MCRecoSptsZ[nMCRecoSpts] < 90)
	    {
	    hMCRecodEdXQ4->Fill(MCRecodEdX[nMCRecoSpts]);
	    hMCRecodQdXQ4->Fill(MCRecodQdX[nMCRecoSpts]);
	    }
	 
	 
	 
	 nMCRecoSpts++;
	 
	 }//<---End spacepoints loop
      
      // #####################################################
      // ### Check to see if this track is consistent with ###
      // ###          being from a stopping track 	   ###
      // #####################################################
      if(InitialKinEnAtTPC < 300)
         {
	 // ### Filling the  tracks PIDA value ###
	 hRecoMCLowMomentumTrkPIDA->Fill(trkpida[nTPCtrk][1]);
	 
	 // ##########################################################
	 // ### Only fill if the MC truth is Pion Capture or Decay ###
	 // ##########################################################
	 if(g4PrimaryProcess[0] == 4 || g4PrimaryProcess[0] == 12 || g4PrimaryProcess[0] == 6)
	 	{hRecoMCLowMomentumTrkPIDACapDec->Fill(trkpida[nTPCtrk][1]);}
	 
	 
	 
	 
	//### Setting the last energy points variable ###
	double lastDeltaEAll = 0;
	    
	// ### Loop over the last five points of the track ###
	if(nMCRecoSpts >= 5)
	   {
           for(int nlastspts = nMCRecoSpts - 1; nlastspts > nMCRecoSpts - 5; nlastspts--)
	      {
	      if(MCRecodEdX[nlastspts] == -99999){continue;}
	      
	      //std::cout<<"nlastspts = "<<nlastspts<<std::endl;
	      // ### Add up the energy in the last 5 points ###
	      lastDeltaEAll += (MCRecoPitch[nlastspts] * MCRecodEdX[nlastspts]);
	      
	      //std::cout<<"lastDeltaEAll = "<<lastDeltaEAll<<std::endl;
	      }//<---End nlastspts loop

	 }//<---End only looking if the track has 5 points 
	 
	 if(g4PrimaryProcess[0] != 4 && g4PrimaryProcess[0] != 12 && g4PrimaryProcess[0] != 6)
	    {DeltaEvsPIDAAll->Fill(trkpida[nTPCtrk][1], lastDeltaEAll);}
	 
	 if(g4PrimaryProcess[0] == 4 || g4PrimaryProcess[0] == 12 || g4PrimaryProcess[0] == 6)
	    {DeltaEvsPIDADecayCap->Fill(trkpida[nTPCtrk][1], lastDeltaEAll);}
	 
	 
	 // ##########################################
	 // ###  If the PIDA is between 9 and 13   ###
	 // ##########################################
	 if(trkpida[nTPCtrk][1] >= 8 && trkpida[nTPCtrk][1] <= 13)
	    {
	    
	    //### Setting the last energy points variable ###
	    double lastDeltaE = 0;
	    
	    // ### Loop over the last five points of the track ###
	    if(nMCRecoSpts >= 5)
	       {
	       for(int nlastspts = nMCRecoSpts - 1; nlastspts > nMCRecoSpts - 5; nlastspts--)
	          {
		  
		  
		  // ### Add up the energy in the last 5 points ###
		  lastDeltaE += (MCRecoPitch[nlastspts] * MCRecodEdX[nlastspts]);

	          }//<---End nlastspts loop

	       }//<---End only looking if the track has 5 points
	    
	    // ### IF the Delta E is between 7 and 25, tag as a stopping track ###
	    if(lastDeltaE >= 10 && lastDeltaE <= 30)
	       // ### Only setting the flag if we are tagging events ###
	       {
	       if(RemoveStopping)
	          {StoppingParticle[nTPCtrk] = true;}
	       
	       }
	    
	    
	    }//<---End looking at 9 < PIDA < 13
	 }//<---End looking at low momentum tracks
      
      
      }//<---End nTPCtrk loop 
   
// ---------------------------------------------------------------------------------------------------------------------------------------
   bool HasToBeReordered = false;
   int ReorderedCount = 0;
   int bb = 0;
   // ############################################################
   // ### Fix the reordering problem of the calorimetry points ###
   // ############################################################
   if(FixCaloIssue_Reordering)
      {
      // ################################
      // ### Loop over the caloPoints ###
      // ################################
      for(int caloPoints = 0; caloPoints < nMCRecoSpts-1; caloPoints++)
         {
	 // ###           If this points Residual Range is smaller than the       ###
	 // ### next point, then things may be out of wack and we want to reorder ###
	 if(MCRecoResRange[caloPoints] < MCRecoResRange[caloPoints+1])
	    {
	    // #######################################################
	    // ### Set a flag that this might have to be reordered ###
	    // #######################################################
	    HasToBeReordered = true;
	    
	    // ### counting the points that are out of order ###
	    ReorderedCount++;
	    }

         }//<---End caloPoints
      }//<---End fixing the ordering problem
   
   // #####################################################
   // ### The things need to be reorderd for this track ###
   // #####################################################
   if(HasToBeReordered && ( (nMCRecoSpts - ReorderedCount) == 1))
      {
      
      // ### Temp Variables for fixing ###
      double tempRR[1000] = {0.};
      double tempdEdX[1000] = {0.};
      double tempPitch[1000] = {0.};
      
      // ### Start at the last point ###
      for(int aa = nMCRecoSpts; aa > -1; aa--)
         {
	 // ##########################################
	 // ### Skip the point if it is at the end ###
	 // ##########################################
	 if(MCRecoResRange[aa] == 0){continue;}
	 
	 // ### Reorder the points ###
	 tempRR[bb] = MCRecoResRange[aa];
	 tempdEdX[bb]     = MCRecodEdX[aa];
	 tempPitch[bb] = MCRecoPitch[aa];
	 
	 bb++;
	 }//<---end aa 
      
      // ###########################
      // ### Now swap the points ###
      // ###########################
      for(int reorder = 0; reorder < nMCRecoSpts; reorder++)
         {
	 MCRecoResRange[reorder] = tempRR[reorder];
	 MCRecodEdX[reorder]     = tempdEdX[reorder];
	 MCRecoPitch[reorder] = tempPitch[reorder];
	 
	 
	 }//<---End reorder loop
      
      
      }//<---End Has to be reordered

   // ##################################
   // ### Printing things as a check ###
   // ##################################
   if(HasToBeReordered && VERBOSE)
      {
      for(int caloPoints = 0; caloPoints < nMCRecoSpts; caloPoints++)
         {
	 std::cout<<"Run = "<<run<<", Event = "<<event<<" point = "<<caloPoints<<", RR = "<<MCRecoResRange[caloPoints]<<", dE/dX = "<<MCRecodEdX[caloPoints]<<std::endl;
      
      
         }//<---End caloPoints
      std::cout<<std::endl;	 
      }//<---Putting in a print to make sure things are reordered correctly   
   
// ---------------------------------------------------------------------------------------------------------------------------------------
   
   
   
   // ####################################################################
   // ### Fix the calorimetry issues associated with huge fluctuations ###
   // ###            by extrapolating through the points               ###
   // ####################################################################
   if(FixCaloIssue_ExtremeFluctuation)
      {
      // ################################
      // ### Loop over the caloPoints ###
      // ################################
      for(int caloPoints = 0; caloPoints < nMCRecoSpts; caloPoints++)
         {
	 
	 // ###################################################
	 // ### If the dE/dX is large and at the end of the ###
	 // ###  track as expected with a proton attached   ###
	 // ###################################################
	 if(MCRecodEdX[caloPoints] > 40. && caloPoints == (nMCRecoSpts-1) )
	    {
	    // ##########################################################
	    // ### Set this point equal to the previous point's dE/dX ###
	    // ##########################################################
	    MCRecodEdX[caloPoints] = MCRecodEdX[caloPoints - 1];
	    }//<---End large and at the end of the track
	 
	 // ############################################################
	 // ### Else, if it is a large dE/dX but not the first point ###
	 // ############################################################
	 else if(MCRecodEdX[caloPoints] > 40. && caloPoints < (nMCRecoSpts-1) && caloPoints > 0.)
	    {
	    
	    if(VERBOSE){std::cout<<"Large Fluctuation"<<std::endl;}
	    // #################################################################
	    // ### Then just average between the previous and the next point ###
	    // #################################################################
	    MCRecodEdX[caloPoints] = ( (MCRecodEdX[caloPoints - 1] + MCRecodEdX[caloPoints + 1]) / 2.);
	    
	    }//<--End large and not at the end of the track
      
         }//<---End caloPoints loop
      
      }//<---Only fixing calorimetry for big fluctuations

// ---------------------------------------------------------------------------------------------------------------------------------------
   
   // ##############################################################################
   // ### Fix the calorimetry issues associated with slightly large fluctuations ###
   // ###                 by extrapolating through the points                    ###
   // ##############################################################################
   if(FixCaloIssue_LessExtremeFluctuation)
      {
      for(int caloPoints = 0; caloPoints < nMCRecoSpts; caloPoints++)
         {
	 // ### If dE/dX > 15 and more than 10cm from the end of the track and isn't the first or last point ###
	 if(MCRecodEdX[caloPoints] > 15. && MCRecoResRange[caloPoints] > 10. && caloPoints > 0.&& caloPoints < (nMCRecoSpts-1) )
	    {
	    if(VERBOSE){std::cout<<"Small Fluctuation"<<std::endl;}
	    // ### Check to see if the previous point is greater than 15 ###
	    if(MCRecodEdX[caloPoints-1] > 15.)
	       {
	       // ### Check to see if the next point is greater than 15 ###
	       if(MCRecodEdX[caloPoints+1] > 15. )
	          {
		  // ### Go 2 points before and after ###
		  MCRecodEdX[caloPoints] = ( (MCRecodEdX[caloPoints - 2] + MCRecodEdX[caloPoints + 2]) / 2.);
		  }
	       else
	          {
		  // ### Go 2 points before and one point after ###
		  MCRecodEdX[caloPoints] = ( (MCRecodEdX[caloPoints - 2] + MCRecodEdX[caloPoints + 1]) / 2.);
		  }
	        }
	    else if(MCRecodEdX[caloPoints-1] <= 15.)
	       {
	       if(MCRecodEdX[caloPoints+1] > 15. )
	          {
		  MCRecodEdX[caloPoints] = ( (MCRecodEdX[caloPoints - 1] + MCRecodEdX[caloPoints+2]) / 2.);
		  }
	       else
	          {
		  MCRecodEdX[caloPoints] = ( (MCRecodEdX[caloPoints - 2] + MCRecodEdX[caloPoints + 1]) / 2.);
		  }
	       }
	   else MCRecodEdX[caloPoints] = ( (MCRecodEdX[caloPoints - 1] + MCRecodEdX[caloPoints+1]) / 2.);
	   }
	
      
         }//<---End caloPoints loop
      
      }//<---Only fixing calorimetry for less big fluctuations   
   
   // ##########################################
   // ### Filling the fixed dE/dX vs RR plot ###
   // ##########################################
   for(int caloPoints = 0; caloPoints < nMCRecoSpts; caloPoints++)
      {
      
      hRecoMCdEdXvsRRFix->Fill(MCRecoResRange[caloPoints], MCRecodEdX[caloPoints]);
      
      hRecoMCdEdXFixed->Fill(MCRecodEdX[caloPoints]);
      
      if(g4PrimaryProcess[0] == 4 || g4PrimaryProcess[0] == 12 && InitialKinEnAtTPC < 300 )
         { hRecoMCdEdXvsRRFixedDecCap->Fill(MCRecoResRange[caloPoints], MCRecodEdX[caloPoints]);}
      
      }//<---End Fix
   
   
   // =========================================================================================================================================
   //						Filling Incident and Interacting Histograms
   // =========================================================================================================================================
   
   // #########################################
   // ### Loop over the tracks in the event ###
   // #########################################
   for(int nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {
      // ### Skipping all the tracks which aren't well matched ###
      if(!MatchTPC_WVTrack[nTPCtrk]){continue;}
      
      // ############################################
      // ### Loop over all the calorimetry points ###
      // ############################################
      for(int npoints = 0; npoints < nMCRecoSpts; npoints++)
         {
	 // ### Filling the incidient histogram weighted by beam profile ###
         hRecoMCIncidentKE->Fill(kineticEnergy, EventWeight);
	 
	 hRecoMCIncidentKEunweighted->Fill(kineticEnergy);
      
         // ###            Filling the interaction histogram for the last spt          ###
	 // ### As long as it isn't a through going track and isn't tagged as stopping ###
         if(npoints == nMCRecoSpts -1 && !ThroughGoingTrack[nTPCtrk] && !StoppingParticle[nTPCtrk] )
            {
	    
	    // ### Weighting the Interaction by the beam profile ###
	    hRecoMCInteractingKE->Fill(kineticEnergy, EventWeight);
	    
	    // ### Saving the unweighted interaction ###
	    hRecoMCInteractingKEunweighted->Fill(kineticEnergy);
	    }
         
	 // ################################################
	 // ### Subtracting the energy loss in this step ###
	 // ################################################
         float energyLossInStep = MCRecodEdX[npoints] * MCRecoPitch[npoints];
         
	 // #######################################################
	 // ### Removing that kinetic energy from the histogram ###
	 // #######################################################
         kineticEnergy -= energyLossInStep;
      
      
      
      
         }//<---End npoints loop
      }//<---End nTPCtrk loop





   }//<---End jentry loop


// ===============================================================================================================
//					MAKING THE CROSS-SECTION PLOT
// ===============================================================================================================

// ###################################################################
// #### Looping over the exiting bins to extract the cross-section ###
// ###################################################################
for( int iBin = 1; iBin <= hRecoMCInteractingKE->GetNbinsX(); ++iBin )
   {
   // ### If an incident bin is equal to zero then skip that bin ###
   if( hRecoMCIncidentKE->GetBinContent(iBin) == 0 )continue; //Temporary fix to ensure that no Infinities are propagated to pad
   
   // ### Cross-section = (Exit Bins / Incident Bins) * (1/Density) * (1/slab width) ###
   float TempCrossSection = (hRecoMCInteractingKE->GetBinContent(iBin)/hRecoMCIncidentKE->GetBinContent(iBin)) * (1/number_density) * (1/slab_width);
   
   // ### Covert this into Barns ###
   float crossSection = TempCrossSection * (1/1e-28);
   
   // ### Putting the value on the plot
   fCrossSection->SetBinContent(iBin,crossSection);
   
   // ###########################################################
   // ### Calculating the error on the numerator of the ratio ###
   // ###########################################################
   float numError = pow(hRecoMCInteractingKE->GetBinContent(iBin),0.5);
   float num = hRecoMCInteractingKE->GetBinContent(iBin);

   // ### Putting in a protection against dividing by zero ###   
   if(num == 0){num = 1;}
   float term1 = numError/num;
   
   // #################################################
   // ### Calculating the error on the denomentator ###
   // #################################################
   float denomError = pow(hRecoMCIncidentKE->GetBinContent(iBin),0.5);
   float denom = hRecoMCIncidentKE->GetBinContent(iBin);
   if(denom == 0){denom = 1;}
   
   // ### Putting in a protection against dividing by zero ###
   float term2 = denomError/denom;
   
   float totalError = (TempCrossSection) * (pow( ( (term1*term1) + (term2*term2) ),0.5)) * (1/number_density) * (1/slab_width) * (1/1e-28) *(1e26);
   //std::cout<<"totalError = "<<totalError<<std::endl;
   fCrossSection->SetBinError(iBin,totalError);
   
   }//<---End iBin Loop




// ========================================================================================================
// ===					EVENT REDUCTION TABLE						===
// ========================================================================================================
std::cout<<std::endl;
std::cout<<"########################################################################"<<std::endl;
std::cout<<"### Number of Events in AnaModule                                = "<<nTotalEvents<<" ###"<<std::endl;
std::cout<<"-------------------------------   Stage 0   ----------------------------"<<std::endl;
std::cout<<"### Number of Events w/ WC Track                                 = "<<nEvtsWCTrack<<" ###"<<std::endl;
std::cout<<"### Number of Events w/ TOF > "<<LowerTOFGoodReco<<" ns and < "<<UpperTOFGoodReco<<" ns                   = "<<nEvtsTOF<<" ###"<<std::endl;
std::cout<<"### Number of Events w/ Good TPC info (nHits > 0)		     = "<<nEvntsTPC<<" ###"<<std::endl;
std::cout<<"-------------------------------   Stage 1   ----------------------------"<<std::endl;
std::cout<<"### Number of Events w/ PID consistent with Pi/Mu                = "<<nEvtsPID<<" ###"<<std::endl;
std::cout<<"-------------------------------   Stage 2   ----------------------------"<<std::endl;
std::cout<<"### Number of Events w/ Primary MC which enters the TPC                   = "<<nEvtsGoodMC<<" ###"<<std::endl;
std::cout<<"### Number of Events w/ Trk Z < "<<FirstSpacePointZPos<<"                                = "<<nEvtsTrackZPos<<" ###"<<std::endl;
std::cout<<"### Number of Events w/ < "<<nLowZTracksAllowed<<" tracks in the first "<<UpperPartOfTPC<<" cm of the TPC = "<<nLowZTrkEvents<<" ###"<<std::endl;
std::cout<<"### Number of Events that are not Shower Like                        = "<<nNonShowerEvents<<std::endl;
std::cout<<"### Number of Events w/ ONE WC Track Matched                     = "<<nEvtsWCTrackMatch<<" ###"<<std::endl;
std::cout<<"###              ( "<<DeltaXLowerBound<<" < Delta X < "<<DeltaXUpperBound<<" , "<<DeltaYLowerBound<<" < Delta Y < "<<DeltaYUpperBound<<" )              ###"<<std::endl;
std::cout<<"###                 and alpha less the "<<alphaCut<<" degrees                      ###"<<std::endl;
std::cout<<"########################################################################"<<std::endl;
std::cout<<std::endl;   
   
// ===========================================================================================
// ============================  Writing out histograms to ROOT File =========================
// ===========================================================================================


// ### MC Info ###
hMCPrimaryStartX->Write();
hMCPrimaryStartY->Write();
hMCPrimaryStartZ->Write();
hMCPrimaryProjectedStartX->Write();
hMCPrimaryProjectedStartY->Write();
hMCPrimaryProjectedStartZ->Write();
hMCPrimaryEndX->Write();
hMCPrimaryEndY->Write();
hMCPrimaryEndZ->Write();
hMCPrimaryEndXvsZ->Write();
hMCPrimaryEndYvsZ->Write();
hMCPrimaryProcess->Write();
hMCPrimaryPx->Write();
hMCPrimaryPy->Write();
hMCPrimaryPz->Write();
hMCTrueLength->Write();

hMCPrimaryPxUnWeighted->Write();
hMCPrimaryPyUnWeighted->Write();
hMCPrimaryPzUnWeighted->Write();

hRecoMCUpstreamZPos->Write();
hRecoMCTPCTheta->Write();
hRecoMCTPCPhi->Write();
hRecoMCTPCPhiUnWeighted->Write();
hRecoMCTPCThetaUnWeighted->Write();
hRecoMCWCTheta->Write();
hRecoMCWCThetaUnWeighted->Write();
hRecoMChWCPhi->Write();
hRecoMChWCPhiUnWeighted->Write();
hRecoMCDeltaWCTrkX->Write();
hRecoMCDeltaWCTrkY->Write();
hRecoMCAlpha->Write();
hRecoMCNMatchTPCWCTrk->Write();
hRecoMCWCTRKMomentum->Write();
hRecoMCInitialKEMomentum->Write();
hRecoMCInitialKEMomentumUnWeighted->Write();
hRecoMCdEdX->Write();
hRecoMCdQdX->Write();

hRecoMCPionRR->Write();
hRecoMCPionTrkPitch->Write();
hRecoMCdEdXvsRR->Write();
hRecoMCLowMomentumTrkPIDA->Write();
hRecoMCIncidentKE->Write();
hRecoMCIncidentKEunweighted->Write();
hRecoMCInteractingKE->Write();
hRecoMCInteractingKEunweighted->Write();
fCrossSection->Write();   
hRecoLength->Write();
hRecoMCTrkInitialX->Write();
hRecoMCTrkInitialXUnweighted->Write();
hRecoMCTrkInitialY->Write();
hRecoMCTrkInitialYUnweighted->Write();
hRecoMCdEdXvsRRFix->Write();
hRecoMCdEdXFixed->Write();
hRecoMCLowMomentumTrkPIDACapDec->Write();
hRecoMCdEdXvsRRFixedDecCap->Write();

DeltaEvsPIDAAll->Write();
DeltaEvsPIDADecayCap->Write();


hMCRecodEdXQ1->Write();
hMCRecodQdXQ1->Write();
hMCRecodEdXQ2->Write();
hMCRecodQdXQ2->Write();
hMCRecodEdXQ3->Write();
hMCRecodQdXQ3->Write();
hMCRecodEdXQ4->Write();
hMCRecodQdXQ4->Write();

   
}//<---End Loop() Function
