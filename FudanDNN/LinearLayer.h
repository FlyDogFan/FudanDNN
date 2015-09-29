#pragma once
#include "Matrix.h"
#include "AbstractNetworkLayer.h"

class LinearLayer : public AbstractNetworkLayer
{
public:
	
	//���캯��
	LinearLayer(size_t visualUnit, size_t hiddenUnit, size_t initScheme);
	LinearLayer() {};
	string getNetworkName() override;
	//ѵ��ǰ��
	void compute() override;
	//Ԥ��ǰ��
	void calculate()override;
	//����
	void gradient()override;

	//����д��
	void writeSelf(string) override;
	void readSelf(string) override;
	
};