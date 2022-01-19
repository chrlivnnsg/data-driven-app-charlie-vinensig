#pragma once

#include "ofMain.h"
#include <vector>
#include <string>

class ofApp : public ofBaseApp {

public:
    int numberOfLines = 0;
    int counter = 0;
    void setup();
    void draw();
    void loadData();
    string ofApp::wrapString(string text, int width);

    void mousePressed(int x, int y, int button);
    vector <string> searched_tweets, tweetHolder1, tweetHolder2, date_of_tweets_searched;
    string dateTimeHolder, ignore, tweetHolder, text, count, count1, str3, query, print, counttxt, tweet;
    ifstream data;

    ofRectangle btn1, btn2, btn3, btn4, btn5, btn6, btn7, btn8, btn9, btn10, result;
    ofTrueTypeFont mainSmall, mainBig, mainBigger, logoBig, mainBigBold;
    ofImage backgroundImg, logoImg, searchBarImg, refreshImg, instructionsImg;
};