#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

int adminView();
int studentView();
int studentLogin();
int checkCredentials(string userName, string password);
int getAllStudentsbyRollNo();
int deleteAllStudents();
int deleteStudentbyRollno();
int checkListOfStudentsRegistered();
int checkPresenseCountbyRollno();
int getListOfStudentsWithTheirPresenseCount();
int registerStudent();
int adminLogin();
int registerStudent();
int markMyAttendance(string username);
int countMyAttendance(string username);
int delay();

int delay()
{
for(int i = 0; i<3; i ++)
{
    cout << endl << " Saving Records ...";
    for(int ii = 0; ii<20000; ii ++)
    {
        for(int iii = 0; iii<20000; iii ++)
        { }
    }
}
    
cout << endl << " Exiting Now ...";
for(int i = 0; i<3; i ++){
   for(int ii = 0; ii<20000; ii ++) { 
     for(int iii = 0; iii<20000; iii ++){
     }
    } 
}

return 0;
}

int adminView()
{   
int goBack = 0;
while(1)
{
system("cls");
cout << endl << " 1 Register a Student";
cout << endl << " 2 Delete All students name registered";
cout << endl << " 3 Delete student by rollno";
cout << endl << " 4 Check List of Student registered by userame";
cout << endl << " 5 Check presense count of any student by Roll No";
cout << endl << " 6 Get List of student with their attendance count";
cout << endl << " 0. Go Back <- " << endl;
int choice;

cout << endl << " Enter you choice: ";
cin >> choice;

switch(choice)
{
    case 1: registerStudent();break;   
    case 2: deleteAllStudents(); break;
    case 3: deleteStudentbyRollno(); break;
    case 4: checkListOfStudentsRegistered(); break;
    case 5: checkPresenseCountbyRollno(); break;
    case 6: getListOfStudentsWithTheirPresenseCount(); break;
    case 0: goBack = 1;break;
    default: cout << endl << " Invalid choice. Enter again ";
    getchar();           
}   

if(goBack == 1)
{
break;
}    

}

return 0;
}

int studentLogin()
{
system("cls");
cout << endl << " -------- Student Login ---------";    
studentView();
delay();
return 0; 
}


int adminLogin()
{
system("cls");
cout << endl << " --------- Admin Login --------";   

string username;
string password;

cout << endl << " Enter username : ";
cin >> username;
cout << endl << " Enter password : ";
cin >> password;

if(username=="admin" && password=="admin@2") 
{
    adminView();
    getchar();   
    delay();
}   
else
{
cout << endl << " Error ! Invalid Credintials..";   
cout << endl << " Press any key for main menu ";
getchar();getchar();
}

return 0;
}


int checkStudentCredentials(string username, string password)
{
ifstream read;
read.open("db.dat");

if (read) {
int recordFound = 0;
string line;
string temp = username + password + ".dat";
cout << endl << " file name is : " << temp;
while(getline(read, line)) {
    if(line == temp)
    {
        recordFound = 1;
        break;
    }
}

if(recordFound == 0)
    return 0;
else
   return 1;
}
else
{
   return 0;
}
            
}

int getAllStudentsbyName()
{
cout << endl << " List of All Students by their Name " << endl;   

cout << endl << " Please any key to continue..";
getchar();getchar();

return 0;
}

int getAllStudentsbyRollNo()
{
cout << endl << " List of All Students by their Roll No " << endl;

cout << endl << " Please any key to continue..";
getchar();getchar();

return 0;         
    
}

int deleteStudentbyRollno()
{
    
cout << endl << " Delete any Student by their Roll No " << endl;     

cout << endl << " Please any key to continue..";
getchar();getchar();

return 0;
}


int checkPresenseCountbyRollno()
{
cout << endl << " Check presense count of any Student by Roll No " << endl;   

cout << endl << " Please any key to continue.." ;
getchar();getchar();

return 0;   
}

int checkAllPresenseCountbyRollno()
{
cout << endl << " Check presense count of All Students by Roll No & Name " << endl;      
cout << endl << " Please any key to continue.." ;
getchar();getchar();

return 0;
}

int studentView()
{
cout << endl << " ------- Student Login-------- " << endl;         

string username, password;

cout << endl << " Enter username : ";
cin >> username;

cout << endl << " Enter password : ";
cin >> password;

int res = checkStudentCredentials(username, password);

if(res   == 0)
{
   cout << endl << " Invalid Credentials !!";
   cout << endl << " Press any key for Main Menu..";
   getchar(); getchar();    
   return 0;
} 

int goBack = 0;
while(1)
{
system("cls");

cout << endl << " 1 Mark Attendance fo Today ";
cout << endl << " 2 Count my Attendance";
cout << endl << " 0. Go Back <- " << endl;
int choice;

cout << endl << " Enter you choice: ";
cin >> choice;

switch(choice)
{
    case 1: markMyAttendance(username); break;
    case 2: countMyAttendance(username); break;
    case 0: goBack = 1;break;
    default: cout << endl << " Invalid choice. Enter again ";
    getchar();           
}   

if(goBack == 1)
{
break;
}    
    
}
return 0; // Added return statement
}

int markMyAttendance(string username)
{
cout << endl << " Mark Attendance for today !!";    
cout << endl << " Please any key to continue..";

getchar();getchar();

return 0;   
} 

int countMyAttendance(string username)
{
cout << endl << " Count my attendace for today !!"; 
cout << endl << " Please any key to continue..";

getchar();getchar();

return 0;   
} 

int deleteAllStudents()
{
cout << endl << " In delete all students !!";
cout << endl << " Please any key to continue..";

getchar(); getchar();
return 0;
}


int checkListOfStudentRegistered()
{
cout << endl << " List of All registered registered !!";
cout << endl << " Please any key to continue..";


getchar(); getchar();
return 0;
}

int getListOfStudentsWithTheirPresenseCount()
{
cout << endl << " All Students with their Presense count !!";
cout << endl << " Please any key to continue..";

getchar(); getchar();
return 0;
}

int checkListOfStudentsRegistered(){
cout << endl << " - Check List of Student Registered by Username-- ";   

ifstream read;
read.open("db.dat");

if(read)
{   int recordFound =0; 
    string line;
    while(getline(read, line)) {
        char name[100];
        strcpy(name, line.c_str());
        char onlyname[100];
        strncpy(onlyname, name, (strlen(name) - 4));
        cout << " " << endl << onlyname;
    }
      read.close();         
}
else
{
cout << endl << " No Record found :(";
}
    
    
cout << endl << " Please any key to continue..";
getchar(); getchar();
return 0;
}


int registerStudent()
{
    cout << endl << " ----- Form to Register Student ---- " << endl;   

    string name, username, password, rollno, address, father, mother;
    
    cout << endl << " Enter Name : ";    cin >> name;
    cout << endl << " Enter Username : ";    cin >> username;
    cout << endl << " Enter password : ";    cin >> password;
    cout << endl << " Enter rollno : ";    cin >> rollno;
    getchar();
    
    char add[100];
    cout << endl << " Enter address : ";    cin.getline(add, 100);
    cout << endl << " Enter father : ";    cin >> father;
    cout << endl << " Enter mother : ";    cin >> mother;
    
    ifstream read;
    read.open("db.dat");
    
    if(read)
    {   int recordFound =0; 
       string line;
        while(getline(read, line)) {
        if(line == username+".dat" )
        {
            recordFound = 1 ;
            break;
        }
        }
        if(recordFound == 1)
        {
        cout << endl << " Username already Register. Please choose another username ";
        getchar(); getchar();
        delay();
        read.close();
        return 0;
        }
    }
    read.close();

    ofstream out;
    out.open("db.dat", ios::app);
    out << username << ".dat" << endl;
    out.close();

    ofstream out1;
    string temp = username+".dat";
    out1.open(temp.c_str());
    out1 << name << endl;   out1 << username << endl;   out1 << password << endl;
    out1 << rollno << endl;     out1 << add << endl;     out1 << father << endl;
    out1 << mother << endl;
    out1.close();

    cout << endl << " Student Registered Successfully !!";
    
    cout << endl << " Please any key to continue..";
    getchar(); getchar();
    return 0;       
}

int main(int argc, char** argv) {
    
while(1)
{
    system("cls");
    cout << endl << " Attendance Management System " << endl;
    cout << "-------------------------------------" << endl << endl;
    
    cout << "1. Student Login" << endl;
    cout << "2. Admin Login" << endl;
    
    cout << "0. Exit" << endl;
    int choice;
    
    cout << endl << " Enter you choice: ";
    cin >> choice;
    
    switch(choice)
    {
    case 1: studentLogin(); break;
    case 2: adminLogin(); break;
    case 0: 
            while(1)
            {
            system("cls");
            cout << endl << " Are you sure, you want to exit? y | n " << endl;
            char ex;
            cin >> ex;
            if(ex == 'y' || ex == 'Y')
                exit(0);
            else if(ex == 'n' || ex == 'N')
             {
                 break;
             }
             else{
                cout << endl << " Invalid choice !!!";
                getchar();
             }

            }
            break;
                      
    default: cout << endl << " Invalid choice. Enter again ";
    getchar();
    }           

}
    
return 0;
}    
