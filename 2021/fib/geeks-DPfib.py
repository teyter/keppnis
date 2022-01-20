def fib(n):
    if n < 1: return -1
    f = []
    f.append(0)
    f.append(1)
    for i in range(2,n+1):
        f.append( f[i-1] + f[i-2] )
    return f[n-1]

print(fib(int(input())))

#for i in range(10):
#    print(fib(i))
