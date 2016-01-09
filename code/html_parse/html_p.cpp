#include "std.h"

// 获取标题
const char* html_p::ParseTitle(const char* s, int)
{
    string str = s;
    regex pattern("<title>(\\w*)* </title>",regex::icase);
    for (sregex_iterator it(str.cbegin(), str.cend(), pattern), end_it; end_it != it; ++it)
    {
       static string msg = it->str();
        msg = msg.substr(5, msg.size() -6);
        cout <<msg<<endl;
        return msg.c_str();
    }
}

// 获取链接
void html_p::ParseUrl(const char*, const char* s, int, IAddUrl& url)
{
    string str = s;
    regex pattern("href=('|\")(http://)?(\\w+\\.)*(\\w*/)*",regex::icase);
    for (sregex_iterator it(str.cbegin(), str.cend(), pattern), end_it; end_it != it; ++it)
    {
        string msg = it->str();
        msg = msg.substr(5, msg.size() -6);
        cout <<msg<<endl;
        url.AddUrl(msg.c_str(),msg.size());
    }
}

// 获取图片
void html_p::ParseImg(const char*, const char* s, int, IAddUrl& pic)
{
    string str = s;
    regex pattern("src=('|\")(http://)?(\\w+\\.)*(\\w*/)*\\w+\\.(jpg|png|gif)('|\")",regex::icase);
    for (sregex_iterator it(str.cbegin(), str.cend(), pattern), end_it; end_it != it; ++it)
    {
        string msg = it->str();
        msg = msg.substr(5, msg.size() -6);
        cout <<msg<<endl;
        pic.AddUrl(msg.c_str(),msg.size());
    }
}

