#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        int IMAGE_HEIGHT;
        int IMAGE_WIDTH;

		ofVideoGrabber vidGrabber;
		ofImage image;
		ofImage bwImage;
		ofImage bwBinaryImage;
		ofImage backgroundShot;
		ofImage substractedImage;
		ofImage binaryImage;
		ofImage bluredImage;
		ofImage newBackground;
		ofImage finalImage;
};
