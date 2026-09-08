# try:
#     num= int(input("enter a no: "))
#     result = 10/ num
#     print("Result: ",result)
## except ZeroDivisionError:
##     print("Error: Division by zero is not allowed.")
## except ValueError:
##     print("Error: Invalid input. Please enter a number.")
# except (ZeroDivisionError,ValueError)as e:
#     print("error cought: ",e)



# try:
#     with open("data.txt","r") as file:
#         content= file.read()
#         print(content)
# except FileNotFoundError:
#     print("file was not found")



# def check_age(age):
#     if age < 0:
#         raise ValueError("Age cannot be negative")
#     return age
# try:
#     a = int(input("Enter age: ")) 
#     check_age(a)
# except ValueError as e:
#     print("Caught an exception:", e)   