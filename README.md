Esquema de las funciones:

level_1	      level_2		           level_3			           level_4		          level_5                level_6

main      --> choose_an_option --> select_option_mssg
	        --> proceed	         --> take_book_info	     --> get_data_info		--> ft_strdup
						                                           --> check_year		    --> check_year_length  --> ft_strlen 
										                                                        --> check_year_digits
						                                           --> ascii_year_to_integer
						                                           --> add_book		       --> insert_book_info	
			  							                                                       --> add_node_to_list  --> compare
                                                                                                   --> where_to_insert
                                                                             --> free_list_node
                                                                             --> free_info
				  						                                 --> free_info
					  	                                         --> free_simple_pointer
			                          --> option_2	         --> get_data_info		--> ft_strdup
						                                           --> remove_book		  --> compare
						                                           --> free_simple_pointer
			                          --> list_books
			                          --> option_4	         --> get_data_info		--> ft_strdup
						                                           --> search_book		--> compare
						                                           --> free_simple_pointer
	         --> free_list	      --> free_list_node	   --> free_simple_pointer
