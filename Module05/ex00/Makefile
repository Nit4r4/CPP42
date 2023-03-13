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

NAME	= Kandinsky

#LOGO_CPP	=	echo "$(MAGENTA)\t.___  ___.   ______    _______   __    __   __       _______     _  _        __________   ___  _______ .______        ______  __    ______  _______     _______.     ___    __      _______   _______      ______ .______   .______
#								\t|   \/   |  /  __  \  |       \ |  |  |  | |  |     |   ____|   | || |      |   ____\  \ /  / |   ____||   _  \      /      ||  |  /      ||   ____|   /       |    / _ \  /_ |    |       \ |   ____|    /      ||   _  \  |   _  \
#								\t|  \  /  | |  |  |  | |  .--.  ||  |  |  | |  |     |  |__      | || |_     |  |__   \  V  /  |  |__   |  |_)  |    |  ,----'|  | |  ,----'|  |__     |   (----`   | | | |  | |    |  .--.  ||  |__      |  ,----'|  |_)  | |  |_)  |
#								\t|  |\/|  | |  |  |  | |  |  |  ||  |  |  | |  |     |   __|     |__   _|    |   __|   >   <   |   __|  |      /     |  |     |  | |  |     |   __|     \   \       | | | |  | |    |  |  |  ||   __|     |  |     |   ___/  |   ___/
#								\t|  |  |  | |  `--'  | |  '--'  ||  `--'  | |  `----.|  |____       | |      |  |____ /  .  \  |  |____ |  |\  \----.|  `----.|  | |  `----.|  |____.----)   |      | |_| |  | |    |  '--'  ||  |____    |  `----.|  |      |  |
#								\t|__|  |__|  \______/  |_______/  \______/  |_______||_______|      |_|      |_______/__/ \__\ |_______|| _| `._____| \______||__|  \______||_______|_______/        \___/   |_|    |_______/ |_______|    \______|| _|      | _| \n $(RESET)\n"

SRCS	= main.cpp AAnimal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
MAIN	= main.cpp
OBJS	= ${SRCS:.cpp=.o}

CC		= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 #-pedantic #-g -fsanitize=address

AR 		= ar rc
RM 		= rm -f

.c.o:		%.o : %.cpp
					@$(CC)${CPPFLAGS} -I $< -o $(<:.cpp=.o)

all: 		logo ${NAME} 

logo :
			@$(LOGO_CPP)

${NAME}:	${OBJS} 
					@echo "$(CYAN)---- Compiling library ----"
					@sleep 0.2
					@echo "$(GREEN2)📚 Link paths"
					@$(CC) $(CPPFLAGS) ${OBJS} -o $(NAME)
					@printf "$(BLUE)🍵 Creating $(NAME)$(RESET)\n"
					@sleep 0.2
					@echo "$(CYAN)$(NAME) Compiled ! \033[39m(\033[31m๑\033[39m╹◡╹\033[31m๑\033[39m)"
					@sleep 0.2
					@echo ""


clean:
					@${RM} ${OBJS}
					@echo ""
					@echo "$(YELLOW)---- Cleaning library ----"
					@sleep 0.2
					@printf "$(BLUE)🧽 Cleaning $(NAME)$(RESET)\n"
					@echo "$(GREEN2)📚 Cleaning paths"
					@sleep 0.2
					@echo "$(YELLOW)$(NAME) is all clean ! $(ORANGE)(ﾉ◕ヮ◕)ﾉ$(YELLOW)*:･ﾟ✧"
					@sleep 0.2
					@echo ""

fclean: 	clean
					@${RM} $(NAME) $(textGen.replace)
					@printf "\r$(PURP)----- Deleting library ----\n"
					@echo 🗑 "\033[31mEverything is deleting now !"
					@sleep 0.2
					@printf "\r$(PURP)$(NAME) have been removed $(WHITE)¯\_$(PURP)(ツ)$(WHITE)_/¯$(RESET)\n"
					@sleep 0.2
					@echo ""

re:			fclean all

leak: 		all
					leaks -atExit -- ./$(NAME)

.PHONY: all clean fclean re
