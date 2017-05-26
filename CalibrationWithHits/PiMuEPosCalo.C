#define PiMuEPosCalo_cxx
#include "PiMuEPosCalo.h"
#include <TH2.h>
#include <TMath.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iostream>

float corrdEdx(float dEdx){
  
  float rho    = 1.383;
  float beta   = 0.3 ;// cm / MeV
  float betap  = 0.212; //(kV/cm)(g/cm^2)/MeV 
  float alpha  = 0.93;
  float Wion   = 23.6 / 1E6;// MeV / e-
  float Efield = 0.5;

  float dQdx = log(dEdx * betap/(rho*Efield) + alpha) / (betap/(rho*Efield) * Wion);
  
  dQdx *= 0.0153/0.048;

  //dQdx *= 0.0153/0.0382;

  float newdQdx = (exp(betap/(rho*Efield) * Wion * dQdx) - alpha)/(betap/(rho*Efield));
  //cout<<newdQdx<<endl;

  return newdQdx;
}


TH1D *hWCMomentumTot          = new TH1D("hWCMomentumTot"         , "All Pi/Miu WC Momentum"         , 180, 0, 1800);
TH1D *hWCMomentumThroughgoing = new TH1D("hWCMomentumThroughgoing", "Throughgoing Pi/Miu WC Momentum", 180, 0, 1800);


//Pitch Study
TH1D *hCollectionPitchThrough     = new TH1D("hCollectionPitchThrough"    , "Throughgoing Pi/Miu Pitch On Collection" , 400, 0, 4.);
TH1D *hInductionPitchThrough      = new TH1D("hInductionPitchThrough"     , "Throughgoing Pi/Miu Pitch On Induction " , 400, 0, 4.);


TH1D *hLowQCollectionPitchThrough     = new TH1D("hLowQCollectionPitchThrough"    , "Throughgoing Pi/Miu Pitch On Collection" , 400, 0, 4.);


// Thought going study
TH1D *hCollectionDEDXThrough     = new TH1D("hCollectionDEDXThrough"    , "Throughgoing Pi/Miu DEDX On Collection" , 100, 0, 10);
TH1D *hInductionDEDXThrough      = new TH1D("hInductionDEDXThrough"     , "Throughgoing Pi/Miu DEDX On Induction " , 100, 0, 10);

TH1D *hCollectionDEDSThroughHits = new TH1D("hCollectionDEDSThroughHits", "Throughgoing Pi/Miu DEDS On Collection from Hits; dEdS [Mev/cm]" , 100, 0, 10);

TH1D *hCollectionDQDXThrough     = new TH1D("hCollectionDQDXThrough"    , "Throughgoing Pi/Miu DQDX On Collection;dEdx [Mev/cm]" , 300, 0, 12000);
TH1D *hInductionDQDXThrough      = new TH1D("hInductionDQDXThrough"     , "Throughgoing Pi/Miu DQDX On Induction;dEdx [Mev/cm] " , 300, 0, 12000);


void PiMuEPosCalo::Loop()
{
   if (fChain == 0) return;

  Long64_t nentries = fChain->GetEntriesFast();
  Long64_t nbytes = 0, nb = 0;

  int nThoughtGoing = 0;

  nentries = 1000;
  for (Long64_t jentry=0; jentry<nentries;jentry++) {

    if (jentry % 1000 == 0) std::cout<<"Event number  "<<jentry<<std::endl;

    Long64_t ientry = LoadTree(jentry);
    if (ientry < 0) break;
    nb = fChain->GetEntry(jentry);   nbytes += nb;
      
    // Loop on tracks
    if (ntracks_reco > 1 || ntracks_reco < 1) continue;
    for(size_t iTPCtrk = 0; iTPCtrk < ntracks_reco; iTPCtrk++)
      {

	//   Fill Tot WC momentum histo   
	hWCMomentumTot->Fill(wctrk_momentum[0]);
		

	// Check which direction the track was reconstructed
	bool   invertedOrder  = false;
	double correctLastZPoint  = trkendz[iTPCtrk];
	double correctFirstZPoint = trkvtxz[iTPCtrk];
	if ( trkvtxz[iTPCtrk] > trkendz[iTPCtrk] )
	  {
	    invertedOrder  = true;
	    correctLastZPoint  = trkvtxz[iTPCtrk];
	    correctFirstZPoint = trkendz[iTPCtrk];
	  }
	  

	// Now, my Pi/Mu is either: 
	// thoughtgoing or 

	if (correctLastZPoint > 85.0 && correctFirstZPoint < 5.0)
	  {
	    nThoughtGoing++;

	    // ******************************
	    // *** thought going analysis *** 
	    // ******************************
	    hWCMomentumThroughgoing->Fill(wctrk_momentum[0]);
	       
	    for (int i = 0; i<nhits; ++i){
	      if (hit_trkkey[i]==iTPCtrk){
		if (hit_plane[i]==1){
		  hCollectionDEDSThroughHits->Fill(corrdEdx(hit_dEds[i]));
		}
	      }
	    }

	    //Loop on Collection Plane Hits
	    for (size_t iHitC = 0; iHitC < trkhits[iTPCtrk][1]; iHitC++ )
	      {
		hCollectionPitchThrough->Fill(trkpitchhit[iTPCtrk][1][iHitC]);
		hCollectionDEDXThrough ->Fill(trkdedx[iTPCtrk][1][iHitC]);
		hCollectionDQDXThrough ->Fill(trkdqdx[iTPCtrk][1][iHitC]);
		if (trkdqdx[iTPCtrk][1][iHitC]< 1600)
		  {
		    hLowQCollectionPitchThrough->Fill(trkpitchhit[iTPCtrk][1][iHitC]);
		    std::cout<<"Run: "<<run<<"  Subrun: "<<subrun<<" Event: "<<event<<"\n";
		  }
		/*
		if (iHitC == trkhits[iTPCtrk][1]-1) 
		  {
		    std::cout<<trkdqdx[iTPCtrk][1][iHitC]  <<" 0\n";
		    std::cout<<trkdqdx[iTPCtrk][1][iHitC+1]<<" 2\n";
		  }
		*/
	      }//End of loop on Collection Plane Hits
	          
	          
	    //Loop on Induction Plane Hits
	    for (size_t iHitI = 0; iHitI < trkhits[iTPCtrk][0]; iHitI++ )
	      {
		hInductionPitchThrough->Fill(trkpitchhit[iTPCtrk][0][iHitI]);
		hInductionDEDXThrough ->Fill(trkdedx[iTPCtrk][0][iHitI]);
		hInductionDQDXThrough ->Fill(trkdqdx[iTPCtrk][0][iHitI]);
	      }//End of loop on Induction Plane Hits
	          

	  }
      }// end of reco track loop
    // if (Cut(ientry) < 0) continue;
  }// end of event loop

  std::cout<<"Total of particle throughoing ... "<<nThoughtGoing<<std::endl;

  TFile myfile("PiMuEPosCalo.root", "RECREATE");
  myfile.cd();

  hWCMomentumTot          ->Write();    
  hWCMomentumThroughgoing ->Write();

  hCollectionPitchThrough->Write();
  hInductionPitchThrough ->Write();
  hLowQCollectionPitchThrough ->Write();                   
  hCollectionDEDXThrough ->Write();
  hInductionDEDXThrough  ->Write();
  hCollectionDQDXThrough ->Write();
  hInductionDQDXThrough  ->Write();

  hCollectionDEDSThroughHits->Write();
}
