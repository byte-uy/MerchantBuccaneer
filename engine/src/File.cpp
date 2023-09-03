#include "File.h"

#include <fstream>
#include <string>

namespace MBEngine::core
{
    File::File(std::string path) : path_(std::move(path))
    {
    }

    std::string File::getContent() const{ 
        std::ifstream file(path_);
        try
        {
            std::string content((std::istreambuf_iterator<char>(file)),
                                std::istreambuf_iterator<char>());
            return content;
        }
        catch (std::exception& e) 
        {
            throw std::runtime_error("Error reading file in path " + path_ + ": " + e.what());
        }

    }
}  // namespace MBEngine::core
