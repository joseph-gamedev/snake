#pragma once

#include <vector>
#include "Vector2.h"

struct BoardInfo
{
	int numRows;
	int numCols;
	Vector2 startPos;
	Vector2 gridSize;
	Vector2 offset;
	Vector2 margin;
};

template<typename T>
class Board
{
public:

	Board(BoardInfo& boardInfo, T defaultVal);

	Vector2 GetPosition(int row, int col);
	void GetGridPosition(/*in*/ const Vector2& position, /*out*/ int& row, /*out*/ int& col);

	T& Get(int row, int col);
	void Set(int row, int col, T value);

	void GetRandomFreeCell(int& row, int& col);
	bool HasFreeCell();

	int GetTotalRows();
	int GetTotalCols();

private:

	BoardInfo m_boardInfo;
	std::vector<std::vector<T>> m_cells;
	T m_DefaultValue;
};

template<typename T>
int Board<T>::GetTotalCols()
{
	return m_boardInfo.numCols;
}

template<typename T>
int Board<T>::GetTotalRows()
{
	return m_boardInfo.numRows;
}

template<typename T>
bool Board<T>::HasFreeCell()
{
	for (size_t rowId = 0; rowId < m_cells.size(); rowId++)
	{
		for (size_t colId = 0; colId < m_cells[0].size(); colId++)
		{
			if (m_cells[rowId][colId] == m_DefaultValue)
				return true;
		}
	}

	return false;
}

template<typename T>
void Board<T>::GetRandomFreeCell(int& row, int& col)
{
	if (!HasFreeCell())
	{
		row = -1;
		col = -1;
		return;
	}
	bool found = false;
	while (!found)
	{
		int max_rows = m_cells.size();
		if (max_rows > 0)
		{
			int max_cols = m_cells[0].size();
			if (max_cols > 0)
			{
				int randomRowId = rand() % m_cells.size();
				int randomColId = rand() % m_cells[0].size();
				if (m_cells[randomRowId][randomColId] == m_DefaultValue)
				{
					row = randomRowId;
					col = randomColId;
					found = true;
				}

			}
		}
	}
}

template<typename T>
void Board<T>::GetGridPosition(/*in*/ const Vector2& position, /*out*/ int& row, /*out*/ int& col)
{
	//Vector2 cellPosition = m_boardInfo.startPos + m_boardInfo.margin

}

template<typename T>
inline Board<T>::Board(BoardInfo & boardInfo, T defaultVal)
	:m_DefaultValue(defaultVal)
{
	m_boardInfo = boardInfo;
	m_cells.resize(boardInfo.numRows);
	for (size_t count = 0; count < boardInfo.numRows; count++)
	{
		m_cells[count].resize(boardInfo.numCols);
	}
}

template<typename T>
Vector2 Board<T>::GetPosition(int row, int col)
{
	Vector2 position = m_boardInfo.startPos + m_boardInfo.margin;

	//position += Vector3(row * (m_boardInfo.gridSize.X + m_boardInfo.offset.X), col * (m_boardInfo.gridSize.Y + m_boardInfo.offset.Y));
	//position += (m_boardInfo.gridSize * 0.5f);
}

template<typename T>
void Board<T>::Set(int row, int col, T value)
{
	assert(m_cells.size() > row && m_cells.size() > col);
	m_cells[row][col] = value;
}

template<typename T>
T& Board<T>::Get(int row, int col)
{
	assert(m_cells.size() > row && m_cells.size() > col);
	return &m_cells[row][col];
}

