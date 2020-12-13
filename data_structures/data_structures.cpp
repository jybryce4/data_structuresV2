#include "data_structures.h"
using namespace data_structures;
// node
template<class T>
node<T>::node(const T &data) : m_data(data), m_next(nullptr), m_prev(nullptr) {}

template<class T>
node<T>::node(const T &data, const node_ptr &next) : m_data(data), m_next(next), m_prev(nullptr) {}

template<class T>
node<T>::node(const T &data, const node_ptr &next, const node_ptr &prev)
        : m_data(data), m_next(next), m_prev(prev) {}

template<class T>
node<T>::~node() {
    m_next.reset();
    m_prev.reset();
}

template<class T>
T node<T>::get_data() const {
    return m_data;
}

template<class T>
auto node<T>::get_next() const {
    return m_next;
}

template<class T>
auto node<T>::get_prev() const {
    return m_prev;
}

template<class T>
void node<T>::set_data(const T &data) {
    m_data = data;
}

template<class T>
void node<T>::set_next(const node_ptr &next) {
    m_next = next;
}

template<class T>
void node<T>::set_prev(const node_ptr &prev) {
    m_prev = prev;
}
// end node member function definitions

// list
template<class T>
list<T>::list() : m_head(nullptr) {}

template<class T>
list<T>::list(const node_ptr &head) : m_head(head) {}

template<class T>
list<T>::list(const list<T> &cp_list) {

}

template<class T>
list<T>::~list() {
    clear();
}

template<class T>
void list<T>::add_node(const node_ptr &a_node) {

}

template <class T>
void list<T>::insert(const node_ptr& i_node) {

}

template<class T>
void list<T>::delete_node(const node_ptr &del_node) {

}

template<class T>
void list<T>::clear() {
    m_head.reset();
}


