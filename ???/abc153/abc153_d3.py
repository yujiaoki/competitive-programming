import math
h = int(input())
count = 0
while (h >0):
    count +=1 
    h = math.floor(h/2)

print(1+2*count)       
