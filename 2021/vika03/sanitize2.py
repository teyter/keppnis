board = []
for i in range(8):
    board.append(list(input()))

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
    if Rj == Kj == Kj or Rj == Kj == Kj:
        return("No")
    if Ki == ki:
        board[Ri][Rj] = "."
        Rj = kj
        board[Ri][Rj] = "R"
        z = "j"
    elif Kj == kj:
        board[Ri][Rj] = "."
        Ri = ki
        board[Ri][Rj] = "R"
        z = "i"

    else:
        if abs(Ki-ki) == 2:
            if Rj == Kj:
                return("No")
            board[Ri][Rj] = "."
            Ri = ki
            board[Ri][Rj] = "R"
            z = "i"
        elif abs(Ki-ki) == 1:
            if Ri == Ki:
                return("No")
            board[Ri][Rj] = "."
            Rj = kj
            board[Ri][Rj] = "R"
            z = "j"

    if z == "i":
        for j in range(8):
            foo = (Ri,j)
            if foo != (Ri,Rj):
                Kset.add(foo)

    if z == "j":
        for i in range(8):
            bar = (i,Rj)
            if bar != (Ri,Rj):
                Kset.add(bar)

    #Kset.remove((Ri,Rj))
    diff = kset.difference(Kset)
    if len(diff) > 0:
        return("No")
    else:
        return("Yes")


##########################################
kset = set()
for i,j in moves:
    if 0 <= ki+i <= 7 and 0 <= kj+j <= 7:
        kset.add( (ki+i,kj+j) )

Kset = set()
for i,j in moves:
    if 0 <= Ki+i <= 7 and 0 <= Kj+j <= 7:
        Kset.add( (Ki+i,Kj+j) )

diff = kset.difference(Kset)
if len(diff) > 2 or Ri == ki != Ki or Rj == kj != Kj:
    print("No")
else:
    print(run(Ki,Kj,Ri,Rj,ki,kj,kset,Kset,diff))
