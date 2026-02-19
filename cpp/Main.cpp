#include <jni.h>
#include <android/log.h>
#include <thread>
#include <unistd.h>
#include <cstdint>
#include "Includes/Logger.h"
#include "Il2Cpp/Il2Cpp.h"
#include "Config/Config.h"
#include "SDK/Vector3.h"
#include "ESP/Render.h"

uintptr_t g_Il2CppBase = 0;

void MainThread() {
    LOGI("🚀 Waiting for Il2Cpp...");
    
    while (!Il2CppIsAssembliesLoaded()) {
        sleep(1);
    }
    
    LOGI("✅ Il2Cpp Loaded!");
    Il2CppAttach("libil2cpp.so");
    LOGI("✅ Il2Cpp Attached!");
    
    LOGI("=================================");
    LOGI("🎯 MLBB ESP Mod Ready");
    LOGI("📦 Project: NativeProject");
    LOGI("=================================");
}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    JNIEnv* env;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }
    
    std::thread(MainThread).detach();
    
    return JNI_VERSION_1_6;
}
