#pragma once
#include <iostream>
#include <string>
#include <vector>

// 每个座位的信息
class Seat {
private:
	std::vector<bool> site; //区间数，第i个元素对应i到i+1站被占（1）或无人占（0）
	uint8_t sitenum; //第一个空的区间，从0开始
	uint8_t restsite; //剩余空区间数
public:
	bool grabSeat(int startsite, int endsite); // 抢座
	bool freeSeat(int startsite, int endsite); // 退座，即退票或改签时的操作
	bool judgeSites(int startsite, int endsite);//判断此区间是否有人占
	Seat(int sitenum); //站点数
	~Seat();
	void print();
	int getsitenum() { return this->sitenum; }
	int getrestsite() { return this->restsite; }
};