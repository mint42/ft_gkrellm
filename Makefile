# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/13 11:34:50 by rreedy            #+#    #+#              #
#    Updated: 2020/01/26 17:47:17 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include config.mk 

# SRCS := $(foreach src_dir, $(SRC_DIRS), $(wildcard $(src_dir)/*.cpp))
SRCS := srcs/main.cpp
SRCS += srcs/DisplayCLI.cpp
SRCS += srcs/Mhu.cpp
SRCS += srcs/Mos.cpp
SRCS += srcs/Mdate.cpp
SRCS += srcs/Mcpu.cpp
SRCS += srcs/Mram.cpp
SRCS += srcs/Mnt.cpp
SRCS += srcs/Mcat.cpp
SRCS += srcs/cmd_to_str.cpp
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

#
# To build a local library:
#
# LIB := $(LIBFT_DIR)/$(LIB_NAME)
# MAKE_LIB := make -C $(LIB_DIR) -f $(LIB_MAKEFILE) --no-print-directory
# 

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
