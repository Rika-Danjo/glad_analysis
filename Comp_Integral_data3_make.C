void Comp_Integral_data3_make(){
    
	TCanvas *can = new TCanvas("can","can");
	TH1F *frame;
	/*
	TFile *infile1 = TFile::Open("/u/lndgst01/danjo/glad_analysis/data_ana/data3/1000_to_2500/1st/data3_1000To2500.root");
	TTree *exp1 = (TTree*)infile1->Get("tree");
	*/
	
	TFile *infile1 = TFile::Open("/u/lndgst01/danjo/glad_analysis/data_ana/data3/1000_to_2500/2nd/data3_1000To2500.root");
        TTree *exp1 = (TTree*)infile1->Get("tree");
	
	/*
	TFile *infile1 = TFile::Open("/u/lndgst01/danjo/glad_analysis/data_ana/data3/2500_to_1000/1st/data3_2500To1000.root");
	TTree *exp1 = (TTree*)infile1->Get("tree");
	*/
	/*
	TFile *infile1 = TFile::Open("/u/lndgst01/danjo/glad_analysis/data_ana/data3/2500_to_1000/2nd/data3_2500To1000.root");
        TTree *exp1 = (TTree*)infile1->Get("tree");
	*/
	
	double x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, current1, current2, current3, current4, xz1, zz1, xz2, zz2, xz3, zz3, xz4, zz4;
	double B1[4], B2[4], B3[4], B4[4], B1_tot[89];
	exp1->SetBranchAddress("x", &x1);
	exp1->SetBranchAddress("y", &y1);
	exp1->SetBranchAddress("z", &z1);
	exp1->SetBranchAddress("xz", &xz1);
	exp1->SetBranchAddress("zz", &zz1); 
	exp1->SetBranchAddress("Bx", &B1[0]);
	exp1->SetBranchAddress("By", &B1[1]); 
	exp1->SetBranchAddress("Bz", &B1[2]);
	exp1->SetBranchAddress("I", &current1);

        FILE *fp;
	
	//for(int I=1000; I<2500+100; I=I+100){
	  for(int I=2500; I>1000-100; I=I-100){
	
	int pos1=88;
	int pos2=88;
	int pos3=88;
	int j=0;
	int k=0;
	int l=0;
	double B1x[89], B1y[89], B1z[89], B1tot[89];


        
      
  	for(int ev1=0; ev1<exp1->GetEntries(); ev1++)
	{
	  
  	   exp1->GetEntry(ev1);
	   

       if(current1==I && xz1 < (pos1+1) && 1< xz1 ){ 
	     B1x[j] = B1[0];
	     printf("pos1: %d, Bz[]: %f\n", pos1, B1[0]);
	     pos1=pos1-1;
	     j++;
	    
	     }
	 
	}

	//printf("pos1: %f\n", B1x[3]);
	
	
	for(int ev1=0; ev1<exp1->GetEntries(); ev1++)
	{
  	   exp1->GetEntry(ev1+1); 
	
          if(current1==I && z1 < (pos3+1) && 1< z1 ){
	     B1y[k] = B1[1];
	     printf("pos2: %d, Bz[]: %f\n", pos2, B1[1]);
	     pos2=pos2-1;
	     k++;
	    
	   }

	}

	
	for(int ev1=0; ev1<exp1->GetEntries(); ev1++)
	{

	   exp1->GetEntry(ev1+2); 
	   if(current1==I && zz1 < (pos3+1) && 1< zz1 ){

	     B1z[l] = B1[2];
	     printf("pos3: %d, Bz[]: %f\n", pos3, B1[2]);
	     pos3=pos3-1;
	     l++;
	     
	   }
	   	
	}
        //printf("Bx[]: %f, %f\n",  B1x[86], B1x[87]);

        B1tot[0] = sqrt(B1x[0]*B1x[0]+B1y[0]*B1y[0]+B1z[0]*B1z[0]);
       	int n;
	B1tot[n] = sqrt(B1x[n]*B1x[n]+B1y[n]*B1y[n]+B1z[n]*B1z[n]);
	//printf("Btot[]: %f, %f\n",  B1tot[0], B1tot[1]);
	for(int i =1; i<87; i++){
	 
          B1tot[i]=B1tot[i-1]+sqrt(B1x[i]*B1x[i]+B1y[i]*B1y[i]+B1z[i]*B1z[i]);
	 
	}
	
	  //printf("Btot[]: %f, %f\n",  B1tot[85], B1tot[86]);

          fp = fopen("/u/lndgst01/danjo/glad_analysis/data_ana/data3/data3_exp2_Integral_From0To10.dat","a");
          fprintf(fp,"%d %f\n", I, B1tot[10]);
          //fclose(fp);

	}

}
