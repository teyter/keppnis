count = 0
def printdict(dct):
    for key, value in dct.items():
        print(key, '->', value)

def simp(s):
    return len(set(s))

def string(li):
    return ''.join(map(str,li))

def remove(s,a,count):
    lst = list(s)
    for i in s:
        try:
            lst.remove(a)
            count+=1
        except:
            return string(lst)

n = input()
y = len(set(n))

lst = list(n)

a = []
for char in map(chr, range(97, 123)):
    a.append(char)

dic = { i : 0 for i in a }

for i in a:
    dic[i] += n.count(i)

dic = {key:val for key, val in dic.items() if val != 0}

while simp(n) > 2:
    keymin = min(dic, key=dic.get)
    n = remove(n,keymin,count)
    del dic[keymin]

print(n)
print(count)
