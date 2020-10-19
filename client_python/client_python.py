import grpc

from google.protobuf.any_pb2 import Any
import protos.ai_module_api_pb2 as module
import protos.ai_module_api_pb2_grpc
import protos.expert.expert_api_pb2_grpc
import protos.expert.expert_api_pb2 as expert
import protos.expert.fact.fact_pb2 as fact
import protos.expert.action.action_pb2 as action


# Helper function that constructs the CommandList protobuf message.
# Since that message requires an array of protobuf "any" objects,
# this function packs a list of specific actions and facts passed as the second
# parameter into a list of "any" objects and appends them to the CommandList
# message. "playerNumber" parameter decides on what player these commands
# get executed on.
def pack_commands(playerNumber, commands):
    command_list = expert.CommandList()
    command_list.playerNumber = playerNumber
    any_command = Any()
    for command in commands:
        any_command.Pack(command)
        command_list.commands.append(any_command)

    return command_list


# a helper function that takes in a protobuf "any" object as the first
# parameter and a protobuf message type as the second parameter and
# then unpacks the "any" object into that specific type, returning it
def unpack_result(result, result_type):
    unpacked_result = result_type()
    result.Unpack(unpacked_result)
    return unpacked_result


def run():
    # first a grpc connection has to be made to the AI library
    with grpc.insecure_channel('localhost:37412') as channel:
        print("Channel opened")

        # module api provides general functions such as unloading the module from the game
        # this is derived from protos/ai_module_api.proto file
        module_api = protos.ai_module_api_pb2_grpc.AIModuleAPIStub(channel)
        # expert api provides functions specific to the Expert AI system integrated into the game, such as facts and actions
        # this is derived from protos/expert/expert_api.proto
        # fact and action definitions can be found in protos/expert/fact/fact.proto and protos/expert/action/action.proto
        expert_api = protos.expert.expert_api_pb2_grpc.ExpertAPIStub(channel)

        # the following code creates a list of commands (actions and facts) that get
        # executed on the specified target player number specified in first parameter of
        # the helper function pack_commands
        # results will be put into the result_list list
        result_list = expert_api.ExecuteCommandList(pack_commands(1, [
            action.UpGetFact(factId=25, factParam=83, goalId=99), # up-get-fact unit-type-count 83 99
            fact.Goal(goalId=99), # goal 99
        ]))

        print(result_list)

        # the result of our "up-get-fact" query can be extracted via the "goal" fact and
        # then reading the array like this
        villager_count = unpack_result(result_list.results[1], fact.GoalResult).result
        print("Villager count = " + str(villager_count))

        # this code would unload the AI module from the game
        #module_api.Unload(module.UnloadRequest())

if __name__ == '__main__':
    run()

