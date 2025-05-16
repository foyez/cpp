#!/bin/bash

# Config
PUSH_SWAP=../push_swap/push_swap    # path to your compiled binary
CHECKER=../push_swap/checker        # optional: your checker binary
TESTS=10                            # number of tests per input size
MAX_OPS_100=700
MAX_OPS_500=5500

# Colors
GREEN="\033[0;32m"
RED="\033[0;31m"
RESET="\033[0m"

test_push_swap() {
    local size=$1
    local max_ops=$2

    echo "Testing $size numbers..."

    for ((i = 0; i < $TESTS; i++)); do
        # Generate unique random numbers
        ARGS=$(ruby -e "puts ((-($size/2))..(($size/2)-1)).to_a.shuffle.join(' ')")
        COUNT=$(echo "$ARGS" | wc -w)

        # Count operations
        OUTPUT=$($PUSH_SWAP $ARGS)
        OPS=$(echo "$OUTPUT" | wc -l)
        # echo -e "Args: $ARGS\nOps:\n$OUTPUT\nCount: $OPS\n"


        # Optional: verify sorted with checker
        if [ -f "$CHECKER" ]; then
            RESULT=$(echo "$ARGS" | $PUSH_SWAP $ARGS | $CHECKER $ARGS)
        else
            RESULT="Not Checked"
        fi

        # Display result
        if [ "$OPS" -le "$max_ops" ]; then
            printf "✅ Test $((i+1)): ${GREEN}$OPS ops${RESET} | Result: $RESULT\n"
        else
            printf "❌ Test $((i+1)): ${RED}$OPS ops${RESET} | Result: $RESULT\n"
        fi
        # printf "Args: %s | Total: %d\n" "$ARGS" "$COUNT"
    done
    echo ""
}

# Run for specific sizes
test_push_swap 2 2
test_push_swap 3 3
test_push_swap 5 12
test_push_swap 100 $MAX_OPS_100
test_push_swap 500 $MAX_OPS_500
