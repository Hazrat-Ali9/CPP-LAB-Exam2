#include<bits/stdc++.h>
using namespace std;
void deleteValue(list<int> & p , int value){
    auto a = p.begin();
    int index=0;
    while(a!=p.end()){
        if(value==*a){
            p.erase(a);
            return;
        }
        a++;


}

void printlist(list<int> &p){
    list<int>::iterator a = p.begin();

    while(a!=p.end()){
        cout<<*a<<" ";
        a++;
    }
    cout<<endl;
}

int main ( ){
    list<int> p;
    p.push_back(7);
    p.push_back(3);
    p.push_back(8);
    p.push_back(4);
    p.push_back(5);
    p.push_back(4);


    printlist(p);
    deleteValue(p,4);
    printlist(p);
}
