#include "setting.h"

vector<string> setting::names = { "ƨ������","�ڿ�fy","ʺ�����˾�","�ȱ�����","ä����Ů" };
vector<int> setting::figure_xs = { 100,200,300,400,500 };
int setting::figure_y = 450;
int setting::arrow_x_change = 100;

setting::setting() 
{ 
	figures.resize(5);
	loadimage(&background, _T("setting_background.png")); 
	loadimage(&arrow, _T("arrow.png"));

	loadimage(&figures[0], _T("cartoon_gy.png"));
	loadimage(&figures[1], _T("cartoon_fy.png"));
	loadimage(&figures[2], _T("cartoon_frj.png"));
	loadimage(&figures[3], _T("cartoon_yy.png"));
	loadimage(&figures[4], _T("blindboxgirl.png"));

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

	for (int i = 0; i < figures.size(); i++)
	{
		setting_caption_name(names[i], i);
		putimage(figure_xs[i], figure_y, &figures[i]);
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

void setting::figure_set_inf(int i)
{
	string temp = "���������";
	temp += to_string(i);
	temp += "ѡ�������ɫ";
	temp += "\n�������ƣ���������,�س���ʾȷ��";
	setting_caption_round(temp);
}

void setting::figure_set()
{
	for (int i = 0; i < player_num; i++)
	{
		refresh();

		//��ʾ��ʼ��ͷ
		arrow_x = figure_xs[0];
		const int arrow_y = 370;
		const int arrow_x_offset = 20;
		putimage(arrow_x + arrow_x_offset, arrow_y, &arrow);

		//��ʾ����ѡ��ʽ
		figure_set_inf(i + 1);
	
		while (1)
		{
			//_getch();
			int c = _getch();
			//c = _getch();
			if (c == 77)  //right key
			{
				refresh();
				if (arrow_x < figure_xs[figure_xs.size()-1])
					arrow_x += arrow_x_change;
				putimage(arrow_x + arrow_x_offset, arrow_y, &arrow);
				figure_set_inf(i + 1);
			}
			else if (c == 75)  //left key
			{
				refresh();
				if (arrow_x > figure_xs[0])
					arrow_x -= arrow_x_change;
				putimage(arrow_x + arrow_x_offset, arrow_y, &arrow);
				figure_set_inf(i + 1);
			}
			else if (c == 13)  //�س�
			{
				kind.push_back((arrow_x - figure_xs[0]) / arrow_x_change + 1);
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
