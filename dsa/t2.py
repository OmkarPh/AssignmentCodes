def find_employee_count(V, bosses):
    employee_count = [0] * V
    
    for i in range(V-2, -1, -1):
        boss = bosses[i]
        employee_count[boss-1] += employee_count[i+1] + 1
    
    return employee_count

V = int(input())
bosses = list(map(int, input().split()))

result = find_employee_count(V, bosses)
print(*result)
