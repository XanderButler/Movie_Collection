/**
 * @file library.h
 * @author1 
 * @author2 Jacqueline Bybee
 * @date 2024-03-29
 * @brief Header file for the library class.
 * 
 * Declares all functions of Library, giving the abiltiy to create linked lists.
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include <list>
#include <string>
#include <iostream>
#include <fstream>

struct Movie {
    std::string title;
    std::string director;
    int runtime;
    std::string format;
    float price;
    int year;


/**
 * Displays the elemets of the movie in a set format.
 *
 * @pre needs a movie to exist.
 * @return void 
 * @post the Movie will be displayed
 * 
 */
    void display() const;
};

class Library {
private:
  std::list<Movie> movies;

public:

/**
 * inserts a struct (movie) to the list of movies. In a sorted manor. 
 *
 * @param const Movie& movie struct movie being inserted. 
 * @pre a list needs to exist
 * @return void 
 * @post the movie will be added to the list
 * 
 */
  void insertMovie(const Movie& movie);

/**
 * Searches through the list of movie titles and displays the promted movie.
 *
 * @param const std::string& searchStr The promted movie to find.
 * @pre A list of movies need to exist
 * @return void 
 * @post The list will be searched through and the movie will be displayed
 * 
 */
  void findMovie(const std::string& searchStr) const;

/**
 * Searches through the list of movies by name of director
 *
 * @param const std::string& director The promted director being searched for. 
 * @pre A list of movies need to exist
 * @return void 
 * @post The promted movie will be displayed.
 * 
 */
  void directorSearch(const std::string& director) const;

/**
 * Removes a specific movie from the list.
 *
 * @param const std::string& title The title of the movie to be removed
 * @pre the movie needs to be in the list.
 * @return void 
 * @post that movie no longer exists in the list.
 * 
 */
  void removeMovie(const std::string& title);

/**
 * displays the whole list of movies with all elements formated
 *
 * @pre A list of movies need to exist
 * @return void 
 * @post the whole list will exist.
 * 
 */
  void displayAll() const;

/**
 * loads movies from a txt file formated correctly
 *
 * @param std::list<Movie> &movies List of movies being made.
 * @param std::string inFile the name of the file being inported from.
 * @pre a list needs to exist, and the file needs to be formated.
 * @return void 
 * @post The file of movies will be inserted into the list.
 * 
 */
  void loadFromFile(std::list<Movie> &movies, std::string inFile);

/**
 * Stores the list of Movies into a txt file
 *
 * @param const std::list<Movie> &movies The list of movies being exported. 
 * @param std::string outFile The name of the file being exported too.
 * @pre A list of movies need to exist
 * @return void 
 * @post A names txt file will be created and hold the list of movies.
 * 
 */
  void storeToFile(const std::list<Movie> &movies, std::string outFile);
};

#endif
