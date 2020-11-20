import psutil
from ctypes import windll

# works on 32-bit Python only
# change DLL path here
dll_path = b'C:\\Development\\AoE2\\aoe2-ai-module\\aimodule\\Release\\aimodule.dll'
aoc_binary_name = "age2_x1.exe"

# get aoc pid
aoc_pid = None
for proc in psutil.process_iter():
    try:
        if proc.name() == aoc_binary_name:
            aoc_pid = proc.pid
            break
    except (psutil.AccessDenied, psutil.NoSuchProcess, psutil.ZombieProcess):
        pass

if aoc_pid:
    print("found aoc process with pid = " + str(aoc_pid))

    # write dll path into aoc memory
    aoc_handle = windll.kernel32.OpenProcess(0x1FFFFF, False, aoc_pid) # PROCESS_ALL_ACCESS
    remote_memory = windll.kernel32.VirtualAllocEx(aoc_handle, 0, 260, 0x3000, 0x40)
    windll.kernel32.WriteProcessMemory(aoc_handle, remote_memory, dll_path, len(dll_path), 0)

    # load the dll from the remote process
    load_library = windll.kernel32.GetProcAddress(windll.kernel32._handle, b'LoadLibraryA')
    remote_thread = windll.kernel32.CreateRemoteThread(aoc_handle, 0, 0, load_library, remote_memory, 0, 0)
    windll.kernel32.WaitForSingleObject(remote_thread, 0xFFFFFFFF)
    windll.kernel32.CloseHandle(remote_thread)

    # clean up
    windll.kernel32.VirtualFreeEx(aoc_handle, remote_memory, 0, 0x00008000)
    windll.kernel32.CloseHandle(aoc_handle)
else:
    print("aoc process not found")
