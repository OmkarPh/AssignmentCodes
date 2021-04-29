percentage=int(input('Enter Percentage : '))
if percentage>=90:
    print('Excellent')
elif (percentage>=80 and percentage<90):
    print('First class')
elif (percentage>=60 and percentage<80): 
    print('Second class')
elif (percentage>=40 and percentage<60): 
    print('Pass Class')
elif (percentage< 40):
    print('Fail')
