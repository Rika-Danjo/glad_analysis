void Comp_Integral_data2(){

  TCanvas* can = new TCanvas("can", "can");
  TH1F* frame;
  frame = gPad->DrawFrame(0, 0, 7, 100);
  frame->SetTitle("Integral");
  frame->SetXTitle("I[A]");
  frame->SetYTitle("Magnetic field Btot Integral");
  //frame->GetXaxis()->SetNdivisions(720);
  //frame->GetYaxis()->SetNdivisions(1020);

  
   TGraph* g1 = new TGraph("/u/lndgst01/danjo/glad_analysis/data_ana/data2/data2_x-5.dat", "%lg %*lg %lg");
   g1->SetLineColor(kRed);
   g1->SetMarkerStyle(kFullCircle);
   g1->SetMarkerSize(1);
   g1->Draw("p l");

   TGraph* g2 = new TGraph("/u/lndgst01/danjo/glad_analysis/data_ana/data2/data2_x0.dat", "%lg %*lg %lg");
   g2->SetLineColor(kBlue);
   g2->SetMarkerStyle(kFullCircle);
   g2->SetMarkerSize(1);
   g2->Draw("p l sames");

   TGraph* g3 = new TGraph("/u/lndgst01/danjo/glad_analysis/data_ana/data2/data2_x5.dat", "%lg %*lg %lg");
   g3->SetLineColor(kGreen);
   g3->SetMarkerStyle(kFullCircle);
   g3->SetMarkerSize(1);
   g3->Draw("p l sames");


  	       double Y1[100];
                int N =100;
		double x1[100], x2[100], x3[100], x4[100];

		
                for(int n=0; n<100; n++){
		  Y1[n]=n;
		}
		for(int n=0; n<100; n++){
		  x1[n]=3;
		}
		
		
		TGraph* line1 = new TGraph(N, x1, Y1);
                line1->Draw("l sames");


		TLegend *l = new TLegend(0.8, 0.68, 0.99, 0.78);
                l->AddEntry(g1, "x=-5", "l");
		l->AddEntry(g2, "x=0", "l");
		l->AddEntry(g3, "x=5", "l");
		l->Draw("sames");

 
}
