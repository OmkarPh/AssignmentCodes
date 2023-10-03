# Check if number is prime or not.

def isPrime(number):
    if number <= 2:
        return True
    
    # If number is even it is never prime except for 2
    if number%2 == 0:
        return False

    i = 3
    # Iterate over all numbers until square root of number.
    while i*i<=number:
        if number%i == 0:
            return False
        i += 2
    return True

number = int(input("Enter a positive number: "));
if number == 1:
    print("Number is neither prime nor composite !")
else:
    if isPrime(number):
        print("Number entered,", number, " is prime.")
    else:
        print("Number entered,", number, " is not prime.")
