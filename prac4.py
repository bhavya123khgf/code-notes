# dictionary
student={"Name":"Bhavya Bhatia","Age":"19","Course":"Btech"}
print(student["Name"])
print(student)
student["Course"]="MBA"
student["Branch"]="CSE"
print(student)
del student["Age"]
print(student)


# set
numbers={1,2,3,4}
print(numbers)
numbers.add(5)
print(numbers)
numbers.remove(2)
print(numbers)
print(3 in numbers)#true
evens={2,4,6}#another set
print(numbers.union(evens))
print(numbers.intersection(evens))