board = []
for i in range(8):
    board.append(list(input()))

def pl(lst):
    for i in lst:
        print(i)


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

def run (Ki,Kj,Ri,Rj,ki,kj):
    z = ""
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
    elif Ki != ki and Ri != Ki:
        board[Ri][Rj] = "."
        Ri = ki
        board[Ri][Rj] = "R"
        z = "j"
    elif Kj != kj and Rj != Kj:
        board[Ri][Rj] = "."
        Ri = ki
        board[Ri][Rj] = "R"
        z = "i"
    else:
        board[Ri][Rj] = "."
        Ri = ki
        board[Ri][Rj] = "R"
        z = "i"


    kset = set()
    Kset = set()
    for i,j in moves:
        if 0 <= ki+i <= 7 and 0 <= kj+j <= 7:
            kset.add( (ki+i,kj+j) )
        if 0 <= Ki+i <= 7 and 0 <= Kj+j <= 7:
            Kset.add( (Ki+i,Kj+j) )

    if z == "i":
        for j in range(8):
            Kset.add((Ri,j))

    if z == "j":
        for i in range(8):
            Kset.add((i,Rj))

    bla = kset.difference(Kset)
    if len(bla) > 0:
        print("No")
    else:
        print("Yes")


run(Ki,Kj,Ri,Rj,ki,kj)
