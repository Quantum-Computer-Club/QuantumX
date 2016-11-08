QuantumX : main.o CSD.o GZ_AND_GP.o output_txt.o
	gcc -o QuantumX main.o CSD.o GZ_AND_GP.o output_txt.o -L. -llapacke -llapack -lrefblas -lm -lgfortran
main.o : main.c
	gcc -c main.c -I.
CSD.o : CSD.c
	gcc -c CSD.c -I.
GZ_AND_GP.o : GZ_AND_GP.c
	gcc -c GZ_AND_GP.c -I.
output_txt.o : output_txt.c
	gcc -c output_txt.c
