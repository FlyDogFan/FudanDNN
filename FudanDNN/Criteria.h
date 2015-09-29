#pragma once
#include "stdafx.h"
#include "AbstractMatrix.h"
#include <string>
#include <fstream>

using namespace std;

class Criteria
{
public:
	Criteria();
	//�������
	virtual double computeError() { return 0; };
	//����
	virtual void gradient() {};
	//��ȡvisual������
	size_t getVisualUnit();
	//����Ԥ��ֵ
	void setPredictValue(shared_ptr<AbstractMatrix>);
	//��ȡԤ��ֵ
	shared_ptr<AbstractMatrix> getPredictValue();
	//��������ֵ
	void setExpectedValue(shared_ptr<AbstractMatrix>);
	//��ȡ����ֵ
	shared_ptr<AbstractMatrix> getExpectedValue();
	//��ȡvisual�����
	shared_ptr<AbstractMatrix> getPredictGradient();
	virtual string getType() { return nullptr; };
	//��ȡ������
	double getErrorRate();
	void readSelf(string);
	void writeSelf(string);

protected:
	size_t visualUnit;
	shared_ptr<AbstractMatrix> predictValue;
	shared_ptr<AbstractMatrix> expectedValue;
	shared_ptr<AbstractMatrix> predictGradient;
	double errorRate = 1;
	string type;
};
