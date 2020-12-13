#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <iostream>
#include <memory>
#include <exception>

namespace data_structures {
	template <class T>
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
		void set_next(node_ptr next);
		void set_prev(node_ptr prev);
	}; // end node

	template <class T>
	class list {
		typedef std::shared_ptr<node<T>> node_ptr;
	private:
	    int length;
		node_ptr m_head;
	public:
		list();
		explicit list(node_ptr head);
		list(const list& cp_list);
		virtual ~list();

		bool empty() const;

		void add_node(const T& data);
		void insert(const T& data);
		void delete_node(node_ptr del_node);

		auto search(node_ptr s_node) const;

		void fwd_traverse() const;
		void bkd_traverse() const;

		void clear();
	}; // end list

	// -------------------------------------------------
	// node
	template<class T>
	node<T>::node(const T& data) {
		m_data = data;
		m_next = nullptr;
		m_prev = nullptr;
	}

	template<class T>
	node<T>::node(const T& data, node_ptr next) {
		m_data = data;
		m_next = next;
		m_prev = nullptr;
	}

	template<class T>
	node<T>::node(const T& data, node_ptr next, node_ptr prev) {
		m_data = data;
		m_next = next;
		m_prev = prev;
	}

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
	void node<T>::set_data(const T& data) {
		m_data = data;
	}

	template<class T>
	void node<T>::set_next(node_ptr next) {
		m_next = next;
	}

	template<class T>
	void node<T>::set_prev(node_ptr prev) {
		m_prev = prev;
	}
	// end node member function definitions

	// list
	template<class T>
	list<T>::list() : m_head(nullptr) {}

	template<class T>
	list<T>::list(node_ptr head) : m_head(head) {}

	template<class T>
	list<T>::list(const list<T>& cp_list) {

	}

	template<class T>
	list<T>::~list() {
		clear();
	}

	template <class T>
	bool list<T>::empty() const {
	    return length == 0;
	}

	template<class T>
	void list<T>::add_node(const T& data) {
		auto new_node = std::make_shared<node<T>>(data);
		if (new_node->get_next() == nullptr) {
			new_node->set_next(m_head);
			m_head = new_node;
		}
		else {
			auto tmp = m_head;
			while (tmp->get_next() != nullptr) {
				tmp = tmp->get_next();
			}
			tmp->set_next(new_node);
		}

	}

	template <class T>
	void list<T>::insert(const T& data) {

	}

	template<class T>
	void list<T>::delete_node(node_ptr del_node) {

	}

	template <class T>
	auto list<T>::search(node_ptr s_node) const {

	}

	template <class T>
	void list<T>::fwd_traverse() const {
		auto current_ptr = m_head;
		while (current_ptr != nullptr) {
			std::cout << current_ptr->get_data() << "-->";
			current_ptr = current_ptr->get_next();
		}
		std::cout << std::endl;
	}

	template <class T>
	void list<T>::bkd_traverse() const {

	}

	template<class T>
	void list<T>::clear() {
		m_head.reset();
	}
}






#endif // DATA_STRUCTURES_H
