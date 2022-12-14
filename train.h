#pragma once
#include "seat.h"
using namespace std;
class Train {
    //高铁名，高铁号
    string number, name;
    //车厢数
    int carriagenum;

    vector<string> vsite;    //每一站的站点信息(即站点名)
    vector<float> distance;  //此站到下一站的距离,最后一站为0
    vector<int> cost;  //此站到下一站的费用，最后一站为0

    //vector<Seat> seat; // 每个座位的信息
    /*
    * 思路1：
    * 定义一个二维数组int seat[i][j],i代表座位，j代表j到j+1站，(seat[i][0]代表第i个座位的第一个空的站点)
    * 和int数组 tickets[k],k代表k到k+1站的余票
    * 和int currentseat,代表当前没有被全部占的座位号（座位全部被占代表座位的所有站点都被占），且从0开始递增
    * seat[i][j] == 1 代表 第i座位从j到j+1站被占，同理0代表座位可占
    * 抢座时永远从没有被全部占的座位开始查找，即currentseat
    * 同时抢座成功时更新tickets，seat,currentseat
    * 
    */
    vector<Seat> seat;
    short currentstart;
    short currentend;
    vector<short> restTickets;

public:
    Train(int carnum,string number,string name);
    ~Train();
    void siteInit(int e); //初始化站点信息包括三种向量,以高铁号为区分
    int getCarrnum();
    std::string getName() { return this->name; }
    std::string getNumber() { return this->number; }
    int getsitesnum() { return vsite.size(); }
    int getcurrentstart() { return this->currentstart; }
    int getcurrentend() { return this->currentend; }
    string getsitename(int i) { return vsite.at(i); }
    void showSeatinfo(int i) { seat[i].print(); }
    int getSitenum(string t);

    int getTicket(int startsite, int endsite); //抢票算法,站点统一从0开始
    int getCost(int startsite, int endsite);  //获取两站间价格
    float getDis(int startsite, int endsite); //获取两站间距离

    bool getSeat(int seatNum,int startsite,int endsite);
    bool freeSeat(int seatNum, int startsite, int endsite);

    int getLeastTick(int startsite, int endsite);
    bool tOf(int tic,int site);
    void show(int start,int end);
    void showSite();
};