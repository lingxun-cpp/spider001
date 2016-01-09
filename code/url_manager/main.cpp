#include "url_p.h"
using namespace Example;

extern "C"
{

    IUrlManager& GetWorkInf(void)
    {
       static urlclass  obj;
       return obj;
    }


}
