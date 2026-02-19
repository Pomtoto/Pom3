#include "Il2Cpp.h"
#include <dlfcn.h>
#include <unistd.h>
#include <android/log.h>

#define LOG_TAG "XYZ-I2Cpp"

namespace {
    const void *(*il2cpp_assembly_get_image)(const void *assembly);
    void *(*il2cpp_domain_get)();
    void **(*il2cpp_domain_get_assemblies)(const void *domain, size_t *size);
    const char *(*il2cpp_image_get_name)(void *image);
    void *(*il2cpp_class_from_name)(const void *image, const char *namespaze, const char *name);
    void *(*il2cpp_class_get_field_from_name)(void *klass, const char *name);
    void *(*il2cpp_class_get_method_from_name)(void *klass, const char *name, int argsCount);
    size_t (*il2cpp_field_get_offset)(void *field);
    void (*il2cpp_field_static_get_value)(void *field, void *value);
    void (*il2cpp_field_static_set_value)(void *field, void *value);
    void *(*il2cpp_array_new)(void *elementTypeInfo, size_t length);
    uint16_t *(*il2cpp_string_chars)(void *str);
    Il2CppString *(*il2cpp_string_new)(const char *str);
    Il2CppString *(*il2cpp_string_new_utf16)(const wchar_t *str, int32_t length);
    String *(*il2cpp_string_new2)(const char *str);
    String *(*il2cpp_string_new_utf162)(const wchar_t *str, int32_t length);
    char *(*il2cpp_type_get_name)(void *type);
    void* (*il2cpp_method_get_param)(void *method, uint32_t index);
    void* (*il2cpp_class_get_methods)(void *klass, void* *iter);
    const char* (*il2cpp_method_get_name)(void *method);
    void *(*il2cpp_object_new)(void *klass);
}

String *String::Create(const char *s) {
    return il2cpp_string_new2(s);
}

String *String::Create(const wchar_t *s, int len) {
    return il2cpp_string_new_utf162(s, len);
}

void *Il2CppGetImageByName(const char *image) {
    size_t size;
    void **assemblies = il2cpp_domain_get_assemblies(il2cpp_domain_get(), &size);
    for(int i = 0; i < size; ++i) {
        void *img = (void *)il2cpp_assembly_get_image(assemblies[i]);
        const char *img_name = il2cpp_image_get_name(img);
        if (strcmp(img_name, image) == 0) {
            return img;
        }
    }
    return 0;
}

void *Il2CppGetClassType(const char *image, const char *namespaze, const char *clazz) {
    static std::map<std::string, void *> cache;
    std::string s = image;
    s += namespaze;
    s += clazz;
    if (cache.count(s) > 0)
        return cache[s];
    void *img = Il2CppGetImageByName(image);
    if (!img) return 0;
    void *klass = il2cpp_class_from_name(img, namespaze, clazz);
    if (!klass) return 0;
    cache[s] = klass;
    return klass;
}

void *Il2CppCreateClassInstance(const char *image, const char *namespaze, const char *clazz) {
    void *img = Il2CppGetImageByName(image);
    if (!img) return 0;
    void *klass = Il2CppGetClassType(image, namespaze, clazz);
    if (!klass) return 0;
    void *obj = il2cpp_object_new(klass);
    return obj;
}

size_t Il2CppGetFieldOffset(const char *image, const char *namespaze, const char *clazz, const char *name) {
    void *img = Il2CppGetImageByName(image);
    if (!img) return -1;
    void *klass = Il2CppGetClassType(image, namespaze, clazz);
    if (!klass) return -1;
    void *field = il2cpp_class_get_field_from_name(klass, name);
    if (!field) return -1;
    return il2cpp_field_get_offset(field);
}

void *Il2CppGetMethodOffset(const char *image, const char *namespaze, const char *clazz, const char *name, int argsCount) {
    void *img = Il2CppGetImageByName(image);
    if (!img) return 0;
    void *klass = Il2CppGetClassType(image, namespaze, clazz);
    if (!klass) return 0;
    void **method = (void**)il2cpp_class_get_method_from_name(klass, name, argsCount);
    if (!method) return 0;
    return *method;
}

bool Il2CppIsAssembliesLoaded() {
    size_t size;
    void **assemblies = il2cpp_domain_get_assemblies(il2cpp_domain_get(), &size);
    return size != 0 && assemblies != 0;
}

void Il2CppAttach(const char *name) {
    void *handle = dlopen(name, RTLD_LAZY);
    while (!handle) {
        handle = dlopen(name, RTLD_LAZY);
        sleep(1);
    }
    
    il2cpp_assembly_get_image = (const void *(*)(const void *)) dlsym(handle, "il2cpp_assembly_get_image");
    il2cpp_domain_get = (void *(*)()) dlsym(handle, "il2cpp_domain_get");
    il2cpp_domain_get_assemblies = (void **(*)(const void* , size_t*)) dlsym(handle, "il2cpp_domain_get_assemblies");
    il2cpp_image_get_name = (const char *(*)(void *)) dlsym(handle, "il2cpp_image_get_name");
    il2cpp_class_from_name = (void* (*)(const void*, const char*, const char *)) dlsym(handle, "il2cpp_class_from_name");
    il2cpp_class_get_field_from_name = (void* (*)(void*, const char *)) dlsym(handle, "il2cpp_class_get_field_from_name");
    il2cpp_class_get_method_from_name = (void* (*)(void *, const char*, int)) dlsym(handle, "il2cpp_class_get_method_from_name");
    il2cpp_field_get_offset = (size_t (*)(void *)) dlsym(handle, "il2cpp_field_get_offset");
    il2cpp_field_static_get_value = (void (*)(void*, void *)) dlsym(handle, "il2cpp_field_static_get_value");
    il2cpp_field_static_set_value = (void (*)(void*, void *)) dlsym(handle, "il2cpp_field_static_set_value");
    il2cpp_array_new = (void *(*)(void*, size_t)) dlsym(handle, "il2cpp_array_new");
    il2cpp_string_chars = (uint16_t *(*)(void*)) dlsym(handle, "il2cpp_string_chars");
    il2cpp_string_new = (Il2CppString *(*)(const char *)) dlsym(handle, "il2cpp_string_new");
    il2cpp_string_new_utf16 = (Il2CppString *(*)(const wchar_t *, int32_t)) dlsym(handle, "il2cpp_string_new");
    il2cpp_string_new2 = (String *(*)(const char *)) dlsym(handle, "il2cpp_string_new");
    il2cpp_string_new_utf162 = (String *(*)(const wchar_t *, int32_t)) dlsym(handle, "il2cpp_string_new");
    il2cpp_type_get_name = (char *(*)(void *)) dlsym(handle, "il2cpp_type_get_name");
    il2cpp_method_get_param = (void *(*)(void *, uint32_t)) dlsym(handle, "il2cpp_method_get_param");
    il2cpp_class_get_methods = (void *(*)(void *, void **)) dlsym(handle, "il2cpp_class_get_methods");
    il2cpp_method_get_name = (const char *(*)(void *)) dlsym(handle, "il2cpp_method_get_name");
    il2cpp_object_new = (void *(*)(void *)) dlsym(handle, "il2cpp_object_new");
    
    dlclose(handle);
}
