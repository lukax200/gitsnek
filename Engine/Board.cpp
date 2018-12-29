#include "Board.h"

Board::Board(Graphics& gfx)
	:
	gfx( gfx )
{

}

void Board::DrawCell(const Location & loc, Color c)
{
	gfx.DrawRectDim((loc.x  * dimension) + xBoardShift, (loc.y * dimension) + yBoardShift, dimension - padding, dimension - padding, c);
}

int Board::GetGridWidth() const
{
	return width;
}

int Board::GetGridHeight() const
{
	return height;
}

bool Board::IsInsideBoard(const Location & loc) const
{
	return loc.x < width && loc.x >= 0
		&& loc.y < height && loc.y >= 0;
}

void Board::DrawBorder()
{
	gfx.DrawRectDim(xBoardShift - thickness - padding, yBoardShift - padding, thickness, (height * dimension) + thickness, BorderColor);
	gfx.DrawRectDim(xBoardShift - thickness - padding, yBoardShift - thickness - padding, (width * dimension) + padding + thickness, thickness, BorderColor);
	gfx.DrawRectDim(xBoardShift + (dimension * width), (yBoardShift - thickness - padding), thickness, (width * dimension) + padding + thickness + padding + 1, BorderColor);
	gfx.DrawRectDim(xBoardShift - thickness - padding, yBoardShift + (dimension * height), (width * dimension) + padding + thickness, thickness, BorderColor);
}
