{

// ############################
// ### Constants ###
// ############################
float rho = 1400; //Argon density in kg/m^3
float molar_mass = 39.9; //g/mol
float g_per_kg = 1000; 
float avogadro = 6.02e+23; //number/mol
float number_density = rho*g_per_kg/molar_mass*avogadro;
float slab_width = 0.0045;//in m (from mean of track pitch)


// ############################
// ### Load Data Plots      ###
// ############################
TFile *f1 = new TFile("../histoROOTfiles_forPlots/RunINegPolData_histos_noCorrections_PionXSectionSample.root");

 TH1F* hDataInc = (TH1F*)f1->Get("hdataIncidentKE");
 TH1F* hDataInt = (TH1F*)f1->Get("hdataInteractingKE");
 TH1F* DataCrossSection = (TH1F*)f1->Get("fCrossSection");
 
 // ########################################################
 // ###      Scaling factor for through going muon       ###
 // ### Note: If you have a 10% contamination than your  ###
 // ###            scale factor should be 0.90           ###
 // ########################################################
 double MuonContaminationScaleFactor = 0.90;
    
 // ===============================================================================================================
 // 					SCALING FOR THE MUON CONTAMINATION
 // ==========================================================================================================
    
 hDataInc->Scale(MuonContaminationScaleFactor);

 //Binomial error calculation, data
 int nbins = hDataInc->GetNbinsX();
 float datasigbinom;
 float datan;
 float dataN;
 float datap;
 float TempCrossSection;
 float crossSection;

 std::cout << "Data cross section" << std::endl;

 for (int i = 1; i <= nbins; i++ ) {
   datan = hDataInt->GetBinContent(i);
   dataN = hDataInc->GetBinContent(i);

   if( dataN == 0 )continue; //Temporary fix to ensure no divide by zero
   // ### Cross-section = (Interacting Bins / Incident Bins) / (Density) / (slab width) ###
   TempCrossSection = (datan/dataN)/(number_density)/(slab_width);
   
   crossSection = TempCrossSection * (1e28); //To put this into barns
   DataCrossSection->SetBinContent(i,crossSection);

   datasigbinom = sqrt(datan/(dataN*dataN)*(1-datan/dataN));
   datasigbinom = datasigbinom/number_density/slab_width*1e28; //data binomial stat error in barns

   DataCrossSection->SetBinError(i,datasigbinom);
   std::cout << crossSection << " +/- " << datasigbinom << std::endl;

 }//End loop over nbins

 
 
// ############################
// ### Load MC Plots        ###
// ############################
TFile *f2 = new TFile("../histoROOTfiles_forPlots/PionMC_RunI_OutOfTheBox.root");
 
 TH1F* hMCInc = (TH1F*)f2->Get("hRecoMCIncidentKEunweighted");
 TH1F* hMCInt = (TH1F*)f2->Get("hRecoMCInteractingKEunweighted");
 TH1F* MCCrossSection = (TH1F*)f2->Get("fCrossSection");
 TH1F* MCCrossSys = (TH1F*)fCrossSection->Clone();
 MCCrossSys->SetName("MCCrossSys");

 
 int nbinsMC = fCrossSection->GetNbinsX();
 float MCsigbinom;
 float MCsysstat;
 float MCn;
 float MCN;
 float MCp;
 
 //Systematic errors taken from Jonathan's slide
 float dEdxuncert = 0.05;
 float dEdxuncertsq = dEdxuncert*dEdxuncert;
 float mucontam = 0.03;
 float mucontamsq = mucontam*mucontam;
 float WCmomuncert = 0.03;
 float WCmomuncertsq = WCmomuncert*WCmomuncert;
 float Eflatuncert = 0.035;
 float Eflatuncertsq = Eflatuncert*Eflatuncert;

 //MC statistical error should be flat (before momentum reweighting)
 //Take peak value of hMCInc histo as proxy for real MC stats
 //In truth, should use the unweighted MC histo to get stat err instead
 double MCstat = hMCInt->GetBinContent(8);
 std::cout << MCstat << std::endl;
 MCstat = (sqrt(MCstat))/MCstat;
 std::cout << MCstat << std::endl;

 std::cout << "MC cross section" << std::endl;

 for (int i = 1; i <= nbinsMC; i++ ) {
   MCn = hMCInt->GetBinContent(i); 
   MCN = hMCInc->GetBinContent(i);
   MCsigbinom = sqrt((MCn/(MCN*MCN))*(1-(MCn/MCN)));

   if( MCN == 0 )continue; //Temporary fix to ensure no divide by zero 
   // ### Cross-section = (Interacting Bins / Incident Bins) / (Density) / (slab width) ###
   TempCrossSection = (MCn/MCN)/(number_density)/(slab_width);
   
   crossSection = TempCrossSection * (1e28); //To put this into barns
   MCCrossSection->SetBinContent(i,crossSection);

   MCsigbinom = sqrt(MCn/(MCN*MCN)*(1-MCn/MCN));
   MCsigbinom = MCsigbinom/number_density/slab_width*1e28; //MC binomial stat error in barns
//
//   MCCrossSection->SetBinError(i,MCsigbinom);
   MCCrossSection->SetBinError(i, MCstat*crossSection); // use flat stat uncertainty


   MCsysstat = dEdxuncertsq + mucontamsq + WCmomuncertsq + Eflatuncertsq; //sum of squares of syserrs
   //   MCsysstat = MCsysstat + MCsigbinom*MCsigbinom; // Add in MC stat err squared
   MCsysstat = MCsysstat*crossSection;
   MCsysstat = MCsysstat + MCstat*MCstat;
   MCsysstat = sqrt(MCsysstat); // sqrt of sum of squares = total err

   std::cout << crossSection << " +/- " << MCstat*crossSection << "(stat) +/- " << MCsysstat << std::endl;


   MCCrossSys->SetBinContent(i,crossSection);
   MCCrossSys->SetBinError(i,MCsysstat);   
 }// end loop over MC bins

// ###############################
// ### Draw the majestic plots ###
// ###############################

 MCCrossSys->SetFillColor(kAzure-5);
 MCCrossSys->SetLineColor(kAzure-5);
 MCCrossSys->SetMarkerStyle(1);
 MCCrossSys->SetMarkerColor(kAzure-5);
 MCCrossSys->SetTitle("");
 MCCrossSys->GetXaxis()->SetTitle("Reconstructed Kinetic Energy (MeV)");
 MCCrossSys->GetXaxis()->SetTitleFont(42);
 MCCrossSys->GetXaxis()->SetTitleSize(0.04);
 MCCrossSys->GetXaxis()->CenterTitle(kFALSE);
 MCCrossSys->GetYaxis()->SetTitle("Total #pi^{#minus} cross section, #sigma_{TOT} (barns)");
 MCCrossSys->GetYaxis()->CenterTitle(kFALSE);
 MCCrossSys->GetYaxis()->SetTitleFont(42);
 MCCrossSys->GetYaxis()->SetTitleSize(0.04);

 MCCrossSection->SetTitle("");
 MCCrossSection->SetFillColor(kAzure-9);
 MCCrossSection->SetLineColor(kAzure-9);
 MCCrossSection->SetMarkerStyle(1);
 MCCrossSection->SetMarkerColor(kAzure-9);
 MCCrossSection->GetXaxis()->SetTitle("");
 MCCrossSection->GetYaxis()->SetTitle("");

 DataCrossSection->SetMarkerStyle(8);
 DataCrossSection->SetMarkerSize(0.75);
 DataCrossSection->SetMarkerColor(kBlack);
 DataCrossSection->SetLineColor(kBlack);
 DataCrossSection->SetLineWidth(2);
 DataCrossSection->SetTitle("");
 DataCrossSection->GetXaxis()->SetTitle("");
 DataCrossSection->GetYaxis()->SetTitle("");

 //Drawing option 1
// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c01 = new TCanvas("c01", "Track Length");
c01->SetTicks();
c01->SetFillColor(kWhite);
c01->cd();
 gStyle->SetOptStat(0);

 MCCrossSys->SetAxisRange(0,1200.);
 MCCrossSys->SetMaximum(3.5);
 MCCrossSys->SetMinimum(0);
 MCCrossSys->Draw("e2");
 MCCrossSection->Draw("e2same");
 DataCrossSection->Draw("e1same");

 TLegend *leg = new TLegend(0.6,0.6,0.85,0.85);
 gStyle->SetLegendFont(62);
 leg->SetFillColor(0);
 leg->SetBorderSize(0);
 leg->SetTextSize(0.04);
 leg->SetTextFont(42);
 leg->AddEntry(MCCrossSys,"MC syst + stat","f");
 leg->AddEntry(MCCrossSection,"MC stat only","f");
 leg->AddEntry(DataCrossSection, "Run-1 data, stat","ep");
 leg->Draw();

// ############################
// # Setting the Latex Header #
// ############################
TLatex *prelim = new TLatex();
prelim->SetNDC();
prelim->SetTextFont(62);
prelim->SetTextSize(0.04);
prelim->SetTextAlign(40);
prelim->DrawLatex(0.1,0.90,"LArIAT Preliminary");
prelim->DrawLatex(0.13,0.84,"");

c01->Print("xsec_MCband_opt1.png");

 //Drawing option 2
// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c02 = new TCanvas("c02", "Track Length");
c02->SetTicks();
c02->SetFillColor(kWhite);
c02->cd();
 
 MCCrossSection->SetFillColor(0);

 TLegend *leg2 = new TLegend(0.6,0.6,0.85,0.85);
 gStyle->SetLegendFont(62);
 leg2->SetFillColor(0);
 leg2->SetBorderSize(0);
 leg2->SetTextSize(0.04);
 leg2->SetTextFont(42);
 leg2->AddEntry(MCCrossSys,"MC syst + stat","f");
 leg2->AddEntry(MCCrossSection,"MC central value","l");
 leg2->AddEntry(DataCrossSection, "Run-1 data, stat","ep");
 leg2->Draw();


 MCCrossSys->Draw("e2");
 MCCrossSection->Draw("histsame");
 DataCrossSection->Draw("e1same");
 leg2->Draw();
 prelim->Draw();

 c02->Print("xsec_MCband_opt2.png");

 //MC no error band
// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c03 = new TCanvas("c03", "Track Length");
c03->SetTicks();
c03->SetFillColor(kWhite);
c03->cd();
 
 MCCrossSection->SetFillColor(0);

 TLegend *leg3 = new TLegend(0.6,0.7,0.85,0.85);
 gStyle->SetLegendFont(62);
 leg3->SetFillColor(0);
 leg3->SetBorderSize(0);
 leg3->SetTextSize(0.04);
 leg3->SetTextFont(42);
 leg3->AddEntry(MCCrossSection,"MC central value","l");
 leg3->AddEntry(DataCrossSection, "Run-1 data, stat","ep");
 leg3->Draw();

 MCCrossSection->SetAxisRange(0,1200.);
 MCCrossSection->SetMaximum(3.5);
 MCCrossSection->SetMinimum(0);

 MCCrossSection->GetXaxis()->SetTitle("Reconstructed Kinetic Energy (MeV)");
 MCCrossSection->GetXaxis()->SetTitleFont(42);
 MCCrossSection->GetXaxis()->SetTitleSize(0.04);
 MCCrossSection->GetXaxis()->CenterTitle(kFALSE);
 MCCrossSection->GetYaxis()->SetTitle("Total #pi^{#minus} cross section, #sigma_{TOT} (barns)");
 MCCrossSection->GetYaxis()->CenterTitle(kFALSE);
 MCCrossSection->GetYaxis()->SetTitleFont(42);
 MCCrossSection->GetYaxis()->SetTitleSize(0.04);

 MCCrossSection->Draw("hist");
 DataCrossSection->Draw("e1same");
 leg3->Draw();
 prelim->Draw();

 c03->Print("xsec_MC_noband.png");

}
