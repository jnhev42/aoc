import { readFileSync } from 'fs';

const splitAt = (string, index) => [
    string.substring(0, index),
    string.substring(index)
];

const uniqueChars = string => Array.from(new Set(Array.from(string)));

const common = (arr1, arr2) => Array.from(arr1.filter(elem => arr2.includes(elem)));

const ascii = char => char.charCodeAt(0);

const groupBy = (n, iter) => {
    let groups = [[]];
    for (const elem of iter) {
        if (groups[groups.length - 1].length == n) {
            groups.push([]);
        }
        groups[groups.length - 1].push(elem);
    }
    return groups;
}

const priority = char => char === char.toUpperCase() ? 
    ascii(char) - ascii('A') + 27 :
    ascii(char) - ascii('a') + 1;

const input = readFileSync('input.txt', {encoding: 'utf-8'});
const output = groupBy(3, input.split('\n'))
    .map(group => {
        const [elf1, elf2, elf3] = group.map(uniqueChars);
        const [allThree] = common(common(elf1, elf2), elf3);
        return priority(allThree);
    })
    .reduce((acc, n) => acc + n, 0);

console.log(`priority sum = ${output}`);
