{
#include<TH2.h>


// #####################################
// ### Load Proton Monte Carlo Plots ###
// #####################################
TFile *f1 = new TFile("./DataDrivenProtonMC_EnergyCalibrationPlots.root");


// ### Scaling the highest count bin in data (740-750) ###


//--------------------------------------------------------------------------------------------------------------
//						Top Portion of TPC
//--------------------------------------------------------------------------------------------------------------

// ########################
// ### Making a TCanvas ###
// ########################

/*
// ### Get the Beam Profile Plot ###
TH1F *hMCELossTop = (TH1F*)f1->Get("hPhivsThetaELossDividedTop");


std::cout<<"      if(FirstPoint_Y > 5 && FirstPoint_Y < 15)"<<std::endl;
std::cout<<"         {"<<std::endl;

// ### Read out each bins scale factor ###
for(int nXbins = 1; nXbins < hMCELossTop.GetNbinsX(); nXbins++)
   {
   
   for(int nYbins = 1; nYbins < hMCELossTop.GetNbinsY(); nYbins++)
      {
      
      std::cout<<"         if(PhiInDegrees > "<<(nXbins - 1)*5<<" && PhiInDegrees < "<<nXbins * 5<< "&& ThetaInDegrees > "<<(nYbins - 1)*5<<" && ThetaInDegrees < "<<nYbins*5<<")"<<std::endl;
      std::cout<<"            {"<<std::endl;
      
      float Energy = hMCELossTop.GetBinContent(nXbins, nYbins);
      
      if(hMCELossTop.GetBinContent(nXbins, nYbins) == 0){Energy = 66.4;}
      
      std::cout<<"            EnergyLossFromMap = "<<Energy<<";"<<std::endl;
      
      std::cout<<"            }"<<std::endl;
      
      //std::cout<<"Phi = "<<nXbins * 5<<", Theta = "<<nYbins*5<<", Eloss = "<<hMCELossTop.GetBinContent(nXbins, nYbins)<<std::endl;
      
      //std::cout<<"nbins = "<<hMCELossTop.GetBinContent(nXbins, nYbins)<<std::endl;
      
      
      
      }//<---End nYbins

   }//<---End nXbins

std::cout<<"         }"<<std::endl;

*/




//--------------------------------------------------------------------------------------------------------------
//						Mid Portion of TPC
//--------------------------------------------------------------------------------------------------------------

/*

// ### Get the Beam Profile Plot ###
TH1F *hMCELossMid = (TH1F*)f1->Get("hPhivsThetaELossDividedMid");


std::cout<<"      if(FirstPoint_Y > -5 && FirstPoint_Y < 5)"<<std::endl;
std::cout<<"         {"<<std::endl;

// ### Read out each bins scale factor ###
for(int nXbins = 1; nXbins < hMCELossMid.GetNbinsX(); nXbins++)
   {
   
   for(int nYbins = 1; nYbins < hMCELossMid.GetNbinsY(); nYbins++)
      {
      
      std::cout<<"         if(PhiInDegrees > "<<(nXbins - 1)*5<<" && PhiInDegrees < "<<nXbins * 5<< "&& ThetaInDegrees > "<<(nYbins - 1)*5<<" && ThetaInDegrees < "<<nYbins*5<<")"<<std::endl;
      std::cout<<"            {"<<std::endl;
      
      float Energy = hMCELossMid.GetBinContent(nXbins, nYbins);
      
      if(hMCELossMid.GetBinContent(nXbins, nYbins) == 0){Energy = 66.4;}
      
      std::cout<<"            EnergyLossFromMap = "<<Energy<<";"<<std::endl;
      
      std::cout<<"            }"<<std::endl;
      
      //std::cout<<"Phi = "<<nXbins * 5<<", Theta = "<<nYbins*5<<", Eloss = "<<hMCELossTop.GetBinContent(nXbins, nYbins)<<std::endl;
      
      //std::cout<<"nbins = "<<hMCELossTop.GetBinContent(nXbins, nYbins)<<std::endl;
      
      
      
      }//<---End nYbins

   }//<---End nXbins

std::cout<<"         }"<<std::endl;

*/



//--------------------------------------------------------------------------------------------------------------
//						Bottom Portion of TPC
//--------------------------------------------------------------------------------------------------------------

// ### Get the Beam Profile Plot ###
TH1F *hMCELossBottom = (TH1F*)f1->Get("hPhivsThetaELossDividedBottom");


std::cout<<"      if(FirstPoint_Y > -55 && FirstPoint_Y < -5)"<<std::endl;
std::cout<<"         {"<<std::endl;

// ### Read out each bins scale factor ###
for(int nXbins = 1; nXbins < hMCELossBottom.GetNbinsX(); nXbins++)
   {
   
   for(int nYbins = 1; nYbins < hMCELossBottom.GetNbinsY(); nYbins++)
      {
      
      std::cout<<"         if(PhiInDegrees > "<<(nXbins - 1)*5<<" && PhiInDegrees < "<<nXbins * 5<< "&& ThetaInDegrees > "<<(nYbins - 1)*5<<" && ThetaInDegrees < "<<nYbins*5<<")"<<std::endl;
      std::cout<<"            {"<<std::endl;
      
      float Energy = hMCELossBottom.GetBinContent(nXbins, nYbins);
      
      if(hMCELossBottom.GetBinContent(nXbins, nYbins) == 0){Energy = 66.4;}
      
      std::cout<<"            EnergyLossFromMap = "<<Energy<<";"<<std::endl;
      
      std::cout<<"            }"<<std::endl;
      
      //std::cout<<"Phi = "<<nXbins * 5<<", Theta = "<<nYbins*5<<", Eloss = "<<hMCELossTop.GetBinContent(nXbins, nYbins)<<std::endl;
      
      //std::cout<<"nbins = "<<hMCELossTop.GetBinContent(nXbins, nYbins)<<std::endl;
      
      
      
      }//<---End nYbins

   }//<---End nXbins

std::cout<<"         }"<<std::endl;



}//<---End File


