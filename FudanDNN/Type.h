#pragma once
#include <string>
using namespace std;

#pragma once
class Type{
public:
	static enum AutoEncoder
	{
		AE,//��ͨautoencoder
		DAE,//denoise autoencoder
		CAE,//contractive autoencoder
		SAE//sparse autoencoder
	};
	static enum RBM
	{
		RBM,//��ͨRBM
	};
	static enum CNN
	{
		CNN,//��ͨcnn
	};
	static enum NONLINEAR
	{
		SIGMOID,
		HARDSHRINK,
		HARHTANH,
		LOGSSIGMOID,
		PRELU,
		RELU,
		SOFTSHRINK,
	};
};