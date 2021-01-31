# 

import re 
enroll_number=input("Enter Enrollment Number") 
if bool(re.match("SS19CO[0-9][0-9][0-9]", enroll_number)) or bool(re.match("FS19CO[0-9][0-9][0-9]",  enroll_number)): 
    print(enroll_number) 
else: 
    raise Exception("Wrong enrollment number")
