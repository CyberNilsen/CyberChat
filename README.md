# CyberChat

A secure, anonymous chat application built with Qt and C++ for private communication without leaving digital traces.

## Lots of these features are not added yet but are ideas of what the program is gonna have.

## 🔒 Overview

CyberChat is an open-source, privacy-focused chat application designed for secure communication across both Local Area Networks (LAN) and Wide Area Networks (WAN). The application prioritizes user anonymity and ensures no persistent chat history is stored locally.

## ✨ Features

- **Anonymous Communication**: Chat without revealing identity or leaving traces
- **Dual Network Support**: 
  - LAN mode for local network communication
  - WAN mode for connecting to public IP servers
- **Flexible Architecture**: Server can also function as a client
- **No Data Persistence**: Messages are not stored locally for maximum privacy
- **Cross-Platform**: Built with Qt for multi-platform compatibility
- **Open Source**: MIT licensed for transparency and community contribution

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

### LAN Mode
- Launch CyberChat on devices within the same network
- One device acts as the server, others connect as clients
- Automatic device discovery on local network

### WAN Mode
- Configure one instance as a public server with accessible IP
- Clients connect using the server's public IP address
- Secure communication over internet connection

## 🏗️ Project Structure

```
CyberChat/
├── build/                  # Build output directory
├── main.cpp               # Application entry point
├── mainwindow.cpp         # Main window implementation
├── mainwindow.h           # Main window header
├── mainwindow.ui          # Qt UI design file
├── CMakeLists.txt         # CMake build configuration
├── LICENSE                # MIT license
└── README.md              # This file
```

## 🔧 Development Status

⚠️ **Early Development**: This project is currently in active development. Core features are being implemented and the application is not yet ready for production use.

### Current Progress
- [x] Basic Qt application structure
- [x] CMake build system setup
- [x] MIT license configuration
- [ ] Network communication layer
- [ ] Encryption implementation
- [ ] User interface design
- [ ] LAN discovery mechanism
- [ ] WAN server/client architecture
- [ ] Message handling system
- [ ] Security features

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

## 🚧 Roadmap

- [ ] Complete core networking functionality
- [ ] Implement end-to-end encryption
- [ ] Design intuitive user interface
- [ ] Add file sharing capabilities
- [ ] Multi-platform testing and optimization
- [ ] Documentation and user guides

---

**Note**: This is an early-stage project under active development. Features and functionality are subject to change.
