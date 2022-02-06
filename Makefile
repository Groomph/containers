# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 16:05:34 by rsanchez          #+#    #+#              #
#    Updated: 2022/02/04 08:05:59 by rsanchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Template

CLASS = Class

SOURCES = main.cpp \
	  $(addprefix $(CLASS)/,	\
	  Fixed.cpp)

include ../../MakefileTemplate
