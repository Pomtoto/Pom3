#pragma once
#include <vector>
#include <string>
#include "../SDK/Vector3.h"
#include "../Config/Config.h"

bool isOutsideScreen(ImVec2 pos, ImVec2 screen);
ImVec2 pushToScreenBorder(ImVec2 Pos, ImVec2 screen, int offset);
void DrawCircleHealth(ImVec2 position, int health, int max_health, float radius);
ImVec2 getPosVec2(Vector3 _Position, int screenWidth, int screenHeight);
void NewDrawESP(ImDrawList *draw, float screenWidth, float screenHeight);
void DroneView();
void UpdateMapHack(void * pThis);
void _ShowEntity__OnUpdate(ShowEntity *showEntity);
void _ShowPlayer_Unity_OnUpdate(void* thisz);

extern int glWidth;
extern int glHeight;
extern ImVec2 StartPos;
extern float MapSize;
extern bool AttachIconDone;
extern std::vector<int> ListMonsterId;

std::string MonsterToString(int id);
std::string HeroToString(int id);
