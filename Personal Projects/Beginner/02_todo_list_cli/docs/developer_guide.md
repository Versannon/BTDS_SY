# To-Do List (CLI) Developer Guide

## What Is Done

This scaffold defines a terminal-based task manager. The folder structure is ready for implementing task creation, listing, completion, and optional persistence.

## How It Is Done

`src/main.py` should become a menu-driven command-line interface. Tasks can be stored as dictionaries or simple objects, then serialized to a text or JSON file so the list survives between runs.

## Where It Will Be Used

This project is useful as a lightweight personal productivity tool and as practice for file handling, collections, and state management in Python.

## Developer Explanation

Model the task list independently from the menu logic. If task storage is isolated behind helper functions, migrating from a JSON file to SQLite later becomes straightforward.
