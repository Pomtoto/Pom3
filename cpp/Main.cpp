#include <jni.h>
#include <android/log.h>
#include <thread>
#include <unistd.h>
#include <cstdint>
#include <dlfcn.h>
#include <sys/mman.h>
#include <cstring>
#include <inttypes.h>
#include <fstream>
#include <string>

#include "Includes/Logger.h"
#include "Il2Cpp/Il2Cpp.h"
#include "Config/Config.h"
#include "SDK/Vector3.h"
#include "SDK/Classes.h"
#include "SDK/Offsets.h"
#include "ESP/Render.h"

// Global Variables
uintptr_t g_Il2CppBase = 0;
JavaVM* g_vm = nullptr;

// External Offset Declarations
extern uintptr_t BattleData_m_BattleBridge;
extern uintptr_t BattleData_battleManager;
extern uintptr_t ShowEntity__Position;
extern uintptr_t EntityBase_m_Hp;
extern uintptr_t EntityBase_m_HpMax;
extern uintptr_t EntityBase_m_bDeath;
extern uintptr_t EntityBase_m_bSameCampType;

// Function to check if file exists
bool FileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

// Get Base Address of a library
uintptr_t GetBaseAddress(const char* libName) {
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

// Main Thread Function
void MainThread() {
    LOGI("🚀 Waiting for Il2Cpp...");
    
    // Wait for Il2Cpp to load
    while (!Il2CppIsAssembliesLoaded()) {
        sleep(1);
    }
    
    LOGI("✅ Il2Cpp Loaded!");
    
    // Attach to libil2cpp.so (for MLBB)
    Il2CppAttach("libil2cpp.so");
    
    LOGI("✅ Il2Cpp Attached!");
    
    // Initialize Offsets
    BattleData_m_BattleBridge = Il2CppGetStaticFieldOffset("Assembly-CSharp", "", "BattleData", "m_BattleBridge");
    BattleData_battleManager = Il2CppGetStaticFieldOffset("Assembly-CSharp", "", "BattleManager", "Instance");
    ShowEntity__Position = Il2CppGetFieldOffset("Assembly-CSharp", "", "ShowEntity", "m_vCachePosition");
    EntityBase_m_Hp = Il2CppGetFieldOffset("Assembly-CSharp", "", "EntityBase", "m_Hp");
    EntityBase_m_HpMax = Il2CppGetFieldOffset("Assembly-CSharp", "", "EntityBase", "m_HpMax");
    EntityBase_m_bDeath = Il2CppGetFieldOffset("Assembly-CSharp", "", "EntityBase", "m_bDeath");
    EntityBase_m_bSameCampType = Il2CppGetFieldOffset("Assembly-CSharp", "", "EntityBase", "m_bSameCampType");
    
    LOGI("📍 BattleBridge Offset: 0x%" PRIxPTR, BattleData_m_BattleBridge);
    LOGI("📍 BattleManager Offset: 0x%" PRIxPTR, BattleData_battleManager);
    LOGI("📍 Position Offset: 0x%" PRIxPTR, ShowEntity__Position);
    LOGI("📍 Health Offset: 0x%" PRIxPTR, EntityBase_m_Hp);
    
    LOGI("=================================");
    LOGI("🎯 MLBB ESP Mod Ready");
    LOGI("📦 Project: NativeProject");
    LOGI("=================================");
    
    // Main Loop
    while (true) {
        if (Config.ESP.FPS) {
            LOGI("📊 FPS Counter Active");
        }
        sleep(2);
    }
}

// JNI OnLoad - Entry Point
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    g_vm = vm;
    
    JNIEnv* env;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }
    
    LOGI("=================================");
    LOGI("🎯 Native Library Loaded");
    LOGI("📦 Package: %s", "com.mobile.legends");
    LOGI("=================================");
    
    // Start Main Thread
    std::thread(MainThread).detach();
    
    return JNI_VERSION_1_6;
}

// JNI OnUnload - Cleanup
JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* vm, void* reserved) {
    LOGI("👋 Library Unloading...");
}
