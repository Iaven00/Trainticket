#pragma once

#include <iostream>
#include <string>
#include <time.h>

//用户的购票记录
class Record {
    //不需要用户信息，一个用户对应一个record文件，用户id储存在文件名中。
private:
    //高铁号，乘车站，下车站
    std::string trainNumber, startsite, endsite;
    //座位号,一列车厢共10排，一排五座(A,B,C,D,E)
    int  seatNumber;

    int price;
    float distance;
    //购买时间
    time_t buytime;
public:
    Record(std::string trainNumber, std::string startsite, std::string endsite,int seat,int price,float distance,time_t buytime);
    ~Record();
    std::string getRecordStr();
};