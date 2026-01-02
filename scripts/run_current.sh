#!/usr/bin/env bash
set -e

# ─────────────────────────────────────────────
#  Campus 42 — run_current.sh
#  gcc + test.c + 8-bit output + timings
# ─────────────────────────────────────────────

# ---------- CONFIG ----------
CFLAGS="-Wall -Wextra -Werror"
BIN="/tmp/test_bin"

# ---------- COLORS (8-bit vibe) ----------
BOLD="\033[1m"
DIM="\033[2m"
RED="\033[31m"
GREEN="\033[32m"
BLUE="\033[34m"
CYAN="\033[36m"
RESET="\033[0m"

# ---------- SPINNER ----------
spinner() {
  local pid=$1
  local spin='|/-\'
  local i=0

  while kill -0 "$pid" 2>/dev/null; do
    i=$(((i + 1) % 4))
    printf "\r${CYAN}[%c]${RESET} " "${spin:$i:1}"
    sleep 0.08
  done
  printf "\r    \r"
}

# ---------- ARGS ----------
FILE="$1"
[[ -f "$FILE" ]] || {
  echo -e "${RED}✘ File not found${RESET}"
  exit 1
}

ROOT=$(git rev-parse --show-toplevel 2>/dev/null || pwd)
LIBFT="$ROOT/libft"
TEST_C="$LIBFT/test.c"

[[ -f "$TEST_C" ]] || {
  echo -e "${RED}✘ test.c not found in libft/${RESET}"
  exit 1
}

# ---------- HEADER ----------
echo -e "${BOLD}${BLUE}==[ 42 RUNNER ]======================${RESET}"
echo -e "${DIM}File:${RESET} $FILE"
echo -e "${DIM}Test:${RESET} $TEST_C"
echo

# ---------- COMPILE ----------
echo -e "${BOLD}${BLUE}▶ COMPILING${RESET}"

START_COMPILE=$(date +%s%N)

(
  gcc $CFLAGS \
    -I"$LIBFT" \
    "$FILE" \
    "$TEST_C" \
    -o "$BIN"
) &

PID=$!
spinner "$PID"
wait "$PID"

END_COMPILE=$(date +%s%N)
COMPILE_MS=$(((END_COMPILE - START_COMPILE) / 1000000))

echo -e "${GREEN}✔ COMPILED${RESET} (${COMPILE_MS} ms)"
echo

# ---------- RUN ----------
echo -e "${BOLD}${BLUE}▶ RUNNING TESTS${RESET}"

START_RUN=$(date +%s%N)

(
  "$BIN"
) &

PID=$!
spinner "$PID"
wait "$PID"
RC=$?

END_RUN=$(date +%s%N)
RUN_MS=$(((END_RUN - START_RUN) / 1000000))

echo
if [[ $RC -eq 0 ]]; then
  echo -e "${GREEN}✔ TESTS PASSED${RESET} (${RUN_MS} ms)"
else
  echo -e "${RED}✘ TESTS FAILED${RESET} (${RUN_MS} ms)"
fi

echo -e "${DIM}=====================================${RESET}"
exit "$RC"
