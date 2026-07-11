To get started, you'll want to first create and start a python virtual environment.

Once activated, use pip and the included requirements.txt to install all the necessary python libraries in your environment:
```bash
pip install -r requirements.txt
```

Next, we'll need to install our npm packages, these are already listed in packages.json but all you need to do is run this command:
```bash
npm install
```

We'll also need to build the engine executable in order for Flask to utilize it. Navigate to the engine_cpp directory and run the following:
```bash
cmake -S . -B build
cmake --build build
```

To start server, in the root directory simply execute the run script with python:
```bash 
python run.py
```

Then navigate to localhost:5000/ to get to the main page!
