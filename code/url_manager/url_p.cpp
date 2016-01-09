#include "url_p.h"

using namespace Example;


bool urlclass::AddUrl(const char* addurl, int i)// ������ӽӿ� iΪ���
{
    string sss = addurl;
    if (sss.find(ss) != string::npos)
    {
      return false;
    }
 if(addurl == nullptr && i == 0)
 {
     return false;
 }
 else
 {
     if (mapbackup.find(addurl) == mapbackup.end())
     {
       mapbackup.insert(make_pair(addurl,mapbackup.size()));
       listvariable.push_back(addurl);
     }

    return true;
 }
}

bool urlclass::SetDomain(const char* domain)// ��������
{

   ss = string("www.") + domain;
   AddUrl(ss.c_str(),1);
   return  true;


}

const char* urlclass::GetNextUrl(void)// ��ȡ��������
{
    static string cc = listvariable.front();
    listvariable.pop_front();
    return cc.c_str();
}

const char* urlclass::GetUrlSrvName(const char* name)// ��ȡ���Ӷ�Ӧ�ķ�������
{
    static string sname = name;
    unsigned int iTail = sname.find("//");
    if (iTail != string::npos)
        sname = sname.substr(iTail, sname.size() - iTail);
    iTail = sname.find("/");
    if (iTail != string::npos)
        sname = sname.substr(0, iTail);
  return sname.c_str();
}
