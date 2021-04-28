#pragma once
#include "Structs.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

struct Color
{
	int R;
	int G;
	int B;
};
struct PositionVector {
	double x;
	double y;

};
/*struct Node {
	Color c;
	PositionVector position;
	int value;
	Node* left = NULL;
	Node* right = NULL;
	int region;
	double distance;
	bool visited = false;
	PositionVector nearestRegion;

	//making the edge to the next vector used in Nearest neighbor
	vector<PositionVector> edgeLine;
};
*/
struct imgWH {
	int height;
	int width;
	int relX;
	int relY;
};
const int k = 2;
struct _node
{
	int point[k]; // To store k dimensional point
	_node* left, * right;
};

// A method to create a node of K D tree
struct _node* newNode(int arr[])
{
	struct _node* temp = new _node;

	for (int i = 0; i < k; i++)
		temp->point[i] = arr[i];

	temp->left = temp->right = NULL;
	return temp;
}
// Inserts a new node and returns root of modified tree
// The parameter depth is used to decide axis of comparison
_node* insertRec(_node* root, int point[], unsigned depth)
{
	// Tree is empty?
	if (root == NULL)
		return newNode(point);

	// Calculate current dimension (cd) of comparison
	unsigned cd = depth % k;

	// Compare the new point with root on current dimension 'cd'
	// and decide the left or right subtree
	if (point[cd] < (root->point[cd]))
		root->left = insertRec(root->left, point, depth + 1);
	else
		root->right = insertRec(root->right, point, depth + 1);

	return root;
}

// Function to insert a new point with given point in
// KD Tree and return new root. It mainly uses above recursive
// function "insertRec()"
_node* insert(_node* root, int point[])
{
	return insertRec(root, point, 0);
}
// A utility method to determine if two Points are same
// in K Dimensional space
bool arePointsSame(int point1[], int point2[])
{
	// Compare individual pointinate values
	for (int i = 0; i < k; ++i)
		if (point1[i] != point2[i])
			return false;

	return true;
}
// Searches a Point represented by "point[]" in the K D tree.
// The parameter depth is used to determine current axis.
bool searchRec(_node* root, int point[], unsigned depth)
{
	// Base cases
	if (root == NULL)
		return false;
	if (arePointsSame(root->point, point))
		return true;

	// Current dimension is computed using current depth and total
	// dimensions (k)
	unsigned cd = depth % k;

	// Compare point with root with respect to cd (Current dimension)
	if (point[cd] < root->point[cd])
		return searchRec(root->left, point, depth + 1);

	return searchRec(root->right, point, depth + 1);
}

// Searches a Point in the K D tree. It mainly uses
// searchRec()
bool search(_node* root, int point[])
{
	// Pass current depth as 0
	return searchRec(root, point, 0);
}