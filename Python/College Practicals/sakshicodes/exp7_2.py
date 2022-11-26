#display the grade of student depending on percentage
percentage=int(input('enter percentage : '))
if percentage>=90:
    print('Excellent ')
elif percentage>=80 and percentage<90:
    print('First Class')
elif percentage>=60 and percentage<80:
    print('Second Class')
elif percentage>=40:
    print('Pass Class')
else:
    print('Fail')
