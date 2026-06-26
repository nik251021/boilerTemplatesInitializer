#pragma once
#include <string>
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

class projGenerator
{
private:
    std::string projName;
    fs::path tempPath;
    fs::path targetPath;
    void pasteTemplate();
    void refactorTemplate();
    
public:
    projGenerator(const std::string& projName, fs::path tempPath, fs::path targetPath);
    void genProj();
};