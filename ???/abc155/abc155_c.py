
n = int(input())
s= []
for _ in range(n):
    x = input()
    s.append(x)
s.sort()
mydict = {}
for i in range(n):
    x = s[i]
    if x in mydict:
        mydict[x]+=1
    else :
        mydict[x] = 1

max_n = -1
for v in mydict.values():
    max_n = max(max_n,v)
aa = []
for k in mydict:
    if mydict[k] == max_n:
        aa.append(k)
aa = sorted(aa)
for i in aa:
    print(i)
