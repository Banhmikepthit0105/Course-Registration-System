# HCMUS Project - Course Registration System  💻

This is the HCMUS Group's Project of Programming Technique course, which is written in C++ language by the group of freshmans from class 22CLC06

1.[`NGUYEN THANH THAI`](https://github.com/Banhmikepthit0105) - Group Leader

2.[`TU CHI TIEN`](https://github.com/chitien2808)

3.[`NGO HAI BANG`](https://github.com/MUisthebest)

4.[`NGUYEN THANH LONG`](https://github.com/Longcryo)

## 🔴 Introduction
`Course Registration System` is a software that manages the details of courses, classes, students. It allows students to enquire, register, cancel, or modify courses. It also helps the management of the institution to see the records of the students and courses.

## 🔴 Data and files Organization
The repository includes 11 .cpp files, 3 folders and .txt files for different tasks of function
### 1. Description of .cpp files
- **`AddCourse.cpp`**: Includes functions which are used for adding courses and several relative tasks.
- **`Menu_Score_Board.cpp`**: Edits students' scores and Displays the Scoreboard when users are staff.
- **`addStudent.cpp`**: Includes functions which are used for adding students to academic classes and courses.
- **`loadINPUT_printOUTPUT_toFILE.cpp`**: Loads data from .txt files and save to RAM, then save these data to .txt file when the functions finished.
- **`main.cpp`**: Displays the screen when users log in into the system. 
- **`password.cpp`**: Includes functions which are used for creating new accounts for users and editting the password.
- **`schoolYearFeature.cpp`**: Manipulates with school years.
- **`staff.cpp`**: Displays and implements list of choices when users are staff
- **`student.cpp`**:  Displays and implements list of choices when users are students
- **`ultilityFunction.cpp`**: Includes functions for making the console works more beatifully and efficiently.
- **`viewScore.cpp`**: Displays scores when users are students.
### 2. Description of folders
Includes 3 folders `schoolyear1-schoolyear2` with the same format:

#### schoolyearXXXX-schoolyearXXXX
##### 🔸SemesterN
`course1.txt`, `course2.txt`,...
`courseList.txt`
##### 🔸semesterList.txt 

### 3. Description of .txt files
- **`course1.txt`**,**`course2.txt`**,... includes students' information and their scores in the courses.
- **`class1.txt`**,**`class2.txt`**,... includes studennts' information.
- **`semesterList.txt`** includes the semesters which has been created.
- **`schoolYearList.txt`** includes the school years which has been created.
- **`classList.txt`** includes the classes which has been created.
- **`addStudentToClass.txt`** includes the students' information who will be added to academic class.
- **`addStudentToCourse.txt`** includes the students's information and their scores which will be added to the courses
- **`import-scoreboard.txt`** includes the students' inforemation and their scores, which will be editing and saving to the system.
- **`password.txt`** includes accounts of staff and students.
- **`student_In_A_Course.txt`** includes a course's information with its school year, semester, and the students in the course.
