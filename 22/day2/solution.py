from pathlib import Path
from enum import IntEnum

class Move(IntEnum):
    ROCK = 1
    PAPER = 2
    SCISSORS = 3

class Outcome(IntEnum):
    WIN = 6
    DRAW = 3
    LOSS = 0

MOVE_DECRYPT = { 
    "A": Move.ROCK, "B": Move.PAPER, "C": Move.SCISSORS,
    "X": Move.ROCK, "Y": Move.PAPER, "Z": Move.SCISSORS,
}


def play(opnt: Move, plr: Move):
    if plr == opnt:
        return Outcome.DRAW
    if plr - opnt == 1:
        return Outcome.WIN
    if opnt - plr == 1:
        return Outcome.LOSS
    if plr < opnt:
        return Outcome.WIN
    if plr > opnt:
        return Outcome.LOSS

def dbg(val, name="dbg"):
    print(f"[{name}] {val}")
    return val

input = Path('input.txt').read_text()
lines = input.split("\n")[:-1]
pairs = map(lambda l: list(map(MOVE_DECRYPT.get, l.split(" "))), lines)
score = sum(map(lambda pair: pair[1] + play(*pair), pairs))
print(score)

