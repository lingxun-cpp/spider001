#pragma once

namespace Example
{
    // 文件下载接口
    class IFileDown : public IBase
    {
    public:
        // 设置主域名
		virtual bool SetDomain(const char*) = 0;
        // 设置根路径、网页提取接口
		virtual bool SetRootPath(const char*) = 0;
        // 下载文件
		virtual bool DownFile(const char*, int) = 0;
    };
}
