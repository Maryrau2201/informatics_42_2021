#include <iostream>
#include <cmath>

using namespace std;


void calc(int n) {
    int proizvedenie = 1;
    while (n>0) {
        proizvedenie *= n % 10;
        n /= 10;
    }
    cout<<proizvedenie;
}

int main(){
    long n;
    cin>>n;
    while (n<100000 || n>999999) {
        cout<<"Chislo ne sootvet trebovaniu"<<endl;
        cin >>n;
    }
    calc(n);


   


}