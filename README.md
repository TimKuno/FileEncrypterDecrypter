# Information

This project was developed for my master thesis. It's goal is to showcase how the file encryption and decryption process of a ransomware could look like and how much information you can get from the binary file with reverse engineering and how close this gets to the original source code. For this purpose the folder Demo contains some files with different file types to proof that the script is working for different file types at least as long as no admistrator rights are required. This means all files in the folder will be encrypted and after the right password is entered in the command prompt they will be decrypted. For the encryption and decryption is the caesar chiffre used. The program works as follows. The content of each file inside the Demo folder will be read. Then every character of each file will be shifted with the caesar chiffre and the new file content will be written to each file.

<br>
<br>

# Compiling with g++

Windows:
```
g++ FileEncrypterDecrypter.cpp -o <exename>.exe
```

Linux:

```
g++ -o <binaryname> FileEncrypterDecrypter.cpp
```

<br>
<br>

# WARNING

Use this tool at your own risk. Author is not responsible or liable if you damage your own system or others. Follow all local, state, federal, and international laws as it pertains to your geographic location. Do NOT use this script maliciously.
