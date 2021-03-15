n=int(input('Enter a number : '))

def isPrime(a):
    if a==1:
        print('1 is neither prime nor a composite number  ')
    elif a > 1:

        for i in range(2,a):
                if (a % i) == 0:
                    print(a," is not a prime number")
                    print(i,"times",a//i,"is",a)
                    break
                else:
                    print(a," is a prime number")
       
    else:
        print(a," is not a prime number")

isPrime(n)