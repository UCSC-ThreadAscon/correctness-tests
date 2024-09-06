import argparse

parser = argparse.ArgumentParser()

parser.add_argument(
  "--start",
  help="The starting line number of the ASCON bytes hex dump",
  action="store"
)

args = parser.parse_args()

if __name__ == "__main__":
  print(args)
  pass