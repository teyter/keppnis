import math

def diag(M,N):
    g = math.gcd(M,N)
    if g > 1:
        return g * diag(math.floor(M/g), math.floor(N/g))
    return (N % 2) * (M % 2)

M,N = list(map(int,input().split()))
result = diag(M,N)
print(result)
