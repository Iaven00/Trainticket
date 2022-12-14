#pragma once
#include "seat.h"
using namespace std;
class Train {
    //��������������
    string number, name;
    //������
    int carriagenum;

    vector<string> vsite;    //ÿһվ��վ����Ϣ(��վ����)
    vector<float> distance;  //��վ����һվ�ľ���,���һվΪ0
    vector<int> cost;  //��վ����һվ�ķ��ã����һվΪ0

    //vector<Seat> seat; // ÿ����λ����Ϣ
    /*
    * ˼·1��
    * ����һ����ά����int seat[i][j],i������λ��j����j��j+1վ��(seat[i][0]�����i����λ�ĵ�һ���յ�վ��)
    * ��int���� tickets[k],k����k��k+1վ����Ʊ
    * ��int currentseat,����ǰû�б�ȫ��ռ����λ�ţ���λȫ����ռ������λ������վ�㶼��ռ�����Ҵ�0��ʼ����
    * seat[i][j] == 1 ���� ��i��λ��j��j+1վ��ռ��ͬ��0������λ��ռ
    * ����ʱ��Զ��û�б�ȫ��ռ����λ��ʼ���ң���currentseat
    * ͬʱ�����ɹ�ʱ����tickets��seat,currentseat
    * 
    */
    vector<Seat> seat;
    short currentstart;
    short currentend;
    vector<short> restTickets;

public:
    Train(int carnum,string number,string name);
    ~Train();
    void siteInit(int e); //��ʼ��վ����Ϣ������������,�Ը�����Ϊ����
    int getCarrnum();
    std::string getName() { return this->name; }
    std::string getNumber() { return this->number; }
    int getsitesnum() { return vsite.size(); }
    int getcurrentstart() { return this->currentstart; }
    int getcurrentend() { return this->currentend; }
    string getsitename(int i) { return vsite.at(i); }
    void showSeatinfo(int i) { seat[i].print(); }
    int getSitenum(string t);

    int getTicket(int startsite, int endsite); //��Ʊ�㷨,վ��ͳһ��0��ʼ
    int getCost(int startsite, int endsite);  //��ȡ��վ��۸�
    float getDis(int startsite, int endsite); //��ȡ��վ�����

    bool getSeat(int seatNum,int startsite,int endsite);
    bool freeSeat(int seatNum, int startsite, int endsite);

    int getLeastTick(int startsite, int endsite);
    bool tOf(int tic,int site);
    void show(int start,int end);
    void showSite();
};