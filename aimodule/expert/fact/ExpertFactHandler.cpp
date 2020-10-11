#include "ExpertFactHandler.h"

#include "expert/fact/ExpertFact.h"
#include "protos/expert/expert_api.pb.h"
#include "protos/expert/fact/fact.pb.h"

void ExpertFactHandler::UpGetFact(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpGetFact command;
	anyCommand.UnpackTo(&command);

	protos::expert::fact::UpGetFactResult result;
	result.set_factvalue(ExpertFact::UpGetFact(command.factid(), command.factparam()));

	anyResult->PackFrom(result);
}

void ExpertFactHandler::Goal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::Goal command;
	anyCommand.UnpackTo(&command);

	protos::expert::fact::GoalResult result;
	result.set_goalvalue(ExpertFact::Goal(command.goalid()));

	anyResult->PackFrom(result);
}

void ExpertFactHandler::Goals(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::Goals command;
	anyCommand.UnpackTo(&command);

	protos::expert::fact::GoalsResult result;
	auto goals = ExpertFact::Goals();
	for (const auto &goal : goals) result.add_goalvalue(goal);

	anyResult->PackFrom(result);
}
