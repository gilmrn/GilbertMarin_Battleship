#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <ctime>

const int gridSize = 16;
int grid[gridSize][gridSize];


//creates 16x16 grid
void CreateGrid()
{
    for (size_t i = 0; i < gridSize; i++)
    {
        for (size_t k = 0; k < gridSize; k++)
        {
            grid[i][k] = 0;
        }
    }
}

//chooses 10 random spots on grid for ships
void RandomSpot()
{
    int randColumn;
    int randRow;
    int shipsPlaced = 0;

    while (shipsPlaced < 10)
    {
        randColumn = rand() % gridSize;
        randRow = rand() % gridSize;

        grid[randColumn][randRow] = 1;
        shipsPlaced++;
    }
}

//prints out grid, 0s for empty spot 1s for occupied spot
void PrintGrid()
{
    for (size_t i = 0; i < gridSize; i++)
    {
        for (size_t k = 0; k < gridSize; k++)
        {
            std::cout << grid[i][k] << " ";
        }

        std::cout << "\n";
    }
}

//scans board for ships and returns HIT, MISS, or NEAR MISS ---- is repeated until all ships are HIT
//for NEAR MISS, "scan" all nearby directions
void ScanGrid()
{
    std::cout << "\nRunning routine...\n";
    int shipsSunk = 0;

    while (shipsSunk < 10)
    {
        int column = rand() % gridSize;
        int row = rand() % gridSize;
        

        std::cout << "\nChecking grid at: " << column << "," << row;

        if (grid[column][row] == 1)
        {
            std::cout << "\nHIT\n";
            shipsSunk++;
        }
        else
        {
            //checks above
            if (grid[column][row--] == 1)
            {
                std::cout << "\nNEAR MISS\n";
            }
            //checks below
            else if (grid[column][row++] == 1)
            {
                std::cout << "\nNEAR MISS\n";
            }
            //checks left
            else if (grid[column--][row] == 1)
            {
                std::cout << "\nNEAR MISS\n";
            }
            //checks right
            else if (grid[column++][row] == 1)
            {
                std::cout << "\nNEAR MISS";
            }
            else
            {
                std::cout << "\nMISS\n";
            }
        }
    }
}

//runs game
void PlayGame()
{
    CreateGrid();

    srand(time(0));

    RandomSpot();

    PrintGrid();

    ScanGrid();
}


int main()
{
    PlayGame();
    return 0;
}