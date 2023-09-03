#pragma once

#include <string>

namespace MBEngine::core
{
    class File
    {
    public:
        File(std::string path);

        std::string getContent() const;
    private:
        std::string path_;
    };
} // namespace MBEngine::core
