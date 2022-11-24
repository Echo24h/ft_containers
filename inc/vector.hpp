/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:20:28 by gborne            #+#    #+#             */
/*   Updated: 2022/11/24 23:05:07 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "simple_iterator.hpp"
# include "reverse_iterator.hpp"
# include "utils.hpp"

namespace ft {

template < class T, class Alloc = std::allocator<T> >
class vector {

public:

	// MEMBERS TYPE

	typedef				T											value_type;
	typedef				Alloc										allocator_type;

	typedef typename	allocator_type::reference					reference;
	typedef typename	allocator_type::const_reference				const_reference;
	typedef typename	allocator_type::pointer						pointer;
	typedef typename	allocator_type::const_pointer				const_pointer;

	typedef				ft::simple_iterator<value_type>				iterator;
	typedef				ft::simple_iterator<const value_type>		const_iterator;
	typedef				ft::reverse_iterator<iterator>				reverse_iterator;
	typedef				ft::reverse_iterator<const_iterator>		const_reverse_iterator;

	typedef typename	iterator_traits<iterator>::difference_type	difference_type;
	typedef typename	allocator_type::size_type					size_type;

	// CANONICAL FORM

	explicit vector( const allocator_type & alloc = allocator_type() )
		: _alloc(alloc), _ptr(0), _size(0), _capacity(0) {
		return ;
	}

	explicit vector( size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type() )
		: _alloc(alloc), _size(n), _capacity(n) {
		_ptr = _alloc.allocate(_capacity);
		for (size_type i = 0; i < _size; i++)
			_alloc.construct(&_ptr[i], val);
		return ;
	}

	template <class InputIterator>
	vector( InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
	typename ft::enable_if<!is_integral<InputIterator>::value, bool>::type = true )
		: _alloc(alloc) {
		_size = static_cast<size_type>(last - first);
		_capacity = _size;
		_ptr = _alloc.allocate(_capacity);
		assign(first, last);
		return ;
	}

	vector( vector const & src ) : _capacity(0) {
		*this = src;
		return ;
	}

	vector &	operator=( vector const & rhs ) {
		if (_capacity > 0)
			_alloc.deallocate(_ptr, _capacity);
		_alloc = rhs._alloc;
		_capacity = rhs._capacity;
		_ptr = _alloc.allocate(_capacity);
		_size = rhs._size;
		for (size_type i = 0; i < _size; i++)
			_ptr[i] = rhs._ptr[i];
		return *this;
	}

	~vector( void ) {
		while (_size)
			_alloc.destroy(&_ptr[--_size]);
		if (_capacity > 0) {
			_alloc.deallocate(_ptr, _capacity);
		}
		std::cout << "destructor vector" << std::endl;
		return ;
	}

	// ITERATORS

	iterator	begin( void ) { return iterator(_ptr); }

	const_iterator begin() const { return const_iterator(_ptr); }

	iterator	end( void ) { return iterator(&_ptr[_size]); }

	const_iterator end() const { return const_iterator(&_ptr[_size]); }

	const_iterator	cbegin( void ) { return const_iterator(_ptr); }

	const_iterator	cend( void ) { return const_iterator(&_ptr[_size]); }

	reverse_iterator	rbegin( void ) { return reverse_iterator(&_ptr[_size] - 1); }

	const_reverse_iterator rbegin() const { return const_reverse_iterator(&_ptr[_size] - 1); }

	reverse_iterator	rend( void ) { return reverse_iterator(_ptr - 1); }

	const_reverse_iterator rend() const { return const_reverse_iterator(_ptr - 1); }

	const_reverse_iterator	crbegin( void ) { return const_reverse_iterator(&_ptr[_size] - 1); }

	const_reverse_iterator	crend( void ) { return const_reverse_iterator(_ptr - 1); }

	// CAPACITY

	size_type	size( void ) const { return _size; };

	size_type	max_size( void ) const { return _alloc.max_size(); };

	// a opti avec insert() ?
	void resize (size_type n, value_type val = value_type()) {
		if (n > _capacity && _size != _capacity)
			reserve(n);
		if (n < _size) {
			while(n < _size)
				pop_back();
		} else if (n > _size) {
			while(n > _size)
				push_back(val);
		}
		return ;
	}

	size_type	capacity( void ) const { return _capacity; };

	bool empty() const {
		if (_size == 0)
			return true;
		return false;
	}

	void reserve( size_type n ) {

		pointer	new_alloc;

		if (n > max_size())
			throw std::length_error("Error: ft::vector::reserve - Length max exception");
		if (n > _capacity) {
			new_alloc = _alloc.allocate(n);
			for (size_type i = 0; i < _size; i++)
				new_alloc[i] = _ptr[i];
			if (_capacity > 0)
				_alloc.deallocate(_ptr, _capacity);
			_ptr = new_alloc;
			_capacity = n;
		}
		return ;
	}

	void shrink_to_fit( void ) {

		pointer	new_alloc;

		if (_capacity > _size) {
			new_alloc = _alloc.allocate(_size);
			for (size_type i = 0; i < _size; i++)
				new_alloc[i] = _ptr[i];
			_alloc.deallocate(_ptr, _capacity);
			_ptr = new_alloc;
			_capacity = _size;
		}
		return ;
	}

	// ELEMENT ACCESS

	reference operator[] (size_type n) { return _ptr[n]; }

	const_reference operator[] (size_type n) const { return _ptr[n]; }

	reference at (size_type n) {
		if (n >= _size)
			throw std::out_of_range("Error: ft::vector::at - Out of range exception");
		return _ptr[n];
	}

	const_reference at (size_type n) const {
		if (n >= _size)
			throw std::out_of_range("Error: ft::vector::at - Out of range exception");
		return _ptr[n];
	}

	reference front() { return _ptr[0]; }

	const_reference front() const { return _ptr[0]; }

	reference back() { return _ptr[_size - 1]; }

	const_reference back() const { return _ptr[_size - 1]; }

	value_type* data() { return _ptr; }

	const value_type* data() const { return _ptr; }

	// MODIFIERS

	template <class InputIterator>
	void	assign( InputIterator first, InputIterator last,
	typename ft::enable_if<!is_integral<InputIterator>::value, bool>::type = true ) {
		clear();
		if (static_cast<size_type>(last - first) > _capacity)
			reserve(static_cast<size_type>(last - first));
		while(first != last)
			push_back(*first++);
		return ;
	}

	void	assign( size_type n, const value_type & val ) {
		clear();
		if (n > _capacity)
			reserve(n);
		while(n--)
			push_back(val);
		return ;
	}

	void	push_back( const value_type	& value ) {
		if (_size + 1 > _capacity) {
			if (_capacity == 0)
				reserve(1);
			else
				reserve(_capacity << 1);
		}
		_alloc.construct(&_ptr[_size], value);
		_size++;
		return ;
	}

	void	pop_back( void ) {
		_alloc.destroy(&_ptr[_size - 1]);
		_size--;
		return ;
	}

	iterator	insert( iterator position, const value_type& val ) {
		difference_type	n = position - begin();
		insert(position, 1, val);
		return (begin() + n);
	}

	void		insert( iterator position, size_type n, const value_type& val ) {
		iterator	it = begin();
		iterator	ite = end();
		vector		new_vec;

		while(it != position)
			new_vec.push_back(*it++);
		while(n--)
			new_vec.push_back(val);
		while(it != ite)
			new_vec.push_back(*it++);

		if (_capacity < new_vec.size()) {
			size_type	new_capacity = _capacity;

			while (new_capacity < new_vec.size())
				new_capacity = new_capacity << 1;
			reserve(new_capacity);
		}

		assign(new_vec.begin(), new_vec.end());
		return ;
	}

	template <class InputIterator>
	void 		insert( iterator position, InputIterator first, InputIterator last,
	typename ft::enable_if<!is_integral<InputIterator>::value, bool>::type = true ) {
		iterator	it = begin();
		iterator	ite = end();
		vector		new_vec;

		while(it != position)
			new_vec.push_back(*it++);
		while(first != last)
			new_vec.push_back(*first++);
		while(it != ite)
			new_vec.push_back(*it++);

		if (_capacity < new_vec.size()) {
			size_type	new_capacity = _capacity;

			while (new_capacity < new_vec.size())
				new_capacity = new_capacity << 1;
			reserve(new_capacity);
		}

		assign(new_vec.begin(), new_vec.end());
		return ;
	}

	iterator	erase( iterator position ) {
		iterator	it = begin();
		iterator	ite = end();
		vector		new_vec;

		difference_type	n = position - begin();

		while(it != position)
			new_vec.push_back(*it++);
		*it++;
		while(it != ite)
			new_vec.push_back(*it++);

		assign(new_vec.begin(), new_vec.end());
		return (begin() + n);
	}

	iterator	erase( iterator first, iterator last ) {
		iterator	it = begin();
		iterator	ite = end();
		vector		new_vec;

		difference_type	n = first - begin();

		while(it != first)
			new_vec.push_back(*it++);
		while(it != last)
			*it++;
		while(it != ite)
			new_vec.push_back(*it++);

		assign(new_vec.begin(), new_vec.end());
		return (begin() + n);
	}

	void swap( vector & x ) {
		vector	tmp;
		tmp = *this;
		*this = x;
		x = tmp;
		return ;
	}

	void clear( void ) {
		while (_size)
			pop_back();
		return ;
	}

	// ALLOCATOR

	allocator_type get_allocator() const {
		return _alloc;
	}

private:

	allocator_type	_alloc;
	pointer			_ptr;
	size_type		_size;
	size_type		_capacity;

};

// NON-MEMBER FUNCTION

template <class T, class Alloc>
bool operator==( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
	if (lhs.size() != rhs.size())
		return false;
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <class T, class Alloc>
bool operator!=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
	return !(lhs == rhs);
}

template <class T, class Alloc>
bool operator<( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, class Alloc>
bool operator<=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
	return !(rhs < lhs);
}

template <class T, class Alloc>
bool operator>( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
	return (rhs < lhs);
}

template <class T, class Alloc>
bool operator>=( const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs ) {
	return !(lhs < rhs);
}

template <class T, class Alloc>
void swap( vector<T,Alloc>& x, vector<T,Alloc>& y ) {
	x.swap(y);
	return ;
}

} // namespace ft

#endif
