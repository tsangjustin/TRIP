''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
 # Name        : trip.py
 # Author      : Michael Curry and Justin Tsang
 # Version     : 1.0
 # Date        : 3/14/2016
 # Description : Generate all subsequence for two string that are longest length
 # Pledge      : I pledge my honor that I have abided by the Stevens Honor System
''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
# Function finds list of all subsequence of longest length
def findLongestTrip(line1, line2, memo):
    # If one person does not have any cities in path
    if line1 == "" or line2 == "":
        return [0, set([""])]
    # If the collection of cities for both people already checked before
    elif (line1, line2) in memo:
        return memo[(line1, line2)]
    # If there is matching city
    elif line1[0] == line2[0]:
        lose12 = findLongestTrip(line1[1:], line2[1:], memo)
        lst = [0, set([""])]
        # Only take paths that are longest subsequence
        lst[1] = set([line1[0] + subStr for subStr in lose12[1] if len(subStr) == lose12[0]])
        lst[0] = 1 + lose12[0]
        memo[(line1, line2)] = lst
        return lst
    # Check all variation if city does not match
    else:
        lose1 = findLongestTrip(line1[1:], line2, memo)
        lose2 = findLongestTrip(line1, line2[1:], memo)
        lose12 = lose1[1].union(lose2[1])
        lst = [0, [""]]
        lst[0] = max(lose1[0], lose2[0])
        lst[1] = set([subStr for subStr in lose12 if len(subStr) == lst[0]])
        memo[(line1, line2)] = lst
        return lst

# Main function
# Get number of trips
numCases = int(input())
if (numCases >= 1 and numCases <= 10):
    for i in range(0, numCases):
        # Get the cities both person traveling to for
        line1 = str(input())
        line2 = str(input())
        lenLine1 = len(line1)
        lenLine2 = len(line2)
        # Check that both string are length [1:80]
        if ((lenLine1 >= 1 and lenLine1 <= 80) and (lenLine2 >= 1 and lenLine2 <= 80)):
            lst = sorted(findLongestTrip(line1, line2, {})[1])
            # Only print all paths is not more than 1000 differ paths
            if len(lst) <= 1000:
                print(*lst, sep='\n')
