add_executable(main main.c)
add_executable(program_UI Program_UI.c)
add_executable(program_file_handling Program_File_Handling.c)
add_executable(sorting_reccomendations sorting_reccomendations.c)

# add -lm compiler flag 
target_link_libraries(main m)
target_link_libraries(program_UI m)
target_link_libraries(program_file_handling m)
target_link_libraries(sorting_reccomendations m)
