# Tic Tac Toe (C)

A terminal-based Tic Tac Toe game written in C, with an emphasis on safe input handling, buffer management, and clean win-condition logic.

The program is designed to behave predictably even with malformed or excessive user input, and maintains a clear, structured game flow.

---

## Features

- Two-player gameplay (X vs O)
- Custom player names
- Illegal move prevention
- Full input buffer clearing
- Accurate win and draw detection
- Board re-rendered after every move

---

## Build and Run

### Compile
```C
gcc Tic_Tac_Toe.c
```

### Run (Windows)

```Windows
./a.exe
```

### Run (macOS / Linux)

```macOS / Linux
./a.out
```

## Game Rules

- Players take turns placing their mark

- Player 1 uses X, Player 2 uses O

- Valid positions range from 1 to 9

- Occupied positions cannot be reused

- Three aligned marks win the game

- If the board fills without a winner, the game ends in a draw

## Board Layout

    1 | 2 | 3
    ---+---+---
    4 | 5 | 6
    ---+---+---
    7 | 8 | 9

## Input Handling

- Only the first character of input is evaluated

- Additional characters are discarded

- Invalid inputs are rejected and re-prompted

- Input buffer is explicitly cleared after each read
  
## Win Detection

All possible winning combinations (horizontal, vertical, diagonal) are checked using a predefined index mapping to ensure consistent and reliable result detection.

## File Structure

Tic_Tac_Toe.c — main source file

## Notes

This project prioritizes correctness, controlled input handling, and readable C code over shortcuts or undefined behavior.