# Library-Management
Library Management is a c++ program build to easily manage a book library.

# Features

User-friendly admin and user interfaces.

Account creation and management for admins(only one account can be created for admin).

Book search functionality for users.

Book borrowing and return capabilities for users.

username and password are encrypted by my encrypter.

Check whether the due date is over.

Detailed records of all the books that have been taken.

Detailed records of all the books that have been returned.


# Usage

Upon running the executable file, you will be prompted to choose between the admin and user interface.

If you choose the admin interface, you will be prompted to create an admin account.

Once you have created an admin account, you can log in and create user accounts or manage existing accounts.

If you choose the user interface, you will be prompted to enter the username and password after login you can take books, return books, search etc.

You can search a book by its name, if the search was succesfull you will get a corresponding book's ID which can be used to take books.

After finding a book, you can borrow it by entering the book's ID.

You can return the book by entering its ID again.

# Warning:

Please remember your username and password for admin and user accounts. The data is stored after encryption and cannot be read from the text file. Once you forget your username or password, you won't be able to retrieve it. So, please store it in a safe place.

Only one admin account can be created. Please make sure to remember the admin username and password. If you forget it, you won't be able to access the admin interface. So you have to download the project once again and freshly run it.
