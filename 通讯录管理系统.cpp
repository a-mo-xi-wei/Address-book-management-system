#include<iostream>
#include<string> 
#include<conio.h>
#define MAX 100
void showMenu(){
	std::cout << "\t\t\t\t\t" << "     欢迎使用通讯录" << "\n"
			  << "\t\t\t\t\t" << "**************************" << "\n"
			  << "\t\t\t\t\t" << "*****  1.添加联系人  *****" << "\n"
			  << "\t\t\t\t\t" << "*****  2.显示联系人  *****" << "\n"
			  << "\t\t\t\t\t" << "*****  3.删除联系人  *****" << "\n"
			  << "\t\t\t\t\t" << "*****  4.查找联系人  *****" << "\n"
			  << "\t\t\t\t\t" << "*****  5.修改联系人  *****" << "\n"
			  << "\t\t\t\t\t" << "*****  6.清空联系人  *****" << "\n"
			  << "\t\t\t\t\t" << "*****  0.退出通讯录  *****" << "\n"
			  << "\t\t\t\t\t" << "**************************" << std::endl;
}
struct Person {
	//姓名
	std::string m_Name;
	//性别1男2女
	std::string m_Sex;
	//年龄
	int m_Age;
	//电话
	std::string m_Phone;
	//住址
	std::string m_Addr;
};

struct Addressbooks {
	//通讯录中保存的联系人数组
	struct Person personarry[MAX];
	//通讯录中当前记录联系人个数
	int m_Size=0;
};
//1.添加联系人
void addPerson(Addressbooks* abs) {
	if (abs->m_Size == MAX) {
		std::cout << "通讯录已满，无法添加！" << std::endl;
	}
	else {
		std::string name;
		std::cout << "请输入姓名：" << std::endl;
		std::cin >> name;
		abs->personarry[abs->m_Size].m_Name = name;
		std::cout << "请输入性别：" << std::endl;
		std::string sex;
		std::cin >> sex;
		abs->personarry[abs->m_Size].m_Sex = sex;
		std::cout << "请输入年龄：" << std::endl;
		int age = 0;
		while (true) {
			std::cin >> age;
			if (0 < age && age < 150) {
				abs->personarry[abs->m_Size].m_Age = age;
				break;
			}
			else {
				std::cout << "输入有误，请重新输入！" << std::endl;
			}
		}
		std::cout << "请输入联系电话：" << std::endl;
		std::string phone;
		std::cin >> phone;
		abs->personarry[abs->m_Size].m_Phone = phone;
		std::cout << "请输入家庭住址：" << std::endl;
		std::string addr;
		std::cin >> addr;
		abs->personarry[abs->m_Size].m_Addr = addr;
		abs->m_Size++;
		std::cout << "添加成功！" << std::endl;
		system("pause");//请按任意键继续
		system("cls");
	}
}
//2.显示联系人
void showPerson(Addressbooks * abs){
	if (abs->m_Size == 0) {
		std::cout << "当前记录为空！" << std::endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			std::cout << "姓名：" << abs->personarry[i].m_Name
				<< "\t" << "性别：" << abs->personarry[i].m_Sex
				<< "\t" << "年龄：" << abs->personarry[i].m_Age
				<< "\t" << "联系电话：" << abs->personarry[i].m_Phone
				<< "\t" << "家庭住址：" << abs->personarry[i].m_Addr
				<< std::endl;
		}
	}
	system("pause");
	system("cls");
}
//检测联系人是否存在，若存在，返回联系人所在数组中的具体位置，否则返回-1
int isExist(Addressbooks * abs, std::string name){
	for (int i = 0; i < abs->m_Size; i++) {
		if (name == abs->personarry[i].m_Name) {
			return i;
		}
	}
    return -1;
}
//3.删除指定的联系人
void deletePerson(Addressbooks * abs) {
	std::cout << "请输入您要删除的联系人：";
	std::string name;
	std::cin >> name;
	int ret = isExist(abs, name);//这里不用*abs是因为已经被deletePerson封装好了
	if (ret != -1) {
		std::cout << "是否决定要删除此人？" << std::endl;
		std::cout << "1-----yes" << "\n" << "2-----no" << std::endl;
		int key = _getch();
		if (key == '1'/*注意使用_getch时其结果要用‘’*/) {
			for (int i = ret; i < abs->m_Size; i++) {
				abs->personarry[i] = abs->personarry[i + 1];//数据前移
			}
			abs->m_Size--;
			std::cout << "删除成功！" << std::endl;
		}
		else {
			std::cout << "删除失败！" << std::endl;
		}
	}
	else {
		std::cout << "查无此人！" << std::endl;
	}
	system("pause");
	system("cls");
}
//4.查找指定联系人信息
void  findPerson(Addressbooks* abs) {
	std::cout << "请输入要查找的联系人：";
	std::string name;
	std::cin >> name;
	int ret=isExist(abs, name);
	if (ret != -1) {
		std::cout << "姓名：" << abs->personarry[ret].m_Name
			<< "\t" << "性别：" << abs->personarry[ret].m_Sex
			<< "\t" << "年龄：" << abs->personarry[ret].m_Age
			<< "\t" << "联系电话：" << abs->personarry[ret].m_Phone
			<< "\t" << "家庭住址：" << abs->personarry[ret].m_Addr
			<< std::endl;
	}
	else {
		std::cout << "查无此人！" << std::endl;
	}
	system("pause");
	system("cls");
}
//5.修改指定联系人信息
void modiPerson(Addressbooks* abs) {
	std::cout << "请输入要修改的联系人：";
	std::string name;
	std::cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		std::string name;
		std::cout << "请输入姓名：" << std::endl;
		std::cin >> name;
		abs->personarry[ret].m_Name = name;
		std::cout << "请输入性别：" << std::endl;
		std::string sex;
		std::cin >> sex;
		abs->personarry[ret].m_Sex = sex;
		std::cout << "请输入年龄：" << std::endl;
		int age = 0;
		while (true) {
			std::cin >> age;
			if (0 < age || age < 150) {
				abs->personarry[ret].m_Age = age;
				break;
			}
			std::cout << "输入有误，请重新输入！" << std::endl;
		}
		std::cout << "请输入联系电话：" << std::endl;
		std::string phone;
		std::cin >> phone;
		abs->personarry[ret].m_Phone = phone;
		std::cout << "请输入家庭住址：" << std::endl;
		std::string addr;
		std::cin >> addr;
		abs->personarry[ret].m_Addr = addr;
		std::cout << "修改成功！" << std::endl;
		system("pause");
		system("cls");
	}
	else {
		std::cout << "查无此人！" << std::endl;
		system("pause");
		system("cls");
	}
}
//清空联系人
void cleanPerson(Addressbooks* abs) {
	std::cout << "是否决定清空联系人？" << std::endl;
	std::cout << "1-----yes" << "\n" << "2-----no" << std::endl;
	int key = _getch();
	if (key == '1') {
		abs->m_Size = 0;
		std::cout << "通讯录已清空" << std::endl;
		system("pause");
		system("cls");
	}
	else {
		std::cout << "清空失败！" << std::endl;
		system("pause");
		system("cls");
	}
}
int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0;
	int select = 0;
	while (true) {
		showMenu();
		std::cout << "请选择功能：";
		std::cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs);//利用地址传递可以修饰实参
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3: {        //用大括号解决其变量作用域
			//std::cout << "请输入要删除的联系人姓名：";
			//std::string name;
			//std::cin >> name;
			//if (isExist(&abs, name) == -1) {
			//	std::cout << "查无此人！" << std::endl;	
			//}
			//else {
			//	std::cout << "找到此人。" << std::endl;
			//}
			deletePerson(&abs);
			break;
		}
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modiPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0:
			std::cout << "欢迎下次使用！" << std::endl;
			system("pause");
			return 0;
			break;
		default:
			system("cls");
			std::cout << "错误输入！请重新输入" << std::endl;
			break;
		}
	}
	system("pause");
	return 0;

}
