#pragma once
#include<vector>
#include<utility>
#include<memory>
#include"person.h"

using namespace std;

class site
{
public:
	site():id(0), status(0),owner(nullptr),is_shirt(false) {}
	site(int s_id) :id(s_id), status(0), owner(nullptr), is_shirt(false) {}
	~site() = default;
	void set(int c_id)
	{
		id = c_id;
	}
	void set_status(int i)
	{
		status = i;
	}
	void set_owner(shared_ptr<person> p)
	{
		owner = p;
	}
	pair<int, int> get_location()
	{
		return { xs[id],ys[id] };
	}
	int get_price()
	{
		return prices[id];
	}
	string get_name()
	{
		return names[id];
	}
	int get_status()
	{
		return status;
	}
	shared_ptr<person> get_owner()
	{
		return owner;
	}
	int get_id()
	{
		return id;
	}
	void set_shirt(bool b)
	{
		is_shirt = b;
	}
	bool get_shirt()
	{
		return is_shirt;
	}

private:
	int id;
	int status;  
	bool is_shirt;
	//-1��ʾ��˰��-2��ʾ���ᣬ-3��ʾ���ˣ�-4��ʾ���ͣ����/·��������-5��ʾ����
	//0��ʾδ���ۣ�1��ʾ�ѳ��ۣ�2��ʾ������������,3��ʾ���˱��ݣ�4��ʾ�������¾Ƶ�
	shared_ptr<person> owner;

	static vector<int> xs;
	static vector<int> ys;
	static vector<int> prices;
	static vector<string> names;
 };



