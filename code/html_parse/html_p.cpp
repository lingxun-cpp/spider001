#include <iostream>
#include <regex>
#include "std.h"
#include "html_p.h"
using namespace std;
using namespace Example;

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
void html_p::ParseUrl(const char*, const char* s, int, IAddUrl&)
{
    string str = s;
    regex pattern("href=('|\")(http://)?(\\w+\\.)*(\\w*/)*",regex::icase);
    for (sregex_iterator it(str.cbegin(), str.cend(), pattern), end_it; end_it != it; ++it)
    {
        string msg = it->str();
        msg = msg.substr(5, msg.size() -6);
        cout <<msg<<endl;
    }
}

// 获取图片
void html_p::ParseImg(const char*, const char* s, int, IAddUrl&)
{
    string str = s;
    regex pattern("src=('|\")(http://)?(\\w+\\.)*(\\w*/)*\\w+\\.(jpg|png|gif)('|\")",regex::icase);
    for (sregex_iterator it(str.cbegin(), str.cend(), pattern), end_it; end_it != it; ++it)
    {
        string msg = it->str();
        msg = msg.substr(5, msg.size() -6);
        cout <<msg<<endl;
    }
}

