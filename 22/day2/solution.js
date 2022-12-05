import { readFileSync } from 'fs';

const input = readFileSync('input.txt', {encoding: 'utf-8'});

const MOVE = {
    ROCK: 1,
    PAPER: 2,
    SCISSORS: 3,
}

const MOVES = [MOVE.ROCK, MOVE.PAPER, MOVE.SCISSORS];

const OUTCOME = {
    WIN: 6,
    DRAW: 3,
    LOSS: 0,
};

const MOVE_CODE = {
    A: MOVE.ROCK,
    X: MOVE.ROCK,
    B: MOVE.PAPER,
    Y: MOVE.PAPER,
    C: MOVE.SCISSORS,
    Z: MOVE.SCISSORS,
};

const OUTCOME_CODE = {
    X: OUTCOME.LOSS,
    Y: OUTCOME.DRAW,
    Z: OUTCOME.WIN,
};

const BEATS = {
    [MOVE.ROCK]: MOVE.SCISSORS,
    [MOVE.PAPER]: MOVE.ROCK,
    [MOVE.SCISSORS]: MOVE.PAPER,
};
    
const outcomeOf = (plr, opnt) => 
    opnt === plr ?
        OUTCOME.DRAW :
    BEATS[plr] === opnt ?
        OUTCOME.WIN : OUTCOME.LOSS;

const playerMove = (opnt, outcome) => 
    MOVES.filter(move => outcomeOf(move, opnt) == outcome).at(0);

const rounds = input
    .trim()
    .split('\n')
    .map(line => line.split(' '));

const part1 = rounds
    .map(moves => moves.map(move => MOVE_CODE[move]))
    .map(([opnt, plr]) => plr + outcomeOf(plr, opnt))
    .reduce((acc, x) => acc + x, 0);

const part2 = rounds
    .map(([opnt, outcome]) => 
        [MOVE_CODE[opnt], OUTCOME_CODE[outcome]]
    )
    .map(([opnt, outcome]) => outcome + playerMove(opnt, outcome))
    .reduce((acc, x) => acc + x, 0);

console.log(`part1 = ${part1}`);
console.log(`part2 = ${part2}`);