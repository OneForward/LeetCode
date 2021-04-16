def factor(n):
    ans = 1
    for i in range(1, n+1):
        ans *= i 
    return ans 

def kth_permutation(n, k):
    L = list(range(1, n+1))
    f = factor(n)
    ans = [] 
    k -= 1
    for i in range(n, 0, -1):
        f //= i 
        ans.append(L[k // f])
        L.pop(k // f)
        k -= k//f*f 
        
    return ans 

print(kth_permutation(4, 9))