#pragma once
#include "ofMain.h"

class ofxStats {
    
public:
    ofxStats();
    void update();
    void draw();
    void mousePressed(int x, int y, int button);
    void setPosition(int left, int top);
    void setSize(int width, int height);
    void setMaxValue(float maxValue);
    void setLapTime(float lapTime);
    void setMode(int mode);
    
    int top;
    int left;
    int width;
    int height;
    float maxValue;
    int lapTime;
    int mode; //(0:fps, 1:ms)

private:
    deque<float> fpsList;
    deque<float> msList;
    int lastLap;
    float currentMs;
    float curretFps;
    float lastMs;
    float padding;
};