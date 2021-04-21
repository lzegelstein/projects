#include "parse.h"
#include <fstream>
#include <sstream>
	
namespace parse {
	
std::vector<std::string> file_to_vector(const std::string & file) {
	std::vector<std::string> result;
    std::ifstream csv(file);
    std::istream_iterator<std::string> iter(csv);
    std::istream_iterator<std::string> datafile;
	while(iter != datafile) {
        result.push_back(*iter);
        iter++;        
	}
    return result;
}

std::vector<std::vector<std::string>> tokenizer(const std::vector<std::string> & csv) {
    std::vector<std::vector<std::string>> result;

	return result;

}
std::vector<std::string> helper(std::string& toke_help, const char& comma) {
	std::vector<std::string> result;
	std::string line;
	std::stringstream stream(line);
	std::string token;
	while(std::getline(stream, token, ',')){
		result.push_back(token);
	}
	return result;
}


}