/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:43:40 by gborne            #+#    #+#             */
/*   Updated: 2022/10/18 18:11:50 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include <iterator>
# include <cstddef>

namespace ft {

template <class Iterator>
class iterator_traits {

public:

	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::iterator_category	iterator_category;

};

template <class T>
class iterator_traits<T*> {

public:

	typedef ptrdiff_t									difference_type;
	typedef T											value_type;
	typedef T *											pointer;
	typedef T &											reference;
	typedef typename std::random_access_iterator_tag	iterator_category;

};

template <class T>
class iterator_traits<const T*> {

public:

	typedef ptrdiff_t									difference_type;
	typedef T											value_type;
	typedef const T *									pointer;
	typedef const T &									reference;
	typedef typename std::random_access_iterator_tag	iterator_category;

};

} // namespace ft

#endif
