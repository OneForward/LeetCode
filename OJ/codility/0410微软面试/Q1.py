import sys
from random import * 
from path import Path
fname = Path(__file__).stem


sys.stdout = open(f"{fname}.txt", "w")


cases = []
Ns = [10, 100, 100]

for i in range(10):
    N = Ns[i%3]
    A = [randint(1, N) for _ in range(N)]

    print(A)