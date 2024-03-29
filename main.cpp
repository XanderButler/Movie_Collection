#include <iostream>
#include "library.h"

void displayMenu() {
    std::cout << "1. Add a movie\n";
    std::cout << "2. Find movies by title\n";
    std::cout << "3. Find movies by director\n";
    std::cout << "4. Remove a movie\n";
    std::cout << "5. Display all movies\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Library library;
    int choice;
    std::string searchStr, director, title;
    Movie newMovie("", "", 0, "", 0.0, 0);

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter title: ";
                std::cin.ignore();
                std::getline(std::cin, newMovie.title);
                std::cout << "Enter director: ";
                std::getline(std::cin, newMovie.director);
                do {
                    std::cout << "Enter runtime (minutes): ";
                    std::cin >> newMovie.runtime;
                    if (newMovie.runtime <= 0) {
                        std::cout << "Invalid runtime. Please enter a positive value.\n";
                    }
                } while (newMovie.runtime <= 0);
                std::cin.ignore();
                std::cout << "Enter format: ";
                std::getline(std::cin, newMovie.format);
                do {
                    std::cout << "Enter price: ";
                    std::cin >> newMovie.price;
                    if (newMovie.price <= 0.0) {
                        std::cout << "Invalid price. Please enter a positive value.\n";
                    }
                } while (newMovie.price <= 0.0);
                do {
                    std::cout << "Enter year: ";
                    std::cin >> newMovie.year;
                    if (newMovie.year <= 0) {
                        std::cout << "Invalid year. Please enter a positive value.\n";
                    }
                } while (newMovie.year <= 0);
                library.insertMovie(newMovie);
                break;
            case 2:
                std::cout << "Enter search string: ";
                std::cin.ignore();
                std::getline(std::cin, searchStr);
                library.findMovie(searchStr);
                break;
            case 3:
                std::cout << "Enter director's name: ";
                std::cin.ignore();
                std::getline(std::cin, director);
                library.directorSearch(director);
                break;
            case 4:
                std::cout << "Enter title of movie to remove: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                library.removeMovie(title);
                break;
            case 5:
                library.displayAll();
                break;
            case 6:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
