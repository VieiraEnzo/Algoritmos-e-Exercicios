mult = 1
div = 1
n = int(input())
for i in range(1,n+1):
    mult *= i
    if(i == n-1):
        mult*= mult
    else:
        div*=2
    


print(int((mult/div) % 1000000007))