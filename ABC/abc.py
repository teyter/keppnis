# ABC
# 
# You will be given three integers A, B and C. 
# The numbers will not be given in that exact 
# order, but we do know that A is less than B 
# and B less than C. In order to make for a 
# more pleasant viewing, we want to rearrange 
# them in a given order.
#
# Input 
# The first line contains the three positive 
# integers A, B and C, not necessarily in 
# that order. The three numbers will be less 
# than or equal to 100
# The second line contains three uppercase 
# letters ’A’, ’B’ and ’C’ (with no spaces 
# between them) representing the desired order.
#
# Output
# A, B and C in the desired order on a single 
# line, separated by single spaces.
# 
# Sample Input 1    Sample Output 1
# 1 5 3             1 3 5
# ABC
#
# Sample Input 2    Sample Outout 2
# 6 4 2             6 2 4
# CAB

li = []
[li.append(int(x)) for x in input().split()] 
li.sort()
dick = {'A': li[0], 'B': li[1], 'C': li[2] }
x, y, z = [x for x in input()] 
print(dick[x], dick[y], dick[z]);
