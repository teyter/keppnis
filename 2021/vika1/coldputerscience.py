n = int(input())
lst = input().split()
bla = [int(i) for i in lst]
count = 0
for i in bla:
    if i < 0:
        count+=1
print(count)
