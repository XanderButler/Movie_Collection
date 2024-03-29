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

    Movie(const std::string& title, const std::string& director, int runtime, const std::string& format, float price, int year)
        : title(title), director(director), runtime(runtime), format(format), price(price), year(year) {}

    void display() const {
        std::cout << "Title: " << title << "\n";
        std::cout << "Director: " << director << "\n";
        std::cout << "Runtime: " << runtime << " minutes\n";
        std::cout << "Format: " << format << "\n";
        std::cout << "Price: $" << price << "\n";
        std::cout << "Year: " << year << "\n";
        std::cout << "-----------------------\n";
    }
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
