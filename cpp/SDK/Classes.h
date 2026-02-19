#pragma once
#include "../Il2Cpp/Il2Cpp.h"
#include "Vector3.h"
#include "Memory.h"
#include <map>

class ShowEntityBase {
public:
    uintptr_t object;
    
    ShowEntityBase() : object(0) {}
    ShowEntityBase(uintptr_t obj) : object(obj) {}
    
    bool IsValid() { return object != 0 && object > 0x10000; }
    
    bool m_bDeath() {
        if (!IsValid()) return true;
        return *(bool*)((uintptr_t)this + Il2CppGetFieldOffset("Assembly-CSharp", "", "EntityBase", "m_bDeath"));
    }
    
    bool m_bSameCampType() {
        if (!IsValid()) return false;
        return *(bool*)((uintptr_t)this + Il2CppGetFieldOffset("Assembly-CSharp", "", "EntityBase", "m_bSameCampType"));
    }
    
    int m_Hp() {
        if (!IsValid()) return 0;
        return *(int*)((uintptr_t)this + Il2CppGetFieldOffset("Assembly-CSharp", "", "EntityBase", "m_Hp"));
    }
    
    int m_HpMax() {
        if (!IsValid()) return 100;
        return *(int*)((uintptr_t)this + Il2CppGetFieldOffset("Assembly-CSharp", "", "EntityBase", "m_HpMax"));
    }
    
    Vector3 m_Position() {
        if (!IsValid()) return Vector3::zero();
        return *(Vector3*)((uintptr_t)this + Il2CppGetFieldOffset("Assembly-CSharp", "", "EntityBase", "m_Position"));
    }
};

class ShowEntity : public ShowEntityBase {
public:
    ShowEntity() : ShowEntityBase() {}
    ShowEntity(uintptr_t obj) : ShowEntityBase(obj) {}
    
    String* m_RoleName() {
        if (!IsValid()) return nullptr;
        return *(String**)((uintptr_t)this + Il2CppGetFieldOffset("Assembly-CSharp", "", "ShowEntity", "m_RoleName"));
    }
};

extern std::map<std::string, uintptr_t> Fields;
extern std::map<std::string, uintptr_t> Methods;
extern Vector3 AimEnemy;
extern Vector3 My;
