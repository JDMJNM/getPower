/* File: getPower.c
 *
 * Author: Jacob Meadows
 *
 * Calculates and outputs the current relative battery power of the device.
 */
#include "getPower.h"

int main(int argc, char** argv)
{
	char* currentCharge;
	char* fullCharge;

	size_t maxFileLength;
	getLongestA(BATTERY_FILES, fileCount, &maxFileLength);

	char fileDir[powerSupplyDirLength + maxFileLength + 1];
	strncpy(fileDir, POWER_SUPPLY_DIR, powerSupplyDirLength);
	// get current charge of battery
	strcpy(fileDir + powerSupplyDirLength, CURRENT_CHARGE_FILE);
	// malloc[currentCharge]
	getFileData(&currentCharge, fileDir);
	// get maximum possible charge of battery
	strcpy(fileDir + powerSupplyDirLength, FULL_CHARGE_FILE);
	// malloc[fullCharge]
	getFileData(&fullCharge, fileDir);
	// output percent of charge left in battery with 2 decimal
	printf("%.2f", 100 * atof(currentCharge) / atof(fullCharge));
	// free
	free(currentCharge);
	free(fullCharge);

	return 0;
}

void getLongestA(const char* data[], size_t size, size_t* result) {
	*result = 0;

	size_t length;
	for (size_t i = 0; i < size; ++i) {
		if ((length = strlen(data[i])) > *result)
			*result = length;
	}
}

void getFileData(char** result, const char* fileName)
{
	FILE* file = fopen(fileName, "r");
	*result = (char*) malloc(8 * sizeof(char));
	fgets(*result, 8, file);
	fclose(file);
}

