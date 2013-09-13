#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(63);
    
    light.setup();
    light.setPosition(ofGetWidth()/2 - 100, ofGetHeight()/2 - 100, 400);
}

//--------------------------------------------------------------
void testApp::update(){
    stats.update();
}

//--------------------------------------------------------------
void testApp::draw(){
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
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    stats.mousePressed(x, y, button);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
