#pragma once
#include "networkunitbase.h"
class CNNSubnet;
class CNNUnitBase :
	public NetworkUnitBase
{
	friend CNNSubnet;
private:
	int bindCNNSubnetId;
public:
	virtual bool isAvailbleInput(NetworkUnitBase*) override;
	virtual bool isAvailbleOutput(NetworkUnitBase*) override;
	/*
		��ȡ��CNN�ڵ�����ĸ�CNN�������ϣ����Ϊ-1��ʾû�а󶨣�Ӧ���������ͷŻ��߰󶨡�
	*/
	int getSubnetId() const {
		return bindCNNSubnetId;
	}
	CNNUnitBase(DiagramItem *, NetworkUnitType typeId);
	~CNNUnitBase();
};

