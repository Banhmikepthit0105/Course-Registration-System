#include "lib.h"

Class *Find_Class_addStudent_1styear(Class *pHead, SchoolYear *currentSchoolYear)
{
	if (pHead == nullptr)
	{
		cout << "There is no class has been created yet! Create class before adding student." << endl;
		cout << "Press any key to continue...";
		string temp;
		cin >> temp;
		return NULL;
	}
	string get_class;
	cout << "Enter class: ";
	cin >> get_class;

	while (pHead != nullptr && pHead->class_name != get_class)
		pHead = pHead->pNext;

	if (pHead == nullptr)
	{
		cout << "There is no class matching with your typing in this school year !!" << endl;
		cout << "Press any key to continue...";
		string temp;
		cin >> temp;
		return NULL;
	}
	// if (pHead->class_name == get_class)
	// {
	// 	if (stoi(pHead->class_name.substr(0, 2)) != stoi(currentSchoolYear->year_name.substr(7, 2)))
	// 	{
	// 		cout << "There is no class matching with your typing in this school year !!" << endl;
	// 		cout << "Press any key to continue...";
	// 		string temp;
	// 		cin >> temp;
	// 		return NULL;
	// 	}
	// }
	return pHead;
}

Class *Find_Class(Class *pHead)
{
	if (pHead == nullptr)
	{
		cout << "There is no class has been created yet!!" << endl;
		cout << "Press any key to continue...";
		string temp;
		cin >> temp;
		return NULL;
	}
	string get_class;
	cout << "Enter class: ";
	cin >> get_class;

	while (pHead != nullptr && pHead->class_name != get_class)
		pHead = pHead->pNext;

	if (pHead == nullptr)
	{
		cout << "There is no class matching with your typing !!" << endl;
		cout << "Press any key to continue...";
		string temp;
		cin >> temp;
		return NULL;
	}
	return pHead;
}

void add_Student_To_Class_By_File(Class *pHead_class, studentClass *&pHead_studentClass, passInfo *&headPass)
{
	ifstream file;
	// The file addStudentToCourse.txt is an input file, which contain the first line is the Course to be added
	// The following next lines are the students information.
	file.open("addStudentToClass.txt");
	if (!file.is_open())
	{
		cout << "Can't open addStudentToClass.txt" << endl;
		file.close();
		cout << "Press any key to continue...\n";
		string s;
		cin >> s;
		clrscr();
		return;
	}
	string student_ID;
	string first_name;
	string last_name;
	string gender;
	string date_of_birth;
	string social_ID;

	passInfo *pCurPass = nullptr;
	if (headPass != nullptr)
	{
		pCurPass = headPass;
		while (pCurPass != nullptr && pCurPass->next != nullptr)
		{
			pCurPass = pCurPass->next;
		}
	}

	while (!file.eof())
	{
		getline(file, student_ID, ',');
		getline(file, first_name, ',');
		getline(file, last_name, ',');
		getline(file, gender, ',');
		getline(file, date_of_birth, ',');
		getline(file, social_ID);
		// Create a new account for the student
		// If the student who is going to added, got the existed ID, then the passInfo won't update.
		if (is_Exist_account(headPass, student_ID) == false)
		{
			if (headPass == nullptr)
			{
				headPass = new passInfo;
				pCurPass = headPass;
			}
			else
			{
				pCurPass->next = new passInfo;
				pCurPass = pCurPass->next;
			}
			pCurPass->login = student_ID;
			pCurPass->password = default_password;
			pCurPass->type = 's';
			pCurPass->next = nullptr;
		}
		studentClass *pOverWrite = pHead_studentClass;
		studentClass *pPrevOverWrite = nullptr;
		while (pOverWrite != nullptr && pOverWrite->student_ID != student_ID)
		{
			pPrevOverWrite = pOverWrite;
			pOverWrite = pOverWrite->pNext;
		}
		if (pOverWrite != nullptr || is_Exist_studentClass(pHead_class, student_ID) == true)
		{
			continue;
		}
		else
		{
			if (pPrevOverWrite == nullptr)
			{
				pHead_studentClass = new studentClass;
				pPrevOverWrite = pHead_studentClass;
			}
			else
			{
				pPrevOverWrite->pNext = new studentClass;
				pPrevOverWrite = pPrevOverWrite->pNext;
			}
			pPrevOverWrite->student_ID = student_ID;
			pPrevOverWrite->first_name = first_name;
			pPrevOverWrite->last_name = last_name;
			pPrevOverWrite->gender = gender;
			pPrevOverWrite->date_of_birth = date_of_birth;
			pPrevOverWrite->social_ID = social_ID;
			pPrevOverWrite->pNext = nullptr;
		}
	}
	file.close();
}

bool is_Exist_studentClass(Class *pHead_class, string student_ID)
{
	while (pHead_class != nullptr)
	{
		studentClass *pCur = pHead_class->student;
		while (pCur != nullptr)
		{
			if (pCur->student_ID == student_ID)
				return true;
			pCur = pCur->pNext;
		}
		pHead_class = pHead_class->pNext;
	}
	return false;
}

bool is_Exist_studentCourse(Student *pHead_student, string student_ID)
{
	while (pHead_student != nullptr)
	{
		if (pHead_student->student_ID == student_ID)
			return true;
		pHead_student = pHead_student->pNext;
	}
	return false;
}

void add_Student_to_Course_By_File(Course *pCur, Student *&pHead, passInfo *&headPass)
{
	ifstream file;
	// The file addStudentToCourse.txt is an input file, which contain the first line is the Course to be addedd
	// The following next lines are the students information.
	file.open("addStudentToCourse.txt");
	if (!file.is_open())
	{
		cout << "Can't open addStudentToCourse.txt" << endl;
		file.close();
		cout << "Press any key to continue...\n";
		string s;
		cin >> s;
		clrscr();
		return;
	}
	string student_ID;
	string first_name;
	string last_name;
	string gender;
	string date_of_birth;
	string social_ID;
	string total_mark;
	string final_mark;
	string mid_mark;
	string other_mark;
	passInfo *pCurPass = nullptr;
	if (headPass != nullptr)
	{
		pCurPass = headPass;
		while (pCurPass != nullptr && pCurPass->next != nullptr)
			pCurPass = pCurPass->next;
	}

	while (!file.eof())
	{
		getline(file, student_ID, ',');
		getline(file, first_name, ',');
		getline(file, last_name, ',');
		getline(file, gender, ',');
		getline(file, date_of_birth, ',');
		getline(file, social_ID, ',');
		getline(file, total_mark, ',');
		getline(file, final_mark, ',');
		getline(file, mid_mark, ',');
		getline(file, other_mark, '\n');

		if (is_Exist_account(headPass, student_ID) == false)
		{
			if (headPass == nullptr)
			{
				headPass = new passInfo;
				pCurPass = headPass;
			}
			else
			{
				pCurPass->next = new passInfo;
				pCurPass = pCurPass->next;
			}

			pCurPass->login = student_ID;
			pCurPass->password = default_password;
			pCurPass->type = 's';
			pCurPass->next = nullptr;
		}
		Student *pOverWrite = nullptr;
		if (pHead != nullptr)
			pOverWrite = pHead;
		Student *pPrevOverWrite = nullptr;
		while (pOverWrite != nullptr && pOverWrite->student_ID != student_ID)
		{
			pPrevOverWrite = pOverWrite;
			pOverWrite = pOverWrite->pNext;
		}
		if (pOverWrite != nullptr)
		{
			continue;
		}
		else
		{
			if (pHead == nullptr)
			{
				pHead = new Student;
				pPrevOverWrite = pHead;
			}
			else
			{
				pPrevOverWrite->pNext = new Student;
				pPrevOverWrite = pPrevOverWrite->pNext;
			}
			pPrevOverWrite->student_ID = student_ID;
			pPrevOverWrite->first_name = first_name;
			pPrevOverWrite->last_name = last_name;
			pPrevOverWrite->gender = gender;
			pPrevOverWrite->date_of_birth = date_of_birth;
			pPrevOverWrite->social_ID = social_ID;
			pPrevOverWrite->score.total_mark = float_one_point_round(stof(total_mark));
			pPrevOverWrite->score.final_mark = float_one_point_round(stof(final_mark));
			pPrevOverWrite->score.mid_mark = float_one_point_round(stof(mid_mark));
			pPrevOverWrite->score.other_mark = float_one_point_round(stof(other_mark));

			pPrevOverWrite->score.total_mark = pPrevOverWrite->score.final_mark * pCur->final / 100 + pPrevOverWrite->score.mid_mark * pCur->midterm / 100 + pPrevOverWrite->score.other_mark * pCur->other / 100;
			pPrevOverWrite->score.total_mark = float_one_point_round(pPrevOverWrite->score.total_mark);
			pPrevOverWrite->pNext = nullptr;
		}
	}
	file.close();
}

void add_Student_to_Course_By_Console(Course *pCur, Student *&pHead, passInfo *&headPass)
{
	Student *pTraverse = nullptr;
	string student_ID;
	while (true)
	{
		cout << "Enter new student ID: ";
		cin >> student_ID;
		if (pHead != nullptr)
			pTraverse = pHead;
		while (pTraverse != nullptr && pTraverse->student_ID != student_ID)
		{
			pTraverse = pTraverse->pNext;
		}
		if (pTraverse != nullptr)
			cout << "The student ID has been created before!. Try again" << endl;
		else
			break;
	}
	Student *pAdd = nullptr;
	if (pHead != nullptr)
	{
		pAdd = pHead;
		while (pAdd != nullptr && pAdd->pNext != nullptr)
		{
			pAdd = pAdd->pNext;
		}
		pAdd->pNext = new Student;
		pAdd = pAdd->pNext;
		pAdd->pNext = nullptr;
	}

	if (pHead == nullptr)
	{
		pHead = new Student;
		pAdd = pHead;
		pHead->pNext = nullptr;
	}
	pAdd->student_ID = student_ID;
	cin.ignore();
	cout << "Enter new student first name: ";
	getline(cin, pAdd->first_name);

	cout << "Enter new student last name: ";
	getline(cin, pAdd->last_name);
	cout << "Enter new student gender: ";
	getline(cin, pAdd->gender);
	cout << "Enter new student date of birth: ";
	getline(cin, pAdd->date_of_birth);
	cout << "Enter new student social ID: ";
	cin >> pAdd->social_ID;

	passInfo *addPass = nullptr;
	if (headPass != nullptr)
	{
		addPass = headPass;
		while (addPass != nullptr && addPass->next != nullptr)
			addPass = addPass->next;
	}
	// Check if the account is exist or not:
	if (is_Exist_account(headPass, pAdd->student_ID) == false)
	{
		if (headPass == nullptr)
		{
			headPass = new passInfo;
			addPass = headPass;
		}
		else
		{
			addPass->next = new passInfo;
			addPass = addPass->next;
		}
		addPass->login = pAdd->student_ID;
		addPass->password = default_password;
		addPass->type = 's';
		addPass->next = nullptr;
	}
}

void remove_Student_from_Course(Student *&pHead)
{
	if (pHead == nullptr)
	{
		cout << "There is no students in the courses." << endl;
		return;
	}
	Student *pCur = pHead;
	Student *pPrevCur = pHead;
	string get_student_ID;
	cout << "Enter student ID: ";
	cin >> get_student_ID;
	while (pCur != nullptr && pCur->student_ID != get_student_ID)
	{
		pPrevCur = pCur;
		pCur = pCur->pNext;
	}

	if (pCur != nullptr)
	{
		if (pCur == pPrevCur)
		{
			pHead = pHead->pNext;
			delete pCur;
			pCur = nullptr;
			pPrevCur = nullptr;
		}
		else
		{
			pPrevCur->pNext = pCur->pNext;
			delete pCur;
			pCur = nullptr;
			pPrevCur = nullptr;
		}
		cout << "Delete student from Course successfully!!!" << endl;
		// cout << "Updated successfully!" << endl;
		// cout << "Press any key to continue...\n";
		// string s;
		// cin >> s;
		// clrscr();
		return;
	}
	cout << "There is no student ID matching with your typing !!!" << endl;
}