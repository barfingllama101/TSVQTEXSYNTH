#include "BinaryTree.h"

/*BinaryTree::BinaryTree() {
	root = NULL;
}

BinaryTree::~BinaryTree() {
	destroy_tree();
}

void BinaryTree::destroy_tree(Node* leaf) {
	if (leaf != NULL) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}
double BinaryTree::getMagnitude(double x, double y) {
	return sqrt(pow(x,2)+ pow(y,2));
}
void BinaryTree::insert(int key, PositionVector position, Node* leaf) {
	if(Distance(position.x, leaf->position.x, position.y, leaf->position.y) <3){
	//if (getMagnitude(position.x, position.y) < getMagnitude(leaf->position.x, leaf->position.y)) {
		if (key < leaf->value) {
			if (leaf->left != NULL) {
				insert(key, leaf->position, leaf->left);
			}
			else {
				leaf->left = new Node;
				leaf->left->value = key;

				leaf->left->c.R = 2;
				leaf->left->c.G = 1;
				leaf->left->c.B = 2;

				leaf->left->position = leaf->position;
				leaf->left->left = NULL;
				leaf->left->right = NULL;
			}
		}
	}else{
	//	else if (getMagnitude(position.x, position.y) >= getMagnitude(leaf->position.x, leaf->position.y)) {
			//else if (key >= leaf->value) {
			if (leaf->right != NULL) {
				insert(key, leaf->position, leaf->right);
			}
			else {
				leaf->right = new Node;
				leaf->right->value = key;

				leaf->right->c.R = 2;
				leaf->right->c.G = 1;
				leaf->right->c.B = 2;

				leaf->right->position = leaf->position;
				leaf->right->region = 2;
				leaf->right->right = NULL;
				leaf->right->left = NULL;
			}
		}
	
	}

void BinaryTree::insert(int key, PositionVector position, Color color) {
	if (root != NULL) {
		insert(key, position, root);
	}
	else {
		root = new Node;
		root->value = key;

		root->c.R = 1;
		root->c.G = 1;
		root->c.B = 1;

		root->position = {1,2};

		root->region = 0;
		root->left = NULL;
		root->right = NULL;
	}
}

Node* BinaryTree::search(int key, Node* leaf) {
	if (leaf != NULL) {
		if (key == leaf->value) {
			return leaf;
		}
		if (key < leaf->value) {
			return search(key, leaf->left);
		}
		else {
			return search(key, leaf->right);
		}
	}
	else {
		return NULL;
	}
}
bool BinaryTree::comparison(Node* a, Node* b)
{
	return (a->distance < b->distance);
}
vector<PositionVector> BinaryTree::NearestNeighborClassification(Node* points[], int n, double k, Node* p) {
	
	for (int i = 0; i < n; i++) {
		points[i]->distance =
			sqrt(((points[i]->position.x - p->position.x) * (points[i]->position.x - p->position.x)) +
				(points[i]->position.y - p->position.y) * (points[i]->position.y - p->position.y));
	}
	
	// Sort the Points by distance from p 
	sort(points, points+n, comparison);

	for (int i = 0; i < k; i++)
	{
		if (points[i] != p ) {
			p->edgeLine = { points[i]->position, p->position };
		}
	}
	
	cout << "edgeline from: " << p->edgeLine[0].x << " , " << p->edgeLine[0].y << " to: " << p->position.x << " , " << p->position.y << std::endl;

	return p->edgeLine;
}
PositionVector BinaryTree::NearestNeighborClassificationCDB(Node* points[], int n, double k, Node* p) {

	for (int i = 0; i < n; i++) {
		points[i]->distance =
			sqrt(((points[i]->position.x - p->position.x) * (points[i]->position.x - p->position.x)) +
				(points[i]->position.y - p->position.y) * (points[i]->position.y - p->position.y));
	}

	int test = 0;
	// Sort the Points by distance from p 
	sort(points, points + n, comparison);
	for (int i = 0; i < k; i++) {
		if (points[i] == p) {
			test = i;
		}
	}
	for (int i = 0; i < k; i++)
	{
			p->nearestRegion = points[i]->position;
	}

	cout << "nearestRegion: " << p->nearestRegion.x << " , " << p->nearestRegion.y << " Current Position: " << p->position.x << " , " << p->position.y << std::endl;


	return p->nearestRegion;
}

PositionVector BinaryTree:: FindNewCentroid(vector<Node*> points) {
	PositionVector altered = { 3,3 };
	double tempX = 0;
	double tempY = 0;
	if (points.size() == 1) {
		cout << "old Centroid: " <<  points[0]->position.x << ", " << points[0]->position.y << std::endl;
		return points[0]->position;
	}
	
	else {
		for (int i = 0; i < points.size(); i++) {
			tempX += points[i]->position.x;
			tempY += points[i]->position.y;
		}
	}
	altered = { tempX / points.size(), tempY / points.size() };
	cout << "new Centroid: " << altered.x << ", " << altered.y << std::endl;
	return altered;
}
double BinaryTree::NearestNeighborRule(Node* points[], Node* point) {
	return 3;
}
Node* BinaryTree::search(int key) {
	return search(key, root);
}

void BinaryTree::destroy_tree() {
	destroy_tree(root);
}

void BinaryTree::inorder_print() {
	inorder_print(root);
	cout << "\n";
}

void BinaryTree::inorder_print(Node* leaf) {
	if (leaf != NULL) {
		inorder_print(leaf->left);
		inorder_print(leaf->right);
	}
}

void BinaryTree::postorder_print() {
	postorder_print(root);
	cout << "\n";
}

void BinaryTree::postorder_print(Node* leaf) {
	if (leaf != NULL) {
		inorder_print(leaf->left);
		inorder_print(leaf->right);
		allNodes.push_back(leaf);
	}

}

void BinaryTree::preorder_print() {
	preorder_print(root);
	
	cout << "\n";
}

void BinaryTree::preorder_print(Node* leaf) {
	if (leaf != NULL) {
		cout << leaf->value << ",";
	
		inorder_print(leaf->left);
		
		inorder_print(leaf->right);
		

	}
}
double BinaryTree::Distance(double x1, double x2, double y1, double y2) {
	
	return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));

	//distance betwen two vector sto determine which side to go on 
}
*/