# AoE2 AI Module

# Introduction
This project is aimed at extending the possibilities of AI scripting in Age of Empires 2 beyond the built-in rule-based system. This is mainly accomplished by exposing the fact and action functions that the game uses internally to an outside scripting environment chosen by the user.

The AI module consists of a DLL file that has to be loaded into the Age of Empires process, after which it starts a gRPC server on port 37412 by default. Available gRPC definitions can be seen in the `protos` folder. These can be used from virtually any scripting environment the gRPC framework is available on. A Python example has been provided in the `client_python` folder.

# Compiling
* Install Microsoft Visual Studio 2017 or later with support for components "Desktop development with C++" and "Windows 10 SDK"
* Install Microsoft vcpkg package manager (https://github.com/microsoft/vcpkg#quick-start-windows)
* Install gRPC C++ libraries with the command `vcpkg install grpc:x64-windows-static`
* Install Detours with the command `vcpkg install detours:x64-windows-static`
* Clone this repository.
* Edit `protoc_path`, `grpc_cpp_path`, `grpc_python_path` and `standard_include_path` in  `protos/make-protos.bat` file to point to correct gRPC and Protocol Buffers files installed earlier with vcpkg.
* Run `protos/make-protos.bat` to convert .proto files in the `protos` directory to useful C++ and Python includes in folders `aimodule/protos` and `client_python/protos` respectively.
* Open `aimodule/aimodule.sln` with Visual Studio.
* Build an x64 Release build for the `aimodule` project.
* DLL will be available in `aimodule/x64/Release/aimodule.dll`.

# Dependencies
* gRPC C++ framework
* Google Protocol Buffers
* Microsoft Detours

# Disclaimer
* This library interfaces with Age of Empires 2: Definitive Edition in ways that are not officially supported by the developers of the game. While the authors of this library try to minimize its impact on the normal operation of the game, it cannot be guaranteed due to the nature of the design. It is therefore recommendeed to use this software only in offline mode in local single player matches. The authors of this library do not provide any kind of warranty nor take liability for the consequences of (mis)using this software. See the license document for further details.
