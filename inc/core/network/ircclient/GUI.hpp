//
// Created by NANAA on 09/05/18.
//

#ifndef PSU_MYIRC_2017_GUI_HPP
#define PSU_MYIRC_2017_GUI_HPP

#include "ircclient.hpp"

#define CHAT_HEIGHT  LINES - (LINES / 6) - 1
#define INPUT_HEIGHT LINES - 5 * (LINES / 6) - 1

void create_window(t_client_info *client);
void run_window(t_client_info *client);
void display_textbox(t_client_info *client);
void display_chatbox(t_client_info *client);

#endif //PSU_MYIRC_2017_GUI_HPP
