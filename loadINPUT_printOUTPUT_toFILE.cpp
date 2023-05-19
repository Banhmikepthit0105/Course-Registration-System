#include "lib.h"

bool isFileEmpty(string filename)
{
	ifstream file(filename);
	return file.peek() == ifstream::traits_type::eof();
}

void load_student_InCourse(Course *pCur_course, Student *&pHead, string schoolYear_name, string semester_name, string course_id)
{
	ifstream file;
	file.open(schoolYear_name + "\\" + semester_name + "\\" + course_id + ".txt");

	if (!file.is_open())
		return;
	if (isFileEmpty(schoolYear_name + "\\" + semester_name + "\\" + course_id + ".txt"))
	{
		pHead = nullptr;
		return;
	}
	Student *pCur = pHead;
	while (!file.eof())
	{
		if (pHead == nullptr)
		{
			pHead = new Student;
			pCur = pHead;
		}
		else
		{
			pCur->pNext = new Student;
			pCur = pCur->pNext;
		}
		getline(file, pCur->student_ID, ',');
		getline(file, pCur->first_name, ',');
		getline(file, pCur->last_name, ',');
		getline(file, pCur->gender, ',');
		getline(file, pCur->date_of_birth, ',');
		getline(file, pCur->social_ID, ',');

		string temp;
		getline(file, temp, ',');
		pCur->score.total_mark = float_one_point_round(stof(temp));

		getline(file, temp, ',');
		pCur->score.final_mark = float_one_point_round(stof(temp));

		getline(file, temp, ',');
		pCur->score.mid_mark = float_one_point_round(stof(temp));

		getline(file, temp);
		pCur->score.other_mark = float_one_point_round(stof(temp));

		pCur->score.total_mark = pCur->score.final_mark * pCur_course->final / 100 + pCur->score.mid_mark * pCur_course->midterm / 100 + pCur->score.other_mark * pCur_course->other / 100;
		pCur->score.total_mark = float_one_point_round(pCur->score.total_mark);

		pCur->pNext = nullptr;
	}
	file.close();
}

void load_student_InClass(studentClass *&pHead, string class_name)
{
	ifstream file;
	file.open(class_name + ".txt");
	if (!file.is_open())
		return;
	if (isFileEmpty(class_name + ".txt"))
	{
		pHead = nullptr;
		return;
	}
	studentClass *pCur = pHead;
	while (!file.eof())
	{
		if (pHead == nullptr)
		{
			pHead = new studentClass;
			pCur = pHead;
		}
		else
		{
			pCur->pNext = new studentClass;
			pCur = pCur->pNext;
		}
		getline(file, pCur->student_ID, ',');
		getline(file, pCur->first_name, ',');
		getline(file, pCur->last_name, ',');
		getline(file, pCur->gender, ',');
		getline(file, pCur->date_of_birth, ',');
		getline(file, pCur->social_ID, '\n');

		pCur->pNext = nullptr;
	}
	file.close();
}

void load_Score_to_student_class(studentClass *&pCur, SchoolYear *&pYear)
{
	scoreClass *pHeadScore = nullptr;
	scoreClass *pCurScore = nullptr;

	SchoolYear *pCurYear = pYear;
	while (pCurYear != nullptr)
	{
		Semester *pCurSemester = pCurYear->semester;
		while (pCurSemester != nullptr)
		{
			Course *pCurCourse = pCurSemester->course;
			while (pCurCourse != nullptr)
			{
				Student *pCurStudent = pCurCourse->student;
				while (pCurStudent != nullptr)
				{
					if (pCurStudent->student_ID == pCur->student_ID)
					{
						if (pHeadScore == nullptr)
						{
							pHeadScore = new scoreClass;
							pCurScore = pHeadScore;
						}
						else
						{
							pCurScore->next = new scoreClass;
							pCurScore = pCurScore->next;
						}

						pCurScore->course_name = pCurCourse->course_name;
						pCurScore->course_ID = pCurCourse->id;
						pCurScore->score = pCurStudent->score;
						pCurScore->next = nullptr;
					}
					pCurStudent = pCurStudent->pNext;
				}
				pCurCourse = pCurCourse->pNext;
			}
			pCurSemester = pCurSemester->pNext;
		}
		pCurYear = pCurYear->pNext;
	}
	pCur->score = pHeadScore;
}

void load_course(Course *&pHead, string schoolYear_name, string semester_name)
{
	ifstream file;
	file.open(schoolYear_name + "\\" + semester_name + "\\courseList.txt");
	if (!file.is_open())
		return;
	if (isFileEmpty(schoolYear_name + "\\" + semester_name + "\\courseList.txt"))
	{
		pHead = nullptr;
		return;
	}
	Course *pCur = pHead;
	while (!file.eof())
	{
		if (pHead == nullptr)
		{
			pHead = new Course;
			pCur = pHead;
		}
		else
		{
			pCur->pNext = new Course;
			pCur = pCur->pNext;
		}

		getline(file, pCur->id, ',');
		getline(file, pCur->course_name, ',');
		getline(file, pCur->class_name, ',');
		getline(file, pCur->teacher_name, ',');
		getline(file, pCur->number_credits, ',');
		getline(file, pCur->number_students, ',');
		getline(file, pCur->day_of_week, ',');
		getline(file, pCur->sessions, ',');

		string s;
		getline(file, s, ',');
		pCur->final = stof(s);

		getline(file, s, ',');
		pCur->midterm = stof(s);

		getline(file, s);
		pCur->other = stof(s);

		pCur->student = nullptr;
		pCur->pNext = nullptr;
	}
	file.close();
}

void load_semester(Semester *&pHead, string schoolYear_name)
{
	ifstream file;
	file.open(schoolYear_name + "\\semesterList.txt");

	Semester *pCur = pHead;
	if (!file.is_open())
	{
		file.close();
		return;
	}
	if (isFileEmpty(schoolYear_name + "\\semesterList.txt") == true)
	{
		pHead = nullptr;
		return;
	}
	while (!file.eof())
	{
		if (pHead == nullptr)
		{
			pHead = new Semester;
			pCur = pHead;
		}
		else
		{
			pCur->pNext = new Semester;
			pCur = pCur->pNext;
		}
		// file >> pCur->semester_name;

		string day, month, year;
		
		getline(file, pCur->semester_name, ',');
		getline(file, day, '/');
		pCur->start.day = stoi(day);
		getline(file, month, '/');
		pCur->start.month = stoi(month);
		getline(file, year, ',');
		pCur->start.year = stoi(year);

		getline(file, day, '/');
		pCur->end.day = stoi(day);
		getline(file, month, '/');
		pCur->end.month = stoi(month);
		getline(file, year);
		pCur->end.year = stoi(year);

		pCur->course = nullptr;
		pCur->pNext = nullptr;
	}
	file.close();
}

void load_schoolYear(SchoolYear *&pHead)
{
	ifstream file;
	file.open("schoolYearList.txt");
	if (!file.is_open())
		return;
	if (isFileEmpty("schoolYearList.txt"))
	{
		pHead = nullptr;
		return;
	}
	SchoolYear *pCur = pHead;
	while (!file.eof())
	{
		if (pHead == nullptr)
		{
			pHead = new SchoolYear;
			pCur = pHead;
		}
		else
		{
			pCur->pNext = new SchoolYear;
			pCur = pCur->pNext;
		}
		file >> pCur->year_name;
		pCur->semester = nullptr;
		pCur->pNext = nullptr;
	}
	file.close();
}

void load_class(Class *&pHead)
{
	ifstream file;
	file.open("classList.txt");

	if (!file.is_open())
		return;

	if (isFileEmpty("classList.txt"))
	{
		pHead = nullptr;
		return;
	}

	Class *pCur = pHead;
	while (!file.eof())
	{
		if (pHead == nullptr)
		{
			pHead = new Class;
			pCur = pHead;
		}
		else
		{
			pCur->pNext = new Class;
			pCur = pCur->pNext;
		}
		file >> pCur->class_name;
		pCur->pNext = nullptr;
	}
	file.close();
}

void load_input(SchoolYear *&pHead_schoolYear, Class *&pHead_class)
{
	// The function is used to load the data of schoolyears, semesters in each schoolyear, courses in each semester, students in each courses.
	// The format of the folder is:
	//
	// The big folder will contain the file .txt which named schoolYearList.txt, which in each line of the file contains the name of the schoolyear (This schoolyear has been created before)
	// For each year which has been included in the file schoolYearList.txt, it means that the folder of that year has been created before.
	// ////
	// In each folder of each year, it will contain the file .txt which named semesterList.txt, which included the list of semester that has been created before and folder of its semester
	// In each folder of each semester, it will contain the file .txt which named courseList.txt, which included the data of all the courses which have been created before.
	// The data of each course includes course id, course name, class name

	/*The pCur_schoolYear is used for traversing the list of nodes*/

	load_schoolYear(pHead_schoolYear);
	SchoolYear *pCur_schoolYear = pHead_schoolYear;
	while (pCur_schoolYear != nullptr)
	{
		Semester *pCur_Semester = nullptr;
		load_semester(pCur_Semester, pCur_schoolYear->year_name);
		pCur_schoolYear->semester = pCur_Semester;
		while (pCur_Semester != nullptr)
		{
			Course *pCur_Course = nullptr;
			load_course(pCur_Course, pCur_schoolYear->year_name, pCur_Semester->semester_name);
			pCur_Semester->course = pCur_Course;
			while (pCur_Course != nullptr)
			{
				Student *pCur_Student = nullptr;
				load_student_InCourse(pCur_Course, pCur_Student, pCur_schoolYear->year_name, pCur_Semester->semester_name, pCur_Course->id);
				pCur_Course->student = pCur_Student;
				pCur_Course = pCur_Course->pNext;
			}
			pCur_Semester = pCur_Semester->pNext;
		}
		pCur_schoolYear = pCur_schoolYear->pNext;
	}

	// Load class
	load_class(pHead_class);
	Class *pCur_class = pHead_class;
	while (pCur_class != nullptr)
	{
		studentClass *pCur_1 = nullptr;
		load_student_InClass(pCur_1, pCur_class->class_name);
		pCur_class->student = pCur_1;
		pCur_class = pCur_class->pNext;
	}
	pCur_class = pHead_class;
	while (pCur_class != nullptr)
	{
		studentClass *pCur_1 = pCur_class->student;
		while (pCur_1 != nullptr)
		{
			load_Score_to_student_class(pCur_1, pHead_schoolYear);
			pCur_1 = pCur_1->pNext;
		}
		pCur_class = pCur_class->pNext;
	}

	// PRINT SOMETHING ON CONSOLE
	//  SchoolYear* pTemp1 = pHead_schoolYear;
	//  while (pHead_schoolYear != nullptr)
	//  {
	//  	cout << endl;
	//  	cout << pHead_schoolYear->year_name << endl;
	//  	while (pHead_schoolYear->semester != nullptr)
	//  	{
	//  		cout << endl;
	//  		cout << pHead_schoolYear->semester->semester_name << endl;
	//  		while (pHead_schoolYear->semester->course != nullptr)
	//  		{
	//  			cout << endl;
	//  			cout << pHead_schoolYear->semester->course->id << " " << pHead_schoolYear->semester->course->course_name << " "
	//  				<< pHead_schoolYear->semester->course->class_name << " " << pHead_schoolYear->semester->course->teacher_name << " "
	//  				<< pHead_schoolYear->semester->course->number_credits << " " << pHead_schoolYear->semester->course->number_students << " "
	//  				<< pHead_schoolYear->semester->course->day_of_week << " " << pHead_schoolYear->semester->course->sessions << endl;

	// 			while (pHead_schoolYear->semester->course->student != nullptr)
	// 			{
	// 				cout << endl;
	// 				cout << pHead_schoolYear->semester->course->student->student_ID << " " << pHead_schoolYear->semester->course->student->first_name << " "
	// 					<< pHead_schoolYear->semester->course->student->last_name << " " << pHead_schoolYear->semester->course->student->gender << " "
	// 					<< pHead_schoolYear->semester->course->student->date_of_birth << " " << pHead_schoolYear->semester->course->student->social_ID << " "
	// 					<< pHead_schoolYear->semester->course->student->score.total_mark << " " << pHead_schoolYear->semester->course->student->score.final_mark << " "
	// 					<< pHead_schoolYear->semester->course->student->score.mid_mark << " " << pHead_schoolYear->semester->course->student->score.other_mark << endl;
	// 				cout << endl;

	// 				pHead_schoolYear->semester->course->student = pHead_schoolYear->semester->course->student->pNext;
	// 			}
	// 			pHead_schoolYear->semester->course = pHead_schoolYear->semester->course->pNext;
	// 		}
	// 		pHead_schoolYear->semester = pHead_schoolYear->semester->pNext;
	// 	}
	// 	pHead_schoolYear = pHead_schoolYear->pNext;
	// }
	// pHead_schoolYear = pTemp1;

	// Class* pTemp2 = pHead_class;
	// while (pHead_class != nullptr)
	// {
	// 	cout << endl;
	// 	cout << pHead_class->class_name << " ";
	// 	while (pHead_class->student != nullptr)
	// 	{
	// 		cout << endl;
	// 		cout << pHead_class->student->student_ID << " " << pHead_class->student->first_name << " "
	// 			<< pHead_class->student->last_name << " " << pHead_class->student->gender << " "
	// 			<< pHead_class->student->date_of_birth << " " << pHead_class->student->social_ID << endl;
	// 		cout << endl;
	// 		pHead_class->student = pHead_class->student->pNext;
	// 	}
	// 	cout << endl;
	// 	pHead_class = pHead_class->pNext;
	// }
}

void print_student_InClass(studentClass *pHead, string class_name)
{
	ofstream file;
	file.open(class_name + ".txt", ios::trunc);
	while (pHead != nullptr)
	{
		file
			<< pHead->student_ID << ","
			<< pHead->first_name << ","
			<< pHead->last_name << ","
			<< pHead->gender << ","
			<< pHead->date_of_birth << ","
			<< pHead->social_ID;
		if (pHead->pNext != nullptr)
			file << '\n';

		pHead = pHead->pNext;
	}
	file.close();
}

void print_student_InCourse(Student *pHead, string schoolYear_name, string semester_name, string course_id)
{
	// ifstream check_file_exist;
	// check_file_exist.open(schoolYear_name + "\\" + semester_name + "\\" + course_id + ".txt");
	// bool check = 0;
	// if (check_file_exist.is_open())
	// 	check = 1;
	// check_file_exist.close();
	// if (check == 1)
	// {
	ofstream file;
	file.open(schoolYear_name + "\\" + semester_name + "\\" + course_id + ".txt", ios::trunc);
	while (pHead != nullptr)
	{
		file << pHead->student_ID << ","
			 << pHead->first_name << ","
			 << pHead->last_name << ","
			 << pHead->gender << ","
			 << pHead->date_of_birth << ","
			 << pHead->social_ID << ","
			 << pHead->score.total_mark << ","
			 << pHead->score.final_mark << ","
			 << pHead->score.mid_mark << ","
			 << pHead->score.other_mark;
		if (pHead->pNext != nullptr)
			file << '\n';
		pHead = pHead->pNext;
	}
	file.close();
	// }
}

void print_course(Course *pHead, string schoolYear_name, string semester_name)
{

	ofstream file;
	file.open(schoolYear_name + "\\" + semester_name + "\\" + "courseList.txt", ios::trunc);
	while (pHead != nullptr)
	{
		file
			<< pHead->id << ","
			<< pHead->course_name << ","
			<< pHead->class_name << ","
			<< pHead->teacher_name << ","
			<< pHead->number_credits << ","
			<< pHead->number_students << ","
			<< pHead->day_of_week << ","
			<< pHead->sessions << ","
			<< pHead->final << ","
			<< pHead->midterm << ","
			<< pHead->other;
		if (pHead->pNext != nullptr)
			file << '\n';

		pHead = pHead->pNext;
	}
	file.close();
}

void print_Semester(Semester *pHead_Semester, string schoolYear_name)
{
	string path;
	ofstream file;
	file.open(schoolYear_name + "\\" + "semesterList.txt", ios::trunc);
	while (pHead_Semester != nullptr)
	{
		path = schoolYear_name + BACKSLASH + pHead_Semester->semester_name;
		file << pHead_Semester->semester_name << "," << pHead_Semester->start.day << "/" << pHead_Semester->start.month << "/" << pHead_Semester->start.year
			 << "," << pHead_Semester->end.day << "/" << pHead_Semester->end.month << "/" << pHead_Semester->end.year ;
		if (pHead_Semester->pNext != nullptr)
			file << endl;
		_mkdir(path.c_str());
		pHead_Semester = pHead_Semester->pNext;
	}
	file.close();
}

void print_output(SchoolYear *pHead_schoolYear, Class *pHead_class)
{
	////-------------------------------------------PRINTTT TO FILE------------------------------------------
	// Print schoolYear to schoolYearList.txt

	ofstream file;
	file.open("schoolYearlist.txt", ios::trunc);
	SchoolYear *pTemp1 = pHead_schoolYear;
	while (pHead_schoolYear != nullptr)
	{
		if (pHead_schoolYear->pNext != nullptr)
			file << pHead_schoolYear->year_name << endl;
		else
			file << pHead_schoolYear->year_name;
		_mkdir(pHead_schoolYear->year_name.c_str());
		pHead_schoolYear = pHead_schoolYear->pNext;
	}
	file.close();

	pHead_schoolYear = pTemp1;
	while (pHead_schoolYear != nullptr)
	{
		Semester *pCur_semester = pHead_schoolYear->semester;
		print_Semester(pCur_semester, pHead_schoolYear->year_name);
		while (pCur_semester != nullptr)
		{
			Course *pCur_course = pCur_semester->course;
			print_course(pCur_course, pHead_schoolYear->year_name, pCur_semester->semester_name);
			while (pCur_course != nullptr)
			{
				Student *pCur_student = pCur_course->student;
				print_student_InCourse(pCur_student, pHead_schoolYear->year_name, pCur_semester->semester_name, pCur_course->id);
				pCur_course = pCur_course->pNext;
			}
			pCur_semester = pCur_semester->pNext;
		}
		pHead_schoolYear = pHead_schoolYear->pNext;
	}

	////NO BUG IN THESE LINES OF CODE.
	file.open("classList.txt", ios::trunc);
	Class *pTemp9 = pHead_class;
	while (pHead_class != nullptr)
	{
		file << pHead_class->class_name;
		if (pHead_class->pNext != nullptr)
			file << endl;
		pHead_class = pHead_class->pNext;
	}
	file.close();

	pHead_class = pTemp9;
	while (pHead_class != nullptr)
	{
		// Print the elements of class.
		print_student_InClass(pHead_class->student, pHead_class->class_name);
		pHead_class = pHead_class->pNext;
	}

	///---------------------------------------------------PRINT TO CONSOLE---------------------------------------------
	/*SchoolYear* pHead1 = pHead_schoolYear;
	while (pHead1 != nullptr)
	{
		cout << pHead1->year_name << " ";
		Semester* pHead2 = pHead1->semester;
		while (pHead2 != nullptr)
		{
			cout << pHead2->semester_name << " ";
			Course* pHead3 = pHead2->course;
			while (pHead3!= nullptr)
			{
				cout << pHead3->course_name << " ";
				Student* pHead4 = pHead3->student;
				while (pHead4 != nullptr)
				{
					cout << endl;
					cout << pHead4->student_ID << " " << pHead4->first_name << " "
						<< pHead4->last_name << " " << pHead4->gender << " "
						<< pHead4->date_of_birth << " " << pHead4->social_ID << " "
						<< pHead4->score.total_mark << " " << pHead4->score.final_mark << " "
						<< pHead4->score.mid_mark << " " << pHead4->score.other_mark << endl;
					pHead4 = pHead4->pNext;
				}
				cout << endl;
				pHead3 = pHead3->pNext;
			}
			cout << endl;
			pHead2 = pHead2->pNext;
		}
		cout << endl;
		pHead1 = pHead1->pNext;
	}

	Class* pHead2 = pHead_class;
	while (pHead2 != nullptr)
	{
		cout << endl;
		cout << pHead2->class_name << " ";
		Student* pHead3 = pHead2->student;
		while (pHead3 != nullptr)
		{
			cout << endl;
			cout << pHead3->student_ID << " "
				<< pHead3->first_name << " "
				<< pHead3->last_name << " "
				<< pHead3->gender << " "
				<< pHead3->date_of_birth << " "
				<< pHead3->social_ID << endl;

			pHead3 = pHead3->pNext;
		}
		cout << endl;
		pHead2 = pHead2->pNext;
	}*/
}

void deallocated(SchoolYear *&pHead_schoolYear, Class *&pHead_class)
{
	// These line is used for deallocating all the students in all courses, and all courses in all semesters, and all semesters in all school years.B
	SchoolYear *pCur_schoolYear = pHead_schoolYear;
	while (pHead_schoolYear != nullptr)
	{
		Semester *pHead_semester = pCur_schoolYear->semester;
		Semester *pCur_semester = pHead_semester;
		if (pCur_semester == nullptr)
			break;
		while (pHead_semester != nullptr)
		{
			Course *pHead_course = pHead_semester->course;
			Course *pCur_course = pHead_course;
			if (pCur_course == nullptr)
				break;
			while (pHead_course != nullptr)
			{
				Student *pHead_student = pHead_course->student;
				Student *pCur_student = pHead_student;
				if (pCur_student == nullptr)
					break;
				while (pHead_student != nullptr)
				{
					pHead_student = pHead_student->pNext;
					delete pCur_student;
					pCur_student = pHead_student;
				}
				pHead_course = pHead_course->pNext;
				delete pCur_course;
				pCur_course = pHead_course;
			}
			pHead_semester = pHead_semester->pNext;
			delete pCur_semester;
			pCur_semester = pHead_semester;
		}
		pHead_schoolYear = pHead_schoolYear->pNext;
		delete pCur_schoolYear;
		pCur_schoolYear = pHead_schoolYear;
	}

	// These line is used for deallocating all the students in the courses, and all the courses.
	Class *pCur_class = pHead_class;
	while (pHead_class != nullptr)
	{
		studentClass *pTemp = pCur_class->student;
		studentClass *pPrevTemp = pCur_class->student;
		if (pTemp == nullptr)
			break;
		while (pTemp != nullptr)
		{
			pTemp = pTemp->pNext;
			delete pPrevTemp;
			pPrevTemp = pTemp;
		}
		pTemp = nullptr;
		pPrevTemp = nullptr;
		pHead_class = pHead_class->pNext;
		delete pCur_class;
		pCur_class = pHead_class;
	}
	pHead_class = nullptr;
	pCur_class = nullptr;
}