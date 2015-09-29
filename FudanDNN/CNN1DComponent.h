#pragma once
#include "Matrix.h"
#include "AbstractComponent.h"
#include <vector>

using namespace std;

class CNN1DComponent : public AbstractComponent {
protected:
	size_t kernelSize;//����˵Ĵ�С
	size_t stride;//������ƶ�����
	size_t hiddenNum;
	size_t featureMapNum;//���������featureMap������
	double regularizationRate;
	double kernelLearningRate;
	double biasLearningRate;
	vector<shared_ptr<AbstractMatrix>> convKernels;//�����
	vector<shared_ptr<AbstractMatrix>> convKernelsGradient;//�����gradient
	vector<shared_ptr<AbstractMatrix>> bias;//bias
	vector<shared_ptr<AbstractMatrix>> biasGradient;//bias��gradient
	vector<shared_ptr<AbstractMatrix>> hiddenValue;//��hiddenValue
	vector<shared_ptr<AbstractMatrix>> hiddenvGradient;//featureMap��gradient
	vector<shared_ptr<AbstractMatrix>> visualValue;
	vector<shared_ptr<AbstractMatrix>> visualGradient;

	void initialization(size_t initScheme);

	//��ͬ��ʼ������
	static enum initializationScheme
	{
		RANDOM,			//[-1,1)
		RANDOM_SQRT,	//[-1/sqrt(visual), 1/sqrt(visual))
		RANDOM_NORM1	//[-1/visual, 1/visual)
	};

public:
	CNN1DComponent();
	CNN1DComponent(size_t kernelSize, size_t stride, size_t num, size_t featureMap_Num,
		size_t visualRow, size_t scheme);
	~CNN1DComponent();
	void gradient();
	void compute();
	void calculate();
	void update();
	void regularize();
	double getRegularizationRate();
	void setRegularizationRate(double regularizationRate);
	double getKernelLearningRate();
	void setKernelLearningRate(double kernelLearningRate);
	double getBiasLearningRate();
	void setBiasLearningRate(double biasLearningRate);

};

