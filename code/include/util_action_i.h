#pragma once

namespace Example
{
    // ͨ�ù��ܻ�ӿ�
    class IUtilAction
    {
    public:
        // ����Ŀ¼
		virtual bool CreateDir(const char*) = 0;
        // �����Ƿ��ļ����ַ�
		virtual const char* FixFileName(const char*) = 0;
    };
}
