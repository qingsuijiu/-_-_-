#include "setting.h"


setting::setting() 
{ 
	figures.resize(5);
	loadimage(&background, _T("setting_background.png")); 
	loadimage(&arrow, _T("arrow.png"));
	/*
	IMAGE temp;
	loadimage(&temp, _T("cartoon_gy.png"));
	figures.push_back(temp);
	*/
	loadimage(&figures[1], _T("cartoon_gy.png"));
	loadimage(&figures[2], _T("cartoon_fy.png"));
	loadimage(&figures[3], _T("cartoon_frj.png"));
	loadimage(&figures[4], _T("cartoon_yy.png"));

	largest_round = 20;
	player_num = 2;
	start_money = 10000;
}

void setting::setting_main()
{
	// ��ͼ���ڳ�ʼ��
	initgraph(718, 631);
	refresh();

	round_set();
	start_money_set();
	player_num_set();
	figure_set();

	setting_caption_round("�������������Ϸ����");
	_getch();
	closegraph();
}

void setting::refresh()
{
	putimage(0, 0, &background);

	vector<string> names = { "ƨ������","�ڿ�fy","ʺ�����˾�","�ȱ�����" };
	for (int i = 1; i < figures.size(); i++)
	{
		setting_caption_name(names[i - 1], i);
		putimage(50 + i * 100, 450, &figures[i]);
	}

}

void setting::round_set()
{
	refresh();
	string temp = "���غ�����";
	temp += to_string(largest_round);
	temp += "\n�������٣���������,�س���ʾȷ��";
	setting_caption_round(temp);

	while (1)
	{
		//_getch();
		int c = _getch();
		//c = _getch();
		if (c == 77)  //right key
		{
			largest_round += 5;

			refresh();
			string temp = "���غ�����";
			temp += to_string(largest_round);
			temp += "\n�������٣���������,�س���ʾȷ��";
			setting_caption_round(temp);
		}
		else if (c == 75)  //left key
		{
			if(largest_round >= 5)
				largest_round -= 5;

			refresh();
			string temp = "���غ�����";
			temp += to_string(largest_round);
			temp += "\n�������٣���������,�س���ʾȷ��";
			setting_caption_round(temp);
		}
		else if (c == 13)  //�س�
		{

			break;
		}
		else//�쳣����Ĵ���
		{
			//caption_write(1, "�������������y/n");
		}
	}
}

void setting::start_money_set()
{
	refresh();
	string temp = "��ʼ�ʽ�";
	temp += to_string(start_money);
	temp += "\n�������٣���������,�س���ʾȷ��";
	setting_caption_round(temp);

	while (1)
	{
		//_getch();
		int c = _getch();
		//c = _getch();
		if (c == 77)  //right key
		{
			start_money += 1000;

			refresh();
			string temp = "��ʼ�ʽ�";
			temp += to_string(start_money);
			temp += "\n�������٣���������,�س���ʾȷ��";
			setting_caption_round(temp);
		}
		else if (c == 75)  //left key
		{
			if (start_money > 0)
				start_money -= 1000;

			refresh();
			string temp = "��ʼ�ʽ�";
			temp += to_string(start_money);
			temp += "\n�������٣���������,�س���ʾȷ��";
			setting_caption_round(temp);
		}
		else if (c == 13)  //�س�
		{
			break;
		}
		else//�쳣����Ĵ���
		{
			//caption_write(1, "�������������y/n");
		}
	}
}


void setting::player_num_set()
{
	refresh();
	string temp = "�������";
	temp += to_string(player_num);
	temp += "\n�������٣���������,�س���ʾȷ��";
	setting_caption_round(temp);

	while (1)
	{
		//_getch();
		int c = _getch();
		//c = _getch();
		if (c == 77)  //right key
		{
			player_num++;

			refresh();
			string temp = "�������";
			temp += to_string(player_num);
			temp += "\n�������٣���������,�س���ʾȷ��";
			setting_caption_round(temp);
		}
		else if (c == 75)  //left key
		{
			if (player_num >= 1)
				player_num--;

			refresh();
			string temp = "�������";
			temp += to_string(player_num);
			temp += "\n�������٣���������,�س���ʾȷ��";
			setting_caption_round(temp);
		}
		else if (c == 13)  //�س�
		{
			break;
		}
		else//�쳣����Ĵ���
		{
			//caption_write(1, "�������������y/n");
		}
	}
}

void setting::figure_set()
{
	for (int i = 0; i < player_num; i++)
	{
		refresh();

		arrow_x = 150;

		string temp = "���������";
		temp += to_string(i + 1);
		temp += "ѡ�������ɫ";
		temp += "\n�������ƣ���������,�س���ʾȷ��";
		putimage(arrow_x, 370, &arrow);
		setting_caption_round(temp);
		
		while (1)
		{
			//_getch();
			int c = _getch();
			//c = _getch();
			if (c == 77)  //right key
			{
				refresh();
				if (arrow_x < 450)
					arrow_x += 100;
				putimage(arrow_x, 370, &arrow);
				string temp = "���������";
				temp += to_string(i + 1);
				temp += "ѡ�������ɫ";
				temp += "\n�������ƣ���������,�س���ʾȷ��";
				setting_caption_round(temp);
			}
			else if (c == 75)  //left key
			{
				refresh();
				if (arrow_x > 150)
					arrow_x -= 100;
				putimage(arrow_x, 370, &arrow);
				string temp = "���������";
				temp += to_string(i + 1);
				temp += "ѡ�������ɫ";
				temp += "\n�������ƣ���������,�س���ʾȷ��";
				setting_caption_round(temp);
			}
			else if (c == 13)  //�س�
			{
				kind.push_back((arrow_x - 50) / 100);
				refresh();
				break;
			}
			else//�쳣����Ĵ���
			{
				//caption_write(1, "�������������y/n");
			}
		}

	}
}
