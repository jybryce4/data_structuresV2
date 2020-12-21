#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <iostream>
#include <memory>
#include <exception>

namespace data_structures {
    inline namespace containers {
        template<class T>
        class node {
            typedef std::shared_ptr<node<T>> node_ptr;
        private:
            T m_data;
            node_ptr m_next;
            node_ptr m_prev;
        public:
            explicit node(const T& data);

            node(const T& data, node_ptr next);

            node(const T& data, node_ptr next, node_ptr prev);

            virtual ~node();

            T get_data() const;

            auto get_next() const;

            auto get_prev() const;

            void set_data(const T& data);

            void set_next(const node_ptr& next);

            void set_prev(const node_ptr& prev);

            void clear();
        }; // end node

        template<class T>
        class list {
            typedef std::shared_ptr<node<T>> node_ptr;
        private:
            int m_length;
            node_ptr m_head;
            node_ptr m_tail;

            auto get_node_at(int position) const;
        public:
            list();

            explicit list(node_ptr head);

            list(const list& cp_list);

            virtual ~list();

            bool empty() const;

            int length() const;

            void push(const T& data);

            void insert_after(int position, const T& data);

            void delete_node(int position);

            T get_entry(int position) const;

            void fwd_traverse() const;

            void bkd_traverse() const;

            void clear();
        }; // end list

        template<class T>
        class stack {
        private:
            int m_top;
            std::vector<T> m_stack;
            int m_size;
        public:
            stack();
            explicit stack(const T& data);
            stack(const stack<T>& cp_stack);
            virtual ~stack();

            void push(const T& data);

            T peek() const;

            void pop();

            int size() const;

            bool empty() const;
        };

        // -------------------------------------------------

        // node
        template<class T>
        node<T>::node(const T& data) : m_data(data), m_next(nullptr), m_prev(nullptr) {}

        template<class T>
        node<T>::node(const T& data, node_ptr next) : m_data(data), m_next(next), m_prev(nullptr) {}

        template<class T>
        node<T>::node(const T& data, node_ptr next, node_ptr prev)
            : m_data(data), m_next(next), m_prev(prev) {}

        template<class T>
        node<T>::~node() {
            clear();
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
        void node<T>::set_data(const T& data) {
            m_data = data;
        }

        template<class T>
        void node<T>::set_next(const node_ptr& next) {
            m_next = next;
        }

        template<class T>
        void node<T>::set_prev(const node_ptr& prev) {
            m_prev = prev;
        }

        template<class T>
        void node<T>::clear() {
            m_next.reset();
            m_prev.reset();
        }
        // end node member function definitions

        // -------------------------------------------------

        // list
        template<class T>
        list<T>::list() : m_head(nullptr), m_tail(nullptr), m_length(0) {}

        template<class T>
        list<T>::list(node_ptr head) : m_head(head), m_tail(nullptr), m_length(0) {}

        template<class T>
        list<T>::list(const list<T>& cp_list) : m_length(cp_list.m_length), m_tail(cp_list.m_tail) {
            auto original_head_ptr = cp_list.m_head;
            if (original_head_ptr == nullptr) {
                m_head.reset();
                m_tail.reset();
            }
            else {
                m_head = std::make_shared<node<T>>(original_head_ptr->get_data());

                auto new_list_ptr = m_head;
                original_head_ptr = original_head_ptr->get_next();
                while (original_head_ptr != nullptr) {
                    T next_item = original_head_ptr->get_data();
                    auto new_node_ptr = std::make_shared<node<T>>(next_item);

                    new_list_ptr->set_next(new_node_ptr);
                    new_list_ptr->set_prev(original_head_ptr->get_prev());

                    new_list_ptr = new_list_ptr->get_next();
                    original_head_ptr = original_head_ptr->get_next();
                } // end while
                new_list_ptr->set_next(nullptr); // flag end of list
            } // end if
        } // end copy constructor

        template<class T>
        list<T>::~list() {
            clear();
        }

        template<class T>
        bool list<T>::empty() const {
            return m_length == 0;
        }

        template<class T>
        int list<T>::length() const {
            return m_length;
        }

        template<class T>
        void list<T>::push(const T& data) {
            if (m_head == nullptr) {
                m_head = std::make_shared<node<T>>(data);
                m_tail = nullptr;
            }
            else {
                if (m_tail == nullptr) {
                    m_tail = std::make_shared<node<T>>(data);
                    m_head->set_next(m_tail);
                    m_tail->set_prev(m_head);
                }
                else {
                    auto prev_tail = m_tail;
                    auto new_tail = std::make_shared<node<T>>(data);
                    new_tail->set_prev(prev_tail);
                    prev_tail->set_next(new_tail);
                    m_tail = new_tail;
                }
            }
            m_length++;
        } // end push

        template<class T>
        void list<T>::insert_after(int position, const T& data) {
            if (empty() || position < 1 || position > m_length) {
                throw std::domain_error("Error: list is empty or the position is invalid.");
            }

            // auto node_before = get_node_at(position);
            auto new_node = std::make_shared<node<T>>(data);

            new_node->set_prev(get_node_at(position));
            new_node->set_next(get_node_at(position)->get_next());

            get_node_at(position)->set_next(new_node);
            get_node_at(position)->get_next()->set_prev(new_node);

            m_length++;
        } // end insert_after

        template<class T>
        void list<T>::delete_node(int position) {
            if (this->empty() || position < 1 || position > m_length) {
                throw std::domain_error("Error: list is empty or the position is invalid.");
            }

            auto node_to_delete = get_node_at(position);
            auto node_before = node_to_delete->get_prev();
            auto node_after = node_to_delete->get_next();

            node_before->set_next(node_after);
            node_after->set_prev(node_before);

            m_length--;
        } // end delete_node

        template<class T>
        auto list<T>::get_node_at(int position) const {
            auto current = m_head;
            for (int count = 1; count < position; count++) {
                current = current->get_next();
            }
            return current;
        } // end get_node_at

        template<class T>
        T list<T>::get_entry(int position) const {
            if ((position >= 1) && (position <= m_length)) {
                auto nd_ptr = get_node_at(position);
                return nd_ptr->get_data();
            }
            else {
                throw std::domain_error("Error: get_entry called with invalid position or empty list.");
            }
        } // end get_entry

        template<class T>
        void list<T>::fwd_traverse() const {
            for (int i = 1; i <= this->length(); i++) {
                std::cout << this->get_entry(i) << "  ";
            }
            std::cout << std::endl;
        } // end fwd_traverse

        template<class T>
        void list<T>::bkd_traverse() const {
            for (int i = this->length(); i >= 1 ; i--) {
                std::cout << this->get_entry(i) << "  ";
            }
            std::cout << std::endl;
        } // end bkd_traverse

        template<class T>
        void list<T>::clear() {
            m_head.reset();
            m_tail.reset();
            m_length = 0;
        } // end clear
        // end list member function declarations

        // ------------------------------------------------

        // stack
        template<class T>
        stack<T>::stack() : m_top(-1), m_size(0) {}

        template<class T>
        stack<T>::stack(const T& data) : m_top(0), m_size(1) {
            push(data);
        }
    }
    
}

#endif // DATA_STRUCTURES_H
