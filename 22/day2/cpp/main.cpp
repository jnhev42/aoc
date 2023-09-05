#include <iostream>
#include <fstream>
#include <cassert>
#include "Outcome.h"
#include "Move.h"

int main() {
    std::ifstream input("../input.txt");
    int scorePt1 = 0;
    int scorePt2 = 0;
    for (std::string line{}; std::getline(input, line);) {
        auto opponent = Move::fromCoded(line[0], true);
        auto player = Move::fromCoded(line[2], false);
        auto outcome = player.play(opponent);
        scorePt1 += player.score() + outcome.score();

        auto desiredOutcome = Outcome::fromCoded(line[2]);
        scorePt2 += desiredOutcome.findMove(opponent).score() + desiredOutcome.score();
    }
    std::cout << "Score Pt1:" << scorePt1 << std::endl;
    std::cout << "Score Pt2:" << scorePt2 << std::endl;

    return 0;
}
