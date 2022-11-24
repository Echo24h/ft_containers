/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:21:32 by gborne            #+#    #+#             */
/*   Updated: 2022/11/24 02:27:01 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "utils.hpp"
# include "map_tree.hpp"
# include "map_iterator.hpp"
# include "map_riterator.hpp"
# include <iostream>

namespace ft
{

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator< ft::node<const Key,T> > >
class map {

public:

	// MEMBER TYPES

	typedef				Key															key_type;
	typedef				T															mapped_type;
	typedef				pair<const key_type,mapped_type>							value_type;
	typedef				Compare														key_compare;

	class value_compare
	{
	protected:
		key_compare comp;
		value_compare (key_compare c) : comp(c) {}
	public:
		bool operator() (const value_type& x, const value_type& y) const {
			return comp(x.first, y.first);
		}
	};

	typedef				Alloc														allocator_type;
	typedef typename	allocator_type::reference									reference;
	typedef typename	allocator_type::const_reference								const_reference;
	typedef typename	allocator_type::pointer										pointer;
	typedef typename	allocator_type::const_pointer								const_pointer;

	typedef				ft::map_tree<const key_type, mapped_type, allocator_type>	bstree;
	typedef				ft::node<const key_type,mapped_type>						node;
	typedef				node *														node_pointer;

	typedef				ft::map_iterator<bstree, value_type>						iterator;
	typedef				ft::map_iterator<bstree, const value_type>					const_iterator;
	typedef				ft::map_riterator<iterator>									reverse_iterator;
	typedef				ft::map_riterator<const_iterator>							const_reverse_iterator;

	typedef typename	iterator_traits<iterator>::difference_type					difference_type;
	typedef typename	allocator_type::size_type									size_type;

	// CONSTRUCTOR

	explicit	map(const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type())
			: _comp(comp), _alloc(alloc), _tree(bstree()) {
		return ;
	}

	template <class InputIterator>
	map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
		_comp = comp;
		_alloc = alloc;
		_tree = bstree();
		insert(first, last);
		return ;
	}

	map( map const & src ) {
		*this = src;
		return ;
	}

	// DESTRUCTOR

	~map( void ) { return ; }

	// OPERATOR=

	map &	operator=( map const & rhs ) {
		_comp = rhs._comp;
		_alloc = rhs._alloc;
		_tree = rhs._tree;
		return *this;
	}

	// ITERATORS

	iterator begin() {
		if (size() <= 0)
			return iterator(_tree.end(), _tree.end());
		return iterator(_tree.min(), _tree.end());
	}

	const_iterator begin() const {
		if (size() <= 0)
			return const_iterator(_tree.end(), _tree.end());
		return const_iterator(_tree.min(), _tree.end());
	}

	iterator end() { return iterator(_tree.end(), _tree.end()); }

	const_iterator end() const { return const_iterator(_tree.end(), _tree.end()); }

	const_iterator cbegin() const {
		if (size() <= 0)
			return const_iterator(_tree.end(), _tree.end());
		return const_iterator(_tree.min(), _tree.end());
	}

	const_iterator cend() const { return const_iterator(_tree.end(), _tree.end()); }

	reverse_iterator rbegin() {
		if (size() <= 0)
			return reverse_iterator(iterator(_tree.end(), _tree.end(), true));
		return reverse_iterator(iterator(_tree.max(), _tree.end(), true));
	}

	const_reverse_iterator rbegin() const {
		if (size() <= 0)
			return reverse_iterator(const_iterator(_tree.end(), _tree.end(), true));
		return const_reverse_iterator(const_iterator(_tree.max(), _tree.end(), true));
	}

	reverse_iterator rend() { return reverse_iterator(iterator(_tree.end(), _tree.end(), true)); }

	const_reverse_iterator rend() const { return const_reverse_iterator(const_iterator(_tree.end(), _tree.end(), true)); }

	const_reverse_iterator	crbegin( void ) {
		if (size() <= 0)
			return const_reverse_iterator(const_iterator(_tree.end(), _tree.end(), true));
		return const_reverse_iterator(const_iterator(_tree.max(), _tree.end(), true));
	}

	const_reverse_iterator	crend( void ) { return const_reverse_iterator(const_iterator(_tree.end(), _tree.end(), true)); }

	// CAPACITY

	bool empty() const { return !(_tree.size() > 0); }

	size_type size() const { return _tree.size(); }

	size_type max_size() const { return _tree.max_size(); }

	// ELEMENTS ACCESS

	mapped_type & operator[] ( const key_type & k ) {

		node_pointer node = _tree.search(k);

		if (node == NULL)
			node = _tree.insert(value_type(k, mapped_type()));
		return node->data.second;
	}

	mapped_type & at ( const key_type & k ) {

		node_pointer node = _tree.search(k);

		if (node == NULL)
			throw std::out_of_range("Error: ft::map::at - Out of range exception");
		return node->data.second;
	}

	const mapped_type & at ( const key_type & k ) const {
		node_pointer node = _tree.search(k);

		if (node == NULL)
			throw std::out_of_range("Error: ft::map::at - Out of range exception");
		return node->data.second;
	}


	// MODIFIERS

	pair<iterator,bool>	insert ( const value_type & val ) {

		node_pointer node = _tree.insert(val);

		if (node == NULL)
			return pair<iterator,bool>(iterator(_tree.search(val.first), _tree.end()), false);

		return pair<iterator,bool>(iterator(node, _tree.end()), true);
	}

	iterator insert ( iterator position, const value_type & val ) {

		node_pointer node = _tree.search(val.first);

		if (node == NULL) {

			node_pointer target = _tree.search(position->first);

			return iterator(_tree.insert(val, target, target->top), _tree.end());
		}
		return iterator(node, _tree.end());
	}

	template <class InputIterator>
	void insert ( InputIterator first, InputIterator last ) {

		while (first != last) {
			insert(*first);
			first++;
		}

		return ;
	}

	void erase ( iterator position );

	size_type erase ( const key_type & k );
	
    void erase ( iterator first, iterator last );

	void clear() { _tree.clear(); return ; }

private:

	key_compare		_comp;
	allocator_type	_alloc;
	bstree			_tree;

};

} // namespace ft

#endif
