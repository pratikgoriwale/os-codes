#!/bin/bash
echo "Samarth Khorate SE AIDS A2 [22539]"
# Function to perform addition
addition() {
    result=$(echo "$1 + $2" | bc -l)
    echo "Result: $result"
}

# Function to perform subtraction
subtraction() {
    result=$(echo "$1 - $2" | bc -l)
    echo "Result: $result"
}

# Function to perform multiplication
multiplication() {
    result=$(echo "$1 * $2" | bc -l)
    echo "Result: $result"
}

# Function to perform division
division() {
    if [ "$2" -ne 0 ]; then
        result=$(echo "$1 / $2" | bc -l)
        echo "Result: $result"
    else
        echo "Error: Division by zero is not allowed."
    fi
}

# Main program

echo "Enter an expression (e.g., 5 + 3):"
read expression

# Split the expression into operands and operator
IFS=' ' read -r num1 operator num2 <<< "$expression"

case "$operator" in
    "+")
        addition "$num1" "$num2"
        ;;
    "-")
        subtraction "$num1" "$num2"
        ;;
    "*")
        multiplication "$num1" "$num2"
        ;;
    "/")
        division "$num1" "$num2"
        ;;
    *)
        echo "Error: Invalid operator."
        ;;
esac