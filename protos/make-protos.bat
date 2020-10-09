cd ..
set protoc_path=vcpkg/installed/x64-windows/tools/protobuf/protoc.exe
set grpc_cpp_path=vcpkg/installed/x64-windows/tools/grpc/grpc_cpp_plugin.exe
set grpc_python_path=vcpkg/installed/x64-windows/tools/grpc/grpc_python_plugin.exe

:: cpp protobuf files
%cd%/%protoc_path% --cpp_out aimodule/ protos/ai_module_api.proto
%cd%/%protoc_path% --cpp_out aimodule/ protos/expert/expert_api.proto
%cd%/%protoc_path% --cpp_out aimodule/ protos/expert/action/action.proto
%cd%/%protoc_path% --cpp_out aimodule/ protos/expert/fact/fact.proto
:: cpp grpc files
%cd%/%protoc_path% -I . --grpc_out aimodule/ --plugin=protoc-gen-grpc=%cd%/%grpc_cpp_path% protos/ai_module_api.proto
%cd%/%protoc_path% -I . --grpc_out aimodule/ --plugin=protoc-gen-grpc=%cd%/%grpc_cpp_path% protos/expert/expert_api.proto

:: Python protobuf files
%cd%/%protoc_path% --python_out client_python/ protos/ai_module_api.proto
%cd%/%protoc_path% --python_out client_python/ protos/expert/expert_api.proto
%cd%/%protoc_path% --python_out client_python/ protos/expert/action/action.proto
%cd%/%protoc_path% --python_out client_python/ protos/expert/fact/fact.proto
:: Python grpc files
%cd%/%protoc_path% -I . --grpc_out client_python/ --plugin=protoc-gen-grpc=%cd%/%grpc_python_path% protos/ai_module_api.proto
%cd%/%protoc_path% -I . --grpc_out client_python/ --plugin=protoc-gen-grpc=%cd%/%grpc_python_path% protos/expert/expert_api.proto
pause