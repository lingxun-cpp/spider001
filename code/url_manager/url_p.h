#pragma  once
#include <string>
#include <iostream>
#include <list>
#include <map>
#include "base_i.h"
#include "url_manager_i.h"
using namespace std;

namespace Example
{
  class urlclass : public IUrlManager
  {
   public:
     urlclass() = default;
     virtual ~urlclass() = default;

      bool AddUrl(const char*, int) override;// 添加链接接口


     bool SetDomain(const char* domain) override;// 设置域名

     const char* GetNextUrl(void) override;// 获取下条链接

     const char* GetUrlSrvName(const char*) override;// 获取链接对应的服务器名

   private:
      bool AddUrlFirst(const char*, int);// 添加链接接口

   private:
     string ss;//保存域名
     list<string> listvariable;
     int listcount;
     map<string,int> mapbackup;


  };
}
