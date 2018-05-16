#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<cmath>

//ѧ��
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
    double get_average(){return (math+physics+english)/(3.0);}
};

Student::Student(
    std::string number,
    std::string name,
    double math,
    double physics,
    double english)
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
    "��ѧ��" << std::setprecision(3) << std::setw(3) << math <<
    " ����" << std::setprecision(3) << std::setw(3) << physics <<
    " Ӣ�" << std::setprecision(3) << std::setw(3) << english <<
    " ƽ����" << std::setprecision(3) << std::setw(3) << get_average() << std::endl;
}

//����ϵͳ
class Sgms
{
private:
	std::vector<Student> List;

public:
	void run();

    //�˵�����
	void add_record();
	void delete_record();
	void change_record();
	void search_record();
	void analyse_record();
	void sort_record();
	void file_record();

    //��������
    void change_data(Student &,int);
    void print_section(std::vector<Student> &,int);
    void all_average(std::vector<Student> &,double &,double &,double &,double &);
    void standard_deviation(std::vector<Student> &,
        double &,double &,double &,double &,
        double,double,double,double);
    void qualified_rate(std::vector<Student> &,double &,double &,double &,double &);
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
    std::cout << "1.���˳ɼ� 2.�ֶ����� 0.���أ�";
    int button_2 = 0;
    std::cin >> button_2;
    switch(button_2){
        case 1:{
            std::cout << "������Ҫ���ҵļ�¼��ѧ�Ż�����(��ģ������):";
            std::string temp_data;
            std::cin >> temp_data;
            std::cout << "���ҵĽ��Ϊ��" << std::endl;
            for(std::vector<Student>::iterator i = List.begin();i != List.end();)
            {
                if((*i).number.find(temp_data) != std::string::npos || (*i).name.find(temp_data) != std::string::npos)
                {
                    (*i).print_data();
                }
                ++i;
            }
        }break;
        case 2:{
            std::cout << "1.��ѧ 2.���� 3.Ӣ�� 4.ƽ���֣�";
            int button_3 = 0;
            std::cin >> button_3;
            print_section(List,button_3);
        }break;
        case 0:break;
    }
}

void Sgms::analyse_record()
{
    double math_average = 0,english_average = 0,physics_average = 0,average_average = 0;
    double math_dev = 0,english_dev = 0,physics_dev = 0,average_dev = 0;
    double math_qua = 0,english_qua = 0,physics_qua = 0,average_qua = 0;

    all_average(List,math_average,physics_average,english_average,average_average);
    standard_deviation(List,math_dev,physics_dev,english_dev,average_dev,
        math_average,physics_average,english_average,average_average);
    qualified_rate(List,math_qua,physics_qua,english_qua,average_qua);

    std::cout << "ƽ���ɼ���" << std::endl
            << "��ѧ��" << std::setprecision(4) << std::setw(4) << math_average
            << " ����" << std::setprecision(4) << std::setw(4) << physics_average
            << " Ӣ�" << std::setprecision(4) << std::setw(4) << english_average
            << " ���壺" << std::setprecision(4) << std::setw(4) << average_average <<std::endl
            << "��׼�" << std::endl
            << "��ѧ��" << std::setprecision(4) << std::setw(4) << math_dev
            << " ����" << std::setprecision(4) << std::setw(4) << physics_dev
            << " Ӣ�" << std::setprecision(4) << std::setw(4) << english_dev
            << " ���壺" << std::setprecision(4) << std::setw(4) << average_dev <<std::endl
            << "�ϸ��ʣ�" << std::endl
            << "��ѧ��" << std::setprecision(3) << std::setw(3) << math_qua << "%"
            << " ����" << std::setprecision(3) << std::setw(3) << physics_qua << "%"
            << " Ӣ�" << std::setprecision(3) << std::setw(3) << english_qua << "%"
            << " ���壺" << std::setprecision(3) << std::setw(3) << average_qua << "%" << std::endl;
}

void Sgms::sort_record()
{

}

void Sgms::file_record()
{
    
}


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

void Sgms::print_section(std::vector<Student> &List,int x)
{
    std::cout << "������ɼ��ֶε���ͷ�����߷֣�";
    double bottom = 0,top = 100;
    std::cin >> bottom >> top;
    std::cout << "���ҵĽ��Ϊ��" << std::endl;
    for(std::vector<Student>::iterator i = List.begin();i != List.end();)
    {
        switch (x) {
            case 1:if((*i).math >= bottom && (*i).math <= top)(*i).print_data();break;
            case 2:if((*i).physics >= bottom && (*i).physics <= top)(*i).print_data();break;
            case 3:if((*i).english >= bottom && (*i).english <= top)(*i).print_data();break;
            case 4:if((*i).get_average() >= bottom && (*i).get_average() <= top)(*i).print_data();break;
        }
        ++i;
    }
}

void Sgms::all_average(std::vector<Student> &List,
    double &math_average,double &physics_average,double &english_average,double &average_average)
{
    for(std::vector<Student>::iterator i = List.begin();i != List.end();)
    {
        math_average += (*i).math;
        physics_average += (*i).physics;
        english_average += (*i).english;
        average_average += (*i).get_average();
        ++i;
    }
    math_average /= List.size();
    physics_average /= List.size();
    english_average /= List.size();
    average_average /= List.size();
}

void Sgms::standard_deviation(std::vector<Student> &List,
    double &math_dev,double &physics_dev,double &english_dev,double &average_dev,
    double math_average,double physics_average,double english_average,double average_average)
{
    for(std::vector<Student>::iterator i = List.begin();i != List.end();)
    {
        math_dev += ((*i).math - math_average)*((*i).math - math_average);
        physics_dev += ((*i).physics - physics_average)*((*i).physics - physics_average);
        english_dev += ((*i).english - english_average)*((*i).english - english_average);
        average_dev += ((*i).get_average() - average_average)*((*i).get_average() - average_average);
        ++i;
    }
    math_dev = sqrt(math_dev/List.size());
    physics_dev = sqrt(physics_dev/List.size());
    english_dev = sqrt(english_dev/List.size());
    average_dev = sqrt(average_dev/List.size());
}

void Sgms::qualified_rate(std::vector<Student> &List,
    double &math_qua,double &physics_qua,double &english_qua,double &average_qua)
{
    for(std::vector<Student>::iterator i = List.begin();i != List.end();)
    {
        if((*i).math >= 60)math_qua += 1;
        if((*i).physics >= 60)physics_qua += 1;
        if((*i).english >= 60)english_qua += 1;
        if((*i).get_average() >= 60)average_qua += 1;
        ++i;
    }
    math_qua = (math_qua/List.size())*100;
    physics_qua = (physics_qua/List.size())*100;
    english_qua = (english_qua/List.size())*100;
    average_qua = (average_qua/List.size())*100;
}
