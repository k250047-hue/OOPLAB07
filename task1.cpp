#include <iostream>
#include <string>
using namespace std;

class Book {
    string title;
    string author;
    double price;

public:
    Book() {
        title = "Untitled";
        author = "Anonymous";
        price = 0.0;
    }

    Book(string t, string a = "Unknown", double p = 0.0) {
        title = t;
        author = a;
        price = p;
    }

    Book(const Book &b) {
        title = b.title;
        author = b.author;
        price = b.price;
    }

    void display() {
        cout << title << " " << author << " " << price << endl;
    }
};

int main() {
    Book b1;
    Book b2("C++", "Bjarne", 500);
    Book b3(b2);
    Book b4("Novel");

    b1.display();
    b2.display();
    b3.display();
    b4.display();

    return 0;
}

