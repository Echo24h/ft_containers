/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:20:28 by gborne            #+#    #+#             */
/*   Updated: 2022/11/24 22:57:49 by gborne           ###   ########.fr       */
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
		: _cont(cont) {
		return ;
	}

	stack( stack const & src ) {
		*this = src;
		return ;
	}

	stack &	operator=( stack const & rhs ) {
		_cont = rhs._cont;
		return *this;
	}

	virtual	~stack( void ) {
		std::cout << "destructor stack" << std::endl;
		return ; }

	// FUNCTIONS

	bool empty() const { return _cont.empty(); }

	size_type	size( void ) const { return _cont.size(); };

	value_type & top() { return _cont.back(); }

	const value_type & top() const { return _cont.back(); }

	void push ( const value_type & val ) { _cont.push_back(val); return ; }

	void pop() { _cont.pop_back(); return ; }

	void swap( stack & x ) { _cont.swap(x._cont); return ; }

private:

	container_type	_cont;

};

template <class T, class Container>
bool operator== ( const stack<T,Container> & lhs , const stack<T,Container> & rhs ) {
	return (lhs._cont == rhs._cont);
}

template <class T, class Container>
bool operator!= ( const stack<T,Container> & lhs , const stack<T,Container> & rhs ) {
	return (lhs._cont != rhs._cont);
}

template <class T, class Container>
bool operator<  ( const stack<T,Container> & lhs , const stack<T,Container> & rhs ) {
	return (lhs._cont < rhs._cont);
}

template <class T, class Container>
bool operator<= ( const stack<T,Container> & lhs , const stack<T,Container> & rhs ) {
	return (lhs._cont <= rhs._cont);
}

template <class T, class Container>
bool operator>  ( const stack<T,Container> & lhs , const stack<T,Container> & rhs ) {
	return (lhs._cont > rhs._cont);
}

template <class T, class Container>
bool operator>= ( const stack<T,Container> & lhs , const stack<T,Container> & rhs ) {
	return (lhs._cont >= rhs._cont);
}

} // namespace ft

#endif
