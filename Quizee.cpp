#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;
void welcome()
{
    cout << "                  ";
    for (int i = 0; i < 30; i++)
    {
        cout << "= ";
    }
    cout << endl
         << endl;
    cout << "                                  ";
    cout << "Quizee : Online exam system";
    cout << endl
         << endl;
    cout << "                  ";
    for (int i = 0; i < 30; i++)
    {
        cout << "= ";
    }
    cout << endl
         << endl
         << endl;
    cout << "                                       ";
    cout << "Prepared by :" << endl;
    cout << "                                      ";
    cout << "Meharjot Singh" << endl;
    cout << "                                   ";
    cout << "Chitkara University" << endl;
    cout << endl
         << endl
         << endl
         << endl;
    cout << "Press any key to continue....";
    getchar();
    cout << endl
         << endl;
}
class loginpg
{
public:
    char done;
    char log, check, stutea;
    string username, pass, passcreate, passcreate1, user, st, roll;
    string num;
    loginpg()
    {
        cout << "Welcome to Quizee";
        cout << endl
             << "Press L for login and R for registering a new account: ";
        cin >> log;
        cout << endl
             << "Enter your details to continue: " << endl;
        if (log == 'L' || log == 'l')
        {
            login();
        }
        if (log == 'R' || log == 'r')
        {
            regi();
        }
    }
    void login()
    {
        int tellstte;
        cout << "Are you a student or teacher: " << endl
             << "Press 1 for Teacher" << endl
             << "Press 2 for Student" << endl;
        cin >> tellstte;
        if (tellstte == 2)
        {
            st = "student";
        }
        if (tellstte == 1)
        {
            st = "teacher";
        }
        if (st == "student" || st == "Student")
        {
            cout << endl
                 << "Enter your Roll number: ";
            cin >> roll;
            cout << endl
                 << "Enter your password: ";
            cin >> pass;
            ifstream file1, file2, file10;
            string line, line1;
            int count = 0;
            file1.open("studentroll.txt", ios::app);
            while (getline(file1, line))
            {
                count++;
                if (line == roll)
                {
                    string line10;
                    file10.open("studentuser.txt", ios::app);
                    int m1 = 0;
                    while (m1 < count)
                    {
                        m1++;
                        getline(file10, line10);
                    }
                    username = line10;
                    string line1;
                    file2.open("studentpass.txt", ios::app);
                    int m = 0;
                    while (m < count)
                    {
                        m++;
                        getline(file2, line1);
                    }
                    if (line1 == pass)
                    {

                        system("cls");
                        cout << endl
                             << "Welcome " << username << endl;
                        done = 'S';
                        break;
                    }
                    else
                    {
                        cout << endl
                             << "Password doesn't match. Try again" << endl;
                        login();
                    }
                    break;
                }
            }
        }
        if (st == "teacher" || st == "Teacher")
        {
            cout << endl
                 << "Enter your name: ";
            cin >> username;
            cout << endl
                 << "Enter your password: ";
            cin >> pass;

            if (st == "teacher" || st == "Teacher")
            {
                ifstream file1, file2;
                string line, line1;
                int count = 0;
                file1.open("teacheruser.txt");
                while (getline(file1, line))
                {
                    count++;
                    if (line == username)
                    {
                        string line1;
                        file2.open("teacherpass.txt", ios::app);
                        int m = 0;
                        while (m < count)
                        {
                            m++;
                            getline(file2, line1);
                        }
                        if (line1 == pass)
                        {
                            system("cls");
                            cout << endl
                                 << "Welcome " << username << endl;
                            done = 'T';
                            break;
                        }
                        else
                        {
                            cout << endl
                                 << "Password doesn't match. Try again" << endl;
                            login();
                        }
                        break;
                    }
                }
                if (line != username)
                {
                    cout << endl
                         << "Username not found. Please try again." << endl;
                    login();
                }
            }
        }
    }
    void regi()
    {
        int tellstte;
        cout << "Are you a student or teacher: " << endl
             << "Press 1 for Teacher" << endl
             << "Press 2 for Student" << endl;
        cin >> tellstte;
        if (tellstte == 2)
        {
            st = "student";
        }
        if (tellstte == 1)
        {
            st = "teacher";
        }
        if (st == "student" || st == "Student")
        {
            ifstream file2;
            string line2;
            int count1 = 0;
            cout << endl
                 << "Enter your roll number: ";
            cin >> num;
            file2.open("studentroll.txt");
            while (getline(file2, line2))
            {
                if (line2 == num)
                {
                    cout << endl
                         << "User already exists. Try loging in." << endl;
                    login();
                    break;
                }
                count1++;
            }
            cout << endl
                 << "Enter your name: ";
            cin >> user;
        }
        if (st == "teacher" || st == "Teacher")
        {
            cout << endl
                 << "Enter your contact number: ";
            cin >> num;
            cout << endl
                 << "Enter your name: ";
            cin >> user;
            ifstream file1;
            string line, line1;
            int count = 0;
            file1.open("teacheruser.txt");
            while (getline(file1, line))
            {
                count++;
                if (line == username)
                {
                    cout << endl
                         << "User already exists. Try loging in." << endl;
                    login();
                    break;
                }
            }
        }
        cout << endl
             << "Enter a password: ";
        cin >> passcreate;
        cout << endl
             << "Confirm your password: ";
        cin >> passcreate1;
        while (passcreate != passcreate1)
        {
            cout << endl
                 << "Enter matching passwords" << endl;
            cout << "Enter a password: ";
            cin >> passcreate;
            cout << endl
                 << "Confirm your password: ";
            cin >> passcreate1;
        }
        if (st == "teacher" || st == "Teacher")
        {
            detailste();
        }
        if (st == "student" || st == "Student")
        {
            detailsstu();
        }
    }
    void detailste()
    {
        cout << "Please check your details: " << endl;
        cout << "Type: " << st << endl;
        cout << "Contact number: " << num << endl
             << "Username: " << user << endl;
        cout << "Password: " << passcreate;
        cout << endl
             << "Press C to continue: ";
        cin >> check;
        if (check == 'R' || check == 'r')
        {
            regi();
        }
        if (check == 'C' || check == 'c')
        {
            cout << endl
                 << "Your account has been registered.";
            ofstream file, file1;
            file.open("teacheruser.txt", ios::app);
            file << user << endl;
            file.close();
            file1.open("teacherpass.txt", ios::app);
            file1 << passcreate << endl;
            file1.close();
            cout << endl
                 << "You are being redirected to login page." << endl;
            login();
        }
    }
    void detailsstu()
    {
        cout << "Please check your details: " << endl;
        cout << "Type: " << st << endl;
        cout << "Roll number: " << num << endl
             << "Username: " << user << endl;
        cout << "Password: " << passcreate;
        cout << endl
             << "Press C to continue: ";
        cin >> check;
        if (check == 'R' || check == 'r')
        {
            regi();
        }
        if (check == 'C' || check == 'c')
        {
            cout << endl
                 << "Your account has been registered.";
            ofstream file, file1, file2;
            file.open("studentuser.txt", ios::app);
            file << user << endl;
            file.close();
            file1.open("studentpass.txt", ios::app);
            file1 << passcreate << endl;
            file1.close();
            file2.open("studentroll.txt", ios::app);
            file2 << num << endl;
            file2.close();
            cout << endl
                 << "You are being redirected to login page." << endl;
            login();
        }
    }
};
class Teacher
{
public:
    int cred;
    string neg;
    char fun;
    char cont;
    string sub;
    Teacher()
    {
        cout << endl
             << "Welcome to teacher's portal for Quizee.";
        cout << endl
             << "Press S to set question paper" << endl
             << "Press C to check short answers" << endl
             << "Press R to read feedback of students" << endl
             << "Press D to see doubt of students" << endl
             << "Press M to display marks of students " << endl
             << "Press L to logout" << endl;
        cin >> fun;
        if (fun == 'S' || fun == 's')
        {
            Set();
        }
        if (fun == 'D' || fun == 'd')
        {
            read_doubt();
        }
        if (fun == 'r' || fun == 'R')
        {
            read_review();
        }
        if (fun == 'c' || fun == 'C')
        {
            check_short();
        }
        if (fun == 'M' || fun == 'm')
        {
            read_mark();
        }
    }
    void read_doubt()
    {
        string doubtre;
        cout << endl
             << "You can see doubt of students here: " << endl;
        ifstream doubt;
        doubt.open("doubts.txt", ios::app);
        while (getline(doubt, doubtre))
        {
            cout << doubtre << endl;
        }
        cin.ignore();
        cout << "Press enter to continue....";
        getchar();
        system("cls");
        Teacher();
    }
    void read_mark()
    {
        string markre1;
        ifstream mark1;
        mark1.open("marks.txt", ios::app);
        int couline = 0;
        while (getline(mark1, markre1))
        {
            couline++;
        }
        couline = couline / 4 - 1;
        string markre;
        cout << endl
             << "You can see marks of students here: " << endl;
        ifstream mark;
        mark.open("marks.txt", ios::app);
        for (int i = 0; i <= 55; i++)
        {
            cout << "= ";
        }
        cout << endl;
        cout << "  S.NO";
        cout << "  Student Name";
        cout << "             Test Name";
        cout << "             Test Type";
        cout << "             Marks Obtained";
        cout << "        Total Marks";
        cout << endl;
        for (int i = 0; i <= 55; i++)
        {
            cout << "= ";
        }
        cout << endl;
        int cou = 0;
        while (cou <= couline)
        {
            cou++;
            cout << "  " << cou;
            getline(mark, markre);
            cout << "     " << markre;
            getline(mark, markre);
            cout << "     " << markre;
            getline(mark, markre);
            cout << "               " << markre;
            getline(mark, markre);
            cout << "                        " << markre;
            getline(mark, markre);
            cout << "                    " << markre;
            cout << endl;
        }
        cin.ignore();
        cout << "Press enter to continue....";
        getchar();
        system("cls");
        Teacher();
    }
    void check_short()
    {
        int marks, inc, t_mark = 0;
        string ans_rea, namestud, rollstud, topic_name, re, name_s, name_short_store;
        ifstream file13, file14;
        file14.open("name_short.txt", ios::app);
        cout << endl
             << "The following students attempted Short Answer Questions: " << endl;
        while (getline(file14, re))
        {
            cout << re << endl;
        }
        cout << endl
             << "Enter the name of student whose answers you want to check: " << endl;
        cin >> name_s;
        name_short_store = name_s + "_short_check.txt";
        file13.open(name_short_store, ios::app);
        getline(file13, ans_rea);
        marks = stoi(ans_rea);
        while (getline(file13, ans_rea))
        {
            cout << "Question: " << endl
                 << ans_rea;
            cout << endl;
            getline(file13, ans_rea);
            cout << "Answer: " << endl
                 << ans_rea;
            cout << endl;
            cout << "Enter the marks you want to give for this answer out of " << marks << ": " << endl;
            cin >> inc;
            t_mark += inc;
        }
        ofstream file7;
        file7.open("marks.txt", ios::app);
        file7 << namestud << " ( " << rollstud << " )" << endl
              << topic_name << endl
              << "Short Answer" << endl
              << t_mark << endl;
        cout << "Press enter to continue....";
        getchar();
        system("cls");
        Teacher();
    }
    void Set()
    {
        int type_sub, test_do;
        string subt, name;
        cout << "Enter the topic on which you want to input practice questions for students: ";
        cin >> sub;
        subt = sub;
        sub = sub + ".txt";
        ofstream file2, file1, file;
        ifstream file3;
        string op1, op2, op3, op4, ans;
        file2.open(sub, ios::app);
        file1.open("name_test.txt", ios::app);
        file3.open("name_test.txt", ios::app);
        while (getline(file3, name))
        {
            if (name == subt)
            {
                break;
            }
        }
        if (name != subt)
        {
            file1 << subt << endl;
        }
        cout << "Enter the type of Questions you want to set for the test: " << endl;
        cout << "1. Objective" << endl;
        cout << "2. True/False" << endl;
        cout << "3. Short Answer" << endl;
        cin >> type_sub;
        if (type_sub == 1)
        {
            string rea, rea111;
            ifstream file4;
            file4.open(sub, ios::app);
            while (getline(file4, rea))
            {
                if (rea == "1. Objective")
                {
                    rea111 = rea;
                    break;
                }
            }
            if (rea111 == "Objective")
            {
                cout << "There is already an objective test for " << subt << "." << endl;
                cout << "Do you want to add questions to it or overwrite that test?" << endl;
                cout << "Press 1 for adding questions" << endl;
                cout << "Press 2 for overwriting the test" << endl;
                cin >> test_do;
                cin.ignore();
                if (test_do == 1)
                {
                    string fname;
                    fname = subt + "_objective.txt";
                    file.open(fname, ios::app);
                    string ques;
                    while (true)
                    {
                        cout << "Enter the question (Press Enter to end):";
                        getline(cin, ques);
                        if (ques.empty())
                            break;
                        file << ques << " ";
                        if (cont == 'n' || cont == 'N')
                        {
                            break;
                        }
                        cout << "Enter the first option: ";
                        cin >> op1;
                        cin.ignore();
                        file << endl
                             << "A: " << op1 << endl;
                        cout << "Enter the second option: ";
                        cin >> op2;
                        cin.ignore();
                        file << "B: " << op2 << endl;
                        cout << "Enter the third option: ";
                        cin >> op3;
                        cin.ignore();
                        file << "C: " << op3 << endl;
                        cout << "Enter the fourth option: ";
                        cin >> op4;
                        cin.ignore();
                        file << "D: " << op4 << endl;
                        cout << "Enter the correct option: ";
                        cin >> ans;
                        cin.ignore();
                        file << ans << endl;
                        cout << "Do you want to write another question?" << endl
                             << "Press Y to write and N to exit.";
                        cin >> cont;
                        cin.ignore();
                        if (cont == 'N' || cont == 'n')
                        {
                            break;
                        }
                    }
                    cin.ignore();
                    cout << endl
                         << "Your test has been created sucessfully." << endl;
                    cout << "Press enter to continue....";
                    getchar();
                    system("cls");
                    Teacher();
                }
                if (test_do == 1)
                {
                    string fname;
                    fname = subt + "_objective.txt";
                    remove(fname.c_str());
                    cout << endl
                         << "The old test has been deleted." << endl;
                    file.open(fname, ios::app);
                    cout << "Credit for each question: " << endl;
                    cin >> cred;
                    cin.ignore();
                    file << cred << endl;
                    cout << "Do you want to keep negative marking for the test: [yes/no]";
                    cin >> neg;
                    cin.ignore();
                    file << neg << endl;
                    cont = 'Y';
                    string ques;
                    while (true)
                    {
                        cin.ignore();
                        cout << "Enter the question (Press Enter to end):";
                        getline(cin, ques);
                        if (ques.empty())
                            break;
                        file << ques << " ";
                        if (cont == 'n' || cont == 'N')
                        {
                            break;
                        }
                        cout << "Enter the first option: ";
                        cin >> op1;
                        cin.ignore();
                        file << endl
                             << "A: " << op1 << endl;
                        cout << "Enter the second option: ";
                        cin >> op2;
                        cin.ignore();
                        file << "B: " << op2 << endl;
                        cout << "Enter the third option: ";
                        cin >> op3;
                        cin.ignore();
                        file << "C: " << op3 << endl;
                        cout << "Enter the fourth option: ";
                        cin >> op4;
                        cin.ignore();
                        file << "D: " << op4 << endl;
                        cout << "Enter the correct option: ";
                        cin >> ans;
                        cin.ignore();
                        file << ans << endl;
                        cout << "Do you want to write another question?" << endl
                             << "Press Y to write and N to exit.";
                        cin >> cont;
                        cin.ignore();
                        if (cont == 'N' || cont == 'n')
                        {
                            break;
                        }
                    }
                    cin.ignore();
                    cout << endl
                         << "Your test has been created sucessfully." << endl;
                    cout << "Press enter to continue....";
                    getchar();
                    system("cls");
                    Teacher();
                }
            }
            if (rea111 != "1. Objective")
            {
                file2 << "1. Objective" << endl;
                string fname;
                fname = subt + "_objective.txt";
                file.open(fname, ios::app);
                cout << "Credit for each question: " << endl;
                cin >> cred;
                cin.ignore();
                file << cred << endl;
                cout << "Do you want to keep negative marking for the test: [yes/no]";
                cin >> neg;
                cin.ignore();
                file << neg << endl;
                cont = 'Y';
                string ques;
                while (true)
                {
                    cout << "Enter the question (Press Enter to end):";
                    getline(cin, ques);
                    if (ques.empty())
                        break;
                    file << ques << " ";
                    if (cont == 'n' || cont == 'N')
                    {
                        break;
                    }
                    cout << "Enter the first option: ";
                    cin >> op1;
                    cin.ignore();
                    file << endl
                         << "A: " << op1 << endl;
                    cout << "Enter the second option: ";
                    cin >> op2;
                    cin.ignore();
                    file << "B: " << op2 << endl;
                    cout << "Enter the third option: ";
                    cin >> op3;
                    cin.ignore();
                    file << "C: " << op3 << endl;
                    cout << "Enter the fourth option: ";
                    cin >> op4;
                    cin.ignore();
                    file << "D: " << op4 << endl;
                    cout << "Enter the correct option: ";
                    cin >> ans;
                    cin.ignore();
                    file << ans << endl;
                    cout << "Do you want to write another question?" << endl
                         << "Press Y to write and N to exit.";
                    cin >> cont;
                    cin.ignore();
                    if (cont == 'N' || cont == 'n')
                    {
                        break;
                    }
                }
                cin.ignore();
                cout << endl
                     << "Your test has been created sucessfully." << endl;
                cout << "Press enter to continue....";
                getchar();
                system("cls");
                Teacher();
            }
        }
        if (type_sub == 2)
        {
            string rea, rea111;
            ifstream file4;
            file4.open(sub, ios::app);
            while (getline(file4, rea))
            {
                if (rea == "2. True/False")
                {
                    rea111 = rea;
                    break;
                }
            }
            if (rea111 == "2. True/False")
            {
                cout << "There is already an True/False test for " << subt << "." << endl;
                cout << "Do you want to add questions to it or overwrite that test?" << endl;
                cout << "Press 1 for adding questions" << endl;
                cout << "Press 2 for overwriting the test" << endl;
                cin >> test_do;
                cin.ignore();
                if (test_do == 1)
                {
                    string fname;
                    fname = subt + "_true.txt";
                    file.open(fname, ios::app);
                    string ques;
                    while (true)
                    {
                        cout << "Enter the question (Press Enter to end):";
                        getline(cin, ques);
                        if (ques.empty())
                            break;
                        file << ques << " ";
                        file << endl
                             << "A True" << endl
                             << "B False" << endl;
                        cout << "Enter the correct option: " << endl;
                        cin >> op1;
                        file << endl
                             << op1 << endl;
                        cin.ignore();
                        cout << "Do you want to write another question?" << endl
                             << "Press Y to write and N to exit.";
                        cin >> cont;
                        if (cont == 'N' || cont == 'n')
                        {
                            break;
                        }
                    }
                    cout << endl
                         << "Your test has been created sucessfully." << endl;
                    cout << "Press enter to continue....";
                    getchar();
                    system("cls");
                    Teacher();
                }
                if (test_do == 2)
                {
                    string fname;
                    fname = subt + "_true.txt";
                    cout << fname;
                    remove(fname.c_str());
                    cout << endl
                         << "The old test has been deleted." << endl;
                    file.open(fname, ios::app);
                    cout << "Enter credit for each question: " << endl;
                    cin >> cred;
                    cin.ignore();
                    file << cred << endl;
                    string ques;
                    while (true)
                    {
                        cin.ignore();
                        cout << "Enter the question (Press Enter to end):";
                        getline(cin, ques);
                        if (ques.empty())
                            break;
                        file << ques << " ";
                        file << endl
                             << "A True" << endl
                             << "B False" << endl;
                        cout << "Enter the correct option: " << endl;
                        cin >> op1;
                        file
                            << op1 << endl;
                        cin.ignore();
                        cout << "Do you want to write another question?" << endl
                             << "Press Y to write and N to exit.";
                        cin >> cont;
                        if (cont == 'N' || cont == 'n')
                        {
                            break;
                        }
                    }
                    cout << endl
                         << "Your test has been created sucessfully." << endl;
                    cout << "Press enter to continue....";
                    getchar();
                    system("cls");
                    Teacher();
                }
            }
            if (rea111 != "2. True/False")
            {
                file2 << "2. True/False" << endl;
                string fname;
                fname = subt + "_true.txt";
                file.open(fname, ios::app);
                cout << "Enter credit for each question: " << endl;
                cin >> cred;
                cin.ignore();
                file << cred << endl;
                string ques;
                while (true)
                {
                    cin.ignore();
                    cout << "Enter the question (Press Enter to end):";
                    getline(cin, ques);
                    if (ques.empty())
                        break;
                    file << ques << " ";
                    file << endl
                         << "A True" << endl
                         << "B False" << endl;
                    cout << "Enter the correct option: " << endl;
                    cin >> op1;
                    file
                        << op1 << endl;
                    cin.ignore();
                    cout << "Do you want to write another question?" << endl
                         << "Press Y to write and N to exit.";
                    cin >> cont;
                    if (cont == 'N' || cont == 'n')
                    {
                        break;
                    }
                }
                cout << endl
                     << "Your test has been created sucessfully." << endl;
                cout << "Press enter to continue....";
                getchar();
                system("cls");
                Teacher();
            }
        }
        if (type_sub == 3)
        {
            string rea, rea111;
            ifstream file4;
            file4.open(sub, ios::app);
            while (getline(file4, rea))
            {
                if (rea == "3. Short Answer")
                {
                    rea111 = rea;
                    break;
                }
            }
            if (rea111 == "3. Short Answer")
            {
                cout << "There is already an Short Answer test for " << subt << "." << endl;
                cout << "Do you want to add questions to it or overwrite that test?" << endl;
                cout << "Press 1 for adding questions" << endl;
                cout << "Press 2 for overwriting the test" << endl;
                cin >> test_do;
                cin.ignore();
                if (test_do == 1)
                {
                    string fname;
                    fname = subt + "_short.txt";
                    file.open(fname, ios::app);
                    string ques;
                    while (true)
                    {
                        cin.ignore();
                        cout << "Enter the question (Press Enter to end):";
                        getline(cin, ques);
                        if (ques.empty())
                            break;
                        file << ques << " ";
                        cout << "Do you want to write another question?" << endl
                             << "Press Y to write and N to exit.";
                        cin >> cont;
                        file << endl;
                        if (cont == 'N' || cont == 'n')
                        {
                            break;
                        }
                    }
                    cin.ignore();
                    cout << endl
                         << "Your test has been updated sucessfully." << endl;
                    cout << "Press enter to continue....";
                    getchar();
                    system("cls");
                    Teacher();
                }
                if (test_do == 2)
                {
                    string fname;
                    fname = subt + "_short.txt";
                    remove(fname.c_str());
                    cout << endl
                         << "The old test has been deleted." << endl;
                    file.open(fname, ios::app);
                    cout << "Enter credit for each question: " << endl;
                    cin >> cred;
                    cin.ignore();
                    file << cred << endl;
                    string ques;
                    while (true)
                    {
                        cin.ignore();
                        cout << "Enter the question (Press Enter to end):";
                        getline(cin, ques);
                        if (ques.empty())
                            break;
                        file << ques << " ";
                        cout << "Do you want to write another question?" << endl
                             << "Press Y to write and N to exit.";
                        cin >> cont;
                        file << endl;
                        if (cont == 'N' || cont == 'n')
                        {
                            break;
                        }
                    }
                    cin.ignore();
                    cout << endl
                         << "Your test has been created sucessfully." << endl;
                    cout << "Press enter to continue....";
                    getchar();
                    system("cls");
                    Teacher();
                }
            }
            if (rea111 != "3. Short Answer")
            {
                file2 << "3. Short Answer" << endl;
                string fname;
                fname = subt + "_short.txt";
                file.open(fname, ios::app);
                cout << "Enter credit for each question: " << endl;
                cin >> cred;
                cin.ignore();
                file << cred << endl;
                string ques;
                while (true)
                {
                    cin.ignore();
                    cout << "Enter the question (Press Enter to end):";
                    getline(cin, ques);
                    if (ques.empty())
                        break;
                    file << ques << " ";
                    cout << "Do you want to write another question?" << endl
                         << "Press Y to write and N to exit.";
                    cin >> cont;
                    if (cont == 'N' || cont == 'n')
                    {
                        break;
                    }
                }
                cout << endl
                     << "Your test has been created sucessfully." << endl;
                cout << "Press enter to continue....";
                getchar();
                system("cls");
                Teacher();
            }
        }
    }
    void read_review()
    {
        string revre;
        cout << endl
             << "You can read feedback of students here: " << endl;
        ifstream revi;
        revi.open("feedback.txt", ios::app);
        while (getline(revi, revre))
        {
            cout << revre << endl;
        }
        cin.ignore();
        cout << "Press enter to continue....";
        getchar();
        system("cls");
        Teacher();
    }
    void view_progress()
    {
        ifstream progress;
        string pro;
        progress.open("progress.txt", ios::app);
        while (getline(progress, pro))
        {
            cout << pro;
            cout << " has performed ";
            getline(progress, pro);
            cout << pro << " in tests.";
            cout << endl;
        }
        cin.ignore();
        cout << "Press enter to continue....";
        getchar();
        system("cls");
        Teacher();
    }
};
class Student
{
public:
    char fun;
    string namestud, rollstud;
    Student(string namestu, string rollstu)
    {
        rollstud = rollstu;
        namestud = namestu;
        cout << endl
             << "Welcome to students portal." << endl;
        cout << "Press T for giving tests" << endl
             << "Press D for sending doubts to your teacher" << endl
             << "Press M to see your scorecard" << endl
             << "Press L to logout" << endl;
        cin >> fun;
        if (fun == 'T' || fun == 't')
        {
            prac();
        }
        else if (fun == 'M' || fun == 'm')
        {
            view_mark();
        }
        else if (fun == 'D' || fun == 'd')
        {
            doubt();
        }
    }
    void prog()
    {
        string namestud = "Mehar", rollstud = "231";
        string search_name;
        search_name = namestud + " (" + rollstud + ")";
        ifstream file15;
        string r, markre;
        int mark_obt = 0, mark_tot = 0;
        cout << endl;
        file15.open("marks.txt", ios::app);
        int i = 0;
        while (getline(file15, r))
        {
            if (r == search_name)
            {
                getline(file15, markre);
                getline(file15, markre);
                getline(file15, markre);
                mark_obt += stof(markre);
                getline(file15, markre);
                mark_tot += stof(markre);
            }
        }
        float prog;
        prog = (mark_obt * 100) / mark_tot;
        cout << endl;
        ofstream progress;
        progress.open("progress.txt", ios::app);
        progress << namestud << " (" << rollstud << ")" << endl;
        if (prog < 20)
        {
            progress << "very bad";
        }
        else if (prog >= 20 && prog < 40)
        {
            progress << "bad";
        }
        else if (prog >= 40 && prog < 60)
        {
            progress << "moderate";
        }
        else if (prog >= 60 && prog < 80)
        {
            progress << "good";
        }
        else if (prog >= 80)
        {
            progress << "very good";
        }
        cout << "Press enter to continue....";
        getchar();
        system("cls");
        Student stude(namestud, rollstud);
    }
    void view_mark()
    {
        string namestud = "Mehar", rollstud = "231";
        string search_name;
        search_name = namestud + " (" + rollstud + ")";
        ifstream file15;
        string r, markre;
        for (int i = 0; i <= 55; i++)
        {
            cout << "= ";
        }
        cout << endl;
        cout << "  S.NO";
        cout << "               Test Name";
        cout << "               Test Type";
        cout << "               Marks Obtained";
        cout << "               Total Marks";
        cout << endl;
        for (int i = 0; i <= 55; i++)
        {
            cout << "= ";
        }
        cout << endl;
        file15.open("marks.txt", ios::app);
        int i = 0;
        while (getline(file15, r))
        {
            if (r == search_name)
            {
                i++;
                cout << "  " << i;
                getline(file15, markre);
                cout << "                  " << markre;
                getline(file15, markre);
                cout << "                    " << markre;
                getline(file15, markre);
                cout << "                   " << markre;
                getline(file15, markre);
                cout << "                           " << markre;
                cout << endl;
            }
        }
        cout << "Press enter to continue....";
        getchar();
        system("cls");
        Student stude(namestud, rollstud);
    }
    void prac()
    {
        ifstream file, file1, file2;
        int inc, dec, ty;
        file.open("name_test.txt", ios::app);
        string line, topic, read, line1, ans;
        string doub;
        char cor_op, op, cor_op1;
        cout << "Choose the topic on which you want to give the test: " << endl;
        int i = 1;
        while (getline(file, line))
        {
            cout << i << ": " << line << endl;
            i++;
        }
        cout << "Enter the topic on which you want to practice questions: ";
        cin >> topic;
        string topic_name = topic, type_test_stu, topic_type, topic_store;
        topic_store = topic;
        topic = topic + ".txt";
        file2.open(topic, ios::app);
        cout << endl
             << "The type of questions that you can attempt are listed below" << endl;
        while (getline(file2, type_test_stu))
        {
            cout << type_test_stu << endl;
        }
        cout << endl
             << "Enter the type of questions you want to practice: [1/2/3]" << endl;
        cin >> ty;
        if (ty == 1)
        {
            int marks = 0, tmarks = 0;
            topic_store = topic_store + "_objective.txt";
            file1.open(topic_store, ios::app);
            getline(file1, read);
            inc = stoi(read);
            getline(file1, read);
            if (read == "Yes" || read == "yes")
            {
                dec = -1;
            }
            else
            {
                dec = 0;
            }
            int number_line = 0;
            char correctAnswer;
            while (getline(file1, line1))
            {
                cout << line1 << endl;
                getline(file1, read);
                cout << read << endl;
                getline(file1, read);
                cout << read << endl;
                getline(file1, read);
                cout << read << endl;
                getline(file1, read);
                cout << read << endl;
                getline(file1, read);
                cin >> op;
                cor_op = read[0];
                char line = read[0];
                int num;
                if (int(line) > 96)
                {
                    num = int(line) - 32;
                }
                if (int(line) < 96)
                {
                    num = int(line) + 32;
                }
                if (op == cor_op || op == char(num))
                {
                    marks = marks + inc;
                }
                else
                {
                    marks = marks + dec;
                }
                tmarks = tmarks + inc;
            }
            cout << "You scored " << marks << " marks in test." << endl;
            ofstream file7;
            file7.open("marks.txt", ios::app);
            file7 << namestud << " ( " << rollstud << " )" << endl
                  << topic_name << endl
                  << "Objective" << endl
                  << marks << endl
                  << tmarks << endl;
        }
        if (ty == 2)
        {
            int marks = 0, tmarks = 0;
            topic_store = topic_store + "_true.txt";
            file1.open(topic_store, ios::app);
            getline(file1, read);
            inc = stoi(read);
            while (getline(file1, line1))
            {
                cout << line1 << endl;
                getline(file1, read);
                cout << read << endl;
                getline(file1, read);
                cout << read << endl;
                getline(file1, read);
                cin >> op;
                cor_op = read[0];
                char line = read[0];
                int num;
                if (int(line) > 96)
                {
                    num = int(line) - 32;
                }
                if (int(line) < 96)
                {
                    num = int(line) + 32;
                }
                if (op == char(num))
                {
                    marks = marks + inc;
                }
                tmarks = tmarks + inc;
                cout << "You scored " << marks << " marks in test." << endl;
            }
            ofstream file7;
            file7.open("marks.txt", ios::app);
            file7 << namestud << " ( " << rollstud << " )" << endl
                  << topic_name << endl
                  << "True/False" << endl
                  << marks << endl
                  << tmarks << endl;
        }
        if (ty == 3)
        {
            string name_short_store;
            int marks = 0, tmarks = 0;
            topic_store = topic_store + "_short.txt";
            file1.open(topic_store, ios::app);
            getline(file1, read);
            inc = stoi(read);
            ofstream file11, file12;
            name_short_store = namestud;
            name_short_store = name_short_store + "_short_check.txt";
            file11.open(name_short_store, ios::app);
            file11 << inc << endl;
            file12.open("name_short.txt", ios::app);
            file12 << namestud;
            while (getline(file1, line1))
            {
                file11 << line1 << " ";
                cout << line1 << endl;
                file11<<endl;
                cout << "Enter the Answer (Press Enter to end):";
                cin.ignore();
                getline(cin, line1);
                if (line1.empty())
                    break;
                file11 << line1 << " ";
            }
            file11 << endl;
        }
        ifstream file4, file5, file8;
        ofstream file3, file6;
        string name_test_mark;
        file6.open("test_name_marks.txt", ios::app);
        file4.open("name_test.txt", ios::app);
        file6 << name_test_mark << endl;
        prog();
        cout << "Do you have any doubts? [Yes/No]";
        cin >> doub;
        if (doub == "Yes" || doub == "yes")
        {
            doubt();
        }
        else
        {
            cout << endl
                 << "You are being redirected to feedback section: ";
            feedback();
        }
    }
    void doubt()
    {
        cin.ignore();
        ofstream doubt;
        string dou;
        doubt.open("doubts.txt", ios::app);
        doubt << namestud << " ( " << rollstud << " ) : ";
        cout << "You can write your doubts here: (Press Enter to end)";
        getline(cin, dou);
        doubt << dou << " ";
        doubt << endl;
        cout << endl
             << "You are being redirected to feedback section: ";
        feedback();
    }
    void feedback()
    {
        ofstream feedback;
        string feed;
        feedback.open("feedback.txt", ios::app);
        feedback << namestud << " ( " << rollstud << " ) : ";
        cout << endl
             << "You can write your feedback here: (Press Enter to end)" << endl;
        getline(cin, feed);
        feedback << feed << " ";
        feedback << endl;
        cout << endl
             << "Thank you for your feedback. We are redirecting you to home page.";
        Student stude(namestud, rollstud);
    }
};
void infi_log_loop()
{
    loginpg l;
    if (l.done == 'S')
    {
        Student stu(l.username, l.roll);
    }
    if (l.done == 'T')
    {
        Teacher te;
    }
}
int main()
{
    string tell;
    welcome();
    infi_log_loop();
    while (true)
    {
        cout << "Do you wish to continue further? [yes/no] " << endl;
        cin >> tell;
        if (tell == "yes" || tell == "Yes")
        {
            system("cls");
            infi_log_loop();
        }
        else
        {
            break;
        }
    }
}