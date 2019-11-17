#ifndef STACKPUSPLUS_STACK_FUNCTIONS_H
#define STACKPUSPLUS_STACK_FUNCTIONS_H


#include "STACK_ERRORS.h"

#include "PRINT_FUNCTIONS.h"             ///Header file with print functions

/**
 * Function that creates stack and initialize it
 * @tparam T - type of data
 * @return true if everything works fine, false if errors occurred
 */

template<typename T>
bool StackDyn_t<T>::STACK_INIT()
{
    srand(time(NULL));
    capacity_ = STACK_CAPACITY;
    size_ = ZERO;
    data_ = (T *) calloc(STACK_CAPACITY, sizeof(T));
    hash_ = COUNTHASH();
    CANARYREF1 = rand() % 100000000;
    CANARYREF2 = rand() % 100000000;
    CANARY1_ = CANARYREF1;
    CANARY2_ = CANARYREF2;
    if (OK_W_O_SIZE())
        return false;
    return true;
}


/**
 * Function that deletes stack and frees memory
 * @tparam T - type of data
 * @return true if everything works fine, false if errors occurred
 */

template<typename T>
bool StackDyn_t<T>::STACK_DESTROY()
{
    if (OK())
        return false;
    free(data_);
    size_ = ZERO;
    hash_ = COUNTHASH();
    if (OK_W_O_SIZE_POINTER())
        return false;
    return true;
}


/**
 * Function that pushes data INTO stack
 * @tparam T - type of data
 * @param Value - value which will be pushed into stack
 * @return true if everything works fine, false if errors occurred
 */

template<typename T>
bool StackDyn_t<T>::PUSH(T Value)
{
    if (OK_W_O_SIZE())
        return false;
    this->data_[this->size_] = Value;
    this->size_++;
    hash_ = COUNTHASH();
    if (OK_W_O_SIZE())
        return false;
    return true;
}


/**
 * Function that pulls data FROM stack
 * @tparam T - type of data
 * @param *Value - pointer on value which pulled from stack
 * @return true if everything works fine, false if errors occurred
 */

template<typename T>
bool StackDyn_t<T>::POP(T *Value)
{
    if (OK())
        return false;
    *Value = this->data_[this->size_ - 1];
    this->size_--;
    hash_ = COUNTHASH();
    if (OK_W_O_SIZE())
        return false;
    return true;
}

/**
 * Function, that calculates hash
 * @tparam T - type of data
 * @return Value of calculated hash
 */

template<typename T>
int StackDyn_t<T>::COUNTHASH()
{
    return ((unsigned long long)((int) data_ * (int) data_ + capacity_ - 1923 * size_ % 24 * (CANARY1_ % 25) * (CANARY2_ % 37)));
}


/**
 * Function that checks if everything is working correctly
 * @tparam T - type of data
 * @return true if everything works fine, false if errors occurred
 */

template<typename T>
char StackDyn_t<T>::OK()
{
    if (this == nullptr) return STACK_POINTER;
    else if (capacity_ == 0) return ZERO_CAPACITY;
    else if (COUNTHASH() != hash_) return ERROR_HASH;
    else if ((CANARY1_ != CANARYREF1) || (CANARY2_ != CANARYREF2)) return ERROR_CANAREES;
    else if (data_ == nullptr) return DATA_POINTER;
    else if (size_ == 0) return STACK_EMPTY;
    else if (size_ > capacity_) return STACK_FULL;
    else return EVERYTHING_GOOD;
}


/**
 * Function that checks if everything is working correctly without checking (size_ == 0)
 * @tparam T - type of data
 * @return true if everything works fine, false if errors occurred
 */

template<typename T>
char StackDyn_t<T>::OK_W_O_SIZE()
{
    if (this == nullptr) return STACK_POINTER;
    else if (capacity_ == 0) return ZERO_CAPACITY;
    else if (COUNTHASH() != hash_) return ERROR_HASH;
    else if ((CANARY1_ != CANARYREF1) || (CANARY2_ != CANARYREF2)) return ERROR_CANAREES;
    else if (data_ == nullptr) return DATA_POINTER;
    else if (size_ > capacity_) return STACK_FULL;
    else return EVERYTHING_GOOD;
}


/**
 * Function that checks if everything is working correctly
 * without checking (size_ == 0) and pointer on data
 * @tparam T - type of data
 * @return true if everything works fine, false if errors occurred
 */

template<typename T>
char StackDyn_t<T>::OK_W_O_SIZE_POINTER()
{

    if (this == nullptr) return STACK_POINTER;
    else if (capacity_ == 0) return ZERO_CAPACITY;
    else if (COUNTHASH() != hash_) return ERROR_HASH;
    else if ((CANARY1_ != CANARYREF1) || (CANARY2_ != CANARYREF2)) return ERROR_CANAREES;
    else if (size_ > capacity_) return STACK_FULL;
    else return EVERYTHING_GOOD;
}


/**
 * Function that shows information about different errors in stack and abort program
 * @tparam T - type of data
 * @param Errorcode - Code of error from function OK()
 */

template<typename T>
void StackDyn_t<T>::ERRORMANAGE(char Errorcode)
{
    if (Errorcode == ZERO_CAPACITY)
    {
        printf("CHECK YOUR STACK CAPACITY!");
        DUMP();
        DUMP_IN_FILE();
        abort();
    } else if (Errorcode == ERROR_HASH)
    {
        printf("CHECK YOUR HASH!");
        DUMP();
        DUMP_IN_FILE();
        abort();
    } else if (Errorcode == ERROR_CANAREES)
    {
        printf("CHECK YOUR CANAREES!");
        DUMP();
        DUMP_IN_FILE();
        abort();
    } else if (Errorcode == DATA_POINTER)
    {
        printf("CHECK YOUR DATA POINTER!");
        DUMP();
        DUMP_IN_FILE();
        abort();
    } else if (Errorcode == STACK_POINTER)
    {
        printf("CHECK YOUR STACK POINTER!");
        DUMP();
        DUMP_IN_FILE();
        abort();
    } else if (Errorcode == STACK_EMPTY)
    {
        printf("YOUR STACK IS EMPTY!");
        DUMP();
        DUMP_IN_FILE();
        abort();
    } else if (Errorcode == STACK_FULL)
    {
        printf("YOUR STACK IS FULL!");
        DUMP();
        DUMP_IN_FILE();
        abort();
    }
}


/**
 * Function that shows all current information about stack
 * @tparam T - type of data
 */

template <typename T>
void StackDyn_t<T>::DUMP()
{
    int Elem = 0;
    printf("\n");
    printf("\n");
    printf("***DUMP***\n");
    printf("\n");
    printf("Pointer on stack: %p\n", this);
    printf("Capacity of stack: %d\n", capacity_);
    printf("Calculated hash: %d\n", abs(hash_));
    printf("Canary 1: %d\n", CANARY1_);
    printf("Canary 2: %d\n", CANARY2_);
    printf("Size of stack: %d\n", size_);
    printf("Pointer on data: %p\n", data_);
    printf("\n");
    for (Elem = 0; Elem < size_; Elem ++)
    {
        printf("Element # %d is ", Elem+1);
        Print(data_[Elem]);
    }
    printf("\n");
    printf("***END OF DUMP***\n");
    printf("\n");
    printf("\n");
}

/**
 * Function that write all current information about stack in file
 * @tparam T
 */

template <typename T>
void StackDyn_t<T>::DUMP_IN_FILE()
{
    int Elem = 0;
    FILE* File = fopen(FILENAME, "w");
    fprintf(File,"\n");
    fprintf(File,"***DUMP***\n");
    fprintf(File,"\n");
    fprintf(File,"Pointer on stack: %p\n", this);
    fprintf(File,"Capacity of stack: %d\n", capacity_);
    fprintf(File,"Calculated hash: %d\n", abs(hash_));
    fprintf(File,"Canary 1: %d\n", CANARY1_);
    fprintf(File,"Canary 2: %d\n", CANARY2_);
    fprintf(File,"Size of stack: %d\n", size_);
    fprintf(File,"Pointer on data: %p\n", data_);
    fprintf(File,"\n");
    for (Elem = 0; Elem < size_; Elem ++)
    {
        fprintf(File, "Element # %d is ", Elem+1);
        FilePrint(File, data_[Elem]);
    }
    fprintf(File,"\n");
    fprintf(File,"***END OF DUMP***\n");
    fprintf(File,"\n");
    fclose(File);

}

#endif //STACKPUSPLUS_STACK_FUNCTIONS_H