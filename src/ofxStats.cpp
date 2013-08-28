//
//  ofxStats.cpp
//  Created by Tadokoro Atsushi on 2013/08/28.
//

#include "ofxStats.h"

ofxStats::ofxStats()
:top(0), left(0), width(80), height(48), maxValue(120), lapTime(1000){
    lastLap = 0;
}

void ofxStats::update(){
    float fps = ofGetFrameRate();
    if (int(ofGetElapsedTimef() * 1000) / lapTime > lastLap) {
        lastLap++;
        fpsList.push_front(fps);
        if (fpsList.size() > width - 5) {
            fpsList.pop_back();
        }
    }
}

void ofxStats::setPosition(float _left, float _top){
    left = _left;
    top = _top;
}

void ofxStats::setSize(float _width, float _height){
    width = _width;
    height = _height;
}

void ofxStats::setMaxValue(float _maxValue){
    maxValue = _maxValue;
}

void ofxStats::setLapTime(float _lapTime){
    lapTime = _lapTime;
}

void ofxStats::draw(){
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(left, top);
    ofEnableAlphaBlending();
    ofDisableSmoothing();
    
    // draw frame
    ofSetColor(0, 0, 0, 204);
    ofRect(0, 0, width, height);
    
    // draw graph
    ofSetHexColor(0x00ffff);
    float scale = float(height - 14) / maxValue;
    ofSetLineWidth(2);
    for (int i = 0; i < fpsList.size(); i++) {
        float length = fpsList[i] * scale;
        if (length > height - 4) {
            length = height - 4;
        }
        int startX = width - 3;
        int startY = height - 2;
        ofLine(startX - i, startY, startX - i, startY - length);
    }
    
    // draw text
    ofSetColor(0, 0, 0, 204);
    ofRect(0, 0, width, 14);
    ofSetHexColor(0x00ffff);
    ofDrawBitmapString(ofToString(ofGetFrameRate(),0) + " fps", 2, 11);
    
    ofPopMatrix();
    ofPopStyle();
}
