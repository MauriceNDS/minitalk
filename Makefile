all:	
		@$(MAKE) -C ./libft
		@$(MAKE) -C ./serv
		@$(MAKE) -C ./clie
		cp ./serv/server .
		cp ./clie/client .

clean:	
		@$(MAKE) clean -C ./libft
		@$(MAKE) clean -C ./serv
		@$(MAKE) clean -C ./clie

fclean:	
		@$(MAKE) fclean -C ./libft
		@$(MAKE) fclean -C ./serv
		@$(MAKE) fclean -C ./clie
		rm -f server
		rm -f client

re:
	@make fclean
	@make all

.PHONY: all clean fclean re