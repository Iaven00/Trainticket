#pragma once

#include <iostream>
#include <string>
#include <time.h>
#include "fileutil.h"

class RecordService :public Fileutil{

public:
	RecordService();
	~RecordService();
	/*
	* 根据用户id增加记录
	* 根据用户id删除记录
	* 根据用户id读取某一行
	* 修改某一行
	*/
	//新增加一个用户记录集合id
	bool addNewid(std::string filename,int id);
	//根据id在某一行追加
	bool addContentByid(std::string filename,int id, std::string content);
	//根据id读取一行用户记录
	std::string readContentByid(std::string filename, int id);
	//根据id删除某条记录
	bool deleteContentByid(std::string filename, int id, std::string content);
	//
	bool deleteContentByid(std::string filename, int id, int contentid);
	//所有的车站信息
	std::vector<std::string> getSite(std::string filename);
};