def how_sum(target, nums, memo = {}):
    if (target in memo): return memo[target]
    if target == 0: return []
    if target < 0: return None

    for num in nums:
        remainderResult = how_sum(target - num, nums, memo)
        if (remainderResult != None):
            remainderResult.append(num)
            memo[target] = remainderResult
            return memo[target]

    memo[target] = None
    return None

print(how_sum(300, [7]))