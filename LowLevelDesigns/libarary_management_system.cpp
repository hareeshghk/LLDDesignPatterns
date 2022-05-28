#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Enums for all objects
enum class AccountStaus {
    ACTIVE,
    REGISTERED,
    BLOCKED,
    CANCELLED,
    NONE
};

enum class BookItemStatus {
    RESERVERD,
    LOANED,
    DAMAGED,
    AVAILABLE,
    LOST
};

enum class BookFormat {
    HARDCOVER,
    EBOOK,
    AUDIOBOOK
};

enum class ReservationStatus {
    WAITING,
    PENDING,
    COMPLETED,
    CANCELLED,
    DONE
};

enum class BookCategory {
    NOVEL,
    HORROR,
    SCEINECE,
    MATHS,
    MISCALLENEOUS
};

class Address {
    string streetName;
    string houseNumber;
    string state, country;
    int pincode;
};

class Account {
    string name;
    Address address;
    string contactNumber;
    string email;
};

class Librarian: public Account {
    void AddBook(BookItem);
    void EditBook(BookItem);
    void DeleteBook(BookItem);
};

class Member: public Account {
    vector<BookItem> booksTaken;
};

class MembershipCard {
    string startDate;
    string memberId;
    AccountStaus status;
};


class Library {
    string name;
    Address address;
    string phone;
    string email;
    Librarian librarian;
    vector<Member> members;
    vector<BookItem> books;
    Catalog catalog;
};

class Catalog {
    vector<Book> Search(string bookName);
    vector<Book> Search(Author author);
    vector<Book> Search(BookCategory book_category);
};

class Author {
    string name;
    string getName();
};


class Book {
    vector<Author> author;
    string name;
};

class BookItem : public Book {
    BookLocation location;
    ReservationStatus status;
    string bookId;
};

class BookLocation {
    int rackId;
    int rowId;
    int columnId;
};

struct Date {
    int date;
    int month;
    int year;
};

class Author {

};