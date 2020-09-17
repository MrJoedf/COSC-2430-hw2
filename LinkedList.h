#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <string>
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
   }
  
    problem(int id, string name, string difficulty){
      this->id=id;
      this->name = name;
      this->difficulty = difficulty;
      }
};
class linkedList{
  public:
    problem* head=nullptr;
    int size = 0;
    void addPos(int pos,int id, string name, string difficult);
    void add(int id, string name, string difficulty);
    void sort(int choice, int direction);
    void remove(int choice, string data, int pos);
};

#endif
