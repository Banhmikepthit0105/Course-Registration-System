#include "lib.h"

bool checkSchoolYearSemIsFull(SchoolYear *currentSchoolYear)
{
    Semester *pCur = currentSchoolYear->semester;
    int count = 0;
    while (pCur != nullptr)
    {
        count++;
        pCur = pCur->pNext;
    }

    if (count == 3)
        return true;
    else
        return false;
}

void changeCurrentSchoolYear(SchoolYear *&currentSchoolYear, SchoolYear *pHead)
{
    string s;
    cout << "Enter School Year you need to work with: ";
    cin >> s;
    while (pHead != nullptr && pHead->year_name != s)
    {
        pHead = pHead->pNext;
    }
    if (pHead == nullptr)
    {
        cout << "There are no school year name '" << s << "' !" << endl;
        cout << "Press any key to continue..." << endl;
        cin >> s;
        return;
    }
    currentSchoolYear = pHead;
    cout << "Current school year has been changed !" << endl;
    cout << "Press any key to continue..." << endl;
    cin >> s;
}