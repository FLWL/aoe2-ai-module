#pragma once
#include "google/protobuf/any.pb.h"

class ExpertFactHandler
{
public:
	static void UpGetFact(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult);
	static void Goal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult);
	static void Goals(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult);
	
private:
	ExpertFactHandler() {};
};

