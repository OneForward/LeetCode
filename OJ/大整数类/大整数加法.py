import random
import shutil, path

fname = path.Path(__file__).stem
rint = lambda x, y: random.randint(x, y)

random.seed(0)
root = path.Path(f'{fname}_cases')
if not root.exists():
    root.mkdir()

import string 

cases = [
    (0, 1),
    (1000, 0),
    (999, 9),
    (9, 999999),
]
for i in range(6):
    cases.append( (rint(0, 10**rint(0, 100)), rint(0, 10**rint(0, 100))) )



for i, (a, b) in enumerate(cases):
    fin = open(root / f'case_{i+1:02}.in', 'w')
    fin.write(f'{a}\n{b}')
    fin.close()

    fout = open(root / f'case_{i+1:02}.out', 'w')
    fout.write(f'{a+b}')
    fout.close()


# import subprocess
# for i in range(5):
#     fin = open(root / f'case_{i+1:02}.in', 'r')
#     fout = open(root / f'case_{i+1:02}.out', 'w')
#     exe = f"{fname}.exe"
#     p  = subprocess.Popen(exe, stdin=fin, stdout=fout)
#     p.wait(timeout=1)

# shutil.make_archive(fname, 'zip', base_dir=str(root))
