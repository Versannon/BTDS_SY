# Password Generator Developer Guide

## What Is Done

This scaffold defines a password generation utility that will create randomized passwords based on configurable rules.

## How It Is Done

The implementation should combine one or more character pools, then use secure random selection to build the final password. In Python, the preferred module for actual password generation is `secrets`, not `random`.

## Where It Will Be Used

It is useful in security-focused utilities, onboarding scripts, and personal account setup workflows.

## Developer Explanation

Security matters here more than in most beginner projects. Use a cryptographically appropriate source such as `secrets.choice` if the generator is intended for real passwords.
