print("Enter Student Details")
name = input("Enter student name: ")
roll_number = input("Enter roll number: ")
age = int(input("Enter age: "))
course = input("Enter course name: ")

# Displaying the info
print("\nStudent Profile")
print(f"Name: {name}")
print(f"Roll Number: {roll_number}")
print(f"Age: {age}")
print(f"Course: {course}")

subjects = ("Math", "Physics", "CS")
marks_list = []

print("\nEnter Subject Marks")
# Using a for loop
for sub in subjects:
    marks = float(input(f"Enter marks for {sub}: "))
    marks_list.append(marks)  # Adding marks to list

# Calculating total and average
total_marks = marks_list[0] + marks_list[1] + marks_list[2]
average_marks = total_marks / 3

# Deciding the grade
if average_marks >= 90:
    final_grade = "Grade A+"
elif average_marks >= 85:
    final_grade = "Grade A"
elif average_marks >= 75:
    final_grade = "Grade B+"
elif average_marks >= 70:
    final_grade = "Grade B"
elif average_marks >= 65:
    final_grade = "Grade C+"
elif average_marks >= 60:
    final_grade = "Grade C"
elif average_marks >= 40:
    final_grade = "D"
else:
    final_grade = "F"


# Set for Extra Skills
print("\nEnter Skills")
skill1 = input("Enter skill 1: ")
skill2 = input("Enter skill 2: ")
skill3 = input("Enter skill 3: ")

# storing into a set
student_skills = {skill1, skill2, skill3}

# adding another skill
bonus_skill = input("Enter one more extra skill to add: ")
student_skills.add(bonus_skill)
required_skills = {"python", "c++", "communication", "problem solving"}

# union and intersection
all_skills_combined = student_skills.union(required_skills)
matching_skills = student_skills.intersection(required_skills)

# store data in a dictionary
student_record = {
    "Name": name,
    "RollNo": roll_number,
    "Age": age,
    "Course": course,
    "Subjects": subjects,
    "Marks": marks_list,
    "Total": total_marks,
    "Average": average_marks,
    "Grade": final_grade,
    "Skills": student_skills,
}

# displaying everything
print("\nFINAL STUDENT REPORT CARD")
print(f"Student Name: {student_record['Name']}")
print(f"Roll Number: {student_record['RollNo']}")
print(f"Course & Age: {student_record['Course']} ({student_record['Age']} years old)\n")

# Loop to display subjects and no's
print("Subjectwise Performance:")
for i in range(len(student_record["Subjects"])):
    print(f"  * {student_record['Subjects'][i]}: {student_record['Marks'][i]}")

print(f"\nTotal Score:    {student_record['Total']:.2f}")
print(f"Average Score:  {student_record['Average']:.2f}")
print(f"Final Grade:    {student_record['Grade']}\n")

print("Skills Overview:")
print(f"  Your Skills:       {student_record['Skills']}")
print(f"  Required Baseline: {required_skills}")
print(f"  Matching Skills:   {matching_skills}")
print(f"  All Unique Skills: {all_skills_combined}")