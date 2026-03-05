# Number Guessing Game Developer Guide

## What Is Done

This scaffold defines a game where the user repeatedly guesses a hidden random number. The project is structured for validation, hinting, and attempt tracking.

## How It Is Done

The game should generate a target with `random.randint`, collect guesses from the user, and compare each guess to the target. The main loop continues until the user wins or chooses to stop.

## Where It Will Be Used

This project is mostly used for learning loops, conditionals, random number generation, and basic game-state handling.

## Developer Explanation

Store the target number, attempt count, and difficulty settings as explicit state variables. That keeps the control flow predictable and makes difficulty modes easy to add later.
