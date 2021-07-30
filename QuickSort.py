def QuickSort():
    less = []
    equal = []
    greater = []

    if len(A) > 1:
        pivot = A[0]
        for i in A:
            if i < pivot:
                less.append(i)
            elif i > pivot:
                greater.append(i)
            else:
                equal.append(i)
        return QuickSort(less)+equal+QuickSort(greater)
    else:
        return A
