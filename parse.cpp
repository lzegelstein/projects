#include "parse.h"
#include <fstream>
#include <sstream>
	
namespace parse {	
    std::vector<std::string> file_to_vector(const std::string & file) {
	    std::vector<std::string> result;
        std::ifstream csv(file);
    
        std::istream_iterator<std::string> eos;
        std::istream_iterator<std::string> iter(csv);
        while (iter != eos) {
            result.push_back(*iter);
            ++iter;        
	    }	
        return result;
    }
}