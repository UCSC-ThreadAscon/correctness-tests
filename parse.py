import argparse
import linecache
import re

def parse(hexDumpString):
  hexRegex = re.compile("[A-F,0-9][A-F,0-9]")
  hexDump = []

  for substring in hexDumpString.split(" "):
    if hexRegex.match(substring) != None:
      hexDump.append(substring)

  return hexDump

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

  key = parse(hexDump[1])
  nonce = parse(hexDump[4])
  assocData = parse(hexDump[7])
  tag = parse(hexDump[len(hexDump) - 2])
  # ciphertextDump = hexDump[10:len(hexDump) - 4]

  print(key)
  print(nonce)
  print(assocData)
  print(tag)
  # print(ciphertextDump)