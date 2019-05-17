/**
 * Zach Schuermann
 * 112944063
 *
 * Includes functionality for zformat
 *
 * zformat - creates and formats a virtual disk according to path set by
 *       the ZDISK environment variable
 */


#include "oufs_lib.h"
#include "vdisk.h"

int main(int argc, char** argv) {
    // current working dir and disk name
    char cwd[MAX_PATH_LENGTH];
    char disk_name[MAX_PATH_LENGTH]; 
    // fetch env variables
    oufs_get_environment(cwd, disk_name);

    if (argc == 1) {
        // open disk
        vdisk_disk_open(disk_name);    

        // attempt format
        if(oufs_format_disk(disk_name) != 0)
            fprintf(stderr, "Clear failed with non-zero exit code");

        // close
        vdisk_disk_close(disk_name);
    }
    else {
        // Wrong number of parameters
        fprintf(stderr, "Usage: zformat\n");
    }


}
