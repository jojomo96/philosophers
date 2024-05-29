# Compiler and Linker
CC := cc

# Compiler flags
CFLAGS := -Wall -Wextra -Werror

# Directories
OBJDIR := obj
LIB_DIR := lib
LIB_INCLUDES := $(LIB_DIR)/includes
SRC_DIR := src
HEADERS_DIR := include

# Additional source directories
SRC_DIRS := $(SRC_DIR) $(SRC_DIR)/utils

# Library name
NAME := philosophers

# Source files
PHILO_SRCS := main.c input_parsing.c static_variables.c free.c

# Include directory for headers
INCLUDES := -I$(LIB_INCLUDES) -I$(HEADERS_DIR)

# Object files
OBJS := $(patsubst %.c,$(OBJDIR)/%.o,$(PHILO_SRCS))

# Total number of objects (for progress bar)
TOTAL := $(words $(OBJS))
CURRENT := 0

# Colors
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
NC := \033[0m # No Color

define ASCII_HEADER

██████╗ ██╗  ██╗██╗██╗      ██████╗ ███████╗ ██████╗ ██████╗ ██╗  ██╗███████╗██████╗ ███████╗
██╔══██╗██║  ██║██║██║     ██╔═══██╗██╔════╝██╔═══██╗██╔══██╗██║  ██║██╔════╝██╔══██╗██╔════╝
██████╔╝███████║██║██║     ██║   ██║███████╗██║   ██║██████╔╝███████║█████╗  ██████╔╝███████╗
██╔═══╝ ██╔══██║██║██║     ██║   ██║╚════██║██║   ██║██╔═══╝ ██╔══██║██╔══╝  ██╔══██╗╚════██║
██║     ██║  ██║██║███████╗╚██████╔╝███████║╚██████╔╝██║     ██║  ██║███████╗██║  ██║███████║
╚═╝     ╚═╝  ╚═╝╚═╝╚══════╝ ╚═════╝ ╚══════╝╚═════╝ ╚═╝     ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚══════╝

endef
export ASCII_HEADER

# VPATH
vpath %.c $(SRC_DIRS)

# Create obj directory and compile the project
all: start_build $(NAME) #lib_make

start_build:
	@echo "$$ASCII_HEADER"
	@if [ -n "`find $(SRC_DIR) -name '*.c' -newer $(NAME) 2>/dev/null`" ] || [ ! -f "$(NAME)" ]; then \
		printf "$(YELLOW)Building philosophers project...$(NC)\n"; \
	else \
		printf "$(GREEN)Philosophers project is up to date. Nothing to build.$(NC)\n"; \
	fi

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@printf "$(GREEN)Philosophers project built.$(NC)\n"

$(OBJDIR)/%.o: %.c $(HEADERS_DIR)/*.h
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	$(eval CURRENT=$(shell echo $$(($(CURRENT) + 1))))
	$(eval PERCENT=$(shell echo $$((100 * $(CURRENT) / $(TOTAL)))))
	$(eval HASHES=$(shell echo $$((50 * $(CURRENT) / $(TOTAL)))))
	$(eval SPACES=$(shell echo $$((50 - $(HASHES)))))
	@printf "\r$(YELLOW)Progress: [$(NC)%-50s$(YELLOW)] %2d%%$(NC)" $$(printf '%*s' $(HASHES) | tr ' ' '#')$$(printf '%*s' $(SPACES) ' ') $(PERCENT)
	@echo -n
	@if [ $(CURRENT) -eq $(TOTAL) ]; then echo ""; fi

# Clean rule
clean: # lib_clean
	@printf "$(RED)Cleaning objects...$(NC)\n"
	@rm -rf $(OBJDIR)
	@printf "$(RED)Objects cleaned.$(NC)\n"

# Clean and remove executable rule
fclean: clean # lib_fclean
	@printf "$(RED)Removing philosophers project...$(NC)\n"
	@rm -f $(NAME)
	@printf "$(RED)Philosophers project removed.$(NC)\n"

# Rebuild rule
re: fclean all

# lib_make:
# 	@make -C $(LIB_DIR)

# lib_clean:
# 	@make -C $(LIB_DIR) clean

# lib_fclean:
# 	@make -C $(LIB_DIR) fclean

.PHONY: all clean fclean re start_build
