n = int(input()) # 삼각형 높이
triangle = [[0 for col in range(n)] for row in range(n)] # n x n 행렬 생성
for i in range(n):
    triangle[i][:i+1]= map(int,input().split()) # 여러개의 숫자 입력 받기
for i in range(n-1):
    for j in range(i+2):
        if (j == 0):  # 젤 왼쪽 경우
            triangle[i+1][0] += triangle[i][0]
        elif (j == i+1): # 젤 오른쪽 경우
            triangle[j][j] += triangle[i][i]
        else : # 사이 값은 더 높은 값으로 업데이트
            #i = 1
            triangle[i+1][j] += max(triangle[i][j-1],triangle[i][j])
print(max(triangle[n-1]))
