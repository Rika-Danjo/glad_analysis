void Comp_ref_data2(int zpos, int xpos){

        gStyle->SetOptStat(0);


        TCanvas *can1 = new TCanvas("can1","can1");
	can1->Divide(2,2);
	TH1F* frame_x, *frame_y, *frame_z, *frame_tot; 

	TChain* ch = new TChain("tree3", "tree3");//tree1: y=-1, tree2: y=4, tree3: y=9[cm]<--data3 measurement cordinate
        ch->Add("/u/lndgst01/danjo/glad_analysis/data_ana/data2/1000A/1st/data2_1000A.root");//exp1
        ch->Add("/u/lndgst01/danjo/glad_analysis/data_ana/data2/1500A/1st/data2_1500A.root");//exp2
        ch->Add("/u/lndgst01/danjo/glad_analysis/data_ana/data2/2000A/1st/data2_2000A.root");//exp3
        ch->Add("/u/lndgst01/danjo/glad_analysis/data_ana/data2/2500A/data2_2500A.root");//exp4
        ch->Add("/u/lndgst01/danjo/glad_analysis/data_ana/data2/2000A/2nd/data2_2000A.root");//exp5
        ch->Add("/u/lndgst01/danjo/glad_analysis/data_ana/data2/1500A/2nd/data2_1500A.root");//exp6
        ch->Add("/u/lndgst01/danjo/glad_analysis/data_ana/data2/1000A/2nd/data2_1000A.root");//exp7

	int pos1=zpos;
	int pos2=zpos;
	int pos3=zpos;
	int xpos1=xpos;
	int xpos2=xpos;
	int xpos3=xpos;

	double x, y, z, xz, zz; //lab cordinate
	double B[4];
	ch->SetBranchAddress("x", &x);
	ch->SetBranchAddress("y", &y);
	ch->SetBranchAddress("z", &z);
	ch->SetBranchAddress("xz", &xz);
        ch->SetBranchAddress("zz", &zz); 
	ch->SetBranchAddress("Bx", &B[0]);
	ch->SetBranchAddress("By", &B[1]); 
	ch->SetBranchAddress("Bz", &B[2]);

	       
	double BrefX, BrefY, BrefZ, BrefT, diffX[64], diffY[64], diffZ[64], diffToT[64];
	double bx[64], by[64], bz[64], btot[64];
	double X[64], Y[64], Z[64], T[64], i[64];
        int j=0;
	int k=0;
	int l=0;
	int m=0;
	int a;

	printf("pos=%d\n",xpos);
        for(int ev=0; ev<ch->GetEntries(); ev++){
  	    ch->GetEntry(ev);
 	    
	  //reference point : 1000A & x = 5, -0, -5[mm] & y = 7.25[mm] & z = 2[mm] - 98[mm] & 1000[A] //lab cordinate
	  switch(xpos1){

	      case 5://<-lab cordinate x=5
	      a=0;
	      //printf("a=%d\n",a);
 	      if(ev==(99*a+(98-(pos1)))){
	       BrefX = B[0];
	      
	      }	    

	     //To find Magnetic field of setting position
	           if(xz == pos1 && x==xpos1){
		    bx[j]= B[0];
		    j++;
		   }
		   break;

	      case -0://<-lab cordinate x=-0
	      a=1;
	      //printf("a=%d\n",a);
              if(ev==(99*a+(98-(pos1)))){
               BrefX = B[0];

              }

             //To find Magnetic field of setting position
                   if(xz == pos1 && x==xpos1){
                    bx[j]= B[0];
                    j++;
                   }
		   break;
	      
	      case -5: //<-lab cordinate x=-5
	      a=2;
	      //printf("a=%d\n",a);
	      if(ev==(99*a+(98-(pos1)))){
               BrefX = B[0];

              }

             //To find Magnetic field of setting position
                   if(xz == pos1 && x==xpos1){
                    bx[j]= B[0];
                    j++;
                   }
		   break;
		 
         }

	}
	
        for(int ev=0; ev<ch->GetEntries(); ev++){
	   ch->GetEntry(ev+1);
 	    
	      
	  //reference point : 1000A & x = 5, -0, -5[mm] & y = 7.25[mm] & z = 2[mm] - 98[mm] & 1000[A] //lab cordinate
	  switch(xpos2){

	      case 5://<-lab cordinate x=5
	      a=0;
	      printf("a=%d\n",a);
 	      if(ev==(99*a+(98-(pos2)))){
	       BrefY = B[1];
	      
	      }	    

	     //To find Magnetic field of setting position
	           if(z == pos2 && x==xpos2){
		    by[k]= B[1];
		    k++;
		   }
		   break;

	      case -0://<-lab cordinate x=-0
	      a=1;
	      printf("a=%d\n",a);
              if(ev==(99*a+(98-(pos2)))){
               BrefY = B[1];

              }

             //To find Magnetic field of setting position
                   if(z == pos2 && x==xpos2){
                    by[k]= B[1];
                    k++;
                   }
		   break;
	      
	      case -5: //<-lab cordinate x=-5
	      a=2;
	      //printf("a=%d\n",a);
	      if(ev==(99*a+(98-(pos2)))){
               BrefY = B[1];

              }

             //To find Magnetic field of setting position
                   if(z == pos2 && x==xpos2){
                    by[k]= B[1];
                    k++;
                   }
		   break;
		 
         }
	  
	}
         printf("by=%f\n",by[1]);
	

	 for(int ev=0; ev<ch->GetEntries(); ev++){
	   ch->GetEntry(ev+2);

	   	      
	  //reference point : 1000A & x = 5, -0, -5[mm] & y = 7.25[mm] & z = 2[mm] - 98[mm] & 1000[A] //lab cordinate
	  switch(xpos3){

	      case 5://<-lab cordinate x=5
	      a=0;
	      printf("a=%d\n",a);
 	      if(ev==(99*a+(98-(pos3)))){
	       BrefZ = B[2];
	      
	      }	    

	     //To find Magnetic field of setting position
	      if(zz == pos3 && x==xpos3){
		    bz[l]= B[2];
		    l++;
		   }
		   break;

	      case -0://<-lab cordinate x=-0
	      a=1;
	      printf("a=%d\n",a);
              if(ev==(99*a+(98-(pos3)))){
               BrefZ = B[2];

              }

             //To find Magnetic field of setting position
                   if(zz == pos3 && x==xpos3){
                    bz[l]= B[2];
                    l++;
                   }
		   break;
	      
	      case -5: //<-lab cordinate x=-5
	      a=2;
	      //printf("a=%d\n",a);
	      if(ev==(99*a+(98-(pos3)))){
               BrefZ = B[2];

              }

             //To find Magnetic field of setting position
                   if(zz == pos3 && x==xpos3){
                    bz[l]= B[2];
                    l++;
                   }
		   break;

	  }
 
	}
	 
	  printf("Bx: %f, By:%f, Bz:%f\n", BrefX, BrefY, BrefZ);
	 
	  BrefT = sqrt(BrefX*BrefX +BrefY*BrefY + BrefZ*BrefZ);
	 //There are 7 points (From exp1 To exp7)
	  double I[7]={1000., 1500., 2000., 2500., 2000., 1500., 1000.};
		   for(int n=0; n<7; n++){	  
        	     diffX[n] = ((bx[n]*1000)/(BrefX*I[n]) - 1)*1000;
		     diffY[n] = ((by[n]*1000)/(BrefY*I[n]) - 1)*1000;
		     diffZ[n] = ((bz[n]*1000)/(BrefZ*I[n]) - 1)*1000;
		     btot[n]=sqrt(bx[n]*bx[n] +by[n]*by[n] + bz[n]*bz[n]);
		     diffToT[n] = ((btot[n]*1000)/(BrefT*I[n]) - 1)*1000;
                     X[n] = diffX[n];
		     Y[n] = diffY[n];
		     Z[n] = diffZ[n];
		     T[n] = diffToT[n];
		     i[n] = diffToT[n]*0+n;
		   }

		printf("Bz: %f, %f, %f, I:%f\n", Y[0], by[0], BrefY, I[0]);        


                double Y1[2000];
                int N =2000;
		double x1[2000];
		int b= -1000;
		
                for(int n=0; n<2000; n++){
		  Y1[n]=b;
		  b++;
		}
		for(int n=0; n<2000; n++){
		  x1[n]=3;
		}	
		
		TGraph* line1 = new TGraph(N, x1, Y1);            
		
		can1->cd(1);
		frame_x=gPad->DrawFrame(0, -20, 8, 20);
                frame_x->SetTitle(Form("data2:x=%d,y=9,z=%d_Bx",xpos,zpos));
                frame_x->SetXTitle("Num");
                frame_x->SetYTitle("Magnetic field relative");
		TGraph* g_x = new TGraph(7, i, X);
		g_x->SetLineColor(kRed);
		g_x->SetMarkerStyle(kFullCircle);
		g_x->SetMarkerSize(1);
		g_x->Draw("p l");
		line1->Draw("l sames");

		can1->cd(2);
		frame_y=gPad->DrawFrame(0, -20, 8, 20);
                frame_y->SetTitle(Form("data2:x=%d,y=9,z=%d)_By",xpos,zpos));
                frame_y->SetXTitle("Num");
                frame_y->SetYTitle("Magnetic field relative");
		TGraph* g_y = new TGraph(7, i, Y);
	        g_y->SetLineColor(kRed);
                g_y->SetMarkerStyle(kFullCircle);
                g_y->SetMarkerSize(1);
                g_y->Draw("p l");
		line1->Draw("l sames");

		can1->cd(3);
		frame_z=gPad->DrawFrame(0, -20, 8, 20);
                frame_z->SetTitle(Form("data2:x=%d,y=9,z=%d_Bz",xpos,zpos));
                frame_z->SetXTitle("Num");
                frame_z->SetYTitle("Magnetic field relative");
		TGraph* g_z = new TGraph(7, i, Z);
		g_z->SetLineColor(kRed);
		g_z->SetMarkerStyle(kFullCircle);
		g_z->SetMarkerSize(1);
		g_z->Draw("p l");
		line1->Draw("l sames");
		
		can1->cd(4);
		frame_tot=gPad->DrawFrame(0, -20, 8, 20);
                frame_tot->SetTitle(Form("data2:x=%d,y=9,z=%d_Btot",xpos,zpos));
                frame_tot->SetXTitle("Num");
                frame_tot->SetYTitle("Magnetic field relative");
		TGraph* g_tot = new TGraph(7, i, T);
	        g_tot->SetLineColor(kRed);
		g_tot->SetMarkerStyle(kFullCircle);
		g_tot->SetMarkerSize(1);
		g_tot->Draw("p l");
		line1->Draw("l sames");
	    

}
