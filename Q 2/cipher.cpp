#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>

void Encrypt(std::string inputFile, std::string outputFile, int cipherType, int keyValue){

	std::ofstream outFile (outputFile.c_str());
	std::ifstream inFile  (inputFile.c_str());
	std::cout << "keyValue: " << keyValue << std::endl;
	if(cipherType == 0){
		std::string line;
		if(inFile.is_open()){
			while( getline(inFile, line) ){
				char* temp = new char(line.length() + 1);
				for(unsigned int i = 0; i < line.length(); ++i){
					temp[i] = line[i]+keyValue;
					std::cout << temp[i] << std::endl;
				}
				std::cout << temp << std::endl;
				outFile << temp;
			}
		}
		outFile.close();
		inFile.close();

	} else {

	}
}

void Decrypt(std::string inputFile, std::string outputFile, int cipherType, int keyValue){

}


int main(int argc, char** argv){
	if(argc != 3){
		perror("Error: syntax is: ./encrpyt <input file> <output file>\n");
		exit(-1);
	}

	Encrypt((std::string)argv[1], (std::string)argv[2], 0, 1);
	//Encrypt(argv[1], argv[2], 1, 1);

}