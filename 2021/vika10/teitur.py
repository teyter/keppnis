import math
p,a = list(map(int,input().split()))

def fermat(n):
    nsqrt = int(math.sqrt(n))
    for i in range(2, nsqrt):
    	if n % i == 0:
    		return False
    return True

while a != p != 0:
    fp = fermat(p)
    if pow(a,p,p) == a and not fp:
        print("yes")
    else:
        print("no")
    p,a = list(map(int,input().split()))
