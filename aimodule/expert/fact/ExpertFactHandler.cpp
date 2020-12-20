#include "ExpertFactHandler.h"

#include "expert/fact/ExpertFact.h"
#include "protos/expert/expert_api.pb.h"
#include "protos/expert/fact/fact.pb.h"

void ExpertFactHandler::AttackSoldierCount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::AttackSoldierCount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::AttackSoldierCount();

	protos::expert::fact::AttackSoldierCountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::AttackWarboatCount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::AttackWarboatCount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::AttackWarboatCount();

	protos::expert::fact::AttackWarboatCountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::BuildingAvailable(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::BuildingAvailable command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::BuildingAvailable(command.inconstbuildingid());

	protos::expert::fact::BuildingAvailableResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::BuildingCount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::BuildingCount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::BuildingCount();

	protos::expert::fact::BuildingCountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::BuildingCountTotal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::BuildingCountTotal command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::BuildingCountTotal();

	protos::expert::fact::BuildingCountTotalResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::BuildingTypeCount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::BuildingTypeCount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::BuildingTypeCount(command.inconstbuildingid());

	protos::expert::fact::BuildingTypeCountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::BuildingTypeCountTotal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::BuildingTypeCountTotal command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::BuildingTypeCountTotal(command.inconstbuildingid());

	protos::expert::fact::BuildingTypeCountTotalResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CanAffordBuilding(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CanAffordBuilding command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::CanAffordBuilding(command.inconstbuildingid());

	protos::expert::fact::CanAffordBuildingResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CanAffordCompleteWall(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CanAffordCompleteWall command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::CanAffordCompleteWall(command.inconstperimeter(), command.inconstwallid());

	protos::expert::fact::CanAffordCompleteWallResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CanAffordResearch(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CanAffordResearch command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::CanAffordResearch(command.inconsttechid());

	protos::expert::fact::CanAffordResearchResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CanAffordUnit(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CanAffordUnit command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::CanAffordUnit(command.inconstunitid());

	protos::expert::fact::CanAffordUnitResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CanBuild(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CanBuild command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::CanBuild(command.inconstbuildingid());

	protos::expert::fact::CanBuildResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CanBuildGate(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CanBuildGate command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::CanBuildGate(command.inconstperimeter());

	protos::expert::fact::CanBuildGateResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CanBuildGateWithEscrow(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CanBuildGateWithEscrow command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::CanBuildGateWithEscrow(command.inconstperimeter());

	protos::expert::fact::CanBuildGateWithEscrowResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CanBuildWall(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CanBuildWall command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::CanBuildWall(command.inconstperimeter(), command.inconstwallid());

	protos::expert::fact::CanBuildWallResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CanBuildWallWithEscrow(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CanBuildWallWithEscrow command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::CanBuildWallWithEscrow(command.inconstperimeter(), command.inconstwallid());

	protos::expert::fact::CanBuildWallWithEscrowResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CanBuildWithEscrow(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CanBuildWithEscrow command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::CanBuildWithEscrow(command.inconstbuildingid());

	protos::expert::fact::CanBuildWithEscrowResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CanBuyCommodity(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CanBuyCommodity command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::CanBuyCommodity(command.inconstcommodity());

	protos::expert::fact::CanBuyCommodityResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CanResearch(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CanResearch command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::CanResearch(command.inconsttechid());

	protos::expert::fact::CanResearchResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CanResearchWithEscrow(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CanResearchWithEscrow command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::CanResearchWithEscrow(command.inconsttechid());

	protos::expert::fact::CanResearchWithEscrowResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CanSellCommodity(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CanSellCommodity command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::CanSellCommodity(command.inconstcommodity());

	protos::expert::fact::CanSellCommodityResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CanSpy(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CanSpy command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::CanSpy();

	protos::expert::fact::CanSpyResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CanSpyWithEscrow(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CanSpyWithEscrow command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::CanSpyWithEscrow();

	protos::expert::fact::CanSpyWithEscrowResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CanTrain(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CanTrain command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::CanTrain(command.inconstunitid());

	protos::expert::fact::CanTrainResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CanTrainWithEscrow(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CanTrainWithEscrow command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::CanTrainWithEscrow(command.inconstunitid());

	protos::expert::fact::CanTrainWithEscrowResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CcPlayersBuildingCount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CcPlayersBuildingCount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::CcPlayersBuildingCount(command.inplayeranyplayer());

	protos::expert::fact::CcPlayersBuildingCountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CcPlayersBuildingTypeCount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CcPlayersBuildingTypeCount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::CcPlayersBuildingTypeCount(command.inplayeranyplayer(), command.inconstbuildingid());

	protos::expert::fact::CcPlayersBuildingTypeCountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CcPlayersUnitCount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CcPlayersUnitCount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::CcPlayersUnitCount(command.inplayeranyplayer());

	protos::expert::fact::CcPlayersUnitCountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CcPlayersUnitTypeCount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CcPlayersUnitTypeCount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::CcPlayersUnitTypeCount(command.inplayeranyplayer(), command.inconstunitid());

	protos::expert::fact::CcPlayersUnitTypeCountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CheatsEnabled(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CheatsEnabled command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::CheatsEnabled();

	protos::expert::fact::CheatsEnabledResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CivSelected(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CivSelected command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::CivSelected();

	protos::expert::fact::CivSelectedResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CivilianPopulation(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CivilianPopulation command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::CivilianPopulation();

	protos::expert::fact::CivilianPopulationResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CommodityBuyingPrice(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CommodityBuyingPrice command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::CommodityBuyingPrice(command.inconstcommodity());

	protos::expert::fact::CommodityBuyingPriceResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CommoditySellingPrice(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CommoditySellingPrice command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::CommoditySellingPrice(command.inconstcommodity());

	protos::expert::fact::CommoditySellingPriceResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CurrentAge(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CurrentAge command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::CurrentAge();

	protos::expert::fact::CurrentAgeResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CurrentAgeTime(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CurrentAgeTime command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::CurrentAgeTime();

	protos::expert::fact::CurrentAgeTimeResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::CurrentScore(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::CurrentScore command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::CurrentScore();

	protos::expert::fact::CurrentScoreResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::DeathMatchGame(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::DeathMatchGame command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::DeathMatchGame();

	protos::expert::fact::DeathMatchGameResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::DefendSoldierCount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::DefendSoldierCount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::DefendSoldierCount();

	protos::expert::fact::DefendSoldierCountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::DefendWarboatCount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::DefendWarboatCount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::DefendWarboatCount();

	protos::expert::fact::DefendWarboatCountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::Difficulty(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::Difficulty command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::Difficulty();

	protos::expert::fact::DifficultyResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::Doctrine(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::Doctrine command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::Doctrine(command.inconstvalue());

	protos::expert::fact::DoctrineResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::DropsiteMinDistance(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::DropsiteMinDistance command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::DropsiteMinDistance(command.inconstresource());

	protos::expert::fact::DropsiteMinDistanceResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::EnemyBuildingsInTown(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::EnemyBuildingsInTown command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::EnemyBuildingsInTown();

	protos::expert::fact::EnemyBuildingsInTownResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::EnemyCapturedRelics(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::EnemyCapturedRelics command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::EnemyCapturedRelics();

	protos::expert::fact::EnemyCapturedRelicsResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::EscrowAmount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::EscrowAmount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::EscrowAmount(command.inconstresource());

	protos::expert::fact::EscrowAmountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::EventDetected(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::EventDetected command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::EventDetected(command.inconsteventtype(), command.inconsteventid());

	protos::expert::fact::EventDetectedResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::False(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::False command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::False();

	protos::expert::fact::FalseResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::FoodAmount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::FoodAmount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::FoodAmount();

	protos::expert::fact::FoodAmountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::GameTime(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::GameTime command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::GameTime();

	protos::expert::fact::GameTimeResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::GameType(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::GameType command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::GameType();

	protos::expert::fact::GameTypeResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::GateCount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::GateCount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::GateCount(command.inconstperimeter());

	protos::expert::fact::GateCountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::Goal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::Goal command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::Goal(command.inconstgoalid());

	protos::expert::fact::GoalResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::GoalList(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::GoalList command;
	anyCommand.UnpackTo(&command);

	std::vector<int> factValues = ExpertFact::GoalList();

	protos::expert::fact::GoalListResult result;
	for (const auto &factValue : factValues) result.add_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::GoldAmount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::GoldAmount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::GoldAmount();

	protos::expert::fact::GoldAmountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::HoldKohRuin(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::HoldKohRuin command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::HoldKohRuin();

	protos::expert::fact::HoldKohRuinResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::HoldRelics(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::HoldRelics command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::HoldRelics();

	protos::expert::fact::HoldRelicsResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::HousingHeadroom(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::HousingHeadroom command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::HousingHeadroom();

	protos::expert::fact::HousingHeadroomResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::IdleFarmCount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::IdleFarmCount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::IdleFarmCount();

	protos::expert::fact::IdleFarmCountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::MapSize(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::MapSize command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::MapSize();

	protos::expert::fact::MapSizeResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::MapType(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::MapType command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::MapType();

	protos::expert::fact::MapTypeResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::MilitaryPopulation(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::MilitaryPopulation command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::MilitaryPopulation();

	protos::expert::fact::MilitaryPopulationResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::PlayerComputer(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::PlayerComputer command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::PlayerComputer(command.inplayeranyplayer());

	protos::expert::fact::PlayerComputerResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::PlayerHuman(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::PlayerHuman command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::PlayerHuman(command.inplayeranyplayer());

	protos::expert::fact::PlayerHumanResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::PlayerInGame(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::PlayerInGame command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::PlayerInGame(command.inplayeranyplayer());

	protos::expert::fact::PlayerInGameResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::PlayerNumber(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::PlayerNumber command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::PlayerNumber(command.inplayeranyplayer());

	protos::expert::fact::PlayerNumberResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::PlayerResigned(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::PlayerResigned command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::PlayerResigned(command.inplayeranyplayer());

	protos::expert::fact::PlayerResignedResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::PlayerValid(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::PlayerValid command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::PlayerValid(command.inplayeranyplayer());

	protos::expert::fact::PlayerValidResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::PlayersAchievements(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::PlayersAchievements command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::PlayersAchievements(command.param1(), command.param2(), command.param3(), command.param4());

	protos::expert::fact::PlayersAchievementsResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::PlayersBuildingCount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::PlayersBuildingCount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::PlayersBuildingCount(command.inplayeranyplayer());

	protos::expert::fact::PlayersBuildingCountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::PlayersBuildingTypeCount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::PlayersBuildingTypeCount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::PlayersBuildingTypeCount(command.inplayeranyplayer(), command.inconstbuildingid());

	protos::expert::fact::PlayersBuildingTypeCountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::PlayersCiv(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::PlayersCiv command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::PlayersCiv(command.inplayeranyplayer());

	protos::expert::fact::PlayersCivResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::PlayersCivilianPopulation(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::PlayersCivilianPopulation command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::PlayersCivilianPopulation(command.inplayeranyplayer());

	protos::expert::fact::PlayersCivilianPopulationResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::PlayersCurrentAge(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::PlayersCurrentAge command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::PlayersCurrentAge(command.inplayeranyplayer());

	protos::expert::fact::PlayersCurrentAgeResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::PlayersCurrentAgeTime(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::PlayersCurrentAgeTime command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::PlayersCurrentAgeTime(command.inplayeranyplayer());

	protos::expert::fact::PlayersCurrentAgeTimeResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::PlayersMilitaryPopulation(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::PlayersMilitaryPopulation command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::PlayersMilitaryPopulation(command.inplayeranyplayer());

	protos::expert::fact::PlayersMilitaryPopulationResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::PlayersPopulation(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::PlayersPopulation command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::PlayersPopulation(command.inplayeranyplayer());

	protos::expert::fact::PlayersPopulationResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::PlayersScore(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::PlayersScore command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::PlayersScore(command.inplayeranyplayer());

	protos::expert::fact::PlayersScoreResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::PlayersStance(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::PlayersStance command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::PlayersStance(command.inplayeranyplayer(), command.inconstesplayerstance());

	protos::expert::fact::PlayersStanceResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::PlayersTribute(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::PlayersTribute command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::PlayersTribute(command.inplayeranyplayer(), command.inconstresource());

	protos::expert::fact::PlayersTributeResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::PlayersTributeMemory(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::PlayersTributeMemory command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::PlayersTributeMemory(command.inplayeranyplayer(), command.inconstresource());

	protos::expert::fact::PlayersTributeMemoryResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::PlayersUnitCount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::PlayersUnitCount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::PlayersUnitCount(command.inplayeranyplayer());

	protos::expert::fact::PlayersUnitCountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::PlayersUnitTypeCount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::PlayersUnitTypeCount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::PlayersUnitTypeCount(command.inplayeranyplayer(), command.inconstunitid());

	protos::expert::fact::PlayersUnitTypeCountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::Population(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::Population command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::Population();

	protos::expert::fact::PopulationResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::PopulationCap(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::PopulationCap command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::PopulationCap();

	protos::expert::fact::PopulationCapResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::PopulationHeadroom(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::PopulationHeadroom command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::PopulationHeadroom();

	protos::expert::fact::PopulationHeadroomResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::RandomNumber(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::RandomNumber command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::RandomNumber();

	protos::expert::fact::RandomNumberResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::RegicideGame(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::RegicideGame command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::RegicideGame();

	protos::expert::fact::RegicideGameResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::ResearchAvailable(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::ResearchAvailable command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::ResearchAvailable(command.inconsttechid());

	protos::expert::fact::ResearchAvailableResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::ResearchCompleted(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::ResearchCompleted command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::ResearchCompleted(command.inconsttechid());

	protos::expert::fact::ResearchCompletedResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::ResourceFound(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::ResourceFound command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::ResourceFound(command.inconstresource());

	protos::expert::fact::ResourceFoundResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::SharedGoal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::SharedGoal command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::SharedGoal(command.inconstsharedgoalid(), command.inconstvalue());

	protos::expert::fact::SharedGoalResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::SheepAndForageTooFar(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::SheepAndForageTooFar command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::SheepAndForageTooFar();

	protos::expert::fact::SheepAndForageTooFarResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::SoldierCount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::SoldierCount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::SoldierCount();

	protos::expert::fact::SoldierCountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::StanceToward(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::StanceToward command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::StanceToward(command.inplayeranyplayer(), command.inconstesplayerstance());

	protos::expert::fact::StanceTowardResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::StartingAge(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::StartingAge command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::StartingAge();

	protos::expert::fact::StartingAgeResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::StartingResources(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::StartingResources command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::StartingResources();

	protos::expert::fact::StartingResourcesResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::StoneAmount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::StoneAmount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::StoneAmount();

	protos::expert::fact::StoneAmountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::StrategicNumber(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::StrategicNumber command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::StrategicNumber(command.inconstsnid());

	protos::expert::fact::StrategicNumberResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::StrategicNumberList(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::StrategicNumberList command;
	anyCommand.UnpackTo(&command);

	std::vector<int> factValues = ExpertFact::StrategicNumberList();

	protos::expert::fact::StrategicNumberListResult result;
	for (const auto& factValue : factValues) result.add_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::TauntDetected(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::TauntDetected command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::TauntDetected(command.inplayeranyplayer(), command.inconsttauntid());

	protos::expert::fact::TauntDetectedResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::TimerTriggered(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::TimerTriggered command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::TimerTriggered(command.inconsttimerid());

	protos::expert::fact::TimerTriggeredResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::TownUnderAttack(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::TownUnderAttack command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::TownUnderAttack();

	protos::expert::fact::TownUnderAttackResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::TraceFact(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::TraceFact command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::TraceFact(command.param());

	protos::expert::fact::TraceFactResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::True(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::True command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::True();

	protos::expert::fact::TrueResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UnitAvailable(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UnitAvailable command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::UnitAvailable(command.inconstunitid());

	protos::expert::fact::UnitAvailableResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UnitCount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UnitCount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UnitCount();

	protos::expert::fact::UnitCountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UnitCountTotal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UnitCountTotal command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UnitCountTotal();

	protos::expert::fact::UnitCountTotalResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UnitTypeCount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UnitTypeCount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UnitTypeCount(command.inconstunitid());

	protos::expert::fact::UnitTypeCountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UnitTypeCountTotal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UnitTypeCountTotal command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UnitTypeCountTotal(command.inconstunitid());

	protos::expert::fact::UnitTypeCountTotalResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpAlliedGoal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpAlliedGoal command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UpAlliedGoal(command.inplayercomputerallyplayer(), command.ingoalid());

	protos::expert::fact::UpAlliedGoalResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpAlliedResourceAmount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpAlliedResourceAmount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UpAlliedResourceAmount(command.inplayerallyplayer(), command.inconstresourceamount());

	protos::expert::fact::UpAlliedResourceAmountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpAlliedResourcePercent(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpAlliedResourcePercent command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UpAlliedResourcePercent(command.inplayerallyplayer(), command.inconstresourceamount());

	protos::expert::fact::UpAlliedResourcePercentResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpAlliedSn(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpAlliedSn command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UpAlliedSn(command.inplayercomputerallyplayer(), command.insnid());

	protos::expert::fact::UpAlliedSnResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpAttackerClass(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpAttackerClass command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UpAttackerClass();

	protos::expert::fact::UpAttackerClassResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpBuildingTypeInTown(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpBuildingTypeInTown command;
	anyCommand.UnpackTo(&command);
	
	int factValue = 0;
	switch (command.buildingId_case())
	{
		default:
		case protos::expert::fact::UpBuildingTypeInTown::kInConstBuildingId:
		{
			factValue = ExpertFact::UpBuildingTypeInTown(expert_conf::CONST_TYPE_OP_CONST, command.inconstbuildingid());
			break;
		}
		case protos::expert::fact::UpBuildingTypeInTown::kInGoalBuildingId:
		{
			factValue = ExpertFact::UpBuildingTypeInTown(expert_conf::CONST_TYPE_OP_GOAL, command.ingoalbuildingid());
			break;
		}
		case protos::expert::fact::UpBuildingTypeInTown::kInSnBuildingId:
		{
			factValue = ExpertFact::UpBuildingTypeInTown(expert_conf::CONST_TYPE_OP_SN, command.insnbuildingid());
			break;
		}
	}

	protos::expert::fact::UpBuildingTypeInTownResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpCanBuild(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpCanBuild command;
	anyCommand.UnpackTo(&command);

	bool factValue = false;
	switch (command.buildingId_case())
	{
		default:
		case protos::expert::fact::UpCanBuild::kInConstBuildingId:
		{
			factValue = ExpertFact::UpCanBuild(command.ingoalescrowstate(), expert_conf::CONST_TYPE_OP_CONST, command.inconstbuildingid());
			break;
		}
		case protos::expert::fact::UpCanBuild::kInGoalBuildingId:
		{
			factValue = ExpertFact::UpCanBuild(command.ingoalescrowstate(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalbuildingid());
			break;
		}
		case protos::expert::fact::UpCanBuild::kInSnBuildingId:
		{
			factValue = ExpertFact::UpCanBuild(command.ingoalescrowstate(), expert_conf::CONST_TYPE_OP_SN, command.insnbuildingid());
			break;
		}
	}

	protos::expert::fact::UpCanBuildResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpCanBuildLine(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpCanBuildLine command;
	anyCommand.UnpackTo(&command);

	bool factValue = false;
	switch (command.buildingId_case())
	{
		default:
		case protos::expert::fact::UpCanBuildLine::kInConstBuildingId:
		{
			factValue = ExpertFact::UpCanBuildLine(command.ingoalescrowstate(), command.ingoalpoint(), expert_conf::CONST_TYPE_OP_CONST, command.inconstbuildingid());
			break;
		}
		case protos::expert::fact::UpCanBuildLine::kInGoalBuildingId:
		{
			factValue = ExpertFact::UpCanBuildLine(command.ingoalescrowstate(), command.ingoalpoint(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalbuildingid());
			break;
		}
		case protos::expert::fact::UpCanBuildLine::kInSnBuildingId:
		{
			factValue = ExpertFact::UpCanBuildLine(command.ingoalescrowstate(), command.ingoalpoint(), expert_conf::CONST_TYPE_OP_SN, command.insnbuildingid());
			break;
		}
	}

	protos::expert::fact::UpCanBuildLineResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpCanResearch(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpCanResearch command;
	anyCommand.UnpackTo(&command);

	bool factValue = false;
	switch (command.techId_case())
	{
		default:
		case protos::expert::fact::UpCanResearch::kInConstTechId:
		{
			factValue = ExpertFact::UpCanResearch(command.ingoalescrowstate(), expert_conf::CONST_TYPE_OP_CONST, command.inconsttechid());
			break;
		}
		case protos::expert::fact::UpCanResearch::kInGoalTechId:
		{
			factValue = ExpertFact::UpCanResearch(command.ingoalescrowstate(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoaltechid());
			break;
		}
		case protos::expert::fact::UpCanResearch::kInSnTechId:
		{
			factValue = ExpertFact::UpCanResearch(command.ingoalescrowstate(), expert_conf::CONST_TYPE_OP_SN, command.insntechid());
			break;
		}
	}

	protos::expert::fact::UpCanResearchResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpCanSearch(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpCanSearch command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::UpCanSearch(command.inconstsearchsource());

	protos::expert::fact::UpCanSearchResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

int ResolveTypeOp(int typeOp, int constValue, int goalValue, int snValue)
{

}

void ExpertFactHandler::UpCanTrain(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpCanTrain command;
	anyCommand.UnpackTo(&command);
	
	bool factValue = false;
	switch (command.unitId_case())
	{
		default:
		case protos::expert::fact::UpCanTrain::kInConstUnitId:
		{
			factValue = ExpertFact::UpCanTrain(command.ingoalescrowstate(), expert_conf::CONST_TYPE_OP_CONST, command.inconstunitid());
			break;
		}
		case protos::expert::fact::UpCanTrain::kInGoalUnitId:
		{
			factValue = ExpertFact::UpCanTrain(command.ingoalescrowstate(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalunitid());
			break;
		}
		case protos::expert::fact::UpCanTrain::kInSnUnitId:
		{
			factValue = ExpertFact::UpCanTrain(command.ingoalescrowstate(), expert_conf::CONST_TYPE_OP_SN, command.insnunitid());
			break;
		}
	}

	protos::expert::fact::UpCanTrainResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpDefenderCount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpDefenderCount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UpDefenderCount();

	protos::expert::fact::UpDefenderCountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpEnemyBuildingsInTown(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpEnemyBuildingsInTown command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UpEnemyBuildingsInTown();

	protos::expert::fact::UpEnemyBuildingsInTownResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpEnemyUnitsInTown(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpEnemyUnitsInTown command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UpEnemyUnitsInTown();

	protos::expert::fact::UpEnemyUnitsInTownResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpEnemyVillagersInTown(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpEnemyVillagersInTown command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UpEnemyVillagersInTown();

	protos::expert::fact::UpEnemyVillagersInTownResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpGaiaTypeCount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpGaiaTypeCount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UpGaiaTypeCount(command.inconstresource());

	protos::expert::fact::UpGaiaTypeCountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpGaiaTypeCountTotal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpGaiaTypeCountTotal command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UpGaiaTypeCountTotal(command.inconstresource());

	protos::expert::fact::UpGaiaTypeCountTotalResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpGroupSize(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpGroupSize command;
	anyCommand.UnpackTo(&command);

	int factValue = 0;
	switch (command.groupId_case())
	{
		default:
		case protos::expert::fact::UpGroupSize::kInConstGroupId:
		{
			factValue = ExpertFact::UpGroupSize(expert_conf::CONST_TYPE_OP_CONST, command.inconstgroupid());
			break;
		}
		case protos::expert::fact::UpGroupSize::kInGoalGroupId:
		{
			factValue = ExpertFact::UpGroupSize(expert_conf::CONST_TYPE_OP_GOAL, command.ingoalgroupid());
			break;
		}
		case protos::expert::fact::UpGroupSize::kInSnGroupId:
		{
			factValue = ExpertFact::UpGroupSize(expert_conf::CONST_TYPE_OP_SN, command.insngroupid());
			break;
		}
	}

	protos::expert::fact::UpGroupSizeResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpIdleUnitCount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpIdleUnitCount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UpIdleUnitCount(command.inconstidletype());

	protos::expert::fact::UpIdleUnitCountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpObjectData(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpObjectData command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UpObjectData(command.inconstobjectdata());

	protos::expert::fact::UpObjectDataResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpObjectDataList(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpObjectDataList command;
	anyCommand.UnpackTo(&command);

	std::vector<int> factValues = ExpertFact::UpObjectDataList();

	protos::expert::fact::UpObjectDataListResult result;
	for (const auto& factValue : factValues) result.add_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpObjectTargetData(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpObjectTargetData command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UpObjectTargetData(command.inconstobjectdata());

	protos::expert::fact::UpObjectTargetDataResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpObjectTypeCount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpObjectTypeCount command;
	anyCommand.UnpackTo(&command);

	int factValue = 0;
	switch (command.objectId_case())
	{
		default:
		case protos::expert::fact::UpObjectTypeCount::kInConstObjectId:
		{
			factValue = ExpertFact::UpObjectTypeCount(expert_conf::CONST_TYPE_OP_CONST, command.inconstobjectid());
			break;
		}
		case protos::expert::fact::UpObjectTypeCount::kInGoalObjectId:
		{
			factValue = ExpertFact::UpObjectTypeCount(expert_conf::CONST_TYPE_OP_GOAL, command.ingoalobjectid());
			break;
		}
		case protos::expert::fact::UpObjectTypeCount::kInSnObjectId:
		{
			factValue = ExpertFact::UpObjectTypeCount(expert_conf::CONST_TYPE_OP_SN, command.insnobjectid());
			break;
		}
	}

	protos::expert::fact::UpObjectTypeCountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpObjectTypeCountTotal(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpObjectTypeCountTotal command;
	anyCommand.UnpackTo(&command);

	int factValue = 0;
	switch (command.objectId_case())
	{
		default:
		case protos::expert::fact::UpObjectTypeCountTotal::kInConstObjectId:
		{
			factValue = ExpertFact::UpObjectTypeCountTotal(expert_conf::CONST_TYPE_OP_CONST, command.inconstobjectid());
			break;
		}
		case protos::expert::fact::UpObjectTypeCountTotal::kInGoalObjectId:
		{
			factValue = ExpertFact::UpObjectTypeCountTotal(expert_conf::CONST_TYPE_OP_GOAL, command.ingoalobjectid());
			break;
		}
		case protos::expert::fact::UpObjectTypeCountTotal::kInSnObjectId:
		{
			factValue = ExpertFact::UpObjectTypeCountTotal(expert_conf::CONST_TYPE_OP_SN, command.insnobjectid());
			break;
		}
	}

	protos::expert::fact::UpObjectTypeCountTotalResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpPathDistance(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpPathDistance command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UpPathDistance(command.ingoalpoint(), command.inconststrict());

	protos::expert::fact::UpPathDistanceResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpPendingObjects(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpPendingObjects command;
	anyCommand.UnpackTo(&command);

	int factValue = 0;
	switch (command.objectId_case())
	{
		default:
		case protos::expert::fact::UpPendingObjects::kInConstObjectId:
		{
			factValue = ExpertFact::UpPendingObjects(expert_conf::CONST_TYPE_OP_CONST, command.inconstobjectid());
			break;
		}
		case protos::expert::fact::UpPendingObjects::kInGoalObjectId:
		{
			factValue = ExpertFact::UpPendingObjects(expert_conf::CONST_TYPE_OP_GOAL, command.ingoalobjectid());
			break;
		}
		case protos::expert::fact::UpPendingObjects::kInSnObjectId:
		{
			factValue = ExpertFact::UpPendingObjects(expert_conf::CONST_TYPE_OP_SN, command.insnobjectid());
			break;
		}
	}

	protos::expert::fact::UpPendingObjectsResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpPendingPlacement(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpPendingPlacement command;
	anyCommand.UnpackTo(&command);

	bool factValue = false;
	switch (command.buildingId_case())
	{
		default:
		case protos::expert::fact::UpPendingPlacement::kInConstBuildingId:
		{
			factValue = ExpertFact::UpPendingPlacement(expert_conf::CONST_TYPE_OP_CONST, command.inconstbuildingid());
			break;
		}
		case protos::expert::fact::UpPendingPlacement::kInGoalBuildingId:
		{
			factValue = ExpertFact::UpPendingPlacement(expert_conf::CONST_TYPE_OP_GOAL, command.ingoalbuildingid());
			break;
		}
		case protos::expert::fact::UpPendingPlacement::kInSnBuildingId:
		{
			factValue = ExpertFact::UpPendingPlacement(expert_conf::CONST_TYPE_OP_SN, command.insnbuildingid());
			break;
		}
	}

	protos::expert::fact::UpPendingPlacementResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpPlayerDistance(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpPlayerDistance command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UpPlayerDistance(command.inplayeranyplayer());

	protos::expert::fact::UpPlayerDistanceResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpPlayersInGame(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpPlayersInGame command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UpPlayersInGame(command.inconstplayerstance());

	protos::expert::fact::UpPlayersInGameResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpPointContains(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpPointContains command;
	anyCommand.UnpackTo(&command);

	bool factValue = false;
	switch (command.objectId_case())
	{
		default:
		case protos::expert::fact::UpPointContains::kInConstObjectId:
		{
			factValue = ExpertFact::UpPointContains(command.ingoalpoint(), expert_conf::CONST_TYPE_OP_CONST, command.inconstobjectid());
			break;
		}
		case protos::expert::fact::UpPointContains::kInGoalObjectId:
		{
			factValue = ExpertFact::UpPointContains(command.ingoalpoint(), expert_conf::CONST_TYPE_OP_GOAL, command.ingoalobjectid());
			break;
		}
		case protos::expert::fact::UpPointContains::kInSnObjectId:
		{
			factValue = ExpertFact::UpPointContains(command.ingoalpoint(), expert_conf::CONST_TYPE_OP_SN, command.insnobjectid());
			break;
		}
	}

	protos::expert::fact::UpPointContainsResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpPointDistance(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpPointDistance command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UpPointDistance(command.ingoalpoint1(), command.ingoalpoint2());

	protos::expert::fact::UpPointDistanceResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpPointElevation(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpPointElevation command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UpPointElevation(command.ingoalpoint());

	protos::expert::fact::UpPointElevationResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpPointExplored(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpPointExplored command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UpPointExplored(command.ingoalpoint());

	protos::expert::fact::UpPointExploredResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpPointTerrain(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpPointTerrain command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UpPointTerrain(command.ingoalpoint());

	protos::expert::fact::UpPointTerrainResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpPointZone(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpPointZone command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UpPointZone(command.ingoalpoint());

	protos::expert::fact::UpPointZoneResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpProjectileDetected(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpProjectileDetected command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UpProjectileDetected(command.inconstprojectiletype());

	protos::expert::fact::UpProjectileDetectedResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpProjectileTarget(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpProjectileTarget command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UpProjectileTarget(command.inconstprojectiletype());

	protos::expert::fact::UpProjectileTargetResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpRemainingBoarAmount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpRemainingBoarAmount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UpRemainingBoarAmount();

	protos::expert::fact::UpRemainingBoarAmountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpResearchStatus(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpResearchStatus command;
	anyCommand.UnpackTo(&command);

	int factValue = 0;
	switch (command.techId_case())
	{
		default:
		case protos::expert::fact::UpResearchStatus::kInConstTechId:
		{
			factValue = ExpertFact::UpResearchStatus(expert_conf::CONST_TYPE_OP_CONST, command.inconsttechid());
			break;
		}
		case protos::expert::fact::UpResearchStatus::kInGoalTechId:
		{
			factValue = ExpertFact::UpResearchStatus(expert_conf::CONST_TYPE_OP_GOAL, command.ingoaltechid());
			break;
		}
		case protos::expert::fact::UpResearchStatus::kInSnTechId:
		{
			factValue = ExpertFact::UpResearchStatus(expert_conf::CONST_TYPE_OP_SN, command.insntechid());
			break;
		}
	}

	protos::expert::fact::UpResearchStatusResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpResourceAmount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpResourceAmount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UpResourceAmount(command.inconstresourceamount());

	protos::expert::fact::UpResourceAmountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpResourcePercent(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpResourcePercent command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UpResourcePercent(command.inconstresourceamount());

	protos::expert::fact::UpResourcePercentResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpSearchObjectIdList(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpSearchObjectIdList command;
	anyCommand.UnpackTo(&command);

	std::vector<int> factValues = ExpertFact::UpSearchObjectIdList(command.inconstsearchsource());

	protos::expert::fact::UpSearchObjectIdListResult result;
	for (const auto& factValue : factValues) result.add_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpTimerStatus(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpTimerStatus command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::UpTimerStatus(command.inconsttimerid());

	protos::expert::fact::UpTimerStatusResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpTrainSiteReady(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpTrainSiteReady command;
	anyCommand.UnpackTo(&command);

	bool factValue = false;
	switch (command.unitId_case())
	{
		default:
		case protos::expert::fact::UpTrainSiteReady::kInConstUnitId:
		{
			factValue = ExpertFact::UpTrainSiteReady(expert_conf::CONST_TYPE_OP_CONST, command.inconstunitid());
			break;
		}
		case protos::expert::fact::UpTrainSiteReady::kInGoalUnitId:
		{
			factValue = ExpertFact::UpTrainSiteReady(expert_conf::CONST_TYPE_OP_GOAL, command.ingoalunitid());
			break;
		}
		case protos::expert::fact::UpTrainSiteReady::kInSnUnitId:
		{
			factValue = ExpertFact::UpTrainSiteReady(expert_conf::CONST_TYPE_OP_SN, command.insnunitid());
			break;
		}
	}

	protos::expert::fact::UpTrainSiteReadyResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpUnitTypeInTown(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpUnitTypeInTown command;
	anyCommand.UnpackTo(&command);

	int factValue = false;
	switch (command.unitId_case())
	{
		default:
		case protos::expert::fact::UpUnitTypeInTown::kInConstUnitId:
		{
			factValue = ExpertFact::UpUnitTypeInTown(expert_conf::CONST_TYPE_OP_CONST, command.inconstunitid());
			break;
		}
		case protos::expert::fact::UpUnitTypeInTown::kInGoalUnitId:
		{
			factValue = ExpertFact::UpUnitTypeInTown(expert_conf::CONST_TYPE_OP_GOAL, command.ingoalunitid());
			break;
		}
		case protos::expert::fact::UpUnitTypeInTown::kInSnUnitId:
		{
			factValue = ExpertFact::UpUnitTypeInTown(expert_conf::CONST_TYPE_OP_SN, command.insnunitid());
			break;
		}
	}

	protos::expert::fact::UpUnitTypeInTownResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::UpVillagerTypeInTown(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::UpVillagerTypeInTown command;
	anyCommand.UnpackTo(&command);

	int factValue = false;
	switch (command.unitId_case())
	{
		default:
		case protos::expert::fact::UpVillagerTypeInTown::kInConstUnitId:
		{
			factValue = ExpertFact::UpVillagerTypeInTown(expert_conf::CONST_TYPE_OP_CONST, command.inconstunitid());
			break;
		}
		case protos::expert::fact::UpVillagerTypeInTown::kInGoalUnitId:
		{
			factValue = ExpertFact::UpVillagerTypeInTown(expert_conf::CONST_TYPE_OP_GOAL, command.ingoalunitid());
			break;
		}
		case protos::expert::fact::UpVillagerTypeInTown::kInSnUnitId:
		{
			factValue = ExpertFact::UpVillagerTypeInTown(expert_conf::CONST_TYPE_OP_SN, command.insnunitid());
			break;
		}
	}

	protos::expert::fact::UpVillagerTypeInTownResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::VictoryCondition(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::VictoryCondition command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::VictoryCondition(command.inconstvictory());

	protos::expert::fact::VictoryConditionResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::WallCompletedPercentage(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::WallCompletedPercentage command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::WallCompletedPercentage(command.inconstperimeter());

	protos::expert::fact::WallCompletedPercentageResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::WallInvisiblePercentage(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::WallInvisiblePercentage command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::WallInvisiblePercentage(command.inconstperimeter());

	protos::expert::fact::WallInvisiblePercentageResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::WarboatCount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::WarboatCount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::WarboatCount();

	protos::expert::fact::WarboatCountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::WoodAmount(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::WoodAmount command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::WoodAmount();

	protos::expert::fact::WoodAmountResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

#if defined GAME_DE
void ExpertFactHandler::EndingAge(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::EndingAge command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::EndingAge();

	protos::expert::fact::EndingAgeResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::FeCanBuildAtPoint(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::FeCanBuildAtPoint command;
	anyCommand.UnpackTo(&command);

	bool factValue = ExpertFact::FeCanBuildAtPoint(command.param1(), command.param2(), command.param3(), command.param4());

	protos::expert::fact::FeCanBuildAtPointResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}

void ExpertFactHandler::FeSubGameType(const google::protobuf::Any& anyCommand, google::protobuf::Any* anyResult)
{
	protos::expert::fact::FeSubGameType command;
	anyCommand.UnpackTo(&command);

	int factValue = ExpertFact::FeSubGameType();

	protos::expert::fact::FeSubGameTypeResult result;
	result.set_result(factValue);
	anyResult->PackFrom(result);
}
#elif defined GAME_AOC

#endif
