# import datetime
def findLongestTrip(line1, line2, memo):
    if line1 == "" or line2 == "":
        return [0, [""]]
    elif (line1, line2) in memo:
        return memo[(line1, line2)]
    elif line1[0] == line2[0]:
        lose12 = findLongestTrip(line1[1:], line2[1:], memo)
        lst = [0, [""]]
        lst[1] = [line1[0] + subStr for subStr in lose12[1] if len(subStr) == lose12[0]]
        lst[0] = 1 + lose12[0]
        memo[(line1, line2)] = lst
        return lst
    else:
        lose1 = findLongestTrip(line1[1:], line2, memo)
        lose2 = findLongestTrip(line1, line2[1:], memo)
        lose12 = lose1[1] + lose2[1]
        lst = [0, [""]]
        lst[0] = max(lose1[0], lose2[0])
        lst[1] = [subStr for subStr in lose12 if len(subStr) == lst[0]]
        memo[(line1, line2)] = lst
        return lst

numCases = int(input())
if (numCases >= 1 and numCases <= 10):
    for i in range(0, numCases):
        charCheck = []
        line1 = str(input())
        line2 = str(input())
        index = 0
        while ((line1[index] not in charCheck) and (index < len(line1) and line1[index] not in line2)):
            charCheck.append(line1[index])
            index += 1
        if (index < len(line1)):
            # startTime = datetime.datetime.now()
            if ((len(line1) >= 1 and len(line1) <= 80) and (len(line2) >= 1 and len(line2) <= 80)):
                lst = findLongestTrip(line1, line2, {})
                print(lst)  
                wordDict = []
                for i in sorted(lst[1]):
                    if i not in wordDict:
                        wordDict.append(i)
                        print(i)
                # endTime = datetime.datetime.now()
                # timeDiff = endTime - startTime
                # print("Time: " + str(1000 * timeDiff.total_seconds()))
