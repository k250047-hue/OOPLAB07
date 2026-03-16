#include <iostream>
#include <string>
using namespace std;

class Media {
private:
    string title;
    string publicationDate;
    string uniqueID;
    string publisher;
    bool isCheckedOut;

public:
    Media() : isCheckedOut(false) {}

    Media(string t, string pubDate, string id, string pub)
        : title(t), publicationDate(pubDate), uniqueID(id), publisher(pub), isCheckedOut(false) {}

    string getTitle() { return title; }
    string getPublisher() { return publisher; }
    string getPublicationDate() { return publicationDate; }
    string getUniqueID() { return uniqueID; }

    virtual void displayInfo() {
        cout << "Title: " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "ID: " << uniqueID << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Status: " << (isCheckedOut ? "Checked Out" : "Available") << endl;
    }

    void checkOut() {
        if(!isCheckedOut) {
            isCheckedOut = true;
            cout << title << " has been checked out." << endl;
        } else {
            cout << title << " is already checked out." << endl;
        }
    }

    void returnItem() {
        if(isCheckedOut) {
            isCheckedOut = false;
            cout << title << " has been returned." << endl;
        } else {
            cout << title << " was not checked out." << endl;
        }
    }
};

class Book : public Media {
private:
    string author;
    string ISBN;
    int numberOfPages;
public:
    Book(string t, string pubDate, string id, string pub, string auth, string isbn, int pages)
        : Media(t, pubDate, id, pub), author(auth), ISBN(isbn), numberOfPages(pages) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Pages: " << numberOfPages << endl;
    }

    string getAuthor() { return author; }
};

class DVD : public Media {
private:
    string director;
    int duration;
    string rating;
public:
    DVD(string t, string pubDate, string id, string pub, string dir, int dur, string rate)
        : Media(t, pubDate, id, pub), director(dir), duration(dur), rating(rate) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " mins" << endl;
        cout << "Rating: " << rating << endl;
    }
};

class CD : public Media {
private:
    string artist;
    int numberOfTracks;
    string genre;
public:
    CD(string t, string pubDate, string id, string pub, string art, int tracks, string g)
        : Media(t, pubDate, id, pub), artist(art), numberOfTracks(tracks), genre(g) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Artist: " << artist << endl;
        cout << "Tracks: " << numberOfTracks << endl;
        cout << "Genre: " << genre << endl;
    }
};

class Magazine : public Media {
private:
    int issueNumber;
    string category;
public:
    Magazine(string t, string pubDate, string id, string pub, int issue, string cat)
        : Media(t, pubDate, id, pub), issueNumber(issue), category(cat) {}

    void displayInfo() override {
        Media::displayInfo();
        cout << "Issue Number: " << issueNumber << endl;
        cout << "Category: " << category << endl;
    }
};

class Library {
private:
    Media* collection[100];
    int count;
public:
    Library() : count(0) {}

    void addMedia(Media* m) {
        if(count < 100) collection[count++] = m;
    }

    void search(string title) {
        cout << "Searching by title: " << title << endl;
        for(int i = 0; i < count; i++) {
            if(collection[i]->getTitle() == title)
                collection[i]->displayInfo();
        }
    }

    void searchByAuthor(string author) {
        cout << "Searching by author: " << author << endl;
        for(int i = 0; i < count; i++) {
            Book* b = dynamic_cast<Book*>(collection[i]);
            if(b && b->getAuthor() == author)
                b->displayInfo();
        }
    }

    void searchByYear(string year) {
        cout << "Searching by publication year: " << year << endl;
        for(int i = 0; i < count; i++) {
            string pubDate = collection[i]->getPublicationDate();
            if(pubDate.substr(0,4) == year)
                collection[i]->displayInfo();
        }
    }
};

int main() {
    Library lib;

    Book* b1 = new Book("C++ Programming", "2021-03-01", "B001", "TechPub", "Bjarne Stroustrup", "1234567890", 500);
    DVD* d1 = new DVD("Inception", "2010-07-16", "D001", "Warner Bros", "Christopher Nolan", 148, "PG-13");
    CD* c1 = new CD("Thriller", "1982-11-30", "C001", "Epic", "Michael Jackson", 9, "Pop");
    Magazine* m1 = new Magazine("National Geographic", "2023-01-01", "M001", "NatGeo", 150, "Science");

    lib.addMedia(b1);
    lib.addMedia(d1);
    lib.addMedia(c1);
    lib.addMedia(m1);

    lib.search("Final Destination");
    lib.searchByAuthor("Thomas Shelby");
    lib.searchByYear("2024");

    b1->checkOut();
    b1->returnItem();

    return 0;
}