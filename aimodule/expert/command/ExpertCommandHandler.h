#pragma once
#include "google/protobuf/any.pb.h"
#include "protos/expert/command/command.pb.h"

class ExpertCommandHandler
{
public:
	static void GetMapDimensions(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult);
	static void GetTiles(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult);
	static void GetUnits(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult);

private:
	static int GeneralizeTerrainType(int terrainId);
};
