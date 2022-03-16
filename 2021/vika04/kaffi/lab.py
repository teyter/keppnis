from math import ceil

lst = [21,14,24,7,17]

x = 0
y = 0

for i in lst:
    x+= ceil(i/3)
    y+= (i/3)

print(x)
print(y)
