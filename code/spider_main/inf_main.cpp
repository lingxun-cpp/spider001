#include "std.h"
#include "inf_run.h"

extern "C"
{
    // A function adding two integers and returning the result
    ISpiderMain& GetWorkInf(const char* path_input)
    {
        static Inf_run obj(path_input);
        return obj;
    }
}

