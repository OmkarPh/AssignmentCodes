import math

l = list(map(int, input().strip().split()))
x_mean = 0
for i in range(0, len(l)):
    x_mean += l[i]
x_mean = x_mean/len(l)
# print(x_mean)
x = 0
for i in range(len(l)):
    x += (l[i]-x_mean)**2
    
x = math.sqrt(x/len(l))/math.sqrt(len(l))

print('%.4f' %x)

'''
Testcase not available
Expected ---
'''