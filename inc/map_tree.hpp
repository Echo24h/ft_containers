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
		end_update();
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
		_end = NULL;
		_alloc = rhs._alloc;
		_size = 0;
		_root = NULL;
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
			end_update(node);
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

	bool	remove( const key_type & key ) {
		return remove(_root, key);
	}

	/*bool	remove( pointer node, const key_type & key ) {
		pointer toRemove = search(node, key);
		if (toRemove == NULL)
			return false;
		if (toRemove->right) {

		}

	}*/

	pointer	remove( pointer node, const key_type & key ) {

		// Return if the tree is empty
		if (node == NULL)
			return node;
		// Find the node to be deleted
		if (key < node->data.first) {
			node->left = remove(node->left, key);
			if (node->left)
				node->left->top = node;
		}
		else if(key > node->data.first) {
			node->right = remove(node->right, key);
			if (node->right)
				node->right->top = node;
		}
		else {
			// If the node is with only one child or no child
			if (node->left == NULL) {
				pointer temp = node->right;
				return temp;
			}
			else if (node->right == NULL) {
				pointer temp = node->left;
				return temp;
			}
			// If the node has two children,
			// place the inorder successor in position of the node to be deleted
			pointer temp = min(node->right);

			pointer cpy = _newNode(temp->data, node->top);
			cpy->left = node->left;
			cpy->right = node->right;
			_destroyNode(node);
			node = cpy;

			// Delete the inorder successor
			node->right = remove(node->right, temp->data.first);

		}
		return node;
	}

	/*Node* deletenode(Node* root, int k)
	{
		// Base case
		if (root == NULL)
			return root;
		//If root->data is greater than k then we delete the root's subtree
		if(root->data > k){
			root->left = deletenode(root->left, k);
			return root;
		}
		else if(root->data < k){
			root->right = deletenode(root->right, k);
			return root;
		}


		// If one of the children is empty
		if (root->left == NULL) {
			Node* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == NULL) {
			Node* temp = root->left;
			delete root;
			return temp;
		}
		else {
			Node* Parent = root;
			// Find successor of the node
			Node *succ = root->right;
			while (succ->left != NULL) {
				Parent = succ;
				succ = succ->left;
			}

			if (Parent != root)
				Parent->left = succ->right;
			else
				Parent->right = succ->right;

			// Copy Successor Data
			root->data = succ->data;

			// Delete Successor and return root
			delete succ;
			return root;
		}
	}
};*/

	void	clear( void ) {
		_clear(_root);
		_root = NULL;
		end_update();
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

	// return Node * contain datas for Before/After in Iterators
	void	end_update( pointer node = NULL ) {
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

	// Don't use this function ! (or repare the NULL statement of the node starter)
	void	_clear( pointer node ) {
		if(node == NULL)
			return;
		_clear(node->left);
		_clear(node->right);
		_destroyNode(node);
	}

	pointer					_root;
	pointer					_end;
	allocator_type			_alloc;
	size_type				_size;

};

} // namespace ft

#endif
