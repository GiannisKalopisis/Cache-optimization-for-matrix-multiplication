# Cache-optimization-for-matrix-multiplication
This project is a matrix multiplication program in MIPS assembly language with cache optimizations techniques, using EduMIPS64 assembly simulator and DineroIV cache emulator. This project was implemented as part the course of Computer Architecture 2 at University of Athens.


## Purpose of the program
The program executes the operation `X = X + YZ`, where X[i][j], Y[i][j], Z[i][j] are random square tables (8 bytes of each integer - X, Y, Z are stored in the data part of the program from scratch) with dimensions 50x50 (i.e. i, j = 0, 1, ..., 49) and after completing operation X = X + YZ, calculates the number of negative (n), zero (z) and positive (p) numbers. In the end it prints these three results in one line. We must **minimize the runtime of the program**. This year also **includes the failures of the two-level cache L1 and L2**.


## Simulation procedure
The process we follow to investigate the best possible combination of code and cache memory is:
  - Run the code in the EduMIPS simulator
  - Extract the tracefile of the memory accesses (commands and data) from EduMIPS64
  - Pass tracefile to the DineroIV cache simulator, with the desired parameters (for the least possible cache misses).

## Cache parameters
The parameters we selected (according to our needs and the limitations of the course project) are:
  - Unified L1 Cache
  - L1 Cache size: 32 KB
  - L1 Cache block size: 16 words (8 bytes)
  - L1 Cache associativity: direct (1-way)
  - L2 Cache size: 64 KB
  - L2 Cache block size: 16 words (8 bytes)
  - L2 Cache associativity: 4-way
  
  
## Multiplication Algorithm
For the multiplication of tables, we implemented the standard multiplication algorithm with complexity O(n^3), with as many hardcoded optimizations as possible according to the data. Implementing a more efficient algorithm with smaller complexity would add more commands and make the code size much larger and also the size of the table is not power of 2, so we cannot effectively apply the Strassen algorithm.

If the tables are resized, the corresponding variables within the code must also be changed to fit the new data.


## Utilities Files
- **Data Creation**: creates 3 matrix with size 50x50 filled with 64 bits unsigned integers.
- **Command Creation**: creates all possible DineroIV command-arguments (according to project needs). It can be easily modified for your specific needs.
- **Time Counter**: according to the parameters we choose for the L1 and L2 caches, we also have small speed charges at clock, as does a real processor. This program calculates the final execution time of the program according to EduMIPS64 cycles, DineroIV penalty cycles from cache misses and clock speed charges.


## Results
- **Total number of commands executed**: 1.157.792
- **Total clock cycles for full program execution** (EduMIPS64 + DineroIV): 1.572.395
- **CPI** (EduMIPS64 + DineroIV): 1.358098
- **Hit rate of L1 Cache**: 0.995
- **Hit rate of L2 Cache**: 0.6884


## Penalties
Depending on the size of the cache, the block size, and the associativity we have charges on the clock of the processor. Also depending on the miss at each cache level (L1 and L2 in our case) we also have extra clock cycles as a penalty, which is essentially the time that data or commands needs to come from the next memory level.


## Simulators

### EduMIPS64
EduMIPS64 simulator was used to simulate a MIPS64 architecture processor. You can run the included jar file of EduMIPS64 with command `java -jar edumips64-1.2.6-standalone.jar` or download the latest version from  [EduMIPS64 website](https://www.edumips.org/).


### DineroIV
DineroIV emulator was used to simulate cache memories. You can use the included DineroIV version for Linux or you can use the latest version [DineroIV (Windows) website](http://pages.cs.wisc.edu/~markhill/DineroIV/) for Windows and at [DineroIV (Linux) website](http://www.dejazzer.com/coen4730/doc/hw2_cache_dinero.pdf?fbclid=IwAR2l6o3jjcisqqeclnhKZtuRjYJBjeTD0JsRCg7uZwDM-UKuY7OMkuoIvY8) for Linux.

An execution example for Linux: `./dineroIV (options) < trace_file_name` or use the command creation file to see more examples.
