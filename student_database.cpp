#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int ID;
class student
{
   public:
    int id;
    string name;
    int age;
    string stream;

//for Add the record in file
void addStudent()
{
    cout<<"enter your name"<<endl;
    cin.get();
    getline(cin,name);
    cout<<"enter your age"<<endl;
    cin>>age;
    cout<<"enter your stream"<<endl;
    cin>>stream;
    ID++;

    ofstream fout;
    fout.open("c:/file/abc.txt",ios::app);  //open abc.txt file to Add data
    fout<<"\n"<<ID;
    fout<<"\n"<<name;
    fout<<"\n"<<age;
    fout<<"\n"<<stream;
    fout.close();  // close abc.txt file

    fout.open("c:/file/id.txt",ios::app);  //open ID.txt file for Add ID
    fout<<"\n"<<ID;
    fout.close();   // close id.txt file

    cout<<"record added successfully"<<endl;
}
   //Print All data which in abc.txt file
   void printAllStudent()
   {
      ifstream fin;
      fin.open("c:/file/abc.txt");
      student s;
      while(!fin.eof())
      {
          fin>>s.id;
          fin.ignore();
          getline(fin,s.name);
          fin>>s.age;
          fin>>s.stream;

          s.print();
      }
      fin.close();
   }
   void print()
   {
       cout<<"ID = "<<id<<endl;
       cout<<"Name = "<<name<<endl;
       cout<<"Age = "<<age<<endl;
       cout<<"Stream = "<<stream<<endl;
       cout<<"###################################"<<endl<<endl;

   }
   //Search student data with the help of id:
    void searchStudent(int id)
    {
        ifstream fin;
        fin.open("c:/file/abc.txt");
        student s;
      while(!fin.eof())
      {
          fin>>s.id;
          fin.ignore();
          getline(fin,s.name);
          fin>>s.age;
          fin>>s.stream;

       if (s.id == id)
       {
           s.print();
           break;
       }
      }
      fin.close();
    }

    //Delete student data from abc.txt file and id.txt file with the help of temp.txt file
    void deleteStudent(int id)
    {
       ifstream fin;
       fin.open("c:/file/abc.txt");

       ofstream fout;
       fout.open("c:/file/temp.txt",ios::app);

        student s;
      while(!fin.eof())
      {
          fin>>s.id;
          fin.ignore();
          getline(fin,s.name);
          fin>>s.age;
          fin>>s.stream;

       if (s.id != id)
       {
           fout<<"\n"<<s.id;
           fout<<"\n"<<s.name;
           fout<<"\n"<<s.age;
           fout<<"\n"<<s.stream;
       }
      }
       fin.close();
       fout.close();

       remove("c:/file/abc.txt");
       rename("c:/file/temp.txt","c:/file/abc.txt");
       cout<<"record deleted successfully"<<endl;
    }

    //update the student record of abc.txt and id.txt file:
    void updateStudent(int id)
    {
        deleteStudent(id);

      cout<<"enter your name"<<endl;
    cin.get();
    getline(cin,name);
    cout<<"enter your age"<<endl;
    cin>>age;
    cout<<"enter your stream"<<endl;
    cin>>stream;
    ID++;

    ofstream fout;
    fout.open("c:/file/abc.txt",ios::app);
    fout<<"\n"<<id;
    fout<<"\n"<<name;
    fout<<"\n"<<age;
    fout<<"\n"<<stream;
    fout.close();

    cout<<"record updated successfully"<<endl;
  }
};
int main()
{
   int choice;

   ifstream fin;
   fin.open("c:/file/id.txt");

   if(!fin)
   {
       cout<<"file not found"<<endl;
   }
   else{
   while(!fin.eof())
   {
       fin>>ID;
   }
  }
   fin.close();
   cout<<"ID ="<<ID<<endl;

   while(true)
   {
   cout<<"enter your choice"<<endl;
   cout<<"1. Add student"<<endl;
   cout<<"2. print all student"<<endl;
   cout<<"3. search a student"<<endl;
   cout<<"4. delete a student"<<endl;
   cout<<"5. update student"<<endl;

    cin>>choice;
    student s;
    int id;

    switch(choice)
    {
        case 1 : s.addStudent();
                 break;
        case 2 : s.printAllStudent();
                 break;
        case 3 :
                 cout<<"enter student id"<<endl;
                 cin>>id;
                 s.searchStudent(id);
                 break;
        case 4 :
                 cout<<"enter student id"<<endl;
                 cin>>id;
                 s.deleteStudent(id);
                 break;
        case 5 :
                 cout<<"enter student id"<<endl;
                 cin>>id;
                 s.updateStudent(id);
                 break;
        default : return 0;
    }
   }
      return 0;
}
