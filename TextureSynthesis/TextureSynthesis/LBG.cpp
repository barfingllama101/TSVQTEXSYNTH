#include "LBG.h"

/*vector<PositionVector*> Centroid(Node* trainingSet[], Node*codeBookVectors[], BinaryTree* tree, int detail) {
	detail -= 1;
	if (detail == 0) {
		return  { &codeBookVectors[0]->position, &codeBookVectors[1]->position };
	}
	Centroid(trainingSet,codeBookVectors,tree,detail);
	int trainingSetSize = 4;
	int initCBVectorSize = 2;

	//establish midpoint b(k) from codebook vectors
	//b(k) midpoint is (y1 + y2) / 2
	PositionVector* midpoint = new PositionVector;
	midpoint->x = (codeBookVectors[0]->position.x + codeBookVectors[1]->position.x) / 2;
	midpoint->y = (codeBookVectors[0]->position.y + codeBookVectors[1]->position.y) / 2;

	// decision boundary b(k) using nearest neighbor (might not actually be needed)
	for (int i = 0; i < trainingSetSize; i++) {
		tree->NearestNeighborClassification(trainingSet, 4, 3, trainingSet[i]);
	}

	// compare the code book vectors to the training points
	
	for (int i = 0; i < trainingSetSize; i++) {
	tree->NearestNeighborClassificationCDB(codeBookVectors, 2, 1, trainingSet[i]);
	}
	
	//assign regions
	for (int i = 0; i < trainingSetSize; i++) {
		if (trainingSet[i]->nearestRegion.x == codeBookVectors[1]->position.x && trainingSet[i]->nearestRegion.y == codeBookVectors[1]->position.y) {
			trainingSet[i]->region = 0;
		}
		else {
			trainingSet[i]->region = 1;
		}
	}
	//compute new centroids
	vector<Node*> regionOne;
	vector<Node*> regionTwo;
	for (int i = 0; i < 4; i++) {
		if (trainingSet[i]->region == 0) {
			regionOne.push_back(trainingSet[i]); // Tree partition
		}
		else {
			regionTwo.push_back(trainingSet[i]); //tree partition
		}
	}
	//these new centroids are the new iy values. 
	codeBookVectors[0]->position = tree->FindNewCentroid(regionOne);
	codeBookVectors[1]->position = tree->FindNewCentroid(regionTwo);
	regionOne.clear();
	regionTwo.clear();

	return {&codeBookVectors[0]->position, &codeBookVectors[1]->position};
}*/