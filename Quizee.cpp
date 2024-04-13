#include <iostream>
#include <fstream>
#include <string>
using namespace std;
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
        cout << "Are you a student or teacher: ";
        cin >> st;
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
        cout << endl
             << "Are you a student or a teacher: ";
        cin >> st;
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
        }

        if (st == "teacher" || st == "Teacher")
        {
            cout << endl
                 << "Enter your contact number: ";
            cin >> num;
        }
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
             << "Press R to change the details or press C to continue: ";
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
        }
        cout << endl
             << "You are being redirected to login page." << endl;
        login();
    }
    void detailsstu()
    {
        cout << "Please check your details: " << endl;
        cout << "Type: " << st << endl;
        cout << "Roll number: " << num << endl
             << "Username: " << user << endl;
        cout << "Password: " << passcreate;
        cout << endl
             << "Press R to change the details or press C to continue: ";
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
        }
        cout << endl
             << "You are being redirected to login page." << endl;
        login();
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
             << "Press S to set question paper or R to read feedback of students or press L to logout: ";
        cin >> fun;
        if (fun == 'S' || fun == 's')
        {
            Set();
        }
        if (fun == 'r' || fun == 'R')
        {
            read_review();
        }
    }
    void Set()
    {
        cout << "Enter the topic on which you want to input practice questions for students: ";
        cin >> sub;
        sub = sub + ".txt";
        ofstream file, file1;
        string op1, op2, op3, op4, ans;
        file.open(sub, ios::app);
        file1.open("name_test.txt", ios::app);
        file1 << sub << endl;
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
            file << ans;
            cout << "Do you want to write another question?" << endl
                 << "Press Y to write and N to exit.";
            cin >> cont;
            cin.ignore();
            if (cont == 'N' || cont == 'n')
            {
                break;
            }
        }
        cout << endl
             << "Your test has been created sucessfully. You are being redirected to home page." << endl;
        Teacher();
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
    }
};
class Student
{
public:
    char fun;
    string namestud;
    Student(string namestu)
    {
        namestud = namestu;
        cout << endl
             << "Welcome to students portal." << endl;
        cout << "Press T for giving tests or press D for sending doubts to your teacher or press L to logout: ";
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
        char cor_op, op;
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
        file1.open(topic);
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
            cin >> op;
            cin.ignore();
            file1.get(cor_op);
            char line = cor_op;
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
        ofstream file3;
        cout << "You scored " << marks << " marks in test." << endl;
        file3.open("marks.txt", ios::app);
        file3 << namestud << " scored " << marks << " in " << topic_name << " test." << endl;
        cout << "Do you have any doubts? [Yes/No]";
        cin >> doub;
        cin.ignore();
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
        ofstream doubt;
        string dou;
        doubt.open("doubts.txt", ios::app);
        doubt << namestud << endl;
        cout << "You can write your doubts here: (Press Enter to end)";
        getline(cin, dou);
        doubt << dou << " ";
        cin.ignore();
        cout << endl
             << "You are being redirected to feedback section: ";
        feedback();
    }
    void feedback()
    {
        cout << endl
             << "You can write your feedback here: (Press Enter to end)" << endl;
        ofstream feedback;
        string feed;
        feedback.open("feedback.txt", ios::app);
        feedback << namestud << endl;
        getline(cin, feed);
        feedback << feed << " ";
        cout << endl
             << "Thank you for your feedback. We are redirecting you to home page.";
        Student stude(namestud);
    }
};
int main()
{
    char fwd;
    do
    {
        loginpg l;
        if (l.done == 'S')
        {
            Student stu(l.username);
            if (stu.fun == 'L' || stu.fun == 'l')
            {
                cout << "You have been logged out." << endl
                     << "Do you wish to proceed further? [y/n]";
                cin >> fwd;
            }
        }
        if (l.done == 'T')
        {
            Teacher te;
            if (te.fun == 'L' || te.fun == 'l')
            {
                cout << "You have been logged out." << endl
                     << "Do you wish to proceed further? [y/n]";
                cin >> fwd;
            }
        }
    } while (fwd == 'y' || fwd == 'Y');
}