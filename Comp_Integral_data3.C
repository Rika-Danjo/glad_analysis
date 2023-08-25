void Comp_Integral_data3(){

  TCanvas* can = new TCanvas("can", "can");
  TH1F* frame;
  frame = gPad->DrawFrame(0, 25, 64, 70);
  frame->SetTitle("Integral");
  frame->SetXTitle("I[A]");
  frame->SetYTitle("Magnetic field Btot Integral");
  frame->GetXaxis()->SetNdivisions(720);
  frame->GetYaxis()->SetNdivisions(1020);

  
   TGraph* g = new TGraph("/u/lndgst01/danjo/glad_analysis/data_ana/data3/data3_all_Integral.dat", "%lg %*lg %lg");
   g->SetLineColor(kRed);
   g->SetMarkerStyle(kFullCircle);
   g->SetMarkerSize(1);
   g->Draw("p l");


  	       double Y1[100];
                int N =100;
		double x1[100], x2[100], x3[100], x4[100];

		
                for(int n=0; n<100; n++){
		  Y1[n]=n;
		}
		for(int n=0; n<100; n++){
		  x1[n]=16;
		}
		for(int n=0; n<100; n++){
		  x2[n]=32;
		}
		for(int n=0; n<100; n++){
		  x3[n]=48;
		}
		
		
		TGraph* line1 = new TGraph(N, x1, Y1);
		TGraph* line2 = new TGraph(N, x2, Y1);
		TGraph* line3 = new TGraph(N, x3, Y1);
                TGraph* line4 = new TGraph(N, x4, Y1);
                line1->Draw("l sames");
		line2->Draw("l sames");
		line3->Draw("l sames");
	        //line4->Draw("l sames");	
 
}
