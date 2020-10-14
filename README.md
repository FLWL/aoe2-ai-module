# aoe2-ai-module

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
* 
