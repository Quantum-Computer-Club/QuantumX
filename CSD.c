#include<math.h>
#include<lapacke.h>
void blkcsd(lapack_complex_double* X,lapack_complex_double* U,lapack_complex_double* V,double* Gatey,int N,int size)
{
	int i,j,num,h = 0;
	lapack_complex_double *X11,*X12,*X21,*X22,*V1,*V2,*U1,*U2;
	double *gatey;
	
	X11 = (lapack_complex_double*)malloc(sizeof(lapack_complex_double)*size/2*size/2);
	X12 = (lapack_complex_double*)malloc(sizeof(lapack_complex_double)*size/2*size/2);
	X21 = (lapack_complex_double*)malloc(sizeof(lapack_complex_double)*size/2*size/2);
	X22 = (lapack_complex_double*)malloc(sizeof(lapack_complex_double)*size/2*size/2);
	V1 = (lapack_complex_double*)malloc(sizeof(lapack_complex_double)*size/2*size/2);
	V2 = (lapack_complex_double*)malloc(sizeof(lapack_complex_double)*size/2*size/2);
	U1 = (lapack_complex_double*)malloc(sizeof(lapack_complex_double)*size/2*size/2);
	U2 = (lapack_complex_double*)malloc(sizeof(lapack_complex_double)*size/2*size/2);
	gatey = (double*)calloc(size/2,sizeof(double));
	
	for(num = 0;num < N/size;num++){
		for(i = 0;i < size/2;i++){
			for(j = 0;j < size/2;j++){
				X11[i*size/2+j] = X[(num*size+i)*N+(num*size+j)];
				X12[i*size/2+j] = X[(num*size+i)*N+(num*size+size/2+j)];
				X21[i*size/2+j] = X[(num*size+size/2+i)*N+(num*size+j)];
				X22[i*size/2+j] = X[(num*size+size/2+i)*N+(num*size+size/2+j)];
			}
		}
        LAPACKE_zuncsd(LAPACK_ROW_MAJOR, 'Y', 'Y', 'Y', 'Y', 'N', 'O', size, 
		size/2, size/2, X11, size/2, X12, size/2,
		X21, size/2, X22, size/2, gatey, U1, size/2, U2, size/2, V1, size/2, V2, size/2);
		
		for(i = 0;i < size/2;i++){
			for(j = 0;j < size/2;j++){
				U[(num*size+i)*N+(num*size+j)] = U1[i*size/2+j];
				U[(num*size+size/2+i)*N+(num*size+size/2+j)] = U2[i*size/2+j];
				V[(num*size+i)*N+(num*size+j)] = V1[i*size/2+j];
				V[(num*size+size/2+i)*N+(num*size+size/2+j)] = V2[i*size/2+j];
			}
			Gatey[h++] = gatey[i];
		}	        
	}
	
	free(X11);
	free(X12);
	free(X21);
	free(X22);
	free(V1);
	free(V2);
	free(U1);
	free(U2);
		
}
