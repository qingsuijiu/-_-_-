#include "person.h"

bool person::go_steps(int i)
{
	int new_location = (location + i + 30) % 30;
	//����������ǰ�� ���� ����λ�ñ��С�ھ�λ�ã�����Ϊ��������
	if (i > 0 && new_location < location)
	{
		location = new_location;
		return true;
	}
	else
	{
		location = new_location;
		return false;
	}
}

bool fartman::fart_push()
{
	if (!this->get_skill())
		return false;

	string temp = this->get_name();
	temp += "�Ƿ�ʹ�ü��ܡ���ƨ�ƽ�����y/n��";
	caption_write_r(temp);

	while (1)
	{
		while (!_kbhit());
		char c = _getch();
		if (c == 'y')
		{
			//refresh_background();
			string temp2 = this->get_name();
			temp2 += "���ۡ������������˸������ƨ������������������ǰһ�񣡲�����fy��Ů�ˣ�";
			caption_write_r(temp2);
			this->set_skill(false);
			return true;
		}
		else if (c == 'n')
		{
			string temp2 = this->get_name();
			temp2 += "����ʹ�ü��ܡ���ƨ�ƽ���";
			caption_write_r(temp2);
			return false;
		}
		else//�쳣����Ĵ���
		{
			//caption_write(1, "�������������y/n");
		}
	}
}

bool fartman::go_steps(int i)
{
	bool is_skill = fart_push();
	if (is_skill)
	{
		while (!_kbhit());
		return person::go_steps(i + 1);
	}
	else
		return person::go_steps(i);
}

int hacker::attack_bank()
{
	if (!this->get_skill())
		return false;

	string temp = this->get_name();
	temp += "�Ƿ�ʹ�ü��ܡ��������С���0:���� 1:��500Ԫ(�ɹ���80%��ʧ������) 2:��1000Ԫ��40%�� 3:��1500Ԫ��26%����";
	caption_write_r(temp);

	while (1)
	{
		while (!_kbhit());
		char c = _getch();
		if (c == '0')
		{
			string temp2 = this->get_name();
			temp2 += "����ʹ�ü��ܡ��������С�";
			caption_write_r(temp2);
			return false;
		}
		else if (c == '1')
		{
			static default_random_engine e(time(0));
			static uniform_int_distribution<size_t> u(1, 100);
			string temp2 = this->get_name();
			if (u(e) <= 80)
			{
				this->set_money(500);
				temp2 += "�ɹ��������У�����500Ԫ";
				caption_write_r(temp2);
				this->set_skill(false);
				return 1;
			}
			else
			{
				temp2 += "����ʧ�ܣ���ץ����";
				caption_write_r(temp2);
				this->set_skill(false);
				return 2;
			}
		}
		else if (c == '2')
		{
			static default_random_engine e(time(0));
			static uniform_int_distribution<size_t> u(1, 100);
			string temp2 = this->get_name();
			if (u(e) <= 40)
			{
				this->set_money(1000);
				temp2 += "�ɹ��������У�����1000Ԫ";
				caption_write_r(temp2);
				this->set_skill(false);
				return 1;
			}
			else
			{
				temp2 += "����ʧ�ܣ���ץ����";
				caption_write_r(temp2);
				this->set_skill(false);
				return 2;
			}

		}
		else if (c == '3')
		{
			static default_random_engine e(time(0));
			static uniform_int_distribution<size_t> u(1, 100);
			string temp2 = this->get_name();
			if (u(e) <= 26)
			{
				this->set_money(1500);
				temp2 += "�ɹ��������У�����1500Ԫ";
				caption_write_r(temp2);
				this->set_skill(false);
				return 1;
			}
			else
			{
				temp2 += "����ʧ�ܣ���ץ����";
				caption_write_r(temp2);
				this->set_skill(false);
				return 2;
			}
		}
		else//�쳣����Ĵ���
		{
			//caption_write(1, "�������������y/n");
		}
	}
}

int hacker::self_land_operations()
{
	int res=attack_bank();
	while (!_kbhit());
	if (res == 0 || res == 1)
		return 0;
	else
		return 1;
}

bool shirtman::throw_shirt()
{
	if (!this->get_skill())
		return false;

	string temp = this->get_name();
	temp += "�Ƿ�ʹ�ü��ܡ����Ӵ�㡱��y/n����";
	caption_write_r(temp);

	while (1)
	{
		while (!_kbhit());
		char c = _getch();
		if (c == 'y')
		{
			string temp2 = this->get_name();
			temp2 += "��bia�����������ڵ���������һ���㣬�����������Щ�ɲ��ñ�㲻�ױ����֣�������Ц��Ц������";
			caption_write_r(temp2);
			this->set_skill(false);
			_getch();
			return 1;
		}
		else if (c == 'n')
		{
			string temp2 = this->get_name();
			temp2 += "����ʹ�ü��ܡ����Ӵ�㡱";
			caption_write_r(temp2);
			_getch();
			return 0;
		}
		else//�쳣����Ĵ���
		{
			//caption_write(1, "�������������y/n");
		}
	}
}

int shirtman::all_land_operations()
{
	bool res = throw_shirt();
	if (res == true)
		return 2;
	else
		return 0;
}

bool cutebaby::act_cute()
{
	string temp = "��λ�����ܹܿ���·������";
	temp += this->get_name();
	temp += ",���Ȼ��ˣ���������������������һ���غϣ��Ƿ�Ը�⣨y/n��";
	caption_write_r(temp);
	while (1)
	{
		while (!_kbhit());
		char c = _getch();
		if (c == 'y')
		{
			string temp2 = this->get_name();
			temp2 += "�������£���λ�����ܹܿ��ĵظ�����600Ԫ���!�����»غ����Ͳ��ܼ��������ˡ�";
			caption_write_r(temp2);
			this->set_money(+600);
			this->set_pause(true);
			_getch();
			return 1;
		}
		else if (c == 'n')
		{
			string temp2 = this->get_name();
			temp2 += "�ܾ��˹ְ���˧���壬�������ҪԶ����˧���������100Ԫ��ʳ��";
			caption_write_r(temp2);
			this->set_money(100);
			_getch();
			return 0;
		}
		else//�쳣����Ĵ���
		{
			//caption_write(1, "�������������y/n");
		}
	}
}

void cutebaby::reach_starting()
{
	act_cute();
}