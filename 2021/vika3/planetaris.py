x = input()
y = input()

xlst = x.split()
n = int(xlst[0])
a = int(xlst[1])
ylst = list(map(int,y.split()))

ylst.sort()

count = 0
for i in ylst:
    a -= i+1
    if a >= 0:
        count+=1

print(count)
