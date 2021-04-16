import sys
from random import * 
from path import Path
fname = Path(__file__).stem


sys.stdout = open(f"{fname}.txt", "w")


cases = []
Ns = [10, 100, 100]

for i in range(10):
    N, M = Ns[i%3], Ns[i%3]
    K = randint(0, N-1)
    A = [randint(0, M) for _ in range(N)]

    # cases.append((K, M, A))

    print((K, M, A))