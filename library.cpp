/**
 * @file library.cpp
 * @author1 
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

void Library::loadFromFile(std::list<Movie> &movies, std::string inFile){
  ifstream inF;
  inF.open(inFile);

  if (!inF) {
    std::cerr << "Error: Unable to load file!" << std::endl;
    return;
  }

  std::string titleT;
  std::string directorT;
  std::string formatT;
  int yearT;
  int runtimeT;
  float priceT;

  while (std::getline(inF, titleT) && std::getline(inF, directorT) && inF >> runtimeT >> formatT >> priceT >> yearT) {
    movies.push_back(Movie(titleT, directorT, runtimeT, formatT, priceT, yearT));
    inF.ignore(); //if it only reads one movie this is the problem...
  }

  inF.close();
  
}

void Library::storeToFile(const std::list<Movie> &movies, std::string outFile){
  std::ofstream outF(outFile);

  for(const auto &movie : movies){
    outF << movie.title << endl << movie.director << endl << movie.runtime << endl
	 << movie.format << endl << movie.price << endl << movie.year << endl
	 << "-----------------------\n";
  }
  outF.close();
}
