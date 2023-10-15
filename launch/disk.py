import psutil

def list_disk_info():
    partitions = psutil.disk_partitions(all=True)
    
    for partition in partitions:
        drive_name = partition.device
        drive_info = psutil.disk_usage(partition.mountpoint)
        
        print(f"Drive Name: {drive_name}")
        print(f"Total Size: {drive_info.total / (1024**3):.2f} GB")
        print(f"Free Space: {drive_info.free / (1024**3):.2f} GB")
        
        # Attempt to differentiate between internal and external drives based on drive name
        if "C:" in drive_name or "D:" in drive_name:
            print("Drive Type: Internal")
        else:
            print("Drive Type: External")
        
        print("")

if __name__ == "__main__":
    list_disk_info()
