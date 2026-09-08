print("Enter details of student")
name=input("Enter Name: ")
rollno=input("Enter Roll no: ")
age=input("Enter age of student: ")
course=input("Enter course: ")

#displaying details of student
print(f"name of student: {name}")
print(f"roll no of student: {rollno}")
print(f"age of student: {age}")
print(f"course of student: {course}")

subjects=("Maths","Physics","CS")
mylist=[]

for sub in subjects:
    marks = float(input(f"Enter marks for {sub}"))
    mylist.append(marks)

total = mylist[0] + mylist[1] + mylist[2]
avg = total / 3

if avg >= 90:
    print("A+ grade")
elif avg >= 85:
    print("A grade")
elif avg >= 75:
    print("B+ grade")
elif avg >= 70:
    print("B grade")
elif avg >= 65:
    print("C+ grade")
elif avg >= 60:
    print("C grade")
elif avg >= 40:
    print("D grade")
else:
    print("F grade")

print("Enter skills")
skill1 = input("Enter first skill: ")
skill2 = input("Enter second skill: ")
skill3 = input("Enter third skill: ")

myset = {skill1,skill2,skill3}
bonusskill = input("Enter one more skill to add: ")
myset.add(bonusskill)
requiredskills = {"python", "c++", "communication", "problem solving"}

allskills = myset.union(requiredskills)
matchingskills = myset.intersection(requiredskills)

# store data in a dictionary
student_record = {
    "Name": name,
    "RollNo": rollno,
    "Age": age,
    "Course": course,
    "Subjects": subjects,
    "Marks": mylist,
    "Total": total,
    "Average": avg,
    "Skills": myset,
}