# hands on training 8
try:
    a = int(input("Enter first no: "))
    b = int(input("Enter second no: "))
    c = input("Enter operator (+, -, *, /): ")  
    
    if c == '+':
        print(a + b)
    elif c == '-':
        print(a - b)
    elif c == '*':
        print(a * b)
    elif c == '/':
        print(a / b)  # This will naturally raise ZeroDivisionError if b is 0
    else:
        # Handle invalid operator by raising a ValueError
        raise ValueError("Invalid operator! Please use +, -, *, or /.")

except ValueError as ve:
    # Captures both invalid numbers and our custom invalid operator error
    print(f"Error: {ve}")
except ZeroDivisionError:
    print("Error: Cannot divide by zero.")
finally:
    # This block always runs no matter what
    print("Thank you for using the Safe Calculator!")