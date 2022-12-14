// Trainticket.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <time.h>
#include "trainBookingSystem.h"
#include "userdao.h"
using namespace std;
int main()
{
    TrainBookingSystem tbs;
    tbs.systemStart();
    //vector<int> res = tbs.findSite("sf", "fw");
    /*Train train(8, "G655", "peace");
    train.siteInit(0);
    for (int i = 0; i < 240; i++) {
        train.getTicket(1, 9);
    }
    cout << train.getcurrentstart() << "-" << train.getcurrentend() << endl;

    for (int i = 0; i < 15; i++) {
        cout << train.getTicket(2, 10) << "   ";
    }
    for (int i = 0; i < 2000; i++) {
        train.getTicket(rand()%11, rand() % 11);
    }
    train.show();
    cout << train.getcurrentstart() << "-" << train.getcurrentend() << endl;*/
    /**/
    /*TrainBookingSystem train;
    train.Show2();
    train.login();
    train.showTrains();
    train.buyTicket();
    train.showRecord();
    train.refundTicket();
    train.showRecord();
    train.buyTicket();
    train.findSiteSer();*/
    //train.refundTicket();
    //train.showRecord();
    //f.writeContent("user.txt", "werwrw");
}

