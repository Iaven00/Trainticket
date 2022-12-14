#pragma once

#include "fileutil.h"


class Userdao :public Fileutil{
public:
	
	Userdao();
	~Userdao();

	//根据用户id读取某一行
	std::string readContentByUserid(std::string fileName, int id);
	//根据用户id修改某一行
	void modifyContentByUserid(std::string fileName, int id, std::string content);
	// 在用户表中增加数据,content为用户名+#+密码（不含id）
	int addUser(std::string fileName, std::string content);

};