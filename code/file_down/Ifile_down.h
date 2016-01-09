#pragma once

class Ifile_down : public IFileDown
{
    public:
        Ifile_down(const char* path_input);
        bool SetDomain(const char* domain);
        bool DownFile(const char* SyncHttpGet, int len);
        bool SaveDownFile(const char* file, const char* context, int len);

        string path;
        const char* domain_sohu;
};

