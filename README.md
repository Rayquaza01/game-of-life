# game-of-life
An implementation of [Conway's Game of Life](https://en.wikipedia.org/wiki/Conway's_Game_of_Life)

Submission for HackYSU 2021

# How to Use

When you launch the application, you will see two numbers at the top, and and many red pixels.

The numbers represent the Viewport position (it is the coordinate of the cell in the top left corner).

The box of pixels (cells) at the bottom represent the cells in the Game of Life. Clicking a cell will turn it green. Green cells represent "living" cells, and red cells represent "dead" cells. Living and dead cells will change over time, following the [rules of Conway's Game of Life](https://en.wikipedia.org/wiki/Conway's_Game_of_Life#Rules):

1. Any live cell with two or three live neighbours survives.
2. Any dead cell with three live neighbours becomes a live cell.
3. All other live cells die in the next generation. Similarly, all other dead cells stay dead.

Pressing *ENTER* will move the cells to the next state.
Pressing *SPACE* will automatically move the cells to the next state every frame.
Using the *Arrow Keys* will move the viewport.

If you click a cell, it will toggle from dead to alive. This way, you can set the live tiles at runtime to play with it. If you give a file as a commandline argument, that will be used as the initial state. The file must be formatted with: 2 numbers representing the *width* and *height* of the game board, followed by (width * height) characters, either 0 or 1 representing dead or alive. See testfile.txt for an example.

Without an argument, the board will be 1000 by 1000.

# Acknowledgements

Using [olcPixelGameEngine](https://github.com/OneLoneCoder/olcPixelGameEngine/)
