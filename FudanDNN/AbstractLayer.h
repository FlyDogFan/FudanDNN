#pragma once
#include "stdafx.h"
#include "AbstractMatrix.h"
#include <fstream>

using namespace std;

class AbstractLayer
{
public:
	//ѵ��ǰ��
	virtual void compute() {};
	//Ԥ��ǰ��
	virtual void calculate() {};
	//����
	virtual void gradient() {};
	virtual string getNetworkName() { return nullptr; };
	//������
	void setVisualValue(shared_ptr<AbstractMatrix> visualValue);
	//����hidden�����
	void setHiddenGradient(shared_ptr<AbstractMatrix> hiddenGradient);
	//��ȡvisual��ֵ
	shared_ptr<AbstractMatrix> getVisualValue();
	//��ȡhidden��ֵ
	shared_ptr<AbstractMatrix> getHiddenValue();
	//��ȡvisual�����
	shared_ptr<AbstractMatrix> getVisualGradient();
	//��ȡhidden�����
	shared_ptr<AbstractMatrix> getHiddenGradient();
	//��ȡvisual������
	size_t getVisualUnit();
	//��ȡhidden������
	size_t getHiddenUnit();
	void setNetworkName(string networkName);
	//���л����
	virtual void writeSelf(string) {};
	virtual void readSelf(string) {};
	virtual ~AbstractLayer() {};

protected:
	shared_ptr<AbstractMatrix> visualValue;
	shared_ptr<AbstractMatrix> hiddenValue;
	shared_ptr<AbstractMatrix> visualGradient;
	shared_ptr<AbstractMatrix> hiddenGradient;
	size_t visualUnit;
	size_t hiddenUnit;
	string networkname;

};

