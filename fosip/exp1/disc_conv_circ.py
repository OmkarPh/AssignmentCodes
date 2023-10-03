x = list(map(int, input("Enter values of x: ").split()))
h = list(map(int, input("Enter values of h: ").split()))
m = max(len(x), len(h))
for i in range(len(x), m):
    x.insert(0, 0)
for i in range(len(h), m):
    h.append(0)
a = h[1:]
a.reverse()
h[1:] = a
print("\n---------Values after padding--------")
print(x)
print(h)
print()
arr = []
sum = -1
i = 0
while (i < m):
    sum = 0
    for j in range(m):
        sum += x[j]*h[j]
    a = h.pop()
    h.insert(0, a)
    arr.append(sum)
    print(f"Y({i}) = ", sum)
    i += 1
