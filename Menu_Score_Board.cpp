#include "lib.h"

void view_scoreboard_toCourse(SchoolYear *list_year)
{
	SchoolYear *pCur = list_year;
	Semester *View_Semester = nullptr;
	View_Semester = pCur->semester;
	SET_COLOR(13);
	if(pCur->semester==nullptr) {
		string temp;
		cout<<"There are no Semesters yet"<<endl;
		cout << "Press any key to continue...";
		cin >> temp;
		return;
	}
	cout << "List of Semesters in " << pCur->year_name << " :" << endl;
	while (View_Semester != nullptr)
	{
		SET_COLOR(13);
		cout << "+) ";
		SET_COLOR(4);
		cout << View_Semester->semester_name << "\n";
		View_Semester = View_Semester->pNext;
	}
	SET_COLOR(13);
	Semester *Cur_Semester = nullptr;
	string Semester;
	cout << "Enter Semester: ";
	SET_COLOR(4);
	cin >> Semester;
	Cur_Semester = pCur->semester;
	while (Cur_Semester->semester_name != Semester)
	{
		Cur_Semester = Cur_Semester->pNext;
		if (Cur_Semester == nullptr)
		{
			clrscr();
			cout << "Semester: " << Semester << " is not over yet\n";
			string temp;
			cout << "Press any key to continue...";
			cin >> temp;
			return;
		}
	}
	if (Cur_Semester->semester_name != Semester)
	{
		clrscr();
		cout << "Semester: " << Semester << " is not over yet\n";
		string temp;
		cout << "Press any key to continue...";
		cin >> temp;
		return;
	}
	clrscr();
	Course *Cur_course = nullptr;
	Course *View_course = nullptr;
	View_course = Cur_Semester->course;
	SET_COLOR(13);
	if(Cur_Semester->course==nullptr) {
		string temp;
		cout<<"There are no Course yet"<<endl;
		cout << "Press any key to continue...";
		cin >> temp;
		return;
	}
	cout << "List of courses in " << Cur_Semester->semester_name << " :" << endl;
	while (View_course != nullptr)
	{
		SET_COLOR(13);
		cout << "+) ";
		SET_COLOR(4);
		cout << View_course->course_name;
		SET_COLOR(13);
		cout << " ID: ";
		SET_COLOR(4);
		cout << View_course->id << " \n";
		View_course = View_course->pNext;
	}
	string Course;
	SET_COLOR(13);
	cout << "Enter ID Course: ";
	SET_COLOR(4);
	cin >> Course;
	Cur_course = Cur_Semester->course;
	while (Cur_course->id.compare(Course) != 0)
	{
		if (Cur_course->pNext == nullptr)
		{
			clrscr();
			cout << "Course: " << Course << " is not over yet\n";
			return;
		}
		Cur_course = Cur_course->pNext;
	}
	Student *studentF = nullptr;
	studentF = Cur_course->student;
	SET_COLOR(5);
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
		 << "Social ID| "
		 << left
		 << setw(9)
		 << "Total mark| "
		 << left
		 << setw(9)
		 << "Final mark|"
		 << left
		 << setw(13)
		 << "Midterm mark|"
		 << left
		 << setw(13)
		 << "Other mark|"
		 << endl;
	cout << setfill('-');
	cout << setw(125) << '-' << endl;
	cout << setfill(' ');
	SET_COLOR(4);
	while (studentF != nullptr)
	{
		cout
			<< left
			<< setw(13)
			<< studentF->student_ID << " "
			<< left
			<< setw(13)
			<< studentF->first_name << " "
			<< left
			<< setw(13)
			<< studentF->last_name << " "
			<< left
			<< setw(13)
			<< studentF->gender << " "
			<< left
			<< setw(13)
			<< studentF->date_of_birth << " "
			<< left
			<< setw(13)
			<< studentF->social_ID << " "
			<< left
			<< setw(9)
			<< studentF->score.total_mark << " "
			<< left
			<< setw(9)
			<< studentF->score.final_mark << " "
			<< left
			<< setw(13)
			<< studentF->score.mid_mark << " "
			<< left
			<< setw(13)
			<< studentF->score.other_mark << endl;
		studentF = studentF->pNext;
	}
	cout << "Press any key to continue...";
	string s;
	cin >> s;
}

void import_score_of_course(Course *pCur_course)
{
	SET_COLOR(0);
	cout << "COURSE INFORMATION" << endl;
	cout << "Course ID: ";
	cout << pCur_course->id << endl;
	cout << "Course name: ";
	cout << pCur_course->course_name << endl;
	cout << "Class name: ";
	cout << pCur_course->class_name << endl;
	cout << "Number of credits: ";
	cout << pCur_course->number_credits << endl;
	cout << "Number of students: ";
	cout << pCur_course->number_students << endl;
	cout << "Teacher name: ";
	cout << pCur_course->teacher_name << endl;
	cout << "Day of week: ";
	cout << pCur_course->day_of_week << endl;
	cout << "Sesssion: ";
	cout << pCur_course->sessions << endl;
	cout << "Percentage of Final mark: ";
	cout << pCur_course->final << endl;
	cout << "Percentage of Midterm mark: ";
	cout << pCur_course->midterm << endl;
	cout << "Percentage of Other mark: ";
	cout << pCur_course->other << endl;
	cout << "Import score for each students" << endl;
	Student *pStudent = pCur_course->student; // from now just use branch Student of this Course
	while (pStudent != nullptr)
	{//
		SET_COLOR(13);
		cout << "Student Information: ";
		SET_COLOR(4);
		cout << pStudent->student_ID << " " << pStudent->first_name << " " << pStudent->last_name << " " << pStudent->gender << " " << pStudent->date_of_birth << " " << pStudent->social_ID << endl;
		SET_COLOR(13);
		cout << "Midterm mark: ";
		SET_COLOR(4);
		cin >> pStudent->score.mid_mark;
		while (pStudent->score.mid_mark < 0 || pStudent->score.mid_mark > 10)
		{
			cout << "Invalid mark! Try again" << endl;
			SET_COLOR(13);
			cout << "Midterm mark: ";
			SET_COLOR(4);
			cin >> pStudent->score.mid_mark;
		}
		SET_COLOR(13);
		cout << "Final mark: ";
		SET_COLOR(4);
		cin >> pStudent->score.final_mark;
		while (pStudent->score.final_mark < 0 || pStudent->score.final_mark > 10)
		{
			cout << "Invalid mark! Try again" << endl;
			SET_COLOR(13);
			cout << "Final mark: ";
			SET_COLOR(4);
			cin >> pStudent->score.final_mark;
		}
		SET_COLOR(13);
		cout << "Other mark: ";
		SET_COLOR(4);
		cin >> pStudent->score.other_mark;
		while (pStudent->score.other_mark < 0 || pStudent->score.other_mark > 10)
		{
			cout << "Invalid mark! Try again" << endl;
			SET_COLOR(13);
			cout << "Other mark: ";
			SET_COLOR(4);
			cin >> pStudent->score.other_mark;
		}
		SET_COLOR(13);
		// just assume the logic math calculate, staff can fix it
		float f = pStudent->score.final_mark * pCur_course->final / 100;
		float m = pStudent->score.mid_mark * pCur_course->midterm / 100;
		float o = pStudent->score.other_mark * pCur_course->other / 100;
		pStudent->score.total_mark = float_one_point_round(f + m + o);
		SET_COLOR(13);
		cout << "Total mark is: ";
		SET_COLOR(4);
		cout << pStudent->score.total_mark << endl;
		pStudent = pStudent->pNext;
	}
	cout << "Press any key to continue...";
	string temp;
	cin >> temp;
}

void Menu_Score_Board(SchoolYear *list_year)
{
	string option;
	while (true)
	{
		clrscr();
		SET_COLOR(0);
		cout << "Enter 1: =Get File ScoreBoard= \t   Enter 2: =Enter by keyboard=\t  Enter 3: = View Score = \t   =Enter 0: Quit=\n";
		cin >> option;
		SchoolYear *pCur = list_year;
		string yes;
		if (option == "1")
		{
			do
			{
				Semester *View_Semester = nullptr;
				View_Semester = pCur->semester;
				SET_COLOR(13);
				if(pCur->semester==nullptr) {
					string temp;
					cout<<"There are no Semesters yet"<<endl;
					cout << "Press any key to continue...";
					cin >> temp;
					return;
				}
				cout << "List of Semester in " << pCur->year_name << ":" << endl;
				while (View_Semester != nullptr)
				{
					SET_COLOR(13);
					cout << "+) ";
					SET_COLOR(4);
					cout << View_Semester->semester_name << "\n";
					View_Semester = View_Semester->pNext;
				}
				SET_COLOR(13);
				Semester *Cur_Semester = nullptr;
				string Semester;
				cout << "Enter Semester: ";
				SET_COLOR(4);
				cin >> Semester;
				Cur_Semester = pCur->semester;
				bool flag = false;
				while (Cur_Semester->semester_name.compare(Semester) != 0)
				{
					if (Cur_Semester->pNext == nullptr)
					{
						flag = true;
						break;
					}
					Cur_Semester = Cur_Semester->pNext;
				}
				if (flag)
				{
					clrscr();
					cout << "Semester: " << Semester << " is not over yet\n";
					string temp;
					cout << "Press any key to continue...";
					cin >> temp;
					break;
				}
				clrscr();
				Course *Cur_course = nullptr;
				Course *View_course = nullptr;
				View_course = Cur_Semester->course;
				SET_COLOR(13);
				if(Cur_Semester->course==nullptr) {
				string temp;
				cout<<"There are no Course yet"<<endl;
				cout << "Press any key to continue...";
				cin >> temp;
				return;
				}
				cout << "List of courses in " << Cur_Semester->semester_name << ": " << endl;
				while (View_course != nullptr)
				{
					SET_COLOR(13);
					cout << "+) ";
					SET_COLOR(4);
					cout << View_course->course_name;
					SET_COLOR(13);
					cout << " ID: ";
					SET_COLOR(4);
					cout << View_course->id << " \n";
					View_course = View_course->pNext;
				}
				string Course;
				SET_COLOR(13);
				cout << "Enter ID Course: ";
				SET_COLOR(4);
				cin >> Course;
				Cur_course = Cur_Semester->course;
				while (Cur_course->id.compare(Course) != 0)
				{
					if (Cur_course->pNext == nullptr)
					{
						flag = true;
						break;
					}
					Cur_course = Cur_course->pNext;
				}
				if (flag)
				{
					clrscr();
					cout << "Course: " << Course << " is not over yet\n";
					string temp;
					cout << "Press any key to continue...";
					cin >> temp;
					break;
				}
				ofstream F;
				F.open("import_scoreboard.txt", ios::trunc);
				Student *studentF = nullptr;
				studentF = Cur_course->student;
				while (studentF != nullptr)
				{
					F << studentF->student_ID << "," << studentF->first_name << "," << studentF->last_name << "," << studentF->gender << "," << studentF->date_of_birth << "," << studentF->social_ID << ","
					  << studentF->score.total_mark << "," << studentF->score.final_mark << "," << studentF->score.mid_mark << "," << studentF->score.other_mark;
					if (studentF->pNext != nullptr)
						F << "\n";
					studentF = studentF->pNext;
				}
				F.close();
				SET_COLOR(13);
				cout << "Created a file containing the information of the course: ";
				SET_COLOR(4);
				cout << Cur_course->id;
				SET_COLOR(13);
				cout << " , Please enter your score into the file (enter 0 = agree): ";
				SET_COLOR(4);
				cin >> yes;
				if (yes != "0")
				{
					cout << "Press any key to continue...";
					string s;
					cin >> s;
					// remove("import_scoreboard.txt");
					continue;
				}
				else
				{
					ifstream outF;
					outF.open("import_scoreboard.txt");
					string tmp;
					Student *score = Cur_course->student;
					while (!outF.eof())
					{
						getline(outF, tmp, ',');
						getline(outF, tmp, ',');
						getline(outF, tmp, ',');
						getline(outF, tmp, ',');
						getline(outF, tmp, ',');
						getline(outF, tmp, ',');
						getline(outF, tmp, ',');

						string get_final_score;
						getline(outF, get_final_score, ',');
						score->score.final_mark = stof(get_final_score);

						string get_mid_score;
						getline(outF, get_mid_score, ',');
						score->score.mid_mark = stof(get_mid_score);

						string get_other_score;
						getline(outF, get_other_score);
						score->score.other_mark = stof(get_other_score);

						if (score->score.mid_mark <= 10 && score->score.final_mark <= 10 && score->score.other_mark <= 10)
						{
							float f = score->score.final_mark * Cur_course->final / 100;
							float m = score->score.mid_mark * Cur_course->midterm / 100;
							float o = score->score.other_mark * Cur_course->other / 100;
							score->score.total_mark = float_one_point_round(f + m + o);
						}
						score = score->pNext;
						// else
						// {
						// 	cout << "Course score entry failed!\n";
						// 	yes = "0";
						// 	// remove("import_scoreboard.txt");
						// 	break;
						// }
					}
					outF.close();
					//  remove("import_scoreboard.txt");
				}
			} while (yes != "1");
		}
		else if (option == "2")
		{
			bool flag = false;
			while (!flag)
			{
				Semester *View_Semester = nullptr;
				View_Semester = pCur->semester;
				SET_COLOR(13);
				if(pCur->semester==nullptr) {
				string temp;
				cout<<"There are no Semesters yet"<<endl;
				cout << "Press any key to continue...";
				cin >> temp;
				return;
			}
				cout << "List of Semesters in " << pCur->year_name << " :" << endl;
				while (View_Semester != nullptr)
				{
					SET_COLOR(13);
					cout << "+) ";
					SET_COLOR(4);
					cout << View_Semester->semester_name << "\n";
					View_Semester = View_Semester->pNext;
				}
				SET_COLOR(13);
				Semester *Cur_Semester = nullptr;
				string Semester;
				cout << "Enter Semester: ";
				SET_COLOR(4);
				cin >> Semester;
				Cur_Semester = pCur->semester;
				while (Cur_Semester->semester_name.compare(Semester) != 0)
				{
					if (Cur_Semester->pNext == nullptr)
					{
						flag = true;
						break;
					}
					Cur_Semester = Cur_Semester->pNext;
				}
				if (flag)
				{
					clrscr();
					cout << "Semester: " << Semester << " is not over yet\n";
					string s;
					cout << "Press any key to continue...";
					cin >> s;
					break;
				}
				cout << Cur_Semester->course->course_name;
				Course *Cur_course = nullptr;
				clrscr();
				Course *View_course = nullptr;
				View_course = Cur_Semester->course;
				SET_COLOR(13);
				if(Cur_Semester->course==nullptr) {
				string temp;
				cout<<"There are no Course yet"<<endl;
				cout << "Press any key to continue...";
				cin >> temp;
				return;
			}
				cout << "List of courses in " << Cur_Semester->semester_name << " :" << endl;
				while (View_course != nullptr)
				{
					SET_COLOR(13);
					cout << "+) ";
					SET_COLOR(4);
					cout << View_course->course_name;
					SET_COLOR(13);
					cout << " ID: ";
					SET_COLOR(4);
					cout << View_course->id << " \n";
					View_course = View_course->pNext;
				}
				SET_COLOR(13);
				string Course;
				cout << "Enter ID Course: ";
				SET_COLOR(4);
				cin >> Course;
				Cur_course = Cur_Semester->course;
				while (Cur_course->id.compare(Course) != 0)
				{
					if (Cur_course->pNext == nullptr)
					{
						flag = true;
						break;
					}
					Cur_course = Cur_course->pNext;
				}
				if (flag)
				{
					clrscr();
					cout << "Course: " << Course << " is not over yet\n";
					string s;
					cout << "Press any key to continue...";
					cin >> s;
					break;
				}
				import_score_of_course(Cur_course);
				flag = true;
			}
			clrscr();
		}
		else if (option == "3")
		{
			view_scoreboard_toCourse(list_year);
		}
		else if (option == "0")
		{
			return;
		}
		else
		{
			continue;
		}
	}
}
