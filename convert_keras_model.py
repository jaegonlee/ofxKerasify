import argparse
parser = argparse.ArgumentParser()
parser.add_argument("input", help="input filepath of keras model file")
parser.add_argument("output", help="output filepath of kerasified model file")
args = parser.parse_args()


print args

from keras.models import load_model
print "convert keras model:", args.input
keras_model = load_model(args.input)


import sys
sys.path.insert(0, './lib/kerasify')
from kerasify import export_model


print "to:", args.output
export_model(keras_model, args.output)

print "done!"
