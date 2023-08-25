//#include"libs.hh"
//#include"definitions.hh"
//#include"R3BTrackingParticle.h"
//#include"R3BGladFieldMap.h"
//#include"R3BTPropagator.h"
//#include"R3BMCTrack.h"

void Comp_exp_sim(int I){

	TCanvas *can = new TCanvas("can","can");
	can->Divide(2,2);
	int NbinsZ = 89;
	int Zmin = 1;
	int Zmax = 89; 
        TH1F* frame_x, *frame_y, *frame_z, *frame_tot; 
	
	TFile *infile1 = TFile::Open("/u/lndgst01/danjo/glad_analysis/data_ana/data3/1000_to_2500/1st/data3_1000To2500.root");
	TTree *exp1 = (TTree*)infile1->Get("tree");//exp1

	TFile *infile2 = TFile::Open("/u/lndgst01/danjo/glad_analysis/data_ana/data3/2500_to_1000/1st/data3_2500To1000.root");
        TTree *exp2 = (TTree*)infile2->Get("tree");//exp2

	TFile *infile3 = TFile::Open("/u/lndgst01/danjo/glad_analysis/data_ana/data3/1000_to_2500/2nd/data3_1000To2500.root");
	TTree *exp3 = (TTree*)infile3->Get("tree");//exp3

	TFile *infile4 = TFile::Open("/u/lndgst01/danjo/glad_analysis/data_ana/data3/2500_to_1000/2nd/data3_2500To1000.root");
        TTree *exp4 = (TTree*)infile4->Get("tree");//exp4
	
	TFile *infile = TFile::Open("/u/lndgst01/danjo/Propagagtion/root/data3_1000.root");
        TTree *sim = (TTree*)infile->Get("tree");//sim
	
	
        /*
	exp1_h[0]->GetYaxis()->SetRangeUser(-0.03, 0.01);
	exp1_h[1]->GetYaxis()->SetRangeUser(0., 1.7);
	exp1_h[2]->GetYaxis()->SetRangeUser(-0.2, 0.);
	exp1_h[3]->GetYaxis()->SetRangeUser(1.7, 1.9);
	exp2_h[0]->GetYaxis()->SetRangeUser(-0.03, 0.01);
	exp2_h[1]->GetYaxis()->SetRangeUser(0., 1.7);
	exp2_h[2]->GetYaxis()->SetRangeUser(-0.2, 0.);
	exp2_h[3]->GetYaxis()->SetRangeUser(1.7, 1.9);
	*/

	double b1x[100], b1y[100], b1z[100], b1tot[100], b2x[100], b2y[100], b2z[100], b2tot[100], b3x[100], b3y[100], b3z[100], b3tot[100], b4x[100], b4y[100], b4z[100], b4tot[100], bx[100], by[100], bz[100], btot[100];
        int j=86;
	int k=86;
	int l=86;
	int m=86;
	int n=86;
	int o=86;
	int p=86;
	int q=86;
	int r=86;
	int s=86;
	int t=86;
	int u=86;
	int v=0;
	double x1, y1, z1, xz1, zz1, current1, x2, y2, z2, xz2, zz2, current2, x3, y3, z3, xz3, zz3, current3, x4, y4, z4, xz4, zz4, current4, x, y, z, current;
	double B1[4], B2[4], B3[4], B4[4], B[4];
	exp1->SetBranchAddress("x", &x1);
	exp1->SetBranchAddress("y", &y1);
	exp1->SetBranchAddress("z", &z1);
	exp1->SetBranchAddress("xz", &xz1);
	exp1->SetBranchAddress("zz", &zz1);
	exp1->SetBranchAddress("Bx", &B1[0]);
	exp1->SetBranchAddress("By", &B1[1]); 
	exp1->SetBranchAddress("Bz", &B1[2]);
	exp1->SetBranchAddress("I", &current1);

	exp2->SetBranchAddress("x", &x2);
        exp2->SetBranchAddress("y", &y2);
        exp2->SetBranchAddress("z", &z2);
	exp2->SetBranchAddress("xz", &xz2);
	exp2->SetBranchAddress("zz", &zz2);
        exp2->SetBranchAddress("Bx", &B2[0]);
        exp2->SetBranchAddress("By", &B2[1]);
        exp2->SetBranchAddress("Bz", &B2[2]);
        exp2->SetBranchAddress("I", &current2);

	exp3->SetBranchAddress("x", &x3);
	exp3->SetBranchAddress("y", &y3);
	exp3->SetBranchAddress("z", &z3);
	exp3->SetBranchAddress("xz", &xz3);
	exp3->SetBranchAddress("zz", &zz3);
	exp3->SetBranchAddress("Bx", &B3[0]);
	exp3->SetBranchAddress("By", &B3[1]); 
	exp3->SetBranchAddress("Bz", &B3[2]);
	exp3->SetBranchAddress("I", &current3);

	exp4->SetBranchAddress("x", &x4);
        exp4->SetBranchAddress("y", &y4);
        exp4->SetBranchAddress("z", &z4);
	exp4->SetBranchAddress("xz", &xz4);
	exp4->SetBranchAddress("zz", &zz4);
        exp4->SetBranchAddress("Bx", &B4[0]);
        exp4->SetBranchAddress("By", &B4[1]);
        exp4->SetBranchAddress("Bz", &B4[2]);
        exp4->SetBranchAddress("I", &current4);

	sim->SetBranchAddress("x", &x);
        sim->SetBranchAddress("y", &y);
        sim->SetBranchAddress("z", &z);
        sim->SetBranchAddress("Bx", &B[0]);
        sim->SetBranchAddress("By", &B[1]);
        sim->SetBranchAddress("Bz", &B[2]);
	
	//exp1////////////////////////////////////////////////////////////////////////////////////////
        for(int ev=0; ev<exp1->GetEntries(); ev++){
  	    exp1->GetEntry(ev);
	     
		    if(current1 == I&& xz1>1 && xz1<89){
		      b1x[j]=(-1)*B1[0];
		      j--;
		     
		    }
		  
 	}

	
	
	 for(int ev=0; ev<exp1->GetEntries(); ev++){
	   exp1->GetEntry(ev);
	  
	            if(current1 == I&& z1>1 && z1<89){
                      b1y[k]=B1[1];
		      k--;
		     
		    }
 
	}
	 for(int ev=0; ev<exp1->GetEntries(); ev++){
	   exp1->GetEntry(ev);
 	 

	            if(current1 == I && zz1>1 && zz1<89){
                      b1z[l]=(-1)*B1[2];
		      l--;
		   
		    }
	   
 
	}
	 
	 //exp2/////////////////////////////////////////////////////////////////////////////////////////
	 for(int ev=0; ev<exp2->GetEntries(); ev++){
  	    exp2->GetEntry(ev);
	     
		    if(current2 == I && xz2>1 && xz2<89){
                      b2x[m]=(-1)*B2[0];
		      m--;
		      
		    }
		  
 	}

	
	
	 for(int ev=0; ev<exp2->GetEntries(); ev++){
	   exp2->GetEntry(ev);
	  
	            if(current2 == I&& z2>1 && z2<89){
		      b2y[n]=B2[1];
		      n--;
		   
		    }
 
	}
	 for(int ev=0; ev<exp2->GetEntries(); ev++){
	   exp2->GetEntry(ev);
 	 

	            if(current2 == I && zz2>1 && zz2<89){
		      b2z[o]=(-1)*B2[2];
		      o--;
		
		    }
	   
 
	}

           
	 
	 
	 //exp3//////////////////////////////////////////////////////////////////////////////////////////////     
	   for(int ev=0; ev<exp3->GetEntries(); ev++){
  	    exp3->GetEntry(ev);
	     
		    if(current3 == I && xz3>1 && xz3<89){
	              b3x[p]=(-1)*B3[0];
		      p--;
		   
		    }
		  
 	}
	
	 for(int ev=0; ev<exp3->GetEntries(); ev++){
	   exp3->GetEntry(ev);
	  
	            if(current3 == I && z3>1 && z3<89){
                      b3y[q]=B3[1];
		      q--;
		    }
 
	}
	 for(int ev=0; ev<exp3->GetEntries(); ev++){
	   exp3->GetEntry(ev);
 	 

	            if(current3 == I && zz3>1 && zz3<89){
                      b3z[r]=(-1)*B3[2];
		      r--;
		    }
	   
 
	}

	 //exp4//////////////////////////////////////////////////////////////////////////////////////////////
	   for(int ev=0; ev<exp4->GetEntries(); ev++){
  	    exp4->GetEntry(ev);
	     
		    if(current4 == I && xz4>1 && xz4<89){
		      b4x[s]=(-1)*B4[0];
		      s--;
		    }
		  
 	}
	
	 for(int ev=0; ev<exp4->GetEntries(); ev++){
	   exp4->GetEntry(ev);
	  
	            if(current4 == I && z4>1 && z4<89){
                      b4y[t]=B4[1];
		      t--;
		    }
 
	}
	 for(int ev=0; ev<exp4->GetEntries(); ev++){
	   exp4->GetEntry(ev);
 	 

	            if(current4 == I && zz4>1 && zz4<89){
                      b4z[u]=(-1)*B4[2];
		      u--;
		    }
	   
 
	}


	 
        
	 //sim////////////////////////////////////////////////////////////////////////////////////////////
	for(int ev=0; ev<sim->GetEntries(); ev++)
        {
                sim->GetEntry(ev);
              
		  if(z>1 && z<89){
		      bx[v]=B[0];
		      by[v]=B[1];
                      bz[v]=B[2];
		      v++;
		  }

	}


	        double N[89];
                  for(int n=0; n<87; n++){
		    b1tot[n]=sqrt(b1x[n]*b1x[n]+b1y[n]*b1y[n]+b1z[n]*b1z[n]);
		    b2tot[n]=sqrt(b2x[n]*b2x[n]+b2y[n]*b2y[n]+b2z[n]*b2z[n]);
		    b3tot[n]=sqrt(b3x[n]*b3x[n]+b3y[n]*b3y[n]+b3z[n]*b3z[n]);
		    b4tot[n]=sqrt(b4x[n]*b4x[n]+b4y[n]*b4y[n]+b4z[n]*b4z[n]);
		    btot[n]=sqrt(bx[n]*bx[n]+by[n]*by[n]+bz[n]*bz[n]);
		    N[n]=n;
		  }

	        can->cd(1);
		frame_x=gPad->DrawFrame(2, -1, 88, 1);
                frame_x->SetTitle("Bx");
                frame_x->SetXTitle("z[mm]");
                frame_x->SetYTitle("Magnetic field X[T]");
		TGraph* g1_x = new TGraph(87, N, b1x);
                TGraph* g2_x = new TGraph(87, N, b2x);
                TGraph* g3_x = new TGraph(87, N, b3x);
		TGraph* g4_x = new TGraph(87, N, b4x);
		TGraph* g_x = new TGraph(87, N, bx);
		g1_x->SetMarkerColor(kRed);
		g1_x->SetMarkerStyle(kFullCircle);
		g1_x->SetMarkerSize(0.7);
		g1_x->Draw("p l sames");
		g2_x->SetMarkerColor(kBlue);
		g2_x->SetMarkerStyle(kFullCircle);
		g2_x->SetMarkerSize(0.7);
		g2_x->Draw("p l sames");
		g3_x->SetMarkerColor(kGreen);
		g3_x->SetMarkerStyle(kFullCircle);
		g3_x->SetMarkerSize(0.7);
		//g3_x->Draw("p l sames");
		g4_x->SetMarkerColor(kBlack);
		g4_x->SetMarkerStyle(kFullCircle);
		g4_x->SetMarkerSize(0.7);
		//g4_x->Draw("p l sames");
		g_x->SetMarkerColor(kPink);
		g_x->SetMarkerStyle(kFullCircle);
		g_x->SetMarkerSize(0.7);
		g_x->Draw("p l sames");
                TLegend *lx = new TLegend(0.8, 0.68, 0.99, 0.78);
                lx->AddEntry(g1_x, "exp1", "l");
                lx->AddEntry(g2_x, "exp2", "l");
                lx->AddEntry(g3_x, "exp3", "l");
                lx->AddEntry(g4_x, "exp4", "l");
                lx->AddEntry(g_x, "sim", "l");
		lx->Draw("sames");
		
		can->cd(2);
		frame_y=gPad->DrawFrame(2, -1, 88, 1);
                frame_y->SetTitle("By");
                frame_y->SetXTitle("z[mm]");
                frame_y->SetYTitle("Magnetic field Y[T]");
		TGraph* g1_y = new TGraph(87, N, b1y);
		TGraph* g2_y = new TGraph(87, N, b2y);
		TGraph* g3_y = new TGraph(87, N, b3y);
		TGraph* g4_y = new TGraph(87, N, b4y);
		TGraph* g_y = new TGraph(87, N, by);
		g1_y->SetMarkerColor(kRed);
		g1_y->SetMarkerStyle(kFullCircle);
		g1_y->SetMarkerSize(0.7);
		g1_y->Draw("p l sames");
		g2_y->SetMarkerColor(kBlue);
		g2_y->SetMarkerStyle(kFullCircle);
		g2_y->SetMarkerSize(0.7);
		g2_y->Draw("p l sames");
		g3_y->SetMarkerColor(kGreen);
		g3_y->SetMarkerStyle(kFullCircle);
		g3_y->SetMarkerSize(0.7);
		//g3_y->Draw("p l sames");
		g4_y->SetMarkerColor(kBlack);
		g4_y->SetMarkerStyle(kFullCircle);
		g4_y->SetMarkerSize(0.7);
		//g4_y->Draw("p l sames");
		g_y->SetMarkerColor(kPink);
		g_y->SetMarkerStyle(kFullCircle);
		g_y->SetMarkerSize(0.7);
		g_y->Draw("p l sames");
                TLegend *ly = new TLegend(0.8, 0.68, 0.99, 0.78);
                ly->AddEntry(g1_y, "exp1", "l");
                ly->AddEntry(g2_y, "exp2", "l");
                ly->AddEntry(g3_y, "exp3", "l");
                ly->AddEntry(g4_y, "exp4", "l");
                ly->AddEntry(g_y, "sim", "l");
		ly->Draw("sames");

		can->cd(3);
		frame_z=gPad->DrawFrame(2, -1, 88, 1);
                frame_z->SetTitle("Bz");
                frame_z->SetXTitle("z[mm]");
                frame_z->SetYTitle("Magnetic field Z[T]");
		TGraph* g1_z = new TGraph(87, N, b1z);
		TGraph* g2_z = new TGraph(87, N, b2z);
		TGraph* g3_z = new TGraph(87, N, b3z);
		TGraph* g4_z = new TGraph(87, N, b4z);
		TGraph* g_z = new TGraph(87, N, bz);
		g1_z->SetMarkerColor(kRed);
		g1_z->SetMarkerStyle(kFullCircle);
		g1_z->SetMarkerSize(0.7);
		g1_z->Draw("p l sames");
		g2_z->SetMarkerColor(kBlue);
		g2_z->SetMarkerStyle(kFullCircle);
		g2_z->SetMarkerSize(0.7);
		g2_z->Draw("p l sames");
		g3_z->SetMarkerColor(kGreen);
		g3_z->SetMarkerStyle(kFullCircle);
		g3_z->SetMarkerSize(0.7);
		//g3_z->Draw("p l sames");
		g4_z->SetMarkerColor(kBlack);
		g4_z->SetMarkerStyle(kFullCircle);
		g4_z->SetMarkerSize(0.7);
		//g4_z->Draw("p l sames");
		g_z->SetMarkerColor(kPink);
		g_z->SetMarkerStyle(kFullCircle);
		g_z->SetMarkerSize(0.7);
		g_z->Draw("p l sames");
		TLegend *lz = new TLegend(0.8, 0.68, 0.99, 0.78);
                lz->AddEntry(g1_z, "exp1", "l");
                lz->AddEntry(g2_z, "exp2", "l");
                lz->AddEntry(g3_z, "exp3", "l");
                lz->AddEntry(g4_z, "exp4", "l");
                lz->AddEntry(g_z, "sim", "l");
		lz->Draw("sames");
		
        	can->cd(4);
		frame_tot=gPad->DrawFrame(2, -1, 88, 1);
                frame_tot->SetTitle("Btot");
                frame_tot->SetXTitle("Z[mm]");
                frame_tot->SetYTitle("Magnetic field ToT[T");
		TGraph* g1_tot = new TGraph(87, N, b1tot);
		TGraph* g2_tot = new TGraph(87, N, b2tot);
		TGraph* g3_tot = new TGraph(87, N, b3tot);
		TGraph* g4_tot = new TGraph(87, N, b4tot);
		TGraph* g_tot = new TGraph(87, N, btot);
		g1_tot->SetMarkerColor(kRed);
		g1_tot->SetMarkerStyle(kFullCircle);
		g1_tot->SetMarkerSize(0.7);
		g1_tot->Draw("p l sames");
		g2_tot->SetMarkerColor(kBlue);
		g2_tot->SetMarkerStyle(kFullCircle);
		g2_tot->SetMarkerSize(0.7);
		g2_tot->Draw("p l sames");
		g3_tot->SetMarkerColor(kGreen);
		g3_tot->SetMarkerStyle(kFullCircle);
		g3_tot->SetMarkerSize(0.7);
		//g3_tot->Draw("p l sames");
		g4_tot->SetMarkerColor(kBlack);
		g4_tot->SetMarkerStyle(kFullCircle);
		g4_tot->SetMarkerSize(0.7);
		//g4_tot->Draw("p l sames");
		g_tot->SetMarkerColor(kPink);
		g_tot->SetMarkerStyle(kFullCircle);
		g_tot->SetMarkerSize(0.7);
		g_tot->Draw("p l sames");
		TLegend *ltot = new TLegend(0.8, 0.68, 0.99, 0.78);
                ltot->AddEntry(g1_tot, "exp1", "l");
                ltot->AddEntry(g2_tot, "exp2", "l");
                ltot->AddEntry(g3_tot, "exp3", "l");
                ltot->AddEntry(g4_tot, "exp4", "l");
                ltot->AddEntry(g_tot, "sim", "l");
		ltot->Draw("sames");
	



}
