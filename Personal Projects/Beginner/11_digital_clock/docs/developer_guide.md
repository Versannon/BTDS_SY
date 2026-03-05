# Digital Clock Developer Guide

## What Is Done

This scaffold defines a live clock application that repeatedly displays the current system time.

## How It Is Done

The implementation should poll the system clock with Python's `datetime` module and refresh output on a timed loop. A terminal version can redraw the same line, while a GUI version can update a label widget.

## Where It Will Be Used

It is useful for beginner practice with time APIs, UI refresh loops, and display formatting.

## Developer Explanation

The key design point is separating time retrieval from rendering. That makes it easier to move between CLI, Tkinter, and web implementations without changing the time source logic.
