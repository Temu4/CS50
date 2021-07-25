from sys import argv

def main():
  alphabetLength = 26
  indexLastUppercaseLetter = 90
  indexLastLowercaseLetter = 122

  if len(argv) != 2:
    print("Usage: python caesar.py key")
    exit(1)

  elif argv[1].isdigit():
    key = int(argv[1])

    if key > 0:
      # cut off how much times key overrides an alphabet
      cleanKey = key % alphabetLength

      message = input("plaintext: ")
      print("ciphertext: ", end="")

      for i in range(len(message)):
        symbol = message[i]

        if symbol.isalpha():
          symbolASCII = ord(symbol)
          crypticSymbolASCII = symbolASCII + cleanKey

          # if character is in uppercase
          if symbol.isupper():
            if crypticSymbolASCII > indexLastUppercaseLetter:
              crypticSymbolASCII -= alphabetLength

          # if character is in lovercase
          if symbol.islower():
            if crypticSymbolASCII > indexLastLowercaseLetter:
              crypticSymbolASCII -= alphabetLength

          crypticSymbol = chr(crypticSymbolASCII)
          print(crypticSymbol, end="")
        else:
          print(symbol, end="")

      print()

    else:
      print("Usage: python caesar.py key")
      exit(2)
  else:
    print("Usage: python caesar.py key")
    exit(3)

if __name__=="__main__":
  main()
