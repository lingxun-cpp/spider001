#pragma once

#include <string>
#include <stdexcept>

#include "load_library.h"

namespace Example
{
    template<typename INF>
    INF& GetDLLWorkInf(const char* DLL)
    {
        std::string sErr;
        static KLoadLibrary<true> lb(DLL, sErr);
        if (!sErr.empty()) throw std::runtime_error(sErr);
        typedef INF& (*FGetWorkInf)(void);
        FGetWorkInf getInf = lb.GetLibFunc<FGetWorkInf>("GetWorkInf", sErr);
        if (!sErr.empty()) throw std::runtime_error(sErr);
        return getInf();
    }
}
