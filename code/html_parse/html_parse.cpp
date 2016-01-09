#include "std.h"
#include "html_p.h"

extern "C"
{
    IHtmlParse& GetWorkInf(int i1, int i2)
    {
    static html_p obj;
    return obj;
    }
}
