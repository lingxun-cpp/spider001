#include "std.h"
#include "util_action.h"

////////////////////////////////////////////////////////////////////////////////
extern "C"
{
	IUtilAction& GetWorkInf(void)
	{
	    static CUtilAction s_Inf;
	    return s_Inf;
	}
}

////////////////////////////////////////////////////////////////////////////////
// CUtilAction类
// 创建目录
bool CUtilAction::CreateDir(const char* dir)
{
    bool bResult = false;
    if (nullptr != dir)
    {
        try
        {
            if (!filesystem::exists(dir))
                filesystem::create_directories(dir);
            bResult = true;
        }
        catch (std::exception& ex)
        {
            cout << ex.what() << endl;
        }
    }
    return bResult;
}

// 修正非法文件名字符
const char* CUtilAction::FixFileName(const char* fn)
{
    const char* pResult = nullptr;
    if (nullptr != fn)
    {
        m_result = fn;
        replace_all(m_result, "\"", "_");
        replace_all(m_result, "\\", "_");
        replace_all(m_result, "/", "_");
        replace_all(m_result, ":", "_");
        replace_all(m_result, "*", "_");
        replace_all(m_result, "?", "_");
        replace_all(m_result, "|", "_");
        replace_all(m_result, "<", "_");
        replace_all(m_result, ">", "_");
        pResult = m_result.c_str();
    }
    return pResult;
}
