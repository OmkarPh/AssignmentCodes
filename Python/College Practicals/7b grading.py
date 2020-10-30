# Display grade of student depending on percentage

percentage = int(input("Enter student's percentage: "))

print("Your grade: ",end="")

if percentage >= 90:
    print("Excellent")
elif percentage >= 80:
    print("First class")
elif percentage >= 60:
    print("Second class")
elif percentage >= 40:
    print("Pass class")
else:
    print ("Failed") 
