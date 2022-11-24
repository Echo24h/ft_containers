# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gborne <gborne@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/04 23:16:53 by gborne            #+#    #+#              #
#    Updated: 2022/11/24 23:07:52 by gborne           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	main.cpp \
					test/test.cpp \
					test/test_vector.cpp \
					test/test_map.cpp \
					test/test_bst.cpp \
					test/test_stack.cpp \
					test/test_speed.cpp

OBJS			= $(SRCS:.cpp=.o)

CXX				= g++
RM				= rm -f
CXXFLAGS		= -Wall -Wextra -Werror #-std=c++98

NAME			= check

%.o : %.c
	@$(CXX) $(CXXFLAGS) -I -o $@ -c $<

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

leaks:			all
				valgrind ./$(NAME)

.PHONY:			all clean fclean re leaks
