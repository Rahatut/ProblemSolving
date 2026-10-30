#include<iostream>
using namespace std;

int solve(int a, int b) {
    if (a <= b) return -1;
    else{
        return min(a - b, b);
    } // if cheese <= sausage, sandwich cant be made. all sausage and sand must be used. 
    //for each sausage at least more cheese needed
    //each sand has sausage and cheese
    // the number of cheese more than sausage - determines how many more sandwich can be made. 6,4 : 6-4 = 2, sausage =4, 2 cheese more, so, 2 sandwich can have 1 more slice of cheese more than sausage
    // 2 sausage, 3 cheese, 2 sausage 3 cheese
    //5, 1 : only 1 sausage can make 1 sandwich. so the smaller val between num of sausage and how many more cheese present is the ans 
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int a, b;
        cin>>a>>b;
        cout<<solve(a, b)<<endl;
    }
}
