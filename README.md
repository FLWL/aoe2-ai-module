# AoE2 AI Module
![Build](https://github.com/FLWL/aoe2-ai-module/workflows/Build/badge.svg?branch=main) ![Build Documentation](https://github.com/FLWL/aoe2-ai-module/workflows/Build%20Documentation/badge.svg?branch=main) (main)

![Build](https://github.com/FLWL/aoe2-ai-module/workflows/Build/badge.svg?branch=dev) ![Build Documentation](https://github.com/FLWL/aoe2-ai-module/workflows/Build%20Documentation/badge.svg?branch=dev) (dev)

# Introduction
This project is aimed at extending the possibilities of AI scripting in Age of Empires 2 beyond the built-in rule-based system. This is mainly accomplished by exposing the fact and action functions that the game uses internally to an outside scripting environment chosen by the user.

The AI module consists of a DLL file that has to be loaded into the Age of Empires process, after which it starts a gRPC server on port 37412 by default. Available gRPC definitions can be seen in the `protos` folder and in the project's wiki. These can be used from virtually any scripting environment the gRPC framework is available on. A Python example has been provided in the `client_python` folder. Note that currently there is no DLL loader included, but that might change in a future release.

Currently the only supported version of the game is the Definitive Edition. If there is interest in using this library with older releases then backporting to AoC+Userpatch or HD Edition should not be too difficult considering the similarities of AI systems in all these versions and might be taken into consideration.

# Compiling
* Clone this repository.
* Install Microsoft Visual Studio 2019 with support for "Desktop development with C++" component.
* Install Microsoft vcpkg package manager (https://github.com/microsoft/vcpkg#quick-start-windows). By default the build scripts assume that it is installed in `aoe2-ai-module/vcpkg`, where `aoe2-ai-module` is the top level directory of this repository.
* Install necessary C++ libraries with the command `vcpkg install grpc detours --triplet x64-windows-static`.
* Edit `vcpkg_path` in `protos/make-protos.bat` if necessary to point to the directory where vcpkg was installed.
* Run `protos/make-protos.bat` to convert .proto files in the `protos` directory to useful C++ and Python includes into folders `aimodule/protos` and `client_python/protos` respectively.
* Open `aimodule/aimodule.sln` with Visual Studio.
* Build an x64 Release build for the `aimodule` project.
* DLL will be available in `aimodule/x64/Release/aimodule.dll`.

There are also automated builds by GitHub Actions available under the Releases section.

# Dependencies
* gRPC C++ framework
* Google Protocol Buffers
* Microsoft Detours

# Disclaimer
* This library interfaces with Age of Empires 2: Definitive Edition in ways that are not officially supported by the developers of the game. While the authors of this library try to minimize its impact on the normal operation of the game, it cannot be guaranteed due to the nature of the design. It is therefore recommendeed to use this software only in offline mode in local single player matches. The authors of this library do not provide any kind of warranty nor take liability for the consequences of (mis)using this software. See the license document for further details.
