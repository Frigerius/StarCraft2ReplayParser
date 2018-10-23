#pragma once
#include "sc2api/sc2_api.h"
#include "Operations.h"
#include <sstream>
#include <unordered_set>

using namespace sc2;

struct BuildOrderEntry {
    uint32_t step;
    union {
        UNIT_TYPEID unitType;
        UPGRADE_ID upgradeId;
    };
    bool isUpgrade;

    BuildOrderEntry(uint32_t pStep, UNIT_TYPEID pType) {
        step = pStep;
        unitType = pType;
        isUpgrade = false;
    }

    BuildOrderEntry(uint32_t pStep, UPGRADE_ID pType) {
        step = pStep;
        upgradeId = pType;
        isUpgrade = true;
    }

    void AppendToJSON(std::ofstream& myfile) const;
};

class ReplayParser : public ReplayObserver {
public:
    ReplayParser(int id);
    ~ReplayParser();

    virtual void OnGameStart() override;
    virtual void OnGameEnd() override;

    virtual void OnStep() override;
    virtual void OnUnitCreated(const Unit*) override;
    virtual void OnUpgradeCompleted(UpgradeID) override;

    virtual bool IgnoreReplay(const ReplayInfo& replay_info, uint32_t& player_id) override;

private:
    int mId;
    std::ostringstream mStream;
    bool mFirstStep;
    bool mEnded;
    std::string mOutputFolder;
    std::string mAnalizedDataFile;
    std::string mCurrentMapName;
    std::string mCurrentReplayName;
    std::unordered_set<UNIT_TYPEID> mUnitsOrdersImInterestedIn;
    std::vector<BuildOrderEntry> mBuildOrdersFromActions;
    std::vector<BuildOrderEntry> mBuildOrdersFromOnCreated;
    std::unordered_set<Tag> mSeenUnits;
    float mLastFeatures[int(SECTORS::MAX)];
    float mCurrentFeatures[int(SECTORS::MAX)]{};
    int mProcessedSteps = 0;
};
