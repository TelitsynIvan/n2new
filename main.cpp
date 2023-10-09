#include <iostream>
#include <string>

class MyDeqeue{
private:
    std::string* data;
    int size = 0;
    int front = 0;
    int back = 0;
    int capacity = 0;
    bool set_size_flag=0;
public:
    MyDeqeue() = default;

    ~MyDeqeue() = default;

    void set_size(int n){
        if(set_size_flag==1){
            std::cout<<"error"<<'\n';
            return;
        }
        if(n<0){
            std::cout<<"error"<<'\n';
            return;
        }
        size = n;
        data = new std::string[size];
        for(int i=0; i<size; i++){
            data[i] = "\0";
        }
        set_size_flag = 1;
    }
    void pushf(std::string X){
        if(set_size_flag==0){
            std::cout<<"error"<<'\n';
            return;
        }
        if(capacity==size){
            std::cout<<"overflow"<<'\n';
            return;
        }
        front = (front-1+size)%size;
        data[front] = X;
        capacity++;
    }
    void pushb(std::string X){
        if(set_size_flag==0){
            std::cout<<"error"<<'\n';
            return;
        }
        if(capacity==size){
            std::cout<<"overflow"<<'\n';
            return;
        }
        data[back] = X;
        capacity++;
        back = (back+1)%size;
    }
    void popf(){
        if(set_size_flag==0){
            std::cout<<"error"<<'\n';
            return;
        }
        if(capacity==0){
            std::cout<<"underflow"<<'\n';
            return;
        }
        std::cout<<data[front]<<'\n';
        data[front] = "\0";
        capacity--;
        front = (front+1)%size;
    };
    void popb(){
        if(set_size_flag==0){
            std::cout<<"error"<<'\n';
            return;
        }
        if(capacity==0){
            std::cout<<"underflow"<<'\n';
            return;
        }
        back = (back-1+size)%size;
        std::cout<<data[back]<<'\n';
        data[back] = "\0";
        capacity--;
    };
    void print(){
        if(set_size_flag==0){
            std::cout<<"error"<<'\n';
            return;
        }
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

bool isNumeric(std::string object){
    for(int i=0; i<object.length(); i++){
        if(object[i]<'0' || object[i]>'9'){
            return false;
        }
    }
    return true;
}

bool checkSpaces(std::string object){
    for(int i=0; i<object.length(); i++){
        if(isspace(object[i])==1){
            return false;
        }
    }
    return true;
}

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
        if(enter.compare(0, 9, "set_size ")==0 && enter.length()>9){
            if(isNumeric(enter.substr(9))){
                test.set_size(stoi(enter.substr(9, std::string::npos)));
                continue;
            }
            std::cout<<"error"<<'\n';
            continue;
        }
        if(enter.compare(0, 6, "pushf ")==0 && enter.length()>=6){
            if(enter.length()==6){
                test.pushf("");
                continue;
            }
            std::string temp = enter.substr(6, std::string::npos);
            if(checkSpaces(temp)){
                test.pushf(temp);
                continue;
            }
            std::cout<<"error"<<'\n';
            continue;
        }
        if(enter.compare(0, 6, "pushb ")==0 && enter.length()>=6){
            if(enter.length()==6){
                test.pushb("");
                continue;
            }
            std::string temp = enter.substr(6, std::string::npos);
            if(checkSpaces(temp)){
                test.pushb(temp);
                continue;
            }
            std::cout<<"error"<<'\n';
            continue;
        }
        if(enter=="\n"){
            continue;
        }
        else{
            std::cout<<"error"<<'\n';
            continue;
        }
    }
    return 0;
}
