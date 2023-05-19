#include "lib.h"

int main()
{
	SchoolYear *pHead_schoolYear = nullptr;
	Class *pHead_class = nullptr;

	load_input(pHead_schoolYear, pHead_class);
	char type;
	string ID;
	passInfo *headPass = nullptr;
	ReadPassword(headPass, pHead_schoolYear, pHead_class);
	string temp;
	int option;
	BackGroundColor(7);
	SET_COLOR(0);
	while (true)
	{
		dialocatePass(headPass);
		clrscr();
		cout << "-----STUDENT MANAGE SYSTEM-----" << endl;	
		cout << "1. Sign in " << endl
			 << "2. Create an account" << endl
			 << "0. Exit" << endl;
		cout << "Your option: ";
		cin >> option;
		switch (option)
		{
		case 1:
		{
			login(type, ID, headPass);
			SET_COLOR(0);
			switch (type)
			{
			case 't':
			{
				// cout << "Hello World" << endl;
				menuStaff(pHead_schoolYear, pHead_class, headPass, ID);
				break;
			}
			case 's':
			{
				menuStudent(pHead_schoolYear, ID, headPass, ID);
				break;
			}
			// case 'm':
			// {
			// 	cout << "Type: Manager " << endl;
			// 	cout << "ID: " << ID << endl;
			// 	// menuManager(pHead_schoolYear, pHead_class, headPass);
				
			// 	1. Cho thêm bới thành viên staff và manager
			// 		Nhập từ console hoặc từ file
			// 			File staff.txt : ID,type
			// 		Xoa theo ID
			// 	2. Edit password
			// 		Cho phép edit password của bất cứ ai
			// 	3. Giống staff menu
				
			// 	break;
			// }
			default:
				break;
			}
			break;
		}
		case 2:
		{
			create_account(headPass);
			break;
		}
		case 0:
		{
			cout << "Thanks for choosing us...!";
			dialocatePass(headPass);
			clear(headPass);
			print_output(pHead_schoolYear, pHead_class);
			deallocated(pHead_schoolYear, pHead_class);
			return 0;
		}
		default:
			continue;
		}
	}
	return 0;
}
