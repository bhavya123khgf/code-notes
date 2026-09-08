# hands on training 6
def agechecker(age):
    return age >= 18
        
def display(eligible_list,ineligible_list):
    print("eligible list:")
    if eligible_list:
        for name,age in eligible_list:
            print("name: {name} age: {age}")
    else:
        print("none")
    print("eligible list:")
    if ineligible_list:
        for name,age in ineligible_list:
            print("name: {name} age: {age}")
    else:
        print("none")

def main():
    eligible_people = []
    ineligible_people = []

while True:
    name= input("Enter name (write 'exit' to finish: )").strip()
    if name.lower() == "exit":
        break
    if not name:
        print("no name entered, please try again")
        continue
    try:
        age = int(input("enter age"))
        if age<0:
            raise ValueError("age can not be negative")
    except ValueError as e:
        print("error:")