t = int(input())

while(t):
    string = input().split()
    y = int(string[0])
    x = int(string[1])
    level = max(x,y)
    if(level%2):
        if(x == level):
            print((level*level) - (y-1)) 
        
        else:
           print(((level*level) - pow(2,level-1)) + (x-1))
    
    else:
        if(x == level):
            print(((level*level) - pow(2,level-1)) + (y-1))
        
        else:
            print((level*level) - (x-1))

    t-=1
    

