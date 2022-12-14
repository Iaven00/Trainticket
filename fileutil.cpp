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
/* char*tostr  �ַ���ת��str����
���룺char * �ַ�����ַ
�����
����ֵ�� str���͵��ַ���
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
	//�Ƚ�Ҫ�и���ַ�����string����ת��Ϊchar*����  
	char* strs = new char[str.length() + 1]; //��Ҫ����  
	strcpy(strs, str.c_str());

	char* d = new char[delim.length() + 1];
	strcpy(d, delim.c_str());

	char* p = strtok(strs, d);
	while (p) {
		std::string s = p; //�ָ�õ����ַ���ת��Ϊstring����  
		res.push_back(s); //����������  
		p = strtok(NULL, d);
	}

	return res;
}


/************************************************************************/
/* �޸��ļ�ĳ������
 ���룺�ļ��� fileName   �к�   lineNum ,�޸ĵ����� content
 ������ļ��� fileName
 �޷���ֵ
 tip��1,lineNum�ӵ�һ�п�ʼ 2.content��Ҫ���ϻ��з�
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


