#include "user.h"
#include "userdao.h"


Userdao f;

User::User() {
	this->id = 0;
	this->passWord = "null";
	this->userName = "null";
}
User::~User() {

}
std::string  User::getUserName() {
	return this->userName;
}
int  User::getUserId() {
	return this->id;
}
std::string  User::getPassword() {
	return this->passWord;
}

bool User::login(std::string fileName,std::string uName, std::string pass) {
	std::cout << "Signing in, please wait...\n" ;
	bool res = false;
	std::ifstream in;
	char line[1024] = { '\0' };
	in.open(fileName);
	int i = 0;
	std::string result;
	while (in.getline(line, sizeof(line)))
	{
		if (i++ == 0) continue; //跳过计数器
		result = f.charToStr(line);
		std::vector<std::string> temp = f.split(result, "#");
		//std::cout << temp.at(1) << std::endl;
		if (temp.at(1).compare(uName) == 0 && temp.at(2).compare(pass) == 0) {
			std::cout << "Welcome , " <<uName<< std::endl;
			this->id = atoi(temp.at(0).c_str());
			this->passWord = pass;
			this->userName = uName;
			res = true;
			break;
		}
	}
	in.close();
	return res;
}

int User::rigister(std::string fileName) {
	
	std::string username;
	std::string password;
	std::string re_password;
	std::cout << "Input Your Username:\n" ;
	std::cin >> username;
	std::cout << "Input Your Password:\n";
	std::cin >> password;
	std::cout << "Repeat Your Password:\n";
	std::cin >> re_password;
	if (password.compare(re_password) == 0) {
		std::cout << "Rigister Success!\n";
		int newid = f.addUser(fileName, username + "#" + password);
		this->id = newid;
		this->passWord = password;
		this->userName = username;
		return newid;
	}
	return 0;
}
void User::modifyInfo(std::string fileName) {
	if (this->id == 0) {
		std::cout << "用户未登录!\n";
	}
	else {
		std::string username;
		std::string password;
		std::string re_password;
		std::string in;
		std::cout << "要修改用户名吗[y/n]\n";
		std::cin >> in;
		if (in.compare("y") == 0 || in.compare("Y") == 0) {
			std::cout << "输入新用户名：";
			std::cin >> username;
		}
		else if (in.compare("n") == 0 || in.compare("N") == 0) {
			username = this->userName;
		}
		else {
			std::cout << "输入违规，退出！" << std::endl; 
			return;
		}
		std::cout << "要修改密码吗[y/n]\n";
		std::cin >> in;
		if (in.compare("y") == 0 || in.compare("Y") == 0) {
			std::cout << "输入新密码：";
			std::cin >> password;
		}
		else if (in.compare("n") == 0 || in.compare("N") == 0) {
			password = this->passWord;
		}
		else {
			std::cout << "输入违规，退出！" << std::endl;
			return;
		}
		std::cout << "确认输入密码";
		std::cin >> re_password;
		if (password.compare(re_password) == 0) {
			f.modifyContentByUserid(fileName, this->id, username + "#" + password);
			this->passWord = password;
			this->userName = username;
			std::cout << "修改成功!\n";
		}
	}
}