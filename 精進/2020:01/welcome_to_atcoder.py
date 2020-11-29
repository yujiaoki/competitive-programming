# coding: utf-8
# Your code here!
n,m = map(int,input().split())
p =[]
s = []
for i in range(m):
    pp,ss = input().split()
    pp =int (pp)
    p.append(pp)
    s.append(ss)
correct_num =[]
for i in range(n):
    correct_num.append(0)
correct = 0
penalty =[]
for i in range(n):
    penalty.append(0)
for i in range(m):
    if s[i] == "AC" :
        correct_num[p[i]-1] = 1
for i in range(n):
    if correct_num[i] == 1:
        correct+=1
i = 0
while i <n :
    if correct_num[i] ==1:
        for j in range(m):
            if p[j]==i+1 and s[j] == "WA" :
                penalty[i] +=1
            if p[j]==i+1 and s[j] == "AC" :
                break
    i+=1
penaltysum=0
for i in range(n):
    penaltysum+=penalty[i]
print(correct,penaltysum)
    
