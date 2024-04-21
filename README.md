# Chat App 🗨️

This project is a chat application designed for real-time communication between users. It consists of a server-side component written in `C` and a client-side application developed using `Java` and `Java Swing`. The application aims to provide a user-friendly interface for text-based chat, enabling users to exchange messages, share photos, and send various documents.

## 📂 Structure

```text
project_root/
|- server/
|  |- bin/          # Compiled server executable files (.exe)
|  |- build/        # Temporary build artifacts (object files, .o)
|  |- include/      # Header files (.h)
|  |- src/          # Source code files (.c)
|  |- Makefile      # Makefile for building and running the server
|  |- README.md     # Explains how to build and run the server
|- client/
|  |- .vscode/      # VS Code configuration folder 
|  |- bin/          # Compiled client application binaries 
|  |- lib/          # External libraries used by the client project
|  |- src/          # Client source code files (.java)
|  |    |- assets   
|  |- README.md     # Brief explanation of the code
|- README.md        # Top-level project README
```

## ✨ Key Features

* **Real-time chat:** Facilitate seamless communication among users through instant messaging.

* **File sharing:** Allow users to share photos, documents, and other supported files with each other.

## 🛠️ Technologies

* `C`: Used for implementing the server-side functionality, handling network communication, and managing user connections.

* `Java`: Employed for developing the client-side application, providing the graphical user interface, and handling message transmission and reception.

* `Java Swing`: Utilized to create the graphical components of the client interface, ensuring a consistent look and feel across different platforms.

## 🎯 Objectives

* Enhance the client chat interface with improved usability and visual appeal.

* Implement support for sending and receiving various file formats, including images, documents, and compressed files.

* Explore the integration of additional features, such as group chat functionality (e.g., private groups, public channels), user authentication, and message encryption
