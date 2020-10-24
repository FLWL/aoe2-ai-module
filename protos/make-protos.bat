@echo off
set vcpkg_path=%VCPKG_ROOT%/vcpkg
set protoc_path=%VCPKG_ROOT%/installed/x64-windows-static/tools/protobuf/protoc.exe
set grpc_cpp_path=%VCPKG_ROOT%/installed/x64-windows-static/tools/grpc/grpc_cpp_plugin.exe
set grpc_python_path=%VCPKG_ROOT%/installed/x64-windows-static/tools/grpc/grpc_python_plugin.exe
set standard_include_path=%VCPKG_ROOT%/installed/x64-windows-static/include

:: cpp protobuf files
%protoc_path% -I . -I %standard_include_path% --cpp_out aimodule/ protos/ai_module_api.proto
%protoc_path% -I . -I %standard_include_path% --cpp_out aimodule/ protos/expert/expert_api.proto
%protoc_path% -I . -I %standard_include_path% --cpp_out aimodule/ protos/expert/action/action.proto
%protoc_path% -I . -I %standard_include_path% --cpp_out aimodule/ protos/expert/fact/fact.proto
:: cpp grpc files
%protoc_path% -I . -I %standard_include_path% --grpc_out aimodule/ --plugin=protoc-gen-grpc=%grpc_cpp_path% protos/ai_module_api.proto
%protoc_path% -I . -I %standard_include_path% --grpc_out aimodule/ --plugin=protoc-gen-grpc=%grpc_cpp_path% protos/expert/expert_api.proto

:: Python protobuf files
%protoc_path% -I . -I %standard_include_path% --python_out client_python/ protos/ai_module_api.proto
%protoc_path% -I . -I %standard_include_path% --python_out client_python/ protos/expert/expert_api.proto
%protoc_path% -I . -I %standard_include_path% --python_out client_python/ protos/expert/action/action.proto
%protoc_path% -I . -I %standard_include_path% --python_out client_python/ protos/expert/fact/fact.proto
:: Python grpc files
%protoc_path% -I . -I %standard_include_path% --grpc_out client_python/ --plugin=protoc-gen-grpc=%grpc_python_path% protos/ai_module_api.proto
%protoc_path% -I . -I %standard_include_path% --grpc_out client_python/ --plugin=protoc-gen-grpc=%grpc_python_path% protos/expert/expert_api.proto

echo All done