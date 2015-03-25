#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>

void Encrypt(std::string inputFile, std::string outputFile, int cipherType, int keyValue){

	std::ofstream outFile (outputFile.c_str());
	std::ifstream inFile  (inputFile.c_str());



	std::cout << "keyValue: " << keyValue << std::endl;
	if(inFile.is_open() && outFile.is_open()){
	if(cipherType == 0){
		std::string line;
		if(inFile.is_open()){
			while( getline(inFile, line) ){
				char* temp = new char(line.length() + 1);
				for(unsigned int i = 0; i < line.length(); ++i){
					if(line[i] >= 'A' && line[i] <= 'Z'){
						temp[i] = (char)(((line[i] + keyValue - 'A' + 26) % 26) + 'A');
					} else if(line[i] >= 'a' && line[i] <= 'z'){
						temp[i] = (char)(((line[i] + keyValue - 'a' + 26) % 26) + 'a');						
					}
				}
				outFile << temp << "\n";
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
				int j, i;
				char * a = new char[line.length() + 1];
				char * b = new char[line.length() + 1];
				char * temp = new char[line.length() + 1];
				for(j = 0,i = 0; i < line.length(); ++i){
					if(i%2 == 0)
						temp[j++] = line[i];
				}

				for(i=0;i<line.length();++i){
					if(i%2 == 1)
						temp[j++] = line[i];
				}
				temp[j] = '\0';
				outFile << temp << "\n";
				delete[] temp;
			} 
		outFile.close();
		inFile.close();
		}

	}
} else {
	std::cout << "Error: Failed to open either the input or output file\n";
	exit(-1);
}
}

int main(int argc, char** argv){
	if(argc != 5){
		perror("Error: syntax is: ./encrpyt <input file> <output file> <Encryption Type> <Key Value>\n");
		exit(-1);
	}
	
	Encrypt(argv[1], argv[2], atoi(argv[3]), atoi(argv[4]));	

}