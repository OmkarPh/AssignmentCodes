k = int(input())

mat = []
for i in range(k):
    l = list(map(int, input().strip().split()))
    mat.append(l)

n = len(mat[0]) * k

dft = k - 1
dfe = n - k
sum_t_square_n = sum([(sum(x) ** 2) / len(x) for x in mat])
sum_t_whole_square_n = (sum([sum(x) for x in mat]) ** 2) / n
sum_t_square = sum([sum([x ** 2 for x in i]) for i in mat])
sst = sum_t_square_n - sum_t_whole_square_n
sse = sum_t_square - sum_t_square_n
mst = sst / dft
mse = sse / dfe
f = mst / mse
print('%.4f' % f)


'''
Testcase
3
9 11 10 9 15
20 21 23 17 30
6 5 8 14 7

Expected - 20.0142
'''