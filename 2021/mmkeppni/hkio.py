n = int(input())
s = input()
lst = list(map(int,s.split()))
count = 1
currentmax = 1
a = 0
for i in range(len(lst)-1):
    if lst[i] == lst[i+1]:
        count+=1
        if count > currentmax: 
            currentmax = count
            a = i+1
    else: 
        count = 1

if currentmax == 1:
    print(0,0)
else: print(a+1-currentmax,a)
print()
print(a)
print(currentmax)

