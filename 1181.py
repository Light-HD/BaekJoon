N = int(input())
a = [''] * N
b = [''] * N
result = []
for i in range(N):
    a[i] = input()
for i in range(N):
    b[i] = len(a[i])
b_list = set(b)
b = list(b_list)
b.sort()
for i in range(len(b)):
    c = []
    for j in range(N):
        if(len(a[j]) == b[i]):
            c.append(a[j])
    c_list = set(c)
    c = list(c_list)
    c.sort()
    for j in range(len(c)):
        result.append(c[j])
for i in range(len(result)):
    print(result[i])
