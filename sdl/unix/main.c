#include <compiler.h>
#include <np2.h>

int main(int argc, char *argv[])
{
	int ret;

	ret = np2_main(argc, argv, NULL);
	if(ret == FAILURE) {
		return ret;
	}
	np2_mainloop();
	ret = np2_end();

	return ret;
}
