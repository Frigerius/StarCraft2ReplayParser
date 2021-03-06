#pragma once
#include "sc2api/sc2_api.h"

using namespace sc2;

enum class MATERIAL : int
{
    INVALID = -1,

    // Terran
    COMMANDCENTER = 0,
    ORBITALCOMMAND,
    PLANETARYFORTRESS,
    SUPPLYDEPOT,
    REFINERY,
    BUNKER,
    ARMORY,
    ENGINEERINGBAY,
    BARRACKS,
    REACTOR_BARRACKS,
    TECHLAB_BARRACKS,
    FACTORY,
    REACTOR_FACTORY,
    TECHLAB_FACTORY,
    FUSIONCORE,
    GHOSTACADEMY,
    STARPORT,
    REACTOR_STARPORT,
    TECHLAB_STARPORT,
    SENSORTOWER,
    MISSILETURRET,

    SCV,
    MULE,
    // Barracks
    MARINE,
    REAPER,
    MARAUDER,
    GHOST,

    // Factory
    CYCLONE,
    HELLION,
    HELLIONTANK,
    SIEGETANK,
    THOR,
    WIDOWMINE,

    // Starport
    VIKINGFIGHTER,
    MEDIVAC,
    BANSHEE,
    BATTLECRUISER,
    LIBERATOR,
    RAVEN,
    //UPGRADES
    TERRANSHIPWEAPONS,
    TERRANVEHICLEANDSHIPPLATING,
    TERRANVEHICLEWEAPONS,

    STIMPACK,
    COMBATSHIELD,
    CONCUSSIVESHELLS,
    HISECAUTOTRACKING,
    TERRANSTRUCTUREARMORUPGRADE,
    NEOSTEELFRAME,
    TERRANINFANTRYARMOR,
    TERRANINFANTRYWEAPONS,

    INFERNALPREIGNITER,
    DRILLINGCLAWS,
    RAPIDFIRELAUNCHERS,
    SMARTSERVOS,

    BATTLECRUISERWEAPONREFIT,

    PERSONALCLOAKING,

    BANSHEECLOAKINGFIELD,
    RAVENCORVIDREACTOR,
    //ENHANCEDMUNITIONS,
    BANSHEEHYPERFLIGHTROTORS,
    //RAVENRECALIBRATEDEXPLOSIVES,
    HIGHCAPACITYFUELTANKS,
    ADVANCEDBALLISTICS,

    MAX,
};

enum class MATERIAL_SECTIONS : int
{
    INVALID = -1,
    START_UNITS = int(MATERIAL::COMMANDCENTER),
    LAST_UNIT = int(MATERIAL::RAVEN),
    START_UPGRADES = int(MATERIAL::TERRANSHIPWEAPONS),

    MAX = int(MATERIAL::MAX),
};

enum class ACTION : int
{
    INVALID = -1,

    // Terran
    COMMANDCENTER = 0,
    ORBITALCOMMAND,
    PLANETARYFORTRESS,
    SUPPLYDEPOT,
    REFINERY,
    BUNKER,
    ARMORY,
    ENGINEERINGBAY,
    BARRACKS,
    REACTOR_BARRACKS,
    TECHLAB_BARRACKS,
    FACTORY,
    REACTOR_FACTORY,
    TECHLAB_FACTORY,
    FUSIONCORE,
    GHOSTACADEMY,
    STARPORT,
    REACTOR_STARPORT,
    TECHLAB_STARPORT,
    SENSORTOWER,
    MISSILETURRET,

    SCV,
    MULE,
    // Barracks
    MARINE,
    REAPER,
    MARAUDER,
    GHOST,

    // Factory
    CYCLONE,
    HELLION,
    HELLIONTANK,
    SIEGETANK,
    THOR,
    WIDOWMINE,

    // Starport
    VIKINGFIGHTER,
    MEDIVAC,
    BANSHEE,
    BATTLECRUISER,
    LIBERATOR,
    RAVEN,

    TERRANSHIPWEAPONS,
    TERRANVEHICLEANDSHIPPLATING,
    TERRANVEHICLEWEAPONS,

    STIMPACK,
    COMBATSHIELD,
    CONCUSSIVESHELLS,
    HISECAUTOTRACKING,
    TERRANSTRUCTUREARMORUPGRADE,
    NEOSTEELFRAME,
    TERRANINFANTRYARMOR,
    TERRANINFANTRYWEAPONS,

    INFERNALPREIGNITER,
    DRILLINGCLAWS,
    RAPIDFIRELAUNCHERS,
    SMARTSERVOS,

    BATTLECRUISERWEAPONREFIT,

    PERSONALCLOAKING,

    BANSHEECLOAKINGFIELD,
    RAVENCORVIDREACTOR,
    //ENHANCEDMUNITIONS,
    BANSHEEHYPERFLIGHTROTORS,
    //RAVENRECALIBRATEDEXPLOSIVES,
    HIGHCAPACITYFUELTANKS,
    ADVANCEDBALLISTICS,

    SUPPLYDROP,

    MAX,
};

enum class GAME_DATA : int
{
    INVALID = -1,

    GAME_LOOP,

    MINERALS,
    VESPENE,
    FOOD_LEFT,//------ Bis hier relevant f�r buildable
    FOOD_CAP,
    FOOD_USED,
    ORBITAL_COMMAND_ENERGY,
    WORKER_IDLE,
    WORKER_REFINERY_CUR,
    WORKER_REFINERY_MAX,
    WORKER_REFINERY_DIF,
    WORKER_MINERALS_CUR,
    WORKER_MINERALS_MAX,
    WORKER_MINERALS_DIF,
    //REFINERY_SPOTS_LEFT,

    MAX,
};

enum class SECTORS : int
{
    START_CURRENT_MATERIAL = 0,
    START_IN_PRODUCTION = int(MATERIAL::MAX),
    START_PROGRESS = START_IN_PRODUCTION + int(MATERIAL::MAX),
    START_GAME_DATA = START_PROGRESS + int(MATERIAL::MAX),
    START_POSSIBLE_ACTIONS = START_GAME_DATA + int(GAME_DATA::MAX),
    MAX = START_POSSIBLE_ACTIONS + int(ACTION::MAX),
};

static UNIT_TYPEID GetUnitTypeFromAbility(const ABILITY_ID& ability_id) {
    switch (ability_id) {
        //Buildings
        case ABILITY_ID::BUILD_COMMANDCENTER:        return UNIT_TYPEID::TERRAN_COMMANDCENTER;
        case ABILITY_ID::MORPH_ORBITALCOMMAND:       return UNIT_TYPEID::TERRAN_ORBITALCOMMAND;
        case ABILITY_ID::MORPH_PLANETARYFORTRESS:    return UNIT_TYPEID::TERRAN_PLANETARYFORTRESS;
        case ABILITY_ID::BUILD_SUPPLYDEPOT:          return UNIT_TYPEID::TERRAN_SUPPLYDEPOT;
        case ABILITY_ID::BUILD_REFINERY:             return UNIT_TYPEID::TERRAN_REFINERY;
        case ABILITY_ID::BUILD_BARRACKS:             return UNIT_TYPEID::TERRAN_BARRACKS;
        case ABILITY_ID::BUILD_TECHLAB_BARRACKS:     return UNIT_TYPEID::TERRAN_BARRACKSTECHLAB;
        case ABILITY_ID::BUILD_REACTOR_BARRACKS:     return UNIT_TYPEID::TERRAN_BARRACKSREACTOR;
        case ABILITY_ID::BUILD_FACTORY:              return UNIT_TYPEID::TERRAN_FACTORY;
        case ABILITY_ID::BUILD_TECHLAB_FACTORY:      return UNIT_TYPEID::TERRAN_FACTORYTECHLAB;
        case ABILITY_ID::BUILD_REACTOR_FACTORY:      return UNIT_TYPEID::TERRAN_FACTORYREACTOR;
        case ABILITY_ID::BUILD_BUNKER:               return UNIT_TYPEID::TERRAN_BUNKER;
        case ABILITY_ID::BUILD_STARPORT:             return UNIT_TYPEID::TERRAN_STARPORT;
        case ABILITY_ID::BUILD_TECHLAB_STARPORT:     return UNIT_TYPEID::TERRAN_STARPORTTECHLAB;
        case ABILITY_ID::BUILD_REACTOR_STARPORT:     return UNIT_TYPEID::TERRAN_STARPORTREACTOR;
        case ABILITY_ID::BUILD_GHOSTACADEMY:         return UNIT_TYPEID::TERRAN_GHOSTACADEMY;
        case ABILITY_ID::BUILD_ENGINEERINGBAY:       return UNIT_TYPEID::TERRAN_ENGINEERINGBAY;
        case ABILITY_ID::BUILD_ARMORY:               return UNIT_TYPEID::TERRAN_ARMORY;
        case ABILITY_ID::BUILD_FUSIONCORE:           return UNIT_TYPEID::TERRAN_FUSIONCORE;
            // UNITS
        case ABILITY_ID::TRAIN_SCV:                  return UNIT_TYPEID::TERRAN_SCV;
        case ABILITY_ID::EFFECT_CALLDOWNMULE:        return UNIT_TYPEID::TERRAN_MULE;
            // Barracks
        case ABILITY_ID::TRAIN_GHOST:                return UNIT_TYPEID::TERRAN_GHOST;
        case ABILITY_ID::TRAIN_MARAUDER:             return UNIT_TYPEID::TERRAN_MARAUDER;
        case ABILITY_ID::TRAIN_REAPER:               return UNIT_TYPEID::TERRAN_REAPER;
        case ABILITY_ID::TRAIN_MARINE:               return UNIT_TYPEID::TERRAN_MARINE;
            // Factory
        case ABILITY_ID::TRAIN_HELLION:              return UNIT_TYPEID::TERRAN_HELLION;
        case ABILITY_ID::TRAIN_SIEGETANK:            return UNIT_TYPEID::TERRAN_SIEGETANK;
        case ABILITY_ID::TRAIN_WIDOWMINE:            return UNIT_TYPEID::TERRAN_WIDOWMINE;
        case ABILITY_ID::TRAIN_HELLBAT:              return UNIT_TYPEID::TERRAN_HELLIONTANK;
        case ABILITY_ID::TRAIN_THOR:                 return UNIT_TYPEID::TERRAN_THOR;
        case ABILITY_ID::TRAIN_CYCLONE:              return UNIT_TYPEID::TERRAN_CYCLONE;
            // Starport
        case ABILITY_ID::TRAIN_VIKINGFIGHTER:        return UNIT_TYPEID::TERRAN_VIKINGFIGHTER;
        case ABILITY_ID::TRAIN_MEDIVAC:              return UNIT_TYPEID::TERRAN_MEDIVAC;
        case ABILITY_ID::TRAIN_RAVEN:                return UNIT_TYPEID::TERRAN_RAVEN;
        case ABILITY_ID::TRAIN_BANSHEE:              return UNIT_TYPEID::TERRAN_BANSHEE;
        case ABILITY_ID::TRAIN_BATTLECRUISER:        return UNIT_TYPEID::TERRAN_BATTLECRUISER;
        case ABILITY_ID::TRAIN_LIBERATOR:            return UNIT_TYPEID::TERRAN_LIBERATOR;
        default:                                     return UNIT_TYPEID::INVALID;
    }
}

static float UpgradeProgessionFromUpgradeId(const UPGRADE_ID upgrade_id) {
    switch (upgrade_id) {
        case UPGRADE_ID::TERRANSHIPWEAPONSLEVEL1:              return 1.f / 3;
        case UPGRADE_ID::TERRANSHIPWEAPONSLEVEL2:              return 2.f / 3;
        case UPGRADE_ID::TERRANSHIPWEAPONSLEVEL3:              return 1.f;
        case UPGRADE_ID::TERRANVEHICLEANDSHIPARMORSLEVEL1:     return 1.f / 3;
        case UPGRADE_ID::TERRANVEHICLEANDSHIPARMORSLEVEL2:     return 2.f / 3;
        case UPGRADE_ID::TERRANVEHICLEANDSHIPARMORSLEVEL3:     return 1.f;
        case UPGRADE_ID::TERRANVEHICLEWEAPONSLEVEL1:           return 1.f / 3;
        case UPGRADE_ID::TERRANVEHICLEWEAPONSLEVEL2:           return 2.f / 3;
        case UPGRADE_ID::TERRANVEHICLEWEAPONSLEVEL3:           return 1.f;
        case UPGRADE_ID::STIMPACK:                             return 1.f;
        case UPGRADE_ID::SHIELDWALL:                           return 1.f;
        case UPGRADE_ID::PUNISHERGRENADES:                     return 1.f;
        case UPGRADE_ID::HISECAUTOTRACKING:                    return 1.f;
        case UPGRADE_ID::TERRANBUILDINGARMOR:                  return 1.f;
        case UPGRADE_ID::NEOSTEELFRAME:                        return 1.f;
        case UPGRADE_ID::TERRANINFANTRYARMORSLEVEL1:           return 1.f / 3;
        case UPGRADE_ID::TERRANINFANTRYARMORSLEVEL2:           return 2.f / 3;
        case UPGRADE_ID::TERRANINFANTRYARMORSLEVEL3:           return 1.f;
        case UPGRADE_ID::TERRANINFANTRYWEAPONSLEVEL1:          return 1.f / 3;
        case UPGRADE_ID::TERRANINFANTRYWEAPONSLEVEL2:          return 2.f / 3;
        case UPGRADE_ID::TERRANINFANTRYWEAPONSLEVEL3:          return 1.f;
        case UPGRADE_ID::HIGHCAPACITYBARRELS:                  return 1.f;
        case UPGRADE_ID::DRILLCLAWS:                           return 1.f;
        case UPGRADE_ID::RAPIDFIRELAUNCHERS:                   return 1.f;
        case UPGRADE_ID::SMARTSERVOS:                          return 1.f;
        case UPGRADE_ID::BATTLECRUISERENABLESPECIALIZATIONS:   return 1.f;
        case UPGRADE_ID::PERSONALCLOAKING:                     return 1.f;
        case UPGRADE_ID::BANSHEECLOAK:                         return 1.f;
        case UPGRADE_ID::RAVENCORVIDREACTOR:                   return 1.f;
        case UPGRADE_ID::BANSHEESPEED:                         return 1.f;
        case UPGRADE_ID::MEDIVACINCREASESPEEDBOOST:            return 1.f;
        case UPGRADE_ID::LIBERATORAGRANGEUPGRADE:              return 1.f;
        default: return -1.f;
    }
}

static UPGRADE_ID GetUpgradeIdFromAbilityId(const ABILITY_ID ability_id) {
    switch (ability_id) {
        case ABILITY_ID::RESEARCH_TERRANSHIPWEAPONS:                       return UPGRADE_ID::TERRANSHIPWEAPONSLEVEL1;
        case ABILITY_ID::RESEARCH_TERRANSHIPWEAPONSLEVEL1:                 return UPGRADE_ID::TERRANSHIPWEAPONSLEVEL1;
        case ABILITY_ID::RESEARCH_TERRANSHIPWEAPONSLEVEL2:                 return UPGRADE_ID::TERRANSHIPWEAPONSLEVEL2;
        case ABILITY_ID::RESEARCH_TERRANSHIPWEAPONSLEVEL3:                 return UPGRADE_ID::TERRANSHIPWEAPONSLEVEL3;
        case ABILITY_ID::RESEARCH_TERRANVEHICLEANDSHIPPLATING:             return UPGRADE_ID::TERRANVEHICLEANDSHIPARMORSLEVEL1;
        case ABILITY_ID::RESEARCH_TERRANVEHICLEANDSHIPPLATINGLEVEL1:       return UPGRADE_ID::TERRANVEHICLEANDSHIPARMORSLEVEL1;
        case ABILITY_ID::RESEARCH_TERRANVEHICLEANDSHIPPLATINGLEVEL2:       return UPGRADE_ID::TERRANVEHICLEANDSHIPARMORSLEVEL2;
        case ABILITY_ID::RESEARCH_TERRANVEHICLEANDSHIPPLATINGLEVEL3:       return UPGRADE_ID::TERRANVEHICLEANDSHIPARMORSLEVEL3;
        case ABILITY_ID::RESEARCH_TERRANVEHICLEWEAPONS:                    return UPGRADE_ID::TERRANVEHICLEWEAPONSLEVEL1;
        case ABILITY_ID::RESEARCH_TERRANVEHICLEWEAPONSLEVEL1:              return UPGRADE_ID::TERRANVEHICLEWEAPONSLEVEL1;
        case ABILITY_ID::RESEARCH_TERRANVEHICLEWEAPONSLEVEL2:              return UPGRADE_ID::TERRANVEHICLEWEAPONSLEVEL2;
        case ABILITY_ID::RESEARCH_TERRANVEHICLEWEAPONSLEVEL3:              return UPGRADE_ID::TERRANVEHICLEWEAPONSLEVEL3;
        case ABILITY_ID::RESEARCH_STIMPACK:                                return UPGRADE_ID::STIMPACK;
        case ABILITY_ID::RESEARCH_COMBATSHIELD:                            return UPGRADE_ID::SHIELDWALL;
        case ABILITY_ID::RESEARCH_CONCUSSIVESHELLS:                        return UPGRADE_ID::PUNISHERGRENADES;
        case ABILITY_ID::RESEARCH_HISECAUTOTRACKING:                       return UPGRADE_ID::HISECAUTOTRACKING;
        case ABILITY_ID::RESEARCH_TERRANSTRUCTUREARMORUPGRADE:             return UPGRADE_ID::TERRANBUILDINGARMOR;
        case ABILITY_ID::RESEARCH_NEOSTEELFRAME:                           return UPGRADE_ID::NEOSTEELFRAME;
        case ABILITY_ID::RESEARCH_TERRANINFANTRYARMOR:                     return UPGRADE_ID::TERRANINFANTRYARMORSLEVEL1;
        case ABILITY_ID::RESEARCH_TERRANINFANTRYARMORLEVEL1:               return UPGRADE_ID::TERRANINFANTRYARMORSLEVEL1;
        case ABILITY_ID::RESEARCH_TERRANINFANTRYARMORLEVEL2:               return UPGRADE_ID::TERRANINFANTRYARMORSLEVEL2;
        case ABILITY_ID::RESEARCH_TERRANINFANTRYARMORLEVEL3:               return UPGRADE_ID::TERRANINFANTRYARMORSLEVEL3;
        case ABILITY_ID::RESEARCH_TERRANINFANTRYWEAPONS:                   return UPGRADE_ID::TERRANINFANTRYWEAPONSLEVEL1;
        case ABILITY_ID::RESEARCH_TERRANINFANTRYWEAPONSLEVEL1:             return UPGRADE_ID::TERRANINFANTRYWEAPONSLEVEL1;
        case ABILITY_ID::RESEARCH_TERRANINFANTRYWEAPONSLEVEL2:             return UPGRADE_ID::TERRANINFANTRYWEAPONSLEVEL2;
        case ABILITY_ID::RESEARCH_TERRANINFANTRYWEAPONSLEVEL3:             return UPGRADE_ID::TERRANINFANTRYWEAPONSLEVEL3;
        case ABILITY_ID::RESEARCH_INFERNALPREIGNITER:                      return UPGRADE_ID::HIGHCAPACITYBARRELS;
        case ABILITY_ID::RESEARCH_DRILLINGCLAWS:                           return UPGRADE_ID::DRILLCLAWS;
        case ABILITY_ID::RESEARCH_RAPIDFIRELAUNCHERS:                      return UPGRADE_ID::RAPIDFIRELAUNCHERS;
        case ABILITY_ID::RESEARCH_SMARTSERVOS:                             return UPGRADE_ID::SMARTSERVOS;
        case ABILITY_ID::RESEARCH_BATTLECRUISERWEAPONREFIT:                return UPGRADE_ID::BATTLECRUISERENABLESPECIALIZATIONS;
        case ABILITY_ID::RESEARCH_PERSONALCLOAKING:                        return UPGRADE_ID::PERSONALCLOAKING;
        case ABILITY_ID::RESEARCH_BANSHEECLOAKINGFIELD:                    return UPGRADE_ID::BANSHEECLOAK;
        case ABILITY_ID::RESEARCH_RAVENCORVIDREACTOR:                      return UPGRADE_ID::RAVENCORVIDREACTOR;
        case ABILITY_ID::RESEARCH_BANSHEEHYPERFLIGHTROTORS:                return UPGRADE_ID::BANSHEESPEED;
        case ABILITY_ID::RESEARCH_HIGHCAPACITYFUELTANKS:                   return UPGRADE_ID::MEDIVACINCREASESPEEDBOOST;
        case ABILITY_ID::RESEARCH_ADVANCEDBALLISTICS:                      return UPGRADE_ID::LIBERATORAGRANGEUPGRADE;
        default: return UPGRADE_ID::INVALID;
    }
}

static MATERIAL GetMaterialFromUnitType(const UNIT_TYPEID& unit_type_id) {
    switch (unit_type_id) {
        case UNIT_TYPEID::TERRAN_ARMORY:                    return MATERIAL::ARMORY;
        case UNIT_TYPEID::TERRAN_BANSHEE:                   return MATERIAL::BANSHEE;
        case UNIT_TYPEID::TERRAN_BARRACKS:
        case UNIT_TYPEID::TERRAN_BARRACKSFLYING:            return MATERIAL::BARRACKS;
        case UNIT_TYPEID::TERRAN_BARRACKSREACTOR:           return MATERIAL::REACTOR_BARRACKS;
        case UNIT_TYPEID::TERRAN_BARRACKSTECHLAB:           return MATERIAL::TECHLAB_BARRACKS;
        case UNIT_TYPEID::TERRAN_BATTLECRUISER:             return MATERIAL::BATTLECRUISER;
        case UNIT_TYPEID::TERRAN_BUNKER:                    return MATERIAL::BUNKER;
        case UNIT_TYPEID::TERRAN_COMMANDCENTER:
        case UNIT_TYPEID::TERRAN_COMMANDCENTERFLYING:       return MATERIAL::COMMANDCENTER;
        case UNIT_TYPEID::TERRAN_CYCLONE:                   return MATERIAL::CYCLONE;
        case UNIT_TYPEID::TERRAN_ENGINEERINGBAY:            return MATERIAL::ENGINEERINGBAY;
        case UNIT_TYPEID::TERRAN_FACTORY:
        case UNIT_TYPEID::TERRAN_FACTORYFLYING:             return MATERIAL::FACTORY;
        case UNIT_TYPEID::TERRAN_FACTORYREACTOR:            return MATERIAL::REACTOR_FACTORY;
        case UNIT_TYPEID::TERRAN_FACTORYTECHLAB:            return MATERIAL::TECHLAB_FACTORY;
        case UNIT_TYPEID::TERRAN_FUSIONCORE:                return MATERIAL::FUSIONCORE;
        case UNIT_TYPEID::TERRAN_GHOST:                     return MATERIAL::GHOST;
        case UNIT_TYPEID::TERRAN_GHOSTACADEMY:              return MATERIAL::GHOSTACADEMY;
        case UNIT_TYPEID::TERRAN_HELLION:                   return MATERIAL::HELLION;
        case UNIT_TYPEID::TERRAN_HELLIONTANK:               return MATERIAL::HELLIONTANK;
        case UNIT_TYPEID::TERRAN_LIBERATOR:
        case UNIT_TYPEID::TERRAN_LIBERATORAG:               return MATERIAL::LIBERATOR;
        case UNIT_TYPEID::TERRAN_MARAUDER:                  return MATERIAL::MARAUDER;
        case UNIT_TYPEID::TERRAN_MARINE:                    return MATERIAL::MARINE;
        case UNIT_TYPEID::TERRAN_MEDIVAC:                   return MATERIAL::MEDIVAC;
        case UNIT_TYPEID::TERRAN_MISSILETURRET:             return MATERIAL::MISSILETURRET;
        case UNIT_TYPEID::TERRAN_MULE:                      return MATERIAL::MULE;
        case UNIT_TYPEID::TERRAN_ORBITALCOMMAND:
        case UNIT_TYPEID::TERRAN_ORBITALCOMMANDFLYING:      return MATERIAL::ORBITALCOMMAND;
        case UNIT_TYPEID::TERRAN_PLANETARYFORTRESS:         return MATERIAL::PLANETARYFORTRESS;
        case UNIT_TYPEID::TERRAN_RAVEN:                     return MATERIAL::RAVEN;
        case UNIT_TYPEID::TERRAN_REAPER:                    return MATERIAL::REAPER;
        case UNIT_TYPEID::TERRAN_REFINERY:                  return MATERIAL::REFINERY;
        case UNIT_TYPEID::TERRAN_SCV:                       return MATERIAL::SCV;
        case UNIT_TYPEID::TERRAN_SENSORTOWER:               return MATERIAL::SENSORTOWER;
        case UNIT_TYPEID::TERRAN_SIEGETANK:
        case UNIT_TYPEID::TERRAN_SIEGETANKSIEGED:           return MATERIAL::SIEGETANK;
        case UNIT_TYPEID::TERRAN_STARPORT:
        case UNIT_TYPEID::TERRAN_STARPORTFLYING:            return MATERIAL::STARPORT;
        case UNIT_TYPEID::TERRAN_STARPORTREACTOR:           return MATERIAL::REACTOR_STARPORT;
        case UNIT_TYPEID::TERRAN_STARPORTTECHLAB:           return MATERIAL::TECHLAB_STARPORT;
        case UNIT_TYPEID::TERRAN_SUPPLYDEPOT:
        case UNIT_TYPEID::TERRAN_SUPPLYDEPOTLOWERED:        return MATERIAL::SUPPLYDEPOT;
        case UNIT_TYPEID::TERRAN_THOR:
        case UNIT_TYPEID::TERRAN_THORAP:                    return MATERIAL::THOR;
        case UNIT_TYPEID::TERRAN_VIKINGASSAULT:
        case UNIT_TYPEID::TERRAN_VIKINGFIGHTER:             return MATERIAL::VIKINGFIGHTER;
        case UNIT_TYPEID::TERRAN_WIDOWMINE:
        case UNIT_TYPEID::TERRAN_WIDOWMINEBURROWED:         return MATERIAL::WIDOWMINE;

        default: return MATERIAL::INVALID;
    }
}

static MATERIAL GetMaterialFromUpgradeId(const UPGRADE_ID upgrade_id) {
    switch (upgrade_id) {
        case UPGRADE_ID::TERRANSHIPWEAPONSLEVEL1:              return MATERIAL::TERRANSHIPWEAPONS;
        case UPGRADE_ID::TERRANSHIPWEAPONSLEVEL2:              return MATERIAL::TERRANSHIPWEAPONS;
        case UPGRADE_ID::TERRANSHIPWEAPONSLEVEL3:              return MATERIAL::TERRANSHIPWEAPONS;
        case UPGRADE_ID::TERRANVEHICLEANDSHIPARMORSLEVEL1:     return MATERIAL::TERRANVEHICLEANDSHIPPLATING;
        case UPGRADE_ID::TERRANVEHICLEANDSHIPARMORSLEVEL2:     return MATERIAL::TERRANVEHICLEANDSHIPPLATING;
        case UPGRADE_ID::TERRANVEHICLEANDSHIPARMORSLEVEL3:     return MATERIAL::TERRANVEHICLEANDSHIPPLATING;
        case UPGRADE_ID::TERRANVEHICLEWEAPONSLEVEL1:           return MATERIAL::TERRANVEHICLEWEAPONS;
        case UPGRADE_ID::TERRANVEHICLEWEAPONSLEVEL2:           return MATERIAL::TERRANVEHICLEWEAPONS;
        case UPGRADE_ID::TERRANVEHICLEWEAPONSLEVEL3:           return MATERIAL::TERRANVEHICLEWEAPONS;

        case UPGRADE_ID::STIMPACK:                             return MATERIAL::STIMPACK;
        case UPGRADE_ID::SHIELDWALL:                           return MATERIAL::COMBATSHIELD;
        case UPGRADE_ID::PUNISHERGRENADES:                     return MATERIAL::CONCUSSIVESHELLS;

        case UPGRADE_ID::HISECAUTOTRACKING:                    return MATERIAL::HISECAUTOTRACKING;
        case UPGRADE_ID::TERRANBUILDINGARMOR:                  return MATERIAL::TERRANSTRUCTUREARMORUPGRADE;
        case UPGRADE_ID::NEOSTEELFRAME:                        return MATERIAL::NEOSTEELFRAME;
        case UPGRADE_ID::TERRANINFANTRYARMORSLEVEL1:           return MATERIAL::TERRANINFANTRYARMOR;
        case UPGRADE_ID::TERRANINFANTRYARMORSLEVEL2:           return MATERIAL::TERRANINFANTRYARMOR;
        case UPGRADE_ID::TERRANINFANTRYARMORSLEVEL3:           return MATERIAL::TERRANINFANTRYARMOR;
        case UPGRADE_ID::TERRANINFANTRYWEAPONSLEVEL1:          return MATERIAL::TERRANINFANTRYWEAPONS;
        case UPGRADE_ID::TERRANINFANTRYWEAPONSLEVEL2:          return MATERIAL::TERRANINFANTRYWEAPONS;
        case UPGRADE_ID::TERRANINFANTRYWEAPONSLEVEL3:          return MATERIAL::TERRANINFANTRYWEAPONS;

        case UPGRADE_ID::HIGHCAPACITYBARRELS:                  return MATERIAL::INFERNALPREIGNITER;
        case UPGRADE_ID::DRILLCLAWS:                           return MATERIAL::DRILLINGCLAWS;
        case UPGRADE_ID::RAPIDFIRELAUNCHERS:                   return MATERIAL::RAPIDFIRELAUNCHERS;
        case UPGRADE_ID::SMARTSERVOS:                          return MATERIAL::SMARTSERVOS;

        case UPGRADE_ID::BATTLECRUISERENABLESPECIALIZATIONS:   return MATERIAL::BATTLECRUISERWEAPONREFIT;

        case UPGRADE_ID::PERSONALCLOAKING:                     return MATERIAL::PERSONALCLOAKING;

        case UPGRADE_ID::BANSHEECLOAK:                         return MATERIAL::BANSHEECLOAKINGFIELD;
        case UPGRADE_ID::RAVENCORVIDREACTOR:                   return MATERIAL::RAVENCORVIDREACTOR;
        case UPGRADE_ID::BANSHEESPEED:                         return MATERIAL::BANSHEEHYPERFLIGHTROTORS;
        case UPGRADE_ID::MEDIVACINCREASESPEEDBOOST:            return MATERIAL::HIGHCAPACITYFUELTANKS;
        case UPGRADE_ID::LIBERATORAGRANGEUPGRADE:              return MATERIAL::ADVANCEDBALLISTICS;
        default: return MATERIAL::INVALID;
    }
}



static MATERIAL GetMaterialFromAbility(const ABILITY_ID& ability_id) {
    switch (ability_id) {
        //Buildings
        case ABILITY_ID::BUILD_COMMANDCENTER:                              return MATERIAL::COMMANDCENTER;
        case ABILITY_ID::MORPH_ORBITALCOMMAND:                             return MATERIAL::ORBITALCOMMAND;
        case ABILITY_ID::MORPH_PLANETARYFORTRESS:                          return MATERIAL::PLANETARYFORTRESS;
        case ABILITY_ID::BUILD_SUPPLYDEPOT:                                return MATERIAL::SUPPLYDEPOT;
        case ABILITY_ID::BUILD_REFINERY:                                   return MATERIAL::REFINERY;
        case ABILITY_ID::BUILD_BARRACKS:                                   return MATERIAL::BARRACKS;
        case ABILITY_ID::BUILD_TECHLAB_BARRACKS:                           return MATERIAL::TECHLAB_BARRACKS;
        case ABILITY_ID::BUILD_REACTOR_BARRACKS:                           return MATERIAL::REACTOR_BARRACKS;
        case ABILITY_ID::BUILD_FACTORY:                                    return MATERIAL::FACTORY;
        case ABILITY_ID::BUILD_TECHLAB_FACTORY:                            return MATERIAL::TECHLAB_FACTORY;
        case ABILITY_ID::BUILD_REACTOR_FACTORY:                            return MATERIAL::REACTOR_FACTORY;
        case ABILITY_ID::BUILD_BUNKER:                                     return MATERIAL::BUNKER;
        case ABILITY_ID::BUILD_STARPORT:                                   return MATERIAL::STARPORT;
        case ABILITY_ID::BUILD_TECHLAB_STARPORT:                           return MATERIAL::TECHLAB_STARPORT;
        case ABILITY_ID::BUILD_REACTOR_STARPORT:                           return MATERIAL::REACTOR_STARPORT;
        case ABILITY_ID::BUILD_GHOSTACADEMY:                               return MATERIAL::GHOSTACADEMY;
        case ABILITY_ID::BUILD_ENGINEERINGBAY:                             return MATERIAL::ENGINEERINGBAY;
        case ABILITY_ID::BUILD_ARMORY:                                     return MATERIAL::ARMORY;
        case ABILITY_ID::BUILD_FUSIONCORE:                                 return MATERIAL::FUSIONCORE;
        case ABILITY_ID::BUILD_SENSORTOWER:                                return MATERIAL::SENSORTOWER;
        case ABILITY_ID::BUILD_MISSILETURRET:                              return MATERIAL::MISSILETURRET;
        case ABILITY_ID::TRAIN_SCV:                                        return MATERIAL::SCV;
        case ABILITY_ID::EFFECT_CALLDOWNMULE:                              return MATERIAL::MULE;
        case ABILITY_ID::TRAIN_GHOST:                                      return MATERIAL::GHOST;
        case ABILITY_ID::TRAIN_MARAUDER:                                   return MATERIAL::MARAUDER;
        case ABILITY_ID::TRAIN_REAPER:                                     return MATERIAL::REAPER;
        case ABILITY_ID::TRAIN_MARINE:                                     return MATERIAL::MARINE;
        case ABILITY_ID::TRAIN_HELLION:                                    return MATERIAL::HELLION;
        case ABILITY_ID::TRAIN_SIEGETANK:                                  return MATERIAL::SIEGETANK;
        case ABILITY_ID::TRAIN_WIDOWMINE:                                  return MATERIAL::WIDOWMINE;
        case ABILITY_ID::TRAIN_HELLBAT:                                    return MATERIAL::HELLIONTANK;
        case ABILITY_ID::TRAIN_THOR:                                       return MATERIAL::THOR;
        case ABILITY_ID::TRAIN_CYCLONE:                                    return MATERIAL::CYCLONE;
        case ABILITY_ID::TRAIN_VIKINGFIGHTER:                              return MATERIAL::VIKINGFIGHTER;
        case ABILITY_ID::TRAIN_MEDIVAC:                                    return MATERIAL::MEDIVAC;
        case ABILITY_ID::TRAIN_RAVEN:                                      return MATERIAL::RAVEN;
        case ABILITY_ID::TRAIN_BANSHEE:                                    return MATERIAL::BANSHEE;
        case ABILITY_ID::TRAIN_BATTLECRUISER:                              return MATERIAL::BATTLECRUISER;
        case ABILITY_ID::TRAIN_LIBERATOR:                                  return MATERIAL::LIBERATOR;
        case ABILITY_ID::RESEARCH_TERRANSHIPWEAPONS:                       return MATERIAL::TERRANSHIPWEAPONS;
        case ABILITY_ID::RESEARCH_TERRANSHIPWEAPONSLEVEL1:                 return MATERIAL::TERRANSHIPWEAPONS;
        case ABILITY_ID::RESEARCH_TERRANSHIPWEAPONSLEVEL2:                 return MATERIAL::TERRANSHIPWEAPONS;
        case ABILITY_ID::RESEARCH_TERRANSHIPWEAPONSLEVEL3:                 return MATERIAL::TERRANSHIPWEAPONS;
        case ABILITY_ID::RESEARCH_TERRANVEHICLEANDSHIPPLATING:             return MATERIAL::TERRANVEHICLEANDSHIPPLATING;
        case ABILITY_ID::RESEARCH_TERRANVEHICLEANDSHIPPLATINGLEVEL1:       return MATERIAL::TERRANVEHICLEANDSHIPPLATING;
        case ABILITY_ID::RESEARCH_TERRANVEHICLEANDSHIPPLATINGLEVEL2:       return MATERIAL::TERRANVEHICLEANDSHIPPLATING;
        case ABILITY_ID::RESEARCH_TERRANVEHICLEANDSHIPPLATINGLEVEL3:       return MATERIAL::TERRANVEHICLEANDSHIPPLATING;
        case ABILITY_ID::RESEARCH_TERRANVEHICLEWEAPONS:                    return MATERIAL::TERRANVEHICLEWEAPONS;
        case ABILITY_ID::RESEARCH_TERRANVEHICLEWEAPONSLEVEL1:              return MATERIAL::TERRANVEHICLEWEAPONS;
        case ABILITY_ID::RESEARCH_TERRANVEHICLEWEAPONSLEVEL2:              return MATERIAL::TERRANVEHICLEWEAPONS;
        case ABILITY_ID::RESEARCH_TERRANVEHICLEWEAPONSLEVEL3:              return MATERIAL::TERRANVEHICLEWEAPONS;
        case ABILITY_ID::RESEARCH_STIMPACK:                                return MATERIAL::STIMPACK;
        case ABILITY_ID::RESEARCH_COMBATSHIELD:                            return MATERIAL::COMBATSHIELD;
        case ABILITY_ID::RESEARCH_CONCUSSIVESHELLS:                        return MATERIAL::CONCUSSIVESHELLS;
        case ABILITY_ID::RESEARCH_HISECAUTOTRACKING:                       return MATERIAL::HISECAUTOTRACKING;
        case ABILITY_ID::RESEARCH_TERRANSTRUCTUREARMORUPGRADE:             return MATERIAL::TERRANSTRUCTUREARMORUPGRADE;
        case ABILITY_ID::RESEARCH_NEOSTEELFRAME:                           return MATERIAL::NEOSTEELFRAME;
        case ABILITY_ID::RESEARCH_TERRANINFANTRYARMOR:                     return MATERIAL::TERRANINFANTRYARMOR;
        case ABILITY_ID::RESEARCH_TERRANINFANTRYARMORLEVEL1:               return MATERIAL::TERRANINFANTRYARMOR;
        case ABILITY_ID::RESEARCH_TERRANINFANTRYARMORLEVEL2:               return MATERIAL::TERRANINFANTRYARMOR;
        case ABILITY_ID::RESEARCH_TERRANINFANTRYARMORLEVEL3:               return MATERIAL::TERRANINFANTRYARMOR;
        case ABILITY_ID::RESEARCH_TERRANINFANTRYWEAPONS:                   return MATERIAL::TERRANINFANTRYWEAPONS;
        case ABILITY_ID::RESEARCH_TERRANINFANTRYWEAPONSLEVEL1:             return MATERIAL::TERRANINFANTRYWEAPONS;
        case ABILITY_ID::RESEARCH_TERRANINFANTRYWEAPONSLEVEL2:             return MATERIAL::TERRANINFANTRYWEAPONS;
        case ABILITY_ID::RESEARCH_TERRANINFANTRYWEAPONSLEVEL3:             return MATERIAL::TERRANINFANTRYWEAPONS;
        case ABILITY_ID::RESEARCH_INFERNALPREIGNITER:                      return MATERIAL::INFERNALPREIGNITER;
        case ABILITY_ID::RESEARCH_DRILLINGCLAWS:                           return MATERIAL::DRILLINGCLAWS;
        case ABILITY_ID::RESEARCH_RAPIDFIRELAUNCHERS:                      return MATERIAL::RAPIDFIRELAUNCHERS;
        case ABILITY_ID::RESEARCH_SMARTSERVOS:                             return MATERIAL::SMARTSERVOS;
        case ABILITY_ID::RESEARCH_BATTLECRUISERWEAPONREFIT:                return MATERIAL::BATTLECRUISERWEAPONREFIT;
        case ABILITY_ID::RESEARCH_PERSONALCLOAKING:                        return MATERIAL::PERSONALCLOAKING;
        case ABILITY_ID::RESEARCH_BANSHEECLOAKINGFIELD:                    return MATERIAL::BANSHEECLOAKINGFIELD;
        case ABILITY_ID::RESEARCH_RAVENCORVIDREACTOR:                      return MATERIAL::RAVENCORVIDREACTOR;
        case ABILITY_ID::RESEARCH_BANSHEEHYPERFLIGHTROTORS:                return MATERIAL::BANSHEEHYPERFLIGHTROTORS;
        case ABILITY_ID::RESEARCH_HIGHCAPACITYFUELTANKS:                   return MATERIAL::HIGHCAPACITYFUELTANKS;
        case ABILITY_ID::RESEARCH_ADVANCEDBALLISTICS:                      return MATERIAL::ADVANCEDBALLISTICS;
        default:                                                           return MATERIAL::INVALID;
    }
}

static ACTION GetActionFromAbility(const ABILITY_ID& ability_id) {
    switch (ability_id) {
        //Buildings
        case ABILITY_ID::BUILD_COMMANDCENTER:                              return ACTION::COMMANDCENTER;
        case ABILITY_ID::MORPH_ORBITALCOMMAND:                             return ACTION::ORBITALCOMMAND;
        case ABILITY_ID::MORPH_PLANETARYFORTRESS:                          return ACTION::PLANETARYFORTRESS;
        case ABILITY_ID::BUILD_SUPPLYDEPOT:                                return ACTION::SUPPLYDEPOT;
        case ABILITY_ID::BUILD_REFINERY:                                   return ACTION::REFINERY;
        case ABILITY_ID::BUILD_BARRACKS:                                   return ACTION::BARRACKS;
        case ABILITY_ID::BUILD_TECHLAB_BARRACKS:                           return ACTION::TECHLAB_BARRACKS;
        case ABILITY_ID::BUILD_REACTOR_BARRACKS:                           return ACTION::REACTOR_BARRACKS;
        case ABILITY_ID::BUILD_FACTORY:                                    return ACTION::FACTORY;
        case ABILITY_ID::BUILD_TECHLAB_FACTORY:                            return ACTION::TECHLAB_FACTORY;
        case ABILITY_ID::BUILD_REACTOR_FACTORY:                            return ACTION::REACTOR_FACTORY;
        case ABILITY_ID::BUILD_BUNKER:                                     return ACTION::BUNKER;
        case ABILITY_ID::BUILD_STARPORT:                                   return ACTION::STARPORT;
        case ABILITY_ID::BUILD_TECHLAB_STARPORT:                           return ACTION::TECHLAB_STARPORT;
        case ABILITY_ID::BUILD_REACTOR_STARPORT:                           return ACTION::REACTOR_STARPORT;
        case ABILITY_ID::BUILD_GHOSTACADEMY:                               return ACTION::GHOSTACADEMY;
        case ABILITY_ID::BUILD_ENGINEERINGBAY:                             return ACTION::ENGINEERINGBAY;
        case ABILITY_ID::BUILD_ARMORY:                                     return ACTION::ARMORY;
        case ABILITY_ID::BUILD_FUSIONCORE:                                 return ACTION::FUSIONCORE;
        case ABILITY_ID::TRAIN_SCV:                                        return ACTION::SCV;
        case ABILITY_ID::EFFECT_CALLDOWNMULE:                              return ACTION::MULE;
        case ABILITY_ID::TRAIN_GHOST:                                      return ACTION::GHOST;
        case ABILITY_ID::TRAIN_MARAUDER:                                   return ACTION::MARAUDER;
        case ABILITY_ID::TRAIN_REAPER:                                     return ACTION::REAPER;
        case ABILITY_ID::TRAIN_MARINE:                                     return ACTION::MARINE;
        case ABILITY_ID::TRAIN_HELLION:                                    return ACTION::HELLION;
        case ABILITY_ID::TRAIN_SIEGETANK:                                  return ACTION::SIEGETANK;
        case ABILITY_ID::TRAIN_WIDOWMINE:                                  return ACTION::WIDOWMINE;
        case ABILITY_ID::TRAIN_HELLBAT:                                    return ACTION::HELLIONTANK;
        case ABILITY_ID::TRAIN_THOR:                                       return ACTION::THOR;
        case ABILITY_ID::TRAIN_CYCLONE:                                    return ACTION::CYCLONE;
        case ABILITY_ID::TRAIN_VIKINGFIGHTER:                              return ACTION::VIKINGFIGHTER;
        case ABILITY_ID::TRAIN_MEDIVAC:                                    return ACTION::MEDIVAC;
        case ABILITY_ID::TRAIN_RAVEN:                                      return ACTION::RAVEN;
        case ABILITY_ID::TRAIN_BANSHEE:                                    return ACTION::BANSHEE;
        case ABILITY_ID::TRAIN_BATTLECRUISER:                              return ACTION::BATTLECRUISER;
        case ABILITY_ID::TRAIN_LIBERATOR:                                  return ACTION::LIBERATOR;
        case ABILITY_ID::RESEARCH_TERRANSHIPWEAPONS:                       return ACTION::TERRANSHIPWEAPONS;
        case ABILITY_ID::RESEARCH_TERRANSHIPWEAPONSLEVEL1:                 return ACTION::TERRANSHIPWEAPONS;
        case ABILITY_ID::RESEARCH_TERRANSHIPWEAPONSLEVEL2:                 return ACTION::TERRANSHIPWEAPONS;
        case ABILITY_ID::RESEARCH_TERRANSHIPWEAPONSLEVEL3:                 return ACTION::TERRANSHIPWEAPONS;
        case ABILITY_ID::RESEARCH_TERRANVEHICLEANDSHIPPLATING:             return ACTION::TERRANVEHICLEANDSHIPPLATING;
        case ABILITY_ID::RESEARCH_TERRANVEHICLEANDSHIPPLATINGLEVEL1:       return ACTION::TERRANVEHICLEANDSHIPPLATING;
        case ABILITY_ID::RESEARCH_TERRANVEHICLEANDSHIPPLATINGLEVEL2:       return ACTION::TERRANVEHICLEANDSHIPPLATING;
        case ABILITY_ID::RESEARCH_TERRANVEHICLEANDSHIPPLATINGLEVEL3:       return ACTION::TERRANVEHICLEANDSHIPPLATING;
        case ABILITY_ID::RESEARCH_TERRANVEHICLEWEAPONS:                    return ACTION::TERRANVEHICLEWEAPONS;
        case ABILITY_ID::RESEARCH_TERRANVEHICLEWEAPONSLEVEL1:              return ACTION::TERRANVEHICLEWEAPONS;
        case ABILITY_ID::RESEARCH_TERRANVEHICLEWEAPONSLEVEL2:              return ACTION::TERRANVEHICLEWEAPONS;
        case ABILITY_ID::RESEARCH_TERRANVEHICLEWEAPONSLEVEL3:              return ACTION::TERRANVEHICLEWEAPONS;
        case ABILITY_ID::RESEARCH_STIMPACK:                                return ACTION::STIMPACK;
        case ABILITY_ID::RESEARCH_COMBATSHIELD:                            return ACTION::COMBATSHIELD;
        case ABILITY_ID::RESEARCH_CONCUSSIVESHELLS:                        return ACTION::CONCUSSIVESHELLS;
        case ABILITY_ID::RESEARCH_HISECAUTOTRACKING:                       return ACTION::HISECAUTOTRACKING;
        case ABILITY_ID::RESEARCH_TERRANSTRUCTUREARMORUPGRADE:             return ACTION::TERRANSTRUCTUREARMORUPGRADE;
        case ABILITY_ID::RESEARCH_NEOSTEELFRAME:                           return ACTION::NEOSTEELFRAME;
        case ABILITY_ID::RESEARCH_TERRANINFANTRYARMOR:                     return ACTION::TERRANINFANTRYARMOR;
        case ABILITY_ID::RESEARCH_TERRANINFANTRYARMORLEVEL1:               return ACTION::TERRANINFANTRYARMOR;
        case ABILITY_ID::RESEARCH_TERRANINFANTRYARMORLEVEL2:               return ACTION::TERRANINFANTRYARMOR;
        case ABILITY_ID::RESEARCH_TERRANINFANTRYARMORLEVEL3:               return ACTION::TERRANINFANTRYARMOR;
        case ABILITY_ID::RESEARCH_TERRANINFANTRYWEAPONS:                   return ACTION::TERRANINFANTRYWEAPONS;
        case ABILITY_ID::RESEARCH_TERRANINFANTRYWEAPONSLEVEL1:             return ACTION::TERRANINFANTRYWEAPONS;
        case ABILITY_ID::RESEARCH_TERRANINFANTRYWEAPONSLEVEL2:             return ACTION::TERRANINFANTRYWEAPONS;
        case ABILITY_ID::RESEARCH_TERRANINFANTRYWEAPONSLEVEL3:             return ACTION::TERRANINFANTRYWEAPONS;
        case ABILITY_ID::RESEARCH_INFERNALPREIGNITER:                      return ACTION::INFERNALPREIGNITER;
        case ABILITY_ID::RESEARCH_DRILLINGCLAWS:                           return ACTION::DRILLINGCLAWS;
        case ABILITY_ID::RESEARCH_RAPIDFIRELAUNCHERS:                      return ACTION::RAPIDFIRELAUNCHERS;
        case ABILITY_ID::RESEARCH_SMARTSERVOS:                             return ACTION::SMARTSERVOS;
        case ABILITY_ID::RESEARCH_BATTLECRUISERWEAPONREFIT:                return ACTION::BATTLECRUISERWEAPONREFIT;
        case ABILITY_ID::RESEARCH_PERSONALCLOAKING:                        return ACTION::PERSONALCLOAKING;
        case ABILITY_ID::RESEARCH_BANSHEECLOAKINGFIELD:                    return ACTION::BANSHEECLOAKINGFIELD;
        case ABILITY_ID::RESEARCH_RAVENCORVIDREACTOR:                      return ACTION::RAVENCORVIDREACTOR;
        case ABILITY_ID::RESEARCH_BANSHEEHYPERFLIGHTROTORS:                return ACTION::BANSHEEHYPERFLIGHTROTORS;
        case ABILITY_ID::RESEARCH_HIGHCAPACITYFUELTANKS:                   return ACTION::HIGHCAPACITYFUELTANKS;
        case ABILITY_ID::RESEARCH_ADVANCEDBALLISTICS:                      return ACTION::ADVANCEDBALLISTICS;
        case ABILITY_ID::EFFECT_SUPPLYDROP:                                return ACTION::SUPPLYDROP;
        default:                                                           return ACTION::INVALID;
    }
}