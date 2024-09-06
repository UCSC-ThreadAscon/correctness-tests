import argparse
import linecache

parser = argparse.ArgumentParser()

helperText = "The file path containing the OpenThread ASCON hex dump."
parser.add_argument("--path", help=helperText, required=True)

helperText = "The starting line number of the OpenThread ASCON hex dump."
parser.add_argument("--start", help=helperText, required=True)

helperText = "The ending line number of the OpenThread ASCON hex dump."
parser.add_argument("--end", help=helperText, required=True)

if __name__ == "__main__":
  args = parser.parse_args()
  path = args.path
  start = int(args.start)
  end = int(args.end)

  hexDump = []
  for lineNum in range(start, end + 1):
    line = linecache.getline(path, lineNum)
    hexDump.append(line)

  for line in hexDump:
    print(line)