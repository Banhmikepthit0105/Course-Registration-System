#include "lib.h"

void view_list_all_courses(SchoolYear *pHead_schoolYear, string student_ID)
{
	Semester *pCur_view_courses_semester = Find_Semester(pHead_schoolYear);
	if (pCur_view_courses_semester != nullptr)
	{
		Course *pHead_view_courses_courses = pCur_view_courses_semester->course;
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
			<< setw(15)
			<< "Session|" << endl;

		while (pHead_view_courses_courses != nullptr)
		{
			Student *pHead_student = pHead_view_courses_courses->student;
			while (pHead_student != nullptr)
			{
				if (pHead_student->student_ID == student_ID)
				{
					cout
						<< left
						<< setw(15)
						<< pHead_view_courses_courses->id
						<< left
						<< setw(15)
						<< pHead_view_courses_courses->course_name
						<< left
						<< setw(20)
						<< pHead_view_courses_courses->class_name
						<< left
						<< setw(15)
						<< pHead_view_courses_courses->teacher_name
						<< left
						<< setw(20)
						<< pHead_view_courses_courses->number_credits
						<< left
						<< setw(27)
						<< pHead_view_courses_courses->number_students
						<< left
						<< setw(17)
						<< pHead_view_courses_courses->day_of_week
						<< setw(15)
						<< pHead_view_courses_courses->sessions;
					cout << endl;
				}
				pHead_student = pHead_student->pNext;
			}
			pHead_view_courses_courses = pHead_view_courses_courses->pNext;
		}
		string s;
		cout << "Press any key to continue...";
		cin >> s;
	}
}

void view_list_all_scoreboard(SchoolYear *pHead_schoolYear, string student_ID)
{
	cout
		<< left
		<< setw(15)
		<< "Course ID| "
		<< left
		<< setw(15)
		<< "Course Name| "
		<< left
		<< setw(15)
		<< "Teacher Name| "
		<< left
		<< setw(20)
		<< "Number of credits| "
		<< left
		<< setw(17)
		<< "Day of the week| "
		<< left
		<< setw(15)
		<< "Session| "
		<< left
		<< setw(15)
		<< "Total mark| "
		<< left
		<< setw(15)
		<< "Final mark| "
		<< left
		<< setw(15)
		<< "Mid mark| "
		<< left
		<< setw(15)
		<< "Other mark| ";
	cout << endl;

	while (pHead_schoolYear != nullptr)
	{
		Semester *pHead2 = pHead_schoolYear->semester;
		while (pHead2 != nullptr)
		{
			Course *pHead3 = pHead2->course;
			while (pHead3 != nullptr)
			{
				Student *pHead4 = pHead3->student;
				while (pHead4 != nullptr)
				{
					int s = 0;
					if (pHead4->student_ID == student_ID)
					{
						cout
							<< left
							<< setw(15)
							<< pHead3->id
							<< left
							<< setw(15)
							<< pHead3->course_name
							<< left
							<< setw(15)
							<< pHead3->teacher_name
							<< left
							<< setw(20)
							<< pHead3->number_credits
							<< left
							<< setw(17)
							<< pHead3->day_of_week
							<< left
							<< setw(15)
							<< pHead3->sessions
							<< left
							<< setw(15)
							<< pHead4->score.total_mark
							<< left
							<< setw(15)
							<< pHead4->score.final_mark
							<< left
							<< setw(15)
							<< pHead4->score.mid_mark
							<< left
							<< setw(15)
							<< pHead4->score.other_mark;
						cout << endl;
					}
					pHead4 = pHead4->pNext;
				}
				pHead3 = pHead3->pNext;
			}
			pHead2 = pHead2->pNext;
		}
		pHead_schoolYear = pHead_schoolYear->pNext;
	}
}

void menuStudent(SchoolYear *pHead_schoolYear, string student_ID, passInfo *&headPass, string login)
{ //
	int i;
	while (true)
	{
		dialocatePass(headPass);
		clrscr();
		cout << "Type: Student " << endl;
		cout << "Login ID: " << login << endl;
		cout << "-----------------------------------------------------------------------------\n";
		cout << "1. View the courses in semester.\n2. View scoreboard.\n3. Change password.";
		cout << "\n0. Log out";
		cout << " \nEnter options:";
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
			view_list_all_courses(pHead_schoolYear, student_ID);
			break;
		}
		case 2:
		{
			view_list_all_scoreboard(pHead_schoolYear, student_ID);
			string s;
			cout << "Press any key to continue...";
			cin >> s;
			break;
		}
		case 3:
		{
			edit(headPass, login);
			string s;
			cout << "Press any key to continue...";
			cin >> s;
			break;
		}
		default:
			continue;
		}
	}
}