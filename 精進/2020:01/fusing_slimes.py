# coding: utf-8
# Your code here!
import itertools
n=int(input())
x = list(map(int, input().split()))
last = x[-1]
p_list = list(itertools.permutations(x,n))
test = []
for i in range(n):
    if p_list[i][-1] == last:
        test.append(p_list[i])
sum = 0
for l in range(len(test)):
    for i in range(n-1):
        sum += abs(test[l][i]-test[l][i+1])
print(sum )