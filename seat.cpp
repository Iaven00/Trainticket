#include "seat.h"

Seat::Seat(int sitenum) {
	this->site.resize(sitenum - 1, 0); //sitenum��վ���Ӧsitenum-1�����䣬0������������
	this->sitenum = 0; //��ʼʱ��0������Ϊ��
	this->restsite = sitenum - 1;
}

Seat::~Seat() {

}

bool Seat::freeSeat(int startsite, int endsite) {
	if (startsite < 0 || endsite > site.size() || endsite <= startsite)
		return false;

	for (int i = startsite; i < endsite; i++) {
		if (site[i] == 1) {
			site[i] = 0;
			this->restsite++;
		}
	}
	if (endsite <= this->sitenum) {
		this->sitenum = startsite;
	}

	return true;
}


//
bool Seat::grabSeat( int startsite, int endsite) {
	if (!judgeSites(startsite, endsite)) return false;
	for (int i = startsite; i < endsite; i++) {
		site[i] = 1;
	}
	this->restsite -= endsite - startsite;
	if (startsite == this->sitenum) {
		for (int i = 0; i < site.size() - endsite; i++) {
			if (site.at(endsite + i) == 0) {
				this->sitenum = endsite + i;
				break;
			}
		}
	}
	return true;
}
void Seat::print() {
	std::cout << "sitenum: " <<(int)this->sitenum<<"   restsites: "<< (int)this->restsite<<std::endl;
	for (int i = 0; i < site.size(); i++)
		std::cout << site[i] << "  ";
	std::cout << std::endl;
}
bool Seat::judgeSites(int startsite, int endsite) {
	if (endsite - startsite > this->restsite || this->sitenum > startsite || startsite < 0 || startsite >= endsite || endsite>site.size()) { //����ʣ�������
		return false;
	}
	for (int i = startsite; i < endsite; i++) {
		if (site.at(i) != 0) {
			return false;
		}
	}
	return true;
}