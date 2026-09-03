#!/bin/bash
# ─────────────────────────────────────────────────────────────────────────────
# test.sh – Functional tests for ex01
# ─────────────────────────────────────────────────────────────────────────────

GREEN='\033[0;32m'
RED='\033[0;31m'
BOLD='\033[1m'
NC='\033[0m'

BINARY="./span"

PASS=0
FAIL=0

assert_eq() {
    local description="$1"
    local expected="$2"
    local actual="$3"

    if [ "$actual" = "$expected" ]; then
        echo -e "${GREEN}[OK]${NC} $description"
        PASS=$((PASS + 1))
    else
        echo -e "${RED}[KO]${NC} $description"
        echo -e "   ${BOLD}Expected:${NC}\n$expected"
        echo -e "   ${BOLD}Got:     ${NC}\n$actual"
        FAIL=$((FAIL + 1))
    fi
}

echo -e "\n${BOLD}══════════════════════════════════════════${NC}"
echo -e "${BOLD}  Testing ex01${NC}"
echo -e "${BOLD}══════════════════════════════════════════${NC}\n"

make > /dev/null 2>&1
if [ ! -f "$BINARY" ]; then
    echo -e "${RED}Build failed – cannot run tests.${NC}"
    exit 1
fi

EXPECTED_OUTPUT="--- Testing Subject Example ---
2
14

--- Testing Exception: Full Span ---
Span is already full!

--- Testing Exception: Not Enough Numbers ---
Not enough numbers to find a span!

--- Testing 10,000 Numbers (Range Iterator) ---
Shortest span (should be 3): 3
Longest span (should be 29997): 29997"

ACTUAL=$($BINARY 2>&1)

assert_eq "Span perfectly tracks min/max, throws exceptions, and handles 10k numbers instantly" "$EXPECTED_OUTPUT" "$ACTUAL"

echo ""
echo -e "${BOLD}══════════════════════════════════════════${NC}"
TOTAL=$((PASS + FAIL))
if [ "$FAIL" -eq 0 ]; then
    echo -e "${GREEN}${BOLD}  ✔ $PASS/$TOTAL tests passed${NC}"
else
    echo -e "${RED}${BOLD}  ✘ $FAIL/$TOTAL tests FAILED${NC}"
fi
echo -e "${BOLD}══════════════════════════════════════════${NC}\n"

[ "$FAIL" -eq 0 ]
