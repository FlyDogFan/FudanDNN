#pragma once
#include "stdafx.h"
#include <vector>

using namespace std;

struct MaxData
{
	double value;
	size_t pos_i;
	size_t pos_j;
};

class AbstractMatrix : public enable_shared_from_this<AbstractMatrix>
{
public:
	void setValue(size_t i, size_t j, double value);
	double getValue(size_t i, size_t j);
	void setRow(size_t i, vector<double> row);
	vector<double> getRow(size_t i);
	void setColumn(size_t j, vector<double> row);
	vector<double> getColumn(size_t j);
	size_t getRowSize();
	size_t getColumnSize();
	//�ж�i,j�Ƿ��ھ�����
	bool bounded(int i, int j);
	//��ʼ������ʹ�þ���ĳ�ʼ��ֵ���½���[lowerBound, upperBound)֮��
	virtual void initializeValue(double lowerBound, double upperBound) {};
	//���01����ȡ1����Ϊp
	virtual void initializeBinaryValue(double p) {};
	//Ԫ�غ�
	virtual double sum() { return 0; };
	//Ԫ�����ֵ
	virtual double max() { return 0; }
	//�Ӿ���Ԫ�����ֵ
	virtual shared_ptr<MaxData> max(int top, int bottom, int left, int right) { return nullptr; };
	//Ԫ����Сֵ
	virtual double min() { return 0; }
	//1-����������Ԫ�ؾ���ֵ��
	virtual double norm1() { return 0; };
	//2-����������Ԫ��ƽ����
	virtual double norm2() { return 0; };
	//����ļ���������Խ���Ԫ�غ�
	virtual double trace() { return 0; };
	//����ת��
	virtual shared_ptr<AbstractMatrix> transpose() { return shared_ptr<AbstractMatrix>(nullptr); };
	//�Ӿ���Խ�籨��
	virtual shared_ptr<AbstractMatrix> submatrix(int top, int bottom, int left, int right) { return nullptr; };
	//�Ӿ���,Խ���ȡ
	virtual shared_ptr<AbstractMatrix> submatrixShrink(int top, int bottom, int left, int right) { return nullptr; };
	//�Ӿ���Խ���	
	virtual shared_ptr<AbstractMatrix> submatrixExpand(int top, int bottom, int left, int right) { return nullptr; };
	//�����з���,[0, row_index), [row_index, row_size)
	virtual vector<shared_ptr<AbstractMatrix>> splitRow(size_t rowIndex) { return *new vector<shared_ptr<AbstractMatrix>>(); };
	//�����з���,[0, collumn_index), [collumn_index, collumn_size)
	virtual vector<shared_ptr<AbstractMatrix>> splitColumn(size_t columnIndex) { return *new vector<shared_ptr<AbstractMatrix>>(); };
	//�ϲ��Ӿ������¾���Ĭ�ϵ�ǰ����Ϊ���Ͼ���
	virtual shared_ptr<AbstractMatrix> merge(shared_ptr<AbstractMatrix> rightTop, shared_ptr<AbstractMatrix> leftBottom, 
		shared_ptr<AbstractMatrix> rightBottom) { return nullptr; };
	//���кϲ��Ӿ������¾���Ĭ�ϵ�ǰ����Ϊ�Ͼ���
	virtual shared_ptr<AbstractMatrix> mergeRow(shared_ptr<AbstractMatrix> bottom) { return nullptr; };
	//���кϲ��Ӿ������¾���Ĭ�ϵ�ǰ����Ϊ�����
	virtual shared_ptr<AbstractMatrix> mergeColumn(shared_ptr<AbstractMatrix> right) { return nullptr; };
	//��������ֵ��d
	virtual shared_ptr<AbstractMatrix> add(double x) { return nullptr; };
	//�������
	virtual shared_ptr<AbstractMatrix> add(shared_ptr<AbstractMatrix> m) { return nullptr; };
	//λ��(i,j)��value
	virtual shared_ptr<AbstractMatrix> add(int i, int j, double value) { return nullptr; };
	//���Ӿ���
	virtual shared_ptr<AbstractMatrix> add(size_t top, size_t bottom, size_t left, size_t right, shared_ptr<AbstractMatrix> m) { return nullptr; };
	//��������ֵ��d
	virtual shared_ptr<AbstractMatrix> subtract(double x) { return nullptr; };
	//�������
	virtual shared_ptr<AbstractMatrix> subtract(shared_ptr<AbstractMatrix> m) { return nullptr; };
	//��������ֵ��d
	virtual shared_ptr<AbstractMatrix> multiple(double x) { return nullptr; };
	//��������ֵ��ͬλ�����
	virtual shared_ptr<AbstractMatrix> multiple(shared_ptr<AbstractMatrix> m) { return nullptr; };
	//���������˵�ǰ���󣬼�m*this
	virtual shared_ptr<AbstractMatrix> multipleLeft(shared_ptr<AbstractMatrix> m) { return nullptr; };
	//��������ҳ˵�ǰ���󣬼�this*m
	virtual shared_ptr<AbstractMatrix> multipleRight(shared_ptr<AbstractMatrix> m) { return nullptr; };
	//����һ������������Ԫ��ִ��������� 
	virtual shared_ptr<AbstractMatrix> map(double func(double)) { return nullptr; };
	//��������Ӿ�����������������
	virtual double convolve(size_t top, size_t bottom, size_t left, size_t right, shared_ptr<AbstractMatrix> m) { return 0; }
	virtual shared_ptr<AbstractMatrix> m2vByColumn() { return nullptr; }
	virtual shared_ptr<AbstractMatrix> v2mByColomn(size_t size) { return nullptr; }
	//�������
	virtual bool equals(shared_ptr<AbstractMatrix> m) { return false; };
	virtual shared_ptr<AbstractMatrix> clone() { return nullptr; };
	virtual void print() {};
	virtual ~AbstractMatrix() {};
    virtual shared_ptr<AbstractMatrix> getSharedPtr(){
        return shared_from_this();
    }

	virtual shared_ptr<AbstractMatrix> add_inplace(double x) { return shared_from_this(); };
	virtual shared_ptr<AbstractMatrix> add_inplace(shared_ptr<AbstractMatrix> m) { return shared_from_this(); };
	virtual shared_ptr<AbstractMatrix> add_inplace(int, int, double) { return shared_from_this(); };
	virtual shared_ptr<AbstractMatrix> add_inplace(size_t, size_t, size_t, size_t, shared_ptr<AbstractMatrix>) { return shared_from_this(); };
	virtual shared_ptr<AbstractMatrix> subtract_inplace(double) { return shared_from_this(); };
	virtual shared_ptr<AbstractMatrix> subtract_inplace(shared_ptr<AbstractMatrix>) { return shared_from_this(); };
	virtual shared_ptr<AbstractMatrix> multiple_inplace(double) { return shared_from_this(); };
	virtual shared_ptr<AbstractMatrix> multiple_inplace(shared_ptr<AbstractMatrix>) { return shared_from_this(); };
	virtual shared_ptr<AbstractMatrix> map_inplace(double func(double)) { return shared_from_this(); };

protected:
	size_t rowSize;
	size_t columnSize;
	double **matrix;

	virtual void initialize() {};

};

