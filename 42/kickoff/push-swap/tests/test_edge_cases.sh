#!/bin/bash

PUSH_SWAP=../push_swap/push_swap

test_edge_cases() {
  local msg="$1"
  local args="${@:2}"
  
  OUTPUT=$($PUSH_SWAP "${args[@]}" 2>&1 | tr '\n' ' ')

  if [ "$OUTPUT" != "Error " ]; then
    printf "✅ Test: $msg\n"
    printf "\tARGS: \"$args\" | Output: $OUTPUT\n"
  else
    printf "❌ Test: $msg\n"
    printf "\tARGS: \"$args\" | Output: $OUTPUT\n"
  fi
}

test_edge_cases "Duplicate input:" 3 1 2 2
test_edge_cases "Overflow input:" 2147483648
test_edge_cases "Underflow input:" -2147483649
test_edge_cases "Non-integer input:" 1 a 3
test_edge_cases "Empty input:" ""
test_edge_cases "Only spaces input:" "   "
test_edge_cases "Invalid input:" "+ - 2"
test_edge_cases "Invalid input:" 123abc

test_edge_cases "Already sorted:" 1 2 3 4 5
test_edge_cases "Negative values:" "  -3  -1 -2 0  "
test_edge_cases "Valid input:" 1 "4 0"
test_edge_cases "Single element:" "0"