#include <iostream>
using namespace std;

int addition(int a, int b){
    int sum = a + b;
    return sum;
}

int test(int i){
    int j;
    for(j=0; j <= i; j++){
        cout << "numéro " << j << endl;
    }

    return 0;
}

int main(int argc, char const *argv[]){

    int a , b, sum;
    cout << "a = " << endl;
    cin >> a;
    cout << "b = " << endl;
    cin >> b;
    
    cout << addition(a,b) << endl;

    test(5);

    return 0;
}


