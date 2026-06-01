#include <iostream>
#include <fstream>
using namespace std;

    class Student{
  
        int rollNo;
        string name;
        float marks;

        public:
        void displayInfo();
        void getInfo();
    
    };   
    
    int search(int targetRollNo)
    { 

            ifstream fin("student.txt");
            string tempname;
            int tempRollno;
            float tempmarks;

            while(getline(fin, tempname))            //use of getline()
            {
                fin >> tempRollno;
                fin >> tempmarks;
                fin.ignore();

                if(tempRollno == targetRollNo)
                {
                    cout << "\nSTUDENT FOUND!\n";
                    cout<< "\t---STUDENT DETAILS---\t"<<endl;
                    cout << "NAME: " << tempname << endl;
                    cout << "ROLL NUMBER: " << tempRollno << endl;
                    cout << "MARKS: "<< tempmarks << endl;

                    fin.close();
                    return 1;
                }
            }
             cout<< "NO MATCH FOUND!";
             return -1;
    }

    //MEMBER FUNCTION
    void Student::getInfo(){
        cout << "ENTER STUDENT'S NAME:- ";
            cin.ignore();
            getline(cin, name);
            cout << "\nENTER STUDENT'S ROLL NUMBER:-  " <<endl;
            cin >> rollNo;
            cout << "ENTER STUDENT'S MARKS:- " <<endl;
            cin >> marks;

            ofstream fout("student.txt", ios::app);
            if(fout.is_open()){
            
            fout << name <<endl;
            fout <<rollNo<<endl;
            fout <<marks <<endl;
            fout.close();
            }else{
                cout<< "File unable to open!";
            }
    }

    //MEMBER FUNCTION
    void Student::displayInfo(){
          cout << "\t-----STUDENT DETAILS-----\t"<<endl;
          cout << "NAME: " << name <<endl;
          cout << "ROLL NUMBER: " << rollNo <<endl;
          cout << "MARKS: " << marks <<endl;
    }


    //ADD STUDENT
    void addStudent(Student s[]){ 
            int n;
            cout << "Enter number of students:- " <<endl;
            cin >> n;

            for(int i=0; i<n; i++){
                cout<< "\t---" << i << "th Student---\t"<<endl;
                s[i].getInfo();
            }
    }

    void displayAllStudent(){
        ifstream fin("student.txt");
        string tempname;
        int temprollno;
        int tempmarks;
        cout << "\n\n\t----ALL STUDENTS----\t\t\n\n";

        while(getline(fin, tempname)){ 

            fin >> temprollno;
            fin >>tempmarks;
            fin.ignore();
            
            cout << "NAME: " << tempname <<endl;
            cout << "Roll Number: " << temprollno<<endl;
            cout << "MARKS: " << tempmarks << "\n\n";
        }
        
    }

int main(){ 

    Student s[100];
    Student obj;
    
    cout << "WELCOME TO STUDENT MANAGEMENT\n";
    string a;
    cout << "enter start to Display Menu.." <<endl;
    cin >> a;
    int choice;

    //MENU
   
          cout << "\t----MENU----\t"<<endl;
          cout << "\n1. Add Student"<<endl;
          cout << "\n2. Display All Students"<<endl;
          //cout << "\n3. Delete Student"<<endl;
          cout << "\n3. Search Student 🔍"<<endl;
          cout << "\n4. EXIT\n\n" <<endl;
          cout << "ENTER YOUR CHOICE"<<endl;

          cin>> choice;

          switch(choice){

                case 1:
                  addStudent(s);
                  break;

                case 2:
                  displayAllStudent();
                  break;
                
                case 3:
                   int target;
                   cout<< "\n\nENTER ROLL NUMBER TO SEARCH.."<<endl;
                   cin >> target;
                   search(target); 
                   break;

                case 4:
                   cout << "EXITING..." <<endl;
                   return 0;
                   break;
                   
                default:
                   cout<<"Invalid Choice!";   
          }
       
   
    


}