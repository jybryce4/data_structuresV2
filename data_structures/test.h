#ifndef TEST_H
#define TEST_H

#include <iostream>

#include "data_structures.h"

using std::cout;
using std::endl;

void list_tester() {
    data_structures::list<int> my_list;
    data_structures::list<int> my_other_list;

    for (int i = 0; i < 10; i++) {
        my_list.add_node(i);
    }

    for (int j = 10; j < 20; j++) {
        my_other_list.add_node(j);
    }

    cout << "my_list.fwd_traverse(): ";
    my_list.fwd_traverse();

    cout << "my_other_list.fwd_traverse(): ";
    my_other_list.fwd_traverse();

    my_list = my_other_list;

    cout << "Copied my_other_list into my_list..." << endl;
    my_list.fwd_traverse();
}

#endif
