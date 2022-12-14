#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "fileutil.h"

Fileutil::Fileutil() {

}
Fileutil::~Fileutil() {

}
bool Fileutil::creatFolder(std::string filepath) {


	std::string command;
	command = "mkdir " + filepath;
	system(command.c_str());
	return true;
}
bool Fileutil::creatFile(std::string fileName) {
	std::ofstream out(fileName, std::ios::app);
	if (out.is_open())
	{
		out.close();
		return true;
	}
	return false;
}
/************************************************************************/
/* char*tostr  字符串转化str类型
输入：char * 字符串地址
无输出
返回值： str类型的字符串
*/
/************************************************************************/
std::string Fileutil::charToStr(char* contentChar)
{
	std::string tempStr;
	for (int i = 0; contentChar[i] != '\0'; i++)
	{
		tempStr += contentChar[i];
	}
	return tempStr;
}

std::vector<std::string> Fileutil::split(std::string str, const std::string& delim) {
	std::vector<std::string> res;
	if ("" == str) return res;
	//先将要切割的字符串从string类型转换为char*类型  
	char* strs = new char[str.length() + 1]; //不要忘了  
	strcpy(strs, str.c_str());

	char* d = new char[delim.length() + 1];
	strcpy(d, delim.c_str());

	char* p = strtok(strs, d);
	while (p) {
		std::string s = p; //分割得到的字符串转换为string类型  
		res.push_back(s); //存入结果数组  
		p = strtok(NULL, d);
	}

	return res;
}


/************************************************************************/
/* 修改文件某行内容
 输入：文件名 fileName   行号   lineNum ,修改的内容 content
 输出：文件名 fileName
 无返回值
 tip：1,lineNum从第一行开始 2.content需要加上换行符
*/
/************************************************************************/
void Fileutil::modifyContentInFile(std::string fileName, int lineNum, std::string content)
{
	std::ifstream in;
	char line[1024] = { '\0' };
	in.open(fileName);
	int i = 0;
	std::string tempStr;
	while (in.getline(line, sizeof(line)))
	{
		i++;
		if (lineNum != i)
		{
			tempStr += charToStr(line);
		}
		else
		{
			tempStr += content;
		}
		tempStr += '\n';
	}
	in.close();
	std::ofstream out;
	out.open(fileName);
	out.flush();
	out << tempStr;
	out.close();


}

bool Fileutil::writeContent(std::string fileName, std::string content) {
	std::ofstream out(fileName, std::ios::app);
	if (out.is_open())
	{
		out << content << std::endl;
		out.close();
		return true;
	}
	return false;
}


std::string Fileutil::readContent(std::string fileName) {
	std::ifstream in;
	char line[1024] = { '\0' };
	in.open(fileName);
	std::string tempStr;
	while (in.getline(line, sizeof(line)))
	{
		tempStr+= charToStr(line);
		tempStr += "\n";
	}
	
	in.close();
	return tempStr;
}

std::string Fileutil::readContentline(std::string fileName, int lineNum) {
	std::ifstream in;
	char line[1024] = { '\0' };
	in.open(fileName);
	int i = 0;
	std::string tempStr;
	while (in.getline(line, sizeof(line)))
	{
		i++;
		if (lineNum == i)
		{
			return charToStr(line);
		}
	}
	return nullptr;
}

void Fileutil::deleteContent(std::string fileName, int lineNum) {
	std::ifstream in;
	char line[1024] = { '\0' };
	in.open(fileName);
	int i = 0;
	std::string tempStr;
	while (in.getline(line, sizeof(line)))
	{
		i++;
		if (lineNum != i)
		{
			tempStr += charToStr(line);
			tempStr += '\n';
		}
		
	}
	in.close();
	std::ofstream out;
	out.open(fileName);
	out.flush();
	out << tempStr;
	out.close();
}


