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

      bool AddUrl(const char*, int) override;// ������ӽӿ�


     bool SetDomain(const char* domain) override;// ��������

     const char* GetNextUrl(void) override;// ��ȡ��������

     const char* GetUrlSrvName(const char*) override;// ��ȡ���Ӷ�Ӧ�ķ�������

   private:
      bool AddUrlFirst(const char*, int);// ������ӽӿ�

   private:
     string ss;//��������
     list<string> listvariable;
     int listcount;
     map<string,int> mapbackup;


  };
}
