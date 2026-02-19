#pragma once
#include "../SDK/Vector3.h"
#include <imgui.h>

#define targetLib "libil2cpp.so"

extern bool OpenLinkURL;
extern bool ActiveESP;
extern bool ActiveVipSkill;
extern bool ButtonComboGusion;
extern bool SetGrassLayerHook;
extern bool EyeRangeHook;
extern bool KimmyAttackJungle;
extern bool GusionButton;
extern bool PaquitoButton;
extern bool KimmyButton;
extern bool UpdateManiacStatus;
extern bool ToggleRetri;
extern int speedInt;
extern bool customTrigger;
extern float CostumLagging;
extern bool ActiveRetribution;
extern bool ActiveAutoSkill;
extern float SetFieldOfView;
extern float GetFieldOfView;
extern float sliderValue;
extern float RangeCombo;
extern float RangePredict;
extern float TargetHP;
extern float RangeFOV;
extern float speedAtt;
extern float TargetHPPer;
extern float SpeedPredict;
extern bool PerformanceInt;

namespace Esp {
    extern bool SkillsId;
}

namespace Configs {
    extern int EglWidth;
    extern int EglHeight;
    extern int DisplayWidth;
    extern int DisplayHeight;
    extern bool LoginValid;
    extern bool Initialized;
    extern bool ClearMouse;
    extern bool ShowImGui;
}

namespace AutoSkills {
    extern bool SoYou;
    extern bool Lucas;
    extern bool KimmyTriggerOnNew;
    extern bool KimmyTrigger;
    extern bool GusionTriggerRecall;
    extern bool GusionTrigger;
    extern bool KimmyCreep;
    extern bool KimmyCreepTrigger;
    extern bool VisibleCheck;
    extern bool KimmyBasicAttack;
    extern bool KimmyBasicAttackTrigger;
    extern bool DyrothBugTest;
    extern bool DyrothBugTrigger;
    extern bool YssBugCall;
    extern bool AluBugCall;
    extern bool BeatrixBugTest;
    extern bool YinBrustDamage;
    extern bool BeatrixBugTrigger;
    extern bool YinBugTrigger;
    extern bool LaylaDamage;
    extern bool LaylaTrigger;
    extern bool AamonDamage;
    extern bool AamonTrigger;
    extern bool NovariaDamage;
    extern bool NovariaTrigger;
    extern bool HanabiDamage;
    extern bool ArgusDamage;
    extern bool FannyCable;
    extern bool HanabiTrigger;
    extern bool GusionDamage;
    extern bool GusionBugTrigger;
    extern bool JoyDoubleDamage;
    extern bool JoyTrigger;
    extern bool JoyDoubleDamage2;
    extern bool JoyTrigger2;
    extern bool JhonsonDmg;
    extern bool JhonsonTrigger;
    extern bool FredrinBug;
    extern bool FredrinTrigger;
    extern bool LesleyBug;
    extern bool LesleyTrigger;
    extern bool MinotaurBug;
    extern bool MinotaurTrigger;
    extern bool EsmeraldaBug;
    extern bool EsmeraldaBug2;
    extern bool EsmeraldaTrigger;
    extern bool PaquitoTrigger;
    extern bool CarmilaBug;
    extern bool AldousBug;
    extern bool KimmyFreeTrigger;
    extern bool PharsaTriggetUlti;
}

struct sAutoRetribution {
    bool RedandBlue;
    bool TurtleandLord;
    bool Crab;
    bool litho;
    float Custom;
};

struct sColorPick {
    float *Line;
    float *Box;
    float *Name;
    float *Health;
    float *Distance;
    float *Second;
};

struct sAutoTrigger {
    bool Retribution;
};

struct sAutoSkill {
    bool Lesley;
    bool Lucas;
};

struct sAim {
    bool SelfPos;
    bool TargetPriority;
    bool AutoTakeSword;
    bool AutoTakeSword2;
    bool ActivePredict;
    Vector3 Dir;
    Vector3 Pos;
    Vector3 NearestEnemyPos;
    int NearestEnemyGuid;
    float NearestEnemyDist;
    bool RetriDistButton;
};

struct sConfig {
    bool m_IDConf;
    bool MinimapIcon;
    bool MinimapIconEnable;
    bool HideLine;
    int MapSize;
    ImVec2 StartPos;
    bool ActiveSkill;
    bool DnsString;
    bool Bypass;
    float getFieldOfView;
    float setFieldOfView;
    
    struct sESP {
        bool FPS;
        struct sPlayer {
            bool Line;
            bool Box;
            bool Health;
            bool Name;
            bool Distance;
            bool Hero;
            bool CoolDown;
            bool CoolDown2;
            bool Circle;
            bool Alert;
            bool Visible;
            bool Round;
            bool HeroZ;
            bool Status;
            bool Locator2;
        };
        sPlayer Player;
        
        struct sMonster {
            bool Box;
            bool Health;
            bool Name;
            bool Alert;
            bool Locator;
            bool JungelAttack;
            bool Rounded;
            bool Locator2;
        };
        sMonster Monster;
    };
    sESP ESP;
    
    struct sVisual {
        bool UnlockHero;
        bool UnlockSkin;
        bool UnlockEmblem;
        bool MaphackIcon;
        bool MapHackIcon2;
        bool MapHackIcon3;
        bool HealthBar;
        bool ShowMonster;
        bool IconMap;
        bool UnlockSpell;
        bool Icon;
        bool RemoveGrass;
        bool MonsterIcon;
        bool MonsterHealth;
        bool MonsterBody;
        bool ShowJungle;
        bool ShowMonsterTest;
        bool NoGrass;
        bool HeadIcon;
    };
    sVisual Visual;
};

extern sAutoRetribution AutoRetribution;
extern sColorPick ColorPick;
extern sAutoTrigger AutoTrigger;
extern sAutoSkill AutoSkill;
extern sAim Aim;
extern sConfig Config;
