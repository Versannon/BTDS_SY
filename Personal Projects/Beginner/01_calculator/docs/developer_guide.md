# Calculator Developer Guide

## What Is Done

This scaffold defines a basic command-line calculator project. The current setup establishes the project boundary, entry point, and a roadmap for implementing arithmetic operations.

## How It Is Done

The project starts from `src/main.py`, which will eventually collect user input, map an operator to a calculation routine, and print the result. For a beginner-friendly implementation, the cleanest approach is a loop-based CLI with separate functions for parsing numbers, choosing operations, and handling errors.

## Where It Will Be Used

This kind of project is mainly used for learning Python control flow, functions, and input validation. It is also useful as a simple terminal utility for quick calculations.

## Developer Explanation

Keep the arithmetic logic separate from the input loop. That makes the calculator easier to test and easier to extend later with features such as percentage, power, or memory operations.
