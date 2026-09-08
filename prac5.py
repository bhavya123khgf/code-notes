
password= input("enter password: ")

haslower = False
hasupper = False
hasdigit = False
hasspecial = False
specialchar="!@#$%^&*"

for char in password:
    if char.islower():
        haslower=True
    elif char.isupper():
        hasupper=True
    elif char.isdigit():
        hasdigit=True
    elif char in specialchar:
        hasspecial=True

if hasupper and haslower and hasspecial and hasdigit:
    print(f"password validated: {password}")
else:
    print("Password invalid")