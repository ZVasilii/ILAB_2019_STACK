

#ifndef STACKPLUSPLUS_PRINT_FUNCTIONS_H
#define STACKPLUSPLUS_PRINT_FUNCTIONS_H

#include <cstdio>

void Print(long long ValueL);        ///Functions that print variables with different types

void Print(double ValueD);

void Print(char ValueC);

void Print(unsigned long long ValueU);

void Print(int ValueI);

void Print(unsigned ValueU);

void Print(unsigned char ValueUC);



void FilePrint(FILE *file, long long ValueL);  ///Functions that print variables with different types in file

void FilePrint(FILE *file, double ValueD);

void FilePrint(FILE *file, char ValueC);

void FilePrint(FILE *file, unsigned long long ValueU);

void FilePrint(FILE *file, int ValueI);

void FilePrint(FILE *file, unsigned ValueU);

void FilePrint(FILE *file, unsigned char ValueUC);


/**
 * Functions that print variables with different types
 * @tparam T - type of data
 * @param Values with different types
 */

void Print(long long ValueL)
{
    printf(" %lld\n",ValueL);
}

void Print(double ValueD)
{
    printf(" %lg\n", ValueD);
}

void Print(char ValueC)
{
    printf(" %c\n", ValueC);
}

void Print(unsigned long long ValueU)
{
    printf(" %llu\n", ValueU);
}

void Print(int ValueI)
{
    printf(" %d\n", ValueI);
}

void Print(unsigned ValueU)
{
    printf(" %u\n", ValueU);
}

void Print(unsigned char ValueUC)
{
    printf(" %u\n", ValueUC);
}


/**
 * Functions that write variables with different types in file
 * @tparam T - type of data
 * @param Values with different types
 */


void FilePrint(FILE *file, long long ValueL)
{
    fprintf(file," %lld\n", ValueL);
}

void FilePrint(FILE *file, double ValueD)
{
    fprintf(file, " %lg\n", ValueD);
}


void FilePrint(FILE *file, char ValueC)
{
    fprintf(file, " %c\n", ValueC);
}

void FilePrint(FILE *file, unsigned long long ValueU)
{
    fprintf(file, " %llu\n", ValueU);
}


void FilePrint(FILE *file, int ValueI)
{
    fprintf(file, " %d\n", ValueI);
}


void FilePrint(FILE *file, unsigned ValueU)
{
    fprintf(file, " %u\n", ValueU);
}


void FilePrint(FILE *file, unsigned char ValueUC)
{
    fprintf(file, " %u\n", ValueUC);
}

#endif //STACKPLUSPLUS_PRINT_FUNCTIONS_H
