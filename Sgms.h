#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<cmath>

//学生
class Student
{
friend class Sgms;

private:
	std::string number;
	std::string name;
	double math,physics,english;

public:
    Student();
	Student(std::string,std::string,double,double,double);
    void print_data();
    double get_average(){return (math+physics+english)/(3.0);}
};

Student::Student()
{
    number = "none";
    name = "none";
    math = 0;
    physics = 0;
    english = 0;
}

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
    "学号：" << std::setw(11) << number << " " <<
    "姓名：" << std::setw(6) << name << " " <<
    "数学：" << std::setprecision(3) << std::setw(3) << math <<
    " 物理：" << std::setprecision(3) << std::setw(3) << physics <<
    " 英语：" << std::setprecision(3) << std::setw(3) << english <<
    " 平均：" << std::setprecision(3) << std::setw(3) << get_average() << std::endl;
}

//管理系统
class Sgms
{
private:
	std::vector<Student> List;

public:
	void run();

    //菜单函数
	void add_record();
	void delete_record();
	void change_record();
	void search_record();
	void analyse_record();
	void sort_record();
	void file_record();

    //辅助函数
    void change_data(Student &,int);
    void print_section(int);
    void all_average(double &,double &,double &,double &);
    void standard_deviation(
        double &,double &,double &,double &,
        double,double,double,double);
    void qualified_rate(double &,double &,double &,double &);
    double double_cin(){double temp;std::cin >> temp;return temp;}
    std::string string_cin(){std::string temp;std::cin >> temp;return temp;}
};

void Sgms::run()
{
	while(1)
	{
		std::cout
		<< "---------------" << std::endl
		<< "    功能菜单    " << std::endl
		<< "---------------" << std::endl
		<< "1. 录入学生记录 " << std::endl
		<< "2. 删除学生记录" << std::endl
		<< "3. 修改学生记录" << std::endl
		<< "4. 查找学生记录" << std::endl
		<< "5. 成绩统计分析" << std::endl
		<< "6. 成绩高低排序" << std::endl
		<< "7. 成绩文件操作" << std::endl
		<< "0. 退出程序" << std::endl
		<< "---------------" << std::endl
		<< "请输入你要使用的功能编号: ";

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
    std::cout << "请分别输入：学号、姓名、数学成绩、物理成绩、英语成绩" << std::endl;
    std::string number, name;double math,physics,english;
    int button_2 = 0;
    do{
        std::cin >> number >> name >> math >> physics >> english;
        Student temp_stu(number,name,math,physics,english);
        List.push_back(temp_stu);
        std::cout << "！录入成功！" << std::endl
                << "1.继续录入 0.返回界面：";
        std::cin >> button_2;
    }while(button_2 == 1);
}

void Sgms::delete_record()
{
    std::cout << "请输入要删除的记录的学号或姓名:";
    std::string temp_data;
    std::cin >> temp_data;
    for(std::vector<Student>::iterator i = List.begin();i != List.end();)
    {
        if(temp_data == (*i).number || temp_data == (*i).name)
        {
            List.erase(i);
            std::cout << "！删除成功！" << std::endl;
            break;
        }
        ++i;
        if(i == List.end())std::cout << "！未找到此记录！" << std::endl;
    }
}

void Sgms::change_record()
{
    std::cout << "请输入要修改的记录的学号或姓名:";
    std::string temp_data;
    std::cin >> temp_data;
    for(std::vector<Student>::iterator i = List.begin();i != List.end();)
    {
        if(temp_data == (*i).number || temp_data == (*i).name)
        {
            int button_2 = 0;
            std::cout << "请选择要修改的项目："
                    << "1.数学 2.物理 3.英语 4.学号 5.姓名 0.返回：";
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
        if(i == List.end())std::cout << "！未找到此记录！" << std::endl;
    }
}

void Sgms::search_record()
{
    std::cout << "1.个人成绩 2.分段名单 0.返回：";
    int button_2 = 0;
    std::cin >> button_2;
    switch(button_2){
        case 1:{
            std::cout << "请输入要查找的记录的学号或姓名(可模糊查找):";
            std::string temp_data;
            std::cin >> temp_data;
            std::cout << "查找的结果为：" << std::endl;
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
            std::cout << "1.数学 2.语文 3.英语 4.平均分：";
            int button_3 = 0;
            std::cin >> button_3;
            print_section(button_3);
        }break;
        case 0:break;
    }
}

void Sgms::analyse_record()
{
    double math_average = 0,english_average = 0,physics_average = 0,average_average = 0;
    double math_dev = 0,english_dev = 0,physics_dev = 0,average_dev = 0;
    double math_qua = 0,english_qua = 0,physics_qua = 0,average_qua = 0;

    all_average(math_average,physics_average,english_average,average_average);
    standard_deviation(math_dev,physics_dev,english_dev,average_dev,
        math_average,physics_average,english_average,average_average);
    qualified_rate(math_qua,physics_qua,english_qua,average_qua);

    std::cout << "平均成绩：" << std::endl
            << "数学：" << std::setprecision(4) << std::setw(4) << math_average
            << " 物理：" << std::setprecision(4) << std::setw(4) << physics_average
            << " 英语：" << std::setprecision(4) << std::setw(4) << english_average
            << " 总体：" << std::setprecision(4) << std::setw(4) << average_average <<std::endl
            << "标准差：" << std::endl
            << "数学：" << std::setprecision(4) << std::setw(4) << math_dev
            << " 物理：" << std::setprecision(4) << std::setw(4) << physics_dev
            << " 英语：" << std::setprecision(4) << std::setw(4) << english_dev
            << " 总体：" << std::setprecision(4) << std::setw(4) << average_dev <<std::endl
            << "合格率：" << std::endl
            << "数学：" << std::setprecision(3) << std::setw(3) << math_qua << "%"
            << " 物理：" << std::setprecision(3) << std::setw(3) << physics_qua << "%"
            << " 英语：" << std::setprecision(3) << std::setw(3) << english_qua << "%"
            << " 总体：" << std::setprecision(3) << std::setw(3) << average_qua << "%" << std::endl;
}

void Sgms::sort_record()
{
    int i,j;Student T;
    for(i = 0;i < (int)List.size()-1;i++)
    {
        for(j = 0;j < (int)List.size()-1-i;j++)
        {
            if(List[j].get_average() < List[j+1].get_average()
                && fabs(List[j].get_average()-List[j+1].get_average()) > 1E-6)
            {T = List[j];List[j] = List[j+1];List[j+1] = T;}
            if(fabs(List[j].get_average()-List[j+1].get_average()) <= 1E-6)
            {
                if(List[j].math < List[j+1].math
                    && fabs(List[j].math-List[j+1].math) > 1E-6)
                {T = List[j];List[j] = List[j+1];List[j+1] = T;}
                if(fabs(List[j].math-List[j+1].math) <= 1E-6)
                {
                    if(List[j].physics < List[j+1].physics
                        && fabs(List[j].physics-List[j+1].physics) > 1E-6)
                    {T = List[j];List[j] = List[j+1];List[j+1] = T;}
                    if(fabs(List[j].physics-List[j+1].physics) <= 1E-6)
                    {
                        if(List[j].english < List[j+1].english
                            && fabs(List[j].english-List[j+1].english) > 1E-6)
                        {T = List[j];List[j] = List[j+1];List[j+1] = T;}
                        if(fabs(List[j].english-List[j+1].english) <= 1E-6)
                        {
                            if(std::stoi(List[j].number) < std::stoi(List[j+1].number)
                                && fabs(std::stoi(List[j].number)-std::stoi(List[j+1].number)) > 1E-6)
                            {T = List[j];List[j] = List[j+1];List[j+1] = T;}
                        }
                    }
                }
            }
        }
    }
    std::cout << "！排序成功！" << std::endl
            << "1.查看 0.返回:";
    int button_2 = 0;
    std::cin >> button_2;
    switch (button_2) {
        case 1:
            for(std::vector<Student>::iterator i = List.begin();i != List.end();i++)
            {(*i).print_data();}
            break;
        case 0:break;
    }
}

void Sgms::file_record()
{

}


void Sgms::change_data(Student &temp_stu,int x)
{
    std::cout << "请输入修改后的内容：";
    switch (x) {
        case 1:temp_stu.math = double_cin();break;
        case 2:temp_stu.physics = double_cin();break;
        case 3:temp_stu.english = double_cin();break;
        case 4:temp_stu.number = string_cin();break;
        case 5:temp_stu.name = string_cin();break;
    }
    std::cout << "！修改成功！" << std::endl;
}

void Sgms::print_section(int x)
{
    std::cout << "请输入成绩分段的最低分与最高分：";
    double bottom = 0,top = 100;
    std::cin >> bottom >> top;
    std::cout << "查找的结果为：" << std::endl;
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

void Sgms::all_average(
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

void Sgms::standard_deviation(
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

void Sgms::qualified_rate(
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
