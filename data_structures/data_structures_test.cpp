#include "test.h"

int main() {
	data_structures::list<int> my_list;

	for (int i = 0; i < 10; i++) {
	    my_list.add_node(i);
	}
	
	my_list.fwd_traverse();


	return 0;
}