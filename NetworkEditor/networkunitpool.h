#ifndef NETWORKUNITPOOL_H

#define NETWORKUNITPOOL
#include <vector>
#include "networkunitbase.h"
#include "cnnsubnet.h"
class DiagramItem;
/*
NetworkUnitPool����ά�������������й����в������������絥Ԫ��ӳ����
һ��NetworkUnit�ڲ�����Ӧ��������ע�ᣬȻ�����︺��������������ռ�ݵĿռ�
*/
namespace NetworkUnitPool{
	extern int idCount;
	extern std::vector<NetworkUnitBase *> networkUnits;
	extern int cnnSubnetIdCount;
	extern std::vector<CNNSubnet*> cnnSubnets;
	/* ע��һ����Ԫ���� */
	void registerUnit(NetworkUnitBase *);
	/* ���һ����Ԫ�����ע��*/
	void unregisterUnit(NetworkUnitBase *);
	/* �����������絥Ԫ����һ���������Ϊ�ڶ���������*/
	void addLink(NetworkUnitBase* start, NetworkUnitBase* end);
	/* ���һ���Ѿ�ע��ĵ�Ԫ����Ĺ�������*/
	NetworkUnitBase * createNetworkUnit(DiagramItem*, NetworkUnitBase::NetworkUnitType);
	/* ���һ��CNN������*/
	CNNSubnet * createSubnet();
	/* �������ͼ״̬�����ڵ���*/
	void outputNetworkGraph(std::ostream& out);
	/* ������ֲ㡣�����һ��int���飬��ʾnetworkUnits��ÿһ��Ӧ�ô��ڵڼ���*/
	std::vector<int > sliceLayers();
	/*
	TODO
	������˴��뽻���ķ���
	*/
}

#endif