board = []
for i in range(8):
    board.append(list(input()))

def pl(lst):
    for i in lst:
        print(i)

pl(board)

def locate(board,piece):
    for i in range(8):
        for j in range(8):
            if board[i][j] == piece:
                return (i,j)

K = locate(board,"K")
Ki = K[0]
Kj = K[1]
R = locate(board,"R")
Ri = R[0]
Rj = R[1]
k = locate(board,"k")
ki = k[0]
kj = k[1]

moves = [
#   y   x
    (-1,-1),
    (-1,0),
    (-1,1),
    (0,1),
    (1,1),
    (1,0),
    (1,-1),
    (0,-1)
]



def run (Ki,Kj,Ri,Rj,ki,kj,kset,Kset,diff):
    z = ""
    difflen = len(diff)
    if difflen == 2:
        if Ki == ki and Ri != Ki:
            board[Ri][Rj] = "."
            Rj = kj
            board[Ri][Rj] = "R"
            z = "j"
        elif Kj == kj and Rj != Kj:
            board[Ri][Rj] = "."
            Ri = ki
            board[Ri][Rj] = "R"
            z = "i"
    elif difflen == 1:
        if abs(Ki-ki) == 2:
            if Rj == Kj:
                return("No")
            board[Ri][Rj] = "."
            Ri = ki
            board[Ri][Rj] = "R"
            z = "i"
            print(abs(Ki-ki))
        elif abs(Ki-ki) == 1:
            if Ri == Ki:
                return("No")
            board[Ri][Rj] = "."
            Rj = kj
            board[Ri][Rj] = "R"
            z = "j"
            print(abs(Ki-ki))

    print()
    pl(board)

    if z == "i":
        for j in range(8):
            Kset.add((Ri,j))

    if z == "j":
        for i in range(8):
            Kset.add((i,Rj))

    Kset.remove((Ri,Rj))
    print(kset)
    print(Kset)
    print()
    diff = kset.difference(Kset)
    print(diff)
    if len(diff) > 0:
        return("No")
    else:
        return("Yes")


##########################################
kset = set()
for i,j in moves:
    if 0 <= ki+i <= 7 and 0 <= kj+j <= 7:
        kset.add( (ki+i,kj+j) )
print(kset)

Kset = set()
for i,j in moves:
    if 0 <= Ki+i <= 7 and 0 <= Kj+j <= 7:
        Kset.add( (Ki+i,Kj+j) )

print(Kset)
diff = kset.difference(Kset)
print(diff)
if len(diff) > 2 or Ri == Ki == ki or Rj == Kj == kj:
    print("No")
else:
    print(run(Ki,Kj,Ri,Rj,ki,kj,kset,Kset,diff))
