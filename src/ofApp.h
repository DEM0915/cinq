#include "ofMain.h"
#include "ofxARTPattern.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		
        ofxArtool5::PatternTracker art;
        ofVideoGrabber cam;
        
        vector<ofPoint> vertices;
        vector<ofColor> colors;
        int nTri;
        int nVert;
    

};
