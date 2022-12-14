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

	bool login(std::string fileName, std::string uName, std::string pass);  // 登录成功返回id
	int rigister(std::string fileName); //注册成功返回id
	bool logup(); // 登出
	void showInfo(); //显示用户信息
	void modifyInfo(std::string fileName); //修改用户信息

};