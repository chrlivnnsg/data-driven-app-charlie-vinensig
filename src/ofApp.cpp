#include "ofApp.h"


void ofApp::setup() {

    mainSmall.load("Teko-Medium.ttf", 17);
    mainBig.load("YanoneKaffeesatz-Bold.ttf", 35);
    mainBigger.load("Teko-Medium.ttf", 35);
    logoBig.load("Teko-Medium.ttf", 30);
    mainBigBold.load("Lobster-Regular.ttf", 75);

    backgroundImg.load("background.png");
    logoImg.load("twitter.png");
    searchBarImg.load("search.png");
    instructionsImg.load("instructions.jpg");
    //all of the button attributes
    btn1.set(20, 250, 90, 40);
    btn2.set(20, 300, 65, 40);
    btn3.set(20, 350, 120, 40);
    btn4.set(20, 400, 65, 40);
    btn5.set(20, 450, 70, 40);
    btn6.set(20, 500, 65, 40);
    btn7.set(20, 550, 70, 40);
    btn8.set(20, 660, 70, 40);
    btn9.set(20, 710, 70, 40);
    btn10.set(20, 760, 80, 40);
    result.set(300, 200, 1200, 850);

    //labels
    mainBig.load("YanoneKaffeesatz-Bold.ttf", 18);
    query = "QUERIES";
    count = "COUNTS";

   //Twitter Label
    mainBigBold.load("Lobster-Regular.ttf", 75);
    tweet = "TWEETS";

    loadData();
}

string ofApp::wrapString(string text, int width) {
    string typeWrapped = "";
    string tempString = "";
    vector <string> words = ofSplitString(text, " ");

    for (int i = 0; i < words.size(); i++) {
        string wrd = words[i];

        if (i > 0) {
            tempString += " ";
        }
        tempString += wrd;

        int stringwidth = mainSmall.stringWidth(tempString);

        if (stringwidth >= width) {
            typeWrapped += "\n";
            tempString = wrd;
        }
        else if (i > 0) {
            typeWrapped += " ";
        }
        typeWrapped += wrd;
    }
    return typeWrapped;
}

void ofApp::loadData() {
    data.open(ofToDataPath("sampleTweets1.csv"));
    if (data.is_open()) {
        while (!data.eof()) {

            getline(data, dateTimeHolder, ',');
            getline(data, ignore, 'b');
            getline(data, tweetHolder);
            numberOfLines++;
            tweetHolder1.push_back(dateTimeHolder);
            tweetHolder2.push_back(tweetHolder);

        }
        tweetHolder1.erase(tweetHolder1.begin());
        data.close();
    }
    else {
        cout << "The File Was Not Found." << endl;
    }
}

void ofApp::draw() {
    //buttons
    ofBackground(0, 138, 190);
    ofSetColor(0, 172, 238);
    ofDrawRectangle(btn1);
    ofDrawRectangle(btn2);
    ofDrawRectangle(btn3);
    ofDrawRectangle(btn4);
    ofDrawRectangle(btn5);
    ofDrawRectangle(btn6);
    ofDrawRectangle(btn7);
    ofDrawRectangle(btn8);
    ofDrawRectangle(btn9);
    ofDrawRectangle(btn10);
    ofDrawRectangle(result);
    
    //button texts
    ofSetColor(255);
    mainSmall.drawString("Politics", 35, 275);
    mainSmall.drawString("Paris", 35, 325);
    mainSmall.drawString("Dreamworks", 35, 375);
    mainSmall.drawString("Uber", 35, 425);
    mainSmall.drawString("Angel", 35, 475);
    mainSmall.drawString("Out", 35, 525);
    mainSmall.drawString("Game", 35, 575);
    mainSmall.drawString("Texts", 35, 685);
    mainSmall.drawString("Money", 35, 735);
    mainSmall.drawString("Politics", 35, 785);
    int i = 340, j = 220, k = 490, l = 240;

    //logo
    logoImg.draw(20, 20);
    logoImg.resize(150, 150);

    //labels
    ofSetColor(204, 204, 255);
    mainBig.drawString(query, 25, 235);
    mainBig.drawString(count, 25, 650);
    mainBigBold.drawString(tweet, 750, 120);

    //draws the count
    ofSetColor(204, 204, 255);
    logoBig.load("Teko-Medium.ttf", 35);
    logoBig.drawString(count1, 125, 750);

    //dates, searched tweets
    ofSetColor(255, 255, 255);
    for (int a = 0; a < searched_tweets.size(); a++) {
        mainSmall.drawString(date_of_tweets_searched[a], i, j);
        j += 82;

        string newText = wrapString(searched_tweets[a], 650);

        mainSmall.drawString(newText, k, l);
        l += 80;
    }

}

void ofApp::mousePressed(int x, int y, int button) { //this is where the buttons are pressed
    //Politics Button
    if (btn1.inside(x, y)) {
        searched_tweets.clear();
        for (int i = 0; i < tweetHolder2.size(); i++) {
            string str1 = tweetHolder2[i];
            if (str1.find("Politics") != string::npos) {
                searched_tweets.push_back(tweetHolder2[i]);
                date_of_tweets_searched.push_back(tweetHolder1[i]);
            }
        }
    }
    //Paris Button
    if (btn2.inside(x, y)) {
        searched_tweets.clear();
        for (int i = 0; i < tweetHolder2.size(); i++) {
            string str1 = tweetHolder2[i];
            if (str1.find("Paris") != string::npos) {
                searched_tweets.push_back(tweetHolder2[i]);
                date_of_tweets_searched.push_back(tweetHolder1[i]);
            }
        }
    }
    //Dreamworks Button
    if (btn3.inside(x, y)) {
        searched_tweets.clear();
        for (int i = 0; i < tweetHolder2.size(); i++) {
            string str1 = tweetHolder2[i];
            if (str1.find("Dreamworks") != string::npos) {
                searched_tweets.push_back(tweetHolder2[i]);
                date_of_tweets_searched.push_back(tweetHolder1[i]);
            }
        }
    }
    //Uber Button
    if (btn4.inside(x, y)) {
        searched_tweets.clear();
        for (int i = 0; i < tweetHolder2.size(); i++) {
            string str1 = tweetHolder2[i];
            if (str1.find("Uber") != string::npos) {
                searched_tweets.push_back(tweetHolder2[i]);
                date_of_tweets_searched.push_back(tweetHolder1[i]);
            }
        }
    }
    //Angel Button
    if (btn5.inside(x, y)) {
        searched_tweets.clear();
        for (int i = 0; i < tweetHolder2.size(); i++) {
            string str1 = tweetHolder2[i];
            if (str1.find("Angel") != string::npos) {
                searched_tweets.push_back(tweetHolder2[i]);
                date_of_tweets_searched.push_back(tweetHolder1[i]);
            }
        }
    }
    //Out Button
    if (btn6.inside(x, y)) {
        searched_tweets.clear();
        for (int i = 0; i < tweetHolder2.size(); i++) {
            string str1 = tweetHolder2[i];
            if (str1.find("Out") != string::npos) {
                searched_tweets.push_back(tweetHolder2[i]);
                date_of_tweets_searched.push_back(tweetHolder1[i]);
            }
        }
    }
    //Game Button
    if (btn7.inside(x, y)) {
        searched_tweets.clear();
        for (int i = 0; i < tweetHolder2.size(); i++) {
            string str1 = tweetHolder2[i];
            if (str1.find("Game") != string::npos) {
                searched_tweets.push_back(tweetHolder2[i]);
                date_of_tweets_searched.push_back(tweetHolder1[i]);
            }
        }
    }
    //Tweets Button
    if (btn8.inside(x, y)) {
        searched_tweets.clear();
        count1.clear();
        for (int i = 0; i < tweetHolder2.size(); i++) {
            count1 = to_string(tweetHolder2.size());
        }
    }
    //Money Button
    if (btn9.inside(x, y)) {
        searched_tweets.clear();
        count1.clear();
        for (int i = 0; i < tweetHolder2.size(); i++) {
            string str1 = tweetHolder2[i];
            if (str1.find("Money") != string::npos) {
                counter += 1;
                count1 = to_string(counter);
            }
        }
        counter = 0;
    }
    //Politics Total Button
    if (btn10.inside(x, y)) {
        searched_tweets.clear();
        count1.clear();
        for (int i = 0; i < tweetHolder2.size(); i++) {
            string str1 = tweetHolder2[i];
            if (str1.find("Politics") != string::npos) {
                counter += 1;
                count1 = to_string(counter);
            }
        }
        counter = 0;
    }
}