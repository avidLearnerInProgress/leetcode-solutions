class SnapshotArray:

    def __init__(self, length: int):
        self.snapshot = {i: {0: 0} for i in range(length)}
        self.snap_id = 0

    def set(self, index: int, val: int) -> None:
        self.snapshot[index][self.snap_id] = val

    def snap(self) -> int:
        self.snap_id += 1
        return self.snap_id - 1

    def get(self, index: int, snap_id: int) -> int:
        while snap_id > 0 and snap_id not in self.snapshot[index]:
            snap_id -= 1
        return self.snapshot[index][snap_id]
