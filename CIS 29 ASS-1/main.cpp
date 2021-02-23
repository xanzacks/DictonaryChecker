//
//  main.cpp
//  CIS 29 ASS-1
//
//  Created by zhaozeyu on 2019/9/21.
//  Copyright © 2019 zhaozeyu. All rights reserved.
//

#include <iostream>
#include <string>
#include <bitset>
using namespace std;

string rotor1[27] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", " "};

void encrpution(string);
void decrpution(string);
//void miancycle();

void returnchar(char a){
    bitset<8> bset(a); // 'E' = 01000101
    string str = bset.to_string();
    for(int i = str.length(); i >= 0 ; i--){
        if(str[i] == '1'){
            cout<< str.length() - i - 1<<" ";
        }
    }
    cout << endl;
    cout << a <<" bits = " << bset.to_string() << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    /*cout << "please input the note that needed to be descripted" << endl;
    string inputwords;
    getline(cin, inputwords);
    //encrpution(inputwords);
    decrpution(inputwords);*/
    char thing;
    cin >> thing;
    returnchar(thing);
    return 0;
}

void encrpution(string note){
    int num1 = 0;
    int num2 = 9;
    int num3 = 4;
    for(string::iterator it=note.begin(); it!=note.end(); ++it){
        for(int i = 0; i < 27; i++){//get the inital num
            if(*rotor1[i].c_str() == *it){
                num1 = i;
            }
        }
        
        int finalnum = (num1 + num2 + num3 + 2) % 27;
        num2++;
        if(num2 == 27){
            num2 = 0;
            num3++;
        }
        cout<<rotor1[finalnum];
    }
    cout << endl;
}

void decrpution(string note){
    int finalnum = 0;
    int num1 = 0;
    int num2 = 9;
    int num3 = 4;
    for(string::iterator it=note.begin(); it!=note.end(); ++it){
        for(int i = 0; i < 27; i++){//get the inital num
            if(*rotor1[i].c_str() == *it){
                finalnum = i;
            }
        }
        num1 = 0;
        while((num1 + num2 + num3 + 2) % 27 != finalnum){
            num1++;
        }
        num2++;
        if(num2 == 27){
            num2 = 0;
            num3++;
        }
        cout<<rotor1[num1];
    }
    cout << endl;
}

/*void miancycle(){
    while(1){
        cout << "please input the note that needed to be descripted" << endl;
    }
}*/
