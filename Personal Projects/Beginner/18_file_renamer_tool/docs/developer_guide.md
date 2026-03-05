# File Renamer Tool Developer Guide

## What Is Done

This scaffold defines a utility for bulk renaming files inside a target directory.

## How It Is Done

The implementation should enumerate files with `pathlib` or `os`, generate the proposed new names, and then rename them after validation. A preview step is important before applying changes to disk.

## Where It Will Be Used

It is useful for organizing media, documents, exported assets, and repetitive administrative file naming tasks.

## Developer Explanation

This project modifies the filesystem, so safety checks matter. Validate duplicate target names and keep the rename logic deterministic before touching any files.
