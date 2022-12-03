
import { readFileSync } from 'fs';

const splitAt = (string, index) => [
    string.substring(0, index),
    string.substring(index)
];

const ascii = char => char.charCodeAt(0);

const priority = char => char === char.toUpperCase() ? 
    ascii(char) - ascii('A') + 27 :
    ascii(char) - ascii('a') + 1;

const input = readFileSync('input.txt', {encoding: 'utf-8'});
const output = input.split('\n').map(backpack => {
    const [comp1, comp2] = splitAt(backpack, Math.floor(backpack.length / 2))
        .map(str => Array.from(str))
        .map(chars => new Set(chars))
        .map(set => Array.from(set));

    const [common] = comp1.filter(elem => comp2.includes(elem));
    return priority(common);
}).reduce((acc, n) => acc + n, 0);

console.log(`priority sum = ${output}`);