#pragma once
#include "AbstractMatrix.h"

using namespace std;

class Matrix : public AbstractMatrix
{

public:
	Matrix(size_t rowSize, size_t columnSize);
	Matrix();	
    ~Matrix() override;
	//��ʼ������ʹ�þ���ĳ�ʼ��ֵ���½���[lowerBound, upperBound)֮��
	void initializeValue(double lowerBound, double upperBound) override;
	void initializeBinaryValue(double p) override;
	//Ԫ�غ�
	double sum() override;
	//Ԫ�����ֵ
	double max() override;
	//�Ӿ���Ԫ�����ֵ
	shared_ptr<MaxData> max(int top, int bottom, int left, int right) override;
	//Ԫ����Сֵ
	double min() override;
	//1-����������Ԫ�ؾ���ֵ��
	double norm1() override;
	//2-����������Ԫ��ƽ����
	double norm2() override;
	//����ļ���������Խ���Ԫ�غ�
	double trace() override;
	//����ת��
	shared_ptr<AbstractMatrix> transpose() override;
	//�Ӿ���Խ�籨��
	shared_ptr<AbstractMatrix> submatrix(int top, int bottom, int left, int right) override;
	//�Ӿ���,Խ���ȡ
	shared_ptr<AbstractMatrix> submatrixShrink(int top, int bottom, int left, int right)override;
	//�Ӿ���Խ���	
	shared_ptr<AbstractMatrix> submatrixExpand(int top, int bottom, int left, int right)override;
	//�����з���,[0, row_index), [row_index, row_size)
	vector<shared_ptr<AbstractMatrix>> splitRow(size_t rowIndex) override;
	//�����з���,[0, collumn_index), [collumn_index, collumn_size)
	vector<shared_ptr<AbstractMatrix>> splitColumn(size_t columnIndex) override;
	//�ϲ��Ӿ������¾���Ĭ�ϵ�ǰ����Ϊ���Ͼ���
	shared_ptr<AbstractMatrix> merge(shared_ptr<AbstractMatrix> rightTop, shared_ptr<AbstractMatrix> leftBottom, 
		shared_ptr<AbstractMatrix> rightBottom) override;
	//���кϲ��Ӿ������¾���Ĭ�ϵ�ǰ����Ϊ�Ͼ���
	shared_ptr<AbstractMatrix> mergeRow(shared_ptr<AbstractMatrix> bottom) override;
	//���кϲ��Ӿ������¾���Ĭ�ϵ�ǰ����Ϊ�����
	shared_ptr<AbstractMatrix> mergeColumn(shared_ptr<AbstractMatrix> right) override;
	//��������ֵ��d
	shared_ptr<AbstractMatrix> add(double x) override;
	//�������
	shared_ptr<AbstractMatrix> add(shared_ptr<AbstractMatrix> m) override;
	//λ��(i,j)��value
	shared_ptr<AbstractMatrix> add(int i, int j, double value) override;
	//���Ӿ���
	shared_ptr<AbstractMatrix> add(size_t top, size_t bottom, size_t left, size_t right, shared_ptr<AbstractMatrix> m) override;
	//��������ֵ��d
	shared_ptr<AbstractMatrix> subtract(double x) override;
	//�������
	shared_ptr<AbstractMatrix> subtract(shared_ptr<AbstractMatrix> m) override;
	//��������ֵ��d
	shared_ptr<AbstractMatrix> multiple(double x) override;
	//��������ֵ��ͬλ�����
	shared_ptr<AbstractMatrix> multiple(shared_ptr<AbstractMatrix> m) override;
	//���������˵�ǰ���󣬼�mnullptr
	shared_ptr<AbstractMatrix> multipleLeft(shared_ptr<AbstractMatrix> m) override;
	//��������ҳ˵�ǰ���󣬼�this*m
	shared_ptr<AbstractMatrix> multipleRight(shared_ptr<AbstractMatrix> m) override;
	//����һ������������Ԫ��ִ���������
	shared_ptr<AbstractMatrix> map(double func(double)) override;
	//��������Ӿ�����������������
	double convolve(size_t top, size_t bottom, size_t left, size_t right, shared_ptr<AbstractMatrix> m) override;
	shared_ptr<AbstractMatrix> m2vByColumn() override;
	shared_ptr<AbstractMatrix> v2mByColomn(size_t size) override;
	//�������
	bool equals(shared_ptr<AbstractMatrix> m) override;
	shared_ptr<AbstractMatrix> clone() override;
	void print() override;

	shared_ptr<AbstractMatrix> add_inplace(double x) override;
	shared_ptr<AbstractMatrix> add_inplace(shared_ptr<AbstractMatrix> m) override;
	shared_ptr<AbstractMatrix> add_inplace(int, int, double) override;
	shared_ptr<AbstractMatrix> add_inplace(size_t, size_t, size_t, size_t, shared_ptr<AbstractMatrix>) override;
	shared_ptr<AbstractMatrix> subtract_inplace(double) override;
	shared_ptr<AbstractMatrix> subtract_inplace(shared_ptr<AbstractMatrix>) override;
	shared_ptr<AbstractMatrix> multiple_inplace(double) override;
	shared_ptr<AbstractMatrix> multiple_inplace(shared_ptr<AbstractMatrix>) override;
	shared_ptr<AbstractMatrix> map_inplace(double func(double)) override;

private:
	void initialize() override;

};
