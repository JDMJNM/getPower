/* File: getPower.cpp
 *
 * Author: Jacob Meadows
 *
 * Calculates and outputs the current relative battery power of the device.
 */
#include "getPower.hpp"

int main(int argc, char** argv)
{
	std::string currentCharge;
	std::string fullCharge;

	std::string fileDir = std::string(POWER_SUPPLY_DIR);
	// get current charge of battery
	getFileData(&currentCharge, fileDir + CURRENT_CHARGE_FILE);
	// get maximum possible charge of battery
	getFileData(&fullCharge, fileDir + FULL_CHARGE_FILE);
	// output percent of charge left in battery with 2 decimal
	std::cout << std::setprecision(2) << std::fixed <<
		100 * std::stof(currentCharge, nullptr) /
			std::stof(fullCharge, nullptr);

	return 1;
}

void getFileData(std::string* result, const std::string fileName)
{
	std::ifstream file;
	file.open(fileName);
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	result->append(buffer.str());
}

