from statistics import median

inn = ""
lst = [i for i in range(1,1001)]
n = int(median(lst))
end = lst[-1]
print(n,flush=True)

while (inn != "correct"):
    inn = input()
    if inn == "higher":
        lst = lst[lst.index(n)+1:]
        n = int(median(lst))
        print(n,flush=True)
    elif inn == "lower":
        lst = lst[:lst.index(n)]
        n = int(median(lst))
        print(n,flush=True)
