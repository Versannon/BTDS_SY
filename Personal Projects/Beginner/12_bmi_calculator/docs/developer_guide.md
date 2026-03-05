# BMI Calculator Developer Guide

## What Is Done

This scaffold defines a health-related calculator that computes BMI and classifies the result.

## How It Is Done

The program should collect height and weight, convert them to a consistent unit system if needed, then calculate `weight / height^2`. The output should include the BMI value and a category label such as underweight, normal, overweight, or obese.

## Where It Will Be Used

It is useful in health tracking apps, fitness tools, and beginner projects involving formulas and categorized output.

## Developer Explanation

Keep unit conversion explicit and validated. Mixing centimeters, meters, kilograms, and pounds without a clean conversion path is the easiest way to introduce incorrect results.
