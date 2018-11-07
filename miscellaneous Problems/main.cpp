#include<fstream>
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

class Book
{
    private:
        int bookid;
        char title[20];
        float price;
    public:
        Book()
        {
            bookid=0;
            strcpy(title, "No title");
            price = 0;
        }
        void getBookData()
        {
            cout<<"Enter BOok id. title and Price of a book";
            cin>>bookid;
            cin.ignore();
            cin.getline(title,19);
            cin>>price;
        }
        void showBookData()
        {
            cout<<"\n"<<bookid<<" "<<title<<" "<<price;
        }
        int storeBook();
        void viewAllBooks();
        void searchBook(char *);
        void deleteBook(char*);
};

void Book ::deleteBook(char* t)
{
    ifstream fin;
    ofstream fout;
    fin.open("file1.dat", ios::in|ios::binary);
    if(!fin)
        cout<<"\nFile Not Found";
    else
    {
        fout.open("tempfile.dat", ios::out|ios::binary);
        fin.read((char*)this, sizeof(*this));
        while(!fin.eof())
        {
            if(strcmp(title,t))
                fout.write((char*)this,sizeof(*this));
            fin.read((char*)this, sizeof(*this));
        }
        fin.close();
        fout.close();
        remove("file1.dat");
        rename("tempfile.dat","file1.dat");
    }
}

void Book :: searchBook(char* t)
{
    int count = 0;
    ifstream fin;
    fin.open("file1.dat",ios::in|ios::binary);
    if(!fin)
        cout<<"\nFile Not Found";
    else
    {
        fin.read((char*)this, sizeof(*this));
        while(!fin.eof())
        {
            if(!strcmp(t,title)){
                showBookData();
                count++;
            }
            fin.read((char*)this, sizeof(*this));
        }
        if(count == 0)
            cout<<"\nRecord Not Found";
        fin.close();
    }
}

int Book::storeBook()
{
    if(bookid == 0 && price == 0)
    {
        cout<<"Book data not initialize";
        return 0;
    }
    else
    {
        ofstream fout;
        fout.open("file1.dat",ios::app|ios::binary);
        fout.write((char*)this,sizeof(*this));
        fout.close();
        return 1;
    }
}

void Book::viewAllBooks()
{

    ifstream fin;
    fin.open("file1.dat", ios::in|ios::binary);
    if(!fin)
        cout<<"\nFile Not Found";
    else
    {
        fin.read((char*)this, sizeof(*this));
        while(!fin.eof())
        {
            showBookData();
            fin.read((char*)this, sizeof(*this));
        }

        fin.close();
    }
}

int main()
{
    Book b1;
    b1.viewAllBooks();
    b1.deleteBook("ds and algo");
    cout<<"\nafter deletion"<<endl;
    b1.viewAllBooks();
}
