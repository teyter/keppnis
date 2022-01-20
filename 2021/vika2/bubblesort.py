lst = []
[lst.append(int(i)) for i in input().split()]

def isSorted(lst):
    for i in range(len(lst)-1):
        if lst[i] > lst[i+1]:
            return False
    return True

def swap(i,j):
    temp = lst[i]
    lst[i] = lst[j]
    lst[j] = temp

def bubblesort(lst):
    while not isSorted(lst):
        for i in range(len(lst)-1):
            if lst[i] > lst[i+1]:
                swap(i,i+1)
                print(' '.join(map(str,lst)))

bubblesort(lst)
