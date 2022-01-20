import math

M,N = list(map(int,input().split()))
g = math.gcd(M,N)
M = math.floor(M/g)
N = math.floor(N/g)
if M % 2 == 0 or N % 2 == 0:
    g = 0

print(g)
