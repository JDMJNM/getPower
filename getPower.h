/* File: getPower.h
 *
 * Author: Jacob Meadows
 *
 * Header file for getPower.c
 */
#ifndef GETPOWER_H
#define GETPOWER_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define POWER_SUPPLY_DIR "/sys/class/power_supply/BAT0/"
#define CURRENT_CHARGE_FILE "charge_now"
#define FULL_CHARGE_FILE "charge_full"

const size_t powerSupplyDirLength = strlen(POWER_SUPPLY_DIR);

const char* BATTERY_FILES[] = {
	CURRENT_CHARGE_FILE,
	FULL_CHARGE_FILE
};
const size_t fileCount = sizeof(BATTERY_FILES) / sizeof(const char*);

void getFileData(char**, const char*);
void getLongestA(const char*[], size_t, size_t*);

#endif /* GETPOWER_H */

