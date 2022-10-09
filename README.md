# 42_so_long
Part of 42 curriculum - Introduction of graphics development






mlx_xpm_to_image & mlx_xpm_file_to_image
SYN : void *mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height)
SYN : void *mlx_xpm_file_to_image(void *mlx_ptr, char **file_name, int *width, int *height)
DES : Create a new image the same way. They will fill it using the specified xpm_data or filename, depending on which function is used.
RTN : Return NULL if an error occurs. Otherwise return a non-null pointer as an image identifier.

width height are the places the img will be plotted on the windows


XPM files - the images are fixed in size, so used imagemagick to rescale the files
https://stackoverflow.com/questions/42055729/rescaling-xpm-image
https://www.tecmint.com/install-imagemagick-on-debian-ubuntu/
