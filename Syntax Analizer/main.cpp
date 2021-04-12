#include<iostream>
#include <string>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
using namespace std;

int Keyword(char buff[]){
    char keywords[33][10]  = {"auto","break","case","char","const","continue","default",
							"do","double","else","enum","extern","float","for","goto",
							"if","int","long","register","return","for","signed",
							"sizeof","static","struct","switch","typedef","union",
							"unsigned","void","volatile","while","main"};
    int flag;
    flag = 0;

    for(int i = 0;i < 33; ++i){
        if(strcmp(keywords[i],buff) == 0){
            flag = 1;
            break;
        }
    }
    return flag;
}

int main(){

    ifstream f;
    f.open("code.txt");                                     //Open the file using the object

    char c;
    string b;
    char buff[30], operators[] = "+-*/%=", separators[] = ",;{}()" ;
    int j = 0;

    if(!f.is_open()){
		cout<<"\nError while opening the file";
		exit(0);
	}
    char buffFor[100][10];
    int i = 0;
    while(!f.eof()){

        c = f.get();
        b.push_back(c);


        for(int i = 0; i<= 6; i++){
            if (c == operators[i]){
                cout<<"\n"<<c<<" ------> operator";
            }
        }

        for(int i = 0; i <= 4; i++){
            if (c == separators[i]){
                cout<<"\n"<<c<<" ------> separator";
            }
        }

        if(isalnum(c)){
            buff[j++] = c;
        }

        if(isdigit(c)){
            cout<<"\n"<<c<<" ------> constant";
        }

        else if((c == ' ' or c == '\n') and j != 0){
            buff[j] = '\0';
            j = 0;

            if(Keyword(buff) == 1){
                cout<<"\n"<<buff<<" \t \t------------> keyword";
            }
            else{
                cout<<"\n"<<buff<<" \t------> id";
            }
        }
    }

    f.close();
    return 0;
}
