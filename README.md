# get_next_line-42
42 School project (GET_NEXT_LINE)

Created function which returns Dynamically Allocated string with null terminator '\0'.
The function gets fd (file descriptor) as parameter, reads file with the given descriptor and returns the first line which ends with '\n' (new line).
If all lines are returned and program reached to the end of the file, it will return the remaining file content which will be returned without '\n'.

The program must work well with very big file content, as it's not reading and saving the whole file content from the start of the program.
The text/file_content is saved in static poitner, which points to dynamically allocated memory.
It will read the file again, if the allocated string doesn't contain line ending with '\n'.
