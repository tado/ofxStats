#include "Particle.h"

Particle::Particle(){
    setInitialCondition(0,0,0,0,0,0);
    damping = 0.01f;
}

void Particle::resetForce(){
    frc.set(0,0);
}

void Particle::addForce(float x, float y, float z){
    frc = frc + ofVec3f(x, y, z);
}

void Particle::addDampingForce(){
    frc = frc - vel * damping;
}

void Particle::setInitialCondition(float px, float py, float pz, float vx, float vy, float vz){
    pos.set(px,py,pz);
    vel.set(vx,vy,vz);
}

void Particle::update(){
    vel = vel + frc;
    pos = pos + vel;
}

void Particle::draw(){
    ofCircle(pos.x, pos.y, 3);
}

