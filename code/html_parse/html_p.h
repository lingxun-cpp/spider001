#pragma once

namespace Example
{
    class html_p : public IHtmlParse
    {
        public:
            html_p() = default;

            // ��ȡ����
            const char* ParseTitle(const char*, int) override;
            // ��ȡ����
            void ParseUrl(const char*, const char*, int, IAddUrl&) override;
            // ��ȡͼƬ
            void ParseImg(const char*, const char*, int, IAddUrl&) override;
    };

}

