#pragma once
#include <string>
#include <vector>

class router
{
private:
    int argc;
    std::vector<std::string> argv;
public:
    router(int argc, char* argv[]);
    bool hasArg(const std::string& arg);
    std::string getArg(const std::string& arg);
};