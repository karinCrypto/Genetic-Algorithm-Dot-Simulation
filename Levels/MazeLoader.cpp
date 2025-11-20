// 미로 txt 파일 로더

#include "MazeLoader.h"

std::vector<int> MazeLoader::loadFromFile(const char* path) {
    std::vector<int> data;
    std::ifstream file(path);
    char c;

    while (file.get(c)) {
        if (c == '0') data.push_back(0);
        if (c == '1') data.push_back(1);
    }
    return data;
}
