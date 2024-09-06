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

  keyDump = hexDump[1]
  nonceDump = hexDump[4]
  assocDataDump = hexDump[7]
  tagDump = hexDump[len(hexDump) - 2]
  ciphertext = hexDump[10:len(hexDump) - 4]

  print(keyDump)
  print(nonceDump)
  print(assocDataDump)
  print(tagDump)
  print(ciphertext)