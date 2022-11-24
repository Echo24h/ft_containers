/* ************************************************************************** */
/*																		    */
/*												        :::      ::::::::   */
/*   map_tree.hpp									        :+:      :+:    :+:   */
/*												    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>			  +#+  +:+       +#+        */
/*												+#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:54:49 by gborne			#+#    #+#			 */
/*   Updated: 2022/11/16 22:04:41 by gborne           ###   ########.fr       */
/*																		    */
/* ************************************************************************** */

#ifndef MAP_TREE_HPP
# define MAP_TREE_HPP

# include "utils.hpp"
# include <iostream>


namespace ft {

template < class Key, class T, class pair = ft::pair<const Key,T> >
struct node {

	pair	data;
	node *	top;
	node *	left;
	node *	right;
};

template < class Key, class T, class Alloc >
class map_tree {

public:

	// MEMBER TYPES

	typedef				Key										key_type;
	typedef				T										mapped_type;
	typedef				ft::pair<const key_type, mapped_type>	pair;
	typedef				ft::node<const key_type, mapped_type>	node;

	typedef				Alloc									allocator_type;
	typedef typename	allocator_type::size_type				size_type;
	typedef				node *									pointer;

	// CONSTRUCTOR

	map_tree( const allocator_type & alloc = allocator_type() )
			: _root(NULL), _end(NULL), _alloc(alloc), _size(0) {
		_end_update();
		return ;
	}

	map_tree( map_tree const & src ) {
		*this = src;
		return ;
	}

	virtual	~map_tree() {
		clear();
		_destroyNode(_end);
		_size++;
		return ;
	}

	map_tree &	operator=( map_tree const & rhs ) {
		clear();
		_copy(rhs._root);
		return *this;
	}

	// CAPACITY

	size_type	size( void ) const { return _size; };

	size_type	max_size( void ) const { return _alloc.max_size(); };

	// MODIFIERS

	pointer	insert( const pair & val ) {
		return	insert(val, _root, NULL);
	}

	pointer	insert( const pair & val, pointer & node, pointer parent ) {
		if(node == NULL) {
			node = _newNode(val, parent);
			_end_update(node);
			return node;
		}
		else {
			if(val.first < node->data.first)
				return	insert(val, node->left, node);
			else if (val.first > node->data.first)
				return	insert(val, node->right, node);
		}
		return NULL;
	}

	void	remove( const key_type & key ) {
		_root = remove(_root, key);
		_end_update();
		return ;
	}

	pointer	remove ( pointer root, key_type key ) {

		if (root == NULL)
			return root;
	
		if (key < root->data.first) {
			root->left = remove(root->left, key);
			if (root->left)
				root->left->top = root;
		}
		else if (key > root->data.first) {
			root->right = remove(root->right, key);
			if (root->right)
				root->right->top = root;
		}
		else {
			if (root->left==NULL and root->right==NULL) {
				_destroyNode(root);
				return NULL;
			}
			else if (root->left == NULL) {
				pointer temp = root->right;
				_destroyNode(root);
				return temp;
			}
			else if (root->right == NULL) {
				pointer temp = root->left;
				_destroyNode(root);
				return temp;
			}

			pointer temp = min(root->right);
			
			pointer cpy = _newNode(temp->data, root->top);
			cpy->left = root->left;
			cpy->right = root->right;
			_destroyNode(root);
			root = cpy;

			root->right = remove(root->right, temp->data.first);
		}
		return root;
	}

	

	void	clear( void ) {
		_root = _clear(_root);
		_end_update();
	}

	// OPERATIONS

	pointer	search( const key_type & key) const {
		return search(_root, key);
	}

	pointer	search( const pointer node, const key_type & key ) const {
		if(node == NULL || node->data.first == key)
			return node;
		if(node->data.first < key)
			return search(node->right,key);
		return search(node->left,key);
	}

	// return Node * contain datas for Before/After in Iterators (~C++11)
	pointer end ( void ) const {
		return _end;
	}

	pointer	min( void ) const {
		return min(_root);
	}

	pointer	min( const pointer node ) const {

		if (node == NULL)
			return NULL;

		pointer cur = node;

		while(cur->left != NULL)
			cur = cur->left;
		return cur;
	}

	pointer	max( void ) const {
		return max(_root);
	}

	pointer	max( const pointer node ) const {

		if (node == NULL)
			return NULL;

		pointer cur = node;

		while(cur->right != NULL)
			cur = cur->right;
		return cur;
	}

	void	inOrder( void ) const {
		inOrder(_root);
	}


	void	inOrder( const pointer node ) const {
		if(node == NULL)
			return;
		inOrder(node->left);
		std::cout << node->data.first << " => " << node->data.second << std::endl;
		inOrder(node->right);
	}

private:

	pointer	_newNode( const pair & data, pointer parent ) {
		pointer newNode = _alloc.allocate(1);
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->top = parent;
		std::allocator<pair>().construct(&newNode->data, data);
		_size++;
		return newNode;
	}

	void	_destroyNode( pointer node ) {

		if (node == NULL)
			return ;

		std::allocator<pair>().destroy(&node->data);
		_alloc.deallocate(node, 1);
		_size--;
	}

	void	_copy( const pointer node ) {
		if(node == NULL)
			return ;
		_copy(node->left);
		insert(node->data);
		_copy(node->right);
	}

	void	_end_update( pointer node = NULL ) {
		if (_end == NULL) {
			_end = _newNode(pair(key_type(), mapped_type()), NULL);
			_size--;
		}
		if (node != NULL && _end->left != NULL && _end->right != NULL) {
			if ( node->data.first < _end->left->data.first )
				_end->left = min();
			if ( node->data.first > _end->right->data.first )
				_end->right = max();
		}
		else {
			_end->left = min();
			_end->right = max();
		}
		return ;
	}

	pointer	_clear( pointer node ) {
		if(node == NULL)
			return NULL;
		node->left = _clear(node->left);
		node->right = _clear(node->right);
		_destroyNode(node);
		return NULL;
	}

	pointer					_root;
	pointer					_end;
	allocator_type			_alloc;
	size_type				_size;

};

} // namespace ft

#endif
