#pragma once
#include "Outcome.h"

class Move {
protected:
    enum MoveV {
        Rock = 1,
        Paper = 2,
        Scissors = 3,
    };
    MoveV kind;

    explicit Move(int);

public:
    int score() const;

    static Move fromCoded(char, bool);

    Outcome play(const Move &) const;

    Move losesTo() const;

    Move winsTo() const;

    Move drawsTo() const;
};
