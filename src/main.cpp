#include "ofMain.h"
#include "ofApp.h"

int main( ){
	FreeConsole();
	ofSetupOpenGL(500,360,OF_WINDOW);
	ofSetWindowTitle("OpenFrameworks Demo");
	ofSetBackgroundColor(ofColor::black);

	ofRunApp(new ofApp());
}