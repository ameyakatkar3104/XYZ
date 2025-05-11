#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// Structure to store book details
struct Book {
    string title;
    bool isAvailable;
};

class LibraryExpertSystem {
public:
    // Knowledge Base: Rules for actions
    void initializeLibrary() {
        books.push_back({"The Great Gatsby", true});
        books.push_back({"To Kill a Mockingbird", true});
        books.push_back({"1984", false});  // Currently issued
        books.push_back({"Moby Dick", true});
        books.push_back({"The Catcher in the Rye", true});
    }

    // Check if a book is available in the library
    void checkAvailability(const string& bookTitle) {
        for (const auto& book : books) {
            if (book.title == bookTitle) {
                if (book.isAvailable) {
                    cout << "The book '" << bookTitle << "' is available.\n";
                } else {
                    cout << "The book '" << bookTitle << "' is currently issued.\n";
                }
                return;
            }
        }
        cout << "Sorry, the book '" << bookTitle << "' is not available in the library.\n";
    }

    // Issue a book
    void issueBook(const string& bookTitle) {
        for (auto& book : books) {
            if (book.title == bookTitle) {
                if (book.isAvailable) {
                    book.isAvailable = false;  // Mark book as issued
                    cout << "The book '" << bookTitle << "' has been issued successfully.\n";
                } else {
                    cout << "Sorry, the book '" << bookTitle << "' is already issued.\n";
                }
                return;
            }
        }
        cout << "Sorry, the book '" << bookTitle << "' is not available in the library.\n";
    }

    // Return a book
    void returnBook(const string& bookTitle) {
        for (auto& book : books) {
            if (book.title == bookTitle) {
                if (!book.isAvailable) {
                    book.isAvailable = true;  // Mark book as available
                    cout << "The book '" << bookTitle << "' has been returned successfully.\n";
                } else {
                    cout << "This book was not issued to you.\n";
                }
                return;
            }
        }
        cout << "The book '" << bookTitle << "' is not part of the library.\n";
    }

    // Display all available books
    void displayAvailableBooks() {
        cout << "Available Books in the Library:\n";
        for (const auto& book : books) {
            if (book.isAvailable) {
                cout << "- " << book.title << endl;
            }
        }
    }

private:
    vector<Book> books;  // Library books
};

int main() {
    LibraryExpertSystem library;
    library.initializeLibrary();

    string userChoice;
    string bookTitle;

    cout << "=== Welcome to the Library Management System ===\n";
    
    while (true) {
        cout << "\nChoose an action:\n";
        cout << "1. Check Book Availability\n";
        cout << "2. Issue a Book\n";
        cout << "3. Return a Book\n";
        cout << "4. Display Available Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> userChoice;
        cin.ignore();  // To ignore the newline character left in the buffer
        
        if (userChoice == "1") {
            cout << "Enter the book title to check availability: ";
            getline(cin, bookTitle);
            library.checkAvailability(bookTitle);
        } else if (userChoice == "2") {
            cout << "Enter the book title to issue: ";
            getline(cin, bookTitle);
            library.issueBook(bookTitle);
        } else if (userChoice == "3") {
            cout << "Enter the book title to return: ";
            getline(cin, bookTitle);
            library.returnBook(bookTitle);
        } else if (userChoice == "4") {
            library.displayAvailableBooks();
        } else if (userChoice == "5") {
            cout << "Thank you for using the Library Management System.\n";
            break;
        } else {
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}


// #include <iostream>
// #include <string>

// using namespace std;

// string recommendBook(string domain, string projectType, string tech) {
//     // Rule-based recommendation
//     if (domain == "Computer Science") {
//         if (projectType == "AI" && tech == "Python")
//             return "Book: 'Python Machine Learning' by Sebastian Raschka";
//         else if (projectType == "Web" && tech == "JavaScript")
//             return "Book: 'Eloquent JavaScript' by Marijn Haverbeke";
//         else if (projectType == "Data Science" && tech == "Python")
//             return "Book: 'Hands-On Data Science with Python' by Frank Kane";
//     }
//     else if (domain == "Electronics") {
//         if (projectType == "Embedded Systems" && tech == "Arduino")
//             return "Book: 'Exploring Arduino' by Jeremy Blum";
//         else if (projectType == "IoT" && tech == "Raspberry Pi")
//             return "Book: 'Raspberry Pi Cookbook' by Simon Monk";
//     }
//     else if (domain == "Mechanical") {
//         if (projectType == "CAD" && tech == "SolidWorks")
//             return "Book: 'Engineering Design with SolidWorks' by David Planchard";
//         else if (projectType == "Robotics" && tech == "Arduino")
//             return "Book: 'Arduino Robotics' by John-David Warren";
//     }

//     return "Sorry, no specific book recommendation found for your selection.";
// }

// int main() {
//     string domain, projectType, tech;

//     cout << "=== Library Expert System for Book Recommendation ===\n";
//     cout << "Enter your domain (Computer Science / Electronics / Mechanical): ";
//     getline(cin, domain);
//     cout << "Enter project type (AI / Web / Data Science / Embedded Systems / IoT / CAD / Robotics): ";
//     getline(cin, projectType);
//     cout << "Enter preferred technology (Python / JavaScript / Arduino / Raspberry Pi / SolidWorks): ";
//     getline(cin, tech);

//     string recommendation = recommendBook(domain, projectType, tech);

//     cout << "\n=== Book Recommendation ===\n";
//     cout << recommendation << endl;

//     return 0;
// }