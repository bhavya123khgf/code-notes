a = float(input("Enter first number: "))
b = float(input("Enter second number: "))
c = input("Enter operator (+, -, *, /): ")

if c == '+':
    print(a + b)
elif c == '-':
    print(a - b)
elif c == '*':
    print(a * b)
elif c == '/':
    if b != 0:
        print(a / b)
    else:
        print("Cannot divide by zero")
else:
    print("Invalid operator")