n = int(input())
count = 0
for i in range(1,int(n/2)+1):
    a = str(i)
    if ( int(a) <10):
        count+=1
        for j in range(1,len(str(n))):
            a+=a
            if (int(a) <= n) :
                count+=2
            else :
                break
    else:
        if (a[-1]!=a[0] and a[-1] !=0 and a[0] != 0) :
            b = a[-1] +a[1:n-1] +a[0]
            if int(b) <= n :
                count+=len(a[1:n-1])*20+2
                print(a,b)
print(count)