def MergeSort(A):
    n = len(A)
    if n > 1:
        m = n//2
        left = A[:m]
        right = A[m:]

        MergeSort(left)
        MergeSort(right)

        i = j = 0
        B = []
        for k in range(n):
            if j >= len(right):
                B.append(left[i])
                i += 1
            elif i >= len(left):
                B.append(right[j])
                j += 1
            elif left[i] < right[j]:
                B.append(left[i])
                i += 1
            else:
                B.append(right[j])
                j += 1
        for k in range(n):
            A[k] = B[k]
