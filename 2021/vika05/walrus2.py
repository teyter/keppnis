
n = int(input())
w = [int(input()) for i in range(n)]

print( len(w) )

goal = 1000
limit = 2001

check = [0 for i in range(limit)]
check[0] = 1

i = 0
while i < n:
    curr = w[i]
    top = limit - curr

    for j in range(top,-1,-1):
        if check[j]:
            check[j+curr] = 1
    i+=1

for i in range(limit):
    if check[goal+i]:
        print(goal+i)
        break
    else:
