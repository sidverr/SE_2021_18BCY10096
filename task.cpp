#include <bits/stdc++.h>
using namespace std;

string A_qaws(string qw, string op);
string B_qaws(string qw, string op);
void Aforward(int x, int y, string qw);
void Bforward(int x,int y, string qw);

string a = "A-",b="B-",chess[5][5], amove, bmove, charac,qw,op;

int main() {
    
    string A[5],B[5]; chess[5][5], amove, bmove, charac;
    
    
    cout<<"Player1 Input:";
    for(int i=0;i<5;i++) cin>>A[i];
    cout<<"Player2 Input:";
    for(int i=0;i<5;i++) cin>>B[i];
    
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
        chess[i][j] = '-';
    
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i==0) chess[i][j] = b + B[j];
            if(i==4) chess[i][j] = a + A[j];
        }
    }
    
    cout<<"Current Grid:"<<endl;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
        cout<<chess[i][j]<<"		";
        cout<<endl;
    }
    
    cout<<"Player A's move:";
    cin>>amove;
    A_qaws(amove.substr(0,2),amove.substr(3,3));
    
    cout<<"Player B's move:";
    cin>>bmove;
    B_qaws(bmove.substr(0,2),bmove.substr(3,3));
    
    
    return 0;
}


string B_qaws(string qw, string op){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if( chess[i][j] == (b + qw)){
                chess[i][j] = "-";
                Bforward(i,j,bmove.substr(0,2));
            }
        }
    }
    return "1";
}

string A_qaws(string qw, string op){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if( chess[i][j] == (a + qw)){
                chess[i][j] = "-";
                Aforward(i,j,amove.substr(0,2));
            }
        }
    }
    return "1";
}

void Aforward(int x,int y, string qw){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i==x-1 && j==y)
            chess[i][j] = (a + qw);
        }
    }
    cout<<"Current Grid:"<<endl;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
        cout<<chess[i][j]<<"		";
        cout<<endl;
    }
}

void Bforward(int x,int y, string qw){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i==x+1 && j==y)
            chess[i][j] = (b + qw);
        }
    }
    cout<<"Current Grid:"<<endl;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++)
        cout<<chess[i][j]<<"		";
        cout<<endl;
    }
}
