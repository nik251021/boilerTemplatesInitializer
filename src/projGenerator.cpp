#include <projGenerator.hpp>

void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); 
    }
}

projGenerator::projGenerator(const std::string& projName, fs::path tempPath, fs::path targetPath) {
    this->projName = projName;
    this->tempPath = tempPath;
    this->targetPath = targetPath;
};

void projGenerator::genProj() {
    std::cout << "Generating project from template" << std::endl;
    pasteTemplate();
    refactorTemplate();
}

void projGenerator::pasteTemplate() {
    try
    {
        fs::create_directories(this->targetPath);
        fs::copy(this->tempPath, this->targetPath, fs::copy_options::recursive | fs::copy_options::overwrite_existing);
    }
    catch(const fs::filesystem_error& e)
    {
        std::cerr << e.what() << '\n';
        return;
    }
}

void projGenerator::refactorTemplate() {
    fs::path CMakeFilePath = this->targetPath / "CMakeLists.txt";
    if (!fs::exists(CMakeFilePath)) {
        std::cerr << "File CMakeLists.txt not exist" << std::endl;
        return;
    }
    std::ifstream inFile(CMakeFilePath);
    if (!inFile.is_open()) {
        std::cerr << "File CMakeLists.txt can not be opened!" << std::endl;
        return;
    }
    std::string fileContent{std::istreambuf_iterator<char>(inFile), std::istreambuf_iterator<char>()};
    inFile.close();

    replaceAll(fileContent, "%^%ProjectName%^%", this->projName);

    std::ofstream outFile(CMakeFilePath, std::ios::trunc);
    if (!outFile.is_open()) {
        std::cerr << "File CMakeLists.txt cannot be opened for rewrite." << std::endl;
        return;
    }
    outFile << fileContent;
    outFile.close();
    std::cout << "File CMakeLists.txt was refactored." << std::endl;
}