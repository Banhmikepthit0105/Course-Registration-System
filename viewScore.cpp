// The work below use for task 20-21-22-23
#include "lib.h"

// This function use to import score for ONE COURSE
// This function use parameter as A Linked List Course 
// pls read comment inside function.


void viewScore (Course *course)
{
    cout << "Course information: " << endl;
    cout << course->id << "  " << course->course_name << endl;
    cout << course->class_name << endl;
    cout << "Here is scoreboard of this course: " << endl;
    Student *s = course->student;
    while (s != nullptr) {
        cout << "Student id: " << s->student_ID << "\t" << s->last_name << " " << s->first_name << endl;
        cout << "Midterm mark:" << s->score.mid_mark << endl;
        cout << "Final mark:" << s->score.final_mark << endl;
        cout << "Other mark:" << s->score.other_mark << endl;
        cout << "Total mark is: " << s->score.total_mark << endl;
        cout << endl;
    }
}

void updateScoreForStudent (Course  *course)
{
    Student *s = course->student;
    string temp;
    cout << "Enter student id need to update the result: " ;
    cin >> temp;
    while (s != nullptr) {
        if (s->student_ID == temp) break;
        else s = s->pNext;
    }
    if (s == nullptr) {
        cout << "There are no student got this ID !!!";
        return;
    }
    cout << "Now enter the updated result of the student ID " << temp << " : " << endl;
    cout << "Midterm mark:"; cin >> s->score.mid_mark;
    cout << "Final mark:"; cin >> s->score.final_mark;//
    cout << "Other mark:"; cin >> s->score.other_mark;
}
