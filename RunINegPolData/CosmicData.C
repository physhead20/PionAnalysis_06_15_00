#define CosmicData_cxx
#include "CosmicData.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>
#include <TVector3.h>
// #######################################################################################
// ### This is the macro for data analysis of a cosmic sample based on the latest cuts ###
// ###      using Run I Negative Polarity in LArIATsoft version 06_15_00               ###
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

/////////////////////////////////// Events with and without WC Tracks //////////////////////////////////////////
///////////////////////////////  0 = No WCTrack Exists, 1 = WCTrack Exists   ///////////////////////////////////
TH1D *hdataWCTrackExist = new TH1D("hdataWCTrackExist", "Existance of WCTrack", 2, 0, 2);


/////////////////////////////////// Full TOF for the data sample, no cuts //////////////////////////////////////
TH1D *hdataTOFNoCuts = new TH1D("hdataTOFNoCuts", "Time of Flight (No Cuts)", 120, 0, 120);

/////////////////////////////////// Wire Chamber Track Momentum vs TOF, no cuts ////////////////////////////////
TH2D *hdataWCTrackMomentumVSTOF = new TH2D("hdataWCTrackMomentumVSTOF", "TOF vs WCTrack Momentum", 250, 0, 2500, 200, 0, 100);

/////////////////////////////////// Most Upstream Z point of tracks //////////////////////////////////////////
TH1D *hdataUpstreamZPos = new TH1D("hdataUpstreamZPos", "Most upstream spacepoint of all TPC Tracks", 20, 0, 10);

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

/////////////////////////////////// Number of Cosmic Tracks ////////////////////////////////////////////////
TH1D *hdataNMatchTPCWCTrk = new TH1D("hdataNMatchTPCWCTrk", "Number of Cosmic TPC/WC Tracks", 20, 0, 10);

/////////////////////////////////// WCTRK Momentum Histogram (MeV) //////////////////////////////////////////
TH1D *hdataWCTRKMomentum = new TH1D("hdataWCTRKMomentum", "WCtrk Momentum (MeV)", 250, 0, 2500);

/////////////////////////////////// RAAW WCTRK MOMENTUM HISTORGRAM (MeV) ///////////////////////////////////
TH1D *hdataRawWCTRKMomentum = new TH1D("hdataRawWCTRKMomentum", "Raw WCtrk Momentum (MeV)", 250, 0, 2500);

/////////////////////////////////// Initial Kinetic Energy (MeV) /////////////////////////////////////////////
TH1D *hdataInitialKEMomentum = new TH1D("hdataInitialKEMomentum", "Pion Initial Momentum (MeV)", 500, 0, 2500); 

/////////////////////////////////// Initial Kinetic Energy (MeV) Unweighted /////////////////////////////////////////////
TH1D *hdataInitialKEMomentumUnWeighted = new TH1D("hdataInitialKEMomentumUnWeighted", "Pion Initial Momentum (MeV)", 500, 0, 2500);

/////////////////////////////////// "Cosmic Track" dE/dX /////////////////////////////////////////////////////
TH1D *hdatadEdX = new TH1D("hdatadEdX", "Cosmic Track dE/dX", 200, 0, 50);

/////////////////////////////////// "Cosmic Track" dQ/dX /////////////////////////////////////////////////////
TH1D *hdatadQdX = new TH1D("hdatadQdX", "Cosmic Track dQ/dX", 2000, 0, 20000);

/////////////////////////////////// "Cosmic Track" Residual Range //////////////////////////////////////////
TH1D *hdataResRange = new TH1D("hdataResRange", "Cosmic Track Residual Range", 400, -100, 100);

/////////////////////////////////// "Cosmic Track" Track Pitch //////////////////////////////////////////
TH1D *hdataTrkPitch = new TH1D("hdataTrkPitch", "Cosmic Track Pitch", 1000, 0, 5);


/////////////////////////////////// Cosmic Track X Position ///////////////////////////////////////////////////////////
TH1D *hdataMatchTrackXPoints = new TH1D("hdataMatchTrackXPoints", "X Track Points", 110, -5, 50);

/////////////////////////////////// Cosmic Track Y Postion ///////////////////////////////////////////////////////////
TH1D *hdataMatchTrackYPoints = new TH1D("hdataMatchTrackYPoints", "Y Track Points", 100, -25, 25);

/////////////////////////////////// Cosmic Track Z Postion ///////////////////////////////////////////////////////////
TH1D *hdataMatchTrackZPoints = new TH1D("hdataMatchTrackZPoints", "Z Track Points", 200, -5, 95);


// -------------------------------------------------------------------------------------------------------------------------

/////////////////////////////////// "Cosmic Track" dE/dX in Q1 /////////////////////////////////////////////////////
TH1D *hdatadEdXQ1 = new TH1D("hdatadEdXQ1", "Cosmic Track dE/dX Q1", 200, 0, 50);

/////////////////////////////////// "Cosmic Track" dE/dX in Q2 /////////////////////////////////////////////////////
TH1D *hdatadEdXQ2 = new TH1D("hdatadEdXQ2", "Cosmic Track dE/dX Q2", 200, 0, 50);

/////////////////////////////////// "Cosmic Track" dE/dX in Q3 /////////////////////////////////////////////////////
TH1D *hdatadEdXQ3 = new TH1D("hdatadEdXQ3", "Cosmic Track dE/dX Q3", 200, 0, 50);

/////////////////////////////////// "Cosmic Track" dE/dX in Q4 /////////////////////////////////////////////////////
TH1D *hdatadEdXQ4 = new TH1D("hdatadEdXQ4", "Cosmic Track dE/dX Q4", 200, 0, 50);

/////////////////////////////////// "Cosmic Track" dQ/dX in Q1 /////////////////////////////////////////////////////
TH1D *hdatadQdXQ1 = new TH1D("hdatadQdXQ1", "Cosmic Track dQ/dX Q1", 2000, 0, 20000);

/////////////////////////////////// "Cosmic Track" dQ/dX in Q2 /////////////////////////////////////////////////////
TH1D *hdatadQdXQ2 = new TH1D("hdatadQdXQ2", "Cosmic Track dQ/dX Q2", 2000, 0, 20000);

/////////////////////////////////// "Cosmic Track" dQ/dX in Q3 /////////////////////////////////////////////////////
TH1D *hdatadQdXQ3 = new TH1D("hdatadQdXQ3", "Cosmic Track dQ/dX Q3", 2000, 0, 20000);

/////////////////////////////////// "Cosmic Track" dQ/dX in Q4 /////////////////////////////////////////////////////
TH1D *hdatadQdXQ4 = new TH1D("hdatadQdXQ4", "Cosmic Track dQ/dX Q4", 2000, 0, 20000);


// --------------------------------------------------------------------------------------------------------------------------


///////////////////////////////// "Cosmic Track" dE/dX vs RR ///////////////////////////////////////////////
TH2D *hdatadEdXvsRR = new TH2D("hdatadEdXvsRR", "dE/dX vs Residual Range",200, 0, 100, 200, 0, 50);

///////////////////////////////// "Cosmic Track" dE/dX vs RR ///////////////////////////////////////////////
TH2D *hdatadEdXvsZRaw = new TH2D("hdatadEdXvsZRaw", "dE/dX vs Raw Z ",200, 0, 100, 200, -20, 80);

///////////////////////////////// "Cosmic Track" dE/dX vs RR (Fixed) ///////////////////////////////////////////////
TH2D *hdatadEdXvsRRFix = new TH2D("hdatadEdXvsRRFix", "dE/dX vs Residual Range",200, 0, 100, 200, 0, 50);

/////////////////////////////////// "Cosmic Track" dE/dX (Fixed) /////////////////////////////////////////////////////
TH1D *hdatadEdXFixed = new TH1D("hdatadEdXFixed", "Cosmic Track dE/dX", 200, 0, 50);

/////////////////////////////////// "Cosmic Track" dQ/dX (Fixed) /////////////////////////////////////////////////////
TH1D *hdatadQdXFixed = new TH1D("hdatadQdXFixed", "Cosmic Track dQ/dX", 2000, 0, 20000);

// -------------------------------------------------------------------------------------------------------------------------

/////////////////////////////////// "Cosmic Track" dE/dX in Q1 /////////////////////////////////////////////////////
TH1D *hdatadEdXQ1Fixed = new TH1D("hdatadEdXQ1Fixed", "Cosmic Track dE/dX Q1 (Fixed)", 200, 0, 50);

/////////////////////////////////// "Cosmic Track" dE/dX in Q2 /////////////////////////////////////////////////////
TH1D *hdatadEdXQ2Fixed = new TH1D("hdatadEdXQ2Fixed", "Cosmic Track dE/dX Q2 (Fixed)", 200, 0, 50);

/////////////////////////////////// "Cosmic Track" dE/dX in Q3 /////////////////////////////////////////////////////
TH1D *hdatadEdXQ3Fixed = new TH1D("hdatadEdXQ3Fixed", "Cosmic Track dE/dX Q3 (Fixed)", 200, 0, 50);

/////////////////////////////////// "Cosmic Track" dE/dX in Q4 /////////////////////////////////////////////////////
TH1D *hdatadEdXQ4Fixed = new TH1D("hdatadEdXQ4Fixed", "Cosmic Track dE/dX Q4 (Fixed)", 200, 0, 50);

/////////////////////////////////// "Cosmic Track" dQ/dX in Q1 /////////////////////////////////////////////////////
TH1D *hdatadQdXQ1Fixed = new TH1D("hdatadQdXQ1Fixed", "Cosmic Track dQ/dX Q1 (Fixed)", 2000, 0, 20000);

/////////////////////////////////// "Cosmic Track" dQ/dX in Q2 /////////////////////////////////////////////////////
TH1D *hdatadQdXQ2Fixed = new TH1D("hdatadQdXQ2Fixed", "Cosmic Track dQ/dX Q2 (Fixed)", 2000, 0, 20000);

/////////////////////////////////// "Cosmic Track" dQ/dX in Q3 /////////////////////////////////////////////////////
TH1D *hdatadQdXQ3Fixed = new TH1D("hdatadQdXQ3Fixed", "Cosmic Track dQ/dX Q3 (Fixed)", 2000, 0, 20000);

/////////////////////////////////// "Cosmic Track" dQ/dX in Q4 /////////////////////////////////////////////////////
TH1D *hdatadQdXQ4Fixed = new TH1D("hdatadQdXQ4Fixed", "Cosmic Track dQ/dX Q4 (Fixed)", 2000, 0, 20000);


// --------------------------------------------------------------------------------------------------------------------------


/////////////////////////////////// Reconstructed Length //////////////////////////////////////////
TH1D *hRecoLength = new TH1D("hRecoLength", "Reconstructed Length of the Primary Particle inside the TPC", 200, 0 , 100);

/////////////////////////////////// Initial Track X Position ////////////////////////////////////////////////////////
TH1D *hdataTrkInitialX = new TH1D("hdataTrkInitialX", "Initial X Position of the TPC Track", 100, 0, 50);


/////////////////////////////////// Initial Track Y Position ////////////////////////////////////////////////////////
TH1D *hdataTrkInitialY = new TH1D("hdataTrkInitialY", "Initial Y Position of the TPC Track", 100, -25, 25);


///////////////////////////////// Fixed Points X vs Z ///////////////////////////////////////////////
TH2D *hdataFixedCaloPointZX = new TH2D("hdataFixedCaloPointZX", "Fixed Points X vs Z",180, 0, 90, 90, 0, 45);

///////////////////////////////// Fixed Points X vs Z ///////////////////////////////////////////////
TH2D *hdataFixedCaloPointZY = new TH2D("hdataFixedCaloPointZY", "Fixed Points Y vs Z",180, 0, 90, 80, -20, 20);



TH2D *hdataXZTrackPoints = new TH2D("hdataXZTrackPoints", "Track X-Z Points", 200, -5, 95, 110, -5, 50);
TH2D *hdataYZTrackPoints = new TH2D("hdataYZTrackPoints", "Track Y-Z Points", 200, -5, 95, 100, -25, 25);



// ===================================================================================================================
// ====================================       END HISTOGRAMS AREA           ==========================================
// ===================================================================================================================





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

// ###                 Note: Format for this variable is:             ###
// ### [trk number][plane 0 = induction, 1 = collection][spts number] ###
int plane = 1;


void CosmicData::Loop()
{
if (fChain == 0) return;
Long64_t nentries = fChain->GetEntriesFast();
Long64_t nbytes = 0, nb = 0;


// ##########################################################
// ###			Name your ROOT file		  ###
// ##########################################################
TFile myfile("../histoROOTfiles_forPlots/RunINegPolData_histos_NewCalo_CosmicTrackSample.root","RECREATE"); 

// ##########################################################
// ### Putting in some counters for event reduction table ###
// ##########################################################
int nTotalEvents = 0, nEvtsWCTrack = 0, nEvtsTOF = 0, nOneTrackEvents = 0;
int nTopToBottomTrkEvents = 0;


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
   

   //=======================================================================================================================
   //						Wire Chamber Track Cuts
   //=======================================================================================================================
   // #######################################################
   // ### Skipping events which have a Wire Chamber Track ###
   // #######################################################
   if(nwctrks > 0){ hdataWCTrackExist->Fill(0); continue;}   
   
   nEvtsWCTrack++;

   //=======================================================================================================================
   //						 TOF Event Selection (ns)
   //=======================================================================================================================
   
   // ################################################
   // ### Skipping events which have a TOF obeject ###
   // ################################################
   if(ntof > 0){continue;}  
   
   nEvtsTOF++; 
   
   //=======================================================================================================================
   //						 Track Reconstructed in the TPC
   //=======================================================================================================================
   
   // #############################################################################
   // ### Skipping the evnet if more than one track is reconstructed in the TPC ###
   // #############################################################################
   if(ntracks_reco < 1 || ntracks_reco > 1){continue;}
   
   nOneTrackEvents++;
   
   //=======================================================================================================================
   //						 Vertical Tracks from Cosmics
   //=======================================================================================================================
   
   
   float DeltaY = abs(trkvtxy[0] - trkendy[0]);
   
   // #######################################################################
   // ### Skipping Events which do not go nearly top to bottom in the TPC ###
   // #######################################################################
   if(abs(DeltaY) < 35){continue;}
   
   nTopToBottomTrkEvents++;
   
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
   
   // ############################
   // ### Loop over all tracks ###
   // ############################
   for(int nTPCtrk = 0; nTPCtrk < ntracks_reco; nTPCtrk++)
      {
      // ### Loop over the hits ###
      for (int ihit = 0; ihit<nhits; ++ihit)
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
	       DatadEdX[nDataTrks][nDataSpts]     = corrdEdx(hit_dEds[ihit]);
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
      nSpacePoints[nDataTrks] = nDataSpts;	 
      nDataSpts = 0;	 
      nDataTrks++;
      }//<---End nTPCtrk loop    
   
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
   
   // ####################################
   // ### Loop over all the TPC Tracks ###
   // ####################################
   for(int nTPCtrk = 0; nTPCtrk < nDataTrks; nTPCtrk++)
      {   
   
      for(int nspts = 0; nspts < nSpacePoints[nTPCtrk]; nspts++)
         {
	 
	 hdataXZTrackPoints->Fill(DataSptsZ[nTPCtrk][nspts], DataSptsX[nTPCtrk][nspts]);
         hdataYZTrackPoints->Fill(DataSptsZ[nTPCtrk][nspts], DataSptsY[nTPCtrk][nspts]);
	 
	 // ### Histogramming the dE/dX ###
         hdatadEdX->Fill(DatadEdX[nTPCtrk][nspts]);
	 
         // ### Histogramming the dQ/dX ###
         hdatadQdX->Fill(DatadQdX[nTPCtrk][nspts]);
	 
         // ### Histogramming the residual range ###
         hdataResRange->Fill(DataResRange[nTPCtrk][nspts]);
         // ### Histogramming the Pitch ###
          if(DataSptPitch[nTPCtrk][nspts] > 0.4)
	 {hdataTrkPitch->Fill(DataSptPitch[nTPCtrk][nspts]);}
	 
         // ### Filling 2d dE/dX vs RR ###
         hdatadEdXvsRR->Fill(DataResRange[nTPCtrk][nspts], DatadEdX[nTPCtrk][nspts]);
	 
	 
	 // =====================================================================
         // === Breaking the TPC into 4 quadrants to analyze the dE/dX and dQ/dX
         // ===               Q1: 0 cm    < z    < 22.5 cm
         // ===               Q2: 22.5 cm < z    < 45 cm
         // ===               Q3: 45 cm   < z    < 67.5 cm
         // ===               Q4: 67.5 cm < z    < 90 cm
         // =====================================================================
         if(DataSptsZ[nTPCtrk][nspts] > 0    && DataSptsZ[nTPCtrk][nspts] < 22.5)
            {
	    hdatadEdXQ1->Fill(DatadEdX[nTPCtrk][nspts]);
	    hdatadQdXQ1->Fill(DatadQdX[nTPCtrk][nspts]);
	    }
         if(DataSptsZ[nTPCtrk][nspts] > 22.5 && DataSptsZ[nTPCtrk][nspts] < 45)
            {
	    hdatadEdXQ2->Fill(DatadEdX[nTPCtrk][nspts]);
	    hdatadQdXQ2->Fill(DatadQdX[nTPCtrk][nspts]);
	    }
         if(DataSptsZ[nTPCtrk][nspts] > 45   && DataSptsZ[nTPCtrk][nspts] < 67.5)
            {
	    hdatadEdXQ3->Fill(DatadEdX[nTPCtrk][nspts]);
	    hdatadQdXQ3->Fill(DatadQdX[nTPCtrk][nspts]);
	    }
         if(DataSptsZ[nTPCtrk][nspts] > 67.5 && DataSptsZ[nTPCtrk][nspts] < 90)
	    {
	    hdatadEdXQ4->Fill(DatadEdX[nTPCtrk][nspts]);
	    hdatadQdXQ4->Fill(DatadQdX[nTPCtrk][nspts]);
	    }
	 
	 
	 }//<---end nSpts loop
      }//<---End nTPCtrk loop
   
 


   
   
   
   }//<----end jentry loop


// ========================================================================================================
// ===					EVENT REDUCTION TABLE						===
// ========================================================================================================
std::cout<<std::endl;
std::cout<<"########################################################################"<<std::endl;
std::cout<<"### Number of Events in AnaModule                                = "<<nTotalEvents<<" ###"<<std::endl;
std::cout<<"### Number of Events w/o a WC Track                              = "<<nEvtsWCTrack<<" ###"<<std::endl;
std::cout<<"### Number of Events w/o a TOF Object                            = "<<nEvtsTOF<<" ###"<<std::endl;
std::cout<<"### Number of Events w exactly one track reconstructed           = "<<nOneTrackEvents<<" ###"<<std::endl;
std::cout<<"### Number of Events which have a Delta Y > 35 cm                = "<<nTopToBottomTrkEvents<<" ###"<<std::endl;


hdataXZTrackPoints->Write();
hdataYZTrackPoints->Write();

hdatadEdX->Write();
hdataResRange->Write();
hdataTrkPitch->Write();
hdatadEdXvsRR->Write();

hdatadQdXFixed->Write();
hdatadQdX->Write();

hdatadEdXQ1->Write();
hdatadQdXQ1->Write();
hdatadEdXQ2->Write();
hdatadQdXQ2->Write();
hdatadEdXQ3->Write();
hdatadQdXQ3->Write();
hdatadEdXQ4->Write();
hdatadQdXQ4->Write();

hdatadEdXQ1Fixed->Write();
hdatadQdXQ1Fixed->Write();
hdatadEdXQ2Fixed->Write();
hdatadQdXQ2Fixed->Write();
hdatadEdXQ3Fixed->Write();
hdatadQdXQ3Fixed->Write();
hdatadEdXQ4Fixed->Write();
hdatadQdXQ4Fixed->Write();
hdatadEdXvsRRFix->Write();
hdatadEdXFixed->Write();

hdataMatchTrackXPoints->Write();
hdataMatchTrackYPoints->Write();
hdataMatchTrackZPoints->Write();

}
