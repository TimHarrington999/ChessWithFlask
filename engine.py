import subprocess
import threading
import queue

class UCIEngine:
    
    def __init__(self, path):
        self.proc = subprocess.Popen(
            [path],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            bufsize=1
        )

        self.out_queue = queue.Queue()
        threading.Thread(target=self._reader, daemon=True).start()

        self._handshake()

        # test print
        print("engine.py has been initialized!\n")

    def _handshake(self):
        self.send("uci")
        while self.recv() != "uciok":
            pass

        self.send("isready")
        while self.recv() != "readyok":
            pass
    
    def _reader(self):
        for line in self.proc.stdout:
            self.out_queue.put(line.strip())

    def send(self, cmd):
        self.proc.stdin.write(cmd + "\n")
        self.proc.stdin.flush()

    def recv(self, timeout=None):
        return self.out_queue.get(timeout=timeout)

    def best_move(self, fen, depth=6):
        self.send("position fen " + fen)
        self.send(f"go depth {depth}")

        while True:
            line = self.recv()
            if line.startswith("bestmove"):
                print("Received best move from the engine!\n")
                return line.split()[1]
