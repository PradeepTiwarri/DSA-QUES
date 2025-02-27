#include<iostream>
using namespace std;
int temp(int n){
    int s =0 ;
    int e = n;
    int ans = -1;
    int  mid = s + (e-s)/2;

    while(s<=e){
        if(mid*mid ==n){
            return mid ;
        }
        if(mid*mid <n){
            ans = mid;
            s= mid +1;
        }
        else{
            e= mid-1;
           
        }
    mid = s + (e-s)/2;  
    }
    return ans;
}
double  precision(int n , int precise,int sqrt){
    double factor  = 1 ;
    double ans = sqrt;
    for(int i =0 ; i< precise; i++){
        factor = factor/10;
        for(double j = ans; j*j<n ;j=j+factor){
            ans = j;

        }
    }
    return ans ;
}
int main(){
 int n ;
 cout << "enter the number for square root: "<< " " ;
 cin >> n ;

 int sqrt= temp(n);
 //cout << sqrt;
 cout<< precision(n,3,sqrt);
 return 0 ;
}