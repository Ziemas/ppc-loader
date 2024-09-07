#include <kernel.h>
#include <iopcontrol.h>
#include <sbv_patches.h>
#include <sifrpc.h>
#include <loadfile.h>

extern unsigned int size_liop_data;
extern unsigned char liop_data[];

int
main() {
	int res = 0;

	SifInitRpc(0);
	sbv_patch_enable_lmb();

	SifExecModuleBuffer(liop_data, size_liop_data, 0, NULL, &res);

	// we currently don't expect to return

	return 0;
}
