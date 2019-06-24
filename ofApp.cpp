#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(3);
	ofEnableDepthTest();

	this->font.loadFont("fonts/Kazesawa-Bold.ttf", 60, true, true, true);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	for (int x = -120; x <= 120; x += 60) {

		for (int y = -120; y <= 120; y += 60) {

			for (int z = -50; z <= 50; z += 10) {

				char noise_char = ofMap(ofNoise(x * 0.005, y * 0.005, z * 0.005 + ofGetFrameNum() * 0.005), 0, 1, 'A', 'Z');

				ofPushMatrix();
				ofTranslate(x, y, z);

				auto path = font.getCharacterAsPoints(noise_char, true, false);
				auto outline = path.getOutline();

				ofFill();
				ofSetColor(239);
				ofBeginShape();
				for (int line_index = 0; line_index < outline.size(); line_index++) {

					if (line_index != 0) { ofNextContour(true); }

					auto vertices = outline[line_index].getVertices();
					ofVertices(vertices);
				}
				ofEndShape(true);

				ofNoFill();
				ofSetColor(39);
				ofBeginShape();
				for (int line_index = 0; line_index < outline.size(); line_index++) {

					if (line_index != 0) { ofNextContour(true); }

					auto vertices = outline[line_index].getVertices();
					ofVertices(vertices);
				}
				ofEndShape(true);

				ofPopMatrix();
			}
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}