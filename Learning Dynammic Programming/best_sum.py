def best_sum(target, nums, memo = {}):
    if target in memo: return memo[target]
    if target == 0: return []
    if target < 0: return None

    currentResult = None

    for num in nums:
        remainder = target - num
        remainderResult = best_sum(remainder, nums, memo)
        if remainderResult != None:
            remainderResult.append(num)
            if (currentResult == None) or (len(remainderResult) < len(currentResult)):
                currentResult = remainderResult.copy()x

    memo[target] = currentResult
    return currentResult

print(best_sum(100, [25,1,2,5]))