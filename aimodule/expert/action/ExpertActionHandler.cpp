#include "ExpertActionHandler.h"

#include "expert/action/ExpertAction.h"
#include "protos/expert/action/action.pb.h"

void ExpertActionHandler::AcknowledgeEvent(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::AcknowledgeEvent command;
	anyCommand.UnpackTo(&command);

	ExpertAction::AcknowledgeEvent(command.eventtype(), command.id());

	protos::expert::action::AcknowledgeEventResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::AcknowledgeTaunt(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::AcknowledgeTaunt command;
	anyCommand.UnpackTo(&command);

	ExpertAction::AcknowledgeTaunt(command.playernumber(), command.tauntid());

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

	ExpertAction::Build(command.buildingtype());

	protos::expert::action::BuildResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::BuildForward(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::BuildForward command;
	anyCommand.UnpackTo(&command);

	ExpertAction::BuildForward(command.buildingtype());

	protos::expert::action::BuildForwardResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::BuildGate(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::BuildGate command;
	anyCommand.UnpackTo(&command);

	ExpertAction::BuildGate(command.perimeter());

	protos::expert::action::BuildGateResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::BuildWall(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::BuildWall command;
	anyCommand.UnpackTo(&command);

	ExpertAction::BuildWall(command.perimeter(), command.walltype());

	protos::expert::action::BuildWallResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::BuyCommodity(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::BuyCommodity command;
	anyCommand.UnpackTo(&command);

	ExpertAction::BuyCommodity(command.commoditytype());

	protos::expert::action::BuyCommodityResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatLocal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatLocal command;
	anyCommand.UnpackTo(&command);

	//ExpertAction::ChatLocal(command.text());

	protos::expert::action::ChatLocalResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatLocalUsingId(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatLocalUsingId command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatLocalUsingId(command.stringid());

	protos::expert::action::ChatLocalUsingIdResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatLocalUsingRange(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatLocalUsingRange command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatLocalUsingRange(command.stringidstart(), command.stringidrange());

	protos::expert::action::ChatLocalUsingRangeResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatLocalToSelf(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatLocalToSelf command;
	anyCommand.UnpackTo(&command);

	//ExpertAction::ChatLocalToSelf(command.text());

	protos::expert::action::ChatLocalToSelfResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatToAll(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatToAll command;
	anyCommand.UnpackTo(&command);

	//ExpertAction::ChatToAll(command.text());

	protos::expert::action::ChatToAllResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatToAllUsingId(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatToAllUsingId command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatToAllUsingId(command.stringid());

	protos::expert::action::ChatToAllUsingIdResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatToAllUsingRange(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatToAllUsingRange command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatToAllUsingRange(command.stringidstart(), command.stringidrange());

	protos::expert::action::ChatToAllUsingRangeResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatToAllies(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatToAllies command;
	anyCommand.UnpackTo(&command);

	//ExpertAction::ChatToAllies(command.text());

	protos::expert::action::ChatToAlliesResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatToAlliesUsingId(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatToAlliesUsingId command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatToAlliesUsingId(command.stringid());

	protos::expert::action::ChatToAlliesUsingIdResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatToAlliesUsingRange(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatToAlliesUsingRange command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatToAlliesUsingRange(command.stringidstart(), command.stringidrange());

	protos::expert::action::ChatToAlliesUsingRangeResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatToEnemies(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatToEnemies command;
	anyCommand.UnpackTo(&command);

	//ExpertAction::ChatToEnemies(command.text());

	protos::expert::action::ChatToEnemiesResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatToEnemiesUsingId(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatToEnemiesUsingId command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatToEnemiesUsingId(command.stringid());

	protos::expert::action::ChatToEnemiesUsingIdResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatToEnemiesUsingRange(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatToEnemiesUsingRange command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatToEnemiesUsingRange(command.stringidstart(), command.stringidrange());

	protos::expert::action::ChatToEnemiesUsingRangeResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatToPlayer(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatToPlayer command;
	anyCommand.UnpackTo(&command);

	//ExpertAction::ChatToPlayer(command.playernumber(), command.text());

	protos::expert::action::ChatToPlayerResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatToPlayerUsingId(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatToPlayerUsingId command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatToPlayerUsingId(command.playernumber(), command.stringid());

	protos::expert::action::ChatToPlayerUsingIdResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatToPlayerUsingRange(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatToPlayerUsingRange command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatToPlayerUsingRange(command.playernumber(), command.stringidstart(), command.stringidrange());

	protos::expert::action::ChatToPlayerUsingRangeResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ChatTrace(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ChatTrace command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ChatTrace(command.tracenumber());

	protos::expert::action::ChatTraceResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ClearTributeMemory(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ClearTributeMemory command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ClearTributeMemory(command.playernumber(), command.resourcetype());

	protos::expert::action::ClearTributeMemoryResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::DeleteBuilding(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::DeleteBuilding command;
	anyCommand.UnpackTo(&command);

	ExpertAction::DeleteBuilding(command.buildingtype());

	protos::expert::action::DeleteBuildingResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::DeleteUnit(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::DeleteUnit command;
	anyCommand.UnpackTo(&command);

	ExpertAction::DeleteUnit(command.unittype());

	protos::expert::action::DeleteUnitResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::DisableRule(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::DisableRule command;
	anyCommand.UnpackTo(&command);

	ExpertAction::DisableRule(command.groupid());

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

	ExpertAction::DisableTimer(command.timerid());

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

	ExpertAction::EnableRule(command.groupid());

	protos::expert::action::EnableRuleResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::EnableTimer(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::EnableTimer command;
	anyCommand.UnpackTo(&command);

	ExpertAction::EnableTimer(command.timerid(), command.timeinterval());

	protos::expert::action::EnableTimerResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::EnableWallPlacement(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::EnableWallPlacement command;
	anyCommand.UnpackTo(&command);

	ExpertAction::EnableWallPlacement(command.perimeter());

	protos::expert::action::EnableWallPlacementResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::GenerateRandomNumber(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::GenerateRandomNumber command;
	anyCommand.UnpackTo(&command);

	ExpertAction::GenerateRandomNumber(command.range());

	protos::expert::action::GenerateRandomNumberResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::Log(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::Log command;
	anyCommand.UnpackTo(&command);

	//ExpertAction::Log(command.text());

	protos::expert::action::LogResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::LogTrace(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::LogTrace command;
	anyCommand.UnpackTo(&command);

	ExpertAction::LogTrace(command.tracenumber());

	protos::expert::action::LogTraceResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::ReleaseEscrow(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::ReleaseEscrow command;
	anyCommand.UnpackTo(&command);

	ExpertAction::ReleaseEscrow(command.resourcetype());

	protos::expert::action::ReleaseEscrowResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::Research(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::Research command;
	anyCommand.UnpackTo(&command);

	ExpertAction::Research(command.researchtype());

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

	ExpertAction::SellCommodity(command.commoditytype());

	protos::expert::action::SellCommodityResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::SetDifficultyParameter(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::SetDifficultyParameter command;
	anyCommand.UnpackTo(&command);

	ExpertAction::SetDifficultyParameter(command.difficultyparameter(), command.value());

	protos::expert::action::SetDifficultyParameterResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::SetDoctrine(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::SetDoctrine command;
	anyCommand.UnpackTo(&command);

	ExpertAction::SetDoctrine(command.doctrine());

	protos::expert::action::SetDoctrineResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::SetEscrowPercentage(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::SetEscrowPercentage command;
	anyCommand.UnpackTo(&command);

	ExpertAction::SetEscrowPercentage(command.resourcetype(), command.percentage());

	protos::expert::action::SetEscrowPercentageResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::SetGoal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::SetGoal command;
	anyCommand.UnpackTo(&command);

	ExpertAction::SetGoal(command.goalid(), command.goalvalue());

	protos::expert::action::SetGoalResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::SetSharedGoal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::SetSharedGoal command;
	anyCommand.UnpackTo(&command);

	ExpertAction::SetSharedGoal(command.goalid(), command.goal());

	protos::expert::action::SetSharedGoalResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::SetSignal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::SetSignal command;
	anyCommand.UnpackTo(&command);

	ExpertAction::SetSignal(command.signalid());

	protos::expert::action::SetSignalResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::SetStance(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::SetStance command;
	anyCommand.UnpackTo(&command);

	ExpertAction::SetStance(command.playernumber(), command.stance());

	protos::expert::action::SetStanceResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::SetStrategicNumber(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::SetStrategicNumber command;
	anyCommand.UnpackTo(&command);

	ExpertAction::SetStrategicNumber(command.strategicnumber(), command.value());

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

	ExpertAction::Taunt(command.tauntnumber());

	protos::expert::action::TauntResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::TauntUsingRange(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::TauntUsingRange command;
	anyCommand.UnpackTo(&command);

	ExpertAction::TauntUsingRange(command.tauntidstart(), command.tauntidrange());

	protos::expert::action::TauntUsingRangeResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::Train(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::Train command;
	anyCommand.UnpackTo(&command);

	ExpertAction::Train(command.unittype());

	protos::expert::action::TrainResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::TributeToPlayer(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::TributeToPlayer command;
	anyCommand.UnpackTo(&command);

	ExpertAction::TributeToPlayer(command.playernumber(), command.resourcetype(), command.tributeamount());

	protos::expert::action::TributeToPlayerResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpAddCostData(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpAddCostData command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpAddCostData(command.goalid(), command.typeop(), command.opvalue());

	protos::expert::action::UpAddCostDataResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpAddObjectById(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpAddObjectById command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpAddObjectById(command.searchsource(), command.typeop(), command.opid());

	protos::expert::action::UpAddObjectByIdResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpAddObjectCost(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpAddObjectCost command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpAddObjectCost(command.typeop1(), command.objectid(), command.typeop2(), command.value());

	protos::expert::action::UpAddObjectCostResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpAddPoint(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpAddPoint command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpAddPoint(command.goalpoint1(), command.goalpoint2(), command.typeop(), command.count());

	protos::expert::action::UpAddPointResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpAddResearchCost(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpAddResearchCost command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpAddResearchCost(command.typeop1(), command.techid(), command.typeop2(), command.value());

	protos::expert::action::UpAddResearchCostResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpAssignBuilders(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpAssignBuilders command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpAssignBuilders(command.typeop1(), command.buildingid(), command.typeop2(), command.value());

	protos::expert::action::UpAssignBuildersResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpBoundPoint(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpBoundPoint command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpBoundPoint(command.goalpoint1(), command.goalpoint2());

	protos::expert::action::UpBoundPointResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpBoundPrecisePoint(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpBoundPrecisePoint command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpBoundPrecisePoint(command.goalpoint(), command.precise(), command.typeop(), command.border());

	protos::expert::action::UpBoundPrecisePointResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpBuild(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpBuild command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpBuild(command.placementtype(), command.escrowstate(), command.typeop(), command.buildingid());

	protos::expert::action::UpBuildResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpBuildLine(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpBuildLine command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpBuildLine(command.goalpoint1(), command.goalpoint2(), command.typeop(), command.buildingid());

	protos::expert::action::UpBuildLineResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpBuyCommodity(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpBuyCommodity command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpBuyCommodity(command.typeop1(), command.resourceamount(), command.typeop2(), command.value());

	protos::expert::action::UpBuyCommodityResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpChangeName(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpChangeName command;
	anyCommand.UnpackTo(&command);

	//ExpertAction::UpChangeName(command.newname());

	protos::expert::action::UpChangeNameResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpChatDataToAll(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpChatDataToAll command;
	anyCommand.UnpackTo(&command);

	//ExpertAction::UpChatDataToAll(command.format(), command.typeop(), command.value());

	protos::expert::action::UpChatDataToAllResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpChatDataToPlayer(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpChatDataToPlayer command;
	anyCommand.UnpackTo(&command);

	//ExpertAction::UpChatDataToPlayer(command.player(), command.format(), command.typeop(), command.value());

	protos::expert::action::UpChatDataToPlayerResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpChatDataToSelf(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpChatDataToSelf command;
	anyCommand.UnpackTo(&command);

	//ExpertAction::UpChatDataToSelf(command.format(), command.typeop(), command.value());

	protos::expert::action::UpChatDataToSelfResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpCleanSearch(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpCleanSearch command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpCleanSearch(command.searchsource(), command.objectdata(), command.searchorder());

	protos::expert::action::UpCleanSearchResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpCopyPoint(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpCopyPoint command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpCopyPoint(command.goalpoint1(), command.goalpoint2());

	protos::expert::action::UpCopyPointResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpCreateGroup(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpCreateGroup command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpCreateGroup(command.goalindex(), command.goalcount(), command.typeop(), command.groupid());

	protos::expert::action::UpCreateGroupResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpCrossTiles(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpCrossTiles command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpCrossTiles(command.goalpoint1(), command.goalpoint2(), command.typeop(), command.tiles());

	protos::expert::action::UpCrossTilesResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpDeleteDistantFarms(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpDeleteDistantFarms command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpDeleteDistantFarms(command.typeop(), command.value());

	protos::expert::action::UpDeleteDistantFarmsResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpDeleteIdleUnits(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpDeleteIdleUnits command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpDeleteIdleUnits(command.idletype());

	protos::expert::action::UpDeleteIdleUnitsResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpDeleteObjects(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpDeleteObjects command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpDeleteObjects(command.typeop1(), command.unitid(), command.typeop2(), command.hitpoints());

	protos::expert::action::UpDeleteObjectsResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpDisbandGroupType(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpDisbandGroupType command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpDisbandGroupType(command.grouptype());

	protos::expert::action::UpDisbandGroupTypeResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpDropResources(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpDropResources command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpDropResources(command.resource(), command.typeop(), command.value());

	protos::expert::action::UpDropResourcesResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFilterDistance(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFilterDistance command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpFilterDistance(command.typeop1(), command.mindistance(), command.typeop2(), command.maxdistance());

	protos::expert::action::UpFilterDistanceResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFilterExclude(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFilterExclude command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpFilterExclude(command.cmdid(), command.actionid(), command.orderid(), command.classid());

	protos::expert::action::UpFilterExcludeResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFilterGarrison(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFilterGarrison command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpFilterGarrison(command.typeop1(), command.mingarrison(), command.typeop2(), command.maxgarrison());

	protos::expert::action::UpFilterGarrisonResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFilterInclude(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFilterInclude command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpFilterInclude(command.cmdid(), command.actionid(), command.orderid(), command.onmainland());

	protos::expert::action::UpFilterIncludeResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFilterRange(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFilterRange command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpFilterRange(command.mingarrison(), command.maxgarrison(), command.mindistance(), command.maxdistance());

	protos::expert::action::UpFilterRangeResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFilterStatus(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFilterStatus command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpFilterStatus(command.typeop1(), command.objectstatus(), command.typeop2(), command.objectlist());

	protos::expert::action::UpFilterStatusResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFindFlare(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFindFlare command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpFindFlare(command.goalpoint());

	protos::expert::action::UpFindFlareResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFindLocal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFindLocal command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpFindLocal(command.typeop1(), command.unitid(), command.typeop2(), command.count());

	protos::expert::action::UpFindLocalResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFindNextPlayer(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFindNextPlayer command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpFindNextPlayer(command.playerstance(), command.findplayermethod(), command.goalplayerid());

	protos::expert::action::UpFindNextPlayerResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFindPlayer(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFindPlayer command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpFindPlayer(command.playerstance(), command.findplayermethod(), command.goalplayerid());

	protos::expert::action::UpFindPlayerResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFindPlayerFlare(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFindPlayerFlare command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpFindPlayerFlare(command.player(), command.goalpoint());

	protos::expert::action::UpFindPlayerFlareResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFindRemote(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFindRemote command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpFindRemote(command.typeop1(), command.unitid(), command.typeop2(), command.count());

	protos::expert::action::UpFindRemoteResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFindResource(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFindResource command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpFindResource(command.typeop1(), command.resource(), command.typeop2(), command.count());

	protos::expert::action::UpFindResourceResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFindStatusLocal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFindStatusLocal command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpFindStatusLocal(command.typeop1(), command.unitid(), command.typeop2(), command.count());

	protos::expert::action::UpFindStatusLocalResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpFindStatusRemote(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpFindStatusRemote command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpFindStatusRemote(command.typeop1(), command.unitid(), command.typeop2(), command.count());

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

	ExpertAction::UpGarrison(command.objectid(), command.typeop(), command.unitid());

	protos::expert::action::UpGarrisonResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGatherInside(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGatherInside command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGatherInside(command.typeop1(), command.buildingid(), command.typeop2(), command.state());

	protos::expert::action::UpGatherInsideResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetAttackerClass(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetAttackerClass command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetAttackerClass(command.goalsourceclass());

	protos::expert::action::UpGetAttackerClassResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetCostDelta(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetCostDelta command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetCostDelta(command.goalid());

	protos::expert::action::UpGetCostDeltaResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetEvent(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetEvent command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetEvent(command.typeop(), command.eventid(), command.goalvalue());

	protos::expert::action::UpGetEventResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetFact(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetFact command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetFact(command.factid(), command.factparam(), command.goalid());

	protos::expert::action::UpGetFactResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetFactMax(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetFactMax command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetFactMax(command.player(), command.factid(), command.param(), command.goaldata());

	protos::expert::action::UpGetFactMaxResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetFactMin(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetFactMin command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetFactMin(command.player(), command.factid(), command.param(), command.goaldata());

	protos::expert::action::UpGetFactMinResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetFactSum(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetFactSum command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetFactSum(command.player(), command.factid(), command.param(), command.goaldata());

	protos::expert::action::UpGetFactSumResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetFocusFact(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetFocusFact command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetFocusFact(command.factid(), command.param(), command.goaldata());

	protos::expert::action::UpGetFocusFactResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetGroupSize(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetGroupSize command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetGroupSize(command.typeop(), command.groupid(), command.goalsize());

	protos::expert::action::UpGetGroupSizeResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetGuardState(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetGuardState command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetGuardState(command.goalstate());

	protos::expert::action::UpGetGuardStateResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetIndirectGoal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetIndirectGoal command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetIndirectGoal(command.typeop1(), command.goalid(), command.goalvalue());

	protos::expert::action::UpGetIndirectGoalResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetObjectData(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetObjectData command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetObjectData(command.objectdata(), command.goaldata());

	protos::expert::action::UpGetObjectDataResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetObjectTargetData(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetObjectTargetData command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetObjectTargetData(command.objectdata(), command.goaldata());

	protos::expert::action::UpGetObjectTargetDataResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetObjectTypeData(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetObjectTypeData command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetObjectTypeData(command.typeop(), command.objecttypeid(), command.objectdata(), command.goaldata());

	protos::expert::action::UpGetObjectTypeDataResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetPathDistance(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetPathDistance command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetPathDistance(command.goalpoint(), command.strict(), command.goaldata());

	protos::expert::action::UpGetPathDistanceResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetPlayerColor(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetPlayerColor command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetPlayerColor(command.player(), command.goalcolorid());

	protos::expert::action::UpGetPlayerColorResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetPlayerFact(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetPlayerFact command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetPlayerFact(command.player(), command.factid(), command.param(), command.goaldata());

	protos::expert::action::UpGetPlayerFactResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetPoint(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetPoint command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetPoint(command.positiontype(), command.goalpoint());

	protos::expert::action::UpGetPointResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetPointContains(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetPointContains command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetPointContains(command.goalpoint(), command.goalid(), command.typeop(), command.objectid());

	protos::expert::action::UpGetPointContainsResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetPointDistance(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetPointDistance command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetPointDistance(command.goalpoint1(), command.goalpoint2(), command.goaldistance());

	protos::expert::action::UpGetPointDistanceResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetPointElevation(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetPointElevation command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetPointElevation(command.goalpoint(), command.goaldata());

	protos::expert::action::UpGetPointElevationResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetPointTerrain(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetPointTerrain command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetPointTerrain(command.goalpoint(), command.goalterrain());

	protos::expert::action::UpGetPointTerrainResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetPointZone(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetPointZone command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetPointZone(command.goalpoint(), command.goaldata());

	protos::expert::action::UpGetPointZoneResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetPreciseTime(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetPreciseTime command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetPreciseTime(command.goalstart(), command.goaltime());

	protos::expert::action::UpGetPreciseTimeResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetProjectilePlayer(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetProjectilePlayer command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetProjectilePlayer(command.projectiletype(), command.goalplayerid());

	protos::expert::action::UpGetProjectilePlayerResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetRuleId(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetRuleId command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetRuleId(command.goalruleid());

	protos::expert::action::UpGetRuleIdResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetSearchState(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetSearchState command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetSearchState(command.goalstate());

	protos::expert::action::UpGetSearchStateResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetSharedGoal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetSharedGoal command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetSharedGoal(command.typeop(), command.sharedgoalid(), command.goalvalue());

	protos::expert::action::UpGetSharedGoalResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetSignal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetSignal command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetSignal(command.typeop(), command.signalid(), command.goalvalue());

	protos::expert::action::UpGetSignalResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetTargetFact(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetTargetFact command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetTargetFact(command.factid(), command.param(), command.goaldata());

	protos::expert::action::UpGetTargetFactResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetThreatData(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetThreatData command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetThreatData(command.goalelapsedtime(), command.goalplayerid(), command.goalsourceclass(), command.goaltargetclass());

	protos::expert::action::UpGetThreatDataResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetTimer(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetTimer command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetTimer(command.typeop(), command.timerid(), command.goalvalue());

	protos::expert::action::UpGetTimerResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetUpgradeId(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetUpgradeId command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetUpgradeId(command.player(), command.count(), command.goaltypeid(), command.goalupgradeid());

	protos::expert::action::UpGetUpgradeIdResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetVictoryData(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetVictoryData command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetVictoryData(command.goalplayerid(), command.goaltype(), command.goaltime());

	protos::expert::action::UpGetVictoryDataResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGetVictoryLimit(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGetVictoryLimit command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGetVictoryLimit(command.goallimit());

	protos::expert::action::UpGetVictoryLimitResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpGuardUnit(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpGuardUnit command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpGuardUnit(command.objectid(), command.typeop(), command.unitid());

	protos::expert::action::UpGuardUnitResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpJumpDirect(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpJumpDirect command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpJumpDirect(command.typeop(), command.ruleid());

	protos::expert::action::UpJumpDirectResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpJumpDynamic(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpJumpDynamic command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpJumpDynamic(command.typeop(), command.ruledelta());

	protos::expert::action::UpJumpDynamicResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpJumpRule(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpJumpRule command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpJumpRule(command.ruledelta());

	protos::expert::action::UpJumpRuleResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpLerpPercent(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpLerpPercent command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpLerpPercent(command.goalpoint1(), command.goalpoint2(), command.typeop(), command.percent());

	protos::expert::action::UpLerpPercentResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpLerpTiles(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpLerpTiles command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpLerpTiles(command.goalpoint1(), command.goalpoint2(), command.typeop(), command.tiles());

	protos::expert::action::UpLerpTilesResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpLogData(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpLogData command;
	anyCommand.UnpackTo(&command);

	//ExpertAction::UpLogData(command.plain(), command.format(), command.typeop(), command.value());

	protos::expert::action::UpLogDataResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpModifyEscrow(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpModifyEscrow command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpModifyEscrow(command.resource(), command.mathop(), command.value());

	protos::expert::action::UpModifyEscrowResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpModifyFlag(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpModifyFlag command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpModifyFlag(command.goalid(), command.mathop(), command.value());

	protos::expert::action::UpModifyFlagResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpModifyGoal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpModifyGoal command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpModifyGoal(command.goalid(), command.mathop(), command.value());

	protos::expert::action::UpModifyGoalResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpModifyGroupFlag(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpModifyGroupFlag command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpModifyGroupFlag(command.on(), command.typeop(), command.groupid());

	protos::expert::action::UpModifyGroupFlagResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpModifySn(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpModifySn command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpModifySn(command.snid(), command.mathop(), command.value());

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

	ExpertAction::UpRemoveObjects(command.searchsource(), command.objectdata(), command.typeop(), command.value());

	protos::expert::action::UpRemoveObjectsResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpRequestHunters(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpRequestHunters command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpRequestHunters(command.typeop(), command.value());

	protos::expert::action::UpRequestHuntersResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpResearch(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpResearch command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpResearch(command.escrowstate(), command.typeop(), command.techid());

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

	ExpertAction::UpResetBuilding(command.preserveresearch(), command.typeop(), command.buildingid());

	protos::expert::action::UpResetBuildingResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpResetCostData(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpResetCostData command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpResetCostData(command.goalid());

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

	ExpertAction::UpResetGroup(command.typeop(), command.groupid());

	protos::expert::action::UpResetGroupResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpResetPlacement(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpResetPlacement command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpResetPlacement(command.typeop(), command.buildingid());

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

	ExpertAction::UpResetSearch(command.localindex(), command.locallist(), command.remoteindex(), command.remotelist());

	protos::expert::action::UpResetSearchResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpResetTargetPriorities(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpResetTargetPriorities command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpResetTargetPriorities(command.prioritytype(), command.mode());

	protos::expert::action::UpResetTargetPrioritiesResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpResetUnit(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpResetUnit command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpResetUnit(command.typeop(), command.unitid());

	protos::expert::action::UpResetUnitResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpRetaskGatherers(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpRetaskGatherers command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpRetaskGatherers(command.resource(), command.typeop(), command.value());

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

	ExpertAction::UpRetreatTo(command.objectid(), command.typeop(), command.unitid());

	protos::expert::action::UpRetreatToResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSellCommodity(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSellCommodity command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpSellCommodity(command.typeop1(), command.resourceamount(), command.typeop2(), command.value());

	protos::expert::action::UpSellCommodityResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSendFlare(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSendFlare command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpSendFlare(command.goalpoint());

	protos::expert::action::UpSendFlareResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSendScout(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSendScout command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpSendScout(command.grouptype(), command.positiontype());

	protos::expert::action::UpSendScoutResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetAttackStance(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetAttackStance command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpSetAttackStance(command.unitid(), command.typeop(), command.attackstance());

	protos::expert::action::UpSetAttackStanceResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetDefensePriority(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetDefensePriority command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpSetDefensePriority(command.typeop1(), command.buildingid(), command.typeop2(), command.value());

	protos::expert::action::UpSetDefensePriorityResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetEvent(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetEvent command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpSetEvent(command.typeop1(), command.eventid(), command.typeop2(), command.value());

	protos::expert::action::UpSetEventResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetGroup(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetGroup command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpSetGroup(command.searchsource(), command.typeop(), command.groupid());

	protos::expert::action::UpSetGroupResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetIndirectGoal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetIndirectGoal command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpSetIndirectGoal(command.typeop1(), command.goalid(), command.typeop2(), command.value());

	protos::expert::action::UpSetIndirectGoalResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetOffensePriority(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetOffensePriority command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpSetOffensePriority(command.typeop1(), command.objectid(), command.typeop2(), command.value());

	protos::expert::action::UpSetOffensePriorityResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetPlacementData(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetPlacementData command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpSetPlacementData(command.playerally(), command.objectid(), command.typeop(), command.value());

	protos::expert::action::UpSetPlacementDataResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetPreciseTargetPoint(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetPreciseTargetPoint command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpSetPreciseTargetPoint(command.goalpoint());

	protos::expert::action::UpSetPreciseTargetPointResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetSharedGoal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetSharedGoal command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpSetSharedGoal(command.typeop1(), command.sharedgoalid(), command.typeop2(), command.value());

	protos::expert::action::UpSetSharedGoalResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetSignal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetSignal command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpSetSignal(command.typeop1(), command.signalid(), command.typeop2(), command.value());

	protos::expert::action::UpSetSignalResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetTargetById(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetTargetById command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpSetTargetById(command.typeop(), command.id());

	protos::expert::action::UpSetTargetByIdResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetTargetObject(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetTargetObject command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpSetTargetObject(command.searchsource(), command.typeop(), command.index());

	protos::expert::action::UpSetTargetObjectResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetTargetPoint(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetTargetPoint command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpSetTargetPoint(command.goalpoint());

	protos::expert::action::UpSetTargetPointResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetTimer(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetTimer command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpSetTimer(command.typeop1(), command.timerid(), command.typeop2(), command.value());

	protos::expert::action::UpSetTimerResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpSetupCostData(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpSetupCostData command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpSetupCostData(command.resetcost(), command.goalid());

	protos::expert::action::UpSetupCostDataResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpStoreMapName(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpStoreMapName command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpStoreMapName(command.extension());

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

	ExpertAction::UpStorePlayerChat(command.player());

	protos::expert::action::UpStorePlayerChatResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpStorePlayerName(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpStorePlayerName command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpStorePlayerName(command.player());

	protos::expert::action::UpStorePlayerNameResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpStoreTechName(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpStoreTechName command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpStoreTechName(command.typeop(), command.techid());

	protos::expert::action::UpStoreTechNameResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpStoreText(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpStoreText command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpStoreText(command.typeop(), command.languageid());

	protos::expert::action::UpStoreTextResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpStoreTypeName(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpStoreTypeName command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpStoreTypeName(command.typeop(), command.objecttypeid());

	protos::expert::action::UpStoreTypeNameResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpTargetObjects(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpTargetObjects command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpTargetObjects(command.target(), command.action(), command.formation(), command.attackstance());

	protos::expert::action::UpTargetObjectsResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpTargetPoint(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpTargetPoint command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpTargetPoint(command.goalpoint(), command.action(), command.formation(), command.attackstance());

	protos::expert::action::UpTargetPointResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpTrain(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpTrain command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpTrain(command.escrowstate(), command.typeop(), command.unitid());

	protos::expert::action::UpTrainResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpTributeToPlayer(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpTributeToPlayer command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpTributeToPlayer(command.player(), command.resourceamount(), command.typeop(), command.value());

	protos::expert::action::UpTributeToPlayerResult result;
	anyResult->PackFrom(result);
}

void ExpertActionHandler::UpUngarrison(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::action::UpUngarrison command;
	anyCommand.UnpackTo(&command);

	ExpertAction::UpUngarrison(command.typeop(), command.objectid());

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
