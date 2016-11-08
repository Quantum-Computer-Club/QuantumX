#include<stdio.h>
#define PI 3.1415926
void output_txt(double **GATEY,int *GATEY_N,double **GATEZ,int *GATEZ_N,double **GATEPHASE,int N,int n)
{
	FILE *fp;
	int i,j,k=1;
	
	fp = fopen("GATE.txt","w");
	
	fprintf(fp,"GATEPHASE\nControled bit:%d\n",n-1);
	fprintf(fp,"%e\n",GATEPHASE[n][0]/PI);
	for(i = 0;i < n;i++){
	    fprintf(fp,"GATEZ\nControled bit:%d\n",n-i-1);
	    for(j = 0;j < k;j++){
		    fprintf(fp,"%e\n",GATEPHASE[n-i-1][j]/PI);
	    }
		k = k*2;		
	}
	for(i = N-2;i >= 0 ;i--){		
		fprintf(fp,"GATEY\nControled bit:%d\n",GATEY_N[i]);
	    for(j = 0;j < N/2;j++){
		    fprintf(fp,"%e\n",GATEY[i][j]/PI);
	    }				
		fprintf(fp,"GATEZ\nConroled bit:%d\n",GATEZ_N[i]);
	    for(j = 0;j < N/2;j++){
		    fprintf(fp,"%e\n",GATEZ[i][j]/PI);
	    }		
	}

	fclose(fp);
		
}
