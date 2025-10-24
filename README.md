To get started, first start your python virtual environment. To activate, run the following script in the home directory of the project (and assuming you are runnning on Windows):
```bash    
Scripts/activate
```

Then use pip to install all the necessary python libraries:
```bash
pip install -r requirements.txt
```

Next, we'll need to install our npm packages, these are already listed in packages.json but all you need to do is run this command:
```bash
npm install
```

To start server, in the main directory simpy execute the run script with python:
```bash 
python run.py
```

Then navigate to localhost:5000/ to get to the main page!