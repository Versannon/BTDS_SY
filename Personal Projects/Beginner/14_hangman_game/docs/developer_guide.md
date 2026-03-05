# Hangman Game Developer Guide

## What Is Done

This scaffold defines a letter-guessing game with hidden-word state, mistake tracking, and round completion logic.

## How It Is Done

The program should store a target word, a set of guessed letters, and a remaining-attempt count. Each turn validates a user guess, updates the revealed word state, and checks for win or loss conditions.

## Where It Will Be Used

It is useful for learning collections, string handling, and simple game-state modeling.

## Developer Explanation

Use sets for guessed letters and keep the target word immutable. That produces cleaner logic than repeatedly modifying the underlying word string during play.
