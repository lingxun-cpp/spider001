#pragma once

namespace Example
{
    // �ļ����ؽӿ�
    class IFileDown : public IBase
    {
    public:
        // ����������
		virtual bool SetDomain(const char*) = 0;
        // ���ø�·������ҳ��ȡ�ӿ�
		virtual bool SetRootPath(const char*) = 0;
        // �����ļ�
		virtual bool DownFile(const char*, int) = 0;
    };
}
