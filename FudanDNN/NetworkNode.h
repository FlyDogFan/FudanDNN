#pragma once
#include "stdafx.h"
#include "AbstractMatrix.h"
#include "AbstractLayer.h"
#include "Input.h"
#include <vector>

using namespace std;

#pragma once
class NetworkNode
{
public:
	NetworkNode(int id, shared_ptr<AbstractLayer> layer);
	int getId();
	void addNextNode(shared_ptr<NetworkNode> next);
	void addBeforeNode(shared_ptr<NetworkNode> before);
	void addInput(shared_ptr<Input> input);
	shared_ptr<Input> getInput();
	vector<shared_ptr<NetworkNode>> getNextNode();
	vector<shared_ptr<NetworkNode>> getBeforeNode();
	shared_ptr<AbstractLayer> getLayer();

private:
	shared_ptr<Input> input;
	int id;
	shared_ptr<AbstractLayer> layer;
	vector<shared_ptr<NetworkNode>> nextNodes;
	vector<shared_ptr<NetworkNode>> beforeNodes;
};