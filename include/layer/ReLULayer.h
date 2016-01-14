#ifndef __FUDANDNN_RELU_LAYER_H
#define __FUDANDNN_RELU_LAYER_H

#include "util/utils.h"
#include "NonlinearLayer.h"
#include "functions/ReLU.h"

class ReLULayer : public NonlinearLayer
{

public:
	ReLULayer(size_t rowSize, size_t columnSize, size_t featureMap);
	ReLULayer(size_t size);
	string getNetworkName() override;
	void compute() override;
	void calculate() override;
	void gradient() override;
	void writeSelf(string) override;
	void readSelf(string) override;
	size_t getSize();

protected:
	shared_ptr<ReLU> instance = ReLU::getInstance();

};


#endif