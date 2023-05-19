#include "lib.h"

// Temp Menu for staff

void menuStaff(SchoolYear *pHead_schoolYear, Class *pHead_class, passInfo *&headPass, string login)
{
	int i;
	SchoolYear *current_schoolyear = currentSchoolYear(pHead_schoolYear);
	while (true)
	{
		dialocatePass(headPass);
		print_output(pHead_schoolYear, pHead_class);
		SET_COLOR(0);
		clrscr();
		cout << "Type: Teacher " << endl;
		cout << "Login ID: " << login << endl;
		cout << "-------------------------------------------\n"
			 << current_schoolyear->year_name << endl;
		cout << "-------------------------------------------\n"
			 << "1. New school year.\n"
			 << "2. New classes.\n"
			 << "3. Change current school year.\n"
			 << "4. Add new students to 1st-year classes.\n"
			 << "5. New semester for current school year.\n"
			 << "6. Add students to course by file.\n"
			 << "7. Add a student to course by console.\n"
			 << "8. Add a course to this semester. \n"
			 << "9. View the list of courses.\n"
			 << "10. View the list of class.\n"
			 << "11. Update course information.\n"
			 << "12. Remove a student from the course.\n"
			 << "13. Delete a course.\n"
			 << "14. Add scores for the current school year.\n"
			 << "15. View a list of students in a class.\n"
			 << "16. View a list of students in a course.\n"
			 << "17. View GPA of a class in a semester.\n"
			 << "18. View total GPA of a class.\n"
			 << "19. Export list of students in course to CSV file.\n"
			 << "20. Edit password.\n"
			 << "0. Log out.\n"
			 << "Enter options: ";
		cin >> i;
		clrscr();
		switch (i)
		{
		case 0:
		{
			return;
		}
		case 1:
		{
			createNewSchoolYear(pHead_schoolYear);
			break;
		}
		case 2:
		{
			createNewClass(pHead_class, pHead_schoolYear);
			break;
		}
		case 3:
		{
			changeCurrentSchoolYear(current_schoolyear, pHead_schoolYear);
			break;
		}
		case 4:
		{
			Class *find_class = Find_Class_addStudent_1styear(pHead_class, current_schoolyear);
			if (find_class != nullptr)
			{
				string s;
				cout << "Enter when you finish entering student in file addStudentToClass.txt[Yes] : ";
				cin >> s;
				if (s != "Yes")
				{
					cout << "Cancel the action!" << endl;
					cout << "Press any key to continue..." << endl;
					cin >> s;
					break;
				}
				add_Student_To_Class_By_File(pHead_class, find_class->student, headPass);
				cout << "Updated successfully!" << endl;
				cout << "Press any key to continue..." << endl;
				cin >> s;
			}
			break;
		}
		case 5:
		{
			if (current_schoolyear != nullptr)
			{
				SchoolYear *pPrev_schoolYear = pHead_schoolYear;
				while (pPrev_schoolYear->pNext != current_schoolyear)
					pPrev_schoolYear = pPrev_schoolYear->pNext;
				addSemesterMenu(current_schoolyear, pPrev_schoolYear);
			}
			break;
		}
		case 6:
		{
			Course *course_addStudent_file = Find_Course(pHead_schoolYear);
			if (course_addStudent_file != nullptr)
			{
				string s;
				cout << "Enter when you finish entering student in file addStudentToCourse.txt[Yes] : ";
				cin >> s;
				if (s != "Yes")
				{
					cout << "Cancel the action!" << endl;
					cout << "Press any key to continue..." << endl;
					cin >> s;
					break;
				}
				add_Student_to_Course_By_File(course_addStudent_file, course_addStudent_file->student, headPass);
				cout << "Updated successfully!" << endl;
				cout << "Press any key to continue..." << endl;
				cin >> s;
			}
			break;
		}
		case 7:
		{
			Course *course_addStudent_console = Find_Course(pHead_schoolYear);
			if (course_addStudent_console != nullptr)
			{
				add_Student_to_Course_By_Console(course_addStudent_console, course_addStudent_console->student, headPass);
				cout << "Updated successfully!" << endl;
				cout << "Press any key to continue..." << endl;
				string s;
				cin >> s;
			}
			break;
		}
		case 8:
		{
			if (current_schoolyear == nullptr)
			{
				cout << "There is no school year has been created before!" << endl;
				cout << "Press any key to continue...";
				string temp;
				cin >> temp;
				break;
			}
			SchoolYear *pHead_schoolYear = current_schoolyear;
			cout << "Current school year: " << current_schoolyear->year_name << endl;
			Semester *pCur = pHead_schoolYear->semester;
			while (pCur != nullptr && pCur->pNext != nullptr)
				pCur = pCur->pNext;
			if (pCur == nullptr)
			{
				cout << "There is no semester has been created before!" << endl;
				cout << "Press any key to continue...";
				string temp;
				cin >> temp;
				break;
			}
			cout << "Current semester: " << pCur->semester_name << endl;
			addCourse(pCur->course);
			cout << "Updated succefully!" << endl;
			cout << "Press any key to continue..." << endl;
			string s;
			cin >> s;
			break;
		}
		case 9:
		{
			print_All_CourseToConsole(pHead_schoolYear);
			break;
		}
		case 10:
		{
			print_All_ClassToConsole(pHead_class);
			break;
		}
		case 11:
		{
			Course *course_update = Find_Course(pHead_schoolYear);
			if (course_update != nullptr)
			{
				update_Course(course_update, pHead_schoolYear);
				cout << "Updated successfully!" << endl;
				cout << "Press any key to continue..." << endl;
				string s;
				cin >> s;
			} //
			break;
		}
		case 12:
		{
			Course *course_remove_student = Find_Course(pHead_schoolYear);
			if (course_remove_student != nullptr)
			{
				remove_Student_from_Course(course_remove_student->student);
				cout << "Press any key to continue..." << endl;
				string s;
				cin >> s;
			}
			break;
		}
		case 13:
		{
			cout << "List of School Years: " << endl;
			SchoolYear *pTraverse_schoolyear = pHead_schoolYear;
			while (pTraverse_schoolyear != nullptr)
			{
				cout << pTraverse_schoolyear->year_name << endl;
				pTraverse_schoolyear = pTraverse_schoolyear->pNext;
			}
			string get_schoolyear;
			cout << "Enter School Year: ";
			cin >> get_schoolyear;
			SchoolYear *pHead = pHead_schoolYear;
			while (pHead != nullptr && pHead->year_name != get_schoolyear)
			{
				pHead = pHead->pNext;
			}
			if (pHead == nullptr)
			{
				cout << "There is no school year matching with your typing!!!" << endl;
				string temp;
				cout << "Press any key to continue...";
				cin >> temp;
				break;
			}
			// These code is used for traversing the linked list of Semester, to found the specific Semester.
			string get_semester;
			cout << "List of Semesters: " << endl;
			Semester *pTraverse_semester = pHead->semester;
			while (pTraverse_semester != nullptr)
			{
				cout << pTraverse_semester->semester_name << endl;
				pTraverse_semester = pTraverse_semester->pNext;
			}
			cout << "Enter Semester: ";
			cin >> get_semester;
			Semester *pCur_Semester = pHead->semester;
			while (pCur_Semester != nullptr && pCur_Semester->semester_name != get_semester)
				pCur_Semester = pCur_Semester->pNext;

			if (pCur_Semester == nullptr)
			{
				cout << "There is no semester matching with your typing !!!" << endl;
				string temp;
				cout << "Press any key to continue...";
				cin >> temp;
				break;
			}

			Course *pCur_Course = pCur_Semester->course;
			Course *pTraverse_course = pCur_Semester->course;
			cout << "List of courses: " << endl;
			cout << setw(13) << left << "Course ID " << setw(13) << left << "Course name " << endl;
			while (pTraverse_course != nullptr)
			{
				cout << left << setw(13) << pTraverse_course->id << left << setw(13) << pTraverse_course->course_name << endl;
				pTraverse_course = pTraverse_course->pNext;
			}
			cout << "Enter Course ID: ";
			string get_course_ID;
			cin >> get_course_ID;
			while (pCur_Course != nullptr && pCur_Course->id != get_course_ID)
			{
				pCur_Course = pCur_Course->pNext;
			}
			if (pCur_Course == nullptr)
			{
				cout << "There is no course ID matching with your typing !!!" << endl;
				string temp;
				cout << "Press any key to continue...";
				cin >> temp;
				break;
			}

			deleteCourse(pCur_Semester->course, pCur_Course, pHead->year_name, pCur_Semester->semester_name);
			break;
		}
		case 14:
		{

			if (current_schoolyear != nullptr)
				Menu_Score_Board(current_schoolyear);
			break;
		}
		case 15:
		{
			Class *class_print_student = Find_Class(pHead_class);
			if (class_print_student != nullptr)
				print_All_Student_In_A_class(class_print_student->student);
			break;
		}
		case 16:
		{
			Course *course_print_student = Find_Course(pHead_schoolYear);
			if (course_print_student != nullptr)
				Print_All_Student_In_A_Course(course_print_student->student);
			break;
		}
		case 17:
		{
			Print_All_Student_In_A_Class_With_score_Semester(pHead_schoolYear, pHead_class);
			break;
		}
		case 18:
		{
			Print_All_Student_In_A_Class_With_score_All(pHead_class);
			break;
		}
		case 19:
		{
			string get_schoolyear;
			cout << "Enter School Year: ";
			cin >> get_schoolyear;
			SchoolYear *pHead = pHead_schoolYear;
			while (pHead != nullptr && pHead->year_name != get_schoolyear)
			{
				pHead = pHead->pNext;
			}
			if (pHead == nullptr)
			{
				cout << "There is no school year matching with your typing!!!" << endl;
				string s;
				cout << "Press any key to continue...";
				cin >> s;
				break;
			}

			Semester *pCur_Semester = pHead->semester;
			// These code is used for traversing the linked list of Semester, to found the specific Semester.
			string get_semester;
			cout << "Enter Semester: ";
			cin >> get_semester;

			while (pCur_Semester != nullptr && pCur_Semester->semester_name != get_semester)
				pCur_Semester = pCur_Semester->pNext;

			if (pCur_Semester == nullptr)
			{
				cout << "There is no semester matching with your typing !!!" << endl;
				string s;
				cout << "Press any key to continue...";
				cin >> s;
				break;
			}

			Course *pCur_Course = pCur_Semester->course;
			cout << "Enter Course ID: ";
			string get_course_ID;
			cin >> get_course_ID;
			while (pCur_Course != nullptr && pCur_Course->id != get_course_ID)
			{
				pCur_Course = pCur_Course->pNext;
			}
			if (pCur_Course == nullptr)
			{
				cout << "There is no course ID matching with your typing !!!" << endl;
				string s;
				cout << "Press any key to continue...";
				cin >> s;
				break;
			}
			export_list_of_student_ToCSVFile(pCur_Course->student, pHead->year_name, pCur_Semester->semester_name, pCur_Course->id);
			break;
		}
		case 20:
		{
			edit(headPass, login);
			cout << "Updated successfully!" << endl;
			cout << "Press any key to continue...";
			string s;
			cin >> s;
			break;
		}
		default:
			continue;
		}
	}
}

// check if current school year exists
SchoolYear *currentSchoolYear(SchoolYear *pHead)
{
	if (pHead == nullptr)
		return NULL;
	// cout << "-------------------------------------------\n";
	SchoolYear *currentshoolyear = pHead;
	int currentSchoolYear = stoi(currentshoolyear->year_name.substr(5, 4));
	SchoolYear *pTraverse = pHead;
	while (pTraverse != nullptr)
	{
		currentSchoolYear = max(currentSchoolYear, stoi(pTraverse->year_name.substr(5, 4)));
		pTraverse = pTraverse->pNext;
	}
	// cout << currentshoolyear->year_name << endl;
	pTraverse = pHead;
	while (pTraverse != nullptr)
	{
		if (currentSchoolYear == stoi(pTraverse->year_name.substr(5, 4)))
			return pTraverse;
		pTraverse = pTraverse->pNext;
	}
	return nullptr;
}

// print current semester to screen
Semester *currentSemester(Semester *pHead)
{
	if (pHead == nullptr)
	{
		cout << "No semester has been created yet!!" << endl;
		return NULL;
	}
	cout << "-------------------------------------------\n";
	string currentSemester;
	while (pHead->pNext != nullptr)
		pHead = pHead->pNext;
	currentSemester = pHead->semester_name;
	cout << "Current semester: " << currentSemester << '\n';
	return pHead;
}

// Revese string
string revString(string a)
{
	string b = "";
	int n = a.length();
	for (int i = 0; i < n; i++)
		b += a[n - i - 1];
	return b;
}

bool isValidYear(string year)
{
	if (year.size() != 9)
		return false;
	for (int i = 0; i < year.length(); i++)
	{
		if (year[i] != '-' && year[i] != '0' && year[i] != '1' && year[i] != '2' && year[i] != '3' && year[i] != '4' &&
			year[i] != '5' && year[i] != '6' && year[i] != '7' && year[i] != '8' && year[i] != '9')
			return false;
	}
	return true;
}

// create new school year
void createNewSchoolYear(SchoolYear *&pHead)
{
	cout << "-------------------------------------------\n";
	cout << "Enter new school year: ";
	string year;
	cin >> year;
	while (!isValidYear(year))
	{
		clrscr();
		cout << "Wrong syntax to create new school year.\n";
		cout << "The syntax must be xxxx-xxxx and x must be a number from 0-9" << endl;
		cout << "Enter new school year (press '0' to exit): ";
		cin >> year;
		if (year == "0")
			return;
	}

	string year1 = year.substr(0, 4);
	string year2 = year.substr(5, 4);

	while (year[4] != '-' || stoi(year2) - stoi(year1) != 1)
	{
		clrscr();
		cout << "Wrong syntax to create new school year.\n";
		if (year.size() != 9 || year[4] != '-')
		{
			cout << "The syntax must be xxxx-xxxx." << endl;
		}
		if (stoi(year2) - stoi(year1) > 1)
			cout << "The distance of the academic year is 1 year." << endl;
		if (stoi(year2) - stoi(year1) < 1)
			cout << "The more later year must be bigger than the sooner year " << endl;
		cout << "Please try again..." << endl;
		cout << "Enter new school year (press '0' to exit): ";
		cin >> year;
		if (year == "0")
			return;
		while (!isValidYear(year))
		{
			clrscr();
			cout << "Wrong syntax to create new school year.\n";
			cout << "The syntax must be xxxx-xxxx and x must be a number from 0-9" << endl;
			cout << "Enter new school year (press '0' to exit): ";
			cin >> year;
			if (year == "0")
				return;
		}
		year1 = year.substr(0, 4);
		year2 = year.substr(5, 4);
	}
	SchoolYear *pCur = nullptr;
	if (pHead != nullptr)
		pCur = pHead;
	bool is_created = true;
	while (pCur != nullptr && pCur->year_name != year)
	{
		pCur = pCur->pNext;
	}
	if (pCur == nullptr)
		is_created = false;
	if (is_created == false)
	{
		SchoolYear *pPrevCur = nullptr;
		pCur = nullptr;
		if (pHead == nullptr)
		{
			pHead = new SchoolYear();
			pCur = pHead;
		}
		else
			pCur = pHead;

		if (stoi(year.substr(0, 4)) < stoi(pHead->year_name.substr(0, 4)))
		{
			SchoolYear *DummyNode = nullptr;
			DummyNode = new SchoolYear;
			DummyNode->year_name = year;
			DummyNode->semester = nullptr;
			DummyNode->pNext = pHead;
			pHead = DummyNode;
			cout << "New school year created successfully.\n";
			cout << "Press any key to continue...\n";
			string s;
			cin >> s;
			return;
		}

		while (pCur != nullptr && pCur->pNext != nullptr)
		{
			if (stoi(year.substr(0, 4)) < stoi(pCur->pNext->year_name.substr(0, 4)))
				break;
			pCur = pCur->pNext;
		}

		SchoolYear *DummyNode = nullptr;
		DummyNode = new SchoolYear;
		DummyNode->year_name = year;
		DummyNode->semester = nullptr;
		DummyNode->pNext = pCur->pNext;
		pCur->pNext = DummyNode;
		cout << "New school year created successfully.\n";
	}
	else
	{
		cout << "Failed to create new school year. The school year has been created!\n";
	}
	cout << "Press any key to continue...\n";
	string s;
	cin >> s;
}

// create new class menu
void createNewClass(Class *&pHead, SchoolYear *head)
{
	int i;
	while (true)
	{
		print_output(head, pHead);
		clrscr();
		cout << "-------------------------------------------\n";
		cout << "1. New classes\n0. Exit\nEnter options: ";
		cin >> i;
		if (i == 1)
		{
			string get_class;
			cout << "Enter class (from 1-99): ";
			cin >> get_class;
			while (stoi(get_class) <= 0 || stoi(get_class) >= 100)
			{
				cout << "Wrong syntax of class, enter the academic class which begin from 1-99 " << endl;
				cin >> get_class;
			}
			cout << "Enter type of the class: ";
			string type_class;
			cin >> type_class;

			while (type_class != "CLC" && type_class != "VP" && type_class != "APCS")
			{
				cout << "Wrong syntax of class, enter the type of class among CLC, VP or APCS: ";
				cin >> type_class;
			}

			cout << "Enter the ordered of the class (1-99): ";
			int ordered_class;
			cin >> ordered_class;
			while (ordered_class < 1 || ordered_class > 99)
			{
				cout << "Invalid input. The ordereded of the class must in range 1-99: ";
				cin >> ordered_class;
			}
			if (ordered_class < 10)
				get_class = get_class + type_class + "0" + to_string(ordered_class);
			else
				get_class = get_class = get_class + type_class + to_string(ordered_class);

			Class *pCur = nullptr, *pPrevCur = nullptr;
			if (pHead == nullptr)
			{
				pHead = new Class;
				pCur = pHead;
				pPrevCur = pHead;
			}
			else
			{
				pCur = pHead;
				while (pCur != nullptr && pCur->class_name != get_class)
				{
					pPrevCur = pCur;
					pCur = pCur->pNext;
				}
				if (pCur != nullptr)
				{
					cout << "The class has been already created !!" << endl;
					cout << "Press any key to continue...\n";
					string s;
					cin >> s;
					continue;
				}
				else
				{
					pPrevCur->pNext = new Class;
					pPrevCur = pPrevCur->pNext;
				}
			}

			pPrevCur->class_name = get_class;
			pPrevCur->student = nullptr;
			pPrevCur->pNext = nullptr;
			cout << "Create the class successfully!" << endl;
			cout << "Press any key to continue...\n";
			string s;
			cin >> s;
			continue;
		}
		else if (i == 0)
			break;
		else
		{
			cout << "Invalid option!" << endl;
			cout << "Press any key to continue...\n";
			string s;
			cin >> s;
			continue;
		}
	}
}

// add new course menu
void addSemesterMenu(SchoolYear *pHead_schoolYear, SchoolYear *pPrev_schoolYear)
{
	clrscr();
	while (!checkSchoolYearSemIsFull(pHead_schoolYear))
	{
		addSemester(pHead_schoolYear, pPrev_schoolYear, pHead_schoolYear->semester);
		break;
	}
	if (checkSchoolYearSemIsFull(pHead_schoolYear))
	{
		cout << "This school year is full of semester ! (3 semesters) \n";
		string temp;
		cout << "Press any key to continue...\n";
		cin >> temp;
	}
}

// void add_semester(Semester*& pHead, string semester)
//{
//	if (pHead == nullptr) {
//		pHead = new Semester();
//		Semester* pTail = pHead;
//		pTail->course = nullptr;
//		pTail->semester_name = semester;
//		pTail->pNext = nullptr;
//	}
//	else {
//		Semester* pTail = pHead;
//		while (pTail->pNext != nullptr)
//			pTail = pTail->pNext;
//		pTail->pNext = new Semester();
//		pTail = pTail->pNext;
//		pTail->course = nullptr;
//		pTail->semester_name = semester;
//		pTail->pNext = nullptr;
//	}
// }
// add new semester

void addSemester(SchoolYear *current_SchoolYear, SchoolYear *pPrev_schoolYear, Semester *&pHead)
{
	while (true)
	{
		cout << "-------------------------------------------\n";
		cout << "Choose Semester: " << endl;
		cout << "1. Semester 1\n2. Semester 2\n3. Semester 3\n0. Exit\nEnter options: ";
		int option;
		cin >> option;
		switch (option)
		{
		case 1:
		{
			if (pHead == nullptr && checkIsGoodSemester)
				add_semester(current_SchoolYear, pPrev_schoolYear, pHead, "Semester1");
			else
				cout << "Failed to create new semester.";
		}
		break;
		case 2:
		{
			if (!check_semester(pHead, "Semester2"))
				cout << "Failed to create new semester.";
			else
				add_semester(current_SchoolYear, pPrev_schoolYear, pHead, "Semester2");
		}
		break;
		case 3:
		{
			if (!check_semester(pHead, "Semester3"))
				cout << "Failed to create new semester.";
			else
				add_semester(current_SchoolYear, pPrev_schoolYear, pHead, "Semester3");
		}
		break;
		case 0:
			return;
		default:
			continue;
		}
	}
}

bool check_semester(Semester *pHead, string semester)
{
	if (pHead == nullptr)
		return false;
	while (pHead != nullptr && pHead->semester_name != semester)
	{
		pHead = pHead->pNext;
	}
	if (pHead != nullptr)
		return false;
	return true;
}

bool isLeapYear(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return true;
	return false;
}

int number_days_of_month(int month, int year)
{
	int day;
	if (month == 2)
	{
		if (isLeapYear(year))
			day = 29;
		else
			day = 28;
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		day = 30;
	}
	else
		day = 31;
	return day;
}

bool isDate(Date p)
{
	if (p.day < 1 || p.day > number_days_of_month(p.month, p.year) || p.month < 1 || p.month > 12)
		return false;
	return true;
}

bool checkIsSmallerDate(Date d1, Date d2)
{
	// d1 befor, d2 after
	if (d1.year > d2.year)
		return false;
	else if (d1.year < d2.year)
		return true;
	else if (d1.month > d2.month)
		return false;
	else if (d1.month < d2.month)
		return true;
	else if (d1.day > d2.day)
		return false;
	else if (d1.day < d2.day)
		return true;
	return false;
}

bool checkIsGoodSemester(Semester *s1, Semester *s2)
{
	if (s1 == nullptr || s2 == nullptr)
		return true;
	else
	{
		return checkIsSmallerDate(s1->end, s2->start);
	}
}

void add_semester(SchoolYear *current_SchoolYear, SchoolYear *pPrev_schoolYear, Semester *&pHead, string semester)
{
	Semester *pTail = nullptr;
	if (pHead == nullptr)
	{
		pHead = new Semester;
		pTail = pHead;
	}

	else
	{
		pTail = pHead;
		while (pTail != nullptr && pTail->pNext != nullptr)
			pTail = pTail->pNext;
		pTail->pNext = new Semester;
		pTail = pTail->pNext;
	}

	pTail->semester_name = semester;

	Semester *lastSemester_pPrev_schoolYear = pPrev_schoolYear->semester;
	while (lastSemester_pPrev_schoolYear->pNext != nullptr)
	{
		lastSemester_pPrev_schoolYear = lastSemester_pPrev_schoolYear->pNext;
	}
	Date start, end;

	cout << "----------" << current_SchoolYear->year_name << "----------" << endl;
	cout << "Enter the start date of the semester (dd/mm/yyyy) \n";
	cout << "Enter day: ";
	cin >> start.day;
	cout << "Enter month: ";
	cin >> start.month;
	cout << "Enter year: ";
	cin >> start.year;

	pTail->start = start;
	Semester *pPrev_tail = nullptr;
	if (pHead->pNext != nullptr)
	{
		pPrev_tail = pHead;
		while (pPrev_tail->pNext != pTail)
			pPrev_tail = pPrev_tail->pNext;
	}

	while ((start.year != stoi(current_SchoolYear->year_name.substr(0, 4)) && start.year != stoi(current_SchoolYear->year_name.substr(5, 4))) || !isDate(start) || !checkIsGoodSemester(lastSemester_pPrev_schoolYear, pTail) || !checkIsGoodSemester(pPrev_tail, pTail))
	{
		if ((start.year != stoi(current_SchoolYear->year_name.substr(0, 4)) && start.year != stoi(current_SchoolYear->year_name.substr(5, 4))))
		{
			cout << "Start date doesn't match with current school year !\n";
		}
		else if (!isDate(start))
			cout << "Date is invalid !\n";
		else
			cout << "Start date of this semester in this school year must be later than end date of semester of previous school year !  \n";
		cout << "----------" << current_SchoolYear->year_name << "----------" << endl;
		cout << "Enter the start date of the semester (dd/mm/yyyy) \n";
		cout << "Enter day: ";
		cin >> start.day;
		cout << "Enter month: ";
		cin >> start.month;
		cout << "Enter year: ";
		cin >> start.year;
		pTail->start = start;
	}

	cout << "----------" << current_SchoolYear->year_name << "----------" << endl;
	cout << "Enter the end date of the semester (dd/mm/yyyy) \n";
	cout << "Enter day: ";
	cin >> end.day;
	cout << "Enter month: ";
	cin >> end.month;
	cout << "Enter year: ";
	cin >> end.year;

	pTail->end = end;

	while ((end.year != stoi(current_SchoolYear->year_name.substr(0, 4)) && end.year != stoi(current_SchoolYear->year_name.substr(5, 4))) || !isDate(end) || !checkIsSmallerDate(start, end))
	{
		if (end.year != stoi(current_SchoolYear->year_name.substr(0, 4)) && end.year != stoi(current_SchoolYear->year_name.substr(5, 4)))
		{
			cout << "End date doesn't match with current school year !\n ";
		}
		else if (!checkIsSmallerDate(start, end))
			cout << "End date must be later than start date !\n";
		else
			cout << "Date is invalid !\n";
		cout << "----------" << current_SchoolYear->year_name << "----------" << endl;
		cout << "Enter the end date of the semester (dd/mm/yyyy) \n";
		cout << "Enter day: ";
		cin >> end.day;
		cout << "Enter month: ";
		cin >> end.month;
		cout << "Enter year: ";
		cin >> end.year;
		pTail->end = end;
	}

	pTail->course = nullptr;
	pTail->pNext = nullptr;
	cout << "Add new semester successful !";
	cout << "Press any keys to continue ...";
	string s;
	cin >> s;
}
