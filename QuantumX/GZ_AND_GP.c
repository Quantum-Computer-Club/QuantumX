#include<math.h>
#include<lapacke.h>
void GZ_AND_GP(lapack_complex_double **Matrix,double **GATEZ,double **GATEPHASE,int *index_table,int *GATEZ_N,int *GATEY_N,int N)
{
	int i,j,k,order,len,m,p1,p2;
	double *phase,phase1,phase2;
	
	phase = (double*)calloc(N,sizeof(double));
	for(i = 0;i < N-1;i++){
		len = index_table[i];
		m = (int)(log(len)/log(2));
		order = 0;
		GATEZ_N[i] = m;
		GATEY_N[i] = m;
		for(j = 0;j < N/len/2;j++){
			for(k = 0;k < len;k++){
			    p1 = j*len*2+k;
			    p2 = j*len*2+k+len;
				phase1 = atan2(lapack_complex_double_imag(Matrix[i][p1*N+p1]),lapack_complex_double_real(Matrix[i][p1*N+p1]));
				phase2 = atan2(lapack_complex_double_imag(Matrix[i][p2*N+p2]),lapack_complex_double_real(Matrix[i][p2*N+p2]));
				phase1 = phase1 + phase[p1];
				phase2 = phase2 + phase[p2];
				GATEZ[i][order] = (phase1-phase2)/2;
				phase[p1] = (phase1+phase2)/2;
				phase[p2] = (phase1+phase2)/2;
				order = order + 1;
			}
		}
	}
	
	for(i = 0;i < N;i++){
		phase1 = atan2(lapack_complex_double_imag(Matrix[N-1][i*N+i]),lapack_complex_double_real(Matrix[N-1][i*N+i]));
		phase[i] = phase[i] + phase1;		
	}

	m = 0;
	for(i = 1;i < N;i=i*2){
		j = 0;
		k = 0;
		while(j < N){
			GATEPHASE[m][k] = phase[j+i];
		    phase[j] = phase[j] + phase[j+i];
		    j = j + i*2;
		    k++;
		}
		m++;
	} 
	GATEPHASE[m][0] = phase[0];
	
	
}
