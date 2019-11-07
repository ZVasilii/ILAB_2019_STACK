#include <cstddef>
#include <cstdlib>
#include <cstdio>
#include <ctime>

const int ZERO = 0;
const int STACK_CAPACITY = 10;                                             ///Maximum size of stack
const int CANARYETALON1 = 127483224;                                     ///Constant - canary1
const int CANARYETALON2 = 159387223;                                     ///Constant - canary2
const char FILENAME[] = "F:\\Projects on C\\STACKPLUSPLUS\\DUMP.txt";    ///File with dumped information


template<typename T>
class StackDyn_t
{
private:

    int CANARY1_;                       ///Canary #1
    T *data_;                           ///Pointer on data, which contained in stack
    size_t size_;                       ///Current size of stack
    size_t capacity_;                   ///Maximum capacity of stack
    int hash_;                          ///Hash, which calculates on every step

    int COUNTHASH();                    ///Function that calculates hash

public:

    bool PUSH(T value);                 ///Function that pushes data INTO stack

    bool POP(T *Value);                 ///Function that pulls data FROM stack

    bool STACK_INIT();                  ///Function that creates stack and initialize it

    bool STACK_DESTROY();               ///Function that deletes stack and frees memory

    char OK_POP();                      ///Function that checks if everything is working correctly

    char OK_INIT_PUSH();                 ///Function that checks if everything is working correctly

    char OK_DESTROY();                   ///Function that checks if everything is working correctly

    void DUMP();                         ///Function that shows all current information about stack

    void DUMP_IN_FILE();                 ///Function that write all current information about stack in file

    void ERRORMANAGE(char Errorcode);    ///Function that shows information about different errors in stack



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

private:
    int CANARY2_;                               ///Canary #2
};

#include "STACK_FUNCTIONS.h"                    ///Header file with all functions









