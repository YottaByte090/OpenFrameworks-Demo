#include "ofApp.h"

int player_x = 200;
int player_y = 340;
int player_speed = 10;

int ball_x = 200;
int ball_x_speed = 3;
int ball_y = 275;
int ball_y_speed = -3;

int status = 0;

bool brick[7][15];
bool win = false;
bool isPlaying = false;

ofTrueTypeFont font;

void ofApp::setup() {
	font.load("font.ttf", 12);

	for (int y = 0; y < 7; y++) {
		for (int x = 0; x < 15; x++) {
			brick[y][x] = true;
		}
	}
}

void ofApp::update() {
	if (isPlaying) {
		if (ball_y - 6 > 360) {
			status = 1;
			isPlaying = false;
		}
		else {
			// 게임 오버가 아닐 때
			if (ball_x - 6 + ball_x_speed < 0) {
				// 공이 왼쪽 벽에 충돌했을 때
				ball_x_speed = -ball_x_speed;
			}
			else if (ball_x + 6 + ball_x_speed > 500) {
				// 공이 오른쪽 벽에 충돌했을 때
				ball_x_speed = -ball_x_speed;
			}
			else if (ball_y - 6 + ball_y_speed < 0) {
				// 공이 윗쪽 벽에 충돌했을 때
				ball_y_speed = -ball_y_speed;
			}
			else {
				ball_x += ball_x_speed;
				ball_y += ball_y_speed;
			}

			if ((ball_y + 6) > 340 && (ball_y - 6) < 350 && (ball_x + 6) > player_x && (ball_x - 6) < player_x + 100) {
				// 플레이어와 충돌했을 때
				ball_y_speed = -ball_y_speed;
			}
		}

		win = true;

		for (int y = 0; y < 7; y++) {
			for (int x = 0; x < 15; x++) {
				if (brick[y][x]) {
					win = false;
					if (/* 공이 벽돌의 X좌표 안에 있다면 */ (ball_x + 6) >((x * 33) + 3) && (ball_x - 6) < ((x + 1) * 33) && /* 공이 벽돌의 Y좌표 안에 있다면 */ (ball_y + 6) > ((y * 18) + 3) && (ball_y - 6) < ((y + 1) * 18)) {
						brick[y][x] = false;
						ball_y_speed = -ball_y_speed;

					}
				}
			}
		}
	}

	if (win == true) {
		status = 2;
		isPlaying = false;
	}
}

void ofApp::draw() {
	ofSetColor(ofColor::green);
	ofDrawRectangle(player_x, player_y, 100, 10);
	ofSetCircleResolution(100);
	ofDrawCircle(ball_x, ball_y, 6);

	for (int y = 0; y < 7; y++) {
		for (int x = 0; x < 15; x++) {
			if(brick[y][x]) ofDrawRectangle(3 + x * 33, 3 + y * 18, 30, 15);
		}
	}

	switch (status) {
		case 0:
			font.drawString("A : Move Left\nD : Move Right", 0, 310);
			break;
		case 1:
			font.drawString("Game Over\nPress any key to restart!", 0, 310);
			break;
		case 2:
			font.drawString("WINNVER WINNER CHICKEN DINNER!\nPress any key to restart!", 0, 310);
			break;
	}
}

void ofApp::keyPressed(int key) {
	if (!isPlaying) {
		ball_x = 200;
		ball_y = 275;
		ball_x_speed = 3;
		ball_y_speed = -3;
		player_x = 200;
		player_y = 340;
		status = 0;

		for (int y = 0; y < 7; y++) {
			for (int x = 0; x < 15; x++) {
				brick[y][x] = true;
			}
		}

		isPlaying = true;
	}
	switch (key) {
		case 'a':
			if (player_x - player_speed >= 0) player_x -= player_speed;
			break;
		case 'd':
			if ((player_x + 100) + player_speed <= 500) player_x += player_speed;
			break;
	}
}

void ofApp::keyReleased(int key){

}

void ofApp::mouseMoved(int x, int y ){

}

void ofApp::mouseDragged(int x, int y, int button){

}

void ofApp::mousePressed(int x, int y, int button){

}

void ofApp::mouseReleased(int x, int y, int button){

}

void ofApp::mouseEntered(int x, int y){

}

void ofApp::mouseExited(int x, int y){

}

void ofApp::windowResized(int w, int h){

}

void ofApp::gotMessage(ofMessage msg){

}

void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
