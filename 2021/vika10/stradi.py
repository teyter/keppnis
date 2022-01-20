from math import sqrt

def pseudo(n):
    sqrtn = int(sqrt(n))
    for i in range(2, sqrtn):
        if n % i == 0:
            return False
        return True
        
p, a = list(map(int, input().split()))
        
while a != 0 and p != 0:
    fermatp = pseudo(p)
    
    if pow(a,p,p) == a and not fermatp:
        print("yes")
        
    else:
        print("no")
    p, a = list(map(int, input().split()))
