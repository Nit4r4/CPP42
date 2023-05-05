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
MAGENTA = \033[35m

NAME	= RPN


SRCS	= main.cpp RPN.cpp
MAIN	= main.cpp
OBJS	= ${SRCS:.cpp=.o}

LOGO_CPP	= 	 @echo "$(CYAN) \t    ___  ____  ____     __  ___  \n\
 								\t   / __)(  _ \(  _ \   /. |(__ \ \n\
								\t  ( (__  )___/ )___/  (_  _)/ _/ \n\
 								\t   \___)(__)  (__)      (_)(____) $(\RESET)\n\
								\t  \n"

CC			= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 -fno-strict-aliasing #-pedantic #-g -fsanitize=address

AR 		= ar rc
RM 		= rm -f

.c.o:		%.o : %.cpp
					@$(CC)${CPPFLAGS}

all: 		logo ${NAME} 

logo:
			$(LOGO_CPP)



${NAME}:			${OBJS}
					@echo "$(CYAN)---- Compiling library ----"
					@echo "$(GREEN2)📚 Link paths"
					@$(CC) $(CPPFLAGS) ${OBJS} -o $(NAME)
					@printf "$(BLUE)🍵 Creating $(NAME)$(RESET)\n"
					@echo "$(CYAN)$(NAME) Compiled ! \033[39m(\033[31m๑\033[39m╹◡╹\033[31m๑\033[39m)"
					@echo ""


clean:
					@${RM} ${OBJS}
					@echo ""
					@echo "$(YELLOW)---- Cleaning library ----"
					@printf "$(BLUE)🧽 Cleaning $(NAME)$(RESET)\n"
					@echo "$(GREEN2)📚 Cleaning paths"
					@echo "$(YELLOW)$(NAME) is all clean ! $(ORANGE)(ﾉ◕ヮ◕)ﾉ$(YELLOW)*:･ﾟ✧"
					@echo ""

fclean: 	clean
					@${RM} $(NAME) $(textGen.replace)
					@printf "\r$(PURP)----- Deleting library ----\n"
					@echo 🗑 "\033[31mEverything is deleting now !"
					@printf "\r$(PURP)$(NAME) have been removed $(WHITE)¯\_$(PURP)(ツ)$(WHITE)_/¯$(RESET)\n"
					@echo ""

re:			fclean all

test:		$(NAME) 
			./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
			./RPN "7 7 * 7 -"
			./RPN "1 2 * 2 / 2 * 2 4 - +"
			./RPN "3 1 * 0 / 2 * 2 4 - +"
			./RPN "1 0 * 2 / 2 * 2 4 - +"
			./RPN "1 -2 * 2 / 2 * 2 4 - +"
			./RPN "1 0 * 2 / 2 * 2a 4 - +"
			./RPN "1 0 * 2 / 2 * a 4 - +"
			./RPN "1 0 * 2 / 2 * 32 4 - +"
			./RPN "(1 + 1)"
			./RPN "7 7 * 7 ^"

leak: 		all
					leaks -atExit -- ./$(NAME)

.PHONY: all clean fclean re
