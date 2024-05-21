#include "include/System.h"
#include <iostream>
#include <limits>
#include <string>

void clearCin()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void printHeader()
{
    // ANSI escape codes for color
    const std::string RESET = "\033[0m";
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string CYAN = "\033[36m";

    std::cout << RED << R"(
  _     _ _                                _   _                                      
 | |   (_) |                              | | (_)                                     
 | |    _| |__  _ __ __ _ _ __ _   _    __| |  _ _ __   __ _                          
 | |   | | '_ \| '__/ _` | '__| | | |  / _` | | | '_ \ / _` |                         
 | |___| | |_) | | | (_| | |  | |_| | | (_| | | | | | | (_| |                         
 |______|_|_.__/|_|  \__,_|_|   \__, |  \__,_| |_|_| |_|\__, |                         
                                __/ |                    __/ |                         
                               |___/                    |___/                          
)" << RESET << '\n';
    std::cout << GREEN << "Welcome to the Library Management System\n"
              << RESET;
    std::cout << YELLOW << "--------------------------------\n"
              << RESET;
    std::cout << CYAN << "This system allows you to manage books and students.\n"
              << "You can create, view, issue, and return books.\n"
              << "Students can be registered and managed easily.\n"
              << RESET;
    std::cout << YELLOW << "--------------------------------\n"
              << RESET;
}

void printMenu()
{
    std::cout << "Library Management System\n";
    std::cout << "--------------------------------\n";
    std::cout << "1. Book Management\n";
    std::cout << "2. Student Management\n";
    std::cout << "3. Issue/Return Books\n";
    std::cout << "4. Search Books\n";
    std::cout << "5. Undo/Redo Actions\n";
    std::cout << "6. Exit\n";
    std::cout << "--------------------------------\n";
}

void printBookManagementMenu()
{
    std::cout << "\n-- Book Management --\n";
    std::cout << "1. Create Book\n";
    std::cout << "2. Show Book\n";
    std::cout << "3. Delete Book\n";
    std::cout << "4. Display All Books\n";
    std::cout << "5. Check Book Availability\n";
    std::cout << "6. Back to Main Menu\n";
}

void printStudentManagementMenu()
{
    std::cout << "\n-- Student Management --\n";
    std::cout << "1. Create Student\n";
    std::cout << "2. Delete Student\n";
    std::cout << "3. Display All Students\n";
    std::cout << "4. Back to Main Menu\n";
}

void printIssueReturnMenu()
{
    std::cout << "\n-- Issue/Return Books --\n";
    std::cout << "1. Issue Book\n";
    std::cout << "2. Return Book\n";
    std::cout << "3. Back to Main Menu\n";
}

void printSearchBooksMenu()
{
    std::cout << "\n-- Search Books --\n";
    std::cout << "1. Search Books by Author\n";
    std::cout << "2. Search Books by Publication\n";
    std::cout << "3. Back to Main Menu\n";
}

void printUndoRedoMenu()
{
    std::cout << "\n-- Undo/Redo Actions --\n";
    std::cout << "1. Undo Delete Book\n";
    std::cout << "2. Undo Delete Student\n";
    std::cout << "3. Redo Delete Book\n";
    std::cout << "4. Redo Delete Student\n";
    std::cout << "5. Back to Main Menu\n";
}

int main()
{
    System librarySystem;
    int mainChoice, subChoice;
    std::string author, publication;

    do
    {
        printHeader();
        printMenu();
        std::cout << "Enter your choice: ";
        std::cin >> mainChoice;
        clearCin();

        int bno, admno, quant;
        std::string bname, aname, pname, sname;

        switch (mainChoice)
        {
        case 1:
            do
            {
                printBookManagementMenu();
                std::cout << "Enter your choice: ";
                std::cin >> subChoice;
                clearCin();

                switch (subChoice)
                {
                case 1:
                {
                    std::cout << "\n-- Create New Book --\n";

                    // Validate book number
                    while (true)
                    {
                        std::cout << "Enter book number: ";
                        std::cin >> bno;
                        if (std::cin.fail() || bno <= 0)
                        {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "Invalid input. Please enter a positive integer for the book number.\n";
                        }
                        else
                        {
                            break;
                        }
                    }

                    // Validate quantity
                    while (true)
                    {
                        std::cout << "Enter quantity: ";
                        std::cin >> quant;
                        if (std::cin.fail() || quant < 0)
                        {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << "Invalid input. Please enter a non-negative integer for the quantity.\n";
                        }
                        else
                        {
                            break;
                        }
                    }
                    clearCin();

                    // Validate book name
                    while (true)
                    {
                        std::cout << "Enter book name: ";
                        getline(std::cin, bname);
                        if (bname.empty())
                        {
                            std::cout << "Book name cannot be empty. Please enter a valid book name.\n";
                        }
                        else
                        {
                            break;
                        }
                    }

                    // Validate author name
                    while (true)
                    {
                        std::cout << "Enter author name: ";
                        getline(std::cin, aname);
                        if (aname.empty())
                        {
                            std::cout << "Author name cannot be empty. Please enter a valid author name.\n";
                        }
                        else
                        {
                            break;
                        }
                    }

                    // Validate publication name
                    while (true)
                    {
                        std::cout << "Enter publication name: ";
                        getline(std::cin, pname);
                        if (pname.empty())
                        {
                            std::cout << "Publication name cannot be empty. Please enter a valid publication name.\n";
                        }
                        else
                        {
                            break;
                        }
                    }

                    librarySystem.createBook(bno, quant, bname, aname, pname);
                    break;
                }

                case 2:
                    std::cout << "\n-- Show Book Details --\n";
                    std::cout << "Enter book number: ";
                    std::cin >> bno;
                    clearCin();
                    librarySystem.showBook(bno);
                    break;
                case 3:
                    std::cout << "\n-- Delete Book --\n";
                    std::cout << "Enter book number to delete: ";
                    std::cin >> bno;
                    clearCin();
                    if (librarySystem.deleteBook(bno))
                    {
                        std::cout << "Book deleted successfully.\n";
                    }
                    else
                    {
                        std::cout << "Book not found.\n";
                    }
                    break;
                case 4:
                    std::cout << "\n-- Display All Books --\n";
                    librarySystem.displayAllBooks();
                    break;
                case 5:
                    std::cout << "\n-- Check Book Availability --\n";
                    std::cout << "Enter book number: ";
                    std::cin >> bno;
                    clearCin();
                    if (librarySystem.checkBookAvailability(bno))
                    {
                        std::cout << "Book is available.\n";
                    }
                    else
                    {
                        std::cout << "Book is not available.\n";
                    }
                    break;
                case 6:
                    std::cout << "Returning to main menu...\n";
                    break;
                default:
                    std::cout << "Invalid choice, please try again.\n";
                }
            } while (subChoice != 6);
            break;
        case 2:
            do
            {
                printStudentManagementMenu();
                std::cout << "Enter your choice: ";
                std::cin >> subChoice;
                clearCin();

                switch (subChoice)
                {
                case 1:
                {
                    std::cout << "\n-- Register New Student --\n";
                    std::cout << "Enter student name: ";
                    getline(std::cin, sname);

                    // Check if the name is empty
                    if (sname.empty())
                    {
                        std::cout << "Invalid input. Please enter a non-empty name.\n";
                        break;
                    }

                    std::cout << "Enter student admission number: ";
                    if (!(std::cin >> admno))
                    {
                        std::cout << "Invalid input. Please enter a valid admission number.\n";
                        clearCin(); // Clear the input buffer to prevent infinite loop
                        break;
                    }
                    clearCin(); // Clear any remaining input in the buffer

                    librarySystem.createStudent(sname, admno);
                    break;
                }

                case 2:
                    std::cout << "\n-- Delete Student --\n";
                    std::cout << "Enter student admission number to delete: ";
                    std::cin >> admno;
                    clearCin();
                    if (librarySystem.deleteStudent(admno))
                    {
                        std::cout << "Student deleted successfully.\n";
                    }
                    else
                    {
                        std::cout << "Student not found.\n";
                    }
                    break;
                case 3:
                    std::cout << "\n-- Display All Students --\n";
                    librarySystem.displayAllStudents();
                    break;
                case 4:
                    std::cout << "Returning to main menu...\n";
                    break;
                default:
                    std::cout << "Invalid choice, please try again.\n";
                }
            } while (subChoice != 4);
            break;
        case 3:
            do
            {
                printIssueReturnMenu();
                std::cout << "Enter your choice: ";
                std::cin >> subChoice;
                clearCin();

                switch (subChoice)
                {
                case 1:
                    std::cout << "\n-- Issue Book to Student --\n";
                    std::cout << "Enter student admission number: ";
                    std::cin >> admno;
                    std::cout << "Enter book number: ";
                    std::cin >> bno;
                    clearCin();
                    librarySystem.issueBook(admno, bno);
                    break;
                case 2:
                    std::cout << "\n-- Return Book --\n";
                    std::cout << "Enter student admission number: ";
                    std::cin >> admno;
                    std::cout << "Enter book number: ";
                    std::cin >> bno;
                    clearCin();
                    librarySystem.returnBook(admno, bno);
                    break;
                case 3:
                    std::cout << "Returning to main menu...\n";
                    break;
                default:
                    std::cout << "Invalid choice, please try again.\n";
                }
            } while (subChoice != 3);
            break;
        case 4:
            do
            {
                printSearchBooksMenu();
                std::cout << "Enter your choice: ";
                std::cin >> subChoice;
                clearCin();

                switch (subChoice)
                {
                case 1:
                    std::cout << "\n-- Search Books by Author --\n";
                    std::cout << "Enter author name: ";
                    getline(std::cin, author);
                    librarySystem.searchBooksByAuthor(author);
                    break;
                case 2:
                    std::cout << "\n-- Search Books by Publication --\n";
                    std::cout << "Enter publication name: ";
                    getline(std::cin, publication);
                    librarySystem.searchBooksByPublication(publication);
                    break;
                case 3:
                    std::cout << "Returning to main menu...\n";
                    break;
                default:
                    std::cout << "Invalid choice, please try again.\n";
                }
            } while (subChoice != 3);
            break;
        case 5:
            do
            {
                printUndoRedoMenu();
                std::cout << "Enter your choice: ";
                std::cin >> subChoice;
                clearCin();

                switch (subChoice)
                {
                case 1:
                    std::cout << "\n-- Undo Delete Book --\n";
                    librarySystem.undoDeleteBook();
                    break;
                case 2:
                    std::cout << "\n-- Undo Delete Student --\n";
                    librarySystem.undoDeleteStudent();
                    break;
                case 3:
                    std::cout << "\n-- Redo Delete Book --\n";
                    librarySystem.redoDeleteBook();
                    break;
                case 4:
                    std::cout << "\n-- Redo Delete Student --\n";
                    librarySystem.redoDeleteStudent();
                    break;
                case 5:
                    std::cout << "Returning to main menu...\n";
                    break;
                default:
                    std::cout << "Invalid choice, please try again.\n";
                }
            } while (subChoice != 5);
            break;
        case 6:
            std::cout << "\nExiting...\n";
            break;
        default:
            std::cout << "\nInvalid choice, please try again.\n";
        }
    } while (mainChoice != 6);

    return 0;
}
