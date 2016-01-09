#include "std.h"
#include "Ifile_down.h"


extern "C"
{
    // A function adding two integers and returning the result
    IFileDown& GetDLLWorkInf(const char* path_input)
    {
        static Ifile_down obj(path_input);
        return obj;
    }
}
