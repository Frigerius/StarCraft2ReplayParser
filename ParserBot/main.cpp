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
#define MY_DEBUG
#define VS_4_5_1 "4.5.1/"
#define VS_4_4_0 "4.4.0/"

std::string Current = "";

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
    coordinator->SetStepSize(8);
    if (Current == VS_4_4_0) {
        coordinator->SetProcessPath("I:/Program Files (x86)/StarCraft II/Versions/Base65895/SC2_x64.exe");
        coordinator->SetDataVersion("BF41339C22AE2EDEBEEADC8C75028F7D");
    } else if (Current == VS_4_5_1) {
        coordinator->SetProcessPath("I:/Program Files (x86)/StarCraft II/Versions/Base67188/SC2_x64.exe");
        coordinator->SetDataVersion("6D239173B8712461E6A7C644A5539369");
    }
    while (coordinator->Update()) {
    }
    delete coordinator;
    delete parser;
}

void dostuff(int argc, char* argv[], int parallelcount, std::string subfolder) {
    std::cout << "Starting with version " << subfolder << std::endl;

    std::string kReplayFolder = "I:/Program Files (x86)/StarCraft II/Replays/" + subfolder;
    std::vector<std::thread> threads(parallelcount);
    for (int i = 0; i < parallelcount; ++i) {
        threads[i] = std::thread(StartBot, argc, argv, i, 10000 + (1000 * i), kReplayFolder + "Replays_" + std::to_string(i) + "/");
        Sleep(30);
    }
    for (int i = 0; i < parallelcount; ++i) {
        threads[i].join();
    }
}

int main(int argc, char* argv[]) {
    std::string path = ExePath();
    if (!fs::exists(path + "\\output")) {
        fs::create_directory(path + "\\output");
    }

    int thread_count = 4;
#ifdef MY_DEBUG
    thread_count = 1;
#endif
    for (int i = 0; i < thread_count; ++i) {
        if (!fs::exists(path + "\\output\\data_" + std::to_string(i))) {
            fs::create_directory(path + "\\output\\data_" + std::to_string(i));
        }
    }
    // Current = VS_4_4_0;
    // dostuff(argc, argv, thread_count, Current);
    Current = VS_4_5_1;
    dostuff(argc, argv, thread_count, Current);

    // StartTestBot(argc, argv);
    while (!PollKeyPress()) {
    }
    return 0;
}
