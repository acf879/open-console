#include <zephyr/kernel.h>
#include <zephyr/shell/shell.h>
#include <zephyr/logging/log.h>

#include <stdlib.h>

#include "console_properties.h"

extern uint32_t delta_time_us;

static inline void help_terminal_cmd(const struct shell* shell_cmd, size_t argc, char** argv) {
    shell_fprintf(shell_cmd, SHELL_VT100_COLOR_MAGENTA, 
            "Help List for Custom Console              \n"
            "------------------------------------------\n"
            "help           - provides a help list     \n"
            "set_delta_time - sets time step in us     \n"
            "get_delta_time - gets time step in us     \n"
            );
    return;
}

static inline void set_delta_time_terminal_cmd(const struct shell* shell_cmd, size_t argc, char** argv) {
    shell_fprintf(shell_cmd, SHELL_VT100_COLOR_MAGENTA, "Delta time set to: %s us\n", argv[1]);
    delta_time_us = atoi(argv[1]);
    return;
}

static inline void get_delta_time_terminal_cmd(const struct shell* shell_cmd, size_t argc, char** argv) {
    shell_fprintf(shell_cmd, SHELL_VT100_COLOR_MAGENTA, "Delta time is: %u us\n", delta_time_us);
    return;
}

SHELL_STATIC_SUBCMD_SET_CREATE(
    terminal_cmds,
    SHELL_CMD_ARG(help, NULL, "provides help list", help_terminal_cmd, 1, 0), 
    SHELL_CMD_ARG(set_delta_time, NULL, "set delta time in us", set_delta_time_terminal_cmd, 2, 0), 
    SHELL_CMD_ARG(get_delta_time, NULL, "get delta time in us", get_delta_time_terminal_cmd, 1, 0), 
    SHELL_SUBCMD_SET_END);

SHELL_CMD_REGISTER(terminal, &terminal_cmds, "Terminal Commands", NULL);
