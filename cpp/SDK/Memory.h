#pragma once
#include <cstdint>

template<typename T>
inline T ReadMemory(uintptr_t address) {
    if (address == 0) return T();
    return *(T*)address;
}

template<typename T>
inline void WriteMemory(uintptr_t address, T value) {
    if (address == 0) return;
    *(T*)address = value;
}

inline bool IsValidPointer(uintptr_t ptr) {
    return ptr != 0 && ptr > 0x10000;
}
