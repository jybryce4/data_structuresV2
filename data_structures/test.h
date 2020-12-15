#ifndef TEST_H
#define TEST_H

#include <iostream>

#include "data_structures.h"

using std::cout;
using std::endl;

namespace test {
    void list_tester() {
        data_structures::list<int> my_list;
        data_structures::list<int> my_other_list;

        for (int i = 0; i < 10; i++) {
            my_list.push(i);
        }

        for (int j = 10; j < 20; j++) {
            my_other_list.push(j);
        }

        cout << "my_list.fwd_traverse(): ";
        my_list.fwd_traverse();

        cout << "my_other_list.fwd_traverse(): ";
        my_other_list.fwd_traverse();

        my_list = my_other_list;

        cout << "Copied my_other_list into my_list..." << endl;
        my_list.fwd_traverse();

        cout << "Creating empty list..." << endl;
        data_structures::list<int> empty_list;
        try {
            empty_list.get_entry(1);
        } catch (const std::domain_error &error) {
            cout << error.what() << endl;
        }
    }
}


#endif
