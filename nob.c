#define NOB_IMPLEMENTATION
#include "nob.h"
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	NOB_GO_REBUILD_URSELF(argc, argv);

	nob_shift_args(&argc, &argv);

	Nob_Cmd cmd = {0};
	int clean_executed = 0;

	nob_cmd_append(&cmd, "make", NULL);
	if (!nob_cmd_run_sync(cmd)) return (1);

	if (argc > 0)
	{
		const char *subcmd = nob_shift_args(&argc, &argv);

		if (strcmp(subcmd, "test") == 0)
		{
			cmd.count = 0;
			nob_cmd_append(&cmd, "make", "lib");
			nob_da_append_many(&cmd, argv, argc);
			if (!nob_cmd_run_sync(cmd)) return (1);

			cmd.count = 0;
			nob_cmd_append(&cmd, "make", "clean");
			if (!nob_cmd_run_sync(cmd)) return (1);
			clean_executed = 1;

			if (chdir("./test") != 0)
			{
				perror("chdir() error");
				return (1);
			}

			cmd.count = 0;
			nob_cmd_append(&cmd, "./test.py", NULL);
			if (!nob_cmd_run_sync(cmd)) return (1);

			if (chdir("../") != 0)
			{
				perror("chdir() error");
				return (1);
			}
		}
		else if (strcmp(subcmd, "run") == 0)
		{
			cmd.count = 0;
			nob_cmd_append(&cmd, "./bin/NexusC", NULL);
			if (!nob_cmd_run_sync(cmd)) return (1);
		}
		else
		{
			nob_log(NOB_ERROR, "Unknown subcommand %s", subcmd);
			return (1);
		}
	}

	if (!clean_executed)
	{
		cmd.count = 0;
		nob_cmd_append(&cmd, "make", "clean");
		if (!nob_cmd_run_sync(cmd)) return (1);
	}

	return (0);
}
