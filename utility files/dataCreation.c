#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>

//#define ARRAYSIZE 5

int64_t int_pow(int64_t, int64_t);

int main(int argc, char *argv[]){

	int ARRAYSIZE = 50;


	int64_t A[ARRAYSIZE][ARRAYSIZE];
	int64_t B[ARRAYSIZE][ARRAYSIZE];
	int64_t C[ARRAYSIZE][ARRAYSIZE];

	int64_t lower = -15;//-32768;	// -2^15
	int64_t upper = 15;//32767;	// 2^15 - 1

	printf("#MaxInt = %ld, MinInt = %ld\r\n", upper, lower);
	printf("#ArraySize = %d\r\n\r\n", ARRAYSIZE);

	srand(time(NULL));

	for (int i = 0; i < ARRAYSIZE; i++){
		for (int j = 0; j < ARRAYSIZE; j++){
			A[i][j] = (rand() % (upper - lower + 1)) + lower;
			B[i][j] = (rand() % (upper - lower + 1)) + lower;
			C[i][j] = (rand() % (upper - lower + 1)) + lower;
		}
	}

	printf("\t.data\r\n\r\n");

	printf("A:\t");
	for (int i = 0; i < ARRAYSIZE; i++){
		for (int j = 0; j < ARRAYSIZE; j++){
			printf(".word %ld\r\n", A[i][j]);
		}
	}
	printf("\r\n");

	printf("B:\t");
        for (int i = 0; i < ARRAYSIZE; i++){
                for (int j = 0; j < ARRAYSIZE; j++){
                        printf(".word %ld\r\n", B[i][j]);
                }
        }
	printf("\r\n");

	printf("C:\t");
        for (int i = 0; i < ARRAYSIZE; i++){
                for (int j = 0; j < ARRAYSIZE; j++){
                        printf(".word %ld\r\n", C[i][j]);
                }
        }
	printf("\r\n");



}



int64_t int_pow(int64_t base, int64_t exp){
    int64_t result = 1;
    while (exp)
    {
        if (exp % 2)
           result *= base;
        exp /= 2;
        base *= base;
    }
    return result;
}
