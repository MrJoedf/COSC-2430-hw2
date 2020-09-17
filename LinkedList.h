#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<stdio.h> 
#include <string.h>
#include <sstream>

using namespace std;

class problem{
  public:

    int id, difficultyRank;
    string name;
    string difficulty;
    problem* next=nullptr;
    

    //FUNCTIONS
   problem(){
     this->id=0;
    this->name = "";
    this->difficulty="";
    //problem* next=nullptr;

   }
    problem(int id, string name, string difficulty){
      this->id=id;
      this->name = name;
      //stringstream thatName(name);


      //cout<<"TESTING THIS: "<<test<<endl;
      cout<<"problem_name: "<<this->name<<endl;
      //cout<<"NAME: "<<this->name<<endl;
      this->difficulty = difficulty;
      }
    
   
    

  
};
class linkedList{
  public:
    problem* head=nullptr;

    int size = 0;
    
    vector<int> ids;

    void addPos(int pos,int id, string name, string difficult);

    void add(int id, string name, string difficulty);

    void sort(int choice, int direction);

    void remove(int choice, string data, int pos);

    string print();

};

#endif