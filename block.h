#pragma once

class Block {
	private:
		int x;
		int y;
		int width;
		int hegiht;
		bool isBroken;
	public:
		void setX(int x);
		int getX();
		void setY(int y);
		int getY();
		void setWidth(int width);
		int getWidth();
		void setHeight(int height);
		int getHeight();
		void setBroken(bool isBroken);
		bool isBroken();
};