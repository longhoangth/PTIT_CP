// count ways to place Queen in chessboard
/*
    Author: Long Hoang Thanh
    Date: 24/10/2022
*/
#include<iostream>
#define MAX 100
#define TRUE 1
#define FALSE 0

using namespace std;

int X[MAX], toFront[MAX], toBack[MAX], notVisited[MAX];
int n, dem{0};

void Init (void ) {
    cin>>n;
    for (int i=1; i<=n; i++) notVisited[i]=TRUE;
    for (int i=1; i<=(2*n-1); i++) {
        toFront[i] = TRUE; 
        toBack[i]=TRUE;
    }
}
void Try(int i){
    for (int j =1; j<=n; j++){
        if (notVisited[j] && toFront[i-j+n] && toBack[i+j-1]){
            X[i] = j;
            notVisited[j]=FALSE;
            toFront[i-j+n]=FALSE;
            toBack[i+j-1]=FALSE;
            if (i==n ) dem++;
            else Try(i+1);
            notVisited[j]=TRUE;
            toFront[i-j+n]=TRUE;
            toBack[i+j-1]=TRUE;
        }
    }
}
int main(){
    int t;
    cin >> t;
    while(t--) {
        Init(); 
        Try(1);
        cout << dem << endl;
        dem = 0;
    }
    return 0;
}