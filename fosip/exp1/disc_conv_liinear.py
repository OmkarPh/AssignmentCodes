x = list(map(int, input("Enter values of x: ").split()))
h = list(map(int, input("Enter values of h: ").split()))
h.reverse()

for i in range(len(h) - 1):
    x.insert(0, 0)
for i in range(len(x) - 1):
    h.append(0)
arr = []
sum = -1

print("\n---------Values after padding--------")
print(x)
print(h)
print()
while (sum != 0):
    sum = 0
    for i in range(len(x)):
        sum += x[i]*h[i]
    h.pop()
    h.insert(0, 0)
    arr.append(sum)
arr.pop()
for i in range(len(arr)):
    print(f"Y({i}) = ", arr[i])
