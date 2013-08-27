#pragma once

#include "ofMain.h"

class Particle {
public:
	
    ofVec3f pos;
    ofVec3f vel;
    ofVec3f frc;
    float damping;
    
    Particle();
    virtual ~Particle(){};
    void resetForce();
    void addForce(float x, float y, float z);
    void addDampingForce();
    void setInitialCondition(float px, float py, float pz, float vx, float vy, float vz);
    void update();
    void draw();
    
protected:
private:
};