#define _CRT_SECURE_NO_WARNINGS
#include "trainBookingSystem.h"


TrainBookingSystem::TrainBookingSystem() {
	Train t1(8, "G655", "��г��");
	t1.siteInit(1);
	Train t2(10, "D1623", "��г��");
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
	cout << "*�𡪡�����������������������������������������*" << endl;
	cout << "*|    ��ӭʹ�ó�Ʊ����ϵͳ~ ����Ҫ:           |*" << endl;
	cout << "*|                                            |*" << endl;
	cout << "*|    �ٵ�¼                                  |*" << endl;
	cout << "*|                                            |*" << endl;
	cout << "*|    ��ע��                                  |*" << endl;
	cout << "*|                                            |*" << endl;
	cout << "*|    �������������˳�                      |*" << endl;
	cout << "*|                                            |*" << endl;
	cout << "************************************************" << endl;
}

void TrainBookingSystem::Show2() {
	cout << "************************************************" << endl;
	cout << "*�𡪡�����������������������������������������*" << endl;
	cout << "*|    ��ӭʹ�ó�Ʊ����ϵͳ~                   |*" << endl;
	cout << "*|                                            |*" << endl;
	cout << "*|    ��������Ҫ�����Ӧ����ţ�              |*" << endl;
	cout << "*|                                            |*" << endl;
	cout << "*|    �١����ȫ�������Ϣ��                  |*" << endl;
	cout << "*|                                            |*" << endl;
	cout << "*|    �ڡ�����Ρ��յ�վ��ѯ�����Ϣ��        |*" << endl;
	cout << "*|                                            |*" << endl;
	cout << "*|    �ۡ��鿴������                          |*" << endl;
	cout << "*|                                            |*" << endl;
	cout << "*|    �ܡ���Ʊ��                              |*" << endl;
	cout << "*|                                            |*" << endl;
	cout << "*|    �ݡ���Ʊ��                              |*" << endl;
	cout << "*|                                            |*" << endl;
	cout << "*|    �ޡ��˻���                              |*" << endl;
	cout << "*|                                            |*" << endl;
	cout << "*|    �ߡ��˳���                              |*" << endl;
	cout << "*|                                            |*" << endl;
	cout << "*�𡪡�����������������������������������������*" << endl;
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

	cout << "�����û���:" << endl;
	cin >> username;
	cout << "��������:" << endl;
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
	cout << "������ʼվ:" << endl;
	cin >> start;
	cout << "�����յ�վ:" << endl;
	cin >> end;
	vector<int> res = findSite(start, end);
	if (res.size() == 3) {
		cout << "��Ϊ���ҵ�" << trains.at(res[0]).getNumber() << "���ε�����" << trains.at(res[0]).getsitename(res[1]) << "---" << trains.at(res[0]).getsitename(res[2]) << endl;
		trains.at(res[0]).show(res[1], res[2]);
	}
	else {
		cout << "δ�ҵ������䣡" << endl;
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
	cout << "ȫ��������" << endl;
	if (tmp.size() > 1) {
		tmp = recordservice.split(tmp[1], ",");
		for (int j = 0; j < tmp.size(); j++) {
			vector<string> tmps = recordservice.split(tmp[j], "#");
			int seat = atoi(tmps[3].c_str());
			int row = seat % 50;
			time_t time = atoll(tmps[6].c_str());
			struct tm* ptminfo = localtime(&time);
			cout <<"id:"<< j+1 << "  ���Σ�" << tmps[0] << "  ��㣺" << tmps[1] << "  �յ㣺" << tmps[2];
			cout << "   ��λ�ţ�" << seat/50 +1 << "����" << row/5 +1 << "��0" << row%5 +1;
			cout << "   �۸�" << tmps[4];
			cout << "   ���룺" << tmps[5];
			printf("    ����: %02d-%02d-%02d %02d:%02d\n",
			ptminfo->tm_year + 1900, ptminfo->tm_mon + 1, ptminfo->tm_mday,
			ptminfo->tm_hour, ptminfo->tm_min);
		}
	}
}
void TrainBookingSystem::refundTicket() {
	string num;
	cout << "���붩��id��ɾ����";
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
		cout << "����id�����ڣ�"<<endl;
	}
}

void TrainBookingSystem::buyTicket() {
	string start, end;
	cout << "����˳�վ:" << endl;
	cin >> start;
	cout << "�����³�վ:" << endl;
	cin >> end;
	vector<int> res = findSite(start, end);
	int trainid = res[0];
	int seat = trains[trainid].getTicket(res[1], res[2]);
	if (seat >= 0) { //˵����Ʊ�ɹ�
		int row = seat % 50;
		cout << "��Ʊ�ɹ���   ���Σ�" << trains[trainid].getNumber()<<"   ��λ�ţ�"<< seat / 50 + 1 << "����" << row / 5 + 1 << "��0" << row % 5 + 1 << endl;
		Record re(trains[trainid].getNumber(), start, end, seat, trains[trainid].getCost(res[1], res[2]), trains[trainid].getDis(res[1], res[2]), time(0));
		recordservice.addContentByid(this->systempath + "record.txt",user.getUserId(),re.getRecordStr());
	}
}



void TrainBookingSystem::systemStart() {
	string choice;
	Show1();
	while (user.getUserId() == 0) {  //�ǵ�¼״̬
		cout << "��������ѡ�";
		cin >> choice;
		if (choice.compare("1") == 0) this->login();
		else if (choice.compare("2") == 0) this->rigister();
		else return;
	}
	Show2();
	while (user.getUserId() != 0) {
		cout << "��������ѡ�";
		cin >> choice;
		switch (atoi(choice.c_str()))
		{
		case 1:this->showTrains(); break;
		case 2:this->findSiteSer(); break;
		case 3:this->showRecord(); break;
		case 4:this->buyTicket(); break;
		case 5:this->refundTicket(); break;
		case 6:cout<<"�û�id:"<<user.getUserId()<<"  �û���:"<<user.getUserName()<<"   ����:"<<user.getPassword()<<endl; break;
		case 7:return;
		default:
			break;
		}
	}
}