# Quiz App Developer Guide

## What Is Done

This scaffold defines a quiz application that will ask users a series of questions and calculate a score.

## How It Is Done

`src/main.py` should drive a loop over question data stored in a list of dictionaries or objects. Each question should have prompt text, answer choices if needed, and the expected correct answer.

## Where It Will Be Used

This type of project is useful for educational tools, interview prep apps, and basic exam simulations.

## Developer Explanation

Separate question storage from quiz flow. That makes it easier to swap static questions for a JSON file, database, or API later without rewriting the scoring logic.
