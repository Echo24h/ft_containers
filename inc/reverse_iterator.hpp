/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:37:40 by gborne            #+#    #+#             */
/*   Updated: 2022/11/22 23:21:18 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft {

template <class Iterator>
class reverse_iterator {

public:

	// MEMBERS

	typedef Iterator													iterator_type;
	typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
	typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
	typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
	typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
	typedef typename ft::iterator_traits<Iterator>::reference			reference;

	// CONSTRUCTOR

	reverse_iterator( void ) : _it(0) { return ; }

	explicit reverse_iterator( iterator_type it ) : _it(it) { return ; }

	template <class Iter>
	reverse_iterator (const reverse_iterator<Iter>& rev_it) : _it(rev_it) { return ; }

	virtual ~reverse_iterator( void ) { return ; };

	// MEMBERS FUNCTIONS

	iterator_type base() const {
		reverse_iterator	cpy(*this);
		cpy--;
		return cpy._it;
	}

	// OPERATORS

	reference operator*() const { return *_it; }

	reverse_iterator operator+( difference_type n ) const { return reverse_iterator(_it - n); }

	reverse_iterator& operator++() { _it--; return *this; };

	reverse_iterator operator++( int ) { reverse_iterator tmp = *this; _it--; return tmp; }

	reverse_iterator& operator+=( difference_type n ) { _it -= n; return *this; }

	reverse_iterator operator-( difference_type n ) const { return reverse_iterator(_it + n); }

	reverse_iterator& operator--() { _it++; return *this; };

	reverse_iterator operator--( int ) { reverse_iterator tmp = *this; _it++; return tmp; }

	reverse_iterator& operator-= ( difference_type n ) { _it += n; return *this; }

	pointer operator->() const { return *_it; }

	reference operator[]( difference_type n ) const { return _it[-n]; }

private:

	iterator_type	_it;

};

	// RELATIONAL OPERATORS

	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (rhs.base() == lhs.base());
	}

	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (rhs.base() != lhs.base());
	}

	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (rhs.base() < lhs.base());
	}

	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (rhs.base() <= lhs.base());
	}

	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (rhs.base() > lhs.base());
	}

	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (rhs.base() >= lhs.base());
	}

	// NON-MEMBERS FUNCTIONS

	template <class Iterator>
	reverse_iterator<Iterator> operator+( typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it) {
		return reverse_iterator<Iterator>( --rev_it.base() - n);
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (rhs.base() - lhs.base());
	}

} // namespace ft

#endif
