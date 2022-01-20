def fib(n):
    if (n == 0): return 1
    f1 = 1
    f2 = 0
    for i in range(2,n+1):
        f3 = f2 + f1
        f1 = f2
        f2 = f3
    return f2

print(fib(int(input())))
