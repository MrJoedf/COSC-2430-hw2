#include <iostream>
#include <fstream>
#include "LinkedList.h"
#include "ArgumentManager.h"
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
  if(argc<2){return -1;}

  ArgumentManager am(argc, argv);
  string inputFileName = am.get("input");
  string outputFileName = am.get("output");
  string commandFileName = am.get("command");

  ifstream inputFile, commandFile; ofstream outputFile;
  inputFile.open(inputFileName);
  outputFile.open(outputFileName);
  commandFile.open(commandFileName);

  linkedList link;
   string s = "problem_id:", u = " problem_name:", v = " difficulty:", t;
  int pos;
  vector<string> labels = {s, u, v};

  while(inputFile){
    linkedList *temp = new linkedList;
    temp = &link;
    while(getline(inputFile, t)){
      if(t==""){continue;
      }else{
       for(string s : labels){
        string::size_type i = t.find(s);
        if (i != std::string::npos)
           t.erase(i, s.length());
    }
    string pID, pName, pDifficulty;
    stringstream s_stream(t);
        getline(s_stream, pID, ',');
        getline(s_stream, pName, ',');
        getline(s_stream, pDifficulty, ','); 
    
    temp->add((stoi(pID)),pName,pDifficulty);
    //cout<<"Test"<<endl;
    }
  }
  }

  while(commandFile){
    string posT, probID, probName, probDif, str, prob;
    while(getline(commandFile,str)){
      if(str==""){continue;
      }else{
        cout<<str<<endl;
        if((str.find("sort") != string::npos)) {
          cout<<"SORTING!"<<endl;
        if(str=="sort problem_id increasing"){
          link.sort(1,0);
        }else if(str=="sort problem_id decreasing"){
          link.sort(1,1);
        }else if(str=="sort problem_name increasing"){
          link.sort(2,0);
        }else if(str=="sort problem_name decreasing"){
          link.sort(2,1);
        }else if(str=="sort difficulty increasing"){
          link.sort(3,0);
        }else if(str=="sort difficulty decreasing"){
          link.sort(3,1);
        }
        }else if((str.find("remove")!=string::npos)){
          cout<<"REMOVING!"<<endl;
        if((str.find("pos")!=string::npos)){
            pos = str[str.find(':')+1]-'0'; 
            link.remove(4, "", pos);
        }else if((str.find("difficulty")!=string::npos)){
          probDif= str.substr(str.find(":") + 1);
          link.remove(3, probDif,0);
        }else if((str.find("problem_name")!=string::npos)){
          probName=str.substr(str.find(":")+1);
          link.remove(2,probName,0);
        }else if((str.find("problem_id")!=string::npos)){
          probID = str.substr(str.find(":")+1);
          link.remove(1,probID,0);
        }
        }else if((str.find("add pos")!=string::npos)){
          if(isdigit(str[str.find(':')+1])){
           pos = str[str.find(':')+1]-'0';}else{
             if(str[str.find(':')+1]=='-'){
               pos = str[str.find(':')+2]-'0';
             }
           }
           prob = str.substr(str.find(to_string(pos))+2);
           for(string s : labels){
            string::size_type i = prob.find(s);
            if (i != std::string::npos)
               prob.erase(i, s.length());
                }
          cout<<"PROB: "<<prob<<endl;
            stringstream probGet(prob);
            getline(probGet,probID, ',');
            getline(probGet, probName, ',');
            getline(probGet, probDif, ',');

            link.addPos(pos,stoi(probID),probName, probDif);                
        }
    }        
    }}
  /*link.add(1, "Mr. Mee6","Easy");
  link.add(5, "Test", "Easy");
  link.add(2,"Look at me!", "Hard");
  link.add(3, "Ooh he's tryin'!", "Medium");
  link.add(4, "But he's failing!","Easy");
  link.add(5, "Test", "Easy");
  link.print();
  //link.remove(2, "But he's failing!",0);
  link.addPos(2, 37, "He eating beans!", "Medium");
  link.remove(4, "2", 0);*/
  cout<<"FINAL: "<<endl;
  outputFile<<link.print();
  cout<<"NULL?:"<<(link.head==nullptr);
  //link.sort(1,1);
  //cout<<"SORTED  PRINT:"<<endl;
  //link.remove(2, "Validate",3);
  //link.print();
  cout<<"SIZE: "<<link.size;
  //cout<<"LINK SIZE: "<<link.size<<endl;*/
  return 1;
}
// ./main "input=input21.txt;command=command21.txt;output=output21.txt"
// ./main "input=input22.txt;command=command22.txt;output=output22.txt"
// ./main "input=input23.txt;command=command23.txt;output=output23.txt"
// ./main "input=input29.txt;command=command29.txt;output=output29.txt"
// ./main "input=input27.txt;command=command27.txt;output=output27.txt"