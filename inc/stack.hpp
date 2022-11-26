/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:20:28 by gborne            #+#    #+#             */
/*   Updated: 2022/11/26 19:01:25 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "utils.hpp"
# include "vector.hpp"

namespace ft {

template <class T, class Container = ft::vector<T> >
class stack {

public:

	// MEMBERS TYPE

	typedef				T											value_type;
	typedef				Container									container_type;
	typedef				size_t										size_type;

	// CANONICAL FORM

	explicit stack( const container_type & cont = container_type() )
		: cont(cont) {
		return ;
	}

	stack( stack const & src ) {
		*this = src;
		return ;
	}

	stack &	operator=( stack const & rhs ) {
		cont = rhs.cont;
		return *this;
	}

	virtual	~stack( void ) { return ; }

	// FUNCTIONS

	bool empty() const { return cont.empty(); }

	size_type	size( void ) const { return cont.size(); };

	value_type & top() { return cont.back(); }

	const value_type & top() const { return cont.back(); }

	void push ( const value_type & val ) { cont.push_back(val); return ; }

	void pop() { cont.pop_back(); return ; }

	void swap( stack & x ) { cont.swap(x.cont); return ; }

public:

	container_type	cont;

};

template <class T, class Container>
bool operator== ( const stack<T,Container> & lhs , const stack<T,Container> & rhs ) {
	return (lhs.cont == rhs.cont);
}

template <class T, class Container>
bool operator!= ( const stack<T,Container> & lhs , const stack<T,Container> & rhs ) {
	return (lhs.cont != rhs.cont);
}

template <class T, class Container>
bool operator<  ( const stack<T,Container> & lhs , const stack<T,Container> & rhs ) {
	return (lhs.cont < rhs.cont);
}

template <class T, class Container>
bool operator<= ( const stack<T,Container> & lhs , const stack<T,Container> & rhs ) {
	return (lhs.cont <= rhs.cont);
}

template <class T, class Container>
bool operator>  ( const stack<T,Container> & lhs , const stack<T,Container> & rhs ) {
	return (lhs.cont > rhs.cont);
}

template <class T, class Container>
bool operator>= ( const stack<T,Container> & lhs , const stack<T,Container> & rhs ) {
	return (lhs.cont >= rhs.cont);
}

template <class T, class Container>
void swap ( stack<T,Container> & x, stack<T,Container> & y ) {
	x.swap(y);
}

} // namespace ft

#endif
