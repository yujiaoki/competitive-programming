n = int(input())
s = []
for i in range(n):
    x = input()
    s.append(x)
s=sorted(s)
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
for k in mydict:
    if mydict[k] == max_n:
        print(k)

