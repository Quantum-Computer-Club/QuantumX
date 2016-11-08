# QuantumX
 
---
This is C implementation of the CSD algorithm. 
Coded by Zengrong Zhou (zrzhou). 
 
---
This program decomposed the unitary matrix stored in a row-major way in matclx into control-u gates and single qubit gates.

Basic Usage
---
First, in order to get the executable file, please make the source code, you can get a program named QuantumX.

Then you can put the unitary matrix into matclx.txt, the format of which is:

	Dimension-Of-Unitary-Matrix
	Real-Part-Of-1st-Matrix-Element Imaginary-Part-Of-1st-Matrix-Element
	. . .
	Real-Part-Of-Last-Matrix-Element Imaginary-Part-Of-Last-Matrix-Element

For instance, a 2x2 identity matrix can be shown as:

	2
	1.0 0.0
	0.0 0.0
	0.0 0.0
	1.0 0.0

As the last step, run QuantumX, the decomposed quantum gates are given in GATES.txt :)

Currently Working On
---
By inputing an arbitrary unitary matrix, our program is supposed to output a quantum program understandable by IBM Quantum Experience (Quantum Score Source Code).

Notice
---
QuantumX should be working fine on Linux.

If the program cannot be made correctly, you should build a lapack library in your computer.

You can download the source code of lapack library from "http://www.netlib.org/lapack/".

You must build those three files "liblapack.a liblapacke.a librefblas.a", and replace the file in the directory of QuantumX.

References
---
1. Quantum Circuits for General Multiqubit Gates  (get the algorithm)
DOI: 10.1103/PhysRevLett.93.130502

2. Qcompiler: Quantum compilation with the CSD method  (get the test data-matclx)
DOI: 10.1016/j.cpc.2012.10.019

