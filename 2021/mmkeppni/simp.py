#n = input()
n = int(input())
s = input()
lst = list(map(int,s.split()))

a = [i for i in range(1,(10**6)+1)]

dic = { i : 0 for i in a }

for i in a:
    dic[i] += lst.count(i)

lst = list(dic.values())
lst.sort()

summa = 0

for i in range(len(lst)-2):
    summa += lst[i]

print(summa)
