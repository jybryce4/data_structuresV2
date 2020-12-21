#ifndef TEST_H
#define TEST_H

#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

#include "data_structures.h"
#include "user_types.h"

namespace list_tests {
    template<class T>
    auto list_creator(const std::vector<T>& data_items);

    //auto test_array_creator();

    void list_tester();

    // ------------------------------------------------------
    
    template<class T>
    auto list_creator(const std::vector<T> &data_items) {
        data_structures::list<T> r_list;
        for (int i = 0; i < data_items.size(); i++) {
            r_list.push(data_items[i]);
        }
        return r_list;
    }

    /*auto test_array_creator() {
        srand(time(nullptr));
        int num_tests = rand() % 10 + 1;

        std::vector<int> test_array;
        for (int i = 0; i < num_tests; i++) {
            int rand_num = rand() % 1000 + 1;
            test_array.push_back(rand_num);
        }

        return test_array;
    }*/

    void list_tester() {
        std::vector<int> test_array;
        data_structures::list<int> my_list = list_creator([&test_array](){
            srand(time(nullptr));
            int num_tests = rand() % 10 + 1;
            for (int i = 0; i < num_tests; i++) {
                int rand_num = rand() % 1000 + 1;
                test_array.push_back(rand_num);
            }
            return test_array;
        }());

        std::cout << "my_list.fwd_traverse(): ";
        my_list.fwd_traverse();
        std::cout << "my_list.bkd_traverse(): ";
        my_list.bkd_traverse();

        std::cout << std::endl;

        std::vector<std::string> names = {"Jamey", "Xhalite", "Keita", "Kino", "Andrea"};
        data_structures::list<std::string> str_list = list_creator(names);
       
        std::cout << "str_list.fwd_traverse(): ";
        str_list.fwd_traverse();
        std::cout << "str_list.bkd_traverse(): ";
        str_list.bkd_traverse();

        user_types::Book lotr("Fellowship of the Ring", "JRR Tolkien", 9780007117116);
        user_types::Book mistborn("The Final Empire", "Brandon Sanderson", 9780765360960);
        user_types::Book wot("The Eye of the World", "Robert Jordan", 9780812511819);

        std::vector<user_types::Book> books = { lotr, mistborn, wot };

        data_structures::list<user_types::Book> book_list = list_creator(books);

        std::cout << std::endl;
        std::cout << "\tBooks (forward): \n" 
                  << "\t---------------------";
        book_list.fwd_traverse();
        std::cout << std::endl;
        std::cout << "\tBooks (backward): \n"
                  << "\t---------------------";
        book_list.bkd_traverse();

        std::vector<int> items;
        data_structures::list<int> another_list = list_creator([&items]() {
            for (int i = 1; i <= 10; i++) {
                items.push_back(i);
            }
            return items;
        }());

        std::cout << std::endl;

        std::cout << "Created another list: ";
        another_list.fwd_traverse();
        std::cout << "Inserting 30 after position 5...\n";
        another_list.insert_after(5, 30);
        std::cout << "Forward traverse: ";
        another_list.fwd_traverse();
        std::cout << "Backward traverse: ";
        another_list.bkd_traverse();

    } // end list_tester
} // end test

#endif // TEST_H
