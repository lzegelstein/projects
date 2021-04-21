#pragma once
	#include <vector>
	#include <cstdlib>
	#include <fstream>
	#include <iostream>
	#include <string>
	
	namespace parse {
	
	std::vector<std::string> file_to_vector(const std::string &file);
	
	std::vector<std::vector<std::string>> tokenizer(const std::vector<std::string> & csv);

	std::vector<std::string> helper(std::string& token_help, const char& comma);
	}