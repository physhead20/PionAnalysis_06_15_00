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




void CosmicData::Loop()
{
if (fChain == 0) return;
Long64_t nentries = fChain->GetEntriesFast();
Long64_t nbytes = 0, nb = 0;


// ##########################################################
// ###			Name your ROOT file		  ###
// ##########################################################
TFile myfile("../histoROOTfiles_forPlots/RunINegPolData_histos_noCorrections_CosmicTrackSample.root","RECREATE"); 

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
   
   double DatadEdX[1000]={0.};
   double DatadQdX[1000]={0.};
   double DataResRange[1000]={0.};
   double DataSptPitch[1000]={0.};
   int nDataSpts = 0;
   
   float DataSptsX[1000];
   float DataSptsY[1000];
   float DataSptsZ[1000];
   
   // ###############################################################
   // ### Looping over the calorimetry spacepoints for this track ###
   // ###############################################################
   for(int nspts = 0; nspts < ntrkhits[0]; nspts++)
      {
      hdataXZTrackPoints->Fill(trkxyz[0][1][nspts][2], trkxyz[0][1][nspts][0]);
      hdataYZTrackPoints->Fill(trkxyz[0][1][nspts][2], trkxyz[0][1][nspts][1]);
      
      
      // ###                 Note: Format for this variable is:             ###
      // ### [trk number][plane 0 = induction, 1 = collection][spts number] ###
      DatadEdX[nDataSpts]     = trkdedx[0][1][nspts];
      DatadQdX[nDataSpts]     = trkdqdx[0][1][nspts];
      
      // ### Putting in a fix in the case that the dE/dX is negative in this step ###
      // ###  then take the point before and the point after and average them
      if(DatadEdX[nDataSpts] < 0 && nspts < ntrkhits[0] && nspts > 0)
      {DatadEdX[nDataSpts] = ( (trkdedx[0][1][nspts - 1] + trkdedx[0][1][nspts + 1]) / 2);}
      
      // ### If this didn't fix it, then just put in a flat 2.4 MeV / cm fix ###
      if(DatadEdX[nDataSpts] < 0)
         {continue;}
	    
      DataResRange[nDataSpts] = trkrr[0][1][nspts];
      DataSptPitch[nDataSpts] = trkpitchhit[0][1][nspts];
	 
      DataSptsX[nDataSpts] = trkxyz[0][1][nspts][0];
      DataSptsY[nDataSpts] = trkxyz[0][1][nspts][1];
      DataSptsZ[nDataSpts] = trkxyz[0][1][nspts][2];
      
      hdataMatchTrackXPoints->Fill(DataSptsX[nDataSpts]);
      hdataMatchTrackYPoints->Fill(DataSptsY[nDataSpts]);
      hdataMatchTrackZPoints->Fill(DataSptsZ[nDataSpts]);
	 
      // ### Histogramming the dE/dX ###
      hdatadEdX->Fill(DatadEdX[nDataSpts]);
	 
      // ### Histogramming the dQ/dX ###
      hdatadQdX->Fill(DatadQdX[nDataSpts]);
	 
      // ### Histogramming the residual range ###
      hdataResRange->Fill(DataResRange[nDataSpts]);
      // ### Histogramming the Pitch ###
      hdataTrkPitch->Fill(DataSptPitch[nDataSpts]);
	 
      // ### Filling 2d dE/dX vs RR ###
      hdatadEdXvsRR->Fill(DataResRange[nDataSpts], DatadEdX[nDataSpts]);
	 
      // =====================================================================
      // === Breaking the TPC into 4 quadrants to analyze the dE/dX and dQ/dX
      // ===               Q1: 0 cm    < z    < 22.5 cm
      // ===               Q2: 22.5 cm < z    < 45 cm
      // ===               Q3: 45 cm   < z    < 67.5 cm
      // ===               Q4: 67.5 cm < z    < 90 cm
      // =====================================================================
      if(DataSptsZ[nDataSpts] > 0    && DataSptsZ[nDataSpts] < 22.5)
         {
	 hdatadEdXQ1->Fill(DatadEdX[nDataSpts]);
	 hdatadQdXQ1->Fill(DatadQdX[nDataSpts]);
	 }
      if(DataSptsZ[nDataSpts] > 22.5 && DataSptsZ[nDataSpts] < 45)
         {
	 hdatadEdXQ2->Fill(DatadEdX[nDataSpts]);
	 hdatadQdXQ2->Fill(DatadQdX[nDataSpts]);
	 }
      if(DataSptsZ[nDataSpts] > 45   && DataSptsZ[nDataSpts] < 67.5)
         {
	 hdatadEdXQ3->Fill(DatadEdX[nDataSpts]);
	 hdatadQdXQ3->Fill(DatadQdX[nDataSpts]);
	 }
      if(DataSptsZ[nDataSpts] > 67.5 && DataSptsZ[nDataSpts] < 90)
	 {
	 hdatadEdXQ4->Fill(DatadEdX[nDataSpts]);
	 hdatadQdXQ4->Fill(DatadQdX[nDataSpts]);
	 }
	 
       nDataSpts++;
      
      
      }//<---End nspts loop


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
      for(int caloPoints = 0; caloPoints < nDataSpts-1; caloPoints++)
         {
	 // ###           If this points Residual Range is smaller than the       ###
	 // ### next point, then things may be out of wack and we want to reorder ###
	 if(DataResRange[caloPoints] < DataResRange[caloPoints+1])
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
   if(HasToBeReordered && ( (nDataSpts - ReorderedCount) == 1))
      {
      
      // ### Temp Variables for fixing ###
      double tempRR[1000] = {0.};
      double tempdEdX[1000] = {0.};
      double tempdQdX[1000] = {0.};
      double tempPitch[1000] = {0.};
      
      double tempx[1000] = {0.};
      double tempy[1000] = {0.};
      double tempz[1000] = {0.};
      
      // ### Start at the last point ###
      for(int aa = nDataSpts; aa > -1; aa--)
         {
	 // ##########################################
	 // ### Skip the point if it is at the end ###
	 // ##########################################
	 if(DataResRange[aa] == 0){continue;}
	 
	 // ### Reorder the points ###
	 tempRR[bb] = DataResRange[aa];
	 tempdEdX[bb]     = DatadEdX[aa];
	 tempdQdX[bb]     = DatadQdX[aa];
	 tempPitch[bb] = DataSptPitch[aa];
	 
	 tempx[bb] = DataSptsX[aa];
	 tempy[bb] = DataSptsY[aa];
	 tempz[bb] = DataSptsZ[aa];
	 
	 bb++;
	 }//<---end aa 
      
      // ###########################
      // ### Now swap the points ###
      // ###########################
      for(int reorder = 0; reorder < nDataSpts; reorder++)
         {
	 DataResRange[reorder] = tempRR[reorder];
	 DatadEdX[reorder]     = tempdEdX[reorder];
	 DatadQdX[reorder]     = tempdQdX[reorder];
	 DataSptPitch[reorder] = tempPitch[reorder];
	 
	 DataSptsX[reorder] = tempx[reorder];
	 DataSptsY[reorder] = tempy[reorder];
	 DataSptsZ[reorder] = tempz[reorder];
	 
	 }//<---End reorder loop
      
      
      }//<---End Has to be reordered

   // ##################################
   // ### Printing things as a check ###
   // ##################################
/*   if(HasToBeReordered && VERBOSE)
      {
      for(int caloPoints = 0; caloPoints < nDataSpts; caloPoints++)
         {
	 std::cout<<"Run = "<<run<<", Event = "<<event<<" point = "<<caloPoints<<", RR = "<<DataResRange[caloPoints]<<", dE/dX = "<<DatadEdX[caloPoints]<<std::endl;
      
      
         }//<---End caloPoints
      std::cout<<std::endl;	 
      }//<---Putting in a print to make sure things are reordered correctly   */
   
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
      for(int caloPoints = 0; caloPoints < nDataSpts; caloPoints++)
         {
	 
	 // ###################################################
	 // ### If the dE/dX is large and at the end of the ###
	 // ###  track as expected with a proton attached   ###
	 // ###################################################
	 if(DatadEdX[caloPoints] > 40. && caloPoints == (nDataSpts-1) )
	    {
	    // ##########################################################
	    // ### Set this point equal to the previous point's dE/dX ###
	    // ##########################################################
	    
	    hdataFixedCaloPointZX->Fill(DataSptsZ[caloPoints], DataSptsX[caloPoints], DatadEdX[caloPoints]);
	    hdataFixedCaloPointZY->Fill(DataSptsZ[caloPoints], DataSptsY[caloPoints], DatadEdX[caloPoints]);
	    
	    DatadEdX[caloPoints] = DatadEdX[caloPoints - 1];
	    
	    
	    }//<---End large and at the end of the track
	 
	 // ############################################################
	 // ### Else, if it is a large dE/dX but not the first point ###
	 // ############################################################
	 else if(DatadEdX[caloPoints] > 40. && caloPoints < (nDataSpts-1) && caloPoints > 0.)
	    {
	    
	    // #################################################################
	    // ### Then just average between the previous and the next point ###
	    // #################################################################
	    
	    hdataFixedCaloPointZX->Fill(DataSptsZ[caloPoints], DataSptsX[caloPoints], DatadEdX[caloPoints]);
	    hdataFixedCaloPointZY->Fill(DataSptsZ[caloPoints], DataSptsY[caloPoints], DatadEdX[caloPoints]);
	    
	    DatadEdX[caloPoints] = ( (DatadEdX[caloPoints - 1] + DatadEdX[caloPoints + 1]) / 2.);
	    
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
      for(int caloPoints = 0; caloPoints < nDataSpts; caloPoints++)
         {
	 // ### If dE/dX > 15 and more than 10cm from the end of the track and isn't the first or last point ###
	 if(DatadEdX[caloPoints] > 15. && DataResRange[caloPoints] > 10. && caloPoints > 0.&& caloPoints < (nDataSpts-1) )
	    {
	    
	    // ### Check to see if the previous point is greater than 15 ###
	    if(DatadEdX[caloPoints-1] > 15.)
	       {
	       // ### Check to see if the next point is greater than 15 ###
	       if(DatadEdX[caloPoints+1] > 15. )
	          {
		  // ### Go 2 points before and after ###
		  hdataFixedCaloPointZX->Fill(DataSptsZ[caloPoints], DataSptsX[caloPoints], DatadEdX[caloPoints]);
	          hdataFixedCaloPointZY->Fill(DataSptsZ[caloPoints], DataSptsY[caloPoints], DatadEdX[caloPoints]);
		  
		  DatadEdX[caloPoints] = ( (DatadEdX[caloPoints - 2] + DatadEdX[caloPoints + 2]) / 2.);
		  }
	       else
	          {
		  // ### Go 2 points before and one point after ###
		  
		  hdataFixedCaloPointZX->Fill(DataSptsZ[caloPoints], DataSptsX[caloPoints], DatadEdX[caloPoints]);
	          hdataFixedCaloPointZY->Fill(DataSptsZ[caloPoints], DataSptsY[caloPoints], DatadEdX[caloPoints]);
		  
		  DatadEdX[caloPoints] = ( (DatadEdX[caloPoints - 2] + DatadEdX[caloPoints + 1]) / 2.);
		  }
	        }
	    else if(DatadEdX[caloPoints-1] <= 15.)
	       {
	       if(DatadEdX[caloPoints+1] > 15. )
	          {
		  
		  hdataFixedCaloPointZX->Fill(DataSptsZ[caloPoints], DataSptsX[caloPoints], DatadEdX[caloPoints]);
	          hdataFixedCaloPointZY->Fill(DataSptsZ[caloPoints], DataSptsY[caloPoints], DatadEdX[caloPoints]);
		  
		  DatadEdX[caloPoints] = ( (DatadEdX[caloPoints - 1] + DatadEdX[caloPoints+2]) / 2.);
		  }
	       else
	          {
		  
		  hdataFixedCaloPointZX->Fill(DataSptsZ[caloPoints], DataSptsX[caloPoints], DatadEdX[caloPoints]);
	          hdataFixedCaloPointZY->Fill(DataSptsZ[caloPoints], DataSptsY[caloPoints], DatadEdX[caloPoints]);
		  
		  DatadEdX[caloPoints] = ( (DatadEdX[caloPoints - 2] + DatadEdX[caloPoints + 1]) / 2.);
		  }
	       }
	   else DatadEdX[caloPoints] = ( (DatadEdX[caloPoints - 1] + DatadEdX[caloPoints+1]) / 2.);
	   }
	
      
         }//<---End caloPoints loop
      
      }//<---Only fixing calorimetry for less big fluctuations   
   
   
   
   // ##########################################
   // ### Filling the fixed dE/dX vs RR plot ###
   // ##########################################
   for(int caloPoints = 0; caloPoints < nDataSpts; caloPoints++)
      {
      
      hdatadEdXvsRRFix->Fill(DataResRange[caloPoints], DatadEdX[caloPoints]);
      
      hdatadEdXFixed->Fill(DatadEdX[caloPoints]);
      
      hdatadQdXFixed->Fill(DatadQdX[caloPoints]);
      
      // =====================================================================
      // === Breaking the TPC into 4 quadrants to analyze the dE/dX and dQ/dX
      // ===               Q1: 0 cm    < z    < 22.5 cm
      // ===               Q2: 22.5 cm < z    < 45 cm
      // ===               Q3: 45 cm   < z    < 67.5 cm
      // ===               Q4: 67.5 cm < z    < 90 cm
      // =====================================================================
      if(DataSptsZ[caloPoints] > 0    && DataSptsZ[caloPoints] < 22.5)
         {
	 hdatadEdXQ1Fixed->Fill(DatadEdX[caloPoints]);
	 hdatadQdXQ1Fixed->Fill(DatadQdX[caloPoints]);
	 }
      if(DataSptsZ[caloPoints] > 22.5 && DataSptsZ[caloPoints] < 45)
         {
	 hdatadEdXQ2Fixed->Fill(DatadEdX[caloPoints]);
	 hdatadQdXQ2Fixed->Fill(DatadQdX[caloPoints]);
	 }
      if(DataSptsZ[caloPoints] > 45   && DataSptsZ[caloPoints] < 67.5)
         {
	 hdatadEdXQ3Fixed->Fill(DatadEdX[caloPoints]);
	 hdatadQdXQ3Fixed->Fill(DatadQdX[caloPoints]);
	 }
      if(DataSptsZ[caloPoints] > 67.5 && DataSptsZ[caloPoints] < 90)
         {
	 hdatadEdXQ4Fixed->Fill(DatadEdX[caloPoints]);
	 hdatadQdXQ4Fixed->Fill(DatadQdX[caloPoints]);
	 }
      
      }//<---End Fix   
   /*std::cout<<std::endl;
   std::cout<<"Track Vtx X = "<<trkvtxx[0]<<", Y = "<<trkvtxy[0]<<", Z = "<<trkvtxz[0]<<std::endl;
   std::cout<<"Track End X = "<<trkendx[0]<<", Y = "<<trkendy[0]<<", Z = "<<trkendz[0]<<std::endl;
   std::cout<<"Delta Y = "<<DeltaY<<std::endl;
   std::cout<<std::endl;*/
   
   
   
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
