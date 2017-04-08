#define StoppingProtonData_cxx
#include "StoppingProtonData.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <TVector3.h>

// #########################################################################################
// ### This is the macro for data analysis of the stopping proton sample based on the    ###
// ###    latest cuts using Run I Positive Polarity in LArIATsoft version 06_15_00       ###
// #########################################################################################



// ===================================================================================================================
// ====================================       PUT HISTOGRAMS HERE           ==========================================
// ===================================================================================================================

/////////////////////////////////// RAW WCTRK MOMENTUM HISTORGRAM (MeV) ///////////////////////////////////
TH1D *hdataRawWCTRKMomentum = new TH1D("hdataRawWCTRKMomentum", "Raw WCtrk Momentum (MeV)", 250, 0, 2500);

/////////////////////////////////// Full TOF for the data sample, no cuts //////////////////////////////////////
TH1D *hdataTOFNoCuts = new TH1D("hdataTOFNoCuts", "Time of Flight (No Cuts)", 120, 0, 120);

/////////////////////////////////// Wire Chamber Track Momentum vs TOF, no cuts ////////////////////////////////
TH2D *hdataWCTrackMomentumVSTOF = new TH2D("hdataWCTrackMomentumVSTOF", "TOF vs WCTrack Momentum", 250, 0, 2500, 200, 0, 100);

/////////////////////////////////// Most Upstream Z point of tracks //////////////////////////////////////////
TH1D *hdataUpstreamZPos = new TH1D("hdataUpstreamZPos", "Most upstream spacepoint of all TPC Tracks", 20, 0, 10);

/////////////////////////////////// Most Upstream Z point of tracks //////////////////////////////////////////
TH1D *hdataNumberOfUSTrks = new TH1D("hdataNumberOfUSTrks", "Number of tracks in the upstream TPC", 40, 0, 20);

/////////////////////////////////// Matched Track Initial Track X Position ////////////////////////////////////////////////////////
TH1D *hdataTrkInitialX = new TH1D("hdataTrkInitialX", "Matched Track Initial X Position of the TPC Track", 100, 0, 50);

/////////////////////////////////// Matched Track Initial Track Y Position ////////////////////////////////////////////////////////
TH1D *hdataTrkInitialY = new TH1D("hdataTrkInitialY", "Matched Track Initial Y Position of the TPC Track", 100, -25, 25);

/////////////////////////////////// Matched Track Initial Track Z Position ////////////////////////////////////////////////////////
TH1D *hdataTrkInitialZ = new TH1D("hdataTrkInitialZ", "Matched Track Initial Z Position of the TPC Track", 100, -25, 25);

/////////////////////////////////// WCTRK Momentum Histogram (MeV) //////////////////////////////////////////
TH1D *hdataWCTRKMomentum = new TH1D("hdataWCTRKMomentum", "WCtrk Momentum (MeV)", 250, 0, 2500);

/////////////////////////////////// Initial Kinetic Energy (MeV) /////////////////////////////////////////////
TH1D *hdataInitialKE = new TH1D("hdataInitialKE", "Matched Proton Initial KE (MeV)", 500, 0, 2500); 

/////////////////////////////////// TPC Track Theta at the upstream point //////////////////////////////////////
TH1D *hdataTPCTheta = new TH1D("hdataTPCTheta", "TPC Track Theta", 180, 0, 90);

/////////////////////////////////// TPC Track Phi at the upstream point ///////////////////////////////////////
TH1D *hdataTPCPhi = new TH1D("hdataTPCPhi", "TPC Track Phi", 360, 0, 360);

/////////////////////////////////// Wire Chamber Theta ////////////////////////////////////////////////////////
TH1D *hdataWCTheta = new TH1D("hdataWCTheta", "WCTrack Theta", 180, 0, 90);

/////////////////////////////////// Wire Chamber Phi //////////////////////////////////////////////////////////
TH1D *hdataWCPhi = new TH1D("hdataWCPhi", "WCTrack Phi", 360, 0, 360);

/////////////////////////////////// Delta WCTrack X ///////////////////////////////////////////////////////////
TH1D *hdataDeltaWCTrkX = new TH1D("hdataDeltaWCTrkX", "#Delta X TPC/WC Track", 160, -40, 40);

/////////////////////////////////// Delta WCTrack Y ///////////////////////////////////////////////////////////
TH1D *hdataDeltaWCTrkY = new TH1D("hdataDeltaWCTrkY", "#Delta Y TPC/WC Track", 160, -40, 40);

/////////////////////////////////// Alpha Between WC and TPC Tracks //////////////////////////////////////////
TH1D *hdataAlpha = new TH1D("hdataAlpha", "#alpha between WC and TPC Track", 90, 0, 90);

/////////////////////////////////// Energy Loss Upstream of TPC (MeV) /////////////////////////////////////////////
TH1D *hStoppedProtonEnergyLossUpstream = new TH1D("hStoppedProtonEnergyLossUpstream", "Proton Energy Loss upstream of TPC (MeV)", 500, -1000, 1000);

/////////////////////////////////// Energy Loss in the TPC (MeV) /////////////////////////////////////////////
TH1D *hStoppedProtonEnergyLossInTPC = new TH1D("hStoppedProtonEnergyLossInTPC", "Proton Energy Loss in TPC (MeV)", 500, -1000, 1000);

/////////////////////////////////// Remaining KE after subtracting TPC energy (MeV) /////////////////////////////////////////////
TH1D *hStoppedProtonRemainingKE = new TH1D("hStoppedProtonRemainingKE", "Proton Remaining Kinetic Energy (MeV)", 500, -1000, 1000);

/////////////////////////////////// E Loss upstream of the TPC /////////////////////////
TH2D *hELossXvsY = new TH2D("hELossXvsY", "Energy Loss X vs Y", 100, 0, 50, 100, -25, 25);

/////////////////////////////////// E Loss upstream of the Flux TPC /////////////////////////
TH2D *hELossXvsYFlux = new TH2D("hELossXvsYFlux", "Energy Loss X vs Y", 100, 0, 50, 100, -25, 25);

/////////////////////////////////// Divided E Loss /////////////////////////
TH2D *hELossXvsYDivide = new TH2D("hELossXvsYDivide", "Energy Loss X vs Y", 100, 0, 50, 100, -25, 25);

/////////////////////////////////// Phi vs Theta ELoss /////////////////////////
TH2D *hPhivsThetaELoss = new TH2D("hPhivsThetaELoss", "Phi vs Energy Loss", 360, 0, 360, 360, -180, 180);

/////////////////////////////////// Phi vs Theta ELoss Flux /////////////////////////
TH2D *hPhivsThetaELossFlux = new TH2D("hPhivsThetaELossFlux", "Phi vs Energy Loss", 360, 0, 360, 360, -180, 180);

/////////////////////////////////// Phi vs Theta ELoss Divided /////////////////////////
TH2D *hPhivsThetaELossDivided = new TH2D("hPhivsThetaELossDivided", "Phi vs Energy Loss", 360, 0, 360, 360, -180, 180);

// ===================================================================================================================
// ===================================================================================================================
// ===================================================================================================================



void StoppingProtonData::Loop()
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

float particle_mass = 938.28; //<---Mass of Proton in MeV

// ##########################################################
// ### Preliminary TOF Cut (sets the bounds for TOF Reco) ###
// ##########################################################
double LowerTOFGoodReco = 0;
double UpperTOFGoodReco = 90;

// ###################################################
// ### Setting the Wire Chamber momentum range and ###
// ###     the TOF range for good particle ID      ###
// ###################################################
double LowerWCTrkMomentum = 450.0; //<--(MeV)
double HighWCTrkMomentum  = 1100.0;//<--(MeV)

double LowerTOF = 28.0; //<--(ns)
double HighTOF  = 55.0; //<--(ns)

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
int nLowZTracksAllowed = 8;


// #################################################################################
// ### Making shower Cut (ShortTkLength) and the number of short tracks we allow ###
// #################################################################################
double ShortTkLength = 5.0;
int nShortTracksAllowed = 2;


// ############################
// ### Alpha Cut in degrees ###
// ############################
double alphaCut = 10;


// #############################################################################################################
// #################################        ROOT FILE FOR HISTOGRAM FOR PLOTS           ########################
// #############################################################################################################
TFile myfile("../histoROOTfiles_forPlots/RunIPosPolData_histos_noCorrections_StoppingProtons.root","RECREATE");


// ----------------------------------------------------------------
// Create the cross section from the incident and interaction plots
// ----------------------------------------------------------------

// ### The assumed energy loss between the cryostat and the TPC ###
float entryTPCEnergyLoss = 0.; //MeV

// ### The assumed mass of the incident particle (here we assume a pion) ###
float mass = 938.28;

float rho = 1396; //kg/m^3
//  float cm_per_m = 100;
float molar_mass = 39.95; //g/mol
float g_per_kg = 1000; 
float avogadro = 6.022e+23; //number/mol
float number_density = rho*g_per_kg/molar_mass*avogadro;
float slab_width = 0.0045;//in m



// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------------------


// ##########################################################
// ### Putting in some counters for event reduction table ###
// ##########################################################
int nTotalEvents = 0, nEvtsWCTrack = 0, nEvtsWCTrackMatch = 0, nEvtsTrackZPos = 0, nEvntsTPC = 0;
int nEvtsTOF = 0, nEvtsPID = 0, nLowZTrkEvents = 0;
int nNonShowerEvents = 0, nTOFHits = 0, nEventsStopProton = 0;

// #######################################################
// ### Providing an index for the Matched WC/TPC track ###
// #######################################################
int MatchWCTrackIndex[10] = {0};

// ###############################
// ### Looping over all events ###
// ###############################   
for (Long64_t jentry=0; jentry<nentries;jentry++) 
//for (Long64_t jentry=0; jentry<60000;jentry++)
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
   //						Wire Chamber Track Cuts
   //=======================================================================================================================
   // ########################################
   // ### Skipping events with no WC Track ###
   // ########################################
   if(nwctrks < 1){ continue;}
   
   // ### Loop over the WCTracks and TOF Objects ###
   for (int numWCTrk = 0; numWCTrk < nwctrks; numWCTrk++)
      {
      hdataRawWCTRKMomentum->Fill(wctrk_momentum[numWCTrk]);
      
      }//<---End loop over WCTrk
      
   // ### Counting Events w/ WC Track ###
   nEvtsWCTrack++;
   
   //=======================================================================================================================
   //						 TOF Event Selection (ns)
   //=======================================================================================================================
   
   bool tofGood = true;
   // ################################################
   // ### If no TOF obeject exists, skip the event ###
   // ################################################
   if(ntof < 1){continue;}
   // ### Loop over all the TOF objects ###
   for(int mmtof = 0; mmtof < ntof; mmtof++)
      {
      // ### Requiring there exists a good TOF recorded ###
      if(tofObject[mmtof] < LowerTOFGoodReco || tofObject[mmtof] > UpperTOFGoodReco)
         {tofGood = false;}
      
      hdataTOFNoCuts->Fill(tofObject[mmtof]);
      
      
      }//<---End mmtof
   if(ntof>0){nTOFHits++;}
   
   if(!tofGood){continue;}
   nEvtsTOF++;
   
   
   //=======================================================================================================================
   //						 Putting in a GOOD TPC Cut (looking for nhits > 0
   //=======================================================================================================================
   
   // ### Skip the event if no hits are reconstructed in the TPC ###
   if(nhits < 1){continue;}
   nEvntsTPC++;
   
   
   // ======================================================================================================================
   //						  Particle ID Filter
   // ======================================================================================================================
   
   bool GoodPID = false;
       
   // ### Loop over the WCTracks and TOF Objects ###
   for (int numWCTrk = 0; numWCTrk < nwctrks; numWCTrk++)
      {
      
      // ### Checking the number of TOF objects ###
      int TOFObject = numWCTrk;
      hdataWCTrackMomentumVSTOF->Fill(wctrk_momentum[numWCTrk] , tofObject[TOFObject]);
      // ### If we have more WCObjects the TOF, put in protection ### 
      if(TOFObject > ntof){TOFObject = ntof -1;}
      
      // ### Only keeping events that fall into the WCTrk Momentum and TOF range ###
      if(wctrk_momentum[numWCTrk] > LowerWCTrkMomentum && wctrk_momentum[numWCTrk] < HighWCTrkMomentum && 
         tofObject[TOFObject] > LowerTOF && tofObject[TOFObject] < HighTOF)
         {GoodPID = true;}
      
      
      }//<---end numWCTrk
   if(!GoodPID){continue;}
   
   nEvtsPID++;
   
   //=======================================================================================================================
   //						Low Z Spacepoint Track Cut
   //=======================================================================================================================
   
   // ### Boolian for events w/ track which ###
   // ###     starts at the front face      ###
   bool TrackSptsZCut = false;
   
   bool ThisTrackHasLowZPoint = false;
   
   // ### Recording the index of the track which ###
   // ###   starts at the front face of the TPC  ###
   bool PreLimTrackIndex[500] = {false};
   
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
      hdataUpstreamZPos->Fill(tempZpoint);
      
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
    
    hdataNumberOfUSTrks->Fill(nLowZTracksInTPC);
     
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
   //						Uniquely matching one WC Track to TPC Track
   //=======================================================================================================================
   
   // ### Keeping track of the number of matched tracks ###
   int nMatchedTracks = 0;
   
   float tpcPhi = -999;
   float tpcTheta = -999;
   
   // ### Variables for Delta WC and TPC tracks ###
   float DeltaX_WC_TPC_Track = 999;
   float DeltaY_WC_TPC_Track = 999;
   
   float FirstSpacePointZ = 999;
   float FirstSpacePointY = 999;
   float FirstSpacePointX = 999;
   
   // ### Setting the index for the track which is ###
   // ### uniquely matched to a wire chamber track ###
   bool MatchTPC_WVTrack[500] = {false};
   
   MatchWCTrackIndex[0] = 0;
   MatchWCTrackIndex[1] = 0;
   MatchWCTrackIndex[2] = 0;
   MatchWCTrackIndex[3] = 0;
   MatchWCTrackIndex[4] = 0;
   MatchWCTrackIndex[5] = 0;
   MatchWCTrackIndex[6] = 0;
   MatchWCTrackIndex[7] = 0;
   MatchWCTrackIndex[8] = 0;
   
   // #############################################
   // ### Loop over all the wire chamber tracks ###
   // #############################################
   for(int mwctrk = 0; mwctrk < nwctrks; mwctrk++)
      {
      
      // ### Grab the WCTrack Theta ###;
      hdataWCTheta->Fill(wctrk_theta[mwctrk]* (180.0/3.141592654));
      
      // ### Grabbing the WCTrack Phi ###
      hdataWCPhi->Fill(wctrk_phi[mwctrk]* (180.0/3.141592654));
      
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
	 FirstSpacePointZ = 999;
	 FirstSpacePointY = 999;
         FirstSpacePointX = 999;
	 
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
         tpcTheta = acos(z_hat.Dot(p_hat_0)/p_hat_0.Mag());  
         hdataTPCTheta->Fill(tpcTheta* (180.0/3.141592654));
   
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
         tpcPhi = phi; 
         hdataTPCPhi->Fill(tpcPhi* (180.0/3.141592654));
      
         // ===============================================================================================================            
         // ===============================================================================================================
	 
	 // #######################################################
	 // ### Defining unit vectors for the WC and TPC tracks ###
	 // #######################################################
	 TVector3 theUnitVector_WCTrack;
         TVector3 theUnitVector_TPCTrack;
	 
	 // === WCTrack Unit Vector ===
         theUnitVector_WCTrack.SetX(sin(wctrk_theta[mwctrk])*cos(wctrk_phi[mwctrk]));
         theUnitVector_WCTrack.SetY(sin(wctrk_theta[mwctrk])*sin(wctrk_phi[mwctrk]));
         theUnitVector_WCTrack.SetZ(cos(wctrk_theta[mwctrk]));
    
         // === TPC Track Unit Vector ===
         theUnitVector_TPCTrack.SetX(sin(tpcTheta)*cos(tpcPhi));
         theUnitVector_TPCTrack.SetY(sin(tpcTheta)*sin(tpcPhi));
         theUnitVector_TPCTrack.SetZ(cos(tpcTheta));
	 
	 // ##########################################################################
	 // ### Calculating the Delta X and Delta Y between WC track and TPC track ###
	 // ##########################################################################
	 DeltaX_WC_TPC_Track = FirstSpacePointX - (wctrk_XFaceCoor[mwctrk]* 0.1);//<---Note: *0.1 to convert to cm
	 DeltaY_WC_TPC_Track = FirstSpacePointY - (wctrk_YFaceCoor[mwctrk]* 0.1);
	 
	 
	 // ###########################################################
         // ### Calculating the angle between WCTrack and TPC Track ###
         // ###########################################################
         float alpha = ( acos(theUnitVector_WCTrack.Dot(theUnitVector_TPCTrack)) )* (180.0/3.141592654);
   
         
	 // ### Filling the Delta X and Delta Y  and alpha between WC tracks and TPC Tracks ###
	 hdataDeltaWCTrkY->Fill(DeltaY_WC_TPC_Track);
	 hdataDeltaWCTrkX->Fill(DeltaX_WC_TPC_Track);
	 hdataAlpha->Fill(alpha);
	 
	 // ###########################################################################
	 // ### If this TPC track matches this Wire Chamber Track, bump the counter ###
	 // ###########################################################################
	 if( DeltaX_WC_TPC_Track >  DeltaXLowerBound && DeltaX_WC_TPC_Track < DeltaXUpperBound && 
	     DeltaY_WC_TPC_Track > DeltaYLowerBound && DeltaY_WC_TPC_Track < DeltaYUpperBound &&
	     alpha < alphaCut )
	    {
	    
	    // ### Filling the tracks initial X and Y position ###
	    hdataTrkInitialX->Fill(FirstSpacePointX);
            hdataTrkInitialY->Fill(FirstSpacePointY);
	    hdataTrkInitialZ->Fill(FirstSpacePointZ);
	    
	    // ### Counting the matched tracks ###
	    nMatchedTracks++;
	    
	    // ### Setting the index of this track to true ###
	    MatchTPC_WVTrack[nTPCtrk] = true;
	    
	    // ### Setting the WCTrack Index = 1 if this WCTrack was matched ###
	    MatchWCTrackIndex[mwctrk] = 1;
	    }  
	 
	 }//<---end nTPCtrk loop
      
      
      }//<---End loop over wire chamber tracks
   
   
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
   // --- the momentum of the wire chamber track which has been matched ---
   // ---  and correct for the "typical" energy loss for a track in the ---
   // ---   argon between the cryostat and the front face of the TPC    ---
   
   
   float momentum = 999;
   
   // ###################################################
   // ### Grabbing the Wire Chamber Track Information ###
   // ###################################################
   for(int mwctrk = 0; mwctrk < nwctrks; mwctrk++)
      {
      // ### Skip this WCTrack if it isn't the matched one ###
      if(MatchWCTrackIndex[mwctrk] < 1 || MatchWCTrackIndex[mwctrk] > 1){continue;}
      
      
      hdataWCTRKMomentum->Fill(wctrk_momentum[mwctrk]);//Momentum of the matched track
      momentum =wctrk_momentum[mwctrk];
      
      }//<---End mwctrk
   
   
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
   hdataInitialKE->Fill(kineticEnergy);
   
   
   // =========================================================================================================================================
   //						Deciding whether this track is a stopping proton
   // =========================================================================================================================================   
   
   
   //Vectors with calo info of the matched tpc track
   double DatadEdX[1000]={0.};
   double DatadQdX[1000]={0.};
   double DataResRange[1000]={0.};
   double DataSptPitch[1000]={0.};
   int nDataSpts = 0;
   
   float DataSptsX[1000];
   float DataSptsY[1000];
   float DataSptsZ[1000];
   
   int nStopProtons = 0;
   int protonTrkNumber = -1;
   // ################################################
   // ### Creating a flag for through going tracks ###
   // ################################################
   bool ThroughGoingTrack[1000]={false};
   
   // ############################
   // ### Loop over all tracks ###
   // ############################
   for(int nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {
      
      // ### Skipping all the tracks which aren't well matched ###
      if(!MatchTPC_WVTrack[nTPCtrk]){continue;}
      
      
      // ###################################################
      // ### Check to see if this track is through going ###
      // ### by checking to see if it ends on a boundary ###
      // ###################################################
      if(trkendx[nTPCtrk] < 1   || trkendx[nTPCtrk] > 42.0 || trkendy[nTPCtrk] > 19 ||
         trkendy[nTPCtrk] < -19 || trkendz[nTPCtrk] > 89.0)
         {ThroughGoingTrack[nTPCtrk] = true;}      
      
      
      // ### Skipping events which are non-stopping ###
      if(ThroughGoingTrack[nTPCtrk]){continue;}
      
      // ###############################################################
      // ### Looping over the calorimetry spacepoints for this track ###
      // ###############################################################
      for(int nspts = 0; nspts < ntrkhits[nTPCtrk]; nspts++)
         {
	 
	 // ###                 Note: Format for this variable is:             ###
	 // ### [trk number][plane 0 = induction, 1 = collection][spts number] ###
         DatadEdX[nDataSpts]     = trkdedx[nTPCtrk][1][nspts];
	 
	 // ### Putting in a fix in the case that the dE/dX is negative in this step ### 
	 // ###  then take the point before and the point after and average them
	 if(DatadEdX[nDataSpts] < 0 && nspts < ntrkhits[nTPCtrk] && nspts > 0)
	    {DatadEdX[nDataSpts] = ( (trkdedx[nTPCtrk][1][nspts - 1] + trkdedx[nTPCtrk][1][nspts + 1]) / 2);}
	 
	 // ### If this didn't fix it, then just put in a flat 2.4 MeV / cm fix ###
	 if(DatadEdX[nDataSpts] < 0)
	    {continue;}
	 
	 DataResRange[nDataSpts] = trkrr[nTPCtrk][1][nspts];
         DataSptPitch[nDataSpts] = trkpitchhit[nTPCtrk][1][nspts];
	 
	 DataSptsX[nDataSpts] = trkxyz[nTPCtrk][1][nspts][0];
	 DataSptsY[nDataSpts] = trkxyz[nTPCtrk][1][nspts][1];
	 DataSptsZ[nDataSpts] = trkxyz[nTPCtrk][1][nspts][2];
	 
	 
	 nDataSpts++;
	 }//<---End nspts
      
      
      // --------------------------------------------------------------------
      // ---- Deciding on if the track looks like a stopping proton track ---
      // --------------------------------------------------------------------
      bool LowIonizingTrack = false;
      bool CloseToTheEdge = false;
      // ############################################
      // ### Loop over all the calorimetry points ###
      // ############################################
      for(int npoints = 0; npoints < nDataSpts; npoints++)
         {
	 if(DatadEdX[npoints] < 4.0 && DataResRange[npoints] < 16)
	    {LowIonizingTrack = true;}
   
	 
	 if(DataSptsX[npoints] > 38 || DataSptsX[npoints] < 5 || DataSptsY[npoints] > 15 || 
	    DataSptsY[npoints] < -15|| DataSptsZ[npoints] > 85)
	    {CloseToTheEdge = true;}
	 
	 }//<---End npoints loop
      
      // ### Skip this track if it is minimum ionizing or too close to the edge
      if(LowIonizingTrack || CloseToTheEdge)
         {continue;}
      
      
      protonTrkNumber = nTPCtrk;
      nStopProtons++;
      
      }//<---End nTPCtrk loop   

   // ##################################################
   // ### Skip events which are not stopping protons ###
   // ##################################################
   if(nStopProtons != 1){continue;}

   nEventsStopProton++;   


   // =========================================================================================================================================
   //						Filling Information for the energy loss
   // =========================================================================================================================================
    
   
   double EnergyLossUpstream = 0;
   double EnergyLossInTPC = 0;
   
   // ############################################
   // ### Loop over all the calorimetry points ###
   // ############################################
   for(int npoints = 0; npoints < nDataSpts; npoints++)
      {
      
      EnergyLossInTPC += DatadEdX[npoints] * DataSptPitch[npoints];
      
      // ################################################
      // ### Subtracting the energy loss in this step ###
      // ################################################
      float energyLossInStep = DatadEdX[npoints] * DataSptPitch[npoints];
      
      // #######################################################
      // ### Removing that kinetic energy from the histogram ###
      // #######################################################
      kineticEnergy -= energyLossInStep;
      
      }//<---End npoints 
   
   EnergyLossUpstream = InitialKinEnAtTPC - EnergyLossInTPC;
   
   hELossXvsY->Fill(FirstSpacePointX, FirstSpacePointY, EnergyLossUpstream);
   hELossXvsYFlux->Fill(FirstSpacePointX, FirstSpacePointY);
   
   hStoppedProtonRemainingKE->Fill(kineticEnergy);
   hStoppedProtonEnergyLossUpstream->Fill(EnergyLossUpstream);
   hStoppedProtonEnergyLossInTPC->Fill(EnergyLossInTPC);
   
   hPhivsThetaELoss->Fill(tpcPhi*(180/3.14159) ,tpcTheta*(180/3.14159), EnergyLossUpstream);
   hPhivsThetaELossFlux->Fill(tpcPhi*(180/3.14159) ,tpcTheta*(180/3.14159));
   
   
   }//<---end jentry loop


// ========================================================================================================
// ===					EVENT REDUCTION TABLE						===
// ========================================================================================================
std::cout<<std::endl;
std::cout<<"########################################################################"<<std::endl;
std::cout<<"### Number of Events in AnaModule                                = "<<nTotalEvents<<" ###"<<std::endl;
std::cout<<"-------------------------------   Stage 0   ----------------------------"<<std::endl;
std::cout<<"### Number of Events w/ WC Track                                 = "<<nEvtsWCTrack<<" ###"<<std::endl;
std::cout<<"### Number of Events w/ TOF Object                               = "<<nTOFHits<<std::endl;
std::cout<<"### Number of Events w/ TOF > "<<LowerTOFGoodReco<<" ns and < "<<UpperTOFGoodReco<<" ns                   = "<<nEvtsTOF<<" ###"<<std::endl;
std::cout<<"### Number of Events w/ Good TPC info (nHits > 0)		     = "<<nEvntsTPC<<" ###"<<std::endl;
std::cout<<"-------------------------------   Stage 1   ----------------------------"<<std::endl;
std::cout<<"### Number of Events w/ PID consistent with proton               = "<<nEvtsPID<<" ###"<<std::endl;
std::cout<<"-------------------------------   Stage 2   ----------------------------"<<std::endl;
std::cout<<"### Number of Events w/ Trk Z < "<<FirstSpacePointZPos<<"                                = "<<nEvtsTrackZPos<<" ###"<<std::endl;
std::cout<<"### Number of Events w/ < "<<nLowZTracksAllowed<<" tracks in the first "<<UpperPartOfTPC<<" cm of the TPC = "<<nLowZTrkEvents<<" ###"<<std::endl;
std::cout<<"### Number of Events that are not Shower Like                        = "<<nNonShowerEvents<<std::endl;
std::cout<<"### Number of Events w/ ONE WC Track Matched                     = "<<nEvtsWCTrackMatch<<" ###"<<std::endl;
std::cout<<"###              ( "<<DeltaXLowerBound<<" < Delta X < "<<DeltaXUpperBound<<" , "<<DeltaYLowerBound<<" < Delta Y < "<<DeltaYUpperBound<<" )              ###"<<std::endl;
std::cout<<"###                 and alpha less the "<<alphaCut<<" degrees                      ###"<<std::endl;
std::cout<<"-------------------------------------------------------------------------"<<std::endl;
std::cout<<"### Number of Events where the proton track is stopping in the TPC = "<<nEventsStopProton<<std::endl;
std::cout<<"########################################################################"<<std::endl;
std::cout<<std::endl; 

// ##########################
// ### Dividing the plots ###
// ##########################
hELossXvsYDivide->Divide(hELossXvsY, hELossXvsYFlux);
hPhivsThetaELossDivided->Divide(hPhivsThetaELoss, hPhivsThetaELossFlux);
   

// ===========================================================================================
// ============================  Writing out histograms to ROOT File =========================
// ===========================================================================================
hdataRawWCTRKMomentum->Write();
hdataTOFNoCuts->Write(); 
hdataWCTrackMomentumVSTOF->Write();
hdataUpstreamZPos->Write();
hdataNumberOfUSTrks->Write();
hdataTrkInitialX->Write();
hdataTrkInitialY->Write();
hdataTrkInitialZ->Write(); 
hdataWCTRKMomentum->Write(); 
hdataTPCTheta->Write(); 
hdataTPCPhi->Write();
hdataWCTheta->Write();
hdataWCPhi->Write();
hdataDeltaWCTrkX->Write();
hdataDeltaWCTrkY->Write();
hdataAlpha->Write();
hStoppedProtonEnergyLossUpstream->Write();
hStoppedProtonEnergyLossInTPC->Write();
hStoppedProtonRemainingKE->Write();
hELossXvsY->Write();
hELossXvsYFlux->Write();
hELossXvsYDivide->Write();
hPhivsThetaELoss->Write();
hPhivsThetaELossFlux->Write();
hPhivsThetaELossDivided->Write();
   
}//<---End Loop() Function
