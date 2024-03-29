#include "library.h"
#include <algorithm>

void Library::insertMovie(const Movie& movie) {
    movies.push_back(movie);
    movies.sort([](const Movie& a, const Movie& b) { return a.title < b.title; });
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
