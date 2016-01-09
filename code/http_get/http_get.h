#pragma once

#include "http_get_i.h"

namespace Example
{
  class http_get:public IHttpGet
  {
  public:
     http_get(INetAction& inetAtion) :m_pacong(inetAtion){};
     const char* SyncHttpGet(int& len, const char* domain, const char* path);
  private:
    INetAction & m_pacong;
  };
}




