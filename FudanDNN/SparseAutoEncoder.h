#include "AutoEncoder.h"
#include "NonLinearLayer.h"
#include "NonLinearFactory.h"
#include <string>
#include <fstream>
#include <sstream>
#include "XMLDataParser.h"

using namespace std;
#pragma once
class SparseAutoEncoder : public AutoEncoder
{
public:
	SparseAutoEncoder(size_t visualUnit, size_t hiddenUnit, int init_scheme, size_t nonlinearType
		,size_t sparseRate,size_t sparsePercent);
	SparseAutoEncoder() {};
	string getNetworkName() override;
	size_t getSparseRate();
	void setSparseRate(size_t sparseRate);
	size_t getSparsePercent();
	void setSparsePercent(size_t sparsePercent);
	void singleTraining(shared_ptr<AbstractMatrix> v);
	void writeSelf(string) {};
	void readSelf(string) {};
protected:
	size_t sparseRate;
	size_t sparsePercent;
};