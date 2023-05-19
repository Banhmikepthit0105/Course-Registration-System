#include "lib.h"

void print_All_CourseToConsole(SchoolYear *pHead_schoolYear)
{
	// print to Console the Courses which have the format:
	// Course_ID---Course_name---Class_name---Teacher_name---Number_of_Credits---Number_of_maximum_students---Day_of_week---Sessions

	SchoolYear *pHead1 = pHead_schoolYear;
	while (pHead1 != nullptr)
	{
		cout << "Academic Year: " << pHead1->year_name << endl;
		Semester *pHead2 = pHead1->semester;
		while (pHead2 != nullptr)
		{
			cout << "Semester: " << pHead2->semester_name << " " << endl;
			cout
				<< left
				<< setw(15)
				<< "Course ID| "
				<< left
				<< setw(15)
				<< "Course Name| "
				<< left
				<< setw(20)
				<< "Class Name|"
				<< left
				<< setw(15)
				<< "Teacher Name| "
				<< left
				<< setw(20)
				<< "Number of credits| "
				<< left
				<< setw(27)
				<< "Number of maximum students| "
				<< left
				<< setw(17)
				<< "Day of the week| "
				<< left
				<< setw(15)
				<< "Session| "
				<< left
				<< setw(3)
				<< "M| "
				<< left
				<< setw(3)
				<< "F| "
				<< left
				<< setw(3)
				<< "O|"
				<< endl;
			Course *pHead3 = pHead2->course;
			while (pHead3 != nullptr)
			{
				cout
					<< left
					<< setw(15)
					<< pHead3->id
					<< left
					<< setw(15)
					<< pHead3->course_name
					<< left
					<< setw(20)
					<< pHead3->class_name
					<< left
					<< setw(15)
					<< pHead3->teacher_name
					<< left
					<< setw(20)
					<< pHead3->number_credits
					<< left
					<< setw(27)
					<< pHead3->number_students
					<< left
					<< setw(17)
					<< pHead3->day_of_week
					<< left
					<< setw(15)
					<< pHead3->sessions
					<< left
					<< setw(3)
					<< pHead3->midterm
					<< left
					<< setw(3)
					<< pHead3->final
					<< left
					<< setw(3)
					<< pHead3->other
					<< endl;
				pHead3 = pHead3->pNext;
			}
			cout << endl;
			pHead2 = pHead2->pNext;
		}
		cout << endl;
		pHead1 = pHead1->pNext;
	}
	string s;
	cout << "Press any key to continue...\n";
	cin >> s;
	clrscr();
}

void print_All_ClassToConsole(Class *pHead_class)
{
	/*if (pHead_class == nullptr)
	{
		cout "There is no class has been created yet" << endl;
		return;
	}*/
	Class *pHead2 = pHead_class;
	while (pHead2 != nullptr)
	{
		cout << pHead2->class_name << endl;
		pHead2 = pHead2->pNext;
	}
	string s;
	cout << "Press any key to continue...\n";
	cin >> s;
	clrscr();
}

void print_All_Student_In_A_class(studentClass *pCur)
{
	if (pCur == nullptr)
	{
		cout << "There is no students have been added yet!" << endl;
		string s;
		cout << "Press any key to continue...\n";
		cin >> s;
		return;
	}
	cout << left
		 << setw(15)
		 << "Student ID| "
		 << left
		 << setw(15)
		 << "First Name| "
		 << left
		 << setw(15)
		 << "Last Name|"
		 << left
		 << setw(15)
		 << "Gender| "
		 << left
		 << setw(17)
		 << "Date of birth| "
		 << left
		 << setw(15)
		 << "Social ID| " << endl;
	while (pCur != nullptr)
	{
		cout << left
			 << setw(15)
			 << pCur->student_ID << " "
			 << left
			 << setw(15)
			 << pCur->first_name << " "
			 << left
			 << setw(15)
			 << pCur->last_name << " "
			 << left
			 << setw(15)
			 << pCur->gender << " "
			 << left
			 << setw(15)
			 << pCur->date_of_birth << " "
			 << left
			 << setw(15)
			 << pCur->social_ID << endl;
		pCur = pCur->pNext;
	}
	string s;
	cout << "Press any key to continue...\n";
	cin >> s;
	clrscr();
}

void Print_All_Student_In_A_Course_With_score(Student *pCur)
{
	while (pCur != nullptr)
	{
		cout
			<< setw(13)
			<< pCur->student_ID << " "
			<< left
			<< setw(13)
			<< pCur->first_name << " "
			<< left
			<< setw(13)
			<< pCur->last_name << " "
			<< left
			<< setw(13)
			<< pCur->gender << " "
			<< left
			<< setw(13)
			<< pCur->date_of_birth << " "
			<< left
			<< setw(13)
			<< pCur->social_ID << " "
			<< left
			<< setw(9)
			<< pCur->score.total_mark << " "
			<< left
			<< setw(9)
			<< pCur->score.final_mark << " "
			<< left
			<< setw(13)
			<< pCur->score.mid_mark << " "
			<< left
			<< setw(13)
			<< pCur->score.other_mark << endl;

		pCur = pCur->pNext;
	}
	string s;
	cout << "Press any key to continue...\n";
	cin >> s;
	clrscr();
}

void Print_All_Student_In_A_Course(Student *pCur)
{
	cout << left
		 << setw(13)
		 << "Student ID| "
		 << left
		 << setw(13)
		 << "First Name| "
		 << left
		 << setw(13)
		 << "Last Name|"
		 << left
		 << setw(13)
		 << "Gender| "
		 << left
		 << setw(13)
		 << "Date of birth| "
		 << left
		 << setw(13)
		 << "Social ID| " << endl;
	while (pCur != nullptr)
	{
		cout
			<< setw(13)
			<< pCur->student_ID << " "
			<< left
			<< setw(13)
			<< pCur->first_name << " "
			<< left
			<< setw(13)
			<< pCur->last_name << " "
			<< left
			<< setw(13)
			<< pCur->gender << " "
			<< left
			<< setw(13)
			<< pCur->date_of_birth << " "
			<< left
			<< setw(13)
			<< pCur->social_ID << " " << endl;
		pCur = pCur->pNext;
	}
	string s;
	cout << "Press any key to continue...\n";
	cin >> s;
	clrscr();
}

void addCourse(Course *&pHead)
{
	cout << "Enter Course ID: ";
	string course_id;
	cin >> course_id;

	Course *pCur = nullptr, *pPrevCur = nullptr;
	if (pHead != nullptr)
	{
		pCur = pHead;
		pPrevCur = pHead;
		while (pCur != nullptr)
		{
			if (pCur->id == course_id)
			{
				cout << "The course ID has been created before! Please choose another course ID: " << endl;
				cout << "Enter Course ID: ";
				cin >> course_id;
				pCur = pHead;
				pPrevCur = pHead;
			}
			else
			{
				pPrevCur = pCur;
				pCur = pCur->pNext;
			}
		}
		pPrevCur->pNext = new Course;
		pPrevCur = pPrevCur->pNext;
	}

	else
	{
		pHead = new Course;
		pPrevCur = pHead;
	}

	cin.ignore();
	cout << "Enter Course Name: ";
	string course_name;
	getline(cin, course_name);

	cout << "Enter Class Name: ";
	string class_name;
	getline(cin, class_name);
	while (class_name.size() > 8)
	{
		cout << "The class name is invalid!" << endl;
		cout << "The form of the class name must be XXCLCXX, XXAPCSXX or XXVPXX " << endl;
		cout << "Enter Class Name: ";
		cin >> class_name;
	}

	cout << "Enter Teacher Name: ";
	string teacher_name;
	getline(cin, teacher_name);

	cout << "Enter Number of credits: ";
	string number_credits;
	cin >> number_credits;
	while (stoi(number_credits) < 0)
	{
		cout << "The number of students must be a positive value....";
		cout << "Enter Number of credits: ";
		cin >> number_credits;
	}

	cout << "Enter Number of students: ";
	string number_students;
	cin >> number_students;
	while (stoi(number_students) < 0)
	{
		cout << "The number of students must be a positive value...";
		cout << "Enter Number of students: ";
		cin >> number_students;
	}
	cin.ignore();
	cout << "Enter day of week: " << endl;
	cout << "MON / TUE / WED / THU / FRI / SAT:  ";
	string day_week;
	getline(cin, day_week);
	while (day_week != "MON" && day_week != "TUE" && day_week != "WED" && day_week != "THU" && day_week != "FRI" && day_week != "SAT")
	{
		cout << "Wrong type of day of week!" << endl;
		cout << "Enter day of week: ";
		cout << "MON / TUE / WED / THU / FRI / SAT:  ";
		getline(cin, day_week);
	}

	cout << "Enter session" << endl;
	cout << "S1(07:30) -- S2(09:30) -- S3(13:30) -- S4(15:30): ";
	string session;
	getline(cin, session);
	while (session != "S1(07:30)" && session != "S2(09:30)" && session != "S3(13:30)" && session != "S4(15:30)")
	{
		cout << "Wrong type of session!" << endl;
		cout << "S1(07:30) -- S2(09:30) -- S3(13:30) -- S4(15:30): ";
		getline(cin, session);
	}

	int other_mark = -1;
	int mid_mark, final_mark;
	while (other_mark < 0)
	{
		cout << "The percentage of mark for the midterm exam: ";
		cin >> mid_mark;
		cout << "The percentage of mark for the final exam: ";
		cin >> final_mark;
		other_mark = 100 - mid_mark - final_mark;
		if (other_mark < 0)
		{
			cout << "The percentage of mark for the other exam is not valid" << endl;
			cout << "Please try again..." << endl;
		}
	}

	pPrevCur->id = course_id;
	pPrevCur->course_name = course_name;
	pPrevCur->class_name = class_name;
	pPrevCur->teacher_name = teacher_name;
	pPrevCur->day_of_week = day_week;
	pPrevCur->sessions = session;
	pPrevCur->final = final_mark;
	pPrevCur->other = other_mark;
	pPrevCur->midterm = mid_mark;
	pPrevCur->number_credits = number_credits;
	pPrevCur->number_students = number_students;

	pPrevCur->pNext = nullptr;
	pPrevCur->student = nullptr;
}

void export_list_of_student_ToCSVFile(Student *pCur, string year_name, string semester_name, string course_id)
{
	ofstream file;
	file.open("student_In_A_Course.txt");
	file << "Academic year: ";
	file << year_name << endl;
	file << "Semester: ";
	file << semester_name << endl;
	file << "Course ID: ";
	file << course_id << endl;
	while (pCur != nullptr)
	{
		file << pCur->student_ID << ","
			 << pCur->first_name << ","
			 << pCur->last_name << ","
			 << pCur->gender << ","
			 << pCur->date_of_birth << ","
			 << pCur->social_ID;
		if (pCur->pNext != nullptr)
			file << endl;

		pCur = pCur->pNext;
	}
	file.close();
	cout << "Updated successfully!" << endl;
	string temp;
	cout << "Press any key to continue...\n";
	cin >> temp;
	clrscr();
}

// The pDelete is surely found.
void deleteCourse(Course *&pHead, Course *&pDelete, string year_name, string semester_name)
{
	if (pHead == nullptr)
	{
		cout << "There is no course to delete!" << endl;
		string s;
		cout << "Press any key to continue...";
		cin >> s;
		return;
	}

	Course *pCur = pHead;
	// If the deleted node is the first Node, then do these lines of code.
	if (pHead == pDelete)
	{
		pHead = pHead->pNext;
		// Delete the linked list of students in the Course.
		while (pCur->student != nullptr)
		{
			Student *pTemp1 = pCur->student;
			pCur->student = pCur->student->pNext;
			delete pTemp1;
		}
		string path;
		path = year_name + BACKSLASH + semester_name + BACKSLASH + pCur->id + ".txt";
		remove(path.c_str());
		delete pCur;
		pCur = nullptr;
		cout << "Updated successfully!" << endl;
		string temp;
		cout << "Press any key to continue...\n";
		cin >> temp;
		clrscr();
		return;
	}

	Course *pPrevCur = pHead;
	while (pCur != nullptr && pCur != pDelete)
	{
		pPrevCur = pCur;
		pCur = pCur->pNext;
	}
	// If found, delete the Node of course in the linked list
	pPrevCur->pNext = pCur->pNext;
	string path;
	path = year_name + BACKSLASH + semester_name + BACKSLASH + pCur->id + ".txt";
	remove(path.c_str());
	// Delete the pointer student of a course
	while (pCur->student != nullptr)
	{
		Student *pTemp1 = pCur->student;
		pCur->student = pCur->student->pNext;
		delete pTemp1;
	}
	delete pCur;
	pPrevCur = nullptr;
	pCur = nullptr;
	cout << "Updated successfully!" << endl;
	string temp;
	cout << "Press any key to continue...\n";
	cin >> temp;
	clrscr();
}

void update_course_ID(Course *&pCur, SchoolYear *pHead)
{
	string old_file_name = pCur->id;
	Semester *pCur_semester = nullptr;
	Course *pCur_course = nullptr;
	bool flag = false;
	while (pHead != nullptr)
	{
		pCur_semester = pHead->semester;
		while (pCur_semester != nullptr)
		{
			pCur_course = pCur_semester->course;
			while (pCur_course != nullptr)
			{
				if (pCur_course->id == pCur->id)
				{
					flag = true;
					break;
				}
				pCur_course = pCur_course->pNext;
			}
			if (flag == true)
				break;
			pCur_semester = pCur_semester->pNext;
		}
		if (flag == true)
			break;
		pHead = pHead->pNext;
	}
	string path = pHead->year_name + BACKSLASH + pCur_semester->semester_name + BACKSLASH;
	string old_path = path + old_file_name + ".txt";

	cout << "Enter new Course ID: ";
	string new_file_name;
	cin.ignore();
	getline(cin, new_file_name);
	string new_path = path + new_file_name + ".txt";
	int result;
	result = rename(old_path.c_str(), new_path.c_str());

	while (result != 0)
	{
		cout << "The course ID has been created before! Please try another course ID" << endl;
		cout << "Enter new Course ID: ";
		getline(cin, new_file_name);
		new_path = path + new_file_name + ".txt";
		result = rename(old_path.c_str(), new_path.c_str());
	}
	pCur->id = new_file_name;
	cout << "Update successfully!\n";
}

void update_course_name(Course *&pCur)
{
	cout << "Enter new Course Name: ";
	getline(cin, pCur->course_name);
	cout << "Update successfully!\n";
}

void update_class_name(Course *&pCur)
{
	cout << "Enter new Class Name: ";
	getline(cin, pCur->class_name);
	cout << "Update successfully!\n";
}

void update_teacher_name(Course *&pCur)
{
	cout << "Enter new Teacher Name: ";
	getline(cin, pCur->teacher_name);
	cout << "Update successfully!\n";
}

void update_number_credits(Course *&pCur)
{
	cout << "Enter new Number of Credits: ";
	int get_number_credits;
	cin >> get_number_credits;
	while (get_number_credits <= 0)
	{
		cout << "Invalid input. Try a new positive number of credits: ";
		cin >> get_number_credits;
	}
	pCur->number_credits = to_string(get_number_credits);
	cout << "Update successfully!\n";
}
void update_number_students(Course *&pCur)
{
	cout << "Enter new number of Students: ";
	int get_number_students;
	cin >> get_number_students;
	while (get_number_students <= 0)
	{
		cout << "Invalid input. Please try a new positive number of students!!!";
		cin >> get_number_students;
	}
	pCur->number_students = to_string(get_number_students);
	cout << "Update successfully!\n";
}

void update_day_week(Course *&pCur)
{
	cout << "Enter day of week: " << endl;
	cout << "MON / TUE / WED / THU / FRI / SAT:  ";
	string day_week;
	cin >> day_week;
	while (day_week != "MON" && day_week != "TUE" && day_week != "WED" && day_week != "THU" && day_week != "FRI" && day_week != "SAT")
	{
		cout << "Wrong type of day of week!" << endl;
		cout << "Enter day of week: ";
		cout << "MON / TUE / WED / THU / FRI / SAT:  ";
		cin >> day_week;
	}
	pCur->day_of_week = day_week;
	cout << "Update successfully!\n";
}

void update_session(Course *&pCur)
{
	cout << "Enter session" << endl;
	cout << "S1(07:30) -- S2(09:30) -- S3(13:30) -- S4(15:30): ";
	string session;
	cin >> session;
	while (session != "S1(07:30)" && session != "S2(09:30)" && session != "S3(13:30)" && session != "S4(15:30)")
	{
		cout << "Wrong type of session!" << endl;
		cout << "S1(07:30) -- S2(09:30) -- S3(13:30) -- S4(15:30): ";
		cin >> session;
	}
	pCur->sessions = session;
	cout << "Update successfully!\n";
}

void update_percentage(Course *&pCur)
{
	pCur->other = -1;
	while (pCur->other < 0)
	{
		// cout << "Hello World" << endl;
		cout << "The percentage of point form the midterm exam and final exam:  ";
		cin >> pCur->midterm >> pCur->final;
		pCur->other = 100 - pCur->midterm - pCur->final;
		if (pCur->other < 0)
			cout << "The percentage of point form the other exam is not valid" << endl;
	}
	cout << "Update successfully!\n";
}

void update_Course(Course *&pCur, SchoolYear *pHead)
{
	cout << "Choose option which have to be updated " << endl;
	while (true)
	{
		cout << "1. Course ID" << endl;
		cout << "2. Course Name" << endl;
		cout << "3. Class Name" << endl;
		cout << "4. Teacher Name" << endl;
		cout << "5. Number of credits " << endl;
		cout << "6. Number of students" << endl;
		cout << "7. Day of the week" << endl;
		cout << "8. Sessions" << endl;
		cout << "9. Update the percentage of point form the midterm exam and final exam" << endl;
		cout << "10. All of above " << endl;
		cout << "0. Exit" << endl;
		int option;
		cout << "Your option: ";
		cin >> option;
		clrscr();
		switch (option)
		{
		case 1:
		{
			update_course_ID(pCur, pHead);
			cout << "Press any key to continue...";
			string s;
			cin >> s;
			break;
		}
		case 2:
		{
			update_course_name(pCur);
			cout << "Press any key to continue...";
			string s;
			cin >> s;
			break;
		}
		case 3:
		{
			update_class_name(pCur);
			cout << "Press any key to continue...";
			string s;
			cin >> s;
			break;
		}
		case 4:
		{
			update_teacher_name(pCur);
			cout << "Press any key to continue...";
			string s;
			cin >> s;
			break;
		}
		case 5:
		{
			update_number_credits(pCur);
			cout << "Press any key to continue...";
			string s;
			cin >> s;
			break;
		}
		case 6:
		{
			update_number_students(pCur);
			cout << "Press any key to continue...";
			string s;
			cin >> s;
			break;
		}
		case 7:
		{
			update_day_week(pCur);
			cout << "Press any key to continue...";
			string s;
			cin >> s;
			break;
		}
		case 8:
		{
			update_session(pCur);
			cout << "Press any key to continue...";
			string s;
			cin >> s;
			break;
		}
		case 9:
		{
			update_percentage(pCur);
			cout << "Press any key to continue...";
			string s;
			cin >> s;
			break;
		}
		case 10:
		{
			update_course_ID(pCur, pHead);
			update_course_name(pCur);
			update_class_name(pCur);
			update_teacher_name(pCur);
			update_number_credits(pCur);
			update_number_students(pCur);
			update_day_week(pCur);
			update_session(pCur);
			update_percentage(pCur);
			break;
		}
		case 0:
		{
			cout << "Finish updating!!!" << endl;
			cout << "Please enter any key to continue...";
			string s;
			cin >> s;
			return;
		}
		default:
			continue;
		}
	}
}

Semester *Find_Semester(SchoolYear *pHead)
{
	cout << "List of School Years: " << endl;
	SchoolYear *pTraverse_schoolyear = pHead;
	while (pTraverse_schoolyear != nullptr)
	{
		cout << pTraverse_schoolyear->year_name << endl;
		pTraverse_schoolyear = pTraverse_schoolyear->pNext;
	}
	cout << "Enter shool Year: ";
	string get_schoolyear;
	cin >> get_schoolyear;
	while (pHead != nullptr && pHead->year_name != get_schoolyear)
	{
		pHead = pHead->pNext;
	}
	if (pHead == nullptr)
	{
		cout << "There is no school year matching with your typing!!!" << endl;
		cout << "Press any key to continue...\n";
		string s;
		cin >> s;
		clrscr();
		return NULL;
	}

	cout << "List of Semesters: " << endl;
	Semester *pTraverse_semester = pHead->semester;
	while (pTraverse_semester != nullptr)
	{
		cout << pTraverse_semester->semester_name << endl;
		pTraverse_semester = pTraverse_semester->pNext;
	}
	Semester *pCur_semester = pHead->semester;
	string get_semester;
	cout << "Enter semester: ";
	cin >> get_semester;

	while (pCur_semester != nullptr && pCur_semester->semester_name != get_semester)
	{
		pCur_semester = pCur_semester->pNext;
	}
	if (pCur_semester == nullptr)
	{
		cout << "There is no semester matching with your typing!!!" << endl;
		cout << "Press any key to continue...\n";
		string s;
		cin >> s;
		clrscr();
		return NULL;
	}
	return pCur_semester;
}

Course *Find_Course(SchoolYear *pHead)
{
	Semester *find_semester = Find_Semester(pHead);
	if (find_semester == nullptr)
		return NULL;
	Course *pTraverse_course = find_semester->course;
	cout << "List of courses: " << endl;
	cout << setw(13) << left << "Course ID " << setw(13) << left << "Course name " << endl;
	while (pTraverse_course != nullptr)
	{
		cout << setw(13) << left << pTraverse_course->id << setw(13) << left << pTraverse_course->course_name << endl;
		pTraverse_course = pTraverse_course->pNext;
	}

	Course *pCur_Course = find_semester->course;
	cout << "Enter Course ID: ";
	string get_course_ID;
	cin >> get_course_ID;
	while (pCur_Course != nullptr && pCur_Course->id != get_course_ID)
		pCur_Course = pCur_Course->pNext;
	if (pCur_Course == nullptr)
	{
		cout << "There is no course ID matching with your typing !!!" << endl;
		cout << "Press any key to continue...";
		string s;
		cin >> s;
		clrscr();
		return NULL;
	}
	// To make sure that the pCur_course is not a null pointer.
	return pCur_Course;
}

void Print_All_Student_In_A_Class_With_score_All(Class *pClass)
{

	Class *pCur_Class = pClass;
	string get_class;
	cout << "Enter Class: ";
	cin >> get_class;

	while (pCur_Class != nullptr && pCur_Class->class_name != get_class)
		pCur_Class = pCur_Class->pNext;

	if (pCur_Class == nullptr)
	{
		cout << "There is no class matching with your typing !!!" << endl;
		cout << "Press any key to continue...\n";
		string s;
		cin >> s;
		clrscr();
		return;
	}

	studentClass *pCur = pCur_Class->student;
	if (pCur == nullptr)
	{
		cout << "There is no students in the class " << endl;
	}

	while (pCur != nullptr)
	{
		cout
			<< pCur->student_ID << "   "
			<< pCur->first_name << "   "
			<< pCur->last_name << "   "
			<< pCur->gender << "   "
			<< pCur->date_of_birth << "   "
			<< pCur->social_ID << endl;

		scoreClass *pCurScore = pCur->score;

		if (pCurScore == nullptr)
		{
			cout << "\tNo score for this student" << endl;
			pCur = pCur->pNext;
			continue;
		}

		int n = 0;
		float sum = 0;

		while (pCurScore != nullptr)
		{
			cout
				<< left
				<< setw(7)
				<< pCurScore->course_ID << "|"
				<< left
				<< setw(15)
				<< pCurScore->course_name << "|"
				<< left
				<< setw(7)
				<< pCurScore->score.total_mark << "|"
				<< left
				<< setw(7)
				<< pCurScore->score.final_mark << "|"
				<< left
				<< setw(7)
				<< pCurScore->score.mid_mark << "|"
				<< left
				<< setw(7)
				<< pCurScore->score.other_mark << endl;

			n++;
			sum += pCurScore->score.total_mark;

			pCurScore = pCurScore->next;
		}
		if (n != 0)
			cout << right << setw(30) << "GPA: " << (sum / n) / 10 * 4 << endl;
		pCur = pCur->pNext;
	}
	cout << "Press any key to continue...\n";
	string s;
	cin >> s;
	clrscr();
}

bool checkForCourse(Course *pCur, string courseID)
{
	while (pCur != nullptr)
	{
		if (pCur->id == courseID)
		{
			return true;
		}
		pCur = pCur->pNext;
	}
	return false;
}

void Print_All_Student_In_A_Class_With_score_Semester(SchoolYear *pHead, Class *pClass)
{
	SchoolYear *pCurYear = pHead;
	Course *pCurCourse = nullptr;

	string get_schoolyear;
	cout << "Enter School Year: ";
	cin >> get_schoolyear;

	while (pHead != nullptr && pHead->year_name != get_schoolyear)
	{
		pHead = pHead->pNext;
	}
	if (pHead == nullptr)
	{
		cout << "There is no schoolyear matching with your typing!!!" << endl;
		cout << "Press any key to continue...\n";
		string s;
		cin >> s;
		clrscr();
		return;
	}

	Semester *pCur_Semester = pHead->semester;
	string get_semester;
	cout << "Enter Semester: ";
	cin >> get_semester;

	while (pCur_Semester != nullptr && pCur_Semester->semester_name != get_semester)
	{
		pCur_Semester = pCur_Semester->pNext;
	}

	if (pCur_Semester == nullptr)
	{
		cout << "There is no semester matching with your typing !!!" << endl;
		cout << "Press any key to continue...\n";
		string s;
		cin >> s;
		clrscr();
		return;
	}

	pCurCourse = pCur_Semester->course;

	Class *pCur_Class = pClass;
	string get_class;
	cout << "Enter Class: ";
	cin >> get_class;

	while (pCur_Class != nullptr && pCur_Class->class_name != get_class)
		pCur_Class = pCur_Class->pNext;

	if (pCur_Class == nullptr)
	{
		cout << "There is no academic class matching with your typing !!!" << endl;
		cout << "Press any key to continue...\n";
		string s;
		cin >> s;
		clrscr();
		return;
	}

	studentClass *pCur = pCur_Class->student;

	while (pCur != nullptr)
	{
		cout
			<< " "
			<< pCur->student_ID << " "
			<< " "
			<< pCur->first_name << " "
			<< " "
			<< pCur->last_name << " "
			<< " "
			<< pCur->gender << " "
			<< " "
			<< pCur->date_of_birth << " "
			<< " "
			<< pCur->social_ID << endl;

		scoreClass *pCurScore = pCur->score;

		if (pCurScore == nullptr)
		{
			cout << "\tNo score for this student" << endl;
		}

		int n = 0;
		float sum = 0;

		while (pCurScore != nullptr)
		{
			if (checkForCourse(pCurCourse, pCurScore->course_ID) == false)
			{
				pCurScore = pCurScore->next;
				if (pCurScore == nullptr)
					cout << "\tNo score for this student" << endl;
				continue;
			}
			cout
				<< left
				<< setw(30)
				<< "COURSE NAME"
				<< "|"
				<< left
				<< setw(15)
				<< "COURSE ID"
				<< "|"
				<< left
				<< setw(10)
				<< "TOTAL MARK"
				<< "|"
				<< left
				<< setw(10)
				<< "FINAL MARK"
				<< "|"
				<< left
				<< setw(10)
				<< "MID MARK"
				<< "|"
				<< left
				<< setw(10)
				<< "OTHER MARK" << endl;
			// if (pCurScore->score.final_mark == 0)
			// {
			// 	pCurScore = pCurScore->next;
			// 	continue;
			// }

			cout
				<< left
				<< setw(30)
				<< pCurScore->course_name << "|"
				<< left
				<< setw(15)
				<< pCurScore->course_ID << "|"
				<< left
				<< setw(10)
				<< pCurScore->score.total_mark << "|"
				<< left
				<< setw(10)
				<< pCurScore->score.final_mark << "|"
				<< left
				<< setw(10)
				<< pCurScore->score.mid_mark << "|"
				<< left
				<< setw(10)
				<< pCurScore->score.other_mark << endl;
			n++;
			sum += pCurScore->score.final_mark;

			pCurScore = pCurScore->next;
		}
		if (n != 0)
			cout << right << setw(50) << "GPA: " << (sum / n) / 10 * 4 << endl;
		pCur = pCur->pNext;
	}
	cout << "Press any key to continue...\n";
	string s;
	cin >> s;
	clrscr();
}