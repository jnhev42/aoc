#pragma once
class Move;

class Outcome {
protected:
    enum class OutcomeV {
        Loss = 0,
        Draw = 1,
        Win = 2,
    };

    explicit Outcome(int);

    OutcomeV kind;
public:
    using
    enum OutcomeV;

    explicit Outcome(OutcomeV);

    int score() const;

    static Outcome fromCoded(char);

    Move findMove(const Move&);
};
