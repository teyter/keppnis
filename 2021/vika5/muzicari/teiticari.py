A = input()
lst = list(map(int,A.split()))

T = lst[0]
N = lst[1]

A = input()
a = list(map(int,A.split()))
r = [0 for i in range(N)]

dp = [[0 for i in range(N+1)] for j in range(T+1)]
for i in range(1,T+1):
    for j in range(1,N+1,):
        dp[i][j] = dp[i][j-1]
        w = a[j-1]
        if i >= w:
            dp[i][j] = max(dp[i][j], w+dp[i-w][j-1])

w = T
for i in range(N,0,-1):
    if dp[w][i-1] != dp[w][i]:
        w -= a[i-1]
        r[i-1] = 1

t1 = 0
t2 = 0
res = []
for i in range(N):
    if r[i]:
        res.append(t1)
        t1 += a[i]
    else:
        res.append(t2)
        t2 += a[i]

print(" ".join(map(str,res)))
