# Movie Collection Program
This is the repository made by the nu-Types group. This C++ program is a simple movie library system that allows users to manage a collection of movies. The program uses `std::list` to store movie entries and provides functionality such as adding, removing, searching, and printing movies.

# Files Included
- `main.cpp`: Contains the main program logic including the menu-driven interface and file I/O operations.
- `library.h`: Header file for the Library class.
- `library.cpp`: Implementation file for the Library class.

# How To Use Program
Use the Makefile
Type "./movie"
You will be immediately met with an interface and a several commands, which include, adding a movie, finding a movie by title, finding a movie by director, removing a movie, display all movies, store all movies to a file, and exit. Each command is number-coded, just type a number and hit Enter. Enjoy from there. This program centers around a movie.txt file.

- Add Movie: Allows users to add new movies to the library.
- Remove Movie: Enables users to remove movies from the library.
- Find Movie By Title: Finds and displays movies based on a search string.
- Director Search: Displays movies directed by a specific director.
- Print All Movies: Prints details of all movies in the library.
- Load from file: loads movies with their elements from a txt file.
- Write to file: Creates a txt file with all the movies loaded on it.
- Exit: Quits the program.

# How Do I Import And Export Files?
You may wonder where an import file feature may be, that is immediately done for you by movie.txt, which is immediately loaded in by the program upon being executed. While this may make the startup time take a little while, we felt it was best for the user experience to make things more convenient. Do note that movie.txt is also affected by the store all movies to a file feature, also as a method of convenience.

# Development Log
This project was a little difficult on us all, as we had to coordinate a lot after we lost one group member due to a reassignment of groups. We made this repository and pushed many things to it, making code and improving from before many times over until we got something which worked in a way we deemed acceptable. Much testing had to be done, most of which tedious. Some problems we encountered were things like the file not loading in correctly, or even at all. Turns out, a line of space was what was causing the issues.

# Authors
- Xander Butler 
- Jacqueline Bybee
