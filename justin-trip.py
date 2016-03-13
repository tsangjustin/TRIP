def findLongestTrip(line1, line2, memo):
    if line1 == '' or line2 == '':
        return [0, ['']]
    elif (line1, line2) in memo:
        return memo[(line1, line2)]
    elif line1[0] == line2[0]:
        lose12 = findLongestTrip(line1[1:], line2[1:], memo)
        lose12[0] += 1
        lose12[1] = [line1[0] + str(subStr) for subStr in lose12[1]]
        print(lose12)
        memo[(line1, line2)] = lose12
        return def findLongestTrip(line1, line2, memo):
    if line1 == '' or line2 == '':
        return [0, Set([''])]
    elif (line1, line2) in memo:
        return memo[(line1, line2)]
    elif line1[0] == line2[0]:
        lose12 = findLongestTrip(line1[1:], line2[1:], memo)
        lose12[0] += 1
        lose12[1] = [line1[0] + str(subStr) for subStr in lose12[1]]
        print(lose12)
        memo[(line1, line2)] = lose12
        return lose12
    else:
        lose1 = findLongestTrip(line1[1:], line2, memo)
        lose2 = findLongestTrip(line1, line2[1:], memo)
        print(lose1)
        print(lose2)
        if (lose2[0] > lose1[0]):
            lose1 = lose2
        elif (lose2[0] == lose1[0]):
            lose1[1].update(lose2[1])
        # lose2 = findLongestTrip(line1[1:], line2[1:], memo)
        # if (lose2[0] > lose1[0]):
        #     lose1 = lose2
        # elif (lose12[0] == lose1[0]):
        #     lose1[1] += lose12[1]
        # lst = [0, [""]]
        # lst[0] = max(lose1[0], lose2[0], lose12[0])
        # lst[1] = [subStr for subStr in loseAll if len(subStr) == lst[0]]
        memo[(line1, line2)] = lose1
        return lose1

numCases = int(input())
if (numCases >= 1 and numCases <= 10):
    for i in range(0, numCases):
        line1 = str(input())
        line2 = str(input())
        if ((len(line1) >= 1 and len(line1) <= 80) and (len(line2) >= 1 and len(line2) <= 80)):
            lst = sorted(findLongestTrip(line1, line2, {})[1])
            print(lst)
            if len(lst) > 0:
                print(lst[0])
                for i in range(1, len(lst)):
                    if (lst[i] != lst[i - 1]):
                        print(lst[i])
                # endTime = datetime.datetime.now()
                # timeDiff = endTime - startTime
                # print("Time: " + str(1000 * timeDiff.total_seconds()))
    else:
        lose1 = findLongestTrip(line1[1:], line2, memo)
        lose2 = findLongestTrip(line1, line2[1:], memo)
        print(lose1)
        print(lose2)
        if (lose2[0] > lose1[0]):
            lose1 = lose2
        elif (lose2[0] == lose1[0]):
            lose1[1].extend(lose2[1])
        # lose2 = findLongestTrip(line1[1:], line2[1:], memo)
        # if (lose2[0] > lose1[0]):
        #     lose1 = lose2
        # elif (lose12[0] == lose1[0]):
        #     lose1[1] += lose12[1]
        # lst = [0, [""]]
        # lst[0] = max(lose1[0], lose2[0], lose12[0])
        # lst[1] = [subStr for subStr in loseAll if len(subStr) == lst[0]]
        memo[(line1, line2)] = lose1
        return lose1

numCases = int(input())
if (numCases >= 1 and numCases <= 10):
    for i in range(0, numCases):
        line1 = str(input())
        line2 = str(input())
        if ((len(line1) >= 1 and len(line1) <= 80) and (len(line2) >= 1 and len(line2) <= 80)):
            lst = sorted(findLongestTrip(line1, line2, {})[1])
            print(lst)
            if len(lst) > 0:
                print(lst[0])
                for i in range(1, len(lst)):
                    if (lst[i] != lst[i - 1]):
                        print(lst[i])
                # endTime = datetime.datetime.now()
                # timeDiff = endTime - startTime
                # print("Time: " + str(1000 * timeDiff.total_seconds()))
