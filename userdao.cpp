#define _CRT_SECURE_NO_WARNINGS
#include "userdao.h"

Userdao::Userdao() {

}
Userdao::~Userdao() {

}


std::string Userdao::readContentByUserid(std::string fileName, int id) {

	std::ifstream in;
	char line[1024] = { '\0' };
	in.open(fileName);
	int i = 0;
	std::string result;
	while (in.getline(line, sizeof(line)))
	{
		if (i++ != id) {
			continue;
		}
		result = charToStr(line);
		return result;
	}
	in.close();
	return "user not exist!";
}

void Userdao::modifyContentByUserid(std::string fileName, int id, std::string content) {
	std::ifstream in;
	char line[1024] = { '\0' };
	in.open(fileName);
	int i = 0;
	std::string tempStr;
	while (in.getline(line, sizeof(line)))
	{

		if (i == id)
		{
			tempStr += std::to_string(id) + content;
		}
		else
		{
			tempStr += charToStr(line);
		}
		tempStr += '\n';
		i++;
	}
	in.close();
	std::ofstream out;
	out.open(fileName);
	out.flush();
	out << tempStr;
	out.close();
}
int Userdao::addUser(std::string fileName, std::string content) {
	std::fstream file;
	int ch;
	file.open(fileName, std::ios::in);
	ch = file.get(); //试图去读一个字符
	if (file.eof()) //或 if ( ch==EOF )  //一个字符都未读到，表示文件为空
	{
		writeContent(fileName, "0");
	}
	file.close();
	
	
	
	std::ifstream in;
	char line[1024] = { '\0' };
	int i = 0, newid = 0;
	in.open(fileName);
	std::string tempStr = "";

	while (in.getline(line, sizeof(line)))
	{

		// 更新计数器
		if (i == 0) {
			newid = atoi(charToStr(line).c_str());
			newid++;
			tempStr += std::to_string(newid);
		}
		else
		{
			tempStr += charToStr(line);
		}
		tempStr += '\n';
		i++;
	}

	tempStr += std::to_string(newid);
	tempStr += "#";
	tempStr += content;
	tempStr += "\n";
	in.close();
	std::ofstream out;
	out.open(fileName);
	out.flush();
	out << tempStr;
	out.close();
	return newid;
}