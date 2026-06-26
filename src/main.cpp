#include <iostream>
#include <router.hpp>
#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char* argv[]){
    router rout(argc, argv);

    if (!rout.hasArg("--path") or !rout.hasArg("--temp")) {
        std::cout << "Please, use flags --path, --temp" << std::endl;
        return 1;
    }
    fs::path path = rout.getArg("--path");
    std::string temp = rout.getArg("--temp");

    fs::path pathTemplate = fs::path("templates") / temp;

    std::cout << "Path: " << path << std::endl;
    std::cout << "Temp: " << temp << std::endl;
    std::cout << "Path to template: " << pathTemplate << std::endl;

    return 0;
}