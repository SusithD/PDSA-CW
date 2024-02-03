# Library Management System

This Library Management System is a console-based application developed in C++. It allows for the management of a library's books and students, including adding new books, displaying book details, registering students, issuing books to students, and returning books. This system is designed to be user-friendly, with a clear and attractive console interface.

## Features

- **Create Book**: Add new books to the library system with details such as book number, quantity, name, author, and publication.
- **Show Book**: Display the details of a book by entering its book number.
- **Create Student**: Register a new student with their name and admission number.
- **Issue Book**: Issue a book to a student, updating the system's records.
- **Return Book**: Mark a book as returned, making it available for issue again.
- **Exit**: Safely exit the Library Management System application.

## Getting Started

### Prerequisites

- C++ Compiler (GCC recommended)
- Git (for cloning the repository)

### Installation

1. **Clone the repository**

   Open a terminal and run the following command:

   ```sh
   git clone https://github.com/yourusername/library-management-system.git
   ```

   Replace `your username` with your GitHub username if you've forked the repository or clone directly from the main repository link.

2. **Navigate to the project directory**

   ```sh
   cd library-management-system
   ```

### Compilation

Compile the project using the following command:

```sh
g++ -o LibrarySystem main.cc src/Display.cc src/System.cc -I include
```

This command compiles the source files and generates an executable named `LibrarySystem`.

### Running the Application

Run the compiled application using:

```sh
./LibrarySystem
```

On Windows, if you're using cmd, you might need to use:

```cmd
LibrarySystem
```

## Usage

Follow the on-screen prompts to interact with the Library Management System:

1. Choose an option from the main menu by entering a number (1-6).
2. For actions requiring input (e.g., creating a book or student), enter the requested details when prompted.
3. To issue or return a book, you'll need the book number and the student's admission number.
4. Select "6" to exit the application.

## Contributing

Contributions to the Library Management System are welcome. Please feel free to fork the repository, make your changes, and create a pull request to contribute.

## Support

If you encounter any issues or have any questions about the Library Management System, please open an issue in the GitHub repository.
