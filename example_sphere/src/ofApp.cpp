#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(63);
    
    light.setup();
    light.setPosition(ofGetWidth()/2 - 100, ofGetHeight()/2 - 100, 400);
}

//--------------------------------------------------------------
void ofApp::update(){
    stats.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    // sphere animation
    ofPushStyle();
    ofEnableDepthTest();
    ofEnableLighting();
    light.enable();
    ofSetHexColor(0xcccccc);
    ofSpherePrimitive sphere;
    sphere.setRadius(sin(ofGetElapsedTimef() * 4.0) * 100 + 200);
    sphere.setResolution(mouseX / 2.0);
    sphere.setPosition(ofGetWidth()/2, ofGetHeight()/2, 0);
    sphere.drawWireframe();
    ofDisableLighting();
    ofDisableDepthTest();
    ofPopStyle();
    
    stats.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    stats.mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
