from random import randint
n = (randint(1,20+1))
print(n)
for i in range(n):
    N = randint(1,10+1)
    M = randint(1,(N*(N-1)/2)+1)
    L = randint(1,100+1)
    S = randint(1,N)
    print(N,M,L,S)
    for j in range(S):
        print(randint(1,N),end=' ')
    print()
    for j in range(M):
        print(randint(1,N),randint(1,N),randint(1,100+1))
