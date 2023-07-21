#include "compiler.h"

int compile_file (const char* filename,const char* filenameout,int flags)
{
    struct compilerprocess * process =compiler_process_create(filename,filenameout,flags);
    if(!process)
    {
        return COMPILER_FAILED_WITH_ERRORS;
    }

    // preform lexical analysis

    // preform parsing

    // preform code generation


    return COMPILER_FILE_COMPILED_OK;
}
