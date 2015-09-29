#pragma once
#include "AbstractLayer.h"
#include <string>

using namespace std;

#pragma once
class AbstractNetworkLayer : public AbstractLayer
{
public:
	//�����������
	virtual void update();
	string getNetworkName() override;
	//�����������
	void regularize();
	//��ȡȨ��
	shared_ptr<AbstractMatrix> getWeight();
	//����Ȩ��
	void setWeight(shared_ptr<AbstractMatrix> weight);
	//��ȡƫ��
	shared_ptr<AbstractMatrix> getBias();
	//����ƫ��
	void setBias(shared_ptr<AbstractMatrix> bias);
	//����dropout����
	void generateDropout();
	//��ȡ���򻯲���
	double getRegularizationRate();
	//�������򻯲���
	void setRegularizationRate(double regularizationRate);
	//��ȡȨ��ѧϰ��
	double getWeightLearningRate();
	//����Ȩ��ѧϰ��
	void setWeightLearningRate(double weightLearningRate);
	//��ȡƫ��ѧϰ��
	double getBiasLearningRate();
	//����ƫ��ѧϰ��
	void setBiasLearningRate(double biasLearningRate);
	//��ȡdropout��
	double getDropoutRate();
	//����dropout��
	void setDropoutRate(double dropoutRate);
	virtual ~AbstractNetworkLayer() {};
	void writeSelf(string) {};
	void readSelf(string) {};
	//��ͬ��ʼ������
	static enum initializationScheme
	{
		RANDOM,			//[-1,1)
		RANDOM_SQRT,	//[-1/sqrt(visual), 1/sqrt(visual))
		RANDOM_NORM1	//[-1/visual, 1/visual)
	};

protected:
	shared_ptr<AbstractMatrix> weight;
	shared_ptr<AbstractMatrix> weightGradient;
	shared_ptr<AbstractMatrix> bias;
	shared_ptr<AbstractMatrix> biasGradient;
	shared_ptr<AbstractMatrix> dropout;
	double regularizationRate = 0;
	double weightLearningRate = 0.8;
	double biasLearningRate = 0.8;
	double dropoutRate = 0.5;

	void initialization(int initScheme);

};

