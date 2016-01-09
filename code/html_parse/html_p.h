#pragma once

namespace Example
{
    class html_p : public IHtmlParse
    {
        public:
            html_p() = default;

            // 获取标题
            const char* ParseTitle(const char*, int) override;
            // 获取链接
            void ParseUrl(const char*, const char*, int, IAddUrl&) override;
            // 获取图片
            void ParseImg(const char*, const char*, int, IAddUrl&) override;
    };

}

