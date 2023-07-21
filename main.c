#include <stdio.h>
#include "compiler.h"

int main()
{
    int res = compile_file("./tests/test.c","./tests/test",0);
    if(res == COMPILER_FAILED_WITH_ERRORS)
    {
        printf("Error: Could not compile file\n");
        return 1;
    }
    else if (res == COMPILER_FILE_COMPILED_OK)
    {
        printf("File compiled successfully\n");
    }
    else
    {
        printf("Error: Unknown error\n");
        return 1;
    }




    return 0;
}