#include <fstream>
#include <ShlObj.h>

#include "json/json.h"
#include "xorstr.hpp"

#include "Config.h"

Config::Config(const std::string& name)
{
    char buff[MAX_PATH]{ };
    if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, 0, buff))) {
        path = buff + std::string{ '\\' } + name;
    }
    load();
}

void Config::load()
{
    std::ifstream in{ path };

    if (!in.is_open())
        return;

    Json::Value config;
    in >> config;

    glow.enabled = config[xorstr_("glow")][xorstr_("enabled")].asBool();

    glow.thickness = config[xorstr_("glow")][xorstr_("thickness")].asFloat();
    glow.alpha = config[xorstr_("glow")][xorstr_("alpha")].asFloat();
    glow.style = config[xorstr_("glow")][xorstr_("style")].asInt();

    glow.players = config[xorstr_("glow")][xorstr_("players")].asBool();
    glow.enemiesOnly = config[xorstr_("glow")][xorstr_("enemiesOnly")].asBool();

    glow.alliesColor[0] = config[xorstr_("glow")][xorstr_("alliesColor")][0].asFloat();
    glow.alliesColor[1] = config[xorstr_("glow")][xorstr_("alliesColor")][1].asFloat();
    glow.alliesColor[2] = config[xorstr_("glow")][xorstr_("alliesColor")][2].asFloat();

    glow.enemiesColor[0] = config[xorstr_("glow")][xorstr_("enemiesColor")][0].asFloat();
    glow.enemiesColor[1] = config[xorstr_("glow")][xorstr_("enemiesColor")][1].asFloat();
    glow.enemiesColor[2] = config[xorstr_("glow")][xorstr_("enemiesColor")][2].asFloat();

    glow.weapons = config[xorstr_("glow")][xorstr_("weapons")].asBool();
    glow.weaponsColor[0] = config[xorstr_("glow")][xorstr_("weaponsColor")][0].asFloat();
    glow.weaponsColor[1] = config[xorstr_("glow")][xorstr_("weaponsColor")][1].asFloat();
    glow.weaponsColor[2] = config[xorstr_("glow")][xorstr_("weaponsColor")][2].asFloat();

    glow.C4 = config[xorstr_("glow")][xorstr_("C4")].asBool();
    glow.C4Color[0] = config[xorstr_("glow")][xorstr_("C4Color")][0].asFloat();
    glow.C4Color[1] = config[xorstr_("glow")][xorstr_("C4Color")][1].asFloat();
    glow.C4Color[2] = config[xorstr_("glow")][xorstr_("C4Color")][2].asFloat();

    glow.plantedC4 = config[xorstr_("glow")][xorstr_("plantedC4")].asBool();
    glow.plantedC4Color[0] = config[xorstr_("glow")][xorstr_("plantedC4Color")][0].asFloat();
    glow.plantedC4Color[1] = config[xorstr_("glow")][xorstr_("plantedC4Color")][1].asFloat();
    glow.plantedC4Color[2] = config[xorstr_("glow")][xorstr_("plantedC4Color")][2].asFloat();

    glow.chickens = config[xorstr_("glow")][xorstr_("chickens")].asBool();
    glow.chickensColor[0] = config[xorstr_("glow")][xorstr_("chickensColor")][0].asFloat();
    glow.chickensColor[1] = config[xorstr_("glow")][xorstr_("chickensColor")][1].asFloat();
    glow.chickensColor[2] = config[xorstr_("glow")][xorstr_("chickensColor")][2].asFloat();

    chams.enabled = config[xorstr_("chams")][xorstr_("enabled")].asBool();
    chams.alpha = config[xorstr_("chams")][xorstr_("alpha")].asFloat();

    chams.visibleAlliesColor[0] = config[xorstr_("chams")][xorstr_("visibleAlliesColor")][0].asFloat();
    chams.visibleAlliesColor[1] = config[xorstr_("chams")][xorstr_("visibleAlliesColor")][1].asFloat();
    chams.visibleAlliesColor[2] = config[xorstr_("chams")][xorstr_("visibleAlliesColor")][2].asFloat();

    chams.visibleEnemiesColor[0] = config[xorstr_("chams")][xorstr_("visibleEnemiesColor")][0].asFloat();
    chams.visibleEnemiesColor[1] = config[xorstr_("chams")][xorstr_("visibleEnemiesColor")][1].asFloat();
    chams.visibleEnemiesColor[2] = config[xorstr_("chams")][xorstr_("visibleEnemiesColor")][2].asFloat();

    triggerbot.enabled = config[xorstr_("triggerbot")][xorstr_("enabled")].asBool();
    triggerbot.shotDelay = config[xorstr_("triggerbot")][xorstr_("shotDelay")].asInt();

    misc.bunnyHop = config[xorstr_("misc")][xorstr_("bunnyHop")].asBool();
    misc.clanTag = config[xorstr_("misc")][xorstr_("clanTag")].asString();
    misc.disablePostProcessing = config[xorstr_("misc")][xorstr_("disablePostProcessing")].asBool();
    misc.flashReduction = config[xorstr_("misc")][xorstr_("flashReduction")].asInt();
    misc.noSmoke = config[xorstr_("misc")][xorstr_("noSmoke")].asBool();
    misc.skybox = config[xorstr_("misc")][xorstr_("skybox")].asString();
    misc.viewmodelFov = config[xorstr_("misc")][xorstr_("viewmodelFov")].asInt();
    misc.worldColor[0] = config[xorstr_("misc")][xorstr_("worldColor")][0].asFloat();
    misc.worldColor[1] = config[xorstr_("misc")][xorstr_("worldColor")][1].asFloat();
    misc.worldColor[2] = config[xorstr_("misc")][xorstr_("worldColor")][2].asFloat();

    in.close();
}

void Config::save() const
{
    std::ofstream out{ path };

    if (!out.is_open())
        return;

    Json::Value config;

    config[xorstr_("glow")][xorstr_("enabled")] = glow.enabled;

    config[xorstr_("glow")][xorstr_("thickness")] = glow.thickness;
    config[xorstr_("glow")][xorstr_("alpha")] = glow.alpha;
    config[xorstr_("glow")][xorstr_("style")] = glow.style;

    config[xorstr_("glow")][xorstr_("players")] = glow.players;
    config[xorstr_("glow")][xorstr_("enemiesOnly")] = glow.enemiesOnly;

    config[xorstr_("glow")][xorstr_("alliesColor")][0] = glow.alliesColor[0];
    config[xorstr_("glow")][xorstr_("alliesColor")][1] = glow.alliesColor[1];
    config[xorstr_("glow")][xorstr_("alliesColor")][2] = glow.alliesColor[2];

    config[xorstr_("glow")][xorstr_("enemiesColor")][0] = glow.enemiesColor[0];
    config[xorstr_("glow")][xorstr_("enemiesColor")][1] = glow.enemiesColor[1];
    config[xorstr_("glow")][xorstr_("enemiesColor")][2] = glow.enemiesColor[2];

    config[xorstr_("glow")][xorstr_("weapons")] = glow.weapons;
    config[xorstr_("glow")][xorstr_("weaponsColor")][0] = glow.weaponsColor[0];
    config[xorstr_("glow")][xorstr_("weaponsColor")][1] = glow.weaponsColor[1];
    config[xorstr_("glow")][xorstr_("weaponsColor")][2] = glow.weaponsColor[2];

    config[xorstr_("glow")][xorstr_("C4")] = glow.C4;
    config[xorstr_("glow")][xorstr_("C4Color")][0] = glow.C4Color[0];
    config[xorstr_("glow")][xorstr_("C4Color")][1] = glow.C4Color[1];
    config[xorstr_("glow")][xorstr_("C4Color")][2] = glow.C4Color[2];

    config[xorstr_("glow")][xorstr_("plantedC4")] = glow.plantedC4;
    config[xorstr_("glow")][xorstr_("plantedC4Color")][0] = glow.plantedC4Color[0];
    config[xorstr_("glow")][xorstr_("plantedC4Color")][1] = glow.plantedC4Color[1];
    config[xorstr_("glow")][xorstr_("plantedC4Color")][2] = glow.plantedC4Color[2];

    config[xorstr_("glow")][xorstr_("chickens")] = glow.chickens;
    config[xorstr_("glow")][xorstr_("chickensColor")][0] = glow.chickensColor[0];
    config[xorstr_("glow")][xorstr_("chickensColor")][1] = glow.chickensColor[1];
    config[xorstr_("glow")][xorstr_("chickensColor")][2] = glow.chickensColor[2];

    config[xorstr_("chams")][xorstr_("enabled")] = chams.enabled;
    config[xorstr_("chams")][xorstr_("alpha")] = chams.alpha;

    config[xorstr_("chams")][xorstr_("visibleAlliesColor")][0] = chams.visibleAlliesColor[0];
    config[xorstr_("chams")][xorstr_("visibleAlliesColor")][1] = chams.visibleAlliesColor[1];
    config[xorstr_("chams")][xorstr_("visibleAlliesColor")][2] = chams.visibleAlliesColor[2];

    config[xorstr_("chams")][xorstr_("visibleEnemiesColor")][0] = chams.visibleEnemiesColor[0];
    config[xorstr_("chams")][xorstr_("visibleEnemiesColor")][1] = chams.visibleEnemiesColor[1];
    config[xorstr_("chams")][xorstr_("visibleEnemiesColor")][2] = chams.visibleEnemiesColor[2];

    config[xorstr_("triggerbot")][xorstr_("enabled")] = triggerbot.enabled;
    config[xorstr_("triggerbot")][xorstr_("shotDelay")] = triggerbot.shotDelay;

    config[xorstr_("misc")][xorstr_("bunnyHop")] = misc.bunnyHop;
    config[xorstr_("misc")][xorstr_("clanTag")] = misc.clanTag;
    config[xorstr_("misc")][xorstr_("disablePostProcessing")] = misc.disablePostProcessing;
    config[xorstr_("misc")][xorstr_("flashReduction")] = misc.flashReduction;
    config[xorstr_("misc")][xorstr_("noSmoke")] = misc.noSmoke;
    config[xorstr_("misc")][xorstr_("skybox")] = misc.skybox;
    config[xorstr_("misc")][xorstr_("viewmodelFov")] = misc.viewmodelFov;
    config[xorstr_("misc")][xorstr_("worldColor")][0] = misc.worldColor[0];
    config[xorstr_("misc")][xorstr_("worldColor")][1] = misc.worldColor[1];
    config[xorstr_("misc")][xorstr_("worldColor")][2] = misc.worldColor[2];

    out << config;
    out.close();
}

void Config::reset()
{
    glow.enabled = false;

    glow.thickness = 1.0f;
    glow.alpha = 1.0f;
    glow.style = 0;

    glow.players = false;
    glow.enemiesOnly = false;

    glow.alliesColor[0] = 0.0f;
    glow.alliesColor[1] = 1.0f;
    glow.alliesColor[2] = 0.0f;

    glow.enemiesColor[0] = 1.0f;
    glow.enemiesColor[1] = 0.0f;
    glow.enemiesColor[2] = 0.0f;

    glow.weapons = false;
    glow.weaponsColor[0] = 1.0f;
    glow.weaponsColor[1] = 1.0f;
    glow.weaponsColor[2] = 1.0f;

    glow.C4 = false;
    glow.C4Color[0] = 1.0f;
    glow.C4Color[1] = 1.0f;
    glow.C4Color[2] = 0.0f;

    glow.plantedC4 = false;
    glow.plantedC4Color[0] = 1.0f;
    glow.plantedC4Color[1] = 0.27f;
    glow.plantedC4Color[2] = 0.0f;

    glow.chickens = false;
    glow.chickensColor[0] = 1.0f;
    glow.chickensColor[1] = 0.08f;
    glow.chickensColor[2] = 0.58f;

    chams.enabled = false;
    chams.alpha = 1.0f;

    chams.visibleAlliesColor[0] = 0.0f;
    chams.visibleAlliesColor[1] = 1.0f;
    chams.visibleAlliesColor[2] = 0.0f;

    chams.visibleEnemiesColor[0] = 1.0f;
    chams.visibleEnemiesColor[1] = 0.0f;
    chams.visibleEnemiesColor[2] = 0.0f;

    triggerbot.enabled = false;
    triggerbot.shotDelay = 0;

    misc.bunnyHop = false;
    misc.clanTag = "";
    misc.disablePostProcessing = false;
    misc.flashReduction = 0;
    misc.noSmoke = false;
    misc.skybox = xorstr_("Default");
    misc.viewmodelFov = 60;
    misc.worldColor[0] = 0.0f;
    misc.worldColor[1] = 0.0f;
    misc.worldColor[2] = 0.0f;
};
