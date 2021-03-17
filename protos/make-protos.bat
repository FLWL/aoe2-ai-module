@echo off
set workspace_path=%~dp0..
set vcpkg_path=%workspace_path%\vcpkg
set protoc_path=%vcpkg_path%\installed\x64-windows-static\tools\protobuf\protoc.exe
set grpc_cpp_path=%vcpkg_path%\installed\x64-windows-static\tools\grpc\grpc_cpp_plugin.exe
set grpc_python_path=%vcpkg_path%\installed\x64-windows-static\tools\grpc\grpc_python_plugin.exe
set standard_include_path=%vcpkg_path%\installed\x64-windows-static\include

echo Generating AIModule C++ protobuf includes
%protoc_path% -I %workspace_path% -I %standard_include_path% --cpp_out %workspace_path%\aimodule\ protos/ai_module_api.proto
%protoc_path% -I %workspace_path% -I %standard_include_path% --cpp_out %workspace_path%\aimodule\ protos/expert/expert_api.proto
%protoc_path% -I %workspace_path% -I %standard_include_path% --cpp_out %workspace_path%\aimodule\ protos/expert/action/action.proto
%protoc_path% -I %workspace_path% -I %standard_include_path% --cpp_out %workspace_path%\aimodule\ protos/expert/command/command.proto
%protoc_path% -I %workspace_path% -I %standard_include_path% --cpp_out %workspace_path%\aimodule\ protos/expert/fact/fact.proto
echo Generating AIModule C++ grpc includes
%protoc_path% -I %workspace_path% -I %standard_include_path% --grpc_out %workspace_path%\aimodule\ --plugin=protoc-gen-grpc=%grpc_cpp_path% protos/ai_module_api.proto
%protoc_path% -I %workspace_path% -I %standard_include_path% --grpc_out %workspace_path%\aimodule\ --plugin=protoc-gen-grpc=%grpc_cpp_path% protos/expert/expert_api.proto

echo Generating AIModule Python protobuf includes
%protoc_path% -I %workspace_path% -I %standard_include_path% --python_out %workspace_path%\client_python\ protos/ai_module_api.proto
%protoc_path% -I %workspace_path% -I %standard_include_path% --python_out %workspace_path%\client_python\ protos/expert/expert_api.proto
%protoc_path% -I %workspace_path% -I %standard_include_path% --python_out %workspace_path%\client_python\ protos/expert/action/action.proto
%protoc_path% -I %workspace_path% -I %standard_include_path% --python_out %workspace_path%\client_python\ protos/expert/command/command.proto
%protoc_path% -I %workspace_path% -I %standard_include_path% --python_out %workspace_path%\client_python\ protos/expert/fact/fact.proto
echo Generating AIModule Python grpc includes
%protoc_path% -I %workspace_path% -I %standard_include_path% --grpc_out %workspace_path%\client_python\ --plugin=protoc-gen-grpc=%grpc_python_path% protos/ai_module_api.proto
%protoc_path% -I %workspace_path% -I %standard_include_path% --grpc_out %workspace_path%\client_python\ --plugin=protoc-gen-grpc=%grpc_python_path% protos/expert/expert_api.proto

echo Protobuf+grpc file generation finished
