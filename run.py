import sys

from frontend import create_app

app = create_app()

if __name__ == "__main__":
    # engine_options = ["C", "C++"]
    #
    # which_engine = None
    # if len(sys.argv) > 1:
    #     which_engine = sys.argv[1]
    #
    # if (which_engine is None) or (which_engine not in engine_options):
    #     print("No proper engine specified, going with defualt (C) engine...\n")
    #
    # else:
    #     if which_engine == "C":
    #         # run the c engine
    #         app.run(debug=True)
    #
    #     else:
    #         # run the c++ engine
    #         pass

    app.run(debug=True)
