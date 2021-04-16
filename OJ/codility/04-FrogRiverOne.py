# you can write to stdout for debugging purposes, e.g.
# print("this is a debug message")

def solution(X, A):
    # write your code in Python 3.6
    S = set(range(1, X+1))
    for i, x in enumerate(A):
        if x in S: S.remove(x)
        if not S: return i
    return -1 

print(solution(5, [1,3,1,4,2,3,5,4]))
