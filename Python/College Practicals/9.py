ST = ["El", "Mike", "Lucas", "Dustin", "Will", "Hopper", "Steve"]
Dark = ["Mikkel", "Jonas", "Martha", "Bartosz", "Regina", "Ulrich", "Magnus", "Noah"]


# Create tuple
print("Enter 5 values for tuple: ")
ls = []
for i in range(5):
    ls.append(input(f'enter element no. {i}: '))

tup1 = tuple(ls)
print("Tuple created:")
print(tup1)
print()


# Accessing element by element
print("Tuple elements: ")
for x in tup1:
    print(x, end=" ")
print()
print()

# Update tuple
print('Update tuple ')
idx = int(input('Enter position to update: '))
ele = input('enter new element: ')
tempList = list(tup1)
tempList[idx] = ele
tup1 = tuple(tempList)
print('Tuple after updation : ', tup1)
print()

# Delete element from tuple
print('Delete tuple')
idx = int(input('Enter index of element to delete from tuple: '))
tempList = list(tup1)
tempList.pop(idx)
tup1=tuple(tempList)
print('Tuple after deleting element: ', tup1)
