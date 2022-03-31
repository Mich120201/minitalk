# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 10:53:31 by mvolpi            #+#    #+#              #
#    Updated: 2022/03/22 11:44:17 by mvolpi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server

CLIENT = client

LIBFT = ./libft/libft.a

HEADER = minitalk.h

CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(CLIENT) $(SERVER) $(HEADER)

$(SERVER): server.c $(HEADER)
	@gcc $(CFLAGS) server.c $(LIBFT) -o $@
	@echo $@ ready

$(CLIENT): client.c $(HEADER)
	@gcc $(CFLAGS) client.c $(LIBFT) -o $@
	@echo $@ ready

$(LIBFT):
	@make -C./libft
bonus: $(LIBFT) $(SERVER_B) $(CLIENT_B) $(HEADER_B)

clean:
	@make clean -C ./libft

fclean: clean
	rm -rf $(SERVER) $(CLIENT) $(SERVER_B) $(CLIENT_B)
	make fclean -C ./libft

re: fclean all

.PHONY: all re clean fclean bonus
