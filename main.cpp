#include <iostream>
#include <string>

class MyDeqeue{
private:
    std::string* data;
    int size = 0;
    int front = 0;
    int back = 0;
    int capacity = 0;
public:
    MyDeqeue() = default;

    ~MyDeqeue() = default;

    void set_size(int n){
        if(n<0){
            std::cout<<"error"<<'\n';
            return;
        }
        size = n;
        data = new std::string[size];
        for(int i=0; i<size; i++){
            data[i] = "\0";
        }
    }
    void pushf(std::string X){
        if(capacity==size){
            std::cout<<"overflow"<<'\n';
            return;
        }
        front = (front-1+size)%size;
        data[front] = X;
        capacity++;
    }
    void pushb(std::string X){
        if(capacity==size){
            std::cout<<"overflow"<<'\n';
            return;
        }
        data[back] = X;
        capacity++;
        back = (back+1)%size;
    }
    void popf(){
        if(capacity==0){
            std::cout<<"underflow"<<'\n';
            return;
        }
        std::cout<<data[front]<<'\n';
        capacity--;
        front = (front+1)%size;
    };
    void popb(){
        if(capacity==0){
            std::cout<<"underflow"<<'\n';
            return;
        }
        back = (back-1+size)%size;
        std::cout<<data[back]<<'\n';
        capacity--;
    };
    void print(){
        if(capacity==0){
            std::cout<<"empty"<<'\n';
            return;
        }
        for(int i = front; i<size+front; i++){
            if(i==size+front-1){
                std::cout<<data[i%size]<<'\n';
                continue;
            }
            std::cout<<data[i%size]<<' ';
        }
    };
};

int main() {
    MyDeqeue test;
    std::string enter;
    while (!std::cin.eof()){
        std::getline(std::cin, enter);
        if(enter=="print"){
            test.print();
            continue;
        }
        if(enter=="popf"){
            test.popf();
            continue;
        }
        if(enter=="popb"){
            test.popb();
            continue;
        }
        if(enter.compare(0, 9, "set_size ")==0){

        }
        else{
            std::cout<<"error"<<'\n';
            continue;
        }
    }
    return 0;
}
