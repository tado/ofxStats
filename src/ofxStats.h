#pragma once
#include "ofMain.h"

class ofxStats {
    
public:
    ofxStats();
    void update();
    void draw();
    void setPosition(float top, float left);
    void setSize(float width, float height);
    
    float top;
    float left;
    float width;
    float height;
    float maxValue;
    
    deque<float> fpsList;
    
private:
    int lastTime;
};