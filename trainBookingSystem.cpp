#define _CRT_SECURE_NO_WARNINGS
#include "trainBookingSystem.h"


TrainBookingSystem::TrainBookingSystem() {
	Train t1(8, "G655", "和谐号");
	t1.siteInit(1);
	Train t2(10, "D1623", "和谐号");
	t2.siteInit(-1);
	trains.push_back(t1);
	trains.push_back(t2);
	systempath = "";
	recordservice.creatFile("record.txt");
	recordservice.creatFile("user.txt");
	trainSeatInit();
}
TrainBookingSystem::~TrainBookingSystem(){}

void TrainBookingSystem::trainSeatInit() {
	vector<string> ts = recordservice.getSite(this->systempath + "record.txt");
	for (int i = 0; i < ts.size(); i += 3) {
		vector<int> res = findSite(ts[i], ts[i + 1]);
		trains[res[0]].getSeat(atoi(ts[i + 2].c_str()), res[1], res[2]);
	}

}


void TrainBookingSystem::Show1() {
	cout << "************************************************" << endl;
	cout << "*○—————————————————————○*" << endl;
	cout << "*|    欢迎使用车票管理系统~ ，您要:           |*" << endl;
	cout << "*|                                            |*" << endl;
	cout << "*|    ①登录                                  |*" << endl;
	cout << "*|                                            |*" << endl;
	cout << "*|    ②注册                                  |*" << endl;
	cout << "*|                                            |*" << endl;
	cout << "*|    或按任意其他键退出                      |*" << endl;
	cout << "*|                                            |*" << endl;
	cout << "************************************************" << endl;
}

void TrainBookingSystem::Show2() {
	cout << "************************************************" << endl;
	cout << "*○—————————————————————○*" << endl;
	cout << "*|    欢迎使用车票管理系统~                   |*" << endl;
	cout << "*|                                            |*" << endl;
	cout << "*|    请输入需要服务对应的序号：              |*" << endl;
	cout << "*|                                            |*" << endl;
	cout << "*|    ①、浏览全部班次信息。                  |*" << endl;
	cout << "*|                                            |*" << endl;
	cout << "*|    ②、按班次、终点站查询班次信息。        |*" << endl;
	cout << "*|                                            |*" << endl;
	cout << "*|    ③、查看订单。                          |*" << endl;
	cout << "*|                                            |*" << endl;
	cout << "*|    ④、购票。                              |*" << endl;
	cout << "*|                                            |*" << endl;
	cout << "*|    ⑤、退票。                              |*" << endl;
	cout << "*|                                            |*" << endl;
	cout << "*|    ⑥、账户。                              |*" << endl;
	cout << "*|                                            |*" << endl;
	cout << "*|    ⑦、退出。                              |*" << endl;
	cout << "*|                                            |*" << endl;
	cout << "*○—————————————————————○*" << endl;
	cout << "************************************************" << endl;
}


vector<int> TrainBookingSystem::findSite(string startsite, string endsite) {
	vector<int> res;
	for (int i = 0; i < trains.size(); i++) {
		int j = trains[i].getSitenum(startsite);
		int k = trains[i].getSitenum(endsite);
		if (k > j && k < trains[i].getsitesnum() && j < trains[i].getsitesnum()) {
			res.push_back(i);
			res.push_back(j);
			res.push_back(k);
			return res;
		}
	}
	return res;
}

bool TrainBookingSystem::login() {
	string username;
	string pass;

	cout << "输入用户名:" << endl;
	cin >> username;
	cout << "输入密码:" << endl;
	cin >> pass;
	return this->user.login(this->systempath + "user.txt", username, pass);
}

void TrainBookingSystem::rigister() {

	int d = user.rigister(this->systempath + "user.txt");
	if (d > 0) {
		recordservice.addNewid(this->systempath + "record.txt", user.getUserId());
	}
}

void TrainBookingSystem::findSiteSer() {
	string start, end;
	cout << "输入起始站:" << endl;
	cin >> start;
	cout << "输入终点站:" << endl;
	cin >> end;
	vector<int> res = findSite(start, end);
	if (res.size() == 3) {
		cout << "已为您找到" << trains.at(res[0]).getNumber() << "车次的区间" << trains.at(res[0]).getsitename(res[1]) << "---" << trains.at(res[0]).getsitename(res[2]) << endl;
		trains.at(res[0]).show(res[1], res[2]);
	}
	else {
		cout << "未找到改区间！" << endl;
	}
}

void TrainBookingSystem::showTrains() {
	for (int i = 0; i < trains.size(); i++) {
		trains[i].showSite();
	}
}

void TrainBookingSystem::showRecord() {
	string record = recordservice.readContentByid(this->systempath + "record.txt", user.getUserId());
	tmp.clear();
	tmp = recordservice.split(record, ";");
	cout << "全部订单：" << endl;
	if (tmp.size() > 1) {
		tmp = recordservice.split(tmp[1], ",");
		for (int j = 0; j < tmp.size(); j++) {
			vector<string> tmps = recordservice.split(tmp[j], "#");
			int seat = atoi(tmps[3].c_str());
			int row = seat % 50;
			time_t time = atoll(tmps[6].c_str());
			struct tm* ptminfo = localtime(&time);
			cout <<"id:"<< j+1 << "  车次：" << tmps[0] << "  起点：" << tmps[1] << "  终点：" << tmps[2];
			cout << "   座位号：" << seat/50 +1 << "车厢" << row/5 +1 << "排0" << row%5 +1;
			cout << "   价格：" << tmps[4];
			cout << "   距离：" << tmps[5];
			printf("    日期: %02d-%02d-%02d %02d:%02d\n",
			ptminfo->tm_year + 1900, ptminfo->tm_mon + 1, ptminfo->tm_mday,
			ptminfo->tm_hour, ptminfo->tm_min);
		}
	}
}
void TrainBookingSystem::refundTicket() {
	string num;
	cout << "输入订单id以删除：";
	cin >> num;
	int id = atoi(num.c_str());

	string record = recordservice.readContentByid(this->systempath + "record.txt", user.getUserId());
	tmp.clear();
	tmp = recordservice.split(record, ";");
	if (tmp.size() > 1) tmp = recordservice.split(tmp[1], ",");
	if (id > 0 && id<=tmp.size()) {
		vector<string> tmps = recordservice.split(tmp[id-1], "#");
		vector<int> index = findSite(tmps[1], tmps[2]);
		trains[index[0]].freeSeat(atoi(tmps[3].c_str()), index[1], index[2]);
		recordservice.deleteContentByid(this->systempath + "record.txt", user.getUserId(), tmp[id - 1]);
	}
	else {
		cout << "订单id不存在！"<<endl;
	}
}

void TrainBookingSystem::buyTicket() {
	string start, end;
	cout << "输入乘车站:" << endl;
	cin >> start;
	cout << "输入下车站:" << endl;
	cin >> end;
	vector<int> res = findSite(start, end);
	int trainid = res[0];
	int seat = trains[trainid].getTicket(res[1], res[2]);
	if (seat >= 0) { //说明抢票成功
		int row = seat % 50;
		cout << "购票成功！   车次：" << trains[trainid].getNumber()<<"   座位号："<< seat / 50 + 1 << "车厢" << row / 5 + 1 << "排0" << row % 5 + 1 << endl;
		Record re(trains[trainid].getNumber(), start, end, seat, trains[trainid].getCost(res[1], res[2]), trains[trainid].getDis(res[1], res[2]), time(0));
		recordservice.addContentByid(this->systempath + "record.txt",user.getUserId(),re.getRecordStr());
	}
}



void TrainBookingSystem::systemStart() {
	string choice;
	Show1();
	while (user.getUserId() == 0) {  //非登录状态
		cout << "输入您的选项：";
		cin >> choice;
		if (choice.compare("1") == 0) this->login();
		else if (choice.compare("2") == 0) this->rigister();
		else return;
	}
	Show2();
	while (user.getUserId() != 0) {
		cout << "输入您的选项：";
		cin >> choice;
		switch (atoi(choice.c_str()))
		{
		case 1:this->showTrains(); break;
		case 2:this->findSiteSer(); break;
		case 3:this->showRecord(); break;
		case 4:this->buyTicket(); break;
		case 5:this->refundTicket(); break;
		case 6:cout<<"用户id:"<<user.getUserId()<<"  用户名:"<<user.getUserName()<<"   密码:"<<user.getPassword()<<endl; break;
		case 7:return;
		default:
			break;
		}
	}
}