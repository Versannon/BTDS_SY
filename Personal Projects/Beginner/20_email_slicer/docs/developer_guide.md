# Email Slicer Developer Guide

## What Is Done

This scaffold defines a parsing utility that breaks an email address into components such as username and domain.

## How It Is Done

The implementation should validate the presence of `@`, split the string into local and domain parts, and optionally break the domain into provider and top-level domain sections.

## Where It Will Be Used

It is useful in user onboarding flows, data-cleaning utilities, and beginner exercises involving string parsing.

## Developer Explanation

Keep the validation level realistic for the scope. Full RFC-compliant email parsing is far more complex than most beginner projects need, so start with practical validation rules.
