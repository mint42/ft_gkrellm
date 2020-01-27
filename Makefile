# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/13 11:34:50 by rreedy            #+#    #+#              #
#    Updated: 2020/01/26 19:48:57 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include config.mk 

SRCS := $(foreach src_dir, $(SRC_DIRS), $(wildcard $(src_dir)/*.cpp))
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

.PHONY: all clean fclean re name

all: $(NAME)

$(NAME): $(OBJS) Makefile config.mk
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

#
# $(LIB):
# 	@- $(MAKE_LIB) all
#

clean:
	@- $(RM) $(OBJS)
#	@- $(MAKE_LIB) clean

fclean: clean
	@- $(RM) $(NAME)
#	@- $(MAKE_LIB) fclean

re: fclean all
