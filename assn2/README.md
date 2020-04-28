# Programming Assignment 2

In this assignment you have to accelerate an image processing pipeline ona GPU as well as on a CPU: the pipeline takes a color image as its input, converts it to grayscale, uses the image's histogram to enhance the contrast of the grayscale image and eventually returns a smoothed grayscale version of the input image. For simplicity and accuracy all operations are done in floating point. The program must be benchmarked on your laptop CPU and Google Colab GPU. A brief description of the four phases is given below:

## Phase 1: Converting a color image to grayscale
Our input images are RGB images; this means that every color is rendered adding together the three components representing Red, Green and Blue. The gray value of a pixel is given by weighting these
three values and then summing them together. The formula is: gray = 0.3*R + 0.59*G + 0.11*B.

## Phase 2: Histogram computation
The histogram measures how often a value of gray is used in an image. To compute the histogram, simply count the value of every pixel and increment the corresponding counter. There are 256 possible
values of gray.

## Phase 3: Contrast enhancement
The computed histogram is used in this phase to determine which are the darkest and lightest gray values actually used in an image - i.e., the lowest (min) and highest (max) gray values that have
"scored" in the histogram above a certain threshold. Thus, pixels whose values are lower than min are set to black, pixels whose values are higher than max are set to white, and pixels whose values are
inside the interval are scaled.

## Phase 4: Smoothing
Smoothing is the process of removing noise from an image. To remove the noise, each point is replaced by a weighted average of its neighbors. This way, small-scale structures are removed from the image.
We are using a triangular smoothing algorithm, i.e. the maximum weight is for the point in the middle and decreases linearly moving from the center. As an example, a 5-point triangular smooth filter in one
dimension will use the following weights: 1, 2, 3, 2, 1. In this assignment, you will use a two-dimensional 5-point triangular smooth filter.


## Accelerated application
A sequential version of the application is provided, for your convenience, in the directory “sequential”. Please read the code carefully, and try to understand it. There are no assumptions
about the size of the input images, thus the code must be capable of running with color images of any size. The output must match the sequential version; a compare utility is provided to test for this. The
output that you should verify is the final output image, named smooth.bmp. You are free to also save the intermediate images, e.g. for debugging, but do not include the time to write this images in the
performance measurements. In the directory “images”, 16 different images are provided for testing.  Running the makefile in the "sequential" directory will compile and run the sequntial program. Edit the makefile to run the program with a certain image as input. 

 

## Speedup

You have to measure and report several different speedups:

Overall Speedup of CPU implementation = (Total Time of sequential program) / (Total time on CPU)

Overall Speedup of GPU implementation over sequential = (Total Time of sequential program) / (Total time on GPU) 

Overall Speedup of GPU implementation over CPU = (Total Time on CPU) / (Total Time on GPU)

The CPU time is the execution time of the application parallelized on CPU. The total time on GPU must include the memory transfer overhead. Furthermore, the "kernel" is the part of the sequential program that is accelerated on GPU or CPU. You have to also measure and report kernel speedups: 

Kernel speedup of CPU over sequential = (Kernel Execution Time in sequential program) / (kernel exection time in CPU)

Kernel speedup of GPU over sequential = (Kernel Execution Time in sequential program) / (kernel exection time in GPU)

Kernel speedup of GPU over CPU = (Kernel Execution Time in CPU) / (kernel exection time in GPU)


Do not include the printing/debugging etc in timing calculations. The speed up results should be reported for image04, image09 and image15.

## Report
Speedup results are important but we are also interested in the procedure you followed to get those results and
their analysis. In the report, you need to mention at least the following along with the speedup results:

- How you performed the four steps of Decomposition, Assignment, Orchestration and Mapping in creating your parallel application?
- Performance of each GPU kernel indicated on the roofline model.
- Important points regarding implementation strategy. For instance, how did you tackle with the problem of reading/writing to single histogram value in histogram implementation?
- Problems/bottlenecks encountered. For instance how did you tackle the problem of reading/writing to same histogram values in Histogram computations?
- Optimizations performed, e.g. the use of shared memory, did it help or not and why did it help?
- Interesting profiling results to show that the GPU kernels have been optimized sufficiently.
- Compiler options.


## Submitting the assignment
Submit a single ZIP archive with the name `prog_assn_2_<your roll number>.zip` containing your working solution. Check the output images after each step and compare to see if they are correct. Clean the code and do not include images in this archive (as they are too big). Timing calculations and meaningful printing of results should be inside code so that we can verify your reported results by simply running it (without the need to write the timing code ourselves). Put the comments in your code to explain what are you doing, so that we know you understand it.
