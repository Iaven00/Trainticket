#pragma once

#include <iostream>
#include <string>
#include <time.h>

//�û��Ĺ�Ʊ��¼
class Record {
    //����Ҫ�û���Ϣ��һ���û���Ӧһ��record�ļ����û�id�������ļ����С�
private:
    //�����ţ��˳�վ���³�վ
    std::string trainNumber, startsite, endsite;
    //��λ��,һ�г��Ṳ10�ţ�һ������(A,B,C,D,E)
    int  seatNumber;

    int price;
    float distance;
    //����ʱ��
    time_t buytime;
public:
    Record(std::string trainNumber, std::string startsite, std::string endsite,int seat,int price,float distance,time_t buytime);
    ~Record();
    std::string getRecordStr();
};