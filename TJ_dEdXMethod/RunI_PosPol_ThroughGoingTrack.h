//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon May 22 11:21:14 2017 by ROOT version 5.34/36
// from TTree anatree/analysis tree
// found on file: ../ROOTFILES/RunIPosPol_AnaTree_06_15_00.root
//////////////////////////////////////////////////////////

#ifndef RunI_PosPol_ThroughGoingTrack_h
#define RunI_PosPol_ThroughGoingTrack_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>

// Fixed size dimensions of array or collections stored in the TTree if any.

class RunI_PosPol_ThroughGoingTrack {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           run;
   Int_t           subrun;
   Int_t           event;
   Double_t        evttime;
   Double_t        efield[3];
   Int_t           t0;
   Int_t           nclus;
   Double_t        clustertwire[765];   //[nclus]
   Double_t        clusterttick[765];   //[nclus]
   Double_t        cluendwire[765];   //[nclus]
   Double_t        cluendtick[765];   //[nclus]
   Int_t           cluplane[765];   //[nclus]
   Int_t           ntracks_reco;
   Double_t        trkvtxx[144];   //[ntracks_reco]
   Double_t        trkvtxy[144];   //[ntracks_reco]
   Double_t        trkvtxz[144];   //[ntracks_reco]
   Double_t        trkendx[144];   //[ntracks_reco]
   Double_t        trkendy[144];   //[ntracks_reco]
   Double_t        trkendz[144];   //[ntracks_reco]
   Double_t        trkstartdcosx[144];   //[ntracks_reco]
   Double_t        trkstartdcosy[144];   //[ntracks_reco]
   Double_t        trkstartdcosz[144];   //[ntracks_reco]
   Double_t        trkenddcosx[144];   //[ntracks_reco]
   Double_t        trkenddcosy[144];   //[ntracks_reco]
   Double_t        trkenddcosz[144];   //[ntracks_reco]
   Int_t           trkWCtoTPCMatch[144];   //[ntracks_reco]
   Double_t        trklength[144];   //[ntracks_reco]
   Double_t        trkmomrange[144];   //[ntracks_reco]
   Double_t        trkmommschi2[144];   //[ntracks_reco]
   Double_t        trkmommsllhd[144];   //[ntracks_reco]
   Int_t           ntrkhits[144];   //[ntracks_reco]
   Double_t        trkx[144][1000];   //[ntracks_reco]
   Double_t        trky[144][1000];   //[ntracks_reco]
   Double_t        trkz[144][1000];   //[ntracks_reco]
   Double_t        trkpitch[144][2];   //[ntracks_reco]
   Int_t           trkhits[144][2];   //[ntracks_reco]
   Double_t        trkdedx[144][2][1000];   //[ntracks_reco]
   Double_t        trkdqdx[144][2][1000];   //[ntracks_reco]
   Double_t        trkrr[144][2][1000];   //[ntracks_reco]
   Double_t        trkpitchhit[144][2][1000];   //[ntracks_reco]
   Double_t        trkxyz[144][2][1000][3];   //[ntracks_reco]
   Double_t        trkke[144][2];   //[ntracks_reco]
   Double_t        trkpida[144][2];   //[ntracks_reco]
   Int_t           nTrajPoint[144];   //[ntracks_reco]
   Double_t        pHat0_X[144][1000];   //[ntracks_reco]
   Double_t        pHat0_Y[144][1000];   //[ntracks_reco]
   Double_t        pHat0_Z[144][1000];   //[ntracks_reco]
   Double_t        trjPt_X[144][1000];   //[ntracks_reco]
   Double_t        trjPt_Y[144][1000];   //[ntracks_reco]
   Double_t        trjPt_Z[144][1000];   //[ntracks_reco]
   Int_t           trkg4id[144];   //[ntracks_reco]
   Int_t           primarytrkkey;
   Int_t           nhits;
   Int_t           hit_plane[16502];   //[nhits]
   Int_t           hit_wire[16502];   //[nhits]
   Int_t           hit_channel[16502];   //[nhits]
   Double_t        hit_peakT[16502];   //[nhits]
   Double_t        hit_charge[16502];   //[nhits]
   Double_t        hit_ph[16502];   //[nhits]
   Double_t        hit_tstart[16502];   //[nhits]
   Double_t        hit_tend[16502];   //[nhits]
   Int_t           hit_trkid[16502];   //[nhits]
   Int_t           hit_trkkey[16502];   //[nhits]
   Int_t           hit_clukey[16502];   //[nhits]
   Int_t           hit_pk[16502];   //[nhits]
   Int_t           hit_t[16502];   //[nhits]
   Int_t           hit_ch[16502];   //[nhits]
   Int_t           hit_fwhh[16502];   //[nhits]
   Double_t        hit_rms[16502];   //[nhits]
   Double_t        hit_nelec[16502];   //[nhits]
   Double_t        hit_energy[16502];   //[nhits]
   Float_t         hit_dQds[16502];   //[nhits]
   Float_t         hit_dEds[16502];   //[nhits]
   Float_t         hit_ds[16502];   //[nhits]
   Float_t         hit_resrange[16502];   //[nhits]
   Float_t         hit_x[16502];   //[nhits]
   Float_t         hit_y[16502];   //[nhits]
   Float_t         hit_z[16502];   //[nhits]
   Int_t           nwctrks;
   Double_t        wctrk_XFaceCoor[1];   //[nwctrks]
   Double_t        wctrk_YFaceCoor[1];   //[nwctrks]
   Double_t        wctrk_momentum[1];   //[nwctrks]
   Double_t        wctrk_theta[1];   //[nwctrks]
   Double_t        wctrk_phi[1];   //[nwctrks]
   Double_t        wctrk_XDist[1];   //[nwctrks]
   Double_t        wctrk_YDist[1];   //[nwctrks]
   Double_t        wctrk_ZDist[1];   //[nwctrks]
   Double_t        XWireHist[1][1000];   //[nwctrks]
   Double_t        YWireHist[1][1000];   //[nwctrks]
   Double_t        XAxisHist[1][1000];   //[nwctrks]
   Double_t        YAxisHist[1][1000];   //[nwctrks]
   Double_t        Y_Kink[1];   //[nwctrks]
   Float_t         WC1xPos[1];   //[nwctrks]
   Float_t         WC1yPos[1];   //[nwctrks]
   Float_t         WC1zPos[1];   //[nwctrks]
   Float_t         WC2xPos[1];   //[nwctrks]
   Float_t         WC2yPos[1];   //[nwctrks]
   Float_t         WC2zPos[1];   //[nwctrks]
   Float_t         WC3xPos[1];   //[nwctrks]
   Float_t         WC3yPos[1];   //[nwctrks]
   Float_t         WC3zPos[1];   //[nwctrks]
   Float_t         WC4xPos[1];   //[nwctrks]
   Float_t         WC4yPos[1];   //[nwctrks]
   Float_t         WC4zPos[1];   //[nwctrks]
   Int_t           ntof;
   Double_t        tofObject[1];   //[ntof]
   Double_t        tof_timestamp[1];   //[ntof]
   Int_t           nAG;
   Double_t        HitTimeStamp1p10_1[1];   //[nAG]
   Double_t        HitTimeStamp1p10_2[1];   //[nAG]
   Double_t        HitTimeStamp1p06_1[1];   //[nAG]
   Double_t        HitTimeStamp1p06_2[1];   //[nAG]
   Float_t         HitPulseArea1p10_1[1];   //[nAG]
   Float_t         HitPulseArea1p10_2[1];   //[nAG]
   Float_t         HitPulseArea1p06_1[1];   //[nAG]
   Float_t         HitPulseArea1p06_2[1];   //[nAG]
   Bool_t          HitExist1p10_1[1];   //[nAG]
   Bool_t          HitExist1p10_2[1];   //[nAG]
   Bool_t          HitExist1p06_1[1];   //[nAG]
   Bool_t          HitExist1p06_2[1];   //[nAG]
   Int_t           maxTrackIDE;
   Double_t        IDEEnergy[1];   //[maxTrackIDE]
   Double_t        IDEPos[1][3];   //[maxTrackIDE]
   Int_t           no_primaries;
   Int_t           geant_list_size;
   Int_t           pdg[1];   //[geant_list_size]
   Double_t        Eng[1];   //[geant_list_size]
   Double_t        Px[1];   //[geant_list_size]
   Double_t        Py[1];   //[geant_list_size]
   Double_t        Pz[1];   //[geant_list_size]
   Double_t        EndEng[1];   //[geant_list_size]
   Double_t        EndPx[1];   //[geant_list_size]
   Double_t        EndPy[1];   //[geant_list_size]
   Double_t        EndPz[1];   //[geant_list_size]
   Double_t        StartPointx[1];   //[geant_list_size]
   Double_t        StartPointy[1];   //[geant_list_size]
   Double_t        StartPointz[1];   //[geant_list_size]
   Double_t        EndPointx[1];   //[geant_list_size]
   Double_t        EndPointy[1];   //[geant_list_size]
   Double_t        EndPointz[1];   //[geant_list_size]
   Int_t           Process[1];   //[geant_list_size]
   Int_t           NumberDaughters[1];   //[geant_list_size]
   Int_t           Mother[1];   //[geant_list_size]
   Int_t           TrackId[1];   //[geant_list_size]
   Int_t           process_primary[1];   //[geant_list_size]
   vector<string>  *G4Process;
   vector<string>  *G4FinalProcess;
   Int_t           NTrTrajPts[1];   //[no_primaries]
   Double_t        MidPosX[1][5000];   //[no_primaries]
   Double_t        MidPosY[1][5000];   //[no_primaries]
   Double_t        MidPosZ[1][5000];   //[no_primaries]
   Double_t        MidPx[1][5000];   //[no_primaries]
   Double_t        MidPy[1][5000];   //[no_primaries]
   Double_t        MidPz[1][5000];   //[no_primaries]
   vector<int>     *InteractionPoint;
   vector<int>     *InteractionPointType;
   Int_t           no_mcshowers;
   Double_t        mcshwr_origin[1];   //[no_mcshowers]
   Double_t        mcshwr_pdg[1];   //[no_mcshowers]
   Int_t           mcshwr_TrackId[1];   //[no_mcshowers]
   Double_t        mcshwr_startX[1];   //[no_mcshowers]
   Double_t        mcshwr_startY[1];   //[no_mcshowers]
   Double_t        mcshwr_startZ[1];   //[no_mcshowers]
   Double_t        mcshwr_endX[1];   //[no_mcshowers]
   Double_t        mcshwr_endY[1];   //[no_mcshowers]
   Double_t        mcshwr_endZ[1];   //[no_mcshowers]
   Double_t        mcshwr_CombEngX[1];   //[no_mcshowers]
   Double_t        mcshwr_CombEngY[1];   //[no_mcshowers]
   Double_t        mcshwr_CombEngZ[1];   //[no_mcshowers]
   Double_t        mcshwr_CombEngPx[1];   //[no_mcshowers]
   Double_t        mcshwr_CombEngPy[1];   //[no_mcshowers]
   Double_t        mcshwr_CombEngPz[1];   //[no_mcshowers]
   Double_t        mcshwr_CombEngE[1];   //[no_mcshowers]
   Double_t        mcshwr_dEdx[1];   //[no_mcshowers]
   Double_t        mcshwr_StartDirX[1];   //[no_mcshowers]
   Double_t        mcshwr_StartDirY[1];   //[no_mcshowers]
   Double_t        mcshwr_StartDirZ[1];   //[no_mcshowers]
   Int_t           mcshwr_isEngDeposited[1];   //[no_mcshowers]
   Int_t           mcshwr_Motherpdg[1];   //[no_mcshowers]
   Int_t           mcshwr_MotherTrkId[1];   //[no_mcshowers]
   Int_t           mcshwr_MotherstartX[1];   //[no_mcshowers]
   Int_t           mcshwr_MotherstartY[1];   //[no_mcshowers]
   Int_t           mcshwr_MotherstartZ[1];   //[no_mcshowers]
   Int_t           mcshwr_MotherendX[1];   //[no_mcshowers]
   Int_t           mcshwr_MotherendY[1];   //[no_mcshowers]
   Int_t           mcshwr_MotherendZ[1];   //[no_mcshowers]
   Int_t           mcshwr_Ancestorpdg[1];   //[no_mcshowers]
   Int_t           mcshwr_AncestorTrkId[1];   //[no_mcshowers]
   Int_t           mcshwr_AncestorstartX[1];   //[no_mcshowers]
   Int_t           mcshwr_AncestorstartY[1];   //[no_mcshowers]
   Int_t           mcshwr_AncestorstartZ[1];   //[no_mcshowers]
   Int_t           mcshwr_AncestorendX[1];   //[no_mcshowers]
   Int_t           mcshwr_AncestorendY[1];   //[no_mcshowers]
   Int_t           mcshwr_AncestorendZ[1];   //[no_mcshowers]
   Int_t           nshowers;
   Int_t           shwID[1];   //[nshowers]
   Int_t           BestPlaneShw[1];   //[nshowers]
   Double_t        LengthShw[1];   //[nshowers]
   Double_t        CosStartShw[3][1000];
   Double_t        CosStartXYZShw[3][1000];
   Double_t        TotalEShw[2][1000];
   Double_t        dEdxPerPlaneShw[2][1000];
   Double_t        TotalMIPEShw[2][1000];

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_subrun;   //!
   TBranch        *b_event;   //!
   TBranch        *b_evttime;   //!
   TBranch        *b_efield;   //!
   TBranch        *b_t0;   //!
   TBranch        *b_nclus;   //!
   TBranch        *b_clustertwire;   //!
   TBranch        *b_clusterttick;   //!
   TBranch        *b_cluendwire;   //!
   TBranch        *b_cluendtick;   //!
   TBranch        *b_cluplane;   //!
   TBranch        *b_ntracks_reco;   //!
   TBranch        *b_trkvtxx;   //!
   TBranch        *b_trkvtxy;   //!
   TBranch        *b_trkvtxz;   //!
   TBranch        *b_trkendx;   //!
   TBranch        *b_trkendy;   //!
   TBranch        *b_trkendz;   //!
   TBranch        *b_trkstartdcosx;   //!
   TBranch        *b_trkstartdcosy;   //!
   TBranch        *b_trkstartdcosz;   //!
   TBranch        *b_trkenddcosx;   //!
   TBranch        *b_trkenddcosy;   //!
   TBranch        *b_trkenddcosz;   //!
   TBranch        *b_trkWCtoTPCMatch;   //!
   TBranch        *b_trklength;   //!
   TBranch        *b_trkmomrange;   //!
   TBranch        *b_trkmommschi2;   //!
   TBranch        *b_trkmommsllhd;   //!
   TBranch        *b_ntrkhits;   //!
   TBranch        *b_trkx;   //!
   TBranch        *b_trky;   //!
   TBranch        *b_trkz;   //!
   TBranch        *b_trkpitch;   //!
   TBranch        *b_trkhits;   //!
   TBranch        *b_trkdedx;   //!
   TBranch        *b_trkdqdx;   //!
   TBranch        *b_trkrr;   //!
   TBranch        *b_trkpitchhit;   //!
   TBranch        *b_trkxyz;   //!
   TBranch        *b_trkke;   //!
   TBranch        *b_trkpida;   //!
   TBranch        *b_nTrajPoint;   //!
   TBranch        *b_pHat0_X;   //!
   TBranch        *b_pHat0_Y;   //!
   TBranch        *b_pHat0_Z;   //!
   TBranch        *b_trjPt_X;   //!
   TBranch        *b_trjPt_Y;   //!
   TBranch        *b_trjPt_Z;   //!
   TBranch        *b_trkg4id;   //!
   TBranch        *b_primarytrkkey;   //!
   TBranch        *b_nhits;   //!
   TBranch        *b_hit_plane;   //!
   TBranch        *b_hit_wire;   //!
   TBranch        *b_hit_channel;   //!
   TBranch        *b_hit_peakT;   //!
   TBranch        *b_hit_charge;   //!
   TBranch        *b_hit_ph;   //!
   TBranch        *b_hit_tstart;   //!
   TBranch        *b_hit_tend;   //!
   TBranch        *b_hit_trkid;   //!
   TBranch        *b_hit_trkkey;   //!
   TBranch        *b_hit_clukey;   //!
   TBranch        *b_hit_pk;   //!
   TBranch        *b_hit_t;   //!
   TBranch        *b_hit_ch;   //!
   TBranch        *b_hit_fwhh;   //!
   TBranch        *b_hit_rms;   //!
   TBranch        *b_hit_nelec;   //!
   TBranch        *b_hit_energy;   //!
   TBranch        *b_hit_dQds;   //!
   TBranch        *b_hit_dEds;   //!
   TBranch        *b_hit_ds;   //!
   TBranch        *b_hit_resrange;   //!
   TBranch        *b_hit_x;   //!
   TBranch        *b_hit_y;   //!
   TBranch        *b_hit_z;   //!
   TBranch        *b_nwctrks;   //!
   TBranch        *b_wctrk_XFaceCoor;   //!
   TBranch        *b_wctrk_YFaceCoor;   //!
   TBranch        *b_wctrk_momentum;   //!
   TBranch        *b_wctrk_theta;   //!
   TBranch        *b_wctrk_phi;   //!
   TBranch        *b_wctrk_XDist;   //!
   TBranch        *b_wctrk_YDist;   //!
   TBranch        *b_wctrk_ZDist;   //!
   TBranch        *b_XWireHist;   //!
   TBranch        *b_YWireHist;   //!
   TBranch        *b_XAxisHist;   //!
   TBranch        *b_YAxisHist;   //!
   TBranch        *b_Y_Kink;   //!
   TBranch        *b_WC1xPos;   //!
   TBranch        *b_WC1yPos;   //!
   TBranch        *b_WC1zPos;   //!
   TBranch        *b_WC2xPos;   //!
   TBranch        *b_WC2yPos;   //!
   TBranch        *b_WC2zPos;   //!
   TBranch        *b_WC3xPos;   //!
   TBranch        *b_WC3yPos;   //!
   TBranch        *b_WC3zPos;   //!
   TBranch        *b_WC4xPos;   //!
   TBranch        *b_WC4yPos;   //!
   TBranch        *b_WC4zPos;   //!
   TBranch        *b_ntof;   //!
   TBranch        *b_tofObject;   //!
   TBranch        *b_tof_timestamp;   //!
   TBranch        *b_nAG;   //!
   TBranch        *b_HitTimeStamp1p10_1;   //!
   TBranch        *b_HitTimeStamp1p10_2;   //!
   TBranch        *b_HitTimeStamp1p06_1;   //!
   TBranch        *b_HitTimeStamp1p06_2;   //!
   TBranch        *b_HitPulseArea1p10_1;   //!
   TBranch        *b_HitPulseArea1p10_2;   //!
   TBranch        *b_HitPulseArea1p06_1;   //!
   TBranch        *b_HitPulseArea1p06_2;   //!
   TBranch        *b_HitExist1p10_1;   //!
   TBranch        *b_HitExist1p10_2;   //!
   TBranch        *b_HitExist1p06_1;   //!
   TBranch        *b_HitExist1p06_2;   //!
   TBranch        *b_maxTrackIDE;   //!
   TBranch        *b_IDEEnergy;   //!
   TBranch        *b_IDEPos;   //!
   TBranch        *b_no_primaries;   //!
   TBranch        *b_geant_list_size;   //!
   TBranch        *b_pdg;   //!
   TBranch        *b_Eng;   //!
   TBranch        *b_Px;   //!
   TBranch        *b_Py;   //!
   TBranch        *b_Pz;   //!
   TBranch        *b_EndEng;   //!
   TBranch        *b_EndPx;   //!
   TBranch        *b_EndPy;   //!
   TBranch        *b_EndPz;   //!
   TBranch        *b_StartPointx;   //!
   TBranch        *b_StartPointy;   //!
   TBranch        *b_StartPointz;   //!
   TBranch        *b_EndPointx;   //!
   TBranch        *b_EndPointy;   //!
   TBranch        *b_EndPointz;   //!
   TBranch        *b_Process;   //!
   TBranch        *b_NumberDaughters;   //!
   TBranch        *b_Mother;   //!
   TBranch        *b_TrackId;   //!
   TBranch        *b_process_primary;   //!
   TBranch        *b_G4Process;   //!
   TBranch        *b_G4FinalProcess;   //!
   TBranch        *b_NTrTrajPts;   //!
   TBranch        *b_MidPosX;   //!
   TBranch        *b_MidPosY;   //!
   TBranch        *b_MidPosZ;   //!
   TBranch        *b_MidPx;   //!
   TBranch        *b_MidPy;   //!
   TBranch        *b_MidPz;   //!
   TBranch        *b_InteractionPoint;   //!
   TBranch        *b_InteractionPointType;   //!
   TBranch        *b_no_mcshowers;   //!
   TBranch        *b_mcshwr_origin;   //!
   TBranch        *b_mcshwr_pdg;   //!
   TBranch        *b_mcshwr_TrackId;   //!
   TBranch        *b_mcshwr_startX;   //!
   TBranch        *b_mcshwr_startY;   //!
   TBranch        *b_mcshwr_startZ;   //!
   TBranch        *b_mcshwr_endX;   //!
   TBranch        *b_mcshwr_endY;   //!
   TBranch        *b_mcshwr_endZ;   //!
   TBranch        *b_mcshwr_CombEngX;   //!
   TBranch        *b_mcshwr_CombEngY;   //!
   TBranch        *b_mcshwr_CombEngZ;   //!
   TBranch        *b_mcshwr_CombEngPx;   //!
   TBranch        *b_mcshwr_CombEngPy;   //!
   TBranch        *b_mcshwr_CombEngPz;   //!
   TBranch        *b_mcshwr_CombEngE;   //!
   TBranch        *b_mcshwr_dEdx;   //!
   TBranch        *b_mcshwr_StartDirX;   //!
   TBranch        *b_mcshwr_StartDirY;   //!
   TBranch        *b_mcshwr_StartDirZ;   //!
   TBranch        *b_mcshwr_isEngDeposited;   //!
   TBranch        *b_mcshwr_Motherpdg;   //!
   TBranch        *b_mcshwr_MotherTrkId;   //!
   TBranch        *b_mcshwr_MotherstartX;   //!
   TBranch        *b_mcshwr_MotherstartY;   //!
   TBranch        *b_mcshwr_MotherstartZ;   //!
   TBranch        *b_mcshwr_MotherendX;   //!
   TBranch        *b_mcshwr_MotherendY;   //!
   TBranch        *b_mcshwr_MotherendZ;   //!
   TBranch        *b_mcshwr_Ancestorpdg;   //!
   TBranch        *b_mcshwr_AncestorTrkId;   //!
   TBranch        *b_mcshwr_AncestorstartX;   //!
   TBranch        *b_mcshwr_AncestorstartY;   //!
   TBranch        *b_mcshwr_AncestorstartZ;   //!
   TBranch        *b_mcshwr_AncestorendX;   //!
   TBranch        *b_mcshwr_AncestorendY;   //!
   TBranch        *b_mcshwr_AncestorendZ;   //!
   TBranch        *b_nshowers;   //!
   TBranch        *b_shwID;   //!
   TBranch        *b_BestPlaneShw;   //!
   TBranch        *b_LengthShw;   //!
   TBranch        *b_CosStartShw;   //!
   TBranch        *b_CosStartXYZShw;   //!
   TBranch        *b_TotalEShw;   //!
   TBranch        *b_dEdxPerPlaneShw;   //!
   TBranch        *b_TotalMIPEShw;   //!

   RunI_PosPol_ThroughGoingTrack(TTree *tree=0);
   virtual ~RunI_PosPol_ThroughGoingTrack();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef RunI_PosPol_ThroughGoingTrack_cxx
RunI_PosPol_ThroughGoingTrack::RunI_PosPol_ThroughGoingTrack(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("../ROOTFILES/RunIPosPol_AnaTree_06_15_00.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("../ROOTFILES/RunIPosPol_AnaTree_06_15_00.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("../ROOTFILES/RunIPosPol_AnaTree_06_15_00.root:/anatree");
      dir->GetObject("anatree",tree);

   }
   Init(tree);
}

RunI_PosPol_ThroughGoingTrack::~RunI_PosPol_ThroughGoingTrack()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t RunI_PosPol_ThroughGoingTrack::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t RunI_PosPol_ThroughGoingTrack::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void RunI_PosPol_ThroughGoingTrack::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   G4Process = 0;
   G4FinalProcess = 0;
   InteractionPoint = 0;
   InteractionPointType = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("subrun", &subrun, &b_subrun);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("evttime", &evttime, &b_evttime);
   fChain->SetBranchAddress("efield", efield, &b_efield);
   fChain->SetBranchAddress("t0", &t0, &b_t0);
   fChain->SetBranchAddress("nclus", &nclus, &b_nclus);
   fChain->SetBranchAddress("clustertwire", clustertwire, &b_clustertwire);
   fChain->SetBranchAddress("clusterttick", clusterttick, &b_clusterttick);
   fChain->SetBranchAddress("cluendwire", cluendwire, &b_cluendwire);
   fChain->SetBranchAddress("cluendtick", cluendtick, &b_cluendtick);
   fChain->SetBranchAddress("cluplane", cluplane, &b_cluplane);
   fChain->SetBranchAddress("ntracks_reco", &ntracks_reco, &b_ntracks_reco);
   fChain->SetBranchAddress("trkvtxx", trkvtxx, &b_trkvtxx);
   fChain->SetBranchAddress("trkvtxy", trkvtxy, &b_trkvtxy);
   fChain->SetBranchAddress("trkvtxz", trkvtxz, &b_trkvtxz);
   fChain->SetBranchAddress("trkendx", trkendx, &b_trkendx);
   fChain->SetBranchAddress("trkendy", trkendy, &b_trkendy);
   fChain->SetBranchAddress("trkendz", trkendz, &b_trkendz);
   fChain->SetBranchAddress("trkstartdcosx", trkstartdcosx, &b_trkstartdcosx);
   fChain->SetBranchAddress("trkstartdcosy", trkstartdcosy, &b_trkstartdcosy);
   fChain->SetBranchAddress("trkstartdcosz", trkstartdcosz, &b_trkstartdcosz);
   fChain->SetBranchAddress("trkenddcosx", trkenddcosx, &b_trkenddcosx);
   fChain->SetBranchAddress("trkenddcosy", trkenddcosy, &b_trkenddcosy);
   fChain->SetBranchAddress("trkenddcosz", trkenddcosz, &b_trkenddcosz);
   fChain->SetBranchAddress("trkWCtoTPCMatch", trkWCtoTPCMatch, &b_trkWCtoTPCMatch);
   fChain->SetBranchAddress("trklength", trklength, &b_trklength);
   fChain->SetBranchAddress("trkmomrange", trkmomrange, &b_trkmomrange);
   fChain->SetBranchAddress("trkmommschi2", trkmommschi2, &b_trkmommschi2);
   fChain->SetBranchAddress("trkmommsllhd", trkmommsllhd, &b_trkmommsllhd);
   fChain->SetBranchAddress("ntrkhits", ntrkhits, &b_ntrkhits);
   fChain->SetBranchAddress("trkx", trkx, &b_trkx);
   fChain->SetBranchAddress("trky", trky, &b_trky);
   fChain->SetBranchAddress("trkz", trkz, &b_trkz);
   fChain->SetBranchAddress("trkpitch", trkpitch, &b_trkpitch);
   fChain->SetBranchAddress("trkhits", trkhits, &b_trkhits);
   fChain->SetBranchAddress("trkdedx", trkdedx, &b_trkdedx);
   fChain->SetBranchAddress("trkdqdx", trkdqdx, &b_trkdqdx);
   fChain->SetBranchAddress("trkrr", trkrr, &b_trkrr);
   fChain->SetBranchAddress("trkpitchhit", trkpitchhit, &b_trkpitchhit);
   fChain->SetBranchAddress("trkxyz", trkxyz, &b_trkxyz);
   fChain->SetBranchAddress("trkke", trkke, &b_trkke);
   fChain->SetBranchAddress("trkpida", trkpida, &b_trkpida);
   fChain->SetBranchAddress("nTrajPoint", nTrajPoint, &b_nTrajPoint);
   fChain->SetBranchAddress("pHat0_X", pHat0_X, &b_pHat0_X);
   fChain->SetBranchAddress("pHat0_Y", pHat0_Y, &b_pHat0_Y);
   fChain->SetBranchAddress("pHat0_Z", pHat0_Z, &b_pHat0_Z);
   fChain->SetBranchAddress("trjPt_X", trjPt_X, &b_trjPt_X);
   fChain->SetBranchAddress("trjPt_Y", trjPt_Y, &b_trjPt_Y);
   fChain->SetBranchAddress("trjPt_Z", trjPt_Z, &b_trjPt_Z);
   fChain->SetBranchAddress("trkg4id", trkg4id, &b_trkg4id);
   fChain->SetBranchAddress("primarytrkkey", &primarytrkkey, &b_primarytrkkey);
   fChain->SetBranchAddress("nhits", &nhits, &b_nhits);
   fChain->SetBranchAddress("hit_plane", hit_plane, &b_hit_plane);
   fChain->SetBranchAddress("hit_wire", hit_wire, &b_hit_wire);
   fChain->SetBranchAddress("hit_channel", hit_channel, &b_hit_channel);
   fChain->SetBranchAddress("hit_peakT", hit_peakT, &b_hit_peakT);
   fChain->SetBranchAddress("hit_charge", hit_charge, &b_hit_charge);
   fChain->SetBranchAddress("hit_ph", hit_ph, &b_hit_ph);
   fChain->SetBranchAddress("hit_tstart", hit_tstart, &b_hit_tstart);
   fChain->SetBranchAddress("hit_tend", hit_tend, &b_hit_tend);
   fChain->SetBranchAddress("hit_trkid", hit_trkid, &b_hit_trkid);
   fChain->SetBranchAddress("hit_trkkey", hit_trkkey, &b_hit_trkkey);
   fChain->SetBranchAddress("hit_clukey", hit_clukey, &b_hit_clukey);
   fChain->SetBranchAddress("hit_pk", hit_pk, &b_hit_pk);
   fChain->SetBranchAddress("hit_t", hit_t, &b_hit_t);
   fChain->SetBranchAddress("hit_ch", hit_ch, &b_hit_ch);
   fChain->SetBranchAddress("hit_fwhh", hit_fwhh, &b_hit_fwhh);
   fChain->SetBranchAddress("hit_rms", hit_rms, &b_hit_rms);
   fChain->SetBranchAddress("hit_nelec", hit_nelec, &b_hit_nelec);
   fChain->SetBranchAddress("hit_energy", hit_energy, &b_hit_energy);
   fChain->SetBranchAddress("hit_dQds", hit_dQds, &b_hit_dQds);
   fChain->SetBranchAddress("hit_dEds", hit_dEds, &b_hit_dEds);
   fChain->SetBranchAddress("hit_ds", hit_ds, &b_hit_ds);
   fChain->SetBranchAddress("hit_resrange", hit_resrange, &b_hit_resrange);
   fChain->SetBranchAddress("hit_x", hit_x, &b_hit_x);
   fChain->SetBranchAddress("hit_y", hit_y, &b_hit_y);
   fChain->SetBranchAddress("hit_z", hit_z, &b_hit_z);
   fChain->SetBranchAddress("nwctrks", &nwctrks, &b_nwctrks);
   fChain->SetBranchAddress("wctrk_XFaceCoor", wctrk_XFaceCoor, &b_wctrk_XFaceCoor);
   fChain->SetBranchAddress("wctrk_YFaceCoor", wctrk_YFaceCoor, &b_wctrk_YFaceCoor);
   fChain->SetBranchAddress("wctrk_momentum", wctrk_momentum, &b_wctrk_momentum);
   fChain->SetBranchAddress("wctrk_theta", wctrk_theta, &b_wctrk_theta);
   fChain->SetBranchAddress("wctrk_phi", wctrk_phi, &b_wctrk_phi);
   fChain->SetBranchAddress("wctrk_XDist", wctrk_XDist, &b_wctrk_XDist);
   fChain->SetBranchAddress("wctrk_YDist", wctrk_YDist, &b_wctrk_YDist);
   fChain->SetBranchAddress("wctrk_ZDist", wctrk_ZDist, &b_wctrk_ZDist);
   fChain->SetBranchAddress("XWireHist", XWireHist, &b_XWireHist);
   fChain->SetBranchAddress("YWireHist", YWireHist, &b_YWireHist);
   fChain->SetBranchAddress("XAxisHist", XAxisHist, &b_XAxisHist);
   fChain->SetBranchAddress("YAxisHist", YAxisHist, &b_YAxisHist);
   fChain->SetBranchAddress("Y_Kink", Y_Kink, &b_Y_Kink);
   fChain->SetBranchAddress("WC1xPos", WC1xPos, &b_WC1xPos);
   fChain->SetBranchAddress("WC1yPos", WC1yPos, &b_WC1yPos);
   fChain->SetBranchAddress("WC1zPos", WC1zPos, &b_WC1zPos);
   fChain->SetBranchAddress("WC2xPos", WC2xPos, &b_WC2xPos);
   fChain->SetBranchAddress("WC2yPos", WC2yPos, &b_WC2yPos);
   fChain->SetBranchAddress("WC2zPos", WC2zPos, &b_WC2zPos);
   fChain->SetBranchAddress("WC3xPos", WC3xPos, &b_WC3xPos);
   fChain->SetBranchAddress("WC3yPos", WC3yPos, &b_WC3yPos);
   fChain->SetBranchAddress("WC3zPos", WC3zPos, &b_WC3zPos);
   fChain->SetBranchAddress("WC4xPos", WC4xPos, &b_WC4xPos);
   fChain->SetBranchAddress("WC4yPos", WC4yPos, &b_WC4yPos);
   fChain->SetBranchAddress("WC4zPos", WC4zPos, &b_WC4zPos);
   fChain->SetBranchAddress("ntof", &ntof, &b_ntof);
   fChain->SetBranchAddress("tofObject", tofObject, &b_tofObject);
   fChain->SetBranchAddress("tof_timestamp", tof_timestamp, &b_tof_timestamp);
   fChain->SetBranchAddress("nAG", &nAG, &b_nAG);
   fChain->SetBranchAddress("HitTimeStamp1p10_1", HitTimeStamp1p10_1, &b_HitTimeStamp1p10_1);
   fChain->SetBranchAddress("HitTimeStamp1p10_2", HitTimeStamp1p10_2, &b_HitTimeStamp1p10_2);
   fChain->SetBranchAddress("HitTimeStamp1p06_1", HitTimeStamp1p06_1, &b_HitTimeStamp1p06_1);
   fChain->SetBranchAddress("HitTimeStamp1p06_2", HitTimeStamp1p06_2, &b_HitTimeStamp1p06_2);
   fChain->SetBranchAddress("HitPulseArea1p10_1", HitPulseArea1p10_1, &b_HitPulseArea1p10_1);
   fChain->SetBranchAddress("HitPulseArea1p10_2", HitPulseArea1p10_2, &b_HitPulseArea1p10_2);
   fChain->SetBranchAddress("HitPulseArea1p06_1", HitPulseArea1p06_1, &b_HitPulseArea1p06_1);
   fChain->SetBranchAddress("HitPulseArea1p06_2", HitPulseArea1p06_2, &b_HitPulseArea1p06_2);
   fChain->SetBranchAddress("HitExist1p10_1", HitExist1p10_1, &b_HitExist1p10_1);
   fChain->SetBranchAddress("HitExist1p10_2", HitExist1p10_2, &b_HitExist1p10_2);
   fChain->SetBranchAddress("HitExist1p06_1", HitExist1p06_1, &b_HitExist1p06_1);
   fChain->SetBranchAddress("HitExist1p06_2", HitExist1p06_2, &b_HitExist1p06_2);
   fChain->SetBranchAddress("maxTrackIDE", &maxTrackIDE, &b_maxTrackIDE);
   fChain->SetBranchAddress("IDEEnergy", &IDEEnergy, &b_IDEEnergy);
   fChain->SetBranchAddress("IDEPos", &IDEPos, &b_IDEPos);
   fChain->SetBranchAddress("no_primaries", &no_primaries, &b_no_primaries);
   fChain->SetBranchAddress("geant_list_size", &geant_list_size, &b_geant_list_size);
   fChain->SetBranchAddress("pdg", &pdg, &b_pdg);
   fChain->SetBranchAddress("Eng", &Eng, &b_Eng);
   fChain->SetBranchAddress("Px", &Px, &b_Px);
   fChain->SetBranchAddress("Py", &Py, &b_Py);
   fChain->SetBranchAddress("Pz", &Pz, &b_Pz);
   fChain->SetBranchAddress("EndEng", &EndEng, &b_EndEng);
   fChain->SetBranchAddress("EndPx", &EndPx, &b_EndPx);
   fChain->SetBranchAddress("EndPy", &EndPy, &b_EndPy);
   fChain->SetBranchAddress("EndPz", &EndPz, &b_EndPz);
   fChain->SetBranchAddress("StartPointx", &StartPointx, &b_StartPointx);
   fChain->SetBranchAddress("StartPointy", &StartPointy, &b_StartPointy);
   fChain->SetBranchAddress("StartPointz", &StartPointz, &b_StartPointz);
   fChain->SetBranchAddress("EndPointx", &EndPointx, &b_EndPointx);
   fChain->SetBranchAddress("EndPointy", &EndPointy, &b_EndPointy);
   fChain->SetBranchAddress("EndPointz", &EndPointz, &b_EndPointz);
   fChain->SetBranchAddress("Process", &Process, &b_Process);
   fChain->SetBranchAddress("NumberDaughters", &NumberDaughters, &b_NumberDaughters);
   fChain->SetBranchAddress("Mother", &Mother, &b_Mother);
   fChain->SetBranchAddress("TrackId", &TrackId, &b_TrackId);
   fChain->SetBranchAddress("process_primary", &process_primary, &b_process_primary);
   fChain->SetBranchAddress("G4Process", &G4Process, &b_G4Process);
   fChain->SetBranchAddress("G4FinalProcess", &G4FinalProcess, &b_G4FinalProcess);
   fChain->SetBranchAddress("NTrTrajPts", &NTrTrajPts, &b_NTrTrajPts);
   fChain->SetBranchAddress("MidPosX", &MidPosX, &b_MidPosX);
   fChain->SetBranchAddress("MidPosY", &MidPosY, &b_MidPosY);
   fChain->SetBranchAddress("MidPosZ", &MidPosZ, &b_MidPosZ);
   fChain->SetBranchAddress("MidPx", &MidPx, &b_MidPx);
   fChain->SetBranchAddress("MidPy", &MidPy, &b_MidPy);
   fChain->SetBranchAddress("MidPz", &MidPz, &b_MidPz);
   fChain->SetBranchAddress("InteractionPoint", &InteractionPoint, &b_InteractionPoint);
   fChain->SetBranchAddress("InteractionPointType", &InteractionPointType, &b_InteractionPointType);
   fChain->SetBranchAddress("no_mcshowers", &no_mcshowers, &b_no_mcshowers);
   fChain->SetBranchAddress("mcshwr_origin", &mcshwr_origin, &b_mcshwr_origin);
   fChain->SetBranchAddress("mcshwr_pdg", &mcshwr_pdg, &b_mcshwr_pdg);
   fChain->SetBranchAddress("mcshwr_TrackId", &mcshwr_TrackId, &b_mcshwr_TrackId);
   fChain->SetBranchAddress("mcshwr_startX", &mcshwr_startX, &b_mcshwr_startX);
   fChain->SetBranchAddress("mcshwr_startY", &mcshwr_startY, &b_mcshwr_startY);
   fChain->SetBranchAddress("mcshwr_startZ", &mcshwr_startZ, &b_mcshwr_startZ);
   fChain->SetBranchAddress("mcshwr_endX", &mcshwr_endX, &b_mcshwr_endX);
   fChain->SetBranchAddress("mcshwr_endY", &mcshwr_endY, &b_mcshwr_endY);
   fChain->SetBranchAddress("mcshwr_endZ", &mcshwr_endZ, &b_mcshwr_endZ);
   fChain->SetBranchAddress("mcshwr_CombEngX", &mcshwr_CombEngX, &b_mcshwr_CombEngX);
   fChain->SetBranchAddress("mcshwr_CombEngY", &mcshwr_CombEngY, &b_mcshwr_CombEngY);
   fChain->SetBranchAddress("mcshwr_CombEngZ", &mcshwr_CombEngZ, &b_mcshwr_CombEngZ);
   fChain->SetBranchAddress("mcshwr_CombEngPx", &mcshwr_CombEngPx, &b_mcshwr_CombEngPx);
   fChain->SetBranchAddress("mcshwr_CombEngPy", &mcshwr_CombEngPy, &b_mcshwr_CombEngPy);
   fChain->SetBranchAddress("mcshwr_CombEngPz", &mcshwr_CombEngPz, &b_mcshwr_CombEngPz);
   fChain->SetBranchAddress("mcshwr_CombEngE", &mcshwr_CombEngE, &b_mcshwr_CombEngE);
   fChain->SetBranchAddress("mcshwr_dEdx", &mcshwr_dEdx, &b_mcshwr_dEdx);
   fChain->SetBranchAddress("mcshwr_StartDirX", &mcshwr_StartDirX, &b_mcshwr_StartDirX);
   fChain->SetBranchAddress("mcshwr_StartDirY", &mcshwr_StartDirY, &b_mcshwr_StartDirY);
   fChain->SetBranchAddress("mcshwr_StartDirZ", &mcshwr_StartDirZ, &b_mcshwr_StartDirZ);
   fChain->SetBranchAddress("mcshwr_isEngDeposited", &mcshwr_isEngDeposited, &b_mcshwr_isEngDeposited);
   fChain->SetBranchAddress("mcshwr_Motherpdg", &mcshwr_Motherpdg, &b_mcshwr_Motherpdg);
   fChain->SetBranchAddress("mcshwr_MotherTrkId", &mcshwr_MotherTrkId, &b_mcshwr_MotherTrkId);
   fChain->SetBranchAddress("mcshwr_MotherstartX", &mcshwr_MotherstartX, &b_mcshwr_MotherstartX);
   fChain->SetBranchAddress("mcshwr_MotherstartY", &mcshwr_MotherstartY, &b_mcshwr_MotherstartY);
   fChain->SetBranchAddress("mcshwr_MotherstartZ", &mcshwr_MotherstartZ, &b_mcshwr_MotherstartZ);
   fChain->SetBranchAddress("mcshwr_MotherendX", &mcshwr_MotherendX, &b_mcshwr_MotherendX);
   fChain->SetBranchAddress("mcshwr_MotherendY", &mcshwr_MotherendY, &b_mcshwr_MotherendY);
   fChain->SetBranchAddress("mcshwr_MotherendZ", &mcshwr_MotherendZ, &b_mcshwr_MotherendZ);
   fChain->SetBranchAddress("mcshwr_Ancestorpdg", &mcshwr_Ancestorpdg, &b_mcshwr_Ancestorpdg);
   fChain->SetBranchAddress("mcshwr_AncestorTrkId", &mcshwr_AncestorTrkId, &b_mcshwr_AncestorTrkId);
   fChain->SetBranchAddress("mcshwr_AncestorstartX", &mcshwr_AncestorstartX, &b_mcshwr_AncestorstartX);
   fChain->SetBranchAddress("mcshwr_AncestorstartY", &mcshwr_AncestorstartY, &b_mcshwr_AncestorstartY);
   fChain->SetBranchAddress("mcshwr_AncestorstartZ", &mcshwr_AncestorstartZ, &b_mcshwr_AncestorstartZ);
   fChain->SetBranchAddress("mcshwr_AncestorendX", &mcshwr_AncestorendX, &b_mcshwr_AncestorendX);
   fChain->SetBranchAddress("mcshwr_AncestorendY", &mcshwr_AncestorendY, &b_mcshwr_AncestorendY);
   fChain->SetBranchAddress("mcshwr_AncestorendZ", &mcshwr_AncestorendZ, &b_mcshwr_AncestorendZ);
   fChain->SetBranchAddress("nshowers", &nshowers, &b_nshowers);
   fChain->SetBranchAddress("shwID", &shwID, &b_shwID);
   fChain->SetBranchAddress("BestPlaneShw", &BestPlaneShw, &b_BestPlaneShw);
   fChain->SetBranchAddress("LengthShw", &LengthShw, &b_LengthShw);
   fChain->SetBranchAddress("CosStartShw", CosStartShw, &b_CosStartShw);
   fChain->SetBranchAddress("CosStartXYZShw", CosStartXYZShw, &b_CosStartXYZShw);
   fChain->SetBranchAddress("TotalEShw", TotalEShw, &b_TotalEShw);
   fChain->SetBranchAddress("dEdxPerPlaneShw", dEdxPerPlaneShw, &b_dEdxPerPlaneShw);
   fChain->SetBranchAddress("TotalMIPEShw", TotalMIPEShw, &b_TotalMIPEShw);
   Notify();
}

Bool_t RunI_PosPol_ThroughGoingTrack::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void RunI_PosPol_ThroughGoingTrack::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t RunI_PosPol_ThroughGoingTrack::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef RunI_PosPol_ThroughGoingTrack_cxx
