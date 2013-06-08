#include <stdio.h>

void printTable(short* table);
void underpopulationRule(short* table);
void stayAliveRule(short* table);
void overcrowdingRule(short* table);
void reproductionRule(short* table);
short countNeighbours(short* ref, short* rowStart, short* gridStart);
short checkUp(short* ref);
short checkDown(short* ref);
short checkLeft(short* ref);
short checkRight(short* ref);

#define SIZE 20

int main()
{
	// Initialise the table
	short table[SIZE][SIZE];

	// Create pointer array. Each element is a pointer to the first element in each row
	short* rowStarts[SIZE];

	for(int i=0; i<SIZE; i++)
	{
		rowStarts[i] = &table[i][0];

		for(int j=0; j<SIZE; j++)
		{
			table[i][j] = 0;
		}
	}

	// First plant the seed, in this case a Block
	table[0][0] = 1;
	table[0][1] = 1;
	table[1][0] = 1;
	table[1][1] = 1;

	// Now for the main loop. First print, then apply the GOL rules
	for(int i=0; i<2; i++)
	{
		printTable(&table[0][0]);

		// Apply the Game of Life rules

		// Iterate over each row
		for(int i=0; i<SIZE; i++)
		{
			// And over each element in that row
			for(int j=0; j<SIZE; j++)
			{
				// Process 'live' rules, i.e. those which apply to live cells
				if(table[i][j] == 1)
				{
					printf("Processing (%d, %d) - LIVE\n",i,j);

					// 1: Underpopulation rule
					if(countNeighbours(&table[i][j], &table[i][0], &table[0][0]) < 2)
					{
						table[i][j] = 0;
					}

					// 2: Stay-alive rule
					if(countNeighbours(&table[i][j], &table[i][0], &table[0][0]) == 2 || countNeighbours(&table[i][j], &table[i][0], &table[0][0]) == 3)
					{
						table[i][j] = 1; // DON'T THINK WE NEED THIS
					}

					// 3: Overcrowding rule
					if(countNeighbours(&table[i][j], &table[i][0], &table[0][0]) > 3)
					{
						table[i][j] = 0;
					}
				}
				// Process 'dead' rules
				else
				{
					printf("Processing (%d, %d) - DEAD\n",i,j);
					// 4: Reproduction rule
					if(countNeighbours(&table[i][j], &table[i][0], &table[0][0]) == 3)
					{
						table[i][j] = 1;
					}
				}
			}
		}

		printf("\n\n");
	}
}

/* This counts the number of live neighbours a given cell has, defined by 
the pointer 'ref'. This also requires the pointer 'start', which is the 
top-most left-most element to decide the location of the element within the 
larger grid */
short countNeighbours(short* ref, short* rowStart, short* gridStart)
{
	short neighbours = 0;

	// Check 'up' - first confirm if not in top row
	if(rowStart != gridStart)
	{
		neighbours += checkUp(ref);
	}

	// Check 'down' - first confirm if not in bottom row
	if(rowStart != (gridStart + SIZE*(SIZE-1)))
	{
		neighbours += checkDown(ref);
	}

	// Check 'left' - first confirm not in leftmost column
	if(ref != rowStart)
	{
		neighbours += checkLeft(ref);
	}

	// Check 'right' - first confirm not in rightmost column
	if(ref != (rowStart + (SIZE - 1)))
	{
		neighbours += checkRight(ref);
	}

	return neighbours;
}

/* Checks 'up' from the given grid position. Trusts that the calling function
'countNeighbours' has passed to it a legal position */
short checkUp(short* ref)
{
	return *(ref - SIZE);
}

short checkDown(short* ref)
{
	return *(ref + SIZE);
}

short checkLeft(short* ref)
{
	return *(ref - 1);
}

short checkRight(short* ref)
{
	return *(ref + 1);
}

/* Due to the way these 2D arrays are held in memory, this iterates through 
SIZE * SIZE addresses in memory, and carriage returns every time it is 
divisible by SIZE, hence forming the grid.*/
void printTable(short* table)
{
	for(int i=0; i<SIZE*SIZE; i++)
	{
		// Carriage return at end of row if necessary
		if(i % SIZE == 0)
		{
			printf("\n");
		}

		// Print array element
		printf("%d ",*(table + i));

	}
}
