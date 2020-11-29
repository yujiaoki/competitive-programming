import math
h = int(input())
h_list =[]
h_list.append(h)
count = 0
while True:
    if len(h_list) > 1 and h_list[0] ==1:
        count += 1
        h_list.pop(0)
    elif h_list[0] > 1 :
        count += 1
        h_list.append(math.floor(h_list[0]/2))
        h_list.append(math.floor(h_list[0]/2))
        h_list.pop(0)
    elif len(h_list) == 1 and h_list[0] == 1 :
        count +=1
        print(count)
        break


