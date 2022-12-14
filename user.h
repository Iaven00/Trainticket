#pragma once
#include <iostream>
#include <vector>
class User{
private:
	std::string userName;
	std::string passWord;
	int id;
public:
	std::string getUserName();
	int getUserId();
	std::string getPassword();
	User();
	~User();

	bool login(std::string fileName, std::string uName, std::string pass);  // ��¼�ɹ�����id
	int rigister(std::string fileName); //ע��ɹ�����id
	bool logup(); // �ǳ�
	void showInfo(); //��ʾ�û���Ϣ
	void modifyInfo(std::string fileName); //�޸��û���Ϣ

};