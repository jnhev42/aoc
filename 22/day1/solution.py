from pathlib import Path

input = Path('input.txt').read_text()
elves = input.split("\n\n")[:-1]
bags = map(lambda elf: map(int, elf.split("\n")), elves)
tot_cals = sorted(map(sum, bags), reverse=True)
print(tot_cals[0])
print(sum(tot_cals[0:3]))
