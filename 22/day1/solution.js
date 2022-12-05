import { readFileSync } from 'fs';

const input = readFileSync('input.txt', {encoding: 'utf-8'});

const bags = Array.from(input
    .trim()
    .split('\n\n')
    .map(bag => bag.split('\n').map(n => parseInt(n)))
    .map(bag => bag.reduce((acc, x) => acc + x, 0)));

bags.sort((a, b) => b - a);
const top3 = bags.slice(0, 3).reduce((acc, x) => acc + x, 0);

console.log(`max = ${bags[0]}`);
console.log(`top3 = ${top3}`);
