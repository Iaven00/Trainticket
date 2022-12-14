#pragma once
#include "train.h"
#include "fileutil.h"



Train::Train(int carnum, string number, string name) {
	this->number = number;
	this->name = name;
	this->carriagenum = carnum;
}
Train::~Train() {

}
void Train::siteInit(int e) {
	if (e > 0) {
		vsite = { "BJ","BD","SJZ","XT" ,"HD","AY" ,"XX" ,"ZZ" ,"LYLM" ,"SMX" ,"XA" };
		distance = { 19.1,28.0,18.9,25.7,23.4,19.7,14.8,37.7,24.0,39.0 };
		cost = { 35,49,37,46,40,35,30,70,46,75 };
	}
	else {
		vsite = { "SH","JS","JX","HZ" ,"ZJ","YW" ,"JH" ,"SR" ,"WY" ,"SM" ,"YA" ,"ZP","LY"};
		distance = { 23.1,34.0,45.4,35.7,23.4,21.7,31.1,41.7,42.0,39.0,43.5,37.6 };
		cost = { 45,59,57,46,30,35,45,70,76,75,78,75 };
	}
	this->seat.resize(this->carriagenum * 50,Seat(vsite.size()));
	this->currentstart = 0; //第一个座位
	this->currentend = this->carriagenum * 50 - 1; // 最后一个座位
	this->restTickets.resize(vsite.size()-1, this->carriagenum * 50); //每个区间的余票
}

int Train::getCost(int startsite, int endsite) {
	int res = 0;
	if (startsite >= 0 && endsite > startsite && endsite <= distance.size()) {
		for (int i = startsite; i < endsite; i++) {
			res += cost.at(i);
		}
	}
	return res;
}
float Train::getDis(int startsite, int endsite) {
	float res = 0;
	if (startsite >= 0 && endsite > startsite && endsite <= distance.size()) {
		for (int i = startsite; i < endsite; i++) {
			res += distance.at(i);
		}
	}
	
	return res;
}

bool Train::getSeat(int seatNum, int startsite, int endsite) {
	if (seat[seatNum].grabSeat(startsite, endsite)) {//第i个座位抢到了票
		//更新current
		//cout << "seat:" << seatNum << "  startsite:" << vsite[startsite] << "  endsite:" << vsite[endsite] << endl;
		for (int e = currentend; e >= currentstart && seat[e].getrestsite() == 0; e--) this->currentend--;
		for (int e = currentstart; e <= currentend && seat[e].getrestsite() == 0; e++) this->currentstart++;
		//更新余票数组
		for (int j = startsite; j < endsite; j++) restTickets[j]--;
		return true;
	}
	return false;
}
bool Train::freeSeat(int seatNum, int startsite, int endsite) {
	if (seat[seatNum].freeSeat(startsite, endsite)) {
		if (seatNum >= currentend) this->currentend = seatNum;
		if (seatNum <= currentstart) this->currentstart = seatNum;
		for (int j = startsite; j < endsite; j++) restTickets[j]--;
		return true;
	}
	return false;
}







/**/
int Train::getTicket(int startsite, int endsite) {
	if (startsite < 0 || endsite <= startsite || endsite > distance.size()) {
		return -1;
	}
	/**/
	int leasttick = getLeastTick(startsite, endsite);
	if (endsite - startsite == distance.size()) { //全程票,从currentend往前找
		for (int i = currentend; i >= currentstart; i--) {
			if (seat[i].grabSeat(startsite, endsite)) { //找到的票为第i个座位
				for (int e = currentend; e >= currentstart && seat[e].getrestsite() == 0; e--) this->currentend--;	
				for (int j = 0; j < restTickets.size(); j++) restTickets[j]--;
				return i;
			}
		}
		
	}
	else if(leasttick !=0){ // 非全程票，从currentstart往后找
		if (leasttick > this->carriagenum * 20) { //不用限制放票
			for (int i = currentstart; i <= currentend; i++) {
				if (seat[i].grabSeat(startsite, endsite)) {//第i个座位抢到了票
					//更新currentstart
					for (int e = currentstart; e <= currentend && seat[e].getrestsite() == 0; e++) this->currentstart++;
					//更新余票数组
					for (int j = startsite; j < endsite; j++) restTickets[j]--;
					return i;
				}
			}
		}
		else { // 开始控制放票
			if (tOf(leasttick, endsite - startsite)) {
				for (int i = currentstart; i <= currentend; i++) {
					if (seat[i].grabSeat(startsite, endsite)) {//第i个座位抢到了票
						//更新currentstart
						for (int e = currentstart; e <= currentend && seat[e].getrestsite() == 0; e++) this->currentstart++;
						//更新余票数组
						for (int j = startsite; j < endsite; j++) restTickets[j]--;
						return i;
					}
				}
			}
		}
	}
	return -1;
}

int Train::getLeastTick(int startsite, int endsite) {
	int min = restTickets.at(startsite);
	for (int i = startsite; i < endsite; i++) {
		if (restTickets.at(i) < min) min = restTickets.at(i);
	}
	return min;
}

bool Train::tOf(int tic, int site) {
	if (tic == 0) return false;
	int p1 = rand() % 10;
	int p2 = rand() % 10;
	if (tic < this->carriagenum * 10) {
		if (p1 < 3 && p2 < site) return true;
	}
	if (p1 < 5 && p2 <= site) return true;
	return false;
}
void Train::show(int start, int end) {
	std::cout <<vsite[start] <<"站--"<<vsite[end]<<"站 每站余票： ";
	for (int i = start; i < end; i++) {
		std::cout << restTickets.at(i) << "   ";
	}
	std::cout << std::endl;
}

int Train::getSitenum(string t) {
	vector<string>::iterator iter = find(vsite.begin(), vsite.end(), t);
	return iter - vsite.begin();
}

void Train::showSite() {
	std::cout << "车次" << this->number << "   车厢: 0-" << this->carriagenum << "   站点信息：";
	for (int i = 0; i < vsite.size(); i++) {
		std::cout << vsite.at(i) << "   ";
	}
	std::cout << std::endl;
}