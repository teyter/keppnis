def run(n,p,q):
    dic = {
        0 : 0,
        1 : 0,
        2 : 0
    }
    """
    p = [1,1,1]
    q = [1,1,1]
    """
    for i in range(len(p)):
        for j in range(len(q)):
            dic[(i+j) % 3] += p[i]*q[j]

    #print(' '.join(map(str,dic.values())))
    print(dic[1],dic[2],dic[0])

n = int(input())
p = input().split()
p = [int(i) for i in p]

q = input().split()
q = [int(i) for i in q]

a = 3 <= n <= 100000
b = 1 <= p[0] and 1 <= q[0]
c = p[n-1] <= 10000 and q[n-1] <= 10000

if a and b and c:
    run(n,p,q)
