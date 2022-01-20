n = int(input())
s = input()
lst = list(map(int,s.split()))
freq = [lst.count(i) for i in lst]
print(lst)
print(freq)
print(lst[max(freq)])
