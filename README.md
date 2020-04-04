# Programming Assignment 1

During the first lab, you are learning/practising how to accelerate an application on a CPU. The application in this assignment is matrix multiplication. Given a vector `v` with `n` elements, a matrix `M` with `n × n` elements,  `matrix.c` computes the product vector `r[n] = v[n] × M[n × n]`. In the follwing exercises do not make assumption about the value of `n`

# Exercise 1
Optimize the application so that the matrix multiplication is cache friendly. Mesaure and report the execution time.

## Exercise 2
Extend the application to compute the `r[n] = A[n x n] × B [n × n]`. Mesaure and report the execution time. 

## Exercise 
Using Pthreads library parallelize the application. You should now be able the application as:
```
./matrix.exe <number of threads> <value of n>
```



## Exercise 5
GCC auto vectorize options in the compilation. Mesaure and report the execution time after GCC auto vectorization.
