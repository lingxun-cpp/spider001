#include "std.h"
#include "inf_run.h"

Inf_run::Inf_run(const char* path_input){
    path = path_input;
}

void Inf_run::Run(const char* domain, const char* key){
    try
    {
        IUrlManager& Url = GetDLLWorkInf<IUrlManager >("url_manager", path.c_str());       //SetDomain
        Url.SetDomain(domain);
        //GetNextUrl
        const char* next_url = nullptr;
        //if nexturl exist, do circle
        while(nullptr != (next_url = Url.GetNextUrl())){
            int len = 0;
            //SyncHttpGet
            const char* SyncHttpGet = GetDLLWorkInf<IHttpGet>("http_get", path.c_str()).SyncHttpGet(len, domain, next_url);
            //ParseUrl
            GetDLLWorkInf<IHtmlParse>("html_parse", path.c_str()).ParseUrl(domain, SyncHttpGet, len, Url);

            string find_SyncHttpGet = SyncHttpGet;
            if(find_SyncHttpGet.find(key) != string::npos){
                //??
                GetDLLWorkInf<IFileDown>("file_down", path.c_str()).DownFile(SyncHttpGet, len);
            }
        }
    }
    catch (exception ex)
    {
        cout << ex.what() << endl;
    }
};
