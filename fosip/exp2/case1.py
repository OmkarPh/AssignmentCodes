import math


def is_even(signal):
    # Check if the signal is even
    for n in range(len(signal)):
        if signal[n] != signal[-n - 1]:
            return False
    return True


def is_odd(signal):
    # Check if the signal is odd
    for n in range(len(signal)):
        if signal[n] != -signal[-n - 1]:
            return False
    return True


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
    print("Y = ", end="")
    for i in range(start, end):
        print(f"\t{y[i + end - 1]}", end="")
    print()
    print("Index = ", end="")
    for i in range(start, end):
        print(f"\t{i}", end="")
    print("\n")
    return y


x = list(map(int, input("Enter values of x: ").split()))
y = auto_correlation(x, x)
energy = 0
for i in range(len(x)):
    energy += math.pow(x[i], 2)

print("Energy of the signal is = ", energy)
if is_even(x):
    print("The signal is even.")
elif is_odd(x):
    print("The signal is odd.")
else:
    print("The signal is neither even nor odd.")
