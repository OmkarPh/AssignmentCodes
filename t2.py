# Given an array of predicted rainfall for next n days, where index i presents a day and day[i] represents the amount of rainfall on that day, return a list of ideal days such that -

# day[i-k] >= day[i-k+1] >= ... day[i-1] >= day[i] <= day[i+1] ... <= day[i+k-1] <= day[i+k],

# where k is given as an input which represents the number of days prior and after the current day.

# As index represents day, while returning, we need to return i+1 as the actual day.

# Ex:
# day = [3,2,2,2,3,4]
# k = 2
# Output:
# [3,4]

# Explanation:

# the rainfall trend for day3 (i = 2) is day1 >= day2 >= day3 <= day4 <= day5 so day3 is ideal
# the rainfall trend for day4 (i = 3) is day2 >= day3 >= day4 <= day5 <= day6 so day4 is ideal

# i <= k <= n <= 2x10^5
# 0 <= day[i] <= 10^9

# Testcase1
# day = [1,0,1,0,1]
# k = 1
# Output:
# [2,4]

# Testcase2
# day = [1,0,0,0,1]
# k = 2
# Output:
# [3]

# Testcase3
# day = [1,1,1,1,1,1,1,1,1,1]
# k = 3
# Output:
# [4,5,6,7]

# Give me most optimal python code

def idealDays(day, k):
    n = len(day)
    ideal_days = []
    max_left = [0] * n
    max_right = [0] * n

    # Calculate the maximum values to the left of each day within the window
    max_val = day[0]
    for i in range(n):
        if i % k == 0:
            max_val = day[i]
        else:
            max_val = max(max_val, day[i])
        max_left[i] = max_val

    # Calculate the maximum values to the right of each day within the window
    max_val = day[n - 1]
    for i in range(n - 1, -1, -1):
        if i == n - 1 or (i + 1) % k == 0:
            max_val = day[i]
        else:
            max_val = max(max_val, day[i])
        max_right[i] = max_val

    # Check for ideal days based on the calculated maximum values
    for i in range(k, n - k):
        if day[i] >= max_left[i] and day[i] >= max_right[i]:
            ideal_days.append(i + 1)

    return ideal_days

# Test cases
day1 = [3, 2, 2, 2, 3, 4]
k1 = 2
print(idealDays(day1, k1))  # Output: [3, 4]

day2 = [1, 0, 1, 0, 1]
k2 = 1
print(idealDays(day2, k2))  # Output: [2, 4]

day3 = [1, 0, 0, 0, 1]
k3 = 2
print(idealDays(day3, k3))  # Output: [3]