#include <iostream>
#include <fstream>
#include <string>
#include<vector>

using namespace std;

class student
{
    string name, roll, branch, fathers_name, city, phone_number;

public:
    student(
        string name,
        string roll,
        string branch,
        string fathers_name,
        string city,
        string phone_number)
    {
        this->name = name;
        this->roll = roll;
        this->branch = branch;
        this->fathers_name = fathers_name;
        this->city = city;
        this->phone_number = phone_number;
    }
    friend void add(student &s);
};

void add(student &s)
{
    ofstream fout;
    fout.open("Student.txt", ios::app);
    fout << s.name << " "
         << s.roll << " "
         << s.branch << " "
         << s.fathers_name << " "
         << s.city << " "
         << s.phone_number << "\n";
    fout.close();
    std::cout << "Added successfuly...!!" << endl;
}

class faculty
{
    string id, name, qualification, branch, phone_number, designation;

public:
    faculty(
        string id,
        string name,
        string qualification,
        string branch,
        string phone_number,
        string designation)
    {
        this->id = id;
        this->name = name;
        this->qualification = qualification;
        this->branch = branch;
        this->phone_number = phone_number;
        this->designation = designation;
    }
    friend void add(faculty &f);
};

void add(faculty &f)
{
    ofstream fout;
    fout.open("Faculty.txt", ios ::app);
    fout << f.id << " "
         << f.name << " "
         << f.qualification << " "
         << f.branch << " "
         << f.phone_number << " "
         << f.designation << "\n";
    fout.close();
    std::cout << "Added successfuly...!!" << endl;
}

class branch
{

    string name, number_of_student, number_of_faculty;

public:
    branch(
        string name,
        string number_of_student,
        string number_of_faculty)
    {
        this->name = name,
        this->number_of_student = number_of_student,
        this->number_of_faculty = number_of_faculty;
    }
    friend void add(branch &b);
};

void add(branch &b)
{
    ofstream fout;
    fout.open("Branch.txt", ios ::app);
    fout << b.name << " "
         << b.number_of_student << " "
         << b.number_of_faculty << "\n";
    fout.close();
    std::cout << "Added successfuly...!!" << endl;
}

void display()
{
    int a;
    cout << endl
         << "1.Student\n2.Faculty\n3.Branch" << endl;
    cin >> a;
    if ((a > 3) || (a < 1))
    {
        cout << "Invalid selection.(select between 1-3)" << endl;
        return;
    }
    a--;
    string s[] = {"Student", "Faculty", "Branch"};
    string s1[]={"Name  Roll    Branch  Fathers_name    City_name   Phone_number",
                 "Id    Name    Qualification   Branch  Phone_number    Designation",
                 "Name  Number_of_student   Number_of_faculty"
                 };
    ifstream f;
    f.open(s[a] + ".txt");
    string word;
    cout<<s1[a]<<endl;
    cout<<"============================================================================"<<endl;
    while (f >> word)
    {
        cout << word << "   ";
    }
    cout << "\n\n\n";
    f.close();
}

void register_student()
{
    int n;
    string name;
    ifstream f;
    std::cout << "Enter the roll number: ";
    cin >> n;
    cout << "Enter the branch name: ";
    cin >> name;
    f.open("Student.txt");
    string sname, branch, fname, city, phn;
    int roll;
    bool found_roll = false;
    while (f)
    {
        f >> sname >> roll >> branch >> fname >> city >> phn;
        if (roll == n)
        {
            found_roll = true;
        }
    }
    if (!found_roll)
    {
        cout << "Roll number not found...";
        return;
    }
    f.close();
    cout << endl;

    f.open("Branch.txt");
    string bname;
    int ns, nf;
    bool found_branch = false;
    while (f)
    {
        f >> bname >> ns >> nf;
        if (bname == name)
        {
            found_branch = true;
        }
    }
    if (!found_branch)
    {
        cout << "Branch not found...";
        return;
    }
    cout << endl;
    f.close();

    ofstream fout;
    fout.open("Register.txt", ios ::app);
    fout << n << " "
         << name << "\n";
    fout.close();
    std::cout << "Registered successfully." << endl;
}

string checkBranch(){
    ifstream f;
    f.open("Branch.txt");
    string w1,w2,w3;
    cout<<"\nBranch list."<<endl;
    int i=0;
    vector<string>v;
    f>>w1>>w2>>w3;
    while (f)
    {
        v.push_back(w1);
        i++;
        f>>w1>>w2>>w3;
        cout <<i<<" "<< w1 << endl;
    }
    cout << endl;
    f.close();
    int x;
    cout<<"\nEnter the branch number: ";
    cin>>x;
    if(x<=v.size() && x>=0){
        return v[x-1];
    }else{
        cout<<"Invalid input.";
        exit(0);
    }
}

void addList()
{
    int a;
    cout << "1.Add Student\n2.Add Faculty\n3.Add branch\n";
    cin >> a;
    if (a == 1)
    {
        string name;
        string roll;
        string branch;
        string fathers_name;
        string city;
        string phone_number;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter roll: ";
        cin >> roll;

        branch=checkBranch();
        
        cout << "Enter father's name: ";
        cin >> fathers_name;
        cout << "Enter city name: ";
        cin >> city;
        cout << "Enter phone number: ";
        cin >> phone_number;

        student s(name, roll, branch, fathers_name, city, phone_number);

        add(s);
    }
    else if (a == 2)
    {
        string id;
        string name;
        string qualification;
        string branch;
        string phone_number;
        string designation;

        cout << "Enter id: ";
        cin >> id;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter qualification: ";
        cin >> qualification;

        branch=checkBranch();
        
        cout << "Enter phone number: ";
        cin >> phone_number;
        cout << "Enter designation: ";
        cin >> designation;

        faculty f(id, name, qualification, branch, phone_number, designation);

        add(f);
    }
    else if (a == 3)
    {
        string name;
        string number_of_student;
        string number_of_faculty;

        cout << "Enter Branch name: ";
        cin >> name;
        cout << "Enter number of students in branch: ";
        cin >> number_of_student;
        cout << "Enter number of faculty in branch: ";
        cin >> number_of_faculty;

        branch b(name, number_of_student, number_of_faculty);

        add(b);
    }
    else
    {
        cout << "Invalid Selection." << endl;
    }
}
int main()
{
    bool flag = true;
    while (flag)
    {
        int n;
        cout << "1.Display List\n2.Register\n3.Add\n";
        cin >> n;
        if (n == 1)
        {
            display();
        }
        else if (n == 2)
        {
            register_student();
        }
        else if (n == 3)
        {
            addList();
        }
        else
        {
            cout << "Invalid input." << endl;
        }
        cout << "Press (y/Y) to continue"<<endl;
        char a;
        cin >> a;
        if (a == 'y' || a == 'Y')
        {
            flag = true;
        }
        else
        {
            flag = false;
        }
    }

    return 0;
}