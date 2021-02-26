#include "ExpertActionHandler.h"

#include "expert/action/ExpertAction.h"
#include "protos/expert/action/action.pb.h"

void ExpertActionHandler::AcknowledgeEvent(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::AcknowledgeEvent command;
	anyCommand.UnpackTo(&command);

	ExpertAction::AcknowledgeEvent(command.inconsteventtype(), command.inconsteventid());

	protos::expert::action::AcknowledgeEventResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::AcknowledgeTaunt(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::AcknowledgeTaunt command;
	anyCommand.UnpackTo(&command);

	ExpertAction::AcknowledgeTaunt(command.inplayeranyplayer(), command.inconsttauntid());

	protos::expert::action::AcknowledgeTauntResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::AttackNow(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::AttackNow command;
	anyCommand.UnpackTo(&command);

	ExpertAction::AttackNow();

	protos::expert::action::AttackNowResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::Build(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::Build command;
	anyCommand.UnpackTo(&command);

	ExpertAction::Build(command.inconstbuildingid());

	protos::expert::action::BuildResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::BuildForward(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::BuildForward command;
	anyCommand.UnpackTo(&command);

	ExpertAction::BuildForward(command.inconstbuildingid());

	protos::expert::action::BuildForwardResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::BuildGate(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::BuildGate command;
	anyCommand.UnpackTo(&command);

	ExpertAction::BuildGate(command.inconstperimeter());

	protos::expert::action::BuildGateResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::BuildWall(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::BuildWall command;
	anyCommand.UnpackTo(&command);

	ExpertAction::BuildWall(command.inconstperimeter(), command.inconstwallid());

	protos::expert::action::BuildWallResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::BuyCommodity(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::BuyCommodity command;
	anyCommand.UnpackTo(&command);

	ExpertAction::BuyCommodity(command.inconstcommodity());

	protos::expert::action::BuyCommodityResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::CcAddResource(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::CcAddResource command;
	anyCommand.UnpackTo(&command);

	ExpertAction::CcAddResource(command.inconstresource(), command.inconstvalue());

	protos::expert::action::CcAddResourceResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatLocal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatLocal command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatLocal(command.intextstring());

	protos::expert::action::ChatLocalResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatLocalUsingId(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatLocalUsingId command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatLocalUsingId(command.inconstlanguageid());

	protos::expert::action::ChatLocalUsingIdResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatLocalUsingRange(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatLocalUsingRange command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatLocalUsingRange(command.inconstlanguageid(), command.inconstvalue());

	protos::expert::action::ChatLocalUsingRangeResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatLocalToSelf(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatLocalToSelf command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatLocalToSelf(command.intextstring());

	protos::expert::action::ChatLocalToSelfResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatToAll(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatToAll command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatToAll(command.intextstring());

	protos::expert::action::ChatToAllResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatToAllUsingId(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatToAllUsingId command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatToAllUsingId(command.inconstlanguageid());

	protos::expert::action::ChatToAllUsingIdResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatToAllUsingRange(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatToAllUsingRange command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatToAllUsingRange(command.inconstlanguageid(), command.inconstvalue());

	protos::expert::action::ChatToAllUsingRangeResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatToAllies(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatToAllies command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatToAllies(command.intextstring());

	protos::expert::action::ChatToAlliesResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatToAlliesUsingId(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatToAlliesUsingId command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatToAlliesUsingId(command.inconstlanguageid());

	protos::expert::action::ChatToAlliesUsingIdResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatToAlliesUsingRange(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatToAlliesUsingRange command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatToAlliesUsingRange(command.inconstlanguageid(), command.inconstvalue());

	protos::expert::action::ChatToAlliesUsingRangeResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatToEnemies(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatToEnemies command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatToEnemies(command.intextstring());

	protos::expert::action::ChatToEnemiesResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatToEnemiesUsingId(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatToEnemiesUsingId command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatToEnemiesUsingId(command.inconstlanguageid());

	protos::expert::action::ChatToEnemiesUsingIdResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatToEnemiesUsingRange(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatToEnemiesUsingRange command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatToEnemiesUsingRange(command.inconstlanguageid(), command.inconstvalue());

	protos::expert::action::ChatToEnemiesUsingRangeResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatToPlayer(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatToPlayer command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatToPlayer(command.inplayeranyplayer(), command.intextstring());

	protos::expert::action::ChatToPlayerResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatToPlayerUsingId(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatToPlayerUsingId command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatToPlayerUsingId(command.inplayeranyplayer(), command.inconstlanguageid());

	protos::expert::action::ChatToPlayerUsingIdResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatToPlayerUsingRange(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatToPlayerUsingRange command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatToPlayerUsingRange(command.inplayeranyplayer(), command.inconstlanguageid(), command.inconstvalue());

	protos::expert::action::ChatToPlayerUsingRangeResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatTrace(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatTrace command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatTrace(command.inconstvalue());

	protos::expert::action::ChatTraceResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ClearTributeMemory(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ClearTributeMemory command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ClearTributeMemory(command.inplayeranyplayer(), command.inconstresource());

	protos::expert::action::ClearTributeMemoryResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::DeleteBuilding(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::DeleteBuilding command;
	anyCommand.UnpackTo(&command);

	ExpertAction::DeleteBuilding(command.inconstbuildingid());

	protos::expert::action::DeleteBuildingResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::DeleteUnit(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::DeleteUnit command;
	anyCommand.UnpackTo(&command);

	ExpertAction::DeleteUnit(command.inconstunitid());

	protos::expert::action::DeleteUnitResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::DisableRule(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::DisableRule command;
	anyCommand.UnpackTo(&command);

	ExpertAction::DisableRule(command.inconstrulegroupid());

	protos::expert::action::DisableRuleResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::DisableSelf(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::DisableSelf command;
	anyCommand.UnpackTo(&command);

	ExpertAction::DisableSelf();

	protos::expert::action::DisableSelfResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::DisableTimer(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::DisableTimer command;
	anyCommand.UnpackTo(&command);

	ExpertAction::DisableTimer(command.inconsttimerid());

	protos::expert::action::DisableTimerResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::DoNothing(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::DoNothing command;
	anyCommand.UnpackTo(&command);

	ExpertAction::DoNothing();

	protos::expert::action::DoNothingResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::EnableRule(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::EnableRule command;
	anyCommand.UnpackTo(&command);

	ExpertAction::EnableRule(command.inconstrulegroupid());

	protos::expert::action::EnableRuleResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::EnableTimer(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::EnableTimer command;
	anyCommand.UnpackTo(&command);

	ExpertAction::EnableTimer(command.inconsttimerid(), command.inconstvalue());

	protos::expert::action::EnableTimerResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::EnableWallPlacement(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::EnableWallPlacement command;
	anyCommand.UnpackTo(&command);

	ExpertAction::EnableWallPlacement(command.inconstperimeter());

	protos::expert::action::EnableWallPlacementResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::GenerateRandomNumber(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::GenerateRandomNumber command;
	anyCommand.UnpackTo(&command);

	ExpertAction::GenerateRandomNumber(command.inconstvalue());

	protos::expert::action::GenerateRandomNumberResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::Log(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::Log command;
	anyCommand.UnpackTo(&command);

	ExpertAction::Log(command.intextstring());

	protos::expert::action::LogResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::LogTrace(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::LogTrace command;
	anyCommand.UnpackTo(&command);

	ExpertAction::LogTrace(command.inconstvalue());

	protos::expert::action::LogTraceResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ReleaseEscrow(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ReleaseEscrow command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ReleaseEscrow(command.inconstresource());

	protos::expert::action::ReleaseEscrowResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::Research(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::Research command;
	anyCommand.UnpackTo(&command);

	ExpertAction::Research(command.inconsttechid());

	protos::expert::action::ResearchResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::Resign(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::Resign command;
	anyCommand.UnpackTo(&command);

	ExpertAction::Resign();

	protos::expert::action::ResignResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::SellCommodity(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::SellCommodity command;
	anyCommand.UnpackTo(&command);

	ExpertAction::SellCommodity(command.inconstcommodity());

	protos::expert::action::SellCommodityResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::SetAuthorName(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::SetAuthorName command;
	anyCommand.UnpackTo(&command);

	ExpertAction::SetAuthorName(command.intextstring());

	protos::expert::action::SetAuthorNameResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::SetAuthorEmail(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::SetAuthorEmail command;
	anyCommand.UnpackTo(&command);

	ExpertAction::SetAuthorEmail(command.intextstring());

	protos::expert::action::SetAuthorEmailResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::SetAuthorVersion(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::SetAuthorVersion command;
	anyCommand.UnpackTo(&command);

	ExpertAction::SetAuthorVersion(command.intextstring());

	protos::expert::action::SetAuthorVersionResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::SetDifficultyParameter(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::SetDifficultyParameter command;
	anyCommand.UnpackTo(&command);

	ExpertAction::SetDifficultyParameter(command.inconstdiffparameterid(), command.inconstvalue());

	protos::expert::action::SetDifficultyParameterResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::SetDoctrine(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::SetDoctrine command;
	anyCommand.UnpackTo(&command);

	ExpertAction::SetDoctrine(command.inconstvalue());

	protos::expert::action::SetDoctrineResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::SetEscrowPercentage(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::SetEscrowPercentage command;
	anyCommand.UnpackTo(&command);

	ExpertAction::SetEscrowPercentage(command.inconstresource(), command.inconstvalue());

	protos::expert::action::SetEscrowPercentageResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::SetGoal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::SetGoal command;
	anyCommand.UnpackTo(&command);

	ExpertAction::SetGoal(command.inconstgoalid(), command.inconstvalue());

	protos::expert::action::SetGoalResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::SetSharedGoal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::SetSharedGoal command;
	anyCommand.UnpackTo(&command);

	ExpertAction::SetSharedGoal(command.inconstgoalid(), command.inconstvalue());

	protos::expert::action::SetSharedGoalResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::SetSignal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::SetSignal command;
	anyCommand.UnpackTo(&command);

	ExpertAction::SetSignal(command.inconstsignalid());

	protos::expert::action::SetSignalResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::SetStance(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::SetStance command;
	anyCommand.UnpackTo(&command);

	ExpertAction::SetStance(command.inplayeranyplayer(), command.inconstesplayerstance());

	protos::expert::action::SetStanceResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::SetStrategicNumber(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::SetStrategicNumber command;
	anyCommand.UnpackTo(&command);

	ExpertAction::SetStrategicNumber(command.inconstsnid(), command.inconstvalue());

	protos::expert::action::SetStrategicNumberResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::Spy(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::Spy command;
	anyCommand.UnpackTo(&command);

	ExpertAction::Spy();

	protos::expert::action::SpyResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::Taunt(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::Taunt command;
	anyCommand.UnpackTo(&command);

	ExpertAction::Taunt(command.inconsttauntid());

	protos::expert::action::TauntResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::TauntUsingRange(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::TauntUsingRange command;
	anyCommand.UnpackTo(&command);

	ExpertAction::TauntUsingRange(command.inconsttauntid(), command.inconstvalue());

	protos::expert::action::TauntUsingRangeResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::Train(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::Train command;
	anyCommand.UnpackTo(&command);

	ExpertAction::Train(command.inconstunitid());

	protos::expert::action::TrainResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::TributeToPlayer(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::TributeToPlayer command;
	anyCommand.UnpackTo(&command);

	ExpertAction::TributeToPlayer(command.inplayeranyplayer(), command.inconstresource(), command.inconstvalue());

	protos::expert::action::TributeToPlayerResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpAddCostData(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpAddCostData command;
	anyCommand.UnpackTo(&command);

	switch (command.value_case())
	{
		default:
		case protos::expert::action::UpAddCostData::kInConstValue:
		{
			ExpertAction::UpAddCostData(command.ingoalid(), expert_conf::CONST_TYPE_OP_CONST, command.inconstvalue());
			break;
		}
		case protos::expert::action::UpAddCostData::kInGoalValue:
		{
			ExpertAction::UpAddCostData(command.ingoalid(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalvalue());
			break;
		}
		case protos::expert::action::UpAddCostData::kInSnValue:
		{
			ExpertAction::UpAddCostData(command.ingoalid(), expert_conf::CONST_TYPE_OP_SN, command.insnvalue());
			break;
		}
	}

	protos::expert::action::UpAddCostDataResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpAddObjectById(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpAddObjectById command;
	anyCommand.UnpackTo(&command);

	switch (command.id_case())
	{
		default:
		case protos::expert::action::UpAddObjectById::kInConstId:
		{
			ExpertAction::UpAddObjectById(command.inconstsearchsource(), expert_conf::CONST_TYPE_OP_CONST, command.inconstid());
			break;
		}
		case protos::expert::action::UpAddObjectById::kInGoalId:
		{
			ExpertAction::UpAddObjectById(command.inconstsearchsource(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalid());
			break;
		}
		case protos::expert::action::UpAddObjectById::kInSnId:
		{
			ExpertAction::UpAddObjectById(command.inconstsearchsource(), expert_conf::CONST_TYPE_OP_SN, command.insnid());
			break;
		}
	}

	protos::expert::action::UpAddObjectByIdResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpAddObjectCost(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpAddObjectCost command;
	anyCommand.UnpackTo(&command);

	int objectIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
	int objectId = 0;
	switch (command.objectId_case())
	{
		default:
		case protos::expert::action::UpAddObjectCost::kInConstObjectId:
		{
			objectIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
			objectId = command.inconstobjectid();
			break;
		}
		case protos::expert::action::UpAddObjectCost::kInGoalObjectId:
		{
			objectIdTypeOp = expert_conf::CONST_TYPE_OP_GOAL;
			objectId = command.ingoalobjectid();
			break;
		}
		case protos::expert::action::UpAddObjectCost::kInSnObjectId:
		{
			objectIdTypeOp = expert_conf::CONST_TYPE_OP_SN;
			objectId = command.insnobjectid();
			break;
		}
	}
	switch (command.value_case())
	{
		default:
		case protos::expert::action::UpAddObjectCost::kInConstValue:
		{
			ExpertAction::UpAddObjectCost(objectIdTypeOp, objectId, expert_conf::CONST_TYPE_OP_CONST, command.inconstvalue());
			break;
		}
		case protos::expert::action::UpAddObjectCost::kInGoalValue:
		{
			ExpertAction::UpAddObjectCost(objectIdTypeOp, objectId, expert_conf::CONST_TYPE_OP_GOAL, command.ingoalvalue());
			break;
		}
		case protos::expert::action::UpAddObjectCost::kInSnValue:
		{
			ExpertAction::UpAddObjectCost(objectIdTypeOp, objectId, expert_conf::CONST_TYPE_OP_SN, command.insnvalue());
			break;
		}
	}

	protos::expert::action::UpAddObjectCostResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpAddPoint(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpAddPoint command;
	anyCommand.UnpackTo(&command);

	switch (command.count_case())
	{
		default:
		case protos::expert::action::UpAddPoint::kInConstCount:
		{
			ExpertAction::UpAddPoint(command.ingoalpoint1(), command.ingoalpoint2(), expert_conf::CONST_TYPE_OP_CONST, command.inconstcount());
			break;
		}
		case protos::expert::action::UpAddPoint::kInGoalCount:
		{
			ExpertAction::UpAddPoint(command.ingoalpoint1(), command.ingoalpoint2(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalcount());
			break;
		}
		case protos::expert::action::UpAddPoint::kInSnCount:
		{
			ExpertAction::UpAddPoint(command.ingoalpoint1(), command.ingoalpoint2(), expert_conf::CONST_TYPE_OP_SN, command.insncount());
			break;
		}
	}

	protos::expert::action::UpAddPointResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpAddResearchCost(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpAddResearchCost command;
	anyCommand.UnpackTo(&command);

	int techIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
	int techId = 0;
	switch (command.techId_case())
	{
		default:
		case protos::expert::action::UpAddResearchCost::kInConstTechId:
		{
			techIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
			techId = command.inconsttechid();
			break;
		}
		case protos::expert::action::UpAddResearchCost::kInGoalTechId:
		{
			techIdTypeOp = expert_conf::CONST_TYPE_OP_GOAL;
			techId = command.ingoaltechid();
			break;
		}
		case protos::expert::action::UpAddResearchCost::kInSnTechId:
		{
			techIdTypeOp = expert_conf::CONST_TYPE_OP_SN;
			techId = command.insntechid();
			break;
		}
	}
	switch (command.value_case())
	{
		default:
		case protos::expert::action::UpAddResearchCost::kInConstValue:
		{
			ExpertAction::UpAddResearchCost(techIdTypeOp, techId, expert_conf::CONST_TYPE_OP_CONST, command.inconstvalue());
			break;
		}
		case protos::expert::action::UpAddResearchCost::kInGoalValue:
		{
			ExpertAction::UpAddResearchCost(techIdTypeOp, techId, expert_conf::CONST_TYPE_OP_GOAL, command.ingoalvalue());
			break;
		}
		case protos::expert::action::UpAddResearchCost::kInSnValue:
		{
			ExpertAction::UpAddResearchCost(techIdTypeOp, techId, expert_conf::CONST_TYPE_OP_SN, command.insnvalue());
			break;
		}
	}

	protos::expert::action::UpAddResearchCostResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpAssignBuilders(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpAssignBuilders command;
	anyCommand.UnpackTo(&command);

	int buildingIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
	int buildingId = 0;
	switch (command.buildingId_case())
	{
		default:
		case protos::expert::action::UpAssignBuilders::kInConstBuildingId:
		{
			buildingIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
			buildingId = command.inconstbuildingid();
			break;
		}
		case protos::expert::action::UpAssignBuilders::kInGoalBuildingId:
		{
			buildingIdTypeOp = expert_conf::CONST_TYPE_OP_GOAL;
			buildingId = command.ingoalbuildingid();
			break;
		}
		case protos::expert::action::UpAssignBuilders::kInSnBuildingId:
		{
			buildingIdTypeOp = expert_conf::CONST_TYPE_OP_SN;
			buildingId = command.insnbuildingid();
			break;
		}
	}
	switch (command.value_case())
	{
		default:
		case protos::expert::action::UpAssignBuilders::kInConstValue:
		{
			ExpertAction::UpAssignBuilders(buildingIdTypeOp, buildingId, expert_conf::CONST_TYPE_OP_CONST, command.inconstvalue());
			break;
		}
		case protos::expert::action::UpAssignBuilders::kInGoalValue:
		{
			ExpertAction::UpAssignBuilders(buildingIdTypeOp, buildingId, expert_conf::CONST_TYPE_OP_GOAL, command.ingoalvalue());
			break;
		}
		case protos::expert::action::UpAssignBuilders::kInSnValue:
		{
			ExpertAction::UpAssignBuilders(buildingIdTypeOp, buildingId, expert_conf::CONST_TYPE_OP_SN, command.insnvalue());
			break;
		}
	}

	protos::expert::action::UpAssignBuildersResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpBoundPoint(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpBoundPoint command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpBoundPoint(command.outgoalpoint(), command.ingoalpoint());

	protos::expert::action::UpBoundPointResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpBoundPrecisePoint(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpBoundPrecisePoint command;
	anyCommand.UnpackTo(&command);

	switch (command.border_case())
	{
		default:
		case protos::expert::action::UpBoundPrecisePoint::kInConstBorder:
		{
			ExpertAction::UpBoundPrecisePoint(command.ingoalpoint(), command.inconstprecise(), expert_conf::CONST_TYPE_OP_CONST, command.inconstborder());
			break;
		}
		case protos::expert::action::UpBoundPrecisePoint::kInGoalBorder:
		{
			ExpertAction::UpBoundPrecisePoint(command.ingoalpoint(), command.inconstprecise(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalborder());
			break;
		}
		case protos::expert::action::UpBoundPrecisePoint::kInSnBorder:
		{
			ExpertAction::UpBoundPrecisePoint(command.ingoalpoint(), command.inconstprecise(), expert_conf::CONST_TYPE_OP_SN, command.insnborder());
			break;
		}
	}

	protos::expert::action::UpBoundPrecisePointResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpBuild(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpBuild command;
	anyCommand.UnpackTo(&command);

	switch (command.buildingId_case())
	{
		default:
		case protos::expert::action::UpBuild::kInConstBuildingId:
		{
			ExpertAction::UpBuild(command.inconstplacementtype(), command.ingoalescrowstate(), expert_conf::CONST_TYPE_OP_CONST, command.inconstbuildingid());
			break;
		}
		case protos::expert::action::UpBuild::kInGoalBuildingId:
		{
			ExpertAction::UpBuild(command.inconstplacementtype(), command.ingoalescrowstate(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalbuildingid());
			break;
		}
		case protos::expert::action::UpBuild::kInSnBuildingId:
		{
			ExpertAction::UpBuild(command.inconstplacementtype(), command.ingoalescrowstate(), expert_conf::CONST_TYPE_OP_SN, command.insnbuildingid());
			break;
		}
	}

	protos::expert::action::UpBuildResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpBuildLine(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpBuildLine command;
	anyCommand.UnpackTo(&command);

	switch (command.buildingId_case())
	{
		default:
		case protos::expert::action::UpBuildLine::kInConstBuildingId:
		{
			ExpertAction::UpBuildLine(command.ingoalpoint1(), command.ingoalpoint2(), expert_conf::CONST_TYPE_OP_CONST, command.inconstbuildingid());
			break;
		}
		case protos::expert::action::UpBuildLine::kInGoalBuildingId:
		{
			ExpertAction::UpBuildLine(command.ingoalpoint1(), command.ingoalpoint2(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalbuildingid());
			break;
		}
		case protos::expert::action::UpBuildLine::kInSnBuildingId:
		{
			ExpertAction::UpBuildLine(command.ingoalpoint1(), command.ingoalpoint2(), expert_conf::CONST_TYPE_OP_SN, command.insnbuildingid());
			break;
		}
	}

	protos::expert::action::UpBuildLineResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpBuyCommodity(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpBuyCommodity command;
	anyCommand.UnpackTo(&command);

	int resourceAmountTypeOp = expert_conf::CONST_TYPE_OP_CONST;
	int resourceAmount = 0;
	switch (command.resourceAmount_case())
	{
		default:
		case protos::expert::action::UpBuyCommodity::kInConstResourceAmount:
		{
			resourceAmountTypeOp = expert_conf::CONST_TYPE_OP_CONST;
			resourceAmount = command.inconstresourceamount();
			break;
		}
		case protos::expert::action::UpBuyCommodity::kInGoalResourceAmount:
		{
			resourceAmountTypeOp = expert_conf::CONST_TYPE_OP_GOAL;
			resourceAmount = command.ingoalresourceamount();
			break;
		}
		case protos::expert::action::UpBuyCommodity::kInSnResourceAmount:
		{
			resourceAmountTypeOp = expert_conf::CONST_TYPE_OP_SN;
			resourceAmount = command.insnresourceamount();
			break;
		}
	}
	switch (command.value_case())
	{
		default:
		case protos::expert::action::UpBuyCommodity::kInConstValue:
		{
			ExpertAction::UpBuyCommodity(resourceAmountTypeOp, resourceAmount, expert_conf::CONST_TYPE_OP_CONST, command.inconstvalue());
			break;
		}
		case protos::expert::action::UpBuyCommodity::kInGoalValue:
		{
			ExpertAction::UpBuyCommodity(resourceAmountTypeOp, resourceAmount, expert_conf::CONST_TYPE_OP_GOAL, command.ingoalvalue());
			break;
		}
		case protos::expert::action::UpBuyCommodity::kInSnValue:
		{
			ExpertAction::UpBuyCommodity(resourceAmountTypeOp, resourceAmount, expert_conf::CONST_TYPE_OP_SN, command.insnvalue());
			break;
		}
	}

	protos::expert::action::UpBuyCommodityResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpCcAddResource(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpCcAddResource command;
	anyCommand.UnpackTo(&command);

	int resourceAmountTypeOp = expert_conf::CONST_TYPE_OP_CONST;
	int resourceAmount = 0;
	switch (command.resourceAmount_case())
	{
		default:
		case protos::expert::action::UpCcAddResource::kInConstResourceAmount:
		{
			resourceAmountTypeOp = expert_conf::CONST_TYPE_OP_CONST;
			resourceAmount = command.inconstresourceamount();
			break;
		}
		case protos::expert::action::UpCcAddResource::kInGoalResourceAmount:
		{
			resourceAmountTypeOp = expert_conf::CONST_TYPE_OP_GOAL;
			resourceAmount = command.ingoalresourceamount();
			break;
		}
		case protos::expert::action::UpCcAddResource::kInSnResourceAmount:
		{
			resourceAmountTypeOp = expert_conf::CONST_TYPE_OP_SN;
			resourceAmount = command.insnresourceamount();
			break;
		}
	}
	switch (command.value_case())
	{
		default:
		case protos::expert::action::UpCcAddResource::kInConstValue:
		{
			ExpertAction::UpCcAddResource(resourceAmountTypeOp, resourceAmount, expert_conf::CONST_TYPE_OP_CONST, command.inconstvalue());
			break;
		}
		case protos::expert::action::UpCcAddResource::kInGoalValue:
		{
			ExpertAction::UpCcAddResource(resourceAmountTypeOp, resourceAmount, expert_conf::CONST_TYPE_OP_GOAL, command.ingoalvalue());
			break;
		}
		case protos::expert::action::UpCcAddResource::kInSnValue:
		{
			ExpertAction::UpCcAddResource(resourceAmountTypeOp, resourceAmount, expert_conf::CONST_TYPE_OP_SN, command.insnvalue());
			break;
		}
	}

	protos::expert::action::UpCcAddResourceResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpCcSendCheat(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpCcSendCheat command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpCcSendCheat(command.intextcode());

	protos::expert::action::UpCcSendCheatResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpChangeName(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpChangeName command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpChangeName(command.intextnewname());

	protos::expert::action::UpChangeNameResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpChatDataToAll(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpChatDataToAll command;
	anyCommand.UnpackTo(&command);

	switch (command.value_case())
	{
		default:
		case protos::expert::action::UpChatDataToAll::kInConstValue:
		{
			ExpertAction::UpChatDataToAll(command.intextformattedstring(), expert_conf::CONST_TYPE_OP_CONST, command.inconstvalue());
			break;
		}
		case protos::expert::action::UpChatDataToAll::kInGoalValue:
		{
			ExpertAction::UpChatDataToAll(command.intextformattedstring(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalvalue());
			break;
		}
		case protos::expert::action::UpChatDataToAll::kInSnValue:
		{
			ExpertAction::UpChatDataToAll(command.intextformattedstring(), expert_conf::CONST_TYPE_OP_SN, command.insnvalue());
			break;
		}
	}

	protos::expert::action::UpChatDataToAllResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpChatDataToPlayer(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpChatDataToPlayer command;
	anyCommand.UnpackTo(&command);

	switch (command.value_case())
	{
		default:
		case protos::expert::action::UpChatDataToPlayer::kInConstValue:
		{
			ExpertAction::UpChatDataToPlayer(command.inplayeranyplayer(), command.intextformattedstring(), expert_conf::CONST_TYPE_OP_CONST, command.inconstvalue());
			break;
		}
		case protos::expert::action::UpChatDataToPlayer::kInGoalValue:
		{
			ExpertAction::UpChatDataToPlayer(command.inplayeranyplayer(), command.intextformattedstring(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalvalue());
			break;
		}
		case protos::expert::action::UpChatDataToPlayer::kInSnValue:
		{
			ExpertAction::UpChatDataToPlayer(command.inplayeranyplayer(), command.intextformattedstring(), expert_conf::CONST_TYPE_OP_SN, command.insnvalue());
			break;
		}
	}

	protos::expert::action::UpChatDataToPlayerResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpChatDataToSelf(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpChatDataToSelf command;
	anyCommand.UnpackTo(&command);

	switch (command.value_case())
	{
		default:
		case protos::expert::action::UpChatDataToSelf::kInConstValue:
		{
			ExpertAction::UpChatDataToSelf(command.intextformattedstring(), expert_conf::CONST_TYPE_OP_CONST, command.inconstvalue());
			break;
		}
		case protos::expert::action::UpChatDataToSelf::kInGoalValue:
		{
			ExpertAction::UpChatDataToSelf(command.intextformattedstring(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalvalue());
			break;
		}
		case protos::expert::action::UpChatDataToSelf::kInSnValue:
		{
			ExpertAction::UpChatDataToSelf(command.intextformattedstring(), expert_conf::CONST_TYPE_OP_SN, command.insnvalue());
			break;
		}
	}

	protos::expert::action::UpChatDataToSelfResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpCleanSearch(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpCleanSearch command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpCleanSearch(command.inconstsearchsource(), command.inconstobjectdata(), command.inconstsearchorder());

	protos::expert::action::UpCleanSearchResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpCopyPoint(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpCopyPoint command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpCopyPoint(command.outgoalpoint(), command.ingoalpoint());

	protos::expert::action::UpCopyPointResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpCreateGroup(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpCreateGroup command;
	anyCommand.UnpackTo(&command);

	switch (command.groupId_case())
	{
		default:
		case protos::expert::action::UpCreateGroup::kInConstGroupId:
		{
			ExpertAction::UpCreateGroup(command.ingoalindex(), command.ingoalcount(), expert_conf::CONST_TYPE_OP_CONST, command.inconstgroupid());
			break;
		}
		case protos::expert::action::UpCreateGroup::kInGoalGroupId:
		{
			ExpertAction::UpCreateGroup(command.ingoalindex(), command.ingoalcount(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalgroupid());
			break;
		}
		case protos::expert::action::UpCreateGroup::kInSnGroupId:
		{
			ExpertAction::UpCreateGroup(command.ingoalindex(), command.ingoalcount(), expert_conf::CONST_TYPE_OP_SN, command.insngroupid());
			break;
		}
	}

	protos::expert::action::UpCreateGroupResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpCrossTiles(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpCrossTiles command;
	anyCommand.UnpackTo(&command);

	switch (command.tiles_case())
	{
		default:
		case protos::expert::action::UpCrossTiles::kInConstTiles:
		{
			ExpertAction::UpCrossTiles(command.iogoalpoint(), command.ingoalpoint(), expert_conf::CONST_TYPE_OP_CONST, command.inconsttiles());
			break;
		}
		case protos::expert::action::UpCrossTiles::kInGoalTiles:
		{
			ExpertAction::UpCrossTiles(command.iogoalpoint(), command.ingoalpoint(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoaltiles());
			break;
		}
		case protos::expert::action::UpCrossTiles::kInSnTiles:
		{
			ExpertAction::UpCrossTiles(command.iogoalpoint(), command.ingoalpoint(), expert_conf::CONST_TYPE_OP_SN, command.insntiles());
			break;
		}
	}

	protos::expert::action::UpCrossTilesResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpDeleteDistantFarms(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpDeleteDistantFarms command;
	anyCommand.UnpackTo(&command);

	switch (command.value_case())
	{
		default:
		case protos::expert::action::UpDeleteDistantFarms::kInConstValue:
		{
			ExpertAction::UpDeleteDistantFarms(expert_conf::CONST_TYPE_OP_CONST, command.inconstvalue());
			break;
		}
		case protos::expert::action::UpDeleteDistantFarms::kInGoalValue:
		{
			ExpertAction::UpDeleteDistantFarms(expert_conf::CONST_TYPE_OP_GOAL, command.ingoalvalue());
			break;
		}
		case protos::expert::action::UpDeleteDistantFarms::kInSnValue:
		{
			ExpertAction::UpDeleteDistantFarms(expert_conf::CONST_TYPE_OP_SN, command.insnvalue());
			break;
		}
	}

	protos::expert::action::UpDeleteDistantFarmsResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpDeleteIdleUnits(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpDeleteIdleUnits command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpDeleteIdleUnits(command.inconstidletype());

	protos::expert::action::UpDeleteIdleUnitsResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpDeleteObjects(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpDeleteObjects command;
	anyCommand.UnpackTo(&command);

	int unitIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
	int unitId = 0;
	switch (command.unitId_case())
	{
		default:
		case protos::expert::action::UpDeleteObjects::kInConstUnitId:
		{
			unitIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
			unitId = command.inconstunitid();
			break;
		}
		case protos::expert::action::UpDeleteObjects::kInGoalUnitId:
		{
			unitIdTypeOp = expert_conf::CONST_TYPE_OP_GOAL;
			unitId = command.ingoalunitid();
			break;
		}
		case protos::expert::action::UpDeleteObjects::kInSnUnitId:
		{
			unitIdTypeOp = expert_conf::CONST_TYPE_OP_SN;
			unitId = command.insnunitid();
			break;
		}
	}
	switch (command.hitPoints_case())
	{
		default:
		case protos::expert::action::UpDeleteObjects::kInConstHitPoints:
		{
			ExpertAction::UpDeleteObjects(unitIdTypeOp, unitId, expert_conf::CONST_TYPE_OP_CONST, command.inconsthitpoints());
			break;
		}
		case protos::expert::action::UpDeleteObjects::kInGoalHitPoints:
		{
			ExpertAction::UpDeleteObjects(unitIdTypeOp, unitId, expert_conf::CONST_TYPE_OP_GOAL, command.ingoalhitpoints());
			break;
		}
		case protos::expert::action::UpDeleteObjects::kInSnHitPoints:
		{
			ExpertAction::UpDeleteObjects(unitIdTypeOp, unitId, expert_conf::CONST_TYPE_OP_SN, command.insnhitpoints());
			break;
		}
	}

	protos::expert::action::UpDeleteObjectsResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpDisbandGroupType(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpDisbandGroupType command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpDisbandGroupType(command.inconstgrouptype());

	protos::expert::action::UpDisbandGroupTypeResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpDropResources(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpDropResources command;
	anyCommand.UnpackTo(&command);

	switch (command.value_case())
	{
		default:
		case protos::expert::action::UpDropResources::kInConstValue:
		{
			ExpertAction::UpDropResources(command.inconstresource(), expert_conf::CONST_TYPE_OP_CONST, command.inconstvalue());
			break;
		}
		case protos::expert::action::UpDropResources::kInGoalValue:
		{
			ExpertAction::UpDropResources(command.inconstresource(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalvalue());
			break;
		}
		case protos::expert::action::UpDropResources::kInSnValue:
		{
			ExpertAction::UpDropResources(command.inconstresource(), expert_conf::CONST_TYPE_OP_SN, command.insnvalue());
			break;
		}
	}

	protos::expert::action::UpDropResourcesResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFilterDistance(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFilterDistance command;
	anyCommand.UnpackTo(&command);

	int minDistanceTypeOp = expert_conf::CONST_TYPE_OP_CONST;
	int minDistance = 0;
	switch (command.minDistance_case())
	{
		default:
		case protos::expert::action::UpFilterDistance::kInConstMinDistance:
		{
			minDistanceTypeOp = expert_conf::CONST_TYPE_OP_CONST;
			minDistance = command.inconstmindistance();
			break;
		}
		case protos::expert::action::UpFilterDistance::kInGoalMinDistance:
		{
			minDistanceTypeOp = expert_conf::CONST_TYPE_OP_GOAL;
			minDistance = command.ingoalmindistance();
			break;
		}
		case protos::expert::action::UpFilterDistance::kInSnMinDistance:
		{
			minDistanceTypeOp = expert_conf::CONST_TYPE_OP_SN;
			minDistance = command.insnmindistance();
			break;
		}
	}
	switch (command.maxDistance_case())
	{
		default:
		case protos::expert::action::UpFilterDistance::kInConstMaxDistance:
		{
			ExpertAction::UpFilterDistance(minDistanceTypeOp, minDistance, expert_conf::CONST_TYPE_OP_CONST, command.inconstmaxdistance());
			break;
		}
		case protos::expert::action::UpFilterDistance::kInGoalMaxDistance:
		{
			ExpertAction::UpFilterDistance(minDistanceTypeOp, minDistance, expert_conf::CONST_TYPE_OP_GOAL, command.ingoalmaxdistance());
			break;
		}
		case protos::expert::action::UpFilterDistance::kInSnMaxDistance:
		{
			ExpertAction::UpFilterDistance(minDistanceTypeOp, minDistance, expert_conf::CONST_TYPE_OP_SN, command.insnmaxdistance());
			break;
		}
	}

	protos::expert::action::UpFilterDistanceResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFilterExclude(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFilterExclude command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpFilterExclude(command.inconstcmdid(), command.inconstactionid(), command.inconstorderid(), command.inconstclassid());

	protos::expert::action::UpFilterExcludeResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFilterGarrison(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFilterGarrison command;
	anyCommand.UnpackTo(&command);
	
	int minGarrisonTypeOp = expert_conf::CONST_TYPE_OP_CONST;
	int minGarrison = 0;
	switch (command.minGarrison_case())
	{
		default:
		case protos::expert::action::UpFilterGarrison::kInConstMinGarrison:
		{
			minGarrisonTypeOp = expert_conf::CONST_TYPE_OP_CONST;
			minGarrison = command.inconstmingarrison();
			break;
		}
		case protos::expert::action::UpFilterGarrison::kInGoalMinGarrison:
		{
			minGarrisonTypeOp = expert_conf::CONST_TYPE_OP_GOAL;
			minGarrison = command.ingoalmingarrison();
			break;
		}
		case protos::expert::action::UpFilterGarrison::kInSnMinGarrison:
		{
			minGarrisonTypeOp = expert_conf::CONST_TYPE_OP_SN;
			minGarrison = command.insnmingarrison();
			break;
		}
	}
	switch (command.maxGarrison_case())
	{
		default:
		case protos::expert::action::UpFilterGarrison::kInConstMaxGarrison:
		{
			ExpertAction::UpFilterGarrison(minGarrisonTypeOp, minGarrison, expert_conf::CONST_TYPE_OP_CONST, command.inconstmaxgarrison());
			break;
		}
		case protos::expert::action::UpFilterGarrison::kInGoalMaxGarrison:
		{
			ExpertAction::UpFilterGarrison(minGarrisonTypeOp, minGarrison, expert_conf::CONST_TYPE_OP_GOAL, command.ingoalmaxgarrison());
			break;
		}
		case protos::expert::action::UpFilterGarrison::kInSnMaxGarrison:
		{
			ExpertAction::UpFilterGarrison(minGarrisonTypeOp, minGarrison, expert_conf::CONST_TYPE_OP_SN, command.insnmaxgarrison());
			break;
		}
	}

	protos::expert::action::UpFilterGarrisonResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFilterInclude(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFilterInclude command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpFilterInclude(command.inconstcmdid(), command.inconstactionid(), command.inconstorderid(), command.inconstonmainland());

	protos::expert::action::UpFilterIncludeResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFilterRange(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFilterRange command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpFilterRange(command.inconstmindistance(), command.inconstmaxgarrison(), command.inconstmindistance(), command.inconstmaxdistance());

	protos::expert::action::UpFilterRangeResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFilterStatus(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFilterStatus command;
	anyCommand.UnpackTo(&command);

	int objectStatusTypeOp = expert_conf::CONST_TYPE_OP_CONST;
	int objectStatus = 0;
	switch (command.objectStatus_case())
	{
		default:
		case protos::expert::action::UpFilterStatus::kInConstObjectStatus:
		{
			objectStatusTypeOp = expert_conf::CONST_TYPE_OP_CONST;
			objectStatus = command.inconstobjectstatus();
			break;
		}
		case protos::expert::action::UpFilterStatus::kInGoalObjectStatus:
		{
			objectStatusTypeOp = expert_conf::CONST_TYPE_OP_GOAL;
			objectStatus = command.ingoalobjectstatus();
			break;
		}
		case protos::expert::action::UpFilterStatus::kInSnObjectStatus:
		{
			objectStatusTypeOp = expert_conf::CONST_TYPE_OP_SN;
			objectStatus = command.insnobjectstatus();
			break;
		}
	}
	switch (command.objectList_case())
	{
		default:
		case protos::expert::action::UpFilterStatus::kInConstObjectList:
		{
			ExpertAction::UpFilterStatus(objectStatusTypeOp, objectStatus, expert_conf::CONST_TYPE_OP_CONST, command.inconstobjectlist());
			break;
		}
		case protos::expert::action::UpFilterStatus::kInGoalObjectList:
		{
			ExpertAction::UpFilterStatus(objectStatusTypeOp, objectStatus, expert_conf::CONST_TYPE_OP_GOAL, command.ingoalobjectlist());
			break;
		}
		case protos::expert::action::UpFilterStatus::kInSnObjectList:
		{
			ExpertAction::UpFilterStatus(objectStatusTypeOp, objectStatus, expert_conf::CONST_TYPE_OP_SN, command.insnobjectlist());
			break;
		}
	}

	protos::expert::action::UpFilterStatusResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFindFlare(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFindFlare command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpFindFlare(command.outgoalpoint());

	protos::expert::action::UpFindFlareResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFindLocal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFindLocal command;
	anyCommand.UnpackTo(&command);

	int unitIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
	int unitId = 0;
	switch (command.unitId_case())
	{
		default:
		case protos::expert::action::UpFindLocal::kInConstUnitId:
		{
			unitIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
			unitId = command.inconstunitid();
			break;
		}
		case protos::expert::action::UpFindLocal::kInGoalUnitId:
		{
			unitIdTypeOp = expert_conf::CONST_TYPE_OP_GOAL;
			unitId = command.ingoalunitid();
			break;
		}
		case protos::expert::action::UpFindLocal::kInSnUnitId:
		{
			unitIdTypeOp = expert_conf::CONST_TYPE_OP_SN;
			unitId = command.insnunitid();
			break;
		}
	}
	switch (command.count_case())
	{
		default:
		case protos::expert::action::UpFindLocal::kInConstCount:
		{
			ExpertAction::UpFindLocal(unitIdTypeOp, unitId, expert_conf::CONST_TYPE_OP_CONST, command.inconstcount());
			break;
		}
		case protos::expert::action::UpFindLocal::kInGoalCount:
		{
			ExpertAction::UpFindLocal(unitIdTypeOp, unitId, expert_conf::CONST_TYPE_OP_GOAL, command.ingoalcount());
			break;
		}
		case protos::expert::action::UpFindLocal::kInSnCount:
		{
			ExpertAction::UpFindLocal(unitIdTypeOp, unitId, expert_conf::CONST_TYPE_OP_SN, command.insncount());
			break;
		}
	}

	protos::expert::action::UpFindLocalResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFindNextPlayer(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFindNextPlayer command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpFindNextPlayer(command.inconstplayerstance(), command.inconstfindplayermethod(), command.iogoalplayerid());

	protos::expert::action::UpFindNextPlayerResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFindPlayer(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFindPlayer command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpFindPlayer(command.inconstplayerstance(), command.inconstfindplayermethod(), command.outgoalplayerid());

	protos::expert::action::UpFindPlayerResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFindPlayerFlare(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFindPlayerFlare command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpFindPlayerFlare(command.inplayeranyplayer(), command.outgoalpoint());

	protos::expert::action::UpFindPlayerFlareResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFindRemote(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFindRemote command;
	anyCommand.UnpackTo(&command);

	int unitIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
	int unitId = 0;
	switch (command.unitId_case())
	{
		default:
		case protos::expert::action::UpFindRemote::kInConstUnitId:
		{
			unitIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
			unitId = command.inconstunitid();
			break;
		}
		case protos::expert::action::UpFindRemote::kInGoalUnitId:
		{
			unitIdTypeOp = expert_conf::CONST_TYPE_OP_GOAL;
			unitId = command.ingoalunitid();
			break;
		}
		case protos::expert::action::UpFindRemote::kInSnUnitId:
		{
			unitIdTypeOp = expert_conf::CONST_TYPE_OP_SN;
			unitId = command.insnunitid();
			break;
		}
	}
	switch (command.count_case())
	{
		default:
		case protos::expert::action::UpFindRemote::kInConstCount:
		{
			ExpertAction::UpFindRemote(unitIdTypeOp, unitId, expert_conf::CONST_TYPE_OP_CONST, command.inconstcount());
			break;
		}
		case protos::expert::action::UpFindRemote::kInGoalCount:
		{
			ExpertAction::UpFindRemote(unitIdTypeOp, unitId, expert_conf::CONST_TYPE_OP_GOAL, command.ingoalcount());
			break;
		}
		case protos::expert::action::UpFindRemote::kInSnCount:
		{
			ExpertAction::UpFindRemote(unitIdTypeOp, unitId, expert_conf::CONST_TYPE_OP_SN, command.insncount());
			break;
		}
	}

	protos::expert::action::UpFindRemoteResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFindResource(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFindResource command;
	anyCommand.UnpackTo(&command);

	int resourceTypeOp = expert_conf::CONST_TYPE_OP_CONST;
	int resource = 0;
	switch (command.resource_case())
	{
		default:
		case protos::expert::action::UpFindResource::kInConstResource:
		{
			resourceTypeOp = expert_conf::CONST_TYPE_OP_CONST;
			resource = command.inconstresource();
			break;
		}
		case protos::expert::action::UpFindResource::kInGoalResource:
		{
			resourceTypeOp = expert_conf::CONST_TYPE_OP_GOAL;
			resource = command.ingoalresource();
			break;
		}
		case protos::expert::action::UpFindResource::kInSnResource:
		{
			resourceTypeOp = expert_conf::CONST_TYPE_OP_SN;
			resource = command.insnresource();
			break;
		}
	}
	switch (command.count_case())
	{
		default:
		case protos::expert::action::UpFindResource::kInConstCount:
		{
			ExpertAction::UpFindResource(resourceTypeOp, resource, expert_conf::CONST_TYPE_OP_CONST, command.inconstcount());
			break;
		}
		case protos::expert::action::UpFindResource::kInGoalCount:
		{
			ExpertAction::UpFindResource(resourceTypeOp, resource, expert_conf::CONST_TYPE_OP_GOAL, command.ingoalcount());
			break;
		}
		case protos::expert::action::UpFindResource::kInSnCount:
		{
			ExpertAction::UpFindResource(resourceTypeOp, resource, expert_conf::CONST_TYPE_OP_SN, command.insncount());
			break;
		}
	}

	protos::expert::action::UpFindResourceResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFindStatusLocal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFindStatusLocal command;
	anyCommand.UnpackTo(&command);

	int unitIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
	int unitId = 0;
	switch (command.unitId_case())
	{
		default:
		case protos::expert::action::UpFindStatusLocal::kInConstUnitId:
		{
			unitIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
			unitId = command.inconstunitid();
			break;
		}
		case protos::expert::action::UpFindStatusLocal::kInGoalUnitId:
		{
			unitIdTypeOp = expert_conf::CONST_TYPE_OP_GOAL;
			unitId = command.ingoalunitid();
			break;
		}
		case protos::expert::action::UpFindStatusLocal::kInSnUnitId:
		{
			unitIdTypeOp = expert_conf::CONST_TYPE_OP_SN;
			unitId = command.insnunitid();
			break;
		}
	}
	switch (command.count_case())
	{
		default:
		case protos::expert::action::UpFindStatusLocal::kInConstCount:
		{
			ExpertAction::UpFindStatusLocal(unitIdTypeOp, unitId, expert_conf::CONST_TYPE_OP_CONST, command.inconstcount());
			break;
		}
		case protos::expert::action::UpFindStatusLocal::kInGoalCount:
		{
			ExpertAction::UpFindStatusLocal(unitIdTypeOp, unitId, expert_conf::CONST_TYPE_OP_GOAL, command.ingoalcount());
			break;
		}
		case protos::expert::action::UpFindStatusLocal::kInSnCount:
		{
			ExpertAction::UpFindStatusLocal(unitIdTypeOp, unitId, expert_conf::CONST_TYPE_OP_SN, command.insncount());
			break;
		}
	}

	protos::expert::action::UpFindStatusLocalResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFindStatusRemote(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFindStatusRemote command;
	anyCommand.UnpackTo(&command);

	int unitIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
	int unitId = 0;
	switch (command.unitId_case())
	{
		default:
		case protos::expert::action::UpFindStatusRemote::kInConstUnitId:
		{
			unitIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
			unitId = command.inconstunitid();
			break;
		}
		case protos::expert::action::UpFindStatusRemote::kInGoalUnitId:
		{
			unitIdTypeOp = expert_conf::CONST_TYPE_OP_GOAL;
			unitId = command.ingoalunitid();
			break;
		}
		case protos::expert::action::UpFindStatusRemote::kInSnUnitId:
		{
			unitIdTypeOp = expert_conf::CONST_TYPE_OP_SN;
			unitId = command.insnunitid();
			break;
		}
	}
	switch (command.count_case())
	{
		default:
		case protos::expert::action::UpFindStatusRemote::kInConstCount:
		{
			ExpertAction::UpFindStatusRemote(unitIdTypeOp, unitId, expert_conf::CONST_TYPE_OP_CONST, command.inconstcount());
			break;
		}
		case protos::expert::action::UpFindStatusRemote::kInGoalCount:
		{
			ExpertAction::UpFindStatusRemote(unitIdTypeOp, unitId, expert_conf::CONST_TYPE_OP_GOAL, command.ingoalcount());
			break;
		}
		case protos::expert::action::UpFindStatusRemote::kInSnCount:
		{
			ExpertAction::UpFindStatusRemote(unitIdTypeOp, unitId, expert_conf::CONST_TYPE_OP_SN, command.insncount());
			break;
		}
	}

	protos::expert::action::UpFindStatusRemoteResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFullResetSearch(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFullResetSearch command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpFullResetSearch();

	protos::expert::action::UpFullResetSearchResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGarrison(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGarrison command;
	anyCommand.UnpackTo(&command);

	switch (command.unitId_case())
	{
		default:
		case protos::expert::action::UpGarrison::kInConstUnitId:
		{
			ExpertAction::UpGarrison(command.inconstobjectid(), expert_conf::CONST_TYPE_OP_CONST, command.inconstunitid());
			break;
		}
		case protos::expert::action::UpGarrison::kInGoalUnitId:
		{
			ExpertAction::UpGarrison(command.inconstobjectid(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalunitid());
			break;
		}
		case protos::expert::action::UpGarrison::kInSnUnitId:
		{
			ExpertAction::UpGarrison(command.inconstobjectid(), expert_conf::CONST_TYPE_OP_SN, command.insnunitid());
			break;
		}
	}

	protos::expert::action::UpGarrisonResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGatherInside(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGatherInside command;
	anyCommand.UnpackTo(&command);

	int buildingIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
	int buildingId = 0;
	switch (command.buildingId_case())
	{
		default:
		case protos::expert::action::UpGatherInside::kInConstBuildingId:
		{
			buildingIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
			buildingId = command.inconstbuildingid();
			break;
		}
		case protos::expert::action::UpGatherInside::kInGoalBuildingId:
		{
			buildingIdTypeOp = expert_conf::CONST_TYPE_OP_GOAL;
			buildingId = command.ingoalbuildingid();
			break;
		}
		case protos::expert::action::UpGatherInside::kInSnBuildingId:
		{
			buildingIdTypeOp = expert_conf::CONST_TYPE_OP_SN;
			buildingId = command.insnbuildingid();
			break;
		}
	}
	switch (command.state_case())
	{
		default:
		case protos::expert::action::UpGatherInside::kInConstState:
		{
			ExpertAction::UpGatherInside(buildingIdTypeOp, buildingId, expert_conf::CONST_TYPE_OP_CONST, command.inconststate());
			break;
		}
		case protos::expert::action::UpGatherInside::kInGoalState:
		{
			ExpertAction::UpGatherInside(buildingIdTypeOp, buildingId, expert_conf::CONST_TYPE_OP_GOAL, command.ingoalstate());
			break;
		}
		case protos::expert::action::UpGatherInside::kInSnState:
		{
			ExpertAction::UpGatherInside(buildingIdTypeOp, buildingId, expert_conf::CONST_TYPE_OP_SN, command.insnstate());
			break;
		}
	}

	protos::expert::action::UpGatherInsideResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetAttackerClass(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetAttackerClass command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetAttackerClass(command.outgoalsourceclass());

	protos::expert::action::UpGetAttackerClassResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetCostDelta(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetCostDelta command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetCostDelta(command.outgoalid());

	protos::expert::action::UpGetCostDeltaResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetEvent(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetEvent command;
	anyCommand.UnpackTo(&command);

	switch (command.eventId_case())
	{
		default:
		case protos::expert::action::UpGetEvent::kInConstEventId:
		{
			ExpertAction::UpGetEvent(expert_conf::CONST_TYPE_OP_CONST, command.inconsteventid(), command.outgoalvalue());
			break;
		}
		case protos::expert::action::UpGetEvent::kInGoalEventId:
		{
			ExpertAction::UpGetEvent(expert_conf::CONST_TYPE_OP_GOAL, command.ingoaleventid(), command.outgoalvalue());
			break;
		}
		case protos::expert::action::UpGetEvent::kInSnEventId:
		{
			ExpertAction::UpGetEvent(expert_conf::CONST_TYPE_OP_SN, command.insneventid(), command.outgoalvalue());
			break;
		}
	}

	protos::expert::action::UpGetEventResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetFact(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetFact command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetFact(command.inconstfactid(), command.inconstparam(), command.outgoaldata());

	protos::expert::action::UpGetFactResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetFactMax(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetFactMax command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetFactMax(command.inplayeranyplayer(), command.inconstfactid(), command.inconstparam(), command.outgoaldata());

	protos::expert::action::UpGetFactMaxResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetFactMin(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetFactMin command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetFactMin(command.inplayeranyplayer(), command.inconstfactid(), command.inconstparam(), command.outgoaldata());

	protos::expert::action::UpGetFactMinResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetFactSum(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetFactSum command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetFactSum(command.inplayeranyplayer(), command.inconstfactid(), command.inconstparam(), command.outgoaldata());

	protos::expert::action::UpGetFactSumResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetFocusFact(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetFocusFact command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetFocusFact(command.inconstfactid(), command.inconstparam(), command.outgoaldata());

	protos::expert::action::UpGetFocusFactResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetGroupSize(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetGroupSize command;
	anyCommand.UnpackTo(&command);

	switch (command.groupId_case())
	{
		default:
		case protos::expert::action::UpGetGroupSize::kInConstGroupId:
		{
			ExpertAction::UpGetGroupSize(expert_conf::CONST_TYPE_OP_CONST, command.inconstgroupid(), command.outgoalsize());
			break;
		}
		case protos::expert::action::UpGetGroupSize::kInGoalGroupId:
		{
			ExpertAction::UpGetGroupSize(expert_conf::CONST_TYPE_OP_GOAL, command.ingoalgroupid(), command.outgoalsize());
			break;
		}
		case protos::expert::action::UpGetGroupSize::kInSnGroupId:
		{
			ExpertAction::UpGetGroupSize(expert_conf::CONST_TYPE_OP_SN, command.insngroupid(), command.outgoalsize());
			break;
		}
	}

	protos::expert::action::UpGetGroupSizeResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetIndirectGoal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetIndirectGoal command;
	anyCommand.UnpackTo(&command);

	switch (command.goalId_case())
	{
		default:
		case protos::expert::action::UpGetIndirectGoal::kInConstGoalId:
		{
			ExpertAction::UpGetIndirectGoal(expert_conf::CONST_TYPE_OP_CONST, command.inconstgoalid(), command.outgoalvalue());
			break;
		}
		case protos::expert::action::UpGetIndirectGoal::kInGoalGoalId:
		{
			ExpertAction::UpGetIndirectGoal(expert_conf::CONST_TYPE_OP_GOAL, command.ingoalgoalid(), command.outgoalvalue());
			break;
		}
		case protos::expert::action::UpGetIndirectGoal::kInSnGoalId:
		{
			ExpertAction::UpGetIndirectGoal(expert_conf::CONST_TYPE_OP_SN, command.insngoalid(), command.outgoalvalue());
			break;
		}
	}

	protos::expert::action::UpGetIndirectGoalResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetObjectData(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetObjectData command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetObjectData(command.inconstobjectdata(), command.outgoaldata());

	protos::expert::action::UpGetObjectDataResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetObjectTargetData(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetObjectTargetData command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetObjectTargetData(command.inconstobjectdata(), command.outgoaldata());

	protos::expert::action::UpGetObjectTargetDataResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetObjectTypeData(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetObjectTypeData command;
	anyCommand.UnpackTo(&command);

	switch (command.typeId_case())
	{
		default:
		case protos::expert::action::UpGetObjectTypeData::kInConstTypeId:
		{
			ExpertAction::UpGetObjectTypeData(expert_conf::CONST_TYPE_OP_CONST, command.inconsttypeid(), command.inconstobjectdata(), command.outgoaldata());
			break;
		}
		case protos::expert::action::UpGetObjectTypeData::kInGoalTypeId:
		{
			ExpertAction::UpGetObjectTypeData(expert_conf::CONST_TYPE_OP_GOAL, command.ingoaltypeid(), command.inconstobjectdata(), command.outgoaldata());
			break;
		}
		case protos::expert::action::UpGetObjectTypeData::kInSnTypeId:
		{
			ExpertAction::UpGetObjectTypeData(expert_conf::CONST_TYPE_OP_SN, command.insntypeid(), command.inconstobjectdata(), command.outgoaldata());
			break;
		}
	}

	protos::expert::action::UpGetObjectTypeDataResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetPathDistance(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetPathDistance command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetPathDistance(command.ingoalpoint(), command.inconststrict(), command.outgoaldata());

	protos::expert::action::UpGetPathDistanceResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetPlayerColor(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetPlayerColor command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetPlayerColor(command.inplayeranyplayer(), command.outgoalcolorid());

	protos::expert::action::UpGetPlayerColorResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetPlayerFact(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetPlayerFact command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetPlayerFact(command.inplayeranyplayer(), command.inconstfactid(), command.inconstparam(), command.outgoaldata());

	protos::expert::action::UpGetPlayerFactResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetPoint(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetPoint command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetPoint(command.inconstpositiontype(), command.outgoalpoint());

	protos::expert::action::UpGetPointResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetPointContains(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetPointContains command;
	anyCommand.UnpackTo(&command);

	switch (command.objectId_case())
	{
		default:
		case protos::expert::action::UpGetPointContains::kInConstObjectId:
		{
			ExpertAction::UpGetPointContains(command.ingoalpoint(), command.outgoalgoalid(), expert_conf::CONST_TYPE_OP_CONST, command.inconstobjectid());
			break;
		}
		case protos::expert::action::UpGetPointContains::kInGoalObjectId:
		{
			ExpertAction::UpGetPointContains(command.ingoalpoint(), command.outgoalgoalid(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalobjectid());
			break;
		}
		case protos::expert::action::UpGetPointContains::kInSnObjectId:
		{
			ExpertAction::UpGetPointContains(command.ingoalpoint(), command.outgoalgoalid(), expert_conf::CONST_TYPE_OP_SN, command.insnobjectid());
			break;
		}
	}

	protos::expert::action::UpGetPointContainsResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetPointDistance(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetPointDistance command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetPointDistance(command.ingoalpoint1(), command.ingoalpoint2(), command.outgoaldistance());

	protos::expert::action::UpGetPointDistanceResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetPointElevation(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetPointElevation command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetPointElevation(command.ingoalpoint(), command.outgoaldata());

	protos::expert::action::UpGetPointElevationResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetPointTerrain(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetPointTerrain command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetPointTerrain(command.ingoalpoint(), command.outgoalterrain());

	protos::expert::action::UpGetPointTerrainResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetPointZone(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetPointZone command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetPointZone(command.ingoalpoint(), command.outgoaldata());

	protos::expert::action::UpGetPointZoneResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetPreciseTime(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetPreciseTime command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetPreciseTime(command.ingoalstart(), command.outgoaltime());

	protos::expert::action::UpGetPreciseTimeResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetProjectilePlayer(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetProjectilePlayer command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetProjectilePlayer(command.inconstprojectiletype(), command.outgoalplayerid());

	protos::expert::action::UpGetProjectilePlayerResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetRuleId(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetRuleId command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetRuleId(command.outgoalruleid());

	protos::expert::action::UpGetRuleIdResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetSearchState(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetSearchState command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetSearchState(command.outgoalstate());

	protos::expert::action::UpGetSearchStateResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetSharedGoal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetSharedGoal command;
	anyCommand.UnpackTo(&command);

	switch (command.sharedGoalId_case())
	{
		default:
		case protos::expert::action::UpGetSharedGoal::kInConstSharedGoalId:
		{
			ExpertAction::UpGetSharedGoal(expert_conf::CONST_TYPE_OP_CONST, command.inconstsharedgoalid(), command.outgoalvalue());
			break;
		}
		case protos::expert::action::UpGetSharedGoal::kInGoalSharedGoalId:
		{
			ExpertAction::UpGetSharedGoal(expert_conf::CONST_TYPE_OP_GOAL, command.ingoalsharedgoalid(), command.outgoalvalue());
			break;
		}
		case protos::expert::action::UpGetSharedGoal::kInSnSharedGoalId:
		{
			ExpertAction::UpGetSharedGoal(expert_conf::CONST_TYPE_OP_SN, command.insnsharedgoalid(), command.outgoalvalue());
			break;
		}
	}

	protos::expert::action::UpGetSharedGoalResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetSignal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetSignal command;
	anyCommand.UnpackTo(&command);

	switch (command.signalId_case())
	{
		default:
		case protos::expert::action::UpGetSignal::kInConstSignalId:
		{
			ExpertAction::UpGetSignal(expert_conf::CONST_TYPE_OP_CONST, command.inconstsignalid(), command.outgoalvalue());
			break;
		}
		case protos::expert::action::UpGetSignal::kInGoalSignalId:
		{
			ExpertAction::UpGetSignal(expert_conf::CONST_TYPE_OP_GOAL, command.ingoalsignalid(), command.outgoalvalue());
			break;
		}
		case protos::expert::action::UpGetSignal::kInSnSignalId:
		{
			ExpertAction::UpGetSignal(expert_conf::CONST_TYPE_OP_SN, command.insnsignalid(), command.outgoalvalue());
			break;
		}
	}

	protos::expert::action::UpGetSignalResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetTargetFact(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetTargetFact command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetTargetFact(command.inconstfactid(), command.inconstparam(), command.outgoaldata());

	protos::expert::action::UpGetTargetFactResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetThreatData(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetThreatData command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetThreatData(command.outgoalelapsedtime(), command.outgoalplayerid(), command.outgoalsourceclass(), command.outgoaltargetclass());

	protos::expert::action::UpGetThreatDataResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetTimer(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetTimer command;
	anyCommand.UnpackTo(&command);

	switch (command.timerId_case())
	{
		default:
		case protos::expert::action::UpGetTimer::kInConstTimerId:
		{
			ExpertAction::UpGetTimer(expert_conf::CONST_TYPE_OP_CONST, command.inconsttimerid(), command.outgoalvalue());
			break;
		}
		case protos::expert::action::UpGetTimer::kInGoalTimerId:
		{
			ExpertAction::UpGetTimer(expert_conf::CONST_TYPE_OP_GOAL, command.ingoaltimerid(), command.outgoalvalue());
			break;
		}
		case protos::expert::action::UpGetTimer::kInSnTimerId:
		{
			ExpertAction::UpGetTimer(expert_conf::CONST_TYPE_OP_SN, command.insntimerid(), command.outgoalvalue());
			break;
		}
	}

	protos::expert::action::UpGetTimerResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetVictoryData(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetVictoryData command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetVictoryData(command.outgoalplayerid(), command.outgoaltype(), command.outgoaltime());

	protos::expert::action::UpGetVictoryDataResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetVictoryLimit(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetVictoryLimit command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetVictoryLimit(command.outgoallimit());

	protos::expert::action::UpGetVictoryLimitResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGuardUnit(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGuardUnit command;
	anyCommand.UnpackTo(&command);

	switch (command.unitId_case())
	{
		default:
		case protos::expert::action::UpGuardUnit::kInConstUnitId:
		{
			ExpertAction::UpGuardUnit(command.inconstobjectid(), expert_conf::CONST_TYPE_OP_CONST, command.inconstunitid());
			break;
		}
		case protos::expert::action::UpGuardUnit::kInGoalUnitId:
		{
			ExpertAction::UpGuardUnit(command.inconstobjectid(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalunitid());
			break;
		}
		case protos::expert::action::UpGuardUnit::kInSnUnitId:
		{
			ExpertAction::UpGuardUnit(command.inconstobjectid(), expert_conf::CONST_TYPE_OP_SN, command.insnunitid());
			break;
		}
	}

	protos::expert::action::UpGuardUnitResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpJumpDirect(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpJumpDirect command;
	anyCommand.UnpackTo(&command);

	switch (command.ruleId_case())
	{
		default:
		case protos::expert::action::UpJumpDirect::kInConstRuleId:
		{
			ExpertAction::UpJumpDirect(expert_conf::CONST_TYPE_OP_CONST, command.inconstruleid());
			break;
		}
		case protos::expert::action::UpJumpDirect::kInGoalRuleId:
		{
			ExpertAction::UpJumpDirect(expert_conf::CONST_TYPE_OP_GOAL, command.ingoalruleid());
			break;
		}
		case protos::expert::action::UpJumpDirect::kInSnRuleId:
		{
			ExpertAction::UpJumpDirect(expert_conf::CONST_TYPE_OP_SN, command.insnruleid());
			break;
		}
	}

	protos::expert::action::UpJumpDirectResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpJumpDynamic(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpJumpDynamic command;
	anyCommand.UnpackTo(&command);

	switch (command.ruleDelta_case())
	{
		default:
		case protos::expert::action::UpJumpDynamic::kInConstRuleDelta:
		{
			ExpertAction::UpJumpDynamic(expert_conf::CONST_TYPE_OP_CONST, command.inconstruledelta());
			break;
		}
		case protos::expert::action::UpJumpDynamic::kInGoalRuleDelta:
		{
			ExpertAction::UpJumpDynamic(expert_conf::CONST_TYPE_OP_GOAL, command.ingoalruledelta());
			break;
		}
		case protos::expert::action::UpJumpDynamic::kInSnRuleDelta:
		{
			ExpertAction::UpJumpDynamic(expert_conf::CONST_TYPE_OP_SN, command.insnruledelta());
			break;
		}
	}

	protos::expert::action::UpJumpDynamicResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpJumpRule(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpJumpRule command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpJumpRule(command.inconstruledelta());

	protos::expert::action::UpJumpRuleResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpLerpPercent(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpLerpPercent command;
	anyCommand.UnpackTo(&command);

	switch (command.percent_case())
	{
		default:
		case protos::expert::action::UpLerpPercent::kInConstPercent:
		{
			ExpertAction::UpLerpPercent(command.iogoalpoint(), command.ingoalpoint(), expert_conf::CONST_TYPE_OP_CONST, command.inconstpercent());
			break;
		}
		case protos::expert::action::UpLerpPercent::kInGoalPercent:
		{
			ExpertAction::UpLerpPercent(command.iogoalpoint(), command.ingoalpoint(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalpercent());
			break;
		}
		case protos::expert::action::UpLerpPercent::kInSnPercent:
		{
			ExpertAction::UpLerpPercent(command.iogoalpoint(), command.ingoalpoint(), expert_conf::CONST_TYPE_OP_SN, command.insnpercent());
			break;
		}
	}

	protos::expert::action::UpLerpPercentResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpLerpTiles(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpLerpTiles command;
	anyCommand.UnpackTo(&command);

	switch (command.tiles_case())
	{
		default:
		case protos::expert::action::UpLerpTiles::kInConstTiles:
		{
			ExpertAction::UpLerpTiles(command.iogoalpoint(), command.ingoalpoint(), expert_conf::CONST_TYPE_OP_CONST, command.inconsttiles());
			break;
		}
		case protos::expert::action::UpLerpTiles::kInGoalTiles:
		{
			ExpertAction::UpLerpTiles(command.iogoalpoint(), command.ingoalpoint(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoaltiles());
			break;
		}
		case protos::expert::action::UpLerpTiles::kInSnTiles:
		{
			ExpertAction::UpLerpTiles(command.iogoalpoint(), command.ingoalpoint(), expert_conf::CONST_TYPE_OP_SN, command.insntiles());
			break;
		}
	}

	protos::expert::action::UpLerpTilesResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpLogData(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpLogData command;
	anyCommand.UnpackTo(&command);

	switch (command.value_case())
	{
		default:
		case protos::expert::action::UpLogData::kInConstValue:
		{
			ExpertAction::UpLogData(command.inconstplain(), command.intextformattedstring(), expert_conf::CONST_TYPE_OP_CONST, command.inconstvalue());
			break;
		}
		case protos::expert::action::UpLogData::kInGoalValue:
		{
			ExpertAction::UpLogData(command.inconstplain(), command.intextformattedstring(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalvalue());
			break;
		}
		case protos::expert::action::UpLogData::kInSnValue:
		{
			ExpertAction::UpLogData(command.inconstplain(), command.intextformattedstring(), expert_conf::CONST_TYPE_OP_SN, command.insnvalue());
			break;
		}
	}

	protos::expert::action::UpLogDataResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpModifyEscrow(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpModifyEscrow command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpModifyEscrow(command.inconstresource(), command.mathop(), command.inopvalue());

	protos::expert::action::UpModifyEscrowResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpModifyFlag(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpModifyFlag command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpModifyFlag(command.iogoalid(), command.mathop(), command.inopflag());

	protos::expert::action::UpModifyFlagResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpModifyGoal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpModifyGoal command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpModifyGoal(command.iogoalid(), command.mathop(), command.inopvalue());

	protos::expert::action::UpModifyGoalResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpModifyGroupFlag(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpModifyGroupFlag command;
	anyCommand.UnpackTo(&command);

	switch (command.groupId_case())
	{
		default:
		case protos::expert::action::UpModifyGroupFlag::kInConstGroupId:
		{
			ExpertAction::UpModifyGroupFlag(command.inconston(), expert_conf::CONST_TYPE_OP_CONST, command.inconstgroupid());
			break;
		}
		case protos::expert::action::UpModifyGroupFlag::kInGoalGroupId:
		{
			ExpertAction::UpModifyGroupFlag(command.inconston(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalgroupid());
			break;
		}
		case protos::expert::action::UpModifyGroupFlag::kInSnGroupId:
		{
			ExpertAction::UpModifyGroupFlag(command.inconston(), expert_conf::CONST_TYPE_OP_SN, command.insngroupid());
			break;
		}
	}

	protos::expert::action::UpModifyGroupFlagResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpModifySn(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpModifySn command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpModifySn(command.iosnid(), command.mathop(), command.inopvalue());

	protos::expert::action::UpModifySnResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpReleaseEscrow(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpReleaseEscrow command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpReleaseEscrow();

	protos::expert::action::UpReleaseEscrowResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpRemoveObjects(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpRemoveObjects command;
	anyCommand.UnpackTo(&command);

	switch (command.value_case())
	{
		default:
		case protos::expert::action::UpRemoveObjects::kInConstValue:
		{
			ExpertAction::UpRemoveObjects(command.inconstsearchsource(), command.inconstobjectdata(), expert_conf::CONST_TYPE_OP_CONST, command.inconstvalue());
			break;
		}
		case protos::expert::action::UpRemoveObjects::kInGoalValue:
		{
			ExpertAction::UpRemoveObjects(command.inconstsearchsource(), command.inconstobjectdata(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalvalue());
			break;
		}
		case protos::expert::action::UpRemoveObjects::kInSnValue:
		{
			ExpertAction::UpRemoveObjects(command.inconstsearchsource(), command.inconstobjectdata(), expert_conf::CONST_TYPE_OP_SN, command.insnvalue());
			break;
		}
	}

	protos::expert::action::UpRemoveObjectsResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpRequestHunters(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpRequestHunters command;
	anyCommand.UnpackTo(&command);

	switch (command.value_case())
	{
		default:
		case protos::expert::action::UpRequestHunters::kInConstValue:
		{
			ExpertAction::UpRequestHunters(expert_conf::CONST_TYPE_OP_CONST, command.inconstvalue());
			break;
		}
		case protos::expert::action::UpRequestHunters::kInGoalValue:
		{
			ExpertAction::UpRequestHunters(expert_conf::CONST_TYPE_OP_GOAL, command.ingoalvalue());
			break;
		}
		case protos::expert::action::UpRequestHunters::kInSnValue:
		{
			ExpertAction::UpRequestHunters(expert_conf::CONST_TYPE_OP_SN, command.insnvalue());
			break;
		}
	}

	protos::expert::action::UpRequestHuntersResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpResearch(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpResearch command;
	anyCommand.UnpackTo(&command);

	switch (command.techId_case())
	{
		default:
		case protos::expert::action::UpResearch::kInConstTechId:
		{
			ExpertAction::UpResearch(command.ingoalescrowstate(), expert_conf::CONST_TYPE_OP_CONST, command.inconsttechid());
			break;
		}
		case protos::expert::action::UpResearch::kInGoalTechId:
		{
			ExpertAction::UpResearch(command.ingoalescrowstate(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoaltechid());
			break;
		}
		case protos::expert::action::UpResearch::kInSnTechId:
		{
			ExpertAction::UpResearch(command.ingoalescrowstate(), expert_conf::CONST_TYPE_OP_SN, command.insntechid());
			break;
		}
	}

	protos::expert::action::UpResearchResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpResetAttackNow(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpResetAttackNow command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpResetAttackNow();

	protos::expert::action::UpResetAttackNowResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpResetBuilding(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpResetBuilding command;
	anyCommand.UnpackTo(&command);

	switch (command.buildingId_case())
	{
		default:
		case protos::expert::action::UpResetBuilding::kInConstBuildingId:
		{
			ExpertAction::UpResetBuilding(command.inconstpreserveresearch(), expert_conf::CONST_TYPE_OP_CONST, command.inconstbuildingid());
			break;
		}
		case protos::expert::action::UpResetBuilding::kInGoalBuildingId:
		{
			ExpertAction::UpResetBuilding(command.inconstpreserveresearch(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalbuildingid());
			break;
		}
		case protos::expert::action::UpResetBuilding::kInSnBuildingId:
		{
			ExpertAction::UpResetBuilding(command.inconstpreserveresearch(), expert_conf::CONST_TYPE_OP_SN, command.insnbuildingid());
			break;
		}
	}

	protos::expert::action::UpResetBuildingResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpResetCostData(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpResetCostData command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpResetCostData(command.outgoalid());

	protos::expert::action::UpResetCostDataResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpResetFilters(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpResetFilters command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpResetFilters();

	protos::expert::action::UpResetFiltersResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpResetGroup(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpResetGroup command;
	anyCommand.UnpackTo(&command);

	switch (command.groupId_case())
	{
		default:
		case protos::expert::action::UpResetGroup::kInConstGroupId:
		{
			ExpertAction::UpResetGroup(expert_conf::CONST_TYPE_OP_CONST, command.inconstgroupid());
			break;
		}
		case protos::expert::action::UpResetGroup::kInGoalGroupId:
		{
			ExpertAction::UpResetGroup(expert_conf::CONST_TYPE_OP_GOAL, command.ingoalgroupid());
			break;
		}
		case protos::expert::action::UpResetGroup::kInSnGroupId:
		{
			ExpertAction::UpResetGroup(expert_conf::CONST_TYPE_OP_SN, command.insngroupid());
			break;
		}
	}

	protos::expert::action::UpResetGroupResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpResetPlacement(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpResetPlacement command;
	anyCommand.UnpackTo(&command);

	switch (command.buildingId_case())
	{
		default:
		case protos::expert::action::UpResetPlacement::kInConstBuildingId:
		{
			ExpertAction::UpResetPlacement(expert_conf::CONST_TYPE_OP_CONST, command.inconstbuildingid());
			break;
		}
		case protos::expert::action::UpResetPlacement::kInGoalBuildingId:
		{
			ExpertAction::UpResetPlacement(expert_conf::CONST_TYPE_OP_GOAL, command.ingoalbuildingid());
			break;
		}
		case protos::expert::action::UpResetPlacement::kInSnBuildingId:
		{
			ExpertAction::UpResetPlacement(expert_conf::CONST_TYPE_OP_SN, command.insnbuildingid());
			break;
		}
	}

	protos::expert::action::UpResetPlacementResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpResetScouts(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpResetScouts command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpResetScouts();

	protos::expert::action::UpResetScoutsResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpResetSearch(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpResetSearch command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpResetSearch(command.inconstlocalindex(), command.inconstlocallist(), command.inconstremoteindex(), command.inconstremotelist());

	protos::expert::action::UpResetSearchResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpResetTargetPriorities(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpResetTargetPriorities command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpResetTargetPriorities(command.inconstprioritytype(), command.inconstmode());

	protos::expert::action::UpResetTargetPrioritiesResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpResetUnit(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpResetUnit command;
	anyCommand.UnpackTo(&command);

	switch (command.unitId_case())
	{
		default:
		case protos::expert::action::UpResetUnit::kInConstUnitId:
		{
			ExpertAction::UpResetUnit(expert_conf::CONST_TYPE_OP_CONST, command.inconstunitid());
			break;
		}
		case protos::expert::action::UpResetUnit::kInGoalUnitId:
		{
			ExpertAction::UpResetUnit(expert_conf::CONST_TYPE_OP_GOAL, command.ingoalunitid());
			break;
		}
		case protos::expert::action::UpResetUnit::kInSnUnitId:
		{
			ExpertAction::UpResetUnit(expert_conf::CONST_TYPE_OP_SN, command.insnunitid());
			break;
		}
	}

	protos::expert::action::UpResetUnitResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpRetaskGatherers(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpRetaskGatherers command;
	anyCommand.UnpackTo(&command);

	switch (command.value_case())
	{
		default:
		case protos::expert::action::UpRetaskGatherers::kInConstValue:
		{
			ExpertAction::UpRetaskGatherers(command.inconstresource(), expert_conf::CONST_TYPE_OP_CONST, command.inconstvalue());
			break;
		}
		case protos::expert::action::UpRetaskGatherers::kInGoalValue:
		{
			ExpertAction::UpRetaskGatherers(command.inconstresource(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalvalue());
			break;
		}
		case protos::expert::action::UpRetaskGatherers::kInSnValue:
		{
			ExpertAction::UpRetaskGatherers(command.inconstresource(), expert_conf::CONST_TYPE_OP_SN, command.insnvalue());
			break;
		}
	}

	protos::expert::action::UpRetaskGatherersResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpRetreatNow(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpRetreatNow command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpRetreatNow();

	protos::expert::action::UpRetreatNowResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpRetreatTo(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpRetreatTo command;
	anyCommand.UnpackTo(&command);

	switch (command.unitId_case())
	{
		default:
		case protos::expert::action::UpRetreatTo::kInConstUnitId:
		{
			ExpertAction::UpRetreatTo(command.inconstobjectid(), expert_conf::CONST_TYPE_OP_CONST, command.inconstunitid());
			break;
		}
		case protos::expert::action::UpRetreatTo::kInGoalUnitId:
		{
			ExpertAction::UpRetreatTo(command.inconstobjectid(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalunitid());
			break;
		}
		case protos::expert::action::UpRetreatTo::kInSnUnitId:
		{
			ExpertAction::UpRetreatTo(command.inconstobjectid(), expert_conf::CONST_TYPE_OP_SN, command.insnunitid());
			break;
		}
	}

	protos::expert::action::UpRetreatToResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSellCommodity(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSellCommodity command;
	anyCommand.UnpackTo(&command);

	int resourceAmountTypeOp = expert_conf::CONST_TYPE_OP_CONST;
	int resourceAmount = 0;
	switch (command.resourceAmount_case())
	{
		default:
		case protos::expert::action::UpSellCommodity::kInConstResourceAmount:
		{
			resourceAmountTypeOp = expert_conf::CONST_TYPE_OP_CONST;
			resourceAmount = command.inconstresourceamount();
			break;
		}
		case protos::expert::action::UpSellCommodity::kInGoalResourceAmount:
		{
			resourceAmountTypeOp = expert_conf::CONST_TYPE_OP_GOAL;
			resourceAmount = command.ingoalresourceamount();
			break;
		}
		case protos::expert::action::UpSellCommodity::kInSnResourceAmount:
		{
			resourceAmountTypeOp = expert_conf::CONST_TYPE_OP_SN;
			resourceAmount = command.insnresourceamount();
			break;
		}
	}
	switch (command.value_case())
	{
		default:
		case protos::expert::action::UpSellCommodity::kInConstValue:
		{
			ExpertAction::UpSellCommodity(resourceAmountTypeOp, resourceAmount, expert_conf::CONST_TYPE_OP_CONST, command.inconstvalue());
			break;
		}
		case protos::expert::action::UpSellCommodity::kInGoalValue:
		{
			ExpertAction::UpSellCommodity(resourceAmountTypeOp, resourceAmount, expert_conf::CONST_TYPE_OP_GOAL, command.ingoalvalue());
			break;
		}
		case protos::expert::action::UpSellCommodity::kInSnValue:
		{
			ExpertAction::UpSellCommodity(resourceAmountTypeOp, resourceAmount, expert_conf::CONST_TYPE_OP_SN, command.insnvalue());
			break;
		}
	}

	protos::expert::action::UpSellCommodityResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSendFlare(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSendFlare command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpSendFlare(command.ingoalpoint());

	protos::expert::action::UpSendFlareResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSendScout(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSendScout command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpSendScout(command.inconstgrouptype(), command.inconstscoutmethod());

	protos::expert::action::UpSendScoutResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetAttackStance(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetAttackStance command;
	anyCommand.UnpackTo(&command);

	switch (command.attackStance_case())
	{
		default:
		case protos::expert::action::UpSetAttackStance::kInConstAttackStance:
		{
			ExpertAction::UpSetAttackStance(command.inconstunitid(), expert_conf::CONST_TYPE_OP_CONST, command.inconstattackstance());
			break;
		}
		case protos::expert::action::UpSetAttackStance::kInGoalAttackStance:
		{
			ExpertAction::UpSetAttackStance(command.inconstunitid(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalattackstance());
			break;
		}
		case protos::expert::action::UpSetAttackStance::kInSnAttackStance:
		{
			ExpertAction::UpSetAttackStance(command.inconstunitid(), expert_conf::CONST_TYPE_OP_SN, command.insnattackstance());
			break;
		}
	}

	protos::expert::action::UpSetAttackStanceResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetDefensePriority(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetDefensePriority command;
	anyCommand.UnpackTo(&command);

	int buildingIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
	int buildingId = 0;
	switch (command.buildingId_case())
	{
		default:
		case protos::expert::action::UpSetDefensePriority::kInConstBuildingId:
		{
			buildingIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
			buildingId = command.inconstbuildingid();
			break;
		}
		case protos::expert::action::UpSetDefensePriority::kInGoalBuildingId:
		{
			buildingIdTypeOp = expert_conf::CONST_TYPE_OP_GOAL;
			buildingId = command.ingoalbuildingid();
			break;
		}
		case protos::expert::action::UpSetDefensePriority::kInSnBuildingId:
		{
			buildingIdTypeOp = expert_conf::CONST_TYPE_OP_SN;
			buildingId = command.insnbuildingid();
			break;
		}
	}
	switch (command.value_case())
	{
		default:
		case protos::expert::action::UpSetDefensePriority::kInConstValue:
		{
			ExpertAction::UpSetDefensePriority(buildingIdTypeOp, buildingId, expert_conf::CONST_TYPE_OP_CONST, command.inconstvalue());
			break;
		}
		case protos::expert::action::UpSetDefensePriority::kInGoalValue:
		{
			ExpertAction::UpSetDefensePriority(buildingIdTypeOp, buildingId, expert_conf::CONST_TYPE_OP_GOAL, command.ingoalvalue());
			break;
		}
		case protos::expert::action::UpSetDefensePriority::kInSnValue:
		{
			ExpertAction::UpSetDefensePriority(buildingIdTypeOp, buildingId, expert_conf::CONST_TYPE_OP_SN, command.insnvalue());
			break;
		}
	}

	protos::expert::action::UpSetDefensePriorityResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetEvent(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetEvent command;
	anyCommand.UnpackTo(&command);

	int eventIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
	int eventId = 0;
	switch (command.eventId_case())
	{
		default:
		case protos::expert::action::UpSetEvent::kInConstEventId:
		{
			eventIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
			eventId = command.inconsteventid();
			break;
		}
		case protos::expert::action::UpSetEvent::kInGoalEventId:
		{
			eventIdTypeOp = expert_conf::CONST_TYPE_OP_GOAL;
			eventId = command.ingoaleventid();
			break;
		}
		case protos::expert::action::UpSetEvent::kInSnEventId:
		{
			eventIdTypeOp = expert_conf::CONST_TYPE_OP_SN;
			eventId = command.insneventid();
			break;
		}
	}
	switch (command.value_case())
	{
		default:
		case protos::expert::action::UpSetEvent::kInConstValue:
		{
			ExpertAction::UpSetEvent(eventIdTypeOp, eventId, expert_conf::CONST_TYPE_OP_CONST, command.inconstvalue());
			break;
		}
		case protos::expert::action::UpSetEvent::kInGoalValue:
		{
			ExpertAction::UpSetEvent(eventIdTypeOp, eventId, expert_conf::CONST_TYPE_OP_GOAL, command.ingoalvalue());
			break;
		}
		case protos::expert::action::UpSetEvent::kInSnValue:
		{
			ExpertAction::UpSetEvent(eventIdTypeOp, eventId, expert_conf::CONST_TYPE_OP_SN, command.insnvalue());
			break;
		}
	}

	protos::expert::action::UpSetEventResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetGroup(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetGroup command;
	anyCommand.UnpackTo(&command);

	switch (command.groupId_case())
	{
		default:
		case protos::expert::action::UpSetGroup::kInConstGroupId:
		{
			ExpertAction::UpSetGroup(command.inconstsearchsource(), expert_conf::CONST_TYPE_OP_CONST, command.inconstgroupid());
			break;
		}
		case protos::expert::action::UpSetGroup::kInGoalGroupId:
		{
			ExpertAction::UpSetGroup(command.inconstsearchsource(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalgroupid());
			break;
		}
		case protos::expert::action::UpSetGroup::kInSnGroupId:
		{
			ExpertAction::UpSetGroup(command.inconstsearchsource(), expert_conf::CONST_TYPE_OP_SN, command.insngroupid());
			break;
		}
	}

	protos::expert::action::UpSetGroupResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetIndirectGoal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetIndirectGoal command;
	anyCommand.UnpackTo(&command);

	int goalIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
	int goalId = 0;
	switch (command.goalId_case())
	{
		default:
		case protos::expert::action::UpSetIndirectGoal::kInConstGoalId:
		{
			goalIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
			goalId = command.inconstgoalid();
			break;
		}
		case protos::expert::action::UpSetIndirectGoal::kInGoalGoalId:
		{
			goalIdTypeOp = expert_conf::CONST_TYPE_OP_GOAL;
			goalId = command.ingoalgoalid();
			break;
		}
		case protos::expert::action::UpSetIndirectGoal::kInSnGoalId:
		{
			goalIdTypeOp = expert_conf::CONST_TYPE_OP_SN;
			goalId = command.insngoalid();
			break;
		}
	}
	switch (command.value_case())
	{
		default:
		case protos::expert::action::UpSetIndirectGoal::kInConstValue:
		{
			ExpertAction::UpSetIndirectGoal(goalIdTypeOp, goalId, expert_conf::CONST_TYPE_OP_CONST, command.inconstvalue());
			break;
		}
		case protos::expert::action::UpSetIndirectGoal::kInGoalValue:
		{
			ExpertAction::UpSetIndirectGoal(goalIdTypeOp, goalId, expert_conf::CONST_TYPE_OP_GOAL, command.ingoalvalue());
			break;
		}
		case protos::expert::action::UpSetIndirectGoal::kInSnValue:
		{
			ExpertAction::UpSetIndirectGoal(goalIdTypeOp, goalId, expert_conf::CONST_TYPE_OP_SN, command.insnvalue());
			break;
		}
	}

	protos::expert::action::UpSetIndirectGoalResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetOffensePriority(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetOffensePriority command;
	anyCommand.UnpackTo(&command);

	int objectIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
	int objectId = 0;
	switch (command.objectId_case())
	{
		default:
		case protos::expert::action::UpSetOffensePriority::kInConstObjectId:
		{
			objectIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
			objectId = command.inconstobjectid();
			break;
		}
		case protos::expert::action::UpSetOffensePriority::kInGoalObjectId:
		{
			objectIdTypeOp = expert_conf::CONST_TYPE_OP_GOAL;
			objectId = command.ingoalobjectid();
			break;
		}
		case protos::expert::action::UpSetOffensePriority::kInSnObjectId:
		{
			objectIdTypeOp = expert_conf::CONST_TYPE_OP_SN;
			objectId = command.insnobjectid();
			break;
		}
	}
	switch (command.value_case())
	{
		default:
		case protos::expert::action::UpSetOffensePriority::kInConstValue:
		{
			ExpertAction::UpSetOffensePriority(objectIdTypeOp, objectId, expert_conf::CONST_TYPE_OP_CONST, command.inconstvalue());
			break;
		}
		case protos::expert::action::UpSetOffensePriority::kInGoalValue:
		{
			ExpertAction::UpSetOffensePriority(objectIdTypeOp, objectId, expert_conf::CONST_TYPE_OP_GOAL, command.ingoalvalue());
			break;
		}
		case protos::expert::action::UpSetOffensePriority::kInSnValue:
		{
			ExpertAction::UpSetOffensePriority(objectIdTypeOp, objectId, expert_conf::CONST_TYPE_OP_SN, command.insnvalue());
			break;
		}
	}

	protos::expert::action::UpSetOffensePriorityResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetPlacementData(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetPlacementData command;
	anyCommand.UnpackTo(&command);

	switch (command.value_case())
	{
		default:
		case protos::expert::action::UpSetPlacementData::kInConstValue:
		{
			ExpertAction::UpSetPlacementData(command.inplayerallyplayer(), command.inconstobjectid(), expert_conf::CONST_TYPE_OP_CONST, command.inconstvalue());
			break;
		}
		case protos::expert::action::UpSetPlacementData::kInGoalValue:
		{
			ExpertAction::UpSetPlacementData(command.inplayerallyplayer(), command.inconstobjectid(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalvalue());
			break;
		}
		case protos::expert::action::UpSetPlacementData::kInSnValue:
		{
			ExpertAction::UpSetPlacementData(command.inplayerallyplayer(), command.inconstobjectid(), expert_conf::CONST_TYPE_OP_SN, command.insnvalue());
			break;
		}
	}

	protos::expert::action::UpSetPlacementDataResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetPreciseTargetPoint(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetPreciseTargetPoint command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpSetPreciseTargetPoint(command.ingoalpoint());

	protos::expert::action::UpSetPreciseTargetPointResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetSharedGoal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetSharedGoal command;
	anyCommand.UnpackTo(&command);

	int sharedGoalIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
	int sharedGoalId = 0;
	switch (command.sharedGoalId_case())
	{
		default:
		case protos::expert::action::UpSetSharedGoal::kInConstSharedGoalId:
		{
			sharedGoalIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
			sharedGoalId = command.inconstsharedgoalid();
			break;
		}
		case protos::expert::action::UpSetSharedGoal::kInGoalSharedGoalId:
		{
			sharedGoalIdTypeOp = expert_conf::CONST_TYPE_OP_GOAL;
			sharedGoalId = command.ingoalsharedgoalid();
			break;
		}
		case protos::expert::action::UpSetSharedGoal::kInSnSharedGoalId:
		{
			sharedGoalIdTypeOp = expert_conf::CONST_TYPE_OP_SN;
			sharedGoalId = command.insnsharedgoalid();
			break;
		}
	}
	switch (command.value_case())
	{
		default:
		case protos::expert::action::UpSetSharedGoal::kInConstValue:
		{
			ExpertAction::UpSetSharedGoal(sharedGoalIdTypeOp, sharedGoalId, expert_conf::CONST_TYPE_OP_CONST, command.inconstvalue());
			break;
		}
		case protos::expert::action::UpSetSharedGoal::kInGoalValue:
		{
			ExpertAction::UpSetSharedGoal(sharedGoalIdTypeOp, sharedGoalId, expert_conf::CONST_TYPE_OP_GOAL, command.ingoalvalue());
			break;
		}
		case protos::expert::action::UpSetSharedGoal::kInSnValue:
		{
			ExpertAction::UpSetSharedGoal(sharedGoalIdTypeOp, sharedGoalId, expert_conf::CONST_TYPE_OP_SN, command.insnvalue());
			break;
		}
	}

	protos::expert::action::UpSetSharedGoalResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetSignal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetSignal command;
	anyCommand.UnpackTo(&command);

	int signalIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
	int signalId = 0;
	switch (command.signalId_case())
	{
		default:
		case protos::expert::action::UpSetSignal::kInConstSignalId:
		{
			signalIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
			signalId = command.inconstsignalid();
			break;
		}
		case protos::expert::action::UpSetSignal::kInGoalSignalId:
		{
			signalIdTypeOp = expert_conf::CONST_TYPE_OP_GOAL;
			signalId = command.ingoalsignalid();
			break;
		}
		case protos::expert::action::UpSetSignal::kInSnSignalId:
		{
			signalIdTypeOp = expert_conf::CONST_TYPE_OP_SN;
			signalId = command.insnsignalid();
			break;
		}
	}
	switch (command.value_case())
	{
		default:
		case protos::expert::action::UpSetSignal::kInConstValue:
		{
			ExpertAction::UpSetSignal(signalIdTypeOp, signalId, expert_conf::CONST_TYPE_OP_CONST, command.inconstvalue());
			break;
		}
		case protos::expert::action::UpSetSignal::kInGoalValue:
		{
			ExpertAction::UpSetSignal(signalIdTypeOp, signalId, expert_conf::CONST_TYPE_OP_GOAL, command.ingoalvalue());
			break;
		}
		case protos::expert::action::UpSetSignal::kInSnValue:
		{
			ExpertAction::UpSetSignal(signalIdTypeOp, signalId, expert_conf::CONST_TYPE_OP_SN, command.insnvalue());
			break;
		}
	}

	protos::expert::action::UpSetSignalResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetTargetById(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetTargetById command;
	anyCommand.UnpackTo(&command);

	switch (command.id_case())
	{
		default:
		case protos::expert::action::UpSetTargetById::kInConstId:
		{
			ExpertAction::UpSetTargetById(expert_conf::CONST_TYPE_OP_CONST, command.inconstid());
			break;
		}
		case protos::expert::action::UpSetTargetById::kInGoalId:
		{
			ExpertAction::UpSetTargetById(expert_conf::CONST_TYPE_OP_GOAL, command.ingoalid());
			break;
		}
		case protos::expert::action::UpSetTargetById::kInSnId:
		{
			ExpertAction::UpSetTargetById(expert_conf::CONST_TYPE_OP_SN, command.insnid());
			break;
		}
	}

	protos::expert::action::UpSetTargetByIdResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetTargetObject(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetTargetObject command;
	anyCommand.UnpackTo(&command);

	switch (command.index_case())
	{
		default:
		case protos::expert::action::UpSetTargetObject::kInConstIndex:
		{
			ExpertAction::UpSetTargetObject(command.inconstsearchsource(), expert_conf::CONST_TYPE_OP_CONST, command.inconstindex());
			break;
		}
		case protos::expert::action::UpSetTargetObject::kInGoalIndex:
		{
			ExpertAction::UpSetTargetObject(command.inconstsearchsource(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalindex());
			break;
		}
		case protos::expert::action::UpSetTargetObject::kInSnIndex:
		{
			ExpertAction::UpSetTargetObject(command.inconstsearchsource(), expert_conf::CONST_TYPE_OP_SN, command.insnindex());
			break;
		}
	}

	protos::expert::action::UpSetTargetObjectResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetTargetPoint(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetTargetPoint command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpSetTargetPoint(command.ingoalpoint());

	protos::expert::action::UpSetTargetPointResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetTimer(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetTimer command;
	anyCommand.UnpackTo(&command);

	int timerIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
	int timerId = 0;
	switch (command.timerId_case())
	{
		default:
		case protos::expert::action::UpSetTimer::kInConstTimerId:
		{
			timerIdTypeOp = expert_conf::CONST_TYPE_OP_CONST;
			timerId = command.inconsttimerid();
			break;
		}
		case protos::expert::action::UpSetTimer::kInGoalTimerId:
		{
			timerIdTypeOp = expert_conf::CONST_TYPE_OP_GOAL;
			timerId = command.ingoaltimerid();
			break;
		}
		case protos::expert::action::UpSetTimer::kInSnTimerId:
		{
			timerIdTypeOp = expert_conf::CONST_TYPE_OP_SN;
			timerId = command.insntimerid();
			break;
		}
	}
	switch (command.value_case())
	{
		default:
		case protos::expert::action::UpSetTimer::kInConstValue:
		{
			ExpertAction::UpSetTimer(timerIdTypeOp, timerId, expert_conf::CONST_TYPE_OP_CONST, command.inconstvalue());
			break;
		}
		case protos::expert::action::UpSetTimer::kInGoalValue:
		{
			ExpertAction::UpSetTimer(timerIdTypeOp, timerId, expert_conf::CONST_TYPE_OP_GOAL, command.ingoalvalue());
			break;
		}
		case protos::expert::action::UpSetTimer::kInSnValue:
		{
			ExpertAction::UpSetTimer(timerIdTypeOp, timerId, expert_conf::CONST_TYPE_OP_SN, command.insnvalue());
			break;
		}
	}

	protos::expert::action::UpSetTimerResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetupCostData(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetupCostData command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpSetupCostData(command.inconstresetcost(), command.iogoalid());

	protos::expert::action::UpSetupCostDataResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpStoreMapName(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpStoreMapName command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpStoreMapName(command.inconstextension());

	protos::expert::action::UpStoreMapNameResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpStoreObjectName(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpStoreObjectName command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpStoreObjectName();

	protos::expert::action::UpStoreObjectNameResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpStorePlayerChat(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpStorePlayerChat command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpStorePlayerChat(command.inplayeranyplayer());

	protos::expert::action::UpStorePlayerChatResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpStorePlayerName(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpStorePlayerName command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpStorePlayerName(command.inplayeranyplayer());

	protos::expert::action::UpStorePlayerNameResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpStoreTechName(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpStoreTechName command;
	anyCommand.UnpackTo(&command);

	switch (command.techId_case())
	{
		default:
		case protos::expert::action::UpStoreTechName::kInConstTechId:
		{
			ExpertAction::UpStoreTechName(expert_conf::CONST_TYPE_OP_CONST, command.inconsttechid());
			break;
		}
		case protos::expert::action::UpStoreTechName::kInGoalTechId:
		{
			ExpertAction::UpStoreTechName(expert_conf::CONST_TYPE_OP_GOAL, command.ingoaltechid());
			break;
		}
		case protos::expert::action::UpStoreTechName::kInSnTechId:
		{
			ExpertAction::UpStoreTechName(expert_conf::CONST_TYPE_OP_SN, command.insntechid());
			break;
		}
	}

	protos::expert::action::UpStoreTechNameResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpStoreText(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpStoreText command;
	anyCommand.UnpackTo(&command);

	switch (command.languageId_case())
	{
		default:
		case protos::expert::action::UpStoreText::kInConstLanguageId:
		{
			ExpertAction::UpStoreText(expert_conf::CONST_TYPE_OP_CONST, command.inconstlanguageid());
			break;
		}
		case protos::expert::action::UpStoreText::kInGoalLanguageId:
		{
			ExpertAction::UpStoreText(expert_conf::CONST_TYPE_OP_GOAL, command.ingoallanguageid());
			break;
		}
		case protos::expert::action::UpStoreText::kInSnLanguageId:
		{
			ExpertAction::UpStoreText(expert_conf::CONST_TYPE_OP_SN, command.insnlanguageid());
			break;
		}
	}

	protos::expert::action::UpStoreTextResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpStoreTypeName(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpStoreTypeName command;
	anyCommand.UnpackTo(&command);

	switch (command.typeId_case())
	{
		default:
		case protos::expert::action::UpStoreTypeName::kInConstTypeId:
		{
			ExpertAction::UpStoreTypeName(expert_conf::CONST_TYPE_OP_CONST, command.inconsttypeid());
			break;
		}
		case protos::expert::action::UpStoreTypeName::kInGoalTypeId:
		{
			ExpertAction::UpStoreTypeName(expert_conf::CONST_TYPE_OP_GOAL, command.ingoaltypeid());
			break;
		}
		case protos::expert::action::UpStoreTypeName::kInSnTypeId:
		{
			ExpertAction::UpStoreTypeName(expert_conf::CONST_TYPE_OP_SN, command.insntypeid());
			break;
		}
	}

	protos::expert::action::UpStoreTypeNameResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpTargetObjects(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpTargetObjects command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpTargetObjects(command.inconsttarget(), command.inconsttargetaction(), command.inconstformation(), command.inconstattackstance());

	protos::expert::action::UpTargetObjectsResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpTargetPoint(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpTargetPoint command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpTargetPoint(command.ingoalpoint(), command.inconsttargetaction(), command.inconstformation(), command.inconstattackstance());

	protos::expert::action::UpTargetPointResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpTrain(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpTrain command;
	anyCommand.UnpackTo(&command);

	switch (command.unitId_case())
	{
		default:
		case protos::expert::action::UpTrain::kInConstUnitId:
		{
			ExpertAction::UpTrain(command.ingoalescrowstate(), expert_conf::CONST_TYPE_OP_CONST, command.inconstunitid());
			break;
		}
		case protos::expert::action::UpTrain::kInGoalUnitId:
		{
			ExpertAction::UpTrain(command.ingoalescrowstate(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalunitid());
			break;
		}
		case protos::expert::action::UpTrain::kInSnUnitId:
		{
			ExpertAction::UpTrain(command.ingoalescrowstate(), expert_conf::CONST_TYPE_OP_SN, command.insnunitid());
			break;
		}
	}

	protos::expert::action::UpTrainResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpTributeToPlayer(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpTributeToPlayer command;
	anyCommand.UnpackTo(&command);

	switch (command.value_case())
	{
		default:
		case protos::expert::action::UpTributeToPlayer::kInConstValue:
		{
			ExpertAction::UpTributeToPlayer(command.inplayeranyplayer(), command.inconstresourceamount(), expert_conf::CONST_TYPE_OP_CONST, command.inconstvalue());
			break;
		}
		case protos::expert::action::UpTributeToPlayer::kInGoalValue:
		{
			ExpertAction::UpTributeToPlayer(command.inplayeranyplayer(), command.inconstresourceamount(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalvalue());
			break;
		}
		case protos::expert::action::UpTributeToPlayer::kInSnValue:
		{
			ExpertAction::UpTributeToPlayer(command.inplayeranyplayer(), command.inconstresourceamount(), expert_conf::CONST_TYPE_OP_SN, command.insnvalue());
			break;
		}
	}

	protos::expert::action::UpTributeToPlayerResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpUngarrison(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpUngarrison command;
	anyCommand.UnpackTo(&command);

	switch (command.objectId_case())
	{
		default:
		case protos::expert::action::UpUngarrison::kInConstObjectId:
		{
			ExpertAction::UpUngarrison(expert_conf::CONST_TYPE_OP_CONST, command.inconstobjectid());
			break;
		}
		case protos::expert::action::UpUngarrison::kInGoalObjectId:
		{
			ExpertAction::UpUngarrison(expert_conf::CONST_TYPE_OP_GOAL, command.ingoalobjectid());
			break;
		}
		case protos::expert::action::UpUngarrison::kInSnObjectId:
		{
			ExpertAction::UpUngarrison(expert_conf::CONST_TYPE_OP_SN, command.insnobjectid());
			break;
		}
	}

	protos::expert::action::UpUngarrisonResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpUpdateTargets(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpUpdateTargets command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpUpdateTargets();

	protos::expert::action::UpUpdateTargetsResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatDebug(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatDebug command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatDebug(command.intextstring());

	protos::expert::action::ChatDebugResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::FeBreakPoint(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::FeBreakPoint command;
	anyCommand.UnpackTo(&command);

	ExpertAction::FeBreakPoint(command.param1(), command.param2(), command.param3(), command.param4());

	protos::expert::action::FeBreakPointResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::SkyboxClearSignal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::SkyboxClearSignal command;
	anyCommand.UnpackTo(&command);

	ExpertAction::SkyboxClearSignal(command.param());

	protos::expert::action::SkyboxClearSignalResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::SkyboxSetNameMode(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::SkyboxSetNameMode command;
	anyCommand.UnpackTo(&command);

	ExpertAction::SkyboxSetNameMode(command.param());

	protos::expert::action::SkyboxSetNameModeResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpChatDataToAllUsingId(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpChatDataToAllUsingId command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpChatDataToAllUsingId(command.param1(), command.param2(), command.param3());

	protos::expert::action::UpChatDataToAllUsingIdResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpChatDataToPlayerUsingId(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpChatDataToPlayerUsingId command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpChatDataToPlayerUsingId(command.param1(), command.param2(), command.param3(), command.param4());

	protos::expert::action::UpChatDataToPlayerUsingIdResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetTreatyData(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetTreatyData command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetTreatyData(command.param());

	protos::expert::action::UpGetTreatyDataResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpTestharnessReport(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpTestharnessReport command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpTestharnessReport(command.param1(), command.param2(), command.param3());

	protos::expert::action::UpTestharnessReportResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpTestharnessTest(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpTestharnessTest command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpTestharnessTest(command.param1(), command.param2(), command.param3(), command.param4());

	protos::expert::action::UpTestharnessTestResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetAlliedTarget(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetAlliedTarget command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetAlliedTarget(command.param1(), command.param2());

	protos::expert::action::UpGetAlliedTargetResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetGuardState(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetGuardState command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetGuardState(command.outgoalstate());

	protos::expert::action::UpGetGuardStateResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetUpgradeId(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetUpgradeId command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetUpgradeId(command.inplayeranyplayer(), command.inconstcount(), command.ingoaltypeid(), command.outgoalupgradeid());

	protos::expert::action::UpGetUpgradeIdResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpOutOfSync(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpOutOfSync command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpOutOfSync();

	protos::expert::action::UpOutOfSyncResult result;
	anyResult->PackFrom(result);
}
