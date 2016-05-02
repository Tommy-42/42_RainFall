/* ************************************************************************** */
/* Reverse code of the level0 executable                                      */
/* tpageard                                                                   */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int ac, int argv) {

	//no check if ac < 2
	int userInput = atoi(argv[1]);

	if( userInput == 423 ) {

		char *path = strdup("/bin/sh");
		gid_t gid = getegid(); // get effective group id
		uid_t uid = geteuid(); // get effective user id

		// sets the real GID, effective GID, and saved set-group-ID of the calling process
    	setresgid(gid, gid, gid);
		// sets the real user ID, the effective user ID, and the saved set-user-ID of the calling process
    	setresuid(uid, uid, uid);
		// exec /bin/sh with the effective group and user id
		execv(path);
	}
	else {
		char err[] = "No !\n";
		fwrite(err, sizeof(char), sizeof(err), 2);
	}
	return 0;
}