#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <shlwapi.h>
class Fileutil {
public:
	Fileutil();
	~Fileutil();
	//�ַ�����ת�ַ���
	std::string charToStr(char* contentChar);
	//�ַ����ָ��
	std::vector<std::string> split(std::string str, const std::string& delim);

	//�޸��ļ�ĳһ�е�����,ע���˴�����������1��ʼ
	void modifyContentInFile(std::string fileName, int lineNum, std::string content);
	//���ļ�ĩβд
	bool writeContent(std::string fileName, std::string content);
	//ɾ��ĳһ�е�����
	void deleteContent(std::string fileName, int lineNum);
	//��ȡĳһ��
	std::string readContentline(std::string fileName, int lineNum);
	// ��ȡ�����ļ�
	std::string readContent(std::string fileName);

	bool creatFolder(std::string filepath);
	bool creatFile(std::string filepath);

};