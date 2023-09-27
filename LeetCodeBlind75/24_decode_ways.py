def numDecodings(self, s: str) -> int:
    # Check for leading zeros or double zero (invalid)
    if s[0] == '0':
        return 0
    for i in range(1, len(s)):
        if s[i] == '0' and s[i - 1] == '0':
            return 0
    
    dp = [0] * len(s)
    dp[0] = 1

    for i in range(1, len(s)):
        # Set to previous amount
        dp[i] = dp[i - 1]
        if s[i] == '0':
            if s[i - 1] >= '3':
                # Invalid, return 0
                return 0

            # s[i - 1] is either '1' or '2'
            if i > 1 and (s[i - 2] == '1' or s[i - 2] == '2') and dp[i] > 1:
                # If value two before i was a 1 or 2, then you are locking (s[i - 1] + s[i]) to either
                # '10' or '20' depending on s[i - 1], effectively removing s[i - 1] from any combinations
                # that were previously formed. Thus, we go back to having dp[i - 2] combinations
                dp[i] = dp[i - 2]

        # If previous value isn't a 1 or 2, then no new combinations can be made
        elif (s[i - 1] == '1' or s[i - 1] == '2') and (s[i] <= '6' or s[i - 1] == '1'):
            # If we can form a new two digit number, then we can add on as many combinations we had
            # before we added s[i - 1], since we have all combinations where s[i - 1] and s[i] are
            # separate plus all combinations where s[i - 1] and s[i] are together
            if i > 1:
                dp[i] = dp[i - 1] + dp[i - 2]
            else:
                # Special case for when we are only on the second character - there is no dp[i - 2] yet,
                # so we just add the single new combination we can form (i.e. [1] -> [1 2, 12])
                dp[i] = dp[i - 1] + 1

    return dp[-1]
