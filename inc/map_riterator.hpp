/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_riterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:11:32 by gborne            #+#    #+#             */
/*   Updated: 2022/11/22 23:10:46 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_RITERATOR_HPP
# define MAP_RITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft {

template < class Iterator >
class map_riterator {

public:

	// MEMBERS TYPE

	typedef Iterator													iterator_type;
	typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
	typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
	typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
	typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
	typedef typename ft::iterator_traits<Iterator>::reference			reference;

	// CONSTRUCTOR

	map_riterator( void ) : _it(0) { return ; }

	explicit map_riterator( iterator_type it ) : _it(it) { return ; }

	map_riterator (const map_riterator & rev_it) : _it(rev_it._it) { return ; }

	virtual ~map_riterator( void ) { return ; };

	// EQUALITY

	bool	operator==( map_riterator const & rhs ) {
		return (_it == rhs._it);
	}

	bool	operator!=( map_riterator const & rhs ) {
		return (_it != rhs._it);
	}

	// DEREFERENCE

	reference operator*() const { return *_it; };

	pointer operator->() const { return _it.operator->(); };

	// MUTABLE

	map_riterator &	operator=( map_riterator const & rhs ) { _it = rhs._it; return *this; }

	// INCREMENT / DECREMENT

	map_riterator& operator++() { _it--; return *this; };

	map_riterator operator++( int ) { map_riterator tmp = *this; _it--; return tmp; }

	map_riterator& operator--() { _it++; return *this; };

	map_riterator operator--( int ) { map_riterator tmp = *this; _it++; return tmp; }

private:

	iterator_type	_it;

};

} // namespace ft


#endif
