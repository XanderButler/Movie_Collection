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
