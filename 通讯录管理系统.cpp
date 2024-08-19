#include<iostream>
#include<string> 
#include<conio.h>
#define MAX 100
void showMenu(){
	std::cout << "\t\t\t\t\t" << "     ��ӭʹ��ͨѶ¼" << "\n"
			  << "\t\t\t\t\t" << "**************************" << "\n"
			  << "\t\t\t\t\t" << "*****  1.�����ϵ��  *****" << "\n"
			  << "\t\t\t\t\t" << "*****  2.��ʾ��ϵ��  *****" << "\n"
			  << "\t\t\t\t\t" << "*****  3.ɾ����ϵ��  *****" << "\n"
			  << "\t\t\t\t\t" << "*****  4.������ϵ��  *****" << "\n"
			  << "\t\t\t\t\t" << "*****  5.�޸���ϵ��  *****" << "\n"
			  << "\t\t\t\t\t" << "*****  6.�����ϵ��  *****" << "\n"
			  << "\t\t\t\t\t" << "*****  0.�˳�ͨѶ¼  *****" << "\n"
			  << "\t\t\t\t\t" << "**************************" << std::endl;
}
struct Person {
	//����
	std::string m_Name;
	//�Ա�1��2Ů
	std::string m_Sex;
	//����
	int m_Age;
	//�绰
	std::string m_Phone;
	//סַ
	std::string m_Addr;
};

struct Addressbooks {
	//ͨѶ¼�б������ϵ������
	struct Person personarry[MAX];
	//ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int m_Size=0;
};
//1.�����ϵ��
void addPerson(Addressbooks* abs) {
	if (abs->m_Size == MAX) {
		std::cout << "ͨѶ¼�������޷���ӣ�" << std::endl;
	}
	else {
		std::string name;
		std::cout << "������������" << std::endl;
		std::cin >> name;
		abs->personarry[abs->m_Size].m_Name = name;
		std::cout << "�������Ա�" << std::endl;
		std::string sex;
		std::cin >> sex;
		abs->personarry[abs->m_Size].m_Sex = sex;
		std::cout << "���������䣺" << std::endl;
		int age = 0;
		while (true) {
			std::cin >> age;
			if (0 < age && age < 150) {
				abs->personarry[abs->m_Size].m_Age = age;
				break;
			}
			else {
				std::cout << "�����������������룡" << std::endl;
			}
		}
		std::cout << "��������ϵ�绰��" << std::endl;
		std::string phone;
		std::cin >> phone;
		abs->personarry[abs->m_Size].m_Phone = phone;
		std::cout << "�������ͥסַ��" << std::endl;
		std::string addr;
		std::cin >> addr;
		abs->personarry[abs->m_Size].m_Addr = addr;
		abs->m_Size++;
		std::cout << "��ӳɹ���" << std::endl;
		system("pause");//�밴���������
		system("cls");
	}
}
//2.��ʾ��ϵ��
void showPerson(Addressbooks * abs){
	if (abs->m_Size == 0) {
		std::cout << "��ǰ��¼Ϊ�գ�" << std::endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			std::cout << "������" << abs->personarry[i].m_Name
				<< "\t" << "�Ա�" << abs->personarry[i].m_Sex
				<< "\t" << "���䣺" << abs->personarry[i].m_Age
				<< "\t" << "��ϵ�绰��" << abs->personarry[i].m_Phone
				<< "\t" << "��ͥסַ��" << abs->personarry[i].m_Addr
				<< std::endl;
		}
	}
	system("pause");
	system("cls");
}
//�����ϵ���Ƿ���ڣ������ڣ�������ϵ�����������еľ���λ�ã����򷵻�-1
int isExist(Addressbooks * abs, std::string name){
	for (int i = 0; i < abs->m_Size; i++) {
		if (name == abs->personarry[i].m_Name) {
			return i;
		}
	}
    return -1;
}
//3.ɾ��ָ������ϵ��
void deletePerson(Addressbooks * abs) {
	std::cout << "��������Ҫɾ������ϵ�ˣ�";
	std::string name;
	std::cin >> name;
	int ret = isExist(abs, name);//���ﲻ��*abs����Ϊ�Ѿ���deletePerson��װ����
	if (ret != -1) {
		std::cout << "�Ƿ����Ҫɾ�����ˣ�" << std::endl;
		std::cout << "1-----yes" << "\n" << "2-----no" << std::endl;
		int key = _getch();
		if (key == '1'/*ע��ʹ��_getchʱ����Ҫ�á���*/) {
			for (int i = ret; i < abs->m_Size; i++) {
				abs->personarry[i] = abs->personarry[i + 1];//����ǰ��
			}
			abs->m_Size--;
			std::cout << "ɾ���ɹ���" << std::endl;
		}
		else {
			std::cout << "ɾ��ʧ�ܣ�" << std::endl;
		}
	}
	else {
		std::cout << "���޴��ˣ�" << std::endl;
	}
	system("pause");
	system("cls");
}
//4.����ָ����ϵ����Ϣ
void  findPerson(Addressbooks* abs) {
	std::cout << "������Ҫ���ҵ���ϵ�ˣ�";
	std::string name;
	std::cin >> name;
	int ret=isExist(abs, name);
	if (ret != -1) {
		std::cout << "������" << abs->personarry[ret].m_Name
			<< "\t" << "�Ա�" << abs->personarry[ret].m_Sex
			<< "\t" << "���䣺" << abs->personarry[ret].m_Age
			<< "\t" << "��ϵ�绰��" << abs->personarry[ret].m_Phone
			<< "\t" << "��ͥסַ��" << abs->personarry[ret].m_Addr
			<< std::endl;
	}
	else {
		std::cout << "���޴��ˣ�" << std::endl;
	}
	system("pause");
	system("cls");
}
//5.�޸�ָ����ϵ����Ϣ
void modiPerson(Addressbooks* abs) {
	std::cout << "������Ҫ�޸ĵ���ϵ�ˣ�";
	std::string name;
	std::cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		std::string name;
		std::cout << "������������" << std::endl;
		std::cin >> name;
		abs->personarry[ret].m_Name = name;
		std::cout << "�������Ա�" << std::endl;
		std::string sex;
		std::cin >> sex;
		abs->personarry[ret].m_Sex = sex;
		std::cout << "���������䣺" << std::endl;
		int age = 0;
		while (true) {
			std::cin >> age;
			if (0 < age || age < 150) {
				abs->personarry[ret].m_Age = age;
				break;
			}
			std::cout << "�����������������룡" << std::endl;
		}
		std::cout << "��������ϵ�绰��" << std::endl;
		std::string phone;
		std::cin >> phone;
		abs->personarry[ret].m_Phone = phone;
		std::cout << "�������ͥסַ��" << std::endl;
		std::string addr;
		std::cin >> addr;
		abs->personarry[ret].m_Addr = addr;
		std::cout << "�޸ĳɹ���" << std::endl;
		system("pause");
		system("cls");
	}
	else {
		std::cout << "���޴��ˣ�" << std::endl;
		system("pause");
		system("cls");
	}
}
//�����ϵ��
void cleanPerson(Addressbooks* abs) {
	std::cout << "�Ƿ���������ϵ�ˣ�" << std::endl;
	std::cout << "1-----yes" << "\n" << "2-----no" << std::endl;
	int key = _getch();
	if (key == '1') {
		abs->m_Size = 0;
		std::cout << "ͨѶ¼�����" << std::endl;
		system("pause");
		system("cls");
	}
	else {
		std::cout << "���ʧ�ܣ�" << std::endl;
		system("pause");
		system("cls");
	}
}
int main()
{
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;
	int select = 0;
	while (true) {
		showMenu();
		std::cout << "��ѡ���ܣ�";
		std::cin >> select;
		switch (select)
		{
		case 1:
			addPerson(&abs);//���õ�ַ���ݿ�������ʵ��
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3: {        //�ô����Ž�������������
			//std::cout << "������Ҫɾ������ϵ��������";
			//std::string name;
			//std::cin >> name;
			//if (isExist(&abs, name) == -1) {
			//	std::cout << "���޴��ˣ�" << std::endl;	
			//}
			//else {
			//	std::cout << "�ҵ����ˡ�" << std::endl;
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
			std::cout << "��ӭ�´�ʹ�ã�" << std::endl;
			system("pause");
			return 0;
			break;
		default:
			system("cls");
			std::cout << "�������룡����������" << std::endl;
			break;
		}
	}
	system("pause");
	return 0;

}
