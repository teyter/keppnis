n = input()

a = []
for char in map(chr, range(97, 123)):
    a.append(char)

dic = { i : 0 for i in a }

for i in a:
    dic[i] += n.count(i)

lst = list(dic.values())
lst.sort()

summa = 0

for i in range(len(lst)-2):
    summa += lst[i]

print(summa)
