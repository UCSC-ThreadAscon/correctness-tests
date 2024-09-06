import argparse

parser = argparse.ArgumentParser()

helperText = "The file containing the OpenThread ASCON hex dump."
parser.add_argument("--file", help=helperText, required=True)

helperText = "The starting line number of the OpenThread ASCON hex dump."
parser.add_argument("--start", help=helperText, required=True)

helperText = "The ending line number of the OpenThread ASCON hex dump."
parser.add_argument("--end", help=helperText, required=True)

args = parser.parse_args()

if __name__ == "__main__":
  print(args)