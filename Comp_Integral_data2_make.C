void Comp_Integral_data2_make(int xpos, int I){
  
	TCanvas *can = new TCanvas("can","can");
	TH1F *frame;  

        //TFile *infile1 = TFile::Open("/u/lndgst01/danjo/glad_analysis/data_ana/data2/1000A/1st/data2_1000A.root");//exp1
	//TFile *infile1 = TFile::Open("/u/lndgst01/danjo/glad_analysis/data_ana/data2/1500A/1st/data2_1500A.root");//exp2
        //TFile *infile1 = TFile::Open("/u/lndgst01/danjo/glad_analysis/data_ana/data2/2000A/1st/data2_2000A.root");//exp3
        //TFile *infile1 = TFile::Open("/u/lndgst01/danjo/glad_analysis/data_ana/data2/2500A/data2_2500A.root");//exp4
        //TFile *infile1 = TFile::Open("/u/lndgst01/danjo/glad_analysis/data_ana/data2/2000A/2nd/data2_2000A.root");//exp5
        //TFile *infile1 = TFile::Open("/u/lndgst01/danjo/glad_analysis/data_ana/data2/1500A/2nd/data2_1500A.root");//exp6
        TFile *infile1 = TFile::Open("/u/lndgst01/danjo/glad_analysis/data_ana/data2/1000A/2nd/data2_1000A.root");//exp7
        TTree *exp1 = (TTree*)infile1->Get("tree3");
	
	double x1, y1, z1, xz1, zz1;
	double B1[4], B1_tot[100];
	exp1->SetBranchAddress("x", &x1);
	exp1->SetBranchAddress("y", &y1);
	exp1->SetBranchAddress("z", &z1);
	exp1->SetBranchAddress("xz", &xz1);
	exp1->SetBranchAddress("zz", &zz1); 
	exp1->SetBranchAddress("Bx", &B1[0]);
	exp1->SetBranchAddress("By", &B1[1]); 
	exp1->SetBranchAddress("Bz", &B1[2]);


        FILE *fp;
	

	
	int pos1=88;
	int pos2=88;
	int pos3=88;
	int xpos1=xpos;
	int xpos2=xpos;
	int xpos3=xpos;
	int j=0;
	int k=0;
	int l=0;
	int a;
	double B1x[100], B1y[100], B1z[100], B1tot[100];


        printf("xpos=%d\n",xpos);
      
  	for(int ev1=0; ev1<exp1->GetEntries(); ev1++)
	{
	  
  	   exp1->GetEntry(ev1);

	   switch(xpos1){

	      case 5://<-lab cordinate x=5
	      a=0;
	      //printf("a=%d\n",a);
 	       

	     //To find Magnetic field of setting position
	           if(xz1 < (pos1+1) && 1< xz1 && x1==xpos1){
		    B1x[j]= B1[0];
		    pos1=pos1-1;
		    j++;
		   
		   }
		   break;

	      case -0://<-lab cordinate x=-0
	      a=1;
	      //printf("a=%d\n",a);
           

             //To find Magnetic field of setting position
                   if(xz1 < (pos1+1) && 1< xz1 && x1==xpos1){
                     //printf("a=%d\n",a);
		     B1x[j]= B1[0];
                    pos1=pos1-1;
                    j++;
                   }
		   break;
	      
	      case -5: //<-lab cordinate x=-5
	      a=2;
	      //printf("a=%d\n",a);
	   

              //To find Magnetic field of setting position
                   if(xz1 < (pos1+1) && 1< xz1 && x1==xpos1){
                    B1x[j]= B1[0];
		    pos1=pos1-1;
                    j++;
                   }
		   break;
		 
         }

 
      
	 
	}
	//printf("Bx[]: %f\n",  B1x[1]);
	//printf("pos1: %f\n", B1x[3]);
	
	
	for(int ev1=0; ev1<exp1->GetEntries(); ev1++)
	{
  	   exp1->GetEntry(ev1+1); 


         switch(xpos2){

	      case 5://<-lab cordinate x=5
	      a=0;
	      //printf("a=%d\n",a);
 	       

	     //To find Magnetic field of setting position
	           if(z1 < (pos2+1) && 1< z1 && x1==xpos2){
		    B1y[k]= B1[1];
		    pos2=pos2-1;
		    k++;
		   }
		   break;

	      case -0://<-lab cordinate x=-0
	      a=1;
	      //printf("a=%d\n",a);
           

             //To find Magnetic field of setting position
                   if(z1 < (pos2+1) && 1< z1 && x1==xpos2){
                    B1y[k]= B1[1];
                    pos2=pos2-1;
                    k++;
                   }
		   break;
	      
	      case -5: //<-lab cordinate x=-5
	      a=2;
	      //printf("a=%d\n",a);
	   

             //To find Magnetic field of setting position
                   if(z1 < (pos2+1) && 1< z1 && x1==xpos2){
                    B1y[k]= B1[1];
		    pos2=pos2-1;
                    k++;
                   }
		   break;

	 }

	}

	
	for(int ev1=0; ev1<exp1->GetEntries(); ev1++)
	{

	   exp1->GetEntry(ev1+2);

         switch(xpos3){

	      case 5://<-lab cordinate x=5
	      a=0;
	      //printf("a=%d\n",a);
 	       

	     //To find Magnetic field of setting position
	           if(zz1 < (pos3+1) && 1< zz1 && x1==xpos3){
		    B1z[l]= B1[2];
		    pos3=pos3-1;
		    l++;
		   }
		   break;

	      case -0://<-lab cordinate x=-0
	      a=1;
	      //printf("a=%d\n",a);
           

             //To find Magnetic field of setting position
                   if(zz1 < (pos3+1) && 1< zz1 && x1==xpos3){
                    B1z[l]= B1[2];
                    pos3=pos3-1;
                    l++;
		    //printf("l=%d\n",l);
                   }
		   break;
	      
	      case -5: //<-lab cordinate x=-5
	      a=2;
	      //printf("a=%d\n",a);
	   

             //To find Magnetic field of setting position
                   if(zz1 < (pos3+1) && 1< zz1 && x1==xpos3){
                    B1z[l]= B1[2];
		    pos3=pos3-1;
                    l++;
                   }
		   break;

	 }
	   	
	}
        
	//printf("By[]: %f, %f, %f, %f\n",  B1z[0], B1z[1], B1z[2], B1z[90]);
        B1tot[0] = sqrt(B1x[0]*B1x[0]+B1y[0]*B1y[0]+B1z[0]*B1z[0]);
       

	
	for(int i =1; i<97; i++){
	 
          B1tot[i]=B1tot[i-1]+sqrt(B1x[i]*B1x[i]+B1y[i]*B1y[i]+B1z[i]*B1z[i]);
	 
	}
	
	  //printf("Btot[]: %f, %f, %f, %f\n",  B1tot[0], B1tot[1], B1tot[2], B1tot[3]);
 	  //printf("Btot[86]: %f\n",  B1tot[86]);

	  fp = fopen(Form("/u/lndgst01/danjo/glad_analysis/data_ana/data2/data2_Integral_x%d_From0To10.dat",xpos),"a");
          fprintf(fp,"%d %d %f\n", xpos, I, B1tot[10]);
          fclose(fp);



}
