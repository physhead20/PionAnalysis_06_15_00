{
#include <TFile.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <TMath.h>

double MuonMomentumError[49] = {0.};
double MuonMomentum[49] = {
27.42,
29.35,
31.16,
32.89,
34.53,
36.11,
39.09,
41.89,
44.53,
47.04,
51.77,
56.16,
62.3,
68.02,
76.86,
85.09,
92.85,
100.3,
107.4,
114.3,
121,
127.6,
140.3,
152.7,
164.7,
176.4,
199.4,
221.8,
254.6,
286.8,
339.6,
356.7,
391.7,
443.2,
494.5,
545.5,
596.4,
647.1,
697.7,
798.7,
899.5,
1000,
1101,
1301,
1502,
1803,
2103,
2604};

double PionMomentumError[49] = {0.};
double PionMomentum[49] = {
35.646,
38.155,
40.508,
42.757,
44.889,
46.943,
50.817,
54.457,
57.889,
61.152,
67.301,
73.008,
80.99,
88.426,
99.918,
110.617,
120.705,
130.39,
139.62,
148.59,
157.3,
165.88,
182.39,
198.51,
214.11,
229.32,
259.22,
288.34,
330.98,
372.84,
441.48,
463.71,
509.21,
576.16,
642.85,
709.15,
775.32,
841.23,
907.01,
1038.31,
1169.35,
1300,
1431.3,
1691.3,
1952.6,
2343.9,
2733.9,
3385.2};

double ProtonMomentumError[49] = {0.};
double ProtonMomentum[49] = {
304.362,
325.785,
345.876,
365.079,
383.283,
400.821,
433.899,
464.979,
494.283,
522.144,
574.647,
623.376,
691.53,
755.022,
853.146,
944.499,
1030.635,
1113.33,
1192.14,
1268.73,
1343.1,
1416.36,
1557.33,
1694.97,
1828.17,
1958.04,
2213.34,
2461.98,
2826.06,
3183.48,
3769.56,
3959.37,
4347.87,
4919.52,
5488.95,
6055.05,
6620.04,
7182.81,
7744.47,
8865.57,
9984.45,
11100,
12221.1,
14441.1,
16672.2,
20013.3,
23343.3,
28904.4};

double TheorydEdXError[49] = {0.};
double TheorydEdX[49] = {
12.72,
11.46,
10.46,
9.635,
8.949,
8.368,
7.435,
6.719,
6.15,
5.687,
4.979,
4.461,
3.902,
3.502,
3.042,
2.731,
2.508,
2.34,
2.21,
2.107,
2.023,
1.954,
1.848,
1.771,
1.713,
1.67,
1.609,
1.57,
1.536,
1.519,
1.508,
1.51,
1.51,
1.517,
1.526,
1.537,
1.548,
1.559,
1.57,
1.591,
1.61,
1.628,
1.645,
1.675,
1.7,
1.733,
1.761,
1.799};


const Int_t m = 49;


// ### Muon Lines ###
grMuon = new TGraphErrors(m,MuonMomentum,TheorydEdX,MuonMomentumError,TheorydEdXError);
grMuon->SetFillColor(kWhite);
grMuon->SetFillStyle(3005);
grMuon->SetLineColor(kBlue);
grMuon->SetLineWidth(2);

// ### Pion Lines ###
grPion = new TGraphErrors(m,PionMomentum,TheorydEdX,PionMomentumError,TheorydEdXError);
grPion->SetFillColor(kWhite);
grPion->SetFillStyle(3005);
grPion->SetLineColor(kRed);
grPion->SetLineWidth(2);

// ### Proton Lines ###
grProton = new TGraphErrors(m,ProtonMomentum,TheorydEdX,ProtonMomentumError,TheorydEdXError);
grProton->SetFillColor(kWhite);
grProton->SetFillStyle(3005);
grProton->SetLineColor(kPink+5);
grProton->SetLineWidth(2);

// ########################
// ### Making a TCanvas ###
// ########################
TCanvas *c01 = new TCanvas("c01", "Low bin data");
c01->SetTicks();
c01->SetFillColor(kWhite);

grMuon->Draw("AP");
grPion->Draw("Csame");
grProton->Draw("Csame");


}//<---End file
