#include <sc2api/sc2_api.h>
#include "sc2utils/sc2_manage_process.h"
#include <iostream>
#include "ReplayParser.h"
#include <thread>
#include <vector>
#include <filesystem>
#include "helper.h"

namespace fs = std::experimental::filesystem;

using namespace sc2;

//#define MY_DEBUG
#define VS_4_5_1 "4.5.1"
#define VS_4_4_0 "4.4.0"

// User defined:
#define STAR_CRAFT_II_PATH "I:/Program Files (x86)/StarCraft II"
#define STEP_SIZE 8
#define THREAD_COUNT 4
#define CURRENT_GAME_VERSION VS_4_5_1
// <- User defined

#define MAKE_SC2_VS_DIR(Base) STAR_CRAFT_II_PATH "/Versions/" #Base "/SC2_x64.exe"

void StartBot(int argc, char* argv[], int index, int start_port, std::string replay_folder) {
    Coordinator* coordinator = new Coordinator();
    coordinator->LoadSettings(argc, argv);
    coordinator->SetPortStart(start_port);

    if (!coordinator->SetReplayPath(replay_folder)) {
        std::cout << "Unable to find replays." << std::endl;
        return;
    }
    ReplayParser* parser = new ReplayParser(index);
    coordinator->AddReplayObserver(parser);
    coordinator->SetStepSize(STEP_SIZE);
    if (CURRENT_GAME_VERSION == VS_4_4_0) {
        coordinator->SetProcessPath(MAKE_SC2_VS_DIR(Base65895));
        coordinator->SetDataVersion("BF41339C22AE2EDEBEEADC8C75028F7D");
    } else if (CURRENT_GAME_VERSION == VS_4_5_1) {
        coordinator->SetProcessPath(MAKE_SC2_VS_DIR(Base67188));
        coordinator->SetDataVersion("6D239173B8712461E6A7C644A5539369");
    }
    while (coordinator->Update()) {
    }
    delete coordinator;
    delete parser;
}

void dostuff(int argc, char* argv[]) {
    std::cout << "Starting with version " << CURRENT_GAME_VERSION << " and " << THREAD_COUNT << " threads." << std::endl;

    std::string kReplayFolder = STAR_CRAFT_II_PATH "/Replays/" CURRENT_GAME_VERSION "/";
    std::vector<std::thread> threads(THREAD_COUNT);
    for (int i = 0; i < THREAD_COUNT; ++i) {
        threads[i] = std::thread(StartBot, argc, argv, i, 10000 + (1000 * i), kReplayFolder + "Replays_" + std::to_string(i) + "/");
        Sleep(30);
    }
    for (int i = 0; i < THREAD_COUNT; ++i) {
        threads[i].join();
    }
}

int main(int argc, char* argv[]) {
    std::string path = ExePath();
    if (!fs::exists(path + "\\output")) {
        fs::create_directory(path + "\\output");
    }

    for (int i = 0; i < THREAD_COUNT; ++i) {
        if (!fs::exists(path + "\\output\\data_" + std::to_string(i))) {
            fs::create_directory(path + "\\output\\data_" + std::to_string(i));
        }
    }

    dostuff(argc, argv);

    while (!PollKeyPress()) {
    }
    return 0;
}
