*************************************************
*   This is c implementation of CSD algorithm.  *
*   Made by zrzhou.                             *
*************************************************

This program decomposed the unitary matrix stored in a row-major way in matclx into control-u gates and single qubit gates.

Reference:
1.Quantum Circuits for General Multiqubit Gates  (get the algorithm)
  DOI: 10.1103/PhysRevLett.93.130502
2.Qcompiler: Quantum compilation with the CSD method  (get the test data-matclx)
  DOI: 10.1016/j.cpc.2012.10.019

Attention:
If the program cannot be made correctly, you should build a lapack library in your computer.
You can download the source code of lapack library from "http://www.netlib.org/lapack/".
You must build those three files "liblapack.a liblapacke.a librefblas.a", and replace the file in the directory of QuantumX.
