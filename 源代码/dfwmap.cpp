#include "dfwmap.h"


/*
��� ���� �Ÿ����� ���� ����� ˫������ ���� ��ƨ˰ ��խ���� ����
�ɶ����ֹ� �Ĵ���ѧ ����· ������è���� ���ͣ����
������ ������ ���� �������� ����˰ �ɶ�����վ ���� ���ɽ ����
����԰ ���������ѧ ����· ���� ̫����
*/

void dfwmap::init()
{
	for (int i = 0; i < 30; i++)
	{
		shared_ptr<site> temp = make_shared<site>(i);
		sites.emplace_back(temp);
	}
	sites[0]->set_status(-4);
	sites[9]->set_status(-4);
	sites[15]->set_status(-4);
	sites[24]->set_status(-5);
	sites[7]->set_status(-1);
	sites[20]->set_status(-1);
	sites[3]->set_status(-2);
	sites[13]->set_status(-2);
	sites[22]->set_status(-2);
	sites[6]->set_status(-3);
	sites[18]->set_status(-3);
	sites[28]->set_status(-3);
}

dfwmap::dfwmap()
{
	init();
}

dfwmap::~dfwmap()
{}