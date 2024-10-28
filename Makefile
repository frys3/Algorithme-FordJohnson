# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blerouss <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 12:30:24 by blerouss          #+#    #+#              #
#    Updated: 2024/02/15 13:47:34 by blerouss         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	PmergeMe

SRC =	main.cpp		\
		PmergeMe.cpp	\
		
INC = 	PmergeMe.hpp	\

OBJ = $(SRC:.cpp=.o)

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

all : $(NAME)

$(NAME) : $(SRC) $(OBJ) $(INC)
	$(CXX) $(CXXFLAGS) $(OBJ) -I $(INC) -o $(NAME) 

clean : 
	@/bin/rm -f *.o 

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all
