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
YELLOW="\033[33m"
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
[[ -n "$FILE" ]] || {
  echo -e "${RED}✘ Usage:${RESET} ./scripts/run_current.sh path/to/file.c"
  exit 1
}

[[ -f "$FILE" ]] || {
  echo -e "${RED}✘ File not found:${RESET} $FILE"
  exit 1
}

ROOT=$(git rev-parse --show-toplevel 2>/dev/null || pwd)
LIBFT="$ROOT/libft/src"
TEST_C="$LIBFT/test.c"

[[ -d "$LIBFT" ]] || {
  echo -e "${RED}✘ libft folder not found:${RESET} $LIBFT"
  exit 1
}

[[ -f "$TEST_C" ]] || {
  echo -e "${RED}✘ test.c not found:${RESET} $TEST_C"
  exit 1
}

# ---------- AUTO DEFINE (core fix) ----------
BASE=$(basename "$FILE")

# extrae nombre tras ft_ y quita .c
FUNC_NAME=$(echo "$BASE" | sed -E 's/^ft_(.*)\.c$/\U\1/')

# si no matchea el patrón ft_*.c
if [[ "$FUNC_NAME" == "$BASE" ]]; then
  echo -e "${YELLOW}⚠️ No ft_ pattern detected, using TEST_ALL${RESET}"
  DEFINES="-DTEST_ALL"
else
  DEFINES="-DTEST_${FUNC_NAME}"
fi

# ---------- SOURCES ----------
# Compila toda la lib para resolver dependencias (libft.c usa otras ft_*.c)
# Excluye test.c para no duplicar main.
SOURCES="$FILE"
# Si el archivo que editas no vive dentro de libft/ o no empieza por ft_,
# aún lo incluimos explícitamente (por si estás probando algo fuera).
EXTRA_SOURCE=""
if [[ "$FILE" != "$LIBFT/"* ]]; then
  EXTRA_SOURCE="$FILE"
else
  # si FILE es ft_*.c dentro de libft ya estará en SOURCES, pero incluirlo 2 veces rompe.
  # evitamos duplicado.
  if ! echo "$SOURCES" | tr ' ' '\n' | grep -qx "$FILE"; then
    EXTRA_SOURCE="$FILE"
  fi
fi

# ---------- HEADER ----------
echo -e "${BOLD}${BLUE}==[ 42 RUNNER ]======================${RESET}"
echo -e "${DIM}Root:${RESET} $ROOT"
echo -e "${DIM}File:${RESET} $FILE"
echo -e "${DIM}Test:${RESET} $TEST_C"
echo -e "${DIM}Defines:${RESET} ${DEFINES:-<none>}"
echo

# ---------- COMPILE ----------
echo -e "${BOLD}${BLUE}▶ COMPILING${RESET}"

START_COMPILE=$(date +%s%N)

(
  # Nota: compilamos (libft sources) + (extra current file si aplica) + test.c
  gcc $CFLAGS \
    -I"$LIBFT" \
    $DEFINES \
    $SOURCES \
    $EXTRA_SOURCE \
    "$TEST_C" \
    -o "$BIN"
) &

PID=$!
spinner "$PID"

# Si gcc falla, wait devuelve error -> set -e corta aquí (bien).
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

# Aquí NO queremos que set -e mate el script antes de imprimir FAIL,
# así que capturamos RC manualmente.
set +e
wait "$PID"
RC=$?
set -e

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
