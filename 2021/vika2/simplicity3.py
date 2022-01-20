from string import punctuation
from collections import Counter

def mostfreq(text):
    return Counter(text).most_common()[0][0]

def remove(s,a):
    lst = list(s)
    for i in s:
        try:
            lst.remove(a)
        except:
            return string(lst)

def string(li):
    return ''.join(map(str,li))

s = input()
x = len(s)
y = len(set(s))

def run(s,x,y):
    if x == y:
        print(abs(2-y))
    elif y > 2:
        k = mostfreq(s)
        s = remove(s,k)
        k = mostfreq(s)
        s = remove(s,k)
        print(len(s))
    else:
        print(0)
if 1 <= x <= 100:
    run(s,x,y)


