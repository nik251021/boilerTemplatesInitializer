#include <router.hpp>

router::router(int argc, char* argv[]) {
    this->argc = argc;
    for (int i = 0; i < argc; i++) {
        this->argv.push_back(argv[i]);
    }
}

bool router::hasArg(const std::string& arg) {
    for (const auto& curArg : this->argv) {
        if (curArg == arg) {
            return true;
        }
    }
    return false;
}

std::string router::getArg(const std::string& arg) {
    for (int i = 0; i < argc; i++) {
        if (argv[i] == arg and i + 1 < argc) {
            return argv[i+1];
        }
    }
    return "";
}