#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <iomanip>
#include "library.h"


/**
 * A main helper function to print the menu.
 *
 * @pre 
 * @return void 
 * @post the menu will be printed for the user on the console
 * 
 */
void displayMenu();

int main() {
    Library library;
    int choice;
    std::string searchStr, director, title;
    Movie newMovie;

    // Load movies from file upon startup
    library.loadFromFile("movies.txt");

    while (true) {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(); // Clear newline character

        switch (choice) {
            case 1:
                std::cout << "Enter title: ";
                std::getline(std::cin, newMovie.title);
                std::cout << "Enter director: ";
                std::getline(std::cin, newMovie.director);
                std::cout << "Enter runtime (minutes): ";
                std::cin >> newMovie.runtime;
                std::cin.ignore(); // Clear newline character
                std::cout << "Enter format: ";
                std::getline(std::cin, newMovie.format);
                std::cout << "Enter price: ";
                std::cin >> newMovie.price;
                std::cin.ignore(); // Clear newline character
                std::cout << "Enter year: ";
                std::cin >> newMovie.year;
                std::cin.ignore(); // Clear newline character
                library.insertMovie(newMovie);
                break;
            case 2:
                std::cout << "Enter search string: ";
                std::getline(std::cin, searchStr);
                library.findMovie(searchStr);
                break;
            case 3:
                std::cout << "Enter director's name: ";
                std::getline(std::cin, director);
                library.directorSearch(director);
                break;
            case 4:
                std::cout << "Enter title of movie to remove: ";
                std::getline(std::cin, title);
                library.removeMovie(title);
                break;
            case 5:
                library.displayAll();
                break;
            case 6:
                library.storeToFile("movies.txt");
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

void displayMenu() {
  std::cout << "1. Add a movie\n";
  std::cout << "2. Find movies by title\n";
  std::cout << "3. Find movies by director\n";
  std::cout << "4. Remove a movie\n";
  std::cout << "5. Display all movies\n";
  std::cout << "6. Store to file\n";
  std::cout << "7. Exit\n";
  std::cout << "Enter your choice: ";
}
