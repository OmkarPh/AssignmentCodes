unique_units = int(input())
boxes = [int(i) for i in input().split()]
unitsPerBox = [int(i) for i in input().split()]
truckSize = int(input())

def getMaxUnits (boxes, unitsPerBox, truckSize):
  res = sorted([
      (unitsPerBox[i], boxes[i]) for i in range(len(boxes))
    ], reverse=True)
    
  ans = 0
  for units, boxes in res:
    temp = min(truckSize, boxes)
    truckSize -= temp 
    ans += temp * units
  return ans

print(getMaxUnits(boxes, unitsPerBox, truckSize))