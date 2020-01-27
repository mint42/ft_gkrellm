# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    config.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 09:39:36 by rreedy            #+#    #+#              #
#    Updated: 2020/01/26 20:15:29 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_gkrellm

SFML_DIR := libsfml

LIBS := ncurses
LIBS += sfml-window
LIBS += sfml-graphics
LIBS += sfml-system
LOCAL_LIB_INCLUDE_DIRS := $(SFML_DIR)/include

SRC_DIRS := ./srcs
INCLUDE_DIRS := ./includes

CXX := clang++
CXXFLAGS := -g
CXXFLAGS += -Wall
CXXFLAGS += -Wextra
CXXFLAGS += -Werror
CXXFLAGS += $(foreach idir,$(INCLUDE_DIRS),-I$(idir))
CXXFLAGS += $(foreach lidir,$(LOCAL_LIB_INCLUDE_DIRS),-I$(lidir))

LDFLAGS := $(foreach lib,$(LIBS),-l$(lib))
LDFLAGS += -L$(SFML_DIR)/lib -rpath @executable_path/$(SFML_DIR)/lib
LDFLAGS += $(foreach ldir,$(LOCAL_LIB_DIRS),-L$(ldir))
