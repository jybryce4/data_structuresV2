#ifndef TEST_H
#define TEST_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "data_structures.h"

namespace test {
    template<class T>
    auto list_creator(const std::vector<T> &data_items) {
        data_structures::list<T> r_list;
        for (int i = 0; i < data_items.size(); i++) {
            r_list.push(data_items[i]);
        }
        return r_list;
    }

    auto test_array_creator() {
        srand(time(nullptr));
        int num_tests = rand() % 10 + 1;

        std::vector<int> test_array;
        for (int i = 0; i < num_tests; i++) {
            int rand_num = rand() % 1000 + 1;
            test_array.push_back(rand_num);
        }

        return test_array;
    }

    void list_tester() {
        data_structures::list<int> my_list = list_creator(test_array_creator());

        std::cout << "my_list.fwd_traverse(): ";
        my_list.fwd_traverse();
        std::cout << "my_list.bkd_traverse(): ";
        my_list.bkd_traverse();
    }
}

#endif
