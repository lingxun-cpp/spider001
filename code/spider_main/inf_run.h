#pragma once

namespace Example{
    class Inf_run : public ISpiderMain
    {
        public:
            Inf_run(const char* path_input);
            void Run(const char* domain, const char* key) override;

            string path;
    };
}
