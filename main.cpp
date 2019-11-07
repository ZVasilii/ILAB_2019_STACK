/**   \brief   This program is a model of Stack
 *    (Visit Wikipedia for more information)
 *    https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
 *
      \author  Zaitsev Vasilii, MIPT
      \version 4.0
      \date    November 2019

      \warning Use the  stack functions in following order:
      ***
             check_errors = Stack.<FUNCTION_NAME>;
             if (!check_errors) Stack.ERRORMANAGE(Stack.<OK FUNCTION>);
      ***
             You can use different data types in this stack
      ***

*/



#include "STACK_FUNCTIONS_DECLARATION.h"


typedef int DATATYPE;               ///Changing type of data

int main()
{
    bool check_errors = false;
    DATATYPE Value = ZERO;
    StackDyn_t<DATATYPE> Stack;    ///Creating stack

    ///Testing function INIT

    check_errors = Stack.STACK_INIT();
    if (!check_errors) Stack.ERRORMANAGE(Stack.OK_INIT_PUSH());


    ///Testing function PUSH

    srand(time(nullptr));
    for (int i = 0; i < 10; i++)
    {
       check_errors = Stack.PUSH(rand() % 100000);
       if (!check_errors) Stack.ERRORMANAGE(Stack.OK_INIT_PUSH());
    }

    ///Testing functions DUMP and DUMP_IN_FILE

    Stack.DUMP();
    Stack.DUMP_IN_FILE();

    ///Testing function POP

    for (int j = 0; j < 10; j++)
    {
        check_errors = Stack.POP(&Value);
        if (!check_errors) Stack.ERRORMANAGE(Stack.OK_POP());
        printf("Popped element is ");
        Stack.Print( Value);
        printf("\n");
    }


    ///Testing function DESTROY

    check_errors = Stack.STACK_DESTROY();
    if (!check_errors) Stack.ERRORMANAGE(Stack.OK_DESTROY());

    return 0;
}

