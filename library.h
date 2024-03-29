#ifndef LIBRARY_H
#define LIBRARY_H

#include <list>
#include <string>
#include <iostream>

struct Movie {
    std::string title;
    std::string director;
    int runtime;
    std::string format;
    float price;
    int year;

    void display() const;
};

class Library {
private:
    std::list<Movie> movies;

public:
    void insertMovie(const Movie& movie);
    void findMovie(const std::string& searchStr) const;
    void directorSearch(const std::string& director) const;
    void removeMovie(const std::string& title);
    void displayAll() const;
};

#endif
