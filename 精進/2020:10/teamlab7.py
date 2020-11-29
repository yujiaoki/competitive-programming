y, m, d= [2020,1,1]
youbi = 2
n = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

count = 0
while count < 666 :
    if d == 13 and youbi == 5:
        count += 1
    if d == n[m - 1] and m == 12:
        y += 1
        m = 1
        d = 1
        youbi = (youbi+1) % 7
    elif d == n[m - 1] and m != 2:
        m += 1
        d = 1
        youbi = (youbi+1) % 7
    elif m == 2 and y % 4 == 0 and d == 29:
        m += 1
        d = 1
        youbi = (youbi+1) % 7
    elif m == 2 and y % 4 != 0 and d == 28:
        m += 1
        d = 1
        youbi = (youbi+1) % 7
    else :
        d+= 1
        youbi = (youbi+1) % 7

print(y,m,d)
