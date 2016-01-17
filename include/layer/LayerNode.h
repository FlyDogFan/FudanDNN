#ifndef __FUDANDNN_LayerNode_H
#define __FUDANDNN_LayerNode_H
#include "util\utils.h"
#include "util\Matrix.h"
#include "layer\Layer.h"
#include "util\Input.h"
#include "InputCell.h"

class LayerNode
{
public:
	LayerNode(int id, shared_ptr<Layer> layer);
	int getId();
	void setId(int id){ this->id = id; }
	void addNextNode(shared_ptr<LayerNode> next);
	void addPrevNode(shared_ptr<LayerNode> prev);
	vector<shared_ptr<LayerNode>> getNextNode();
	vector<shared_ptr<LayerNode>> getPrevNode();
	shared_ptr<Layer> getLayer();
	void clearEdges();
	void setInputCell(shared_ptr<InputCell> inputCell);
	shared_ptr<InputCell> getInputCell();

private:
	int id;
	shared_ptr<Layer> layer;
	vector<shared_ptr<LayerNode>> nextNodes;
	vector<shared_ptr<LayerNode>> prevNodes;
	shared_ptr<InputCell> inputCell;
};

#endif