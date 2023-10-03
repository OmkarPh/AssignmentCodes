x = list(map(int, input("Enter the values of x: ").split()))
h = list(map(int, input("Enter the values of h: ").split()))
m = max(len(x), len(h)) + min(len(x), len(h)) - 1
for i in range(len(x), m):
    x.insert(i, 0)
for i in range(len(h), m):
    h.append(0)
a = h[1:]
a.reverse()
h[1:] = a
arr = []
sum = -1
i = 0
print("\n---------Values after padding--------")
print(x)
print(h)
print()
while (i < len(h)):
    sum = 0
    for j in range(len(x)):
        sum += x[j]*h[j]
    a = h.pop()
    h.insert(0, a)
    arr.append(sum)
    print(f"Y({i}) = ", sum)
    i += 1
