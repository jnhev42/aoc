from pathlib import Path
def curry(f, *args):
    return lambda *more_args: f(*args, *more_args)

input = Path('input.txt').read_text()
elves = map(lambda elf: map(int, elf.split("\n")), input.split("\n\n")[:-1])
cals = max(map(sum, elves))
print(cals)