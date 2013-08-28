//
//  ofxStats.cpp
//  Created by Tadokoro Atsushi on 2013/08/28.
//

#include "ofxStats.h"

ofxStats::ofxStats():top(0), left(0), width(80), height(48), maxValue(120), lapTime(100), mode(0){
    lastLap = 0;
    lastMs = 0;
}

void ofxStats::update(){
    curretFps = ofGetFrameRate();
    currentMs = (ofGetElapsedTimef() - lastMs) * 1000;
    lastMs = ofGetElapsedTimef();
    
    if (int(ofGetElapsedTimef() * 1000) / lapTime > lastLap) {
        
        fpsList.push_front(curretFps);
        if (fpsList.size() > width - 5) {
            fpsList.pop_back();
        }
        
        msList.push_front(currentMs);
        if (msList.size() > width - 5) {
            msList.pop_back();
        }
        
        lastLap++;
    }
}

void ofxStats::draw(){
    ofPushStyle();
    ofPushMatrix();
    ofTranslate(left, top);
    ofEnableAlphaBlending();
    ofDisableSmoothing();
    
    ofSetColor(0, 0, 0, 204);
    ofRect(0, 0, width, height);
    float scale = float(height - 14) / maxValue;
    
    // draw graph
    ofSetLineWidth(2);
    if (mode == 0) { // FPS
        ofSetHexColor(0x00ffff);
        for (int i = 0; i < fpsList.size(); i++) {
            float length = fpsList[i] * scale;
            if (length > height - 4) {
                length = height - 4;
            }
            int startX = width - 3;
            int startY = height - 2;
            ofLine(startX - i, startY, startX - i, startY - length);
        }
        ofSetColor(0, 0, 0, 204);
        ofRect(0, 0, width, 14);
        ofSetHexColor(0x00ffff);
        ofDrawBitmapString(ofToString(curretFps, 0) + " fps", 2, 11);
    }
    if (mode == 1) { // MS
        ofSetHexColor(0x00ff00);
        for (int i = 0; i < msList.size(); i++) {
            float length = msList[i] * scale;
            if (length > height - 4) {
                length = height - 4;
            }
            int startX = width - 3;
            int startY = height - 2;
            ofLine(startX - i, startY, startX - i, startY - length);
        }
        ofSetColor(0, 0, 0, 204);
        ofRect(0, 0, width, 14);
        ofSetHexColor(0x00ff00);
        ofDrawBitmapString(ofToString(currentMs, 0) + " ms", 2, 11);
    }
    
    ofPopMatrix();
    ofPopStyle();
}

void ofxStats::mousePressed(int x, int y, int button){
    if (x > left && x < left+width && y > top && y < top+height) {
        (mode == 0)? mode = 1: mode = 0;
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
