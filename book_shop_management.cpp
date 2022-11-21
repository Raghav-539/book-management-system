#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <conio.h>
#include <iomanip>
using namespace std;


class Books{ 
    char book_id_[5];
    char title_[30];
    char author_[30];
    char publisher_[30];
    float price_;
    int stock_;

    public:

    void add_book()
    {
        cout <<"Enter detail of book" << endl;
        cout <<"Enter the book id: " ;
        cin >> book_id_;
        cout <<"Enter the name of book: ";
        cin >> title_;
        cout <<"Enter the author's name: " ;
        cin >> author_;
        cout <<"Enter the publisher name: ";
        cin >> publisher_;
        cout <<"Enter the price of book: " ;
        cin >> price_;
        cout <<"Enter the number of copies: ";
        cin >> stock_;
    }

    void display_books()
    {
        cout <<"Book id is: " << book_id_ << endl;
        cout <<"Book name is: " << title_ << endl;
        cout <<"Author is: " << author_ << endl;
        cout <<"Publisher is: " << publisher_ << endl;
        cout <<"Price of book is: " << price_ << endl;
        cout <<"Stock is: " << stock_ << endl;

    }

    void modify_book()
    {
        cout << "Book id: " << book_id_ << endl;
        cout << "Modify book name: ";
        cin >> title_;
        cout << "\nModify author's name: ";
        cin >> author_;
        cout << "\nEnter number of copies: ";
        cin >> stock_;
    }

    char*  booknumber()
    {
        return book_id_;
    }

    void report()
    {
        cout << book_id_ << setw(30) << title_ << setw(30) << author_ << setw(30) << publisher_ << setw(30) << price_  << setw(30) << stock_ << endl;
    }
};

class Student{

    char addmission_no[5];
    char student_name[25];
    char student_book_no[5];
    int token;

    public:
    void add_student()
    {
        cout <<"New student entry..." << endl;
        cout <<"Enter the addmission number of student: ";
        cin >> addmission_no;
        cout <<"\nEnter the name of student: ";
        cin >> student_name;
        token = 0;
        student_book_no[0]=0;
        cout << "\nStudent record created..." << endl;
    }

    void display_students()
    {
        cout <<"Addmission number is: " << addmission_no << endl;
        cout <<"Student name is: " << student_name << endl;
        cout <<"Number of book issued: " << token << endl;
        if(token==1){
            cout << "Book number: " << student_book_no << endl; 
        }
    }

    void modify_student()
    {
        cout << "Addmission number: " << addmission_no << endl;
        cout << "Modify Student name: ";
        cin >> student_name;
        cout << "\nModify number of book issued: ";
        cin >> token;
        if(token==1){
            cout << "Book number: " << student_book_no << endl; 
        }
    }

    char*  addmissionno()
    {
        return addmission_no;
    }

    char* studentbookno()
    {
        return student_book_no;
    }

    int tokenno()
    {
        return token;
    }

    void addtoken()
    {
        token=1;
    }

    void resettoken()
    {
        token=0;
    }

    void getstudentbookno(char t[])
    {
        strcpy(student_book_no,t);
    }

    void report()
    {
        cout << addmission_no << setw(30) << student_name << setw(30) << token << endl;
    }

};

// file handling 

fstream fp,fp2;
Books book;
Student student;

// function to write in file

void write_book()
{
    char ch;
    fp.open("book_data.txt");
    do
    {
        book.add_book();
        fp.write((char*)&book,sizeof(Books));
        cout << "\nDo you want to add more record? (y/n)" << endl;
        cin >> ch;

    } while (ch=='y' || ch=='Y');
    fp.close();   
}

void write_student()
{
    char ch;
    fp.open("student_data.txt");
    do
    {
        student.add_student();
        fp.write((char*)&student,sizeof(Student));
        cout << "\nDo you want to add more record? (y/n)" << endl;
        cin >> ch;

    } while (ch=='y' || ch=='Y');
    fp.close();   
}

// functions to read specific records 

void display_book(char n [])
{
    cout << "\nBook details: " << endl;
    int flag=0;
    fp.open("book_data.txt");
    while(fp.read((char*)&book,sizeof(Books)))
    {
        if(strcmpi(book.booknumber(),n)==0)
        {
            book.display_books();
            flag=1;
        }
    }  
    fp.close();
    if(flag==0)
    {
        cout << "\nBook not exist" << endl;
    }
    getch();
}


void display_student(char n [])
{
    cout << "\nStudent details: " << endl;
    int flag=0;
    fp.open("student_data.txt");
    while(fp.read((char*)&student,sizeof(Student)))
    {
        if(strcmpi(student.addmissionno(),n)==0)
        {
            student.display_students();
            flag=1;
        }
    }  
    fp.close();
    if(flag==0)
    {
        cout << "\nStudent does not exist" << endl;
    }
    getch();
}

// function to modify record

void  modify_book()
{
    char n[5];
    int found = 0;
    cout << "Modify book record" << endl;
    cout << "Enter the book id: " << endl;
    cin >> n;
    fp.open("book_data.txt");
    while(fp.read((char*)&book,sizeof(Books))&& found==0)
    {
        if(strcmpi(book.booknumber(),n)==0)
        {
            book.display_books();
            cout << "\nEnter the new details of book" << endl;
            book.modify_book();
            int position=-1*sizeof(book);
            fp.seekp(position);
            fp.write((char*)&book,sizeof(Books));
            cout << "\nRecord Updated" << endl;
        }
    }
    fp.close();
        if(found==0)
        {
            cout << "Record Not Found" << endl;
        }
    getch();
}

void  modify_student()
{
    char n[5];
    int found = 0;
    cout << "Modify student record" << endl;
    cout << "Enter the student admission number: " << endl;
    cin >> n;
    fp.open("book_data.txt");
    while(fp.read((char*)&student,sizeof(Student)) && found==0)
    {
        if(strcmpi(student.addmissionno(),n)==0)
        {
            student.display_students();
            cout << "\nEnter the new details of student" << endl;
            student.modify_student();
            int position=-1*sizeof(student);
            fp.seekp(position);
            fp.write((char*)&student,sizeof(Student));
            cout << "\nRecord Updated" << endl;
        }
    }
    fp.close();
        if(found==0)
        {
            cout << "Record Not Found" << endl;
        }
    getch();
}

// function to delete record of file

void delete_book()
{

    char n[5];
    int flag = 0;
    cout << "\nDelete Book" << endl;
    cout << "Enter the book number you want to delete: ";
    cin >> n;
    fp.open("book_data.txt");
    fstream fp1;
    fp1.open("temp_data.txt");
    fp.seekg(0);
    while(fp.read((char*)&book,sizeof(Books)))
    {
        if(strcmpi(book.booknumber(),n)!=0)
        {
            fp1.write((char*)&book,sizeof(Books));
        }
        else{
            flag=1;
        }
    }

    fp1.close();
    fp.close();
    remove("book_data.txt");
    rename("temp_data.txt","book_data.txt");
    if(flag==1)
    {
        cout << "Record Deleted." << endl;
    }
    else{
        cout << "Record not found." << endl;
    }
    getch();

}

void delete_student()
{
    char n[5];
    int flag = 0;
    cout << "\nDelete Student" << endl;
    cout << "Enter the student admission number you want to delete: ";
    cin >> n;
    fp.open("student_data.txt");
    fstream fp1;
    fp1.open("temp_data.txt");
    fp.seekg(0);
    while(fp.read((char*)&student,sizeof(Student)))
    {
        if(strcmpi(student.addmissionno(),n)!=0)
        {
            fp1.write((char*)&student,sizeof(Student));
        }
        else{
            flag=1;
        }
    }

    fp1.close();
    fp.close();
    remove("student_data.txt");
    rename("temp_data.txt","student_data.txt");
    if(flag==1)
    {
        cout << "Record Deleted." << endl;
    }
    else{
        cout << "Record not found." << endl;
    }
    getch();
}

// function to display all books and student list

void display_all_books()
{
    fp.open("book_data.txt");
    if(!fp)
    {
        cout << "Error! File could not be found." << endl;
        getch();
        return;
    }

    cout << "\nBook List" << endl;
    cout << "Book Number" << setw(25) << "Book Title" << setw(25) << "Author" << setw(30) << "Publisher" << setw(28) << "Price" << setw(28) << "Stock" << endl;
    while(fp.read((char*)&book,sizeof(Books)))
    {
        book.report();


    }
    fp.close();
    getch;
}

void display_all_students()
{
    fp.open("student_data.txt");
    if(!fp)
    {
        cout << "Error! File could not be found." << endl;
        getch();
        return;
    }

    cout << "\nStudent List" << endl;
    cout << "Admission Number" << setw(30) << "Name" << setw(30) << "Book issued" << endl;
    while(fp.read((char*)&student,sizeof(Student)))
    {
        student.report();
    }
    fp.close();
    getch;
}

// function to issue book

void issue_book()
{
    char adn[5],bn[5];
    int found=0, flag=0;
    cout << "\nBook Issue." << endl;
    cout << "\nEnter the student admission number: ";
    cin >> adn;
    fp.open("student_data.txt");
    fp2.open("book_data.txt");
    while (fp.read((char*)&student,sizeof(student)) && found==0)
    {
        if(strcmpi(student.addmissionno(),adn)==0)
        {
            found=1;
            if(student.tokenno() == 0)
            {
                cout << "\nEnter the book number: " ;
                cin >> bn;
                while(fp2.read((char*)&book,sizeof(Books))&& flag==0)
                {
                    if(strcmpi(book.booknumber(),bn)==0)
                    {
                        book.add_book();
                        flag=1;
                        student.addtoken();
                        student.getstudentbookno(book.booknumber());
                        int position=-1*sizeof(student);
                        fp.seekp(position);
                        fp.write((char*)&student,sizeof(Student));
                        cout << "\nBook issued successfully." << endl;
                    }
                }
                if (flag==0)
                {
                    cout << "Book does not exist." << endl;
                }
            }
            else{
                cout << "You have not returned the last book.";
            }
        }
    }
    if (found==0)
    {
        cout << "Student record not exist." << endl;
    }
    getch();
    fp.close();
    fp2.close();   
}

// function to deposit book

void deposit_book()
{
    char adn[5],bn[5];
    int found=0, flag=0;
    cout << "\nBook Issue." << endl;
    cout << "\nEnter the student admission number: ";
    cin >> adn;
    fp.open("student_data.txt");
    fp2.open("book_data.txt");
    while (fp.read((char*)&student,sizeof(student)) && found==0)
    {
        if(strcmpi(student.addmissionno(),adn)==0)
        {
            found=1;
            if(student.tokenno() == 1)
            {
                while(fp2.read((char*)&book,sizeof(Books))&& flag==0)
                {
                    if(strcmpi(book.booknumber(),student.studentbookno())==0)
                    {
                        book.add_book();
                        flag=1;
                        cout << "Book deposited." << endl;
                        student.resettoken();
                        int position=-1*sizeof(student);
                        fp.seekp(position);
                        fp.write((char*)&student,sizeof(Student));
                        cout << "\nBook depostied successfully." << endl;
                    }
                }
                if (flag==0)
                {
                    cout << "Book does not exist." << endl;
                }
            }
            else{
                cout << "No book is issued.";
            }
        }
    }
    if (found==0)
    {
        cout << "Student record not exist." << endl;
    }
    getch();
    fp.close();
    fp2.close();
    
}

// intorduction function
void intro()
{
    cout << setw(100) <<"----------------------Welcome-----------------------" << endl;
    cout << setw(100) << "-----------Book Shop Management System-----------" << endl;
    cout << setw(90) << "------------Raghav Gupta-----------" << endl;

    getch();
}



int main()
{
    intro();
    cout << endl;
    for (;;)
    {
        cout << "Press 1 to add new book" << endl;
        cout << "Press 2 to see all books" << endl;
        cout << "Press 3 to check single book record" << endl;
        cout << "Press 4 to modify books" << endl;
        cout << "Press 5 to delete books" << endl;
        cout << "Press 6 to add student" << endl;
        cout << "Press 7 to see all student record" << endl;
        cout << "Press 8 to see single student record" << endl;
        cout << "Press 9 to modify student" << endl;
        cout << "Press 10 to delete student" << endl;
        cout << "Press 11 to issue book" << endl;
        cout << "Press 12 to deposit the book" << endl;
        cout << "Press 0 to exit" << endl;
        int choice = 0;

        do {
            cout<<"\nEnter Your Choice: ";
            cin>>choice;
            switch (choice)
            {
                case 1:
                    write_book();
                    break;
                    
                case 2:
                    display_all_books();
                    break;
                    
                case 3:
                {
                    char num[5];
                    cout<<"Enter book number: ";
                    cin>>num;
                    display_book(num);
                    break;
                }	


                case 4:
                    modify_book();
                    break;
                    
                case 5:
                    delete_book();
                    break;
                    
                case 6:
                    write_student();
                    break;
                    
                case 7:
                    display_all_students();
                    break;

                case 8:
                    char num[5];
                    cout<<"Enter student's admission number: ";
                    cin>>num;
                    display_student(num);
                    
                    break;
                
                case 9:
                    modify_student();
                    break;
                
                case 10:
                    delete_student();
                    break;

                
                case 11:
                    issue_book();
                    break;
                
                case 12:
                    deposit_book();
                    break;

            }
        } while (choice != 0);
    }
}