#pragma once

#include "fileutil.h"


class Userdao :public Fileutil{
public:
	
	Userdao();
	~Userdao();

	//�����û�id��ȡĳһ��
	std::string readContentByUserid(std::string fileName, int id);
	//�����û�id�޸�ĳһ��
	void modifyContentByUserid(std::string fileName, int id, std::string content);
	// ���û�������������,contentΪ�û���+#+���루����id��
	int addUser(std::string fileName, std::string content);

};