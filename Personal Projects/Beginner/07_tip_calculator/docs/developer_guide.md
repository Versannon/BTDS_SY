# Tip Calculator Developer Guide

## What Is Done

This scaffold defines a small billing utility that calculates tips and optionally splits the total across multiple people.

## How It Is Done

The app should collect the bill amount, tip percentage, and number of people, then compute derived values using simple arithmetic. The implementation is best kept in dedicated calculation helpers to avoid mixing math with input handling.

## Where It Will Be Used

It is useful in restaurants, group outings, and as a basic finance-related beginner project.

## Developer Explanation

Be careful with rounding and output formatting. If the calculation logic is isolated, it becomes easy to reuse in a GUI, web form, or mobile interface.
