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
	* �����û�id���Ӽ�¼
	* �����û�idɾ����¼
	* �����û�id��ȡĳһ��
	* �޸�ĳһ��
	*/
	//������һ���û���¼����id
	bool addNewid(std::string filename,int id);
	//����id��ĳһ��׷��
	bool addContentByid(std::string filename,int id, std::string content);
	//����id��ȡһ���û���¼
	std::string readContentByid(std::string filename, int id);
	//����idɾ��ĳ����¼
	bool deleteContentByid(std::string filename, int id, std::string content);
	//
	bool deleteContentByid(std::string filename, int id, int contentid);
	//���еĳ�վ��Ϣ
	std::vector<std::string> getSite(std::string filename);
};