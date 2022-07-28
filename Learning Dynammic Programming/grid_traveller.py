def grid_traveller(m, n, memo = {}) -> int:
    key = str(m)+','+str(n)
    if key in memo: return memo[key]
    if m == 1 and n == 1: return 1;
    if m == 0 or n == 0: return 0;

    memo[key] = grid_traveller(m-1, n, memo) + grid_traveller(m, n-1, memo)

    return memo[key]

print(grid_traveller(18,18))