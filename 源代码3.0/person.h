#pragma once
#include<string>
#include<memory>
#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include<stdlib.h>
#include<random>
#include<ctime>

#include"caption.h"

using namespace std;

class person
{
public:
	person() :name("none"), money(0), location(0), kind(0) 
	{  pause = false; }
	person(string s_name, size_t s_money,int k) :
		name(s_name), money(s_money), location(0), kind(k) 
	{
		 pause = false;
	}
	
	virtual ~person(){}
	bool get_pause()
	{
		return pause;
	}
	int get_kind()
	{
		return kind;
	}
	IMAGE* get_picture()
	{
		return &pic;
	}
	size_t get_location()
	{
		return location;
	}
	int get_money() const
	{
		return money;
	}
	string get_name() const
	{
		return name;
	}
	int get_credit() const
	{
		return credit;
	}
	void goto_location(int i) 
	{
		if (i >= 0)
			location = i;
	}
	virtual bool go_steps(int i);
	void set_money(int m)
	{
		money += m;
	}
	void set_pause(bool b)
	{
		pause = b;
	}
	void set_kind(int k)
	{
		if (k >= 0)
			kind = k;
	}
	void set_credit(int c)
	{
		credit += c;
	}
	void acquire_property(int i)
	{
		property.push_back(i);
	}
	int lose_property()
	{
		if (property.size() == 0)
			return -1;
		int res = property[0];
		property.erase(property.begin());
		return res;
	}

	virtual string reach_starting()
	{
		set_money(1000);
		return "";
	}
	virtual int self_land_operations() { return 0; }  //0��ʾ������������1��ʾ����,2��ʾ���ϰ���
	virtual int all_land_operations() { return 0; }
	/*
	//רΪ�ڲ��ṩ
	void set_gy_pic()
	{
		loadimage(&pic, _T("cartoon_gy.png"));
	}
	*/

protected:
	IMAGE pic;
private:
	string name;
	int money;
	int location;
	int kind;
	//bool skill;
	bool pause;
	//���õ㣬�غ���������������ʣ������ۣ���˰��
	int credit;
	vector<int> property;
};

//�м��ܵ��ˣ�û���κ�ʹ�ü�ֵ��ֻ��Ϊ�˴���һЩ������صĺ����ͱ���
class special_man :public person
{
public:
	special_man() :person("special man", 0, 0) { set_skill(true); }
	special_man(string s_name, size_t s_money,int k) :person(s_name, s_money, k) { set_skill(true); }
	virtual ~special_man() {}

	void set_skill(bool b)
	{
		skill = b;
	}
	bool get_skill()
	{
		return skill;
	}
	virtual string reach_starting()
	{
		set_skill(true);
		set_money(1000);
		return "";
	}
private:
	bool skill;
};

//��ƨ��
class fartman :public special_man
{
public:
	fartman() :special_man("fartman", 0, 1) { loadimage(&pic, _T("cartoon_gy.png")); }
	fartman(string s_name, size_t s_money) :special_man(s_name, s_money, 1) 
	{ 
		loadimage(&pic, _T("cartoon_gy.png")); 
	}
	~fartman() {}
	virtual bool go_steps(int i);
private:
	bool fart_push();  //���ܣ���ƨ�ƽ����������Ӻ����ѡ���Ƿ������ǰһ��
};

class hacker :public special_man
{
public:
	hacker() :special_man("hacker", 0, 2) { loadimage(&pic, _T("cartoon_fy.png")); }
	hacker(string s_name, size_t s_money) :special_man(s_name, s_money, 2) 
	{
		loadimage(&pic, _T("cartoon_fy.png"));
	}
	~hacker() {}
	virtual int self_land_operations();
private:
	int attack_bank(); //���ܣ��������У����Լ��ĵز��Ͽɶ�����չ���������ɹ���Ǯ��ʧ������
	//����ֵ 0��δ������1�������ɹ���2������ʧ��
};

class shirtman :public special_man
{
public:
	shirtman() :special_man("shirtman", 0, 3) { loadimage(&pic, _T("cartoon_frj.png")); }
	shirtman(string s_name, size_t s_money) :special_man(s_name, s_money, 3) 
	{ 
		loadimage(&pic, _T("cartoon_frj.png")); 
	}
	~shirtman() {}
	virtual int all_land_operations();
private:
	bool throw_shirt();

};

class cutebaby :public special_man
{
public:
	cutebaby() :special_man("cutebaby", 0, 4) { loadimage(&pic, _T("cartoon_yy.png")); }
	cutebaby(string s_name, size_t s_money) :special_man(s_name, s_money, 4) 
	{
		loadimage(&pic, _T("cartoon_yy.png"));
	}
	~cutebaby() {}
	virtual string reach_starting();
private:
	bool act_cute();

};

class blindBoxGirl :public special_man
{
public:
	blindBoxGirl() :special_man("blindBoxGirl", 0, 4) 
	{ 
		loadimage(&pic, _T("blindboxgirl.png")); 
		loadimage(&ppmt, _T("POPMART.png"));
		loadimage(&arrow, _T("arrow.png"));
		loadimage(&choice_interface, _T("ppmt_choice_interface.png"));
		loadimage(&box, _T("ppmt_box.jpg"));
	}
	blindBoxGirl(string s_name, size_t s_money) :special_man(s_name, s_money, 4)
	{
		loadimage(&pic, _T("blindboxgirl.png"));
		loadimage(&ppmt, _T("POPMART.png"));
		loadimage(&arrow, _T("arrow.png"));
		loadimage(&choice_interface, _T("ppmt_choice_interface.png"));
		loadimage(&box, _T("ppmt_box.jpg"));
		//Resize(&arrow, 30, 24);
	}
	~blindBoxGirl() {}
	virtual string reach_starting();
private:
	IMAGE ppmt;
	IMAGE arrow;
	IMAGE choice_interface;
	IMAGE box;
	vector<int> xs = { 50,190,320,460 };
	vector<int> ys = { 0,230,460 };
	vector<string> names = { "����","��ɫ�ǹ�","С��","������",
							"��ɫ����","Ģ��","������","С����",
							"����֮��","С��Ѽ","����Ȧ","ˮĸ" };
	int take_blind_box();

};


