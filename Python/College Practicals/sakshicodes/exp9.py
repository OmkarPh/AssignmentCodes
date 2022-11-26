animals=()

#crete tuple
print('create tuple ')
n=5
for i in range(n):
    ele=input('enter element : ')
    x=list(animals)
    x.append(ele)
    animals=tuple(x)


#access tuple
print('\noriginal tuple ')
print(animals)

#update tuple
print('\nupdate tuple ')
n=int(input('enter position : '))
ele=input('enter element : ')
x=list(animals)
x[n]=ele
animals=tuple(x)
print('tuple after updation : ',animals)


print('\ndelete tuple ')
ele=input('enter element : ')
x=list(animals)
x.remove(ele)
animals=tuple(x)
print('tuple after deleting element : ',animals)

