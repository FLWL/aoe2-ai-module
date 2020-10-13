import grpc

from google.protobuf.any_pb2 import Any
import protos.ai_module_api_pb2 as module
import protos.ai_module_api_pb2_grpc
import protos.expert.expert_api_pb2_grpc
import protos.expert.expert_api_pb2 as expert
import protos.expert.fact.fact_pb2 as fact
import protos.expert.action.action_pb2 as action


def pack_commands(commands):
    command_list = expert.CommandList()
    any_command = Any()
    for command in commands:
        any_command.Pack(command)
        command_list.commands.append(any_command)

    return command_list


def unpack_result(result, result_type):
    unpacked_result = result_type()
    result.Unpack(unpacked_result)
    return unpacked_result


def run():
    with grpc.insecure_channel('localhost:37412') as channel:
        print("Channel opened")
        module_api = protos.ai_module_api_pb2_grpc.AIModuleAPIStub(channel)
        expert_api = protos.expert.expert_api_pb2_grpc.ExpertAPIStub(channel)

        result_list = expert_api.ExecuteCommandList(pack_commands([
            #action.Train(unitType=83), # train villager
            #action.Build(buildingType=70), # build house
            #action.UpGetFact(factId=25, factParam=83, goalId=99), # up-get-fact unit-type-count 83 99
            #fact.Goal(goalId=99), # goal 99
            #action.UpGetFact(factId=0, factParam=0, goalId=99), # up-get-fact game-time 0 99
            #fact.Goals(), # goals[512]
            #action.AttackNow()
            #action.Resign()
            #action.SetStrategicNumber(strategicNumber=0, value=0),
            #action.SetGoal(goalId=100, goalValue=50),
            #action.SetGoal(goalId=101, goalValue=50),
            #action.SetGoal(goalId=200, goalValue=50),
            #action.SetGoal(goalId=201, goalValue=50),
            #action.UpBuildLine(goalPoint1=100, goalPoint2=200, typeOp=0, buildingId=68),
            #action.SetStrategicNumber(strategicNumber=18, value=0),
            #action.UpResearch(escrowState=0, typeOp=0, techId=22),
            #action.UpBuild(buildingId=12)
            #action.UpGarrison(objectId=109, typeOp=0, unitId=83)
            #action.UpDeleteIdleUnits(idleType=0)
            action.SetGoal(goalId=100, goalValue = 100),
            action.SetGoal(goalId=101, goalValue = 100),
            action.UpSendFlare(goalPoint=100),
            #action.UpSendScout(groupType=101, positionType=1),
            #action.UpBuild(buildingId=50)
        ]))

        print(result_list)

        #villager_count = unpack_result(result_list.results[3], fact.GoalResult).goalValue
        #print("Villager count = " + str(villager_count))

        # shut down the module
        #module_api.Unload(module.UnloadRequest())

if __name__ == '__main__':
    run()

