/**
 * @file library.cpp
 * @author1 Xander Butler
 * @author2 Jacqueline Bybee
 * @date 2024-03-29
 * @brief Implentation file for library
 * 
 * Implements all functions of the library class
 */

#include "library.h"

void Movie::display() const {
    std::cout << "Title: " << title << "\n";
    std::cout << "Director: " << director << "\n";
    std::cout << "Runtime: " << runtime << " minutes\n";
    std::cout << "Format: " << format << "\n";
    std::cout << "Price: $" << price << "\n";
    std::cout << "Year: " << year << "\n";
    std::cout << "-----------------------\n";
}

void Library::insertMovie(const Movie& movie) {
    movies.push_back(movie);
}

void Library::findMovie(const std::string& searchStr) const {
    for (const auto& movie : movies) {
        if (movie.title.find(searchStr) != std::string::npos) {
            movie.display();
        }
    }
}

void Library::directorSearch(const std::string& director) const {
    for (const auto& movie : movies) {
        if (movie.director == director) {
            movie.display();
        }
    }
}

void Library::removeMovie(const std::string& title) {
    movies.remove_if([title](const Movie& movie) { return movie.title == title; });
}

void Library::displayAll() const {
    for (const auto& movie : movies) {
        movie.display();
    }
}

void Library::loadFromFile(const std::string& inFile) {
    std::ifstream inF(inFile);

    if (!inF.is_open()) {
        std::cerr << "Error: Unable to load file " << inFile << "!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inF, line)) {
        Movie newMovie;
        newMovie.title = line;

        std::getline(inF, newMovie.director);
        inF >> newMovie.runtime >> newMovie.format >> newMovie.price >> newMovie.year;
        inF.ignore(1000, '\n'); // Ignore remaining characters in line

        movies.push_back(newMovie);
    }

    inF.close();
}

void Library::storeToFile(const std::string& outFile) const {
    std::ofstream outF(outFile);

    for (const auto& movie : movies) {
        outF << movie.title << std::endl << movie.director << std::endl << movie.runtime << std::endl
             << movie.format << std::endl << movie.price << std::endl << movie.year << std::endl
             << "-----------------------\n";
    }
    outF.close();
}
