#pragma once
#include <string>

std::string MonsterToString(int id) {
    switch(id) {
        case 2001: return "Blue Buff";
        case 2002: return "Red Buff";
        case 2003: return "Gold Lane";
        case 2004: return "Exp Lane";
        case 2005: return "Crab";
        case 2006: return "Turtle";
        case 2007: return "Lord";
        default: return "";
    }
}

std::string HeroToString(int id) {
    return "Hero";
}
