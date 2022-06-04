printf "Compiling"
make -s fclean
printf "."
make -s ft
printf "."
make -s std
printf "\033[2K\r\e[92mCompiling: OK\n"

printf "\e[95mVector\n"
printf "\e[93mFT\e[39m"
time ./ft vector > ft_vector
printf "\e[93m\nSTD\e[39m"
time ./std vector > std_vector
(diff ft_vector std_vector > diff_vector && printf "\e[92mVector OK :)\n\e[39m" \
	&& rm -f ft_vector std_vector diff_vector) \
	|| printf "\e[91mVector KO :(\n\e[39m"

printf "\e[95m\nStack\n"
printf "\e[93mFT\e[39m"
time ./ft stack > ft_stack
printf "\e[93m\nSTD\e[39m"
time ./std stack > std_stack
(diff ft_stack std_stack > diff_stack && printf "\e[92mStack OK :)\n\e[39m" \
	&& rm -f ft_stack std_stack diff_stack) \
	|| printf "\e[91mStack KO :(\n\e[39m"

printf "\e[95m\nMap\n"
printf "\e[93mFT\e[39m"
time ./ft map > ft_map
printf "\e[93m\nSTD\e[39m"
time ./std map > std_map
(diff ft_map std_map > diff_map && printf "\e[92mMap OK :)\n\e[39m" \
	&& rm -f ft_map std_map diff_map) \
	|| printf "\e[91mMap KO :(\n\e[39m"

make -s fclean