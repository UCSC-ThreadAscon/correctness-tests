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

  key = hexDump[1]
  nonce = hexDump[4]
  assocData = hexDump[7]
  tag = hexDump[len(hexDump) - 2]
  ciphertextDump = hexDump[10:len(hexDump) - 4]

  print(key)
  print(nonce)
  print(assocData)
  print(tag)
  print(ciphertextDump)