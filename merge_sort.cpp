#include<stdlib.h>
#include <iostream>
#include <string>

using namespace std;

unsigned long long int merged_row[500000];

void merge_sort(int n, unsigned long long int row[]){
    if(n==1){
        merged_row[0] = row[0];
    }
    else{
        unsigned long long int half_row1[n-1],half_row2[n-1];
        unsigned long long int merged_row1[n-1],merged_row2[n-1];
        if(n%2 == 0){//n is even number
            int i = 0;
            while (i<n/2) {
                half_row1[i] = row[i];
                half_row2[i] = row[i+n/2];
                i++;
            }
            merge_sort(n/2, half_row1);
            for(i=0;i<n/2;i++){
                merged_row1[i] = merged_row[i];
            }
            merge_sort(n/2, half_row2);
            for(i=0;i<n/2;i++){
                merged_row2[i] = merged_row[i];
            }
//            cout<<merged_row1[0]<<endl;
//            cout<<merged_row2[0]<<endl;
        }
        else {//n is odd number
            int i = 0;
            while (i<(n-1)/2) {
                half_row1[i] = row[i];
                half_row2[i] = row[i+(n+1)/2];
                i++;
            }
            half_row1[(n-1)/2] = row[(n-1)/2];
            merge_sort((n+1)/2, half_row1);
            for(i=0;i<(n+1)/2;i++){
                merged_row1[i] = merged_row[i];
            }
            merge_sort((n-1)/2, half_row2);
            for(i=0;i<(n-1)/2;i++){
                merged_row2[i] = merged_row[i];
            }
        }
        int index1 = 0;
        int index2 = 0;
        int index = 0;
        while(index<n && index1<=(n-1)/2 && index2<= n/2-1){
            if(merged_row1[index1] < merged_row2[index2]){
                merged_row[index] = merged_row1[index1];
                index1++;
            }
            else {
                merged_row[index] = merged_row2[index2];
                index2++;
            }
            index++;
        }
        if(index<n && index1<=(n-1)/2){
            while (index<n) {
                merged_row[index] = merged_row1[index1];
                index++;
                index1++;
            }
        }
        else if (index<n && index2<= n/2-1) {
            while (index<n) {
                merged_row[index] = merged_row2[index2];
                index++;
                index2++;
            }
        }
    }
}

int main() {
    int N;
    //N<=500000
    cin >> N;
    unsigned long long int rows[N-1];
    int i = 0;
    while(i<N){
        cin >> rows[i];
        i++;
    }
    merge_sort(N,rows);
    int j = 0;
    while (j<N) {
        cout << merged_row[j] << endl;
        j++;
    }
}
