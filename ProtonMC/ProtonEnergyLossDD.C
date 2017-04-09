#define ProtonEnergyLossDD_cxx
#include "ProtonEnergyLossDD.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

// ===================================================================================================================
// ====================================       PUT HISTOGRAMS HERE           ==========================================
// ===================================================================================================================

/////////////////////////////////// Energy Loss in the upstream region of the beamline ///////////////////////
TH1D *hMCELossUpstream = new TH1D("hMCELossUpstream", "Energy loss prior to entering the TPC", 1000, 0, 1000);

/////////////////////////////////// Energy Loss in the TPC  ///////////////////////
TH1D *hMCELossInTPC = new TH1D("hMCELossInTPC", "Energy loss inside the TPC", 110, -100, 1000);

/////////////////////////////////// Energy Loss in the TPC (Reco-info)  ///////////////////////
TH1D *hMCELossRecoInTPC = new TH1D("hMCELossRecoInTPC", "Reconstructed Energy loss inside the TPC", 110, -100, 1000);

/////////////////////////////////// Delta Energy Loss in the TPC (Reco-true)  ///////////////////////
TH1D *hDeltaELoss = new TH1D("hDeltaELoss", "E_{Loss in TPC}^{Reco} - E_{Loss in TPC}^{True}", 100, -100, 100);

/////////////////////////////////// Initial Kinetic Energy /////////////////////////
TH1D *hInitialKE = new TH1D("hInitialKE", "Initial Kinetic Energy", 110, -100, 1000);

/////////////////////////////////// Initial Kinetic Energy @ the TPC /////////////////////////
TH1D *hInitialKEAtTPC = new TH1D("hInitialKEAtTPC", "Initial Kinetic Energy at the TPC", 110, -100, 1000);

/////////////////////////////////// Initial Kinetic Energy @ the TPC using flat correction /////////////////////////
TH1D *hInitialKEAtTPCFlat = new TH1D("hInitialKEAtTPCFlat", "Initial Kinetic Energy at the TPC using flat correction", 110, -100, 1000);

/////////////////////////////////// Final Kinetic Energy in the TPC /////////////////////////
TH1D *hFinalKEInTPC = new TH1D("hFinalKEInTPC", "Final Kinetic Energy in the TPC", 110, -100, 1000);

/////////////////////////////////// Final Kinetic Energy in the TPC from Reconstruction /////////////////////////
TH1D *hFinalKEInTPCReco = new TH1D("hFinalKEInTPCReco", "Final Kinetic Energy in the TPC using Reco", 110, -100, 1000);

/////////////////////////////////// Final Kinetic Energy in the TPC from Reconstruction and flat correction /////////////////////////
TH1D *hFinalKEInTPCRecoFlat = new TH1D("hFinalKEInTPCRecoFlat", "Final Kinetic Energy in the TPC using Reco and flat correction", 110, -100, 1000);

/////////////////////////////////// E Loss upstream of the TPC /////////////////////////
TH2D *hELossXvsY = new TH2D("hELossXvsY", "Energy Loss X vs Y", 100, 0, 50, 100, -25, 25);

/////////////////////////////////// E Loss upstream of the Flux TPC /////////////////////////
TH2D *hELossXvsYFlux = new TH2D("hELossXvsYFlux", "Energy Loss X vs Y", 100, 0, 50, 100, -25, 25);

/////////////////////////////////// Divided E Loss /////////////////////////
TH2D *hELossXvsYDivide = new TH2D("hELossXvsYDivide", "Energy Loss X vs Y", 100, 0, 50, 100, -25, 25);

////////////////////////////////// MC Theta  //////////////////////////////
TH1D *hMCTheta = new TH1D("hMCTheta", "Theta", 360, -180, 180);

////////////////////////////////// MC Phi  //////////////////////////////
TH1D *hMCPhi = new TH1D("hMCPhi", "Phi", 360, 0, 360);

/////////////////////////////////// Phi vs ELoss /////////////////////////
TH2D *hPhivsELoss = new TH2D("hPhivsELoss", "Phi vs Energy Loss", 360, 0, 360, 400, 0, 400);

/////////////////////////////////// Phi vs Theta ELoss /////////////////////////
TH2D *hPhivsThetaELoss = new TH2D("hPhivsThetaELoss", "Phi vs Energy Loss", 360, 0, 360, 360, -180, 180);

/////////////////////////////////// Phi vs Theta ELoss Flux /////////////////////////
TH2D *hPhivsThetaELossFlux = new TH2D("hPhivsThetaELossFlux", "Phi vs Energy Loss", 360, 0, 360, 360, -180, 180);

/////////////////////////////////// Phi vs Theta ELoss Divided /////////////////////////
TH2D *hPhivsThetaELossDivided = new TH2D("hPhivsThetaELossDivided", "Phi vs Energy Loss", 360, 0, 360, 360, -180, 180);

/////////////////////////////////// Primary End X vs Z Position //////////////////////////////////////////////
TH2D *hMCPrimaryEndXvsZ = new TH2D("hMCPrimaryEndXvsZ", "X_{f} vs Z_{f}", 600, -150, 450, 400, -200, 200);

/////////////////////////////////// Primary End Y vs Z Position //////////////////////////////////////////////
TH2D *hMCPrimaryEndYvsZ = new TH2D("hMCPrimaryEndYvsZ", "Y_{f} vs Z_{f}", 600, -150, 450, 200, -200, 200);

void ProtonEnergyLossDD::Loop()
{

// ##########################################################
// ### Putting in some counters for event reduction table ###
// ##########################################################
int nTotalEvents = 0, nEventsReachTPC = 0, nParticlesStop = 0;

bool EventsReachTPC = false;
bool EventsWhereParticleStops = false;

float particle_mass = 938.28 ;

// #################################
// ### Variables for Energy Loss ###
// #################################
float EnergyLossOutsideTPC = 0;
float EnergyLossInsideTPC = 0;


float RecoEnergyLossInsideTPC = 0;



// ###########################################
// ### Create a file for all my histograms ###
// ###########################################
TFile myfile("../histoROOTfiles_forPlots/DataDrivenProtonMC_EnergyCalibrationPlots.root","RECREATE");

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if (fChain == 0) return;
Long64_t nentries = fChain->GetEntriesFast();
Long64_t nbytes = 0, nb = 0;


// ###########################
// ### Looping over events ###
// ###########################
//for (Long64_t jentry=0; jentry<nentries;jentry++) 
for (Long64_t jentry=0; jentry< 50000;jentry++)
   {
   Long64_t ientry = LoadTree(jentry);
   if (ientry < 0) break;
   nb = fChain->GetEntry(jentry);   nbytes += nb;
   
   RecoEnergyLossInsideTPC = 0;
   
   // #############################
   // ### Counting Total Events ###
   // #############################
   nTotalEvents++;
   
   
   // === Outputting every nEvents to the screen ===
   if(nTotalEvents % 1000 == 0){std::cout<<"Event = "<<nTotalEvents<<std::endl;} 
   
   // ### Assume the event doesn't reach the TPC ###
   EventsReachTPC = false;
   
   // ### Assume the particle does stop ###
   EventsWhereParticleStops = true;
   
   
   
   // #############################################
   // ###       Defining variables for the      ###
   // ### momentum at the front face of the TPC ###
   // #############################################
   
   float FrontFace_Px = 0, FrontFace_Py = 0, FrontFace_Pz = 0;
      
   //=======================================================================================================================
   //					      GEANT 4 Information
   //=======================================================================================================================
   // #######################################
   // ### Loop over all the G4  particles ###
   // #######################################
   for (int iG4 = 0; iG4 < geant_list_size; iG4++)
      {
      
      EnergyLossOutsideTPC = 0;
      EnergyLossInsideTPC = 0;
      
      
      float FinalKEInTPC = 0;
      float FinalKEInTPCReco = 0;
      float FinalKEInTPCRecoDumbCorr = 0;
      
      // #########################################################
      // ### Skipping any particle which doesn't enter the TPC ###
      // #########################################################
      if(EndPointz[iG4] < 0){continue;}
      
      // ### If we are here, the event must pass through the TPC ###
      EventsReachTPC = true;
      
      // #######################################################
      // ### Skipping the event if the particle doesn't stop ###
      // #######################################################
      if(EndPointz[iG4] < 0 || EndPointz[iG4] > 90 || EndPointx[iG4] < 0 || 
         EndPointx[iG4] > 43 || EndPointy[iG4] < -20 || 
	 EndPointy[iG4] > 20 || NumberDaughters[iG4] > 0) {EventsWhereParticleStops = false; continue; }
      
      
      float g4Primary_ProjX0 = 0.0;
      float g4Primary_ProjY0 = 0.0;
      float g4Primary_ProjZ0 = 0.0; 
      
      
      float MCRecodEdX[1000]  = {0.}; 
      int nMCRecoSpts = 0;   
      // #############################################
      // ### Loop over all the primary true points ###
      // #############################################
      if(process_primary[iG4] == 1 && NumberDaughters[iG4] == 0)
         {
	
	 
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
	 
	       // ### If this didn't fix it, then just put in a flat 2.4 MeV / cm fix ###
	       if(MCRecodEdX[nMCRecoSpts] < 0)
	          {continue;}
	       
	       RecoEnergyLossInsideTPC+= MCRecodEdX[nMCRecoSpts] * trkpitchhit[nTPCtrk][1][nspts];
	       //std::cout<<"dE/dX = "<<MCRecodEdX[nMCRecoSpts]<<", Pitch = "<<trkpitchhit[nTPCtrk][1][nspts]<<std::endl;
	       
	       nMCRecoSpts++;
	       }//<---end nspts

	    
	    }// end nTPCtrk loop
	 
	 
	 // ### Filling the energy loss inside the TPC from reconstruction ###
	 // ###        (unless there wasn't any dE/dX info reco'd)         ###
	 if(RecoEnergyLossInsideTPC > 0)
	    {hMCELossRecoInTPC->Fill(RecoEnergyLossInsideTPC);}
	 
	 
	 // ### Plotting the end point of the particles ###
	 hMCPrimaryEndXvsZ->Fill(EndPointz[iG4], EndPointx[iG4]);
	 hMCPrimaryEndYvsZ->Fill(EndPointz[iG4], EndPointy[iG4]);
	 
	 // ############################################
	 // ### Calculate the initial Kinetic Energy ###
	 // ############################################
	 
	 float momentum = sqrt( (Px[iG4] * Px[iG4]) + (Py[iG4] * Py[iG4]) + (Pz[iG4] * Pz[iG4]) ) * 1000;
	 
	 float InitialKE = sqrt( (momentum*momentum) + (particle_mass*particle_mass)) - particle_mass;
	 
	 hInitialKE->Fill(InitialKE);
	 
	 // ### Defining first point ###
	 float FirstPoint_Z = 999;
	 
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
				       
	       float Energy_Point1 = sqrt( (Momentum_Point1*Momentum_Point1) + (particle_mass*particle_mass)  );
	       
	       float Energy_Point2 = sqrt( (Momentum_Point2*Momentum_Point2) + (particle_mass*particle_mass)  );
	       
	       EnergyLossOutsideTPC +=  Energy_Point1 - Energy_Point2;
	       }//<---End Looking at energy loss upstream of TPC
	    
	    
	       
	    // ### Only looking at points which are inside of the TPC ###
	    if(MidPosZ[iG4][iPriTrj] >= 0 && MidPosZ[iG4][iPriTrj] < 90 &&
	       MidPosX[iG4][iPriTrj] > 0 && MidPosX[iG4][iPriTrj] < 43 &&
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
	    
	 hMCELossUpstream->Fill(EnergyLossOutsideTPC);
	 hMCELossInTPC->Fill(EnergyLossInsideTPC);
	 
	 float DeltaELoss = RecoEnergyLossInsideTPC - EnergyLossInsideTPC;
	 hDeltaELoss->Fill(DeltaELoss);
	 
	 // ###############################################################
	 // ### Calculating the initial KE at the front face of the TPC ###
	 // ###############################################################
	 float InitialKEAtTPC = InitialKE - EnergyLossOutsideTPC;
	 float InitialKEAtTPCDumbWay = InitialKE - 65;
	 
	 hInitialKEAtTPC->Fill(InitialKEAtTPC);
	 hInitialKEAtTPCFlat->Fill(InitialKEAtTPCDumbWay);
	 
	 // ###############################################
	 // ### Calculating the Final KE inside the TPC ###
	 // ###############################################
	 FinalKEInTPC = InitialKE - EnergyLossOutsideTPC - EnergyLossInsideTPC;
	 
	 FinalKEInTPCReco = InitialKE - EnergyLossOutsideTPC - RecoEnergyLossInsideTPC;
	 
	 FinalKEInTPCRecoDumbCorr = InitialKEAtTPCDumbWay - RecoEnergyLossInsideTPC;
	 
	 hFinalKEInTPC->Fill(FinalKEInTPC);
	 hFinalKEInTPCReco->Fill(FinalKEInTPCReco);
	 hFinalKEInTPCRecoFlat->Fill(FinalKEInTPCRecoDumbCorr);
	 
	 // ------------------------------------------------------------------------------------
	 // ---------------        Extrapolate the X, Y, Z position of the primary         -----
	 // ---------------     if it started upstream of the front face of the TPC        -----
	 // ------------------------------------------------------------------------------------
	 
	 double b1 = StartPointz[iG4] - StartPointx[iG4]*Pz[iG4]/Px[iG4];
	 double b2 = StartPointz[iG4] - StartPointy[iG4]*Pz[iG4]/Py[iG4];
	 
	 g4Primary_ProjX0 = -b1*Px[iG4]/Pz[iG4];
	 g4Primary_ProjY0 = -b2*Py[iG4]/Pz[iG4];
	 g4Primary_ProjZ0 = 0.0;
	 
	 hELossXvsY->Fill(g4Primary_ProjX0, g4Primary_ProjY0, EnergyLossOutsideTPC);
	 
	 hELossXvsYFlux->Fill(g4Primary_ProjX0, g4Primary_ProjY0);
	 
	 
	 
	 // ----------------------------------------------------------------------- 
	 // ------------        Calculating the theta and phi at the       --------
	 // ------------           at the front face of the TPC            --------
	 // -----------------------------------------------------------------------
	 
	 // ################################################
   	 // ### Calculating the angles for the Geant4 MC ###
   	 // ################################################
   	 TVector3 z_hat_MC(0,0,1);
   	 TVector3 p_hat_0_MC;
	 
	 // ### Setting the vector for the MC using the ###
   	 // ###  extrapolated Momentum vector   ###
   	 /*p_hat_0_MC.SetX(Px[iG4]);
   	 p_hat_0_MC.SetY(Py[iG4]);
   	 p_hat_0_MC.SetZ(Pz[iG4]); */
	 
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
	 
	 //std::cout<<"mcTheta = "<<mcTheta*(180/3.14159)<<std::endl;
	 //std::cout<<"FrontFace_Px = "<<FrontFace_Px<<std::endl;
	 hMCTheta->Fill(mcTheta*(180/3.14159));
	 hMCPhi->Fill(mcPhi*(180/3.14159));
	 
	 
	 hPhivsELoss->Fill(mcPhi*(180/3.14159) ,EnergyLossOutsideTPC);
	 hPhivsThetaELoss->Fill(mcPhi*(180/3.14159) ,mcTheta*(180/3.14159), EnergyLossOutsideTPC);
	 hPhivsThetaELossFlux->Fill(mcPhi*(180/3.14159) ,mcTheta*(180/3.14159));
	 }//<---Only looking at primary particles
      
      float P = sqrt( (Px[iG4]*Px[iG4]) + (Py[iG4]*Py[iG4]) + (Pz[iG4]*Pz[iG4])) * 1000;
      //if(FinalKEInTPC == 0){std::cout<<"Run "<<run<<", SubRun "<<subrun<<", Event "<<event<<" P "<<P<<std::endl;}
      
      
      
      }//<---End iG4Pri loop
   
   
   // ### Counting the events which pass through the TPC ###
   if(EventsReachTPC){nEventsReachTPC++;}
   if(EventsWhereParticleStops){nParticlesStop++;}
   
   }//<---End jentry loop


std::cout<<"========================================================================================"<<std::endl;
std::cout<<"Total Number of Events 				"<<nTotalEvents<<std::endl;
std::cout<<"Particles reach the TPC				"<<nEventsReachTPC<<std::endl;
std::cout<<"Particle stops inside the TPC			"<<nParticlesStop<<std::endl;
std::cout<<"========================================================================================"<<std::endl;


// ##########################
// ### Dividing the plots ###
// ##########################
hELossXvsYDivide->Divide(hELossXvsY, hELossXvsYFlux);
hPhivsThetaELossDivided->Divide(hPhivsThetaELoss, hPhivsThetaELossFlux);



hMCELossUpstream->Write();
hMCELossInTPC->Write();
hInitialKE->Write();
hInitialKEAtTPC->Write();
hFinalKEInTPC->Write();
hELossXvsY->Write();
hELossXvsYFlux->Write();
hELossXvsYDivide->Write();
hMCTheta->Write();
hMCPhi->Write();
hPhivsELoss->Write();
hPhivsThetaELoss->Write();
hPhivsThetaELossFlux->Write();
hPhivsThetaELossDivided->Write();
hMCPrimaryEndXvsZ->Write();
hMCPrimaryEndYvsZ->Write();
hMCELossRecoInTPC->Write();
hDeltaELoss->Write();
hFinalKEInTPCReco->Write();
hInitialKEAtTPCFlat->Write();
hFinalKEInTPCRecoFlat->Write();



}
