# CyberChat v1.0

A secure, anonymous chat application built with Qt and C++ for private communication without leaving digital traces.

## 🔒 Overview

CyberChat v1.0 is an open-source, privacy-focused chat application designed for secure communication across both Local Area Networks (LAN) and Wide Area Networks (WAN). This initial release provides core functionality for anonymous messaging with no persistent chat history stored locally.

## ✨ Features

### Core Features (v1.0)
- **Anonymous Communication**: Chat without revealing identity or leaving traces
- **LAN Communication**: Connect and chat with users on your local network
- **Basic Server/Client Architecture**: Simple server-client model for message relay
- **No Data Persistence**: Messages are not stored locally for maximum privacy
- **Cross-Platform**: Built with Qt for Windows, macOS, and Linux compatibility
- **Open Source**: MIT licensed for transparency and community contribution

### Planned Features (Future Releases)
- WAN mode for connecting to public IP servers
- Enhanced server functionality (server acting as client)
- Message encryption
- File sharing capabilities
- User authentication system

## 🛠️ Technology Stack

- **Language**: C++
- **UI Framework**: Qt 6.9.1
- **IDE**: Qt Creator
- **Build System**: CMake
- **License**: MIT (Open Source)

## 📋 Prerequisites

- Qt 6.9.1 or higher
- Qt Creator IDE
- MinGW 64-bit compiler (or equivalent C++ compiler)
- CMake 3.16 or higher

## 🚀 Installation

### Building from Source

1. **Clone the repository**
   ```bash
   git clone https://github.com/CyberNilsen/CyberChat.git
   cd CyberChat
   ```

2. **Open in Qt Creator**
   - Launch Qt Creator
   - Open the `CMakeLists.txt` file
   - Configure the project with your Qt kit

3. **Build the project**
   - Use Qt Creator's build system or
   - Command line build:
     ```bash
     mkdir build
     cd build
     cmake ..
     make
     ```

## 🎯 Usage

### Getting Started with v1.0

1. **Launch CyberChat** on two or more devices within the same local network
2. **Start Server Mode** on one device:
   - Click "Start Server" or equivalent option
   - Note the local IP address displayed
3. **Connect as Client** from other devices:
   - Enter the server's IP address
   - Join the chat session
4. **Start Chatting** anonymously with connected users

### Current Limitations (v1.0)
- LAN communication only
- Basic text messaging
- No message history retention
- Simple user interface
- No encryption (messages sent in plain text over local network)

## 🔧 Version 1.0 Status

✅ **Released Features**:
- Basic LAN chat functionality
- Server/client connection model
- Anonymous messaging
- Cross-platform compatibility
- No persistent storage

⚠️ **Known Issues**:
- Limited to local network communication
- Basic UI design
- No message encryption
- Connection stability may vary

## 🤝 Contributing

We welcome contributions to CyberChat! Please feel free to:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

### Development Guidelines
- Follow Qt and C++ best practices
- Maintain code documentation
- Test on multiple platforms when possible
- Prioritize security and privacy in all implementations
- Focus on stability and user experience for v1.x releases

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🛡️ Security & Privacy

CyberChat v1.0 implements basic privacy features:
- No chat history persistence
- Anonymous communication (no user registration required)
- Open source for transparency
- Local network communication only (reducing external exposure)

**Security Note**: v1.0 does not include message encryption. Communications are sent in plain text over the local network. Encryption will be added in future releases.

## 📞 Support

For questions, issues, or contributions:
- Open an issue on GitHub
- Check existing issues before creating new ones
- Provide detailed information for bug reports
- Include system information (OS, Qt version, etc.) for technical issues


This is the first stable release of CyberChat. While functional for basic LAN, WAN communication, many advanced features are planned for future versions. Thank you for trying CyberChat v1.0!
