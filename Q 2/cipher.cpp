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
				delete[] temp;
			}
		}
		outFile.close();
		inFile.close();

	} else {
		/* Transposition cipher */
		std::string line;
		if(inFile.is_open()){
			while( getline(inFile, line) ){
				char* temp = new char(line.length() + 1);
				int j = 0;

				/* Fix this algorithm, needs to move around the characters based
				       on the keyValue */
				for(unsigned int i = 0; i < line.length(); ++i){
					if(i >= line.length()/2){
						temp[i] = line[j];
						j++;
						printf("%c\n", temp[i]);
					} else {
						temp[i] = line[line.length()/2 + i];
						printf("%c\n", temp[i]);
					}
				}
				std::cout << temp << std::endl;
				outFile << temp;
				delete[] temp;
			} 
		outFile.close();
		inFile.close();
		}

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

	Encrypt(argv[1], argv[2], 1, 1);

}