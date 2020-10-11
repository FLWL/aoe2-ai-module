#pragma once
#include "google/protobuf/any.pb.h"

class ExpertActionHandler
{
public:
	static void Train(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult);
	static void Build(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult);
	static void UpGetFact(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult);

private:
	ExpertActionHandler() {};
};

