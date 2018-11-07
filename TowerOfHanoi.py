#Tower of Hanoi to move all the disk from A to C using B
n=2
def TowerofHanoi(n, frm, to, extra):
    if n==1:
        print("Moving disk 1 from", frm, "to", to ,'\n')
        return 
    TowerofHanoi(n-1, frm, extra, to)
    print("Moving disk", n , " from", frm, "to", to ,'\n')
    TowerofHanoi(n-1, extra, to, frm)
    return
TowerofHanoi(n, 'A', 'C', 'B')
    
