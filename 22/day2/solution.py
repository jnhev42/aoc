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

PART1_CODE = { 
    "A": Move.ROCK, "B": Move.PAPER, "C": Move.SCISSORS,
    "X": Move.ROCK, "Y": Move.PAPER, "Z": Move.SCISSORS,
}

PART2_CODE = {
    "A": Move.ROCK, "B": Move.PAPER, "C": Move.SCISSORS,
    "X": Outcome.LOSS, "Y": Outcome.DRAW, "Z": Outcome.WIN,
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

def plr_move(opnt: Move, outcome: Outcome):
    if outcome == Outcome.DRAW:
        return opnt
    if outcome == Outcome.LOSS:
        return Move.SCISSORS if opnt == Move.ROCK else Move(opnt - 1)
    if outcome == Outcome.WIN:
        return Move.ROCK if opnt == Move.SCISSORS else Move(opnt + 1)

input = Path('input.txt').read_text()
lines = input.split("\n")[:-1]

pairs_part1 = list(map(lambda l: list(map(PART1_CODE.get, l.split(" "))), lines))
part1 = sum(map(lambda pair: pair[1] + play(*pair), pairs_part1))
print('part1 =', part1)

pairs_part2 = list(map(lambda l: list(map(PART2_CODE.get, l.split(" "))), lines))
part2 = sum(map(lambda pair: pair[1] + plr_move(*pair), pairs_part2))
print('part2 =', part2)
