#include <cassert>

#include "Outcome.h"
#include "Move.h"

Outcome::Outcome(Outcome::OutcomeV kind_) : kind(kind_) {}

Outcome::Outcome(int kindInt) {
    assert(kindInt >= 0 && kindInt <= 2);
    kind = static_cast<OutcomeV>(kindInt);
}

int Outcome::score() const {
    switch (kind) {
        case Outcome::Win:
            return 6;
        case Outcome::Draw:
            return 3;
        case Outcome::Loss:
            return 0;
    }
    assert(false);
}

Move Outcome::findMove(const Move& opponent) {
    switch (kind) {
        case Outcome::Win:
            return opponent.losesTo();
        case Outcome::Loss:
            return opponent.winsTo();
        case Outcome::Draw:
            return opponent.drawsTo();
    }
    assert(false);
}

Outcome Outcome::fromCoded(char coded) {
    return Outcome(coded - 'X');
}

