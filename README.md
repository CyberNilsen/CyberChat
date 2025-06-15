# CyberChat
A secure, anonymous chat application built with Qt and C++ for private communication without leaving digital traces.

![CyberChat interface](https://github.com/user-attachments/assets/4d6c9d34-ddc8-4199-a083-eeffedfc0160)

## 🔒 Overview
CyberChat is an open-source, privacy-focused chat application designed for secure communication across both Local Area Networks (LAN) and Wide Area Networks (WAN). The application prioritizes user anonymity and ensures no persistent chat history is stored locally.

## ✨ Features
- Anonymous Communication: Chat without revealing identity or leaving traces
- Dual Network Support: 
  - LAN mode for local network communication
  - WAN mode for connecting to public IP servers
- No Data Persistence: Messages are not stored locally for maximum privacy
- Cross-Platform: Built with Qt for multi-platform compatibility
- Open Source: MIT licensed for transparency and community contribution
  
## 🛠️ Technology Stack
- Language: C++
- UI Framework: Qt 6.5.3
- IDE: Qt Creator
- Build System: CMake
- License: MIT (Open Source)
  
## 📋 Prerequisites
- Qt 6.5.3 or higher
- Qt Creator IDE
- MinGW 64-bit compiler (or equivalent C++ compiler)
- CMake 3.16 or higher
  
## 🚀 Installation

### Building from Source
1. Clone the repository
   ```bash
   git clone https://github.com/CyberNilsen/CyberChat.git
   cd CyberChat```
   
2. Open in Qt Creator
   - Launch Qt Creator
   - Open the CMakeLists.txt file
   - Configure the project with your Qt kit
3. Build the project
   - Use Qt Creator's build system or
   - Command line build:
     bash
     mkdir build
     cd build
     cmake ..
     make
     
## 🎯 Usage

### LAN Mode
- Launch CyberChat on devices within the same network
- One device acts as the server, others connect as clients
- Automatic device discovery on local network
  
### WAN Mode
- Configure one instance as a public server with accessible IP
- Clients connect using the server's public IP address
- Secure communication over internet connection
- You have to port forward for this the WAN side to work

## 🤝 Contributing

We welcome contributions to CyberChat! Please feel free to:
1. Fork the repository
2. Create a feature branch (git checkout -b feature/amazing-feature)
3. Commit your changes (git commit -m 'Add amazing feature')
4. Push to the branch (git push origin feature/amazing-feature)
5. Open a Pull Request

### Development Guidelines
- Follow Qt and C++ best practices
- Maintain code documentation
- Test on multiple platforms when possible
- Prioritize security and privacy in all implementations
  
## 📄 License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🛡️ Security & Privacy
CyberChat is designed with privacy as a core principle:
- No chat history persistence
- Anonymous communication
- Open source for transparency
- Encrypted message transmission (planned)
  
## 📞 Support
For questions, issues, or contributions:
- Open an issue on GitHub
- Check existing issues before creating new ones
- Provide detailed information for bug reports
---
Note: This is an early-stage project under active development. Features and functionality are subject to change.
