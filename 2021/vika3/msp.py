def msp(a, b):
    a.sort()
    a.reverse()
    b.sort()
    summa = 0
    for i in range(len(a)):
        summa += a[i] * b[i]
    return summa


T = int(input())
for i in range(T):
    n = input()
    A = input()
    a = list(map(int,A.split()))
    B = input()
    b = list(map(int,B.split()))
    print("Case #"+str(i+1)+":", msp(a,b))
