#define _CRT_SECURE_NO_WARNINGS
#include "recordService.h"



RecordService::RecordService() {

}
RecordService::~RecordService() {

}



bool RecordService::addNewid(std::string filename, int id) {
	return this->writeContent(filename, std::to_string(id)+";");
}
//根据id在某一行追加
bool RecordService::addContentByid(std::string fileName, int id, std::string content) {
	bool res = false;
	std::ifstream in;
	char line[1024] = { '\0' };
	in.open(fileName);
	int i = 0;
	std::string tempStr;
	while (in.getline(line, sizeof(line)))
	{
		i++;
		tempStr += charToStr(line);
		if (id == i)
		{
			tempStr += content+",";
			res = true;
		}
		tempStr += '\n';
	}
	in.close();
	std::ofstream out;
	out.open(fileName);
	out.flush();
	out << tempStr;
	out.close();
	return res;
}
//根据id读取一行用户记录
std::string RecordService::readContentByid(std::string filename, int id) {
	return this->readContentline(filename,id);
}
//根据id删除某条记录
bool RecordService::deleteContentByid(std::string filename, int id, std::string content) {
	bool res = false;
	std::ifstream in;
	char line[1024] = { '\0' };
	in.open(filename);
	int i = 0;
	std::string tempStr;
	while (in.getline(line, sizeof(line)))
	{
		i++;
		if(i!=id) tempStr += charToStr(line);
		else
		{
			std::string restem = "";
			std::vector<std::string> temp = split(charToStr(line), ";");
			restem += temp[0]; restem += ";";
			std::vector<std::string> temp1 = split(temp[1], ",");
			for (int j = 0; j < temp1.size(); j++) {
				if (temp1[j].compare(content) != 0) {
					restem += temp1[j]; restem += ",";
				}
			}
			tempStr += restem;

			res = true;
		}
		tempStr += '\n';
	}
	in.close();
	std::ofstream out;
	out.open(filename);
	out.flush();
	out << tempStr;
	out.close();
	return res;
}
//所有的车站信息
std::vector<std::string> RecordService::getSite(std::string filename) {
	std::vector<std::string> res;

	std::string tempStr = readContent(filename);

	std::vector<std::string> temp = split(tempStr,"\n");
	/**/for (int i = 0; i < temp.size(); i++) {
		std::vector<std::string> tmp = split(temp[i], ";");
		if (tmp.size() > 1) {
			tmp = split(tmp[1], ",");
			for (int j = 0; j < tmp.size(); j++) {
				std::vector<std::string> tmps = split(tmp[j], "#");
				res.push_back(tmps[1]); res.push_back(tmps[2]); res.push_back(tmps[3]);
			}
		}
	}
	return res;
}
