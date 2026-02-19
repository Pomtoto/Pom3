#include "Config.h"

bool OpenLinkURL = false;
bool ActiveESP = false;
bool ActiveVipSkill = false;
bool ButtonComboGusion = false;
bool SetGrassLayerHook = false;
bool EyeRangeHook = false;
bool KimmyAttackJungle = false;
bool GusionButton = false;
bool PaquitoButton = false;
bool KimmyButton = false;
bool UpdateManiacStatus = false;
bool ToggleRetri = false;
int speedInt = 21;
bool customTrigger = false;
float CostumLagging = 15;
bool ActiveRetribution = false;
bool ActiveAutoSkill = false;
float SetFieldOfView = 0;
float GetFieldOfView = 0;
float sliderValue = 0;
float RangeCombo = 10.0f;
float RangePredict = 13.0f;
float TargetHP = 1750;
float RangeFOV = 10.0f;
float speedAtt = 1.0f;
float TargetHPPer = 40;
float SpeedPredict = 1;
bool PerformanceInt = false;

namespace Esp {
    bool SkillsId = false;
}

namespace Configs {
    int EglWidth = 0;
    int EglHeight = 0;
    int DisplayWidth = 0;
    int DisplayHeight = 0;
    bool LoginValid = false;
    bool Initialized = false;
    bool ClearMouse = true;
    bool ShowImGui = true;
}

namespace AutoSkills {
    bool SoYou = false;
    bool Lucas = false;
    bool KimmyTriggerOnNew = false;
    bool KimmyTrigger = false;
    bool GusionTriggerRecall = false;
    bool GusionTrigger = false;
    bool KimmyCreep = false;
    bool KimmyCreepTrigger = false;
    bool VisibleCheck = false;
    bool KimmyBasicAttack = false;
    bool KimmyBasicAttackTrigger = false;
    bool DyrothBugTest = false;
    bool DyrothBugTrigger = false;
    bool YssBugCall = false;
    bool AluBugCall = false;
    bool BeatrixBugTest = false;
    bool YinBrustDamage = false;
    bool BeatrixBugTrigger = false;
    bool YinBugTrigger = false;
    bool LaylaDamage = false;
    bool LaylaTrigger = false;
    bool AamonDamage = false;
    bool AamonTrigger = false;
    bool NovariaDamage = false;
    bool NovariaTrigger = false;
    bool HanabiDamage = false;
    bool ArgusDamage = false;
    bool FannyCable = false;
    bool HanabiTrigger = false;
    bool GusionDamage = false;
    bool GusionBugTrigger = false;
    bool JoyDoubleDamage = false;
    bool JoyTrigger = false;
    bool JoyDoubleDamage2 = false;
    bool JoyTrigger2 = false;
    bool JhonsonDmg = false;
    bool JhonsonTrigger = false;
    bool FredrinBug = false;
    bool FredrinTrigger = false;
    bool LesleyBug = false;
    bool LesleyTrigger = false;
    bool MinotaurBug = false;
    bool MinotaurTrigger = false;
    bool EsmeraldaBug = false;
    bool EsmeraldaBug2 = false;
    bool EsmeraldaTrigger = false;
    bool PaquitoTrigger = false;
    bool CarmilaBug = false;
    bool AldousBug = false;
    bool KimmyFreeTrigger = false;
    bool PharsaTriggetUlti = false;
}

sAutoRetribution AutoRetribution{false, false, false, false, 7.0f};
sColorPick ColorPick{nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
sAutoTrigger AutoTrigger{false};
sAutoSkill AutoSkill{false, false};
sAim Aim{false, false, false, false, false, Vector3::zero(), Vector3::One(), Vector3::zero(), 0, 9999, false};
sConfig Config{false, false, false, false, 341, ImVec2(105.0f, 0.0f), false, true, false, 0, 0, {false, {false, false, false, false, false, false, false, false, false, false, false, false, false, false}, {false, false, false, false, false, false, false, false}}, {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false}};
