#include "ofApp.h"

void ofApp::setup(){
    // init screen
    ofBackground(63);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    img.loadImage("particle32.png");
    
    // create ofxStats object
    stats = new ofxStats();

    // set stats position and size
    stats->setPosition(5, 5);
    stats->setSize(120, 50);
    // set maximun varlue of graph
    stats->setMaxValue(120);
    // set lap time to update graph (milliseconds)
    stats->setLapTime(100);
}

void ofApp::update(){
    // update partciles
    for (int i = 0; i < particles.size(); i++) {
        particles[i].resetForce();
        particles[i].addDampingForce();
        particles[i].update();
    }
    
    // update stats
    stats->update();
}

void ofApp::draw(){
    // draw particle
    ofSetColor(255, 255, 255);
    for (int i = 0; i < particles.size(); i++){
        float posx = particles[i].pos.x - 16;
        float posy = particles[i].pos.y - 16;
        float posz = particles[i].pos.z;
        img.draw(posx, posy, posz);
    }
    
    // draw stats
    stats->draw();
    
    // draw help
    ofSetColor(255);
    ofDrawBitmapString("[c]: clear, [d]: pop_back, [f]: toggle fullscreen, particle num = " + ofToString(particles.size(),0), 5, ofGetHeight()-10);
}

void ofApp::keyPressed  (int key){
    if (key == 'c') {
        particles.clear();
    }
    if (key == 'd') {
        for (int i = 0; i < 4; i++) {
            if (particles.size() > 0) {
                particles.pop_back();
            }
        }
    }
    if (key == 'f') {
        ofToggleFullscreen();
    }
}

void ofApp::keyReleased  (int key){
}

void ofApp::mouseMoved(int x, int y ){
}

void ofApp::mouseDragged(int x, int y, int button){
    for (int i = 0; i < 4; i++) {
        Particle myParticle;
        float vx = ofRandom(-1, 1);
        float vy = ofRandom(-1, 1);
        float vz = ofRandom(3, 5);
        myParticle.setInitialCondition(x, y, 0, vx, vy, vz);
        particles.push_back(myParticle);
    }
}

void ofApp::mousePressed(int x, int y, int button){
    // click to change mode (fps / ms)
    stats->mousePressed(x, y, button);
}

void ofApp::mouseReleased(){
}