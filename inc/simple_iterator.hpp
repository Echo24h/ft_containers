/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 15:01:58 by gborne            #+#    #+#             */
/*   Updated: 2022/11/22 23:21:47 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLE_ITERATOR_HPP
# define SIMPLE_ITERATOR_HPP

# include <iterator>
# include <cstddef>

namespace ft {

template < class T >
class simple_iterator {

public:

	// MEMBERS TYPE

	typedef T									value_type;
	typedef ptrdiff_t							difference_type;
	typedef T *									pointer;
	typedef T &									reference;
	typedef std::random_access_iterator_tag		iterator_category;

	// CONSTRUCTOR

	simple_iterator( void ) : _ptr(0) { return ; }

	simple_iterator( pointer ptr ) : _ptr(ptr) { return ; }

	simple_iterator( simple_iterator const & src ) { *this = src; return ; }

	virtual ~simple_iterator( void ) { return ; }

	// OPERATOR

	simple_iterator &	operator=( simple_iterator const & rhs ) { _ptr = rhs._ptr; return *this; }

	reference operator*() const { return *_ptr; };

	simple_iterator operator+( difference_type n ) const { return simple_iterator(_ptr + n); }

	simple_iterator & operator++() { _ptr++; return *this; } // Prefix increment

	simple_iterator operator++( int ) { simple_iterator tmp = *this; _ptr++; return tmp; } // Postfix increment

	simple_iterator& operator+=( difference_type n ) { _ptr += n; return *this; }

	simple_iterator operator-( difference_type n ) const {  return simple_iterator(_ptr - n); }

	simple_iterator & operator--() { _ptr--; return *this; } // Prefix increment

	simple_iterator operator--( int ) { simple_iterator tmp = *this; _ptr--; return tmp; } // Postfix increment

	simple_iterator& operator-= ( difference_type n ) { _ptr -= n; return *this; }

	pointer operator->() const { return *_ptr; }

	reference operator[] ( difference_type n ) const { return *simple_iterator(_ptr + n); }

	// RELATIONAL OPERATOR

	bool operator==( simple_iterator const & rhs ) {
		return (_ptr == rhs._ptr);
	}

	bool	operator!=( simple_iterator const & rhs ) {
		return (_ptr != rhs._ptr);
	}

	bool operator<( simple_iterator const & rhs ) {
		return (_ptr < rhs._ptr);
	}

	bool operator<=( simple_iterator const & rhs ) {
		return (_ptr <= rhs._ptr);
	}

	bool operator>( simple_iterator const & rhs ) {
		return (_ptr > rhs._ptr);
	}

	bool operator>=( simple_iterator const & rhs ) {
		return (_ptr >= rhs._ptr);
	}

	typename simple_iterator::difference_type operator-( simple_iterator const & rhs ) {
		return (_ptr - rhs._ptr);
	}

private:

	pointer	_ptr;

};

} // namespace ft

#endif
