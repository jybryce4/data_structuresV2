#include "user_types.h"

namespace user_types {
    Book::Book(std::string title, std::string author, long long isbn)
        : m_title(title), m_author(author), m_isbn(isbn) {}

    long long Book::get_isbn() const {
        return m_isbn;
    }

    std::string Book::get_title() const {
        return m_title;
    }

    std::string Book::get_author() const {
        return m_author;
    }

    std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << "\n\t" << book.get_title() << "\n"
            << "\tBy " << book.get_author() << "\n"
            << "\tISBN#" << book.get_isbn() << "\n";

        return os;
    }
}
