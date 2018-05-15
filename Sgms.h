#include<iostream>
#include<string>
#include<vector>

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
};

Student::Student(std::string number,std::string name,double math,double physics,double english)
{
	this->number = number;
	this->name = name;
	this->math = math;
	this->physics = physics;
	this->english = english;
}


class Sgms{
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
    int old_size = List.size();
    for(std::vector<Student>::iterator i = List.begin();i != List.end();i++)
    {
        if(temp_data == (*i).number || temp_data == (*i).name)
        {
            List.erase(i);
            std::cout << "��ɾ���ɹ���" << std::endl;
        }
    }
    int new_size = List.size();
    if(old_size == new_size)std::cout << "��δ�ҵ��˼�¼��" << std::endl;
}

void Sgms::change_record()
{
    std::cout << "������Ҫ�޸ĵļ�¼��ѧ�Ż�����:";
    std::string temp_data;
    int old_size = List.size();
    for(std::vector<Student>::iterator i = List.begin();i != List.end();i++)
    {
        if(temp_data == (*i).number || temp_data == (*i).name)
        {
            int button_2 = 0;
            std::cout << "��ѡ��Ҫ�޸ĵ���Ŀ��"
                    << "1.��ѧ 2.���� 3.Ӣ�� 0.���أ�";
            std::cin >> button_2;
            switch (button_2) {
                case 1:change_data((*i),1);break;
                case 2:change_data((*i),2);break;
                case 3:change_data((*i),3);break;
                case 0:break;
            }
        }
    }
    int new_size = List.size();
    if(old_size == new_size)std::cout << "��δ�ҵ��˼�¼��" << std::endl;
}

void Sgms::search_record()
{
    
}

void Sgms::analyse_record(){}
void Sgms::sort_record(){}
void Sgms::file_record(){}


//����������

void Sgms::change_data(Student &temp_stu,int x)
{
    double data = 0;
    std::cout << "�������޸ĺ�����ݣ�";
    std::cin >> data;
    switch (x) {
        case 1:temp_stu.math = data;break;
        case 2:temp_stu.physics = data;break;
        case 3:temp_stu.english = data;break;
    }
    std::cout << "���޸ĳɹ���" << std::endl;
}
