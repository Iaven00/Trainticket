

#include "record.h"

Record::Record(std::string trainNumber, std::string startsite, std::string endsite, int seat, int price,float distance, time_t buytime) {
    this->trainNumber = trainNumber;
    this->startsite = startsite;
    this->endsite = endsite;
    this->seatNumber = seat;
    this->price = price;
    this->distance = distance;
    this->buytime = buytime;
}
Record::~Record() {

}

std::string Record::getRecordStr() {
    std::string res = "";
    res += this->trainNumber;
    res += "#";
    res += this->startsite;
    res += "#";
    res += this->endsite;
    res += "#";
    res += std::to_string(this->seatNumber);
    res += "#";
    res += std::to_string(this->price);
    res += "#";
    res += std::to_string(this->distance);
    res += "#";
    res += std::to_string(this->buytime);
    return res;
}