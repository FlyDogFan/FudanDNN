#include "NonLinearLayer.h"

#pragma once
class HardTanH : public NonLinearLayer
{

public:
	HardTanH(size_t size);
	HardTanH() {};
	string getNetworkName() override;
	void compute();
	void calculate();
	void gradient();
	size_t getSize();
	void writeSelf(string) {};
	void readSelf(string) {};

};

