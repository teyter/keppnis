from statistics import median

n = 1000
correct = 333
lst = [i for i in range(1,n+1)]

x = (int(median(lst)))
print(lst[:x])

