#pragma once
#include "ofMain.h"

class ofxStats {
    
public:
    ofxStats();
    void update();
    void draw();
    void setPosition(float top, float left);
    void setSize(float width, float height);
    void setMaxValue(float maxValue);
    void setLapTime(float lapTime);
    
    int lastLap;
    float top;
    float left;
    float width;
    float height;
    float maxValue;
    int lapTime;

private:
    deque<float> fpsList;
};