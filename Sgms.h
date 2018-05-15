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

void Sgms::add_record(){}
void Sgms::delete_record(){}
void Sgms::change_record(){}
void Sgms::search_record(){}
void Sgms::analyse_record(){}
void Sgms::sort_record(){}
void Sgms::file_record(){}