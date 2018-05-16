#include<iostream>
#include<string>
#include<vector>
#include<iomanip>

class Sgms;

class Student
{
friend class Sgms;

private:
	std::string number;
	std::string name;
	double math,physics,english;

public:
	Student(std::string,std::string,double,double,double);
    void print_data();
};

Student::Student(std::string number,std::string name,double math,double physics,double english)
{
	this->number = number;
	this->name = name;
	this->math = math;
	this->physics = physics;
	this->english = english;
}

void Student::print_data()
{
    std::cout <<
    "ѧ�ţ�" << std::setw(11) << number << " " <<
    "������" << std::setw(6) << name << " " <<
    "��ѧ��" << std::setw(3) << math << " " <<
    "����" << std::setw(3) << physics << " " <<
    "Ӣ�" << std::setw(3) << english << std::endl;
}


class Sgms
{
private:
	std::vector<Student> List;

public:
	void run();

	void add_record();
	void delete_record();
	void change_record();
	void search_record();
	void analyse_record();
	void sort_record();
	void file_record();

    void change_data(Student &,int);
    double double_cin(){double temp;std::cin >> temp;return temp;}
    std::string string_cin(){std::string temp;std::cin >> temp;return temp;}
};

void Sgms::run()
{
	while(1)
	{
		std::cout
		<< "---------------" << std::endl
		<< "    ���ܲ˵�    " << std::endl
		<< "---------------" << std::endl
		<< "1. ¼��ѧ����¼ " << std::endl
		<< "2. ɾ��ѧ����¼" << std::endl
		<< "3. �޸�ѧ����¼" << std::endl
		<< "4. ����ѧ����¼" << std::endl
		<< "5. �ɼ�ͳ�Ʒ���" << std::endl
		<< "6. �ɼ��ߵ�����" << std::endl
		<< "7. �ɼ��ļ�����" << std::endl
		<< "0. �˳�����" << std::endl
		<< "---------------" << std::endl
		<< "��������Ҫʹ�õĹ��ܱ��: ";

		int button_1 = 0;
		std::cin >> button_1;

		if(button_1 == 0){break;}
		else if(button_1 == 1){add_record();}
		else if(button_1 == 2){delete_record();}
		else if(button_1 == 3){change_record();}
		else if(button_1 == 4){search_record();}
		else if(button_1 == 5){analyse_record();}
		else if(button_1 == 6){sort_record();}
		else if(button_1 == 7){file_record();}

        system("pause");
	}
}


//���˵�������

void Sgms::add_record()
{
    std::cout << "��ֱ����룺ѧ�š���������ѧ�ɼ�������ɼ���Ӣ��ɼ�" << std::endl;
    std::string number, name;double math,physics,english;
    int button_2 = 0;
    do{
        std::cin >> number >> name >> math >> physics >> english;
        Student temp_stu(number,name,math,physics,english);
        List.push_back(temp_stu);
        std::cout << "��¼��ɹ���" << std::endl
                << "1.����¼�� 0.���ؽ��棺";
        std::cin >> button_2;
    }while(button_2 == 1);
}

void Sgms::delete_record()
{
    std::cout << "������Ҫɾ���ļ�¼��ѧ�Ż�����:";
    std::string temp_data;
    std::cin >> temp_data;
    for(std::vector<Student>::iterator i = List.begin();i != List.end();)
    {
        if(temp_data == (*i).number || temp_data == (*i).name)
        {
            List.erase(i);
            std::cout << "��ɾ���ɹ���" << std::endl;
            break;
        }
        ++i;
        if(i == List.end())std::cout << "��δ�ҵ��˼�¼��" << std::endl;
    }
}

void Sgms::change_record()
{
    std::cout << "������Ҫ�޸ĵļ�¼��ѧ�Ż�����:";
    std::string temp_data;
    std::cin >> temp_data;
    for(std::vector<Student>::iterator i = List.begin();i != List.end();)
    {
        if(temp_data == (*i).number || temp_data == (*i).name)
        {
            int button_2 = 0;
            std::cout << "��ѡ��Ҫ�޸ĵ���Ŀ��"
                    << "1.��ѧ 2.���� 3.Ӣ�� 4.ѧ�� 5.���� 0.���أ�";
            std::cin >> button_2;
            switch (button_2) {
                case 1:change_data((*i),1);break;
                case 2:change_data((*i),2);break;
                case 3:change_data((*i),3);break;
                case 4:change_data((*i),4);break;
                case 5:change_data((*i),5);break;
                case 0:break;
            }
            break;
        }
        ++i;
        if(i == List.end())std::cout << "��δ�ҵ��˼�¼��" << std::endl;
    }
}

void Sgms::search_record()
{
    std::cout << "1.���˳ɼ� 2.�ɼ�ͳ�� 0.���أ�";
    int button_2 = 0;
    std::cin >> button_2;
    switch(button_2){
        case 1:{
            std::cout << "������Ҫ���ҵļ�¼��ѧ�Ż�����(��ģ������):";
            std::string temp_data;
            std::cin >> temp_data;
            std::cout << "���ҵĽ��Ϊ��" <<std::endl;
            for(std::vector<Student>::iterator i = List.begin();i != List.end();)
            {
                if((*i).number.find(temp_data) != std::string::npos || (*i).name.find(temp_data) != std::string::npos)
                {
                    (*i).print_data();
                }
                ++i;
            }
            break;}
        case 2: ;break;
        case 0: ;break;
    }
}

void Sgms::analyse_record(){}
void Sgms::sort_record(){}
void Sgms::file_record(){}


//����������

void Sgms::change_data(Student &temp_stu,int x)
{
    std::cout << "�������޸ĺ�����ݣ�";
    switch (x) {
        case 1:temp_stu.math = double_cin();break;
        case 2:temp_stu.physics = double_cin();break;
        case 3:temp_stu.english = double_cin();break;
        case 4:temp_stu.number = string_cin();break;
        case 5:temp_stu.name = string_cin();break;
    }
    std::cout << "���޸ĳɹ���" << std::endl;
}
