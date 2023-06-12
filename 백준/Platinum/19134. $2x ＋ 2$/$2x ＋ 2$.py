ans = 0
i = 0
n = int(input())
while True:
    x = ((n+2) >> (2*i)) - 2
    if x <= 0:
        break
    elif x >= 3:
        ans += (x+1)//2 + 1
    else:
        ans += x
    i += 1

print(ans)