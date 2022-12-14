#pragma once
#include <iostream>
#include <string>
#include <vector>

// ÿ����λ����Ϣ
class Seat {
private:
	std::vector<bool> site; //����������i��Ԫ�ض�Ӧi��i+1վ��ռ��1��������ռ��0��
	uint8_t sitenum; //��һ���յ����䣬��0��ʼ
	uint8_t restsite; //ʣ���������
public:
	bool grabSeat(int startsite, int endsite); // ����
	bool freeSeat(int startsite, int endsite); // ����������Ʊ���ǩʱ�Ĳ���
	bool judgeSites(int startsite, int endsite);//�жϴ������Ƿ�����ռ
	Seat(int sitenum); //վ����
	~Seat();
	void print();
	int getsitenum() { return this->sitenum; }
	int getrestsite() { return this->restsite; }
};