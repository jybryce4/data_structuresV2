//
// Created by jamey on 12/19/2020.
//

#ifndef DATA_STRUCTURES_BOOK_H
#define DATA_STRUCTURES_BOOK_H

#include <ostream>
#include <string>

class Book {
private:
    long long m_isbn;
    std::string m_title;
    std::string m_author;
public:
    Book(std::string title, std::string author, long long isbn);

    long long get_isbn() const;
    std::string get_title() const;
    std::string get_author() const;

    std::ostream& operator<<(const Book &book) const;
};


#endif //DATA_STRUCTURES_BOOK_H
