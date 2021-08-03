from itertools import product

res = list(product("01",repeat=4))

for i in res:
    print(''.join(i))
