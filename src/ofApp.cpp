#include "ofApp.h"

void ofApp::setup(){
    
    // ARToolKit setup
    ofBackground(0, 0, 0);
    ofSetFrameRate(60);
    
    ofVec2f camSize(ofGetWidth(), ofGetHeight());
    
    cam.setup(camSize.x, camSize.y);
    art.setup(camSize, camSize);
    
    
    
    // Draw Triangle
    ofSetFrameRate(60);
    nTri = 1000;
    nVert= nTri * 3;
    float Rad = 55;
    float rad = 5;
    
    vertices.resize( nVert );
    for (int i=0; i<nTri; i++) {
        ofPoint center( ofRandom( -1, 1 ),
                       ofRandom( -1, 1 ),
                       ofRandom( -1, 1 ) );
        center.normalize();
        center *= Rad;
        for (int j=0; j<3; j++) {
            vertices[ i*3 + j ] =
            center + ofPoint( ofRandom( -rad, rad ),
                             ofRandom( -rad, rad ),
                             ofRandom( -rad, rad ));
        }
        
    }
    
    colors.resize( nTri );
    for (int i=0; i<nTri; i++) {
        colors[i] = ofColor( ofRandom( 0, 200 ), 7, 7 );
    }


}


void ofApp::update(){
    
    cam.update();
    if(cam.isFrameNew()){
        art.update(cam);
    }
}


void ofApp::draw(){
    
    ofEnableDepthTest();
    ofBackgroundGradient( ofColor( 255 ), ofColor( 128 ) );

    ofSetColor(7, 7, 7,205);
    cam.draw(0, 0);
    
    if(art.isFound()){
        art.beginAR();
        
        ofPushMatrix();
        
        ofTranslate( ofGetWidth()/2, ofGetHeight()/2, 0 );
        
        float time = ofGetElapsedTimef();
        float angle = time * 82;
        ofPopMatrix();
        
        ofRotate( angle, 0, 1, 0 );
        
        for (int i=0; i<nTri; i++) {
            
            ofSetColor( colors[i] );
            ofDrawTriangle( vertices[ i*3 ],
                           vertices[ i*3 + 1 ],
                           vertices[ i*3 + 2 ] );
            
        }
        
        ofPopMatrix();
        
        art.endAR();
    }
    
    
    art.drawDebug();
}