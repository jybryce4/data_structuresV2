#ifndef DATA_STRUCTURES_USER_TYPES_H
#define DATA_STRUCTURES_USER_TYPES_H

#include <ostream>
#include <string>

namespace user_types {
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

        std::ostream& operator<<(const Book &book);
    };
} // namespace user_types

#endif