# coding: utf-8
# Your code here!
import math

n = int(input())
r = []
p = list(map(int, input().split()))
q = list(map(int, input().split()))
for i in range(n):
    r.append(i+1)

count =0
a=1
b=1
while(count<n):
    for i in r:
        if p[count] ==i :
            count+=1
            r.remove(i)
            break;
        else:
            a+=math.factorial(n-count-1)
r = [] 
for i in range(n):
    r.append(i+1)
count = 0
while(count<n):
    for i in r:
        if q[count] ==i :
            count+=1
            r.remove(i)
            break;
        else:
            b+=math.factorial(n-count-1)           
print(abs(a-b))