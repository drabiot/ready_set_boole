# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tchartie <tchartie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/18 17:57:42 by tchartie          #+#    #+#              #
#    Updated: 2026/09/09 14:05:43 by tchartie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#============ NAME ============#

NAME				=	boollib.a
NAME_TESTER			=	tester

#========= COMPILER ===========#

CC					=	c++

#=========== FLAGS ============#

CFLAGS				=	-Wall -Wextra -Werror -g -std=c++17

#=========== COLOR ============#

BASE_COLOR			=	\033[0;39m
GRAY				=	\033[0;90m
RED					=	\033[0;91m
GREEN				=	\033[0;92m
YELLOW				=	\033[0;93m
BLUE				=	\033[0;94m
MAGENTA				=	\033[0;95m
CYAN				=	\033[0;96m
WHITE				=	\033[0;97m

#========== SOURCES ===========#

INC_DIR				=	./inc
INC_FLAGS			=	-I$(INC_DIR)

DIR					=	src/
NAMES				=	adder.cpp \
						multiplier.cpp \
						gray_code.cpp \
						eval_formula.cpp \
						print_truth_table.cpp \
						negation_normal_form.cpp \
						conjonctive_normal_form.cpp \
						sat.cpp \
						powerset.cpp \
						eval_set.cpp \
						map.cpp \
						reverse_map.cpp

DIR_TESTER			=	tests/
NAMES_TESTER		=	main.cpp \
						ex00Tester.cpp \
						ex01Tester.cpp \
						ex02Tester.cpp \
						ex03Tester.cpp \
						ex04Tester.cpp \
						ex05Tester.cpp \
						ex06Tester.cpp \
						ex07Tester.cpp \
						ex08Tester.cpp \
						ex09Tester.cpp \
						ex10Tester.cpp \
						ex11Tester.cpp

#========== OBJECTS ===========#

OBJ_DIR				=   obj/
OBJ					=   $(addprefix $(OBJ_DIR), $(NAMES:.cpp=.o))

OBJ_TESTER_DIR		=	obj_tester/
OBJ_TESTER			=	$(addprefix $(OBJ_TESTER_DIR), $(NAMES_TESTER:.cpp=.o))

#=========== RULES ============#

all:        $(NAME_TESTER)

lib:		$(NAME)


$(NAME):				$(OBJ)
	@ar -rcs $(NAME) $(OBJ)
	@echo "$(GREEN)Boollib archive successfully compiled! $(BASE_COLOR)"

$(NAME_TESTER):			$(NAME) $(OBJ_TESTER)
	@$(CC) $(CFLAGS) $(INC_FLAGS) $(OBJ_TESTER) $(NAME) -o $(NAME_TESTER)
	@echo "$(GREEN)Tester successfully compiled! $(BASE_COLOR)"

$(OBJ_DIR)%.o:			$(DIR)%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiling lib: $< $(BASE_COLOR)"

$(OBJ_TESTER_DIR)%.o:	$(DIR_TESTER)%.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@
	@echo "$(YELLOW)Compiling tester: $< $(BASE_COLOR)"

clean:
	@rm -rf $(OBJ_DIR) $(OBJ_TESTER_DIR)
	@echo "$(BLUE)Object files cleaned! $(BASE_COLOR)"

fclean:	clean
	@rm -f $(NAME) $(NAME_TESTER)
	@echo "$(CYAN)Archive and tester cleaned! $(BASE_COLOR)"

re:		fclean all

.PHONY:	all clean fclean re