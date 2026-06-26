#include <iostream>
#include <router.hpp>
#include <projGenerator.hpp>
#include <filesystem>

namespace fs = std::filesystem;

int main(int argc, char* argv[]){
    router rout(argc, argv);

    if (!rout.hasArg("--path") or !rout.hasArg("--temp") or !rout.hasArg("--name")) {
        std::cout << "Please, use flags --path, --temp, --name" << std::endl;
        return 1;
    }
    fs::path path = rout.getArg("--path");
    std::string temp = rout.getArg("--temp");
    std::string name = rout.getArg("--name");

    fs::path pathTemplate = fs::path("templates") / temp;

    std::cout << "Path: " << path << std::endl;
    std::cout << "Temp: " << temp << std::endl;
    std::cout << "Path to template: " << pathTemplate << std::endl;
    std::cout << "Name of project: " << name << std::endl;

    projGenerator generator(name, pathTemplate, path);
    generator.genProj();

    return 0;
}