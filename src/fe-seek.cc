#include "globals.h"
#include "flags.h"
#include "usb/usb.h"
#include "protocol.h"

static FlagGroup flags = {
	&usbFlags,
};

static IntFlag drive(
    { "--drive", "-d" },
    "drive to use",
    0);

static IntFlag track(
    { "--track", "-t" },
    "track to seek to",
    0);

int mainSeek(int argc, const char* argv[])
{
    flags.parseFlags(argc, argv);

    usbSetDrive(drive, false, F_INDEX_REAL);
    usbSeek(track);
    return 0;
}
