# AoE2 AI Module

| Branch        | Build         | Build Documentation |
| ------------- | ------------- | ------------------- |
| main          | ![Build](https://github.com/FLWL/aoe2-ai-module/workflows/Build/badge.svg?branch=main) | ![Build Documentation](https://github.com/FLWL/aoe2-ai-module/workflows/Build%20Documentation/badge.svg?branch=main)  |
| dev           | ![Build](https://github.com/FLWL/aoe2-ai-module/workflows/Build/badge.svg?branch=dev) | ![Build Documentation](https://github.com/FLWL/aoe2-ai-module/workflows/Build%20Documentation/badge.svg?branch=dev)  |

# Introduction
This project is aimed at extending the possibilities of AI scripting in Age of Empires 2 beyond the built-in rule-based system. This is mainly accomplished by exposing the fact and action functions that the game uses internally to an outside scripting environment chosen by the user.

The AI module consists of a DLL file that has to be loaded into the Age of Empires process, after which it starts a gRPC server on port 37412 by default. Available gRPC definitions can be seen in the `protos` folder and in the project's wiki. These can be used from virtually any scripting environment the gRPC framework is available on. A Python example has been provided in the `client_python` folder.

At the moment the 32-bit version of the module supports AoC with Userpatch 1.5 and the 64-bit one supports builds 43210 and higher.

Note that this library is still under development and is not an easy to use solution just yet. There may be bugs, unsupported functionality and the release binaries might not always be up to date.

# Compiling
* Clone this repository.
* Install Microsoft Visual Studio 2019 with support for "Desktop development with C++" component.
* Install Microsoft vcpkg package manager (https://github.com/microsoft/vcpkg#quick-start-windows). By default the build scripts assume that it is installed in `aoe2-ai-module/vcpkg`, where `aoe2-ai-module` is the top level directory of this repository.
* Install necessary C++ libraries with the command `.\vcpkg\vcpkg install --recurse @.\aimodule\vcpkg_dependencies.txt --clean-after-build`.
* Run `.\protos\make-protos.bat` to convert .proto files in the `protos` directory to useful C++ and Python includes into folders `aimodule/protos` and `client_python/protos` respectively. Edit paths in `.\protos\make-protos.bat` if using a different directory structure.
* Open `aimodule/aimodule.sln` with Visual Studio.
* Build an x86 (for AoC) or x64 (for DE) Release build for the `aimodule` project.
* DLLs will be available in `aimodule/Release/aimodule.dll` and `aimodule/x64/Release/aimodule.dll` respectively.

There are also automated builds by GitHub Actions available under the Releases section.

# Dependencies
* gRPC C++ framework
* Google Protocol Buffers
* Microsoft Detours
* Zydis

# Known issues
* DE: The module can trip the anti-tampering mechanism and/or crash the game sometimes.

# Disclaimer
* This library interfaces with Age of Empires 2: Definitive Edition in ways that are not officially supported by the developers of the game. While the authors of this library try to minimize its impact on the normal operation of the game, it cannot be guaranteed due to the nature of the design. It is therefore recommendeed to use this software only in offline mode in local single player matches. The authors of this library do not provide any kind of warranty nor take liability for the consequences of (mis)using this software. See the license document for further details.
