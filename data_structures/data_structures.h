#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

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
		node(const T& data, const node_ptr& next);
		node(const T& data, const node_ptr& next, const node_ptr& prev);
		virtual ~node();

		T get_data() const;
		auto get_next() const;
		auto get_prev() const;

		void set_data(const T& data);
		void set_next(const node_ptr& next);
		void set_prev(const node_ptr& prev);
	}; // end node

	template <class T>
	class list {
		typedef std::shared_ptr<node<T>> node_ptr;
	private:
		node_ptr m_head;
	public:
		list();
		explicit list(const node_ptr& head);
		list(const list& cp_list);
		virtual ~list();

		void add_node(const node_ptr& a_node);
		void insert(const node_ptr& i_node);
		void delete_node(const node_ptr& del_node);

		void clear();
	}; // end list

	template <class T>
	class stack {

	};

	template <class T>
	class queue {

	};

	template <class T>
	class binary_search_tree {

	};

	template <class T>
	class set {

	};

	template <class T>
	class map {

	};

	template <class T>
	class hash_map {

	};
}

#endif // DATA_STRUCTURES_H
