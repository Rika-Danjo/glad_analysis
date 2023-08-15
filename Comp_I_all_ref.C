void Comp_I_all_ref(int pos){

        gStyle->SetOptStat(0);
	TCanvas *can1 = new TCanvas("can1","can1");
	can1->Divide(2,2);
	TH1F* frame_x, *frame_y, *frame_z, *frame_tot; 

	TChain* ch = new TChain("tree", "tree");
	ch->Add("/u/lndgst01/danjo/glad_analysis/data3/1000_to_2500/1st/data3_1000To2500.root");//exp1
	ch->Add("/u/lndgst01/danjo/glad_analysis/data3/2500_to_1000/1st/data3_2500To1000.root");//exp2
        ch->Add("/u/lndgst01/danjo/glad_analysis/data3/1000_to_2500/2nd/data3_1000To2500.root");//exp3
        ch->Add("/u/lndgst01/danjo/glad_analysis/data3/2500_to_1000/2nd/data3_2500To1000.root");//exp4
	
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
        for(int ev=0; ev<ch->GetEntries(); ev++){
  	    ch->GetEntry(ev);
 	    
	    //reference point : 1000A & x=0[mm] & y=5[mm] & z = 1[mm] - 89[mm] & From1000[A]To2500[A]     
	      if(ev==88-(pos-1)){
	       BrefX = B[0];
	       BrefY = B[1];
	       BrefZ = B[2];
	       BrefT = sqrt(BrefX*BrefX +BrefY*BrefY + BrefZ*BrefZ);
	      }	    

	     //To find Magnetic field of setting position
	           if(xz == (pos-1)){
		    bx[j]= B[0];
		    I[j] = current;
		    j++;
		   }
		   if(z ==  pos){
		     by[k] = B[1];
                     k++;
		   }
		   if(zz == (pos+1)){
		     bz[l] = B[2];
                     l++;
		   }
		   if(xz== (pos-1) && z ==  pos && zz== (pos+1)){
		     btot[m] = sqrt(B[0]*B[0] +B[1]*B[1] + B[2]*B[2]);
                     m++;
  	           }

	      //There are 64 points (From exp1 To exp4) 
		   for(int n=0; n<64; n++){	  
        	     diffX[n] = ((bx[n]*1000)/(BrefX*I[n]) - 1)*1000;
		     diffY[n] = ((by[n]*1000)/(BrefY*I[n]) - 1)*1000;
		     diffZ[n] = ((bz[n]*1000)/(BrefZ*I[n]) - 1)*1000;
		     diffToT[n] = ((btot[n]*1000)/(BrefT*I[n]) - 1)*1000;
                     X[n] = diffX[n];
		     Y[n] = diffY[n];
		     Z[n] = diffZ[n];
		     T[n] = diffToT[n];
		     i[n]=I[n]*0+n;
		   }
  		
 
	}	

	//printf("BY: %f, %f, %f\n", Y[0], Y[31], BrefY);        

		
		can1->cd(1);
		frame_x=gPad->DrawFrame(0, -20, 64, 20);
                frame_x->SetTitle(Form("z=%d_Bx", pos));
                frame_x->SetXTitle("I[A]");
                frame_x->SetYTitle("Magnetic field Y[T]");
		TGraph* g_x = new TGraph(64, i, X);
		g_x->SetMarkerSize(0.7);
		g_x->Draw("L");

	       	can1->cd(2);
		frame_y=gPad->DrawFrame(0, -20, 64, 20);
                frame_y->SetTitle(Form("z=%d_By", pos));
                frame_y->SetXTitle("I[A]");
                frame_y->SetYTitle("Magnetic field Y[T]");
                TGraph* g_y = new TGraph(64, i, Y);
                g_y->SetMarkerSize(0.7);
                g_y->Draw("L");

		can1->cd(3);
		frame_z= gPad->DrawFrame(0, -20, 64, 20);
                frame_z->SetTitle(Form("z=%d_Bz", pos));
                frame_z->SetXTitle("I[A]");
                frame_z->SetYTitle("Magnetic field Z[T]");
                TGraph* g_z = new TGraph(64, i, Z);
                g_z->SetMarkerSize(0.7);
                g_z->Draw("L");

		can1->cd(4);
		frame_tot= gPad->DrawFrame(0, -20, 64, 20);
                frame_tot->SetTitle(Form("z=%d_Btot", pos));
                frame_tot->SetXTitle("I[A]");
                frame_tot->SetYTitle("Magnetic field tot[T]");
                TGraph* g_tot = new TGraph(64, i, T);
                g_tot->SetMarkerSize(0.7);
                g_tot->Draw("L");
                     


}
