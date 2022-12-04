import { readFileSync } from 'fs';

const input = readFileSync('input.txt', {encoding: 'utf-8'});

const parsePair = line => line
        .split(',')
        .map(sect => sect.split('-').map(n => parseInt(n)));

const pairContains = ([aLower, aUpper], [bLower, bUpper]) => 
    aLower <= bLower && aUpper >= bUpper;

const pairsList = input.split('\n').map(parsePair);

const totalOverlaps = pairsList.map(pairs => 
        pairContains(pairs[0], pairs[1]) || 
        pairContains(pairs[1], pairs[0])
    )
    .reduce((acc, x) => acc + x, 0);

console.log(`total overlaps: ${totalOverlaps}`);
    