//
// Created by Amrik.Sadhra on 20/06/2018.
//

#pragma once

#include <sstream>
#include <iomanip>
#include <cstdint>
#include <cstdlib>
#include "trk_loader.h"
#include "../Physics/Car.h"
#include "../Config.h"
#include "../Util/Utils.h"
#include "../Scene/TrackBlock.h"
#include "../nfs_data.h"

using namespace NFS3_4;
using namespace Utils;

class NFS3 {
public:
    static std::shared_ptr<Car> LoadCar(const string &car_base_path, string *car_name);
    static std::shared_ptr<TRACK> LoadTrack(const std::string &track_base_path);

    static void ConvertFCE(const std::string &fce_path, const std::string &obj_out_path);
private:
    // Car
    static std::vector<CarModel> LoadFCE(const std::string &fce_path);
    // Track
    static bool LoadFRD(std::string frd_path, const std::string &track_name, std::shared_ptr<TRACK> track);
    static bool LoadCOL(std::string col_path, std::shared_ptr<TRACK> track);
    static std::vector<TrackBlock> ParseTRKModels(std::shared_ptr<TRACK>track);
    static std::vector<Track> ParseCOLModels(std::shared_ptr<TRACK> track);
    static Texture LoadTexture(TEXTUREBLOCK track_texture, const std::string &track_name);
};



