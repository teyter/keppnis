def printdict(dct):
    for key, value in dct.items():
        print(key, '->', value)

def simp(s):
    return len(set(s))

def string(li):
    return ''.join(map(str,li))

def remove(s,a):
    lst = list(s)
    count = 0
    for i in s:
        try:
            lst.remove(a)
            count += 1
        except:
            return string(lst),count

n = input()
y = len(set(n))

lst = list(n)

a = []
for char in map(chr, range(97, 123)):
    a.append(char)

dic = { i : 0 for i in a }

for i in a:
    dic[i] += n.count(i)

keymax = max(dic, key=dic.get)
dic[keymax] = 0
keymax2 = max(dic, key=dic.get)
n = remove(n,keymax)
n = remove(n,keymax2)
print(len(n))
