//
// Created by jamey on 12/19/2020.
//

#include "Book.h"

Book::Book(std::string title, std::string author, long long isbn)
            : m_title(title), m_author(author), m_isbn(isbn) { }

long long Book::get_isbn() const {
    return m_isbn;
}

std::string Book::get_title() const {
    return m_title;
}

std::string Book::get_author() const {
    return m_author;
}

std::ostream& Book::operator<<(const Book &book) const {
    std::ostream* os;
    /*
     * Title: Book Title
     * Author: Author Name
     */

    *os << "Title: " << book.get_title() << "\n"
        << "Author: " << book.get_author() << "\n";

    return *os;
}
