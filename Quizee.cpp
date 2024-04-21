#include <iostream>
#include <fstream>
#include <string>
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
        couline = couline / 3 - 1;
        string markre;
        cout << endl
             << "You can see marks of students here: " << endl;
        ifstream mark;
        mark.open("marks.txt", ios::app);
        for (int i = 0; i < 45; i++)
        {
            cout << "= ";
        }
        cout << endl;
        cout << "    S.NO";
        cout << "    Student Name";
        cout << "                  Test Name";
        cout << "                  Marks Obtained";
        cout << endl;
        for (int i = 0; i < 45; i++)
        {
            cout << "= ";
        }
        cout << endl;
        int cou = 0;
        while (cou <= couline)
        {
            cou++;
            cout << "    " << cou;
            getline(mark, markre);
            cout << "       " << markre;
            getline(mark, markre);
            cout << "               " << markre;
            getline(mark, markre);
            cout << "                           " << markre;
            cout << endl;
        }
        cin.ignore();
        cout << "Press enter to continue....";
        getchar();
        system("cls");
        Teacher();
    }
    void Set()
    {
        int cred;
        string neg;
        char fun;
        char cont;
        string sub;
        // Code start
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
            string rea;
            ifstream file4;
            file4.open(sub, ios::app);
            while (getline(file4, rea))
            {
                if (rea == "Objective")
                {
                    break;
                }
            }
            if (rea == "Objective")
            {
                cout << "There is already an objective test for " << subt << "." << endl;
                cout << "Do you want to add questions to it or overwrite that test?" << endl;
                cout << "Press 1 for adding questions" << endl;
                cout << "Press 2 for overwriting the test" << endl;
                cin >> test_do;
                if (test_do == 1)
                {
                }
                if (test_do == 2)
                {
                }
            }
            if (rea != "Objective")
            {
                file2 << "Objective" << endl;
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
            string rea;
            ifstream file4;
            file4.open(sub, ios::app);
            while (getline(file4, rea))
            {
                if (rea == "True/False")
                {
                    break;
                }
            }
            if (rea == "True/False")
            {
                cout << "There is already an True/False test for " << subt << "." << endl;
                cout << "Do you want to add questions to it or overwrite that test?" << endl;
                cout << "Press 1 for adding questions" << endl;
                cout << "Press 2 for overwriting the test" << endl;
                cin >> test_do;
                if (test_do == 1)
                {
                }
                if (test_do == 2)
                {
                }
            }
            if (rea != "True/False")
            {
                file2 << "True/False" << endl;
                string fname;
                fname = subt + "_true.txt";
                file.open(fname, ios::app);
                cout << "Enter credit for each question: " << endl;
                cin >> cred;
                file << cred << endl;
                string ques;
                while (true)
                {
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
        if (type_sub == 3)
        {
            string rea;
            ifstream file4;
            file4.open(sub, ios::app);
            while (getline(file4, rea))
            {
                if (rea == "Short Answer")
                {
                    break;
                }
            }
            if (rea == "Short Answer")
            {
                cout << "There is already an Short Answer test for " << subt << "." << endl;
                cout << "Do you want to add questions to it or overwrite that test?" << endl;
                cout << "Press 1 for adding questions" << endl;
                cout << "Press 2 for overwriting the test" << endl;
                cin >> test_do;
                if (test_do == 1)
                {
                }
                if (test_do == 2)
                {
                }
            }
            if (rea != "Short Answer")
            {
                file2 << "Short Answer" << endl;
                string fname;
                fname = subt + "_short.txt";
                file.open(fname, ios::app);
                cout << "Enter credit for each question: " << endl;
                cin >> cred;
                file << cred << endl;
                string ques;
                while (true)
                {
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
             << "Press L to logout" << endl;
        cin >> fun;
        if (fun == 'T' || fun == 't')
        {
            prac();
        }
        if (fun == 'D' || fun == 'd')
        {
            doubt();
        }
    }
    void prac()
    {
        ifstream file, file1;
        int marks = 0, inc, dec;
        file.open("name_test.txt", ios::app);
        string line, topic, read, line1;
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
        string topic_name = topic;
        topic = topic + ".txt";
        file1.open(topic, ios::app);
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
        }
        cout << "You scored " << marks << " marks in test." << endl;
        ifstream file4, file5, file8;
        ofstream file3, file6, file7;
        file7.open("marks.txt", ios::app);
        string name_test_mark;
        file6.open("test_name_marks.txt", ios::app);
        file4.open("name_test.txt", ios::app);
        name_test_mark = topic_name;
        file6 << name_test_mark << endl;
        name_test_mark = name_test_mark + "_marks.txt";
        file3.open(name_test_mark, ios::app);
        file8.open(name_test_mark, ios::app);
        file5.open(topic, ios::app);
        getline(file5, read);
        inc = stoi(read);
        getline(file5, read);
        number_line = 0;
        while (getline(file5, line1))
        {
            file3 << line1 << endl;
            getline(file5, read);
            file3 << read << endl;
            getline(file5, read);
            file3 << read << endl;
            getline(file5, read);
            file3 << read << endl;
            getline(file5, read);
            file3 << read << endl;
            getline(file5, read);
            file3 << "Correct option is : " << read << endl;
            file3 << endl;
        }
        file3 << endl
              << namestud << " ( " << rollstud << " )" << " scored "
              << marks << " marks in "
              << topic_name << " test." << endl;
        file7 << namestud << " ( " << rollstud << " )" << endl
              << topic_name << endl
              << marks << endl;
        string tell_key, tell_ans_key;
        cout << "Do you want to download answer key? [yes/no]" << endl;
        cin >> tell_key;
        if (tell_key == "yes" || tell_key == "Yes")
        {
            while (getline(file8, tell_ans_key))
            {
                cout << endl
                     << tell_ans_key;
            }
            cout << endl;
        }
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