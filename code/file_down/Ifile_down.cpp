#include "std.h"
#include "Ifile_down.h"

Ifile_down::Ifile_down(const char* path_input){
    path = path_input;
}

bool Ifile_down::SetDomain(const char* domain){
    domain_sohu = domain;
    return true;
}

bool Ifile_down::DownFile(const char* SyncHttpGet, int len){
    string sSub =  path + "/downfile/";
    //get title
    string title = GetDLLWorkInf<IHtmlParse>("html_parse", path.c_str()).ParseTitle(SyncHttpGet, len);
    //judge title
    title = GetDLLWorkInf<IUtilAction>("util_action", path.c_str()).FixFileName(title.c_str());
    //save file
    bool bsavefile = SaveDownFile((sSub + title).c_str(), SyncHttpGet, len);
    return bsavefile;
}

bool Ifile_down::SaveDownFile(const char* file, const char* context, int len){
    bool bResult = false;
    try{
        if(nullptr != context && len > 0){
            ofstream f_ofsSave(file, ios_base::out | ios_base::binary | ios_base::trunc);
            f_ofsSave.write(context, len);
            f_ofsSave.close();
            bResult = true;
        }
    }
    catch(std::exception& ex)
    {
    }
    return bResult;
}



