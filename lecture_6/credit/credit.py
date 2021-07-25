import cs50
import math

def main ():
    while True:
        cardNumber = cs50.get_int("Enter Card Number (without spaces or dashes): ")

        if cardNumber and cardNumber > 0:
            break

    # get number length using math
    digits = int(math.log10(cardNumber))+1

    if (digits == 13 or digits == 15 or digits == 16) and checkSum(cardNumber):
        printCardLogo(cardNumber)
    else:
        print("INVALID")

# based on source code from geeksforgeeks.org/luhn-algorithm/
def checkSum(cardNumber):
    # get number length using converting to string
    cardNumberStr = str(cardNumber)
    cardNumberDigits = len(cardNumberStr)
    cardNumberSum = 0
    isSecond = False

    for i in range(cardNumberDigits - 1, -1, -1):
        d = ord(cardNumberStr[i]) - ord('0')

        if (isSecond == True):
            d = d * 2

        # We add two digits to handle
        # cases that make two digits after
        # doubling
        cardNumberSum += d // 10
        cardNumberSum += d % 10

        isSecond = not isSecond

    if (cardNumberSum % 10 == 0):
        return True
    else:
        return False

def printCardLogo(number):
    if (number >= 34e13 and number < 35e13) or (number >= 37e13 and number < 38e13):
        print("AMEX")
    elif  number >= 51e14 and number < 56e14:
        print("MASTERCARD")
    elif  (number >= 4e12 and number < 5e12) or (number >= 4e15 and number < 5e15):
        print("VISA")
    else:
        print("INVALID")

if __name__=="__main__":
    main()
