#ifndef NETWORKUNITPOOL_H

#define NETWORKUNITPOOL
#include <vector>
#include <memory>
#include "networkunitbase.h"
namespace fudandnn{
    class Model;
}
class DiagramItem;
/*
NetworkUnitPool����ά�������������й����в������������絥Ԫ��ӳ����
һ��NetworkUnit�ڲ�����Ӧ��������ע�ᣬȻ�����︺��������������ռ�ݵĿռ�
*/
namespace NetworkUnitPool{
	extern int idCount;
	extern std::vector<NetworkUnitBase *> networkUnits;
	/* ע��һ����Ԫ���� */
	void registerUnit(NetworkUnitBase *);
	/* ���һ����Ԫ�����ע��*/
	void unregisterUnit(NetworkUnitBase *);
	/* �����������絥Ԫ����һ���������Ϊ�ڶ���������*/
	void addLink(NetworkUnitBase* start, NetworkUnitBase* end);
	/* ���һ���Ѿ�ע��ĵ�Ԫ����Ĺ�������*/
	NetworkUnitBase * createNetworkUnit(DiagramItem*, NetworkUnitBase::NetworkUnitType);
	/* �������ͼ״̬�����ڵ���*/
	void outputNetworkGraph(std::ostream& out);
	/* ������ֲ㡣�����һ��int���飬��ʾnetworkUnits��ÿһ��Ӧ�ô��ڵڼ���*/
	std::vector<int > sliceLayers();
    void parseInformation(fudandnn::Model &, std::shared_ptr<Solver>);
	/*
	TODO
	������˴��뽻���ķ���
	*/
}

#endif