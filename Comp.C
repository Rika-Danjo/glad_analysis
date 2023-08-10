void Comp(int I){
  
	TCanvas *canX = new TCanvas("canX","canX");
	TCanvas *canY = new TCanvas("canY","canY");
	TCanvas *canZ = new TCanvas("canZ","canZ");
	TCanvas *canToT = new TCanvas("canToT","canToT");	
	canX->Divide(2,1);
	canY->Divide(2,1);
	canZ->Divide(2,1);
	canToT->Divide(2,1);
	TH1F *frame_x[90], *frame_y[90], *frame_z[90], *frame_tot[90]  ;
       
	TFile *infile1 = TFile::Open("/u/lndgst01/danjo/glad_analysis/data3/1000_to_2500/1st/data3_1000To2500.root");
	TTree *exp1 = (TTree*)infile1->Get("tree");

	TFile *infile2 = TFile::Open("/u/lndgst01/danjo/glad_analysis/data3/1000_to_2500/2nd/data3_1000To2500.root");
        TTree *exp2 = (TTree*)infile2->Get("tree");

	double x1, y1, z1, x2, y2, z2, current1, current2;
	double B1[4], B2[4], B[4];
	exp1->SetBranchAddress("x", &x1);
	exp1->SetBranchAddress("y", &y1);
	exp1->SetBranchAddress("z", &z1); 	
	exp1->SetBranchAddress("Bx", &B1[0]);
	exp1->SetBranchAddress("By", &B1[1]); 
	exp1->SetBranchAddress("Bz", &B1[2]);
	exp1->SetBranchAddress("Btot", &B1[3]);
	exp1->SetBranchAddress("I", &current1);

	exp2->SetBranchAddress("x", &x2);
        exp2->SetBranchAddress("y", &y2);
        exp2->SetBranchAddress("z", &z2);
        exp2->SetBranchAddress("Bx", &B2[0]);
        exp2->SetBranchAddress("By", &B2[1]);
        exp2->SetBranchAddress("Bz", &B2[2]);
        exp2->SetBranchAddress("Btot", &B2[3]);
        exp2->SetBranchAddress("I", &current2);

	TGraph *g1_x[89], *g1_y[89],*g1_z[89],*g1_tot[89],*g2_x[89], *g2_y[89],*g2_z[89],*g2_tot[89];
	for(int i=1; i<90; i++)
	{
	  //****exp1 data*********************************************************
	        g1_x[i] = new TGraph;
		g1_x[i]->SetMarkerStyle(kFullCircle);
		g1_x[i]->SetMarkerColor(kRed);
		g1_x[i]->SetMarkerSize(0.5);
		
		g1_y[i] = new TGraph;
                g1_y[i]->SetMarkerStyle(kFullCircle);
                g1_y[i]->SetMarkerColor(kRed);
                g1_y[i]->SetMarkerSize(0.5);

		g1_z[i] = new TGraph;
		g1_z[i]->SetMarkerStyle(kFullCircle);
		g1_z[i]->SetMarkerColor(kRed);
		g1_z[i]->SetMarkerSize(0.5);

		g1_tot[i] = new TGraph;
                g1_tot[i]->SetMarkerStyle(kFullCircle);
                g1_tot[i]->SetMarkerColor(kRed);
                g1_tot[i]->SetMarkerSize(0.5);

	  //**********************************************************************

	  //****exp2 data*********************************************************
		g2_x[i] = new TGraph;
		g2_x[i]->SetMarkerStyle(kFullCircle);
		g2_x[i]->SetMarkerColor(kBlue);
		g2_x[i]->SetMarkerSize(0.5);
		
		g2_y[i] = new TGraph;
                g2_y[i]->SetMarkerStyle(kFullCircle);
                g2_y[i]->SetMarkerColor(kBlue);
                g2_y[i]->SetMarkerSize(0.5);

		g2_z[i] = new TGraph;
		g2_z[i]->SetMarkerStyle(kFullCircle);
		g2_z[i]->SetMarkerColor(kBlue);
		g2_z[i]->SetMarkerSize(0.5);

		g2_tot[i] = new TGraph;
                g2_tot[i]->SetMarkerStyle(kFullCircle);
                g2_tot[i]->SetMarkerColor(kBlue);
                g2_tot[i]->SetMarkerSize(0.5);
	   //**********************************************************************
	}

	for(int ev1=0; ev1<exp1->GetEntries(); ev1++)
	{
	  
	 exp1->GetEntry(ev1); 
	 for(int pos=1 ; pos<3; pos++){
	   if(I==current1 && pos==z1){

	     double Z1 = z1;
	     double B1x = B1[0];
	     double B1y = B1[1];
	     double B1z = B1[2];
             double B1tot = B1[3];	

	     g1_x[pos]->SetPoint(1,Z1,B1x);
	     g1_y[pos]->SetPoint(1,Z1,B1y);
	     g1_z[pos]->SetPoint(1,Z1,B1z);
	     g1_tot[pos]->SetPoint(1,Z1,B1tot);
	     
	     cout << "\nz1=" <<  Z1 << ", Bt=" <<  B1tot << "pos=" << pos;  
	   }
         }

        }

	for(int ev2=0; ev2<exp2->GetEntries(); ev2++)
	{
	  
	 exp2->GetEntry(ev2); 
	 for(int pos=1 ; pos<3; pos++){
	   if(I==current2 && pos==z2){

	     double Z2 = z2;
	     double B2x = B2[0];
	     double B2y = B2[1];
	     double B2z = B2[2];
	     double B2tot = B2[3];
	
	     g2_x[pos]->SetPoint(1,Z2,B2x);
	     g2_y[pos]->SetPoint(1,Z2,B2y);
	     g2_z[pos]->SetPoint(1,Z2,B2z);
	     g2_tot[pos]->SetPoint(1,Z2,B2tot);
	     
	     //cout << "\nz1=" <<  Z1 << ", Bx=" <<  B1x << "pos=" << pos;  
	   }
         }

        }

	
	for(int i=1; i<3; i++)
	{
	        canX->cd(i);
 	        frame_x[i]= gPad->DrawFrame(i-1,-0.05,i+1,0.05);
	        frame_x[i]->SetTitle(Form("%dA_z=%d_Bx",I, i));
		frame_x[i]->SetXTitle("z[mm]");
	        frame_x[i]->SetYTitle("Magnetic field X[T]");

        	g1_x[i]->Draw("P");
		g2_x[i]->Draw("P sames");

		canY->cd(i);
		frame_y[i]= gPad->DrawFrame(i-1,-0.05,i+1,0.05);
	        frame_y[i]->SetTitle(Form("%dA_z=%d_By",I, i));
		frame_y[i]->SetXTitle("z[mm]");
	        frame_y[i]->SetYTitle("Magnetic field Y[T]");
                g1_y[i]->Draw("P");
		g2_y[i]->Draw("P sames");

		canZ->cd(i);
		frame_z[i]= gPad->DrawFrame(i-1,-0.05,i+1,0.05);
	        frame_z[i]->SetTitle(Form("%dA_z=%d_Bz",I, i));
		frame_z[i]->SetXTitle("z[mm]");
	        frame_z[i]->SetYTitle("Magnetic field Z[T]");
                g1_y[i]->Draw("P");
		g2_y[i]->Draw("P sames");

		canToT->cd(i);
		frame_tot[i]= gPad->DrawFrame(i-1,0,i+1,2);
	        frame_tot[i]->SetTitle(Form("%dA_z=%d_Btot",I, i));
		frame_tot[i]->SetXTitle("z[mm]");
	        frame_tot[i]->SetYTitle("Magnetic field ToT[T]");
                g1_tot[i]->Draw("P");
		g2_tot[i]->Draw("P sames");
	
	
	
	}
	


}
