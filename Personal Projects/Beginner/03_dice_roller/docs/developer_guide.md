# Dice Roller Developer Guide

## What Is Done

This scaffold defines a random dice simulation app. The current project layout is ready for single-roll and repeated-roll behavior.

## How It Is Done

The implementation should rely on Python's `random` module to generate values inside the allowed dice range. The CLI should ask whether the user wants another roll and optionally support custom numbers of dice or sides.

## Where It Will Be Used

It is commonly used for beginner practice, tabletop game helpers, and simple randomization utilities.

## Developer Explanation

Keep randomness and presentation separate. A pure function that returns roll values is easier to test than embedding the random call directly inside a print-heavy loop.
