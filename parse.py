import argparse

parser = argparse.ArgumentParser()

helperText = "The file path containing the OpenThread ASCON hex dump."
parser.add_argument("--path", help=helperText, required=True)

helperText = "The starting line number of the OpenThread ASCON hex dump."
parser.add_argument("--start", help=helperText, required=True)

helperText = "The ending line number of the OpenThread ASCON hex dump."
parser.add_argument("--end", help=helperText, required=True)

args = parser.parse_args()
path = args.path
start = args.start
end = args.end

with open(path, "r") as file:
  for line in file:
    print(line)