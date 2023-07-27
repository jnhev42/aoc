#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

int main() {
    std::ifstream input("../input.txt");
    int top[3] = {0, 0, 0};
    int curBag = 0;
    for (std::string line{}; std::getline(input, line);) {
        if (!line.empty()) {
            curBag += std::stoi(line);
        } else {
            if (curBag > top[0]) {
                top[2] = top[1];
                top[1] = top[0];
                top[0] = curBag;
            } else if (curBag > top[1]) {
                top[2] = top[1];
                top[1] = curBag;
            } else if (curBag > top[2]) {
                top[2] = curBag;
            }
            curBag = 0;
        }
    }
    std::cout << "Part 1: " << top[0] << std::endl;
    int top3 = std::accumulate(std::begin(top), std::end(top), 0);
    std::cout << "Part 2: " << top3 << std::endl;
    return 0;
}
