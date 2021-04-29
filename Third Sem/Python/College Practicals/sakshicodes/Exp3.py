fruits_lst = []                                                                  # create list
n = int(input("Enter number of elements : ")) 
for i in range(0, n):
    ele =input()  
    fruits_lst.append(ele)     
print('Original list of fruits is : ',fruits_lst)                                 # Access List
print()
a=input('enter new elment to add in list ')
fruits_lst.append(a)                                                             # Add new elements in list
print('list of fruits  after adding new element is : ',fruits_lst)
print()
b=int(input('enter index no of element to delete from a list '))

del fruits_lst[b]                                                                # Delete element of string
print('list of fruits after deleting element is : ',fruits_lst)

l=len(fruits_lst)
print('length of list is ',l)