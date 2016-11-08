#include <stdio.h>
#include <stdlib.h>
#include <complex.h> 
#include <lapacke.h>
#include <math.h> 
#include "sub.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	
	FILE *fp;
	int N,i,j,n,*index_table,*GATEY_N,*GATEZ_N,size,level,index;
	double x,y,**GATEY,**GATEZ,**GATEPHASE,*Gatey;
	lapack_complex_double **Matrix1,**Matrix2,*U,*V;


	if((fp = fopen("matclx.txt","r"))==NULL)
	    printf("The file does not exist!\n");
	else{
		fscanf(fp,"%d",&N);
		n = (int)(log(N)/log(2));
		size = N;
		Matrix1 = (lapack_complex_double**)malloc(sizeof(lapack_complex_double*));
		GATEY = (double**)malloc(sizeof(double*)*(N-1));
		GATEZ = (double**)malloc(sizeof(double*)*(N-1));
		GATEPHASE = (double**)malloc(sizeof(double)*(n+1));
		index_table = (int*)malloc(sizeof(int)*(N-1));
		GATEY_N = (int*)malloc(sizeof(int)*(N-1));
		GATEZ_N = (int*)malloc(sizeof(int)*N);

        Matrix1[0] = (lapack_complex_double*)malloc(sizeof(lapack_complex_double)*N*N);
		for(i = 0;i < N;i++){			
			for(j = 0;j < N;j++){
				fscanf(fp,"%lf",&x);
				fscanf(fp,"%lf",&y);
				Matrix1[0][i*N+j] = lapack_make_complex_double(x,y);
			}
		}
		fclose(fp); 
		        
        for(level = 1;level <= n;level++){
		    Matrix2 = (lapack_complex_double**)malloc(sizeof(lapack_complex_double*)*N/size*2);  
			for(i = 0;i < N/size;i++){
		        U = (lapack_complex_double*)calloc(N*N,sizeof(lapack_complex_double));
	            V = (lapack_complex_double*)calloc(N*N,sizeof(lapack_complex_double));
	            Gatey = (double*)calloc(N/2,sizeof(double));
				blkcsd(Matrix1[i],U,V,Gatey,N,size);
				free(Matrix1[i]);
				Matrix2[i*2] = U;
				Matrix2[i*2+1] = V;
				index = (int)pow(2,n-level)*(2*i+1)-1;
				GATEY[index] = Gatey;
				index_table[index] = size/2;
			}
			size = size/2;
			free(Matrix1);
			Matrix1 = Matrix2;   	                    	
		}
		
		
		for(i = 0;i < N;i++){
			GATEZ[i] = (double*)malloc(sizeof(double)*N/2);
		}
		for(i = 0;i <= n;i++){
			GATEPHASE[i] = (double*)malloc(sizeof(double)*N/2);
		}
	        GZ_AND_GP(Matrix1,GATEZ,GATEPHASE,index_table,GATEZ_N,GATEY_N,N);
		output_txt(GATEY,GATEY_N,GATEZ,GATEZ_N,GATEPHASE,N,n);
		
	}
	
	return 0;
}
