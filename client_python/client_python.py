import grpc

import protos.ai_module_api_pb2 as module
import protos.ai_module_api_pb2_grpc
import protos.expert.expert_api_pb2_grpc
import protos.expert.expert_api_pb2 as expert
import protos.expert.fact.fact_pb2 as fact
import protos.expert.action.action_pb2 as action

def run():
    with grpc.insecure_channel('localhost:37412') as channel:
        print("Channel opened")
        module_api = protos.ai_module_api_pb2_grpc.AIModuleAPIStub(channel)
        expert_api = protos.expert.expert_api_pb2_grpc.ExpertAPIStub(channel)

        commands = [
            expert.Request(train=action.Train(unitType=83)), # train villager
            expert.Request(build=action.Build(buildingType=70)), # build house
            expert.Request(upGetFact=action.UpGetFact(factId=25, factParam=83, goalId=99)), # up-get-fact unit-type-count 83 99
            expert.Request(goal=fact.Goal(goalId=99)), # goal 99
            expert.Request(upGetFact=action.UpGetFact(factId=0, factParam=0, goalId=99)), # up-get-fact game-time 0 99
            expert.Request(goals=fact.Goals()), # goals[512]
        ]

        print("--- Commands:")
        print(commands)

        results = expert_api.RunRequestList(expert.RequestList(request=commands))

        print ("--- Results:")
        print("train villager = " + str(results.reply[0].trainReply.success))
        print("build house = " + str(results.reply[1].buildReply.success))
        print("goal 99 = " + str(results.reply[3].goalReply.goalValue))
        print("goal 99 = " + str(results.reply[5].goalsReply.goalValue[99 - 1]))

        # shut down the module
        #module_api.Unload(module.UnloadRequest())

if __name__ == '__main__':
    run()

