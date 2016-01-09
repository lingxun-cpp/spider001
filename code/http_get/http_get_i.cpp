#include "std.h"
#include "http_get.h"
using namespace Example;

        extern "C"
    {
        IHttpGet& GetWorkInf(const char* path)
        {
            static http_get s_Inf(GetDLLWorkInf<INetAction>("net_action", path));
            return s_Inf;
        }
    }

