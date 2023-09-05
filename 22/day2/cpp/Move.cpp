#include <cassert>

#include "Move.h"
#include "Outcome.h"

Move::Move(int move) {
    assert(move >= 1 && move <= 3);
    kind = static_cast<MoveV>(move);
}

int Move::score() const {
    return static_cast<int>(kind);
}

Move Move::fromCoded(char coded, bool isOpponent) {
    auto base = isOpponent ? 'A' : 'X';
    auto move = coded - base + 1;
    return Move(move);
}

Outcome Move::play(const Move &other) const {
    switch (score() - other.score()) {
        case 0:
            return Outcome(Outcome::Draw);
        case -2:
        case 1:
            return Outcome(Outcome::Win);
        default:
            return Outcome(Outcome::Loss);
    }
}

Move Move::losesTo() const {
    int s = score();
    return Move(s == 3 ? 1 : s + 1);
}

Move Move::winsTo() const {
    int s = score();
    return Move(s == 1 ? 3 : s - 1);
}

Move Move::drawsTo() const {
    return Move(score());
}
