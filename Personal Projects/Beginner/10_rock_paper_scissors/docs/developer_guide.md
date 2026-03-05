# Rock Paper Scissors Developer Guide

## What Is Done

This scaffold defines a terminal game where the user competes against randomized computer choices.

## How It Is Done

The project should compare two moves against a small ruleset. A mapping-based approach works well because each move can declare which move it defeats.

## Where It Will Be Used

This project is useful for learning conditionals, loops, and simple rule-based game design.

## Developer Explanation

Avoid long nested `if` blocks if possible. A compact rules map is easier to read, easier to test, and easier to extend if more move types are added later.
