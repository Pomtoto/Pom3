#pragma once
#include <string>
#include <fstream>
#include <cstdint>
#include <cstring>
#include <dlfcn.h>

namespace Tools {
    inline bool FileExists(const std::string& path) {
        std::ifstream file(path);
        return file.good();
    }

    inline uintptr_t GetBaseAddress(const char* libName) {
        std::ifstream maps("/proc/self/maps");
        std::string line;
        while (std::getline(maps, line)) {
            if (strstr(line.c_str(), libName)) {
                uintptr_t base = strtoul(line.substr(0, line.find('-')).c_str(), nullptr, 16);
                maps.close();
                return base;
            }
        }
        maps.close();
        return 0;
    }
}
