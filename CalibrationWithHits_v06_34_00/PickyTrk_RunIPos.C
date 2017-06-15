#define PickyTrk_RunIPos_cxx
#include "PickyTrk_RunIPos.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <TVector3.h>

// #######################################################################################
// ### This is the macro for data analysis of the matched track sample of tracks based ###
// ### on the latest cuts using Run I Negative Polarity in LArIATsoft version 06_15_00 ###
// #######################################################################################


float corrdEdx(float dEdx)
{
  
  // ###########################################
  // ### Putting in the calorimetry constant ###
  // ###########################################
  
  // *** 06_15_00 Run-1 Data Induction Plane:  0.0247 ***
  // *** 06_15_00 Run-1 Data Collection Plane: 0.048 ***
  
  float caloconstant = 0.055;
  
  
  float rho    = 1.383;
  float beta   = 0.3 ;// cm / MeV
  float betap  = 0.212; //(kV/cm)(g/cm^2)/MeV 
  float alpha  = 0.93;
  float Wion   = 23.6 / 1E6;// MeV / e-
  float Efield = 0.5;

  float dQdx = log(dEdx * betap/(rho*Efield) + alpha) / (betap/(rho*Efield) * Wion);
  
  dQdx *= 0.0153/caloconstant;

  //dQdx *= 0.0153/0.0382;

  float newdQdx = (exp(betap/(rho*Efield) * Wion * dQdx) - alpha)/(betap/(rho*Efield));
  //cout<<newdQdx<<endl;

  return newdQdx;
}

// ### Possible Collection Plane ###
// 0.058

// ===================================================================================================================
// ====================================       PUT HISTOGRAMS HERE           ==========================================
// ===================================================================================================================



/////////////////////////////////// Full TOF for the data sample, no cuts //////////////////////////////////////
TH1D *hdataTOFNoCuts = new TH1D("hdataTOFNoCuts", "Time of Flight (No Cuts)", 120, 0, 120);

/////////////////////////////////// Wire Chamber Track Momentum vs TOF, no cuts ////////////////////////////////
TH2D *hdataWCTrackMomentumVSTOF = new TH2D("hdataWCTrackMomentumVSTOF", "TOF vs WCTrack Momentum", 250, 0, 2500, 200, 0, 100);

/////////////////////////////////// "Matched Track" dE/dX 150 - 200 MeV Momentum /////////////////////////////////////////////////////
TH1D *hdatadEdX = new TH1D("hdatadEdX", "Matched Track dE/dX", 200, 0, 50);

/////////////////////////////////// "Matched Track" Track Pitch //////////////////////////////////////////
TH1D *hdataTrkPitch = new TH1D("hdataTrkPitch", "Matched Track Pitch", 1000, 0, 5);

/////////////////////////////////// "Matched Track" dE/dX 150 - 200 MeV Momentum /////////////////////////////////////////////////////
TH1D *hdatadEdX_150_200 = new TH1D("hdatadEdX_150_200", "Matched Track dE/dX 150 MeV < P < 200 MeV", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX 200 - 250 MeV Momentum /////////////////////////////////////////////////////
TH1D *hdatadEdX_200_250 = new TH1D("hdatadEdX_200_250", "Matched Track dE/dX 200 MeV < P < 250 MeV", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX 250 - 300 MeV Momentum /////////////////////////////////////////////////////
TH1D *hdatadEdX_250_300 = new TH1D("hdatadEdX_250_300", "Matched Track dE/dX 250 MeV < P < 300 MeV", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX 300 - 350 MeV Momentum /////////////////////////////////////////////////////
TH1D *hdatadEdX_300_350 = new TH1D("hdatadEdX_300_350", "Matched Track dE/dX 300 MeV < P < 350 MeV", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX 350 - 400 MeV Momentum /////////////////////////////////////////////////////
TH1D *hdatadEdX_350_400 = new TH1D("hdatadEdX_350_400", "Matched Track dE/dX 350 MeV < P < 400 MeV", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX 400 - 450 MeV Momentum /////////////////////////////////////////////////////
TH1D *hdatadEdX_400_450 = new TH1D("hdatadEdX_400_450", "Matched Track dE/dX 400 MeV < P < 450 MeV", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX 450 - 500 MeV Momentum /////////////////////////////////////////////////////
TH1D *hdatadEdX_450_500 = new TH1D("hdatadEdX_450_500", "Matched Track dE/dX 450 MeV < P < 500 MeV", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX 500 - 550 MeV Momentum /////////////////////////////////////////////////////
TH1D *hdatadEdX_500_550 = new TH1D("hdatadEdX_500_550", "Matched Track dE/dX 500 MeV < P < 550 MeV", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX 550 - 600 MeV Momentum /////////////////////////////////////////////////////
TH1D *hdatadEdX_550_600 = new TH1D("hdatadEdX_550_600", "Matched Track dE/dX 550 MeV < P < 600 MeV", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX 600 - 650 MeV Momentum /////////////////////////////////////////////////////
TH1D *hdatadEdX_600_650 = new TH1D("hdatadEdX_600_650", "Matched Track dE/dX 600 MeV < P < 650 MeV", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX 650 - 700 MeV Momentum /////////////////////////////////////////////////////
TH1D *hdatadEdX_650_700 = new TH1D("hdatadEdX_650_700", "Matched Track dE/dX 650 MeV < P < 700 MeV", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX 700 - 750 MeV Momentum /////////////////////////////////////////////////////
TH1D *hdatadEdX_700_750 = new TH1D("hdatadEdX_700_750", "Matched Track dE/dX 700 MeV < P < 750 MeV", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX 750 - 800 MeV Momentum /////////////////////////////////////////////////////
TH1D *hdatadEdX_750_800 = new TH1D("hdatadEdX_750_800", "Matched Track dE/dX 750 MeV < P < 800 MeV", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX 800 - 850 MeV Momentum /////////////////////////////////////////////////////
TH1D *hdatadEdX_800_850 = new TH1D("hdatadEdX_800_850", "Matched Track dE/dX 800 MeV < P < 850 MeV", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX 850 - 900 MeV Momentum /////////////////////////////////////////////////////
TH1D *hdatadEdX_850_900 = new TH1D("hdatadEdX_850_900", "Matched Track dE/dX 850 MeV < P < 900 MeV", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX 900 - 950 MeV Momentum /////////////////////////////////////////////////////
TH1D *hdatadEdX_900_950 = new TH1D("hdatadEdX_900_950", "Matched Track dE/dX 900 MeV < P < 950 MeV", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX 950 - 1000 MeV Momentum /////////////////////////////////////////////////////
TH1D *hdatadEdX_950_1000 = new TH1D("hdatadEdX_950_1000", "Matched Track dE/dX 950 MeV < P < 1000 MeV", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX 1000 - 1050 MeV Momentum /////////////////////////////////////////////////////
TH1D *hdatadEdX_1000_1050 = new TH1D("hdatadEdX_1000_1050", "Matched Track dE/dX 1000 MeV < P < 1050 MeV", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX 1050 - 1100 MeV Momentum /////////////////////////////////////////////////////
TH1D *hdatadEdX_1050_1100 = new TH1D("hdatadEdX_1050_1100", "Matched Track dE/dX 1050 MeV < P < 1100 MeV", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX 1100 - 1150 MeV Momentum /////////////////////////////////////////////////////
TH1D *hdatadEdX_1100_1150 = new TH1D("hdatadEdX_1100_1150", "Matched Track dE/dX 1100 MeV < P < 1150 MeV", 200, 0, 50);

/////////////////////////////////// "Matched Track" dE/dX 1150 - 1200 MeV Momentum /////////////////////////////////////////////////////
TH1D *hdatadEdX_1150_1200 = new TH1D("hdatadEdX_1150_1200", "Matched Track dE/dX 1150 MeV < P < 1200 MeV", 200, 0, 50);




void PickyTrk_RunIPos::Loop()
{
if (fChain == 0) return;
Long64_t nentries = fChain->GetEntriesFast();
Long64_t nbytes = 0, nb = 0;


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

// ############################
// ### Alpha Cut in degrees ###
// ############################
double alphaCut = 10;

// ###################################################
// ### Setting the Wire Chamber momentum range and ###
// ###     the TOF range for good particle ID      ###
// ###################################################
double LowerWCTrkMomentum = 100.0; //<--(MeV)
double HighWCTrkMomentum  = 2000.0;//<--(MeV)

//double LowerWCTrkMomentum = 450.0; //<--(MeV)
//double HighWCTrkMomentum  = 1100.0;//<--(MeV)

double LowerTOF = 10.0; //<--(ns)
double HighTOF  = 30.0; //<--(ns)

//double LowerTOF = 28.0; //<--(ns)
//double HighTOF  = 55.0; //<--(ns)


// ########################################################################
// ### Fiducial Boundry Cuts (used to determine if a track is stopping) ###
// ########################################################################
double XLowerFid = 0;
double XUpperFid = 47;

double YLowerFid = -20;
double YUpperFid = 20;

double ZLowerFid = 0;
double ZUpperFid = 90;


// ###                 Note: Format for this variable is:             ###
// ### [trk number][plane 0 = induction, 1 = collection][spts number] ###
int plane = 1;


// ########################################################################
// ### Definition of the upstream part of the TPC where we restrict the ###
// ###             number of tracks which can be present                ###
// ########################################################################
int UpperPartOfTPC = 14.0;


// ###############################################
// ###  Only keeping through going reco Tracks ###
// ###  True = Only keep through going tracks  ###
// ###   False = Keep all types of tracks      ###
// ###############################################
bool SelectThroughGoing = true;

// ######################################################
// ### Choose whether or not to fix the calo problems ###
// ###  associated with ordering of the calo points   ###
// ###                                                ###
// ### True  = Use the fix                            ###
// ### False = Don't use the fix                      ###
// ######################################################
bool FixCaloIssue_Reordering = true; 


// ####################################################
// ### Choose whether or not to use the 3d distance ###
// ### between points for the pitch and recalculate ###
// ###    the dE/dX distribution based on this      ###
// ###                                              ###
// ### True = Recalculate                           ###
// ### False = Use the existing dE/dX               ###
// ####################################################
bool Calculate3dPitch = false;

// ###################################################
// ### Setting a flag to print out bunch of checks ###
// ###################################################
bool VERBOSE = false;  


// ### The assumed energy loss between the cryostat and the TPC ###
float entryTPCEnergyLoss = 40.; //MeV


// ##########################################################
// ### Putting in some counters for event reduction table ###
// ##########################################################
int nTotalEvents = 0, nEvtsWCTrack = 0, nEvtsTOF = 0, nEvtsPID = 0, nEvtsTPCTrk = 0;
int nEvtsWCTrackMatch = 0, nEvtsThroughGoing = 0;


// #######################################################
// ### Providing an index for the Matched WC/TPC track ###
// #######################################################
int MatchWCTrackIndex[10] = {0};


// ====================================================
// ======  Make histogram file for data sample  ======= 
TFile myfile("./TJCalibrationMethod_RunIPosPol_NewPickySample_ThroughGoing.root","RECREATE");

// ###############################
// ### Looping over all events ###
// ###############################
for (Long64_t jentry=0; jentry<nentries;jentry++) 
//for (Long64_t jentry=0; jentry<100000;jentry++)
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
   
   
   // ########################################
   // ### Skipping events with no WC Track ###
   // ########################################
   if(nwctrks < 1){continue;}
   nEvtsWCTrack++;
   
   // ################################################
   // ### If no TOF obeject exists, skip the event ###
   // ################################################
   if(ntof < 1){continue;}
   nEvtsTOF++;
   
   // ### Loop over all the TOF objects ###
   for(int mmtof = 0; mmtof < ntof; mmtof++)
      {
      hdataTOFNoCuts->Fill(tofObject[mmtof]);
      
      }//<---End mmtof
    
   bool GoodPID = false;
      
   // ### Loop over the WCTracks and TOF Objects ###
   for (int numWCTrk = 0; numWCTrk < nwctrks; numWCTrk++)
      {
      
      // ### Checking the number of TOF objects ###
      int TOFObject = numWCTrk;
      hdataWCTrackMomentumVSTOF->Fill(wctrk_momentum[numWCTrk] , tofObject[TOFObject]);
      
      // ### Only keeping events that fall into the WCTrk Momentum and TOF range ###
      if(wctrk_momentum[numWCTrk] > LowerWCTrkMomentum && wctrk_momentum[numWCTrk] < HighWCTrkMomentum && 
         tofObject[TOFObject] > LowerTOF && tofObject[TOFObject] < HighTOF)
         {GoodPID = true;}
	 
      }
   
   // ### Only keeping Good PID 
   if(!GoodPID){continue;}
   
   nEvtsPID++;
   
   
   // #############################################
   // ### If no TPC trks exists, skip the event ###
   // #############################################
   if(ntracks_reco < 1){continue;}
   nEvtsTPCTrk++;
   
   
   //=======================================================================================================================
   //						Uniquely matching one WC Track to TPC Track
   //=======================================================================================================================
   
   // ### Keeping track of the number of matched tracks ###
   int nMatchedTracks = 0;
   
   // ### Variables for Delta WC and TPC tracks ###
   float DeltaX_WC_TPC_Track = 999;
   float DeltaY_WC_TPC_Track = 999;
   
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
   
   
   float WireChamberTrackMomentum = 0;
   
   
   // ### Loop over the WCTracks and TOF Objects ###
   for (int numWCTrk = 0; numWCTrk < nwctrks; numWCTrk++)
      {
      // ####################################
      // ### Loop over all the TPC Tracks ###
      // ####################################
      for(int nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
         {
	 
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
      
         // ===============================================================================================================            
         // ===============================================================================================================
	 
	 // #######################################################
	 // ### Defining unit vectors for the WC and TPC tracks ###
	 // #######################################################
	 TVector3 theUnitVector_WCTrack;
         TVector3 theUnitVector_TPCTrack;
	 
	 // === WCTrack Unit Vector ===
         theUnitVector_WCTrack.SetX(sin(wctrk_theta[numWCTrk])*cos(wctrk_phi[numWCTrk]));
         theUnitVector_WCTrack.SetY(sin(wctrk_theta[numWCTrk])*sin(wctrk_phi[numWCTrk]));
         theUnitVector_WCTrack.SetZ(cos(wctrk_theta[numWCTrk]));
    
         // === TPC Track Unit Vector ===
         theUnitVector_TPCTrack.SetX(sin(tpcTheta)*cos(tpcPhi));
         theUnitVector_TPCTrack.SetY(sin(tpcTheta)*sin(tpcPhi));
         theUnitVector_TPCTrack.SetZ(cos(tpcTheta));
	 
	 // ##########################################################################
	 // ### Calculating the Delta X and Delta Y between WC track and TPC track ###
	 // ##########################################################################
	 DeltaX_WC_TPC_Track = FirstSpacePointX - (wctrk_XFaceCoor[numWCTrk]* 0.1);//<---Note: *0.1 to convert to cm
	 DeltaY_WC_TPC_Track = FirstSpacePointY - (wctrk_YFaceCoor[numWCTrk]* 0.1);
	 
	 
	 // ###########################################################
         // ### Calculating the angle between WCTrack and TPC Track ###
         // ###########################################################
         float alpha = ( acos(theUnitVector_WCTrack.Dot(theUnitVector_TPCTrack)) )* (180.0/3.141592654);
	 
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
	    
	    // ### Setting the WCTrack Index = 1 if this WCTrack was matched ###
	    MatchWCTrackIndex[numWCTrk] = 1;
	    
	    WireChamberTrackMomentum = wctrk_momentum[numWCTrk] - entryTPCEnergyLoss;
	    } 
	 
	 
	 }//<---End nTPCtrk loop
      
      
      }//<---End loop over numWCTrk
   
   // #####################################################
   // ### Skipping this event if no WC track is matched ###
   // ###    OR if more than one WC track is matched    ###
   // #####################################################
   if( (nMatchedTracks < 1 || nMatchedTracks > 1)){continue;}
      
   
   // ### Counting the number of events with ONE WC track matched ###
   nEvtsWCTrackMatch++;
   
   
   // =========================================================================================================================================
   //							 Calorimetry Points
   // =========================================================================================================================================
   
   //Vectors with calo info of the matched tpc track
   double DatadEdX[20][1000]={0.};
   double DatadQdX[20][1000]={0.};
   double DataResRange[20][1000]={0.};
   double DataSptPitch[20][1000]={0.};
   int nDataTrks = 0;
   int nDataSpts = 0;
   int nSpacePoints[1000] = {0.};
   
   float DataSptsX[20][1000];
   float DataSptsY[20][1000];
   float DataSptsZ[20][1000];
   
   
   bool AtLeastOneThroughGoingTrack = false;
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
      
      // ### Skipping all the tracks which ARE NOT well matched ###
      if(!MatchTPC_WVTrack[nTPCtrk]){continue;}

      // ###################################################
      // ### Check to see if this track is through going ###
      // ### by checking to see if it ends on a boundary ###
      // ###################################################
      if(trkendx[nTPCtrk] < 1   || trkendx[nTPCtrk] > 42.0 || trkendy[nTPCtrk] > 19 ||
         trkendy[nTPCtrk] < -19 || trkendz[nTPCtrk] > 88.0)
         {ThroughGoingTrack[nTPCtrk] = true;}
             
      
      float average_dEdX = 0;
      
      if(SelectThroughGoing && !ThroughGoingTrack[nTPCtrk]){continue;}
      
      // ### Loop over the hits ###
      /*for (int ihit = 0; ihit<nhits; ++ihit)
         {
	 // ##################################
	 // ### Match the track to the hit ###
	 // ##################################
	 if (hit_trkkey[ihit]==nTPCtrk)
	    {
	    // #################################################
	    // ### Require the hits to be in the right plane ###
	    // #################################################
	    if (hit_plane[ihit] == plane)
	       {
	       //DatadEdX[nDataTrks][nDataSpts]     = corrdEdx(hit_dEds[ihit]);
	       DatadEdX[nDataTrks][nDataSpts]     = hit_dEds[ihit];
	       DatadQdX[nDataTrks][nDataSpts]     = hit_dQds[ihit];
	       
	       DataResRange[nDataTrks][nDataSpts] = hit_resrange[ihit];
	       DataSptPitch[nDataTrks][nDataSpts] = hit_ds[ihit];
	       DataSptsX[nDataTrks][nDataSpts] = hit_x[ihit];
	       DataSptsY[nDataTrks][nDataSpts] = hit_y[ihit];
	       DataSptsZ[nDataTrks][nDataSpts] = hit_z[ihit];
	       
	       // ###################################################
	       // ### Adding an option to calculate the 3-d pitch ###
	       // ###################################################
	       if(Calculate3dPitch && ihit > 0)
	          {
		  float dE = DatadEdX[nDataTrks][nDataSpts] * DataSptPitch[nDataTrks][nDataSpts];
		  
		  float dX = (DataSptsX[nDataTrks][nDataSpts] - DataSptsX[nDataTrks][nDataSpts - 1]);
		  float dY = (DataSptsY[nDataTrks][nDataSpts] - DataSptsY[nDataTrks][nDataSpts - 1]);
		  float dZ = (DataSptsZ[nDataTrks][nDataSpts] - DataSptsZ[nDataTrks][nDataSpts - 1]);
		  
		  float ds = sqrt( (dX*dX) + (dY*dY) + (dZ*dZ) );
		  
		  DatadEdX[nDataTrks][nDataSpts] = dE/ds;
		  DataSptPitch[nDataTrks][nDataSpts] = ds;
		  
		  }//<---end calculate 3-d pitch
	       
	       
	       nDataSpts++;
	       }//<---end matching hit plane
	    }//<---end matching hit to track
	 
	 }//<---End 
      */
      
      
      
      // ###############################################################
      // ### Looping over the calorimetry spacepoints for this track ###
      // ###############################################################
      for(int nspts = 0; nspts < ntrkhits[nTPCtrk]; nspts++)
         {
	 // ###                 Note: Format for this variable is:             ###
	 // ### [trk number][plane 0 = induction, 1 = collection][spts number] ###
         DatadEdX[nDataTrks][nDataSpts]     = trkdedx[nTPCtrk][plane][nspts];
	 DatadQdX[nDataTrks][nDataSpts]     = trkdqdx[nTPCtrk][plane][nspts];
	 
	 // ### Putting in a fix in the case that the dE/dX is negative in this step ### 
	 // ###  then take the point before and the point after and average them
	 if(DatadEdX[nDataTrks][nDataSpts] < 0 && nspts < ntrkhits[nTPCtrk] && nspts > 0)
	    {DatadEdX[nDataTrks][nDataSpts] = ( (trkdedx[nTPCtrk][plane][nspts - 1] + trkdedx[nTPCtrk][plane][nspts + 1]) / 2);}
	 
	 // ### If this didn't fix it, then just put in a flat 2.4 MeV / cm fix ###
	 if(DatadEdX[nDataTrks][nDataSpts] < 0)
	    {continue;}
	    
	 DataResRange[nDataTrks][nDataSpts] = trkrr[nTPCtrk][plane][nspts];
	 
	 // ### Put in a flag to look for through going tracks ###
	 if(trkrr[nTPCtrk][plane][nspts] > 88){AtLeastOneThroughGoingTrack = true;}
	 
	 
         DataSptPitch[nDataTrks][nDataSpts] = trkpitchhit[nTPCtrk][plane][nspts];
	 
	 DataSptsX[nDataTrks][nDataSpts] = trkxyz[nTPCtrk][plane][nspts][0];
	 DataSptsY[nDataTrks][nDataSpts] = trkxyz[nTPCtrk][plane][nspts][1];
	 DataSptsZ[nDataTrks][nDataSpts] = trkxyz[nTPCtrk][plane][nspts][2];

	 
	 // ### Bump the nDataSpts counter ###
	 nDataSpts++;

	 
	 }//<---End spacepoints loop
      	 
      nSpacePoints[nDataTrks] = nDataSpts;	 
      nDataSpts = 0;	 
      nDataTrks++;
      AtLeastOneThroughGoingTrack = true;
      }//<---End nTPCtrk loop 

// ############################################################################
// ### Adding a counter for the number of events with a through going track ###
// ############################################################################
if(AtLeastOneThroughGoingTrack){nEvtsThroughGoing++;}


   
// ---------------------------------------------------------------------------------------------------------------------------------------
   bool HasToBeReordered[20] = {false};
   int ReorderedCount = 0;
   int ReorderTrkCount[20] = {0};
   int bb = 0;
   // ############################################################
   // ### Fix the reordering problem of the calorimetry points ###
   // ############################################################
   if(FixCaloIssue_Reordering)
      {
      
      for( int trkPoints = 0; trkPoints < nDataTrks; trkPoints++)
         {
         // ################################
         // ### Loop over the caloPoints ###
         // ################################
         for(int caloPoints = 0; caloPoints < nSpacePoints[trkPoints]-1; caloPoints++)
            {
	    // ###           If this points Residual Range is smaller than the       ###
	    // ### next point, then things may be out of wack and we want to reorder ###
	    if(DataResRange[trkPoints][caloPoints] < DataResRange[trkPoints][caloPoints+1])
	       {
	       // #######################################################
	       // ### Set a flag that this might have to be reordered ###
	       // #######################################################
	       HasToBeReordered[trkPoints] = true;
	    
	       // ### counting the points that are out of order ###
	       ReorderedCount++;
	       }

            }//<---End caloPoints
	 ReorderTrkCount[trkPoints] = ReorderedCount;
	 ReorderedCount = 0;   
	 }//<---End trkPoints
      }//<---End fixing the ordering problem
   
   // #####################################################
   // ### The things need to be reorderd for this track ###
   // #####################################################
   
   for(int trkpt = 0; trkpt < nDataTrks; trkpt++)
      {
   
      if(HasToBeReordered[trkpt] && ( (nSpacePoints[trkpt] -  ReorderTrkCount[trkpt]) == 1))
         {
      
         // ### Temp Variables for fixing ###
         double tempRR[20][1000] = {0.};
         double tempdEdX[20][1000] = {0.};
         double tempdQdX[20][1000] = {0.};
         double tempPitch[20][1000] = {0.};
      
         double tempx[20][1000] = {0.};
         double tempy[20][1000] = {0.};
         double tempz[20][1000] = {0.};
      
         // ### Start at the last point ###
         for(int aa = nSpacePoints[trkpt]; aa > -1; aa--)
            {
	    // ##########################################
	    // ### Skip the point if it is at the end ###
	    // ##########################################
	    if(DataResRange[aa] == 0){continue;}
	 
	    // ### Reorder the points ###
	    tempRR[trkpt][bb]       = DataResRange[trkpt][aa];
	    tempdEdX[trkpt][bb]     = DatadEdX[trkpt][aa];
	    tempdQdX[trkpt][bb]     = DatadQdX[trkpt][aa];
	    tempPitch[trkpt][bb]    = DataSptPitch[trkpt][aa];
	 
	    tempx[trkpt][bb] = DataSptsX[trkpt][aa];
	    tempy[trkpt][bb] = DataSptsY[trkpt][aa];
	    tempz[trkpt][bb] = DataSptsZ[trkpt][aa];
	 
	    bb++;
	    }//<---end aa 
      
         // ###########################
         // ### Now swap the points ###
         // ###########################
         for(int reorder = 0; reorder < nSpacePoints[trkpt]; reorder++)
            {
	    DataResRange[trkpt][reorder] = tempRR[trkpt][reorder];
	    DatadEdX[trkpt][reorder]     = tempdEdX[trkpt][reorder];
	    DatadQdX[trkpt][reorder]     = tempdQdX[trkpt][reorder];
	    DataSptPitch[trkpt][reorder] = tempPitch[trkpt][reorder];
	 
	    DataSptsX[trkpt][reorder] = tempx[trkpt][reorder];
	    DataSptsY[trkpt][reorder] = tempy[trkpt][reorder];
	    DataSptsZ[trkpt][reorder] = tempz[trkpt][reorder];
	 
	    }//<---End reorder loop
      
         }//<<----End trkpt loop
      }//<---End Has to be reordered

   // ##################################
   // ### Printing things as a check ###
   // ##################################
   if(HasToBeReordered[0] && VERBOSE)
      {
      for(int trackPoint = 0; trackPoint < nDataTrks; trackPoint++)
         {
	 if(!MatchTPC_WVTrack[trackPoint]){continue;}
	 
	 std::cout<<"===== Track "<<trackPoint<<"  ========"<<std::endl;
         for(int caloPoints = 0; caloPoints < nSpacePoints[trackPoint]; caloPoints++)
            {
	    std::cout<<"Run = "<<run<<", Event = "<<event<<" point = "<<caloPoints<<", RR = "<<DataResRange[trackPoint][caloPoints]<<", dE/dX = "<<DatadEdX[trackPoint][caloPoints]<<std::endl;
      
      
            }//<---End caloPoints
      std::cout<<std::endl;
         }//<---End track  Piont	 
      }//<---Putting in a print to make sure things are reordered correctly   

   // ####################################
   // ### Loop over all the TPC Tracks ###
   // ####################################
   for(int nTPCtrk = 0; nTPCtrk < nDataTrks; nTPCtrk++)
      {
      
      // ### Skipping all the tracks which ARE NOT well matched ###
      if(!MatchTPC_WVTrack[nTPCtrk]){continue;}
      
      // ### Skipping any track with too few spacepoints ###
      if(nSpacePoints[nTPCtrk] < 20 && AtLeastOneThroughGoingTrack){continue;}
      
      
      for(int nspts = 0; nspts < nSpacePoints[nTPCtrk]; nspts++)
         {
         hdatadEdX->Fill(DatadEdX[nTPCtrk][nspts]);
	 
	 if(DataSptPitch[nTPCtrk][nspts] > 0.4)
	 {hdataTrkPitch->Fill(DataSptPitch[nTPCtrk][nspts]);}
	 
	 }
      
      // -----------------------------
      // --- 150 MeV < P < 200 MeV ---
      // -----------------------------
      if(WireChamberTrackMomentum > 150 && WireChamberTrackMomentum < 200)
         {
	 // ###############################################################
         // ### Looping over the calorimetry spacepoints for this track ###
         // ###############################################################
         for(int nspts = 0; nspts < 12; nspts++)
            {
	    hdatadEdX_150_200->Fill(DatadEdX[nTPCtrk][nspts]);
	    
	    }
	 
	 }//<---End Momentum Bin
      
      // -----------------------------
      // --- 200 MeV < P < 250 MeV ---
      // -----------------------------
      if(WireChamberTrackMomentum > 200 && WireChamberTrackMomentum < 250)
         {
	 // ###############################################################
         // ### Looping over the calorimetry spacepoints for this track ###
         // ###############################################################
         for(int nspts = 0; nspts < 12; nspts++)
            {
	    hdatadEdX_200_250->Fill(DatadEdX[nTPCtrk][nspts]);
	    
	    }
	 
	 }//<---End Momentum Bin
      
      // -----------------------------
      // --- 250 MeV < P < 300 MeV ---
      // -----------------------------
      if(WireChamberTrackMomentum > 250 && WireChamberTrackMomentum < 300)
         {
	 // ###############################################################
         // ### Looping over the calorimetry spacepoints for this track ###
         // ###############################################################
         for(int nspts = 0; nspts < 12; nspts++)
            {
	    hdatadEdX_250_300->Fill(DatadEdX[nTPCtrk][nspts]);
	    
	    }
	 
	 }//<---End Momentum Bin
      
      // -----------------------------
      // --- 300 MeV < P < 350 MeV ---
      // -----------------------------
      if(WireChamberTrackMomentum > 300 && WireChamberTrackMomentum < 350)
         {
	 // ###############################################################
         // ### Looping over the calorimetry spacepoints for this track ###
         // ###############################################################
         for(int nspts = 0; nspts < 12; nspts++)
            {
	    hdatadEdX_300_350->Fill(DatadEdX[nTPCtrk][nspts]);
	    
	    }
	 
	 }//<---End Momentum Bin
      
      // -----------------------------
      // --- 350 MeV < P < 400 MeV ---
      // -----------------------------
      if(WireChamberTrackMomentum > 350 && WireChamberTrackMomentum < 400)
         {
	 // ###############################################################
         // ### Looping over the calorimetry spacepoints for this track ###
         // ###############################################################
         for(int nspts = 0; nspts < 12; nspts++)
            {
	    hdatadEdX_350_400->Fill(DatadEdX[nTPCtrk][nspts]);
	    
	    }
	 
	 }//<---End Momentum Bin
      
      // -----------------------------
      // --- 400 MeV < P < 450 MeV ---
      // -----------------------------
      if(WireChamberTrackMomentum > 400 && WireChamberTrackMomentum < 450)
         {
	 // ###############################################################
         // ### Looping over the calorimetry spacepoints for this track ###
         // ###############################################################
         for(int nspts = 0; nspts < 12; nspts++)
            {
	    hdatadEdX_400_450->Fill(DatadEdX[nTPCtrk][nspts]);
	    
	    }
	 
	 }//<---End Momentum Bin
      
      // -----------------------------
      // --- 450 MeV < P < 500 MeV ---
      // -----------------------------
      if(WireChamberTrackMomentum > 450 && WireChamberTrackMomentum < 500)
         {
	 // ###############################################################
         // ### Looping over the calorimetry spacepoints for this track ###
         // ###############################################################
         for(int nspts = 0; nspts < 12; nspts++)
            {
	    hdatadEdX_450_500->Fill(DatadEdX[nTPCtrk][nspts]);
	    
	    }
	 
	 }//<---End Momentum Bin
	 
      // -----------------------------
      // --- 500 MeV < P < 550 MeV ---
      // -----------------------------
      if(WireChamberTrackMomentum > 500 && WireChamberTrackMomentum < 550)
         {
	 // ###############################################################
         // ### Looping over the calorimetry spacepoints for this track ###
         // ###############################################################
         for(int nspts = 0; nspts < 12; nspts++)
            {
	    hdatadEdX_500_550->Fill(DatadEdX[nTPCtrk][nspts]);
	    
	    }
	 
	 }//<---End Momentum Bin
      
      // -----------------------------
      // --- 550 MeV < P < 600 MeV ---
      // -----------------------------
      if(WireChamberTrackMomentum > 550 && WireChamberTrackMomentum < 600)
         {
	 // ###############################################################
         // ### Looping over the calorimetry spacepoints for this track ###
         // ###############################################################
         for(int nspts = 0; nspts < 12; nspts++)
            {
	    hdatadEdX_550_600->Fill(DatadEdX[nTPCtrk][nspts]);
	    
	    }
	 
	 }//<---End Momentum Bin
      
      
      // -----------------------------
      // --- 600 MeV < P < 650 MeV ---
      // -----------------------------
      if(WireChamberTrackMomentum > 600 && WireChamberTrackMomentum < 650)
         {
	 // ###############################################################
         // ### Looping over the calorimetry spacepoints for this track ###
         // ###############################################################
         for(int nspts = 0; nspts < 12; nspts++)
            {
	    hdatadEdX_600_650->Fill(DatadEdX[nTPCtrk][nspts]);
	    
	    }
	 
	 }//<---End Momentum Bin
        
      
      // -----------------------------
      // --- 650 MeV < P < 700 MeV ---
      // -----------------------------
      if(WireChamberTrackMomentum > 650 && WireChamberTrackMomentum < 700)
         {
	 // ###############################################################
         // ### Looping over the calorimetry spacepoints for this track ###
         // ###############################################################
         for(int nspts = 0; nspts < 12; nspts++)
            {
	    hdatadEdX_650_700->Fill(DatadEdX[nTPCtrk][nspts]);
	    
	    }
	 
	 }//<---End Momentum Bin
      
      // -----------------------------
      // --- 700 MeV < P < 750 MeV ---
      // -----------------------------
      if(WireChamberTrackMomentum > 700 && WireChamberTrackMomentum < 750)
         {
	 // ###############################################################
         // ### Looping over the calorimetry spacepoints for this track ###
         // ###############################################################
         for(int nspts = 0; nspts < 12; nspts++)
            {
	    hdatadEdX_700_750->Fill(DatadEdX[nTPCtrk][nspts]);
	    
	    }
	 
	 }//<---End Momentum Bin
      
      // -----------------------------
      // --- 750 MeV < P < 800 MeV ---
      // -----------------------------
      if(WireChamberTrackMomentum > 750 && WireChamberTrackMomentum < 800)
         {
	 // ###############################################################
         // ### Looping over the calorimetry spacepoints for this track ###
         // ###############################################################
         for(int nspts = 0; nspts < 12; nspts++)
            {
	    hdatadEdX_750_800->Fill(DatadEdX[nTPCtrk][nspts]);
	    
	    }
	 
	 }//<---End Momentum Bin
      
      
      // -----------------------------
      // --- 800 MeV < P < 850 MeV ---
      // -----------------------------
      if(WireChamberTrackMomentum > 800 && WireChamberTrackMomentum < 850)
         {
	 // ###############################################################
         // ### Looping over the calorimetry spacepoints for this track ###
         // ###############################################################
         for(int nspts = 0; nspts < 12; nspts++)
            {
	    hdatadEdX_800_850->Fill(DatadEdX[nTPCtrk][nspts]);
	    
	    }
	 
	 }//<---End Momentum Bin
      
      // -----------------------------
      // --- 850 MeV < P < 900 MeV ---
      // -----------------------------
      if(WireChamberTrackMomentum > 850 && WireChamberTrackMomentum < 900)
         {
	 // ###############################################################
         // ### Looping over the calorimetry spacepoints for this track ###
         // ###############################################################
         for(int nspts = 0; nspts < 12; nspts++)
            {
	    hdatadEdX_850_900->Fill(DatadEdX[nTPCtrk][nspts]);
	    
	    }
	 
	 }//<---End Momentum Bin
      
      // -----------------------------
      // --- 900 MeV < P < 950 MeV ---
      // -----------------------------
      if(WireChamberTrackMomentum > 900 && WireChamberTrackMomentum < 950)
         {
	 // ###############################################################
         // ### Looping over the calorimetry spacepoints for this track ###
         // ###############################################################
         for(int nspts = 0; nspts < 12; nspts++)
            {
	    hdatadEdX_900_950->Fill(DatadEdX[nTPCtrk][nspts]);
	    
	    }
	 
	 }//<---End Momentum Bin
      
      
      // -----------------------------
      // --- 950 MeV < P < 1000 MeV ---
      // -----------------------------
      if(WireChamberTrackMomentum > 950 && WireChamberTrackMomentum < 1000)
         {
	 // ###############################################################
         // ### Looping over the calorimetry spacepoints for this track ###
         // ###############################################################
         for(int nspts = 0; nspts < 12; nspts++)
            {
	    hdatadEdX_950_1000->Fill(DatadEdX[nTPCtrk][nspts]);
	    
	    }
	 
	 }//<---End Momentum Bin
      
      // -----------------------------
      // --- 1000 MeV < P < 1050 MeV ---
      // -----------------------------
      if(WireChamberTrackMomentum > 1000 && WireChamberTrackMomentum < 1050)
         {
	 // ###############################################################
         // ### Looping over the calorimetry spacepoints for this track ###
         // ###############################################################
         for(int nspts = 0; nspts < 12; nspts++)
            {
	    hdatadEdX_1000_1050->Fill(DatadEdX[nTPCtrk][nspts]);
	    
	    }
	 
	 }//<---End Momentum Bin
	 
      // -----------------------------
      // --- 1050 MeV < P < 1100 MeV ---
      // -----------------------------
      if(WireChamberTrackMomentum > 1050 && WireChamberTrackMomentum < 1100)
         {
	 // ###############################################################
         // ### Looping over the calorimetry spacepoints for this track ###
         // ###############################################################
         for(int nspts = 0; nspts < 12; nspts++)
            {
	    hdatadEdX_1050_1100->Fill(DatadEdX[nTPCtrk][nspts]);
	    
	    }
	 
	 }//<---End Momentum Bin	 
      
      
      // -----------------------------
      // --- 1100 MeV < P < 1150 MeV ---
      // -----------------------------
      if(WireChamberTrackMomentum > 1100 && WireChamberTrackMomentum < 1150)
         {
	 // ###############################################################
         // ### Looping over the calorimetry spacepoints for this track ###
         // ###############################################################
         for(int nspts = 0; nspts < 12; nspts++)
            {
	    hdatadEdX_1100_1150->Fill(DatadEdX[nTPCtrk][nspts]);
	    
	    }
	 
	 }//<---End Momentum Bin
      
      
      // -----------------------------
      // --- 1150 MeV < P < 1200 MeV ---
      // -----------------------------
      if(WireChamberTrackMomentum > 1150 && WireChamberTrackMomentum < 1200)
         {
	 // ###############################################################
         // ### Looping over the calorimetry spacepoints for this track ###
         // ###############################################################
         for(int nspts = 0; nspts < 12; nspts++)
            {
	    hdatadEdX_1150_1200->Fill(DatadEdX[nTPCtrk][nspts]);
	    
	    }
	 
	 }//<---End Momentum Bin

      }//<---End nTPC trk









   }//<---end jentry loop
   
std::cout<<"Total number of Events        = "<<nTotalEvents<<std::endl;
std::cout<<"Events w/ WC Tracks           = "<<nEvtsWCTrack<<std::endl;
std::cout<<"Events w/ TOF                 = "<<nEvtsTOF<<std::endl;
std::cout<<"Events w/ PID consistent with Pi/Mu = "<<nEvtsPID<<" ###"<<std::endl;
std::cout<<"Events w/ TPC Track           = "<<nEvtsTPCTrk<<std::endl;
std::cout<<"Events w/ unique match        = "<<nEvtsWCTrackMatch<<std::endl;
std::cout<<"Events w/ through going track = "<<nEvtsThroughGoing<<std::endl;


hdataTOFNoCuts->Write(); 
hdataWCTrackMomentumVSTOF->Write(); 
hdatadEdX->Write();
hdataTrkPitch->Write();

hdatadEdX_150_200->Write();
hdatadEdX_200_250->Write();
hdatadEdX_250_300->Write();
hdatadEdX_300_350->Write();
hdatadEdX_350_400->Write();
hdatadEdX_400_450->Write();
hdatadEdX_450_500->Write();
hdatadEdX_500_550->Write();
hdatadEdX_550_600->Write();
hdatadEdX_600_650->Write();
hdatadEdX_650_700->Write();
hdatadEdX_700_750->Write();
hdatadEdX_750_800->Write();
hdatadEdX_800_850->Write();
hdatadEdX_850_900->Write();
hdatadEdX_900_950->Write();
hdatadEdX_950_1000->Write();
hdatadEdX_1000_1050->Write();
hdatadEdX_1050_1100->Write();
hdatadEdX_1100_1150->Write();
hdatadEdX_1150_1200->Write();   
   
}
