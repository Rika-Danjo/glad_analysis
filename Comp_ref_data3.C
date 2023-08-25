void Comp_ref_data3(int pos){
  
        gStyle->SetOptStat(0);
	TCanvas *can1 = new TCanvas("can1","can1");
	can1->Divide(2,2);
	TH1F* frame_x, *frame_y, *frame_z, *frame_tot; 

	TChain* ch = new TChain("tree", "tree");
	ch->Add("/u/lndgst01/danjo/glad_analysis/data_ana/data3/1000_to_2500/1st/data3_1000To2500.root");//exp1
	ch->Add("/u/lndgst01/danjo/glad_analysis/data_ana/data3/2500_to_1000/1st/data3_2500To1000.root");//exp2
        ch->Add("/u/lndgst01/danjo/glad_analysis/data_ana/data3/1000_to_2500/2nd/data3_1000To2500.root");//exp3
        ch->Add("/u/lndgst01/danjo/glad_analysis/data_ana/data3/2500_to_1000/2nd/data3_2500To1000.root");//exp4

	int pos1=pos;
	int pos2=pos;
	int pos3=pos;
	double x, y, z, xz, zz, current;
	double B[4];
	ch->SetBranchAddress("x", &x);
	ch->SetBranchAddress("y", &y);
	ch->SetBranchAddress("z", &z);
	ch->SetBranchAddress("xz", &xz);
        ch->SetBranchAddress("zz", &zz); 
	ch->SetBranchAddress("Bx", &B[0]);
	ch->SetBranchAddress("By", &B[1]); 
	ch->SetBranchAddress("Bz", &B[2]);
	ch->SetBranchAddress("I", &current);
	
	       
	double BrefX, BrefY, BrefZ, BrefT, diffX[64], diffY[64], diffZ[64], diffToT[64];
	double bx[64], by[64], bz[64], btot[64];
	double X[64], Y[64], Z[64], T[64], i[64];
	int I[64];
        int j=0;
	int k=0;
	int l=0;
	int m=0;
	int a=0;//exp1: a=0, exp3: a=2 --> ev==(1424*a+(88-(pos-1))), exp2: a=2, exp3: a=4--> ev==(1424*a-(pos-1))
        for(int ev=0; ev<ch->GetEntries(); ev++){
  	    ch->GetEntry(ev);
 	    
	    //reference point : 1000A & x=0[mm] & y=5[mm] & z = 2[mm] - 88[mm] & From1000[A]To2500[A]     
	    if(ev==(1424*a+(87-(pos1-1)))){
	       BrefX = B[0];
	      }	    

	     //To find Magnetic field of setting position
	           if(xz == pos1){
		    bx[j]= B[0];
		    I[j] = current;
		    j++;
		   
		   }
		  
 	}
	
	 for(int ev=0; ev<ch->GetEntries(); ev++){
	   ch->GetEntry(ev+1);
	  
	  
	   //reference point : 1000A & x=0[mm] & y=5[mm] & z = 2[mm] - 88[mm] & From1000[A]To2500[A]     
	    if(ev==(1424*a+(87-(pos2-1)))){
	      BrefY = B[1];
	      }	    

	   
	     //To find Magnetic field of setting position

	          if(z ==  pos2){		     
		     by[k] = B[1];
                     k++;
		    
		   }
 
	}
	 for(int ev=0; ev<ch->GetEntries(); ev++){
	   ch->GetEntry(ev+2);
 	    
	    //reference point : 1000A & x=0[mm] & y=5[mm] & z = 2[mm] - 88[mm] & From1000[A]To2500[A]     
	    if(ev==(1424*a+(87-(pos3-1)))){
	       BrefZ = B[2];
	      }	    

	     //To find Magnetic field of setting position
	           if(zz ==  pos3){
		     bz[l] = B[2];
                     l++;
		   }
 
	}


	 printf("Bx: %f, By:%f, Bz:%f\n", BrefX, BrefY, BrefZ);
	 printf("bx: %f, by:%f, bz:%f\n", bx[0], by[2], bz[1]);
	 printf("I: %d\n", I[0]);
	 
	 
	 
	 BrefT = sqrt(BrefX*BrefX +BrefY*BrefY + BrefZ*BrefZ);
	 //There are 64 points (From exp1 To exp4) 
		   for(int n=0; n<64; n++){
		     
        	     diffX[n] = ((bx[n]*1000)/(BrefX*I[n]) - 1)*1000;
		     diffY[n] = ((by[n]*1000)/(BrefY*I[n]) - 1)*1000;
		     diffZ[n] = ((bz[n]*1000)/(BrefZ*I[n]) - 1)*1000;
		     btot[n]=sqrt(bx[n]*bx[n] +by[n]*by[n] + bz[n]*bz[n]);
		     diffToT[n] = ((btot[n]*1000)/(BrefT*I[n]) - 1)*1000;
	             X[n] = diffX[n];
		     Y[n] = diffY[n];
		     Z[n] = diffZ[n];
		     T[n] = diffToT[n];
		     i[n]=I[n]*0+n;
		     
		   }
		
		printf("deff: %f, %f, %f\n", X[0], Y[0], Z[0]);        


                double Y1[200];
                int N =200;
		double x1[200],x2[200],x3[200];
		int b= -100;
		
                for(int n=0; n<200; n++){
		  Y1[n]=b;
		  b++;
		}
		for(int n=0; n<200; n++){
		  x1[n]=16;
		}
		for(int n=0; n<200; n++){
		  x2[n]=32;
		}
	        for(int n=0; n<200; n++){
		  x3[n]=48;
		}
 
		
		TGraph* line1 = new TGraph(N, x1, Y1);
		TGraph* line2 = new TGraph(N, x2, Y1);
		TGraph* line3 = new TGraph(N, x3, Y1);      
	
		can1->cd(1);
		frame_x=gPad->DrawFrame(0, -200, 64, 200);
                frame_x->SetTitle(Form("data3:x=0,y=5,z=%d_Bx", pos));
                frame_x->SetXTitle("I[A]");
                frame_x->SetYTitle("((Bx(I)*1000/Bx(1000)*I)-1)*1000[permil]");
		TGraph* g_x = new TGraph(64, i, X);
		g_x->SetLineColor(kRed);
		g_x->SetMarkerStyle(kFullCircle);
		g_x->SetMarkerSize(0.7);
		g_x->Draw("p l");
		line1->Draw("l sames");
		line2->Draw("l sames");
		line3->Draw("l sames");

	       	can1->cd(2);
		frame_y=gPad->DrawFrame(0, -30, 64, 30);
                frame_y->SetTitle(Form("data3:x=0,y=5,z=%d_By", pos));
                frame_y->SetXTitle("I[A]");
                frame_y->SetYTitle("((By(I)*1000/By(1000)*I)-1)*1000[permil]");
                TGraph* g_y = new TGraph(64, i, Y);
		g_y->SetLineColor(kRed);
                g_y->SetMarkerStyle(kFullCircle);
                g_y->SetMarkerSize(0.7);
                g_y->Draw("p l");
		line1->Draw("l sames");
		line2->Draw("l sames");
		line3->Draw("l sames");
		
		can1->cd(3);
		frame_z= gPad->DrawFrame(0, -200, 64, 200);
                frame_z->SetTitle(Form("data3:x=0,y=5,z=%d_Bz", pos));
                frame_z->SetXTitle("I[A]");
                frame_z->SetYTitle("((Bz(I)*1000/Bz(1000)*I)-1)*1000[permil]");
                TGraph* g_z = new TGraph(64, i, Z);
		g_z->SetLineColor(kRed);
		g_z->SetMarkerStyle(kFullCircle);
                g_z->SetMarkerSize(0.7);
                g_z->Draw("p l");
		line1->Draw("l sames");
		line2->Draw("l sames");
		line3->Draw("l sames");
		
		can1->cd(4);
		frame_tot= gPad->DrawFrame(0, -30, 64, 30);
                frame_tot->SetTitle(Form("data3:x=0,y=5,z=%d_Btot", pos));
                frame_tot->SetXTitle("I[A]");
                frame_tot->SetYTitle("((Btot(I)*1000/Btot(1000)*I)-1)*1000[permil]");
                TGraph* g_tot = new TGraph(64, i, T);
		g_tot->SetLineColor(kRed);
		g_tot->SetMarkerStyle(kFullCircle);
                g_tot->SetMarkerSize(0.7);
                g_tot->Draw("p l");
		line1->Draw("l sames");
		line2->Draw("l sames");
		line3->Draw("l sames");
		


}
