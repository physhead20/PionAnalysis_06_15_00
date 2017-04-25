#define ProtonMC_cxx
#include "ProtonMC.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <TVector3.h>

// ===================================================================================================================
// ====================================       PUT HISTOGRAMS HERE           ==========================================
// ===================================================================================================================

/////////////////////////////////// Primary Particle Start X Position //////////////////////////////////////////
TH1D *hMCPrimaryStartX = new TH1D("hMCPrimaryStartX", "Primary Particle X_{0}", 200, -50 , 50);
/////////////////////////////////// Primary Particle Start Y Position //////////////////////////////////////////
TH1D *hMCPrimaryStartY = new TH1D("hMCPrimaryStartY", "Primary Particle Y_{0}", 200, -50 , 50);
/////////////////////////////////// Primary Particle Start Z Position //////////////////////////////////////////
TH1D *hMCPrimaryStartZ = new TH1D("hMCPrimaryStartZ", "Primary Particle Z_{0}", 600, -120 , 180);

/////////////////////////////////// Primary Particle End X Position //////////////////////////////////////////
TH1D *hMCPrimaryEndX = new TH1D("hMCPrimaryEndX", "Primary Particle X_{f}", 120, -10 , 50);
/////////////////////////////////// Primary Particle End Y Position //////////////////////////////////////////
TH1D *hMCPrimaryEndY = new TH1D("hMCPrimaryEndY", "Primary Particle Y_{f}", 40, -20 , 20);
/////////////////////////////////// Primary Particle End Z Position //////////////////////////////////////////
TH1D *hMCPrimaryEndZ = new TH1D("hMCPrimaryEndZ", "Primary Particle Z_{f}", 200, -10 , 90);

/////////////////////////////////// Primary Particle Start X Position inside TPC //////////////////////////////////////////
TH1D *hMCPrimaryTPCStartX = new TH1D("hMCPrimaryTPCStartX", "Primary Particle X_{0} inside TPC", 200, -50 , 50);
/////////////////////////////////// Primary Particle Start Y Position inside TPC //////////////////////////////////////////
TH1D *hMCPrimaryTPCStartY = new TH1D("hMCPrimaryTPCStartY", "Primary Particle Y_{0} inside TPC", 200, -50 , 50);
/////////////////////////////////// Primary Particle Start Z Position inside TPC //////////////////////////////////////////
TH1D *hMCPrimaryTPCStartZ = new TH1D("hMCPrimaryTPCStartZ", "Primary Particle Z_{0} inside TPC", 600, -120 , 180);

/////////////////////////////////// Primary Particle Initial Px   //////////////////////////////////////////
TH1D *hMCPrimaryPxUnWeighted = new TH1D("hMCPrimaryPxUnWeighted", "Primary Particle P_{x}", 300, -150 , 150);
/////////////////////////////////// Primary Particle Initial Py  //////////////////////////////////////////
TH1D *hMCPrimaryPyUnWeighted = new TH1D("hMCPrimaryPyUnWeighted", "Primary Particle P_{y}", 300, -159 , 150);
/////////////////////////////////// Primary Particle Initial Pz //////////////////////////////////////////
TH1D *hMCPrimaryPzUnWeighted = new TH1D("hMCPrimaryPzUnWeighted", "Primary Particle P_{z}", 250, 0 , 2500);

/////////////////////////////////// Primary End X vs Z Position //////////////////////////////////////////////
TH2D *hMCPrimaryEndXvsZ = new TH2D("hMCPrimaryEndXvsZ", "X_{f} vs Z_{f}", 200, -10, 90, 120, -10, 50);
/////////////////////////////////// Primary End Y vs Z Position //////////////////////////////////////////////
TH2D *hMCPrimaryEndYvsZ = new TH2D("hMCPrimaryEndYvsZ", "Y_{f} vs Z_{f}", 200, -10, 90, 40, -20, 20);


/////////////////////////////////////////// Initial Kinetic Energy ///////////////////////////////////////////
TH1D *hMCTrueInitialKE = new TH1D("hMCTrueInitialKE", "Initial Kinetic Energy (MC Truth)", 1100, -100, 1000);

/////////////////////////////////// Energy Loss in the upstream region of the beamline ///////////////////////
TH1D *hMCTrueELossUpstream = new TH1D("hMCTrueELossUpstream", "Energy loss prior to entering the TPC (MC Truth)", 1100, -100, 1000);

/////////////////////////////////// Energy Loss in the TPC  ///////////////////////
TH1D *hMCTrueELossInTPC = new TH1D("hMCTrueELossInTPC", "Energy loss inside the TPC (MCTruth)", 1100, -100, 1000);

/////////////////////////////////// Final Kinetic Energy in the TPC /////////////////////////
TH1D *hERemainMCTrue = new TH1D("hERemainMCTrue", "Remaining Energy from MC Truth", 1000, -50, 50);

/////////////////////////////////// E Loss upstream of the TPC /////////////////////////
TH2D *hELossXvsY = new TH2D("hELossXvsY", "Energy Loss X vs Y", 200, 0, 50, 200, -25, 25);

/////////////////////////////////// E Loss upstream of the Flux TPC /////////////////////////
TH2D *hELossXvsYFlux = new TH2D("hELossXvsYFlux", "Energy Loss X vs Y", 200, 0, 50, 200, -25, 25);

/////////////////////////////////// Divided E Loss /////////////////////////
TH2D *hELossXvsYDivide = new TH2D("hELossXvsYDivide", "Energy Loss X vs Y", 200, 0, 50, 200, -25, 25);

////////////////////////////////// MC Theta  //////////////////////////////
TH1D *hMCThetaAtFrontFace = new TH1D("hMCThetaAtFrontFace", "#theta at the front face of the TPC", 80, -10, 30);

////////////////////////////////// MC Phi  //////////////////////////////
TH1D *hMCPhiAtFrontFace = new TH1D("hMCPhiAtFrontFace", "#phi at the front face of the TPC", 360, 0, 360);

/////////////////////////////////// Phi vs Theta ELoss /////////////////////////
TH2D *hPhivsThetaELoss = new TH2D("hPhivsThetaELoss", "Phi vs Energy Loss", 360, 0, 360, 40, -10, 30);

/////////////////////////////////// Phi vs Theta ELoss Flux /////////////////////////
TH2D *hPhivsThetaELossFlux = new TH2D("hPhivsThetaELossFlux", "Phi vs Energy Loss", 360, 0, 360, 40, -10, 30);

/////////////////////////////////// Phi vs Theta ELoss Divided /////////////////////////
TH2D *hPhivsThetaELossDivided = new TH2D("hPhivsThetaELossDivided", "Phi vs Energy Loss", 360, 0, 360, 40, -10, 30);



/////////////////////////////////// Weird Energy Loss Peak 1 X vs Z //////////////////////////////////////////////
TH2D *hMCPrimaryXvsZNotWeirdPeak = new TH2D("hMCPrimaryXvsZNotWeirdPeak", "X vs Z", 200, -100, 10, 120, -10, 50);
/////////////////////////////////// Weird Energy Loss Peak 1 Y vs Z //////////////////////////////////////////////
TH2D *hMCPrimaryYvsZNotWeirdPeak = new TH2D("hMCPrimaryYvsZNotWeirdPeak", "Y vs Z", 200, -100, 10, 40, -20, 20);

/////////////////////////////////// Weird Energy Loss Peak 1 X vs Z //////////////////////////////////////////////
TH2D *hMCPrimaryXvsZNotWeirdPeakFlux = new TH2D("hMCPrimaryXvsZNotWeirdPeakFlux", "X vs Z", 200, -100, 10, 120, -10, 50);
/////////////////////////////////// Weird Energy Loss Peak 1 Y vs Z //////////////////////////////////////////////
TH2D *hMCPrimaryYvsZNotWeirdPeakFlux = new TH2D("hMCPrimaryYvsZNotWeirdPeakFlux", "Y vs Z", 200, -100, 10, 40, -20, 20);

/////////////////////////////////// Weird Energy Loss Peak 1 X vs Z //////////////////////////////////////////////
TH2D *hMCPrimaryXvsZNotWeirdPeakDivide = new TH2D("hMCPrimaryXvsZNotWeirdPeakDivide", "X vs Z", 200, -100, 10, 120, -10, 50);
/////////////////////////////////// Weird Energy Loss Peak 1 Y vs Z //////////////////////////////////////////////
TH2D *hMCPrimaryYvsZNotWeirdPeakDivide = new TH2D("hMCPrimaryYvsZNotWeirdPeakDivide", "Y vs Z", 200, -100, 10, 40, -20, 20);




/////////////////////////////////// Weird Energy Loss Peak 1 X vs Z //////////////////////////////////////////////
TH2D *hMCPrimaryXvsZWeirdPeak1 = new TH2D("hMCPrimaryXvsZWeirdPeak1", "X vs Z", 200, -100, 10, 120, -10, 50);
/////////////////////////////////// Weird Energy Loss Peak 1 Y vs Z //////////////////////////////////////////////
TH2D *hMCPrimaryYvsZWeirdPeak1 = new TH2D("hMCPrimaryYvsZWeirdPeak1", "Y vs Z", 200, -100, 10, 40, -20, 20);

/////////////////////////////////// Weird Energy Loss Peak 1 X vs Z //////////////////////////////////////////////
TH2D *hMCPrimaryXvsZWeirdPeak1Flux = new TH2D("hMCPrimaryXvsZWeirdPeak1Flux", "X vs Z", 200, -100, 10, 120, -10, 50);
/////////////////////////////////// Weird Energy Loss Peak 1 Y vs Z //////////////////////////////////////////////
TH2D *hMCPrimaryYvsZWeirdPeak1Flux = new TH2D("hMCPrimaryYvsZWeirdPeak1Flux", "Y vs Z", 200, -100, 10, 40, -20, 20);

/////////////////////////////////// Weird Energy Loss Peak 1 X vs Z //////////////////////////////////////////////
TH2D *hMCPrimaryXvsZWeirdPeak1Divide = new TH2D("hMCPrimaryXvsZWeirdPeak1Divide", "X vs Z", 200, -100, 10, 120, -10, 50);
/////////////////////////////////// Weird Energy Loss Peak 1 Y vs Z //////////////////////////////////////////////
TH2D *hMCPrimaryYvsZWeirdPeak1Divide = new TH2D("hMCPrimaryYvsZWeirdPeak1Divide", "Y vs Z", 200, -100, 10, 40, -20, 20);


/////////////////////////////////// Energy Loss Upstream vs Particle Pz //////////////////////////////////////////
TH2D *hMCPrimaryPzvsELossUpstream = new TH2D("hMCPrimaryPzvsELossUpstream", "Energy Loss Upstream vs Primary Particle P_{z}", 250, 0 , 2500, 1100, -100, 1000);


// --------------------------------------------------------------------------------------------------------------
// --------------------                   Phi vs Theta loss for 5 cm < Y < 15 cm                         --------
// --------------------------------------------------------------------------------------------------------------
/////////////////////////////////// Phi vs Theta ELoss /////////////////////////
TH2D *hPhivsThetaELossTop = new TH2D("hPhivsThetaELossTop", "Phi vs Energy Loss ", 72, 0, 360, 8, -10, 30);

/////////////////////////////////// Phi vs Theta ELoss Flux /////////////////////////
TH2D *hPhivsThetaELossFluxTop = new TH2D("hPhivsThetaELossFluxTop", "Phi vs Energy Loss", 72, 0, 360, 8, -10, 30);

/////////////////////////////////// Phi vs Theta ELoss Divided /////////////////////////
TH2D *hPhivsThetaELossDividedTop = new TH2D("hPhivsThetaELossDividedTop", "Phi vs Energy Loss", 72, 0, 360, 8, -10, 30);

// --------------------------------------------------------------------------------------------------------------
// --------------------                   Phi vs Theta loss for 5 cm < Y < -5 cm                         --------
// --------------------------------------------------------------------------------------------------------------
/////////////////////////////////// Phi vs Theta ELoss /////////////////////////
TH2D *hPhivsThetaELossMid = new TH2D("hPhivsThetaELossMid", "Phi vs Energy Loss ", 72, 0, 360, 8, -10, 30);

/////////////////////////////////// Phi vs Theta ELoss Flux /////////////////////////
TH2D *hPhivsThetaELossFluxMid = new TH2D("hPhivsThetaELossFluxMid", "Phi vs Energy Loss", 72, 0, 360, 8, -10, 30);

/////////////////////////////////// Phi vs Theta ELoss Divided /////////////////////////
TH2D *hPhivsThetaELossDividedMid = new TH2D("hPhivsThetaELossDividedMid", "Phi vs Energy Loss", 72, 0, 360, 8, -10, 30);

// --------------------------------------------------------------------------------------------------------------
// --------------------                   Phi vs Theta loss for -5 cm < Y < -15 cm                         --------
// --------------------------------------------------------------------------------------------------------------
/////////////////////////////////// Phi vs Theta ELoss /////////////////////////
TH2D *hPhivsThetaELossBottom = new TH2D("hPhivsThetaELossBottom", "Phi vs Energy Loss ", 72, 0, 360, 8, -10, 30);

/////////////////////////////////// Phi vs Theta ELoss Flux /////////////////////////
TH2D *hPhivsThetaELossFluxBottom = new TH2D("hPhivsThetaELossFluxBottom", "Phi vs Energy Loss", 72, 0, 360, 8, -10, 30);

/////////////////////////////////// Phi vs Theta ELoss Divided /////////////////////////
TH2D *hPhivsThetaELossDividedBottom = new TH2D("hPhivsThetaELossDividedBottom", "Phi vs Energy Loss", 72, 0, 360, 8, -10, 30);


/////////////////////////////////// Energy Loss in the upstream region of the beamline ///////////////////////
TH1D *hMCELossUpstreamLookUp = new TH1D("hMCELossUpstreamLookUp", "Energy loss prior to entering the TPC (Map)", 1100, -100, 1000);


/////////////////////////////////// Final Kinetic Energy in the TPC using Map /////////////////////////
TH1D *hERemainMCMap = new TH1D("hERemainMCMap", "Remaining Energy from MC Map", 1000, -75, 75);

/////////////////////////////////// Delta Energy Loss between True and Map method /////////////////////////
TH1D *hDeltaEnergyLossTruevsMap = new TH1D("hDeltaEnergyLossTruevsMap", "#Delta Energy Loss Upstream (True - Map)", 1000, -75, 75);

/////////////////////////////////// Energy Loss in the upstream region of the beamline flat method ///////////////////////
TH1D *hMCELossUpstreamFlat = new TH1D("hMCELossUpstreamFlat", "Energy loss prior to entering the TPC (Flat 66.6 MeV)", 1100, -100, 1000);


/////////////////////////////////// Final Kinetic Energy in the TPC using Map /////////////////////////
TH1D *hERemainMCFlat = new TH1D("hERemainMCFlat", "Remaining Energy from MC using flat 66.6 MeV", 1000, -75, 75);



/////////////////////////////////// "Matched Track" dE/dX /////////////////////////////////////////////////////
TH1D *hRecoMCdEdX = new TH1D("hRecoMCdEdX", "Matched Track dE/dX", 200, 0, 50);

/////////////////////////////////// "Matched Track" Residual Range //////////////////////////////////////////
TH1D *hRecoMCResidualRange = new TH1D("hRecoMCResidualRange", "Matched Track Residual Range", 400, -100, 100);

/////////////////////////////////// "Matched Track" Track Pitch //////////////////////////////////////////////
TH1D *hRecoMCTrkPitch = new TH1D("hRecoMCTrkPitch", "Matched Track Pitch", 1000, 0, 5);

///////////////////////////////// "Matched Track" dE/dX vs RR ///////////////////////////////////////////////
TH2D *hRecoMCdEdXvsRR = new TH2D("hRecoMCdEdXvsRR", "dE/dX vs Residual Range",200, 0, 100, 200, 0, 50);

/////////////////////////////////// Energy Loss in the TPC (Reco-info)  /////////////////////////////////////
TH1D *hMCELossRecoInTPC = new TH1D("hMCELossRecoInTPC", "Reconstructed Energy loss inside the TPC", 1100, -100, 1000);

/////////////////////////////////// TPC Track Phi at the upstream point ///////////////////////////////////////
TH1D *hRecoMCTPCPhi = new TH1D("hRecoMCTPCPhi", "TPC Track Phi", 360, 0, 360);

/////////////////////////////////// TPC Track Theta at the upstream point //////////////////////////////////////
TH1D *hRecoMCTPCTheta = new TH1D("hRecoMCTPCTheta", "TPC Track Theta", 180, 0, 90);

/////////////////////////////////// Reconstructed Particle Start X Position inside TPC //////////////////////////////////////////
TH1D *hRecoMCTPCStartX = new TH1D("hRecoMCTPCStartX", "Reconstructed X_{0} inside TPC", 200, -50 , 50);
/////////////////////////////////// Reconstructed Particle Start Y Position inside TPC //////////////////////////////////////////
TH1D *hRecoMCTPCStartY = new TH1D("hRecoMCTPCStartY", "Reconstructed Y_{0} inside TPC", 200, -50 , 50);
/////////////////////////////////// Reconstructed Particle Start Z Position inside TPC //////////////////////////////////////////
TH1D *hRecoMCTPCStartZ = new TH1D("hRecoMCTPCStartZ", "Primary Particle Z_{0} inside TPC", 600, -120 , 180);

/////////////////////////////////// Final Kinetic Energy in the TPC using TPC Reco Only /////////////////////////
TH1D *hERemainTPCRecoOnly = new TH1D("hERemainTPCRecoOnly", "Remaining Energy using TPC Reco Energy", 1000, -75, 75);

/////////////////////////////////// Energy Loss in the upstream region of the beamline using TPC theta and Phi ///////////////////////
TH1D *hMCELossUpstreamTPCRecoMap = new TH1D("hMCELossUpstreamTPCRecoMap", "Energy loss prior to entering the TPC (using Reco TPC #theta and #phi)", 1100, -100, 1000);


/////////////////////////////////// Delta Energy Loss in TPC between True and dE/dX method /////////////////////////
TH1D *hDeltaEnergyLossInTPCTruevsReco = new TH1D("hDeltaEnergyLossInTPCTruevsReco", "#Delta Energy Loss in the TPC (True - Reco)", 1000, -75, 75);

// ===================================================================================================================
// ===================================================================================================================




void ProtonMC::Loop()
{

// ##########################################################
// ### Putting in some counters for event reduction table ###
// ##########################################################
int nTotalEvents = 0, TrueStoppingParticle = 0, nRecoEvents = 0;


float particle_mass = 938.28 ;

// ########################################################################
// ### Fiducial Boundry Cuts (used to determine if a track is stopping) ###
// ########################################################################
double XLowerFid = 0;
double XUpperFid = 47;

double YLowerFid = -20;
double YUpperFid = 20;

double ZLowerFid = 0;
double ZUpperFid = 90;


// ###################################
// ### Load the calibration tables ###
// ###################################
TFile *f1 = new TFile("./DataDrivenProtonMC_EnergyCalibrationTable.root");


if (fChain == 0) return;
Long64_t nentries = fChain->GetEntriesFast();
Long64_t nbytes = 0, nb = 0;
   
// #######################################################
// ###                 Looping over events             ###
// ####################################################### 
for (Long64_t jentry=0; jentry<nentries;jentry++) 
//for (Long64_t jentry=0; jentry<25000;jentry++) 
   {
   Long64_t ientry = LoadTree(jentry);
   if (ientry < 0) break;
   nb = fChain->GetEntry(jentry);   nbytes += nb;
   
   
   // #############################
   // ### Counting Total Events ###
   // #############################
   nTotalEvents++;
   
   
   // === Outputting every nEvents to the screen ===
   if(nTotalEvents % 1000 == 0){std::cout<<"Event = "<<nTotalEvents<<std::endl;}

   //=======================================================================================================================
   //					      GEANT 4 Information
   //=======================================================================================================================      
   
   
   bool EventsWhereParticleStops = false;
   
   int nG4Primary = 0;
   int nG4TrajPoints = 0;
   
   float g4Primary_X0[100] = {0.}, g4Primary_Y0[100] = {0.}, g4Primary_Z0[100] = {0.};
   float g4Primary_Xf[100] = {0.}, g4Primary_Yf[100] = {0.}, g4Primary_Zf[100] = {0.};
   float g4Primary_Px[100] = {0.}, g4Primary_Py[100] = {0.}, g4Primary_Pz[100] = {0.};
   
   // #############################################
   // ###       Defining variables for the      ###
   // ### momentum at the front face of the TPC ###
   // #############################################
   
   float FrontFace_Px = 0, FrontFace_Py = 0, FrontFace_Pz = 0;
   
   // #################################
   // ### Variables for Energy Loss ###
   // #################################
   float EnergyLossOutsideTPC = 0;
   float EnergyLossInsideTPC = 0;
   float ERemainingMCTrue = 9999;
   
   float ERemainingMCMap = 9999;
   
   float ERemainingMCDumbFlat = 9999;
   
   float RecoEnergyLossInsideTPC = 0;
   
   float EnergyRemainingRecoTPCOnly = 9999;
   
   float InitialKineticEnergy = 0;
   
   float EnergyLossFromMap = 0;
   
   // #######################################
   // ### Loop over all the G4  particles ###
   // #######################################
   for (int iG4 = 0; iG4 < geant_list_size; iG4++)
      {
      
      
      // #################################################################
      // ### Set to true if this event is a stopping proton in the TPC ###
      // #################################################################
      
      if(pdg[iG4] == 2212 && process_primary[iG4] == 1 && 
         EndPointz[iG4] > 0 && EndPointz[iG4] < 90 && EndPointx[iG4] > 0 && 
         EndPointx[iG4] < 47 && EndPointy[iG4] > -20 && 
	 EndPointy[iG4] < 20 && NumberDaughters[iG4] == 0) {EventsWhereParticleStops = true;  }

      else {continue;}
      
      
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
      
      
      
      // ==========================
      // === Filling histograms ===
      // ==========================
      hMCPrimaryPxUnWeighted->Fill(g4Primary_Px[nG4Primary]);
      hMCPrimaryPyUnWeighted->Fill(g4Primary_Py[nG4Primary]);
      hMCPrimaryPzUnWeighted->Fill(g4Primary_Pz[nG4Primary]);
      
      hMCPrimaryStartX->Fill(StartPointx[iG4]);
      hMCPrimaryStartY->Fill(StartPointy[iG4]);
      hMCPrimaryStartZ->Fill(StartPointz[iG4]);
      
      hMCPrimaryEndX->Fill(EndPointx[iG4]);
      hMCPrimaryEndY->Fill(EndPointy[iG4]);
      hMCPrimaryEndZ->Fill(EndPointz[iG4]);
      
      hMCPrimaryEndXvsZ->Fill(EndPointz[iG4], EndPointx[iG4]);
      hMCPrimaryEndYvsZ->Fill(EndPointz[iG4], EndPointy[iG4]);
      
      
      
      // #############################################################
      // ### Calculating the momentum from the MC Primary Particle ###
      // #############################################################
      float momentumScale = sqrt( (g4Primary_Px[nG4Primary]*g4Primary_Px[nG4Primary]) + 
	                        (g4Primary_Py[nG4Primary]*g4Primary_Py[nG4Primary]) + 
				(g4Primary_Pz[nG4Primary]*g4Primary_Pz[nG4Primary]) );
				
      InitialKineticEnergy = pow( (momentumScale*momentumScale) + (particle_mass*particle_mass) ,0.5) - particle_mass;
      
      hMCTrueInitialKE->Fill(InitialKineticEnergy);
      
      
      // ### Defining first point ###
      float FirstPoint_Z = 999;
      float FirstPoint_Y = 999;
      float FirstPoint_X = 999;
      
      EnergyLossOutsideTPC = 0;
      
      // ##################################################
      // ### Looping over all primary trajectory points ###
      // ##################################################
      for(int iPriTrj = 1; iPriTrj < NTrTrajPts[iG4]; iPriTrj++)
         {
	 
	 // ### Only looking at points which are upstream of the TPC ###
	 if(MidPosZ[iG4][iPriTrj] < 0)
	    {
	    
	    float Momentum_Point1 = (sqrt((MidPx[iG4][iPriTrj-1]*MidPx[iG4][iPriTrj-1]) + 
	                               (MidPy[iG4][iPriTrj-1]*MidPy[iG4][iPriTrj-1]) +
				       (MidPz[iG4][iPriTrj-1]*MidPz[iG4][iPriTrj-1])))*1000;
				       
	    float Momentum_Point2 = (sqrt((MidPx[iG4][iPriTrj]*MidPx[iG4][iPriTrj]) + 
	                               (MidPy[iG4][iPriTrj]*MidPy[iG4][iPriTrj]) +
				       (MidPz[iG4][iPriTrj]*MidPz[iG4][iPriTrj])))*1000;
				       
	    float Energy_UpstreamPoint1 = sqrt( (Momentum_Point1*Momentum_Point1) + (particle_mass*particle_mass)  );
	       
	    float Energy_UpstreamPoint2 = sqrt( (Momentum_Point2*Momentum_Point2) + (particle_mass*particle_mass)  );
	       
	    EnergyLossOutsideTPC +=  Energy_UpstreamPoint1 - Energy_UpstreamPoint2;
	    }//<---End Looking at energy loss upstream of TPC
	    
	 // ##########################################################   
         // ### Only looking at points which are inside of the TPC ###
	 // ##########################################################
	 if(MidPosZ[iG4][iPriTrj] >= 0 && MidPosZ[iG4][iPriTrj] < 90 &&
	    MidPosX[iG4][iPriTrj] > 0 && MidPosX[iG4][iPriTrj] < 47 &&
	    MidPosY[iG4][iPriTrj] > -20 && MidPosY[iG4][iPriTrj] < 20 )
	    {
	    
	    float Momentum_Point1 = (sqrt((MidPx[iG4][iPriTrj-1]*MidPx[iG4][iPriTrj-1]) + 
	                               (MidPy[iG4][iPriTrj-1]*MidPy[iG4][iPriTrj-1]) +
				       (MidPz[iG4][iPriTrj-1]*MidPz[iG4][iPriTrj-1])))*1000;
				       
	    float Momentum_Point2 = (sqrt((MidPx[iG4][iPriTrj]*MidPx[iG4][iPriTrj]) + 
	                               (MidPy[iG4][iPriTrj]*MidPy[iG4][iPriTrj]) +
				       (MidPz[iG4][iPriTrj]*MidPz[iG4][iPriTrj])))*1000;
	       
	    // ### Storing the upstream point ###
	    if(MidPosZ[iG4][iPriTrj] < FirstPoint_Z)
	       {
	       FirstPoint_Z = MidPosZ[iG4][iPriTrj];
	       FirstPoint_Y = MidPosY[iG4][iPriTrj];
	       FirstPoint_X = MidPosX[iG4][iPriTrj];
	       //std::cout<<"FirstPoint_Z = "<<FirstPoint_Z<<std::endl;
	       //std::cout<<"MidPx[iG4][iPriTrj] = "<<MidPx[iG4][iPriTrj]<<std::endl;
	       FrontFace_Px = MidPx[iG4][iPriTrj] * 1000;
	       FrontFace_Py = MidPy[iG4][iPriTrj] * 1000;
	       FrontFace_Pz = MidPz[iG4][iPriTrj] * 1000;
	       
	       }//<---End finding upstream point
	    		       
	    float Energy_Point1 = sqrt( (Momentum_Point1*Momentum_Point1) + (particle_mass*particle_mass)  );
	       
	    //std::cout<<"Energy_Point1 = "<<Energy_Point1<<std::endl;
	    float Energy_Point2 = sqrt( (Momentum_Point2*Momentum_Point2) + (particle_mass*particle_mass)  );
	    //std::cout<<"Energy_Point2 = "<<Energy_Point2<<std::endl;
	       
	    //std::cout<<std::endl;
	    EnergyLossInsideTPC +=  Energy_Point1 - Energy_Point2;
	   
	    }//<---End Looking at energy loss upstream of TPC
	    
	    
	    
	    
	 }//<---iPriTrj loop
      // --- Filling initial TPC informationo ----
      hMCPrimaryTPCStartX->Fill(FirstPoint_X);
      hMCPrimaryTPCStartY->Fill(FirstPoint_Y); 
      hMCPrimaryTPCStartZ->Fill(FirstPoint_Z);	
      
       
      // --- Filling histograms for ELoss ---
      hMCTrueELossUpstream->Fill(EnergyLossOutsideTPC);
      hMCTrueELossInTPC->Fill(EnergyLossInsideTPC);
      
      hELossXvsY->Fill(FirstPoint_X, FirstPoint_Y, EnergyLossOutsideTPC);
      hELossXvsYFlux->Fill(FirstPoint_X, FirstPoint_Y);
      
      
      hMCPrimaryPzvsELossUpstream->Fill(momentumScale, EnergyLossOutsideTPC);
      
      
      // ### Studying weird behavior ###
      if(EnergyLossOutsideTPC > 85 || EnergyLossOutsideTPC < 105)
         {
	 // ##################################################
         // ### Looping over all primary trajectory points ###
         // ##################################################
         for(int iPriTrj = 1; iPriTrj < NTrTrajPts[iG4]; iPriTrj++)
            {
	 
	    // ### Only looking at points which are upstream of the TPC ###
	    if(MidPosZ[iG4][iPriTrj] < 0)
	       {
	       float Momentum_Point1 = (sqrt((MidPx[iG4][iPriTrj-1]*MidPx[iG4][iPriTrj-1]) + 
	                               (MidPy[iG4][iPriTrj-1]*MidPy[iG4][iPriTrj-1]) +
				       (MidPz[iG4][iPriTrj-1]*MidPz[iG4][iPriTrj-1])))*1000;
				       
	       float Momentum_Point2 = (sqrt((MidPx[iG4][iPriTrj]*MidPx[iG4][iPriTrj]) + 
	                               (MidPy[iG4][iPriTrj]*MidPy[iG4][iPriTrj]) +
				       (MidPz[iG4][iPriTrj]*MidPz[iG4][iPriTrj])))*1000;
				       
	       float Energy_UpstreamPoint1 = sqrt( (Momentum_Point1*Momentum_Point1) + (particle_mass*particle_mass)  );
	       
	       float Energy_UpstreamPoint2 = sqrt( (Momentum_Point2*Momentum_Point2) + (particle_mass*particle_mass)  );
	       
	       
	       float EnergyLossAtThisPoint = Energy_UpstreamPoint1 - Energy_UpstreamPoint2;
	       
	       hMCPrimaryXvsZWeirdPeak1->Fill(MidPosZ[iG4][iPriTrj], MidPosX[iG4][iPriTrj], EnergyLossAtThisPoint);
	       hMCPrimaryYvsZWeirdPeak1->Fill(MidPosZ[iG4][iPriTrj], MidPosY[iG4][iPriTrj], EnergyLossAtThisPoint);
	       
	       hMCPrimaryXvsZWeirdPeak1Flux->Fill(MidPosZ[iG4][iPriTrj], MidPosX[iG4][iPriTrj]);
	       hMCPrimaryYvsZWeirdPeak1Flux->Fill(MidPosZ[iG4][iPriTrj], MidPosY[iG4][iPriTrj]);
	       
	       }//End upstream requirement
	 
	 
	    }//<---End iPriTrj loop
	 }//<---End Weird peak
      if(EnergyLossOutsideTPC < 85 )
         {
	 // ##################################################
         // ### Looping over all primary trajectory points ###
         // ##################################################
         for(int iPriTrj = 1; iPriTrj < NTrTrajPts[iG4]; iPriTrj++)
            {
	 
	    // ### Only looking at points which are upstream of the TPC ###
	    if(MidPosZ[iG4][iPriTrj] < 0)
	       {
	       
	       float Momentum_Point1 = (sqrt((MidPx[iG4][iPriTrj-1]*MidPx[iG4][iPriTrj-1]) + 
	                               (MidPy[iG4][iPriTrj-1]*MidPy[iG4][iPriTrj-1]) +
				       (MidPz[iG4][iPriTrj-1]*MidPz[iG4][iPriTrj-1])))*1000;
				       
	       float Momentum_Point2 = (sqrt((MidPx[iG4][iPriTrj]*MidPx[iG4][iPriTrj]) + 
	                               (MidPy[iG4][iPriTrj]*MidPy[iG4][iPriTrj]) +
				       (MidPz[iG4][iPriTrj]*MidPz[iG4][iPriTrj])))*1000;
				       
	       float Energy_UpstreamPoint1 = sqrt( (Momentum_Point1*Momentum_Point1) + (particle_mass*particle_mass)  );
	       
	       float Energy_UpstreamPoint2 = sqrt( (Momentum_Point2*Momentum_Point2) + (particle_mass*particle_mass)  );
	       
	       
	       float EnergyLossAtThisPoint = Energy_UpstreamPoint1 - Energy_UpstreamPoint2;
	       
	       hMCPrimaryXvsZNotWeirdPeak->Fill(MidPosZ[iG4][iPriTrj], MidPosX[iG4][iPriTrj], EnergyLossAtThisPoint);
	       hMCPrimaryYvsZNotWeirdPeak->Fill(MidPosZ[iG4][iPriTrj], MidPosY[iG4][iPriTrj], EnergyLossAtThisPoint);
	       
	       hMCPrimaryXvsZNotWeirdPeakFlux->Fill(MidPosZ[iG4][iPriTrj], MidPosX[iG4][iPriTrj]);
	       hMCPrimaryYvsZNotWeirdPeakFlux->Fill(MidPosZ[iG4][iPriTrj], MidPosY[iG4][iPriTrj]);
	       
	       }//End upstream requirement
	 
	 
	    }//<---End iPriTrj loop
	 
	 
	 }//<---End Normal park of the peak 
      
      // ----------------------------------------------------------------------- 
      // ------------        Calculating the theta and phi at the       --------
      // ------------           at the front face of the TPC            --------
      // -----------------------------------------------------------------------
      
      // ################################################
      // ### Calculating the angles for the Geant4 MC ###
      // ################################################
      TVector3 z_hat_MC(0,0,1);
      TVector3 p_hat_0_MC;
      
      p_hat_0_MC.SetX(FrontFace_Px);
      p_hat_0_MC.SetY(FrontFace_Py);
      p_hat_0_MC.SetZ(FrontFace_Pz); 
      
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
        {if( p_hat_0_MC.X() > 0 ){ mcPhi = 0; }
        else{ mcPhi = 3.141592654; }
	}
      else if( p_hat_0_MC.X() == 0 )
        {
	if( p_hat_0_MC.Y() > 0 ){ mcPhi = 3.141592654/2; }
	else{ mcPhi = 3.141592654*3/2; }
	}
      
      
      // --- Filling the angle plots at the front face of the TPC ---
      hMCPhiAtFrontFace->Fill(mcPhi *(180/3.14159));
      hMCThetaAtFrontFace->Fill(mcTheta *(180/3.14159));
      
      hPhivsThetaELoss->Fill(mcPhi*(180/3.14159) ,mcTheta*(180/3.14159), EnergyLossOutsideTPC);
      hPhivsThetaELossFlux->Fill(mcPhi*(180/3.14159) ,mcTheta*(180/3.14159));
      
      // ###################################################
      // ### Getting the energy loss for 5cm < Y < 15 cm ###
      // ###################################################
      if(FirstPoint_Y > 5 && FirstPoint_Y < 15)
         {
         hPhivsThetaELossTop->Fill(mcPhi*(180/3.14159) ,mcTheta*(180/3.14159), EnergyLossOutsideTPC);
         hPhivsThetaELossFluxTop->Fill(mcPhi*(180/3.14159) ,mcTheta*(180/3.14159));
	 }
      
      // ###################################################
      // ### Getting the energy loss for 5cm < Y < -5 cm ###
      // ###################################################
      if(FirstPoint_Y > -5 && FirstPoint_Y < 5)
         {
         hPhivsThetaELossMid->Fill(mcPhi*(180/3.14159) ,mcTheta*(180/3.14159), EnergyLossOutsideTPC);
         hPhivsThetaELossFluxMid->Fill(mcPhi*(180/3.14159) ,mcTheta*(180/3.14159));
	 }
      
      // #####################################################
      // ### Getting the energy loss for -5cm < Y < -15 cm ###
      // #####################################################
      if(FirstPoint_Y > -15 && FirstPoint_Y < -5)
         {
         hPhivsThetaELossBottom->Fill(mcPhi*(180/3.14159) ,mcTheta*(180/3.14159), EnergyLossOutsideTPC);
         hPhivsThetaELossFluxBottom->Fill(mcPhi*(180/3.14159) ,mcTheta*(180/3.14159));
	 }
      
      // ###################################################################
      // ### Calculating the remaining energy of the particle from truth ###
      // ###################################################################
      ERemainingMCTrue = InitialKineticEnergy - EnergyLossOutsideTPC - EnergyLossInsideTPC;
      
      hERemainMCTrue->Fill(ERemainingMCTrue);
      
      
      
      
      
      // --------------------------------------------------------------------------------------------------
      // --------------------------------------------------------------------------------------------------
      // 					MAP THE ENERGY LOSS
      // --------------------------------------------------------------------------------------------------
      // --------------------------------------------------------------------------------------------------
      
      EnergyLossFromMap = 0;
      float PhiInDegrees   = mcPhi *(180/3.14159);
      float ThetaInDegrees = mcTheta *(180/3.14159);
      
      
      // ################################################
      // ### Deterimine which histogram I should open ###
      // ################################################
      if(FirstPoint_Y > 5 && FirstPoint_Y < 15)
         {
	 TH1F *hMCELossMap = (TH1F*)f1->Get("hPhivsThetaELossDividedTop");
	 
	 // ### Loop over the phi bins ###
	 for(int nXbins = 1; nXbins < hMCELossMap->GetNbinsX(); nXbins++)
            {
	    // ### Match the phi angle ###
	    if(PhiInDegrees > (nXbins - 1)*5 && PhiInDegrees < nXbins * 5)
	       {
	       // ### Loop over the theta bins ###
	       for(int nYbins = 1; nYbins < hMCELossMap->GetNbinsY(); nYbins++)
	          {
	          // ### Match the theta angle ###
		  if(ThetaInDegrees > ((nYbins - 1)*5) - 10 && ThetaInDegrees < (nYbins*5) - 10)
		     {
	             EnergyLossFromMap = hMCELossMap->GetBinContent(nXbins, nYbins);
		     
		     //std::cout<<"PhiInDegrees = "<<PhiInDegrees<<", ThetaInDegrees = "<<ThetaInDegrees<<std::endl;
		     //std::cout<<"EnergyLossFromMap = "<<EnergyLossFromMap<<std::endl;
	    
	             }//<---End only looking if theta is matched
	          }//<---End nYbins loop
	       }//<---End only looking if the Phi is matched
	    }//<---End nXbins loop
	 
	 }//<---End Y in the top
      
      // ################################################
      // ### Deterimine which histogram I should open ###
      // ################################################
      if(FirstPoint_Y > -5 && FirstPoint_Y < 5)
         {
	 TH1F *hMCELossMap = (TH1F*)f1->Get("hPhivsThetaELossDividedMid");
	 
	 // ### Loop over the phi bins ###
	 for(int nXbins = 1; nXbins < hMCELossMap->GetNbinsX(); nXbins++)
            {
	    // ### Match the phi angle ###
	    if(PhiInDegrees > (nXbins - 1)*5 && PhiInDegrees < nXbins * 5)
	       {
	       // ### Loop over the theta bins ###
	       for(int nYbins = 1; nYbins < hMCELossMap->GetNbinsY(); nYbins++)
	          {
	          // ### Match the theta angle ###
		  if(ThetaInDegrees > ((nYbins - 1)*5) - 10 && ThetaInDegrees < (nYbins*5) - 10)
		     {
	             EnergyLossFromMap = hMCELossMap->GetBinContent(nXbins, nYbins);
		     
		     //std::cout<<"PhiInDegrees = "<<PhiInDegrees<<", ThetaInDegrees = "<<ThetaInDegrees<<std::endl;
		     //std::cout<<"EnergyLossFromMap = "<<EnergyLossFromMap<<std::endl;
	    
	             }//<---End only looking if theta is matched
	          }//<---End nYbins loop
	       }//<---End only looking if the Phi is matched
	    }//<---End nXbins loop
	 
	 }//<---End Y in the top
      
      // ################################################
      // ### Deterimine which histogram I should open ###
      // ################################################
      if(FirstPoint_Y > -15 && FirstPoint_Y < -5)
         {
	 TH1F *hMCELossMap = (TH1F*)f1->Get("hPhivsThetaELossDividedBottom");
	 
	 // ### Loop over the phi bins ###
	 for(int nXbins = 1; nXbins < hMCELossMap->GetNbinsX(); nXbins++)
            {
	    // ### Match the phi angle ###
	    if(PhiInDegrees > (nXbins - 1)*5 && PhiInDegrees < nXbins * 5)
	       {
	       // ### Loop over the theta bins ###
	       for(int nYbins = 1; nYbins < hMCELossMap->GetNbinsY(); nYbins++)
	          {
	          // ### Match the theta angle ###
		  if(ThetaInDegrees > ((nYbins - 1)*5) - 10 && ThetaInDegrees < (nYbins*5) - 10)
		     {
	             EnergyLossFromMap = hMCELossMap->GetBinContent(nXbins, nYbins);
		     
		     //std::cout<<"PhiInDegrees = "<<PhiInDegrees<<", ThetaInDegrees = "<<ThetaInDegrees<<std::endl;
		     //std::cout<<"EnergyLossFromMap = "<<EnergyLossFromMap<<std::endl;
	    
	             }//<---End only looking if theta is matched
	          }//<---End nYbins loop
	       }//<---End only looking if the Phi is matched
	    }//<---End nXbins loop
	 
	 }//<---End Y in the top    
      
      if(EnergyLossFromMap == 0){EnergyLossFromMap = 66.6;}
      
      // ###################################################################
      // ### Calculating the remaining energy of the particle from truth ###
      // ###################################################################
      ERemainingMCMap = InitialKineticEnergy - EnergyLossFromMap - EnergyLossInsideTPC;
      
      ERemainingMCDumbFlat = InitialKineticEnergy - 66.6 - EnergyLossInsideTPC;
      
      
      float DeltaEnergyLoss = EnergyLossOutsideTPC - EnergyLossFromMap;
      
      hDeltaEnergyLossTruevsMap->Fill(DeltaEnergyLoss);
      
      // === Filling Histograms ===
      hERemainMCTrue->Fill(ERemainingMCTrue);
      hMCELossUpstreamLookUp->Fill(EnergyLossFromMap);
      hERemainMCMap->Fill(ERemainingMCMap);
      
      hMCELossUpstreamFlat->Fill(66.6);
      hERemainMCFlat->Fill(ERemainingMCDumbFlat);
      
      nG4Primary++;
      

      }//<---End iG4 loop
      
   // ##########################################################
   // ### Bump the counter if this is a true stopping proton ###
   // ##########################################################
   if(EventsWhereParticleStops){TrueStoppingParticle++;}
   else{continue;}
   
   
   
   //=======================================================================================================================
   //					      Reconstructed information
   //======================================================================================================================= 
   
   bool ReconstructedEvent = true;
   
   float MCRecodEdX[1000]  = {0.}; 
   int nMCRecoSpts = 0; 
   
   double MCRecoSptsX[1000];
   double MCRecoSptsY[1000];
   double MCRecoSptsZ[1000];
   
   double MCRecoResRange[1000]={0.};
   double MCRecoPitch[1000]={0.};
   
   // ##########################################
   // ### Loop over all reconstructed tracks ###
   // ##########################################
   for(int nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {
      // ###############################################################
      // ### Looping over the calorimetry spacepoints for this track ###
      // ###############################################################
      for(int nspts = 0; nspts < ntrkhits[nTPCtrk]; nspts++)
         {
	 MCRecodEdX[nMCRecoSpts]     = trkdedx[nTPCtrk][1][nspts];
	 // ### Putting in a fix in the case that the dE/dX is negative in this step ### 
	 // ###  then take the point before and the point after and average them
	 if(MCRecodEdX[nMCRecoSpts] < 0 && nspts < ntrkhits[nTPCtrk] && nspts > 0)
	    {MCRecodEdX[nMCRecoSpts] = ( (trkdedx[nTPCtrk][1][nspts - 1] + trkdedx[nTPCtrk][1][nspts + 1]) / 2);}
	 
	 // ### If this didn't fix it, then just skip the point ###
	 if(MCRecodEdX[nMCRecoSpts] < 0){continue;}
	 
	 
	 MCRecoResRange[nMCRecoSpts] = trkrr[nTPCtrk][1][nspts];
         MCRecoPitch[nMCRecoSpts] = trkpitchhit[nTPCtrk][1][nspts];
	 
	 MCRecoSptsX[nMCRecoSpts] = trkxyz[nTPCtrk][1][nspts][0];
	 MCRecoSptsY[nMCRecoSpts] = trkxyz[nTPCtrk][1][nspts][1];
	 MCRecoSptsZ[nMCRecoSpts] = trkxyz[nTPCtrk][1][nspts][2];
	 
	 
	 // ### Histogramming the dE/dX ###
	 hRecoMCdEdX->Fill(MCRecodEdX[nMCRecoSpts]);
	 
	 // ### Histogramming the residual range ###
	 hRecoMCResidualRange->Fill(MCRecoResRange[nMCRecoSpts]);
	 
	 // ### Histogramming the Pitch ###
	 hRecoMCTrkPitch->Fill(MCRecoPitch[nMCRecoSpts]);
	 
	 // ### Filling 2d dE/dX vs RR ###
	 hRecoMCdEdXvsRR->Fill(MCRecoResRange[nMCRecoSpts], MCRecodEdX[nMCRecoSpts]);
	 
	 // ================================================================
	 // === Calculating the Reconstructed Energy loss inside the TPC ===
	 // ================================================================
	 RecoEnergyLossInsideTPC+= MCRecodEdX[nMCRecoSpts] * MCRecoPitch[nMCRecoSpts];
	 
	 nMCRecoSpts++;
	 }//<---End nspts loop
      
      
      // ####################################################################
      // ### As long as a track in the event has a point reco'd...take it ###
      // ####################################################################
      
      }//<---End nTPCtrk loop

   
   float FirstSpacePointZ = 999;
   float FirstSpacePointY = 999;
   float FirstSpacePointX = 999;
	 
   float TempTrj_X = 999;
   float TempTrj_Y = 999;
   float TempTrj_Z = 999;
   
   float RecoTPCTheta = 999;
   float RecoTPCPhi   = 999;
   
   
   // ####################################
   // ### Loop over all the TPC Tracks ###
   // ####################################
   for(int nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {
      // === Set a dummy variables for the most upstream point ===
      FirstSpacePointZ = 999;
      FirstSpacePointY = 999;
      FirstSpacePointX = 999;
	 
      TempTrj_X = 999;
      TempTrj_Y = 999;
      TempTrj_Z = 999;
      // ###############################################################
      // ### Looping over the trajectory points for the prelim-track ###
      // ###############################################################
      for(int ntrjpts = 0; ntrjpts < nTrajPoint[nTPCtrk]; ntrjpts++)
         {
	    
	 // ### Recording this tracks upstream most X, Y, Z location, ###
	 // ###       which is inside the fiducial boundary           ###
	 if(trjPt_Z[nTPCtrk][ntrjpts] < FirstSpacePointZ && trjPt_Y[nTPCtrk][ntrjpts] > YLowerFid && 
	    trjPt_Y[nTPCtrk][ntrjpts] < YUpperFid && trjPt_X[nTPCtrk][ntrjpts] > XLowerFid && 
	    trjPt_X[nTPCtrk][ntrjpts] < XUpperFid && trjPt_Z[nTPCtrk][ntrjpts] < 14)
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
      
      hRecoMCTPCTheta->Fill(tpcTheta* (180.0/3.141592654));
      
      RecoTPCTheta = tpcTheta* (180.0/3.141592654);
   
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
      hRecoMCTPCPhi->Fill(tpcPhi* (180.0/3.141592654));
      
      RecoTPCPhi = tpcPhi* (180.0/3.141592654);
      
      }//<---end nTPCTrk
      // ===============================================================================================================            
      // ===============================================================================================================
   
   
   // ### Skipping events which aren't reconstructed ###
   if(nMCRecoSpts < 1){ReconstructedEvent = false; continue;}
   
   
   
   // ################################################
   // ### Deterimine which histogram I should open ###
   // ################################################
   if(FirstSpacePointY > 5 && FirstSpacePointY < 15)
      {
      TH1F *hMCELossMap = (TH1F*)f1->Get("hPhivsThetaELossDividedTop");
      
      // ### Loop over the phi bins ###
      for(int nXbins = 1; nXbins < hMCELossMap->GetNbinsX(); nXbins++)
         {
	 // ### Match the phi angle ###
	 if(RecoTPCPhi > (nXbins - 1)*5 && RecoTPCPhi < nXbins * 5)
	    {
	    // ### Loop over the theta bins ###
	    for(int nYbins = 1; nYbins < hMCELossMap->GetNbinsY(); nYbins++)
	       {
	       // ### Match the theta angle ###
	       if(RecoTPCTheta > ((nYbins - 1)*5) - 10 && RecoTPCTheta < (nYbins*5) - 10)
	          {
		  EnergyLossFromMap = hMCELossMap->GetBinContent(nXbins, nYbins);
		  
		  }//<---End only looking if theta is matched
	       }//<---End nYbins loop
	    }//<---End only looking if the Phi is matched
	 }//<---End nXbins loop
	 
      }//<---End Y in the top
      
   // ################################################
   // ### Deterimine which histogram I should open ###
   // ################################################
   if(FirstSpacePointY > -5 && FirstSpacePointY < 5)
      {
      TH1F *hMCELossMap = (TH1F*)f1->Get("hPhivsThetaELossDividedMid");
      
      // ### Loop over the phi bins ###
      for(int nXbins = 1; nXbins < hMCELossMap->GetNbinsX(); nXbins++)
         {
	 // ### Match the phi angle ###
	 if(RecoTPCPhi > (nXbins - 1)*5 && RecoTPCPhi < nXbins * 5)
	    {
	    // ### Loop over the theta bins ###
	    for(int nYbins = 1; nYbins < hMCELossMap->GetNbinsY(); nYbins++)
	       {
	       // ### Match the theta angle ###
	       if(RecoTPCTheta > ((nYbins - 1)*5) - 10 && RecoTPCTheta < (nYbins*5) - 10)
	          {
	          EnergyLossFromMap = hMCELossMap->GetBinContent(nXbins, nYbins);
		
	          }//<---End only looking if theta is matched
	       }//<---End nYbins loop
	    }//<---End only looking if the Phi is matched
	 }//<---End nXbins loop
      }//<---End Y in the top
      
   // ################################################
   // ### Deterimine which histogram I should open ###
   // ################################################
   if(FirstSpacePointY > -15 && FirstSpacePointY < -5)        
      {
      TH1F *hMCELossMap = (TH1F*)f1->Get("hPhivsThetaELossDividedBottom");
      
      // ### Loop over the phi bins ###
      for(int nXbins = 1; nXbins < hMCELossMap->GetNbinsX(); nXbins++)
         {
	 // ### Match the phi angle ###
	 if(RecoTPCPhi > (nXbins - 1)*5 && RecoTPCPhi < nXbins * 5)
	    {
	   // ### Loop over the theta bins ###
	    for(int nYbins = 1; nYbins < hMCELossMap->GetNbinsY(); nYbins++)
               {
               // ### Match the theta angle ###
	       if(RecoTPCTheta > ((nYbins - 1)*5) - 10 && RecoTPCTheta < (nYbins*5) - 10)
	          {
		  EnergyLossFromMap = hMCELossMap->GetBinContent(nXbins, nYbins);

	          }//<---End only looking if theta is matched
	       }//<---End nYbins loop
	    }//<---End only looking if the Phi is matched
	 }//<---End nXbins loop
	 
      }//<---End Y in the top    
      
   if(EnergyLossFromMap == 0){EnergyLossFromMap = 66.6;}
   
   hMCELossUpstreamTPCRecoMap->Fill(EnergyLossFromMap);
   
   
   
   
   
   
   
   // ### Filling Histograms ###
   hMCELossRecoInTPC->Fill(RecoEnergyLossInsideTPC);
   
   float DeltaEnergyLossInTPC = EnergyLossInsideTPC - RecoEnergyLossInsideTPC;
   
   hDeltaEnergyLossInTPCTruevsReco->Fill(DeltaEnergyLossInTPC);

   hRecoMCTPCStartX->Fill(FirstSpacePointX);
   hRecoMCTPCStartY->Fill(FirstSpacePointY);
   hRecoMCTPCStartZ->Fill(FirstSpacePointZ);
   
   // ########################################################################
   // ### Calculating the energy remaining using only reco TPC information ###
   // ########################################################################
   EnergyRemainingRecoTPCOnly = InitialKineticEnergy - EnergyLossOutsideTPC - RecoEnergyLossInsideTPC;
   
   hERemainTPCRecoOnly->Fill(EnergyRemainingRecoTPCOnly);
   
   if(ReconstructedEvent){nRecoEvents++;}
      
   }//<---End jentry loop
   
f1->Close();

std::cout<<"========================================================================================"<<std::endl;
std::cout<<"Total Number of Events 			    	   "<<nTotalEvents<<std::endl;
std::cout<<"Particles which reach the TPC and stop w/o interaction "<<TrueStoppingParticle<<std::endl;
std::cout<<"Events with reconstruction information                 "<<nRecoEvents<<std::endl;
std::cout<<"========================================================================================"<<std::endl;


// ###########################################
// ### Create a file for all my histograms ###
// ###########################################
TFile myfile("./DataDrivenProtonMC_EnergyCalibrationPlots.root","RECREATE");


// ##########################
// ### Dividing the plots ###
// ##########################
hELossXvsYDivide->Divide(hELossXvsY, hELossXvsYFlux);
hPhivsThetaELossDivided->Divide(hPhivsThetaELoss, hPhivsThetaELossFlux);
hPhivsThetaELossDividedTop->Divide(hPhivsThetaELossTop, hPhivsThetaELossFluxTop);
hPhivsThetaELossDividedMid->Divide(hPhivsThetaELossMid, hPhivsThetaELossFluxMid);
hPhivsThetaELossDividedBottom->Divide(hPhivsThetaELossBottom, hPhivsThetaELossFluxBottom);

hMCPrimaryXvsZWeirdPeak1Divide->Divide(hMCPrimaryXvsZWeirdPeak1, hMCPrimaryXvsZWeirdPeak1Flux);
hMCPrimaryYvsZWeirdPeak1Divide->Divide(hMCPrimaryYvsZWeirdPeak1, hMCPrimaryYvsZWeirdPeak1Flux);

hMCPrimaryXvsZNotWeirdPeakDivide->Divide(hMCPrimaryXvsZNotWeirdPeak, hMCPrimaryXvsZNotWeirdPeakFlux);
hMCPrimaryYvsZNotWeirdPeakDivide->Divide(hMCPrimaryYvsZNotWeirdPeak, hMCPrimaryYvsZNotWeirdPeakFlux);








///////////////////////////////////////////////////////////////////////////////////////
hMCPrimaryPxUnWeighted->Write();
hMCPrimaryPyUnWeighted->Write();
hMCPrimaryPzUnWeighted->Write();
      
hMCPrimaryStartX->Write();
hMCPrimaryStartY->Write();
hMCPrimaryStartZ->Write();
      
hMCPrimaryEndX->Write();
hMCPrimaryEndY->Write();
hMCPrimaryEndZ->Write(); 

hMCPrimaryEndXvsZ->Write();  
hMCPrimaryEndYvsZ->Write();

hMCTrueInitialKE->Write();  
hMCTrueELossUpstream->Write(); 
hMCTrueELossInTPC->Write();

hERemainMCTrue->Write();

hELossXvsY->Write();
hELossXvsYFlux->Write();
hELossXvsYDivide->Write();

hMCPhiAtFrontFace->Write();
hMCThetaAtFrontFace->Write();

hPhivsThetaELoss->Write();
hPhivsThetaELossFlux->Write();
hPhivsThetaELossDivided->Write();

hPhivsThetaELossTop->Write();
hPhivsThetaELossFluxTop->Write();
hPhivsThetaELossDividedTop->Write();

hPhivsThetaELossMid->Write();
hPhivsThetaELossFluxMid->Write();
hPhivsThetaELossDividedMid->Write();

hPhivsThetaELossBottom->Write();
hPhivsThetaELossFluxBottom->Write();
hPhivsThetaELossDividedBottom->Write();

hMCPrimaryTPCStartX->Write();
hMCPrimaryTPCStartY->Write();
hMCPrimaryTPCStartZ->Write();

hMCELossUpstreamLookUp->Write();
hERemainMCMap->Write();

hMCELossUpstreamFlat->Write();
hERemainMCFlat->Write();

hRecoMCdEdX->Write();
hRecoMCResidualRange->Write();
hRecoMCTrkPitch->Write();
hRecoMCdEdXvsRR->Write();
hMCELossRecoInTPC->Write();
hRecoMCTPCPhi->Write();
hRecoMCTPCTheta->Write();
hRecoMCTPCStartX->Write();
hRecoMCTPCStartY->Write();
hRecoMCTPCStartZ->Write();

hERemainTPCRecoOnly->Write();

hMCELossUpstreamTPCRecoMap->Write();

hDeltaEnergyLossTruevsMap->Write();

hDeltaEnergyLossInTPCTruevsReco->Write();

hMCPrimaryXvsZWeirdPeak1->Write();
hMCPrimaryYvsZWeirdPeak1->Write();
hMCPrimaryXvsZWeirdPeak1Flux->Write();
hMCPrimaryYvsZWeirdPeak1Flux->Write();
hMCPrimaryXvsZWeirdPeak1Divide->Write();
hMCPrimaryYvsZWeirdPeak1Divide->Write();


hMCPrimaryXvsZNotWeirdPeak->Write();
hMCPrimaryYvsZNotWeirdPeak->Write();
hMCPrimaryXvsZNotWeirdPeakFlux->Write();
hMCPrimaryYvsZNotWeirdPeakFlux->Write();
hMCPrimaryXvsZNotWeirdPeakDivide->Write();
hMCPrimaryYvsZNotWeirdPeakDivide->Write();
hMCPrimaryPzvsELossUpstream->Write();
   
}//<----End Loop()
