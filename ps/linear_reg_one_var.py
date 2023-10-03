import math
n = int(input())
x = list(map(int, input().strip().split()))
y = list(map(int, input().strip().split()))
xy=0
sumx=0
sumy=0
sumx2=0
sumy2=0
for i in range (n):
    xy+=x[i]*y[i]
    sumx+=x[i]
    sumy+=y[i]
    sumx2+=x[i]**2
    sumy2+=y[i]**2
a=(sumy*sumx2-sumx*xy)
a/=n*sumx2-sumx**2
b=(n*xy-sumx*sumy)
b/=n*sumx2-sumx**2
print('%.3f' % b)
print('%.3f' % a)