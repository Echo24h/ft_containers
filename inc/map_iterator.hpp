/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:29:54 by gborne            #+#    #+#             */
/*   Updated: 2022/11/21 15:49:29 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include <iterator>
# include <cstddef>
# include "utils.hpp"

namespace ft {

template < class Tree, class T >
class map_iterator {

public:

	// MEMBERS TYPE

	typedef typename Tree::node				node;
	typedef node *							node_pointer;

	typedef	T								value_type;
	typedef ptrdiff_t						difference_type;
	typedef value_type *					pointer;
	typedef value_type &					reference;
	typedef std::bidirectional_iterator_tag	iterator_category;

	// CONSTRUCTOR

	map_iterator( void ) : _ptr(0), _end(NULL), _reverse(false) { return ; }

	map_iterator( node_pointer ptr,  node_pointer end, bool reverse = false ) : _ptr(ptr), _end(end), _reverse(reverse) { return ; }

	map_iterator( map_iterator const & src ) { *this = src; return ; }

	virtual	~map_iterator( void ) { return ; }

	// EQUALITY

	bool	operator==( map_iterator const & rhs ) {
		return (_ptr == rhs._ptr);
	}

	bool	operator!=( map_iterator const & rhs ) {
		return (_ptr != rhs._ptr);
	}

/*	// UTILS

	node_pointer	get_node( void ) const {
		return _ptr;
	} */

	// DEREFERENCE

	reference operator*() const {
		//if (_ptr == NULL)
		//	return value_type(0, 0);
		return _ptr->data;
	};

	pointer operator->() const {
		//if (_ptr == NULL)
	//		return value_type(0, 0);
		return &_ptr->data;
	};

	map_iterator &	operator=( map_iterator const & rhs ) {
		_ptr = rhs._ptr;
		_end = rhs._end;
		_reverse = rhs._reverse;
		return *this;
	}

	// INCREMENT

	map_iterator & operator++() { // Prefix increment

		if (_ptr == NULL) {
			return *this;
		}

		if (_ptr == _end->right) {
			if (_reverse == true)
				operator--();
			else
				_ptr = _end;
		}
		else if (_ptr == _end) {
			if (_reverse == true)
				_ptr = _end->left;
			else
				_ptr = _end->right;
		}
		else if (_ptr->right != NULL) {
			_ptr = _min(_ptr->right);
		}
		else {
			node_pointer	parent = _ptr->top;
			while (parent != NULL && _ptr == parent->right) {
				_ptr = parent;
				parent = parent->top;
			}
			_ptr = parent;
		}
		return *this;
	}

	map_iterator operator++( int ) { map_iterator tmp = *this; operator++(); return tmp; } // Postfix increment

	// DECREMENT

	map_iterator & operator--() { // Prefix increment

		if (_ptr == NULL) {
			return *this;
		}

		if (_ptr == _end->left) {
			_ptr = _end;
		}
		else if (_ptr == _end) {
			_ptr = _end->right;
		}
		else if (_ptr->left != NULL)
			_ptr = _max(_ptr->left);
		else {
			node_pointer	parent = _ptr->top;
			while (parent != NULL && _ptr == parent->left) {
				_ptr = parent;
				parent = parent->top;
			}
			_ptr = parent;
		}
		return *this;
	}

	map_iterator operator--( int ) { map_iterator tmp = *this; operator--(); return tmp; } // Postfix increment

private:

	node_pointer	_min( const node_pointer node ) {

		if (node == NULL)
			return NULL;

		node_pointer cur = node;

		while(cur->left != NULL)
			cur = cur->left;
		return cur;
	}

	node_pointer	_max( const node_pointer node ) {

		if (node == NULL)
			return NULL;

		node_pointer cur = node;

		while(cur->right != NULL)
			cur = cur->right;
		return cur;
	}

	node_pointer	_ptr;
	node_pointer	_end;
	bool			_reverse;
};

} // namespace ft


#endif
