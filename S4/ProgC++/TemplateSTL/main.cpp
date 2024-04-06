#include <iostream>
#include <filesystem>
#include <fstream>
#include <map>
#include <set>
#include <vector>

using std::cout, std::endl, std::string, std::filesystem::directory_iterator, std::map, std::vector, std::ifstream,
        std::filesystem::path, std::set;

int main() {
    map<string, vector<string>> app_data;
    for (const string data_dir_path = "data"; const auto& data_file_path: directory_iterator(data_dir_path)) {
        ifstream app(data_file_path.path());
        string name = path(data_file_path.path()).filename();

        string line;
        vector<string> data;
        while (std::getline(app, line)) {
            std::replace( line.begin(), line.end(), '\n', ' ');
            std::replace( line.begin(), line.end(), '\r', ' ');
            data.emplace_back(line);
        }
        app_data.emplace(name, data);
    }

    set<string> features;

    for (const auto& [k, v]: app_data) {
        features.insert(v.begin(), v.end());
    }


    map<string, map<string, bool>> embedding_vectors;
    map<string, bool> embedding_vector;
    for (const auto& feature: features) {
        embedding_vector.emplace(feature, false);
    }
    for (const auto& [app_name, app_features]: app_data) {

        auto app_embedding_vector (embedding_vector);

        for (const auto& feature: app_features) {
            app_embedding_vector[feature] = true;
        }

        embedding_vectors.emplace(app_name, app_embedding_vector);
    }

    const string out_dir = "out_data";
    if ( !std::filesystem::exists(out_dir)) {
        std::filesystem::create_directory(out_dir);
    }

    for (const auto& [app, embedding_v]: embedding_vectors) {
        std::stringstream ss;
        ss << out_dir << "/" << app;
        std::ofstream app_file(ss.str());

        for (const auto& [feature, value]: embedding_v) {
            app_file << feature << ": " << value << endl;
        }
    }

    return 0;
}
