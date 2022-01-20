n = []
for i in range(5):
    n.append(input())

moves = [
    (1,2),
    (1,-2),
    (-1,2),
    (-1,-2),
    (2,1),
    (2,-1),
    (-2,1),
    (-2,-1)
]

def pl(lst):
    for i in lst:
        print(i)

count = 0
for i in n:
    count+=list(i).count("k")

def run(n):
    for i in range(len(n[0])):
        for j in range(5):
            if n[i][j] == "k":
                for k in moves:
                    z = ""
                    try:
                        x = i+k[0]
                        y = j+k[1]
                        if x < 0 or y < 0: break
                        z = n[i+k[0]][j+k[1]]
                    except:
                        pass
                    if z == "k":
                        print("invalid")
                        return 0
    print("valid")
    return 1

if count == 9:
    run(n)
else:
    print("invalid")
