def can_construct(target, words, memo = {}):
    if target in memo: return memo[target]

    if target == '': return True

    for word in words:
        if word in target and target.index(word) == 0:
            suffix = target[len(word):]
            if can_construct(suffix, words) == True:
                memo[target] = True
                return True

    memo[target] = False
    return False

print(can_construct("abcdef", ["ab", "ef", "abc"]))