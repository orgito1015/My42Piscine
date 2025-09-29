# Build a single exercise by name:
#   make EX=ft_atoi
# This expects: exercises/ft_atoi/ft_atoi.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
BIN_DIR = bin

.PHONY: help
help:
	@echo "Usage: make EX=<exercise_name>"
	@echo "Example: make EX=ft_atoi"

.PHONY: build
build:
	@if [ -z "$(EX)" ]; then \
		echo "Please provide EX=<exercise_name>"; exit 1; \
	fi
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) exercises/$(EX)/$(EX).c -o $(BIN_DIR)/$(EX)

.PHONY: run
run: build
	@./$(BIN_DIR)/$(EX)

.PHONY: clean
clean:
	rm -rf $(BIN_DIR)/*.o $(BIN_DIR)/* 2>/dev/null || true
