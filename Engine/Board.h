#pragma once
#include "Graphics.h"
#include "Location.h"
#include <assert.h>

class Board
{
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c);
	int GetGridWidth() const;
	int GetGridHeight() const;
	bool IsInsideBoard(const Location& loc) const;
	void DrawBorder();
private:
	static constexpr int dimension = 20;
	int width = 25;
	int height = 25;
	Graphics& gfx;
	int xBoardShift = 40;
	int yBoardShift = 40;
	int thickness = 5;
	int padding = 4;
	Color BorderColor = Colors::LightGray;

};