//
//  main.cpp
//  final project
//
//  Created by shan on 4/20/17.
//  Copyright © 2017 shan. All rights reserved.
//
#include "shapes.hpp"
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <memory>
#include <vector>
#include <fstream>
#include <math.h>
#include <string>

//This is just a demo test for testing the element if it functions well.
int main() {
    cout<<"welcome to the game!!!"<<endl;
    cout<<"Start(1) or resume(2)?"<<endl;
    vector<string> Name = {};
    vector<int> Score ={};
    vector<int> Tops ={};
    vector<string> Location = {};
    int choice;
    cin >> choice;
    string username;
    int score;
    if (choice == 1){
        cout<<"What's your name?"<<endl;
        cin >> username;
        score = 0;
        Coord a;
        a.setCenter(120, 150);
        a.move(50, 100);
        a.setHeight(150);
        a.setWidth(120);
        
        Car A(a);
        A.setName(username);
        A.setScore(score);
    
        Coord b;
        b.setCenter(12, 16);
        b.setHeight(150);
        b.setWidth(120);
        
        Barrier B(b);
        
        
        Coord c;
        c.setCenter(146, 126);
        c.setHeight(150);
        c.setWidth(120);
        
        Barrier C(c);
        if (a.isOverlapping(b)){
            cout<<"overlap"<<endl;
        }
        cout<<"Do you want to save(1) or not (2)?"<<endl;
        int save;
        cin >> save;
        if (save == 1){
            string point = to_string(a.getCenterX())+" "+ to_string(a.getCenterY())+" "+to_string(a.getHeight())+" "+to_string(a.getWidth());
            Name.push_back(A.getName());
            Score.push_back(A.getScore());
            Location.push_back(point);
            ofstream out_file("/Users/apple/Desktop/score.txt",ios_base::out|ios_base::app);
            ofstream out_file2("/Users/apple/Desktop/location.txt");
            if (out_file) {
                for(int i = 0; i < Name.size(); i++){
                    out_file << Name[i]<<" " <<Score[i]<< endl;
                }
                // out_file << A.getName()<<" " <<A.getScore()<< endl;
            }
            out_file.close();
            if (out_file2){
                for(int i = 0; i < Location.size(); i++){
                    out_file2 << Location[i]<< endl;
                }
            }
            out_file2.close();
        }else if (save ==2){
            return 0;
        }
    } else if (choice == 2){
        ifstream in_file("/Users/apple/Desktop/score.txt");
        ifstream in_file2("/Users/apple/Desktop/location.txt");
        if (!in_file ||!in_file2 ){
            cout << "You don't have a saved game to resume!" << endl;
        }else{
            if (in_file) {
            string str;
            while (getline(in_file, str)) {
                istringstream iss(str);
                string name;
                string score;
                iss>> name;
                iss>>score;
                Name.push_back(name);
                Score.push_back(stoi(score));
                cout << "name "+name << endl;
                cout << "score "+score << endl;
            }
        }
        if (in_file2) {
            string str;
            while (getline(in_file2, str)) {
                istringstream iss(str);
                string x_coord;
                string y_coord;
                string s_height;
                string s_width;
                iss>> x_coord;
                iss>>y_coord;
                iss>> s_height;
                iss>> s_width;
                cout<<x_coord<<endl;
                cout<<y_coord<<endl;
                cout<<s_height<<endl;
                cout<<s_width<<endl;
                Coord a;
                a.setCenter(stoi(x_coord), stoi(y_coord));
                a.setHeight(stoi(s_height));
                a.setWidth(stoi(s_width));
            }
        }
        }
    }
    return 0;
}
