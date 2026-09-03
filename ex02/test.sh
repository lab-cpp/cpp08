#!/bin/bash
# ─────────────────────────────────────────────────────────────────────────────
# test.sh – Functional tests for ex02
# ─────────────────────────────────────────────────────────────────────────────

GREEN='\033[0;32m'
RED='\033[0;31m'
BOLD='\033[1m'
NC='\033[0m'

BINARY="./mutantstack"

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
echo -e "${BOLD}  Testing ex02${NC}"
echo -e "${BOLD}══════════════════════════════════════════${NC}\n"

make > /dev/null 2>&1
if [ ! -f "$BINARY" ]; then
    echo -e "${RED}Build failed – cannot run tests.${NC}"
    exit 1
fi

EXPECTED_OUTPUT="--- 1. Testing MutantStack (Subject Test) ---
Top: 17
Size: 1
MutantStack Iteration: 5 3 5 737 0 

--- 2. Testing std::list (Control Group) ---
Back (Top): 17
Size: 1
std::list Iteration: 5 3 5 737 0"

ACTUAL=$($BINARY 2>&1 | sed 's/[[:space:]]*$//') # Strip trailing spaces for easy comparison

# Strip trailing spaces from expected output just to be safe
EXPECTED_OUTPUT=$(echo "$EXPECTED_OUTPUT" | sed 's/[[:space:]]*$//')

assert_eq "MutantStack precisely mimics the behavior of std::list" "$EXPECTED_OUTPUT" "$ACTUAL"

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
