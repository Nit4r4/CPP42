PURP	= \e[35m
GREEN	= \e[32m
GREEN2	= \033[32m
RED		= \e[31m
WHITE	= \e[39m
YELLOW	= \033[33m
HIDDEN	= \e[8m
RESET	= \e[0m
BLUE	= \033[34m
CYAN	= \033[36m

NAME	= Poly

SRCS	= main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp
MAIN	= main.cpp
OBJS	= ${SRCS:.cpp=.o}

CC		= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 #-pedantic #-g -fsanitize=address

AR 		= ar rc
RM 		= rm -f

.c.o:		%.o : %.cpp
					@$(CC)${CPPFLAGS} -I $< -o $(<:.cpp=.o)

all: 		${NAME} 

${NAME}:	${OBJS} 
					@echo "$(CYAN)---- Compiling library ----"
					@sleep 0.2
					@echo "$(GREEN2)ð Link paths"
					@$(CC) $(CPPFLAGS) ${OBJS} -o $(NAME)
					@printf "$(BLUE)ðµ Creating $(NAME)$(RESET)\n"
					@sleep 0.2
					@echo "$(CYAN)$(NAME) Compiled ! \033[39m(\033[31mà¹\033[39mâ¹â¡â¹\033[31mà¹\033[39m)"
					@sleep 0.2
					@echo ""


clean:
					@${RM} ${OBJS}
					@echo ""
					@echo "$(YELLOW)---- Cleaning library ----"
					@sleep 0.2
					@printf "$(BLUE)ð§½ Cleaning $(NAME)$(RESET)\n"
					@echo "$(GREEN2)ð Cleaning paths"
					@sleep 0.2
					@echo "$(YELLOW)$(NAME) is all clean ! $(ORANGE)(ï¾âã®â)ï¾$(YELLOW)*:ï½¥ï¾â§"
					@sleep 0.2
					@echo ""

fclean: 	clean
					@${RM} $(NAME) $(textGen.replace)
					@printf "\r$(PURP)----- Deleting library ----\n"
					@echo ð "\033[31mEverything is deleting now !"
					@sleep 0.2
					@printf "\r$(PURP)$(NAME) have been removed $(WHITE)Â¯\_$(PURP)(ã)$(WHITE)_/Â¯$(RESET)\n"
					@sleep 0.2
					@echo ""

re:			fclean all

leak: 		all
					leaks -atExit -- ./$(NAME)

.PHONY: all clean fclean re
