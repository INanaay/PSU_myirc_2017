//
// Created by NANAA on 08/05/18.
//

#ifndef PSU_MYIRC_2017_UTILS_HPP
#define PSU_MYIRC_2017_UTILS_HPP

int get_double_array_size(char **array);
void put_in_caps(char *command);
void send_command(int sd, char **command);

#endif //PSU_MYIRC_2017_UTILS_HPP
