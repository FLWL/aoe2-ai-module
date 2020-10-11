#include "ExpertActionHandler.h"

#include "expert/action/ExpertAction.h"
#include "protos/expert/action/action.pb.h"

void ExpertActionHandler::Train(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::Train command;
	anyCommand.UnpackTo(&command);

	protos::expert::action::TrainResult result;
	result.set_success(ExpertAction::Train(command.unittype()));

	anyResult->PackFrom(result);
}

void ExpertActionHandler::Build(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::Build command;
	anyCommand.UnpackTo(&command);

	protos::expert::action::BuildResult result;
	result.set_success(ExpertAction::Build(command.buildingtype()));

	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetFact(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetFact command;
	anyCommand.UnpackTo(&command);

	protos::expert::action::UpGetFactResult result;
	ExpertAction::UpGetFact(command.factid(), command.factparam(), command.goalid());

	anyResult->PackFrom(result);
}

