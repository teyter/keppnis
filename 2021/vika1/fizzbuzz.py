lst = []
[lst.append(int(i)) for i in input().split()]

x,y,n = lst[0],lst[1],lst[2]
for i in range(1,n+1):
    if i % x == 0 and i % y == 0:
        print("FizzBuzz")
    elif i % x == 0:
        print("Fizz")
    elif i % y == 0:
        print("Buzz")
    else:
        print(i)
