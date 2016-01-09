#include "std.h"

#include "http_get.h"

//using namespace Example;
/*class IHttpGet::http_get()
{

}*/

const char* http_get::SyncHttpGet(int& len, const char* domain, const char* path)
{
    stringstream request_stream;
    request_stream << "GET " << path << " HTTP/1.1" << endl;
    request_stream << "Content-Type: application/x-www-form-urlencoded" << endl;
    request_stream << "Host: " << domain << endl;
    request_stream << "Connection: Close" << endl;
    request_stream << "Accept: image/gif, image/x-xbitmap, image/jpeg, image/pjpeg, application/x-shockwave-flash, application/vnd.ms-excel, application/msword, */*" << endl;
    request_stream << "User-Agent: Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 2.0.50727)" << endl;
    request_stream << endl;

    int iCount = 0;
    const char* p = m_pacong.SyncRequest(iCount, domain, request_stream.str().c_str());
    static string str;
    str.append(p, iCount);
    return str.c_str();

}
