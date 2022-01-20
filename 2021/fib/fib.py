def fib(x):
    if x < 3: return 1
    return fib(x-1) + fib(x-2)

def DPfib(x):
    if d[x] != -1: return d[x]
    if x < 2: return 1
    return d[x] = fib(x-1) + fib(x-2)

print(DPfib(5))
