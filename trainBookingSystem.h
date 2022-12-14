#pragma once
#include "record.h"
#include"recordService.h"
#include"train.h"
#include"user.h"
class TrainBookingSystem {
private:
	User user;
	std::vector<Train> trains;
	RecordService recordservice;
	string systempath;
	vector<string> tmp;
public:
	TrainBookingSystem();
	~TrainBookingSystem();
	void trainSeatInit();
	bool siteInit();
	void Show1();
	void Show2();
	//按站点查询票
	vector<int> findSite(string startsite, string endsite);
	//登录
	bool login();
	void rigister();
	void findSiteSer();
	//浏览全部车次信息
	void showTrains();
	//查看订单
	void showRecord();
	//退票
	void refundTicket();
	//购票
	void buyTicket();
	//
	void systemStart();
};