# Fraction
This is a C++ class named `Fraction` that represents a fraction of two integers. The class overloads several operators to perform arithmetic operations and comparisons with fractions and floating-point numbers.

## Operators Overloaded
The following operators are overloaded for the `Fraction` class:

1. `+` operator: Adds two fractions and returns their sum as another fraction in reduced form.
2. `-` operator: Subtracts two fractions and returns their difference as another fraction in reduced form.
3. `*` operator: Multiplies two fractions and returns their product as another fraction in reduced form.
4. `/` operator: Divides two fractions and returns their quotient as another fraction in reduced form.
5. `==` operator: Compares two fractions for equality and returns `true` or `false`.
6. Comparison operators (`>`, `<`, `>=`, `<=`) for comparing fractions.
7. `++` and `--` operators: Increment or decrement the fraction by 1, both in pre and post-fix form.
8. `<<` operator: Prints a fraction to an output stream in the format "numerator/denominator".
9. `>>` operator: Reads a fraction from an input stream by taking two integers as input.

## Usage Example
You can find usage examples of the `Fraction` class in [Demo.cpp](Demo.cpp).

## Testing
To run all the tests and ensure that all required files are working without errors, use the following command:

```bash
bash grade

##Note
When working with floating-point variables, ensure that up to 3 digits beyond the decimal point are used for accuracy in operations involving fractions and floats.
