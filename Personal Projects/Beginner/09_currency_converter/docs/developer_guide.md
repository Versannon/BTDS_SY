# Currency Converter Developer Guide

## What Is Done

This scaffold defines a converter that translates a monetary amount between currencies.

## How It Is Done

The implementation should normalize currencies to codes such as `USD`, `INR`, or `EUR`, then multiply the input amount by an exchange rate. For a beginner version, static rates are acceptable before moving to an external API.

## Where It Will Be Used

It is useful in travel planning, expense estimation, and basic financial utility tooling.

## Developer Explanation

Abstract the exchange-rate source behind a simple function. That keeps the CLI logic stable whether rates are hardcoded, read from a file, or fetched from an API.
