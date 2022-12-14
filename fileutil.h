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
	//字符数组转字符串
	std::string charToStr(char* contentChar);
	//字符串分割函数
	std::vector<std::string> split(std::string str, const std::string& delim);

	//修改文件某一行的内容,注：此处的行数都从1开始
	void modifyContentInFile(std::string fileName, int lineNum, std::string content);
	//向文件末尾写
	bool writeContent(std::string fileName, std::string content);
	//删除某一行的内容
	void deleteContent(std::string fileName, int lineNum);
	//读取某一行
	std::string readContentline(std::string fileName, int lineNum);
	// 读取整个文件
	std::string readContent(std::string fileName);

	bool creatFolder(std::string filepath);
	bool creatFile(std::string filepath);

};