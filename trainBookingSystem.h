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
	//��վ���ѯƱ
	vector<int> findSite(string startsite, string endsite);
	//��¼
	bool login();
	void rigister();
	void findSiteSer();
	//���ȫ��������Ϣ
	void showTrains();
	//�鿴����
	void showRecord();
	//��Ʊ
	void refundTicket();
	//��Ʊ
	void buyTicket();
	//
	void systemStart();
};