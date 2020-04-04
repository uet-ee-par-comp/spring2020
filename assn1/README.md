# Programming Assignment 1

During the first lab, you are learning/practising how to accelerate an application on a CPU. The application in this assignment is matrix multiplication. Given a vector `v` with `n` elements, a matrix `M` with `n × n` elements,  `matrix.c` computes the product vector `r[n] = v[n] × M[n × n]`. The application can be compiled as 

```
gcc -lm matrix.c -o matrix.exe
```

To run the applicattion use the following command:

```
./matrix.exe <value of n>
```
In all the exercises, DONOT MAKE ANY ASSUMPTION ABOUT THE VALUE OF n. Select a reasonable value of `n` so that the application exectues for few seconds so that you can observe the speedup achieved by accelerating the application,  On my computer the sequential time of given application is about 3.5 seconds for `n = 10000`. Explicitly mention the value of `n` and the number of threads while reporting the results. To ensure the correctness always compare the parallel and sequential results as done in the given application.  
 
## Exercise 1
Run the application and report the sequential execution then. Optimize the application so that the matrix multiplication is cache friendly. Measure and report the execution time after the optimization. 

## Exercise 2
Extend the application to compute the `r[n] = A[n x n] × B [n × n]`. Mesaure and report the sequential execution time. 

## Exercise 3
Using Pthreads library parallelize the application. You should now be able the application as:
```
./matrix.exe <value of n>  <number of threads>
```
Measure and report the parallel execution time with the maximum hardware threads of your CPU.

## Exercise 4
Parallelize the application using OPENMP.  Measure and report the parallel execution time with the maximum hardware threads of your CPU.

## Exercise 5
Extend the parallelized application of Exercise 4 to vectorize the matrix multiplication using AVX2. The applcation should be multithreaded with OPENMP and vectorized AVX2. Measure and report the parallel execution time with the maximum hardware threads of your CPU.


## Exercise 6
Extend the pthreaded application of Exercise 3 to vectorize the matrix multiplication using ISPC. The applcation should be multithreaded with pthreads and vectorized ISPC. Measure and report the parallel execution time with the maximum hardware threads of your CPU.

## Exercise 7
Use GCC auto vectorize options for compiling the application of Exercise 4. Mesaure and report the execution time after GCC auto vectorization.

## Submitting the assignment
Submit the assignment as a single ZIP file. Name the file as `prog_assn_1_<your roll number>`. The zip file must contain different directories for the abover exercises and a single PDF file that contains the measurement results. 

