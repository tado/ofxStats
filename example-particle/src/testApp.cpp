#include "testApp.h"

void testApp::setup(){
    // init screen
    ofSetVerticalSync(true);
    ofBackground(63);
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    img.loadImage("particle32.png");
    
    // create ofxStats object
    stats = new ofxStats();

    // set stats position and size
    stats->setPosition(5, 5);
    stats->setSize(120, 50);
    // set maximun varlue of graph
    stats->setMaxValue(110);
    // set lap time to update graph (milliseconds)
    stats->setLapTime(100);
}

void testApp::update(){
    // update partciles
    for (int i = 0; i < particles.size(); i++) {
        particles[i].resetForce();
        particles[i].addDampingForce();
        particles[i].update();
    }
    
    // update stats
    stats->update();
}

void testApp::draw(){
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

void testApp::keyPressed  (int key){
    if (key == 'c') {
        particles.clear();
    }
    if (key == 'd') {
        particles.pop_back();
    }
    if (key == 'f') {
        ofToggleFullscreen();
    }
}

void testApp::keyReleased  (int key){
}

void testApp::mouseMoved(int x, int y ){
}

void testApp::mouseDragged(int x, int y, int button){
    for (int i = 0; i < 4; i++) {
        Particle myParticle;
        float vx = ofRandom(-1, 1);
        float vy = ofRandom(-1, 1);
        float vz = ofRandom(3, 5);
        myParticle.setInitialCondition(x, y, 0, vx, vy, vz);
        particles.push_back(myParticle);
    }
}

void testApp::mousePressed(int x, int y, int button){
    stats->mousePressed(x, y, button);
}

void testApp::mouseReleased(){
}