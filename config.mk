# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    config.mk                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rreedy <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 09:39:36 by rreedy            #+#    #+#              #
#    Updated: 2020/01/26 00:34:25 by rreedy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_gkrellm

#
# Insert a local library's information here:
#
# LIB_NAME :=
# LIB_DIR :=
# LIB_MAKEFILE := Makefile
#

LIBS := ncurses

#
# LOCAL_LIB_DIRS :=
# LOCAL_LIB_INCLUDE_DIRS :=
#

SRC_DIRS := ./srcs
SRC_DIRS += ./srcs/modules
INCLUDE_DIRS := ./includes

CXX := clang++
CXXFLAGS := -g
CXXFLAGS += -Wall
CXXFLAGS += -Wextra
CXXFLAGS += -Werror
CXXFLAGS += $(foreach idir,$(INCLUDE_DIRS),-I$(idir))
#
# CXXFLAGS += $(foreach lidir,$(LOCAL_LIB_INCLUDE_DIRS),-I$(lidir))
#

LDFLAGS := $(foreach lib,$(LIBS),-l$(lib))
#
# LDFLAGS += $(foreach ldir,$(LOCAL_LIB_DIRS),-L$(ldir))
#
