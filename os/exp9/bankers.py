import threading
import time

def reqResources(process_num, request, need, allocation, available, n, m):
    if any(request[i] > need[process_num][i] for i in range(m)):
        return False

    if any(request[i] > available[i] for i in range(m)):
        return False

    newAllocation = allocation.copy()
    newAvailable = available.copy()
    for i in range(m):
        newAllocation[process_num][i] += request[i]
        newAvailable[i] -= request[i]
    newNeed = [[need[i][j] - newAllocation[i][j] for j in range(m)] for i in range(n)]
    sequence = []
    if checkSafe(newNeed, newAllocation, newAvailable, n, m, sequence):
        return True
    else:
        return False


def checkSafe(need, allocation, available, n, m, sequence):
    work = available.copy()
    finish = [False] * n

    while False in finish:
        found = False
        for i in range(n):
            if not finish[i]:
                if all(need[i][j] <= work[j] for j in range(m)):
                    for j in range(m):
                        work[j] += allocation[i][j]
                    finish[i] = True
                    sequence.append(i)
                    found = True
                    break
        if not found:
            return False
    return True

def customerThread(thread_id, request, need, allocation, available, n, m, process_num):
    if reqResources(process_num, request, need, allocation, available, n, m):
        for i in range(m):
            allocation[thread_id][i] += request[i]
            available[i] -= request[i]
            need[process_num][i] -= request[i]
        sequence = []
        if checkSafe(need, allocation, available, n, m, sequence):
            print("Request granted, safe sequence: {}".format(sequence))
        else:
            print("Request granted, but system is now in unsafe state")
        print("Allocation Matrix after granting:")
        for e in allocation:
            print(e)
        print("Remaining Need Matrix after granting:")
        for e in need:
            print(e)
    else:
        print("Request denied, coz system becomes in unsafe state upon granting !")

if __name__ == '__main__':
    n = int(input("No. of processes: "))
    m = int(input("No. of resources: "))

    print("Enter allocations: ");
    allocation = []
    for i in range(n):
        row = [int(x) for x in input("P{} allocation: ".format(i)).split()]
        allocation.append(row)

    print()
    available = [int(x) for x in input("Enter available resources: ").split()]
    print()

    maxNeed = []
    print("Enter max needs: ");
    for i in range(n):
        row = [int(x) for x in input("P{} max need: ".format(i)).split()]
        maxNeed.append(row)

    remainingNeed = [[maxNeed[i][j] - allocation[i][j] for j in range(m)] for i in range(n)]
    print("need", remainingNeed)

    print("Allocation \t MaxNeed \t RemainingNeed")
    for i in range(n):
        for j in range(m):
            print(allocation[i][j], end=' ')
        print("\t\t", end='')  
        for j in range(m):
            print(maxNeed[i][j], end=' ')
        print("\t\t", end='')  
        for j in range(m):
            print(remainingNeed[i][j], end='')
        print()  
    print()
    print("Available: ", available)

    sequence = []
    if checkSafe(remainingNeed, allocation, available, n, m, sequence):
        print("System is in Safe state!!\nSafe sequence: {}".format(sequence))
    else:
        print("System is not in state :(")
        print("Bye !")
        exit

    for i in range(n):
        process_num = int(input("Enter process number for which resources are to be requested: "))
        request = [int(x) for x in input("Enter units of resources requested by P{}: ".format(process_num)).split()]

        t = threading.Thread(target=customerThread, args=(i, request, remainingNeed, allocation, available, n, m, process_num))
        t.start()
        time.sleep(0.01)

