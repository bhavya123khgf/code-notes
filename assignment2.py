import datetime


class Employee:
    def __init__(self, name, emp_id, department):
        # Format strings
        self.name = name.strip().title()
        self.emp_id = emp_id.strip().upper()
        self.department = department.strip().title()

    def mark_attendance(self):
        # Gen log entry
        current_date = str(datetime.datetime.now().date())
        return f"{current_date} | ID: {self.emp_id} | Name: {self.name} | Dept: {self.department} | Status: Present\n"

    def __str__(self):
        # Print string representation
        return f"Employee details -> Name: {self.name}, ID: {self.emp_id}, Dept: {self.department}"


def register_employee():
    print("\nRegister a New Employee")
    name = input("Enter full name: ")
    dept = input("Enter department name: ")
    
    # ID validation loop
    while True:
        emp_id = input("Enter employee ID (Must start with 'EMP'): ")
        
        try:
            # Check prefix
            if not emp_id.strip().upper().startswith("EMP"):
                raise ValueError("Validation failed: Employee ID must begin with 'EMP' prefix!")
            
            break
            
        except ValueError as err:
            print(f"Oops: {err} Please try again.")

    return Employee(name, emp_id, dept)


def record_attendance(employee_obj):
    try:
        # Append mode
        with open("attendance.txt", "a") as file:
            log_entry = employee_obj.mark_attendance()
            file.write(log_entry)
        print(f"Success: Attendance recorded for {employee_obj.name}!")
        
    except IOError:
        # File write error
        print("Error: Could not write to attendance.txt. Check file permissions.")


def show_attendance():
    print("\nCurrent Attendance Records")
    try:
        with open("attendance.txt", "r") as file:
            records = file.readlines()
            
            if not records:
                print("The file is empty. No attendance has been recorded yet.")
                return
                
            for record in records:
                # Remove newlines
                print(record.strip())
                
    except FileNotFoundError:
        # File missing
        print("Alert: No attendance file found yet. (attendance.txt doesn't exist).")
    except IOError:
        print("Error: Had trouble opening or reading the attendance file.")


def main():
    print("Welcome to the Employee Attendance System")
    
    while True:
        print("\n1. Register & Mark Present")
        print("2. View Attendance Logs")
        print("3. Exit System")
        
        choice = input("Select an option (1-3): ").strip()
        
        if choice == "1":
            new_emp = register_employee()
            print(f"\nCreated successfully -> {new_emp}")
            record_attendance(new_emp)
            
        elif choice == "2":
            show_attendance()
            
        elif choice == "3":
            print("\nExiting tracker system. Have a great day!")
            break
            
        else:
            print("Invalid choice. Please select 1, 2, or 3.")

    main()