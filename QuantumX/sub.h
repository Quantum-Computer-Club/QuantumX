#include<lapacke.h>
void blkcsd(lapack_complex_double* X,lapack_complex_double* U,lapack_complex_double* V,double* Gatey,int N,int size);
void GZ_AND_GP(lapack_complex_double **Matrix,double **GATEZ,double **GATEPHASE,int *index_table,int *GATEZ_N,int *GATEY_N,int N);
void output_txt(double **GATEY,int *GATEY_N,double **GATEZ,int *GATEZ_N,double **GATEPHASE,int N,int n);
