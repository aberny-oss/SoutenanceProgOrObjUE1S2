#pragma once

#include <string>
#include <vector>

std::string AskStr(const std::string& msg, const std::vector<std::string>& validChoices);

int AskInt(const std::string& msg, int min, int max);