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

def count(board):
    K = 0
    R = 0
    k = 0
    for i in range(8):
        for j in range(8):
            if board[i][j] == "K":
                K +=1
            if board[i][j] == "R":
                R +=1
            if board[i][j] == "k":
                k +=1
    return K,R,k

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
    kset = set()
    Kset = set()
    for i,j in moves:
        if 0 <= ki+i <= 7 and 0 <= kj+j <= 7:
            kset.add( (ki+i,kj+j) )
        if 0 <= Ki+i <= 7 and 0 <= Kj+j <= 7:
            Kset.add( (Ki+i,Kj+j) )

    diff = kset.difference(Kset)
    if Ki == 6 and Kj == 2 and ki == 7 and kj == 0 and Ri < Ki and Rj > Kj:
        return "Yes"
    if Ki == 5 and Kj == 1 and ki == 7 and kj == 0 and Ri < Ki and Rj > Kj:
        return "Yes"
    if Ki == 6 and Kj == 5 and ki == 7 and kj == 7 and Ri < Ki and Rj < Kj:
        return "Yes"
    if Ki == 5 and Kj == 6 and ki == 7 and kj == 7 and Ri < Ki and Rj < Kj:
        return "Yes"
    if Ki == 1 and Kj == 5 and ki == 0 and kj == 7 and Ri > Ki and Rj < Kj:
        return "Yes"
    if Ki == 2 and Kj == 6 and ki == 0 and kj == 7 and Ri > Ki and Rj < Kj:
        return "Yes"
    if Ki == 1 and Kj == 2 and ki == 0 and kj == 0 and Ri > Ki and Rj > Kj:
        return "Yes"
    if Ki == 2 and Kj == 1 and ki == 0 and kj == 0 and Ri > Ki and Rj > Kj:
        return "Yes"
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

    if z == "i":
        for j in range(8):
            Kset.add((Ri,j))
    if z == "j":
        for i in range(8):
            Kset.add((i,Rj))
    diff = kset.difference(Kset)
    if len(diff) > 0:
        return "No"
    else:
        return "Yes"

K,R,k = count(board)
if K != 1 or R != 1 or k != 1:
    print("No")
else:
    print(run(Ki,Kj,Ri,Rj,ki,kj))
