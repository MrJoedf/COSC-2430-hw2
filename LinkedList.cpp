#include "LinkedList.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

void linkedList::addPos(int pos, int id, string name, string difficulty){  
  //condition to check if the problem's ID is already in the list
  problem *check = head;
  while(check!=nullptr){
      if(check->id==id){
        return;
      }
      check=check->next;
    }
     
  if((pos>=this->size) ){
    add(id,name,difficulty);
    return;
  }else if(pos<0){
    problem *temp = new problem;
    temp->id=id;
    temp->name=name;
    temp->difficulty=difficulty;
    if(difficulty=="Easy"){
       temp->difficultyRank=1;
     }else if(difficulty=="Medium"){
       temp->difficultyRank=2;
     }else if(difficulty=="Hard"){
       temp->difficultyRank=3;
     }

    temp->next=head;
    head=temp;
    return;
  }
  
 problem *temp = new problem;
 temp->id = id;
 temp->name=name;
 temp->difficulty=difficulty;

  int count =0;
  if(pos==0){
    temp->next=this->head;
    this->head=temp;
    this->size++;
  }else{
    if(this->head!=nullptr){
      problem *trav = head;

      for(int i=0; i<pos-1; i++){
        count++;
        trav = trav->next;
      }
        problem *next = new problem;
        next = trav->next;
        trav->next=temp;
        temp->next=next;
        this->size++;
      }else{
       add(id,name,difficulty);
      }
  }
}

  void linkedList::add(int id, string name, string difficulty){
    problem *check = head;
    while(check!=nullptr){
      if(check->id==id){
        return;
      }
      check=check->next;
    }
     problem *temp = new problem;
     temp->id=id;
     temp->name = name;
     temp->difficulty=difficulty;
     if(difficulty=="Easy"){
       temp->difficultyRank=1;
     }else if(difficulty=="Medium"){
       temp->difficultyRank=2;
     }else if(difficulty=="Hard"){
       temp->difficultyRank=3;
     }

    if(head==nullptr){
      head=temp;
      this->size++;
    }else{
      problem *test = head;
      while(test->next!=nullptr){
        test=test->next;
      }
      test->next=temp;
      this->size++;
    }
  }

  void linkedList::remove(int choice, string data, int pos){ 
    switch(choice){
      case 1:{//case for deleting by problem_id
        problem *test = head;
        problem *prev = nullptr;
        while(test!=nullptr){
          if(test->id==stoi(data) && prev==nullptr){
            this->size--;
            problem *next = test->next;
            test = prev;
            head=next;
            delete test;
            return;
          }else if(test->id==stoi(data)&& prev!=nullptr){
            problem *next = test->next;
            prev->next= next;
            delete test;
            this->size--;  
          }
        prev=test;
        test=test->next;
        }
          break;
    }
    case 2: { //case for deleting by problem_name
    problem *test = head;
    problem *prev = nullptr;
    while(test!=nullptr){
      if ((test->name)==data){
        this->size--;
        if(prev==nullptr){
          head = test->next;
        }else{
          problem *next = test->next;
        prev->next=next;
        delete test;    
      }
      }
        cout<<data<<endl;
        prev=test;
        test=test->next;
      }
      break;
    }
    case 3:{ //remove by difficulty
      problem *test = head;
    problem *prev = nullptr;
    while(test!=nullptr){
      if (test->difficulty==data){
        this->size--;
        if(test==head){
          head = test->next;
        }else{
          problem *next = test->next;
        prev->next=next;
        delete test;    
      }
      }
        cout<<data<<endl;
        prev=test;
        test=test->next;

      }
      break;
  }
   case 4:{ //remove by position
      if(pos<0 || pos>this->size){
        return;
      }else{ 
        problem *trav = head;
        problem *prev = nullptr;
        //problem *next = trav->next;
        if(pos==0 && head!=nullptr){
          this->size--;
         problem *next =head->next;
         delete head;
         head = next; 
        }else{
          for(int i=0; i<pos;i++){
            prev=trav;
            trav=trav->next;
          
          }
          problem *next = trav->next;
          delete trav;
          prev->next = next;
          this->size--;

        }
    
   } 
break; }}
    }

  //this Sort Function is based on the Bubble Sort function found at https://www.geeksforgeeks.org/bubble-sort-for-linked-list-by-swapping-nodes/ 
 //and was originally written by kalaikarthick
  void linkedList::sort(int choice, int direction){
    //0 = ascending, 1 = descending
        switch(choice){
          case 1: {//sort based on id number
              if(direction==0){//sort ascending
              problem** h; 
              int i, j, swapped; 
  
              for (i = 0; i <= this->size; i++) { 
                h = &head; 
                swapped = 0; 
                for (j = 0; j < (this->size)- i - 1; j++){ 
                  problem* p1 = *h; 
                  problem* p2 = p1->next; 
  
                  if (p1->id > p2->id){ 
                /* update the link after swapping */
                  problem* tmp = p2->next; 
                  p2->next = p1; 
                  p1->next = tmp; 
                  *h=p2;
                  swapped = 1; 
            } 
            h = &(*h)->next; 
        } 
        /* break if the loop ended without any swap */
        if (swapped == 0){break;}
    } //end "ascending" if
            }else if(direction==1){ //sort descending
              problem** h; 
              int i, j, swapped; 
              for (i = 0; i <= this->size; i++) { 
                h = &head; 
                swapped = 0; 
                for (j = 0; j < (this->size)- i - 1; j++){ 
                  problem* p1 = *h; 
                  problem* p2 = p1->next; 
                  if (p1->id < p2->id){        
                  problem* tmp = p2->next; 
                  p2->next = p1; 
                  p1->next = tmp; 
                  *h=p2;
                  swapped = 1; 
            } 
            h = &(*h)->next; 
        } 
        if (swapped == 0){break;}
        } 
    }
        break; }//end case 1
          case 2:{//sort based on problem_name
                if(direction==0){
                  problem** h; 
              int i, j, swapped; 
              for (i = 0; i <= this->size; i++) { 
                h = &head; 
                swapped = 0; 
                for (j = 0; j < (this->size)- i - 1; j++){ 
                  problem* p1 = *h; 
                  problem* p2 = p1->next; 
                  if (p1->name < p2->name){        
                    problem* tmp = p2->next; 
                    p2->next = p1; 
                    p1->next = tmp; 
                    *h=p2;
                    swapped = 1; 
            } 
            h = &(*h)->next; 
        } 
        if (swapped == 0){break;}
        } 
                }else if(direction==1){
                  problem** h; 
                int i, j, swapped; 
                for (i = 0; i <= this->size; i++) { 
                  h = &head; 
                  swapped = 0; 
                for (j = 0; j < (this->size)- i - 1; j++){ 
                  problem* p1 = *h; 
                  problem* p2 = p1->next; 
                  if (p1->name > p2->name){        
                  problem* tmp = p2->next; 
                  p2->next = p1; 
                  p1->next = tmp; 
                  *h=p2;
                  swapped = 1; 
            } 
            h = &(*h)->next; 
        } 
        if (swapped == 0){break;}
        } 
                }
       break;}//end case 2
        
        case 3:{//sort by difficultyRank
        if(direction==0){
                  problem** h; 
              int i, j, swapped; 
              for (i = 0; i <= this->size; i++) { 
                h = &head; 
                swapped = 0; 
                for (j = 0; j < (this->size)- i - 1; j++){ 
                  problem* p1 = *h; 
                  problem* p2 = p1->next; 
                  if (p1->difficultyRank > p2->difficultyRank){        
                    problem* tmp = p2->next; 
                    p2->next = p1; 
                    p1->next = tmp; 
                    *h=p2;
                    swapped = 1; 
            } 
            h = &(*h)->next; 
        } 
        if (swapped == 0){break;} 
        }
  } else if(direction==1){
                  problem** h; 
              int i, j, swapped; 
              for (i = 0; i <= this->size; i++) { 
                h = &head; 
                swapped = 0; 
                for (j = 0; j < (this->size)- i - 1; j++){ 
                  problem* p1 = *h; 
                  problem* p2 = p1->next; 
                  if (p1->difficultyRank < p2->difficultyRank){        
                    problem* tmp = p2->next; 
                    p2->next = p1; 
                    p1->next = tmp; 
                    *h=p2;
                    swapped = 1; 
            } 
            h = &(*h)->next; 
        } 
        if (swapped == 0){break;}
  }
}
        break;}//end case 3
        }//end switch statement
        }

  string linkedList::print(){
    string output;
    problem *test = new problem;
    test = head;
    while(test!=nullptr){ 
      cout<<"problem_id:"<<test->id<<", problem_name: "<<test->name<<", difficulty: "<<test->difficulty<<endl;
      output+="problem_id:"+to_string(test->id)+", problem_name:"+test->name+", difficulty:"+test->difficulty+"\n";

      test=test->next;
    }
    return output;
}
  
