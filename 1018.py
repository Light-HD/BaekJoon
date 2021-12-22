a,b = map(int,input().split())
chess = [[0] * b] * a
result = 2500
board1 = [['W','B','W','B','W','B','W','B','W','B'],
         ['B','W','B','W','B','W','B','W','B','W'], 
         ['W','B','W','B','W','B','W','B','W','B'], 
         ['B','W','B','W','B','W','B','W','B','W'], 
         ['W','B','W','B','W','B','W','B','W','B'],  
         ['B','W','B','W','B','W','B','W','B','W'], 
         ['W','B','W','B','W','B','W','B','W','B'],
         ['B','W','B','W','B','W','B','W','B','W']]
board2 = [['B','W','B','W','B','W','B','W','B','W'],
         ['W','B','W','B','W','B','W','B','W','B'],
         ['B','W','B','W','B','W','B','W','B','W'],
         ['W','B','W','B','W','B','W','B','W','B'],
         ['B','W','B','W','B','W','B','W','B','W'],
         ['W','B','W','B','W','B','W','B','W','B'],
         ['B','W','B','W','B','W','B','W','B','W'],
         ['W','B','W','B','W','B','W','B','W','B']]
for i in range(a):
    c = input()
    chess[i] = list(c)
for i in range(a-7):
    for j in range(b-7):
        count = [0,0]
        for k in range(8):
            for l in range(8):
                if (chess[i+k][j+l] != board1[k][l]):
                    count[0] += 1
                if (chess[i+k][j+l] != board2[k][l]):
                    count[1] += 1
        if(min(count) < result):
            result = min(count)
print(result)
