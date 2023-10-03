import math
def auto_correlation(x, h):
    n = (len(h) * len(x)) - 1
    y = []
    start = (len(h) - 1) - (2 * (len(h) - 1))
    end = len(x)
    for i in range(start, end):
        sum = 0
        for j in range(len(x)):
            try:
                if j - i < 0:
                    raise Exception("")
                else:
                    shifted_value = h[j - i]
            except:
                shifted_value = 0
            sum += x[j] * shifted_value
        y.append(sum)

    print("P     = ", end="")
    for i in range(start, end):
        print(f"\t{y[i + end - 1]}", end="")
    print()
    print("Index = ", end="")
    for i in range(start, end):
        print(f"\t{i}", end="")
    print()
    return y
x = list(map(int, input("Enter values of x: ").split()))
x.insert(0, 0)
y = auto_correlation(x, x)
energy = 0
for i in range(len(x)):
    energy += math.pow(x[i], 2)