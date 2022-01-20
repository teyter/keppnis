n = int(input())
lst = [int(input()) for i in range(n)]

goal = 1000
limit = 2001

boolst = [0 for i in range(limit)]
boolst[0] = 1

i = 0
while i < n:
    temp = lst[i]
    roof = limit - temp

    for j in range(roof,-1,-1):
        if boolst[j]:
            boolst[j+temp] = 1
    i+=1

for i in range(limit):
    if boolst[goal + i]:
        print(goal+i)
        break
    elif boolst[goal-i]:
        print(goal-i)
        break
